/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Skarvald_Dalronn
SD%Complete: 95
SDComment: Needs adjustments to blizzlike timers
SDCategory: Utgarde Keep
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "utgarde_keep.h"

enum Texts
{
    // Texts are common for both bosses and their ghosts.
    SAY_AGGRO                  = 0,
    SAY_DEATH                  = 1, // Said once both bosses are dead.
    SAY_DIED_FIRST             = 2, // Said by the first boss that dies.
    SAY_KILL                   = 3,
    SAY_DEATH_RESPONSE         = 4  // Said by the boss alive after the first one dies.

};

enum Spells
{
    // Spells of Skarvald and his Ghost
    SPELL_CHARGE                                = 43651,
    SPELL_STONE_STRIKE                          = 48583,
    SPELL_ENRAGE                                = 48193,
    SPELL_SUMMON_SKARVALD_GHOST                 = 48613,

    // Spells of Dalronn and his Ghost
    SPELL_SHADOW_BOLT                           = 43649,
    SPELL_SUMMON_SKELETONS                      = 52611,
    SPELL_DEBILITATE                            = 43650,
    SPELL_SUMMON_DALRONN_GHOST                  = 48612,
};

enum Events
{
    // Skarvald the Constructor
    EVENT_SKARVALD_CHARGE = 1,
    EVENT_STONE_STRIKE,

    // Dalronn the Controller
    EVENT_SHADOW_BOLT,
    EVENT_DEBILITATE,
    EVENT_SUMMON_SKELETONS,
    EVENT_DELAYED_AGGRO_SAY, // Dalronn's SAY_AGGRO is delayed so it doesn't overlap Skarvald's one.

    // Common event to both bosses.
    // Delays SAY_DEATH_RESPONSE so it doesn't overlap with the SAY_DIED_FIRST from the boss that has just died.
    EVENT_DEATH_RESPONSE
};

enum Actions
{
    ACTION_OTHER_JUST_DIED = 1,
    ACTION_DESPAWN_SUMMONS = 2 // Only needed to clear off the ghosts when the second boss dies.
};

class SkarvaldChargePredicate
{
    public:
        SkarvaldChargePredicate(Unit* unit) : _me(unit) { }

        bool operator() (WorldObject* target) const
        {
            return target->GetDistance2d(_me) >= 5.0f && target->GetDistance2d(_me) <= 30.0f;
        }

    private:
        Unit* _me;
};

struct generic_boss_controllerAI : public BossAI
{
    generic_boss_controllerAI(Creature* creature) : BossAI(creature, DATA_SKARVALD_DALRONN)
    {
        OtherBossData = 0;
        IsInGhostForm = me->GetEntry() == NPC_SKARVALD_GHOST || me->GetEntry() == NPC_DALRONN_GHOST;
    }

    void Reset() override
    {
        if (IsInGhostForm)
        {
            // Call this here since ghosts aren't set in combat as they spawn.
            DoZoneInCombat(me, 50.0f);
        }
        else
            _Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (!IsInGhostForm)
            _EnterCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* otherBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(OtherBossData)))
        {
            if (otherBoss->IsAlive())
            {
                Talk(SAY_DIED_FIRST);
                me->RemoveFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                otherBoss->AI()->DoAction(ACTION_OTHER_JUST_DIED);
                DoCast(me, OtherBossData == DATA_DALRONN ? SPELL_SUMMON_SKARVALD_GHOST : SPELL_SUMMON_DALRONN_GHOST, true);
            }
            else
            {
                Talk(SAY_DEATH);
                otherBoss->AI()->DoAction(ACTION_DESPAWN_SUMMONS);
                _JustDied();
            }
        }
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_OTHER_JUST_DIED:
                events.ScheduleEvent(EVENT_DEATH_RESPONSE, 2000);
                break;
            case ACTION_DESPAWN_SUMMONS:
                summons.DespawnAll();
                break;
            default:
                break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (eventId == EVENT_DEATH_RESPONSE)
            Talk(SAY_DEATH_RESPONSE);
    }

    void KilledUnit(Unit* who) override
    {
        if (!IsInGhostForm && who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    protected:
        uint32 OtherBossData;
        bool IsInGhostForm;
};

class boss_skarvald_the_constructor : public CreatureScript
{
    public:
        boss_skarvald_the_constructor() : CreatureScript("boss_skarvald_the_constructor") { }

        struct boss_skarvald_the_constructorAI : public generic_boss_controllerAI
        {
            boss_skarvald_the_constructorAI(Creature* creature) : generic_boss_controllerAI(creature)
            {
                OtherBossData = DATA_DALRONN;
                Enraged = false;
            }

            void Reset() override
            {
                Enraged = false;
                generic_boss_controllerAI::Reset();
            }

            void EnterCombat(Unit* who) override
            {
                generic_boss_controllerAI::EnterCombat(who);

                if (!IsInGhostForm)
                    Talk(SAY_AGGRO);

                events.ScheduleEvent(EVENT_SKARVALD_CHARGE, 5000);
                events.ScheduleEvent(EVENT_STONE_STRIKE, 10000);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SKARVALD_CHARGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, SkarvaldChargePredicate(me)))
                            DoCast(target, SPELL_CHARGE);
                        events.ScheduleEvent(EVENT_CHARGE, urand(5000, 10000));
                        break;
                    case EVENT_STONE_STRIKE:
                        DoCastVictim(SPELL_STONE_STRIKE);
                        events.ScheduleEvent(EVENT_STONE_STRIKE, urand(5000, 10000));
                        break;
                    default:
                        generic_boss_controllerAI::ExecuteEvent(eventId);
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (!Enraged && !IsInGhostForm && me->HealthBelowPctDamaged(15, damage))
                {
                    Enraged = true;
                    DoCast(me, SPELL_ENRAGE);
                }
            }
            private:
                bool Enraged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardeKeepAI<boss_skarvald_the_constructorAI>(creature);
        }
};

class boss_dalronn_the_controller : public CreatureScript
{
    public:
        boss_dalronn_the_controller() : CreatureScript("boss_dalronn_the_controller") { }

        struct boss_dalronn_the_controllerAI : public generic_boss_controllerAI
        {
            boss_dalronn_the_controllerAI(Creature* creature) : generic_boss_controllerAI(creature)
            {
                OtherBossData = DATA_SKARVALD;
            }

            void EnterCombat(Unit* who) override
            {
                generic_boss_controllerAI::EnterCombat(who);

                events.ScheduleEvent(EVENT_SHADOW_BOLT, 1000);
                events.ScheduleEvent(EVENT_DEBILITATE, 5000);

                if (!IsInGhostForm)
                    events.ScheduleEvent(EVENT_DELAYED_AGGRO_SAY, 5000);

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_SKELETONS, 10000);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2100); //give a 100ms pause to try cast other spells
                        break;
                    case EVENT_DEBILITATE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            DoCast(target, SPELL_DEBILITATE);
                        events.ScheduleEvent(EVENT_DEBILITATE, urand(5000, 10000));
                        break;
                    case EVENT_SUMMON_SKELETONS:
                        DoCast(me, SPELL_SUMMON_SKELETONS);
                        events.ScheduleEvent(EVENT_SUMMON_SKELETONS, urand(10000, 30000));
                        break;
                    case EVENT_DELAYED_AGGRO_SAY:
                        Talk(SAY_AGGRO);
                        break;
                    default:
                        generic_boss_controllerAI::ExecuteEvent(eventId);
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUtgardeKeepAI<boss_dalronn_the_controllerAI>(creature);
        }
};

void AddSC_boss_skarvald_dalronn()
{
    new boss_skarvald_the_constructor();
    new boss_dalronn_the_controller();
}
