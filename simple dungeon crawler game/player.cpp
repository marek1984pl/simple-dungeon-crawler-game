#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	strength = 5;
	dexterity = 3;
	stamina = 5;
	for (int i = 2; i < 100; ++i)
	{
		exp_to_lvl_up[i] = 50 + i * 50;
	}
}

Player::~Player()
{
}

int Player::getGold() const
{
	return gold;
}

int Player::getExp() const
{
	return exp;
}

void Player::setGold(int g)
{
	gold = g;
}

void Player::addGold(int g)
{
	gold += g;
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
	setHealth(max_health);
	setExp(0);

	setAttackPower();
	setArmor();
}

void Player::setHealth(int h)
{
	health = h;
}

int Player::getHealth() const
{
	return health;
}

void Player::setMaxHealth()
{
	max_health = getStamina() * getLevel() * 2;
}

int Player::getMaxHealth() const
{
	return max_health;
}

void Player::setAttackPower()
{
	attack_power = (getStrength() + getLevel()) * 2 + getDexterity();
}

void Player::setArmor()
{
	armor = (getDexterity() + getLevel()) * 2 + getStrength();
}

void Player::setDead(bool d)
{
	is_dead = d;
}

bool Player::isDead()
{
	return is_dead;
}
