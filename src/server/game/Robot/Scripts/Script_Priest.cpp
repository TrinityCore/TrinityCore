#include "Script_Priest.h"

#ifndef PRIEST_CLOSER_DISTANCE
# define PRIEST_CLOSER_DISTANCE 25
#endif

#ifndef PRIEST_RANGE_DISTANCE
# define PRIEST_RANGE_DISTANCE 30
#endif

Script_Priest::Script_Priest(RobotAI* pmSourceAI) :Script_Base(pmSourceAI)
{

}

bool Script_Priest::HealMe()
{
    Player* me = ObjectAccessor::FindPlayerByLowGUID(sourceAI->characterID);
    if (!me)
    {
        return false;
    }
    float healthPCT = me->GetHealthPct();
    if (healthPCT < 90)
    {
        if (!sourceAI->HasAura(me, "Weakened Soul"))
        {
            if (sourceAI->CastSpell(me, "Power Word: Shield"))
            {
                return true;
            }
        }
        if (sourceAI->CastSpell(me, "Renew", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }
    }
    if (healthPCT < 70)
    {
        if (sourceAI->CastSpell(me, "Heal"))
        {
            return true;
        }
    }

    return false;
}

bool Script_Priest::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Priest::Healer(Unit* pmTarget)
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
    sourceAI->BaseMove(pmTarget, PRIEST_CLOSER_DISTANCE, false);
    float healthPCT = pmTarget->GetHealthPct();
    if (healthPCT < 90)
    {
        if (!sourceAI->HasAura(pmTarget, "Weakened Soul"))
        {
            if (sourceAI->CastSpell(pmTarget, "Power Word: Shield", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
        if (sourceAI->CastSpell(pmTarget, "Renew", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }
    }
    if (healthPCT < 50)
    {
        if (sourceAI->CastSpell(pmTarget, "Heal", PRIEST_RANGE_DISTANCE))
        {
            return true;
        }
    }
    return false;
}

bool Script_Priest::DPS(Unit* pmTarget)
{
    return DPS_Common(pmTarget);
}

bool Script_Priest::DPS_Common(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, PRIEST_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Attack(Unit* pmTarget)
{
    return Attack_Common(pmTarget);
}

bool Script_Priest::Attack_Common(Unit* pmTarget)
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

    sourceAI->BaseMove(pmTarget, PRIEST_CLOSER_DISTANCE, false);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (sourceAI->CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (sourceAI->CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (sourceAI->CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Buff(Unit* pmTarget)
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
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > 200)
    {
        return false;
    }

    if (sourceAI->CastSpell(pmTarget, "Power Word: Fortitude", PRIEST_RANGE_DISTANCE, true))
    {
        return true;
    }

    return false;
}
