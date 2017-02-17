#pragma once

#include <array>
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	~Player();

	int getGold() const;
	int getExp() const;

	void setGold(int g);
	void addGold(int g);
	void setExp(int xp);
	void addExp(int xp);

	void levelUp();

	virtual void setHealth(int h) override;
	virtual int getHealth() const override;

	virtual void setMaxHealth() override;
	virtual int getMaxHealth() const override;

	virtual void setAttackPower() override;
	virtual void setArmor() override;

	std::array<int, 100> exp_to_lvl_up;

	void setDead(bool d);
	bool isDead() const;

private:
	int gold = 0;
	int exp = 0;
	bool is_dead;
};

