#include "stdafx.h"
#include "Player.h"


Player::Player()
{
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
	setExp(0);

	setMaxHealth();
	setAttackPower();
	setArmor();

	setHealth(max_health);
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
	max_health = getStamina() * 2;
}

int Player::getMaxHealth() const
{
	return max_health;
}

void Player::setAttackPower()
{
	attack_power = (getStrength() + getLevel()) * 2;
}

void Player::setArmor()
{
	armor = (getDexterity() + getLevel()) * 2;
}

void Player::setDead(bool d)
{
	is_dead = d;
}

bool Player::isDead() const
{
	return is_dead;
}
