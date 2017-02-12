#pragma once

#include <curses.h>

enum class WINDOW_TYPE { MAIN, UI, TEXT};

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void showMainMenu();
	void createGameInterface();

	WINDOW * getWindow(WINDOW_TYPE window);

	WINDOW * mainWindow;
	WINDOW * uiWindow;
	WINDOW * textWindow;
};

