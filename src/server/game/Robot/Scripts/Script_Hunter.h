#ifndef ROBOT_STRATEGIES_SCRIPT_HUNTER_H
#define ROBOT_STRATEGIES_SCRIPT_HUNTER_H

#ifndef TAME_SPELL_ID
#define TAME_SPELL_ID 13481
#endif

#ifndef HUNTER_CLOSER_DISTANCE
# define HUNTER_CLOSER_DISTANCE 25
#endif

#ifndef HUNTER_MIN_RANGE_DISTANCE
# define HUNTER_MIN_RANGE_DISTANCE 6
#endif

#ifndef HUNTER_RANGE_DISTANCE
# define HUNTER_RANGE_DISTANCE 30
#endif

#include "Script_Base.h"

class Script_Hunter :public Script_Base
{
public:
    Script_Hunter(uint32 pmCharacterID);
    bool DPS(Unit* pmTarget);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

    void PetAttack(Pet* pmMyPet, Unit* pmTarget);

    bool DPS_Common(Unit* pmTarget);
    bool Attack_Common(Unit* pmTarget);

    bool DPS_BeastMastery(Unit* pmTarget);
    bool Attack_BeastMastery(Unit* pmTarget);

    bool DPS_Marksmanship(Unit* pmTarget);
    bool Attack_Marksmanship(Unit* pmTarget);

    bool DPS_Survival(Unit* pmTarget);
    bool Attack_Survival(Unit* pmTarget);
};
#endif
