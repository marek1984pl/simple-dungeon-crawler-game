#include "stdafx.h"
#include "Tile.h"


Tile::Tile() : can_collide(false), can_interact(false), tile_type(TILE_TYPE::EMPTY), occupied(false)
{
}

Tile::Tile(const Tile & t)
{
	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;
}

Tile::Tile(Tile && t)
{
	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;
}

Tile::Tile(TILE_TYPE t)
{
	tile_type = t;
	switch (t)
	{
	case TILE_TYPE::WALL:
	case TILE_TYPE::WATER:
	case TILE_TYPE::TREE:
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::EMPTY:
		setCollide(false);
		setInteract(false);
		setOccupied(false);
		break;
	case TILE_TYPE::PLAYER:
	case TILE_TYPE::MONSTER:
	case TILE_TYPE::NPC:
	case TILE_TYPE::TREASURE:
	case TILE_TYPE::CORPSE:
	case TILE_TYPE::LEVEL_DOWN:
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

Tile & Tile::operator=(const Tile & t)
{
	if (this == &t)
		return *this;

	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;

	return *this;
}

Tile & Tile::operator=(Tile && t)
{
	if (this == &t)
		return *this;

	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;

	return *this;
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
