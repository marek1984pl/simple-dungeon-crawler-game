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

int Actor::getHealth() const
{
	return health;
}

int Actor::getMaxHealth() const
{
	return max_health;
}

void Actor::setName(std::string _name)
{
	name = _name;
}

void Actor::setLevel(int _level)
{
	level = _level;
}

void Actor::setHealth(int _health)
{
	health = _health;
}

void Actor::setMaxHealth(int _health)
{
	max_health = _health;
}

void Actor::setCurrentPos(int pos_x, int pos_y)
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

void Actor::setOldPos(int pos_x, int pos_y)
{
	old_pos_x = pos_x;
	old_pos_y = pos_y;
}

void Actor::setChanged(bool change)
{
	position_changed = change;
}

bool Actor::isChanged() const
{
	return (position_changed ? true : false);
}

void Actor::setGraphicTile(char tile)
{
	graphic_tile = tile;
}

char Actor::getGraphicTile()
{
	return graphic_tile;
}
