#pragma once

#include "Actor.h"


class Player : public Actor
{
public:
	Player();
	~Player();

	int getGold() const;
	int getExp() const;

	void setGold(int g);
	void addGold(int g);
	void setExp(int xp);
	void addExp(int xp);

	void levelUp();

	virtual void setMaxHealth() override;

	virtual void setAttackPower() override;
	virtual void setArmor() override;

private:
	int gold = 0;
	int exp = 0;
};

