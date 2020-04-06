#ifndef ROBOT_STRATEGIES_SCRIPT_HUNTER_H
#define ROBOT_STRATEGIES_SCRIPT_HUNTER_H

#ifndef TAME_SPELL_ID
#define TAME_SPELL_ID 13481
#endif

#ifndef HUNTER_MIN_RANGE_DISTANCE
# define HUNTER_MIN_RANGE_DISTANCE 8
#endif

#ifndef HUNTER_RANGE_DISTANCE
# define HUNTER_RANGE_DISTANCE 25
#endif

#include "Script_Base.h"

class Script_Hunter :public Script_Base
{
public:    
    Script_Hunter(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_BeastMastery(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Marksmanship(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Survival(Unit* pmTarget, bool pmChase, bool pmAOE);

    bool Attack_Common(Unit* pmTarget);
    bool Attack_BeastMastery(Unit* pmTarget);
    bool Attack_Marksmanship(Unit* pmTarget);
    bool Attack_Survival(Unit* pmTarget);
};
#endif
