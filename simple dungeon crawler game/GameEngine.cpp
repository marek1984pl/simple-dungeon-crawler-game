#include "stdafx.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
	InitializeGraphics(200, 50);

	mainWindow = newwin(50, 150, 0, 0);
	uiWindow = newwin(40, 50, 0, 150);
	textWindow = newwin(10, 50, 40, 150);
}

GameEngine::~GameEngine()
{
	delwin(mainWindow);
	delwin(uiWindow);
	delwin(textWindow);
	endwin();
}

void GameEngine::InitializeGraphics(int window_width, int window_height)
{
	initscr();
	raw();
	noecho();
	cbreak();

	if (has_colors() != TRUE)
	{
		printw("Konsola nie obs³uguje kolorów!");
		getch();
		exit(0);
	}
	start_color();

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

void GameEngine::setColor(COLOR color, WINDOW * window)
{
	switch (color)
	{
	case COLOR::BLACK:
		wattrset(window, COLOR_PAIR(1));
		break;
	case COLOR::GRAY:
		wattrset(window, COLOR_PAIR(9) | A_BOLD);
		break;
	case COLOR::RED:
		wattrset(window, COLOR_PAIR(2) | A_BOLD);
		break;
	case COLOR::GREEN:
		wattrset(window, COLOR_PAIR(3) | A_BOLD);
		break;
	case COLOR::YELLOW:
		wattrset(window, COLOR_PAIR(4) | A_BOLD);
		break;
	case COLOR::BLUE:
		wattrset(window, COLOR_PAIR(5) | A_BOLD);
		break;
	case COLOR::MAGENTA:
		wattrset(window, COLOR_PAIR(6) | A_BOLD);
		break;
	case COLOR::CYAN:
		wattrset(window, COLOR_PAIR(7) | A_BOLD);
		break;
	case COLOR::WHITE:
		wattrset(window, COLOR_PAIR(8) | A_BOLD);
		break;
	case COLOR::DARK_RED:
		wattrset(window, COLOR_PAIR(13));
		break;
	case COLOR::DARK_GREEN:
		wattrset(window, COLOR_PAIR(11));
		break;
	case COLOR::DARK_YELLOW:
		wattrset(window, COLOR_PAIR(15));
		break;
	case COLOR::DARK_BLUE:
		wattrset(window, COLOR_PAIR(10));
		break;
	case COLOR::DARK_MAGENTA:
		wattrset(window, COLOR_PAIR(14));
		break;
	case COLOR::DARK_CYAN:
		wattrset(window, COLOR_PAIR(12));
		break;
	default:
		break;
	}
}

void GameEngine::printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window)
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%c", char_to_print);
}

void GameEngine::printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window)
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%s", string_to_print);
}

void GameEngine::printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window)
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%d", string_to_print);
}

void GameEngine::DisplayLevel(Level & lvl)
{
	char tile;
	for (auto i = 0; i < 48; i++)
	{
		for (auto j = 0; j < 148; j++)
		{
			tile = lvl.level_data[i][j];
			switch (tile)
			{
			case '@':
				printChar(tile, j + 1, i + 1, COLOR::CYAN, mainWindow);
				break;
			case '#':
				printChar(tile, j + 1, i + 1, COLOR::GRAY, mainWindow);
				break;
			case '.':
				printChar(tile, j + 1, i + 1, COLOR::DARK_GREEN, mainWindow);
				break;
			default:
				printChar(tile, j + 1, i + 1, COLOR::YELLOW, mainWindow);
				break;
			}
		}
	}
}

void GameEngine::UpdateGame(Game & game)
{
	char old_tile = '.';

	if (game.player.isChanged() == true)
	{
		game.levels[0].level_data[game.player.GetOldPositionY()][game.player.GetOldPositionX()] = old_tile;
		game.levels[0].level_data[game.player.GetCurrentPositionY()][game.player.GetCurrentPositionX()] = '@';
		game.player.setChanged(0);
	}
}

void GameEngine::refreshGameInterface(UserInterface & ui)
{
	ui.refreshGameInterface(mainWindow, uiWindow, textWindow);
}

bool GameEngine::MoveActor(Actor & actor, DIR direction)
{
	int actor_new_position_x = actor.GetCurrentPositionX();
	int actor_new_position_y = actor.GetCurrentPositionY();

	int actor_old_position_x = actor.GetCurrentPositionX();
	int actor_old_position_y = actor.GetCurrentPositionY();

	switch (direction)
	{
	case DIR::UP:
		actor_new_position_y -= 1;
		break;
	case DIR::DOWN:
		actor_new_position_y += 1;
		break;
	case DIR::LEFT:
		actor_new_position_x -= 1;
		break;
	case DIR::RIGHT:
		actor_new_position_x += 1;
		break;
	default:
		break;
	}

	actor.SetOldPosition(actor_old_position_x, actor_old_position_y);
	actor.SetCurrentPosition(actor_new_position_x, actor_new_position_y);
	actor.setChanged(1);
	return true;
}
