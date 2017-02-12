#include "stdafx.h"
#include "Actor.h"


Actor::Actor() : current_position_x(2), current_position_y(2)
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

void Actor::SetCurrentPosition(int pos_x, int pos_y)
{
	current_position_x = pos_x;
	current_position_y = pos_y;
}

int Actor::GetCurrentPositionX() const
{
	return current_position_x;
}

int Actor::GetCurrentPositionY() const
{
	return current_position_y;
}

void Actor::SetOldPosition(int pos_x, int pos_y)
{
	old_position_x = pos_x;
	old_position_x = pos_y;
}

int Actor::GetOldPositionX() const
{
	return old_position_x;
}

int Actor::GetOldPositionY() const
{
	return old_position_y;
}

void Actor::setChanged(bool change)
{
	position_changed = change;
}

bool Actor::isChanged() const
{
	return (position_changed ? true : false);
}
