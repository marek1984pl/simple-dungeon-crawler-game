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
		Cell() : x(0), y(0) {}
		Cell(int x_, int y_) : x(x_), y(y_){}

		int x, y;
	};

	std::stack<Cell> cells;

public:
	MazeGenerator();
	~MazeGenerator();

	void generateMaze(int start_x, int start_y);
	bool canCurve(Cell cell, DIRECTION dir);
	Cell move(DIRECTION dir, Cell cell);
};

