#pragma once

#include <ctime>
#include <string>

#include "actor.h"
#include "Game.h"

enum class DIR { UP, DOWN, LEFT, RIGHT, RAND };

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	bool placeActor(Actor & actor, Game & game) const;
	bool MoveActor(Actor & actor, Game & game, DIR direction);

	bool attack_monster(Game & g, Actor & actor);
	bool attack_player(Game & g, Actor & actor);
};
