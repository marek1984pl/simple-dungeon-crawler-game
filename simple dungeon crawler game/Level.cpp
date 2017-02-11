#include "stdafx.h"
#include "Level.h"

#include <curses.h>

Level::Level()
{
	file.open(".\\data\\levels\\level_1.txt");
}


Level::~Level()
{
	file.close();
}

void Level::LoadLevelFromFile()
{
	char tile;

	for (int i = 0; i < getLevelHeight(); i++)
	{
		for (int j = 0; j < getLevelWidth(); j++)
		{
			// TODO:
			// load a file with a level
			file >> tile;
			switch (tile)
			{
			case '#':
				attron(COLOR_PAIR(2));
				printw("%c", tile);
				attroff(COLOR_PAIR(2));
				break;
			case '.':
				attron(COLOR_PAIR(1));
				printw("%c", tile);
				attroff(COLOR_PAIR(1));
				break;
			default:
				break;
			}
		}
	}
}

int Level::getLevelWidth() const
{
	return level_width;
}

int Level::getLevelHeight() const
{
	return level_height;
}
