#include "../include/terminal.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

// 保存终端的原始设置
static struct termios orig_termios;

void initTerminal()
{
	// 获取终端当前设置
	tcgetattr(STDIN_FILENO, &orig_termios);
	// 创建新的终端设置
	struct termios raw = orig_termios;
	// 禁用规范模式(ICANON)和输入回显(ECHO)
	raw.c_lflag &= ~(ICANON | ECHO);
	// 设置读取的最小字符数和等待时间
	raw.c_cc[VMIN] = 0;	 // 最小字符数为0
	raw.c_cc[VTIME] = 0; // 不等待
	// 应用新设置
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	// 清空输入缓冲区
	tcflush(STDIN_FILENO, TCIFLUSH);
}

void restoreTerminal()
{
	// 恢复终端到原始设置
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
	// 显示光标
	std::cout << "\033[?25h";
}

char getch()
{
	char buf = 0;
	struct termios old = {0};
	// 获取当前终端设置
	tcgetattr(0, &old);
	// 修改终端设置：禁用规范模式和回显
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	// 设置为立即读取单个字符
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	// 应用修改后的设置
	tcsetattr(0, TCSANOW, &old);

	// 读取单个字符
	if (read(0, &buf, 1) < 0)
	{
		perror("read()");
	}

	// 恢复终端设置
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	tcsetattr(0, TCSADRAIN, &old);
	return buf;
}

bool kbhit()
{
	// 保存当前终端设置
	struct termios term;
	tcgetattr(0, &term);

	// 创建新的终端设置：禁用规范模式和回显
	termios term_new = term;
	term_new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term_new);

	// 检查是否有待处理的输入
	int byteswaiting;
	ioctl(0, FIONREAD, &byteswaiting);

	// 恢复终端设置
	tcsetattr(0, TCSANOW, &term);
	return byteswaiting > 0;
}

void clearScreen()
{
	// 使用ANSI转义序列清屏并将光标移动到左上角
	// \033[2J 清除整个屏幕
	// \033[H 将光标移动到左上角(1,1)位置
	std::cout << "\033[2J\033[H";
}

void drawBorder(int x, int y, int width, int height)
{
	// 设置边框颜色为青色
	const std::string borderColor = "\033[36m";
	std::cout << borderColor;

	// 绘制上边框
	// 使用ANSI转义序列移动光标到指定位置
	std::cout << "\033[" << y << ";" << x << "H┌";
	for (int i = 0; i < width - 2; i++)
		std::cout << "─";
	std::cout << "┐";

	// 绘制侧边框
	for (int i = 1; i < height - 1; i++)
	{
		// 左侧边框
		std::cout << "\033[" << y + i << ";" << x << "H│";
		// 右侧边框
		std::cout << "\033[" << y + i << ";" << x + width - 1 << "H│";
	}

	// 绘制下边框
	std::cout << "\033[" << y + height - 1 << ";" << x << "H└";
	for (int i = 0; i < width - 2; i++)
		std::cout << "─";
	std::cout << "┘";

	// 重置颜色属性
	std::cout << "\033[0m";
	// 确保所有输出立即显示
	std::cout.flush();
}