#include "../include/game_logic.h"
#include "../include/game_state.h"
#include "../include/renderer.h"
#include "../include/terminal.h"
#include "../include/tetris.h"
#include <thread>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

GameLogic::GameLogic() : moveDelay(1000) // 初始移动延迟为1秒
{
	// 记录游戏开始时间点
	lastMoveTime = std::chrono::steady_clock::now();
}

void GameLogic::run()
{
	// 显示开始界面并等待用户开始游戏
	showStartScreen();
	// 初始化游戏状态
	initGame();
	// 进入游戏主循环
	gameLoop();
}

void GameLogic::gameLoop()
{
	// 游戏主循环，直到游戏结束
	while (!gameOver)
	{
		processFrame();
		// 控制游戏帧率为30fps (1秒≈33333微秒)
		std::this_thread::sleep_for(std::chrono::microseconds(33333));
	}

	// 游戏结束时显示结算界面
	Renderer::drawGameOver(score);
	// 恢复终端设置
	restoreTerminal();
}

void GameLogic::updateGameSpeed()
{
	// 根据当前等级调整方块下落速度
	moveDelay = 1000 - (level - 1) * 100;
	// 设置最快速度限制（100毫秒）
	if (moveDelay < 100)
	{
		moveDelay = 100;
	}
}

bool GameLogic::shouldUpdate()
{
	// 获取当前时间
	auto currentTime = std::chrono::steady_clock::now();
	// 计算自上次更新后经过的时间（毫秒）
	auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(
						currentTime - lastMoveTime)
						.count();

	// 如果经过的时间超过延迟时间，则需要更新
	if (timeDiff >= moveDelay)
	{
		lastMoveTime = currentTime;
		return true;
	}
	return false;
}

void GameLogic::processFrame()
{
	// 绘制游戏界面
	drawBoard();
	// 处理用户输入
	handleInput();
	// 更新游戏速度
	updateGameSpeed();

	// 检查是否需要更新方块位置
	if (shouldUpdate())
	{
		updateGame();
	}
}

void GameLogic::showStartScreen()
{
	// 清屏并将光标移到开头
	std::cout << "\033[2J\033[H";
	// 获取终端窗口大小
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	int terminalWidth = w.ws_col;

	// 计算并显示各个界面元素的位置
	const int titleY = 3;
	drawStartTitle((terminalWidth - 49) / 2, titleY);

	const int controlsY = titleY + 8;
	drawStartControls((terminalWidth - 26) / 2, controlsY);

	// 显示开始提示
	const std::string startMessage = "▶ 按任意键开始游戏...";
	showBlinkingPrompt((terminalWidth - startMessage.length()) / 2,
					   controlsY + 10, startMessage);

	// 等待用户按键开始游戏
	handleStartScreenInput();
}

void GameLogic::drawStartTitle(int x, int y)
{
	// ASCII艺术字形式的游戏标题
	const std::string title[] = {
		"████████╗███████╗████████╗██████╗ ██╗███████╗",
		"╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝",
		"   ██║   █████╗     ██║   ██████╔╝██║███████╗",
		"   ██║   ██╔══╝     ██║   ██╔══██╗██║╚════██║",
		"   ██║   ███████╗   ██║   ██║  ██║██║███████║",
		"   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚══════╝"};

	// 以青色加粗显示标题
	std::cout << CYAN << BOLD;
	for (int i = 0; i < 6; ++i)
	{
		std::cout << "\033[" << (y + i) << ";" << x << "H" << title[i];
	}
	std::cout << RESET;
}

void GameLogic::drawStartControls(int x, int y)
{
	// 绘制控制说明边框
	const int boxWidth = 26;
	const int boxHeight = 8;
	drawBorder(x, y, boxWidth, boxHeight);

	// 绘制标题
	const std::string title_text = "操作说明";
	const int titleX = x + (boxWidth - title_text.length()) / 2;

	// 显示控制说明文本
	std::cout << "\033[" << y << ";" << titleX << "H" << YELLOW << title_text << RESET;
	std::cout << "\033[" << (y + 2) << ";" << (x + 2) << "H" << "← →  移动方块左右";
	std::cout << "\033[" << (y + 3) << ";" << (x + 2) << "H" << "↑    旋转方块";
	std::cout << "\033[" << (y + 4) << ";" << (x + 2) << "H" << "↓    加速下落";
	std::cout << "\033[" << (y + 5) << ";" << (x + 2) << "H" << "Q    退出游戏";
}

void GameLogic::showBlinkingPrompt(int x, int y, const std::string &message)
{
	// 实现闪烁效果（3次）
	for (int i = 0; i < 3; ++i)
	{
		// 显示提示文本
		std::cout << "\033[" << y << ";" << x << "H" << GREEN << message << RESET;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		// 清除提示文本
		std::cout << "\033[" << y << ";" << x << "H"
				  << std::string(message.length(), ' ');
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	// 最后保持提示文本显示
	std::cout << "\033[" << y << ";" << x << "H" << GREEN << message << RESET;
	std::cout.flush();
}

void GameLogic::handleStartScreenInput()
{
	// 设置终端为原始模式以直接读取输入
	char ch;
	system("stty raw");
	ch = getchar();
	system("stty cooked");
	// 清屏准备开始游戏
	std::cout << "\033[2J\033[H";
}

// 获取终端宽度的辅助函数
int getTerminalWidth()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}

// 计算字符串的实际显示宽度的辅助函数
int getDisplayWidth(const std::string &str)
{
	int width = 0;
	for (char c : str)
	{
		if ((unsigned char)c >= 0x80)
			width += 2; // 双字节字符（如中文）占用两个字符宽度
		else
			width += 1; // ASCII字符占用一个字符宽度
	}
	return width;
}

// 测试光标定位功能的辅助函数
void testCursorPositioning()
{
	// 清屏
	std::cout << "\033[2J\033[H";

	// 在不同位置打印测试文字
	for (int i = 1; i <= 5; ++i)
	{
		int x = i * 10;
		int y = i * 2;
		std::cout << "\033[" << y << ";" << x << "H" << "测试文字 (" << x << ", " << y << ")";
	}

	// 等待用户按键
	std::cout << "\033[12;1H" << "按任意键继续...";
	char ch;
	system("stty raw");
	ch = getchar();
	system("stty cooked");
	std::cout << "\033[2J\033[H";
}