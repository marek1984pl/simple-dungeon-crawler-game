#include "stdafx.h"
#include "Monster.h"


Monster::Monster()
{
}

Monster::Monster(std::string name, int lvl, char tile)
{
	setName(name);
	setLevel(lvl);
	setGraphicTile(tile);
	setCurrentPos(rand() % 140 + 5, rand() % 40 + 5);
}


Monster::~Monster()
{
}
