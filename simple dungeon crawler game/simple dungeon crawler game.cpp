// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "curses.h"

int main()
{
	Game game;
	game.ShowLevel();

	/*
	initscr();
	raw();
	noecho();
	if (has_colors() != TRUE)
	{
		printw("Konsola nie obs³uguje kolorów!");
		getch();
		exit(0);
	}
	start_color();
	use_default_colors();

	resize_term(50, 200);

	for (int i = 0; i < 255; ++i)
	{
		init_pair(i, i, COLOR_BLACK);
		
		attron(COLOR_PAIR(i));
		printw("%d ", i);
		printw("Xxxxxxxxxx\n");

		refresh();
	}
	*/

	while (1)
	{
		refresh();
		if (getch() == 'q' || getch() == 'Q')
			exit(0);
	}

    return 0;
}

