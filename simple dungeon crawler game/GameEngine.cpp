#include "stdafx.h"
#include "GameEngine.h"
#include <memory>

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

bool GameEngine::placeActor(Actor & actor, Game & game) const
{
	game.levels[game.getCurrentLevel()].setMapTile(actor.getCurrentPosX(), actor.getCurrentPosY(), actor.getActorTile());
	return true;
}

RESULT GameEngine::MoveActor(Actor & actor, Game & game, DIR direction) const
{
	// todo change this to remove typeid
	auto actor_is_player = false;
	if (typeid(actor) == typeid(Player))
		actor_is_player = true;

	std::string msg;

	actor.setOldPos(actor.getCurrentPosX(), actor.getCurrentPosY());
	auto old_tile = game.levels[game.getCurrentLevel()].getMapTile(actor.getCurrentPosX(), actor.getCurrentPosY());

	if (direction == DIR::RAND)
	{
		auto rand_dir = generateRandNumber(0, 7);
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
	case DIR::LEFT_UP:
		actor.setNewPos(actor.getCurrentPosX() - 1, actor.getCurrentPosY() - 1);
		break;
	case DIR::LEFT_DOWN:
		actor.setNewPos(actor.getCurrentPosX() - 1, actor.getCurrentPosY() + 1);
		break;
	case DIR::RIGHT_UP:
		actor.setNewPos(actor.getCurrentPosX() + 1, actor.getCurrentPosY() - 1);
		break;
	case DIR::RIGHT_DOWN:
		actor.setNewPos(actor.getCurrentPosX() + 1, actor.getCurrentPosY() + 1);
		break;
	default:
		break;
	}

	auto next_tile = game.levels[game.getCurrentLevel()].getMapTile(actor.getNewPosX(), actor.getNewPosY());

	if (next_tile.canCollide() == true && next_tile.canInteract() == false)
	{
		switch (next_tile.getType())
		{
		case TILE_TYPE::WALL:
			if (actor_is_player == true)
				game.c_log.addToLog("You run into a wall!");
			break;
		case TILE_TYPE::TREE:
			if (actor_is_player == true)
				game.c_log.addToLog("You run into a tree!");
			break;
		case TILE_TYPE::WATER:
			if (actor_is_player == true)
				game.c_log.addToLog("You cannot go into water!");
		default:
			break;
		}
		return RESULT::NONE;
	}
	if (next_tile.canCollide() == false && next_tile.canInteract() == true)
	{
		switch (next_tile.getType())
		{
		case TILE_TYPE::MONSTER:
			if (actor_is_player == true)
			{
				Monster & temp_monster = game.getMonster(actor.getNewPosX(), actor.getNewPosY());
				msg = "Monster attacked: " + temp_monster.getName() + " level: " + std::to_string(temp_monster.getLevel());
				game.c_log.addToLog(msg);
				if (attack_monster(game, temp_monster) == RESULT::MONSTER_DEAD)
				{
					game.levels[game.getCurrentLevel()].setMapTile(actor.getNewPosX(), actor.getNewPosY(), TILE_TYPE::CORPSE);
					return RESULT::MONSTER_DEAD;
				}
			}
			break;
		case TILE_TYPE::PLAYER:
			msg = "You were attacked by a monster: " + actor.getName() + " level: " + std::to_string(actor.getLevel());
			game.c_log.addToLog(msg);
			if (attack_player(game, actor) == RESULT::PLAYER_DEAD)
				return RESULT::PLAYER_DEAD;
			break;
		case TILE_TYPE::TREASURE:
			if (actor_is_player == true)
				pickUpTreasure(game);
			break;
		case TILE_TYPE::CORPSE:
			if (actor_is_player == true)
				lootCorpse(game);
			break;
		case TILE_TYPE::LEVEL_DOWN:
			if (actor_is_player == true)
				changeLevel(game, game.getCurrentLevel() + 1);
			return RESULT::LEVEL_DOWN;
		case TILE_TYPE::LEVEL_UP:
			if (actor_is_player == true)
				changeLevel(game, game.getCurrentLevel() - 1);
			return RESULT::LEVEL_UP;
		default:
			break;
		}
		return RESULT::NONE;
	}
	if (next_tile.canCollide() == false && next_tile.canInteract() == false)
	{
		actor.setCurrentPos(actor.getNewPosX(), actor.getNewPosY());
		game.levels[game.getCurrentLevel()].setMapTile(actor.getNewPosX(), actor.getNewPosY(), old_tile);
		game.levels[game.getCurrentLevel()].setMapTile(actor.getOldPosX(), actor.getOldPosY(), next_tile);
	}
	return RESULT::NONE;
}

RESULT GameEngine::attack_monster(Game & g, Actor & monster) const
{
	std::string combat_msg;

	auto dmg = abs(monster.getArmor() - (generateRandNumber(0, 9) + g.player.getAttackPower()));
	auto current_monster_hp = monster.getHealth() - dmg;

	monster.setHealth(current_monster_hp);

	combat_msg = "Dmg to monster: " + std::to_string(dmg) + "   Monster HP: " + std::to_string(monster.getHealth()) + " / " + std::to_string(monster.getMaxHealth());

	if (current_monster_hp <= 0)
	{
		g.c_log.addToLog(combat_msg);
		combat_msg = monster.getName() + " is dead";
		g.c_log.addToLog(combat_msg);
		g.player.addExp(monster.getLevel() * 25);

		if (g.player.getExp() >= g.player.exp_to_lvl_up[g.player.getLevel() + 1])
		{
			auto exp_to_move = g.player.getExp() - g.player.exp_to_lvl_up[g.player.getLevel() + 1];
			g.player.levelUp();
			g.player.addExp(exp_to_move);
		}
		g.deleteMonster(dynamic_cast<Monster &>(monster));
		return RESULT::MONSTER_DEAD;
	}

	g.c_log.addToLog(combat_msg);
	return RESULT::NONE;
}

RESULT GameEngine::attack_player(Game & g, Actor & monster) const
{
	std::string combat_msg;

	auto dmg = abs(g.player.getArmor() - (generateRandNumber(0, 9) + monster.getAttackPower()));
	auto current_player_hp = g.player.getHealth() - dmg;

	g.player.setHealth(current_player_hp);

	combat_msg = monster.getName() + " hit you : " + std::to_string(dmg) + "   Monster HP: " + std::to_string(monster.getHealth()) + " / " + std::to_string(monster.getMaxHealth());
	g.c_log.addToLog(combat_msg);

	if (current_player_hp <= 0)
	{
		g.player.setDead(true);
		g.c_log.addToLog("You died!");
		return RESULT::PLAYER_DEAD;
	}

	return RESULT::NONE;
}

void GameEngine::pickUpTreasure(Game & g) const
{
	auto gold_found = generateRandNumber(1, 50);
	std::string msg = "You found a treasure: " + std::to_string(gold_found) + " gold coins";
	g.c_log.addToLog(msg);
	g.player.addExp(10);
	g.player.addGold(gold_found);
	g.levels[g.getCurrentLevel()].setMapTile(g.player.getNewPosX(), g.player.getNewPosY(), TILE_TYPE::EMPTY);

	randomItemFound(g);
}

void GameEngine::lootCorpse(Game & g) const
{
	auto gold_found = generateRandNumber(1, 20);
	std::string msg = "You looted corpse and found " + std::to_string(gold_found) + " gold coins";
	g.player.addGold(gold_found);
	g.c_log.addToLog(msg);
	g.levels[g.getCurrentLevel()].setMapTile(g.player.getNewPosX(), g.player.getNewPosY(), TILE_TYPE::EMPTY);

	randomItemFound(g);
}

void GameEngine::randomItemFound(Game & g) const
{
	auto chance = generateRandNumber(0, 5);
	std::string msg;

	switch (chance)
	{
	case 0:
		g.player.addBackpackItem(Item("Health potion", Item_Type::POTION, 0, 0, 0, Quality::NORMAL));
		msg = "Health potion found!";
		g.c_log.addToLog(msg);
		break;
	case 1:
		std::unique_ptr<Item> rand_item(new Item(g.getCurrentLevel()));
		g.player.addInventoryItem(*rand_item);
		msg = "Item found : " + rand_item->getName() + " " + std::to_string(rand_item->getStrength()) + " / " + std::to_string(rand_item->getDexterity()) + " / " + std::to_string(rand_item->getStamina());
		g.c_log.addToLog(msg);
		break;
	}
}

RESULT GameEngine::changeLevel(Game & g, int lvl) const
{
	g.levels[g.getCurrentLevel()].setMapTile(g.player.getCurrentPosX(), g.player.getCurrentPosY(), TILE_TYPE::EMPTY);
	if (g.getCurrentLevel() < lvl)
	{
		g.setCurrentLevel(g.getCurrentLevel() + 1);
		return RESULT::LEVEL_DOWN;
	}
	else
	{
		g.setCurrentLevel(g.getCurrentLevel() - 1);
		return RESULT::LEVEL_UP;
	}
}

void GameEngine::useHealthPotion(Player & p) const
{
	if (p.getHealth() < p.getMaxHealth())
	{
		if (p.removeBackpackItem(Item_Type::POTION) == true)
		{
			auto new_health = p.getHealth() + 10;
			if (new_health > p.getMaxHealth())
				p.setHealth(p.getMaxHealth());
			else
				p.setHealth(p.getHealth() + 10);
		}
	}
}
