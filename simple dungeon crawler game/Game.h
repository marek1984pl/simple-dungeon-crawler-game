#pragma once

#include "Level.h"
#include "monster.h"
#include "player.h"

#include <array>
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void createPlayer(std::string name);

	Player player;
	std::array<Level, 5> levels;
	std::vector<Monster> monsters;
private:
};

