#ifndef ROBOT_STRATEGIES_SCRIPT_PALADIN_H
#define ROBOT_STRATEGIES_SCRIPT_PALADIN_H

#ifndef AURA_THE_ART_OF_WAR_1
# define AURA_THE_ART_OF_WAR_1 53489
#endif

#ifndef AURA_THE_ART_OF_WAR_2
# define AURA_THE_ART_OF_WAR_2 59578
#endif

#ifndef PALADIN_RANGE_DISTANCE
# define PALADIN_RANGE_DISTANCE 30
#endif

#include "Script_Base.h"

enum PaladinAuraType :uint32
{
    PaladinAuraType_Concentration = 0,
    PaladinAuraType_Devotion = 1,
    PaladinAuraType_Retribution = 2,
};

enum PaladinBlessingType :uint32
{
    PaladinBlessingType_Kings = 0,
    PaladinBlessingType_Might = 1,
    PaladinBlessingType_Wisdom = 2,
};

class Script_Paladin :public Script_Base
{
public:    
    Script_Paladin(Player* pmMe);

    void Reset();
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

    bool DPS_Retribution(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);

    bool Attack_Retribution(Unit* pmTarget);
    bool Attack_Common(Unit* pmTarget);

    bool Heal_Holy(Unit* pmTarget, bool pmCure);

    uint32 auraType;
    uint32 blessingType;
};
#endif
