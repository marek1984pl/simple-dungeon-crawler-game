#include "stdafx.h"
#include "Tile.h"

Tile::Tile() : tile_type(TILE_TYPE::EMPTY), can_interact(false), can_collide(false), occupied(false), tile_symbol('M')
{
}

Tile::Tile(const Tile & t)
{
	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;
	tile_symbol = t.tile_symbol;
}

Tile::Tile(Tile&& t) noexcept
{
	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;
	tile_symbol = t.tile_symbol;
}

Tile::Tile(const TILE_TYPE t, const char symbol)
{
	tile_type = t;
	switch (t)
	{
	case TILE_TYPE::WALL:
		tile_symbol = '#';
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::WATER:
		tile_symbol = '~';
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::TREE:
		tile_symbol = 'T';
		setCollide(true);
		setInteract(false);
		setOccupied(true);
		break;
	case TILE_TYPE::EMPTY:
		tile_symbol = '.';
		setCollide(false);
		setInteract(false);
		setOccupied(false);
		break;
	case TILE_TYPE::PLAYER:
		tile_symbol = '@';
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::MONSTER:
		tile_symbol = symbol;
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::NPC:
		tile_symbol = '*';
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::TREASURE:
		tile_symbol = '$';
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::CORPSE:
		tile_symbol = 'x';
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::LEVEL_DOWN:
		tile_symbol = '>';
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	case TILE_TYPE::LEVEL_UP:
		tile_symbol = '<';
		setCollide(false);
		setInteract(true);
		setOccupied(true);
		break;
	default:
		tile_symbol = '?';
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
	tile_symbol = t.tile_symbol;

	return *this;
}

Tile & Tile::operator=(Tile && t) noexcept
{
	if (this == &t)
		return *this;

	tile_type = t.tile_type;
	can_interact = t.can_interact;
	can_collide = t.can_collide;
	occupied = t.occupied;
	tile_symbol = t.tile_symbol;

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

void Tile::setCollide(const bool s)
{
	can_collide = s;
}

void Tile::setInteract(const bool s)
{
	can_interact = s;
}

void Tile::setType(const TILE_TYPE t)
{
	tile_type = t;
}

void Tile::setOccupied(const bool oc)
{
	occupied = oc;
}

char Tile::getTileSymbol() const
{
	return tile_symbol;
}

void Tile::setTileSymbol(const char symbol)
{
	tile_symbol = symbol;
}
