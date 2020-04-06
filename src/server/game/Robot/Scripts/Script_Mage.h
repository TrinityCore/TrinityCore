#ifndef ROBOT_STRATEGIES_SCRIPT_MAGE_H
#define ROBOT_STRATEGIES_SCRIPT_MAGE_H

#ifndef MAGE_RANGE_DISTANCE
# define MAGE_RANGE_DISTANCE 25
#endif

#include "Script_Base.h"

class Script_Mage :public Script_Base
{
public:    
    Script_Mage(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Frost(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Fire(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Arcane(Unit* pmTarget, bool pmChase, bool pmAOE);

    bool Attack_Common(Unit* pmTarget);
    bool Attack_Frost(Unit* pmTarget);
    bool Attack_Fire(Unit* pmTarget);
    bool Attack_Arcane(Unit* pmTarget);
};
#endif
