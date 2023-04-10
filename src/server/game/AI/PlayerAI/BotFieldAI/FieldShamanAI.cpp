
#include "BotFieldClassAI.h"
#include "Totem.h"

void FieldShamanAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldShamanAI::ResetBotAI()
{
    UpdateTalentType();
    BotFieldAI::ResetBotAI();
    m_CurrentPattern = ShamanTotemPattern::ShamanTP_None;
    InitializeSpells(me);
}

void FieldShamanAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
}

uint32 FieldShamanAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool FieldShamanAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (m_BotTalentType == 1)
        return false;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget || pTarget->ToCreature())
        return false;
    if (RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0)
        return true;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

bool FieldShamanAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    //if (m_BotTalentType == 0)
    //{
    //	if (!me->HasAura(ShamanIDLE_FireWeapon) && CanCastSpell(ShamanIDLE_FireWeapon, me, true) == SpellCastResult::SPELL_CAST_OK)
    //		return false;
    //}
    //else if (m_BotTalentType == 1)
    //{
    //	if (ShamanIDLE_FastWeapon)
    //	{
    //		if (!me->HasAura(ShamanIDLE_FastWeapon) && CanCastSpell(ShamanIDLE_FastWeapon, me, true) == SpellCastResult::SPELL_CAST_OK)
    //			return false;
    //	}
    //	else
    //	{
    //		if (!me->HasAura(ShamanIDLE_IceWeapon) && CanCastSpell(ShamanIDLE_IceWeapon, me, true) == SpellCastResult::SPELL_CAST_OK)
    //			return false;
    //	}
    //}
    //else if (m_BotTalentType == 2)
    //{
    //	if (ShamanIDLE_LifeWeapon)
    //	{
    //		if (!me->HasAura(ShamanIDLE_LifeWeapon) && CanCastSpell(ShamanIDLE_LifeWeapon, me, true) == SpellCastResult::SPELL_CAST_OK)
    //			return false;
    //	}
    //	else
    //	{
    //		if (!me->HasAura(ShamanIDLE_FireWeapon) && CanCastSpell(ShamanIDLE_FireWeapon, me, true) == SpellCastResult::SPELL_CAST_OK)
    //			return false;
    //	}
    //}

    if (me->HasAura(m_UseMountID))
        return false;
    NearUnitVec needHealthPlayers = SearchNeedHealth(BOTAI_RANGESPELL_DISTANCE);
    if (needHealthPlayers.empty())
        return TryUpMount();
    Unit* healthPlayer = needHealthPlayers[urand(0, needHealthPlayers.size() - 1)];
    ProcessHealthSpell(healthPlayer);
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return false;
}

void FieldShamanAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    else
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Flee))
        return;

    if (m_BotTalentType == 0 && ShamanShield_Earth)
    {
        if (!me->HasAura(ShamanShield_Earth) && TryCastSpell(ShamanShield_Earth, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (!me->HasAura(ShamanShield_Water) && TryCastSpell(ShamanShield_Water, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 0)
    {
        Unit* pRndPlayer = enemys[urand(0, enemys.size() - 1)];
        if (m_BotTalentType == 0 && ShamanAssist_MomentHeal && !HasAuraMechanic(pRndPlayer, Mechanics::MECHANIC_POLYMORPH))
        {
            if (TryCastSpell(ShamanAssist_MomentHeal, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (TryCastSpell(ShamanAssist_Frog, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (m_BotTalentType == 0 && ShamanHealth_Torrent && me->GetHealthPct() < 75)
        {
            if (TryCastSpell(ShamanHealth_Torrent, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }

        if (ShamanTotem_DecMove && !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_DecMove, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (ShamanTotem_AbsorbBuff && !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_AbsorbBuff, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        bool existFireTotem = ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE, BOTAI_TOTEMRANGE);
        if (ShamanTotem_Attack && !existFireTotem)
        {
            if (TryCastSpell(ShamanTotem_Attack, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (existFireTotem && ShamanAssist_FireNova && TryCastSpell(ShamanAssist_FireNova, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(ShamanCast_IceThud, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

void FieldShamanAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Heal))
        return;
    if (GetManaPowerPer() > 25)
    {
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_WATER, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_BMana, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (TryCastSpell(ShamanTotem_Mana, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_MgcHeal, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (m_BotTalentType == 2 && ShamanAssist_HealCrit)
    {
        if (TryCastSpell(ShamanAssist_HealCrit, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 2 && ShamanShield_Earth)
    {
        if (!pTarget->HasAura(ShamanShield_Earth) && TryCastSpell(ShamanShield_Earth, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (m_BotTalentType == 2 && ShamanHealth_Torrent && pTarget->GetHealthPct() < 75)
    {
        if (TryCastSpell(ShamanHealth_Torrent, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (SearchLifePctByFriendRange(pTarget, 75).size() > 1)
    {
        if (TryCastSpell(ShamanHealth_Chain, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    float targetHealPct = pTarget->GetHealthPct();
    if (targetHealPct < 15 && TryCastSpell(ShamanHealth_Fast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (targetHealPct >= 15 && targetHealPct < 70 && TryCastSpell(ShamanHealth_Bast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (targetHealPct >= 70 && targetHealPct < 85 && TryCastSpell(ShamanHealth_Fast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    ProcessDispel();
}

void FieldShamanAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Melee))
        return;
    if (ShamanShield_Lightning && !me->HasAura(ShamanShield_Lightning) && TryCastSpell(ShamanShield_Lightning, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(ShamanAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (GetManaPowerPer() > 15)
    {
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_SummonFire, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (TryCastSpell(ShamanTotem_Attack, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_SummonSoil, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (TryCastSpell(ShamanTotem_PhyPower, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_AttSpeed, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (ProcessHeroic())
        return;
    if (TryCastSpell(ShamanAssist_FireNova, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ShamanAtt_StormStrike && TryCastSpell(ShamanAtt_StormStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ShamanAtt_FireStrike && TryCastSpell(ShamanAtt_FireStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TargetIsMagic(pTarget->ToPlayer()))
    {
        if (TryCastSpell(ShamanCast_FireThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(ShamanCast_EarthThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TryCastSpell(ShamanAssist_Cleansing, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void FieldShamanAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Range))
        return;
    if (ShamanShield_Water && !me->HasAura(ShamanShield_Water) && TryCastSpell(ShamanShield_Water, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(ShamanAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessHeroic())
        return;
    if (GetManaPowerPer() > 25)
    {
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_MgcPower, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_MgcSpeed, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (me->GetHealthPct() < 40)
        {
            ProcessHealthSpell(me);
            return;
        }
    }
    if (me->GetDistance(pTarget) < BOTAI_TOTEMRANGE && TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && ShamanAssist_MomentCast && TryCastSpell(ShamanAssist_MomentCast, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && ShamanCast_LightningStorm && RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(ShamanCast_LightningStorm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    //if (m_BotTalentType == 2 && GetManaPowerPer() < 80)
    //	return;
    if (ShamanCast_FireStrike && TryCastSpell(ShamanCast_FireStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(ShamanCast_LightningChain, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TryCastSpell(ShamanCast_LightningArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool FieldShamanAI::ProcessDispel()
{
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    if (friends.empty())
        return false;
    //std::random_shuffle(friends.begin(), friends.end());
    for (Unit* player : friends)
    {
        if (TryCastSpell(ShamanDispel_Refine, player) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool FieldShamanAI::ProcessHeroic()
{
    if (ShamanAssist_Heroic)
    {
        //uint32 enemyCount = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE).size();
        //if (enemyCount < 3)
        //	return false;
        NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
        uint32 canHeroicCount = 0;
        for (Unit* player : friends)
        {
            if (!player->HasAura(ShamanFlag_NoHeroic))
                ++canHeroicCount;
        }
        if (canHeroicCount > 4 && TryCastSpell(ShamanAssist_Heroic, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool FieldShamanAI::ExistTotemByType(PlayerTotemType totemType, float range)
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

uint32 FieldShamanAI::GetReviveSpell()
{
    return ShamanIDLE_Revive;
}

bool FieldShamanAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool FieldShamanAI::IsRangeBotAI()
{
    if (m_BotTalentType == 0 || m_BotTalentType == 2)
        return true;
    return false;
}

bool FieldShamanAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool FieldShamanAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool FieldShamanAI::TryRecycleTotem(ShamanTotemPattern pattern)
{
    if (pattern == ShamanTotemPattern::ShamanTP_None || m_CurrentPattern == pattern)
        return false;
    m_CurrentPattern = pattern;
    //if (CanCastSpell(ShamanTotem_Recycle, me) == SpellCastResult::SPELL_CAST_OK)
    //	return true;
    return false;
}

void FieldShamanAI::UpEnergy()
{
}
