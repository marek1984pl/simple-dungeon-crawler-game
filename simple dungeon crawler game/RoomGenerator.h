#pragma once

#include <vector>

#include "utilities.h"
#include "Tile.h"
#include "Level.h"

class RoomGenerator : public virtual Level
{
protected:
	struct Room
	{
		int x, y;
		int width, height;
	};

	std::vector<Room> rooms;

public:
	RoomGenerator();
	~RoomGenerator();

	void generateRooms();

	bool checkRoomsIntersection(const Room r_A, const Room r_B) const;

	void makeRoomConections();
	void removeDeadEnds();
	int checkNumberOfExits(const int x, const int y) const;
	// todo add room decorator function e.g. trees in room, water etc.
};
