#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	levels[0].LoadLevelFromFile(148, 48);
	player.SetCurrentPos(1, 1);
	player.SetOldPos(1, 1);
	player.setName("Zodgar");
	player.setLevel(1);
	player.setChanged(0);
}

Game::~Game()
{
}

