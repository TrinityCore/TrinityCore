/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef FIRELANDS_H_
#define FIRELANDS_H_

#include "Map.h"
#include "CreatureAI.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "Pet.h"

#define DataHeader "FL"
#define FirelandsScriptName "instance_firelands"

uint32 const EncounterCount = 7;

enum FLDataTypes
{
    DATA_BETH_TILAC                 = 0,
    DATA_LORD_RHYOLITH              = 1,
    DATA_SHANNOX                    = 2,
    DATA_ALYSRAZOR                  = 3,
    DATA_BALEROC                    = 4,
    DATA_MAJORDOMO_STAGHELM         = 5,
    DATA_RAGNAROS                   = 6,
};

enum FLCreatureIds
{
    // Bosses
    NPC_SHANNOX                     = 53691,
    NPC_LORD_RHYOLITH               = 52558,
    NPC_BETH_TILAC                  = 52498,
    NPC_ALYSRAZOR                   = 52530,
    NPC_BALEROC                     = 53494,
    NPC_MAJORDOMO_STAGHELM          = 52571,
    NPC_RAGNAROS                    = 52409,

    // Alysrazor
    NPC_BLAZING_MONSTROSITY_LEFT    = 53786,
    NPC_BLAZING_MONSTROSITY_RIGHT   = 53791,
    NPC_EGG_PILE                    = 53795,
    NPC_HARBINGER_OF_FLAME          = 53793,
    NPC_MOLTEN_EGG_TRASH            = 53914,
    NPC_SMOULDERING_HATCHLING       = 53794,

    // Baleroc
    NPC_MAGMA_CONDUIT               = 54145,
    NPC_MAGMAKIN                    = 54144
};

enum GameobjectIds
{
    GO_BALEROC_FIREWALL             = 209066
};

enum FirelandsSpells
{
    SPELL_SMOULDERING_1             = 101089,
    SPELL_SMOULDERING_2             = 101092,
};

enum FirelandsQuests
{
    QUEST_HEART_OF_FLAME_A          = 29307,
    QUEST_HEART_OF_FLAME_H          = 29308
};

class DelayedAttackStartEvent : public BasicEvent
{
    public:
        DelayedAttackStartEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
        {
            _owner->AI()->DoZoneInCombat(_owner, 200.0f);
            return true;
        }

    private:
        Creature* _owner;
};

class DelayedSpellCastEvent : public BasicEvent
{
    public:
        DelayedSpellCastEvent(Creature* owner, Unit* target, uint32 spellId, bool triggered) : _owner(owner), _target(target), _spellId(spellId), _triggered(triggered) { }

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
        {
            _owner->CastSpell(_target, _spellId, _triggered);
            return true;
        }

    private:
        Creature* _owner;
        Unit* _target;
        uint32 _spellId;
        bool _triggered;
};

class PlayerCheck
{
    public:
        bool operator()(WorldObject* object) const
        {
            return object->GetTypeId() != TYPEID_PLAYER;
        }
};

struct firelands_bossAI : public BossAI
{
    firelands_bossAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId) { }

    void EnterCombat(Unit* target) override
    {
        BossAI::EnterCombat(target);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->m_Events.AddEvent(new DelayedSpellCastEvent(me, static_cast<Unit*>(nullptr), SPELL_SMOULDERING_1, false), me->m_Events.CalculateTime(2 * IN_MILLISECONDS));
        me->m_Events.AddEvent(new DelayedSpellCastEvent(me, static_cast<Unit*>(nullptr), SPELL_SMOULDERING_2, false), me->m_Events.CalculateTime(2 * IN_MILLISECONDS));
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        // Copy paste ScriptedAI::EnterEvadeMode functionality to exclude Reset function call
        if (!_EnterEvadeMode(why))
            return;

        TC_LOG_DEBUG("entities.unit", "Creature %u enters evade mode.", me->GetEntry());

        if (!me->GetVehicle()) // otherwise me will be in evade mode forever
        {
            if (Unit* owner = me->GetCharmerOrOwner())
            {
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MOTION_SLOT_ACTIVE);
            }
            else
            {
                // Required to prevent attacking creatures that are evading and cause them to reenter combat
                // Does not apply to MoveFollow
                me->AddUnitState(UNIT_STATE_EVADE);
                me->GetMotionMaster()->MoveTargetedHome();
            }
        }

        // Copy paste reason
        //Reset();

        if (me->IsVehicle()) // use the same sequence of addtoworld, aireset may remove all summons!
            me->GetVehicleKit()->Reset(true);

        _DespawnAtEvade();
    }
};

template<class AI, class T>
inline AI* GetFirelandsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, FirelandsScriptName);
}

#endif // FIRELANDS_H_
