// simple dungeon crawler game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "GameEngine.h"
#include "UserInterface.h"
#include <memory>

int main()
{
	std::unique_ptr<GameEngine> engine(new GameEngine);
	std::unique_ptr<Game> game(new Game);
	std::unique_ptr<UserInterface> ui(new UserInterface);

	RESULT result = RESULT::NONE;

	if (ui->createMainMenu() == -1)
	{
		return 0;
	}

	ui->createGameInterface();

	game->createPlayer("Zodgar");

	game->createRandomMonsters(30);

	engine->placeActor(game->player, *game);
	
	for (auto& i : game->monsters[game->getCurrentLevel()])
			engine->placeActor(i, *game);
	
	char key_pressed;

	ui->clearScreen();
	ui->updateInterface(*game);
	ui->updateScreen(*game);

	while (true)
	{
		ui->clearScreen();
		game->setGameMesage("");
		game->setFightMesage("");

		key_pressed = getch();

		if (key_pressed == 'w' || key_pressed == 's' || key_pressed == 'a' || key_pressed == 'd' || key_pressed == 'q' || key_pressed == 'e' || key_pressed == 'z' || key_pressed == 'c')
		{
			switch (key_pressed)
			{
			case 'w':
				result = engine->MoveActor(game->player, *game, DIR::UP);
				break;
			case 'a':
				result = engine->MoveActor(game->player, *game, DIR::LEFT);
				break;
			case 's':
				result = engine->MoveActor(game->player, *game, DIR::DOWN);
				break;
			case 'd':
				result = engine->MoveActor(game->player, *game, DIR::RIGHT);
				break;
			case 'q':
				result = engine->MoveActor(game->player, *game, DIR::LEFT_UP);
				break;
			case 'e':
				result = engine->MoveActor(game->player, *game, DIR::RIGHT_UP);
				break;
			case 'z':
				result = engine->MoveActor(game->player, *game, DIR::LEFT_DOWN);
				break;
			case 'c':
				result = engine->MoveActor(game->player, *game, DIR::RIGHT_DOWN);
				break;
			default:
				break;
			}

			game->nextMove();

			if (result == RESULT::LEVEL_DOWN)
			{
				engine->placeActor(game->player, *game);
				for (auto& i : game->monsters[game->getCurrentLevel()])
					engine->placeActor(i, *game);
			}
			if (result == RESULT::LEVEL_UP)
				engine->placeActor(game->player, *game);

			for (auto& i : game->monsters[game->getCurrentLevel()])
				result = engine->MoveActor(i, *game, DIR::RAND);

			ui->printInfo(game->getGameMessage());
			ui->printInfo(game->getFightMessage(), 2);
		}

		else if (key_pressed == 'p')
		{
			engine->useHealthPotion(game->player);
		}
		
		else if (key_pressed == 'Q')
		{
			return 0;
		}
		ui->updateInterface(*game);
		ui->updateScreen(*game);

		if (game->player.isDead() == true)
		{
			ui->createEndScreen(*game);
			return 0;
		}
	}
    return 0;
}

