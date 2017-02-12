#pragma once

#include "Level.h"
#include "Player.h"
#include "GameEngine.h"
#include "UserInterface.h"

#include <array>

class Game
{
public:
	Game();
	~Game();
	void ShowLevel();

private:
	UserInterface * ui;
	GameEngine * engine;
	Player * player;
	std::array<Level, 5> levels;
};

