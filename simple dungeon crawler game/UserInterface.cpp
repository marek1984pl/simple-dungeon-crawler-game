#include "stdafx.h"
#include "UserInterface.h"


UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{
	delwin(mainWindow);
	delwin(uiWindow);
	delwin(textWindow);
}

void UserInterface::showMainMenu()
{
}

void UserInterface::createGameInterface()
{
	mainWindow = newwin(50, 150, 0, 0);
	box(mainWindow, 0, 0);
	wrefresh(mainWindow);

	uiWindow = newwin(40, 50, 0, 150);
	box(uiWindow, 0, 0);
	wrefresh(uiWindow);

	textWindow = newwin(10, 50, 40, 150);
	box(textWindow, 0, 0);
	wrefresh(textWindow);
}

WINDOW * UserInterface::getWindow(WINDOW_TYPE window)
{
	switch (window)
	{
	case WINDOW_TYPE::MAIN:
		return mainWindow;
		break;
	case WINDOW_TYPE::UI:
		return uiWindow;
		break;
	case WINDOW_TYPE::TEXT:
		return textWindow;
		break;
	default:
		return mainWindow;
		break;
	}
}

