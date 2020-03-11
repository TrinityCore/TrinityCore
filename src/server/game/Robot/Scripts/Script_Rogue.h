#ifndef ROBOT_STRATEGIES_SCRIPT_ROGUE_H
#define ROBOT_STRATEGIES_SCRIPT_ROGUE_H

#include "Script_Base.h"

class Script_Rogue :public Script_Base
{
public:
    Script_Rogue()
    {

    }
    Script_Rogue(uint32 pmCharacterID);
    bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool Tank(Unit* pmTarget);
    bool Heal(Unit* pmTarget, bool pmCure);
    bool Attack(Unit* pmTarget);
    bool Buff(Unit* pmTarget, bool pmCure);

	bool DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE);
    bool DPS_Combat(Unit* pmTarget, bool pmChase, bool pmAOE);

	bool Attack_Common(Unit* pmTarget);    
    bool Attack_Combat(Unit* pmTarget);
};
#endif
