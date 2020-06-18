#ifndef ROBOT_STRATEGIES_SCRIPT_SHAMAN_H
#define ROBOT_STRATEGIES_SCRIPT_SHAMAN_H

#ifndef SHAMAN_RANGE_DISTANCE
# define SHAMAN_RANGE_DISTANCE 30
#endif

#include "Script_Base.h"

class Script_Shaman :public Script_Base
{
public:
    Script_Shaman(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting = true);
    bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Heal(Unit* pmTarget, bool pmCure = true);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure = true);

    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool Attack_Common(Unit* pmTarget);
};
#endif
