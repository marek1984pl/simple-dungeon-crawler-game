#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

int Player::GetGold() const
{
	return gold;
}

int Player::GetXP() const
{
	return exp;
}

void Player::SetGold(int g)
{
	gold = g;
}

void Player::SetExp(int xp)
{
	exp = xp;
}
