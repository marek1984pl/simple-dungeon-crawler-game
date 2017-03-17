#include "stdafx.h"
#include "MazeGenerator.h"


MazeGenerator::MazeGenerator()
{
}


MazeGenerator::~MazeGenerator()
{
}

void MazeGenerator::generateMaze(int start_x, int start_y)
{
	// Implementation of the "growing tree" algorithm from here:
	// http://www.astrolog.org/labyrnth/algrithm.htm.
	// http://stackoverflow.com/questions/8820993/recursive-backtracker-maze-generation-algorithm-stack-loop

	Cell cell(start_x, start_y);
	auto number_of_good_moves = 0;
	auto dir = 1;

	do
	{
		for (auto i = 0; i < 4; ++i)
		{
			if (canMove(cell, static_cast<DIRECTION>(i)) == true)
				number_of_good_moves++;
		}

		if (number_of_good_moves == 1)
		{
			if (canMove(cell, UP))
				cell.y = cell.y - 1;
			else if (canMove(cell, DOWN))
				cell.y = cell.y + 1;
			else if (canMove(cell, LEFT))
				cell.x = cell.x - 1;
			else if (canMove(cell, RIGHT))
				cell.x = cell.x + 1;
		}
		else if (number_of_good_moves == 0)
		{
			cell.x = cells.top().x;
			cell.y = cells.top().y;
			cells.pop();
		}
		else if (number_of_good_moves > 1)
		{
			cells.push(cell);

			do
			{
				// maze twisting factor
				if (generateRandNumber(0, 100) < 30) 
					dir = generateRandNumber(0, 3);
			} while (canMove(cell, static_cast<DIRECTION>(dir)) == false);
			
			switch (dir)
			{
			case 0: // up
				cell.x = cell.x;
				cell.y = cell.y - 1;
				break;
			case 1: //down
				cell.x = cell.x;
				cell.y = cell.y + 1;
				break;
			case 2: //left
				cell.x = cell.x - 1;
				cell.y = cell.y;
				break;
			case 3: // right
				cell.x = cell.x + 1;
				cell.y = cell.y;
				break;
			}

		}
		setMapTile(cell.x, cell.y, TILE_TYPE::EMPTY);
		number_of_good_moves = 0;
	} while (!cells.empty());
}

bool MazeGenerator::canMove(Cell cell, DIRECTION dir)
{
	auto new_x = move(dir, cell).x;
	auto new_y = move(dir, cell).y;

	if (getMapTile(new_x, new_y).getType() == TILE_TYPE::EMPTY || valueInRange(new_x, 1, game_size_max_x - 1) == false || valueInRange(new_y, 1, game_size_max_y - 1) == false)
		return false;

	if (dir == UP)
	{
		if (getMapTile(new_x - 1, new_y).getType() != TILE_TYPE::EMPTY && getMapTile(new_x + 1, new_y).getType() != TILE_TYPE::EMPTY &&
			map[new_y - 1][new_x - 1].getType() != TILE_TYPE::EMPTY && map[new_y - 1][new_x + 1].getType() != TILE_TYPE::EMPTY &&
			map[new_y - 1][new_x].getType() != TILE_TYPE::EMPTY)
			return true;
	}
	if (dir == DOWN)
	{
		if (map[new_y][new_x - 1].getType() != TILE_TYPE::EMPTY && map[new_y][new_x + 1].getType() != TILE_TYPE::EMPTY &&
			map[new_y + 1][new_x - 1].getType() != TILE_TYPE::EMPTY && map[new_y + 1][new_x + 1].getType() != TILE_TYPE::EMPTY &&
			map[new_y + 1][new_x].getType() != TILE_TYPE::EMPTY)
			return true;
	}
	if (dir == LEFT)
	{
		if (map[new_y - 1][new_x - 1].getType() != TILE_TYPE::EMPTY && map[new_y + 1][new_x - 1].getType() != TILE_TYPE::EMPTY &&
			map[new_y - 1][new_x].getType() != TILE_TYPE::EMPTY && map[new_y + 1][new_x].getType() != TILE_TYPE::EMPTY &&
			map[new_y][new_x -1].getType() != TILE_TYPE::EMPTY)
			return true;
	}
	if (dir == RIGHT)
	{
		if (map[new_y - 1][new_x + 1].getType() != TILE_TYPE::EMPTY && map[new_y + 1][new_x + 1].getType() != TILE_TYPE::EMPTY &&
			map[new_y - 1][new_x].getType() != TILE_TYPE::EMPTY && map[new_y + 1][new_x].getType() != TILE_TYPE::EMPTY &&
			map[new_y][new_x + 1].getType() != TILE_TYPE::EMPTY)
			return true;
	}

	return false;
}

MazeGenerator::Cell MazeGenerator::move(DIRECTION dir, Cell cell)
{
	Cell new_cell;

	switch (dir)
	{
	case UP:
		new_cell.x = cell.x;
		new_cell.y = cell.y - 1;
		break;
	case DOWN:
		new_cell.x = cell.x;
		new_cell.y = cell.y + 1;
		break;
	case LEFT:
		new_cell.x = cell.x - 1;
		new_cell.y = cell.y;
		break;
	case RIGHT:
		new_cell.x = cell.x + 1;
		new_cell.y = cell.y;
		break;
	}

	return new_cell;
}
