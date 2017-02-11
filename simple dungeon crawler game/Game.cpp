#include "stdafx.h"
#include "Game.h"
#include "GameEngine.h"

Game::Game()
{
	engine.InitializeGraphics(200, 50);
	levels[0].LoadLevelFromFile();
}

Game::~Game()
{
}
