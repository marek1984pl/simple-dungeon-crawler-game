#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	ui = new UserInterface;
	engine = new GameEngine(ui);
	player = new Player();
	engine->InitializeGraphics(200, 50);
	levels[0].LoadLevelFromFile(148, 48);
	ui->createGameInterface();

	//engine->printChar('A', 10, 10, COLOR::CYAN, WINDOW_TYPE::MAIN);
}

Game::~Game()
{
	delete player;
	delete ui;
	delete engine;
}

void Game::ShowLevel()
{
	char tile;
	for (auto i = 0; i < 48; i++)
	{
		for (auto j = 0; j < 148; j++)
		{
			tile = levels[0].level_data[i][j];
			switch (tile)
			{
				case '@':
					engine->printChar(tile, j + 1, i + 1, COLOR::CYAN);
					player->setPosition(i, j);
					break;
				case '#':
					engine->printChar(tile, j + 1, i + 1, COLOR::WHITE);
					break;
				case '.':
					engine->printChar(tile, j + 1, i + 1, COLOR::DARK_GREEN);
					break;
				default:
					engine->printChar(tile, j + 1, i + 1, COLOR::YELLOW);
					break;
			}
		}
	}
}

