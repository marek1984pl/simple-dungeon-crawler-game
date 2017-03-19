#pragma once

#include <deque>

class CombatLog
{
public:
	CombatLog(const int size = 8);
	~CombatLog();

	std::deque<std::string> getLog() const;
	void addToLog(const std::string & info);

private:
	std::deque<std::string> combat_log;
	int log_size;
};
