#include "stdafx.h"
#include "GameEngine.h"

GameEngine::GameEngine()
{
	srand(static_cast<int>(time(nullptr)));
}

GameEngine::~GameEngine()
{
}

bool GameEngine::placeActor(Actor & actor, Game & game) const
{
	// check if spot is already occupied

	Tile * temp;

	if(typeid(actor) == typeid(Player))
		temp = new Tile(TILE_TYPE::PLAYER);
	else if(typeid(actor) == typeid(Monster))
		temp = new Tile(TILE_TYPE::MONSTER);
	else
		temp = new Tile(TILE_TYPE::NPC);

	game.levels[0].setLevelData(actor.getCurrentPosX(), actor.getCurrentPosY(), *temp);

	delete temp;

	return true;
}

bool GameEngine::MoveActor(Actor & actor, Game & game, DIR direction)
{
	bool actor_is_player = false;
	if (typeid(actor) == typeid(Player))
		actor_is_player = true;
	
	actor.setOldPos(actor.getCurrentPosX(), actor.getCurrentPosY());
	Tile old_tile = game.levels[0].getLevelData(actor.getCurrentPosX(), actor.getCurrentPosY());

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
	
	Tile next_tile = game.levels[0].getLevelData(actor.getNewPosX(), actor.getNewPosY());
	
	if (next_tile.canCollide() == true && next_tile.canInteract() == false)
	{
		switch (next_tile.getType())
		{
		case TILE_TYPE::WALL:
			if (actor_is_player == true)
				game.setGameMesage("You run into a wall!");
			break;
		case TILE_TYPE::TREE:
			if (actor_is_player == true)
				game.setGameMesage("You run into a tree!");
			break;
		case TILE_TYPE::WATER:
			if (actor_is_player == true)
				game.setGameMesage("You cannot go into water!");
		default:
			break;
		}
	}
	else if(next_tile.canCollide() == false && next_tile.canInteract() == true)
	{
		switch (next_tile.getType())
		{
		case TILE_TYPE::MONSTER:
			if (actor_is_player == true)
			{
				game.setGameMesage("Monster attacked!");
				if (attack_monster(game, game.getMonster(actor.getNewPosX(), actor.getNewPosY())) == true)
				{
					game.levels[0].setLevelData(actor.getNewPosX(), actor.getNewPosY(), TILE_TYPE::EMPTY);
				}
			}
			break;
		case TILE_TYPE::PLAYER:
			game.setGameMesage("You were attacked by a monster!");
			if (attack_player(game, actor) == true)
			{
				return true;
			}
			break;
		case TILE_TYPE::TREASURE:
			if(actor_is_player == true)
			{
				game.setGameMesage("You found a treasure!\n 25 gold coins");
				game.player.addExp(10);
				game.player.addGold(25);
				game.levels[0].setLevelData(actor.getNewPosX(), actor.getNewPosY(), TILE_TYPE::EMPTY);
			}
			break;
		default:
			break;
		}
	}
	else if(next_tile.canCollide() == false && next_tile.canInteract() == false)
	{
		actor.setCurrentPos(actor.getNewPosX(), actor.getNewPosY());
		game.levels[0].setLevelData(actor.getNewPosX(), actor.getNewPosY(), old_tile);
		game.levels[0].setLevelData(actor.getOldPosX(), actor.getOldPosY(), next_tile);
	}
	return false;
}

bool GameEngine::attack_monster(Game & g, Actor & actor)
{
	std::string msg = "";
	// balance of stats needed
	int dmg = rand() % 6 + g.player.getAttackPower();
	int current_monster_hp = actor.getHealth() - dmg;

	actor.setHealth(current_monster_hp);

	msg = "Dmg to monster: " + std::to_string(dmg) + "   Monster HP: " + std::to_string(actor.getHealth()) + " / " + std::to_string(actor.getMaxHealth());

	if (current_monster_hp <= 0)
	{
		// add monster delete

		g.setGameFightMesage(msg);
		g.setGameMesage("Monster is dead!");
		g.player.addExp(actor.getLevel() * 25);

		if (g.player.getExp() >= g.player.exp_to_lvl_up[g.player.getLevel() + 1])
		{
			int exp_to_move = g.player.getExp() - g.player.exp_to_lvl_up[g.player.getLevel() + 1];
			g.player.levelUp();
			g.player.addExp(exp_to_move);
		}
		return true;
	}

	g.setGameFightMesage(msg);
	return false;
}

bool GameEngine::attack_player(Game & g, Actor & actor)
{
	std::string msg = "";

	int dmg = rand() % 6 + actor.getAttackPower();
	int current_player_hp = g.player.getHealth() - dmg;

	g.player.setHealth(current_player_hp);

	msg = "Dmg to player: " + std::to_string(dmg) + "   Monster HP: " + std::to_string(actor.getHealth()) + " / " + std::to_string(actor.getMaxHealth());

	if (current_player_hp <= 0)
	{
		g.player.setDead(true);
		g.setGameMesage("You died!");
	}

	g.setGameFightMesage(msg);
	return false;
}

