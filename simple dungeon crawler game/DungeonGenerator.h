#pragma once

#include <array>

#include "Tile.h"
#include "RoomGenerator.h"
#include "MazeGenerator.h"

class DungeonGenerator : public RoomGenerator, public MazeGenerator
{
public:
	DungeonGenerator(const int width, const int height);
	~DungeonGenerator();

	std::array<std::array<Tile, 148>, 48> & getGeneratedMap();

	void generateDungeon(const int numberOfTries);
};
