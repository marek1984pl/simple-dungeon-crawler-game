#include "stdafx.h"
#include "CombatLog.h"

CombatLog::CombatLog(int size) : log_size(size)
{
}

CombatLog::~CombatLog()
{
}

std::deque<std::string> CombatLog::getLog() const
{
	return combat_log;
}

void CombatLog::addToLog(std::string info)
{
	if (combat_log.size() < 8)
		combat_log.push_back(info);
	else
	{
		combat_log.pop_front();
		combat_log.push_back(info);
	}
}
