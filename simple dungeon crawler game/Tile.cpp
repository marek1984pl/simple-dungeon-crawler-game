#include "stdafx.h"
#include "Tile.h"


Tile::Tile() : can_collide(false), can_interact(false), tile_type(TILE_TYPE::EMPTY)
{
}


Tile::~Tile()
{
}

bool Tile::canInteract()
{
	return can_interact;
}

bool Tile::canCollide()
{
	return can_collide;
}

TILE_TYPE Tile::getType()
{
	return tile_type;
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
