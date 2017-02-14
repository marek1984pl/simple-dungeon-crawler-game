#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	strength = 5;
	dexterity = 3;
	stamina = 5;
}


Player::~Player()
{
}

int Player::getGold() const
{
	return gold;
}

int Player::getXP() const
{
	return exp;
}

void Player::setGold(int g)
{
	gold = g;
}

void Player::setExp(int xp)
{
	exp = xp;
}

void Player::addExp(int xp)
{
	exp += xp;
}

void Player::levelUp()
{
	setStrength(getStrength() + 1);
	setDexterity(getDexterity() + 1);
	setStamina(getStamina() + 1);

	setLevel(getLevel() + 1);
	max_health = getStamina() * getLevel() * 2;
	setExp(0);
}

void Player::setMaxHealth()
{
	max_health = getStamina() * getLevel() * 2;
}

void Player::setAttackPower()
{
	attack_power = (getStrength() + getLevel()) * 2 + getDexterity();
}

void Player::setArmor()
{
	armor = (getDexterity() + getLevel()) * 2 + getStrength();
}
