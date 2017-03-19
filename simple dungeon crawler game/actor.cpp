#include "stdafx.h"
#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

std::string Actor::getName() const
{
	return name;
}

int Actor::getLevel() const
{
	return level;
}

void Actor::setName(const std::string n)
{
	name = n;
}

void Actor::setLevel(const int lvl)
{
	level = lvl;
}

int Actor::getAttackPower() const
{
	return attack_power;
}

int Actor::getArmor() const
{
	return armor;
}

int Actor::getStrength() const
{
	return strength;
}

int Actor::getDexterity() const
{
	return dexterity;
}

int Actor::getStamina() const
{
	return stamina;
}

void Actor::setStrength(const int str)
{
	strength = str;
}

void Actor::setDexterity(const int dex)
{
	dexterity = dex;
}

void Actor::setStamina(const int sta)
{
	stamina = sta;
}

void Actor::setCurrentPos(const int pos_x, const int pos_y)
{
	current_pos_x = pos_x;
	current_pos_y = pos_y;
}

int Actor::getCurrentPosX() const
{
	return current_pos_x;
}

int Actor::getCurrentPosY() const
{
	return current_pos_y;
}

int Actor::getOldPosX() const
{
	return old_pos_x;
}

int Actor::getOldPosY() const
{
	return old_pos_y;
}

void Actor::setOldPos(const int pos_x, const int pos_y)
{
	old_pos_x = pos_x;
	old_pos_y = pos_y;
}

int Actor::getNewPosX() const
{
	return new_pos_x;
}

int Actor::getNewPosY() const
{
	return new_pos_y;
}

void Actor::setNewPos(const int pos_x, const int pos_y)
{
	new_pos_x = pos_x;
	new_pos_y = pos_y;
}

Tile Actor::getActorTile() const
{
	return actor_tile;
}

void Actor::setActorTile(const Tile & tile, char symbol)
{
	actor_tile = tile;
	if (symbol != '?')
		actor_tile.setTileSymbol(symbol);
}

