#include "stdafx.h"
#include "Level.h"


Level::Level()
{
}

Level::Level(int width, int height)
{
	game_size_max_x = width;
	game_size_max_y = height;
}

Level::Level(int width, int height, int lvl_number)
{
	game_size_max_x = width;
	game_size_max_y = height;
	loadLevelFromFile(game_size_max_x, game_size_max_y, lvl_number);
}

Level::~Level()
{
}

void Level::loadLevelFromFile(int width, int height, int lvl_number)
{
	// todo
	game_size_max_x = width;  // temp solution
	game_size_max_y = height; // temp solution

	file.open(".\\data\\levels\\level_" + std::to_string(lvl_number) + ".txt");

	char tile;
	for (auto i = 0; i <= game_size_max_y; i++) // todo
	{
		for (auto j = 0; j <= game_size_max_x; j++) // todo
		{			
			file >> tile;
			switch (tile)
			{
			case '#':
				map[i][j] = std::move(Tile(TILE_TYPE::WALL));
				break;
			case '~':
				map[i][j] = std::move(Tile(TILE_TYPE::WATER));
				break;
			case 'T':
				map[i][j] = std::move(Tile(TILE_TYPE::TREE));
				break;
			case '@':
				map[i][j] = std::move(Tile(TILE_TYPE::PLAYER));
				break;
			case 'g':
			case 's':
				map[i][j] = std::move(Tile(TILE_TYPE::MONSTER));
				break;
			case '*':
				map[i][j] = std::move(Tile(TILE_TYPE::NPC));
				break;
			case '$':
				map[i][j] = std::move(Tile(TILE_TYPE::TREASURE));
				break;
			case '.':
				map[i][j] = std::move(Tile(TILE_TYPE::EMPTY));
				break;
			case '>':
				map[i][j] = std::move(Tile(TILE_TYPE::LEVEL_DOWN));
				break;
			case '<':
				map[i][j] = std::move(Tile(TILE_TYPE::LEVEL_UP));
				break;
			default:
				break;
			}
		}
	}

	file.close();
}

void Level::setMap(std::array<std::array<Tile, 148>, 48> m)
{
	map = m;
}

Tile Level::getMapTile(int x, int y) const
{
	return map[y][x];
}

void Level::setMapTile(int x, int y, Tile t)
{
	map[y][x] = t;
}

