#pragma once

#include "Actor.h"

enum class MONSTER_TYPE { GOBLIN, WOLF, BANDIT, SNAKE, TROLL };

class Monster : public Actor
{
public:
	Monster();
	Monster(const std::string name, const int lvl, const MONSTER_TYPE t);
	~Monster();

	void setHealth(const int h) override;
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
