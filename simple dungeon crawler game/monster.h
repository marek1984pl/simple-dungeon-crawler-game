#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	Monster(std::string name, int lvl, char tile);
	~Monster();
};

