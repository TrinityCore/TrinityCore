#ifndef ROBOT_STRATEGIES_SCRIPT_DRUID_H
#define ROBOT_STRATEGIES_SCRIPT_DRUID_H

#include "Script_Base.h"

class Script_Druid :public Script_Base
{
public:
	Script_Druid(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer();
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff();
	virtual bool HealMe();

	bool DPS_Balance(Unit* pmTarget);
	bool DPS_Feral(Unit* pmTarget);
	bool Attack_Balance(Unit* pmTarget);
	bool Attack_Feral(Unit* pmTarget);
	bool Attack_Feral_Cat(Unit* pmTarget);
	bool Attack_Feral_Bear(Unit* pmTarget);
	bool Attack_Restoration(Unit* pmTarget);
};
#endif
