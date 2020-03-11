#ifndef ROBOT_STRATEGIES_SCRIPT_WARRIOR_H
#define ROBOT_STRATEGIES_SCRIPT_WARRIOR_H

#ifndef WARRIOR_CHARGE_DISTANCE
# define WARRIOR_CHARGE_DISTANCE 10
#endif

#ifndef WARRIOR_RANGE_DISTANCE
# define WARRIOR_RANGE_DISTANCE 25
#endif

#include "Script_Base.h"

class Script_Warrior :public Script_Base
{
public:
    Script_Warrior()
    {

    }
    Script_Warrior(uint32 pmCharacterID);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

	bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Arms(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Fury(Unit* pmTarget, bool pmChase, bool pmAOE);

	bool Attack_Common(Unit* pmTarget);    
    bool Attack_Arms(Unit* pmTarget);    
    bool Attack_Fury(Unit* pmTarget);
    bool Attack_Protection(Unit* pmTarget);
};
#endif
