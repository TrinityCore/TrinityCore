
#include "BotDuelClassAI.h"
#include "Totem.h"

void DuelShamanAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void DuelShamanAI::ResetBotAI()
{
    UpdateTalentType();
    BotDuelAI::ResetBotAI();
    m_CurrentPattern = ShamanTotemPattern::ShamanTP_None;
    InitializeSpells(me);
    m_SummonFireTotemTick = 0;
}

uint32 DuelShamanAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void DuelShamanAI::EachTick()
{
    BotDuelAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool DuelShamanAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (m_BotTalentType == 1)
        return m_NeedFlee.TargetHasFleeAura();
    Unit* pTarget = me->GetSelectedUnit();
    if (m_NeedFlee.TargetHasFleeAura(pTarget))
    {
        return true;
    }
    if (!pTarget)
        return false;
    if (!IsFleeTargetByRangeBot(pTarget))
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void DuelShamanAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    else
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Flee))
        return;

    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(ShamanAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessShield())
        return;
    if (TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessTotem())
        return;
    if (ShamanAssist_Frog && !TargetIsSuppress(pTarget) && BotUtility::SpellHasReady(me, ShamanAssist_Frog))
    {
        me->StopMoving();
        if (TryCastSpell(ShamanAssist_Frog, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() < 60 && m_BotTalentType != 1)
        ProcessHealthSpell(me);
    ProcessDispel();
}

void DuelShamanAI::ProcessHealthSpell(Unit* pTarget)
{
    if (pTarget != me)
        return;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Heal))
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;
    if (ProcessShield())
        return;
    if (ProcessTotem())
        return;
    if (m_BotTalentType == 2 && ShamanAssist_HealCrit)
    {
        if (TryCastSpell(ShamanAssist_HealCrit, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 2 && ShamanHealth_Torrent && pTarget->GetHealthPct() < 75)
    {
        if (TryCastSpell(ShamanHealth_Torrent, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    float targetHealPct = pTarget->GetHealthPct();
    if (targetHealPct < 20)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(ShamanHealth_Fast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (targetHealPct >= 20 && targetHealPct < 70)
    {
        if (TryCastSpell(ShamanAssist_MomentHeal, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(ShamanHealth_Bast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (targetHealPct >= 70 && targetHealPct < 85)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(ShamanHealth_Fast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

void DuelShamanAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Melee))
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(ShamanAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessShield())
        return;
    if (ProcessTotem())
        return;
    if (TryCastSpell(ShamanAssist_FireNova, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ShamanAtt_StormStrike && TryCastSpell(ShamanAtt_StormStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ShamanAtt_FireStrike && TryCastSpell(ShamanAtt_FireStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TargetIsMagic(pTarget->ToPlayer()))
    {
        if (TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(ShamanCast_EarthThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (me->GetHealthPct() < 60 && m_BotTalentType != 1)
        ProcessHealthSpell(me);
    if (TryCastSpell(ShamanAssist_Cleansing, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void DuelShamanAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Range))
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(ShamanAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessShield())
        return;
    if (ProcessTotem())
        return;
    if (me->GetDistance(pTarget) < BOTAI_TOTEMRANGE && TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && ShamanAssist_MomentCast && TryCastSpell(ShamanAssist_MomentCast, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ShamanCast_FireStrike && TryCastSpell(ShamanCast_FireStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() < 60 && m_BotTalentType != 1)
        ProcessHealthSpell(me);
    if (TryCastSpell(ShamanCast_LightningArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool DuelShamanAI::ProcessDispel()
{
    if (TryCastSpell(ShamanDispel_Refine, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}

bool DuelShamanAI::ProcessShield()
{
    bool hasEarth = me->HasAura(ShamanShield_Earth);
    if (!hasEarth && TryCastSpell(ShamanShield_Earth, me) == SpellCastResult::SPELL_CAST_OK)
    {
        hasEarth = true;
        return true;
    }
    if (hasEarth)
        return false;
    if (GetManaPowerPer() < 15)
    {
        if (!me->HasAura(ShamanShield_Lightning) && !me->HasAura(ShamanShield_Water) && TryCastSpell(ShamanShield_Water, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (!me->HasAura(ShamanShield_Lightning) && !me->HasAura(ShamanShield_Water) && TryCastSpell(ShamanShield_Lightning, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool DuelShamanAI::ProcessTotem()
{
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_DecMove, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (ShamanTotem_AbsorbBuff && !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_AbsorbBuff, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (GetManaPowerPer() < 20)
    {
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_WATER, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_BMana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_Mana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    if (ShamanTotem_SummonFire && TryCastSpell(ShamanTotem_SummonFire, me) == SpellCastResult::SPELL_CAST_OK)
    {
        m_SummonFireTotemTick = getMSTime();
        return true;
    }
    if (m_SummonFireTotemTick == 0 || m_SummonFireTotemTick + 90000 < getMSTime())
    {
        bool existFireTotem = ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE, BOTAI_TOTEMRANGE);
        if (ShamanTotem_Attack && !existFireTotem)
        {
            if (TryCastSpell(ShamanTotem_Attack, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        if (existFireTotem && ShamanAssist_FireNova && TryCastSpell(ShamanAssist_FireNova, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool DuelShamanAI::ExistTotemByType(PlayerTotemType totemType, float range)
{
    std::list<Creature*> results;
    Trinity::AllWorldObjectsInRange checker(me, range);
    Trinity::CreatureListSearcher<Trinity::AllWorldObjectsInRange> searcher(me, results, checker);
    //me->VisitNearbyGridObject(range, searcher);

    uint32 slotType = SUMMON_SLOT_TOTEM;
    switch (totemType)
    {
    case PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE:
        slotType = SUMMON_SLOT_TOTEM;
        break;
    case PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH:
        slotType = SUMMON_SLOT_TOTEM + 1;
        break;
    case PlayerTotemType::SUMMON_TYPE_TOTEM_WATER:
        slotType = SUMMON_SLOT_TOTEM + 2;
        break;
    case PlayerTotemType::SUMMON_TYPE_TOTEM_AIR:
        slotType = SUMMON_SLOT_TOTEM + 3;
        break;
    }
    for (Creature* pObject : results)
    {
        Totem* pTotem = dynamic_cast<Totem*>(pObject);
        if (!pTotem || pTotem->GetOwner() != me)
            continue;
        if (pTotem->m_Properties->Slot != int32(slotType))
            continue;
        return true;
    }
    return false;
}

bool DuelShamanAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool DuelShamanAI::IsRangeBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool DuelShamanAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool DuelShamanAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool DuelShamanAI::TargetIsSuppress(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISTRACT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH)/* ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD)*/)
        return true;
    //if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) && !pTarget->HasAura(ShamanAssist_Frog))
    //	return true;
    return false;
}

bool DuelShamanAI::TryRecycleTotem(ShamanTotemPattern pattern)
{
    if (pattern == ShamanTotemPattern::ShamanTP_None || m_CurrentPattern == pattern)
        return false;
    m_CurrentPattern = pattern;
    //if (CanCastSpell(ShamanTotem_Recycle, me) == SpellCastResult::SPELL_CAST_OK)
    //	return true;
    return false;
}
