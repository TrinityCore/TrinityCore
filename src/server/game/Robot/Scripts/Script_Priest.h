#ifndef ROBOT_STRATEGIES_SCRIPT_PRIEST_H
#define ROBOT_STRATEGIES_SCRIPT_PRIEST_H

#ifndef PRIEST_CLOSER_DISTANCE
# define PRIEST_CLOSER_DISTANCE 25
#endif

#ifndef PRIEST_RANGE_DISTANCE
# define PRIEST_RANGE_DISTANCE 30
#endif

#include "Script_Base.h"

class Script_Priest :public Script_Base
{
public:
    Script_Priest(uint32 pmCharacterID);
    bool DPS(Unit* pmTarget);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

	bool DPS_Common(Unit* pmTarget);
	bool Attack_Common(Unit* pmTarget);
};
#endif
