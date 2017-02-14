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

	void setHealth(int h);
	virtual void setMaxHealth() = 0;

	int getAttackPower();
	int getArmor();
	int getStrength();
	int getDexterity();
	int getStamina();

	virtual void setAttackPower() = 0;
	virtual void setArmor() = 0;
	void setStrength(int str);
	void setDexterity(int dex);
	void setStamina(int sta);

	int getCurrentPosX() const;
	int getCurrentPosY() const;

	int getOldPosX() const;
	int getOldPosY() const;

	void setCurrentPos(int pos_x, int pos_y);
	void setOldPos(int pos_x, int pos_y);

	int getNewPosX() const;
	int getNewPosY() const;

	void setNewPos(int new_x, int new_y);

	void setChanged(bool change);
	bool isChanged() const;

	void setGraphicTile(char tile);
	char getGraphicTile() const;

protected:
	std::string name;
	int level;

	int health;
	int max_health;
	int attack_power;
	int armor;
	int strength;
	int dexterity;
	int stamina;

	int current_pos_x;
	int current_pos_y;

	int old_pos_x;
	int old_pos_y;

	int new_pos_x;
	int new_pos_y;

	bool position_changed;

	char graphic_tile;

};

