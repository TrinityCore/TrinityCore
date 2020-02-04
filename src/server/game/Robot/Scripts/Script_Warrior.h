#ifndef ROBOT_STRATEGIES_SCRIPT_WARRIOR_H
#define ROBOT_STRATEGIES_SCRIPT_WARRIOR_H

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Warrior :public Script_Base
{
public:
	Script_Warrior(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget);
	virtual bool Tank(Unit* pmTarget);
	virtual bool Healer(Unit* pmTarget);
	virtual bool Attack(Unit* pmTarget);
	virtual bool Buff(Unit* pmTarget);
	virtual bool HealMe();

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);

    bool DPS_Arms(Unit* pmTarget);
    bool Attack_Arms(Unit* pmTarget);

    bool DPS_Fury(Unit* pmTarget);
    bool Attack_Fury(Unit* pmTarget);

    bool Attack_Protection(Unit* pmTarget);
};
#endif
