#ifndef ROBOT_STRATEGIES_SCRIPT_HUNTER_H
#define ROBOT_STRATEGIES_SCRIPT_HUNTER_H

#ifndef TAME_SPELL_ID
#define TAME_SPELL_ID 13481
#endif

#include "Script_Base.h"
#include "RobotAI.h"

class Script_Hunter :public Script_Base
{
public:
    Script_Hunter(RobotAI* pmSourceAI);
    virtual bool DPS(Unit* pmTarget);
    virtual bool Tank(Unit* pmTarget);
    virtual bool Healer();
    virtual bool Attack(Unit* pmTarget);
    virtual bool Buff();
    virtual bool HealMe();

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
