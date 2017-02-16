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

	void createRandomMonsters(int quantity);

	Player player;
	std::array<Level, 5> levels;
	std::vector<Monster> monsters;

	Monster & getMonster(int pos_x, int pos_y);

	void nextMove();
	int getNumberOfMoves() const;

	std::string getGameMessage() const;
	std::string getGameFightMessage() const;
	void setGameMesage(std::string msg);
	void setGameFightMesage(std::string msg);

private:
	int current_level;
	int number_of_moves = 0;
	std::string game_message;
	std::string game_fight_message;
};

