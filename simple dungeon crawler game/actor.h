#pragma once

#include "Item.h"
#include "Tile.h"

class Actor
{
public:
	Actor();
	virtual ~Actor() = 0;

	std::string getName() const;
	int getLevel() const;

	void setName(const std::string n);
	void setLevel(const int lvl);

	virtual void setHealth(const int h) = 0;
	virtual void setMaxHealth() = 0;
	virtual int getHealth() const = 0;
	virtual int getMaxHealth() const = 0;

	int getAttackPower() const;
	int getArmor() const;
	int getStrength() const;
	int getDexterity() const;
	int getStamina() const;

	virtual void setAttackPower() = 0;
	virtual void setArmor() = 0;
	void setStrength(const int str);
	void setDexterity(const int dex);
	void setStamina(const int sta);

	int getOldPosX() const;
	int getOldPosY() const;

	int getCurrentPosX() const;
	int getCurrentPosY() const;

	int getNewPosX() const;
	int getNewPosY() const;

	void setOldPos(const int pos_x, const int pos_y);
	void setCurrentPos(const int pos_x, const int pos_y);
	void setNewPos(const int pos_x, const int pos_y);

	Tile getActorTile() const;
	void setActorTile(const Tile & tile, const char symbol = '?');

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

	Tile actor_tile;
};
