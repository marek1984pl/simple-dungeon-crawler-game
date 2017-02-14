#include "stdafx.h"
#include "Player.h"


Player::Player()
{
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

void Player::levelUp()
{
	setLevel(getLevel() + 1);
	setMaxHealth(10 * getLevel());
	setHealth(getMaxHealth());
	setExp(0);
}
