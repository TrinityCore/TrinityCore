/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

/////////////////
// CombatAI
/////////////////

void CombatAI::InitializeAI()
{
    for (uint32 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        if (me->m_spells[i] && sSpellMgr->GetSpellInfo(me->m_spells[i]))
            Spells.push_back(me->m_spells[i]);

    CreatureAI::InitializeAI();
}

void CombatAI::Reset()
{
    Events.Reset();
}

void CombatAI::JustDied(Unit* killer)
{
    for (SpellVector::iterator i = Spells.begin(); i != Spells.end(); ++i)
        if (AISpellInfo[*i].condition == AICOND_DIE)
            me->CastSpell(killer, *i, true);
}

void CombatAI::JustEngagedWith(Unit* who)
{
    for (SpellVector::iterator i = Spells.begin(); i != Spells.end(); ++i)
    {
        if (AISpellInfo[*i].condition == AICOND_AGGRO)
            me->CastSpell(who, *i, false);
        else if (AISpellInfo[*i].condition == AICOND_COMBAT)
            Events.ScheduleEvent(*i, AISpellInfo[*i].cooldown + rand32() % AISpellInfo[*i].cooldown);
    }
}

void CombatAI::UpdateAI(uint32 diff)
{
    if (!UpdateVictim())
        return;

    Events.Update(diff);

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (uint32 spellId = Events.ExecuteEvent())
    {
        DoCast(spellId);
        Events.ScheduleEvent(spellId, AISpellInfo[spellId].cooldown + rand32() % AISpellInfo[spellId].cooldown);
    }
    else
        DoMeleeAttackIfReady();
}

void CombatAI::SpellInterrupted(uint32 spellId, uint32 unTimeMs)
{
    Events.RescheduleEvent(spellId, unTimeMs);
}

/////////////////
// CasterAI
/////////////////

void CasterAI::InitializeAI()
{
    CombatAI::InitializeAI();

    _attackDistance = 30.0f;

    for (SpellVector::iterator itr = Spells.begin(); itr != Spells.end(); ++itr)
        if (AISpellInfo[*itr].condition == AICOND_COMBAT && _attackDistance > GetAISpellInfo(*itr)->maxRange)
            _attackDistance = GetAISpellInfo(*itr)->maxRange;

    if (_attackDistance == 30.0f)
        _attackDistance = MELEE_RANGE;
}

void CasterAI::JustEngagedWith(Unit* who)
{
    if (Spells.empty())
        return;

    uint32 spell = rand32() % Spells.size();
    uint32 count = 0;
    for (SpellVector::iterator itr = Spells.begin(); itr != Spells.end(); ++itr, ++count)
    {
        if (AISpellInfo[*itr].condition == AICOND_AGGRO)
            me->CastSpell(who, *itr, false);
        else if (AISpellInfo[*itr].condition == AICOND_COMBAT)
        {
            uint32 cooldown = GetAISpellInfo(*itr)->realCooldown;
            if (count == spell)
            {
                DoCast(Spells[spell]);
                cooldown += me->GetCurrentSpellCastTime(*itr);
            }
            Events.ScheduleEvent(*itr, cooldown);
        }
    }
}

void CasterAI::UpdateAI(uint32 diff)
{
    if (!UpdateVictim())
        return;

    Events.Update(diff);

    if (me->GetVictim() && me->EnsureVictim()->HasBreakableByDamageCrowdControlAura(me))
    {
        me->InterruptNonMeleeSpells(false);
        return;
    }

    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (uint32 spellId = Events.ExecuteEvent())
    {
        DoCast(spellId);
        uint32 casttime = me->GetCurrentSpellCastTime(spellId);
        Events.ScheduleEvent(spellId, (casttime ? casttime : 500) + GetAISpellInfo(spellId)->realCooldown);
    }
}

//////////////
// ArcherAI
//////////////

ArcherAI::ArcherAI(Creature* creature) : CreatureAI(creature)
{
    if (!creature->m_spells[0])
        TC_LOG_ERROR("scripts.ai", "ArcherAI set for creature with spell1 = 0. AI will do nothing (%s)", creature->GetGUID().ToString().c_str());

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(creature->m_spells[0]);
    _minimumRange = spellInfo ? spellInfo->GetMinRange(false) : 0;

    if (!_minimumRange)
        _minimumRange = MELEE_RANGE;
    creature->m_CombatDistance = spellInfo ? spellInfo->GetMaxRange(false) : 0;
    creature->m_SightDistance = creature->m_CombatDistance;
}

void ArcherAI::AttackStart(Unit* who)
{
    if (!who)
        return;

    if (me->IsWithinCombatRange(who, _minimumRange))
    {
        if (me->Attack(who, true) && !who->IsFlying())
            me->GetMotionMaster()->MoveChase(who);
    }
    else
    {
        if (me->Attack(who, false) && !who->IsFlying())
            me->GetMotionMaster()->MoveChase(who, me->m_CombatDistance);
    }

    if (who->IsFlying())
        me->GetMotionMaster()->MoveIdle();
}

void ArcherAI::UpdateAI(uint32 /*diff*/)
{
    if (!UpdateVictim())
        return;

    if (!me->IsWithinCombatRange(me->GetVictim(), _minimumRange))
        DoSpellAttackIfReady(me->m_spells[0]);
    else
        DoMeleeAttackIfReady();
}

//////////////
// TurretAI
//////////////

TurretAI::TurretAI(Creature* creature) : CreatureAI(creature)
{
    if (!creature->m_spells[0])
        TC_LOG_ERROR("scripts.ai", "TurretAI set for creature with spell1 = 0. AI will do nothing (%s)", creature->GetGUID().ToString().c_str());

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(creature->m_spells[0]);
    _minimumRange = spellInfo ? spellInfo->GetMinRange(false) : 0;
    creature->m_CombatDistance = spellInfo ? spellInfo->GetMaxRange(false) : 0;
    creature->m_SightDistance = creature->m_CombatDistance;
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

VehicleAI::VehicleAI(Creature* creature) : CreatureAI(creature), _hasConditions(false), _conditionsTimer(VEHICLE_CONDITION_CHECK_TIME)
{
    LoadConditions();
    _dismiss = false;
    _dismissTimer = VEHICLE_DISMISS_TIME;
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
        if (Vehicle* vehicleKit = me->GetVehicleKit())
        {
            for (SeatMap::iterator itr = vehicleKit->Seats.begin(); itr != vehicleKit->Seats.end(); ++itr)
                if (Unit* passenger = ObjectAccessor::GetUnit(*me, itr->second.Passenger.Guid))
                {
                    if (Player* player = passenger->ToPlayer())
                    {
                        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE, me->GetEntry(), player, me))
                        {
                            player->ExitVehicle();
                            return; // check other pessanger in next tick
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
