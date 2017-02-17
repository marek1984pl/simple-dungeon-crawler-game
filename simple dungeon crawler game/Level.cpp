#include "stdafx.h"
#include "Level.h"


Level::Level()
{
}

Level::Level(int width, int height, int lvl_number)
{
	loadLevelFromFile(width, height, lvl_number);
}

Level::~Level()
{
}

void Level::loadLevelFromFile(int width, int height, int lvl_number)
{
	file.open(".\\data\\levels\\level_" + std::to_string(lvl_number) + ".txt");

	char tile;
	for (auto i = 0; i < height; i++)
	{
		for (auto j = 0; j < width; j++)
		{			
			file >> tile;
			switch (tile)
			{
			// todo
			// remove unnecessary code, use setType method from tile or tile constructor to set default collide, interact and occupied
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
			case '>':
				map[i][j].setType(TILE_TYPE::LEVEL_DOWN);
				map[i][j].setCollide(false);
				map[i][j].setInteract(true);
				map[i][j].setOccupied(true);
				break;
			case '<':
				map[i][j].setType(TILE_TYPE::LEVEL_UP);
				map[i][j].setCollide(false);
				map[i][j].setInteract(true);
				map[i][j].setOccupied(true);
				break;
			default:
				break;
			}
		}
	}

	file.close();
}

Tile Level::getMapTile(int x, int y) const
{
	return map[y][x];
}

void Level::setMapTile(int x, int y, Tile t)
{
	map[y][x] = t;
}

