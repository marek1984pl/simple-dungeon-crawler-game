// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "curses.h"

int main()
{
	Game game;

	while (1)
	{
		refresh();
		if (getch() == 'q' || getch() == 'Q')
			exit(0);
	}

    return 0;
}

