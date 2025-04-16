#include "../include/tetris.h"
#include "../include/game_logic.h"
#include "../include/renderer.h"
#include "../include/terminal.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

void initGame()
{
	// 初始化随机数生成器
	srand(time(0));
	// 生成第一个预览方块
	nextShape = rand() % 7;
	// 创建第一个活动方块
	createNewPiece();
	// 初始化终端设置
	initTerminal();
}

void drawBoard()
{
	// 隐藏光标，提供更好的视觉体验
	std::cout << "\033[?25l";
	clearScreen();

	// 计算右侧信息面板的X坐标
	const int rightSideX = WIDTH * 2 + 6;

	// 绘制游戏界面的各个组成部分
	Renderer::drawMainBoard(2, 1, WIDTH, HEIGHT); // 主游戏区域
	Renderer::drawInfoPanel(rightSideX, 1);		  // 信息面板（分数等）
	Renderer::drawControlsPanel(rightSideX, 8);	  // 控制说明面板
	Renderer::drawNextPiecePanel(rightSideX, 16); // 下一个方块预览区

	// 创建临时面板用于显示当前状态
	std::vector<std::vector<int>> tempBoard = board;
	std::vector<std::vector<int>> tempColors = colors;

	// 将当前活动方块添加到临时面板中
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// 只在有效范围内添加方块
			if (currentPiece[i][j] && currentY + i >= 0 && currentY + i < HEIGHT && currentX + j >= 0 && currentX + j < WIDTH)
			{
				tempBoard[currentY + i][currentX + j] = currentPiece[i][j];
				tempColors[currentY + i][currentX + j] = currentShape;
			}
		}
	}

	// 绘制游戏区域和预览区域
	Renderer::drawGameBoard(tempBoard, tempColors);
	Renderer::drawNextPiece(rightSideX + 4, 18, nextShape);

	// 确保所有输出立即显示
	std::cout.flush();
}

bool isValidMove(int x, int y)
{
	// 检查4x4方块矩阵中的每个格子
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (currentPiece[i][j])
			{
				int newX = x + j;
				int newY = y + i;
				// 检查是否超出游戏区域边界
				if (newX < 0 || newX >= WIDTH || newY >= HEIGHT)
					return false;
				// 检查是否与已固定的方块重叠
				if (newY >= 0 && board[newY][newX])
					return false;
			}
		}
	}
	return true;
}

void rotatePiece()
{
    int temp[4][4];
    // 实现90度顺时针旋转
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = currentPiece[3 - j][i];
            
    // 临时保存当前方块状态
    int backup[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            backup[i][j] = currentPiece[i][j];
            
    // 临时应用旋转
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            currentPiece[i][j] = temp[i][j];
    
    // 检查旋转后的位置是否有效，如果无效则尝试左右移动一格
    if (!isValidMove(currentX, currentY)) {
        // 尝试向左移动一格
        if (isValidMove(currentX - 1, currentY)) {
            currentX--;
            return;
        }
        // 尝试向右移动一格
        if (isValidMove(currentX + 1, currentY)) {
            currentX++;
            return;
        }
        // 如果都不行，恢复到原始状态
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                currentPiece[i][j] = backup[i][j];
    }
}

void clearLines()
{
	int linesCleared = 0;
	for (int i = HEIGHT - 1; i >= 0; i--)
	{
		// 检查当前行是否已填满
		bool lineFull = true;
		for (int j = 0; j < WIDTH; j++)
		{
			if (board[i][j] == 0)
			{
				lineFull = false;
				break;
			}
		}

		if (lineFull)
		{
			linesCleared++;
			// 将上方的所有行下移一行
			for (int k = i; k > 0; k--)
			{
				for (int j = 0; j < WIDTH; j++)
				{
					board[k][j] = board[k - 1][j];
					colors[k][j] = colors[k - 1][j];
				}
			}
			// 清空最上方的行
			for (int j = 0; j < WIDTH; j++)
			{
				board[0][j] = 0;
				colors[0][j] = 0;
			}
			i++; // 由于行下移，需要重新检查当前行
		}
	}

	// 更新分数和等级
	if (linesCleared > 0)
	{
		// 计算得分：消除的行数平方 * 100 * 当前等级
		lines += linesCleared;
		score += linesCleared * linesCleared * 100 * level;
		// 每消除10行提升一个等级
		level = 1 + lines / 10;
	}
}

void createNewPiece()
{
	// 使用预览的方块作为当前方块
	currentShape = nextShape;
	// 生成新的预览方块
	nextShape = rand() % 7;

	// 复制方块形状到当前方块数组
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			currentPiece[i][j] = SHAPES[currentShape][i][j];

	// 设置新方块的初始位置（居中，顶部）
	currentX = WIDTH / 2 - 2;
	currentY = 0;

	// 检查游戏是否结束（新方块无法放置）
	if (!isValidMove(currentX, currentY))
		gameOver = true;
}

void updateGame()
{
	// 检查方块是否可以继续下落
	if (isValidMove(currentX, currentY + 1))
	{
		currentY++; // 方块下移一格
	}
	else
	{
		// 将当前方块固定到游戏面板上
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (currentPiece[i][j] && currentY + i >= 0)
				{
					board[currentY + i][currentX + j] = currentPiece[i][j];
					colors[currentY + i][currentX + j] = currentShape;
				}
			}
		}
		// 检查并清除已填满的行
		clearLines();
		// 生成新的方块
		createNewPiece();
	}
}

void handleInput()
{
	if (kbhit())
	{
		char key = getch();
		if (key == '\033') // ESC字符，表示方向键序列的开始
		{
			char seq[3];
			// 读取方向键的完整序列
			if (read(0, &seq[0], 1) != -1 && read(0, &seq[1], 1) != -1)
			{
				if (seq[0] == '[')
				{
					switch (seq[1])
					{
					case 'D': // 左箭头：向左移动
						if (isValidMove(currentX - 1, currentY))
							currentX--;
						break;
					case 'C': // 右箭头：向右移动
						if (isValidMove(currentX + 1, currentY))
							currentX++;
						break;
					case 'A': // 上箭头：旋转方块
						rotatePiece();
						break;
					case 'B': // 下箭头：加速下落
						if (isValidMove(currentX, currentY + 1))
							currentY++;
						break;
					}
				}
			}
		}
		else if (key == 'q' || key == 'Q') // 退出游戏
		{
			gameOver = true;
		}
	}
}

int main()
{
	// 创建游戏逻辑对象并运行游戏
	GameLogic game;
	game.run();
	return 0;
}