#pragma once

#include <deque>

class CombatLog
{
public:
	CombatLog(int size = 8);
	~CombatLog();

	std::deque<std::string> getLog() const;
	void addToLog(std::string info);

private:
	std::deque<std::string> combat_log;
	int log_size;
};
