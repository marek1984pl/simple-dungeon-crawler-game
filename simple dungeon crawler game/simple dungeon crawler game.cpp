// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "GameEngine.h"

int main()
{
	GameEngine * engine = new GameEngine;
	UserInterface * ui = new UserInterface;
	Game * game = new Game;

	ui->createGameInterface(engine->mainWindow, engine->uiWindow, engine->textWindow);
	engine->DisplayLevel(game->levels[0]);
	engine->refreshGameInterface(*ui);
	engine->UpdateGame(*game);

	char key_pressed;

	while (1)
	{
		key_pressed = getch();
		engine->printChar(key_pressed, 1, 1, COLOR::RED, engine->textWindow);
		engine->printString(game->player.getName().c_str(), 1, 1, COLOR::CYAN, engine->uiWindow);
		engine->printString("LEVEL: ", 1, 2, COLOR::GRAY, engine->uiWindow);
		engine->printString(game->player.getLevel(), 8, 2, COLOR::CYAN, engine->uiWindow);

		if (key_pressed == 's')
		{
			engine->MoveActor(game->player, DIR::DOWN);
		}
		if (key_pressed == 'w')
		{
			engine->MoveActor(game->player, DIR::UP);
		}
		if (key_pressed == 'a')
		{
			engine->MoveActor(game->player, DIR::LEFT);
		}
		if (key_pressed == 'd')
		{
			engine->MoveActor(game->player, DIR::RIGHT);
		}

		engine->printString(game->player.GetCurrentPositionX(), 2, 2, COLOR::YELLOW, engine->textWindow);
		engine->printString(game->player.GetCurrentPositionY(), 2, 3, COLOR::YELLOW, engine->textWindow);

		engine->UpdateGame(*game);
		engine->DisplayLevel(game->levels[0]);
		engine->refreshGameInterface(*ui);
	}
	// dobrze
	//game.engine->MoveActor(game.GetPlayer(), DIR::DOWN);

	delete engine;
	delete ui;
	delete game;

    return 0;
}

