#pragma once

#include <curses.h>

#include "UserInterface.h"
#include "Level.h"
#include "actor.h"
#include "Game.h"


enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

enum class DIR { UP, DOWN, LEFT, RIGHT };

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void InitializeGraphics(int window_width, int window_height);

	void setColor(COLOR color, WINDOW * window);

	void printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);
	void printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);
	void printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);

	void DisplayLevel(Level & lvl);
	void UpdateGame(Game & game);
	void refreshGameInterface(UserInterface & ui);

	bool MoveActor(Actor & actor, DIR direction);

	WINDOW * mainWindow;
	WINDOW * uiWindow;
	WINDOW * textWindow;

private:
};

