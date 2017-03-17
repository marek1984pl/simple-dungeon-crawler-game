#pragma once

#include "Actor.h"

enum class MONSTER_TYPE { GOBLIN, WOLF, BANDIT, SNAKE, TROLL };

class Monster : public Actor
{
public:
	Monster();
	Monster(std::string name, int lvl, MONSTER_TYPE t);
	~Monster();

	void setHealth(int h) override;
	int getHealth() const override;

	void setMaxHealth() override;
	int getMaxHealth() const override;

	void setAttackPower() override;
	void setArmor() override;

	bool operator==(const Monster & m) const;

	MONSTER_TYPE getMonsterType() const;

private:
	MONSTER_TYPE monster_type;
};
