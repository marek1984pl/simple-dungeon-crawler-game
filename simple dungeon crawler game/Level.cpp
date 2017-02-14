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
				lvl_data[i][j].setType(TILE_TYPE::WALL);
				lvl_data[i][j].setCollide(true);
				lvl_data[i][j].setInteract(false);
				break;
			case '~':
				lvl_data[i][j].setType(TILE_TYPE::WATER);
				lvl_data[i][j].setCollide(true);
				lvl_data[i][j].setInteract(false);
				break;
			case 'T':
				lvl_data[i][j].setType(TILE_TYPE::TREE);
				lvl_data[i][j].setCollide(true);
				lvl_data[i][j].setInteract(false);
				break;
			case '@':
				lvl_data[i][j].setType(TILE_TYPE::PLAYER);
				lvl_data[i][j].setCollide(false);
				lvl_data[i][j].setInteract(true);
				break;
			case 'g':
			case 's':
				lvl_data[i][j].setType(TILE_TYPE::MONSTER);
				lvl_data[i][j].setCollide(false);
				lvl_data[i][j].setInteract(true);
				break;
			case '*':
				lvl_data[i][j].setType(TILE_TYPE::NPC);
				lvl_data[i][j].setCollide(false);
				lvl_data[i][j].setInteract(true);
				break;
			case '$':
				break;
				lvl_data[i][j].setType(TILE_TYPE::TREASURE);
				lvl_data[i][j].setCollide(false);
				lvl_data[i][j].setInteract(true);
			case '.':
				lvl_data[i][j].setType(TILE_TYPE::EMPTY);
				lvl_data[i][j].setCollide(false);
				lvl_data[i][j].setInteract(false);
				break;
			default:
				break;
			}
		}
	}
}

Tile Level::getLevelData(int x, int y)
{
	return lvl_data[x][y];
}

void Level::setLevelData(int x, int y, Tile t)
{
	lvl_data[x][y];
}

