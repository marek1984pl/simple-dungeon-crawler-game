#pragma once

#include <ctime>
#include <string>

#include "actor.h"
#include "Game.h"

enum class DIR { UP, DOWN, LEFT, RIGHT, L_UP, L_DOWN, R_UP, R_DOWN, RAND };
enum RESULT { PLAYER_DEAD, MONSTER_DEAD, NONE, LEVEL_DOWN, LEVEL_UP };

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	bool placeActor(Actor & actor, Game & game) const;
	RESULT MoveActor(Actor & actor, Game & game, DIR direction) const;

	RESULT attack_monster(Game & g, Actor & monster) const;
	RESULT attack_player(Game & g, Actor & monster) const ;

	void pickUpTreasure(Game & g) const;
	void lootCorpse(Game & game) const;

	RESULT changeLevel(Game & g, int lvl) const;

	void useItem(Player & p) const;
};
