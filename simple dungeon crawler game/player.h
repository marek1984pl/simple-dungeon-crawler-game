#pragma once

#include "Actor.h"


class Player : public Actor
{
public:
	Player();
	~Player();

	int getGold() const;
	int getXP() const;

	void setGold(int g);
	void setExp(int xp);

	void levelUp();

private:
	int gold = 0;
	int exp = 0;
};

