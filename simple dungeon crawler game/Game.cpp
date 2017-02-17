#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	for(int i = 0; i < number_of_levels; ++i)
		levels[i].loadLevelFromFile(148, 48, i + 1);
}

Game::~Game()
{
}

void Game::createPlayer(std::string name)
{
	player.setName(name);
	player.setLevel(1);
	player.setStrength(3);
	player.setDexterity(4);
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
	int pos_x, pos_y;
	
	for (int i = 0; i < quantity; ++i)
	{		
		pos_x = rand() % 145 + 2;
		pos_y = rand() % 45 + 2;

		while (levels[current_level].getMapTile(pos_x, pos_y).getOccupied() == true)
		{
			pos_x = rand() % 145 + 2;
			pos_y = rand() % 45 + 2;
		}
	
		random_type = rand() % 5;

		switch (random_type)
		{
		case 0:
			monsters.push_back(Monster("Goblin", 1, MONSTER_TYPE::GOBLIN));
			break;
		case 1:
			monsters.push_back(Monster("Wolf", 1, MONSTER_TYPE::WOLF));
			break;
		case 2:
			monsters.push_back(Monster("Bandit", 1, MONSTER_TYPE::BANDIT));
			break;
		case 3:
			monsters.push_back(Monster("Snake", 1, MONSTER_TYPE::SNAKE));
			break;
		case 4:
			monsters.push_back(Monster("Troll", 1, MONSTER_TYPE::TROLL));
			break;
		default:
			break;
		}
		monsters.back().setCurrentPos(pos_x, pos_y);
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

void Game::setCurrentLevel(int lvl)
{
	current_level = lvl;
}

int Game::getCurrentLevel() const
{
	return current_level;
}

std::string Game::getGameMessage() const
{
	return game_message;
}

std::string Game::getFightMessage() const
{
	return fight_message;
}

void Game::setGameMesage(std::string msg)
{
	game_message = msg;
}

void Game::setFightMesage(std::string msg)
{
	fight_message = msg;
}


