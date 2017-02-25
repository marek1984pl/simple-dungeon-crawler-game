#include "stdafx.h"
#include "DungeonGenerator.h"


DungeonGenerator::DungeonGenerator(int width, int height)
{
	std::random_device random_device;
	std::mt19937 generator(random_device());

	for (auto i = 0; i < height; i++)
	{
		for (auto j = 0; j < width; j++)
		{
			map[i][j] = std::move(Tile(TILE_TYPE::WALL));
		}
	}
}

DungeonGenerator::~DungeonGenerator()
{
}

void DungeonGenerator::generateRooms()
{
	int room_width = generateRand(6, 12);
	int room_height = generateRand(3, 7);

	Room * r = new Room;
	r->x = generateRand(1, 147 - room_width);
	r->y = generateRand(1, 47 - room_height);
	r->width = room_width;
	r->height = room_height;

	bool intersection = false;

	if (rooms.size() == 0)
	{
		rooms.push_back(*r);

		for (auto i = r->y; i < r->y + r->height; i++)
		{
			for (auto j = r->x; j < r->x + r->width; j++)
			{
				map[i][j].setType(TILE_TYPE::EMPTY);
			}
		}
	}
	else
	{
		for (auto& i : rooms)
		{
			intersection = intersection || checkRoomsIntersection(*r, i);
		}
		if (intersection == false)
		{
			rooms.push_back(*r);

			for (auto i = r->y; i < r->y + r->height; i++)
			{
				for (auto j = r->x; j < r->x + r->width; j++)
				{
					map[i][j].setType(TILE_TYPE::EMPTY);
				}
			}
		}
	}
	delete r;
}

void DungeonGenerator::generateDungeon(int numberOfTries)
{
	for (int i = 0; i < numberOfTries; i++)
	{
		generateRooms();
	}
}

std::array<std::array<Tile, 148>, 48> & DungeonGenerator::getGeneratedMap()
{
	return map;
}

int DungeonGenerator::generateRand(int min, int max) const
{
	return min + (rand() % (max - min + 1));
}

bool DungeonGenerator::checkRoomsIntersection(Room A, Room B) const
{
	bool xOverlap = valueInRange(A.x, B.x, B.x + B.width + 1) ||
		valueInRange(B.x, A.x, A.x + A.width + 1);

	bool yOverlap = valueInRange(A.y, B.y, B.y + B.height + 1) ||
		valueInRange(B.y, A.y, A.y + A.height + 1);

	return xOverlap && yOverlap;
}

bool DungeonGenerator::valueInRange(int value, int min, int max) const
{
	return (value >= min) && (value <= max);
}
