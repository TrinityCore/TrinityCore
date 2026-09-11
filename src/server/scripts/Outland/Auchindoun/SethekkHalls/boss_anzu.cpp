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
 * Birds-helpers are NYI
 */

#include "ScriptMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "sethekk_halls.h"

enum AnzuTexts
{
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_SUMMON                  = 2,
    SAY_BOMB                    = 3
};

enum AnzuSpells
{
    SPELL_SHADOWFORM            = 37816,

    SPELL_PARALYZING_SCREECH    = 40184,
    SPELL_SPELL_BOMB            = 40303,
    SPELL_CYCLONE_OF_FEATHERS   = 40321,
    SPELL_BANISH_SELF           = 42354
};

enum AnzuEvents
{
    EVENT_PARALYZING_SCREECH    = 1,
    EVENT_SPELL_BOMB,
    EVENT_CYCLONE_OF_FEATHERS,

    EVENT_SUMMON_1,
    EVENT_SUMMON_2,

    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3
};

enum AnzuPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_70,
    PHASE_HEALTH_33
};

enum AnzuSpawnGroups
{
    SPAWN_GROUP_BROOD_1         = 406,
    SPAWN_GROUP_BROOD_2         = 407,
    SPAWN_GROUP_BROOD_3         = 408,
    SPAWN_GROUP_BROOD_4         = 409,
    SPAWN_GROUP_BROOD_5         = 410,
    SPAWN_GROUP_BROOD_6         = 411,
    SPAWN_GROUP_BROOD_7         = 412,
    SPAWN_GROUP_HAWK            = 413,
    SPAWN_GROUP_FALCON          = 414,
    SPAWN_GROUP_EAGLE           = 415
};

enum AnzuMisc
{
    PATH_BROOD_1                = 1475160,
    PATH_BROOD_2                = 1475170,
    NPC_ANZU                    = 23035,
    ACTION_INFORM_ANZU          = 0
};

static constexpr std::array<uint32, 7> BroodSpawnGroupsData =
{
    SPAWN_GROUP_BROOD_1,
    SPAWN_GROUP_BROOD_2,
    SPAWN_GROUP_BROOD_3,
    SPAWN_GROUP_BROOD_4,
    SPAWN_GROUP_BROOD_5,
    SPAWN_GROUP_BROOD_6,
    SPAWN_GROUP_BROOD_7
};

static constexpr std::array<uint32, 3> HelpersSpawnGroupsData =
{
    SPAWN_GROUP_HAWK,
    SPAWN_GROUP_FALCON,
    SPAWN_GROUP_EAGLE
};

// 23035 - Anzu
struct boss_anzu : public BossAI
{
    boss_anzu(Creature* creature) : BossAI(creature, DATA_ANZU), _phase(PHASE_NONE), _deadBroodCount(0) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_INTRO_1, 0s);
    }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
        _deadBroodCount = 0;
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_PARALYZING_SCREECH, 15s, 25s);
        events.ScheduleEvent(EVENT_SPELL_BOMB, 20s, 30s);
        events.ScheduleEvent(EVENT_CYCLONE_OF_FEATHERS, 10s, 15s);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_70 && me->HealthBelowPctDamaged(70, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON_1, 0s);
        }

        if (_phase < PHASE_HEALTH_33 && me->HealthBelowPctDamaged(33, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SUMMON_1, 0s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_INFORM_ANZU)
        {
            _deadBroodCount++;

            if (_deadBroodCount == std::size(BroodSpawnGroupsData))
            {
                me->RemoveAurasDueToSpell(SPELL_BANISH_SELF);
                _deadBroodCount = 0;
            }
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        for (uint32 group : BroodSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);

        BossAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        for (uint32 group : HelpersSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_1:
                        Talk(SAY_INTRO_1);
                        DoCastSelf(SPELL_SHADOWFORM);
                        events.ScheduleEvent(EVENT_INTRO_2, 5s);
                        break;
                    case EVENT_INTRO_2:
                        Talk(SAY_INTRO_2);
                        events.ScheduleEvent(EVENT_INTRO_3, 5s);
                        break;
                    case EVENT_INTRO_3:
                        me->RemoveAurasDueToSpell(SPELL_SHADOWFORM);
                        me->SetImmuneToAll(false);
                        for (uint32 group : HelpersSpawnGroupsData)
                            me->GetMap()->SpawnGroupSpawn(group, true);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PARALYZING_SCREECH:
                    DoCastSelf(SPELL_PARALYZING_SCREECH);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_SPELL_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, [](Unit const* unit) { return unit && unit->GetPowerType() == POWER_MANA; }))
                    {
                        DoCast(target, SPELL_SPELL_BOMB);
                        Talk(SAY_BOMB, target);
                    }
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_CYCLONE_OF_FEATHERS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CYCLONE_OF_FEATHERS);
                    events.Repeat(20s, 25s);
                    break;

                case EVENT_SUMMON_1:
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_SUMMON);

                    _deadBroodCount = 0;

                    for (uint32 group : BroodSpawnGroupsData)
                        me->GetMap()->SpawnGroupSpawn(group, true, true);

                    events.ScheduleEvent(EVENT_SUMMON_2, 3s);
                    break;
                case EVENT_SUMMON_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_BANISH_SELF);
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
    uint8 _phase;
    uint8 _deadBroodCount;
};

// 23132 - Brood of Anzu
struct npc_brood_of_anzu : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        me->SetDisableGravity(true);
        me->SetReactState(REACT_PASSIVE);

        _scheduler.Schedule(0s, 5s, [this](TaskContext /*task*/)
        {
            me->GetMotionMaster()->MovePath(RAND(PATH_BROOD_1, PATH_BROOD_2), false);
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetDisableGravity(false);
        DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* anzu = me->FindNearestCreature(NPC_ANZU, 200.0f))
            anzu->AI()->DoAction(ACTION_INFORM_ANZU);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_anzu()
{
    RegisterSethekkHallsCreatureAI(boss_anzu);
    RegisterSethekkHallsCreatureAI(npc_brood_of_anzu);
}
