#ifndef ROBOT_STRATEGIES_SCRIPT_SHAMAN_H
#define ROBOT_STRATEGIES_SCRIPT_SHAMAN_H

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Shaman :public Script_Base
{
public:
	Script_Shaman(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer(Unit* pmTarget);
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff(Unit* pmTarget);
	virtual bool HealMe();

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);
};
#endif
