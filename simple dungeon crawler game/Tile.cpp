#include "stdafx.h"
#include "Tile.h"


Tile::Tile() : can_collide(false), can_interact(false), tile_type(TILE_TYPE::EMPTY), occupied(false)
{
}

Tile::Tile(TILE_TYPE t)
{
	tile_type = t;
	switch (t)
	{
	case TILE_TYPE::WALL:
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::WATER:
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::TREE:
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::PLAYER:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::MONSTER:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::NPC:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::TREASURE:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::EMPTY:
		setCollide(false);
		setInteract(false);
		setOccupied(false);
		break;
	case TILE_TYPE::CORPSE:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::LEVEL_DOWN:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::LEVEL_UP:
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	default:
		break;
	}
}

Tile::~Tile()
{
}

bool Tile::canInteract() const
{
	return can_interact;
}

bool Tile::canCollide() const
{
	return can_collide;
}

TILE_TYPE Tile::getType() const
{
	return tile_type;
}

bool Tile::getOccupied() const
{
	return occupied;
}

void Tile::setCollide(bool s)
{
	can_collide = s;
}

void Tile::setInteract(bool s)
{
	can_interact = s;
}

void Tile::setType(TILE_TYPE t)
{
	tile_type = t;
}

void Tile::setOccupied(bool oc)
{
	occupied = oc;
}
