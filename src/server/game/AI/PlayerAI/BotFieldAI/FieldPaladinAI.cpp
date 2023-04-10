
#include "BotFieldClassAI.h"


void FieldPaladinAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldPaladinAI::ResetBotAI()
{
    UpdateTalentType();
    BotFieldAI::ResetBotAI();
    InitializeSpells(me);
}

void FieldPaladinAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
}

uint32 FieldPaladinAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool FieldPaladinAI::ProcessAura()
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

bool FieldPaladinAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (ProcessAura())
        return true;
    if (me->HasAura(m_UseMountID))
    {
        return false;
    }

    if (m_BotTalentType == 0)
    {
        if (!me->HasAura(PaladinAssist_ManaStamp) && TryCastSpell(PaladinAssist_ManaStamp, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else if (m_BotTalentType == 1)
    {
        if (!me->HasAura(PaladinIDLE_JusticeRage) && TryCastSpell(PaladinIDLE_JusticeRage, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
        if (!me->HasAura(PaladinAssist_LifeStamp) && TryCastSpell(PaladinAssist_LifeStamp, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else if (m_BotTalentType == 2)
    {
        if (PaladinAssist_ComStamp)
        {
            if (!me->HasAura(PaladinAssist_ComStamp) && TryCastSpell(PaladinAssist_ComStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else if (PaladinAssist_RevengeStamp)
        {
            if (!me->HasAura(PaladinAssist_RevengeStamp) && TryCastSpell(PaladinAssist_RevengeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else if (PaladinAssist_StunStamp)
        {
            if (!me->HasAura(PaladinAssist_StunStamp) && TryCastSpell(PaladinAssist_StunStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else
        {
            if (!me->HasAura(PaladinAssist_JusticeStamp) && TryCastSpell(PaladinAssist_JusticeStamp, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
    }

    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    for (Unit* player : friends)
    {
        if (!player->ToPlayer() || !player->IsAlive())
            continue;
        if (NeedUseGuardWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEGuardWish, player, true) == SpellCastResult::SPELL_CAST_OK)
            return false;
        //if (NeedUseWitWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEWitWish, player, true) == SpellCastResult::SPELL_CAST_OK)
        //	return false;
        if (NeedUseStrWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEStrWish, player, true) == SpellCastResult::SPELL_CAST_OK)
            return false;
        if (NeedUseKingWish(player->ToPlayer()) && TryCastSpell(PaladinIDLE_AOEKingWish, player, true) == SpellCastResult::SPELL_CAST_OK)
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

bool FieldPaladinAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (m_BotTalentType != 0)
        return false;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget || pTarget->ToCreature())
        return false;
    return RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE).size() > 0;
}

void FieldPaladinAI::ProcessFlee()
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
    if (PaladinHeal_FullHoly && me->GetHealthPct() < 10)
    {
        if (PaladinHeal_FullHoly && TryCastSpell(PaladinHeal_FullHoly, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
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

void FieldPaladinAI::ProcessHealthSpell(Unit* pTarget)
{
    if (ProcessAura())
        return;
    float manaPct = GetManaPowerPer();
    if (manaPct <= 3)
        return;
    if (pTarget != me && m_BotTalentType != 0)
    {
        if (manaPct < 50)
            return;
    }
    float life = pTarget->GetHealthPct();
    if (m_BotTalentType == 2 && me->HasAura(PaladinFlag_MomentHoly) && pTarget->GetHealthPct() < 90)
    {
        if (TryCastSpell(PaladinHeal_FastHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (life < 15)
    {
        me->StopMoving();
        if (TryCastSpell(PaladinHeal_FullHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(PaladinHeal_FastHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (life >= 15 && life < 65)
    {
        me->StopMoving();
        if (TryCastSpell(PaladinHeal_BigHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (life >= 65 && life < 90)
    {
        me->StopMoving();
        if (TryCastSpell(PaladinHeal_FastHoly, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

void FieldPaladinAI::ProcessMeleeSpell(Unit* pTarget)
{
    uint32 manaPct = GetManaPowerPer();
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        if (m_BotTalentType != 1)
        {
            if (!IsInvincible(me) && me->GetHealthPct() < 25)
            {
                me->StopMoving();
                if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (IsInvincible(me) && me->GetHealthPct() < 80)
            {
                if (manaPct > 25)
                {
                    me->StopMoving();
                    if (TryCastSpell(PaladinHeal_BigHoly, me) == SpellCastResult::SPELL_CAST_OK)
                        return;
                }
                if (TryCastSpell(PaladinHeal_FastHoly, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
    else
        return;
    if (ProcessAura())
        return;

    if (manaPct < 20)
    {
        if (!me->HasAura(PaladinAssist_ManaStamp) && TryCastSpell(PaladinAssist_ManaStamp, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(PaladinMelee_ManaJudge, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
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
    if (m_BotTalentType == 2 && PaladinAssist_UpPower && TryCastSpell(PaladinAssist_UpPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() < 20)
    {
        if (TryCastSpell(PaladinMelee_KillMace, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    /*if (m_BotTalentType == 0 && meLife < 65)
    {
    if (PaladinMelee_HolyAtt && TryCastSpell(PaladinMelee_HolyAtt, me) == SpellCastResult::SPELL_CAST_OK)
    return;
    }
    else */if (m_BotTalentType == 1)
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

void FieldPaladinAI::ProcessRangeSpell(Unit* /*pTarget*/)
{
    if (ProcessAura())
        return;
    ProcessDispel();
}

bool FieldPaladinAI::ProcessDispel()
{
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

bool FieldPaladinAI::TargetNeedInvincible(Unit* player)
{
    if (player->GetHealthPct() < 20 && player->IsInCombat() && !IsInvincible(player))
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

bool FieldPaladinAI::TargetNeedFree(Unit* player)
{
    if (IsInvincible(player))
        return false;
    if (HasAuraMechanic(player, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_SNARE) ||
        HasAuraMechanic(player, Mechanics::MECHANIC_DAZE))
        return true;
    return false;
}

uint32 FieldPaladinAI::GetReviveSpell()
{
    return PaladinIDLE_Revive;
}

bool FieldPaladinAI::IsMeleeBotAI()
{
    return (m_BotTalentType != 0);
}

bool FieldPaladinAI::IsHealerBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool FieldPaladinAI::IsAttacker()
{
    return (m_BotTalentType != 0);
}

bool FieldPaladinAI::NeedUseGuardWish(Player* player)
{
    if (m_BotTalentType != 1 || !PaladinIDLE_AOEGuardWish || ExistWish(player))
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

bool FieldPaladinAI::NeedUseKingWish(Player* player)
{
    if (!PaladinIDLE_AOEKingWish || ExistWish(player))
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

bool FieldPaladinAI::NeedUseWitWish(Player* player)
{
    if (!PaladinIDLE_AOEWitWish || ExistWish(player))
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

bool FieldPaladinAI::NeedUseStrWish(Player* player)
{
    if (!PaladinIDLE_AOEStrWish || ExistWish(player))
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

bool FieldPaladinAI::ExistWish(Unit* player)
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

void FieldPaladinAI::UpEnergy()
{
}
