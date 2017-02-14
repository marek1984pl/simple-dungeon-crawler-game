#include "stdafx.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
	srand(static_cast<int>(time(nullptr)));

	initializeGraphics(200, 50);

	mainWindow = newwin(50, 150, 0, 0);
	playerWindow = newwin(40, 50, 0, 150);
	textWindow = newwin(10, 50, 40, 150);
}

GameEngine::GameEngine(const GameEngine & engine)
{
	delwin(mainWindow);
	delwin(playerWindow);
	delwin(textWindow);

	old_tile = engine.old_tile;
	next_tile = engine.next_tile;

	mainWindow = engine.mainWindow;
	playerWindow = engine.playerWindow;
	textWindow = engine.textWindow;
}

GameEngine::GameEngine(GameEngine && engine) noexcept
{
	delwin(mainWindow);
	delwin(playerWindow);
	delwin(textWindow);

	old_tile = engine.old_tile;
	next_tile = engine.next_tile;

	mainWindow = engine.mainWindow;
	playerWindow = engine.playerWindow;
	textWindow = engine.textWindow;

	old_tile = 0;
	next_tile = 0;
	delwin(engine.mainWindow);
	delwin(engine.playerWindow);
	delwin(engine.textWindow);
}

GameEngine::~GameEngine()
{
	delwin(mainWindow);
	delwin(playerWindow);
	delwin(textWindow);
	endwin();
}

GameEngine & GameEngine::operator=(const GameEngine & engine)
{
	if (this == &engine)
		return *this;

	delwin(mainWindow);
	delwin(playerWindow);
	delwin(textWindow);

	old_tile = engine.old_tile;
	next_tile = engine.next_tile;

	mainWindow = engine.mainWindow;
	playerWindow = engine.playerWindow;
	textWindow = engine.textWindow;

	return *this;
}

GameEngine & GameEngine::operator=(GameEngine && engine) noexcept
{
	if (this == &engine)
		return *this;

	delwin(mainWindow);
	delwin(playerWindow);
	delwin(textWindow);

	old_tile = engine.old_tile;
	next_tile = engine.next_tile;

	mainWindow = engine.mainWindow;
	playerWindow = engine.playerWindow;
	textWindow = engine.textWindow;

	old_tile = 0;
	next_tile = 0;
	delwin(engine.mainWindow);
	delwin(engine.playerWindow);
	delwin(engine.textWindow);

	return *this;
}

bool GameEngine::initializeGraphics(int window_width, int window_height) const
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
	
	return false;
}

void GameEngine::refreshInterface(Game & g) const
{
	printString(g.player.getName().c_str(), 1, 1, COLOR::CYAN, playerWindow);

	printString("Health: ", 20, 1, COLOR::WHITE, playerWindow);
	printString(g.player.getHealth(), 30, 1, COLOR::RED, playerWindow);

	printString("Level: ", 1, 2, COLOR::WHITE, playerWindow);
	printString(g.player.getLevel(), 8, 2, COLOR::CYAN, playerWindow);

	printString("Experience: ", 1, 3, COLOR::WHITE, playerWindow);
	printString(g.player.getExp(), 13, 3, COLOR::CYAN, playerWindow);

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

void GameEngine::printInfo(std::string text, int line)
{
	printString(text.c_str(), 1, 4 + line, COLOR::WHITE, textWindow);
}

void GameEngine::setColor(COLOR color, WINDOW * window) const
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

void GameEngine::printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%c", char_to_print);
}

void GameEngine::printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%s", string_to_print);
}

void GameEngine::printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window) const
{
	setColor(color, window);
	mvwprintw(window, pos_y, pos_x, "%d", string_to_print);
}

void GameEngine::createScreen(Game & game) const
{
	char tile;
	for (auto i = 0; i < 48; i++)
	{
		for (auto j = 0; j < 148; j++)
		{
			tile = game.levels[0].lvl_data[i][j];
			switch (tile)
			{
			case '@':
				printChar(tile, j + 1, i + 1, COLOR::CYAN, mainWindow);
				break;
			case '#':
				printChar(tile, j + 1, i + 1, COLOR::GRAY, mainWindow);
				break;
			case '~':
				printChar(tile, j + 1, i + 1, COLOR::BLUE, mainWindow);
				break;
			case 'T':
				printChar(tile, j + 1, i + 1, COLOR::GREEN, mainWindow);
				break;
			case '.':
				printChar(tile, j + 1, i + 1, COLOR::BLACK, mainWindow);
				break;
			case 'g':
			case 'w':
			case 'b':
			case 's':
			case 't':
				printChar(tile, j + 1, i + 1, COLOR::RED, mainWindow);
				break;
			case '$':
				printChar(tile, j + 1, i + 1, COLOR::YELLOW, mainWindow);
				break;
			default:
				printChar(tile, j + 1, i + 1, COLOR::YELLOW, mainWindow);
				break;
			}
		}
	}
	refreshScreen();
}

bool GameEngine::placeActor(Actor & actor, Game & game, int pos_x, int pos_y) const
{
	actor.setCurrentPos(pos_x, pos_y);
	actor.setOldPos(pos_x, pos_y);
	actor.setNewPos(pos_x, pos_y);
	actor.setChanged(false);
	return true;
}

bool GameEngine::MoveActor(Actor & actor, Game & game, DIR direction)
{
	actor.setOldPos(actor.getCurrentPosX(), actor.getCurrentPosY());
	old_tile = getTile(actor.getCurrentPosX(), actor.getCurrentPosY(), game);

	if (direction == DIR::RAND)
	{
		int rand_dir = rand() % 4;
		direction = static_cast<DIR>(rand_dir);
	}

	switch (direction)
	{
	case DIR::UP:
		actor.setNewPos(actor.getCurrentPosX(), actor.getCurrentPosY() - 1);
		break;
	case DIR::DOWN:
		actor.setNewPos(actor.getCurrentPosX(), actor.getCurrentPosY() + 1);
		break;
	case DIR::LEFT:
		actor.setNewPos(actor.getCurrentPosX() - 1, actor.getCurrentPosY());
		break;
	case DIR::RIGHT:
		actor.setNewPos(actor.getCurrentPosX() + 1, actor.getCurrentPosY());
		break;
	default:
		break;
	}

	next_tile = getTile(actor.getNewPosX(), actor.getNewPosY(), game);

	switch (next_tile)
	{
	case '#':
		actor.setCurrentPos(actor.getOldPosX(), actor.getOldPosY());
		if(typeid(actor) == typeid(Player))
			printInfo("You run into a wall!");
		actor.setChanged(false);
		break;
	case '~':
		actor.setCurrentPos(actor.getOldPosX(), actor.getOldPosY());
		if(typeid(actor) == typeid(Player))
			printInfo("You cannot go into water!");
		actor.setChanged(false);
		break;
	case 'T':
		actor.setCurrentPos(actor.getOldPosX(), actor.getOldPosY());
		if(typeid(actor) == typeid(Player))
			printInfo("You run into a tree!");
		actor.setChanged(false);
		break;
	case 'g':
	case 'w':
	case 'b':
	case 's':
	case 't':
	case '@':
		if (typeid(actor) == typeid(Player))
		{
			printInfo("Monster attacked!");
		}
		break;
	case '$':
		if (typeid(actor) == typeid(Player))
		{
			printInfo("You found a treasue!");
			printInfo("25 gold coins", 1);
			setTile('.', actor.getNewPosX(), actor.getNewPosY(), game);
			game.player.addExp(10);
			game.player.addGold(25);
		}
		break;
	default:
		actor.setCurrentPos(actor.getNewPosX(), actor.getNewPosY());

		setTile(actor.getGraphicTile(), actor.getCurrentPosX(), actor.getCurrentPosY(), game);
		setTile(next_tile, actor.getOldPosX(), actor.getOldPosY(), game);

		actor.setChanged(true);
		break;
	}

	refreshInterface(game);

	return true;
}

char GameEngine::getTile(int pos_x, int pos_y, Game & game)
{
	// TODO: change this
	return game.levels[0].lvl_data[pos_y][pos_x];
}

void GameEngine::setTile(char new_tile, int pos_x, int pos_y, Game & game)
{
	game.levels[0].lvl_data[pos_y][pos_x] = new_tile;
}

WINDOW * GameEngine::getMainWindow() const
{
	return mainWindow;
}

WINDOW * GameEngine::getPlayerWindow() const
{
	return playerWindow;;
}

WINDOW * GameEngine::getTextWindow() const
{
	return textWindow;
}

void GameEngine::clearScreen() const
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

void GameEngine::refreshScreen() const
{
	wrefresh(mainWindow);
	wrefresh(playerWindow);
	wrefresh(textWindow);
}
