#include "stdafx.h"
#include "Monster.h"


Monster::Monster()
{
	strength = 4;
	dexterity = 2;
	stamina = 4;
}

Monster::Monster(std::string name, int lvl, MONSTER_TYPE t)
{
	setName(name);
	setLevel(lvl);

	setCurrentPos(rand() % 145 + 2, rand() % 45 + 2);

	setDexterity(4);
	setStamina(3);
	setStrength(3);

	setArmor();
	setAttackPower();
	setMaxHealth();
	setHealth(getMaxHealth());

	monster_type = t;
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

bool Monster::operator==(const Monster & m1)
{
	if (this->current_pos_x == m1.current_pos_x && this->current_pos_y == m1.current_pos_y)
		return true;
	else 
		return false;
}

MONSTER_TYPE Monster::getMonsterType() const
{
	return monster_type;
}

