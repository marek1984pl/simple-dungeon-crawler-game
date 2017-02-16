#include "stdafx.h"
#include "Monster.h"


Monster::Monster()
{
	strength = 4;
	dexterity = 2;
	stamina = 4;
}

Monster::Monster(std::string name, int lvl)
{
	setName(name);
	setLevel(lvl);
	setCurrentPos(rand() % 145 + 2, rand() % 45 + 2);

	setDexterity(4);
	setStamina(3);
	setStrength(5);

	setArmor();
	setAttackPower();
	setMaxHealth();
	setHealth(getMaxHealth());
}

Monster::~Monster()
{
}

void Monster::setHealth(int h)
{
	health = h;
}

int Monster::getHealth() const
{
	return health;
}

void Monster::setMaxHealth()
{
	max_health = getStamina() * getLevel() * 2;
}

int Monster::getMaxHealth() const
{
	return max_health;
}

void Monster::setAttackPower()
{
	attack_power = (getStrength() + getLevel()) * 2 + getDexterity();
}

void Monster::setArmor()
{
	armor = (getDexterity() + getLevel()) * 2 + getStrength();
}

