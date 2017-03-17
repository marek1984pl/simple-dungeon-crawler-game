#include "stdafx.h"
#include "UserInterface.h"

UserInterface::UserInterface(int window_width, int window_height)
{
	main_window_size_x = window_width;
	main_window_size_y = window_height;

	combat_log_window_size_x = 50;
	combat_log_window_size_y = 10;

	player_window_size_x = 50;
	player_window_size_y = 40;

	game_window_size_min_x = 1;
	game_window_size_min_y = 1;
	game_window_size_max_x = main_window_size_x - 50;
	game_window_size_max_y = main_window_size_y;

	initializeGraphics(main_window_size_x, main_window_size_y);
}

UserInterface::~UserInterface()
{
	delwin(gameWindow);
	delwin(playerWindow);
	delwin(combatLogWindow);
	delwin(mainMenuWindow);
	endwin();
}

int UserInterface::createMainMenu()
{
	std::string tmp;
	auto next_line = 0;
	char option;

	mainMenuWindow = newwin(main_window_size_y, main_window_size_x, 0, 0);
	setColor(COLOR::DARK_GREEN, mainMenuWindow);
	box(mainMenuWindow, 0, 0);
	setColor(COLOR::GREEN, mainMenuWindow);

	std::ifstream fin(".\\data\\logo.txt");
	while (!fin.eof())
	{
		std::getline(fin, tmp);
		printString(tmp.c_str(), (main_window_size_x - tmp.size()) / 2, 7 + next_line++, COLOR::GREEN, mainMenuWindow);
	}

	std::string opt1 = "1) New game";
	std::string opt2 = "2) Quit game";

	printString(opt1.c_str(), (main_window_size_x - opt1.size()) / 2, 25, COLOR::RED, mainMenuWindow);
	printString(opt2.c_str(), (main_window_size_x - opt2.size()) / 2, 26, COLOR::RED, mainMenuWindow);

	wrefresh(mainMenuWindow);

	fin.close();

	while (true)
	{
		option = getch();

		switch (option)
		{
		case '1':
			return 0;
		case '2':
			return -1;
		default:
			break;
		}
	}
}

void UserInterface::createEndScreen(Game & g)
{
	mainMenuWindow = newwin(main_window_size_y, main_window_size_x, 0, 0);
	setColor(COLOR::DARK_GREEN, mainMenuWindow);
	box(mainMenuWindow, 0, 0);
	setColor(COLOR::GREEN, mainMenuWindow);

	printString("GAME OVER!", 190 / 2, 15, COLOR::RED, mainMenuWindow);

	std::string msg = "You was level " + std::to_string(g.player.getLevel());
	printString(msg.c_str(), (main_window_size_x - msg.size()) / 2, 20, COLOR::RED, mainMenuWindow);

	msg = "You had " + std::to_string(g.player.getGold()) + " gold coins.";
	printString(msg.c_str(), (main_window_size_x - msg.size()) / 2, 21, COLOR::YELLOW, mainMenuWindow);

	msg = "You died after " + std::to_string(g.getNumberOfMoves()) + " moves!";
	printString(msg.c_str(), (main_window_size_x - msg.size()) / 2, 22, COLOR::WHITE, mainMenuWindow);

	auto line = 30;

	for (auto & i : g.c_log.getLog())
	{
		printString(i.c_str(), 20, line++, COLOR::WHITE, mainMenuWindow);
	}

	msg = "Press q to exit";
	printString(msg.c_str(), (main_window_size_x - msg.size()) / 2, 48, COLOR::MAGENTA, mainMenuWindow);

	wrefresh(mainMenuWindow);
}

void UserInterface::createGameInterface()
{
	gameWindow = newwin(game_window_size_max_y, game_window_size_max_x, 0, 0);
	playerWindow = newwin(player_window_size_y, player_window_size_x, 0, 150);
	combatLogWindow = newwin(combat_log_window_size_y, combat_log_window_size_x, 40, 150);
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
	wclear(getCombatLogWindow());

	setColor(COLOR::WHITE, gameWindow);
	setColor(COLOR::WHITE, playerWindow);
	setColor(COLOR::WHITE, combatLogWindow);

	box(gameWindow, 0, 0);
	box(playerWindow, 0, 0);
	box(combatLogWindow, 0, 0);
}

void UserInterface::refreshScreen() const
{
	wrefresh(gameWindow);
	wrefresh(playerWindow);
	wrefresh(combatLogWindow);
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

	printString(g.player.getStrengthFromItems(), 20, 7, COLOR::GREEN, playerWindow);
	printString(g.player.getDexterityFromItems(), 20, 8, COLOR::GREEN, playerWindow);
	printString(g.player.getStaminaFromItems(), 20, 9, COLOR::GREEN, playerWindow);

	printString(g.player.getTotalStrength(), 24, 7, COLOR::CYAN, playerWindow);
	printString(g.player.getTotalDexterity(), 24, 8, COLOR::CYAN, playerWindow);
	printString(g.player.getTotalStamina(), 24, 9, COLOR::CYAN, playerWindow);

	printString("Gold: ", 1, 11, COLOR::WHITE, playerWindow);
	printString(g.player.getGold(), 7, 11, COLOR::YELLOW, playerWindow);

	std::string tmp = "";
	auto pos = 13;

	for (auto i = g.player.getBackpack().begin(); i != g.player.getBackpack().end(); ++i)
	{
		tmp = "Backpack : " + i->getName();
		printString(tmp.c_str(), 1, pos, COLOR::WHITE, playerWindow);
		++pos;
	}

	printString("STR / DEX / STA", 33, 19, COLOR::YELLOW, playerWindow);

	printItemInfo(g.player.getItemFromInventory(Item_Type::WEAPON), 20);
	printItemInfo(g.player.getItemFromInventory(Item_Type::SHIELD), 21);
	printItemInfo(g.player.getItemFromInventory(Item_Type::ARMOR), 22);
	printItemInfo(g.player.getItemFromInventory(Item_Type::HELMET), 23);
	printItemInfo(g.player.getItemFromInventory(Item_Type::LEGS), 24);
	printItemInfo(g.player.getItemFromInventory(Item_Type::SHOULDERS), 25);
	printItemInfo(g.player.getItemFromInventory(Item_Type::GLOVES), 26);
	printItemInfo(g.player.getItemFromInventory(Item_Type::BOOTS), 27);

	printString("Dungeon level: ", 1, 37, COLOR::WHITE, playerWindow);
	printString(g.getCurrentLevel() + 1, 16, 37, COLOR::WHITE, playerWindow);

	printString("Player X: ", 1, 38, COLOR::YELLOW, playerWindow);
	printString(g.player.getCurrentPosX(), 11, 38, COLOR::YELLOW, playerWindow);
	printString("Player Y: ", 15, 38, COLOR::YELLOW, playerWindow);
	printString(g.player.getCurrentPosY(), 25, 38, COLOR::YELLOW, playerWindow);

	printString("Move number: ", 30, 38, COLOR::WHITE, playerWindow);
	printString(g.getNumberOfMoves(), 44, 38, COLOR::WHITE, playerWindow);
}

void UserInterface::printItemInfo(Item & item, int line_to_print) const
{
	std::string new_string;

	if (item.getType() != Item_Type::EMPTY)
	{
		switch (item.getType())
		{
		case Item_Type::WEAPON:
			new_string = "Weapon    : ";
			break;
		case Item_Type::SHIELD:
			new_string = "Shield    : ";
			break;
		case Item_Type::ARMOR:
			new_string = "Armor     : ";
			break;
		case Item_Type::HELMET:
			new_string = "Helmet    : ";
			break;
		case Item_Type::LEGS:
			new_string = "Legs      : ";
			break;
		case Item_Type::SHOULDERS:
			new_string = "Shoulders : ";
			break;
		case Item_Type::GLOVES:
			new_string = "Gloves    : ";
			break;
		case Item_Type::BOOTS:
			new_string = "Boots     : ";
			break;
		default:
			break;
		}

		COLOR quality_color = COLOR::WHITE;

		switch (item.getQuality())
		{
		case Quality::NORMAL:
			quality_color = COLOR::WHITE;
			break;
		case Quality::MAGIC:
			quality_color = COLOR::GREEN;
			break;
		case Quality::RARE:
			quality_color = COLOR::BLUE;
			break;
		case Quality::EPIC:
			quality_color = COLOR::MAGENTA;
			break;
		}

		printString(new_string.c_str(), 1, line_to_print, COLOR::WHITE, playerWindow);
		new_string = item.getName();
		printString(new_string.c_str(), 13, line_to_print, quality_color, playerWindow);
		new_string = std::to_string(item.getStrength()) + "     " + std::to_string(item.getDexterity()) + "     " + std::to_string(item.getStamina());
		printString(new_string.c_str(), 34, line_to_print, quality_color, playerWindow);
	}
}

void UserInterface::printLog(CombatLog c_log) const
{
	auto line = 1;
	for (auto & i : c_log.getLog())
	{
		printString(i.c_str(), 1, line++, COLOR::WHITE, combatLogWindow);
	}
}

void UserInterface::setColor(COLOR color, WINDOW* window) const
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

	for (auto i = game_window_size_min_y - 1; i < game_window_size_max_y - 2; i++)
	{
		for (auto j = game_window_size_min_x - 1; j < game_window_size_max_x - 2; j++)
		{
			current_tile = game.levels[game.getCurrentLevel()].getMapTile(j, i);
			current_tile_type = current_tile.getType();
			char monster_type;

			switch (current_tile_type)
			{
			case TILE_TYPE::PLAYER:
				printChar('@', j + 1, i + 1, COLOR::CYAN, gameWindow);
				break;
			case TILE_TYPE::WALL:
				printChar('#', j + 1, i + 1, COLOR::GRAY, gameWindow);
				break;
			case TILE_TYPE::WATER:
				printChar('~', j + 1, i + 1, COLOR::BLUE, gameWindow);
				break;
			case TILE_TYPE::TREE:
				printChar('T', j + 1, i + 1, COLOR::GREEN, gameWindow);
				break;
			case TILE_TYPE::EMPTY:
				printChar('.', j + 1, i + 1, COLOR::BLACK, gameWindow);
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
				printChar(monster_type, j + 1, i + 1, COLOR::RED, gameWindow);
				break;
			case TILE_TYPE::TREASURE:
				printChar('$', j + 1, i + 1, COLOR::YELLOW, gameWindow);
				break;
			case TILE_TYPE::CORPSE:
				printChar('x', j + 1, i + 1, COLOR::WHITE, gameWindow);
				break;
			case TILE_TYPE::LEVEL_DOWN:
				printChar('>', j + 1, i + 1, COLOR::MAGENTA, gameWindow);
				break;
			case TILE_TYPE::LEVEL_UP:
				printChar('<', j + 1, i + 1, COLOR::MAGENTA, gameWindow);
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
	return gameWindow;
}

WINDOW * UserInterface::getPlayerWindow() const
{
	return playerWindow;;
}

WINDOW * UserInterface::getCombatLogWindow() const
{
	return combatLogWindow;
}

WINDOW * UserInterface::getMainMenuWindo() const
{
	return mainMenuWindow;
}
