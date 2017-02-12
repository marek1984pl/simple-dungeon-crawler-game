#pragma once

#include <iostream>

#include "Item.h"

class Actor
{
public:
	struct Position
	{
		int x;
		int y;
	};

	Actor();
	virtual ~Actor() = 0;

	std::string getName() const;
	int getLevel() const;
	int getHealth() const;

	void setName(std::string _name);
	void setLevel(int _level);
	void setHealth(int _health);

	void setPosition(Position pos);
	void setPosition(int pos_x, int pos_y);
	Position getPosition() const;

	bool move(Position new_position);

private:
	std::string name;
	int level;
	int health;
	Position current_position;

};

