// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "GameEngine.h"

int main()
{
	GameEngine * engine = new GameEngine;
	Game * game = new Game;

	engine->createGameInterface();

	engine->placeActor(game->player, *game, 1, 1);
	
	engine->DisplayLevel(game->levels[0]);
	engine->refreshGameInterface();

	char key_pressed;

	while (1)
	{
		wclear(engine->GetMainWindow());
		wclear(engine->GetUiWindow());
		wclear(engine->GetTextWindow());

		engine->createGameInterface();

		key_pressed = getch();
		engine->printChar(key_pressed, 1, 1, COLOR::RED, engine->GetTextWindow());
		engine->printString(game->player.getName().c_str(), 1, 1, COLOR::CYAN, engine->GetUiWindow());
		engine->printString("LEVEL: ", 1, 2, COLOR::GRAY, engine->GetUiWindow());
		engine->printString(game->player.getLevel(), 8, 2, COLOR::CYAN, engine->GetUiWindow());

		if (key_pressed == 's')
		{
			engine->MoveActor(game->player, *game, DIR::DOWN);
		}
		if (key_pressed == 'w')
		{
			engine->MoveActor(game->player, *game, DIR::UP);
		}
		if (key_pressed == 'a')
		{
			engine->MoveActor(game->player, *game, DIR::LEFT);
		}
		if (key_pressed == 'd')
		{
			engine->MoveActor(game->player, *game, DIR::RIGHT);
		}
		if (key_pressed == 'Q')
		{
			return 0;
		}
		
		engine->printString("POS X: ", 1, 2, COLOR::YELLOW, engine->GetTextWindow());
		engine->printString(game->player.GetCurrentPosX(), 8, 2, COLOR::YELLOW, engine->GetTextWindow());
		engine->printString("POS Y: ", 1, 3, COLOR::YELLOW, engine->GetTextWindow());
		engine->printString(game->player.GetCurrentPosY(), 8, 3, COLOR::YELLOW, engine->GetTextWindow());

		engine->DisplayLevel(game->levels[0]);
		engine->refreshGameInterface();
	}

	delete engine;
	delete game;

    return 0;
}

