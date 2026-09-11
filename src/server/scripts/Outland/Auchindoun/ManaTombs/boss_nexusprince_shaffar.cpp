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

/*
 * Timers requires to be revisited
 * His caster mode requires rechecks
 * Move away after succesful Frost Nova cast (seems like doesn't always triggered)
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "mana_tombs.h"
#include "Map.h"

enum ShaffarTexts
{
    SAY_INTRO                       = 0,
    SAY_AGGRO                       = 1,
    SAY_SLAY                        = 2,
    SAY_SUMMON                      = 3,
    SAY_DEATH                       = 4
};

enum ShaffarSpells
{
    // Shaffar
    SPELL_BLINK                     = 34605,
    SPELL_SUMMON_ETHEREAL_BEACON    = 32371,
    SPELL_FIREBALL                  = 32363,
    SPELL_FROSTBOLT                 = 32364,
    SPELL_FROST_NOVA                = 32365,

    // Ethereal Beacon
    SPELL_ETHEREAL_BEACON_VISUAL    = 32368,
    SPELL_ARCANE_BOLT               = 15254,
    SPELL_SUMMON_APPRENTICE         = 32372
};

enum ShaffarEvents
{
    // Shaffar
    EVENT_BLINK                     = 1,
    EVENT_BEACON,
    EVENT_MAIN_SPELL,
    EVENT_FROST_NOVA,

    // Ethereal Beacon
    EVENT_SUMMON_APPRENTICE,
    EVENT_ARCANE_BOLT
};

enum ShaffarSpawnGroups
{
    SPAWN_GROUP_BEACON_1            = 416,
    SPAWN_GROUP_BEACON_2            = 417,
    SPAWN_GROUP_BEACON_3            = 418
};

static constexpr std::array<uint32, 3> BeaconSpawnGroupsData =
{
    SPAWN_GROUP_BEACON_1,
    SPAWN_GROUP_BEACON_2,
    SPAWN_GROUP_BEACON_3
};

// 18344 - Nexus-Prince Shaffar
struct boss_nexusprince_shaffar : public BossAI
{
    boss_nexusprince_shaffar(Creature* creature) : BossAI(creature, DATA_NEXUSPRINCE_SHAFFAR), _hasTaunted(false) { }

    void JustAppeared() override
    {
        for (uint32 group : BeaconSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    /// @todo: Handle this with GameObject 184120 (Auchindoun Ethereal - Nexus-Prince Shaffar Intro Event - Trigge)
    void MoveInLineOfSight(Unit* who) override
    {
        if (!_hasTaunted && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 100.0f))
        {
            Talk(SAY_INTRO);
            _hasTaunted = true;
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_BLINK, 20s, 30s);
        events.ScheduleEvent(EVENT_BEACON, 10s, 30s);
        events.ScheduleEvent(EVENT_MAIN_SPELL, 0s, 6s);
        events.ScheduleEvent(EVENT_FROST_NOVA, 15s, 35s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            summoned->AI()->AttackStart(target);

        summons.Summon(summoned);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SUMMON_ETHEREAL_BEACON)
            if (roll_chance_i(50))
                Talk(SAY_SUMMON);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();

        for (uint32 group : BeaconSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BLINK:
                DoCastSelf(SPELL_BLINK);
                events.Repeat(40s, 60s);
                events.RescheduleEvent(EVENT_MAIN_SPELL, 0s);
                break;
            case EVENT_BEACON:
                DoCastSelf(SPELL_SUMMON_ETHEREAL_BEACON);
                events.Repeat(20s);
                break;
            case EVENT_MAIN_SPELL:
                DoCastVictim(RAND(SPELL_FIREBALL, SPELL_FROSTBOLT));

                if (me->IsWithinMeleeRange(me->GetVictim()))
                    events.Repeat(1s, 6s);
                else
                    events.Repeat(1s);
                break;
            case EVENT_FROST_NOVA:
                DoCastSelf(SPELL_FROST_NOVA);
                events.Repeat(15s, 25s);
                break;
            default:
                break;
        }
    }

private:
    bool _hasTaunted;
};

// 18431 - Ethereal Beacon
struct npc_ethereal_beacon : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ETHEREAL_BEACON_VISUAL);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SUMMON_APPRENTICE, DUNGEON_MODE(20s, 10s));
        _events.ScheduleEvent(EVENT_ARCANE_BOLT, 3s, 10s);
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
                case EVENT_SUMMON_APPRENTICE:
                    DoCastSelf(SPELL_SUMMON_APPRENTICE);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetImmuneToPC(true);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->DespawnOrUnsummon(2s);
                    break;
                case EVENT_ARCANE_BOLT:
                    DoCastVictim(SPELL_ARCANE_BOLT);
                    _events.Repeat(3s, 10s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

enum EtherealApprentice
{
    SPELL_SIMPLE_TELEPORT                       = 12980,
    SPELL_ETHEREAL_APPRENTICE_FIREBOLT          = 32369,
    SPELL_ETHEREAL_APPRENTICE_FROSTBOLT         = 32370,
    EVENT_ETHEREAL_APPRENTICE_FIREBOLT          = 1,
    EVENT_ETHEREAL_APPRENTICE_FROSTBOLT
};

// 18430 - Ethereal Apprentice
struct npc_ethereal_apprentice : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SIMPLE_TELEPORT);
        DoZoneInCombat();
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(RAND(EVENT_ETHEREAL_APPRENTICE_FIREBOLT, EVENT_ETHEREAL_APPRENTICE_FROSTBOLT), 0s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
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
                case EVENT_ETHEREAL_APPRENTICE_FIREBOLT:
                    DoCastVictim(SPELL_ETHEREAL_APPRENTICE_FIREBOLT);
                    _events.ScheduleEvent(EVENT_ETHEREAL_APPRENTICE_FROSTBOLT, 3s);
                    break;
                case EVENT_ETHEREAL_APPRENTICE_FROSTBOLT:
                    DoCastVictim(SPELL_ETHEREAL_APPRENTICE_FROSTBOLT);
                    _events.ScheduleEvent(EVENT_ETHEREAL_APPRENTICE_FIREBOLT, 3s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

void AddSC_boss_nexusprince_shaffar()
{
    RegisterManaTombsCreatureAI(boss_nexusprince_shaffar);
    RegisterManaTombsCreatureAI(npc_ethereal_beacon);
    RegisterManaTombsCreatureAI(npc_ethereal_apprentice);
}
