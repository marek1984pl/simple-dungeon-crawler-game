#pragma once

#include <vector>

#include "Actor.h"


class Player : public Actor
{
public:
	Player();
	~Player();

	int GetGold() const;
	int GetXP() const;

	void SetGold(int g);
	void SetExp(int xp);

private:
	int gold = 0;
	int exp = 0;
};

