#pragma once

#include <fstream>
#include <array>


class Level
{
public:
	Level();
	~Level();

	void loadLevelFromFile(int width, int height);
	std::array<std::array<char, 148>, 48> lvl_data;

private:
	std::ifstream file;
};

