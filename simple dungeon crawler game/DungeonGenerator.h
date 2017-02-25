#pragma once

#include <array>
#include <vector>

#include "Tile.h"
#include "Level.h"

#include <random>
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

	void generateRooms();
	void generateDungeon(int numberOfTries);
	std::array<std::array<Tile, 148>, 48> & getGeneratedMap();

	int generateRand(int min, int max) const;
	bool checkRoomsIntersection(Room r_A, Room r_B) const;
	bool valueInRange(int value, int min, int max) const;

private:
	int width = 148;
	int height = 48;

	std::vector<Room> rooms;
};

