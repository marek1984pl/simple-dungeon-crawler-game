#pragma once

#include <curses.h>

#include "Game.h"

enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

class UserInterface
{
public:
	UserInterface(const int window_width, const int window_height);
	~UserInterface();

	int createMainMenu();
	void createEndScreen(const Game & g);
	void createGameInterface();

	bool initializeGraphics(const int window_width, const int window_height) const;

	void clearScreen() const;
	void updateScreen(Game & game) const;
	void refreshScreen() const;

	void updateInterface(Game & g) const;

	void printItemInfo(const Item & item, const int line_to_print) const;
	void printLog(const CombatLog c_log) const;

	void setColor(const COLOR color, WINDOW * window) const;

	void printChar(const char char_to_print, const int pos_x, const int pos_y, const COLOR color, WINDOW * window) const;
	void printString(const char * string_to_print, const int pos_x, const int pos_y, const COLOR color, WINDOW * window) const;
	void printString(const int string_to_print, const int pos_x, const int pos_y, const COLOR color, WINDOW * window) const;

	WINDOW * getMainWindow() const;
	WINDOW * getPlayerWindow() const;
	WINDOW * getCombatLogWindow() const;
	WINDOW * getMainMenuWindo() const;

private:
	WINDOW * gameWindow;
	WINDOW * playerWindow;
	WINDOW * combatLogWindow;
	WINDOW * mainMenuWindow;

	int main_window_size_x;
	int main_window_size_y;

	int combat_log_window_size_x;
	int combat_log_window_size_y;

	int player_window_size_x;
	int player_window_size_y;

	int game_window_size_min_x;
	int game_window_size_min_y;
	int game_window_size_max_x;
	int game_window_size_max_y;
};
