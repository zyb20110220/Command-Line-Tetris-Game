#include "../include/game_state.h"

// ANSI 转义序列常量定义，用于终端输出的颜色控制
const std::string RESET = "\033[0m";	// 重置所有属性
const std::string BOLD = "\033[1m";		// 文本加粗
const std::string RED = "\033[31m";		// 红色
const std::string GREEN = "\033[32m";	// 绿色
const std::string YELLOW = "\033[33m";	// 黄色
const std::string BLUE = "\033[34m";	// 蓝色
const std::string MAGENTA = "\033[35m"; // 品红色
const std::string CYAN = "\033[36m";	// 青色
const std::string WHITE = "\033[37m";	// 白色

// 各种方块形状对应的颜色数组
const std::string BLOCK_COLORS[] = {CYAN, YELLOW, GREEN, RED, MAGENTA, BLUE, WHITE};

// 游戏区域的大小定义
const int WIDTH = 12;  // 游戏区域宽度
const int HEIGHT = 20; // 游戏区域高度

// 七种俄罗斯方块的形状定义
// 每个形状用4x4的矩阵表示，1表示方块，0表示空白
const int SHAPES[7][4][4] = {
	{{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}}, // I型方块
	{{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // O型方块
	{{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}}, // S型方块
	{{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}}, // Z型方块
	{{0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}}, // T型方块
	{{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}}, // L型方块
	{{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}}  // J型方块
};

// 游戏状态变量的初始化
std::vector<std::vector<int>> board(HEIGHT, std::vector<int>(WIDTH, 0));  // 游戏面板，初始化为全0
std::vector<std::vector<int>> colors(HEIGHT, std::vector<int>(WIDTH, 0)); // 颜色面板，初始化为全0
int currentPiece[4][4];													  // 当前正在下落的方块的形状矩阵
int currentX, currentY;													  // 当前方块的位置坐标
int currentShape;														  // 当前方块的形状索引
int score = 0;															  // 游戏得分
int level = 1;															  // 游戏等级
int lines = 0;															  // 已消除的行数
bool gameOver = false;													  // 游戏结束标志
int nextShape;															  // 下一个方块的形状索引