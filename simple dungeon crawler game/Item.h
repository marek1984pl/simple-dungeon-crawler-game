#pragma once

#include <string>

enum class Item_Type { WEAPON, HELMET, ARMOR, LEGS, SHOULDERS, GLOVES, SHIELD, POTION, GOLD, EMPTY};

class Item
{
public:
	Item();
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
	void setName(int n);

private:
	Item_Type type;

	std::string name;

	int strength;
	int dexterity;
	int stamina;
};

