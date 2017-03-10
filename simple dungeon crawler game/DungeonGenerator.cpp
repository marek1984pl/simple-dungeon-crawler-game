#include "stdafx.h"
#include "DungeonGenerator.h"


DungeonGenerator::DungeonGenerator(int width, int height)
{
	for (auto i = 0; i < height; ++i)
	{
		for (auto j = 0; j < width; ++j)
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
	auto room_width = generateRandNumber(6, 12);
	auto room_height = generateRandNumber(3, 7);

	auto * r = new Room;
	r->x = generateRandNumber(1, 147 - room_width);
	r->y = generateRandNumber(1, 47 - room_height);
	r->width = room_width;
	r->height = room_height;

	auto intersection = false;

	if (rooms.size() == 0)
	{
		rooms.push_back(*r);

		for (auto i = r->y; i < r->y + r->height; ++i)
		{
			for (auto j = r->x; j < r->x + r->width; ++j)
			{
				map[i][j].setType(TILE_TYPE::EMPTY);
			}
		}
	}
	else
	{
		for (auto & i : rooms)
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

void DungeonGenerator::generateMaze(int width, int height)
{
	auto dir = 2;
	int same_dir;

	for (auto i = 2; i < height; i += 2)
	{
		for (auto j = 2; j < width; j += 2)
		{
			if (map[i][j].getType() == TILE_TYPE::EMPTY)
				;
			else
			{
				same_dir = generateRandNumber(1, 100);
				if (same_dir >= 10)
					dir = generateRandNumber(1, 4);

				switch (dir)
				{
				case 1: // up
					if ((map[i - 1][j].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 2][j].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 1][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 2][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 1][j + 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 2][j + 1].getType() != TILE_TYPE::EMPTY))
						map[i][j].setType(TILE_TYPE::TREE);
						map[i - 1][j].setType(TILE_TYPE::TREE);
					break;
				case 2: // down
					if ((map[i + 1][j].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 2][j].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 1][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 2][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 1][j + 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 2][j + 1].getType() != TILE_TYPE::EMPTY))
						map[i][j].setType(TILE_TYPE::TREE);
						map[i + 1][j].setType(TILE_TYPE::TREE);
					break;
				case 3: // left
					if ((map[i][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i][j - 2].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 1][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 1][j - 2].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 1][j - 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 1][j - 2].getType() != TILE_TYPE::EMPTY))
						map[i][j].setType(TILE_TYPE::TREE);
						map[i][j - 1].setType(TILE_TYPE::TREE);
					break;
				case 4: // right
					if ((map[i][j + 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i][j + 2].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 1][j + 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i + 1][j + 2].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 1][j + 1].getType() != TILE_TYPE::EMPTY) &&
						(map[i - 1][j + 2].getType() != TILE_TYPE::EMPTY))
						map[i][j].setType(TILE_TYPE::TREE);
						map[i][j + 1].setType(TILE_TYPE::TREE);
					break;
				default:
					break;
				}
			}
		}
	}
}

void DungeonGenerator::generateDungeon(int numberOfTries)
{
	for (auto i = 0; i < numberOfTries; ++i)
	{
		generateRooms();
	}
	//generateMaze(146, 46);
}

std::array<std::array<Tile, 148>, 48> & DungeonGenerator::getGeneratedMap()
{
	return map;
}

bool DungeonGenerator::checkRoomsIntersection(Room A, Room B) const
{
	auto x_overlap = valueInRange(A.x, B.x, B.x + B.width + 1) ||
		valueInRange(B.x, A.x, A.x + A.width + 1);

	auto y_overlap = valueInRange(A.y, B.y, B.y + B.height + 1) ||
		valueInRange(B.y, A.y, A.y + A.height + 1);

	return x_overlap && y_overlap;
}
