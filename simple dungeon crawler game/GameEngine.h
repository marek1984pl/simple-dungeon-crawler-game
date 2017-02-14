#pragma once

#include <ctime>

#include "actor.h"
#include "Game.h"

enum class DIR { UP, DOWN, LEFT, RIGHT, RAND };

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	bool placeActor(Actor & actor, Game & game, int pos_x, int pos_y) const;
	bool MoveActor(Actor & actor, Game & game, DIR direction);
};
