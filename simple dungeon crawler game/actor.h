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
	int getMaxHealth() const;

	void setName(std::string _name);
	void setLevel(int _level);
	void setHealth(int _health);
	void setMaxHealth(int _health);

	int GetCurrentPosX() const;
	int GetCurrentPosY() const;

	int GetOldPosX() const;
	int GetOldPosY() const;

	void SetCurrentPos(int pos_x, int pos_y);
	void SetOldPos(int pos_x, int pos_y);

	void setChanged(bool change);
	bool isChanged() const;

	void setGraphicTile(char tile);
	char getGraphicTile();

private:
	std::string name;
	int level;
	int health;
	int max_health;
	int current_pos_x;
	int current_pos_y;

	int old_pos_x;
	int old_pos_y;

	bool position_changed;

	char graphic_tile = 'x';
};

