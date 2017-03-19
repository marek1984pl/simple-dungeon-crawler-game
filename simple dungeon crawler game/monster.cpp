#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(const std::string name, const int lvl, const MONSTER_TYPE t)
{
	setName(name);
	setLevel(lvl);

	setStrength(4);
	setDexterity(3);
	setStamina(5);

	Monster::setMaxHealth();
	Monster::setArmor();
	Monster::setAttackPower();
	Monster::setHealth(Monster::getMaxHealth());

	monster_type = t;

	switch (monster_type)
	{
	case MONSTER_TYPE::GOBLIN: 
		setActorTile(TILE_TYPE::MONSTER, 'G');
		break;
	case MONSTER_TYPE::WOLF:
		setActorTile(TILE_TYPE::MONSTER, 'W');
		break;
	case MONSTER_TYPE::BANDIT:
		setActorTile(TILE_TYPE::MONSTER, 'B');
		break;
	case MONSTER_TYPE::SNAKE:
		setActorTile(TILE_TYPE::MONSTER, 'S');
		break;
	case MONSTER_TYPE::TROLL: 
		setActorTile(TILE_TYPE::MONSTER, 'R');
		break;
	default:
		setActorTile(TILE_TYPE::MONSTER);
	}
}

Monster::~Monster()
{
}

void Monster::setHealth(const int h)
{
	health = h;
}

int Monster::getHealth() const
{
	return health;
}

void Monster::setMaxHealth()
{
	max_health = (getStamina() + getLevel() * 2) * 2;
}

int Monster::getMaxHealth() const
{
	return max_health;
}

void Monster::setAttackPower()
{
	attack_power = (getStrength() + getLevel()) * 2;
}

void Monster::setArmor()
{
	armor = (getDexterity() + getLevel()) * 2;
}

bool Monster::operator==(const Monster & m) const
{
	if (this->current_pos_x == m.current_pos_x && this->current_pos_y == m.current_pos_y)
		return true;
	return false;
}

MONSTER_TYPE Monster::getMonsterType() const
{
	return monster_type;
}
