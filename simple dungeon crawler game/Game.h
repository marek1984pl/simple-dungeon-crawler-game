#pragma once

#include "Level.h"
#include "Player.h"
#include "GameEngine.h"

#include <array>

class Game
{
public:
	Game();
	~Game();

public:
	GameEngine engine;
	std::array<Level, 1> levels;
};

