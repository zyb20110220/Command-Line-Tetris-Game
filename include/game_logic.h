#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "game_state.h"
#include <chrono>

/**
 * @brief 游戏逻辑控制类，负责管理游戏流程和主循环
 */
class GameLogic
{
public:
	/**
	 * @brief 构造函数，初始化游戏基本参数
	 */
	GameLogic();

	/**
	 * @brief 运行游戏，包括显示开始界面和进入主循环
	 */
	void run();

private:
	// 时间相关成员变量
	std::chrono::steady_clock::time_point lastMoveTime; // 上次方块移动的时间点
	int moveDelay;										// 方块移动的延迟时间(毫秒)

	/**
	 * @brief 游戏主循环，处理游戏状态更新和渲染
	 */
	void gameLoop();

	/**
	 * @brief 处理单帧游戏逻辑，包括绘制、输入处理和状态更新
	 */
	void processFrame();

	/**
	 * @brief 检查是否应该更新方块位置
	 * @return true 如果到达更新时间，false 否则
	 */
	bool shouldUpdate();

	/**
	 * @brief 根据当前等级更新游戏速度
	 */
	void updateGameSpeed();

	// 开始界面相关函数
	/**
	 * @brief 显示游戏开始界面
	 */
	void showStartScreen();

	/**
	 * @brief 绘制游戏标题
	 * @param x 标题左上角X坐标
	 * @param y 标题左上角Y坐标
	 */
	void drawStartTitle(int x, int y);

	/**
	 * @brief 绘制控制说明
	 * @param x 说明左上角X坐标
	 * @param y 说明左上角Y坐标
	 */
	void drawStartControls(int x, int y);

	/**
	 * @brief 处理开始界面的输入
	 */
	void handleStartScreenInput();

	/**
	 * @brief 显示闪烁的提示信息
	 * @param x 提示文本的X坐标
	 * @param y 提示文本的Y坐标
	 * @param message 提示文本内容
	 */
	void showBlinkingPrompt(int x, int y, const std::string &message);
};

#endif // GAME_LOGIC_H