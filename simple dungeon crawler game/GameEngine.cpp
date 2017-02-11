#include "stdafx.h"
#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
	endwin();
}

void GameEngine::InitializeGraphics(int window_width, int window_height)
{

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
	resize_term(window_width, window_height);

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
}

void GameEngine::setColor(color c)
{
	switch (c)
	{
	case color::GREEN:
		attron(COLOR_PAIR(1));
		break;
	case color::RED:
		attron(COLOR_PAIR(2));
		break;
	case color::BLUE:
		break;
	case color::WHITE:
		break;
	case color::YELLOW:
		break;
	default:
		break;
	}
}
