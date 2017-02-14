#include "stdafx.h"
#include "Monster.h"


Monster::Monster()
{
}

Monster::Monster(std::string name, int lvl)
{
	setName(name);
	setLevel(lvl);
	setCurrentPos(rand() % 140 + 5, rand() % 40 + 5);
}


Monster::~Monster()
{
}

void Monster::setMaxHealth()
{
	// todo
}

void Monster::setAttackPower()
{
	// todo
}

void Monster::setArmor()
{
	// todo
}

