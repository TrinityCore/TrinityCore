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
 * Find a better way to deal with his three initial beacons to make sure all aggro
 * His caster mode requires rechecks
 * Move away after succesful Frost Nova cast (seems like doesn't always triggered)
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "mana_tombs.h"
#include "MotionMaster.h"

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
    SPELL_FIREBALL                  = 32363,
    SPELL_FROSTBOLT                 = 32364,
    SPELL_FROSTNOVA                 = 32365,

    SPELL_ETHEREAL_BEACON           = 32371,

    // Ethereal Beacon
    SPELL_ETHEREAL_BEACON_VISUAL    = 32368,
    SPELL_ARCANE_BOLT               = 15254,
    SPELL_ETHEREAL_APPRENTICE       = 32372
};

enum ShaffarEvents
{
    EVENT_BLINK                     = 1,
    EVENT_BEACON,
    EVENT_MAIN_SPELL,
    EVENT_FROST_NOVA,

    // Ethereal Beacon
    EVENT_SUMMON_APPRENTICE,
    EVENT_ARCANE_BOLT
};

enum ShaffarCreatures
{
    NPC_BEACON                      = 18431,
    NPC_SHAFFAR                     = 18344
};

// 18344 - Nexus-Prince Shaffar
struct boss_nexusprince_shaffar : public BossAI
{
    boss_nexusprince_shaffar(Creature* creature) : BossAI(creature, DATA_NEXUSPRINCE_SHAFFAR), _hasTaunted(false) { }

    void Reset() override
    {
        _Reset();

        me->SummonCreature(NPC_BEACON, -191.116f, 3.82914f, 16.7834f, 3.62003f, TEMPSUMMON_MANUAL_DESPAWN);
        me->SummonCreature(NPC_BEACON, -180.408f, 10.9629f, 16.7025f, 3.45070f, TEMPSUMMON_MANUAL_DESPAWN);
        me->SummonCreature(NPC_BEACON, -185.980f, 14.4201f, 16.7234f, 1.31540f, TEMPSUMMON_MANUAL_DESPAWN);
    }

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
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_BLINK, 20s, 30s);
        events.ScheduleEvent(EVENT_BEACON, 10s, 30s);
        events.ScheduleEvent(EVENT_MAIN_SPELL, 0s, 6s);
        events.ScheduleEvent(EVENT_FROST_NOVA, 15s, 35s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (summoned->GetEntry() == NPC_BEACON)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                summoned->AI()->AttackStart(target);

            if (!me->IsInCombat())
                summoned->GetMotionMaster()->MoveRandom(5.0f);
        }

        summons.Summon(summoned);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ETHEREAL_BEACON)
            if (roll_chance_i(50))
                Talk(SAY_SUMMON);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                DoCastSelf(SPELL_ETHEREAL_BEACON);
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
                DoCastSelf(SPELL_FROSTNOVA);
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
    npc_ethereal_beacon(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ETHEREAL_BEACON_VISUAL);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        if (Creature* shaffar = me->FindNearestCreature(NPC_SHAFFAR, 100.0f))
            if (!shaffar->IsInCombat())
                shaffar->AI()->AttackStart(who);

        _events.ScheduleEvent(EVENT_SUMMON_APPRENTICE, DUNGEON_MODE(20s, 10s));
        _events.ScheduleEvent(EVENT_ARCANE_BOLT, 3s, 10s);
    }

    void JustSummoned(Creature* summoned) override
    {
        summoned->AI()->AttackStart(me->GetVictim());
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
                    DoCastSelf(SPELL_ETHEREAL_APPRENTICE);
                    me->AttackStop();
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
    npc_ethereal_apprentice(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SIMPLE_TELEPORT);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(RAND(EVENT_ETHEREAL_APPRENTICE_FIREBOLT, EVENT_ETHEREAL_APPRENTICE_FROSTBOLT), 0s);
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
