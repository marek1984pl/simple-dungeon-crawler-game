#include "stdafx.h"
#include "Item.h"
#include "DungeonGenerator.h"


Item::Item() : name(""), type(Item_Type::EMPTY), strength(0), dexterity(0), stamina(0), quality(Quality::NORMAL)
{
}

Item::Item(std::string n, Item_Type t, int str, int dex, int sta, Quality q)
{
	name = n;
	type = t;
	strength = str;
	dexterity = dex;
	stamina = sta;
	quality = q;
}

Item::Item(int game_level, int additional_chance)
{
	auto item_type = generateRandNumber(0, 7);
	auto random_quality = generateRandNumber(0, 100) + additional_chance;
	auto random_stat = 0;

	std::string item_name = "";
	strength = 0;
	dexterity = 0;
	stamina = 0;

	switch (item_type)
	{
	case 0:
		item_name = "Sword";
		setType(Item_Type::WEAPON);
		break;
	case 1:
		item_name = "Shield";
		setType(Item_Type::SHIELD);
		break;
	case 2:
		item_name = "Armor";
		setType(Item_Type::ARMOR);
		break;
	case 3:
		item_name = "Helmet";
		setType(Item_Type::HELMET);
		break;
	case 4:
		item_name = "Gloves";
		setType(Item_Type::GLOVES);
		break;
	case 5:
		item_name = "Shoulders";
		setType(Item_Type::SHOULDERS);
		break;
	case 6:
		item_name = "Legs";
		setType(Item_Type::LEGS);
		break;
	case 7:
		item_name = "Boots";
		setType(Item_Type::BOOTS);
		break;
	default:
		break;
	}

	if (random_quality >= 0 && random_quality < 50)
	{
		item_name = "Simple " + item_name;
		setQuality(Quality::NORMAL);
	}
	else if (random_quality >= 50 && random_quality < 80)
	{
		random_stat = generateRandNumber(0, 2);
		switch (random_stat)
		{
		case 0:
			setStrength(generateRandNumber(0, 1) + game_level + 1);
			item_name += " of strength";
			break;
		case 1:
			setDexterity(generateRandNumber(0, 1) + game_level + 1);
			item_name += " of dexterity";
			break;
		case 2:
			setStamina(generateRandNumber(0, 1) + game_level + 1);
			item_name += " of stamina";
			break;
		default:
			break;
		}
		setQuality(Quality::MAGIC);
	}
	else if (random_quality >= 80 && random_quality < 95)
	{
		random_stat = generateRandNumber(0, 2);
		switch (random_stat)
		{
		case 0:
			setStrength(generateRandNumber(0, 1) + game_level + 1);
			setDexterity(generateRandNumber(0, 1) + game_level + 1);
			item_name += " of power";
			break;
		case 1:
			setStrength(generateRandNumber(0, 1) + game_level + 1);
			setStamina(generateRandNumber(0, 1) + game_level + 1);
			item_name += " of endurance";
			break;
		case 2:
			setDexterity(generateRandNumber(0, 1) + game_level + 1);
			setStamina(generateRandNumber(0, 1) + game_level + 1);
			item_name += " of cunning";
			break;
		default:
			break;
		}
		setQuality(Quality::RARE);
	}
	else
	{
		setStrength(generateRandNumber(0, 1) + game_level + 2);
		setDexterity(generateRandNumber(0, 1) + game_level + 2);
		setStamina(generateRandNumber(0, 1) + game_level + 2);

		item_name += " of might";
		setQuality(Quality::EPIC);
	}

	name = item_name;
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

Quality Item::getQuality() const
{
	return quality;
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

void Item::setQuality(Quality q)
{
	quality = q;
}

int Item::calculateItemStats() const
{
	return strength + dexterity + stamina;
}
