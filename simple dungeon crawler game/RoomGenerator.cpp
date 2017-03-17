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
	auto room_height = generateRandNumber(3, 6);

	auto * r = new Room;
	// todo change min and max room coords to avoid blind rooms when opening them to corridors
	r->x = generateRandNumber(2, game_size_max_x - room_width - 1);
	r->y = generateRandNumber(2, game_size_max_y - room_height - 1);
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
					setMapTile(j, i, TILE_TYPE::EMPTY);
				}
			}
		}
	}
	delete r;
}

bool RoomGenerator::checkRoomsIntersection(Room A, Room B) const
{
	auto x_overlap = valueInRange(A.x, B.x, B.x + B.width + 2) || valueInRange(B.x, A.x, A.x + A.width + 2);
	auto y_overlap = valueInRange(A.y, B.y, B.y + B.height + 2) || valueInRange(B.y, A.y, A.y + A.height + 2);

	return x_overlap && y_overlap;
}

void RoomGenerator::makeRoomConection()
{
	int room_min_x;
	int room_min_y;
	int room_max_x;
	int room_max_y;

	struct pos
	{
		pos(int x_, int y_) : x(x_), y(y_) {}
		int x, y;
	};

	std::vector<pos> tiles;
	int tile_to_open;

	int additional_chance_to_open;

	for (auto & i : rooms)
	{
		// todo
		room_min_x = i.x;
		room_min_y = i.y;
		room_max_x = i.x + i.width;
		room_max_y = i.y + i.height;

		for (auto y = room_min_y; y < room_max_y; ++y)
		{
			if (valueInRange(room_min_x - 2, 1, game_size_max_x) && valueInRange(room_max_x + 2, 1, game_size_max_x))
			{
				if (getMapTile(room_min_x - 2, y).getType() == TILE_TYPE::EMPTY)
					tiles.push_back(pos(room_min_x - 1, y));
				if (getMapTile(room_max_x + 1, y).getType() == TILE_TYPE::EMPTY)
					tiles.push_back(pos(room_max_x, y));
			}
		}

		for (auto x = room_min_x; x < room_max_x; ++x)
		{
			if (valueInRange(room_min_y - 2, 1, game_size_max_y) && valueInRange(room_max_y + 2, 1, game_size_max_y))
			{
				if (getMapTile(x, room_min_y - 2).getType() == TILE_TYPE::EMPTY)
					tiles.push_back(pos(x, room_min_y - 1));
				if (getMapTile(x, room_max_y + 1).getType() == TILE_TYPE::EMPTY)
					tiles.push_back(pos(x, room_max_y));
			}
		}

		if (tiles.empty() == false)
		{
			tile_to_open = generateRandNumber(0, tiles.size() - 1);
			setMapTile(tiles.at(tile_to_open).x, tiles.at(tile_to_open).y, TILE_TYPE::EMPTY);

			additional_chance_to_open = generateRandNumber(0, 100);
			if (valueInRange(additional_chance_to_open, 0, 50))
			{
				tile_to_open = generateRandNumber(0, tiles.size() - 1);
				setMapTile(tiles.at(tile_to_open).x, tiles.at(tile_to_open).y, TILE_TYPE::EMPTY);
			}

			tiles.clear();
		}
	}
}

void RoomGenerator::removeDeadEnds()
{
	auto done = false;
	auto number_of_exits = 0;

	while (done == false)
	//for (auto i = 1; i < 100; ++i)
	{
		done = true;
		for (auto y = 1; y < game_size_max_y; ++y)
		{
			for (auto x = 1; x < game_size_max_x; ++x)
			{
				if (getMapTile(x, y).getType() == TILE_TYPE::EMPTY)
				{
					number_of_exits = checkNumberOfExits(x, y);
					
					if (number_of_exits == 1)
					{
						setMapTile(x, y, TILE_TYPE::WALL);
						done = false;
					}
				}
			}
		}
	}
}

int RoomGenerator::checkNumberOfExits(int x, int y)
{
	auto possible_routes = 0;

	if (valueInRange(x, 1, game_size_max_x) == false && valueInRange(y, 1, game_size_max_y) == false)
		return 0;
	if (getMapTile(x, y - 1).getType() == TILE_TYPE::EMPTY)
		possible_routes++;
	if (getMapTile(x, y + 1).getType() == TILE_TYPE::EMPTY)
		possible_routes++;
	if (getMapTile(x - 1, y).getType() == TILE_TYPE::EMPTY)
		possible_routes++;
	if (getMapTile(x + 1, y).getType() == TILE_TYPE::EMPTY)
		possible_routes++;

	return possible_routes;
}
