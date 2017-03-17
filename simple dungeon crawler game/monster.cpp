#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(std::string name, int lvl, MONSTER_TYPE t)
{
	setName(name);
	setLevel(lvl);

	setStrength(4);
	setDexterity(3);
	setStamina(5);

	Monster::setMaxHealth();
	Monster::setArmor();
	Monster::setAttackPower();
	Monster::setHealth(Monster::getMaxHealth());

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
	max_health = (getStamina() + getLevel() * 2) * 2;
}

int Monster::getMaxHealth() const
{
	return max_health;
}

void Monster::setAttackPower()
{
	attack_power = (getStrength() + getLevel()) * 2;
}

void Monster::setArmor()
{
	armor = (getDexterity() + getLevel()) * 2;
}

bool Monster::operator==(const Monster & m) const
{
	if (this->current_pos_x == m.current_pos_x && this->current_pos_y == m.current_pos_y)
		return true;
	return false;
}

MONSTER_TYPE Monster::getMonsterType() const
{
	return monster_type;
}
