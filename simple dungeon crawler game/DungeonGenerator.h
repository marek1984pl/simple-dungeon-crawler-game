#pragma once

#include <array>

#include "Tile.h"
#include "RoomGenerator.h"
#include "MazeGenerator.h"

class DungeonGenerator : public RoomGenerator, public MazeGenerator
{
public:
	DungeonGenerator(int width, int height);
	~DungeonGenerator();

	std::array<std::array<Tile, 148>, 48>& getGeneratedMap();

	void generateDungeon(int numberOfTries);
};
