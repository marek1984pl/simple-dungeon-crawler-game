#pragma once

#include <iostream>

#include "Item.h"

class Actor
{
public:
	Actor();
	virtual ~Actor() = 0;

	std::string getName() const;
	int getLevel() const;
	int getHealth() const;

	void setName(std::string _name);
	void setLevel(int _level);
	void setHealth(int _health);

	void SetCurrentPosition(int pos_x, int pos_y);
	int GetCurrentPositionX() const;
	int GetCurrentPositionY() const;

	void SetOldPosition(int pos_x, int pos_y);
	int GetOldPositionX() const;
	int GetOldPositionY() const;

	void setChanged(bool change);
	bool isChanged() const;

private:
	std::string name;
	int level;
	int health;
	int current_position_x;
	int current_position_y;

	int old_position_x;
	int old_position_y;

	bool position_changed;
};

