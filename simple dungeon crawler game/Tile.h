#pragma once

enum class TILE_TYPE { WALL, WATER, TREE, PLAYER, MONSTER, NPC, TREASURE, EMPTY, CORPSE, LEVEL_UP, LEVEL_DOWN };

class Tile
{
public:
	Tile();
	Tile(TILE_TYPE t);
	~Tile();

	bool canInteract() const;
	bool canCollide() const;
	TILE_TYPE getType() const;;
	bool getOccupied() const;

	void setCollide(bool s);
	void setInteract(bool s);
	void setType(TILE_TYPE t);
	void setOccupied(bool oc);

private:
	TILE_TYPE tile_type;
	bool can_interact;
	bool can_collide;
	bool occupied;
};

