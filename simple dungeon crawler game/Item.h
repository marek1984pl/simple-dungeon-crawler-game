#pragma once

enum class Item_Type { WEAPON, HELMET, ARMOR, LEGS, SHOULDERS, GLOVES, SHIELD, POTION, GOLD};

class Item
{
public:
	Item();
	~Item();

private:
	Item_Type type;
};

