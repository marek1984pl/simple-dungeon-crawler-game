#include "stdafx.h"
#include "UserInterface.h"


UserInterface::UserInterface()
{
	initializeGraphics(200, 50);

	mainWindow = newwin(50, 150, 0, 0);
	playerWindow = newwin(40, 50, 0, 150);
	textWindow = newwin(10, 50, 40, 150);
}

UserInterface::~UserInterface()
{
	delwin(mainWindow);
	delwin(playerWindow);
	delwin(textWindow);
	endwin();
}

bool UserInterface::initializeGraphics(int window_width, int window_height) const
{
	initscr();
	raw();
	noecho();
	cbreak();
	keypad(stdscr, true);

	if (has_colors() != TRUE)
	{
		printw("No colors in console!");
		getch();
		return false;
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

	return true;
}

void UserInterface::clearScreen() const
{
	wclear(getMainWindow());
	wclear(getPlayerWindow());
	wclear(getTextWindow());

	setColor(COLOR::WHITE, mainWindow);
	setColor(COLOR::WHITE, playerWindow);
	setColor(COLOR::WHITE, textWindow);

	box(mainWindow, 0, 0);
	box(playerWindow, 0, 0);
	box(textWindow, 0, 0);
}

void UserInterface::refreshScreen() const
{
	wrefresh(mainWindow);
	wrefresh(playerWindow);
	wrefresh(textWindow);
}

void UserInterface::updateInterface(Game & g) const
{
	printString(g.player.getName().c_str(), 1, 1, COLOR::CYAN, playerWindow);

	printString("Health: ", 20, 1, COLOR::WHITE, playerWindow);
	printString(g.player.getHealth(), 28, 1, COLOR::RED, playerWindow);
	printString(" / ", 30, 1, COLOR::WHITE, playerWindow);
	printString(g.player.getMaxHealth(), 33, 1, COLOR::RED, playerWindow);

	printString("Level: ", 1, 2, COLOR::WHITE, playerWindow);
	printString(g.player.getLevel(), 8, 2, COLOR::CYAN, playerWindow);

	printString("Experience: ", 1, 3, COLOR::WHITE, playerWindow);
	printString(g.player.getExp(), 13, 3, COLOR::CYAN, playerWindow);
	printString(" / ", 17, 3, COLOR::WHITE, playerWindow);
	printString(g.player.exp_to_lvl_up[g.player.getLevel() + 1], 20, 3, COLOR::CYAN, playerWindow);

	printString("Attack power : ", 1, 5, COLOR::WHITE, playerWindow);
	printString(g.player.getAttackPower(), 16, 5, COLOR::WHITE, playerWindow);
	printString("Armor        : ", 1, 6, COLOR::WHITE, playerWindow);
	printString(g.player.getArmor(), 16, 6, COLOR::WHITE, playerWindow);
	printString("Strength     : ", 1, 7, COLOR::WHITE, playerWindow);
	printString(g.player.getStrength(), 16, 7, COLOR::WHITE, playerWindow);
	printString("Dexterity    : ", 1, 8, COLOR::WHITE, playerWindow);
	printString(g.player.getDexterity(), 16, 8, COLOR::WHITE, playerWindow);
	printString("Stamina      : ", 1, 9, COLOR::WHITE, playerWindow);
	printString(g.player.getStamina(), 16, 9, COLOR::WHITE, playerWindow);

	printString("Gold: ", 1, 11, COLOR::WHITE, playerWindow);
	printString(g.player.getGold(), 7, 11, COLOR::YELLOW, playerWindow);

	printString("Player X: ", 1, 1, COLOR::YELLOW, textWindow);
	printString(g.player.getCurrentPosX(), 11, 1, COLOR::YELLOW, textWindow);
	printString("Player Y: ", 15, 1, COLOR::YELLOW, textWindow);
	printString(g.player.getCurrentPosY(), 25, 1, COLOR::YELLOW, textWindow);

	printString("Move number: ", 30, 1, COLOR::WHITE, textWindow);
	printString(g.getNumberOfMoves(), 44, 1, COLOR::WHITE, textWindow);
}

void UserInterface::printInfo(std::string text, int line)
{
	printString(text.c_str(), 1, 4 + line, COLOR::WHITE, textWindow);
}

void UserInterface::setColor(COLOR color, WINDOW * window) const
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

void UserInterface::printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%c", char_to_print);
}

void UserInterface::printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%s", string_to_print);
}

void UserInterface::printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%d", string_to_print);
}

void UserInterface::updateScreen(Game & game) const
{
	TILE_TYPE current_tile_type;
	Tile current_tile;

	for (auto i = 0; i < 48; i++)
	{
		for (auto j = 0; j < 148; j++)
		{
			current_tile = game.levels[0].getMapTile(j, i);
			current_tile_type = current_tile.getType();
			char monster_type = 'M';

			switch (current_tile_type)
			{
			case TILE_TYPE::PLAYER:
				printChar('@', j + 1, i + 1, COLOR::CYAN, mainWindow);
				break;
			case TILE_TYPE::WALL:
				printChar('#', j + 1, i + 1, COLOR::GRAY, mainWindow);
				break;
			case TILE_TYPE::WATER:
				printChar('~', j + 1, i + 1, COLOR::BLUE, mainWindow);
				break;
			case TILE_TYPE::TREE:
				printChar('T', j + 1, i + 1, COLOR::GREEN, mainWindow);
				break;
			case TILE_TYPE::EMPTY:
				printChar('.', j + 1, i + 1, COLOR::BLACK, mainWindow);
				break;
			case TILE_TYPE::MONSTER:
				switch (game.getMonster(j, i).getMonsterType())
				{
				case MONSTER_TYPE::GOBLIN:
					monster_type = 'G';
					break;
				case MONSTER_TYPE::WOLF:
					monster_type = 'W';
					break;
				case MONSTER_TYPE::BANDIT:
					monster_type = 'B';
					break;
				case MONSTER_TYPE::SNAKE:
					monster_type = 'S';
					break;
				case MONSTER_TYPE::TROLL:
					monster_type = 'R';
					break;
				default:
					monster_type = 'M';
					break;
				}
				printChar(monster_type, j + 1, i + 1, COLOR::RED, mainWindow);
				break;
			case TILE_TYPE::TREASURE:
				printChar('$', j + 1, i + 1, COLOR::YELLOW, mainWindow);
				break;
			case TILE_TYPE::CORPSE:
				printChar('x', j + 1, i + 1, COLOR::WHITE, mainWindow);
				break;
			default:
				break;
			}
		}
	}
	refreshScreen();
}

WINDOW * UserInterface::getMainWindow() const
{
	return mainWindow;
}

WINDOW * UserInterface::getPlayerWindow() const
{
	return playerWindow;;
}

WINDOW * UserInterface::getTextWindow() const
{
	return textWindow;
}