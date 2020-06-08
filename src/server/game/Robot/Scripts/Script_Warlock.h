#ifndef ROBOT_STRATEGIES_SCRIPT_WARLOCK_H
#define ROBOT_STRATEGIES_SCRIPT_WARLOCK_H

#ifndef WARLOCK_RANGE_DISTANCE
# define WARLOCK_RANGE_DISTANCE 30
#endif

#include "Script_Base.h"

class Script_Warlock :public Script_Base
{
public:    
    Script_Warlock(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptCasting = true);
    bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

	bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Affliction(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Demonology(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);
    bool DPS_Destruction(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank);

	bool Attack_Common(Unit* pmTarget);    
    bool Attack_Affliction(Unit* pmTarget);    
    bool Attack_Demonology(Unit* pmTarget);    
    bool Attack_Destruction(Unit* pmTarget);
};
#endif
