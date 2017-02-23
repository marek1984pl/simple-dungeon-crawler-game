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
	return c_log;
}

void CombatLog::addToLog(std::string info)
{
	if (c_log.size() < 8)
		c_log.push_back(info);
	else
	{
		c_log.pop_front();
		c_log.push_back(info);
	}
}
