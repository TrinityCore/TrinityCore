/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ruby_sanctum.h"
#include "ScriptedEscortAI.h"

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
    SPELL_LAVA_GOUT             = 74394
};

enum Events
{
    // General Zarithrian
    EVENT_CLEAVE = 1,
    EVENT_INTIDMDATING_ROAR,
    EVENT_SUMMON_ADDS,
    EVENT_SUMMON_ADDS2,

    // Onyx Flamecaller
    EVENT_BLAST_NOVA,
    EVENT_LAVA_GOUT
};

enum MinionsMovement
{
    SPLINE_GENERAL_EAST = 1,
    SPLINE_GENERAL_WEST = 2,
    POINT_GENERAL_ROOM  = 3
};

class boss_general_zarithrian : public CreatureScript
{
    public:
        boss_general_zarithrian() : CreatureScript("boss_general_zarithrian") { }

        struct boss_general_zarithrianAI : public BossAI
        {
            boss_general_zarithrianAI(Creature* creature) : BossAI(creature, DATA_GENERAL_ZARITHRIAN) { }

            void Reset() override
            {
                _Reset();
                if (instance->GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE && instance->GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE)
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
            }

            bool CanAIAttack(Unit const* target) const override
            {
                return (instance->GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE && instance->GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE && BossAI::CanAIAttack(target));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_CLEAVE, Seconds(8));
                events.ScheduleEvent(EVENT_INTIDMDATING_ROAR, Seconds(14));
                events.ScheduleEvent(EVENT_SUMMON_ADDS, Seconds(15));
                if (Is25ManRaid())
                    events.ScheduleEvent(EVENT_SUMMON_ADDS2, Seconds(16));
            }

            // Override to not set adds in combat yet.
            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_ADDS:
                            Talk(SAY_ADDS);
                            // no break
                        case EVENT_SUMMON_ADDS2:
                        {
                            if (Creature* stalker1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ZARITHRIAN_SPAWN_STALKER_1)))
                                stalker1->CastSpell(stalker1, SPELL_SUMMON_FLAMECALLER, true);

                            if (Creature* stalker2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ZARITHRIAN_SPAWN_STALKER_2)))
                                stalker2->CastSpell(stalker2, SPELL_SUMMON_FLAMECALLER, true);

                            events.Repeat(Seconds(45));
                            break;
                        }
                        case EVENT_INTIDMDATING_ROAR:
                            DoCastSelf(SPELL_INTIMIDATING_ROAR);
                            events.Repeat(Seconds(35), Seconds(40));
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE_ARMOR);
                            events.ScheduleEvent(EVENT_CLEAVE, Seconds(15));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<boss_general_zarithrianAI>(creature);
        }
};

class npc_onyx_flamecaller : public CreatureScript
{
    public:
        npc_onyx_flamecaller() : CreatureScript("npc_onyx_flamecaller") { }

        struct npc_onyx_flamecallerAI : public ScriptedAI
        {
            npc_onyx_flamecallerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _lavaGoutCount(0) { }

            void Reset() override
            {
                _events.Reset();
                _lavaGoutCount = 0;
                me->SetReactState(REACT_DEFENSIVE);
                MoveToGeneral();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_BLAST_NOVA, Seconds(17));
                _events.ScheduleEvent(EVENT_LAVA_GOUT, Seconds(3));
            }

            void EnterEvadeMode(EvadeReason /*why*/) override { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                // Let Zarithrian count as summoner.
                if (Creature* zarithrian = _instance->GetCreature(DATA_GENERAL_ZARITHRIAN))
                    zarithrian->AI()->JustSummoned(me);
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != SPLINE_CHAIN_MOTION_TYPE && pointId != POINT_GENERAL_ROOM)
                    return;

                me->SetInCombatWithZone();
            }

            void MoveToGeneral()
            {
                if (me->GetPositionY() < 500.0f)
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_GENERAL_ROOM, SPLINE_GENERAL_WEST, false);
                else
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_GENERAL_ROOM, SPLINE_GENERAL_EAST, false);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLAST_NOVA:
                            DoCastAOE(SPELL_BLAST_NOVA);
                            _events.Repeat(Seconds(15), Seconds(20));
                            break;
                        case EVENT_LAVA_GOUT:
                            if (_lavaGoutCount >= 3)
                            {
                                _lavaGoutCount = 0;
                                _events.Repeat(Seconds(8));
                                break;
                            }
                            DoCastVictim(SPELL_LAVA_GOUT);
                            _lavaGoutCount++;
                            _events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
            uint8 _lavaGoutCount;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<npc_onyx_flamecallerAI>(creature);
        }
};

void AddSC_boss_general_zarithrian()
{
    new boss_general_zarithrian();
    new npc_onyx_flamecaller();
}
