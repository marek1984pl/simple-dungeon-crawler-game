#pragma once
#include "Actor.h"

enum class MONSTER_TYPE { GOBLIN, WOLF, BANDIT, SNAKE, TROLL };

class Monster : public Actor
{
public:
	Monster();
	Monster(std::string name, int lvl, MONSTER_TYPE t);
	~Monster();

	virtual void setHealth(int h) override;
	virtual int getHealth() const override;

	virtual void setMaxHealth() override;
	virtual int getMaxHealth() const override;

	virtual void setAttackPower() override;
	virtual void setArmor() override;

	bool operator==(const Monster & m) const;

	MONSTER_TYPE getMonsterType() const;

private:
	MONSTER_TYPE monster_type;
};

