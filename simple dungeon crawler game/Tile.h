#pragma once

enum class TILE_TYPE { WALL, WATER, TREE, PLAYER, MONSTER, NPC, TREASURE, EMPTY};

class Tile
{
public:
	Tile();
	~Tile();

	bool canInteract();
	bool canCollide();
	TILE_TYPE getType();

	void setCollide(bool s);
	void setInteract(bool s);
	void setType(TILE_TYPE t);

private:
	TILE_TYPE tile_type;
	bool can_interact;
	bool can_collide;
};

