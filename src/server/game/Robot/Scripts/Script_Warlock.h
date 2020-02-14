#ifndef ROBOT_STRATEGIES_SCRIPT_WARLOCK_H
#define ROBOT_STRATEGIES_SCRIPT_WARLOCK_H

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Warlock :public Script_Base
{
public:
	Script_Warlock(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer();
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff();
	virtual bool HealMe();

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);

    bool DPS_Affliction(Unit* pmTarget);
    bool Attack_Affliction(Unit* pmTarget);

    bool DPS_Demonology(Unit* pmTarget);
    bool Attack_Demonology(Unit* pmTarget);

    bool DPS_Destruction(Unit* pmTarget);
    bool Attack_Destruction(Unit* pmTarget);
};
#endif
