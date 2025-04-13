#ifndef RENDERER_H
#define RENDERER_H

#include "game_state.h"
#include <string>

/**
 * @brief 游戏界面渲染器类，负责所有游戏界面元素的绘制
 */
class Renderer
{
public:
	/**
	 * @brief 绘制游戏主面板边框
	 * @param x 左上角X坐标
	 * @param y 左上角Y坐标
	 * @param width 面板宽度（方块数）
	 * @param height 面板高度（方块数）
	 */
	static void drawMainBoard(int x, int y, int width, int height);

	/**
	 * @brief 绘制信息面板（显示分数、等级等）
	 * @param x 面板左上角X坐标
	 * @param y 面板左上角Y坐标
	 */
	static void drawInfoPanel(int x, int y);

	/**
	 * @brief 绘制下一个方块预览面板
	 * @param x 面板左上角X坐标
	 * @param y 面板左上角Y坐标
	 */
	static void drawNextPiecePanel(int x, int y);

	/**
	 * @brief 绘制控制说明面板
	 * @param x 面板左上角X坐标
	 * @param y 面板左上角Y坐标
	 */
	static void drawControlsPanel(int x, int y);

	/**
	 * @brief 绘制游戏面板内的所有方块
	 * @param board 游戏面板状态矩阵
	 * @param colors 对应的颜色矩阵
	 */
	static void drawGameBoard(const std::vector<std::vector<int>> &board,
							  const std::vector<std::vector<int>> &colors);

	/**
	 * @brief 绘制下一个方块的预览
	 * @param x 预览区域左上角X坐标
	 * @param y 预览区域左上角Y坐标
	 * @param shape 方块形状索引
	 */
	static void drawNextPiece(int x, int y, int shape);

	/**
	 * @brief 绘制游戏结束画面
	 * @param score 最终得分
	 */
	static void drawGameOver(int score);

private:
	/**
	 * @brief 绘制游戏统计信息（分数、等级、已消除行数）
	 * @param x 文本起始X坐标
	 * @param y 文本起始Y坐标
	 * @param score 当前分数
	 * @param level 当前等级
	 * @param lines 已消除的行数
	 */
	static void drawGameStats(int x, int y, int score, int level, int lines);

	/**
	 * @brief 绘制面板标题
	 * @param x 标题起始X坐标
	 * @param y 标题起始Y坐标
	 * @param title 标题文本
	 */
	static void drawPanelTitle(int x, int y, const std::string &title);
};

#endif // RENDERER_H