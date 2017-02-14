#pragma once

#include <curses.h>
#include <ctime>
#include <list>

#include "actor.h"
#include "Game.h"


enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

enum class DIR { UP, DOWN, LEFT, RIGHT, RAND };

class GameEngine
{
public:
	GameEngine();
	GameEngine(const GameEngine & engine);
	GameEngine(GameEngine && engine) noexcept;
	~GameEngine();

	GameEngine & operator=(const GameEngine & engine);
	GameEngine & operator=(GameEngine && engine) noexcept;

	bool initializeGraphics(int window_width, int window_height) const;

	void clearScreen() const;
	void refreshScreen() const;

	void refreshInterface(Game & g) const;
	void printInfo(std::string text, int line = 0);

	void setColor(COLOR color, WINDOW * window) const;

	void printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const;
	void printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const;
	void printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const;

	void createScreen(Game & game) const;

	bool placeActor(Actor & actor, Game & game, int pos_x, int pos_y) const;
	bool MoveActor(Actor & actor, Game & game, DIR direction);

	char getTile(int pos_x, int pos_y, Game & game);
	void setTile(char new_tile, int pos_x, int pos_y, Game & game);

	WINDOW * getMainWindow() const;
	WINDOW * getPlayerWindow() const;
	WINDOW * getTextWindow() const;

private:
	WINDOW * mainWindow;
	WINDOW * playerWindow;
	WINDOW * textWindow;

	char old_tile;
	char next_tile;

	std::list<std::string> combat_log;
};
