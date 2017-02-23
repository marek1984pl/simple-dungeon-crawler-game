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

	void setGold(int g);
	void addGold(int g);
	void setExp(int xp);
	void addExp(int xp);

	void levelUp();

	virtual void setHealth(int h) override;
	virtual int getHealth() const override;

	virtual void setMaxHealth() override;
	virtual int getMaxHealth() const override;

	virtual void setAttackPower() override;
	virtual void setArmor() override;

	int getTotalStrength() const;
	int getTotalDexterity() const;
	int getTotalStamina() const;

	int getStrengthFromItems() const;
	int getDexterityFromItems() const;
	int getStaminaFromItems() const;

	std::array<int, 100> exp_to_lvl_up;

	void setDead(bool d);
	bool isDead() const;

	bool addBackpackItem(Item & item);
	bool removeBackpackItem(Item_Type t);
	std::array<Item, 5> & getBackpack();

	std::map<Item_Type, Item> & getInventory();
	bool addInventoryItem(Item & item);
	Item & getItemFromInventory(Item_Type slot);

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

