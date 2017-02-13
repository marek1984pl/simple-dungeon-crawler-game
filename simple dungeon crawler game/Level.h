#pragma once

#include <fstream>
#include <array>
#include <iostream>
#include <string>


class Level
{
public:
	Level();
	~Level();

	void LoadLevelFromFile(int width, int height);
	std::array<std::array<char, 148>, 48> lvl_data;

private:
	std::ifstream file;
};

