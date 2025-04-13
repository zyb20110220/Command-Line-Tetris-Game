#include "../include/renderer.h"
#include "../include/terminal.h"
#include <iostream>

// 定义方块显示字符（使用Unicode实心方块）
static const std::string BLOCK = "█";

void Renderer::drawMainBoard(int x, int y, int width, int height)
{
	// 绘制主游戏区域的边框，宽度需要乘2因为每个方块占用两个字符位置
	drawBorder(x, y, width * 2 + 2, height + 2);
}

void Renderer::drawInfoPanel(int x, int y)
{
	// 绘制信息面板边框
	drawBorder(x, y, 22, 6);
	// 在边框内显示游戏统计信息
	drawGameStats(x + 2, y + 1, score, level, lines);
}

void Renderer::drawControlsPanel(int x, int y)
{
	// 绘制控制说明面板边框
	drawBorder(x, y, 22, 7);
	// 绘制面板标题
	drawPanelTitle(x + 2, y + 1, "操作说明");

	// 显示控制按键说明
	std::cout << "\033[" << (y + 2) << ";" << (x + 2) << "H" << "←→ : 移动方块左右";
	std::cout << "\033[" << (y + 3) << ";" << (x + 2) << "H" << "↑   : 旋转方块";
	std::cout << "\033[" << (y + 4) << ";" << (x + 2) << "H" << "↓   : 加速下落";
	std::cout << "\033[" << (y + 5) << ";" << (x + 2) << "H" << "Q   : 退出游戏";
}

void Renderer::drawNextPiecePanel(int x, int y)
{
	// 绘制下一个方块预览区的边框
	drawBorder(x, y, 16, 8);
	// 绘制预览区标题
	drawPanelTitle(x + 2, y + 1, "下一个");
}

void Renderer::drawGameBoard(const std::vector<std::vector<int>> &board,
							 const std::vector<std::vector<int>> &colors)
{
	// 遍历游戏面板的每一行
	for (int i = 0; i < HEIGHT; i++)
	{
		// 移动光标到当前行的开始位置
		std::cout << "\033[" << (i + 2) << ";" << 3 << "H";
		// 绘制每一列
		for (int j = 0; j < WIDTH; j++)
		{
			if (board[i][j] == 0)
				std::cout << "  "; // 空白位置显示两个空格
			else
				// 有方块的位置显示彩色方块
				std::cout << BLOCK_COLORS[colors[i][j]] << BLOCK << BLOCK << RESET;
		}
	}
}

void Renderer::drawNextPiece(int x, int y, int shape)
{
	// 在预览区绘制下一个方块
	for (int i = 0; i < 4; i++)
	{
		// 移动光标到预览区的每一行
		std::cout << "\033[" << (y + i) << ";" << x << "H";
		for (int j = 0; j < 4; j++)
		{
			if (SHAPES[shape][i][j])
				// 用对应颜色绘制方块
				std::cout << BLOCK_COLORS[shape] << BLOCK << BLOCK << RESET;
			else
				std::cout << "  "; // 空白位置
		}
	}
}

void Renderer::drawGameOver(int score)
{
	// 在屏幕中央显示游戏结束信息
	std::cout << "\033[" << (HEIGHT / 2) << ";" << (WIDTH + 5) << "H"
			  << RED << BOLD << "游戏结束!" << RESET << std::endl;
	std::cout << "\033[" << (HEIGHT / 2 + 1) << ";" << (WIDTH + 5) << "H"
			  << "最终得分: " << score << std::endl;
}

void Renderer::drawGameStats(int x, int y, int score, int level, int lines)
{
	// 显示游戏标题和统计信息
	std::cout << "\033[" << y << ";" << x << "H" << CYAN << BOLD << "俄罗斯方块" << RESET;
	std::cout << "\033[" << (y + 1) << ";" << x << "H" << "分数: " << score;
	std::cout << "\033[" << (y + 2) << ";" << x << "H" << "等级: " << level;
	std::cout << "\033[" << (y + 3) << ";" << x << "H" << "消除行: " << lines;
}

void Renderer::drawPanelTitle(int x, int y, const std::string &title)
{
	// 以青色显示面板标题
	std::cout << "\033[" << y << ";" << x << "H" << CYAN << title << RESET;
}