// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "GameEngine.h"
#include "UserInterface.h"

int main()
{
	GameEngine * engine = new GameEngine;
	Game * game = new Game;
	UserInterface ui;

	RESULT result = RESULT::NONE;

	game->createPlayer("Zodgar");

	game->createRandomMonsters(30);

	engine->placeActor(game->player, *game);

	for (auto& i : game->monsters)
		engine->placeActor(i, *game);
	
	char key_pressed;

	ui.clearScreen();
	ui.updateInterface(*game);
	ui.updateScreen(*game);

	while (true)
	{
		ui.clearScreen();
		game->setGameMesage("");
		game->setFightMesage("");

		key_pressed = getch();

		if (key_pressed == 'w' || key_pressed == 's' || key_pressed == 'a' || key_pressed == 'd')
		{
			game->nextMove();
			if (key_pressed == 's')
			{
				result = engine->MoveActor(game->player, *game, DIR::DOWN);
			}
			else if (key_pressed == 'w')
			{
				result = engine->MoveActor(game->player, *game, DIR::UP);
			}
			else if (key_pressed == 'a')
			{
				result = engine->MoveActor(game->player, *game, DIR::LEFT);
			}
			else if (key_pressed == 'd')
			{
				result = engine->MoveActor(game->player, *game, DIR::RIGHT);
			}

			if (result == RESULT::LEVEL_DOWN)
			{
				engine->placeActor(game->player, *game);
				for (auto& i : game->monsters)
					engine->placeActor(i, *game);
				continue;
			}
			if (result == RESULT::LEVEL_UP)
			{
				continue;
			}

			for (auto& i : game->monsters)
				result = engine->MoveActor(i, *game, DIR::RAND);

			ui.printInfo(game->getGameMessage());
			ui.printInfo(game->getFightMessage(), 2);
		}

		else if (key_pressed == 'p')
		{
			engine->useItem(game->player);
		}
		
		else if (key_pressed == 'Q')
		{
			delete engine;
			delete game;

			return 0;
		}
		ui.updateInterface(*game);
		ui.updateScreen(*game);

		if (game->player.isDead() == true)
		{
			//exit(0);
		}
	}

	delete engine;
	delete game;
	
    return 0;
}

