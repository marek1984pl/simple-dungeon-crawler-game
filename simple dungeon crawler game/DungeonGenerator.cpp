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

	//for (auto i = 1; i < game_size_max_y; i += 2)
	//{
	//	for (auto j = 1; j < game_size_max_x; j += 2)
	//	{
	//		if (map[i][j].getType() == TILE_TYPE::EMPTY)
	//			continue;
	//		else
				generateMaze(1, 1);
	//	}
	//}
}

std::array<std::array<Tile, 148>, 48> & DungeonGenerator::getGeneratedMap()
{
	return map;
}

