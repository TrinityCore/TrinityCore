#ifndef ROBOT_STRATEGIES_SCRIPT_PALADIN_H
#define ROBOT_STRATEGIES_SCRIPT_PALADIN_H

#ifndef AURA_THE_ART_OF_WAR_1
# define AURA_THE_ART_OF_WAR_1 53489
#endif

#ifndef AURA_THE_ART_OF_WAR_2
# define AURA_THE_ART_OF_WAR_2 59578
#endif

#ifndef PALADIN_RANGE_DISTANCE
# define PALADIN_RANGE_DISTANCE 25
#endif

#include "Script_Base.h"

class Script_Paladin :public Script_Base
{
public:    
    Script_Paladin(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget, bool pmChase);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

    bool DPS_Retribution(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE);

    bool Attack_Retribution(Unit* pmTarget);
    bool Attack_Common(Unit* pmTarget);

    bool Heal_Holy(Unit* pmTarget, bool pmCure);
};
#endif
