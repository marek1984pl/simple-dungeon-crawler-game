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

	bool checkRoomsIntersection(Room r_A, Room r_B) const;

	void makeRoomConection();
	void removeDeadEnds();
	int checkNumberOfExits(int x, int y);
};

