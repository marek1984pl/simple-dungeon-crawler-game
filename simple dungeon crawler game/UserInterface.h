#pragma once

#include <curses.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Game.h"

enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

class UserInterface
{
public:
	UserInterface(int window_width, int window_height);
	~UserInterface();

	int createMainMenu();
	void createEndScreen(Game & g);
	void createGameInterface();

	bool initializeGraphics(int window_width, int window_height) const;

	void clearScreen() const;
	void updateScreen(Game & game) const;
	void refreshScreen() const;

	void updateInterface(Game & g) const;

	void printItemInfo(Item & item, int line_to_print) const;
	void printLog(CombatLog c_log) const;

	void setColor(COLOR color, WINDOW * window) const;

	void printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const;
	void printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const;
	void printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const;

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

