
#include "BotGroupClassAI.h"
#include "Group.h"

void GroupPaladinAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void GroupPaladinAI::ResetBotAI()
{
    UpdateTalentType();
    BotGroupAI::ResetBotAI();
    InitializeSpells(me);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(PaladinIDLE_AOEGuardWish);
    m_WishStore.RegisterWish(PaladinIDLE_GuardWish);
    m_WishStore.RegisterWish(PaladinIDLE_AOEKingWish);
    m_WishStore.RegisterWish(PaladinIDLE_KingWish);
    m_WishStore.RegisterWish(PaladinIDLE_AOEWitWish);
    m_WishStore.RegisterWish(PaladinIDLE_WitWish);
    m_WishStore.RegisterWish(PaladinIDLE_AOEStrWish);
    m_WishStore.RegisterWish(PaladinIDLE_StrWish);
}

uint32 GroupPaladinAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 1;
}

void GroupPaladinAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);

    m_WishStore.RegisterWish(PaladinIDLE_AOEGuardWish);
    m_WishStore.RegisterWish(PaladinIDLE_GuardWish);
    m_WishStore.RegisterWish(PaladinIDLE_AOEKingWish);
    m_WishStore.RegisterWish(PaladinIDLE_KingWish);
    m_WishStore.RegisterWish(PaladinIDLE_AOEWitWish);
    m_WishStore.RegisterWish(PaladinIDLE_WitWish);
    m_WishStore.RegisterWish(PaladinIDLE_AOEStrWish);
    m_WishStore.RegisterWish(PaladinIDLE_StrWish);
}

uint32 GroupPaladinAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool GroupPaladinAI::ProcessAura()
{
    if (me->IsMounted() && !me->IsInCombat())
    {
        if (PaladinIDLE_MountAura && !me->HasAura(PaladinIDLE_MountAura) && TryCastSpell(PaladinIDLE_MountAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (m_BotTalentType == 0)
        {
            if (!me->HasAura(PaladinIDLE_CastAura) && TryCastSpell(PaladinIDLE_CastAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 1)
        {
            if (!me->HasAura(PaladinIDLE_ArmorAura) && TryCastSpell(PaladinIDLE_ArmorAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 2)
        {
            if (!me->HasAura(PaladinIDLE_JudgeAura) && TryCastSpell(PaladinIDLE_JudgeAura, me, false, false) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}
bool GroupPaladinAI::ProcessTryFriendImmune()
{
    if (ProcessTryFullHealth())
        return true;
    if (!PaladinGuard_PhyImmune || BotUtility::SpellHasReady(me, PaladinGuard_PhyImmune))
        return false;
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        if (pUnit->GetHealthPct() > 12)
            continue;
        if (IsInvincible(pUnit))
            continue;
        if (!pUnit->HasAura(PaladinFlag_Discipline))
        {
            if (TryCastSpell(PaladinGuard_PhyImmune, pUnit) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool GroupPaladinAI::ProcessTryFullHealth()
{
    if (!PaladinHeal_FullHoly || BotUtility::SpellHasReady(me, PaladinHeal_FullHoly))
        return false;
    if (me->GetHealthPct() > 8)
        return false;
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        if (pUnit->GetHealthPct() > 8)
            continue;
        if (IsInvincible(pUnit))
            continue;
        if (!pUnit->HasAura(PaladinFlag_Discipline))
        {
            if (TryCastSpell(PaladinHeal_FullHoly, pUnit) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

void GroupPaladinAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    ProcessMeleeSpell(pTarget);
}

bool GroupPaladinAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (!me->HasAura(m_UseMountID) && ProcessStamp())
        return false;

    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    for (Unit* player : friends)
    {
        if (!player->ToPlayer() || !player->IsAlive())
            continue;
        if (NeedUseGuardWish(player->ToPlayer()))
        {
            if (PaladinIDLE_AOEGuardWish)
            {
                if (TryCastSpell(PaladinIDLE_AOEGuardWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
            else if (PaladinIDLE_GuardWish)
            {
                if (!player->HasAura(PaladinIDLE_GuardWish) && TryCastSpell(PaladinIDLE_GuardWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
        }
        //if (NeedUseWitWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEWitWish, player, true) == SpellCastResult::SPELL_CAST_OK)
        //	return false;
        if (NeedUseStrWish(player->ToPlayer()))
        {
            if (PaladinIDLE_AOEStrWish)
            {
                if (TryCastSpell(PaladinIDLE_AOEStrWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
            else if (PaladinIDLE_StrWish)
            {
                if (!player->HasAura(PaladinIDLE_StrWish) && TryCastSpell(PaladinIDLE_StrWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
        }
        if (NeedUseKingWish(player->ToPlayer()))
        {
            if (PaladinIDLE_AOEKingWish)
            {
                if (TryCastSpell(PaladinIDLE_AOEKingWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
            else if (PaladinIDLE_KingWish)
            {
                if (!player->HasAura(PaladinIDLE_KingWish) && TryCastSpell(PaladinIDLE_KingWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return false;
            }
        }
    }

    if (ProcessAura())
        return true;
    if (me->HasAura(m_UseMountID))
    {
        return false;
    }
    NearUnitVec needHealthPlayers = SearchNeedHealth(BOTAI_RANGESPELL_DISTANCE);
    if (needHealthPlayers.empty())
        return TryUpMount();
    //me->StopMoving();
    Unit* healthPlayer = needHealthPlayers[urand(0, needHealthPlayers.size() - 1)];
    ProcessHealthSpell(healthPlayer);
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return false;
}

bool GroupPaladinAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    //if (m_BotTalentType != 0)
    return false;
    return RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE).size() > 0;
}

void GroupPaladinAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        if (IsInvincible(me) || me->GetHealthPct() < 25)
        {
            me->StopMoving();
            if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
            FleeMovement();
    }
    else
        return;
    if (ProcessAura())
        return;
    if (ProcessStamp())
        return;
    if (PaladinAssist_ReviveMana && GetManaPowerPer() < 20 && TryCastSpell(PaladinAssist_ReviveMana, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PaladinGuard_UnShield && !me->HasAura(PaladinGuard_UnShield) && TryCastSpell(PaladinGuard_UnShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && me->HasAura(PaladinFlag_MomentHoly) && me->GetHealthPct() < 90)
    {
        if (TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TargetNeedInvincible(me) && TryCastSpell(PaladinGuard_Invincible, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessTryFriendImmune())
        return;
    if (TargetNeedFree(me) && TryCastSpell(PaladinGuard_FreeAura, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 0)
    {
        Unit* player = enemys[urand(0, enemys.size() - 1)];
        if (!HasAuraMechanic(player, Mechanics::MECHANIC_STUN) && TryCastSpell(PaladinAssist_StunMace, player) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (m_BotTalentType == 2 && !HasAuraMechanic(player, Mechanics::MECHANIC_STUN) && TryCastSpell(PaladinAssist_Confession, player) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() < 40)
    {
        if (m_BotTalentType == 0 && PaladinMelee_HolyAtt && TryCastSpell(PaladinMelee_HolyAtt, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

void GroupPaladinAI::ProcessPrepareHealthSpell(Unit* pTarget)
{
    if (!pTarget || GetManaPowerPer() < 5)
        return;
    if (ProcessDispel())
        return;
    if (PaladinHeal_BigHoly)
    {
        if (TryCastSpellByLifePCTInterrupt(PaladinHeal_BigHoly, pTarget, 70) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (PaladinHeal_FastHoly)
    {
        if (TryCastSpellByLifePCTInterrupt(PaladinHeal_FastHoly, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupPaladinAI::ProcessHealthSpell(Unit* pTarget)
{
    if (ProcessAura())
        return;
    if (ProcessStamp())
        return;
    float manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;
    if (pTarget != me && m_BotTalentType != 0)
    {
        if (manaPct < 25)
            return;
    }
    if (ProcessTryFriendImmune())
        return;
    float life = pTarget->GetHealthPct();
    if (m_BotTalentType == 2 && me->HasAura(PaladinFlag_MomentHoly) && pTarget->GetHealthPct() < 90)
    {
        if (TryCastSpellByLifePCTInterrupt(PaladinHeal_FastHoly, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (life < 15)
    {
        me->StopMoving();
        if (TryCastSpell(PaladinHeal_FullHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpellByLifePCTInterrupt(PaladinHeal_FastHoly, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (life >= 15 && life < 65)
    {
        me->StopMoving();
        if (TryCastSpellByLifePCTInterrupt(PaladinHeal_BigHoly, pTarget, 70) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if ((life >= 65 && life < 90) || (pTarget->GetGUID() == m_CruxHealTarget))
    {
        me->StopMoving();
        if (TryCastSpellByLifePCTInterrupt(PaladinHeal_FastHoly, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

void GroupPaladinAI::ProcessMeleeSpell(Unit* pTarget)
{
    uint32 manaPct = GetManaPowerPer();
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        if (m_BotTalentType != 1)
        {
            if (!IsInvincible(me) && me->GetHealthPct() < 40)
            {
                me->StopMoving();
                if (TryCastSpellByLifePCTInterrupt(PaladinHeal_BigHoly, me, 80) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (IsInvincible(me) && me->GetHealthPct() < 80)
            {
                if (manaPct > 25)
                {
                    me->StopMoving();
                    if (TryCastSpellByLifePCTInterrupt(PaladinHeal_BigHoly, me, 80) == SpellCastResult::SPELL_CAST_OK)
                        return;
                }
                if (TryCastSpellByLifePCTInterrupt(PaladinHeal_FastHoly, me, 93) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
    else
        return;
    if (ProcessAura())
        return;
    if (ProcessStamp())
        return;

    if (TargetNeedFree(me) && TryCastSpell(PaladinGuard_FreeAura, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 1 && TryCastSpell(PaladinMelee_AOEOffertory, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType != 1 && me->GetHealthPct() < 20 && manaPct > 25 && me->IsInCombat() && !IsInvincible(me) && enemys.size() > 0)
    {
        if (TryCastSpell(PaladinGuard_Invincible, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    float meLife = me->GetHealthPct();
    if (PaladinGuard_UnShield && !me->HasAura(PaladinGuard_UnShield) && TryCastSpell(PaladinGuard_UnShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (PaladinAssist_UpPower && meLife > 80 && TryCastSpell(PaladinAssist_UpPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec tryKills = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : tryKills)
    {
        if (pUnit->GetHealthPct() >= 20)
            continue;
        if (TryCastSpell(PaladinMelee_KillMace, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 0 && meLife < 65)
    {
        if (PaladinMelee_HolyAtt && TryCastSpell(PaladinMelee_HolyAtt, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 1)
    {
        if (PaladinMelee_FlyShield && TryCastSpell(PaladinMelee_FlyShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_ShieldAtt && TryCastSpell(PaladinMelee_ShieldAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_MaceAtt && TryCastSpell(PaladinMelee_MaceAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (m_BotTalentType == 2)
    {
        if (me->HasAura(PaladinFlag_MomentHoly) && meLife < 90 && TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_HolyStrom && TryCastSpell(PaladinMelee_HolyStrom, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (PaladinMelee_WeaponAtt && TryCastSpell(PaladinMelee_WeaponAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TryCastSpell(PaladinMelee_LifeJudge, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (ProcessDispel())
        return;
    if (m_BotTalentType != 1)
    {
        NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
        if (friends.size() > 0)
        {
            //std::random_shuffle(friends.begin(), friends.end());
            for (Unit* player : friends)
            {
                if (player->GetHealthPct() < 60)
                {
                    ProcessHealthSpell(player);
                    break;
                }
            }
        }
    }
}

void GroupPaladinAI::ProcessRangeSpell(Unit* pTarget)
{
    if (pTarget && ProcessPullSpell(pTarget))
        return;
    if (ProcessStamp())
        return;
    if (ProcessAura())
        return;
    if (ProcessTryFriendImmune())
        return;
    ProcessDispel();
}

bool GroupPaladinAI::ProcessPullSpell(Unit* pTarget)
{
    if (m_BotTalentType != 1)
        return false;
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
        return false;
    if (BotGroupAI::PVE_PULL)
    {
        if (PaladinGuard_Pull && TryCastPullSpell(PaladinGuard_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (PaladinGuard_Pull && TryCastSpell(PaladinGuard_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool GroupPaladinAI::ProcessFullDispel()
{
    if (!m_FullDispel)
        return false;
    if (me->IsMounted())
    {
        m_FullDispel = 0;
        return false;
    }
    if (PaladinAssist_Dispel != 0)
    {
        if (ProcessDispel())
            return true;
        else if (!BotUtility::SpellHasReady(me, PaladinAssist_Dispel))
            return true;
    }
    if (m_FullDispel < getMSTime())
        m_FullDispel = 0;
    return false;
}

bool GroupPaladinAI::ProcessStamp()
{
    float manaPct = GetManaPowerPer();
    if (manaPct < 15)
    {
        if (PaladinAssist_ReviveMana && !me->HasAura(PaladinAssist_ReviveMana) && TryCastSpell(PaladinAssist_ReviveMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (PaladinAssist_ManaStamp && !me->HasAura(PaladinAssist_ManaStamp) && TryCastSpell(PaladinAssist_ManaStamp, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (PaladinMelee_ManaJudge && BotUtility::SpellHasReady(me, PaladinMelee_ManaJudge))
        {
            Unit* pTarget = me->GetSelectedUnit();
            if (pTarget && TryCastSpell(PaladinMelee_ManaJudge, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (me->InArena())
            {
                NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
                for (Unit* pUnit : enemys)
                {
                    if (TryCastSpell(PaladinMelee_ManaJudge, pUnit) == SpellCastResult::SPELL_CAST_OK)
                        return true;
                }
            }
        }
    }
    else if (manaPct > 80)
    {
        if (m_BotTalentType == 0)
        {
            if (!me->HasAura(PaladinAssist_ManaStamp) && TryCastSpell(PaladinAssist_ManaStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 1)
        {
            if (!me->HasAura(PaladinIDLE_JusticeRage) && TryCastSpell(PaladinIDLE_JusticeRage, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (!me->HasAura(PaladinAssist_LifeStamp) && TryCastSpell(PaladinAssist_LifeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (m_BotTalentType == 2)
        {
            if (PaladinAssist_ComStamp)
            {
                if (!me->HasAura(PaladinAssist_ComStamp) && TryCastSpell(PaladinAssist_ComStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else if (PaladinAssist_RevengeStamp)
            {
                if (!me->HasAura(PaladinAssist_RevengeStamp) && TryCastSpell(PaladinAssist_RevengeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else if (PaladinAssist_StunStamp)
            {
                if (!me->HasAura(PaladinAssist_StunStamp) && TryCastSpell(PaladinAssist_StunStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else
            {
                if (!me->HasAura(PaladinAssist_JusticeStamp) && TryCastSpell(PaladinAssist_JusticeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    return false;
}

bool GroupPaladinAI::ProcessDispel()
{
    if (PaladinAssist_Dispel == 0 || !BotUtility::SpellHasReady(me, PaladinAssist_Dispel))
        return false;
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        //if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_FREEZE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_HORROR) ||
        //	HasAuraMechanic(player, Mechanics::MECHANIC_STUN))
        {
            if (TryCastSpell(PaladinAssist_Dispel, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool GroupPaladinAI::TargetNeedInvincible(Unit* player)
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

bool GroupPaladinAI::TargetNeedFree(Unit* player)
{
    if (IsInvincible(player))
        return false;
    if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_DAZE))
        return true;
    return false;
}

uint32 GroupPaladinAI::GetReviveSpell()
{
    return PaladinIDLE_Revive;
}

bool GroupPaladinAI::IsMeleeBotAI()
{
    return (m_BotTalentType != 0);
}

bool GroupPaladinAI::IsHealerBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool GroupPaladinAI::IsAttacker()
{
    return (m_BotTalentType != 0);
}

bool GroupPaladinAI::NeedUseGuardWish(Player* player)
{
    if (m_BotTalentType != 1 || ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
        return true;
    case CLASS_HUNTER:
    case CLASS_ROGUE:
    case CLASS_PRIEST:
    case CLASS_SHAMAN:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_DRUID:
        return false;
    }
    return false;
}

bool GroupPaladinAI::NeedUseKingWish(Player* player)
{
    if (ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
    case CLASS_PALADIN:
    case CLASS_HUNTER:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return true;
    }
    return false;
}

bool GroupPaladinAI::NeedUseWitWish(Player* player)
{
    if (ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
    case CLASS_HUNTER:
    case CLASS_ROGUE:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
        return false;
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
        return true;
    }
    return false;
}

bool GroupPaladinAI::NeedUseStrWish(Player* player)
{
    if (ExistWish(player))
        return false;
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
        return true;
    case CLASS_PALADIN:
    case CLASS_HUNTER:
    case CLASS_SHAMAN:
    case CLASS_DRUID:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
    case CLASS_PRIEST:
        return false;
    }
    return false;
}

bool GroupPaladinAI::ExistWish(Unit* player)
{
    if (PaladinIDLE_AOEGuardWish && player->HasAura(PaladinIDLE_AOEGuardWish))
        return true;
    if (PaladinIDLE_AOEKingWish && player->HasAura(PaladinIDLE_AOEKingWish))
        return true;
    if (PaladinIDLE_AOEWitWish && player->HasAura(PaladinIDLE_AOEWitWish))
        return true;
    if (PaladinIDLE_AOEStrWish && player->HasAura(PaladinIDLE_AOEStrWish))
        return true;
    return false;
}

void GroupPaladinAI::UpEnergy()
{
    if (m_BotTalentType == 0)
    {
        uint32 max = me->GetMaxPower(Powers::POWER_MANA);
        uint32 power = me->GetPower(Powers::POWER_MANA);
        me->SetPower(Powers::POWER_MANA, (max / 600) + power);
    }
}

bool GroupPaladinAI::IsTankBotAI()
{
    return (m_BotTalentType == 1);
}
