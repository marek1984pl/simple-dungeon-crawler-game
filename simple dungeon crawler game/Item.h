#pragma once

#include <string>

enum class Item_Type { WEAPON, HELMET, ARMOR, LEGS, SHOULDERS, GLOVES, BOOTS, SHIELD, POTION, EMPTY};
enum class Quality { NORMAL, MAGIC, RARE, EPIC };

class Item
{
public:
	Item();
	Item(const std::string n, const Item_Type t, const int str, const int dex, const int sta, const Quality q);
	Item(const int game_level, const int additional_chance = 0);
	~Item();

	Item_Type getType() const;

	int getStrength() const;
	int getDexterity() const;
	int getStamina() const;
	std::string getName() const;
	Quality getQuality() const;

	void setType(const Item_Type t);
	void setStrength(const int str);
	void setDexterity(const int dex);
	void setStamina(const int sta);
	void setName(const std::string n);
	void setQuality(const Quality q);

	int calculateItemStats() const;

private:
	Item_Type type;

	std::string name;

	Quality quality;
	int strength;
	int dexterity;
	int stamina;
};
