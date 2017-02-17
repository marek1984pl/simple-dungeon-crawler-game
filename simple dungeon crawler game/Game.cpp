#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	for (int i = 0; i < number_of_levels; ++i)
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
	
	for (int i = 0; i < number_of_levels; i++)
	{
		for (int j = 0; j < quantity; ++j)
		{
			pos_x = rand() % 145 + 2;
			pos_y = rand() % 45 + 2;

			while (levels[i].getMapTile(pos_x, pos_y).getOccupied() == true)
			{
				pos_x = rand() % 145 + 2;
				pos_y = rand() % 45 + 2;
			}

			random_type = rand() % 5;

			switch (random_type)
			{
			case 0:
				monsters[i].push_back(Monster("Goblin", i * 2, MONSTER_TYPE::GOBLIN));
				break;
			case 1:
				monsters[i].push_back(Monster("Wolf", i * 2, MONSTER_TYPE::WOLF));
				break;
			case 2:
				monsters[i].push_back(Monster("Bandit", i * 2, MONSTER_TYPE::BANDIT));
				break;
			case 3:
				monsters[i].push_back(Monster("Snake", i * 2, MONSTER_TYPE::SNAKE));
				break;
			case 4:
				monsters[i].push_back(Monster("Troll", i * 2, MONSTER_TYPE::TROLL));
				break;
			default:
				break;
			}
			monsters[i].back().setCurrentPos(pos_x, pos_y);
		}
	}
}

Monster & Game::getMonster(int pos_x, int pos_y)
{
	for (auto & i : monsters[getCurrentLevel()])
	{
		if (i.getCurrentPosX() == pos_x && i.getCurrentPosY() == pos_y)
			return i;
	}
}

void Game::deleteMonster(Monster & m)
{
	auto monster_iter = std::find(monsters[getCurrentLevel()].begin(), monsters[getCurrentLevel()].end(), m);
	monsters[getCurrentLevel()].erase(monster_iter);
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

int Game::getNumberOfLevels() const
{
	return number_of_levels;
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


