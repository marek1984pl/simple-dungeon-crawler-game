#pragma once

#include <curses.h>

#include "Level.h"
#include "actor.h"
#include "Game.h"


enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

enum class DIR { UP, DOWN, LEFT, RIGHT };

class GameEngine
{
public:
	GameEngine();
	GameEngine(const GameEngine & engine);
	GameEngine(GameEngine && engine) noexcept;
	~GameEngine();

	GameEngine & operator=(const GameEngine & engine);
	GameEngine & operator=(GameEngine && engine) noexcept;


	void InitializeGraphics(int window_width, int window_height);

	void createGameInterface();
	void refreshGameInterface() const;

	void setColor(COLOR color, WINDOW * window);

	void printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);
	void printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);
	void printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);

	void DisplayLevel(Level & lvl);

	bool placeActor(Actor & actor, Game & game, int pos_x, int pos_y);
	bool MoveActor(Actor & actor, Game & game, DIR direction);

	char GetNextTile(int pos_x, int pos_y, Game & game);

	WINDOW * GetMainWindow();
	WINDOW * GetUiWindow();
	WINDOW * GetTextWindow();

private:
	WINDOW * mainWindow;
	WINDOW * uiWindow;
	WINDOW * textWindow;

	char old_tile = '.';
	char next_tile = '.';
};

