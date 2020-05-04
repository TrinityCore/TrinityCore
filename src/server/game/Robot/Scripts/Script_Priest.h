#ifndef ROBOT_STRATEGIES_SCRIPT_PRIEST_H
#define ROBOT_STRATEGIES_SCRIPT_PRIEST_H

#ifndef PRIEST_RANGE_DISTANCE
# define PRIEST_RANGE_DISTANCE 25
#endif

#include "Script_Base.h"

class Script_Priest :public Script_Base
{
public:    
    Script_Priest(Player* pmMe);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget, bool pmChase);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool GroupHeal();
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

	bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE);
	bool Attack_Common(Unit* pmTarget);
    bool Heal_Holy(Unit* pmTarget, bool pmCure);
    bool GroupHeal_Holy();
};
#endif
