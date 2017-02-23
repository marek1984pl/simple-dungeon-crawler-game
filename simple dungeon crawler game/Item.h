#pragma once

#include <string>

enum class Item_Type { WEAPON, HELMET, ARMOR, LEGS, SHOULDERS, GLOVES, BOOTS, SHIELD, POTION, EMPTY};

class Item
{
public:
	Item(int option = 0);
	Item(std::string n, Item_Type t, int str, int dex, int sta);
	~Item();

	Item_Type getType() const;

	int getStrength() const;
	int getDexterity() const;
	int getStamina() const;
	std::string getName() const;

	void setType(Item_Type t);
	void setStrength(int str);
	void setDexterity(int dex);
	void setStamina(int sta);
	void setName(std::string n);

	int calculateItemStats() const;

private:
	Item_Type type;

	std::string name;

	int strength;
	int dexterity;
	int stamina;
};

