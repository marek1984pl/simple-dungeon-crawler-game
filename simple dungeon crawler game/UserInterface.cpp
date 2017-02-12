#include "stdafx.h"
#include "UserInterface.h"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{

}

void UserInterface::showMainMenu()
{
}

void UserInterface::createGameInterface(WINDOW * main, WINDOW * ui, WINDOW * text)
{
	box(main, 0, 0);
	box(ui, 0, 0);
	box(text, 0, 0);
}

void UserInterface::refreshGameInterface(WINDOW * main, WINDOW * ui, WINDOW * text) const
{
	wrefresh(main);
	wrefresh(ui);
	wrefresh(text);
}


