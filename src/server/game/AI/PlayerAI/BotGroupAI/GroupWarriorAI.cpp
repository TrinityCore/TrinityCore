
#include "BotGroupClassAI.h"
#include "BotBGAIMovement.h"
#include "MovementPackets.h"

uint32 GroupWarriorAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

void GroupWarriorAI::ClearMechanicAura()
{
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN) || HasAuraMechanic(me, Mechanics::MECHANIC_FEAR);
    if (stun && TryCastSpell(WarriorCommon_ClearCtrl, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (root && TryCastSpell(WarriorRage_ReIntercept, me) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool GroupWarriorAI::NeedWaitSpecialSpell(uint32 diff)
{
    m_ChargeWaitTick -= diff;
    if (m_ChargeWaitTick < 0)
        m_ChargeWaitTick = 0;
    if (BotGroupAI::NeedWaitSpecialSpell(diff))
        return true;

    if (m_ChargeWaitTick > 0)
        return true;
    return false;
}

void GroupWarriorAI::UpdateTalentType()
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

void GroupWarriorAI::ResetBotAI()
{
    BotGroupAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);
}

uint32 GroupWarriorAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 4;
}

void GroupWarriorAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
}

void GroupWarriorAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    ProcessMeleeSpell(pTarget);
}

bool GroupWarriorAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    //if (m_BotTalentType == 2 && WarriorIDLE_AOEAddLife)
    //{
    //	TryCastSpell(WarriorIDLE_AOEAddLife, me);
    //}
    //else if (WarriorIDLE_AOEAddPower)
    //{
    //	TryCastSpell(WarriorIDLE_AOEAddPower, me);
    //}
    return TryUpMount();
}

void GroupWarriorAI::ProcessMeleeSpell(Unit* pTarget)
{
    UpdateWarriorPose();
    uint32 triggerRate = urand(0, 99);
    uint32 ragePer = GetRagePowerPer();
    float healthPct = me->GetHealthPct();
    if (ragePer < 5 && TryCastSpell(WarriorCommon_AddPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct <= 75.0f && TryCastSpell(WarriorCommon_PowerRelife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    uint32 targetMeCount = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size();
    if (ragePer >= 50)
    {
        if (targetMeCount > 3)
        {
            if (!me->HasAura(WarriorCommon_SweepAtt))
                TryCastSpell(WarriorCommon_AOEFear, pTarget);
        }
        else if (!me->HasAura(WarriorCommon_PowerAtt))
            TryCastSpell(WarriorCommon_PowerAtt, pTarget);
    }
    if (triggerRate > 85 && RangeEnemyListByNonAura(WarriorCommon_AOEDecPower, NEEDFLEE_CHECKRANGE).size() >= 2 && TryCastSpell(WarriorCommon_AOEDecPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFullAttack(pTarget))
        return;
    if (ProcessBackStorm())
        return;
    //if (targetMeCount >= 3 && TryCastSpell(WarriorCommon_AOEFear, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessWeaponMeleeSpell(pTarget);
        break;
    case 1:
        ProcessRageMeleeSpell(pTarget);
        break;
    case 2:
        if (targetMeCount >= 2)
        {
            if (healthPct <= 20 && TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (healthPct <= 20 && TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        ProcessDefanceMeleeSpell(pTarget);
        break;
    }
}

void GroupWarriorAI::ProcessRangeSpell(Unit* pTarget)
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

    if (m_BotTalentType == 1 && TryCastSpell(WarriorRage_Intercept, pTarget) == SpellCastResult::SPELL_CAST_OK)
    {
        OnCastCharge(pTarget);
        return;
    }
    if (TryCastSpell(WarriorWeapon_HighThrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorCommon_PowerThrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 75.0f && TryCastSpell(WarriorCommon_PowerRelife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && WarriorIDLE_AOEAddLife && !me->HasAura(WarriorIDLE_AOEAddLife) && TryCastSpell(WarriorIDLE_AOEAddLife, me))
        return;
    if (m_BotTalentType != 2 && WarriorIDLE_AOEAddPower && !me->HasAura(WarriorIDLE_AOEAddPower) && TryCastSpell(WarriorIDLE_AOEAddPower, me))
        return;
    if (pTarget && ProcessPullSpell(pTarget))
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

bool GroupWarriorAI::ProcessPullSpell(Unit* pTarget)
{
    if (m_BotTalentType != 2)
        return false;
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
        return false;
    if (BotGroupAI::PVE_PULL)
    {
        if (WarriorDefance_Pull && TryCastPullSpell(WarriorDefance_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (WarriorDefance_Pull && TryCastSpell(WarriorDefance_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

void GroupWarriorAI::ProcessFlee()
{
    //Unit* pTarget = me->GetSelectedUnit();
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
    NearUnitVec range8Players = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    //if (range8Players.size() >= 2 && TryCastSpell(WarriorCommon_AOEFear, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (m_BotTalentType == 2 && range8Players.size() >= 2)
    {
        float healthPct = me->GetHealthPct();
        if (healthPct <= 20 && TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct <= 20 && TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void GroupWarriorAI::UpdateWarriorPose()
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

void GroupWarriorAI::ProcessWeaponMeleeSpell(Unit* pTarget)
{
    uint32 ragePer = GetRagePowerPer();
    if (TryCastSpell(WarriorWeaponRage_WinAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarriorRage_HeadAtt && pTarget->HasUnitState(UNIT_STATE_CASTING) && BotUtility::SpellHasReady(me, WarriorRage_HeadAtt))
    {
        if (!me->HasAura(WarriorRage_Status))
            me->CastSpell(me, WarriorRage_Status, true);
        if (TryCastSpell(WarriorRage_HeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TryCastSpell(WarriorWeapon_DeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeapon_Suppress, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(WarriorWeaponRage_FullKill, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (!pTarget->HasAura(WarriorWeaponRage_Backfillet) && TryCastSpell(WarriorWeaponRage_Backfillet, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    if (!pTarget->HasAura(WarriorWeaponDefance_Bleed, me->GetGUID()) && TryCastSpell(WarriorWeaponDefance_Bleed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 30 && RangeEnemyListByNonAura(WarriorWeaponDefance_AOEAtt, NEEDFLEE_CHECKRANGE).size() >= 2 && TryCastSpell(WarriorWeaponDefance_AOEAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool GroupWarriorAI::ProcessBackStorm()
{
    if (!WarriorWeapon_Backstorm || !BotUtility::SpellHasReady(me, WarriorWeapon_Backstorm))
        return false;
    uint32 targetMeEnemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size();
    if (targetMeEnemys <= 2)
        return false;
    if (!me->HasAura(WarriorWeapon_Status))
        me->CastSpell(me, WarriorWeapon_Status, true);
    TryCastSpell(WarriorWeapon_Backstorm, me);
    return true;
}

void GroupWarriorAI::ProcessWeaponRangeSpell(Unit* /*pTarget*/)
{
}

void GroupWarriorAI::ProcessRageMeleeSpell(Unit* pTarget)
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
    if (WarriorRage_Harsh && RangeEnemyListByNonAura(WarriorRage_Harsh, NEEDFLEE_CHECKRANGE).size() >= 2 && TryCastSpell(WarriorRage_Harsh, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (!pTarget->HasAura(WarriorWeaponRage_Backfillet) && TryCastSpell(WarriorWeaponRage_Backfillet, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    NearUnitVec playerVec8Range = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    if (playerVec8Range.size() >= 2 && TryCastSpell(WarriorRage_Whirlwind, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupWarriorAI::ProcessRageRangeSpell(Unit* /*pTarget*/)
{
}

void GroupWarriorAI::ProcessDefanceMeleeSpell(Unit* pTarget)
{
    uint32 ragePer = GetRagePowerPer();
    float healthPct = me->GetHealthPct();
    if (healthPct <= 25 && TryCastSpell(WarriorDefance_MaxLife, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->HasUnitState(UNIT_STATE_CASTING) && TryCastSpell(WarriorWeaponDefance_ShieldHit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorWeaponDefance_Bleed, me->GetGUID()) && TryCastSpell(WarriorWeaponDefance_Bleed, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarriorDefance_ShieldAtt && TryCastSpell(WarriorDefance_ShieldAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarriorDefance_Fuchou && TryCastSpell(WarriorDefance_Fuchou, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarriorDefance_Disarm && TryCastSpell(WarriorDefance_Disarm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec range8Players = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (range8Players.size() >= 1 && TryCastSpell(WarriorDefance_ShieldBlock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (range8Players.size() >= 2 && TryCastSpell(WarriorDefance_AOEConk, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(WarriorDefance_Conk) && TryCastSpell(WarriorDefance_Conk, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct <= 25 && range8Players.size() >= 1 && TryCastSpell(WarriorDefance_ShiledWall, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 50 && range8Players.size() >= 1 && TryCastSpell(WarriorWeaponDefance_AOEAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ragePer >= 40 && TryCastSpell(WarriorDefance_HPojia, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    NearUnitVec range30Players = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (range30Players.size() >= 1 && WarriorWeaponDefance_SpellReflect)
    {
        //uint32 castCount = 0;
        for (Unit* rangePlayer : range30Players)
        {
            if (rangePlayer->HasUnitState(UNIT_STATE_CASTING))
            {
                if (TryCastSpell(WarriorWeaponDefance_SpellReflect, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
                break;
            }
        }
    }
}

void GroupWarriorAI::ProcessDefanceRangeSpell(Unit* /*pTarget*/)
{
}
bool GroupWarriorAI::ProcessFullAttack(Unit* pTarget)
{
    if (!pTarget)
        return false;
    NearUnitVec targetMeEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (WarriorRage_Needdead && targetMeEnemys.size() <= 1 && BotUtility::SpellHasReady(me, WarriorRage_Needdead))
    {
        if (!me->HasAura(WarriorRage_Status))
            me->CastSpell(me, WarriorRage_Status, true);
        if (TryCastSpell(WarriorRage_Needdead, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (WarriorRage_Impertinency && targetMeEnemys.empty() && BotUtility::SpellHasReady(me, WarriorRage_Impertinency))
    {
        if (!me->HasAura(WarriorRage_Status))
            me->CastSpell(me, WarriorRage_Status, true);
        if (TryCastSpell(WarriorRage_Impertinency, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void GroupWarriorAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    //me->AttackStop();
    //m_ChargeWaitTick = 1500;
    me->StopMoving();
    float rndOffset = 2.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    //me->GetMap()->GetHeight(me->GetPhaseMask(), posX, posY, posZ);
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);
    me->GetMotionMaster()->MoveCharge(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), SPEED_CHARGE);

    //WorldSession* pSession = me->GetSession();
   /* WorldPacket opcode(2);
    opcode.appendPackGUID(me->GetGUID().GetRawValue());*/
    /*opcode << uint32(0);
    opcode << uint32(100);*/
    //pSession->HandleMoveTeleportAck(opcode);
    //m_Movement->SyncPosition(Position(posX, posY, posZ, me->GetOrientation()), true);
}

void GroupWarriorAI::UpEnergy()
{
    if (m_BotTalentType != 2)
    {
        uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
        uint32 power = me->GetPower(Powers::POWER_RAGE);
        me->SetPower(Powers::POWER_RAGE, (max / 100) + power);
    }
}

bool GroupWarriorAI::IsTankBotAI()
{
    return (m_BotTalentType == 2);
}

bool GroupWarriorAI::TryBlockCastingByTarget(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (m_BotTalentType == 1 && WarriorRage_HeadAtt && TryCastSpell(WarriorRage_HeadAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (m_BotTalentType == 2 && WarriorWeaponDefance_ShieldHit && TryCastSpell(WarriorWeaponDefance_ShieldHit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}
