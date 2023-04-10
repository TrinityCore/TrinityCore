#include "BotDeathknightAI.h"
#include "Group.h"
#include "BotBGAIMovement.h"
#include "SpellHistory.h"
#include "Pet.h"
#include "BotAI.h"
#include "WorldSession.h"

void BotDeathknightAI::InitializeSpells()
{
    DKIDLE_SummonPet = FindMaxRankSpellByExist(46584);
    DKIDLE_SummonAllPets = FindMaxRankSpellByExist(42650);

    DKBlock_Silence = FindMaxRankSpellByExist(221562);
    DKBlock_Cast = FindMaxRankSpellByExist(47528);

    DKRevie = FindMaxRankSpellByExist(61999);
    DKPulls_Pull = FindMaxRankSpellByExist(56222);
    DKPulls_DKPull = FindMaxRankSpellByExist(49576);
    DKPulls_DKAllPull = FindMaxRankSpellByExist(108199);

    DKDefense_MgcShield = FindMaxRankSpellByExist(48707);
    DKDefense_IceBody = FindMaxRankSpellByExist(48792);
    DKDefense_IceArmor = FindMaxRankSpellByExist(196770);
    DKDefense_BoneShield = FindMaxRankSpellByExist(49222);

    DKAssist_RuneLife = FindMaxRankSpellByExist(49028);
    DKAssist_BloodBrand = FindMaxRankSpellByExist(206940);

    DKAssist_BloodBuf = FindMaxRankSpellByExist(55233);
    DKAssist_RuneWeapon = FindMaxRankSpellByExist(47568);
    DKAssist_Infect = FindMaxRankSpellByExist(50842);
    DKAssist_RuneShunt = FindMaxRankSpellByExist(45529);
    DKAssist_IceLock = FindMaxRankSpellByExist(45524);
    DKAssist_DeadRevive = FindMaxRankSpellByExist(47541);
    DKAssist_PetPower = FindMaxRankSpellByExist(63560);
    DKAssist_SummonFlyAtt = FindMaxRankSpellByExist(49206);
    DKAssist_SummonRuneWeapon = FindMaxRankSpellByExist(49028);

    DKAttack_AreaAOE = FindMaxRankSpellByExist(43265);
    DKAttack_BloodAtt = FindMaxRankSpellByExist(49998);
    DKAttack_ShadowAtt = FindMaxRankSpellByExist(85948);
    DKAttack_FrostAtt = FindMaxRankSpellByExist(49143);

    DKAttack_RuneAttack = FindMaxRankSpellByExist(49020);
    DKAttack_IceWindAtt = FindMaxRankSpellByExist(49184);
    DKAttack_CorpseExplosion = FindMaxRankSpellByExist(77575);
    DKAttack_NaturalAtt = FindMaxRankSpellByExist(55090);
    DKAttack_CoreAtt = FindMaxRankSpellByExist(206930);
    DKAttack_Deaths_caress = FindMaxRankSpellByExist(195292);
}

void BotDeathknightAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotDeathknightAI::ResetBotAI()
{
    BotBGAI::ResetBotAI();
    UpdateTalentType();
    InitializeSpells();
}

uint32 BotDeathknightAI::GetRunePowerPer()
{
    float per = (float)me->GetPower(POWER_RUNIC_POWER) / (float)me->GetMaxPower(POWER_RUNIC_POWER);
    return (uint32)(per * 100);
}

void BotDeathknightAI::ProcessReady()
{
    ProcessNormalSpell();
}

void BotDeathknightAI::ProcessFlee()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    FleeMovement();
    PetAction(NULL);
}

bool BotDeathknightAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;
    return TryUpMount();
}

void BotDeathknightAI::ProcessMeleeSpell(Unit* pTarget)
{
    PetAction(pTarget);
    if (ProcessBlcokCast())
        return;
    if (ProcessMgcShield())
        return;

    uint32 powerPct = GetRunePowerPer();
    
    if (powerPct < 15 && DKAssist_RuneWeapon && m_BotTalentType == DeathknightTalent_Blood)
    {
        if (TryCastSpell(DKAssist_RuneWeapon, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    
    uint32 lifePct = me->GetHealthPct();
    if (lifePct < 30)
    {
        if (DKDefense_IceBody && TryCastSpell(DKDefense_IceBody, me) == SpellCastResult::SPELL_CAST_OK)
            return;
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

    if (ProcessInfected(pTarget))
        return;

    switch (m_BotTalentType)
    {
    case DeathknightTalent_Blood:
        ProcessBloodMeleeSpell(pTarget);
        break;
    case DeathknightTalent_Frost:
        ProcessFrostMeleeSpell(pTarget);
        break;
    case DeathknightTalent_Unholy:
        ProcessEvilMeleeSpell(pTarget);
        break;
    }

    if (DKAssist_DeadRevive && TryCastSpell(DKAssist_DeadRevive, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotDeathknightAI::ProcessRangeSpell(Unit* pTarget)
{
    PetAction(pTarget);
    if (ProcessDKPull(pTarget))
        return;
    if (ProcessBlcokCast())
        return;
}

void BotDeathknightAI::ProcessBloodMeleeSpell(Unit* pTarget)
{
    if (me->GetHealthPct() < 35)
    {
        if (DKAssist_RuneLife && TryCastSpell(DKAssist_RuneLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (DKAssist_BloodBuf && TryCastSpell(DKAssist_BloodBuf, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (DKAssist_SummonRuneWeapon && TryCastSpell(DKAssist_SummonRuneWeapon, me) == SpellCastResult::SPELL_CAST_OK)
            return;
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
    //  PlayerStorage* storage = me->GetStorage(); TODO THOR
      
     /* if (!storage->IsEntryExists(DKAttack_Deaths_caress))
      {
          storage->SetEntry(DKAttack_Deaths_caress, 0, 10000);
          if (DKAttack_Deaths_caress && TryCastSpell(DKAttack_Deaths_caress, pTarget) == SpellCastResult::SPELL_CAST_OK)
              return;
      }*/
      
    if (DKAssist_BloodBrand && TryCastSpell(DKAssist_BloodBrand, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAttack_BloodAtt && TryCastSpell(DKAttack_BloodAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKDefense_BoneShield && TryCastSpell(DKDefense_BoneShield, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAttack_CoreAtt && TryCastSpell(DKAttack_CoreAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotDeathknightAI::ProcessFrostMeleeSpell(Unit* pTarget)
{
    
    if (TryCastSpell(DKAssist_RuneShunt, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() < 50)
    {
        
        if (DKDefense_IceArmor && TryCastSpell(DKDefense_IceArmor, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    //??
    if (DKAttack_RuneAttack && TryCastSpell(DKAttack_RuneAttack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAttack_BloodAtt && TryCastSpell(DKAttack_BloodAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAttack_IceWindAtt && TryCastSpell(DKAttack_IceWindAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAttack_FrostAtt && TryCastSpell(DKAttack_FrostAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

}

void BotDeathknightAI::ProcessEvilMeleeSpell(Unit* pTarget)
{
    
    if (TryCastSpell(DKAssist_RuneShunt, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAssist_DeadRevive && TryCastSpell(DKAssist_DeadRevive, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKIDLE_SummonPet && TryCastSpell(DKIDLE_SummonPet, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAssist_SummonFlyAtt && TryCastSpell(DKAssist_SummonFlyAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    
    if (DKAssist_PetPower && TryCastSpell(DKAssist_PetPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;

    /*  PlayerStorage* storage = me->GetStorage();
      //??
      if (!storage->IsEntryExists(DKAttack_CorpseExplosion))
      {
          storage->SetEntry(DKAttack_CorpseExplosion, 0, 10000);
          if (DKAttack_CorpseExplosion && TryCastSpell(DKAttack_CorpseExplosion, pTarget) == SpellCastResult::SPELL_CAST_OK)
              return;
      }*/
      
    /*  if (!storage->IsEntryExists(DKAttack_ShadowAtt))
      {
          storage->SetEntry(DKAttack_ShadowAtt, 0, 5000);
          if (DKAttack_ShadowAtt && TryCastSpell(DKAttack_ShadowAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
              return;
      }*/
      
     /* if (!storage->IsEntryExists(DKAttack_NaturalAtt))
      {
          storage->SetEntry(DKAttack_NaturalAtt, 0, 2000);
          if (DKAttack_NaturalAtt && TryCastSpell(DKAttack_NaturalAtt, pTarget) == SpellCastResult::SPELL_CAST_OK)
              return;
      }*/
}

bool BotDeathknightAI::ProcessBlcokCast()
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

bool BotDeathknightAI::ProcessMgcShield()
{
    NearUnitVec enemys = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    if (DKDefense_MgcShield && BotUtility::SpellHasReady(me, DKDefense_MgcShield))
    {
        for (Unit* pUnit : enemys)
        {
            if (!pUnit->HasUnitState(UNIT_STATE_CASTING))
                continue;
            if (pUnit->GetTarget() != me->GetGUID())
                continue;
            if (TryCastSpell(DKDefense_MgcShield, me) == SpellCastResult::SPELL_CAST_OK)
                return true;
            break;
        }
    }
    return false;
}

bool BotDeathknightAI::ProcessInfected(Unit* pTarget)
{
    if (!pTarget || !DKAssist_Infect)
        return false;
    if (!HasAuraMechanic(pTarget, Mechanics::MECHANIC_INFECTED))
        return false;
    NearUnitVec enemys = RangeEnemyListByHasAura(0, NEEDFLEE_CHECKRANGE);
    uint32 noInfecctedCount = 0;
    for (Unit* pUnit : enemys)
    {
        if (pUnit == pTarget)
            continue;
        if (HasAuraMechanic(pUnit, Mechanics::MECHANIC_INFECTED))
            continue;
        ++noInfecctedCount;
    }
    if (noInfecctedCount > 1)
    {
        if (TryCastSpell(DKAssist_Infect, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool BotDeathknightAI::ProcessDKPull(Unit* pTarget)
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
    else if (DKPulls_Pull && BotUtility::SpellHasReady(me, DKPulls_Pull))
    {
        if (Creature* pCreature = pTarget->ToCreature())
        {
            if (TryCastSpell(DKPulls_Pull, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    else if (DKPulls_DKAllPull && BotUtility::SpellHasReady(me, DKPulls_DKAllPull))
    {
        if (Creature* pCreature = pTarget->ToCreature())
        {
            if (TryCastSpell(DKPulls_DKAllPull, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return true;
        }
    }
    return false;
}

bool BotDeathknightAI::TargetHasMechanic(Unit* pTarget)
{
    if (HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return true;
    return false;
}

bool BotDeathknightAI::IsMeleeBotAI()
{
    return true;
}

bool BotDeathknightAI::IsRangeBotAI()
{
    return false;
}

bool BotDeathknightAI::IsHealerBotAI()
{
    return false;
}

bool BotDeathknightAI::IsAttacker()
{
    return true;
}

void BotDeathknightAI::UpPower()
{
    uint32 max = me->GetMaxPower(Powers::POWER_RUNIC_POWER);
    uint32 power = me->GetPower(Powers::POWER_RUNIC_POWER);
    me->SetPower(Powers::POWER_RUNIC_POWER, (max / 100) + power);
}

void BotDeathknightAI::PetAction(Unit* pTarget)
{
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
    Position pos = *me;
    if (pTarget)
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 2, 7, pTarget->GetGUID(), pos);
    else
        pSession->HandlePetActionHelper(pPet, pPet->GetGUID(), 1, 7, ObjectGuid::Empty, pos);
}

bool BotDeathknightAI::IsTankBotAI()
{
    return (m_BotTalentType == DeathknightTalent_Blood);
}

void BotDeathknightAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    me->StopMoving();
    float rndOffset = 3.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    me->GetMap()->GetHeight(me->GetPhaseShift(), posX, posY, posZ);
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);
}

