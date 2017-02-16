#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	levels[0].loadLevelFromFile(148, 48);
}

Game::~Game()
{
}

void Game::createPlayer(std::string name)
{
	player.setName(name);
	player.setLevel(1);
	player.setStrength(3);
	player.setDexterity(2);
	player.setStamina(7);
	player.setExp(0);
	player.setGold(0);

	player.setCurrentPos(1, 1);
	player.setOldPos(1, 1);
	player.setNewPos(1, 1);

	player.setMaxHealth();
	player.setArmor();
	player.setAttackPower();
	player.setHealth(player.getMaxHealth());
}

void Game::createRandomMonsters(int quantity)
{
	int random_type;
	
	for (int i = 0; i < quantity; ++i)
	{
		random_type = rand() % 5;
		switch (random_type)
		{
		case 0:
			monsters.push_back(Monster("Goblin", 1));
			break;
		case 1:
			monsters.push_back(Monster("Wolf", 1));
			break;
		case 2:
			monsters.push_back(Monster("Bandit", 1));
			break;
		case 3:
			monsters.push_back(Monster("Snake", 1));
			break;
		case 4:
			monsters.push_back(Monster("Troll", 1));
			break;
		default:
			break;
		}
	}
}

Monster & Game::getMonster(int pos_x, int pos_y)
{
	for (auto & i : monsters)
	{
		if (i.getCurrentPosX() == pos_x && i.getCurrentPosY() == pos_y)
			return i;
	}
}

void Game::deleteMonster(Monster & m)
{
	auto monster_iter = std::find(monsters.begin(), monsters.end(), m);
	monsters.erase(monster_iter);
}

void Game::nextMove()
{
	++number_of_moves;
}

int Game::getNumberOfMoves() const
{
	return number_of_moves;
}

std::string Game::getGameMessage() const
{
	return game_message;
}

std::string Game::getGameFightMessage() const
{
	return game_fight_message;
}

void Game::setGameMesage(std::string msg)
{
	game_message = msg;
}

void Game::setGameFightMesage(std::string msg)
{
	game_fight_message = msg;
}


