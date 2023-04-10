
#include "BotDemonHunterAI.h"
#include "BotBGAIMovement.h"
#include "Group.h"

void BotDemonHunterAI::InitializeSpells()
{
    HAVOC_demons_bite = FindMaxRankSpellByExist(162243);
    HAVOC_chaos_strike = FindMaxRankSpellByExist(162794);
    HAVOC_fel_rush = FindMaxRankSpellByExist(195072);
    //AOE
    HAVOC_eye_beam = FindMaxRankSpellByExist(198013);
    HAVOC_blade_dance = FindMaxRankSpellByExist(188499);
    HAVOC_throw_glaive = FindMaxRankSpellByExist(185123);
    HAVOC_chaos_nova = FindMaxRankSpellByExist(179057);
    //CONTROL
    HAVOC_disrupt = FindMaxRankSpellByExist(183752);
    HAVOC_imprison = FindMaxRankSpellByExist(217832);
    HAVOC_vengeful_retreat = FindMaxRankSpellByExist(198793);
    HAVOC_fel_eruption = FindMaxRankSpellByExist(211881);// talent
    //
    HAVOC_darkness = FindMaxRankSpellByExist(196718);
    HAVOC_blur = FindMaxRankSpellByExist(198589);
    HAVOC_metamorphosis = FindMaxRankSpellByExist(191427);

    //SINGEL
    Vengeance_shear = FindMaxRankSpellByExist(203782);
    //AOE
    Vengeance_immolation_aura = FindMaxRankSpellByExist(178740);
    Vengeance_infernal_strike = FindMaxRankSpellByExist(189110);
    Vengeance_throw_glaive = FindMaxRankSpellByExist(204157);
    Vengeance_soul_cleave = FindMaxRankSpellByExist(228477);
    Vengeance_sigil_of_flame = FindMaxRankSpellByExist(204596);
    //CONTROL
    Vengeance_disrupt = FindMaxRankSpellByExist(183752);
    Vengeance_sigil_of_silence = FindMaxRankSpellByExist(202137);
    Vengeance_sigil_of_misery = FindMaxRankSpellByExist(207684);

    Vengeance_demon_spikes = FindMaxRankSpellByExist(203720);
    Vengeance_fiery_brand = FindMaxRankSpellByExist(204021);
    Vengeance_soul_227225 = FindMaxRankSpellByExist(227225); //talent
    Vengeance_metamorphosis = FindMaxRankSpellByExist(187827);

    Vengeance_torment = FindMaxRankSpellByExist(185245);

    DemonHunterIDLE_MountAura = FindMaxRankSpellByExist(32223);
}

void BotDemonHunterAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotDemonHunterAI::ResetBotAI()
{
    UpdateTalentType();
    BotBGAI::ResetBotAI();
    InitializeSpells();
}

uint32 BotDemonHunterAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void BotDemonHunterAI::ProcessReady()
{
    ProcessNormalSpell();
}

bool BotDemonHunterAI::ProcessAura()
{
    if (me->IsMounted() && !me->IsInCombat())
    {
        if (DemonHunterIDLE_MountAura && !me->HasAura(DemonHunterIDLE_MountAura) && TryCastSpell(DemonHunterIDLE_MountAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool BotDemonHunterAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (!me->HasAura(m_UseMountID))
        return false;

    if (ProcessAura())
        return true;
    if (me->HasAura(m_UseMountID))
    {
        return false;
    }
    NearUnitVec needHealthPlayers = SearchNeedHealth(BOTAI_RANGESPELL_DISTANCE);
    if (needHealthPlayers.empty())
        return TryUpMount();

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return false;
}

void BotDemonHunterAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        if (!IsInvincible(me) && me->GetHealthPct() < 25)
        {
            me->StopMoving();
        }
        else
            FleeMovement();
    }
    else
        return;
    if (ProcessAura())
        return;
}

void BotDemonHunterAI::ProcessHealthSpell(Unit* /*pTarget*/)
{
}

void BotDemonHunterAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    //if (ProcessDHPull(pTarget))
    //    return;
    if (Vengeance_throw_glaive)
    {
        if (!pTarget->HasAura(Vengeance_throw_glaive) && TryCastSpell(Vengeance_throw_glaive, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    ProcessMeleeSpell(pTarget);
}

bool BotDemonHunterAI::ProcessControl(Unit* pTarget)
{
    if (!pTarget)
        pTarget = me->GetSelectedUnit();

    if (m_BotTalentType == DemonHunterTalent_Havoc)
    {
        if (HAVOC_disrupt && BotUtility::SpellHasReady(me, HAVOC_disrupt))
            if (TryCastSpell(HAVOC_disrupt, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        if (HAVOC_imprison && BotUtility::SpellHasReady(me, HAVOC_imprison))
            if (TryCastSpell(HAVOC_imprison, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        if (HAVOC_vengeful_retreat && BotUtility::SpellHasReady(me, HAVOC_vengeful_retreat))
            if (TryCastSpell(HAVOC_vengeful_retreat, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        if (HAVOC_fel_eruption && BotUtility::SpellHasReady(me, HAVOC_fel_eruption))
            if (TryCastSpell(HAVOC_fel_eruption, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
    }

    if (m_BotTalentType == DemonHunterTalent_Vengeance)
    {
        if (Vengeance_disrupt && BotUtility::SpellHasReady(me, Vengeance_disrupt))
            if (TryCastSpell(Vengeance_disrupt, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        if (Vengeance_sigil_of_silence && BotUtility::SpellHasReady(me, Vengeance_sigil_of_silence))
            if (TryCastSpell(Vengeance_sigil_of_silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        if (Vengeance_sigil_of_misery && BotUtility::SpellHasReady(me, Vengeance_sigil_of_misery))
            if (TryCastSpell(Vengeance_sigil_of_misery, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
    }

    return false;
}

void BotDemonHunterAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (!pTarget)
        pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    if (ProcessAura())
        return;


    if (ProcessControl(pTarget))
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessHavocMeleeSpell(pTarget);
        break;
    case 1:
        ProcessVengeanceMeleeSpell(pTarget);
        break;
    }
}

void BotDemonHunterAI::ProcessVengeanceMeleeSpell(Unit* pTarget)
{
    if (me->GetHealthPct() < 85)
    {
        if (Vengeance_demon_spikes && TryCastSpell(Vengeance_demon_spikes, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (Vengeance_fiery_brand && TryCastSpell(Vengeance_fiery_brand, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (Vengeance_soul_227225 && TryCastSpell(Vengeance_soul_227225, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (me->GetHealthPct() < 50 && Vengeance_metamorphosis && BotUtility::SpellHasReady(me, Vengeance_metamorphosis) && TryCastSpell(Vengeance_metamorphosis, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //TryCastSpell(GetArtifactSpell(), pTarget);
    if (Vengeance_immolation_aura && BotUtility::SpellHasReady(me, Vengeance_immolation_aura))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(Vengeance_immolation_aura, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (Vengeance_infernal_strike && BotUtility::SpellHasReady(me, Vengeance_infernal_strike))
    {
        NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
        if (targetRangeEnemys.size() > 2)
        {
            if (TryCastSpell(Vengeance_infernal_strike, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (Vengeance_throw_glaive && BotUtility::SpellHasReady(me, Vengeance_throw_glaive))
    {
        NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
        if (targetRangeEnemys.size() > 2)
        {
            if (TryCastSpell(Vengeance_throw_glaive, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (Vengeance_soul_cleave && BotUtility::SpellHasReady(me, Vengeance_soul_cleave))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(Vengeance_soul_cleave, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (Vengeance_sigil_of_flame && BotUtility::SpellHasReady(me, Vengeance_sigil_of_flame))
    {
        NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
        if (targetRangeEnemys.size() > 2)
        {
            if (TryCastSpell(Vengeance_sigil_of_flame, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }

    if (Vengeance_shear && TryCastSpell(Vengeance_shear, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotDemonHunterAI::ProcessHavocMeleeSpell(Unit* pTarget)
{
    if (me->GetHealthPct() < 50)
    {
        if (HAVOC_darkness && TryCastSpell(HAVOC_darkness, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (HAVOC_blur && TryCastSpell(HAVOC_blur, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    //  TryCastSpell(GetArtifactSpell(), pTarget);
    if (HAVOC_metamorphosis && BotUtility::SpellHasReady(me, HAVOC_metamorphosis) && TryCastSpell(HAVOC_metamorphosis, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //aoe
    if (HAVOC_eye_beam && BotUtility::SpellHasReady(me, HAVOC_eye_beam))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(HAVOC_eye_beam, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (HAVOC_blade_dance && BotUtility::SpellHasReady(me, HAVOC_blade_dance))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(HAVOC_blade_dance, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (HAVOC_throw_glaive && BotUtility::SpellHasReady(me, HAVOC_throw_glaive))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(HAVOC_throw_glaive, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (HAVOC_chaos_nova && BotUtility::SpellHasReady(me, HAVOC_chaos_nova))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(HAVOC_chaos_nova, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    //single
    if (HAVOC_fel_rush && TryCastSpell(HAVOC_fel_rush, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (HAVOC_chaos_strike && TryCastSpell(HAVOC_chaos_strike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (HAVOC_demons_bite && TryCastSpell(HAVOC_demons_bite, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotDemonHunterAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (!pTarget)
        pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;

    if (ProcessAura())
        return;
    if (ProcessControl(pTarget))
        return;

    switch (m_BotTalentType)
    {
    case 0:
        if (HAVOC_eye_beam && BotUtility::SpellHasReady(me, HAVOC_eye_beam))
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
            if (nearEnemys.size() > 2)
            {
                if (TryCastSpell(HAVOC_eye_beam, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (HAVOC_blade_dance && BotUtility::SpellHasReady(me, HAVOC_blade_dance))
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
            if (nearEnemys.size() > 2)
            {
                if (TryCastSpell(HAVOC_blade_dance, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (HAVOC_throw_glaive && BotUtility::SpellHasReady(me, HAVOC_throw_glaive))
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
            if (nearEnemys.size() > 2)
            {
                if (TryCastSpell(HAVOC_throw_glaive, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (HAVOC_chaos_nova && BotUtility::SpellHasReady(me, HAVOC_chaos_nova))
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
            if (nearEnemys.size() > 2)
            {
                if (TryCastSpell(HAVOC_chaos_nova, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        break;
    case 1:
        if (Vengeance_immolation_aura && BotUtility::SpellHasReady(me, Vengeance_immolation_aura))
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
            if (nearEnemys.size() > 2)
            {
                if (TryCastSpell(Vengeance_immolation_aura, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (Vengeance_infernal_strike && BotUtility::SpellHasReady(me, Vengeance_infernal_strike))
        {
            NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
            if (targetRangeEnemys.size() > 2)
            {
                if (TryCastSpell(Vengeance_infernal_strike, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (Vengeance_throw_glaive && BotUtility::SpellHasReady(me, Vengeance_throw_glaive))
        {
            NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
            if (targetRangeEnemys.size() > 2)
            {
                if (TryCastSpell(Vengeance_throw_glaive, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (Vengeance_soul_cleave && BotUtility::SpellHasReady(me, Vengeance_soul_cleave))
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
            if (nearEnemys.size() > 2)
            {
                if (TryCastSpell(Vengeance_soul_cleave, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        if (Vengeance_sigil_of_flame && BotUtility::SpellHasReady(me, Vengeance_sigil_of_flame))
        {
            NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
            if (targetRangeEnemys.size() > 2)
            {
                if (TryCastSpell(Vengeance_sigil_of_flame, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        break;
    }

}

bool BotDemonHunterAI::TargetNeedInvincible(Unit* player)
{
    if (player->GetHealthPct() < 15 && player->IsInCombat() && !IsInvincible(player))
    {
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_CHARM) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FEAR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FREEZE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_HORROR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        return true;
    }
    return false;
}

bool BotDemonHunterAI::TargetNeedFree(Unit* player)
{
    if (IsInvincible(player))
        return false;
    if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_DAZE))
        return true;
    return false;
}

bool BotDemonHunterAI::IsHealerBotAI()
{
    return false;
}

bool BotDemonHunterAI::IsAttacker()
{
    return true;
}

bool BotDemonHunterAI::TargetIsCtrl(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR))
        return true;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return true;
    return false;
}
