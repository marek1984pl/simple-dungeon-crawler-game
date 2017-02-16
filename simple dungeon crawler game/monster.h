#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	Monster(std::string name, int lvl);
	~Monster();

	virtual void setHealth(int h) override;
	virtual int getHealth() const override;

	virtual void setMaxHealth() override;
	virtual int getMaxHealth() const override;

	virtual void setAttackPower() override;
	virtual void setArmor() override;
};

