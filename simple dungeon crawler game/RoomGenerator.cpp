#include "stdafx.h"
#include "RoomGenerator.h"


RoomGenerator::RoomGenerator()
{
}


RoomGenerator::~RoomGenerator()
{
}

void RoomGenerator::generateRooms()
{
	auto room_width = generateRandNumber(7, 12);
	auto room_height = generateRandNumber(3, 7);

	auto * r = new Room;
	r->x = generateRandNumber(1, game_size_max_x - room_width);
	r->y = generateRandNumber(1, game_size_max_y - room_height);
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
				//map[i][j].setType(TILE_TYPE::EMPTY);
				setMapTile(j, i, TILE_TYPE::EMPTY);
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
					//map[i][j].setType(TILE_TYPE::EMPTY);
					setMapTile(j, i, TILE_TYPE::EMPTY);
				}
			}
		}
	}
	delete r;
}

bool RoomGenerator::checkRoomsIntersection(Room A, Room B) const
{
	auto x_overlap = valueInRange(A.x, B.x, B.x + B.width + 1) || valueInRange(B.x, A.x, A.x + A.width + 1);
	auto y_overlap = valueInRange(A.y, B.y, B.y + B.height + 1) || valueInRange(B.y, A.y, A.y + A.height + 1);

	return x_overlap && y_overlap;
}