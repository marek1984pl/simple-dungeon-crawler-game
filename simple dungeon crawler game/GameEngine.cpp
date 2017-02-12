#include "stdafx.h"
#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine()
{
}

GameEngine::GameEngine(UserInterface * _ui)
{
	ui = _ui;
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
	//use_default_colors();

	resize_term(window_height, window_width);

	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	init_pair(9, 0, COLOR_BLACK);
	init_pair(10, 1, COLOR_BLACK);
	init_pair(11, 2, COLOR_BLACK);
	init_pair(12, 3, COLOR_BLACK);
	init_pair(13, 4, COLOR_BLACK);
	init_pair(14, 5, COLOR_BLACK);
	init_pair(15, 6, COLOR_BLACK);
}

void GameEngine::setColor(COLOR color, WINDOW_TYPE window)
{
	switch (color)
	{
	case COLOR::BLACK:
		wattrset(ui->getWindow(window), COLOR_PAIR(1));
		break;
	case COLOR::GRAY:
		wattrset(ui->getWindow(window), COLOR_PAIR(9) | A_BOLD);
		break;
	case COLOR::RED:
		wattrset(ui->getWindow(window), COLOR_PAIR(2) | A_BOLD);
		break;
	case COLOR::GREEN:
		wattrset(ui->getWindow(window), COLOR_PAIR(3) | A_BOLD);
		break;
	case COLOR::YELLOW:
		wattrset(ui->getWindow(window), COLOR_PAIR(4) | A_BOLD);
		break;
	case COLOR::BLUE:
		wattrset(ui->getWindow(window), COLOR_PAIR(5) | A_BOLD);
		break;
	case COLOR::MAGENTA:
		wattrset(ui->getWindow(window), COLOR_PAIR(6) | A_BOLD);
		break;
	case COLOR::CYAN:
		wattrset(ui->getWindow(window), COLOR_PAIR(7) | A_BOLD);
		break;
	case COLOR::WHITE:
		wattrset(ui->getWindow(window), COLOR_PAIR(8) | A_BOLD);
		break;
	case COLOR::DARK_RED:
		wattrset(ui->getWindow(window), COLOR_PAIR(13));
		break;
	case COLOR::DARK_GREEN:
		wattrset(ui->getWindow(window), COLOR_PAIR(11));
		break;
	case COLOR::DARK_YELLOW:
		wattrset(ui->getWindow(window), COLOR_PAIR(15));
		break;
	case COLOR::DARK_BLUE:
		wattrset(ui->getWindow(window), COLOR_PAIR(10));
		break;
	case COLOR::DARK_MAGENTA:
		wattrset(ui->getWindow(window), COLOR_PAIR(14));
		break;
	case COLOR::DARK_CYAN:
		wattrset(ui->getWindow(window), COLOR_PAIR(12));
		break;
	default:
		break;
	}
}

void GameEngine::printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW_TYPE window)
{
	setColor(color, window);
	mvwaddch(ui->getWindow(window), pos_y, pos_x, char_to_print);
	wrefresh(ui->getWindow(window));
}
