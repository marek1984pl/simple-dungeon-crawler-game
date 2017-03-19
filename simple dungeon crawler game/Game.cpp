#include "stdafx.h"
#include "Game.h"
#include <memory>

Game::Game(const int game_size_x, const int game_size_y)
{
	game_size_min_x = 1;
	game_size_min_y = 1;
	game_size_max_x = game_size_x - 3;
	game_size_max_y = game_size_y - 3;

	std::unique_ptr<DungeonGenerator> dungeon_generator(new DungeonGenerator(game_size_max_x, game_size_max_y));

	dungeon_generator->generateDungeon(500);
	levels[0].setMap(dungeon_generator->getGeneratedMap());

	//for (auto i = 0; i < number_of_levels; ++i)
	//	levels[i].loadLevelFromFile(game_size_max_x, game_size_max_y, i + 1);

	int pos_x, pos_y;

	do // todo change this to prevent app not starting because there is no possibility to place player on empty cell
	{
		pos_x = generateRandNumber(1, 10);
		pos_y = generateRandNumber(1, 10);
	}
	while (levels[0].getMapTile(pos_x, pos_y).getOccupied() == true);

	player.setCurrentPos(pos_x, pos_y);
}

Game::~Game()
{
}

void Game::createPlayer(const std::string name)
{
	player.setName(name);
}

void Game::createRandomMonsters(const int min, const int max)
{
	int random_type;
	int pos_x, pos_y;
	int quantity;

	for (auto i = 0; i < number_of_levels; i++)
	{
		quantity = generateRandNumber(min, max);
		for (auto j = 0; j < quantity; ++j)
		{
			do
			{
				pos_x = generateRandNumber(game_size_min_x, game_size_max_x);
				pos_y = generateRandNumber(game_size_min_y, game_size_max_y);
			}
			while (levels[i].getMapTile(pos_x, pos_y).getOccupied() == true);

			random_type = generateRandNumber(0, 4);

			auto random_monster_level = generateRandNumber(0, 1) + i;

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

void Game::createRandomTreasures(const int min, const int max)
{
	int quantity;
	int pos_x, pos_y;

	for (auto i = 0; i < number_of_levels; i++)
	{
		quantity = generateRandNumber(min, max);
		for (auto j = 0; j < quantity; ++j)
		{
			do
			{
				pos_x = generateRandNumber(game_size_min_x, game_size_max_x);
				pos_y = generateRandNumber(game_size_min_y, game_size_max_y);
			}
			while (levels[i].getMapTile(pos_x, pos_y).getOccupied() == true);

			levels[i].setMapTile(pos_x, pos_y, Tile(TILE_TYPE::TREASURE));
		}
	}
}

Monster & Game::getMonster(const int pos_x, const int pos_y)
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

void Game::setCurrentLevel(const int lvl)
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
