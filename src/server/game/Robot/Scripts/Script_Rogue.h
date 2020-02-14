#ifndef ROBOT_STRATEGIES_SCRIPT_ROGUE_H
#define ROBOT_STRATEGIES_SCRIPT_ROGUE_H

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Rogue :public Script_Base
{
public:
	Script_Rogue(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer();
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff();
	virtual bool HealMe();

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);

    bool DPS_Combat(Unit* pmTarget);
    bool Attack_Combat(Unit* pmTarget);
};
#endif
