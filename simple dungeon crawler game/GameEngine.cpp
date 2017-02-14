#include "stdafx.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
	srand(static_cast<int>(time(nullptr)));
}

GameEngine::~GameEngine()
{
}

bool GameEngine::placeActor(Actor & actor, Game & game, int pos_x, int pos_y) const
{
	actor.setCurrentPos(pos_x, pos_y);
	actor.setOldPos(pos_x, pos_y);
	actor.setNewPos(pos_x, pos_y);
	actor.setChanged(false);
	return true;
}

bool GameEngine::MoveActor(Actor & actor, Game & game, DIR direction)
{
	/*
	actor.setOldPos(actor.getCurrentPosX(), actor.getCurrentPosY());
	old_tile = getTile(actor.getCurrentPosX(), actor.getCurrentPosY(), game);

	if (direction == DIR::RAND)
	{
		int rand_dir = rand() % 4;
		direction = static_cast<DIR>(rand_dir);
	}

	switch (direction)
	{
	case DIR::UP:
		actor.setNewPos(actor.getCurrentPosX(), actor.getCurrentPosY() - 1);
		break;
	case DIR::DOWN:
		actor.setNewPos(actor.getCurrentPosX(), actor.getCurrentPosY() + 1);
		break;
	case DIR::LEFT:
		actor.setNewPos(actor.getCurrentPosX() - 1, actor.getCurrentPosY());
		break;
	case DIR::RIGHT:
		actor.setNewPos(actor.getCurrentPosX() + 1, actor.getCurrentPosY());
		break;
	default:
		break;
	}

	next_tile = getTile(actor.getNewPosX(), actor.getNewPosY(), game);

	switch (next_tile)
	{
	case '#':
		actor.setCurrentPos(actor.getOldPosX(), actor.getOldPosY());
		if(typeid(actor) == typeid(Player))
			printInfo("You run into a wall!");
		actor.setChanged(false);
		break;
	case '~':
		actor.setCurrentPos(actor.getOldPosX(), actor.getOldPosY());
		if(typeid(actor) == typeid(Player))
			printInfo("You cannot go into water!");
		actor.setChanged(false);
		break;
	case 'T':
		actor.setCurrentPos(actor.getOldPosX(), actor.getOldPosY());
		if(typeid(actor) == typeid(Player))
			printInfo("You run into a tree!");
		actor.setChanged(false);
		break;
	case 'g':
	case 'w':
	case 'b':
	case 's':
	case 't':
	case '@':
		if (typeid(actor) == typeid(Player))
		{
			printInfo("Monster attacked!");
		}
		break;
	case '$':
		if (typeid(actor) == typeid(Player))
		{
			printInfo("You found a treasue!");
			printInfo("25 gold coins", 1);
			setTile('.', actor.getNewPosX(), actor.getNewPosY(), game);
			game.player.addExp(10);
			game.player.addGold(25);
		}
		break;
	default:
		actor.setCurrentPos(actor.getNewPosX(), actor.getNewPosY());

		setTile(actor.getGraphicTile(), actor.getCurrentPosX(), actor.getCurrentPosY(), game);
		setTile(next_tile, actor.getOldPosX(), actor.getOldPosY(), game);

		actor.setChanged(true);
		break;
	}

	updateInterface(game);

	return true;
	*/
	return false;
}

