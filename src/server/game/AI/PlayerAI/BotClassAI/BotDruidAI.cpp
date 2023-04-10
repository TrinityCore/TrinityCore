
#include "BotDruidAI.h"
#include "Group.h"
#include "BotBGAIMovement.h"

void BotDruidAI::InitializeSpells()
{
    DruidIDLE_AOEFerityWish = FindMaxRankSpellByExist(165754);

    DruidStatus_Travel = FindMaxRankSpellByExist(783);
    DruidStatus_Bear = FindMaxRankSpellByExist(5487);
    DruidStatus_Cat = FindMaxRankSpellByExist(768);
    DruidStatus_Bird = FindMaxRankSpellByExist(24858);
    DruidStatus_Tree = FindMaxRankSpellByExist(33891);

    DruidGuard_Sneak = FindMaxRankSpellByExist(5215);
    DruidGuard_Harden = FindMaxRankSpellByExist(182872);
    DruidGuard_Thorns = FindMaxRankSpellByExist(209334);
    DruidGuard_AutoTwine = FindMaxRankSpellByExist(66071);
    DruidGuard_Twine = FindMaxRankSpellByExist(339);
    DruidGuard_Control = FindMaxRankSpellByExist(33786);
    DruidGuard_Pofu = FindMaxRankSpellByExist(61336);
    DruidGuard_TreeMan = FindMaxRankSpellByExist(6913);

    DruidAssist_PersonSpirit = FindMaxRankSpellByExist(770);
    DruidAssist_BeastSpirit = FindMaxRankSpellByExist(16857);
    DruidAssist_Active = FindMaxRankSpellByExist(6950);

    DruidCast_Moonfire = FindMaxRankSpellByExist(65856);
    DruidCast_Insect = FindMaxRankSpellByExist(65855);
    DruidCast_Anger = FindMaxRankSpellByExist(65862);
    DruidCast_Spark = FindMaxRankSpellByExist(98993);

    DruidAOE_Hurricane = FindMaxRankSpellByExist(55881);
    DruidAOE_Typhoon = FindMaxRankSpellByExist(51817);
    DruidAOE_FallStar = FindMaxRankSpellByExist(100806);

    DruidHeal_Nourishing = FindMaxRankSpellByExist(63556);
    DruidHeal_Relife = FindMaxRankSpellByExist(774);
    DruidHeal_Coalescence = FindMaxRankSpellByExist(66067);
    DruidHeal_Touch = FindMaxRankSpellByExist(5185);
    DruidHeal_LifeBurst = FindMaxRankSpellByExist(57763);
    DruidHeal_MergerLife = FindMaxRankSpellByExist(18562);
    DruidHeal_MomentHeal = FindMaxRankSpellByExist(127316);

    DruidHeal_AOETranquility = FindMaxRankSpellByExist(740);
    DruidHeal_AOEFerity = FindMaxRankSpellByExist(173170);

    DruidCat_Stun = FindMaxRankSpellByExist(203123);
    DruidCat_Bite = FindMaxRankSpellByExist(22568);
    DruidCat_Roar = FindMaxRankSpellByExist(52610);
    DruidCat_Separate = FindMaxRankSpellByExist(1943);

    DruidCat_Tiger = FindMaxRankSpellByExist(5217);
    DruidCat_FastMove = FindMaxRankSpellByExist(1850);
    DruidCat_Charge = FindMaxRankSpellByExist(16979);
    DruidCat_Surprise = FindMaxRankSpellByExist(75008);
    DruidCat_Sack = FindMaxRankSpellByExist(201427);
    DruidCat_Claw = FindMaxRankSpellByExist(91776);
    DruidCat_BackStab = FindMaxRankSpellByExist(5221);
    DruidCat_Attack = FindMaxRankSpellByExist(26103);
    DruidCat_Sweep = FindMaxRankSpellByExist(1822);
    DruidCat_Laceration = FindMaxRankSpellByExist(19820);

    DruidBear_DecAtt = FindMaxRankSpellByExist(10968);
    DruidBear_AddPower = FindMaxRankSpellByExist(8599);
    DruidBear_PowerLife = FindMaxRankSpellByExist(22842);
    DruidBear_Laceration = FindMaxRankSpellByExist(22689);
    DruidBear_Sweep = FindMaxRankSpellByExist(61896);
    DruidBear_Attack = FindMaxRankSpellByExist(61598);
    DruidBear_NextAtt = FindMaxRankSpellByExist(6807);
    DruidBear_Stun = FindMaxRankSpellByExist(1464);
    DruidBear_Charge = FindMaxRankSpellByExist(39435);
}

void BotDruidAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void BotDruidAI::EachTick()
{
    BotBGAI::EachTick();
    if (me->InArena())
    {
        Group* pGroup = me->GetGroup();
        if (pGroup)
        {
            Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
            for (Group::MemberSlot const& slot : memList)
            {
                Player* player = ObjectAccessor::FindPlayer(slot.guid);//.Guid  //org
                if (!player || me->GetMap() != player->GetMap() || !player->IsInWorld() || player->IsPlayerBot())
                    continue;
                return;
            }
        }
        else
            return;
    }
    if (me->HasAura(DruidStatus_Cat))
        UpEnergy();
    else if (me->HasAura(DruidStatus_Bear))
        UpPower();
    else
        UpMana();
}

void BotDruidAI::ResetBotAI()
{
    UpdateTalentType();
    BotBGAI::ResetBotAI();
    InitializeSpells();
}

uint32 BotDruidAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

uint32 BotDruidAI::GetEnergyPowerPer()
{
    float per = (float)me->GetPower(POWER_ENERGY) / (float)me->GetMaxPower(POWER_ENERGY);
    return (uint32)(per * 100);
}

uint32 BotDruidAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

bool BotDruidAI::NeedFlee()
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

void BotDruidAI::ProcessReady()
{
    ProcessNormalSpell();
}

void BotDruidAI::ProcessFlee()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    FleeMovement();

    if (DruidGuard_Harden && me->GetHealthPct() < 60 && TryCastSpell(DruidGuard_Harden, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (TryCastSpell(DruidGuard_AutoTwine, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && DruidGuard_TreeMan && TryCastSpell(DruidGuard_TreeMan, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (me->HasAura(DruidStatus_Travel))
    {
        if (HasAuraMechanic(me, Mechanics::MECHANIC_SNARE) || HasAuraMechanic(me, Mechanics::MECHANIC_ROOT))
        {
            SwitchStatus(0);
        }
    }
    else
    {
        Unit* pTarget = me->GetSelectedUnit();
        float healthPct = me->GetHealthPct();
        bool hasRelife = me->HasAura(DruidHeal_Relife, me->GetGUID());
        bool hasBurst = me->HasAura(DruidHeal_LifeBurst, me->GetGUID());
        bool hasMF = (pTarget && pTarget->HasAura(DruidCast_Moonfire, me->GetGUID())) ? true : false;
        bool hasIns = (pTarget && m_BotTalentType == 0 && pTarget->HasAura(DruidCast_Insect, me->GetGUID())) ? true : false;
        if (pTarget && (!hasRelife || !hasBurst || !hasMF || (m_BotTalentType == 0 && !hasIns)))
            SwitchStatus(0);
        /*else if (me->GetMap()->IsOutdoors(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
        {
            SwitchStatus(DruidStatus_Travel);
            return;
        }*/
        if (healthPct < 80 && !hasRelife && TryCastSpell(DruidHeal_Relife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 80 && !hasBurst && TryCastSpell(DruidHeal_LifeBurst, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (pTarget && !hasMF && TryCastSpell(DruidCast_Moonfire, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (pTarget && m_BotTalentType == 0 && !hasIns && TryCastSpell(DruidCast_Insect, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool BotDruidAI::ProcessSneak()
{
    if (m_BotTalentType != 1)
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;

    Unit* pUnit = me->GetSelectedUnit();
    if (pUnit && pUnit->IsAlive() && pUnit->ToPlayer() && pUnit->ToPlayer()->GetTeamId() != me->GetTeamId())   
    {
        if (!me->IsInCombat() && DruidStatus_Cat && DruidGuard_Sneak && !me->HasAura(DruidGuard_Sneak))
        {
            if (!me->HasAura(DruidStatus_Cat))
            {
                SwitchStatus(DruidStatus_Cat);
            }
            if (TryCastSpell(DruidGuard_Sneak, me) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastSneak();
                return false;
            }
        }
        if (me->HasAura(DruidStatus_Cat) && !me->HasAura(DruidGuard_Sneak))
        {
            if (TryCastSpell(DruidCat_FastMove, me) == SpellCastResult::SPELL_CAST_OK)
                return false;
            if (TryCastSpell(DruidCat_Charge, pUnit) == SpellCastResult::SPELL_CAST_OK)
            {
                OnCastCharge(pUnit);
                return false;
            }
        }
    }
    else
    {
        if (me->HasAura(DruidGuard_Sneak))
        {
            me->RemoveOwnedAura(DruidGuard_Sneak, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        }
    }
    return false;
}

bool BotDruidAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;

    if (!me->HasAura(DruidGuard_Sneak))
    {
        if (me->HasAura(DruidStatus_Travel))
            SwitchStatus(0);
        if (DruidIDLE_AOEFerityWish)
        {
            if (!me->HasAura(DruidIDLE_AOEFerityWish) && TryCastSpell(DruidIDLE_AOEFerityWish, me, true) == SpellCastResult::SPELL_CAST_OK)
                return false;
            Group* pGroup = me->GetGroup();
            if (pGroup)
            {
                Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
                for (Group::MemberSlot const& slot : memList)
                {
                    Player* player = ObjectAccessor::FindPlayer(slot.guid);//Guid
                    if (!player || !player->IsAlive() || me->GetMap() != player->GetMap() ||     
                        !player->IsInWorld() || me->GetDistance(player) > BOTAI_RANGESPELL_DISTANCE)
                        continue;
                    if (!player->HasAura(DruidIDLE_AOEFerityWish) && TryCastSpell(DruidIDLE_AOEFerityWish, player, true) == SpellCastResult::SPELL_CAST_OK)
                        return true;
                }
            }
        }
        if (DruidGuard_Thorns && !me->HasAura(DruidGuard_Thorns) && TryCastSpell(DruidGuard_Thorns, me, true) == SpellCastResult::SPELL_CAST_OK)
            return false;

        if (me->HasAura(m_UseMountID))
            return false;
        NearUnitVec needHealthPlayers = SearchNeedHealth(BOTAI_RANGESPELL_DISTANCE);
        if (needHealthPlayers.empty())
        {
            SwitchStatus(0);
            return TryUpMount();
        }
        //me->StopMoving();
        Unit* healthPlayer = needHealthPlayers[urand(0, needHealthPlayers.size() - 1)];
        ProcessHealthSpell(healthPlayer);
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return true;
    }

    ProcessSneak();
    return false;
}

void BotDruidAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (me->GetDistance(pTarget) > 30)
        return;
    uint32 manaPct = GetManaPowerPer();
    if (manaPct < 4)
        return;

    if (m_BotTalentType == 2 && DruidStatus_Tree && me->IsInCombat())
    {
        if (!me->HasAura(DruidStatus_Tree))
            SwitchStatus(DruidStatus_Tree);
    }
    else
        SwitchStatus(0);
    if (ProcessActive())
        return;
    NearUnitVec friends = SearchLifePctByFriendRange(pTarget, 70);
    if (friends.size() > 1)
    {
        if (m_BotTalentType == 2 && DruidHeal_AOEFerity && TryCastSpell(DruidHeal_AOEFerity, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (friends.size() > 2)
    {
        if (DruidHeal_AOETranquility && TryCastSpell(DruidHeal_AOETranquility, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    float healthPct = pTarget->GetHealthPct();
    bool hasRelife = pTarget->HasAura(DruidHeal_Relife, me->GetGUID());
    bool hasBurst = pTarget->HasAura(DruidHeal_LifeBurst, me->GetGUID());
    bool hasCoale = pTarget->HasAura(DruidHeal_Coalescence, me->GetGUID());
    if (healthPct < 30)
    {
        if (DruidHeal_MomentHeal && me->HasAura(DruidHeal_MomentHeal) && TryCastSpell(DruidHeal_Touch, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        else if (DruidHeal_MomentHeal && TryCastSpell(DruidHeal_MomentHeal, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 40 && m_BotTalentType == 2 && DruidHeal_MergerLife && (hasRelife || hasCoale))
    {
        if (TryCastSpell(DruidHeal_MergerLife, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!hasRelife && TryCastSpell(DruidHeal_Relife, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct < 75 && !hasBurst && TryCastSpell(DruidHeal_LifeBurst, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct < 75 && !hasCoale)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(DruidHeal_Coalescence, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 75 && DruidHeal_Nourishing && (hasRelife || hasCoale))
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(DruidHeal_Nourishing, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 60)
    {
        if (me->HasUnitState(UNIT_STATE_MOVING))
            me->StopMoving();
        if (TryCastSpell(DruidHeal_Touch, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

void BotDruidAI::ProcessMeleeSpell(Unit* pTarget)
{
    ProcessSneak();
    if (me->HasAura(DruidStatus_Bear))
        ProcessBearCombat(pTarget);
    else if (me->HasAura(DruidStatus_Cat))
        ProcessCatCombat(pTarget);
    else if (CanMeleeHealthMe())
        ProcessHealthSpell(me);
    else if (m_BotTalentType == 1)
    {
        if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() > 1)
        {
            SwitchStatus(DruidStatus_Bear);
            return;
        }
        else
        {
            SwitchStatus(DruidStatus_Cat);
            return;
        }
    }
    else
    {
        if (TargetHasMechanic(pTarget))
            return;
        if (pTarget->ToPlayer() && TargetIsRange(pTarget->ToPlayer()))
        {
            if (!BotUtility::ControllSpellDiminishing /*|| TargetIsNotDiminishingByType(pTarget, DiminishingGroup::DIMINISHING_CYCLONE)*/)
            {
                if (TryCastSpell(DruidGuard_Control, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
        else
        {
            if (!BotUtility::ControllSpellDiminishing/* || TargetIsNotDiminishingByType(pTarget, DiminishingGroup::DIMINISHING_CONTROLLED_ROOT)*/)
            {
                if (TryCastSpell(DruidGuard_Twine, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
}

void BotDruidAI::ProcessBearCombat(Unit* pTarget)
{
    if (CanMeleeHealthMe())
    {
        me->RemoveOwnedAura(DruidStatus_Bear, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        return;
    }
    uint32 rage = GetRagePowerPer();
    if (me->GetHealthPct() < 40)
    {
        if (rage > 40 && TryCastSpell(DruidBear_PowerLife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (DruidGuard_Harden && TryCastSpell(DruidGuard_Harden, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (me->GetHealthPct() > 80 || RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() < 2)
    {
        SwitchStatus(DruidStatus_Cat);
        return;
    }
    if (!pTarget->HasAuraState(AURA_STATE_FAERIE_FIRE) && TryCastSpell(DruidAssist_BeastSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (rage < 10 && TryCastSpell(DruidBear_AddPower, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (rage > 65 && RangeEnemyListByNonAura(DruidBear_DecAtt, NEEDFLEE_CHECKRANGE).size() >= 2 && TryCastSpell(DruidBear_DecAtt, me) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!pTarget->HasAura(DruidBear_Sweep, me->GetGUID()) && TryCastSpell(DruidBear_Sweep, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (DruidBear_Laceration && TryCastSpell(DruidBear_Laceration, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (!TargetHasMechanic(pTarget))
    {
        if (TryCastSpell(DruidBear_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (rage > 60)
        TryCastSpell(DruidBear_NextAtt, pTarget);
    if (rage > 40 && TryCastSpell(DruidBear_Attack, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void BotDruidAI::ProcessCatCombat(Unit* pTarget)
{
    if (CanMeleeHealthMe())
    {
        me->RemoveOwnedAura(DruidStatus_Cat, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        return;
    }
    if (me->HasAura(DruidGuard_Sneak))
    {
        if (HasAuraMechanic(pTarget, MECHANIC_STUN))
        {
            if (TryCastSpell(DruidCat_Sack, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (TryCastSpell(DruidCat_Surprise, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    else
    {
        if (!pTarget->HasAuraState(AURA_STATE_FAERIE_FIRE) && TryCastSpell(DruidAssist_BeastSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (me->GetHealthPct() < 40 || RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() > 2)
        {
            SwitchStatus(DruidStatus_Bear);
            return;
        }
        if (CanConsumeCombo(pTarget))
        {
            if (DruidCat_Roar && !HasAuraMechanic(me, Mechanics::MECHANIC_ENRAGED))
            {
                if (TryCastSpell(DruidCat_Roar, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (!TargetHasMechanic(pTarget))
            {
                if (TryCastSpell(DruidCat_Stun, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (DruidCat_Separate && !pTarget->HasAura(DruidCat_Separate, me->GetGUID()))
            {
                if (TryCastSpell(DruidCat_Separate, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            if (DruidCat_Bite && TryCastSpell(DruidCat_Bite, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else if (HasEnergyStore())
        {
            if (TryCastSpell(DruidCat_Tiger, me) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (!pTarget->HasAura(DruidCat_Sweep, me->GetGUID()) && TryCastSpell(DruidCat_Sweep, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            if (DruidCat_Laceration && TryCastSpell(DruidCat_Laceration, pTarget) == SpellCastResult::SPELL_CAST_OK)
                return;
            uint32 rate = urand(0, 99);
            if (rate < 10)
            {
                if (TryCastSpell(DruidCat_Claw, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            else if (rate >= 10 && rate < 55)
            {
                if (TryCastSpell(DruidCat_BackStab, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
            else
            {
                if (DruidCat_Attack && TryCastSpell(DruidCat_Attack, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
                if (TryCastSpell(DruidCat_BackStab, pTarget) == SpellCastResult::SPELL_CAST_OK)
                    return;
            }
        }
    }
}

void BotDruidAI::ProcessRangeSpell(Unit* pTarget)
{
    if (m_BotTalentType == 0 || m_BotTalentType == 2)
        ProcessBalanceCombat(pTarget);
    else if (m_BotTalentType == 1)
        ProcessSneak();
}

bool BotDruidAI::ProcessArenaHealthMember()
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

void BotDruidAI::ProcessBalanceCombat(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;
    if (ProcessArenaHealthMember())
        return;

    if (m_BotTalentType == 0 && DruidStatus_Bird && me->IsInCombat() && !me->HasAura(DruidStatus_Bird))
    {
        SwitchStatus(DruidStatus_Bird);
        return;
    }
    else if (me->HasAura(DruidStatus_Travel))
        SwitchStatus(0);
    if (ProcessActive())
        return;
    if (!pTarget->HasAura(DruidAssist_PersonSpirit) && TryCastSpell(DruidAssist_PersonSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    NearUnitVec rangeEnemy = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    if (m_BotTalentType == 0 && DruidAOE_FallStar && rangeEnemy.size() > 3)
    {
        if (TryCastSpell(DruidAOE_FallStar, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    NearUnitVec targetRangeEnemy = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (targetRangeEnemy.size() > 5)
    {
        if (m_BotTalentType == 0 && DruidGuard_TreeMan && TryCastSpell(DruidGuard_TreeMan, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(DruidAOE_Hurricane, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (ProcessControl(pTarget))
        return;
    if (!pTarget->HasAura(DruidCast_Moonfire, me->GetGUID()) && TryCastSpell(DruidCast_Moonfire, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && !pTarget->HasAura(DruidCast_Insect, me->GetGUID()) && TryCastSpell(DruidCast_Insect, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (pTarget->GetHealthPct() > 65 && urand(0, 99) < 15)
    {
        if (TryCastSpell(DruidCast_Spark, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    else
    {
        if (TryCastSpell(DruidCast_Anger, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
}

bool BotDruidAI::ProcessActive()
{
    if (!DruidAssist_Active)
        return false;
    if (GetManaPowerPer() < 10)
    {
        if (TryCastSpell(DruidAssist_Active, me) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    if (!me->InArena())
        return false;
    NearUnitVec friends = SearchFriend();
    for (Unit* pUnit : friends)
    {
        uint32 maxMana = pUnit->GetMaxPower(POWER_MANA);
        if (maxMana == 0)
            continue;
        float per = (float)pUnit->GetPower(POWER_MANA) / (float)maxMana;
        uint32 manaPct = (uint32)(per * 100);
        if (manaPct > 9 || manaPct <= 1)
            continue;
        if (TryCastSpell(DruidAssist_Active, pUnit) == SpellCastResult::SPELL_CAST_OK)
            return true;
    }
    return false;
}

bool BotDruidAI::CastingControlCommandSpell()
{
    if (m_LastControlTarget == ObjectGuid::Empty || !DruidGuard_Control)
        return false;
    if (!me->HasUnitState(UNIT_STATE_CASTING))
        return false;
    Spell* pCurrentSpell = me->GetCurrentSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL);
    if (pCurrentSpell)
    {
        if (pCurrentSpell->m_spellInfo && pCurrentSpell->m_spellInfo->Id == DruidGuard_Control)
        {
            return pCurrentSpell->m_targets.GetUnitTargetGUID() == m_LastControlTarget;
        }
    }
    if (!pCurrentSpell)
    {
        pCurrentSpell = me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL);
        if (pCurrentSpell && pCurrentSpell->m_spellInfo && pCurrentSpell->m_spellInfo->Id == DruidGuard_Control)
        {
            return pCurrentSpell->m_targets.GetUnitTargetGUID() == m_LastControlTarget;
        }
    }
    return false;
}

bool BotDruidAI::TryStartControlCommand()
{
    if (m_CruxControlTarget == ObjectGuid::Empty)
        return false;
    if (!DruidGuard_Control)
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    Player* pTarget = ObjectAccessor::FindPlayer(m_CruxControlTarget);
    if (!pTarget/* || !TargetIsNotDiminishingByType2(pTarget, DIMINISHING_CYCLONE)*/ || !pTarget->IsAlive() || TargetIsControl(pTarget)) 
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    NearUnitVec friends =SearchFriend();
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
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(DruidGuard_Control,DIFFICULTY_40);//,DIFFICULTY_40 //I WROTE
    if (!spellInfo || spellInfo->IsPassive())
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }
    /*if (me->GetGlobalCooldownMgr().HasGlobalCooldown(spellInfo))
        return true;
    if (!me->HasSpellCooldown(spellInfo->Id))
    {
        m_CruxControlTarget = ObjectGuid::Empty;
        return false;
    }*/

    if (me->IsWithinLOSInMap(pTarget) && me->GetDistance(pTarget) < BOTAI_RANGESPELL_DISTANCE)
    {
        if (me->HasAura(DruidStatus_Travel) || me->HasAura(DruidStatus_Bear) || me->HasAura(DruidStatus_Cat) || me->HasAura(DruidStatus_Tree))
        {
            SwitchStatus(0);
        }
        else
        {
            m_Movement->ClearMovement();
            TryCastSpell(DruidGuard_Control, pTarget);
        }
    }
    else
    {
        if (!IsNotMovement())
            m_Movement->MovementTo(m_CruxControlTarget);
    }
    return true;
}

float BotDruidAI::TryPushControlCommand(Player* pTarget)
{
    if (!pTarget || !pTarget->IsAlive() || !pTarget->IsInWorld() || me->GetMap() != pTarget->GetMap())
    {
        ClearCruxControlCommand();
        return -1;
    }
    if (!DruidGuard_Control)
        return -1;
    //if (!TargetIsNotDiminishingByType2(pTarget, DIMINISHING_CYCLONE))
    //	return -1;
    if (!BotUtility::SpellHasReady(me, DruidGuard_Control))
        return -1;
    m_CruxControlTarget = pTarget->GetGUID();
    m_LastControlTarget = m_CruxControlTarget;
    return me->GetDistance(pTarget->GetPosition());
}

bool BotDruidAI::CanMeleeHealthMe()
{
    if (GetManaPowerPer() > 15 && me->GetHealthPct() < 60 &&
        !HasAuraMechanic(me, Mechanics::MECHANIC_SILENCE))
    {
        if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() < 2)
            return true;
    }
    return false;
}

bool BotDruidAI::CanConsumeCombo(Unit* pTarget)
{
    uint8 combo = me->GetComboPoints();
    if (combo == 0)
        return false;
    float targetLife = pTarget->GetHealthPct();
    if (targetLife < 10)
        return true;
    else if (targetLife < 60 && combo > 2)
        return true;
    else if (combo >= 4)
        return true;
    return false;
}

bool BotDruidAI::TargetHasMechanic(Unit* pTarget)
{
    if (/*HasAuraMechanic(pTarget, Mechanics::MECHANIC_KNOCKOUT) ||*/
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_BANISH) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_FEAR) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_ROOT) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_STUN) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SLEEP) ||
        HasAuraMechanic(pTarget, Mechanics::MECHANIC_SAPPED))
        return true;
    return false;
}

bool BotDruidAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool BotDruidAI::IsRangeBotAI()
{
    if (m_BotTalentType == 0)
        return true;
    return false;
}

bool BotDruidAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool BotDruidAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool BotDruidAI::HasEnergyStore()
{
    return GetEnergyPowerPer() >= 60;
}

void BotDruidAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_ENERGY);
    uint32 power = me->GetPower(Powers::POWER_ENERGY);
    me->SetPower(Powers::POWER_ENERGY, (max / 30) + power);
}

void BotDruidAI::UpPower()
{
    uint32 max = me->GetMaxPower(Powers::POWER_RAGE);
    uint32 power = me->GetPower(Powers::POWER_RAGE);
    me->SetPower(Powers::POWER_RAGE, (max / 100) + power);
}

void BotDruidAI::UpMana()
{
    uint32 max = me->GetMaxPower(Powers::POWER_MANA);
    uint32 power = me->GetPower(Powers::POWER_MANA);
    me->SetPower(Powers::POWER_MANA, (max / 550) + power);
}

void BotDruidAI::SwitchStatus(uint32 status)
{
    if (status != DruidStatus_Travel && me->HasAura(DruidStatus_Travel))
        me->RemoveOwnedAura(DruidStatus_Travel, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Bear && me->HasAura(DruidStatus_Bear))
        me->RemoveOwnedAura(DruidStatus_Bear, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Cat && me->HasAura(DruidStatus_Cat))
        me->RemoveOwnedAura(DruidStatus_Cat, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Bird && me->HasAura(DruidStatus_Bird))
        me->RemoveOwnedAura(DruidStatus_Bird, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
    if (status != DruidStatus_Tree && me->HasAura(DruidStatus_Tree))
        me->RemoveOwnedAura(DruidStatus_Tree, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);

    if (status == DruidStatus_Travel)
        TryCastSpell(DruidStatus_Travel, me, true);
    else if (status == DruidStatus_Bear)
        TryCastSpell(DruidStatus_Bear, me, true);
    else if (status == DruidStatus_Cat)
        TryCastSpell(DruidStatus_Cat, me, true);
    else if (status == DruidStatus_Bird)
        TryCastSpell(DruidStatus_Bird, me, true);
    else if (status == DruidStatus_Tree)
        TryCastSpell(DruidStatus_Tree, me, true);
}

bool BotDruidAI::CanAttackSpell()
{
    if (me->HasAura(DruidStatus_Travel))
        return false;
    if (me->HasAura(DruidStatus_Bear))
        return false;
    if (me->HasAura(DruidStatus_Cat))
        return false;
    if (me->HasAura(DruidStatus_Tree))
        return false;
    return true;
}

bool BotDruidAI::ProcessControl(Unit* pTarget)
{
    if (!CanAttackSpell())
        return false;
    NearUnitVec rangeEnemy = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    for (Unit* player : rangeEnemy)
    {
        if (player == pTarget)// || player->GetTarget() != me->GetGUID())
            continue;
        if (TargetHasMechanic(player))
            continue;
        if (player->ToPlayer() && TargetIsRange(player->ToPlayer()))
        {
            if (m_NeedReserveCtrlSpell)
                continue;
            if (BotUtility::ControllSpellDiminishing /*&& !TargetIsNotDiminishingByType2(player, DiminishingGroup::DIMINISHING_CYCLONE)*/)
                continue;
            if (TryCastSpell(DruidGuard_Control, player) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
        else
        {
            if (BotUtility::ControllSpellDiminishing /*&& !TargetIsNotDiminishingByType2(player, DiminishingGroup::DIMINISHING_CONTROLLED_ROOT)*/)
                continue;
            if (TryCastSpell(DruidGuard_Twine, player) == SpellCastResult::SPELL_CAST_OK)
            {
                return true;
            }
        }
    }
    return false;
}

void BotDruidAI::OnCastSneak()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE);
    for (Unit* player : enemys)
    {
        player->SetTarget(ObjectGuid::Empty);
        player->ToPlayer()->SetSelection(ObjectGuid::Empty);
    }
}

void BotDruidAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    me->StopMoving();
    float rndOffset = 3.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    me->GetMap()->GetHeight(me->GetPhaseShift(), posX, posY, posZ);//GetPhaseMask
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);
}
