#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <string>

extern const std::string RESET;
extern const std::string BOLD;
extern const std::string RED;
extern const std::string GREEN;
extern const std::string YELLOW;
extern const std::string BLUE;
extern const std::string MAGENTA;
extern const std::string CYAN;
extern const std::string WHITE;

extern const std::string BLOCK_COLORS[];
extern const int WIDTH;
extern const int HEIGHT;
extern const int SHAPES[7][4][4];

extern std::vector<std::vector<int>> board;
extern std::vector<std::vector<int>> colors;
extern int currentPiece[4][4];
extern int currentX, currentY;
extern int currentShape;
extern int score;
extern int level;
extern int lines;
extern bool gameOver;
extern int nextShape;

#endif