#pragma once

#include <fstream>
#include <string>
#include <array>

#include "Tile.h"

class Level
{
public:
	Level();
	Level(const int width, const int height);
	Level(const int width, const int height, const int lvl_number);
	~Level();

	void loadLevelFromFile(const int width, const int height, const int lvl_number);
	void setMap(std::array<std::array<Tile, 148>, 48> & m);

	Tile getMapTile(const int x, const int y) const;
	void setMapTile(const int x, const int y, Tile t);

protected:
	std::array<std::array<Tile, 148>, 48> map; // todo move this from stack to heap
	std::ifstream file;

	int game_size_max_x;
	int game_size_max_y;
};
