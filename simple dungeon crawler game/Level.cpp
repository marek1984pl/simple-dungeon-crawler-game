#include "stdafx.h"
#include "Level.h"


Level::Level()
{
}

Level::~Level()
{
	file.close();
}

void Level::loadLevelFromFile(int width, int height)
{
	file.open(".\\data\\levels\\level_1.txt");

	char tile;
	for (auto i = 0; i < height; i++)
	{
		for (auto j = 0; j < width; j++)
		{			
			file >> tile;
			switch (tile)
			{
			case '#':
				map[i][j].setType(TILE_TYPE::WALL);
				map[i][j].setCollide(true);
				map[i][j].setInteract(false);
				map[i][j].setOccupied(true);
				break;
			case '~':
				map[i][j].setType(TILE_TYPE::WATER);
				map[i][j].setCollide(true);
				map[i][j].setInteract(false);
				map[i][j].setOccupied(true);
				break;
			case 'T':
				map[i][j].setType(TILE_TYPE::TREE);
				map[i][j].setCollide(true);
				map[i][j].setInteract(false);
				map[i][j].setOccupied(true);
				break;
			case '@':
				map[i][j].setType(TILE_TYPE::PLAYER);
				map[i][j].setCollide(false);
				map[i][j].setInteract(true);
				map[i][j].setOccupied(true);
				break;
			case 'g':
			case 's':
				map[i][j].setType(TILE_TYPE::MONSTER);
				map[i][j].setCollide(false);
				map[i][j].setInteract(true);
				map[i][j].setOccupied(true);
				break;
			case '*':
				map[i][j].setType(TILE_TYPE::NPC);
				map[i][j].setCollide(false);
				map[i][j].setInteract(true);
				map[i][j].setOccupied(true);
				break;
			case '$':
				map[i][j].setType(TILE_TYPE::TREASURE);
				map[i][j].setCollide(false);
				map[i][j].setInteract(true);
				map[i][j].setOccupied(true);
				break;
			case '.':
				map[i][j].setType(TILE_TYPE::EMPTY);
				map[i][j].setCollide(false);
				map[i][j].setInteract(false);
				map[i][j].setOccupied(false);
				break;
			default:
				break;
			}
		}
	}
}

Tile Level::getMapTile(int x, int y)
{
	return map[y][x];
}

void Level::setMapTile(int x, int y, Tile t)
{
	map[y][x] = t;
}

