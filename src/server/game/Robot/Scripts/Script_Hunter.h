#ifndef ROBOT_STRATEGIES_SCRIPT_HUNTER_H
#define ROBOT_STRATEGIES_SCRIPT_HUNTER_H

#ifndef TAME_SPELL_ID
#define TAME_SPELL_ID 13481
#endif

#ifndef HUNTER_MIN_RANGE_DISTANCE
# define HUNTER_MIN_RANGE_DISTANCE 8.0f
#endif

#ifndef HUNTER_RANGE_DISTANCE
# define HUNTER_RANGE_DISTANCE 40.0f
#endif

#ifndef HUNTER_CHASE_DISTANCE
# define HUNTER_CHASE_DISTANCE 35.0f
#endif

#include "Script_Base.h"

class Script_Hunter :public Script_Base
{
public:    
    Script_Hunter(Player* pmMe);    
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting = true);
    bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Heal(Unit* pmTarget, bool pmCure = true);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure = true);

    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_BeastMastery(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Marksmanship(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Survival(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);

    bool Attack_Common(Unit* pmTarget);
    bool Attack_BeastMastery(Unit* pmTarget);
    bool Attack_Marksmanship(Unit* pmTarget);
    bool Attack_Survival(Unit* pmTarget);
};
#endif
