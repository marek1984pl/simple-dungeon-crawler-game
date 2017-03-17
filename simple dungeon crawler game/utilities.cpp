#include  "stdafx.h"
#include "utilities.h"

std::random_device random_device;
std::mt19937 random_generator(random_device());

int generateRandNumber(int min, int max)
{
	std::uniform_int_distribution<int> dis(min, max);
	return dis(random_generator);
	//return min + (rand() % (max - min + 1));
}

bool valueInRange(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}
