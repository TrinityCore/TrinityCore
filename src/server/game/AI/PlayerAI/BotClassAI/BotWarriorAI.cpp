
#include "BotWarriorAI.h"
#include "Group.h"

uint32 BotWarriorAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

void BotWarriorAI::EachTick()
{
    BotBGAI::EachTick();
    if (!me->IsInCombat())
        return;
    if (me->InArena())
    {
        Group* pGroup = me->GetGroup();
        if (pGroup)
        {
            m_NeedPuniness = 0;
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || me->GetMap() != player->GetMap() || !player->IsInWorld() || player->IsPlayerBot())
                    continue;
                m_NeedPuniness = 1;
                break;
            }
        }
        else
            return;
    }
    else
    {
        uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
        uint32 power = me->GetPower(Powers::POWER_RAGE);
        me->SetPower(Powers::POWER_RAGE, (max / 100) + power);
        return;
    }
    if (m_NeedPuniness == 0)
    {
        uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
        uint32 power = me->GetPower(Powers::POWER_RAGE);
        me->SetPower(Powers::POWER_RAGE, (max / 100) + power);
    }
    else if (m_NeedPuniness > 0)
    {
        uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
        uint32 power = me->GetPower(Powers::POWER_RAGE);
        if (power > (max / 120))
            power -= (max / 120);
        else
            power = 0;
        me->SetPower(Powers::POWER_RAGE, power);
        WarriorCommon_AddPower = 0;
        WarriorWeapon_Suppress = 0;
        WarriorWeaponRage_FullKill = 0;
        WarriorRage_Impertinency = 0;
        WarriorRage_HeadAtt = 0;
    }
}

void BotWarriorAI::ClearMechanicAura()
{
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN) || HasAuraMechanic(me, Mechanics::MECHANIC_FEAR);
    if (stun && TryCastSpell(WarriorCommon_ClearCtrl, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (root && TryCastSpell(WarriorRage_ReIntercept, me) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool BotWarriorAI::NeedWaitSpecialSpell(uint32 diff)
{
    m_ChargeWaitTick -= diff;
    if (m_ChargeWaitTick < 0)
        m_ChargeWaitTick = 0;
    if (BotBGAI::NeedWaitSpecialSpell(diff))
        return true;

    if (m_ChargeWaitTick > 0)
        return true;
    return false;
}

void BotWarriorAI::InitializeSpells()
{
    WarriorIDLE_AOEAddLife = FindMaxRankSpellByExist(45517);
    WarriorIDLE_AOEAddPower = FindMaxRankSpellByExist(27578);
    WarriorWeapon_Status = FindMaxRankSpellByExist(122990);
    WarriorDefance_Status = FindMaxRankSpellByExist(71);
    WarriorRage_Status = FindMaxRankSpellByExist(122989);
    WarriorCommon_PowerAtt = FindMaxRankSpellByExist(25712);
    WarriorCommon_PowerThrow = FindMaxRankSpellByExist(57755);
    WarriorCommon_PowerRelife = FindMaxRankSpellByExist(184364);
    WarriorCommon_ClearCtrl = FindMaxRankSpellByExist(18499);
    WarriorCommon_AOEFear = FindMaxRankSpellByExist(65930);
    WarriorCommon_SweepAtt = FindMaxRankSpellByExist(231833);
    WarriorCommon_AddPower = FindMaxRankSpellByExist(173401);
    WarriorCommon_AOEDecPower = FindMaxRankSpellByExist(27579);
    WarriorDefance_HPojia = FindMaxRankSpellByExist(186688);
    WarriorDefance_Fuchou = FindMaxRankSpellByExist(40392);
    WarriorDefance_ShieldBlock = FindMaxRankSpellByExist(38031);
    WarriorDefance_ShieldAtt = FindMaxRankSpellByExist(23922);
    WarriorDefance_Pojia = FindMaxRankSpellByExist(25051);
    WarriorDefance_MaxLife = FindMaxRankSpellByExist(12975);
    WarriorDefance_ShiledWall = FindMaxRankSpellByExist(871);
    WarriorDefance_Disarm = FindMaxRankSpellByExist(11879);
    WarriorDefance_Support = FindMaxRankSpellByExist(41198);
    WarriorDefance_Conk = FindMaxRankSpellByExist(22427);
    WarriorDefance_AOEConk = FindMaxRankSpellByExist(46968);
    WarriorWeaponDefance_AOEAtt = FindMaxRankSpellByExist(165749);
    WarriorWeaponDefance_Bleed = FindMaxRankSpellByExist(43931);
    WarriorWeaponDefance_SpellReflect = FindMaxRankSpellByExist(57643);
    WarriorWeaponDefance_ShieldHit = FindMaxRankSpellByExist(149383);
    WarriorWeapon_SwordStorm = FindMaxRankSpellByExist(9632);
    WarriorWeapon_HighThrow = FindMaxRankSpellByExist(65940);
    WarriorWeapon_Charge = FindMaxRankSpellByExist(100);
    WarriorWeapon_Suppress = FindMaxRankSpellByExist(7384);
    WarriorWeapon_Backstorm = FindMaxRankSpellByExist(22857);
    WarriorWeapon_DeadAtt = FindMaxRankSpellByExist(27580);
    WarriorWeaponRage_FullKill = FindMaxRankSpellByExist(5308);
    WarriorWeaponRage_WinAttack = FindMaxRankSpellByExist(34428);
    WarriorWeaponRage_Backfillet = FindMaxRankSpellByExist(1715);
    WarriorRage_Harsh = FindMaxRankSpellByExist(12323);
    WarriorRage_HeadAtt = FindMaxRankSpellByExist(6552);
    WarriorRage_Intercept = FindMaxRankSpellByExist(20615);
    WarriorRage_Whirlwind = FindMaxRankSpellByExist(12950);
    WarriorRage_Impertinency = FindMaxRankSpellByExist(13847);
    WarriorRage_Needdead = FindMaxRankSpellByExist(199261);
    WarriorRage_Bloodthirsty = FindMaxRankSpellByExist(39071);
    WarriorRage_ReIntercept = FindMaxRankSpellByExist(184364);
}

void BotWarriorAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
    //Item* pMainHandItem = me->GetItemByPos(255, EquipmentSlots::EQUIPMENT_SLOT_MAINHAND);
    //Item* pOffHandItem = me->GetItemByPos(255, EquipmentSlots::EQUIPMENT_SLOT_OFFHAND);
    //if (!pMainHandItem)
    //{
    //	m_BotTalentType = 1;
    //}
    //else
    //{
    //	if (pMainHandItem->GetTemplate()->InventoryType == InventoryType::INVTYPE_2HWEAPON)
    //		m_BotTalentType = 0;
    //	else if (pOffHandItem->GetTemplate()->InventoryType == InventoryType::INVTYPE_SHIELD)
    //		m_BotTalentType = 2;
    //	else
    //		m_BotTalentType = 1;
    //}
}

void BotWarriorAI::ResetBotAI()
{
    BotBGAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells();
    m_IsIDLEBuff = false;
    if (WarriorWeapon_SwordStorm == 0 && m_BotTalentType == 0 && me->getLevel() == 80)
    {
        me->LearnSpell(46924, false);
        WarriorWeapon_SwordStorm = FindMaxRankSpellByExist(46924);
    }
    m_NeedPuniness = -1;
}

void BotWarriorAI::ProcessReady()
{
    if (m_IsIDLEBuff)
        return;
    if (m_BotTalentType == 2 && WarriorIDLE_AOEAddLife)
    {
        m_IsIDLEBuff = true;
        if (!me->HasAura(WarriorIDLE_AOEAddLife))
            TryCastSpell(WarriorIDLE_AOEAddLife, me);
    }
    else if (WarriorIDLE_AOEAddPower)
    {
        m_IsIDLEBuff = true;
        if (!me->HasAura(WarriorIDLE_AOEAddPower))
            TryCastSpell(WarriorIDLE_AOEAddPower, me);
    }
}

bool BotWarriorAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return TryUpMount();
}

void BotWarriorAI::ProcessMeleeSpell(Unit* pTarget)
{
    UpdateWarriorPose();
    uint32 triggerRate = urand(0, 99);
    uint32 ragePer = GetRagePowerPer();
    if (ragePer < 5 && TryCastSpell(WarriorCommon_AddPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 75.0f && TryCastSpell(WarriorCommon_PowerRelife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 75 && !me->HasAura(WarriorCommon_PowerAtt))
        TryCastSpell(WarriorCommon_PowerAtt, pTarget);
    if (triggerRate > 85 && RangeEnemyListByNonAura(WarriorCommon_AOEDecPower, NEEDFLEE_CHECKRANGE).size() >= 2 && TryCastSpell(WarriorCommon_AOEDecPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFullAttack(pTarget))
        return;
    if (RangeEnemyListByTargetIsMe(8.0f).size() >= 3 && TryCastSpell(WarriorCommon_AOEFear, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessWeaponMeleeSpell(pTarget);
        break;
    case 1:
        ProcessRageMeleeSpell(pTarget);
        break;
    case 2:
        ProcessDefanceMeleeSpell(pTarget);
        break;
    }
}

void BotWarriorAI::ProcessRangeSpell(Unit* pTarget)
{
    if (me->GetDistance(pTarget) > 9)
    {
        if (m_BotTalentType == 2)
        {
            if (BotUtility::SpellHasReady(me, WarriorWeapon_Charge) && TryCastSpell(WarriorWeapon_Charge, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pTarget);
                return;
            }
            if (BotUtility::SpellHasReady(me, WarriorRage_Intercept) && TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pTarget);
                return;
            }
        }
        else if (m_BotTalentType == 0)
        {
            if (BotUtility::SpellHasReady(me, WarriorWeapon_Charge))
            {
                if (!me->HasAura(WarriorWeapon_Status))
                    me->CastSpell(me, WarriorWeapon_Status, true);
                if (TryCastSpell(WarriorWeapon_Charge, pTarget) == SpellCastResult::SPELL_CAST_OK)
                {
                    OnCastCharge(pTarget);
                    return;
                }
            }
            if (BotUtility::SpellHasReady(me, WarriorRage_Intercept))
            {
                if (!me->HasAura(WarriorRage_Status))
                    me->CastSpell(me, WarriorRage_Status, true);
                if (TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
                {
                    OnCastCharge(pTarget);
                    return;
                }
            }
        }
        else
        {
            if (BotUtility::SpellHasReady(me, WarriorRage_Intercept) && TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pTarget);
                return;
            }
        }
    }
    UpdateWarriorPose();
    if (IsInvincible(pTarget) && TryCastSpell(WarriorWeapon_HighThrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (IsNotMovement() && TryCastSpell(WarriorCommon_PowerThrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 75.0f && TryCastSpell(WarriorCommon_PowerRelife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && WarriorIDLE_AOEAddLife && !me->HasAura(WarriorIDLE_AOEAddLife) && TryCastSpell(WarriorIDLE_AOEAddLife, me))
        return;
    if (m_BotTalentType != 2 && WarriorIDLE_AOEAddPower && !me->HasAura(WarriorIDLE_AOEAddPower) && TryCastSpell(WarriorIDLE_AOEAddPower, me))
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessWeaponRangeSpell(pTarget);
        break;
    case 1:
        ProcessRageRangeSpell(pTarget);
        break;
    case 2:
        ProcessDefanceRangeSpell(pTarget);
        break;
    }
}

void BotWarriorAI::ProcessFlee()
{
    NearPlayerVec farFriends = SearchFarFriend(12, BOTAI_RANGESPELL_DISTANCE, false);
    if (!farFriends.empty())
    {
        if (me->HasAura(WarriorDefance_Status) && WarriorDefance_Support)
        {
            Player* farFriend = farFriends[urand(0, farFriends.size() - 1)];
            if (TryCastSpell(WarriorDefance_Support, farFriend) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(farFriend);
                return;
            }
        }
    }
    FleeMovement();
    float healthPct = me->GetHealthPct();
    NearUnitVec range8Players = RangeEnemyListByTargetIsMe(8.0f);
    Unit* pTarget = me->GetSelectedUnit();
    if (range8Players.size() >= 2 && TryCastSpell(WarriorCommon_AOEFear, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2)
    {
        if (healthPct <= 20.0f && TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct <= 20 && range8Players.size() >= 2 && TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void BotWarriorAI::UpdateWarriorPose()
{
    if (!me->IsInCombat())
    {
        if (!me->HasAura(WarriorWeapon_Status))
            me->CastSpell(me, WarriorWeapon_Status, true);
    }
    else
    {
        switch (m_BotTalentType)
        {
        case 0:
            if (!me->HasAura(WarriorWeapon_Status))
                me->CastSpell(me, WarriorWeapon_Status, true);
            break;
        case 1:
            if (!me->HasAura(WarriorRage_Status))
                me->CastSpell(me, WarriorRage_Status, true);
            break;
        case 2:
            if (!me->HasAura(WarriorDefance_Status))
                me->CastSpell(me, WarriorDefance_Status, true);
            break;
        }
    }
}

void BotWarriorAI::ProcessWeaponMeleeSpell(Unit* pTarget)
{
    uint32 ragePer = GetRagePowerPer();
    if (TryCastSpell(WarriorWeaponRage_WinAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetIsMe(7.0f).size() > 1 && TryCastSpell(WarriorWeapon_Backstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponRage_Backfillet) && TryCastSpell(WarriorWeaponRage_Backfillet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeapon_DeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeapon_Suppress, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeaponRage_FullKill, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarriorWeapon_SwordStorm && me->getLevel() == 80 && RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(WarriorWeapon_SwordStorm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pTarget->HasAura(WarriorWeaponDefance_Bleed, me->GetGUID()) && TryCastSpell(WarriorWeaponDefance_Bleed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 30 && RangeEnemyListByNonAura(WarriorWeaponDefance_AOEAtt, 5.0f).size() >= 2 && TryCastSpell(WarriorWeaponDefance_AOEAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotWarriorAI::ProcessWeaponRangeSpell(Unit* /*pTarget*/)
{
}

void BotWarriorAI::ProcessRageMeleeSpell(Unit* pTarget)
{
    //uint32 ragePer = GetRagePowerPer();
    if (TryCastSpell(WarriorWeaponRage_WinAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(WarriorRage_HeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorRage_Bloodthirsty, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeaponRage_FullKill, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByNonAura(WarriorRage_Harsh, 8.0f).size() >= 2 && TryCastSpell(WarriorRage_Harsh, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponRage_Backfillet) && TryCastSpell(WarriorWeaponRage_Backfillet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec playerVec8Range = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    if (playerVec8Range.size() > 1 && TryCastSpell(WarriorRage_Whirlwind, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotWarriorAI::ProcessRageRangeSpell(Unit* /*pTarget*/)
{
}

void BotWarriorAI::ProcessDefanceMeleeSpell(Unit* pTarget)
{
    uint32 ragePer = GetRagePowerPer();
    float healthPct = me->GetHealthPct();
    if (healthPct <= 10.0f && TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(WarriorWeaponDefance_ShieldHit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TargetIsMelee(pTarget->ToPlayer()) && !pTarget->HasAura(WarriorDefance_Disarm) && TryCastSpell(WarriorDefance_Disarm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponDefance_Bleed, me->GetGUID()) && TryCastSpell(WarriorWeaponDefance_Bleed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorDefance_ShieldAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorDefance_Fuchou, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec range8Players = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (range8Players.size() >= 2 && TryCastSpell(WarriorDefance_ShieldBlock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (range8Players.size() >= 2 && TryCastSpell(WarriorDefance_AOEConk, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorDefance_Conk) && TryCastSpell(WarriorDefance_Conk, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct <= 20 && range8Players.size() >= 2 && TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 30 && range8Players.size() >= 2 && TryCastSpell(WarriorWeaponDefance_AOEAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 40 && TryCastSpell(WarriorDefance_HPojia, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec range30Players = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (range30Players.size() >= 3 && WarriorWeaponDefance_SpellReflect)
    {
        uint32 castCount = 0;
        for (Unit* rangePlayer : range30Players)
        {
            if (rangePlayer->HasUnitState(UNIT_STATE_CASTING))
                ++castCount;
            if (castCount >= 2)
                break;
        }
        if (castCount >= 2 && TryCastSpell(WarriorWeaponDefance_SpellReflect, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void BotWarriorAI::ProcessDefanceRangeSpell(Unit* /*pTarget*/)
{
}

bool BotWarriorAI::ProcessSurviveSpell()
{
    if (m_BotTalentType == 2)
    {
        float healthPct = me->GetHealthPct();
        if (healthPct < 19)
        {
            if (!me->HasAura(WarriorDefance_Status))
                me->CastSpell(me, WarriorDefance_Status, true);
            if (TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool BotWarriorAI::ProcessFullAttack(Unit* pTarget)
{
    if (!pTarget)
        return false;
    NearUnitVec targetMeEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (targetMeEnemys.size() <= 1 && BotUtility::SpellHasReady(me, WarriorRage_Needdead))
    {
        if (!me->HasAura(WarriorRage_Status))
            me->CastSpell(me, WarriorRage_Status, true);
        if (TryCastSpell(WarriorRage_Needdead, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (targetMeEnemys.empty() && BotUtility::SpellHasReady(me, WarriorRage_Impertinency))
    {
        if (!me->HasAura(WarriorRage_Status))
            me->CastSpell(me, WarriorRage_Status, true);
        if (TryCastSpell(WarriorRage_Impertinency, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void BotWarriorAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    //me->AttackStop();
    //m_ChargeWaitTick = 2000;
    me->StopMoving();
    float rndOffset = 3.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    //me->GetMap()->GetHeight(me->GetPhaseMask(), posX, posY, posZ);
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);
    //me->GetMotionMaster()->MoveCharge(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), SPEED_CHARGE);
}
