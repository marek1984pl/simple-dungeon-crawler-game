#pragma once

#include "Level.h"
#include "monster.h"
#include "player.h"
#include "CombatLog.h"

#include <array>
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void createPlayer(std::string name);

	void createRandomMonsters();
	void createRandomTreasuers();

	Monster & getMonster(int pos_x, int pos_y);
	void deleteMonster(Monster & m);

	void nextMove();
	int getNumberOfMoves() const;

	void setCurrentLevel(int lvl);
	int getCurrentLevel() const;

	int getNumberOfLevels() const;

	Player player;
	std::array<Level, 5> levels;
	std::array<std::vector<Monster>, 5> monsters;

	CombatLog c_log;

private:
	int number_of_levels = 5;
	int current_level = 0;
	int number_of_moves = 0;
};

