#pragma once

#include <array>
#include <map>

#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	~Player();

	int getGold() const;
	int getExp() const;

	void setGold(const int g);
	void addGold(const int g);
	void setExp(const int xp);
	void addExp(const int xp);

	void levelUp();

	void setHealth(const int h) override;
	int getHealth() const override;

	void setMaxHealth() override;
	int getMaxHealth() const override;

	void setAttackPower() override;
	void setArmor() override;

	int getTotalStrength() const;
	int getTotalDexterity() const;
	int getTotalStamina() const;

	int getStrengthFromItems() const;
	int getDexterityFromItems() const;
	int getStaminaFromItems() const;

	std::array<int, 100> exp_to_lvl_up;

	void setDead(const bool d);
	bool isDead() const;

	bool addBackpackItem(const Item & item);
	bool removeBackpackItem(const Item_Type t);
	std::array<Item, 5> & getBackpack();

	std::map<Item_Type, Item> & getInventory();
	bool addInventoryItem(const Item & item);
	Item & getItemFromInventory(const Item_Type slot);

	void refreshStats();

private:
	int gold = 0;
	int exp = 0;
	bool is_dead;

	int strenght_from_items = 0;
	int dexterity_from_items = 0;
	int stamina_from_items = 0;

	int strength_total = 0;
	int dexterity_total = 0;
	int stamina_total = 0;

	std::array<Item, 5> backpack;
	std::map<Item_Type, Item> inventory;
};
