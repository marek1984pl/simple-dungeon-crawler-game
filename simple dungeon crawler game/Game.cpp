#include "stdafx.h"
#include "Game.h"


Game::Game()
{	
	levels[0].loadLevelFromFile(148, 48);
}

Game::~Game()
{
}

void Game::createPlayer(std::string name)
{
	player.setName(name);
	player.setLevel(1);
	player.setStrength(3);
	player.setDexterity(2);
	player.setStamina(5);
	player.setExp(0);
	player.setChanged(0);

	player.setCurrentPos(1, 1);
	player.setOldPos(1, 1);
	player.setGraphicTile('@');

	player.setMaxHealth();
	player.setArmor();
	player.setAttackPower();
	player.setHealth(player.getMaxHealth());
}

void Game::createRandomMonsters(int quantity)
{
	int random_type;

	for (int i = 0; i < quantity; ++i)
	{
		random_type = rand() % 5;
		switch (random_type)
		{
		case 0:
			monsters.push_back(Monster("Goblin", 1, 'g'));
			break;
		case 1:
			monsters.push_back(Monster("Wolf", 1, 'w'));
			break;
		case 2:
			monsters.push_back(Monster("Bandit", 1, 'b'));
			break;
		case 3:
			monsters.push_back(Monster("Snake", 1, 's'));
			break;
		case 4:
			monsters.push_back(Monster("Troll", 1, 't'));
			break;
		default:
			break;
		}
	}
}

void Game::nextMove()
{
	++number_of_moves;
}

int Game::getNumberOfMoves() const
{
	return number_of_moves;
}

