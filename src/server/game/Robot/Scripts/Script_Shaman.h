#ifndef ROBOT_STRATEGIES_SCRIPT_SHAMAN_H
#define ROBOT_STRATEGIES_SCRIPT_SHAMAN_H

#ifndef SHAMAN_CLOSER_DISTANCE
# define SHAMAN_CLOSER_DISTANCE 25
#endif

#ifndef SHAMAN_RANGE_DISTANCE
# define SHAMAN_RANGE_DISTANCE 30
#endif

#include "Script_Base.h"

class Script_Shaman :public Script_Base
{
public:
    Script_Shaman(uint32 pmCharacterID);
    bool DPS(Unit* pmTarget);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);
};
#endif
