// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "GameEngine.h"

int main()
{
	GameEngine * engine = new GameEngine;
	Game * game = new Game;

	game->createPlayer("Zodgar");

	game->createRandomMonsters(30);

	engine->clearScreen();
	engine->placeActor(game->player, *game, 1, 1);

	for (auto& i : game->monsters)
		engine->placeActor(i, *game, i.GetCurrentPosX(), i.GetCurrentPosY());
	
	for (auto& i : game->monsters)
		engine->MoveActor(i, *game, DIR::RAND);

	char key_pressed;

	engine->uiPrintPlayerInformations(game->player);
	engine->uiPrintGameInformation(*game);

	engine->createScreen(*game);

	while (1)
	{
		engine->clearScreen();
		key_pressed = getch();

		if(key_pressed == 'w' || key_pressed == 's' || key_pressed == 'a' || key_pressed == 'd')
		{
			game->nextMove();
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

			for (auto& i : game->monsters)
				engine->MoveActor(i, *game, DIR::RAND);
		}
		else if (key_pressed == 'Q')
		{
			delete engine;
			delete game;

			return 0;
		}
		engine->createScreen(*game);
	}

	delete engine;
	delete game;
	
    return 0;
}

