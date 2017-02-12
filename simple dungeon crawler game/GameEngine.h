#pragma once

#include <curses.h>
#include "UserInterface.h"

enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

class GameEngine
{
public:
	GameEngine();
	GameEngine(UserInterface * _ui);
	~GameEngine();

	void InitializeGraphics(int window_width, int window_height);
	void setColor(COLOR color, WINDOW_TYPE window);
	void printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW_TYPE window = WINDOW_TYPE::MAIN);

private:
	UserInterface * ui;
};

