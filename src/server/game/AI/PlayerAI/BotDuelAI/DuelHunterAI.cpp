
#include "BotDuelClassAI.h"
#include "Pet.h"

void DuelHunterAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelHunterAI::ResetBotAI()
{
    BotDuelAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);
   /* if (Pet* pet = me->GetPet())
        pet->SettingAllSpellAutocast(true);*/
    if (HunterShot_QMLShot == 0 && m_BotTalentType == 1 && me->getLevel() == 80)
    {
        me->LearnSpell(53209, false);
        HunterShot_QMLShot = BotUtility::FindMaxRankSpellByExist(me, 53209);
    }
}

uint32 DuelHunterAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool DuelHunterAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void DuelHunterAI::ProcessFlee()
{
    FleeMovement();

    Unit* pDuelPlayer = GetDuelEnemy();
    if (!pDuelPlayer)
        return;
    Pet* pPet = me->GetPet();
    if (pDuelPlayer->HasAura(HunterDebug_Sleep))
    {
        if (pPet)
        {
            pPet->AttackStop();
            pPet->SetTarget(ObjectGuid::Empty);
        }
        me->AttackStop();
        return;
    }
    if (pPet)
    {
        Unit* pPetTarget = pPet->GetVictim();
        if (pPetTarget != pDuelPlayer)
            PetAction(pPet, pDuelPlayer);
    }

    if (TryCastSpell(HunterTrap_Ice, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (HunterIDLE_DragonAura)
    {
        if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (!me->HasAura(HunterIDLE_DodgeAura) && TryCastSpell(HunterIDLE_DodgeAura, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    bool hasRoot = HasRootMechanic();
    if (me->GetDistance(pDuelPlayer->GetPosition()) <= 8 && hasRoot)
    {
        if (TryCastSpell(HunterMelee_NoDamage, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 2 && HunterMelee_BackRoot)
    {
        if (TryCastSpell(HunterMelee_BackRoot, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 2 && HunterDebug_Sleep && TargetIsMelee(pDuelPlayer->ToPlayer()) && me->GetDistance(pDuelPlayer->GetPosition()) < 12)
    {
        if (!pDuelPlayer->HasAura(HunterDebug_Sleep) && TryCastSpell(HunterDebug_Sleep, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pDuelPlayer->HasAura(HunterMelee_DecSpeed) && !pDuelPlayer->HasAura(HunterShot_Shock) && !pDuelPlayer->HasAura(HunterDebug_Sleep))
    {
        if (TryCastSpell(HunterMelee_DecSpeed, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_Shock, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (hasRoot && HunterAssist_ClearRoot && TryCastSpell(HunterAssist_ClearRoot, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0)
    {
        if (hasRoot && HunterAssist_PetRage && TryCastSpell(HunterAssist_PetRage, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterAssist_PetStun, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(HunterMelee_NextAtt) && TryCastSpell(HunterMelee_NextAtt, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterMelee_MeleeAtt, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pDuelPlayer->HasAura(HunterAssist_Stamp) && TryCastSpell(HunterAssist_Stamp, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (HunterShot_KillShot && pDuelPlayer->GetHealthPct() < 20 && TryCastSpell(HunterShot_KillShot, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 20)
    {
        if (!pDuelPlayer->HasAura(HunterDebug_Mana) && !pDuelPlayer->HasAura(HunterDebug_Damage) && TryCastSpell(HunterDebug_Mana, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (!pDuelPlayer->HasAura(HunterDebug_Mana) && !pDuelPlayer->HasAura(HunterDebug_Damage) && TryCastSpell(HunterDebug_Damage, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterShot_MgcShot, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pDuelPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelHunterAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (m_BotTalentType == 2 && HunterMelee_BackRoot)
    {
        if (TryCastSpell(HunterMelee_BackRoot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pTarget->HasAura(HunterMelee_DecSpeed) && TryCastSpell(HunterMelee_DecSpeed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    bool hasRoot = HasRootMechanic();
    if (hasRoot && HunterAssist_ClearRoot && TryCastSpell(HunterAssist_ClearRoot, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0)
    {
        if (hasRoot && HunterAssist_PetRage && TryCastSpell(HunterAssist_PetRage, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterAssist_PetStun, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(HunterMelee_NextAtt) && TryCastSpell(HunterMelee_NextAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterMelee_MeleeAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelHunterAI::ProcessRangeSpell(Unit* pTarget)
{
    uint32 manaPct = GetManaPowerPer();
    Pet* pPet = me->GetPet();
    if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    PetAction(pPet, pTarget);
    if (pPet && pPet->IsAlive() && manaPct > 15)
    {
        if (pPet->GetHealthPct() < 75 && !pPet->HasAura(HunterAssist_HealPet) && TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (HunterIDLE_DragonAura)
    {
        if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (manaPct < 20)
    {
        if (!pTarget->HasAura(HunterDebug_Mana) && !pTarget->HasAura(HunterDebug_Damage) && TryCastSpell(HunterDebug_Mana, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (!pTarget->HasAura(HunterDebug_Mana) && !pTarget->HasAura(HunterDebug_Damage) && TryCastSpell(HunterDebug_Damage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (pTarget->HasUnitState(UNIT_STATE_CASTING))
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (HunterShot_KillShot && pTarget->GetHealthPct() < 20 && TryCastSpell(HunterShot_KillShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(HunterAssist_Stamp) && TryCastSpell(HunterAssist_Stamp, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        if (pTarget->HasAura(HunterShot_Shock) && TryCastSpell(HunterShot_Shock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterTrap_Shot && TryCastSpell(HunterTrap_Shot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && HunterTrap_Shot && TryCastSpell(HunterTrap_Shot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterShot_Cast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void DuelHunterAI::PetAction(Pet* pPet, Unit* pTarget)
{
    Position pos;
    if (!pPet)
        return;
    if (pPet->GetVictim() == pTarget)
        return;
    WorldSession* pSession = me->GetSession();
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(),pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

bool DuelHunterAI::HasRootMechanic()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}

bool DuelHunterAI::TargetIsSuppress(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}
