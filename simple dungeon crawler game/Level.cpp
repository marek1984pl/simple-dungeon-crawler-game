#include "stdafx.h"
#include "Level.h"


Level::Level()
{
	file.open(".\\data\\levels\\level_1.txt");
}

Level::~Level()
{
	file.close();
}

void Level::loadLevelFromFile(int width, int height)
{
	char tile;
	for (auto i = 0; i < height; i++)
	{
		for (auto j = 0; j < width; j++)
		{			
			file >> tile;
			lvl_data[i][j] = tile;
		}
	}
}

