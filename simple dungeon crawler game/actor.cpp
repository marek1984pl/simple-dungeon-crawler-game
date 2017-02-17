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

void Actor::setName(std::string n)
{
	name = n;
}

void Actor::setLevel(int lvl)
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

void Actor::setStrength(int str)
{
	strength = str;
}

void Actor::setDexterity(int dex)
{
	dexterity = dex;
}

void Actor::setStamina(int sta)
{
	stamina = sta;
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

int Actor::getNewPosX() const
{
	return new_pos_x;
}

int Actor::getNewPosY() const
{
	return new_pos_y;
}

void Actor::setNewPos(int pos_x, int pos_y)
{
	new_pos_x = pos_x;
	new_pos_y = pos_y;
}

