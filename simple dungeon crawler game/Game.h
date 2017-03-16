#pragma once

#include "Level.h"
#include "monster.h"
#include "player.h"
#include "CombatLog.h"
#include "DungeonGenerator.h"

#include <array>
#include <vector>

class Game
{
public:
	Game(int game_size_x, int game_size_y);
	~Game();

	void createPlayer(std::string name);

	void createRandomMonsters(int min, int max);
	void createRandomTreasuers(int min, int max);

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
	DungeonGenerator * dungeon_generator;

	CombatLog c_log;

private:
	int number_of_levels = 5;
	int current_level = 0;
	int number_of_moves = 0;

	int game_size_max_x;
	int game_size_max_y;
	int game_size_min_x;
	int game_size_min_y;
};

