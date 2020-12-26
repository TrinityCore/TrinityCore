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
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "LootMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "QuestDef.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

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

void UnitAI::AttackStartCaster(Unit* victim, float dist)
{
    if (victim && me->Attack(victim, false))
        me->GetMotionMaster()->MoveChase(victim, dist);
}

void UnitAI::DoMeleeAttackIfReady()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    Unit* victim = me->GetVictim();

    if (!me->IsWithinMeleeRange(victim))
        return;

    //Make sure our attack is ready and we aren't currently casting before checking distance
    if (me->isAttackReady())
    {
        if (ShouldSparWith(victim))
            me->FakeAttackerStateUpdate(victim);
        else
            me->AttackerStateUpdate(victim);

        me->resetAttackTimer();
    }

    if (me->haveOffhandWeapon() && me->isAttackReady(OFF_ATTACK))
    {
        if (ShouldSparWith(victim))
            me->FakeAttackerStateUpdate(victim, OFF_ATTACK);
        else
            me->AttackerStateUpdate(victim, OFF_ATTACK);

        me->resetAttackTimer(OFF_ATTACK);
    }
}

bool UnitAI::DoSpellAttackIfReady(uint32 spellId)
{
    if (me->HasUnitState(UNIT_STATE_CASTING) || !me->isAttackReady())
        return true;

    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, me->GetMap()->GetDifficultyID()))
    {
        if (me->IsWithinCombatRange(me->GetVictim(), spellInfo->GetMaxRange(false)))
        {
            me->CastSpell(me->GetVictim(), spellInfo, TRIGGERED_NONE);
            me->resetAttackTimer();
            return true;
        }
    }

    return false;
}

Unit* UnitAI::SelectTarget(SelectAggroTarget targetType, uint32 position, float dist, bool playerOnly, bool withTank, int32 aura)
{
    return SelectTarget(targetType, position, DefaultTargetSelector(me, dist, playerOnly, withTank, aura));
}

void UnitAI::SelectTargetList(std::list<Unit*>& targetList, uint32 num, SelectAggroTarget targetType, uint32 offset, float dist, bool playerOnly, bool withTank, int32 aura)
{
    SelectTargetList(targetList, num, targetType, offset, DefaultTargetSelector(me, dist, playerOnly, withTank, aura));
}

void UnitAI::DoCast(uint32 spellId)
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
                bool playerOnly = spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS);
                target = SelectTarget(SELECT_TARGET_RANDOM, 0, spellInfo->GetMaxRange(false), playerOnly);
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
                bool playerOnly = spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS);
                float range = spellInfo->GetMaxRange(false);

                DefaultTargetSelector targetSelector(me, range, playerOnly, true, -(int32)spellId);
                if (!spellInfo->HasAuraInterruptFlag(AURA_INTERRUPT_FLAG_NOT_VICTIM) && targetSelector(me->GetVictim()))
                    target = me->GetVictim();
                else
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, targetSelector);
            }
            break;
        }
    }

    if (target)
        me->CastSpell(target, spellId, false);
}

void UnitAI::DoCast(Unit* victim, uint32 spellId, bool triggered)
{
    if (!victim || (me->HasUnitState(UNIT_STATE_CASTING) && !triggered))
        return;

    me->CastSpell(victim, spellId, triggered);
}

void UnitAI::DoCastVictim(uint32 spellId, bool triggered)
{
    if (!me->GetVictim() || (me->HasUnitState(UNIT_STATE_CASTING) && !triggered))
        return;

    me->CastSpell(me->GetVictim(), spellId, triggered);
}

void UnitAI::DoCastAOE(uint32 spellId, bool triggered)
{
    if (!triggered && me->HasUnitState(UNIT_STATE_CASTING))
        return;

    me->CastSpell(nullptr, spellId, triggered);
}

#define UPDATE_TARGET(a) {if (AIInfo->target<a) AIInfo->target=a;}

void UnitAI::FillAISpellInfo()
{
    sSpellMgr->ForEachSpellInfo([](SpellInfo const* spellInfo)
    {
        AISpellInfoType* AIInfo = &AISpellInfo[{ spellInfo->Id, spellInfo->Difficulty }];

        if (spellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_DEAD))
            AIInfo->condition = AICOND_DIE;
        else if (spellInfo->IsPassive() || spellInfo->GetDuration() == -1)
            AIInfo->condition = AICOND_AGGRO;
        else
            AIInfo->condition = AICOND_COMBAT;

        if (AIInfo->cooldown < spellInfo->RecoveryTime)
            AIInfo->cooldown = spellInfo->RecoveryTime;

        if (!spellInfo->GetMaxRange(false))
            UPDATE_TARGET(AITARGET_SELF)
        else
        {
            for (SpellEffectInfo const* effect : spellInfo->GetEffects())
            {
                if (!effect)
                    continue;

                uint32 targetType = effect->TargetA.GetTarget();

                if (targetType == TARGET_UNIT_TARGET_ENEMY
                    || targetType == TARGET_DEST_TARGET_ENEMY)
                    UPDATE_TARGET(AITARGET_VICTIM)
                else if (targetType == TARGET_UNIT_DEST_AREA_ENEMY)
                    UPDATE_TARGET(AITARGET_ENEMY)

                if (effect->Effect == SPELL_EFFECT_APPLY_AURA)
                {
                    if (targetType == TARGET_UNIT_TARGET_ENEMY)
                        UPDATE_TARGET(AITARGET_DEBUFF)
                    else if (spellInfo->IsPositive())
                        UPDATE_TARGET(AITARGET_BUFF)
                }
            }
        }
        AIInfo->realCooldown = spellInfo->RecoveryTime + spellInfo->StartRecoveryTime;
        AIInfo->maxRange = spellInfo->GetMaxRange(false) * 3 / 4;

        AIInfo->Effects = 0;
        AIInfo->Targets = 0;

        for (SpellEffectInfo const* effect : spellInfo->GetEffects())
        {
            if (!effect)
                continue;

            // Spell targets self.
            if (effect->TargetA.GetTarget() == TARGET_UNIT_CASTER)
                AIInfo->Targets |= 1 << (SELECT_TARGET_SELF - 1);

            // Spell targets a single enemy.
            if (effect->TargetA.GetTarget() == TARGET_UNIT_TARGET_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_DEST_TARGET_ENEMY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_SINGLE_ENEMY - 1);

            // Spell targets AoE at enemy.
            if (effect->TargetA.GetTarget() == TARGET_UNIT_SRC_AREA_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_DEST_AREA_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_SRC_CASTER ||
                effect->TargetA.GetTarget() == TARGET_DEST_DYNOBJ_ENEMY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_AOE_ENEMY - 1);

            // Spell targets an enemy.
            if (effect->TargetA.GetTarget() == TARGET_UNIT_TARGET_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_DEST_TARGET_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_SRC_AREA_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_DEST_AREA_ENEMY ||
                effect->TargetA.GetTarget() == TARGET_SRC_CASTER ||
                effect->TargetA.GetTarget() == TARGET_DEST_DYNOBJ_ENEMY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_ANY_ENEMY - 1);

            // Spell targets a single friend (or self).
            if (effect->TargetA.GetTarget() == TARGET_UNIT_CASTER ||
                effect->TargetA.GetTarget() == TARGET_UNIT_TARGET_ALLY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_TARGET_PARTY)
                AIInfo->Targets |= 1 << (SELECT_TARGET_SINGLE_FRIEND - 1);

            // Spell targets AoE friends.
            if (effect->TargetA.GetTarget() == TARGET_UNIT_CASTER_AREA_PARTY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_LASTTARGET_AREA_PARTY ||
                effect->TargetA.GetTarget() == TARGET_SRC_CASTER)
                AIInfo->Targets |= 1 << (SELECT_TARGET_AOE_FRIEND - 1);

            // Spell targets any friend (or self).
            if (effect->TargetA.GetTarget() == TARGET_UNIT_CASTER ||
                effect->TargetA.GetTarget() == TARGET_UNIT_TARGET_ALLY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_TARGET_PARTY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_CASTER_AREA_PARTY ||
                effect->TargetA.GetTarget() == TARGET_UNIT_LASTTARGET_AREA_PARTY ||
                effect->TargetA.GetTarget() == TARGET_SRC_CASTER)
                AIInfo->Targets |= 1 << (SELECT_TARGET_ANY_FRIEND - 1);

            // Make sure that this spell includes a damage effect.
            if (effect->Effect == SPELL_EFFECT_SCHOOL_DAMAGE ||
                effect->Effect == SPELL_EFFECT_INSTAKILL ||
                effect->Effect == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE ||
                effect->Effect == SPELL_EFFECT_HEALTH_LEECH)
                AIInfo->Effects |= 1 << (SELECT_EFFECT_DAMAGE - 1);

            // Make sure that this spell includes a healing effect (or an apply aura with a periodic heal).
            if (effect->Effect == SPELL_EFFECT_HEAL ||
                effect->Effect == SPELL_EFFECT_HEAL_MAX_HEALTH ||
                effect->Effect == SPELL_EFFECT_HEAL_MECHANICAL ||
                (effect->Effect == SPELL_EFFECT_APPLY_AURA && effect->ApplyAuraName == 8))
                AIInfo->Effects |= 1 << (SELECT_EFFECT_HEALING - 1);

            // Make sure that this spell applies an aura.
            if (effect->Effect == SPELL_EFFECT_APPLY_AURA)
                AIInfo->Effects |= 1 << (SELECT_EFFECT_AURA - 1);
        }
    });
}

void UnitAI::QuestReward(Player* player, Quest const* quest, uint32 opt)
{
    QuestReward(player, quest, LootItemType::Item, opt);
}

QuestGiverStatus UnitAI::GetDialogStatus(Player* /*player*/)
{
    return QuestGiverStatus::ScriptedDefault;
}

ThreatManager& UnitAI::GetThreatManager()
{
    return me->GetThreatManager();
}

void UnitAI::SortByDistance(std::list<Unit*> list, bool ascending)
{
    list.sort(Trinity::ObjectDistanceOrderPred(me, ascending));
}

DefaultTargetSelector::DefaultTargetSelector(Unit const* unit, float dist, bool playerOnly, bool withTank, int32 aura)
    : me(unit), m_dist(dist), m_playerOnly(playerOnly), except(!withTank ? me->GetThreatManager().GetCurrentVictim() : nullptr), m_aura(aura)
{
}

bool DefaultTargetSelector::operator()(Unit const* target) const
{
    if (!me)
        return false;

    if (!target)
        return false;

    if (except && target == except)
        return false;

    if (m_playerOnly && (target->GetTypeId() != TYPEID_PLAYER))
        return false;

    if (m_dist > 0.0f && !me->IsWithinCombatRange(target, m_dist))
        return false;

    if (m_dist < 0.0f && me->IsWithinCombatRange(target, -m_dist))
        return false;

    if (m_aura)
    {
        if (m_aura > 0)
        {
            if (!target->HasAura(m_aura))
                return false;
        }
        else
        {
            if (target->HasAura(-m_aura))
                return false;
        }
    }

    return true;
}

SpellTargetSelector::SpellTargetSelector(Unit* caster, uint32 spellId) :
    _caster(caster), _spellInfo(sSpellMgr->GetSpellInfo(spellId, caster->GetMap()->GetDifficultyID()))
{
    ASSERT(_spellInfo);
}

bool SpellTargetSelector::operator()(Unit const* target) const
{
    if (!target)
        return false;

    if (_spellInfo->CheckTarget(_caster, target) != SPELL_CAST_OK)
        return false;

    // copypasta from Spell::CheckRange
    float minRange = 0.0f;
    float maxRange = 0.0f;
    float rangeMod = 0.0f;
    if (_spellInfo->RangeEntry)
    {
        if (_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE)
        {
            rangeMod = _caster->GetCombatReach() + 4.0f / 3.0f;
            rangeMod += target->GetCombatReach();

            rangeMod = std::max(rangeMod, NOMINAL_MELEE_RANGE);
        }
        else
        {
            float meleeRange = 0.0f;
            if (_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED)
            {
                meleeRange = _caster->GetCombatReach() + 4.0f / 3.0f;
                meleeRange += target->GetCombatReach();

                meleeRange = std::max(meleeRange, NOMINAL_MELEE_RANGE);
            }

            minRange = _caster->GetSpellMinRangeForTarget(target, _spellInfo) + meleeRange;
            maxRange = _caster->GetSpellMaxRangeForTarget(target, _spellInfo);

            rangeMod = _caster->GetCombatReach();
            rangeMod += target->GetCombatReach();

            if (minRange > 0.0f && !(_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED))
                minRange += rangeMod;
        }

        if (_caster->isMoving() && target->isMoving() && !_caster->IsWalking() && !target->IsWalking() &&
            (_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE || target->GetTypeId() == TYPEID_PLAYER))
            rangeMod += 8.0f / 3.0f;
    }

    maxRange += rangeMod;

    minRange *= minRange;
    maxRange *= maxRange;

    if (target != _caster)
    {
        if (_caster->GetExactDistSq(target) > maxRange)
            return false;

        if (minRange > 0.0f && _caster->GetExactDistSq(target) < minRange)
            return false;
    }

    return true;
}

bool NonTankTargetSelector::operator()(Unit const* target) const
{
    if (!target)
        return false;

    if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if (Unit* currentVictim = _source->GetThreatManager().GetCurrentVictim())
        return target != currentVictim;

    return target != _source->GetVictim();
}

bool PowerUsersSelector::operator()(Unit const* target) const
{
    if (!_me || !target)
        return false;

    if (target->GetPowerType() != _power)
        return false;

    if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if (_dist > 0.0f && !_me->IsWithinCombatRange(target, _dist))
        return false;

    if (_dist < 0.0f && _me->IsWithinCombatRange(target, -_dist))
        return false;

    return true;
}

bool FarthestTargetSelector::operator()(Unit const* target) const
{
    if (!_me || !target)
        return false;

    if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if (_dist > 0.0f && !_me->IsWithinCombatRange(target, _dist))
        return false;

    if (_inLos && !_me->IsWithinLOSInMap(target))
        return false;

    return true;
}
