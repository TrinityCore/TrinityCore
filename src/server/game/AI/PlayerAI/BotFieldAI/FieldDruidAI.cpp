
#include "BotFieldClassAI.h"
#include "BotBGAIMovement.h"
#include "MovementPackets.h"

void FieldDruidAI::UpdateTalentType()
{
    m_BotTalentType = me->FindTalentType();// PlayerBotSetting::FindPlayerTalentType(me);
}

void FieldDruidAI::ResetBotAI()
{
    UpdateTalentType();
    BotFieldAI::ResetBotAI();
    InitializeSpells(me);
    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(DruidIDLE_AOEFerityWish);
    m_WishStore.RegisterWish(DruidIDLE_FerityWish);
    SwitchStatus(0);
}

void FieldDruidAI::OnLevelUp(uint32 talentType)
{
    if (talentType < 3)
        m_BotTalentType = talentType;
    InitializeSpells(me);

    m_WishStore.ClearWishs();
    m_WishStore.RegisterWish(DruidIDLE_AOEFerityWish);
    m_WishStore.RegisterWish(DruidIDLE_FerityWish);
}

uint32 FieldDruidAI::GetManaPowerPer()
{
    float per = (float)me->GetPower(POWER_MANA) / (float)me->GetMaxPower(POWER_MANA);
    return (uint32)(per * 100);
}

uint32 FieldDruidAI::GetEnergyPowerPer()
{
    float per = (float)me->GetPower(POWER_ENERGY) / (float)me->GetMaxPower(POWER_ENERGY);
    return (uint32)(per * 100);
}

uint32 FieldDruidAI::GetRagePowerPer()
{
    float per = (float)me->GetPower(POWER_RAGE) / (float)me->GetMaxPower(POWER_RAGE);
    return (uint32)(per * 100);
}

bool FieldDruidAI::NeedFlee()
{
    if (m_Flee.Fleeing())
        return true;
    if (m_BotTalentType == 1)
        return false;
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

void FieldDruidAI::ProcessFlee()
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
            me->RemoveOwnedAura(DruidStatus_Travel, ObjectGuid::Empty, 0, AURA_REMOVE_BY_CANCEL);
        }
    }
    else
    {
        float healthPct = me->GetHealthPct();
        bool hasRelife = me->HasAura(DruidHeal_Relife);
        bool hasBurst = me->HasAura(DruidHeal_LifeBurst);
        if (healthPct < 60 && !hasRelife && TryCastSpell(DruidHeal_Relife, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (healthPct < 55 && !hasBurst && TryCastSpell(DruidHeal_LifeBurst, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        //if (me->GetMap()->IsOutdoors(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
        //{
        //    SwitchStatus(DruidStatus_Travel);
        //    return;
        //}
    }
}

bool FieldDruidAI::ProcessSneak()
{
    if (m_BotTalentType != 1)
        return false;
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;

    Unit* pUnit = me->GetSelectedUnit();
    if (pUnit && pUnit->IsAlive() && me->IsValidAttackTarget(pUnit) && me->GetDistance(pUnit) < 20)
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

bool FieldDruidAI::ProcessNormalSpell()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return true;

    if (!me->HasAura(DruidGuard_Sneak))
    {
        if (me->HasAura(DruidStatus_Travel))
            SwitchStatus(0);
        if (me->HasAura(m_UseMountID))
            return false;
        if (DruidIDLE_AOEFerityWish)
        {
            if (!me->HasAura(DruidIDLE_AOEFerityWish) && TryCastSpell(DruidIDLE_AOEFerityWish, me, true) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        else if (DruidIDLE_FerityWish)
        {
            if (!me->HasAura(DruidIDLE_FerityWish) && TryCastSpell(DruidIDLE_FerityWish, me, true) == SpellCastResult::SPELL_CAST_OK)
                return false;
        }
        if (DruidGuard_Thorns && !me->HasAura(DruidGuard_Thorns) && TryCastSpell(DruidGuard_Thorns, me, true) == SpellCastResult::SPELL_CAST_OK)
            return false;

        NearUnitVec needHealthPlayers = SearchNeedHealth(BOTAI_RANGESPELL_DISTANCE);
        if (needHealthPlayers.empty())
        {
            SwitchStatus(0);
            return TryUpMount();
        }
        Unit* healthPlayer = needHealthPlayers[urand(0, needHealthPlayers.size() - 1)];
        ProcessHealthSpell(healthPlayer);
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return true;
    }

    ProcessSneak();
    return false;
}

void FieldDruidAI::ProcessHealthSpell(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (m_BotTalentType == 2 && DruidStatus_Tree && me->IsInCombat() && !me->HasAura(DruidStatus_Tree))
    {
        SwitchStatus(DruidStatus_Tree);
    }
    else if (me->HasAura(DruidStatus_Travel))
        SwitchStatus(0);
    ProcessCombatRevive();
    if (DruidAssist_Active && GetManaPowerPer() < 30)
    {
        if (TryCastSpell(DruidAssist_Active, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    NearUnitVec friends = SearchLifePctByFriendRange(pTarget, BOTAI_RANGESPELL_DISTANCE);
    if (friends.size() > 3)
    {
        if (DruidHeal_AOETranquility && TryCastSpell(DruidHeal_AOETranquility, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (friends.size() > 2)
    {
        if (m_BotTalentType == 2 && DruidHeal_AOEFerity && TryCastSpell(DruidHeal_AOEFerity, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }

    float healthPct = pTarget->GetHealthPct();
    bool hasRelife = pTarget->HasAura(DruidHeal_Relife);
    bool hasBurst = pTarget->HasAura(DruidHeal_LifeBurst);
    bool hasCoale = pTarget->HasAura(DruidHeal_Coalescence);
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
    if (healthPct < 75 && !hasCoale && TryCastSpell(DruidHeal_Coalescence, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (healthPct < 75 && DruidHeal_Nourishing && (hasRelife || hasCoale))
    {
        if (TryCastSpell(DruidHeal_Nourishing, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (healthPct < 60 && TryCastSpell(DruidHeal_Touch, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
}

void FieldDruidAI::ProcessMeleeSpell(Unit* pTarget)
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
}

void FieldDruidAI::ProcessBearCombat(Unit* pTarget)
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
    if (!pTarget->HasAura(DruidBear_Sweep) && TryCastSpell(DruidBear_Sweep, pTarget) == SpellCastResult::SPELL_CAST_OK)
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

void FieldDruidAI::ProcessCatCombat(Unit* pTarget)
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
            if (DruidCat_Separate && !pTarget->HasAura(DruidCat_Separate))
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
            if (!pTarget->HasAura(DruidCat_Sweep) && TryCastSpell(DruidCat_Sweep, pTarget) == SpellCastResult::SPELL_CAST_OK)
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

void FieldDruidAI::ProcessRangeSpell(Unit* pTarget)
{
    if (m_BotTalentType == 0 || m_BotTalentType == 2)
        ProcessBalanceCombat(pTarget);
    else if (m_BotTalentType == 1)
        ProcessSneak();
}

void FieldDruidAI::ProcessBalanceCombat(Unit* pTarget)
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    //if (m_BotTalentType == 2 && GetManaPowerPer() < 75)
    //	return;
    if (m_BotTalentType == 0 && DruidStatus_Bird && me->IsInCombat() && !me->HasAura(DruidStatus_Bird))
    {
        SwitchStatus(DruidStatus_Bird);
        return;
    }
    else if (me->HasAura(DruidStatus_Travel))
        SwitchStatus(0);
    else if (me->HasAura(DruidStatus_Tree))
        SwitchStatus(0);
    if (DruidAssist_Active && GetManaPowerPer() < 30)
    {
        if (TryCastSpell(DruidAssist_Active, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pTarget->HasAura(DruidAssist_PersonSpirit) && TryCastSpell(DruidAssist_PersonSpirit, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;

    NearUnitVec rangeEnemy = RangeEnemyListByHasAura(0, BOTAI_RANGESPELL_DISTANCE);
    if (m_BotTalentType == 0 && DruidAOE_FallStar && rangeEnemy.size() > 3)
    {
        if (TryCastSpell(DruidAOE_FallStar, me) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    NearUnitVec targetRangeEnemy = RangeEnemyListByTargetRange(pTarget, NEEDFLEE_CHECKRANGE);
    if (targetRangeEnemy.size() > 5 && m_BotTalentType != 2)
    {
        if (m_BotTalentType == 0 && DruidGuard_TreeMan && TryCastSpell(DruidGuard_TreeMan, me) == SpellCastResult::SPELL_CAST_OK)
            return;
        if (TryCastSpell(DruidAOE_Hurricane, pTarget) == SpellCastResult::SPELL_CAST_OK)
            return;
    }
    if (!pTarget->HasAura(DruidCast_Moonfire) && TryCastSpell(DruidCast_Moonfire, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    if (m_BotTalentType == 0 && !pTarget->HasAura(DruidCast_Insect) && TryCastSpell(DruidCast_Insect, pTarget) == SpellCastResult::SPELL_CAST_OK)
        return;
    for (Unit* player : rangeEnemy)
    {
        if (player == pTarget || player->GetTarget() != me->GetGUID())//GetTargetGUID
            continue;
        if (TargetHasMechanic(player))
            continue;
        if (player->ToPlayer() && TargetIsRange(player->ToPlayer()))
        {
            if (TryCastSpell(DruidGuard_Control, player) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
        else
        {
            if (TryCastSpell(DruidGuard_Twine, player) == SpellCastResult::SPELL_CAST_OK)
                return;
        }
    }
    if (DruidCast_Spark && pTarget->GetHealthPct() > 65)
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

void FieldDruidAI::ProcessCombatRevive()
{
    if (DruidIDLE_CombatReive == 0)
        return;
    if (!me->IsAlive() || me->HasUnitState(UNIT_STATE_CASTING))
        return;
    //Group* pGroup = me->GetGroup();
    //if (!pGroup)
    //	return;
    //std::vector<ObjectGuid>& needPlayers = pGroup->GetGroupMemberFromNeedRevivePlayer(me->GetMapId());
    //if (needPlayers.empty())
    //	return;
    //ObjectGuid& guid = needPlayers[urand(0, needPlayers.size() - 1)];
    //Player* pRevive = ObjectAccessor::FindPlayer(guid);
    //if (!pRevive || pRevive->IsAlive())
    //	return;
    //if (!me->IsWithinLOSInMap(pRevive) || me->GetDistance(pRevive->GetPosition()) > 15)
    //	return;
    //TryCastSpell(DruidIDLE_CombatReive, pRevive, true);
}

bool FieldDruidAI::CanMeleeHealthMe()
{
    if (GetManaPowerPer() > 15 && me->GetHealthPct() < 60 &&
        !HasAuraMechanic(me, Mechanics::MECHANIC_SILENCE))
    {
        if (RangeEnemyListByTargetIsMe(BOTAI_RANGESPELL_DISTANCE).size() < 2)
            return true;
    }
    return false;
}

bool FieldDruidAI::CanConsumeCombo(Unit* pTarget)
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

bool FieldDruidAI::TargetHasMechanic(Unit* pTarget)
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

uint32 FieldDruidAI::GetReviveSpell()
{
    return DruidIDLE_Revive;
}

bool FieldDruidAI::IsMeleeBotAI()
{
    if (m_BotTalentType == 1)
        return true;
    return false;
}

bool FieldDruidAI::IsRangeBotAI()
{
    if (m_BotTalentType != 1)
        return true;
    return false;
}

bool FieldDruidAI::IsHealerBotAI()
{
    if (m_BotTalentType == 2)
        return true;
    return false;
}

bool FieldDruidAI::IsAttacker()
{
    return (m_BotTalentType != 2);
}

bool FieldDruidAI::HasEnergyStore()
{
    return GetEnergyPowerPer() >= 60;
}

void FieldDruidAI::UpEnergy()
{
    uint32 max = me->GetMaxPower(Powers::POWER_ENERGY);
    uint32 power = me->GetPower(Powers::POWER_ENERGY);
    me->SetPower(Powers::POWER_ENERGY, (max / 20) + power);
}

void FieldDruidAI::SwitchStatus(uint32 status)
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

void FieldDruidAI::OnCastSneak()
{
    NearUnitVec enemys = RangeEnemyListByTargetIsMe(BOTAI_SEARCH_RANGE);
    for (Unit* player : enemys)
    {
        player->SetTarget(ObjectGuid::Empty);
        //player->ToPlayer()->SetSelection(ObjectGuid::Empty);
    }
}

void FieldDruidAI::OnCastCharge(Unit* pTarget)
{
    if (!pTarget)
        return;
    m_Movement->ClearMovement();
    float rndOffset = 3.0f;
    float posX = pTarget->GetPositionX() + frand(-rndOffset, rndOffset);
    float posY = pTarget->GetPositionY() + frand(-rndOffset, rndOffset);
    float posZ = pTarget->GetPositionZ();
    //me->GetMap()->GetHeight(me->GetPhaseMask(), posX, posY, posZ);
    me->UpdatePosition(posX, posY, posZ, me->GetOrientation(), true);

    WorldSession* pSession = me->GetSession();
    WorldPacket opcode2(CMSG_MOVE_TELEPORT_ACK);
    WorldPackets::Movement::MoveTeleportAck pakcet(std::move(opcode2));
    pakcet.MoverGUID = me->GetGUID();
    pSession->HandleMoveTeleportAck(pakcet);
    //m_Movement->SyncPosition(Position(posX, posY, posZ, me->GetOrientation()), true);
}
