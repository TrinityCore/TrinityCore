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

#include "CombatAI.h"
#include "ConditionMgr.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Vehicle.h"

/////////////////
// AggressorAI
/////////////////

int32 AggressorAI::Permissible(Creature const* creature)
{
    // have some hostile factions, it will be selected by IsHostileTo check at MoveInLineOfSight
    if (!creature->IsCivilian() && !creature->IsNeutralToAll())
        return PERMIT_BASE_REACTIVE;

    return PERMIT_BASE_NO;
}

void AggressorAI::UpdateAI(uint32 /*diff*/)
{
    UpdateVictim();
}

/////////////////
// CombatAI
/////////////////

void CombatAI::InitializeAI()
{
    for (uint32 spell : me->m_spells)
        if (spell && sSpellMgr->GetSpellInfo(spell, me->GetMap()->GetDifficultyID()))
            _spells.push_back(spell);

    CreatureAI::InitializeAI();
}

void CombatAI::Reset()
{
    _events.Reset();
}

void CombatAI::JustDied(Unit* killer)
{
    for (uint32 spell : _spells)
    {
        if (AISpellInfoType const* info = GetAISpellInfo(spell, me->GetMap()->GetDifficultyID()))
            if (info->condition == AICOND_DIE)
                me->CastSpell(killer, spell, true);
    }
}

void CombatAI::JustEngagedWith(Unit* who)
{
    for (uint32 spell : _spells)
    {
        if (AISpellInfoType const* info = GetAISpellInfo(spell, me->GetMap()->GetDifficultyID()))
        {
            if (info->condition == AICOND_AGGRO)
                me->CastSpell(who, spell, false);
            else if (info->condition == AICOND_COMBAT)
                _events.ScheduleEvent(spell, info->cooldown, info->cooldown * 2);
        }
    }
}

void CombatAI::UpdateAI(uint32 diff)
{
    if (!UpdateVictim())
        return;

    _events.Update(diff);

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (uint32 spellId = _events.ExecuteEvent())
    {
        DoCast(spellId);
        if (AISpellInfoType const* info = GetAISpellInfo(spellId, me->GetMap()->GetDifficultyID()))
            _events.ScheduleEvent(spellId, info->cooldown, info->cooldown * 2);
    }
}

void CombatAI::SpellInterrupted(uint32 spellId, uint32 unTimeMs)
{
    _events.RescheduleEvent(spellId, Milliseconds(unTimeMs));
}

/////////////////
// CasterAI
/////////////////

void CasterAI::InitializeAI()
{
    CombatAI::InitializeAI();

    _attackDistance = 30.0f;

    for (uint32 spell : _spells)
    {
        if (AISpellInfoType const* info = GetAISpellInfo(spell, me->GetMap()->GetDifficultyID()))
            if (info->condition == AICOND_COMBAT && _attackDistance > info->maxRange)
                _attackDistance = info->maxRange;
    }

    if (_attackDistance == 30.0f)
        _attackDistance = MELEE_RANGE;
}

void CasterAI::JustEngagedWith(Unit* who)
{
    if (_spells.empty())
        return;

    uint32 spell = rand32() % _spells.size();
    uint32 count = 0;
    for (auto itr = _spells.begin(); itr != _spells.end(); ++itr, ++count)
    {
        if (AISpellInfoType const* info = GetAISpellInfo(*itr, me->GetMap()->GetDifficultyID()))
        {
            if (info->condition == AICOND_AGGRO)
                me->CastSpell(who, *itr, false);
            else if (info->condition == AICOND_COMBAT)
            {
                Milliseconds cooldown = info->realCooldown;
                if (count == spell)
                {
                    DoCast(_spells[spell]);
                    cooldown += Milliseconds(me->GetCurrentSpellCastTime(*itr));
                }
                _events.ScheduleEvent(*itr, cooldown);
            }
        }
    }
}

void CasterAI::UpdateAI(uint32 diff)
{
    if (!UpdateVictim())
        return;

    _events.Update(diff);

    if (me->GetVictim() && me->EnsureVictim()->HasBreakableByDamageCrowdControlAura(me))
    {
        me->InterruptNonMeleeSpells(false);
        return;
    }

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (uint32 spellId = _events.ExecuteEvent())
    {
        DoCast(spellId);
        uint32 casttime = me->GetCurrentSpellCastTime(spellId);
        if (AISpellInfoType const* info = GetAISpellInfo(spellId, me->GetMap()->GetDifficultyID()))
            _events.ScheduleEvent(spellId, Milliseconds(casttime ? casttime : 500) + info->realCooldown);
    }
}

//////////////
// TurretAI
//////////////

TurretAI::TurretAI(Creature* creature, uint32 scriptId) : CreatureAI(creature, scriptId)
{
    if (!creature->m_spells[0])
        TC_LOG_ERROR("scripts.ai", "TurretAI set for creature with spell1 = 0. AI will do nothing ({})", creature->GetGUID().ToString());

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(creature->m_spells[0], creature->GetMap()->GetDifficultyID());
    _minimumRange = spellInfo ? spellInfo->GetMinRange(false) : 0;
    creature->m_CombatDistance = spellInfo ? spellInfo->GetMaxRange(false) : 0;
    creature->m_SightDistance = creature->m_CombatDistance;
    creature->SetCanMelee(false);
}

bool TurretAI::CanAIAttack(Unit const* who) const
{
    /// @todo use one function to replace it
    if (!me->IsWithinCombatRange(who, me->m_CombatDistance) || (_minimumRange && me->IsWithinCombatRange(who, _minimumRange)))
        return false;
    return true;
}

void TurretAI::AttackStart(Unit* who)
{
    if (who)
        me->Attack(who, false);
}

void TurretAI::UpdateAI(uint32 /*diff*/)
{
    if (!UpdateVictim())
        return;

    DoSpellAttackIfReady(me->m_spells[0]);
}

//////////////
// VehicleAI
//////////////

VehicleAI::VehicleAI(Creature* creature, uint32 scriptId) : CreatureAI(creature, scriptId), _hasConditions(false), _conditionsTimer(VEHICLE_CONDITION_CHECK_TIME)
{
    LoadConditions();
    _dismiss = false;
    _dismissTimer = VEHICLE_DISMISS_TIME;
    me->SetCanMelee(false);
}

// NOTE: VehicleAI::UpdateAI runs even while the vehicle is mounted
void VehicleAI::UpdateAI(uint32 diff)
{
    CheckConditions(diff);

    if (_dismiss)
    {
        if (_dismissTimer < diff)
        {
            _dismiss = false;
            me->DespawnOrUnsummon();
        }
        else
            _dismissTimer -= diff;
    }
}

void VehicleAI::OnCharmed(bool /*isNew*/)
{
    bool const charmed = me->IsCharmed();
    if (!me->GetVehicleKit()->IsVehicleInUse() && !charmed && _hasConditions) // was used and has conditions
    {
        _dismiss = true; // needs reset
    }
    else if (charmed)
        _dismiss = false; // in use again

    _dismissTimer = VEHICLE_DISMISS_TIME; // reset timer
}

void VehicleAI::LoadConditions()
{
    _hasConditions = sConditionMgr->HasConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE, me->GetEntry());
}

void VehicleAI::CheckConditions(uint32 diff)
{
    if (!_hasConditions)
        return;

    if (_conditionsTimer <= diff)
    {
        if (Vehicle * vehicleKit = me->GetVehicleKit())
        {
            for (auto const& [i, vehicleSeat] : vehicleKit->Seats)
            {
                if (Unit* passenger = ObjectAccessor::GetUnit(*me, vehicleSeat.Passenger.Guid))
                {
                    if (Player * player = passenger->ToPlayer())
                    {
                        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE, me->GetEntry(), player, me))
                        {
                            player->ExitVehicle();
                            return; // check other pessanger in next tick
                        }
                    }
                }
            }
        }

        _conditionsTimer = VEHICLE_CONDITION_CHECK_TIME;
    }
    else
        _conditionsTimer -= diff;
}

int32 VehicleAI::Permissible(Creature const* creature)
{
    if (creature->IsVehicle())
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}
