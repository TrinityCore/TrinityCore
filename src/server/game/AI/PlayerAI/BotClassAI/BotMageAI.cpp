
#include "BotMageAI.h"
#include "BotBGAIMovement.h"
#include "Group.h"
#include "Pet.h"

void BotMageAI::InitializeSpells()
{
    MageIDLE_ManaGem = FindMaxRankSpellByExist(36883);
    MageIDLE_ArcaneMagic = FindMaxRankSpellByExist(13326);
    MageIDLE_AOEArcaneMagic = FindMaxRankSpellByExist(129171);
    MageIDLE_MgcArmor = FindMaxRankSpellByExist(164309);
    MageIDLE_FrostArmor = FindMaxRankSpellByExist(79563);
    MageIDLE_IceArmor = FindMaxRankSpellByExist(165743);
    MageIDLE_FireArmor = FindMaxRankSpellByExist(35915);
    MageIDLE_MagicAdd = FindMaxRankSpellByExist(70408);
    MageIDLE_MagicDec = FindMaxRankSpellByExist(44475);
    MageIDLE_SummonRite = FindMaxRankSpellByExist(43987);

    MageGuard_MagicShield = FindMaxRankSpellByExist(56778);
    MageGuard_FrostShield = FindMaxRankSpellByExist(201565);
    MageGuard_FrostScherm = FindMaxRankSpellByExist(41590);
    MageGuard_FrostNova = FindMaxRankSpellByExist(64919);
    MageGuard_FireBreath = FindMaxRankSpellByExist(31661);
    MageGuard_FireNova = FindMaxRankSpellByExist(11969);

    MageAssist_Mirror = FindMaxRankSpellByExist(166894);
    MageAssist_Rouse = FindMaxRankSpellByExist(12051);
    MageAssist_Stealth = FindMaxRankSpellByExist(66);
    MageAssist_Teleport = FindMaxRankSpellByExist(14514);
    MageAssist_DecCurse = FindMaxRankSpellByExist(15729);
    MageAssist_Grace = FindMaxRankSpellByExist(15729);
    MageAssist_ArcanePower = FindMaxRankSpellByExist(12042);
    MageAssist_CastSpeed = FindMaxRankSpellByExist(12472);
    MageAssist_FastColddown = FindMaxRankSpellByExist(235219);
    MageAssist_FrostPet = FindMaxRankSpellByExist(31687);
    MageAssist_FireCritAura = FindMaxRankSpellByExist(19428);

    MageConfine_BreakCast = FindMaxRankSpellByExist(29443);
    MageConfine_AuraSteal = FindMaxRankSpellByExist(30449);
    MageConfine_ArcaneSlow = FindMaxRankSpellByExist(246);
    MageConfine_ToSheep = FindMaxRankSpellByExist(246);
    MageConfine_Freeze = FindMaxRankSpellByExist(79130);

    MageAOE_ArcaneExplode = FindMaxRankSpellByExist(9433);
    MageAOE_Snowstorm = FindMaxRankSpellByExist(15783);
    MageAOE_IcePiton = FindMaxRankSpellByExist(12557);
    MageAOE_FireStorm = FindMaxRankSpellByExist(13899);

    MageArcane_Barrage = FindMaxRankSpellByExist(44425);
    MageArcane_Bullet = FindMaxRankSpellByExist(5143);
    MageArcane_ArcaneShock = FindMaxRankSpellByExist(16067);
    MageFrost_IceArrow = FindMaxRankSpellByExist(9672);
    MageFrost_IceLance = FindMaxRankSpellByExist(43571);
    MageFrost_FFArrow = FindMaxRankSpellByExist(70616);
    MageFire_FireArrow = FindMaxRankSpellByExist(133);
    MageFire_FireShock = FindMaxRankSpellByExist(15574);
    MageFire_Firing = FindMaxRankSpellByExist(2948);
    MageFire_BigFireBall = FindMaxRankSpellByExist(33051);
    MageFire_FireBomb = FindMaxRankSpellByExist(178551);

    MagePet_FrostNova = 40875;
    MageFlag_FireStun = 201565;
    MageFlag_FastFStorm = 201565;
    MageFlag_FastBFBall = 201565;
    MageFlag_FastFFArrow = 201565;
    MageFlag_CanFrozen = 201565;
    MageFlag_Scherm = 201565;
}

void BotMageAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotMageAI::ResetBotAI()
{
    BotBGAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells();
    m_LastPolymorphTarget = ObjectGuid::Empty;

    if (MageConfine_Freeze == 0 && m_BotTalentType == 2 && me->getLevel() == 80)
    {
        me->LearnSpell(44572, false);
        MageConfine_Freeze = FindMaxRankSpellByExist(44572);
    }

    m_JewelEntrys.clear();
    m_JewelEntrys.insert(5514);
    m_JewelEntrys.insert(5513);
    m_JewelEntrys.insert(8007);
    m_JewelEntrys.insert(8008);
    m_JewelEntrys.insert(22044);
    m_JewelEntrys.insert(33312);
}

uint32 BotMageAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

void BotMageAI::ClearMechanicAura()
{
    if (IsStealthing())
        return;
    bool root = HasAuraMechanic(me, Mechanics::MECHANIC_ROOT) || HasAuraMechanic(me, Mechanics::MECHANIC_SNARE);
    bool stun = HasAuraMechanic(me, Mechanics::MECHANIC_STUN);
    if (root || stun)
    {
        if (stun && me->GetHealthPct() < 20 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (MageAssist_Teleport && RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE).size() > 0 && TryCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastTeleport();
            return;
        }
    }
}

bool BotMageAI::NeedWaitSpecialSpell(uint32 diff)
{
    if (BotBGAI::NeedWaitSpecialSpell(diff))
        return true;
    if (MageFlag_Scherm)
    {
        if (me->HasAura(MageFlag_Scherm))
        {
            if (me->InArena() && RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE).empty())
            {
                me->RemoveOwnedAura(MageFlag_Scherm, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
                return false;
            }
            return true;
        }
    }
    return false;
}

bool BotMageAI::TargetCanFreeze(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (pTarget->HasAuraState(AURA_STATE_FROZEN) || me->HasAura(MageFlag_CanFrozen))
        return true;
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE) || HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT))
        return true;
    return false;
}

void BotMageAI::EachTick()
{
    BotBGAI::EachTick();
    if (!me->IsInCombat() || !me->InArena())
        return;
    Group* pGroup = me->GetGroup();
    if (pGroup)
    {
        Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
        for (Group::MemberSlot const& slot : memList)
        {
            Player* player = ObjectAccessor::FindPlayer(slot.guid);
            if (!player || me->GetMap() != player->GetMap() || !player->IsInWorld() || player->IsPlayerBot())
                continue;
            uint32 max = me->GetMaxPower(Powers::POWER_MANA);
            uint32 power = me->GetPower(Powers::POWER_MANA);
            me->SetPower(Powers::POWER_MANA, (max / 650) + power);
            return;
        }
    }
    else
        return;
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 450) + power);
}

bool BotMageAI::NeedFlee()
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

void BotMageAI::ProcessReady()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(MageIDLE_MagicAdd) && TryCastSpell(MageIDLE_MagicAdd, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (MageIDLE_AOEArcaneMagic && !me->HasAura(MageIDLE_AOEArcaneMagic) && TryCastSpell(MageIDLE_AOEArcaneMagic, me, true) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!FindExistManaJewel() && TryCastSpell(MageIDLE_ManaGem, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (MageIDLE_AOEArcaneMagic)
    {
        Group* pGroup = me->GetGroup();
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld() || me->GetDistance(player) > BOTAI_RANGESPELL_DISTANCE)
                    continue;
                if (!player->HasAura(MageIDLE_AOEArcaneMagic) && TryCastSpell(MageIDLE_AOEArcaneMagic, player, true) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
}

bool BotMageAI::ProcessNormalSpell()
{
    if (IsStealthing())
        return true;
    if (me->HasAura(m_UseMountID))
        return false;
    if (MageIDLE_AOEArcaneMagic && !me->HasAura(MageIDLE_AOEArcaneMagic) && TryCastSpell(MageIDLE_AOEArcaneMagic, me, true) == SpellCastResult::SPELL_CAST_OK)
        return false;
    if (MageIDLE_FireArmor && !me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
        return false;
    uint32 manaPct = GetManaPowerPer();
    if (MageIDLE_ManaGem && manaPct > 30 && !FindExistManaJewel())
    {
        me->StopMoving();
        if (TryCastSpell(MageIDLE_ManaGem, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (MageAssist_Rouse && manaPct < 15 && TryCastSpell(MageAssist_Rouse, me) == SpellCastResult::SPELL_CAST_OK)
    {
        me->StopMoving();
        return true;
    }
    return TryUpMount();
}

void BotMageAI::ProcessFlee()
{
    FleeMovement();
    ProcessPetAttack(me->GetSelectedUnit());
    if (IsStealthing())
        return;

    if (MageIDLE_FrostArmor)
    {
        if (!me->HasAura(MageIDLE_FrostArmor) && TryCastSpell(MageIDLE_FrostArmor, me, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else if (MageIDLE_IceArmor)
    {
        if (!me->HasAura(MageIDLE_IceArmor) && TryCastSpell(MageIDLE_IceArmor, me, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (me->IsInCombat() && TryCastSpell(MageAssist_Mirror, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    float healthPct = me->GetHealthPct();
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 0)
    {
        for (Unit* player : enemys)
        {
            if (HasAuraMechanic(player, MECHANIC_ROOT) ||
                HasAuraMechanic(player, MECHANIC_STUN))
                continue;
            {
                if (PetTryCastSpell(MagePet_FrostNova, player) == SpellCastResult::SPELL_CAST_OK)
                    break;
                if (TryCastSpell(MageGuard_FrostNova, me) == SpellCastResult::SPELL_CAST_OK)
                    return;
                break;
            }
        }
    }
    if (healthPct <= 20 && enemys.size() > 0 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (CanCastSpell(MageAssist_Teleport, me) == SpellCastResult::SPELL_CAST_OK)
    //{
    //	OnCastTeleport();
    //	return;
    //}
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 60 && UseManaJewel())
        return;

    if (ProcessFreezeSpell(me->GetSelectedUnit()))
        return;
    switch (m_BotTalentType)
    {
    case 0:
        if (ProcessArcaneFlee())
            return;
        break;
    case 1:
        if (ProcessFireFlee())
            return;
        break;
    case 2:
        if (ProcessFrostFlee())
            return;
        break;
    }
    if (enemys.size() > 0 && TryCastSpell(MageAssist_Stealth, me) == SpellCastResult::SPELL_CAST_OK)
    {
        m_StealthTick = getMSTime();
        NearUnitVec cancelTargets = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
        for (Unit* target : cancelTargets)
        {
            if (Player* player = target->ToPlayer())
                player->SetSelection(ObjectGuid::Empty);
            else
                target->SetTarget(ObjectGuid::Empty);
        }
        return;
    }
    Unit* pTarget = me->GetSelectedUnit();
    if (pTarget && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->HasAura(MageAssist_Stealth) && RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE).size() > 1)
    {
        if (TryCastSpell(MageAOE_ArcaneExplode, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    NearUnitVec stealTargets = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    if (stealTargets.size() > 0 && TryCastSpell(MageConfine_AuraSteal, stealTargets[urand(0, stealTargets.size() - 1)], true) == SpellCastResult::SPELL_CAST_OK)
        return;
}

bool BotMageAI::ProcessArcaneFlee()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE);
    float healthPct = me->GetHealthPct();
    if (healthPct <= 50 && enemys.size() > 0 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageAssist_Grace, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->HasAura(MageAssist_Grace))
        {
            if (TryCastSpell(MageFire_FireArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
    }
    if (enemys.size() > 1 && !m_NeedReserveCtrlSpell)
    {
        Unit* player = enemys[urand(0, enemys.size() - 1)];
        if (TargetCanPolymorph(player) && me->HasAura(MageAssist_Grace))
        {
            if (TryCastSpell(MageConfine_ToSheep, player) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastPolymorph(player);
                return true;
            }
        }
    }

    return false;
}

bool BotMageAI::ProcessFireFlee()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(8.0f);
    float healthPct = me->GetHealthPct();
    if (healthPct <= 50 && enemys.size() > 0 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (Unit* pTarget = me->GetSelectedUnit())
    {
        if (me->GetDistance(pTarget) < 8.0f && TryCastSpell(MageGuard_FireBreath, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (enemys.size() > 1 && TryCastSpell(MageGuard_FireNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (!pTarget->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (me->InArena())
        {
            NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
            for (Unit* pUnit : nearEnemys)
            {
                if (HasAuraMechanic(pUnit, Mechanics::MECHANIC_POLYMORPH))
                    continue;
                if (!pUnit->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pUnit) == SpellCastResult::SPELL_CAST_OK)
                    return true;
            }
        }
    }

    return false;
}

bool BotMageAI::ProcessFrostFlee()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(8.0f);
    float healthPct = me->GetHealthPct();
    if (MageGuard_FrostShield)
    {
        if (enemys.size() > 0 && !me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (MageGuard_MagicShield)
    {
        if (healthPct <= 50 && enemys.size() > 0 && GetManaPowerPer() > 50 && !me->HasAura(MageGuard_MagicShield) && TryCastSpell(MageGuard_MagicShield, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!BotUtility::SpellHasReady(me, MageGuard_FrostNova) && enemys.size() > 0)
    {
        if (TryCastSpell(MageAssist_FastColddown, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

void BotMageAI::ProcessMeleeSpell(Unit* pTarget)
{
    if (IsStealthing())
        return;
    if (PetTryCastSpell(MagePet_FrostNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!HasAuraMechanic(pTarget, MECHANIC_ROOT) && me->GetDistance(pTarget->GetPosition()) < 8 && TryCastSpell(MageGuard_FrostNova, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    switch (m_BotTalentType)
    {
    case 0:
        ProcessArcaneMeleeSpell(pTarget);
        break;
    case 1:
        ProcessFireMeleeSpell(pTarget);
        break;
    case 2:
        ProcessFrostMeleeSpell(pTarget);
        break;
    }
}

void BotMageAI::ProcessRangeSpell(Unit* pTarget)
{
    ProcessPetAttack(pTarget);
    if (IsStealthing())
        return;
    if (!me->IsInCombat())
    {
        if (!me->HasAura(MageIDLE_ArcaneMagic) && TryCastSpell(MageIDLE_ArcaneMagic, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (!me->HasAura(MageIDLE_FireArmor) && TryCastSpell(MageIDLE_FireArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(MageAssist_Mirror, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 8 && TryCastSpell(MageAssist_Rouse, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (manaPct < 60 && UseManaJewel())
        return;
    if (ProcessFreezeSpell(pTarget))
        return;
    Unit* castEnemy = RandomRangeEnemyByCasting(25.0f);
    if (castEnemy && TryCastSpell(MageConfine_BreakCast, castEnemy) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() <= 20 && RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE).size() > 0 && TryCastSpell(MageGuard_FrostScherm, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (ProcessPolymorph(pTarget))
        return;
    uint32 stealRate = urand(0, 99);
    if (stealRate < 5 && TryCastSpell(MageConfine_AuraSteal, pTarget, true) == SpellCastResult::SPELL_CAST_OK)
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessArcaneRangeSpell(pTarget);
        break;
    case 1:
        ProcessFireRangeSpell(pTarget);
        break;
    case 2:
        ProcessFrostRangeSpell(pTarget);
        break;
    }
}

void BotMageAI::ProcessArcaneRangeSpell(Unit* pTarget)
{
    if (RangeEnemyListByTargetRange(pTarget, 10.0f).size() > 5 && TryCastSpell(MageAOE_Snowstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(MageConfine_ArcaneSlow) && TryCastSpell(MageConfine_ArcaneSlow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageAssist_ArcanePower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!me->InArena())
    {
        if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() <= 0 && TryCastSpell(MageArcane_ArcaneShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (TryCastSpell(MageArcane_Barrage, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageArcane_Bullet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotMageAI::ProcessFireRangeSpell(Unit* pTarget)
{
    if (me->HasAura(MageFlag_FireStun) && TryCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, 10.0f).size() > 4 && TryCastSpell(MageAOE_FireStorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->InArena())
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
        for (Unit* pUnit : nearEnemys)
        {
            if (HasAuraMechanic(pUnit, Mechanics::MECHANIC_POLYMORPH))
                continue;
            if (!pUnit->HasAura(MageFire_FireBomb, me->GetGUID()) && TryCastSpell(MageFire_FireBomb, pUnit) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (!me->HasAura(MageAssist_FireCritAura) && TryCastSpell(MageAssist_FireCritAura, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(MageFlag_FastFStorm))
    {
        TryCastSpell(MageAOE_FireStorm, pTarget, true);
        return;
    }
    if (MageFire_BigFireBall && me->HasAura(MageFlag_FastBFBall))
    {
        TryCastSpell(MageFire_BigFireBall, pTarget, true);
        return;
    }
    //if (CanCastSpell(MageFire_FireShock, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //	return;
    uint32 rate = urand(0, 99);
    if (rate <= 30)
    {
        if (TryCastSpell(MageFire_FireArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(MageFire_Firing, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void BotMageAI::ProcessFrostRangeSpell(Unit* pTarget)
{
    if (!me->HasAura(MageGuard_FrostShield) && TryCastSpell(MageGuard_FrostShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (RangeEnemyListByTargetRange(pTarget, 10.0f).size() > 5 && TryCastSpell(MageAOE_Snowstorm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageAssist_CastSpeed, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(MageFlag_FastFFArrow))
    {
        if (MageFrost_FFArrow)
        {
            TryCastSpell(MageFrost_FFArrow, pTarget, true);
            return;
        }
        TryCastSpell(MageFire_FireArrow, pTarget, true);
        return;
    }
    if (TryCastSpell(MageAssist_FrostPet, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(MageFrost_IceArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotMageAI::ProcessArcaneMeleeSpell(Unit* /*pTarget*/)
{

}

void BotMageAI::ProcessFireMeleeSpell(Unit* /*pTarget*/)
{

}

void BotMageAI::ProcessFrostMeleeSpell(Unit* /*pTarget*/)
{

}

bool BotMageAI::ProcessPolymorph(Unit* pTarget)
{
    if (!pTarget || m_NeedReserveCtrlSpell)
        return false;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget)
            continue;
        if (!TargetCanPolymorph(pUnit))
            continue;
        if (TryCastSpell(MageConfine_ToSheep, pUnit) == SpellCastResult::SPELL_CAST_OK)
        {
            OnCastPolymorph(pUnit);
            return true;
        }
    }

    return false;
}

bool BotMageAI::ProcessFreezeSpell(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (TargetCanFreeze(pTarget) && !HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
    {
        if (m_BotTalentType == 2 && MageConfine_Freeze && me->getLevel() == 80 &&
            !pTarget->HasAura(MageConfine_Freeze) && TryCastSpell(MageConfine_Freeze, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageFrost_IceLance, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!me->InArena())
        return false;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_SEARCH_RANGE);
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget)
            continue;
        if (!TargetCanFreeze(pUnit))
            continue;
        if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
            continue;
        if (m_BotTalentType == 2 && MageConfine_Freeze && me->getLevel() == 80 &&
            !pUnit->HasAura(MageConfine_Freeze) && TryCastSpell(MageConfine_Freeze, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
        if (TryCastSpell(MageFrost_IceLance, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

void BotMageAI::OnCastTeleport()
{
    Position telePos = GetTeleportSpellPos();
    me->GetMotionMaster()->Clear();
    m_Movement->ClearMovement();
    SetTeleport(telePos);
    //me->UpdatePosition(telePos, true);
    //m_Movement->SyncPosition(telePos, true);
}

void BotMageAI::OnCastPolymorph(Unit* pTarget)
{
    m_LastPolymorphTarget = pTarget->GetGUID();
    if (me->GetTarget() == m_LastPolymorphTarget)//GetTargetGUID
        me->SetSelection(ObjectGuid::Empty);
    me->AttackStop();
    //NearUnitVec friends = SearchFriendTargetIsTarget(pTarget);
    //for (Unit* pFriend : friends)
    //{
    //	if (pFriend->GetTarget() == pTarget->GetTarget())
    //		pFriend->SetTarget(ObjectGuid::Empty);
    //}
}

bool BotMageAI::TargetCanPolymorph(Unit* pTarget)
{
    if (!MageConfine_ToSheep)
        return false;
    if (pTarget->GetHealthPct() <= 85.0f)
        return false;
    uint32 tmanaPct = TargetManaPCT(pTarget);
    if (tmanaPct <= 85)
        return false;
    if (pTarget->HasAura(MageConfine_ToSheep))
        return false;

    if (BotUtility::ControllSpellDiminishing && !TargetIsNotDiminishingByType2(pTarget, DiminishingGroup::DIMINISHING_DISORIENT))
        return false;
    if (m_LastPolymorphTarget != ObjectGuid::Empty)
    {
        if (Player* pPlayer = ObjectAccessor::FindPlayer(m_LastPolymorphTarget))
        {
            if (pPlayer->GetMap() != me->GetMap())
                m_LastPolymorphTarget = ObjectGuid::Empty;
            else
            {
                if (HasAuraMechanic(pPlayer, Mechanics::MECHANIC_POLYMORPH))
                    return false;
                if (pPlayer->HasAura(MageConfine_ToSheep))
                    return false;
            }
        }
        else
            m_LastPolymorphTarget = ObjectGuid::Empty;
    }

    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_CHARM))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_DISORIENTED))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_FREEZE))
        return false;
    //else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT))
    //	return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_POLYMORPH))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_HORROR))
        return false;
    else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return false;

    if (SearchFriendTargetIsTarget(pTarget, NEEDFLEE_CHECKRANGE).size() > 0)
        return false;

    return true;
}

void BotMageAI::ProcessPetAttack(Unit* pTarget)
{
    Position pos;
    Pet* pPet = me->GetPet();
    if (pPet)
    {
        Unit* pPetTarget = pPet->GetVictim();
        if (pPetTarget != pTarget)
        {
            WorldSession* pSession = me->GetSession();
            if (pTarget)
                pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(), pos);
            else
                pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
        }
    }
}

bool BotMageAI::CastingControlCommandSpell()
{
    if (m_LastControlTarget == ObjectGuid::Empty || !MageConfine_ToSheep)
        return false;
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        return false;
    Spell* pCurrentSpell = me->GetCurrentSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
    if (pCurrentSpell)
    {
        if (pCurrentSpell->m_spellInfo && pCurrentSpell->m_spellInfo->Id == MageConfine_ToSheep)
        {
            return pCurrentSpell->m_targets.GetUnitTargetGUID() == m_LastControlTarget;
        }
    }
    if (!pCurrentSpell)
    {
        pCurrentSpell = me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
        if (pCurrentSpell && pCurrentSpell->m_spellInfo && pCurrentSpell->m_spellInfo->Id == MageConfine_ToSheep)
        {
            return pCurrentSpell->m_targets.GetUnitTargetGUID() == m_LastControlTarget;
        }
    }
    return false;
}

bool BotMageAI::TryStartControlCommand()
{
    if (m_CruxControlTarget == ObjectGuid::Empty)
        return false;
    if (!MageConfine_ToSheep)
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
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(MageConfine_ToSheep,DIFFICULTY_40);//DIFFICULTY_40 //I DID
    if (!spellInfo || spellInfo->IsPassive())
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
   /* if (me->GetGlobalCooldownMgr().HasGlobalCooldown(spellInfo))
        return true;
    if (!me->HasSpellCooldown(spellInfo->Id))
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }*/

    if (me->IsWithinLOSInMap(pTarget) && me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
    {
        m_Movement->ClearMovement();
        TryCastSpell(MageConfine_ToSheep, pTarget);
    }
    else
    {
        if (!IsNotMovement())
            m_Movement->MovementTo(m_CruxControlTarget);
    }
    return true;
}

float BotMageAI::TryPushControlCommand(Player* pTarget)
{
    if (!pTarget || !pTarget->IsAlive() || !pTarget->IsInWorld() || me->GetMap() != pTarget->GetMap())
    {
        ClearCruxControlCommand();
        return -1;
    }
    if (!MageConfine_ToSheep)
        return -1;
    if (!TargetIsNotDiminishingByType2(pTarget, DIMINISHING_DISORIENT))
        return -1;
    if (!BotUtility::SpellHasReady(me, MageConfine_ToSheep))
        return -1;
    m_CruxControlTarget = pTarget->GetGUID();
    m_LastControlTarget = m_CruxControlTarget;
    return me->GetDistance(pTarget->GetPosition());
}

bool BotMageAI::IsStealthing()
{
    if (!MageAssist_Stealth || !me->HasAura(MageAssist_Stealth))
        return false;
    if (m_StealthTick + 5000 < getMSTime())
    {
        m_StealthTick = 0;
        return false;
    }
    return true;
}

Position BotMageAI::GetTeleportSpellPos()
{
    float onceAngle = float(M_PI) * 2.0f / 8.0f;
    Position targetPos = me->GetPosition();
    float maxDist = 0.0f;
    std::list<Position> allPosition;
    for (float angle = 0.0f; angle < (float(M_PI) * 2.0f); angle += onceAngle)
    {
        Position pos = me->GetFirstCollisionPosition(BOTAI_RANGESPELL_DISTANCE, angle);
        /*pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseMask(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        allPosition.push_back(pos);*/
    }
    if (allPosition.empty())
        return targetPos;
    for (Position pos : allPosition)
    {
        float dist = me->GetDistance(pos);
        if (dist > maxDist)
        {
            maxDist = dist;
            targetPos = pos;
        }
    }
    return targetPos;
}

bool BotMageAI::UseManaJewel()
{
    Item* pItem = FindExistManaJewel();
    if (!pItem)
        return false;
    SpellCastTargets targets;
    targets.SetTargetMask(0);
   /* if (me->CastItemUseSpell(pItem, targets,  ObjectGuid::Empty,0) == SpellCastResult::SPELL_CAST_OK)
    {
        return true;
    }*/
    return false;
}

Item* BotMageAI::FindExistManaJewel()
{
    for (uint8 slot = InventoryPackSlots::INVENTORY_SLOT_ITEM_START; slot < InventoryPackSlots::INVENTORY_SLOT_ITEM_END; slot++)
    {
        Item* pItem = me->GetItemByPos(255, slot);
        if (!pItem)
            continue;
        const ItemTemplate* pTemplate = pItem->GetTemplate();
        if (!pTemplate)
            continue;
        if (m_JewelEntrys.find(pTemplate->GetId()) != m_JewelEntrys.end())
            return pItem;
    }
    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = me->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); j++)
            {
                Item* pItem = pBag->GetItemByPos(uint8(j));
                if (!pItem)
                    continue;
                const ItemTemplate* pTemplate = pItem->GetTemplate();
                if (!pTemplate)
                    continue;
                if (m_JewelEntrys.find(pTemplate->GetId()) != m_JewelEntrys.end())
                    return pItem;
            }
        }
    }
    return NULL;
}

uint32 BotMageAI::TryCastSummonRiteSpell()
{
    if (MageIDLE_SummonRite == 0 || !me->HasSpell(MageIDLE_SummonRite))
        return 0;
    if (!me->IsAlive() || me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING))
        return 0;
    std::list<GameObject*> goResults;
    Trinity::GameObjectInRangeCheck checkerGO(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), BOTAI_SEARCH_RANGE);
    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcherGO(me, goResults, checkerGO);
    //me->VisitNearbyGridObject(BOTAI_SEARCH_RANGE, searcherGO);
    for (GameObject* go : goResults)
    {
        if (go->GetSpellId() == MageIDLE_SummonRite)
            return 0;
    }
    Group* pGroup = me->GetGroup();
    if (pGroup)
    {
        Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
        for (Group::MemberSlot const& slot : memList)
        {
            Player* player = ObjectAccessor::FindPlayer(slot.guid);
            if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() || !player->IsInWorld())
                continue;
            if (BotGroupAI* pAI = dynamic_cast<BotGroupAI*>(me->GetAI()))
            {
                if (pAI->CastingSummonRite())
                    return 0;
            }
        }
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(MageIDLE_SummonRite,DIFFICULTY_40);//DIFFICULTY_40 //I DID
    if (!spellInfo || spellInfo->IsPassive())
        return SpellCastResult::SPELL_FAILED_UNKNOWN;
   /* TriggerCastData data;
    data.triggerFlags = TriggerCastFlags(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TriggerCastFlags::TRIGGERED_IGNORE_CAST_ITEM);
    Spell* spell = new Spell(me, spellInfo, data);*/
    //spell->m_CastItem = NULL;
   /* SpellCastTargets targets;
    targets.SetUnitTarget(me);
    Dismount();
    SpellCastResult castResult = spell->prepare(&targets);
    if (castResult == SPELL_CAST_OK)
        return MageIDLE_SummonRite;*/
    return 0;
}
