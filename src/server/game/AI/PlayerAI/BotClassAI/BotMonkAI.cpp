
#include "BotMonkAI.h"
#include "Group.h"
#include "BotBGAIMovement.h"
#include "SpellHistory.h"
void BotMonkAI::InitializeSpells()
{
    //TALENT_SPEC_MONK_BREWMASTER;
    //SINGEL
    BREWMASTER_tiger_palm = FindMaxRankSpellByExist(100780);
    BREWMASTER_blackout_strike = FindMaxRankSpellByExist(205523);
    BREWMASTER_keg_smash = FindMaxRankSpellByExist(121253);
    BREWMASTER_chi_wave = FindMaxRankSpellByExist(115098); //talent
    //AOE
    BREWMASTER_breath_of_fire = FindMaxRankSpellByExist(115181);
    BREWMASTER_rushing_jade_wind = FindMaxRankSpellByExist(116847);
    //CONTROL       
    BREWMASTER_spear_hand_strike = FindMaxRankSpellByExist(116705);
    BREWMASTER_leg_sweep = FindMaxRankSpellByExist(119381);  //talent
    //
    BREWMASTER_detox = FindMaxRankSpellByExist(218164);
    //HEAL  
    BREWMASTER_HEAL_01 = FindMaxRankSpellByExist(116694);
    BREWMASTER_expel_harm = FindMaxRankSpellByExist(115072);
    //
    BREWMASTER_fortifying_brew = FindMaxRankSpellByExist(115203);
    BREWMASTER_purifying_brew = FindMaxRankSpellByExist(119582);
    BREWMASTER_ironskin_brew = FindMaxRankSpellByExist(115308);
    BREWMASTER_dampen_harm = FindMaxRankSpellByExist(122278); //talent

    BREWMASTER_provoke = FindMaxRankSpellByExist(115546); //pull
    BREWMASTER_resuscitate = FindMaxRankSpellByExist(115178); //reive

    //TALENT_SPEC_MONK_BATTLEDANCER;
    //SINGEL
    BATTLEDANCER_tiger_palm = FindMaxRankSpellByExist(100780);
    BATTLEDANCER_rising_sun_kick = FindMaxRankSpellByExist(107428);
    BATTLEDANCER_touch_of_death = FindMaxRankSpellByExist(115080);
    BATTLEDANCER_blackout_kick = FindMaxRankSpellByExist(100784);
    BATTLEDANCER_chi_wave = FindMaxRankSpellByExist(115098); // talent
    BATTLEDANCER_invoke_xuen_the_white_tiger = FindMaxRankSpellByExist(123904); // talent

    //AOE
    BATTLEDANCER_fists_of_fury = FindMaxRankSpellByExist(113656);
    BATTLEDANCER_spinning_crane_kick = FindMaxRankSpellByExist(101546);
    BATTLEDANCER_whirling_dragon_punch = FindMaxRankSpellByExist(152175); // talent

    //CONTROL
    BATTLEDANCER_disable = FindMaxRankSpellByExist(116095);
    BATTLEDANCER_leg_sweep = FindMaxRankSpellByExist(119381); // TALENT
    //  
    BATTLEDANCER_detox = FindMaxRankSpellByExist(218164);
    //HEAL
    BATTLEDANCER_HEAL_01 = FindMaxRankSpellByExist(116694);
    //
    BATTLEDANCER_touch_of_karma = FindMaxRankSpellByExist(122470);
    BATTLEDANCER_dampen_harm = FindMaxRankSpellByExist(122278); // talent
    //
    BATTLEDANCER_resuscitate = FindMaxRankSpellByExist(115178); //REIVE

    //TALENT_SPEC_MONK_MISTWEAVER;
    //SINGEL
    MISTWEAVER_blackout_kick = FindMaxRankSpellByExist(100784);
    MISTWEAVER_rising_sun_kick = FindMaxRankSpellByExist(107428);
    MISTWEAVER_spinning_crane_kick = FindMaxRankSpellByExist(101546); // TALENT
    //AOE
    MISTWEAVER_chi_wave = FindMaxRankSpellByExist(115098);
    //CONTROL
    MISTWEAVER_song_of_chi_ji = FindMaxRankSpellByExist(198898);
    //
    MISTWEAVER_detox = FindMaxRankSpellByExist(115450);
    //HEAL
    MISTWEAVER_renewing_mist = FindMaxRankSpellByExist(115151);
    MISTWEAVER_enveloping_mist = FindMaxRankSpellByExist(124682);
    MISTWEAVER_HEAL_01 = FindMaxRankSpellByExist(116694);
    MISTWEAVER_summon_jade_serpent_statue = FindMaxRankSpellByExist(115313); // talent
    //HEAL AOE
    MISTWEAVER_essence_font = FindMaxRankSpellByExist(191837);
    MISTWEAVER_revival = FindMaxRankSpellByExist(115310);
    MISTWEAVER_vivify = FindMaxRankSpellByExist(116670); //talent
    //FOR TANK
    MISTWEAVER_life_cocoon = FindMaxRankSpellByExist(116849);
    //REIVE
    MISTWEAVER_resuscitate = FindMaxRankSpellByExist(115178);
    MISTWEAVER_reawaken = FindMaxRankSpellByExist(212051);
}

void BotMonkAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotMonkAI::EachTick()
{
    BotBGAI::EachTick();
    //if (me->InArena())
    {
        Group* pGroup = me->GetGroup();
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);
                if (!player || me->GetMap() != player->GetMap() || !player->IsInWorld() || player->IsPlayerBot())
                    continue;
                return;
            }
        }
        else
            return;
    }
    if (m_BotTalentType == MonkTalent_BrewMaster)
        UpPower();
    else if (m_BotTalentType == MonkTalent_BattleDancer)
        UpEnergy();
    else if (m_BotTalentType == MonkTalent_MistWeaver)
        UpMana();
}

void BotMonkAI::ResetBotAI()
{
    UpdateTalentType();
    BotBGAI::ResetBotAI();
    InitializeSpells();
}

uint32 BotMonkAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

uint32 BotMonkAI::GetEnergyPowerPer()
{
    float per = (float)me->GetPower(POWER_ENERGY) / (float)me->GetMaxPower(POWER_ENERGY);
    return (uint32)(per * 100);
}

uint32 BotMonkAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

bool BotMonkAI::NeedFlee()
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

void BotMonkAI::ProcessReady()
{
    ProcessNormalSpell();
}

void BotMonkAI::ProcessFlee()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    FleeMovement();
    //???
    if (monk_roll && me->GetHealthPct() < 60 && TryCastSpell(monk_roll, me) == SpellCastResult::SPELL_CAST_OK)
    {
        TryCastSpell(BREWMASTER_HEAL_01, me);
        return;
    }

    if (m_BotTalentType == MonkTalent_BrewMaster)
    {
        if (BREWMASTER_expel_harm && TryCastSpell(BREWMASTER_expel_harm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (BREWMASTER_HEAL_01 && TryCastSpell(BREWMASTER_HEAL_01, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else  if (m_BotTalentType == MonkTalent_BattleDancer)
    {
        if (BREWMASTER_HEAL_01 && TryCastSpell(BREWMASTER_HEAL_01, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else  if (m_BotTalentType == MonkTalent_MistWeaver)
    {
        float healthPct = me->GetHealthPct();
        if (healthPct < 60 && TryCastSpell(MISTWEAVER_essence_font, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 55 && TryCastSpell(MISTWEAVER_vivify, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 50 && TryCastSpell(MISTWEAVER_revival, me) == SpellCastResult::SPELL_CAST_OK)
            return;


        if (TryCastSpell(MISTWEAVER_enveloping_mist, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(MISTWEAVER_HEAL_01, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(MISTWEAVER_summon_jade_serpent_statue, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(MISTWEAVER_renewing_mist, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool BotMonkAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
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

void BotMonkAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    // TryCastSpell(GetArtifactSpell(), pTarget);
    if (m_BotTalentType == MonkTalent_MistWeaver)
    {
        float healthPct = pTarget->GetHealthPct();
        NearUnitVec friends = SearchLifePctByFriendRange(pTarget, BOTAI_RANGESPELL_DISTANCE);
        if (friends.size() > 2)
        {
            if (healthPct < 50 && MISTWEAVER_revival && TryCastSpell(MISTWEAVER_revival, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (MISTWEAVER_vivify && TryCastSpell(MISTWEAVER_vivify, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (MISTWEAVER_essence_font && TryCastSpell(MISTWEAVER_essence_font, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        if (MISTWEAVER_spinning_crane_kick && TryCastSpell(MISTWEAVER_spinning_crane_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (MISTWEAVER_rising_sun_kick && TryCastSpell(MISTWEAVER_rising_sun_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (MISTWEAVER_blackout_kick && TryCastSpell(MISTWEAVER_blackout_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (MISTWEAVER_HEAL_01 && TryCastSpell(MISTWEAVER_HEAL_01, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotMonkAI::ProcessMeleeSpell(Unit* pTarget)
{
    //TryCastSpell(GetArtifactSpell(), pTarget);
    if (m_BotTalentType == MonkTalent_BrewMaster)
        ProcessBrewMasterCombat(pTarget);
    else if (m_BotTalentType == MonkTalent_BattleDancer)
        ProcessBattleDancerCombat(pTarget);
    else if (m_BotTalentType == MonkTalent_MistWeaver)
        ProcessHealthSpell(me);
}

void BotMonkAI::ProcessBrewMasterCombat(Unit* pTarget)
{
    //uint32 rage = GetRagePowerPer();
    if (me->GetHealthPct() < 60)
    {
        if (TryCastSpell(BREWMASTER_fortifying_brew, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(BREWMASTER_purifying_brew, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(BREWMASTER_ironskin_brew, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(BREWMASTER_dampen_harm, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() > 2)
    {
        if (TryCastSpell(BREWMASTER_breath_of_fire, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(BREWMASTER_rushing_jade_wind, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TryCastSpell(BREWMASTER_chi_wave, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(BREWMASTER_keg_smash, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(BREWMASTER_blackout_strike, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(BREWMASTER_tiger_palm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotMonkAI::ProcessBattleDancerCombat(Unit* pTarget)
{
    if (me->GetHealthPct() < 80 || TryCastSpell(BATTLEDANCER_touch_of_karma, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->GetHealthPct() < 80 || TryCastSpell(BATTLEDANCER_dampen_harm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() > 2)
    {
        if (TryCastSpell(BATTLEDANCER_fists_of_fury, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(BATTLEDANCER_spinning_crane_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(BATTLEDANCER_whirling_dragon_punch, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    if (TryCastSpell(BATTLEDANCER_touch_of_death, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(BATTLEDANCER_invoke_xuen_the_white_tiger, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(BATTLEDANCER_chi_wave, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    uint32 rate = urand(0, 99);
    if (rate < 50 && TryCastSpell(BATTLEDANCER_blackout_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    else if (TryCastSpell(BATTLEDANCER_rising_sun_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    if (TryCastSpell(BATTLEDANCER_tiger_palm, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotMonkAI::ProcessRangeSpell(Unit* pTarget)
{
    if (m_BotTalentType == MonkTalent_MistWeaver)
        ProcessMistWeaverCombat(pTarget);
}

bool BotMonkAI::ProcessArenaHealthMember()
{
    if (!me->InArena())
        return false;
    if (GetManaPowerPer() < 15)
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

void BotMonkAI::ProcessMistWeaverCombat(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (m_BotTalentType == MonkTalent_MistWeaver && GetManaPowerPer() < 75)
        return;

    if (m_BotTalentType == MonkTalent_MistWeaver)
    {
        NearUnitVec targetRangeEnemy = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
        if (targetRangeEnemy.size() > 3)
        {
            if (TryCastSpell(MISTWEAVER_chi_wave, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }

        if (TryCastSpell(MISTWEAVER_blackout_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(MISTWEAVER_rising_sun_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(MISTWEAVER_spinning_crane_kick, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool BotMonkAI::CanMeleeHealthMe()
{
    if (GetManaPowerPer() > 15 && me->GetHealthPct() < 60 &&
        !HasAuraMechanic(me, Mechanics::MECHANIC_SILENCE))
    {
        if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() < 2)
            return true;
    }
    return false;
}

bool BotMonkAI::TargetHasMechanic(Unit* pTarget)
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

bool BotMonkAI::IsMeleeBotAI()
{
    // if (m_BotTalentType != MonkTalent_MistWeaver)
    return true;
    //  return false;
}

bool BotMonkAI::IsRangeBotAI()
{
    if (m_BotTalentType == MonkTalent_BattleDancer)
        return true;
    return false;
}

bool BotMonkAI::IsHealerBotAI()
{
    if (m_BotTalentType == MonkTalent_MistWeaver)
        return true;
    return false;
}

bool BotMonkAI::IsAttacker()
{
    return (m_BotTalentType != MonkTalent_MistWeaver);
}

bool BotMonkAI::HasEnergyStore()
{
    return GetEnergyPowerPer() >= 60;
}

void BotMonkAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_ENERGY);
    uint32 power = me->GetPower(Powers::POWER_ENERGY);
    me->SetPower(Powers::POWER_ENERGY, (max / 30) + power);
}

void BotMonkAI::UpPower()
{
    uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
    uint32 power = me->GetPower(Powers::POWER_RAGE);
    me->SetPower(Powers::POWER_RAGE, (max / 100) + power);
}

void BotMonkAI::UpMana()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 550) + power);
}

void BotMonkAI::OnCastCharge(Unit* pTarget)
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

