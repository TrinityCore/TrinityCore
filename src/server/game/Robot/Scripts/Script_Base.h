#ifndef ROBOT_STRATEGIES_SCRIPT_BASE_H
#define ROBOT_STRATEGIES_SCRIPT_BASE_H

#include "Player.h"
#include "RobotAI.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

class RobotAI;

class Script_Base
{
public:
	Script_Base(RobotAI* pmSourceAI);
	virtual bool DPS(Unit* pmTarget) = 0;
	virtual bool Tank(Unit* pmTarget) = 0;
	virtual bool Healer(Unit* pmTarget) = 0;
	virtual bool Attack(Unit* pmTarget) = 0;
	virtual bool Buff(Unit* pmTarget) = 0;
	virtual bool HealMe() = 0;

	RobotAI* sourceAI;
};
#endif
