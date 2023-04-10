
#include "BotGroupClassAI.h"
#include "Pet.h"
#include <BotDeathknightAI.h>
#include "BotAISpells.h"

uint32 GroupDeathknightAI::GetRunePowerPer()
{
    float per = (float)me->GetPower(POWER_RUNIC_POWER) / (float)me->GetMaxPower(POWER_RUNIC_POWER);
    return (uint32)(per * 100);
}

void GroupDeathknightAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();
}

void GroupDeathknightAI::ResetBotAI()
{
    BotGroupAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells(me);
    //UpdatePose();
}

uint32 GroupDeathknightAI::GetSeducePriority()
{
    if (!me->IsAlive())
        return 0;
    return 4;
}

void GroupDeathknightAI::OnLevelUp(uint32 talentType)
{
    BotGroupAI::OnLevelUp(talentType);
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);
}

void GroupDeathknightAI::ProcessSeduceSpell(Unit* pTarget)
{
    if (!pTarget)
        return;
    if (ProcessDKPull(pTarget))
        return;
    if (DKAssist_IceLock)
    {
        if (!pTarget->HasAura(DKAssist_IceLock) && TryCastSpell(DKAssist_IceLock, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    ProcessMeleeSpell(pTarget);
}

bool GroupDeathknightAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    if (DKIDLE_Buffer && !me->HasAura(DKIDLE_Buffer) && TryCastSpell(DKIDLE_Buffer, me) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return TryUpMount();
}

bool GroupDeathknightAI::ProcessPullSpell(Unit* pTarget)
{
    if (m_BotTalentType != 1)
        return false;
    if (pTarget->GetTarget() == me->GetGUID())//GetTargetGUID
        return false;
    if (ProcessDKPull(pTarget))
        return true;
    if (BotGroupAI::PVE_PULL)
    {
        if (DKPulls_Pull && TryCastPullSpell(DKPulls_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    else
    {
        if (DKPulls_Pull && TryCastSpell(DKPulls_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }

    return false;
}

void GroupDeathknightAI::ProcessRangeSpell(Unit* pTarget)
{
    PetAction(pTarget);
    if (ProcessDKPull(pTarget))
        return;
    if (ProcessBlcokCast())
        return;
}

void GroupDeathknightAI::ProcessMeleeSpell(Unit* pTarget)
{
    PetAction(pTarget);
    if (ProcessBlcokCast())
        return;
    if (ProcessMgcShield())
        return;

    uint32 powerPct = GetRunePowerPer();
    if (powerPct < 15 && DKAssist_RuneWeapon)
    {
        if (TryCastSpell(DKAssist_RuneWeapon, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    uint32 lifePct = me->GetHealthPct();
    if (lifePct < 10)
    {
        if (DKDefense_IceBody && TryCastSpell(DKDefense_IceBody, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (lifePct < 50 && TryCastSpell(DKAssist_DeadRevive, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (DKAttack_RuneAttack && TryCastSpell(DKAttack_RuneAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_NearAOE && BotUtility::SpellHasReady(me, DKAttack_NearAOE))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(DKAttack_NearAOE, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (DKIDLE_SummonAllPets && BotUtility::SpellHasReady(me, DKIDLE_SummonAllPets))
    {
        NearUnitVec nearEnemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
        if (nearEnemys.size() > 2)
        {
            if (TryCastSpell(DKIDLE_SummonAllPets, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (DKAttack_AreaAOE && BotUtility::SpellHasReady(me, DKAttack_AreaAOE))
    {
        NearUnitVec targetRangeEnemys = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
        if (targetRangeEnemys.size() > 1)
        {
            if (TryCastSpell(DKAttack_AreaAOE, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }

    bool hasInfected = false;// HasAuraMechanic(pTarget, Mechanics::MECHANIC_INFECTED);
    if (hasInfected)
    {
        if (DKAttack_LifeAttack && lifePct < 60 && TryCastSpell(DKAttack_LifeAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessInfected(pTarget))
        return;

    switch (m_BotTalentType)
    {
    case 0:
        ProcessBloodMeleeSpell(pTarget);
        break;
    case 1:
        ProcessFrostMeleeSpell(pTarget);
        break;
    case 2:
        ProcessEvilMeleeSpell(pTarget);
        break;
    }

    if (hasInfected)
    {
        if (DKAttack_DoDestroy && TryCastSpell(DKAttack_DoDestroy, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (DKAssist_DeadRevive && TryCastSpell(DKAssist_DeadRevive, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupDeathknightAI::ProcessBloodMeleeSpell(Unit* pTarget)
{
    if (me->GetHealthPct() < 35)
    {
        if (DKAssist_RuneLife && TryCastSpell(DKAssist_RuneLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (DKAssist_BloodBuf && TryCastSpell(DKAssist_BloodBuf, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (DKAssist_BloodBrand && TryCastSpell(DKAssist_BloodBrand, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAssist_Frenzied && TryCastSpell(DKAssist_Frenzied, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAssist_SummonRuneWeapon && TryCastSpell(DKAssist_SummonRuneWeapon, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (DKAttack_CoreAtt && TryCastSpell(DKAttack_CoreAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_ShadowAtt && TryCastSpell(DKAttack_ShadowAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_BloodAtt && TryCastSpell(DKAttack_BloodAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupDeathknightAI::ProcessFrostMeleeSpell(Unit* pTarget)
{
    if (TryCastSpell(DKAssist_RuneShunt, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() < 50)
    {
        if (DKDefense_IceArmor && TryCastSpell(DKDefense_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (DKAssist_NextCrit && TryCastSpell(DKAssist_NextCrit, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_IceWindAtt && TryCastSpell(DKAttack_IceWindAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_FrostAtt && TryCastSpell(DKAttack_FrostAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_IceSickness && TryCastSpell(DKAttack_IceSickness, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupDeathknightAI::ProcessEvilMeleeSpell(Unit* pTarget)
{
    if (TryCastSpell(DKAssist_RuneShunt, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKDefense_BoneShield && !me->HasAura(DKDefense_BoneShield) && TryCastSpell(DKDefense_BoneShield, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAssist_SummonFlyAtt && TryCastSpell(DKAssist_SummonFlyAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAssist_PetPower && TryCastSpell(DKAssist_PetPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_CorpseExplosion && TryCastSpell(DKAttack_CorpseExplosion, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_NaturalAtt && TryCastSpell(DKAttack_NaturalAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_IceSickness && TryCastSpell(DKAttack_IceSickness, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DKAttack_BloodAtt && TryCastSpell(DKAttack_BloodAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void GroupDeathknightAI::ProcessFlee()
{
    FleeMovement();
    PetAction(NULL);
}

//void GroupDeathknightAI::UpdatePose()
//{
//    switch (m_BotTalentType)
//    {
//    case 0:
//        if (!me->HasAura(DKStatus_Blood))
//            me->CastSpell(me, DKStatus_Blood, true);
//        break;
//    case 1:
//        if (!me->HasAura(DKStatus_Frost))
//            me->CastSpell(me, DKStatus_Frost, true);
//        break;
//    case 2:
//        if (!me->HasAura(DKStatus_Evil))
//            me->CastSpell(me, DKStatus_Evil, true);
//        break;
//    }
//}

bool GroupDeathknightAI::ProcessBlcokCast()
{
    if (!DKBlock_Cast || !BotUtility::SpellHasReady(me, DKBlock_Cast))
        return false;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_TOTEMRANGE);
    if (enemys.empty())
        return false;
    for (Unit* pUnit : enemys)
    {
        if (!pUnit->HasUnitState(UNIT_STATE_CASTING))
            continue;
        if (TryCastSpell(DKBlock_Cast, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupDeathknightAI::ProcessMgcShield()
{
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    if (DKDefense_MgcShield && BotUtility::SpellHasReady(me, DKDefense_MgcShield))
    {
        for (Unit* pUnit : enemys)
        {
            if (!pUnit->HasUnitState(UNIT_STATE_CASTING))
                continue;
            if (pUnit->GetTarget() != me->GetGUID())//GetTargetGUID
                continue;
            if (TryCastSpell(DKDefense_MgcShield, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            break;
        }
    }
    if (m_BotTalentType == 2 && DKDefense_NoMgcArea && BotUtility::SpellHasReady(me, DKDefense_NoMgcArea))
    {
        uint32 castMeCount = 0;
        for (Unit* pUnit : enemys)
        {
            if (!pUnit->HasUnitState(UNIT_STATE_CASTING))
                continue;
            if (pUnit->GetTarget() != me->GetGUID())//GetTargetGUID
                continue;
            ++castMeCount;
        }
        if (castMeCount > 1)
        {
            if (TryCastSpell(DKDefense_NoMgcArea, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool GroupDeathknightAI::ProcessInfected(Unit* pTarget)
{
    if (!pTarget || !DKAssist_Infect)
        return false;
    //if (!HasAuraMechanic(pTarget, Mechanics::MECHANIC_INFECTED))
    //	return false;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    uint32 noInfecctedCount = 0;
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget)
            continue;
        //if (HasAuraMechanic(pUnit, Mechanics::MECHANIC_INFECTED))
        //	continue;
        ++noInfecctedCount;
    }
    if (noInfecctedCount > 1)
    {
        if (TryCastSpell(DKAssist_Infect, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool GroupDeathknightAI::ProcessDKPull(Unit* pTarget)
{
    if (!pTarget || !IsTankBotAI())
        return false;
    if (DKPulls_DKPull && BotUtility::SpellHasReady(me, DKPulls_DKPull))
    {
        if (Creature* pCreature = pTarget->ToCreature())
        {
            if (TryCastSpell(DKPulls_DKPull, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

void GroupDeathknightAI::PetAction(Unit* pTarget)
{
    Position pos;
    Pet* pPet = me->GetPet();
    if (!pPet)
    {
        if (pTarget && DKIDLE_SummonPet && BotUtility::SpellHasReady(me, DKIDLE_SummonPet))
        {
            if (TryCastSpell(DKIDLE_SummonPet, me) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        return;
    }
    if (pPet->GetVictim() == pTarget)
        return;
    WorldSession* pSession = me->GetSession();
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(),pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

void GroupDeathknightAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_RUNIC_POWER);
    uint32 power = me->GetPower(Powers::POWER_RUNIC_POWER);
    me->SetPower(Powers::POWER_RAGE, (max / 200) + power);
}

bool GroupDeathknightAI::IsTankBotAI()
{
    return (m_BotTalentType == 1);
}

bool GroupDeathknightAI::TryBlockCastingByTarget(Unit* pTarget)
{
    if (!pTarget)
        return false;
    if (DKBlock_Cast && TryCastSpell(DKBlock_Cast, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    if (DKBlock_Silence && TryCastSpell(DKBlock_Silence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return true;
    return false;
}
