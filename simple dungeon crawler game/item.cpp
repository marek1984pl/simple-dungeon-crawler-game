#include "stdafx.h"
#include "Item.h"


Item::Item(int option) : name(""), type(Item_Type::EMPTY), strength(0), dexterity(0), stamina(0)
{
	if (option != 0)
	{
		int random = rand() % 8;
		switch (random)
		{
		case 0:
			setName("Sword");
			setType(Item_Type::WEAPON);
			break;
		case 1:
			setName("Shield");
			setType(Item_Type::SHIELD);
			break;
		case 2:
			setName("Armor");
			setType(Item_Type::ARMOR);
			break;
		case 3:
			setName("Helmet");
			setType(Item_Type::HELMET);
			break;
		case 4:
			setName("Gloves");
			setType(Item_Type::GLOVES);
			break;
		case 5:
			setName("Shoulders");
			setType(Item_Type::SHOULDERS);
			break;
		case 6:
			setName("Legs");
			setType(Item_Type::LEGS);
			break;
		case 7:
			setName("Boots");
			setType(Item_Type::BOOTS);
			break;
		default:
			break;
		}

		setStrength(rand() % 3);
		setDexterity(rand() % 3);
		setStamina(rand() % 3);
	}
}

Item::Item(std::string n, Item_Type t, int str, int dex, int sta)
{
	name = n;
	type = t;
	strength = str;
	dexterity = dex;
	stamina = sta;
}

Item::~Item()
{
}

Item_Type Item::getType() const
{
	return type;
}

int Item::getStrength() const
{
	return strength;
}

int Item::getDexterity() const
{
	return dexterity;
}

int Item::getStamina() const
{
	return stamina;
}

std::string Item::getName() const
{
	return name;
}

void Item::setType(Item_Type t)
{
	type = t;
}

void Item::setStrength(int str)
{
	strength = str;
}

void Item::setDexterity(int dex)
{
	dexterity = dex;
}

void Item::setStamina(int sta)
{
	stamina = sta;
}

void Item::setName(std::string n)
{
	name = n;
}

int Item::calculateItemStats() const
{
	return strength + dexterity + stamina;
}
