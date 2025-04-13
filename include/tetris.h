#ifndef TETRIS_H
#define TETRIS_H

#include "game_state.h"
#include "terminal.h"

/**
 * @brief 初始化游戏，包括随机数种子、初始方块和终端设置
 */
void initGame();

/**
 * @brief 绘制整个游戏界面，包括游戏区域、信息面板和预览区
 */
void drawBoard();

/**
 * @brief 检查当前方块移动到指定位置是否有效
 * @param x 目标位置的X坐标
 * @param y 目标位置的Y坐标
 * @return true 如果移动有效，false 如果发生碰撞或超出边界
 */
bool isValidMove(int x, int y);

/**
 * @brief 旋转当前方块，如果旋转后的位置有效则执行旋转
 */
void rotatePiece();

/**
 * @brief 检查并清除已填满的行，更新分数和等级
 */
void clearLines();

/**
 * @brief 生成新的方块，设置其初始位置，并检查游戏是否结束
 */
void createNewPiece();

/**
 * @brief 更新游戏状态，包括方块下落和固定
 */
void updateGame();

/**
 * @brief 处理用户输入，包括方块移动、旋转和游戏退出
 */
void handleInput();

#endif // TETRIS_H