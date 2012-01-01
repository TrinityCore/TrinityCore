/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "ruby_sanctum.h"

enum Texts
{
    SAY_AGGRO                   = 0,    // Alexstrasza has chosen capable allies.... A pity that I must END YOU!
    SAY_KILL                    = 1,    // You thought you stood a chance? - It's for the best.
    SAY_ADDS                    = 2,    // Turn them to ash, minions!
    SAY_DEATH                   = 3,    // HALION! I...
};

enum Spells
{
    // General Zarithrian
    SPELL_INTIMIDATING_ROAR     = 74384,
    SPELL_CLEAVE_ARMOR          = 74367,
    // Zarithrian Spawn Stalker
    SPELL_SUMMON_FLAMECALLER    = 74398,
    // Onyx Flamecaller
    SPELL_BLAST_NOVA            = 74392,
    SPELL_LAVA_GOUT             = 74394,
};

enum Events
{
    // General Zarithrian
    EVENT_CLEAVE                    = 1,
    EVENT_INTIDMDATING_ROAR         = 2,
    EVENT_SUMMON_ADDS               = 3,
    // Onyx Flamecaller
    EVENT_BLAST_NOVA                = 4,
    EVENT_LAVA_GOUT                 = 5,
};

uint32 const MAX_PATH_FLAMECALLER_WAYPOINTS = 12;

Position const FlamecallerWaypoints[MAX_PATH_FLAMECALLER_WAYPOINTS*2] =
{
    // East
    {3042.971f, 419.8809f, 86.94320f, 0.0f},
    {3043.971f, 419.8809f, 86.94320f, 0.0f},
    {3044.885f, 428.8281f, 86.19320f, 0.0f},
    {3045.494f, 434.7930f, 85.56398f, 0.0f},
    {3045.900f, 438.7695f, 84.81398f, 0.0f},
    {3045.657f, 456.8290f, 85.95601f, 0.0f},
    {3043.657f, 459.0790f, 87.20601f, 0.0f},
    {3042.157f, 460.5790f, 87.70601f, 0.0f},
    {3040.907f, 462.0790f, 88.45601f, 0.0f},
    {3038.907f, 464.0790f, 89.20601f, 0.0f},
    {3025.907f, 478.0790f, 89.70601f, 0.0f},
    {3003.832f, 501.2510f, 89.47303f, 0.0f},
    // West
    {3062.596f, 636.9980f, 82.50338f, 0.0f},
    {3062.514f, 624.9980f, 83.70634f, 0.0f},
    {3062.486f, 620.9980f, 84.33134f, 0.0f},
    {3062.445f, 613.9930f, 84.45634f, 0.0f},
    {3062.445f, 613.9930f, 84.45634f, 0.0f},
    {3059.208f, 610.6501f, 85.39581f, 0.0f},
    {3055.958f, 606.9001f, 86.14581f, 0.0f},
    {3046.458f, 596.4001f, 86.89581f, 0.0f},
    {3043.958f, 593.4001f, 87.64581f, 0.0f},
    {3040.458f, 589.9001f, 88.39581f, 0.0f},
    {3034.458f, 583.1501f, 88.89581f, 0.0f},
    {3014.970f, 561.8073f, 88.83527f, 0.0f},
};

class boss_general_zarithrian : public CreatureScript
{
    public:
        boss_general_zarithrian() : CreatureScript("boss_general_zarithrian") { }

        struct boss_general_zarithrianAI : public BossAI
        {
            boss_general_zarithrianAI(Creature* creature) : BossAI(creature, DATA_GENERAL_ZARITHRIAN)
            {
            }

            void Reset()
            {
                _Reset();
                if (instance->GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE && instance->GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE)
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.Reset();
                events.ScheduleEvent(EVENT_CLEAVE, 15000);
                events.ScheduleEvent(EVENT_INTIDMDATING_ROAR, 42000);
                events.ScheduleEvent(EVENT_SUMMON_ADDS, 40000);
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                instance->SetBossState(DATA_GENERAL_ZARITHRIAN, FAIL);
            }

            // Override to not set adds in combat yet.
            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                // Can't use room boundary here, the gameobject is spawned at the same position as the boss. This is just as good anyway.
                if (me->GetPositionX() > 3060.0f)
                {
                    EnterEvadeMode();
                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_ADDS:
                        {
                            if (Creature* stalker1 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ZARITHIAN_SPAWN_STALKER_1)))
                                stalker1->AI()->DoCast(stalker1, SPELL_SUMMON_FLAMECALLER);
                            if (Creature* stalker2 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ZARITHIAN_SPAWN_STALKER_2)))
                                stalker2->AI()->DoCast(stalker2, SPELL_SUMMON_FLAMECALLER);
                            Talk(SAY_ADDS);
                            events.ScheduleEvent(EVENT_SUMMON_ADDS, 42000);
                            break;
                        }
                        case EVENT_INTIDMDATING_ROAR:
                            DoCast(me, SPELL_INTIMIDATING_ROAR, true);
                            events.ScheduleEvent(EVENT_INTIDMDATING_ROAR, 42000);
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE_ARMOR);
                            events.ScheduleEvent(EVENT_CLEAVE, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_general_zarithrianAI>(creature);
        }
};

class npc_onyx_flamecaller : public CreatureScript
{
    public:
        npc_onyx_flamecaller() : CreatureScript("npc_onyx_flamecaller") { }

        struct npc_onyx_flamecallerAI : public npc_escortAI
        {
            npc_onyx_flamecallerAI(Creature* creature) : npc_escortAI(creature)
            {
                _instance = creature->GetInstanceScript();
                npc_escortAI::SetDespawnAtEnd(false);
            }

            void Reset()
            {
                _lavaGoutCount = 0;
                me->setActive(true);
                AddWaypoints();
                Start(true, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_BLAST_NOVA, urand(20000, 30000));
                _events.ScheduleEvent(EVENT_LAVA_GOUT, 5000);
            }

            void EnterEvadeMode()
            {
                // Prevent EvadeMode
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                // Let Zarithrian count as summoner. _instance cant be null since we got GetRubySanctumAI
                if (Creature* zarithrian = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_GENERAL_ZARITHRIAN)))
                    zarithrian->AI()->JustSummoned(me);
            }

            void WaypointReached(uint32 pointId)
            {
                if (pointId == MAX_PATH_FLAMECALLER_WAYPOINTS || pointId == MAX_PATH_FLAMECALLER_WAYPOINTS*2)
                {
                    DoZoneInCombat();
                    SetEscortPaused(true);
                }
            }

            void AddWaypoints()
            {
                if (me->GetPositionY() < 500.0f)
                {
                    for (uint8 i = 0; i < MAX_PATH_FLAMECALLER_WAYPOINTS; i++)
                        AddWaypoint(i, FlamecallerWaypoints[i].GetPositionX(), FlamecallerWaypoints[i].GetPositionY(), FlamecallerWaypoints[i].GetPositionZ());
                }
                else
                {
                    for (uint8 i = 0, j = MAX_PATH_FLAMECALLER_WAYPOINTS; j < MAX_PATH_FLAMECALLER_WAYPOINTS*2; j++, i++)
                        AddWaypoint(i, FlamecallerWaypoints[j].GetPositionX(), FlamecallerWaypoints[j].GetPositionY(), FlamecallerWaypoints[j].GetPositionZ());
                }
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLAST_NOVA:
                            DoCastAOE(SPELL_BLAST_NOVA);
                            _events.ScheduleEvent(EVENT_BLAST_NOVA, urand(20000, 30000));
                            break;
                        case EVENT_LAVA_GOUT:
                            if (_lavaGoutCount >= 3)
                            {
                                _lavaGoutCount = 0;
                                _events.ScheduleEvent(EVENT_LAVA_GOUT, 8000);
                                break;
                            }
                            DoCastVictim(SPELL_LAVA_GOUT);
                            _lavaGoutCount++;
                            _events.ScheduleEvent(EVENT_LAVA_GOUT, 1500);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
            bool _movementComplete;
            InstanceScript* _instance;
            uint8 _lavaGoutCount;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_onyx_flamecallerAI>(creature);
        }
};

void AddSC_boss_general_zarithrian()
{
    new boss_general_zarithrian();
    new npc_onyx_flamecaller();
}
