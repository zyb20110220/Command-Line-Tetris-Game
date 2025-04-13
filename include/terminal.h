#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>

/**
 * @brief 从终端读取一个字符，无需按回车即可读取
 * @return 读取到的字符
 */
char getch();

/**
 * @brief 检查终端是否有待处理的输入
 * @return true 如果有输入待处理，false 否则
 */
bool kbhit();

/**
 * @brief 清空终端屏幕并将光标移动到左上角
 */
void clearScreen();

/**
 * @brief 在指定位置绘制边框
 * @param x 左上角的X坐标
 * @param y 左上角的Y坐标
 * @param width 边框宽度
 * @param height 边框高度
 */
void drawBorder(int x, int y, int width, int height);

/**
 * @brief 初始化终端设置，包括禁用输入回显和行缓冲
 */
void initTerminal();

/**
 * @brief 恢复终端到原始设置
 */
void restoreTerminal();

#endif // TERMINAL_H