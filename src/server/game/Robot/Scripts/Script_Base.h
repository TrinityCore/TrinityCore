#ifndef ROBOT_STRATEGIES_SCRIPT_BASE_H
#define ROBOT_STRATEGIES_SCRIPT_BASE_H

#ifndef AOE_TARGETS_RANGE
# define AOE_TARGETS_RANGE 5
#endif

#include "Player.h"
#include "RobotAI.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Group.h"

class RobotAI;

class Script_Base
{
public:
	Script_Base(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget) = 0;
	virtual bool Tank(Unit* pmTarget) = 0;
	virtual bool Healer() = 0;
	virtual bool Attack(Unit* pmTarget) = 0;
	virtual bool Buff() = 0;
	virtual bool HealMe() = 0;

	RobotAI* sourceAI;
};
#endif
