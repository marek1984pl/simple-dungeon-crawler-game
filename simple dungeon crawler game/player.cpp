#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	for (auto i = 2; i < 100; ++i)
	{
		exp_to_lvl_up[i] = 50 + i * 50;
	}

	setLevel(1);
	setStrength(3);
	setDexterity(4);
	setStamina(7);
	setExp(0);
	setGold(0);

	setCurrentPos(1, 1);
	setOldPos(1, 1);
	setNewPos(1, 1);

	refreshStats();

	setMaxHealth();
	setArmor();
	setAttackPower();
	setHealth(getMaxHealth());

	for (auto i = 0; i < 2; i++)
		addBackpackItem(Item("Health potion", Item_Type::POTION, 0, 0, 0, Quality::NORMAL));

	addInventoryItem(Item("Simple club", Item_Type::WEAPON, 0, 0, 0, Quality::NORMAL));
	addInventoryItem(Item("Simple pants", Item_Type::LEGS, 0, 0, 0, Quality::NORMAL));
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

	refreshStats();
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
	max_health = getTotalStamina() * 3;
}

int Player::getMaxHealth() const
{
	return max_health;
}

void Player::setAttackPower()
{
	attack_power = getTotalStrength() * 2 + getLevel();
}

void Player::setArmor()
{
	armor = getTotalDexterity() * 2 + getLevel();
}

int Player::getTotalStrength() const
{
	return strength_total;
}

int Player::getTotalDexterity() const
{
	return dexterity_total;
}

int Player::getTotalStamina() const
{
	return stamina_total;
}

int Player::getStrengthFromItems() const
{
	return strenght_from_items;
}

int Player::getDexterityFromItems() const
{
	return dexterity_from_items;
}

int Player::getStaminaFromItems() const
{
	return stamina_from_items;
}

void Player::setDead(bool d)
{
	is_dead = d;
}

bool Player::isDead() const
{
	return is_dead;
}

bool Player::addBackpackItem(Item & item)
{
	for (auto i = backpack.begin(); i != backpack.end(); ++i)
	{
		if (i->getType() == Item_Type::EMPTY)
		{
			*i = item;
			return true;
		}
	}
	return false;
}

bool Player::removeBackpackItem(Item_Type t)
{
	Item empty;

	for (auto i = backpack.rbegin(); i != backpack.rend(); ++i)
	{
		if(i->getType() == t)
		{
			*i = empty;
			return true;
		}
	}
	return false;
}

std::array<Item, 5> & Player::getBackpack()
{
	return backpack;
}

std::map<Item_Type, Item>& Player::getInventory()
{
	return inventory;
}

bool Player::addInventoryItem(Item & item)
{
	if (inventory[item.getType()].calculateItemStats() <= item.calculateItemStats())
		inventory[item.getType()] = item;

	refreshStats();
	return true;
}

Item & Player::getItemFromInventory(Item_Type slot)
{
	return inventory[slot];
}

void Player::refreshStats()
{
	strenght_from_items = 0;
	dexterity_from_items = 0;
	stamina_from_items = 0;

	for (auto& i : inventory)
	{
		strenght_from_items += i.second.getStrength();
		dexterity_from_items += i.second.getDexterity();
		stamina_from_items += i.second.getStamina();
	}

	strength_total = strength + strenght_from_items;
	dexterity_total = dexterity + dexterity_from_items;
	stamina_total = stamina + stamina_from_items;

	setAttackPower();
	setArmor();
	setMaxHealth();
}
