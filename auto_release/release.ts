#!/usr/bin/env -S deno run --allow-net --allow-run --allow-read --allow-write --allow-env

// Add Deno type declarations
/// <reference lib="deno.ns" />
/// <reference lib="deno.unstable" />

// Import required modules
import { serve } from "https://deno.land/std@0.220.0/http/server.ts";

const GITHUB_TOKEN = Deno.env.get("GITHUB_TOKEN");
const WEBHOOK_SECRET = Deno.env.get("WEBHOOK_SECRET");

// Get the latest version number
async function getLatestVersion(): Promise<number> {
	try {
		const headers: HeadersInit = {
			"Accept": "application/vnd.github.v3+json"
		};

		// Only add authorization header if token exists
		const token = Deno.env.get("GITHUB_TOKEN");
		if (token) {
			headers["Authorization"] = `Bearer ${token}`;
		}

		const response = await fetch(
			`https://api.github.com/repos/zyb20110220/Command-Line-Tetris-Game/releases`,
			{ headers }
		);

		if (!response.ok) {
			console.warn("Failed to fetch release history, using version 1");
			return 1;
		}

		const releases = await response.json();
		if (!releases || releases.length === 0) {
			return 1;
		}

		const versionPattern = /release-\d{4}-\d{2}-\d{2}-v(\d+)/;
		let maxVersion = 0;
		for (const release of releases) {
			const match = release.tag_name.match(versionPattern);
			if (match) {
				const version = parseInt(match[1], 10);
				if (version > maxVersion) {
					maxVersion = version;
				}
			}
		}
		return maxVersion + 1;
	} catch (error) {
		console.warn("Failed to fetch release history, using version 1:", error);
		return 1;
	}
}

// Verify GitHub webhook signature
async function verifySignature(request: Request): Promise<boolean> {
	const signature = request.headers.get("x-hub-signature-256");
	if (!signature || !WEBHOOK_SECRET) return false;

	const body = await request.clone().text();
	const encoder = new TextEncoder();
	const key = await crypto.subtle.importKey(
		"raw",
		encoder.encode(WEBHOOK_SECRET),
		{ name: "HMAC", hash: "SHA-256" },
		false,
		["sign"]
	);

	const signatureHash = signature.replace("sha256=", "");
	const bodyHash = Array.from(
		new Uint8Array(
			await crypto.subtle.sign(
				"HMAC",
				key,
				encoder.encode(body)
			)
		)
	).map(b => b.toString(16).padStart(2, "0")).join("");

	return bodyHash === signatureHash;
}

// Handle the root path
async function handleRoot(): Promise<Response> {
	return new Response("Release API is running. Send POST requests to trigger releases.", {
		headers: { "Content-Type": "text/plain" },
	});
}

// Check environment variables
function checkEnvVars(): { ok: boolean; message: string } {
	if (!GITHUB_TOKEN) {
		return {
			ok: false,
			message: "GitHub token is not configured. Please set GITHUB_TOKEN environment variable."
		};
	}
	if (!WEBHOOK_SECRET) {
		return {
			ok: false,
			message: "Webhook secret is not configured. Please set WEBHOOK_SECRET environment variable."
		};
	}
	return { ok: true, message: "Environment variables are properly configured." };
}

// Handle webhook request
async function handleRequest(request: Request): Promise<Response> {
	// Handle OPTIONS request for CORS
	if (request.method === "OPTIONS") {
		return new Response(null, {
			headers: {
				"Access-Control-Allow-Origin": "*",
				"Access-Control-Allow-Methods": "POST, OPTIONS",
				"Access-Control-Allow-Headers": "Content-Type, x-hub-signature-256",
			},
		});
	}

	// Handle GET request for health check
	if (request.method === "GET") {
		return handleRoot();
	}

	// Only accept POST requests for webhook
	if (request.method !== "POST") {
		return new Response("Method not allowed", {
			status: 405,
			headers: { "Content-Type": "text/plain" }
		});
	}

	// Check environment variables
	const envCheck = checkEnvVars();
	if (!envCheck.ok) {
		return new Response(envCheck.message, {
			status: 500,
			headers: { "Content-Type": "text/plain" }
		});
	}

	// Verify webhook signature
	if (!await verifySignature(request)) {
		return new Response("Invalid signature", {
			status: 403,
			headers: { "Content-Type": "text/plain" }
		});
	}

	try {
		const payload = await request.json();

		// Check if it's a schedule event and it's Monday
		if (payload.schedule === "weekly" && new Date().getDay() === 1) {  // 1 represents Monday
			const date = new Date().toISOString().split("T")[0];
			const version = await getLatestVersion();

			const releaseData = {
				tag_name: `release-${date}-v${version}`,
				name: `Weekly Build Release ${date} (v${version})`,
				body: `Automated Build Release\n\nBuild Information:\n- Date: ${date}\n- Version: v${version}\n\nTriggered by Deno Deploy webhook on Monday.`,
				draft: false,
				prerelease: false
			};

			// Create release through GitHub API
			const headers: HeadersInit = {
				"Content-Type": "application/json",
				"Accept": "application/vnd.github.v3+json"
			};

			// Only add authorization header if token exists
			const token = Deno.env.get("GITHUB_TOKEN");
			if (token) {
				headers["Authorization"] = `Bearer ${token}`;
			}

			const releaseResponse = await fetch(
				"https://api.github.com/repos/zyb20110220/Command-Line-Tetris-Game/releases",
				{
					method: "POST",
					headers,
					body: JSON.stringify(releaseData)
				}
			);

			if (!releaseResponse.ok) {
				const error = await releaseResponse.text();
				throw new Error(`Failed to create release: ${error}`);
			}

			return new Response("Release created successfully", {
				status: 200,
				headers: { "Content-Type": "text/plain" }
			});
		}

		return new Response("Event ignored - not a weekly schedule or not Monday", {
			status: 200,
			headers: { "Content-Type": "text/plain" }
		});

	} catch (error) {
		console.error("Error processing webhook:", error);
		return new Response(`Error processing webhook: ${error.message}`, {
			status: 500,
			headers: { "Content-Type": "text/plain" }
		});
	}
}

// Start HTTP server
serve(handleRequest);