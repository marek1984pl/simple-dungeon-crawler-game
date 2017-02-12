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

void Actor::setPosition(Position pos)
{
	current_position.x = pos.x;
	current_position.y = pos.y;
}

void Actor::setPosition(int pos_x, int pos_y)
{
	current_position.x = pos_x;
	current_position.y = pos_y;
}

Actor::Position Actor::getPosition() const
{
	return current_position;
}

bool Actor::move(Position new_position)
{
	current_position.x = new_position.x;
	current_position.y = new_position.y;
	return true;
}
