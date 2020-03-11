#include "Script_Priest.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "SpellAuraEffects.h"
#include "RobotManager.h"
#include "Group.h"

Script_Priest::Script_Priest(uint32 pmCharacterID) :Script_Base()
{
    character = pmCharacterID;
}

bool Script_Priest::Tank(Unit* pmTarget)
{
    return false;
}

bool Script_Priest::Heal(Unit* pmTarget, bool pmCure)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    Chase(pmTarget, PRIEST_RANGE_DISTANCE);
    float healthPCT = pmTarget->GetHealthPct();
    if (healthPCT < 30)
    {
        if (CastSpell(pmTarget, "Desperate Prayer", PRIEST_RANGE_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 60)
    {
        if (CastSpell(pmTarget, "Greater Heal", PRIEST_RANGE_DISTANCE))
        {
            return true;
        }
        if (CastSpell(pmTarget, "Heal", PRIEST_RANGE_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 80)
    {
        Unit* tankTarget = pmTarget->GetVictim();
        if (tankTarget)
        {
            // when facing boss
            if (tankTarget->GetMaxHealth() / me->GetMaxHealth() > 3)
            {
                if (CastSpell(pmTarget, "Lightwell", PRIEST_RANGE_DISTANCE))
                {
                    me->Yell("LIGHTWELL !", Language::LANG_UNIVERSAL);
                    return true;
                }
            }
        }
        if (CastSpell(pmTarget, "Flash Heal", PRIEST_RANGE_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 90)
    {
        if (!HasAura(pmTarget, "Weakened Soul"))
        {
            if (CastSpell(pmTarget, "Power Word: Shield", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
        if (CastSpell(pmTarget, "Renew", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }
    }

    if (pmCure)
    {
        for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
        {
            std::list<AuraEffect*> auraList = pmTarget->GetAuraEffectsByType((AuraType)type);
            for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
            {
                const SpellInfo* pST = (*auraIT)->GetSpellInfo();
                if (!pST->IsPositive())
                {
                    if (pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (CastSpell(pmTarget, "Cure Disease"))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool Script_Priest::DPS(Unit* pmTarget, bool pmChase, bool pmAOE)
{
    return DPS_Common(pmTarget, pmChase, pmAOE);
}

bool Script_Priest::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (pmChase)
    {
        Chase(pmTarget, PRIEST_CLOSER_DISTANCE);
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
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
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    Chase(pmTarget, PRIEST_CLOSER_DISTANCE);
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 10)
    {
        if (!me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (CastSpell(pmTarget, "Shoot", PRIEST_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (CastSpell(pmTarget, "Shadow Word: Pain", PRIEST_RANGE_DISTANCE, true, true))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Smite", PRIEST_RANGE_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Priest::Buff(Unit* pmTarget, bool pmCure)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
    Player* me = ObjectAccessor::FindConnectedPlayer(guid);
    if (!me)
    {
        return false;
    }
    if (me->GetDistance(pmTarget) < PRIEST_RANGE_DISTANCE)
    {
        if (CastSpell(pmTarget, "Power Word: Fortitude", PRIEST_RANGE_DISTANCE, true))
        {
            return true;
        }

        if (pmCure)
        {
            for (uint32 type = SPELL_AURA_NONE; type < TOTAL_AURAS; ++type)
            {
                std::list<AuraEffect*> auraList = pmTarget->GetAuraEffectsByType((AuraType)type);
                for (auto auraIT = auraList.begin(), end = auraList.end(); auraIT != end; ++auraIT)
                {
                    const SpellInfo* pST = (*auraIT)->GetSpellInfo();
                    if (!pST->IsPositive())
                    {
                        if (pST->Dispel == DispelType::DISPEL_DISEASE)
                        {
                            if (CastSpell(pmTarget, "Cure Disease"))
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}
