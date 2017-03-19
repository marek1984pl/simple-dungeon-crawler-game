#pragma once

#include <stack>

#include "Level.h"
#include "utilities.h"
#include "Tile.h"

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class MazeGenerator : public virtual Level
{
protected:
	struct Cell
	{
		Cell() : x(0), y(0)
		{
			
		}
		Cell(const int x_, const int y_) : x(x_), y(y_)
		{
			
		}

		int x, y;
	};

	std::stack<Cell> cells;

public:
	MazeGenerator();
	~MazeGenerator();

	void generateMaze(const int start_x, const int start_y);
	bool canMove(const Cell cell, const DIRECTION dir);
	Cell move(const DIRECTION dir, const Cell cell) const;
};
