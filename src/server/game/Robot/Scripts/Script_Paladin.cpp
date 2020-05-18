#include "Script_Paladin.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "SpellAuraEffects.h"
#include "RobotManager.h"
#include "Group.h"

Script_Paladin::Script_Paladin(Player* pmMe) :Script_Base(pmMe)
{

}

void Script_Paladin::Reset()
{
    blessingType = PaladinBlessingType::PaladinBlessingType_Kings;
    switch (characterTalentTab)
    {
    case 0:
    {
        auraType = PaladinAuraType::PaladinAuraType_Concentration;
        break;
    }
    case 1:
    {
        auraType = PaladinAuraType::PaladinAuraType_Devotion;
        break;
    }
    case 2:
    {
        auraType = PaladinAuraType::PaladinAuraType_Retribution;
        break;
    }
    default:
    {
        auraType = PaladinAuraType::PaladinAuraType_Devotion;
        break;
    }
    }
}

bool Script_Paladin::Heal(Unit* pmTarget, bool pmCure)
{
    if (!me)
    {
        return false;
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        return Heal_Holy(pmTarget, pmCure);
    }
    case 1:
    {
        return Heal_Holy(pmTarget, pmCure);
    }
    case 2:
    {
        return Heal_Holy(pmTarget, pmCure);
    }
    default:
        return Heal_Holy(pmTarget, pmCure);
    }

    return false;
}

bool Script_Paladin::Heal_Holy(Unit* pmTarget, bool pmCure)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    if (me->GetDistance(pmTarget) > PALADIN_RANGE_DISTANCE)
    {
        return false;
    }
    float healthPCT = pmTarget->GetHealthPct();
    if (healthPCT < 20.0f)
    {
        if (!HasAura(pmTarget, "Forbearance"))
        {
            if (CastSpell(pmTarget, "Lay on Hands", PALADIN_RANGE_DISTANCE))
            {
                return true;
            }
        }
    }
    if (healthPCT < 60.0f)
    {
        if (CastSpell(pmTarget, "Holy Light", PALADIN_RANGE_DISTANCE))
        {
            return true;
        }
    }
    if (healthPCT < 80.0f)
    {
        if (CastSpell(pmTarget, "Flash of Light", PALADIN_RANGE_DISTANCE))
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
                    if (pST->Dispel == DispelType::DISPEL_POISON || pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (CastSpell(pmTarget, "Purify"))
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

bool Script_Paladin::Tank(Unit* pmTarget, bool pmChase, bool pmSingle)
{
    return false;
}

bool Script_Paladin::DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!me)
    {
        return false;
    }
    if (me->GetHealthPct() < 20.0f)
    {
        UseHealingPotion();
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }
    case 1:
    {
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }
    case 2:
    {
        return DPS_Retribution(pmTarget, pmChase, pmAOE, pmTank);
    }
    default:
        return DPS_Common(pmTarget, pmChase, pmAOE, pmTank);
    }
}

bool Script_Paladin::DPS_Retribution(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (pmChase)
    {
        if (!Chase(pmTarget))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    me->Attack(pmTarget, true);
    if (pmAOE)
    {
        if (pmTank)
        {
            if (pmTank->getAttackers().size() >= 3)
            {
                uint32 inRangeCount = 0;
                for (std::set<Unit*>::const_iterator i = pmTank->getAttackers().begin(); i != pmTank->getAttackers().end(); ++i)
                {
                    if (Unit* eachAttacker = *i)
                    {
                        if (pmTank->GetDistance(eachAttacker) < AOE_TARGETS_RANGE)
                        {
                            inRangeCount++;
                            if (inRangeCount >= 3)
                            {
                                if (CastSpell(eachAttacker, "Consecration", MELEE_MAX_DISTANCE))
                                {
                                    return true;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (me->HasAura(AURA_THE_ART_OF_WAR_1) || me->HasAura(AURA_THE_ART_OF_WAR_2))
    {
        if (CastSpell(pmTarget, "Exorcism", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Wisdom", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Crusader Strike", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    return true;
}

bool Script_Paladin::DPS_Common(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (pmChase)
    {
        if (!Chase(pmTarget))
        {
            return false;
        }
    }
    else
    {
        if (!me->isInFront(pmTarget))
        {
            me->SetFacingToObject(pmTarget);
        }
    }
    me->Attack(pmTarget, true);
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Light", MELEE_MAX_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Paladin::Attack(Unit* pmTarget)
{
    if (!me)
    {
        return false;
    }
    if (me->GetHealthPct() < 20.0f)
    {
        UseHealingPotion();
    }
    if ((me->GetPower(Powers::POWER_MANA) * 100 / me->GetMaxPower(Powers::POWER_MANA)) < 30)
    {
        UseManaPotion();
    }
    switch (characterTalentTab)
    {
    case 0:
    {
        return Attack_Common(pmTarget);
    }
    case 1:
    {
        return Attack_Common(pmTarget);
    }
    case 2:
    {
        return Attack_Retribution(pmTarget);
    }
    default:
        return Attack_Common(pmTarget);
    }
}

bool Script_Paladin::Attack_Retribution(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }


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
    if (!Chase(pmTarget))
    {
        return false;
    }
    me->Attack(pmTarget, true);
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (me->HasAura(AURA_THE_ART_OF_WAR_1) || me->HasAura(AURA_THE_ART_OF_WAR_2))
    {
        if (CastSpell(pmTarget, "Exorcism", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Light", MELEE_MAX_DISTANCE))
    {
        return true;
    }
    if (CastSpell(pmTarget, "Crusader Strike", MELEE_MAX_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Paladin::Attack_Common(Unit* pmTarget)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }


    if (!me)
    {
        return false;
    }
    else if (!me->IsValidAttackTarget(pmTarget))
    {
        return false;
    }
    float targetDistance = me->GetDistance(pmTarget);
    if (targetDistance > ATTACK_RANGE_LIMIT)
    {
        return false;
    }
    if (!Chase(pmTarget))
    {
        return false;
    }
    me->Attack(pmTarget, true);
    if (pmTarget->GetHealthPct() < 20.0f)
    {
        if (CastSpell(pmTarget, "Hammer of Wrath", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (pmTarget->IsNonMeleeSpellCast(false))
    {
        if (CastSpell(pmTarget, "Hammer of Justice", MELEE_MAX_DISTANCE))
        {
            return true;
        }
    }
    if (CastSpell(pmTarget, "Judgement of Light", MELEE_MAX_DISTANCE))
    {
        return true;
    }

    return true;
}

bool Script_Paladin::Buff(Unit* pmTarget, bool pmCure)
{
    if (!pmTarget)
    {
        return false;
    }
    else if (!pmTarget->IsAlive())
    {
        return false;
    }
    if (!me)
    {
        return false;
    }
    if (me->GetGUID() == pmTarget->GetGUID())
    {
        if (FindSpellID("Seal of Command"))
        {
            if (CastSpell(me, "Seal of Command", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
        }
        else
        {
            if (CastSpell(me, "Seal of Righteousness", PALADIN_RANGE_DISTANCE, true))
            {
                return true;
            }
        }
    }
    switch (auraType)
    {
    case PaladinAuraType::PaladinAuraType_Concentration:
    {
        if (CastSpell(me, "Concentration Aura", PALADIN_RANGE_DISTANCE, true))
        {
            return true;
        }
        break;
    }
    case PaladinAuraType::PaladinAuraType_Devotion:
    {
        if (CastSpell(me, "Devotion Aura", PALADIN_RANGE_DISTANCE, true))
        {
            return true;
        }
        break;
    }
    case PaladinAuraType::PaladinAuraType_Retribution:
    {
        if (CastSpell(me, "Retribution Aura", PALADIN_RANGE_DISTANCE, true))
        {
            return true;
        }
        break;
    }
    default:
    {
        break;
    }
    }
    switch (blessingType)
    {
    case PaladinBlessingType::PaladinBlessingType_Kings:
    {
        if (!HasAura(pmTarget, "Blessing of Kings") && !HasAura(pmTarget, "Greater Blessing of Kings"))
        {
            if (FindSpellID("Greater Blessing of Kings"))
            {
                if (CastSpell(pmTarget, "Greater Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
            else
            {
                if (CastSpell(pmTarget, "Blessing of Kings", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
        }
        break;
    }
    case PaladinBlessingType::PaladinBlessingType_Might:
    {
        if (!HasAura(pmTarget, "Blessing of Might") && !HasAura(pmTarget, "Greater Blessing of Might"))
        {
            if (FindSpellID("Greater Blessing of Might"))
            {
                if (CastSpell(pmTarget, "Greater Blessing of Might", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
            else
            {
                if (CastSpell(pmTarget, "Blessing of Might", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
        }
        break;
    }
    case PaladinBlessingType::PaladinBlessingType_Wisdom:
    {
        if (!HasAura(pmTarget, "Blessing of Wisdom") && !HasAura(pmTarget, "Greater Blessing of Wisdom"))
        {
            if (FindSpellID("Greater Blessing of Wisdom"))
            {
                if (CastSpell(pmTarget, "Greater Blessing of Wisdom", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
            else
            {
                if (CastSpell(pmTarget, "Blessing of Wisdom", PALADIN_RANGE_DISTANCE, true))
                {
                    return true;
                }
            }
        }
        break;
    }
    default:
    {
        break;
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
                    if (pST->Dispel == DispelType::DISPEL_POISON || pST->Dispel == DispelType::DISPEL_DISEASE)
                    {
                        if (CastSpell(pmTarget, "Purify"))
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
