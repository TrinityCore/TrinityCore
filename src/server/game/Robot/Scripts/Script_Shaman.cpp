#include "Script_Shaman.h"

#ifndef SHAMAN_CLOSER_DISTANCE
# define SHAMAN_CLOSER_DISTANCE 20
#endif

#ifndef SHAMAN_RANGE_DISTANCE
# define SHAMAN_RANGE_DISTANCE 25
#endif

Script_Shaman::Script_Shaman(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Shaman::HealMe()
{
    Player* me = sourceAI->sourcePlayer;
    float healthPCT = me->GetHealthPercent();
    if (healthPCT < 30)
    {
        if (sourceAI->CastSpell(me, "Healing Wave"))
        {
            return true;
        }
    }

    return false;
}

bool Script_Shaman::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Shaman::Healer(Unit* pmTarget)
{
    Player* me = sourceAI->sourcePlayer;
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->isAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    sourceAI->BaseMove(pmTarget, SHAMAN_CLOSER_DISTANCE, false);

    float healthPCT = pmTarget->GetHealthPercent();
    if (healthPCT < 70)
    {
        if (sourceAI->CastSpell(pmTarget, "Healing Wave", SHAMAN_RANGE_DISTANCE))
        {
            return true;
        }
    }
    return false;
}

bool Script_Shaman::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Shaman::DPS_Common(Unit* pmTarget)
{
    Player* me = sourceAI->sourcePlayer;
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->CanAttack(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->isAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }

    sourceAI->BaseMove(pmTarget, SHAMAN_CLOSER_DISTANCE, false);
    if (sourceAI->CastSpell(pmTarget, "Lightning Bolt", SHAMAN_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Shaman::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Shaman::Attack_Common(Unit* pmTarget)
{
    Player* me = sourceAI->sourcePlayer;
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->CanAttack(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->isAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }

    sourceAI->BaseMove(pmTarget, SHAMAN_CLOSER_DISTANCE, false);
    if (sourceAI->CastSpell(pmTarget, "Lightning Bolt", SHAMAN_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Shaman::Buff(Unit* pmTarget)
{
    return false;
}
