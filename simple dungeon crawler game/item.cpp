#include "stdafx.h"
#include "Item.h"


Item::Item() : name(""), type(Item_Type::EMPTY), strength(0), dexterity(0), stamina(0)
{
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

void Item::setName(int n)
{
	name = n;
}
