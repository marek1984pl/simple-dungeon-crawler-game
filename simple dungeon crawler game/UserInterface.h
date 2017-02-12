#pragma once

#include <curses.h>

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void showMainMenu();
	void createGameInterface(WINDOW * main, WINDOW * ui, WINDOW * text);
	void refreshGameInterface(WINDOW * main, WINDOW * ui, WINDOW * text) const;
};

