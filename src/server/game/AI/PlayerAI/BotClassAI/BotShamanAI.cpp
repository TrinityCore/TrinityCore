
#include "BotShamanAI.h"
#include "BotBGAIMovement.h"

void BotShamanAI::InitializeSpells()
{
    ShamanIDLE_LifeWeapon = FindMaxRankSpellByExist(32911);
    ShamanIDLE_IceWeapon = FindMaxRankSpellByExist(78273);
    ShamanIDLE_FireWeapon = FindMaxRankSpellByExist(160098);
    ShamanIDLE_PhyWeapon = FindMaxRankSpellByExist(159974);
    ShamanIDLE_FastWeapon = FindMaxRankSpellByExist(32911);

    ShamanShield_Earth = FindMaxRankSpellByExist(226078);
    ShamanShield_Water = FindMaxRankSpellByExist(79949);
    ShamanShield_Lightning = FindMaxRankSpellByExist(20545);

    ShamanAssist_Frog = FindMaxRankSpellByExist(11641);
    ShamanAssist_HealCrit = FindMaxRankSpellByExist(137531);
    ShamanAssist_MomentHeal = FindMaxRankSpellByExist(127316);
    ShamanAssist_MomentCast = FindMaxRankSpellByExist(16166);
    ShamanAssist_BlockCast = FindMaxRankSpellByExist(52870);
    ShamanAssist_Cleansing = FindMaxRankSpellByExist(370);
    ShamanAssist_FireNova = FindMaxRankSpellByExist(11969);
    ShamanAssist_Heroic = FindMaxRankSpellByExist(32182);

    ShamanAtt_StormStrike = FindMaxRankSpellByExist(17364);
    ShamanAtt_FireStrike = FindMaxRankSpellByExist(60103);

    ShamanCast_LightningArrow = FindMaxRankSpellByExist(218013);
    ShamanCast_LightningChain = FindMaxRankSpellByExist(190332);
    ShamanCast_LightningStorm = FindMaxRankSpellByExist(71935);
    ShamanCast_FireThud = FindMaxRankSpellByExist(23038);
    ShamanCast_IceThud = FindMaxRankSpellByExist(22582);
    ShamanCast_EarthThud = FindMaxRankSpellByExist(43305);
    ShamanCast_FireStrike = FindMaxRankSpellByExist(58972);

    ShamanHealth_Fast = FindMaxRankSpellByExist(71985);
    ShamanHealth_Bast = FindMaxRankSpellByExist(253330);
    ShamanHealth_Chain = FindMaxRankSpellByExist(237925);
    ShamanHealth_Torrent = FindMaxRankSpellByExist(237920);
    ShamanDispel_Refine = FindMaxRankSpellByExist(234893);

    ShamanTotem_Recycle = FindMaxRankSpellByExist(5394);

    ShamanTotem_Life = FindMaxRankSpellByExist(35199);
    ShamanTotem_Mana = FindMaxRankSpellByExist(24854);
    ShamanTotem_BMana = FindMaxRankSpellByExist(24854);

    ShamanTotem_SummonFire = FindMaxRankSpellByExist(27623);
    ShamanTotem_MgcPower = FindMaxRankSpellByExist(31985);
    ShamanTotem_Attack = FindMaxRankSpellByExist(38116);
    ShamanTotem_AOEAttack = FindMaxRankSpellByExist(39591);
    ShamanTotem_MgcHeal = FindMaxRankSpellByExist(31633);

    ShamanTotem_DecMove = FindMaxRankSpellByExist(51485);
    ShamanTotem_SummonSoil = FindMaxRankSpellByExist(73903);
    ShamanTotem_PhyPower = FindMaxRankSpellByExist(65992);
    ShamanTotem_Armor = FindMaxRankSpellByExist(73393);

    ShamanTotem_AbsorbBuff = FindMaxRankSpellByExist(148819);
    ShamanTotem_AttSpeed = FindMaxRankSpellByExist(27621);
    ShamanTotem_MgcSpeed = FindMaxRankSpellByExist(27621);

    ShamanFlag_NoHeroic = 27621;
}

void BotShamanAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

bool BotShamanAI::ProcessUpWeapon()
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

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(weaponSpellEntry,DIFFICULTY_40);//DIFFICULTY_40 //I DID
    if (!spellInfo || spellInfo->IsPassive())
        return false;
    Dismount();
    //TriggerCastData data;
    //data.triggerFlags = TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM;
    //Spell* spell = new Spell(me, spellInfo, data);
    //spell->m_CastItem = NULL;
    SpellCastTargets targets;
    targets.SetTargetMask(TARGET_FLAG_ITEM);
    targets.SetItemTarget(pWeaponItem);
    targets.SetSrc(me->GetPosition());
    targets.SetDst(me->GetPosition());
    targets.Update(me);
    //SpellCastResult castResult = spell->prepare(&targets);
    //return (castResult == SpellCastResult::SPELL_CAST_OK);
    return true;// I DID
}

void BotShamanAI::ResetBotAI()
{
    UpdateTalentType();
    BotBGAI::ResetBotAI();
    m_CurrentPattern = ShamanTotemPattern::ShamanTP_None;
    InitializeSpells();
    m_NonFearTotemTick = 0;
    m_SummonFireTotemTick = 0;
    m_IsUpedWeapon = 0;
}

uint32 BotShamanAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void BotShamanAI::EachTick()
{
    BotBGAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool BotShamanAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (m_BotTalentType == 1)
        return m_NeedFlee.TargetHasFleeAura();
    NearUnitVec nearEnemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (me->InArena())
    {
        for (Unit* pUnit : nearEnemys)
        {
            if (m_NeedFlee.TargetHasFleeAura(pUnit))
            {
                me->SetSelection(pUnit->GetGUID());
                return true;
            }
        }
    }
    else if (nearEnemys.size() > 0)
    {
        Unit* pNear = nearEnemys[urand(0, nearEnemys.size() - 1)];
        me->SetSelection(pNear->GetGUID());
        return true;
    }
    Unit* pTarget = me->GetSelectedUnit();
    if (!pTarget)
        return false;
    if (me->InArena() && !IsFleeTargetByRangeBot(pTarget))
        return false;
    float fleeDistance = m_Flee.CalcMaxFleeDistance(pTarget);
    if (me->GetDistance(pTarget->GetPosition()) < fleeDistance)//BOTAI_FLEE_JUDGE)
        return true;
    return false;
}

void BotShamanAI::ProcessReady()
{
    ProcessNormalSpell();
}

bool BotShamanAI::ProcessNormalSpell()
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
    //me->StopMoving();
    Unit* healthPlayer = needHealthPlayers[urand(0, needHealthPlayers.size() - 1)];
    ProcessHealthSpell(healthPlayer);
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return false;
}

void BotShamanAI::ProcessFlee()
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
    if (ProcessTotem())
        return;
    if (ShamanAssist_Frog && !m_NeedReserveCtrlSpell && !TargetIsSuppress(pTarget) && BotUtility::SpellHasReady(me, ShamanAssist_Frog))
    {
        me->StopMoving();
        if (TryCastSpell(ShamanAssist_Frog, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (me->GetHealthPct() < 60 && m_BotTalentType != 1)
        ProcessHealthSpell(me);
    if (ProcessArenaHealthMember())
        return;
    ProcessDispel();
}

void BotShamanAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (me != pTarget && me->GetDistance(pTarget) > BOTAI_RANGESPELL_DISTANCE)
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
    if (SearchLifePctByFriendRange(pTarget, 75).size() > 1)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(ShamanHealth_Chain, pTarget) == SpellCastResult::SPELL_CAST_OK)
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
    if (targetHealPct >= 70 && targetHealPct < 90)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(ShamanHealth_Fast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    ProcessDispel();
}

void BotShamanAI::ProcessMeleeSpell(Unit* pTarget)
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
    if (ProcessTotem())
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
    if (ProcessArenaHealthMember())
        return;
    if (TryCastSpell(ShamanAssist_Cleansing, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotShamanAI::ProcessRangeSpell(Unit* pTarget)
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
    if (ProcessTotem())
        return;
    if (ProcessHeroic())
        return;
    if (ProcessArenaHealthMember())
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

bool BotShamanAI::ProcessDispel()
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

bool BotShamanAI::ProcessHeroic()
{
    if (ShamanAssist_Heroic)
    {
        bool inArena = me->InArena();
        if (!inArena)
        {
            uint32 enemyCount = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE).size();
            if (enemyCount < 3)
                return false;
            NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
            uint32 canHeroicCount = 0;
            for (Unit* player : friends)
            {
                if (!player->HasAura(ShamanFlag_NoHeroic))
                    ++canHeroicCount;
            }
            if (canHeroicCount > 3 && TryCastSpell(ShamanAssist_Heroic, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else if (TryCastSpell(ShamanAssist_Heroic, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool BotShamanAI::ProcessArenaHealthMember()
{
    if (!me->InArena())
        return false;
    if (GetManaPowerPer() < 10)
        return false;
    float minLife = 100;
    Unit* minLifeUnit = NULL;
    NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
    for (Unit* pUnit : friends)
    {
        float healPct = pUnit->GetHealthPct();
        if (healPct > 50)
            continue;
        if (minLifeUnit == NULL || healPct < minLife)
        {
            minLife = healPct;
            minLifeUnit = pUnit;
        }
    }
    if (minLifeUnit)
    {
        ProcessHealthSpell(minLifeUnit);
        return true;
    }
    return false;
}

bool BotShamanAI::CastingControlCommandSpell()
{
    if (m_LastControlTarget == ObjectGuid::Empty || !ShamanAssist_Frog)
        return false;
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        return false;
    Spell* pCurrentSpell = me->GetCurrentSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
    if (pCurrentSpell)
    {
        if (pCurrentSpell->m_spellInfo && pCurrentSpell->m_spellInfo->Id == ShamanAssist_Frog)
        {
            return pCurrentSpell->m_targets.GetUnitTargetGUID() == m_LastControlTarget;
        }
    }
    if (!pCurrentSpell)
    {
        pCurrentSpell = me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
        if (pCurrentSpell && pCurrentSpell->m_spellInfo && pCurrentSpell->m_spellInfo->Id == ShamanAssist_Frog)
        {
            return pCurrentSpell->m_targets.GetUnitTargetGUID() == m_LastControlTarget;
        }
    }
    return false;
}

bool BotShamanAI::TryStartControlCommand()
{
    if (m_CruxControlTarget == ObjectGuid::Empty)
        return false;
    if (!ShamanAssist_Frog)
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    Player* pTarget = ObjectAccessor::FindPlayer(m_CruxControlTarget);
    if (!pTarget || !TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT) || !pTarget->IsAlive() || TargetIsControl(pTarget))
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        Player* pPlayer = pUnit->ToPlayer();
        if (!pPlayer)
            continue;
        if (BotBGAI* pAI = dynamic_cast<BotBGAI*>(pPlayer))
        {
            if (pAI->CastingControlCommandSpell())
            {
                m_CruxControlTarget = ObjectGuid::Empty;
                return false;
            }
        }
    }
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ShamanAssist_Frog,DIFFICULTY_40);//DIFFICULTY_40 //I DID
    if (!spellInfo || spellInfo->IsPassive())
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }/*
    if (me->GetGlobalCooldownMgr().HasGlobalCooldown(spellInfo))
        return true;
    if (!me->HasSpellCooldown(spellInfo->Id))
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }*/

    if (me->IsWithinLOSInMap(pTarget) && me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
    {
        m_Movement->ClearMovement();
        TryCastSpell(ShamanAssist_Frog, pTarget);
    }
    else
    {
        if (!IsNotMovement())
            m_Movement->MovementTo(m_CruxControlTarget);
    }
    return true;
}

float BotShamanAI::TryPushControlCommand(Player* pTarget)
{
    if (!pTarget || !pTarget->IsAlive() || !pTarget->IsInWorld() || me->GetMap() != pTarget->GetMap())
    {
        ClearCruxControlCommand();
        return -1;
    }
    if (!ShamanAssist_Frog)
        return -1;
    if (!TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT))
        return -1;
    if (!BotUtility::SpellHasReady(me, ShamanAssist_Frog))
        return -1;
    m_CruxControlTarget = pTarget->GetGUID();
    m_LastControlTarget = m_CruxControlTarget;
    return me->GetDistance(pTarget->GetPosition());
}

bool BotShamanAI::ProcessShield()
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

bool BotShamanAI::ProcessTotem()
{
    if (ShamanTotem_NonFear && (m_NonFearTotemTick + 5000 <= getMSTime()) && me->InArena())
    {
        bool needFearTotem = false;
        NearUnitVec friends = SearchFriend(BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pFriends : friends)
        {
            if (HasAuraMechanic(pFriends, Mechanics::MECHANIC_CHARM) || HasAuraMechanic(pFriends, Mechanics::MECHANIC_SLEEP) || HasAuraMechanic(pFriends, Mechanics::MECHANIC_FEAR))
            {
                needFearTotem = true;
                break;
            }
        }
        if (needFearTotem && ShamanTotem_NonFear && TryCastSpell(ShamanTotem_NonFear, me) == SpellCastResult::SPELL_CAST_OK)
        {
            m_NonFearTotemTick = getMSTime();
            return true;
        }
    }
    if (m_NonFearTotemTick == 0 || (m_NonFearTotemTick + 5000 <= getMSTime()))
    {
        if (m_NonFearTotemTick > 0 || !ExistTotemByType(PlayerTotemType::SUMMON_TYPE_TOTEM_EARTH, BOTAI_TOTEMRANGE))
        {
            if (TryCastSpell(ShamanTotem_DecMove, me) == SpellCastResult::SPELL_CAST_OK)
            {
                m_NonFearTotemTick = 0;
                return true;
            }
        }
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

bool BotShamanAI::ExistTotemByType(PlayerTotemType totemType, float range)
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
        if (pTotem->m_Properties->Slot != int32(slotType))//int32
            continue;
        return true;
    }
    return false;
}

bool BotShamanAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool BotShamanAI::IsRangeBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool BotShamanAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool BotShamanAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool BotShamanAI::TargetIsSuppress(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISTRACT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH)/* ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_IMMUNE_SHIELD)*/)
        return true;
    return false;
}

bool BotShamanAI::TryRecycleTotem(ShamanTotemPattern pattern)
{
    if (pattern == ShamanTotemPattern::ShamanTP_None || m_CurrentPattern == pattern)
        return false;
    m_CurrentPattern = pattern;
    //if (CanCastSpell(ShamanTotem_Recycle, me) == SpellCastResult::SPELL_CAST_OK)
    //	return true;
    return false;
}
