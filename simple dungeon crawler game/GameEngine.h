#pragma once

#include <curses.h>
#include <ctime>

#include "Level.h"
#include "actor.h"
#include "Game.h"


enum class COLOR { BLACK, GRAY, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DARK_RED, DARK_GREEN, DARK_YELLOW, DARK_BLUE, DARK_MAGENTA, DARK_CYAN, DARK_GRAY };

enum class DIR { UP, DOWN, LEFT, RIGHT, RAND };

enum class UI { CORD_X, CORD_Y, INFO, PLAYER_NAME, PLAYER_LEVEL, PLAYER_XP, PLAYER_GOLD, PLAYER_HP};

class GameEngine
{
public:
	GameEngine();
	GameEngine(const GameEngine & engine);
	GameEngine(GameEngine && engine) noexcept;
	~GameEngine();

	GameEngine & operator=(const GameEngine & engine);
	GameEngine & operator=(GameEngine && engine) noexcept;

	void InitializeGraphics(int window_width, int window_height);

	void createGameInterface();
	void refreshGameInterface() const;

	template <typename T>
	void uiPrint(T msg, UI ui);
	
	void uiPrintPlayerInformations(Player & p);

	void setColor(COLOR color, WINDOW * window);

	void printChar(char char_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);
	void printString(const char * string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);
	void printString(int string_to_print, int pos_x, int pos_y, COLOR color, WINDOW * window);

	void DisplayLevel(Level & lvl);

	bool placeActor(Actor & actor, Game & game, int pos_x, int pos_y);
	bool MoveActor(Actor & actor, Game & game, DIR direction);

	char GetNextTile(int pos_x, int pos_y, Game & game);

	WINDOW * GetMainWindow();
	WINDOW * GetUiWindow();
	WINDOW * GetTextWindow();

private:
	WINDOW * mainWindow;
	WINDOW * playerWindow;
	WINDOW * textWindow;

	char old_tile = '.';
	char next_tile = '.';
};

template <typename T>
void GameEngine::uiPrint(T msg, UI ui)
{
	switch (ui)
	{
	case UI::CORD_X:
		printString("Player X: ", 1, 1, COLOR::YELLOW, textWindow);
		printString(msg, 11, 1, COLOR::YELLOW, textWindow);
		break;
	case UI::CORD_Y:
		printString("Player Y: ", 15, 1, COLOR::YELLOW, textWindow);
		printString(msg, 25, 1, COLOR::YELLOW, textWindow);
		break;
	case UI::INFO:
		printString(msg, 1, 5, COLOR::WHITE, textWindow);
		break;
	case UI::PLAYER_NAME:
		printString(msg, 1, 1, COLOR::CYAN, playerWindow);
		break;
	case UI::PLAYER_HP:
		printString("Health: ", 20, 1, COLOR::WHITE, playerWindow);
		printString(msg, 30, 1, COLOR::RED, playerWindow);
		break;
	case UI::PLAYER_LEVEL:
		printString("Level: ", 1, 2, COLOR::WHITE, playerWindow);
		printString(msg, 8, 2, COLOR::CYAN, playerWindow);
		break;
	case UI::PLAYER_XP:
		printString("Experience: ", 1, 3, COLOR::WHITE, playerWindow);
		printString(msg, 13, 3, COLOR::CYAN, playerWindow);
		break;
	case UI::PLAYER_GOLD:
		printString("Gold: ", 1, 3, COLOR::WHITE, playerWindow);
		printString(msg, 7, 3, COLOR::CYAN, playerWindow);
		break;
	default:
		break;
	}
}