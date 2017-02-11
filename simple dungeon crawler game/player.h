#pragma once

#include <vector>

#include "Actor.h"


class Player : public Actor
{
public:
	Player();
	~Player();

private:
	int gold;
};

