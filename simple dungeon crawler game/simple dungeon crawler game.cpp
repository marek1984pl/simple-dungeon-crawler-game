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

	engine->createGameInterface();
	engine->placeActor(game->player, *game, 1, 1);

	for (auto& i : game->monsters)
		engine->placeActor(i, *game, i.GetCurrentPosX(), i.GetCurrentPosY());
	
	for (auto& i : game->monsters)
		engine->MoveActor(i, *game, DIR::RAND);

	char key_pressed;

	engine->uiPrintPlayerInformations(game->player);

	engine->DisplayLevel(game->levels[0]);
	engine->refreshGameInterface();

	while (1)
	{
		wclear(engine->GetMainWindow());
		wclear(engine->GetUiWindow());
		wclear(engine->GetTextWindow());

		engine->createGameInterface();

		engine->uiPrintPlayerInformations(game->player);

		key_pressed = getch();

		for (auto& i : game->monsters)
			engine->MoveActor(i, *game, DIR::RAND);

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

		engine->DisplayLevel(game->levels[0]);
		engine->refreshGameInterface();
	}

	delete engine;
	delete game;
	
    return 0;
}

