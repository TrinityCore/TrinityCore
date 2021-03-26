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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "Vehicle.h"

enum VehicleSeatIds
{
    SEAT_1 = 0,
    SEAT_2 = 1
};

enum Xariona
{
    // Events
    EVENT_FURY_OF_THE_TWILIGHT_FLIGHT = 1,
    EVENT_TWILIGHT_BREATH,
    EVENT_TWILIGHT_BUFFET,
    EVENT_UNLEASHED_MAGIC,
    EVENT_TWILIGHT_FISSURE,
    EVENT_TWILIGHT_ZONE,

    // Spells
    SPELL_ZERO_POWER                        = 87239,
    SPELL_ROGUE_CLASS_CRIT_DODGE_DEBUFF     = 73059,
    SPELL_FURY_OF_THE_TWILIGHT_FLIGHT       = 93554,
    SPELL_TWILIGHT_BREATH                   = 93544,
    SPELL_TWILIGHT_BUFFET_TARGETING         = 95385,
    SPELL_UNLEASHED_MAGIC                   = 93556,
    SPELL_TWILIGHT_FISSURE                  = 93546,
    SPELL_VOID_BLAST                        = 93545,
    SPELL_TWILIGHT_ZONE                     = 93553,

    // Creatures
    NPC_TWILIGHT_FISSURE                    = 50431,
};

struct npc_deepholm_xariona : public ScriptedAI
{
    npc_deepholm_xariona(Creature* creature) : ScriptedAI(creature), _furyOfTheTwilightFlightCount(0)
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
    }

    void JustEnteredCombat(Unit* /*who*/) override
    {
        me->SetHomePosition(me->GetPosition());
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ZERO_POWER);
        DoCastSelf(SPELL_ROGUE_CLASS_CRIT_DODGE_DEBUFF);
    }

    void JustEngagedWith(Unit* /*who`*/) override
    {
        _events.ScheduleEvent(EVENT_FURY_OF_THE_TWILIGHT_FLIGHT, 1s);
        _events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 14s);
        _events.ScheduleEvent(EVENT_TWILIGHT_BUFFET, 13s);
        _events.ScheduleEvent(EVENT_TWILIGHT_FISSURE, 29s);
        _events.ScheduleEvent(EVENT_TWILIGHT_ZONE, 31s);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_TWILIGHT_FISSURE:
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->CastSpell(summon, SPELL_VOID_BLAST);
                    summon->DespawnOrUnsummon(4s);
                }, 4s); // Tooltip states 5 seconds but sniffs say 4
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon(0s, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FURY_OF_THE_TWILIGHT_FLIGHT:
                    DoCastSelf(SPELL_FURY_OF_THE_TWILIGHT_FLIGHT);
                    ++_furyOfTheTwilightFlightCount;
                    if (_furyOfTheTwilightFlightCount < 2)
                        _events.Repeat(30s + 500ms);
                    else
                        _events.ScheduleEvent(EVENT_UNLEASHED_MAGIC, 32s);
                    break;
                case EVENT_TWILIGHT_BREATH:
                    DoCastVictim(SPELL_TWILIGHT_BREATH);
                    _events.Repeat(18s, 20s);
                    break;
                case EVENT_TWILIGHT_BUFFET:
                    DoCastAOE(SPELL_TWILIGHT_BUFFET_TARGETING, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    _events.Repeat(23s, 25s);
                    break;
                case EVENT_UNLEASHED_MAGIC:
                    DoCastAOE(SPELL_UNLEASHED_MAGIC);
                    _furyOfTheTwilightFlightCount = 0;
                    _events.DelayEvents(5s);
                    _events.ScheduleEvent(EVENT_FURY_OF_THE_TWILIGHT_FLIGHT, 1ms);
                    break;
                case EVENT_TWILIGHT_FISSURE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.f, true))
                        DoCast(target, SPELL_TWILIGHT_FISSURE);
                    _events.Repeat(29s);
                    break;
                case EVENT_TWILIGHT_ZONE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 55.f, true))
                        DoCast(target, SPELL_TWILIGHT_ZONE);
                    _events.Repeat(31s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    uint8 _furyOfTheTwilightFlightCount;
};

enum DeepholmTheRealmOfEarth
{
    // Spells
    SPELL_CAMERA_1                      = 84364,
    SPELL_FORCECAST_AGGRA_PING          = 96123,
    SPELL_FORCECAST_TELEPORT            = 84093,
    SPELL_EJECT_PASSENGER_2             = 62539,

    // Events
    EVENT_PING_AGGRA                    = 1,
    EVENT_APPROACH_MAELSTROM,

    // Move Points
    POINT_ID_INTRO_FLIGHT = 0,
    POINT_ID_LEAVE_PLAYER,

    // Creature
    NPC_WYVERN_TEMPLE_OF_EARTH          = 45024
};

struct npc_deepholm_wyvern : public NullCreatureAI
{
    npc_deepholm_wyvern(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        if (!passenger || !passenger->IsPlayer())
            return;

        if (apply && seatId == SEAT_2)
        {
            if (me->GetEntry() != NPC_WYVERN_TEMPLE_OF_EARTH)
                DoCastSelf(SPELL_CAMERA_1);
            else
                me->GetMotionMaster()->MovePath(me->GetEntry() * 100, false);

            _events.ScheduleEvent(EVENT_PING_AGGRA, 400ms);
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != WAYPOINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_ID_INTRO_FLIGHT:
                if (me->GetEntry() != NPC_WYVERN_TEMPLE_OF_EARTH)
                    DoCastSelf(SPELL_FORCECAST_TELEPORT);
                else
                    DoCastSelf(SPELL_EJECT_PASSENGER_2);
                break;
            case POINT_ID_LEAVE_PLAYER:
                me->DespawnOrUnsummon(3s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PING_AGGRA:
                    if (Vehicle const* vehicle = me->GetVehicleKit())
                        if (Unit* aggra = vehicle->GetPassenger(SEAT_1))
                            DoCast(aggra, SPELL_FORCECAST_AGGRA_PING);

                    if (me->GetEntry() != NPC_WYVERN_TEMPLE_OF_EARTH)
                        _events.ScheduleEvent(EVENT_APPROACH_MAELSTROM, 800ms);
                    break;
                case EVENT_APPROACH_MAELSTROM:
                    me->GetMotionMaster()->MovePath(me->GetEntry() * 100, false);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 95385 - Twilight Buffet Targeting
class spell_deepholm_twilight_buffet_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        // Xariona never hits her current victim with Twilight Buffed
        targets.remove_if([&](WorldObject* target)
        {
            return GetCaster()->GetVictim() == target;
        });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_deepholm_twilight_buffet_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_deepholm_twilight_buffet_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_deepholm()
{
    RegisterCreatureAI(npc_deepholm_xariona);
    RegisterCreatureAI(npc_deepholm_wyvern);
    RegisterSpellScript(spell_deepholm_twilight_buffet_targeting);
}
