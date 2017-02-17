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

	Tile getMapTile(int x, int y) const;
	void setMapTile(int x, int y, Tile t);

private:
	std::array<std::array<Tile, 148>, 48> map;
	std::ifstream file;
};

