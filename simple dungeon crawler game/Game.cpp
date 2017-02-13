#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	levels[0].LoadLevelFromFile(148, 48);
}

Game::~Game()
{
}

void Game::createPlayer(std::string name)
{
	player.setName(name);
	player.setLevel(1);
	player.setHealth(10);
	player.setChanged(0);
	player.SetCurrentPos(1, 1);
	player.SetOldPos(1, 1);
}

