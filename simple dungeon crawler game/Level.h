#pragma once

#include <fstream>
#include <string>
#include <array>

#include "Tile.h"

class Level
{
public:
	Level();
	Level(int width, int height);
	Level(int width, int height, int lvl_number);
	~Level();

	void loadLevelFromFile(int width, int height, int lvl_number);
	void setMap(std::array<std::array<Tile, 148>, 48> m);

	Tile getMapTile(int x, int y) const;
	void setMapTile(int x, int y, Tile t);

protected:
	std::array<std::array<Tile, 148>, 48> map;
	std::ifstream file;

	int game_size_max_x;
	int game_size_max_y;
};
