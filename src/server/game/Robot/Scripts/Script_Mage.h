#ifndef ROBOT_STRATEGIES_SCRIPT_MAGE_H
#define ROBOT_STRATEGIES_SCRIPT_MAGE_H

#include "Script_Base.h"
#include "Robot/RobotAI.h"

class Script_Mage :public Script_Base
{
public:
	Script_Mage(RobotAI* pmSourceAI);
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
