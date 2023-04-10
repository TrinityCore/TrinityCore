
#include "BotGroupClassAI.h"
#include "Totem.h"

void GroupShamanAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

bool GroupShamanAI::ProcessUpWeapon()
{
    if (m_IsUpedWeapon >= 2)
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    ++m_IsUpedWeapon;
    uint32 weaponSpellEntry = 0;
    if (m_BotTalentType == 0)
    {
        weaponSpellEntry = ShamanIDLE_FireWeapon;
    }
    else if (m_BotTalentType == 1)
    {
        weaponSpellEntry = ShamanIDLE_FastWeapon;
        if (weaponSpellEntry == 0)
            weaponSpellEntry = ShamanIDLE_IceWeapon;
        if (weaponSpellEntry == 0)
            weaponSpellEntry = ShamanIDLE_FireWeapon;
    }
    else if (m_BotTalentType == 2)
    {
        weaponSpellEntry = ShamanIDLE_LifeWeapon;
        if (weaponSpellEntry == 0)
            weaponSpellEntry = ShamanIDLE_FireWeapon;
    }
    if (weaponSpellEntry == 0)
        return false;
    EquipmentSlots equipSlot = (m_IsUpedWeapon <= 1) ? EquipmentSlots::EQUIPMENT_SLOT_MAINHAND : EquipmentSlots::EQUIPMENT_SLOT_OFFHAND;
    if (m_BotTalentType != 1)
        ++m_IsUpedWeapon;
    Item* pWeaponItem = me->GetItemByPos(255, equipSlot);
    if (!pWeaponItem)
        return false;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(weaponSpellEntry,DIFFICULTY_40);//DIFFICULTY_40
    if (!spellInfo || spellInfo->IsPassive() || m_Flying.HasFlying())
        return false;
    Dismount();
    /*TriggerCastData data;
    data.triggerFlags = TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM;
    Spell* spell = new Spell(me, spellInfo, data);*/
    //spell->m_CastItem = NULL;
    SpellCastTargets targets;
    targets.SetTargetMask(TARGET_FLAG_ITEM);
    targets.SetItemTarget(pWeaponItem);
    targets.SetSrc(me->GetPosition());
    targets.SetDst(me->GetPosition());
    targets.Update(me);
    //SpellCastResult castResult = spell->prepare(&targets);
    //return (castResult == SpellCastResult::SPELL_CAST_OK);
    return 0;
}

void GroupShamanAI::ResetBotAI()
{
    UpdateTalentType();
    BotGroupAI::ResetBotAI();
    m_CurrentPattern = ShamanTotemPattern::ShamanTP_None;
    InitializeSpells(me);
    m_NonFearTotemTick = 0;
    m_SummonFireTotemTick = 0;
    m_IsUpedWeapon = 0;
}

uint32 GroupShamanAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 1;
}

void GroupShamanAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
}

uint32 GroupShamanAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool GroupShamanAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (m_BotTalentType == 1)
        return false;
    if (RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0)
        return true;
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void GroupShamanAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    if (ProcessShield())
        return;
    if (TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool GroupShamanAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (ProcessUpWeapon())
        return true;

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

void GroupShamanAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    else
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Flee))
        return;
    if (Unit* pCastingTarget = RandomRangeEnemyByCasting(24))
    {
        if (TryCastSpell(ShamanAssist_BlockCast, pCastingTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessShield())
        return;

    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return;
    if (TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFleeStateTotem())
        return;

    if (me->GetHealthPct() < 60 && m_BotTalentType != 1)
        ProcessHealthSpell(me);

    ProcessDispel();
    ProcessCruel();
}

void GroupShamanAI::ProcessPrepareHealthSpell(Unit* pTarget)
{
    if (!pTarget || GetManaPowerPer() < 5)
        return;
    if (ProcessDispel())
        return;

    if (ShamanHealth_Bast)
    {
        if (TryCastSpellByLifePCTInterrupt(ShamanHealth_Bast, pTarget, 70) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (ShamanHealth_Fast)
    {
        if (TryCastSpellByLifePCTInterrupt(ShamanHealth_Fast, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupShamanAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Heal))
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;
    if (ProcessShield())
        return;
    if (ProcessHealthStateTotem())
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
    if (SearchLifePctByFriendRange(pTarget, 75).size() > 1)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpellByLifePCTInterrupt(ShamanHealth_Chain, pTarget, 88) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    float targetHealPct = pTarget->GetHealthPct();
    if (targetHealPct < 20)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpellByLifePCTInterrupt(ShamanHealth_Fast, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (targetHealPct >= 20 && targetHealPct < 70)
    {
        if (TryCastSpell(ShamanAssist_MomentHeal, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpellByLifePCTInterrupt(ShamanHealth_Bast, pTarget, 70) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (targetHealPct >= 70 && targetHealPct < 90)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpellByLifePCTInterrupt(ShamanHealth_Fast, pTarget, 85) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
    ProcessCruel();
}

void GroupShamanAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Melee))
        return;
    if (Unit* pCastingTarget = RandomRangeEnemyByCasting(24))
    {
        if (TryCastSpell(ShamanAssist_BlockCast, pCastingTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessShield())
        return;
    if (ProcessMeleeStateTotem())
        return;
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

void GroupShamanAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (TryRecycleTotem(ShamanTotemPattern::ShamanTP_Range))
        return;
    if (Unit* pCastingTarget = RandomRangeEnemyByCasting(24))
    {
        if (TryCastSpell(ShamanAssist_BlockCast, pCastingTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessShield())
        return;
    if (ProcessRangeStateTotem())
        return;
    if (ProcessHeroic())
        return;
    if (me->GetDistance(pTarget) < BOTAI_TOTEMRANGE && TryCastSpell(ShamanCast_IceThud, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && ShamanAssist_MomentCast && TryCastSpell(ShamanAssist_MomentCast, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && ShamanCast_LightningStorm && RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(ShamanCast_LightningStorm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ShamanCast_FireStrike && TryCastSpell(ShamanCast_FireStrike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(ShamanCast_LightningChain, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() < 60 && m_BotTalentType != 1)
        ProcessHealthSpell(me);
    if (TryCastSpell(ShamanCast_LightningArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool GroupShamanAI::ProcessFullDispel()
{
    if (!m_FullDispel)
        return false;
    if (me->IsMounted())
    {
        m_FullDispel = 0;
        return false;
    }
    if (ProcessDispel())
        return true;
    if (ProcessCruel())
        return true;
    if (ShamanDispel_Refine != 0)
    {
        if (!BotUtility::SpellHasReady(me, ShamanDispel_Refine))
            return true;
    }
    if (ShamanAssist_DecCruel != 0)
    {
        if (!BotUtility::SpellHasReady(me, ShamanAssist_DecCruel))
            return true;
    }
    if (m_FullDispel < getMSTime())
        m_FullDispel = 0;
    return false;
}

bool GroupShamanAI::ProcessDispel()
{
    if (ShamanDispel_Refine == 0 || !BotUtility::SpellHasReady(me, ShamanDispel_Refine))
        return false;
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

bool GroupShamanAI::ProcessCruel()
{
    if (ShamanAssist_DecCruel == 0 || !BotUtility::SpellHasReady(me, ShamanAssist_DecCruel))
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
            if (TryCastSpell(ShamanAssist_DecCruel, player) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool GroupShamanAI::ProcessHeroic()
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

bool GroupShamanAI::ProcessShield()
{
    bool hasEarth = false;
    NearUnitVec nearEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (nearEnemys.empty())
    {
        if (m_BotTalentType == 2 && ShamanShield_Earth)
        {
            NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
            Unit* pNeedEarthUnit = NULL;
            float pMinLifePct = 100;
            for (Unit* pFriend : friends)
            {
                if (pFriend->HasAura(ShamanShield_Earth, me->GetGUID()))
                {
                    hasEarth = true;
                    return false;
                }
                float lifePct = pFriend->GetHealthPct();
                if (lifePct < 80 && lifePct < pMinLifePct)
                {
                    pMinLifePct = lifePct;
                    pNeedEarthUnit = pFriend;
                }
            }
            if (!hasEarth && pNeedEarthUnit)
            {
                if (!me->HasAura(ShamanShield_Earth) && TryCastSpell(ShamanShield_Earth, pNeedEarthUnit) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    else
    {
        if (m_BotTalentType == 2 && ShamanShield_Earth)
        {
            hasEarth = me->HasAura(ShamanShield_Earth);
            if (RangeEnemyListByHasAura(ShamanShield_Earth, BOTAI_RANGESPELL_DISTANCE).empty())
            {
                if (!hasEarth && TryCastSpell(ShamanShield_Earth, me) == SpellCastResult::SPELL_CAST_OK)
                {
                    hasEarth = true;
                    return true;
                }
            }
        }
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

bool GroupShamanAI::ProcessFleeStateTotem()
{
    if (ShamanTotem_DecMove && !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_DecMove, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (ShamanTotem_AbsorbBuff && !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_AbsorbBuff, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (ShamanTotem_SummonFire && TryCastSpell(ShamanTotem_SummonFire, me) == SpellCastResult::SPELL_CAST_OK)
    {
        m_SummonFireTotemTick = getMSTime();
        return true;
    }
    return false;
}

bool GroupShamanAI::ProcessHealthStateTotem()
{
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_WATER, BOTAI_TOTEMRANGE))
    {
        if (GetManaPowerPer() < 30)
        {
            if (TryCastSpell(ShamanTotem_BMana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_Mana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_Life, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (TryCastSpell(ShamanTotem_Life, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_BMana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_Mana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_FIRE, BOTAI_TOTEMRANGE))
    {
        if (ShamanTotem_MgcHeal && TryCastSpell(ShamanTotem_MgcHeal, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (ShamanTotem_MgcPower && TryCastSpell(ShamanTotem_MgcPower, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
    {
        if (ShamanTotem_MgcSpeed && TryCastSpell(ShamanTotem_MgcSpeed, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupShamanAI::ProcessMeleeStateTotem()
{
    if (m_BotTalentType != 1)
        return false;
    if (ShamanTotem_Life && !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_WATER, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_Life, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
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
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_PhyPower, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(ShamanTotem_Armor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_AttSpeed, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(ShamanTotem_AbsorbBuff, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupShamanAI::ProcessRangeStateTotem()
{
    if (m_BotTalentType == 1)
        return false;
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_WATER, BOTAI_TOTEMRANGE))
    {
        if (GetManaPowerPer() < 30)
        {
            if (TryCastSpell(ShamanTotem_BMana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_Mana, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(ShamanTotem_Life, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (TryCastSpell(ShamanTotem_Life, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
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
        //if (existFireTotem && ShamanAssist_FireNova && TryCastSpell(ShamanAssist_FireNova, me) == SpellCastResult::SPELL_CAST_OK)
        //	return true;
    }
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_DecMove, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(ShamanTotem_Armor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_AIR, BOTAI_TOTEMRANGE))
    {
        if (TryCastSpell(ShamanTotem_MgcSpeed, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(ShamanTotem_AbsorbBuff, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupShamanAI::ExistTotemByType(PlayerTotemType totemType, float range)
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

uint32 GroupShamanAI::GetReviveSpell()
{
    return ShamanIDLE_Revive;
}

bool GroupShamanAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool GroupShamanAI::IsRangeBotAI()
{
    if (m_BotTalentType == 0 || m_BotTalentType == 2)
        return true;
    return false;
}

bool GroupShamanAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool GroupShamanAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool GroupShamanAI::TryRecycleTotem(ShamanTotemPattern pattern)
{
    if (pattern == ShamanTotemPattern::ShamanTP_None || m_CurrentPattern == pattern)
        return false;
    m_CurrentPattern = pattern;
    //if (CanCastSpell(ShamanTotem_Recycle, me) == SpellCastResult::SPELL_CAST_OK)
    //	return true;
    return false;
}

void GroupShamanAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool GroupShamanAI::TryBlockCastingByTarget(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (ShamanAssist_BlockCast && TryCastSpell(ShamanAssist_BlockCast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}
