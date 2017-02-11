#pragma once

#include <curses.h>

enum class color { GREEN, RED, BLUE, WHITE, YELLOW };

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void InitializeGraphics(int window_width, int window_height);
	void setColor(color c);
};

