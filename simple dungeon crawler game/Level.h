#pragma once

#include <fstream>
#include <array>

#include "Tile.h"

class Level
{
public:
	Level();
	~Level();

	void loadLevelFromFile(int width, int height);

	Tile getLevelData(int x, int y);
	void setLevelData(int x, int y, Tile t);

private:
	std::array<std::array<Tile, 148>, 48> lvl_data;
	std::ifstream file;
};

