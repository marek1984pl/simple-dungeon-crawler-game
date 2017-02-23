#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	for (auto i = 0; i < number_of_levels; ++i)
		levels[i].loadLevelFromFile(148, 48, i + 1);
}

Game::~Game()
{
}

void Game::createPlayer(std::string name)
{
	player.setName(name);
}

void Game::createRandomMonsters()
{
	int random_type;
	int pos_x, pos_y;
	int quantity;
	
	for (auto i = 0; i < number_of_levels; i++)
	{
		quantity = rand() % 20 + 20;
		for (auto j = 0; j < quantity; ++j)
		{
			pos_x = rand() % 145 + 2;
			pos_y = rand() % 45 + 2;

			while (levels[i].getMapTile(pos_x, pos_y).getOccupied() == true)
			{
				pos_x = rand() % 145 + 2;
				pos_y = rand() % 45 + 2;
			}

			random_type = rand() % 5;

			int random_monster_level = rand() % 2 + 1 + i;

			switch (random_type)
			{
			case 0:
				monsters[i].push_back(Monster("Goblin", random_monster_level, MONSTER_TYPE::GOBLIN));
				break;
			case 1:
				monsters[i].push_back(Monster("Wolf", random_monster_level, MONSTER_TYPE::WOLF));
				break;
			case 2:
				monsters[i].push_back(Monster("Bandit", random_monster_level, MONSTER_TYPE::BANDIT));
				break;
			case 3:
				monsters[i].push_back(Monster("Snake", random_monster_level, MONSTER_TYPE::SNAKE));
				break;
			case 4:
				monsters[i].push_back(Monster("Troll", random_monster_level, MONSTER_TYPE::TROLL));
				break;
			default:
				break;
			}
			monsters[i].back().setCurrentPos(pos_x, pos_y);
		}
	}
}

void Game::createRandomTreasuers()
{
	int quantity;
	int pos_x, pos_y;

	for (auto i = 0; i < number_of_levels; i++)
	{
		quantity = rand() % 20 + 20;
		for (auto j = 0; j < quantity; ++j)
		{
			pos_x = rand() % 145 + 2;
			pos_y = rand() % 45 + 2;

			while (levels[i].getMapTile(pos_x, pos_y).getOccupied() == true)
			{
				pos_x = rand() % 145 + 2;
				pos_y = rand() % 45 + 2;
			}
			levels[i].setMapTile(pos_x, pos_y, Tile(TILE_TYPE::TREASURE));
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

