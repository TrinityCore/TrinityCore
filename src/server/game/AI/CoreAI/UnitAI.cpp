/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "UnitAI.h"
#include "Containers.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include <sstream>

void UnitAI::AttackStart(Unit* victim)
{
    if (victim && me->Attack(victim, true))
    {
        // Clear distracted state on attacking
        if (me->HasUnitState(UNIT_STATE_DISTRACTED))
        {
            me->ClearUnitState(UNIT_STATE_DISTRACTED);
            me->GetMotionMaster()->Clear();
        }
        me->GetMotionMaster()->MoveChase(victim);
    }
}

void UnitAI::InitializeAI()
{
    if (!me->isDead())
        Reset();
}

void UnitAI::OnCharmed(bool isNew)
{
    if (!isNew)
        me->ScheduleAIChange();
}

void UnitAI::AttackStartCaster(Unit* victim, float dist)
{
    if (victim && me->Attack(victim, false))
        me->GetMotionMaster()->MoveChase(victim, dist);
}

bool UnitAI::DoSpellAttackIfReady(uint32 spellId)
{
    if (me->HasUnitState(UNIT_STATE_CASTING) || !me->isAttackReady())
        return true;

    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, me->GetMap()->GetDifficultyID()))
    {
        if (me->IsWithinCombatRange(me->GetVictim(), spellInfo->GetMaxRange(false)))
        {
            me->CastSpell(me->GetVictim(), spellId, me->GetMap()->GetDifficultyID());
            me->resetAttackTimer();
            return true;
        }
    }

    return false;
}

Unit* UnitAI::SelectTarget(SelectTargetMethod targetType, uint32 position, float dist, bool playerOnly, bool withTank, int32 aura)
{
    return SelectTarget(targetType, position, DefaultTargetSelector(me, dist, playerOnly, withTank, aura));
}

void UnitAI::SelectTargetList(std::list<Unit*>& targetList, uint32 num, SelectTargetMethod targetType, uint32 offset, float dist, bool playerOnly, bool withTank, int32 aura)
{
    SelectTargetList(targetList, num, targetType, offset, DefaultTargetSelector(me, dist, playerOnly, withTank, aura));
}

SpellCastResult UnitAI::DoCast(uint32 spellId)
{
    Unit* target = nullptr;
    AITarget aiTargetType = AITARGET_SELF;
    if (AISpellInfoType const* info = GetAISpellInfo(spellId, me->GetMap()->GetDifficultyID()))
        aiTargetType = info->target;

    switch (aiTargetType)
    {
        default:
        case AITARGET_SELF:
            target = me;
            break;
        case AITARGET_VICTIM:
            target = me->GetVictim();
            break;
        case AITARGET_ENEMY:
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, me->GetMap()->GetDifficultyID()))
            {
                DefaultTargetSelector targetSelectorInner(me, spellInfo->GetMaxRange(false), false, true, 0);
                auto targetSelector = [&](Unit const* candidate) -> bool
                {
                    if (!candidate->IsPlayer())
                    {
                        if (spellInfo->HasAttribute(SPELL_ATTR3_ONLY_ON_PLAYER))
                            return false;

                        if (spellInfo->HasAttribute(SPELL_ATTR5_NOT_ON_PLAYER_CONTROLLED_NPC) && candidate->IsControlledByPlayer())
                            return false;
                    }
                    else if (spellInfo->HasAttribute(SPELL_ATTR5_NOT_ON_PLAYER))
                        return false;

                    return targetSelectorInner(candidate);
                };
                target = SelectTarget(SelectTargetMethod::Random, 0, targetSelector);
            }
            break;
        }
        case AITARGET_ALLY:
            target = me;
            break;
        case AITARGET_BUFF:
            target = me;
            break;
        case AITARGET_DEBUFF:
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, me->GetMap()->GetDifficultyID()))
            {
                float range = spellInfo->GetMaxRange(false);

                DefaultTargetSelector targetSelectorInner(me, range, false, true, -(int32)spellId);
                auto targetSelector = [&](Unit const* candidate) -> bool
                {
                    if (!candidate->IsPlayer())
                    {
                        if (spellInfo->HasAttribute(SPELL_ATTR3_ONLY_ON_PLAYER))
                            return false;

                        if (spellInfo->HasAttribute(SPELL_ATTR5_NOT_ON_PLAYER_CONTROLLED_NPC) && candidate->IsControlledByPlayer())
                            return false;
                    }
                    else if (spellInfo->HasAttribute(SPELL_ATTR5_NOT_ON_PLAYER))
                        return false;

                    return targetSelectorInner(candidate);
                };
                if (!spellInfo->HasAuraInterruptFlag(SpellAuraInterruptFlags::NOT_VICTIM) && targetSelector(me->GetVictim()))
                    target = me->GetVictim();
                else
                    target = SelectTarget(SelectTargetMethod::Random, 0, targetSelector);
            }
            break;
        }
    }

    if (target)
        return me->CastSpell(target, spellId, false);

    return SPELL_FAILED_BAD_TARGETS;
}

SpellCastResult UnitAI::DoCast(Unit* victim, uint32 spellId, CastSpellExtraArgs const& args)
{
    if (me->HasUnitState(UNIT_STATE_CASTING) && !(args.TriggerFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))
        return SPELL_FAILED_SPELL_IN_PROGRESS;

    return me->CastSpell(victim, spellId, args);
}

SpellCastResult UnitAI::DoCastVictim(uint32 spellId, CastSpellExtraArgs const& args)
{
    if (Unit* victim = me->GetVictim())
        return DoCast(victim, spellId, args);

    return SPELL_FAILED_BAD_TARGETS;
}

#define UPDATE_TARGET(a) {if (AIInfo->target<a) AIInfo->target=a;}

void UnitAI::FillAISpellInfo()
{
    sSpellMgr->ForEachSpellInfo([](SpellInfo const* spellInfo)
    {
        AISpellInfoType* AIInfo = &AISpellInfo[{ spellInfo->Id, spellInfo->Difficulty }];

        if (spellInfo->HasAttribute(SPELL_ATTR0_ALLOW_CAST_WHILE_DEAD))
            AIInfo->condition = AICOND_DIE;
        else if (spellInfo->IsPassive() || spellInfo->GetDuration() == -1)
            AIInfo->condition = AICOND_AGGRO;
        else
            AIInfo->condition = AICOND_COMBAT;

        if (AIInfo->cooldown.count() < int32(spellInfo->RecoveryTime))
            AIInfo->cooldown = Milliseconds(spellInfo->RecoveryTime);

        if (spellInfo->GetMaxRange(false))
        {
            for (SpellEffectInfo const& effect : spellInfo->GetEffects())
            {
                uint32 targetType = effect.TargetA.GetTarget();

                if (targetType == TARGET_UNIT_TARGET_ENEMY
                    || targetType == TARGET_DEST_TARGET_ENEMY)
                    UPDATE_TARGET(AITARGET_VICTIM)
                else if (targetType == TARGET_UNIT_DEST_AREA_ENEMY)
                    UPDATE_TARGET(AITARGET_ENEMY)

                if (effect.Effect == SPELL_EFFECT_APPLY_AURA)
                {
                    if (targetType == TARGET_UNIT_TARGET_ENEMY)
                        UPDATE_TARGET(AITARGET_DEBUFF)
                    else if (spellInfo->IsPositive())
                        UPDATE_TARGET(AITARGET_BUFF)
                }
            }
        }
        AIInfo->realCooldown = Milliseconds(spellInfo->RecoveryTime + spellInfo->StartRecoveryTime);
        AIInfo->maxRange = spellInfo->GetMaxRange(false) * 3 / 4;

        AIInfo->Effects = 0;
        AIInfo->Targets = 0;

        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
        {
            // Spell targets self.
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER)
                AIInfo->Targets |= 1 << (SELECT_TARGET_SELF - 1);

            // Spell targets a single enemy.
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_TARGET_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_DEST_TARGET_ENEMY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_SINGLE_ENEMY - 1);

            // Spell targets AoE at enemy.
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_SRC_AREA_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_DEST_AREA_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_SRC_CASTER ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_DEST_DYNOBJ_ENEMY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_AOE_ENEMY - 1);

            // Spell targets an enemy.
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_TARGET_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_DEST_TARGET_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_SRC_AREA_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_DEST_AREA_ENEMY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_SRC_CASTER ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_DEST_DYNOBJ_ENEMY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_ANY_ENEMY - 1);

            // Spell targets a single friend (or self).
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_TARGET_ALLY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_TARGET_PARTY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_SINGLE_FRIEND - 1);

            // Spell targets AoE friends.
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER_AREA_PARTY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_LASTTARGET_AREA_PARTY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_SRC_CASTER)
                AIInfo->Targets |= 1 << (SELECT_TARGET_AOE_FRIEND - 1);

            // Spell targets any friend (or self).
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_TARGET_ALLY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_TARGET_PARTY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER_AREA_PARTY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_LASTTARGET_AREA_PARTY ||
                spellEffectInfo.TargetA.GetTarget() == TARGET_SRC_CASTER)
                AIInfo->Targets |= 1 << (SELECT_TARGET_ANY_FRIEND - 1);

            // Make sure that this spell includes a damage effect.
            if (spellEffectInfo.Effect == SPELL_EFFECT_SCHOOL_DAMAGE ||
                spellEffectInfo.Effect == SPELL_EFFECT_INSTAKILL ||
                spellEffectInfo.Effect == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE ||
                spellEffectInfo.Effect == SPELL_EFFECT_HEALTH_LEECH)
                AIInfo->Effects |= 1 << (SELECT_EFFECT_DAMAGE - 1);

            // Make sure that this spell includes a healing effect (or an apply aura with a periodic heal).
            if (spellEffectInfo.Effect == SPELL_EFFECT_HEAL ||
                spellEffectInfo.Effect == SPELL_EFFECT_HEAL_MAX_HEALTH ||
                spellEffectInfo.Effect == SPELL_EFFECT_HEAL_MECHANICAL ||
                (spellEffectInfo.Effect == SPELL_EFFECT_APPLY_AURA && spellEffectInfo.ApplyAuraName == 8))
                AIInfo->Effects |= 1 << (SELECT_EFFECT_HEALING - 1);

            // Make sure that this spell applies an aura.
            if (spellEffectInfo.Effect == SPELL_EFFECT_APPLY_AURA)
                AIInfo->Effects |= 1 << (SELECT_EFFECT_AURA - 1);
        }
    });
}

Unit* UnitAI::FinalizeTargetSelection(std::list<Unit*>& targetList, SelectTargetMethod targetType)
{
    // maybe nothing fulfills the predicate
    if (targetList.empty())
        return nullptr;

    switch (targetType)
    {
        case SelectTargetMethod::MaxThreat:
        case SelectTargetMethod::MinThreat:
        case SelectTargetMethod::MaxDistance:
        case SelectTargetMethod::MinDistance:
            return targetList.front();
        case SelectTargetMethod::Random:
            return Trinity::Containers::SelectRandomContainerElement(targetList);
        default:
            break;
    }

    return nullptr;
}

bool UnitAI::PrepareTargetListSelection(std::list<Unit*>& targetList, SelectTargetMethod targetType, uint32 offset)
{
    targetList.clear();
    ThreatManager& mgr = me->GetThreatManager();
    // shortcut: we're gonna ignore the first <offset> elements, and there's at most <offset> elements, so we ignore them all - nothing to do here
    if (mgr.GetThreatListSize() <= offset)
        return false;

    if (targetType == SelectTargetMethod::MaxDistance || targetType == SelectTargetMethod::MinDistance)
    {
        for (ThreatReference const* ref : mgr.GetUnsortedThreatList())
        {
            if (ref->IsOffline())
                continue;

            targetList.push_back(ref->GetVictim());
        }
    }
    else
    {
        Unit* currentVictim = mgr.GetCurrentVictim();
        if (currentVictim)
            targetList.push_back(currentVictim);

        for (ThreatReference const* ref : mgr.GetSortedThreatList())
        {
            if (ref->IsOffline())
                continue;

            Unit* thisTarget = ref->GetVictim();
            if (thisTarget != currentVictim)
                targetList.push_back(thisTarget);
        }
    }

    // shortcut: the list isn't gonna get any larger
    if (targetList.size() <= offset)
    {
        targetList.clear();
        return false;
    }

    // right now, list is unsorted for DISTANCE types - re-sort by SelectTargetMethod::MaxDistance
    if (targetType == SelectTargetMethod::MaxDistance || targetType == SelectTargetMethod::MinDistance)
        targetList.sort(Trinity::ObjectDistanceOrderPred(me, targetType == SelectTargetMethod::MinDistance));

    // now the list is MAX sorted, reverse for MIN types
    if (targetType == SelectTargetMethod::MinThreat)
        targetList.reverse();

    // ignore the first <offset> elements
    while (offset)
    {
        targetList.pop_front();
        --offset;
    }

    return true;
}

void UnitAI::FinalizeTargetListSelection(std::list<Unit*>& targetList, uint32 num, SelectTargetMethod targetType)
{
    if (targetList.size() <= num)
        return;

    if (targetType == SelectTargetMethod::Random)
        Trinity::Containers::RandomResize(targetList, num);
    else
        targetList.resize(num);
}

std::string UnitAI::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
         << "Me: " << (me ? me->GetDebugInfo() : "NULL");
    return sstr.str();
}
