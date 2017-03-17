#include "stdafx.h"
#include "DungeonGenerator.h"

// Alghorithm based on article from:
// http://journal.stuffwithstuff.com/2014/12/21/rooms-and-mazes/

DungeonGenerator::DungeonGenerator(int width, int height)
{
	// todo
	game_size_max_x = width;  // temp solution
	game_size_max_y = height; // temp solution

	for (auto i = 0; i <= game_size_max_y; ++i)
	{
		for (auto j = 0; j <= game_size_max_x; ++j)
		{
			map[i][j] = std::move(Tile(TILE_TYPE::WALL));
		}
	}
}

DungeonGenerator::~DungeonGenerator()
{
}

void DungeonGenerator::generateDungeon(int numberOfTries)
{
	for (auto i = 0; i < numberOfTries; ++i)
	{
		generateRooms();
	}
	
	int rand_x;
	int rand_y;

	do 
	{
		rand_x = generateRandNumber(3, game_size_max_x - 3);
		rand_y = generateRandNumber(3, game_size_max_y - 3);
	} while (getMapTile(rand_x, rand_y).getType() == TILE_TYPE::EMPTY);

	generateMaze(rand_x, rand_y);
	makeRoomConection();
	removeDeadEnds();
}

std::array<std::array<Tile, 148>, 48> & DungeonGenerator::getGeneratedMap()
{
	return map;
}

