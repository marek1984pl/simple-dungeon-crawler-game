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

	game->createPlayer("Zodgar");

	game->createRandomMonsters(100);

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
			if (key_pressed == 'p')
			{
				engine->useItem(game->player);
			}

			for (auto& i : game->monsters)
				engine->MoveActor(i, *game, DIR::RAND);

			ui.printInfo(game->getGameMessage());
			ui.printInfo(game->getGameFightMessage(), 2);
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

