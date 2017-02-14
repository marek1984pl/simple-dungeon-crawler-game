#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	Monster(std::string name, int lvl);
	~Monster();

	virtual void setMaxHealth() override;

	virtual void setAttackPower() override;
	virtual void setArmor() override;
};

