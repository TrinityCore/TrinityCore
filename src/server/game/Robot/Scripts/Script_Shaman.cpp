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
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    float healthPCT = me->GetHealthPct();
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
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }
    sourceAI->BaseMove(pmTarget, SHAMAN_CLOSER_DISTANCE, false);

    float healthPCT = pmTarget->GetHealthPct();
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
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
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
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    if (!pmTarget)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
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
