#pragma once

#include <fstream>
#include <vector>
#include <iostream>
#include <string>


class Level
{
public:
	Level();
	~Level();

	void LoadLevelFromFile();
	int getLevelWidth() const;
	int getLevelHeight() const;
private:
	std::ifstream file;

	int level_width = 200;
	int level_height = 50;
};

