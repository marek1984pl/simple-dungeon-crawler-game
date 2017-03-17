#pragma once

#include <string>

enum class Item_Type { WEAPON, HELMET, ARMOR, LEGS, SHOULDERS, GLOVES, BOOTS, SHIELD, POTION, EMPTY};
enum class Quality { NORMAL, MAGIC, RARE, EPIC };

class Item
{
public:
	Item();
	Item(std::string n, Item_Type t, int str, int dex, int sta, Quality q);
	Item(int game_level, int additional_chance = 0);
	~Item();

	Item_Type getType() const;

	int getStrength() const;
	int getDexterity() const;
	int getStamina() const;
	std::string getName() const;
	Quality getQuality() const;

	void setType(Item_Type t);
	void setStrength(int str);
	void setDexterity(int dex);
	void setStamina(int sta);
	void setName(std::string n);
	void setQuality(Quality q);

	int calculateItemStats() const;

private:
	Item_Type type;

	std::string name;

	Quality quality;
	int strength;
	int dexterity;
	int stamina;
};
