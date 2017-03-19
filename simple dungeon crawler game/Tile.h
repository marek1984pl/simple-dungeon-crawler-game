#pragma once

enum class TILE_TYPE { WALL, WATER, TREE, PLAYER, MONSTER, NPC, TREASURE, EMPTY, CORPSE, LEVEL_UP, LEVEL_DOWN };

class Tile
{
public:
	Tile();
	Tile(const Tile & t);
	Tile(Tile && t) noexcept;
	Tile(const TILE_TYPE t, const char symbol = '?');
	~Tile();

	Tile & operator=(const Tile & t);
	Tile & operator=(Tile && t) noexcept;

	bool canInteract() const;
	bool canCollide() const;
	TILE_TYPE getType() const;;
	bool getOccupied() const;

	void setCollide(const bool s);
	void setInteract(const bool s);
	void setType(const TILE_TYPE t);
	void setOccupied(const bool oc);

	char getTileSymbol() const;
	void setTileSymbol(const char symbol);

private:
	TILE_TYPE tile_type;
	bool can_interact;
	bool can_collide;
	bool occupied;

	char tile_symbol;
};
