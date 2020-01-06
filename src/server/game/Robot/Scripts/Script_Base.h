#ifndef ROBOT_STRATEGIES_SCRIPT_BASE_H
#define ROBOT_STRATEGIES_SCRIPT_BASE_H

#include "Entities/Player.h"
#include "Spells/SpellMgr.h"
#include "Spells/SpellAuras.h"

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

	RobotAI * sourceAI;
};
#endif
