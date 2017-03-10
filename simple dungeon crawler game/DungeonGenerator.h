#pragma once

#include <array>
#include <vector>

#include "Tile.h"
#include "Level.h"
#include "utilities.h"

#include <iostream>

enum { NORTH, SOUTH, WEST, EAST };

class DungeonGenerator : public Level
{
public:
	struct Room
	{
		int x, y;
		int width, height;
	};

	DungeonGenerator(int width, int height);
	~DungeonGenerator();

	std::array<std::array<Tile, 148>, 48> & getGeneratedMap();
	
	void generateRooms();
	void generateMaze(int width, int height);
	void generateDungeon(int numberOfTries);

	bool checkRoomsIntersection(Room r_A, Room r_B) const;

private:
	int width = 148;
	int height = 48;

	std::vector<Room> rooms;
};

