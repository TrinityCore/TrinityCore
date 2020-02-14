#ifndef ROBOT_STRATEGIES_SCRIPT_PRIEST_H
#define ROBOT_STRATEGIES_SCRIPT_PRIEST_H

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Priest :public Script_Base
{
public:
	Script_Priest(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer();
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff();
	virtual bool HealMe();

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);
};
#endif
