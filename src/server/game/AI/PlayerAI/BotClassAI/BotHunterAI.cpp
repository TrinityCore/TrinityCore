
#include "BotHunterAI.h"
#include "PlayerBotSession.h"
#include "Pet.h"
#include "BotBGAIMovement.h"

void BotHunterAI::InitializeSpells()
{
    HunterIDLE_SummonPet = FindMaxRankSpellByExist(23498);// 883			召唤宠物
    HunterIDLE_RevivePet = FindMaxRankSpellByExist(982);// 982			复活宠物
    HunterIDLE_ManaAura = FindMaxRankSpellByExist(210754);// 34074			攻击回蓝守护
    HunterIDLE_DodgeAura = FindMaxRankSpellByExist(210753);// 13163		闪躲守护
    HunterIDLE_EagleAura = FindMaxRankSpellByExist(231555);// 27044		射击守护
    HunterIDLE_DragonAura = FindMaxRankSpellByExist(210752);// 61847		龙鹰守护 射击和闪躲守护
    HunterIDLE_ShotAura = FindMaxRankSpellByExist(31519);// 19506			强击光环(射击系)

    //uint32 HunterTrap_FarFrozen = FindMaxRankSpellByExist(209789);// 60192		远程冰冻陷阱
    //uint32 HunterTrap_Frozen = FindMaxRankSpellByExist(43447);// 14311			冰冻陷阱
    //uint32 HunterTrap_Ice = FindMaxRankSpellByExist(165769);// 13809				冰霜陷阱
    //uint32 HunterTrap_Viper = FindMaxRankSpellByExist(43449);// 34600			毒蛇陷阱
    //uint32 HunterTrap_Explode = FindMaxRankSpellByExist(43444);// 49067			爆炸陷阱
    //uint32 HunterTrap_Fire = FindMaxRankSpellByExist(155623);// 49056				火焰陷阱
    //uint32 HunterTrap_Shot = FindMaxRankSpellByExist(80003);// 63672				黑浊箭(生存系)

    //uint32 HunterAssist_ClearRoot = FindMaxRankSpellByExist(53271);// 53271		移除定身
    //uint32 HunterAssist_PetCommand = FindMaxRankSpellByExist(205440);// 34026		宠物杀截
    //uint32 HunterAssist_HealPet = FindMaxRankSpellByExist(37381);// 48990		宠物治疗
    //uint32 HunterAssist_PetStun = FindMaxRankSpellByExist(7093);// 19577		宠物击晕目标(野兽系)
    //uint32 HunterAssist_PetRage = FindMaxRankSpellByExist(19574);// 19574		宠物和自己狂暴(野兽系)
    //uint32 HunterAssist_Stamp = FindMaxRankSpellByExist(1130);// 53338			猎人印记
    //uint32 HunterAssist_FalseDead = FindMaxRankSpellByExist(5384);// 5384		假死
    //uint32 HunterAssist_BackJump = FindMaxRankSpellByExist(781);// 781			后跳
    //uint32 HunterAssist_FastSpeed = FindMaxRankSpellByExist(3045);// 3045		急速射击BUF
    //uint32 HunterAssist_ReadyCD = FindMaxRankSpellByExist(203551);// 23989		准备就绪CD(射击系)

    //uint32 HunterMelee_BackRoot = FindMaxRankSpellByExist(116599);// 48999		招架后反击定身(生存系)
    //uint32 HunterMelee_NoDamage = FindMaxRankSpellByExist(31567);// 19263		威慑 无法攻击
    //uint32 HunterMelee_DecSpeed = FindMaxRankSpellByExist(195645);// 2974			摔拌 近战减移动速
    //uint32 HunterMelee_NextAtt = FindMaxRankSpellByExist(31566);// 48996			next近战攻击加强
    //uint32 HunterMelee_MeleeAtt = FindMaxRankSpellByExist(190928);// 53339		近战攻击

    HunterDebug_Damage = FindMaxRankSpellByExist(160503);
    HunterDebug_Mana = FindMaxRankSpellByExist(31407);
    HunterDebug_Sleep = FindMaxRankSpellByExist(19386);

    HunterShot_AOEShot = FindMaxRankSpellByExist(22908);
    HunterShot_CharmShot = FindMaxRankSpellByExist(23601);
    HunterShot_Explode = FindMaxRankSpellByExist(15495);
    HunterShot_Aim = FindMaxRankSpellByExist(48871);
    HunterShot_Silence = FindMaxRankSpellByExist(248919);
    HunterShot_Shock = FindMaxRankSpellByExist(5116);
    HunterShot_Cast = FindMaxRankSpellByExist(65867);
    HunterShot_MgcShot = FindMaxRankSpellByExist(69989);
    HunterShot_KillShot = FindMaxRankSpellByExist(69989);
    HunterShot_MulShot = FindMaxRankSpellByExist(2643);
    HunterShot_QMLShot = FindMaxRankSpellByExist(53209);
}

void BotHunterAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotHunterAI::ResetBotAI()
{
    BotBGAI::ResetBotAI();
    m_IsSupplemented = false;
    m_IsReviveManaModel = false;
    UpdateTalentType();
    InitializeSpells();
    if (Pet* pet = me->GetPet())
        pet->GetPetAutoSpellOnPos(true);//SettingAllSpellAutocast
    if (HunterShot_QMLShot == 0 && m_BotTalentType == 1 && me->getLevel() == 80)
    {
        me->LearnSpell(53209, false);
        HunterShot_QMLShot = FindMaxRankSpellByExist(53209);
    }
}

uint32 BotHunterAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool BotHunterAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
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

void BotHunterAI::ProcessReady()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (!m_IsSupplemented)
    {
        m_IsSupplemented = true;
        //me->SupplementAmmo();
        return;
    }
    if (me->GetPetGUID().IsEmpty())
    {
        TC_LOG_INFO("BotHunterAI.cpp", "Hunter Ai check pet, is no pet!");//"BotHunterAI.cpp" is LOG_FILTER_GENERAL before,I did.
        PlayerBotSetting::CheckHunterPet(me);
        return;
    }
    ProcessNormalSpell();
}

void BotHunterAI::ProcessFlee()
{
    FleeMovement();

    Unit* pSelectTarget = me->GetSelectedUnit();
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.empty())
        return;
    if (!pSelectTarget && !enemys.empty())
        pSelectTarget = enemys[urand(0, enemys.size() - 1)];
    if (!pSelectTarget)
        return;
    Pet* pPet = me->GetPet();
    if (TargetIsSuppress(pSelectTarget))
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
        if (pPetTarget && pPetTarget != pSelectTarget)
            PetAction(pPet, pSelectTarget);
    }

    if (enemys.size() > 1 && TryCastSpell(HunterTrap_Ice, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    else if (TryCastSpell(HunterTrap_Frozen, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessAura(true))
        return;
    if (enemys.size() > 1 && TryCastSpell(HunterMelee_NoDamage, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    bool hasRoot = HasRootMechanic();
    if (hasRoot && HunterAssist_ClearRoot && TryCastSpell(HunterAssist_ClearRoot, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (enemys.size() > 1 && TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    Unit* pCastEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pCastEnemy)
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (m_BotTalentType == 0)
    {
        if (hasRoot && HunterAssist_PetRage && TryCastSpell(HunterAssist_PetRage, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(HunterAssist_PetStun, pSelectTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (CastMeleeSpell(pSelectTarget))
        return;
    if (CastRangeSpell(pSelectTarget))
        return;
    if (me->InArena())
    {
        uint32 minLifePct = 100;
        Unit* pMinUnit = NULL;
        Unit* pMeleeUnit = NULL;
        NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pUnit : enemys)
        {
            if (pUnit == pSelectTarget || TargetIsSuppress(pUnit))
                continue;
            float dist = me->GetDistance(pUnit->GetPosition());
            if (dist <= 9)
            {
                if (dist < 7)
                    pMeleeUnit = pUnit;
                continue;
            }
            uint32 lifePct = uint32(pUnit->GetHealthPct());
            if (!pMinUnit || lifePct < minLifePct)
            {
                pMinUnit = pUnit;
                minLifePct = lifePct;
            }
        }
        if (pMinUnit && CastRangeSpell(pMinUnit))
            return;
        if (pMeleeUnit && CastMeleeSpell(pMeleeUnit))
            return;
    }
}

bool BotHunterAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    //if (me->GetPetGUID().IsEmpty() && CanCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
    //	return false;
    if (!me->HasAura(m_UseMountID))
    {
        Pet* pPet = me->GetPet();
        if (pPet && !pPet->IsAlive())
        {
            me->StopMoving();
            TryCastSpell(HunterIDLE_RevivePet, pPet);
            return true;
        }
        else if (pPet && pPet->GetHealthPct() < 85 && !pPet->HasAura(HunterAssist_HealPet))
        {
            if (TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        {
            return false;
        }
        PetAction(pPet, NULL);
    }
    if (me->HasAura(m_UseMountID))
        return false;
    if (m_BotTalentType == 1)
    {
        if (HunterIDLE_ShotAura && !me->HasAura(HunterIDLE_ShotAura) && TryCastSpell(HunterIDLE_ShotAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    if (HunterIDLE_DragonAura)
    {
        if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }
    else
    {
        if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me) == SpellCastResult::SPELL_CAST_OK)
            return false;
    }

    return TryUpMount();
}

void BotHunterAI::ProcessMeleeSpell(Unit* pTarget)
{
    CastMeleeSpell(pTarget);
    if (me->InArena())
    {
        uint32 minLifePct = 100;
        Unit* pMinUnit = NULL;
        NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pUnit : enemys)
        {
            if (pUnit == pTarget || TargetIsSuppress(pUnit))
                continue;
            if (me->GetDistance(pUnit->GetPosition()) <= 9)
                continue;
            uint32 lifePct = uint32(pUnit->GetHealthPct());
            if (!pMinUnit || lifePct < minLifePct)
            {
                pMinUnit = pUnit;
                minLifePct = lifePct;
            }
        }
        if (pMinUnit && CastRangeSpell(pMinUnit))
            return;
    }
}

void BotHunterAI::ProcessRangeSpell(Unit* pTarget)
{
    Pet* pPet = me->GetPet();
    if (!pPet && TryCastSpell(HunterIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    PetAction(pPet, pTarget);
    if (pPet && pPet->IsAlive())
    {
        if (pPet->GetHealthPct() < 70 && !pPet->HasAura(HunterAssist_HealPet) && TryCastSpell(HunterAssist_HealPet, pPet) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessAura(false))
        return;

    NearUnitVec selMeEnemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    if (selMeEnemys.size() > 0)
    {
        if (selMeEnemys.size() > 1 && TryCastSpell(HunterAssist_FalseDead, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        Unit* pRndPlayer = selMeEnemys[urand(0, selMeEnemys.size() - 1)];
        if (HunterTrap_FarFrozen && pRndPlayer != pTarget && !TargetIsSuppress(pRndPlayer) && TryCastSpell(HunterTrap_FarFrozen, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    Unit* pCastEnemy = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pCastEnemy)
    {
        if (m_BotTalentType == 1 && HunterShot_Silence && TryCastSpell(HunterShot_Silence, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (m_BotTalentType == 2 && HunterShot_CharmShot && TryCastSpell(HunterShot_CharmShot, pCastEnemy) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (!pTarget->HasAura(HunterAssist_Stamp) && TryCastSpell(HunterAssist_Stamp, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(HunterAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (CastRangeSpell(pTarget))
        return;
    if (me->InArena())
    {
        uint32 minLifePct = 100;
        Unit* pMinUnit = NULL;
        Unit* pMeleeUnit = NULL;
        NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pUnit : enemys)
        {
            if (pUnit == pTarget || TargetIsSuppress(pUnit))
                continue;
            float dist = me->GetDistance(pUnit->GetPosition());
            if (dist <= 9)
            {
                if (dist < 7)
                    pMeleeUnit = pUnit;
                continue;
            }
            uint32 lifePct = uint32(pUnit->GetHealthPct());
            if (!pMinUnit || lifePct < minLifePct)
            {
                pMinUnit = pUnit;
                minLifePct = lifePct;
            }
        }
        if (pMinUnit && CastRangeSpell(pMinUnit))
            return;
        if (pMeleeUnit && CastMeleeSpell(pMeleeUnit))
            return;
    }
}

bool BotHunterAI::ProcessAura(bool isFlee)
{
    if (HunterIDLE_ManaAura && CheckManaModel())
    {
        if (!me->HasAura(HunterIDLE_ManaAura) && TryCastSpell(HunterIDLE_ManaAura, me, true) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (HunterIDLE_DragonAura)
        {
            if (!me->HasAura(HunterIDLE_DragonAura) && TryCastSpell(HunterIDLE_DragonAura, me, true) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (isFlee)
            {
                if (!me->HasAura(HunterIDLE_DodgeAura) && TryCastSpell(HunterIDLE_DodgeAura, me, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
            else
            {
                if (!me->HasAura(HunterIDLE_EagleAura) && TryCastSpell(HunterIDLE_EagleAura, me, true) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }
    return false;
}

//bool BotHunterAI::TryStartControlCommand()
//{
//	if (m_CruxControlTarget == ObjectGuid::Empty)
//		return false;
//	if (!HunterTrap_FarFrozen)
//	{
//		m_CruxControlTarget = ObjectGuid::Empty;
//		return false;
//	}
//	Player* pTarget = ObjectAccessor::FindPlayer(m_CruxControlTarget);
//	if (!pTarget || !TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT) || !pTarget->IsAlive() || TargetIsControl(pTarget))
//	{
//		m_CruxControlTarget = ObjectGuid::Empty;
//		return false;
//	}
//	SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(HunterTrap_FarFrozen);
//	if (!spellInfo || spellInfo->IsPassive())
//	{
//		m_CruxControlTarget = ObjectGuid::Empty;
//		return false;
//	}
//	if (me->GetSpellHistory()->HasGlobalCooldown(spellInfo))
//		return true;
//	if (!me->GetSpellHistory()->IsReady(spellInfo))
//	{
//		m_CruxControlTarget = ObjectGuid::Empty;
//		return false;
//	}
//
//	if (me->IsWithinLOSInMap(pTarget) && me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
//	{
//		TryCastSpell(HunterTrap_FarFrozen, pTarget);
//	}
//	else
//	{
//		if (!IsNotMovement())
//			m_Movement->MovementTo(m_CruxControlTarget);
//	}
//	return true;
//}
//
//float BotHunterAI::TryPushControlCommand(Player* pTarget)
//{
//	if (!pTarget || !pTarget->IsAlive() || !pTarget->IsInWorld() || me->GetMap() != pTarget->GetMap())
//	{
//		ClearCruxControlCommand();
//		return -1;
//	}
//	if (!HunterTrap_FarFrozen)
//		return -1;
//	if (!TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT))
//		return -1;
//	if (!BotUtility::SpellHasReady(me, HunterTrap_FarFrozen))
//		return -1;
//	m_CruxControlTarget = pTarget->GetGUID();
//	m_LastControlTarget = m_CruxControlTarget;
//	return me->GetDistance(pTarget->GetPosition());
//}

bool BotHunterAI::CastRangeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (me->GetDistance(pTarget->GetPosition()) <= 9)
        return false;
    NearUnitVec targetRanges = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (targetRanges.size() > 5)
    {
        if (HunterShot_MulShot && TryCastSpell(HunterShot_MulShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (HunterShot_AOEShot && TryCastSpell(HunterShot_AOEShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    if (HunterShot_KillShot && pTarget->GetHealthPct() < 20 && TryCastSpell(HunterShot_KillShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (CheckManaModel())
    {
        if (!pTarget->HasAura(HunterDebug_Mana, me->GetGUID()) && !pTarget->HasAura(HunterDebug_Damage, me->GetGUID()) && TryCastSpell(HunterDebug_Mana, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (!pTarget->HasAura(HunterDebug_Mana, me->GetGUID()) && !pTarget->HasAura(HunterDebug_Damage, me->GetGUID()) && TryCastSpell(HunterDebug_Damage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (me->InArena() && TryCastSpell(HunterShot_MulShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (TryCastSpell(HunterAssist_FastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (TargetIsMelee(pTarget->ToPlayer()) && !pTarget->HasAura(HunterMelee_DecSpeed) && !pTarget->HasAura(HunterShot_Shock) && !TargetIsSuppress(pTarget))
    {
        if (TryCastSpell(HunterShot_Shock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterTrap_Shot && TryCastSpell(HunterTrap_Shot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (m_BotTalentType == 1 && HunterShot_Aim && TryCastSpell(HunterShot_Aim, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 1 && HunterShot_QMLShot && me->getLevel() == 80 && TryCastSpell(HunterShot_QMLShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterShot_Explode && TryCastSpell(HunterShot_Explode, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_MgcShot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (m_BotTalentType == 2 && HunterTrap_Shot && TryCastSpell(HunterTrap_Shot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_Cast, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool BotHunterAI::CastMeleeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (m_BotTalentType == 2 && HunterDebug_Sleep && TargetIsMelee(pTarget->ToPlayer()) && me->GetDistance(pTarget->GetPosition()) < 12)
    {
        if (!TargetIsSuppress(pTarget) && TryCastSpell(HunterDebug_Sleep, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (TargetIsMelee(pTarget->ToPlayer()) && !pTarget->HasAura(HunterMelee_DecSpeed) && !pTarget->HasAura(HunterShot_Shock) && !TargetIsSuppress(pTarget))
    {
        if (TryCastSpell(HunterMelee_DecSpeed, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(HunterShot_Shock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!me->HasAura(HunterMelee_NextAtt))
        TryCastSpell(HunterMelee_NextAtt, pTarget);
    if (TryCastSpell(HunterMelee_MeleeAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (m_BotTalentType == 2 && HunterMelee_BackRoot)
    {
        if (TryCastSpell(HunterMelee_BackRoot, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void BotHunterAI::PetAction(Pet* pPet, Unit* pTarget)
{
    Position pos;//I DID
    if (!pPet)
        return;
    if (pPet->GetVictim() == pTarget)
        return;
    WorldSession* pSession = me->GetSession();
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(), pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

bool BotHunterAI::HasRootMechanic()
{
    if (HasAuraMechanic(me, Mechanics::MECHANIC_CHARM) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_POLYMORPH) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_HORROR) ||
        HasAuraMechanic(me, Mechanics::MECHANIC_STUN))
        return true;
    return false;
}

bool BotHunterAI::TargetIsSuppress(Unit* pTarget)
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

bool BotHunterAI::CheckManaModel()
{
    uint32 manaPct = GetManaPowerPer();
    if (m_IsReviveManaModel)
    {
        if (manaPct > 70)
            m_IsReviveManaModel = false;
    }
    else
    {
        if (manaPct < 8)
            m_IsReviveManaModel = true;
    }
    return m_IsReviveManaModel;
}
