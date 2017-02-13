#include "stdafx.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
	srand(static_cast<int>(time(nullptr)));

	InitializeGraphics(200, 50);

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

void GameEngine::InitializeGraphics(int window_width, int window_height)
{
	initscr();
	raw();
	noecho();
	cbreak();
	keypad(stdscr, true);

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

void GameEngine::uiPrintPlayerInformations(Player & p)
{
	uiPrint(p.GetCurrentPosX(), UI::CORD_X);
	uiPrint(p.GetCurrentPosY(), UI::CORD_Y);
	uiPrint(p.getName().c_str(), UI::PLAYER_NAME);
	uiPrint(p.getLevel(), UI::PLAYER_LEVEL);
	uiPrint(p.getHealth(), UI::PLAYER_HP);
	uiPrint(p.GetGold(), UI::PLAYER_GOLD);
	uiPrint(p.GetXP(), UI::PLAYER_XP);
}

void GameEngine::uiPrintGameInformation(Game & g)
{
	uiPrint(g.getNumberOfMoves(), UI::MOVE_NO);
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

void GameEngine::createScreen(Game & g)
{
	char tile;
	for (auto i = 0; i < 48; i++)
	{
		for (auto j = 0; j < 148; j++)
		{
			tile = g.levels[0].lvl_data[i][j];
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
				//printChar(tile, j + 1, i + 1, COLOR::YELLOW, mainWindow);
				break;
			default:
				printChar(tile, j + 1, i + 1, COLOR::YELLOW, mainWindow);
				break;
			}
		}
	}
	refreshScreen();
}

bool GameEngine::placeActor(Actor & actor, Game & game, int pos_x, int pos_y)
{
	actor.SetCurrentPos(pos_x, pos_y);
	actor.SetOldPos(pos_x, pos_y);
	actor.setChanged(false);
	return true;
}

bool GameEngine::MoveActor(Actor & actor, Game & game, DIR direction)
{
	actor.SetOldPos(actor.GetCurrentPosX(), actor.GetCurrentPosY());

	if (direction == DIR::RAND)
	{
		int rand_dir = rand() % 4;
		direction = static_cast<DIR>(rand_dir);
	}

	switch (direction)
	{
	case DIR::UP:
		actor.SetCurrentPos(actor.GetOldPosX(), actor.GetOldPosY() - 1);
		break;
	case DIR::DOWN:
		actor.SetCurrentPos(actor.GetOldPosX(), actor.GetOldPosY() + 1);
		break;
	case DIR::LEFT:
		actor.SetCurrentPos(actor.GetOldPosX() - 1, actor.GetOldPosY());
		break;
	case DIR::RIGHT:
		actor.SetCurrentPos(actor.GetOldPosX() + 1, actor.GetOldPosY());
		break;
	default:
		break;
	}

	next_tile = GetNextTile(actor.GetCurrentPosX(), actor.GetCurrentPosY(), game);

	switch (next_tile)
	{
	case '#':
		actor.SetCurrentPos(actor.GetOldPosX(), actor.GetOldPosY());
		if(typeid(actor) == typeid(Player))
			uiPrint("You run into a wall!", UI::INFO);
		actor.setChanged(false);
		break;
	case '~':
		actor.SetCurrentPos(actor.GetOldPosX(), actor.GetOldPosY());
		if(typeid(actor) == typeid(Player))
			uiPrint("You cannot go into water!", UI::INFO);
		actor.setChanged(false);
		break;
	case 'T':
		actor.SetCurrentPos(actor.GetOldPosX(), actor.GetOldPosY());
		if(typeid(actor) == typeid(Player))
			uiPrint("You run into a tree!", UI::INFO);
		actor.setChanged(false);
		break;
	case 'g':
	case 'w':
	case 'b':
	case 's':
	case 't':
	//case '@':
		//uiPrint("Monster attacked!", UI::INFO);
		break;
	case '$':
		//uiPrint("Treasue!", UI::INFO);
		break;
	default:
		// TODO: change this
		game.levels[0].lvl_data[actor.GetCurrentPosY()][actor.GetCurrentPosX()] = actor.getGraphicTile();
		game.levels[0].lvl_data[actor.GetOldPosY()][actor.GetOldPosX()] = old_tile;
		actor.setChanged(true);
		break;
	}
	uiPrintPlayerInformations(game.player);
	uiPrintGameInformation(game);
	return true;
}

char GameEngine::GetNextTile(int pos_x, int pos_y, Game & game)
{
	// TODO: change this
	return game.levels[0].lvl_data[pos_y][pos_x];
}

WINDOW * GameEngine::GetMainWindow()
{
	return mainWindow;
}

WINDOW * GameEngine::GetUiWindow()
{
	return playerWindow;;
}

WINDOW * GameEngine::GetTextWindow()
{
	return textWindow;
}

void GameEngine::clearScreen()
{
	wclear(GetMainWindow());
	wclear(GetUiWindow());
	wclear(GetTextWindow());

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
