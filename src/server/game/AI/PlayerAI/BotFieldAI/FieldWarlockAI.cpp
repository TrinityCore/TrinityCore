
#include "BotFieldClassAI.h"
#include "PlayerBotSession.h"
#include "Pet.h"

void FieldWarlockAI::InitializePetSpells()
{
    if (m_IsInitedPetSpells)
        return;
    Pet* pPet = me->GetPet();
    if (!pPet || !pPet->IsAlive())
        return;

    WarlockPetDemon_Charge = BotUtility::FindPetMaxRankSpellByExist(me, 47996);
    WarlockPetDemon_Melee = BotUtility::FindPetMaxRankSpellByExist(me, 47994);
    WarlockPetDog_MagicBuf = BotUtility::FindPetMaxRankSpellByExist(me, 57567);
    WarlockPetDog_EatMgc = BotUtility::FindPetMaxRankSpellByExist(me, 48011);
    WarlockPetDog_Bite = BotUtility::FindPetMaxRankSpellByExist(me, 54053);
    WarlockPetDog_Silence = BotUtility::FindPetMaxRankSpellByExist(me, 19647);
    WarlockPetSuccubus_Lash = BotUtility::FindPetMaxRankSpellByExist(me, 47992);
    WarlockPetSuccubus_Sneak = BotUtility::FindPetMaxRankSpellByExist(me, 7870);
    WarlockPetSuccubus_Charm = BotUtility::FindPetMaxRankSpellByExist(me, 6358);
    WarlockPetGhost_Shield = BotUtility::FindPetMaxRankSpellByExist(me, 47983);
    WarlockPetGhost_Sneak = BotUtility::FindPetMaxRankSpellByExist(me, 4511);
    WarlockPetGhost_Stamp = BotUtility::FindPetMaxRankSpellByExist(me, 47982);
    WarlockPetGhost_FireArrow = BotUtility::FindPetMaxRankSpellByExist(me, 47964);

    SettingPetAutoCastSpell(WarlockPetDemon_Charge, true);
    SettingPetAutoCastSpell(WarlockPetDemon_Melee, true);
    SettingPetAutoCastSpell(WarlockPetDog_MagicBuf, false);
    SettingPetAutoCastSpell(WarlockPetDog_EatMgc, true);
    SettingPetAutoCastSpell(WarlockPetDog_Bite, true);
    SettingPetAutoCastSpell(WarlockPetDog_Silence, false);
    SettingPetAutoCastSpell(WarlockPetSuccubus_Lash, true);
    SettingPetAutoCastSpell(WarlockPetSuccubus_Sneak, true);
    SettingPetAutoCastSpell(WarlockPetSuccubus_Charm, false);
    SettingPetAutoCastSpell(WarlockPetGhost_Shield, true);
    SettingPetAutoCastSpell(WarlockPetGhost_Sneak, true);
    SettingPetAutoCastSpell(WarlockPetGhost_Stamp, true);
    SettingPetAutoCastSpell(WarlockPetGhost_FireArrow, true);

    m_IsInitedPetSpells = true;
}

void FieldWarlockAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldWarlockAI::ResetBotAI()
{
    BotFieldAI::ResetBotAI();
    m_IsInitedPetSpells = false;
    UpdateTalentType();
    InitializeSpells(me);
}

void FieldWarlockAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
    m_IsInitedPetSpells = false;
    InitializePetSpells();
}

uint32 FieldWarlockAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

bool FieldWarlockAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
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

void FieldWarlockAI::ProcessFlee()
{
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        FleeMovement();
    if (ProcessMana())
        return;

    NearUnitVec enemys = RangeEnemyListByTargetIsMe(NEEDFLEE_CHECKRANGE);
    if (enemys.empty())
        return;
    Unit* pRndPlayer = NULL;
    for (Unit* player : enemys)
    {
        if (!TargetIsFear(player))
        {
            pRndPlayer = player;
            break;
        }
    }
    if (pRndPlayer == NULL)
        pRndPlayer = enemys[urand(0, enemys.size() - 1)];
    Pet* pPet = me->GetPet();
    if (pPet && !pPet->HasUnitState(UNIT_STATE_CASTING))
    {
        Unit* pPetTarget = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
        if (pPetTarget && WarlockPetDog_Silence)
        {
            if (PetTryCastSpell(WarlockPetDog_Silence, pPetTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        pPetTarget = pPet->GetVictim();
        bool isValidTarget = false;
        for (Unit* player : enemys)
        {
            if (pPetTarget == player)
            {
                isValidTarget = true;
                break;
            }
        }
        if (!isValidTarget)
        {
            PetAction(pPet, pRndPlayer);
        }
        else if (pPetTarget && WarlockPetSuccubus_Charm)
        {
            if (PetTryCastSpell(WarlockPetSuccubus_Charm, pPetTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }

    if (m_BotTalentType == 1 && WarlockAssist_DemonPower && TryCastSpell(WarlockAssist_DemonPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (WarlockAOE_MeleeFire && TryCastSpell(WarlockAOE_MeleeFire, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && enemys.size() > 1 && WarlockAOE_ShadowRage)
    {
        if (TryCastSpell(WarlockAOE_ShadowRage, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (WarlockCurse_MoveLow && m_BotTalentType == 0 && !pRndPlayer->HasAura(WarlockCurse_MoveLow) && TryCastSpell(WarlockCurse_MoveLow, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (enemys.size() <= 2 && !TargetIsFear(pRndPlayer))
    {
        if (enemys.size() > 1)
        {
            if (TryCastSpell(WarlockAssist_AOEFear, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            {
                me->StopMoving();
                return;
            }
        }
        if (TryCastSpell(WarlockAssist_FastFear, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        {
            me->StopMoving();
            return;
        }
        if (TryCastSpell(WarlockAssist_BaseFear, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
        {
            me->StopMoving();
            return;
        }
    }
    if (m_BotTalentType == 2 && WarlockCast_ShadowShock)
    {
        if (!pRndPlayer->HasAura(WarlockCast_ShadowShock) && TryCastSpell(WarlockCast_ShadowShock, pRndPlayer, true) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (!pRndPlayer->HasAura(WarlockCurse_MoveLow))
    {
        if (!pRndPlayer->HasAura(WarlockCurse_MoveLow) && TryCastSpell(WarlockCurse_MoveLow, pRndPlayer) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    ProcessDot(pRndPlayer, false);
}

bool FieldWarlockAI::ProcessMana()
{
    uint32 manaPct = GetManaPowerPer();
    if (manaPct > 35)
        return false;
    if (m_BotTalentType == 0 && WarlockAssist_ExtractMana)
    {
        if (TryCastSpell(WarlockAssist_ExtractMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (me->GetHealthPct() > 40)
    {
        if (TryCastSpell(WarlockAssist_ConvertMana, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool FieldWarlockAI::ProcessDot(Unit* pTarget, bool canCastTime)
{
    if (!pTarget)
        return false;
    uint32 targetRangeCount = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE).size();
    if (!WarlockDot_AOEDmg || targetRangeCount <= 2)
    {
        if (!pTarget->HasAura(WarlockDot_LowDmg) && TryCastSpell(WarlockDot_LowDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (canCastTime)
    {
        if (!pTarget->HasAura(WarlockDot_Sacrifice) && TryCastSpell(WarlockDot_Sacrifice, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
        //if (WarlockDot_AOEDmg && targetRangeCount > 2 && !pTarget->HasAura(WarlockDot_AOEDmg))
        //{
        //	uint32 curTick = getMSTime();
        //	if (curTick > m_LastAOEDotTick && TryCastSpell(WarlockDot_AOEDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
        //	{
        //		m_LastAOEDotTick = curTick + 8000;
        //		return true;
        //	}
        //}
        if (m_BotTalentType == 0)
        {
            if (!pTarget->HasAura(WarlockDot_LeechSoul) && TryCastSpell(WarlockDot_LeechSoul, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
            if (!pTarget->HasAura(WarlockDot_HighDmg) && TryCastSpell(WarlockDot_HighDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }

    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
    {
        Player* pPlayer = (Player*)pTarget->ToPlayer();
        if (TargetIsCastMagic(pPlayer))
        {
            if (!pTarget->HasAura(WarlockCurse_CastLow) && TryCastSpell(WarlockCurse_CastLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
        else
        {
            if (!pTarget->HasAura(WarlockCurse_MeleeLow) && TryCastSpell(WarlockCurse_MeleeLow, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    else
    {
        if (!pTarget->HasAura(WarlockCurse_MgcDmg) && TryCastSpell(WarlockCurse_MgcDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

bool FieldWarlockAI::ProcessFear(Unit* pTarget)
{
    if (!pTarget || !WarlockAssist_BaseFear)
        return false;
    if (TargetIsFear(pTarget))
    {
        return false;
    }

    if (!m_CastRecords.MatchCastRecord(pTarget, WarlockAssist_BaseFear, 20000))
    {
        return false;
    }

    if (TryCastSpell(WarlockAssist_BaseFear, pTarget) == SpellCastResult::SPELL_CAST_OK)
    {
        me->StopMoving();
        m_CastRecords.RecordCastSpellTick(pTarget, WarlockAssist_BaseFear);
        return true;
    }
    return false;
}

bool FieldWarlockAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    InitializePetSpells();

    if (WarlockPetDog_MagicBuf && !me->HasAura(WarlockPetDog_MagicBuf))
        PetTryCastSpell(WarlockPetDog_MagicBuf, me);
    if (WarlockIDLE_HighArmor)
    {
        if (!me->HasAura(WarlockIDLE_HighArmor) && TryCastSpell(WarlockIDLE_HighArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (WarlockIDLE_Armor)
    {
        if (!me->HasAura(WarlockIDLE_Armor) && TryCastSpell(WarlockIDLE_Armor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else if (WarlockIDLE_LowArmor)
    {
        if (!me->HasAura(WarlockIDLE_LowArmor) && TryCastSpell(WarlockIDLE_LowArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    //if (WarlockIDLE_ShadowShield)
    //{
    //	if (!me->HasAura(WarlockIDLE_ShadowShield) && TryCastSpell(WarlockIDLE_ShadowShield, me) == SpellCastResult::SPELL_CAST_OK)
    //		return true;
    //}
    if (!me->HasAura(m_UseMountID))
    {
        if (me->GetPetGUID().IsEmpty())
        {
            if (WarlockIDLE_FastSummon)
                TryCastSpell(WarlockIDLE_FastSummon, me);
            if (m_BotTalentType == 1 && WarlockIDLE_SummonGuardDemon && me->getLevel() >= 60)
            {
                if (TryCastSpell(WarlockIDLE_SummonGuardDemon, me, true) == SpellCastResult::SPELL_CAST_OK)
                {
                    m_IsInitedPetSpells = false;
                    return true;
                }
            }
            else
            {
                uint32 rndRate = urand(0, 99);
                if (rndRate <= 50)
                {
                    if (TryCastSpell(WarlockIDLE_SummonFireDemon, me, true) == SpellCastResult::SPELL_CAST_OK)
                    {
                        m_IsInitedPetSpells = false;
                        return true;
                    }
                }
                else// if (rndRate > 50)
                {
                    if (TryCastSpell(WarlockIDLE_SummonSuccubus, me, true) == SpellCastResult::SPELL_CAST_OK)
                    {
                        m_IsInitedPetSpells = false;
                        return true;
                    }
                }
                //else
                //{
                //	if (TryCastSpell(WarlockIDLE_SummonDogDemon, me, true) == SpellCastResult::SPELL_CAST_OK)
                //	{
                //		m_IsInitedPetSpells = false;
                //		return true;
                //	}
                //}
            }
        }
        else if (m_BotTalentType == 1 && WarlockIDLE_SoulLink)
        {
            if (!me->HasAura(WarlockFlag_SoulLink) && TryCastSpell(WarlockIDLE_SoulLink, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
    }
    return TryUpMount();
}

void FieldWarlockAI::ProcessMeleeSpell(Unit* /*pTarget*/)
{

}

void FieldWarlockAI::ProcessRangeSpell(Unit* pTarget)
{
    PetAction(me->GetPet(), pTarget);
    if (ProcessMana())
        return;

    NearUnitVec enemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (enemys.size() > 3)
    {
        if (m_BotTalentType == 2 && TryCastSpell(WarlockAOE_ShadowRage, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (WarlockDot_AOEDmg && !pTarget->HasAura(WarlockDot_AOEDmg))
        {
            uint32 curTick = getMSTime();
            if (curTick > m_LastAOEDotTick && TryCastSpell(WarlockDot_AOEDmg, pTarget) == SpellCastResult::SPELL_CAST_OK)
            {
                m_LastAOEDotTick = curTick + 8000;
                return;
            }
        }
        if (enemys.size() > 5 && TryCastSpell(WarlockAOE_RainFire, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    Unit* pPetTarget = RandomRangeEnemyByCasting(BOTAI_RANGESPELL_DISTANCE);
    if (pPetTarget && WarlockPetDog_Silence)
    {
        if (PetTryCastSpell(WarlockPetDog_Silence, pPetTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (enemys.size() > 1 && WarlockPetSuccubus_Charm)
    {
        for (Unit* pUnit : enemys)
        {
            if (pUnit == pTarget || RangeListByTargetIsTarget(pUnit, BOTAI_RANGESPELL_DISTANCE).size() > 0)
                continue;
            if (PetTryCastSpell(WarlockPetSuccubus_Charm, pUnit) == SpellCastResult::SPELL_CAST_OK)
                break;
        }
    }
    if (ProcessFear(pTarget))
        return;
    if (ProcessDot(pTarget, true))
        return;

    if (m_BotTalentType == 2 && WarlockCast_ChaosArrow && TryCastSpell(WarlockCast_ChaosArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 2 && pTarget->HasAura(WarlockDot_Sacrifice))
    {
        if (WarlockCast_FullBurn && TryCastSpell(WarlockCast_FullBurn, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (WarlockCast_FireBurn && TryCastSpell(WarlockCast_FireBurn, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TryCastSpell(WarlockCast_ShadowArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    //if (pTarget->GetHealthPct() < 65)
    //{
    //	if (TryCastSpell(WarlockCast_ShadowArrow, pTarget) == SpellCastResult::SPELL_CAST_OK)
    //		return;
    //}
    //else
    //{
    //	if (TryCastSpell(WarlockCast_BigFireBall, pTarget, true) == SpellCastResult::SPELL_CAST_OK)
    //		return;
    //}
}

void FieldWarlockAI::PetAction(Pet* pPet, Unit* pTarget)
{
    Position pos;
    if (!pPet)
        return;
    if (pPet->GetVictim() == pTarget)
        return;
    WorldSession* pSession = me->GetSession();
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(),pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

bool FieldWarlockAI::TargetIsFear(Unit* pTarget)
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
    //else if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT))
    //	return true;
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
