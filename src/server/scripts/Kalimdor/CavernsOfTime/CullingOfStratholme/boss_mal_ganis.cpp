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

#include "culling_of_stratholme.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"

enum Spells
{
    SPELL_CARRION_SWARM = 52720,
    SPELL_MIND_BLAST = 52722,
    SPELL_SLEEP = 52721,
    SPELL_VAMPIRIC_TOUCH = 52723
};

enum Yells
{
    SAY_KILL = 3,
    SAY_SLAY = 4,
    SAY_SLEEP = 5,
    SAY_30HEALTH = 6,
    SAY_15HEALTH = 7
};

enum Events
{
    EVENT_CARRION_SWARM = 1,
    EVENT_MIND_BLAST,
    EVENT_VAMPIRIC_TOUCH,
    EVENT_SLEEP
};

class boss_mal_ganis : public CreatureScript
{
    public:
        boss_mal_ganis() : CreatureScript("boss_mal_ganis") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            if (!InstanceHasScript(creature, CoSScriptName))
                return nullptr;

            if (creature->GetInstanceScript()->GetData(DATA_INSTANCE_PROGRESS) < MALGANIS_IN_PROGRESS)
                return new NullCreatureAI(creature);
            else
                return new boss_mal_ganisAI(creature);
        }

        struct boss_mal_ganisAI : public BossAI
        {
            boss_mal_ganisAI(Creature* creature) : BossAI(creature, DATA_MAL_GANIS), _defeated(false), _hadYell30(false), _hadYell15(false) { }

            void Reset() override
            {
                if (!_defeated)
                    instance->SetBossState(DATA_MAL_GANIS, NOT_STARTED);
            }

            void DamageTaken(Unit* /*source*/, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = me->GetHealth() - 1;
                    if (_defeated)
                        return;
                    _defeated = true;

                    // @todo hack most likely
                    if (InstanceMap* map = instance->instance->ToInstanceMap())
                        map->PermBindAllPlayers();
                }
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _defeated = false;
                _hadYell30 = false;
                _hadYell15 = false;
                events.ScheduleEvent(EVENT_CARRION_SWARM, Seconds(5));
                events.ScheduleEvent(EVENT_MIND_BLAST, Seconds(6), Seconds(8));
                events.ScheduleEvent(EVENT_VAMPIRIC_TOUCH, Seconds(4));
                events.ScheduleEvent(EVENT_SLEEP, Seconds(17), Seconds(21));
            }

            void JustReachedHome() override
            {
                if (!_defeated)
                    me->DespawnOrUnsummon(Seconds(1));
            }

            void UpdateAI(uint32 diff) override
            {
                if (_defeated)
                {
                    if (me->IsInCombat())
                    {
                        EnterEvadeMode();
                        me->SetImmuneToAll(true);
                    }
                    return;
                }

                if (!UpdateVictim())
                    return;

                if (!_hadYell30 && HealthBelowPct(30))
                {
                    Talk(SAY_30HEALTH);
                    _hadYell30 = true;
                }

                if (!_hadYell15 && HealthBelowPct(15))
                {
                    Talk(SAY_15HEALTH);
                    _hadYell15 = true;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CARRION_SWARM:
                            DoCastAOE(SPELL_CARRION_SWARM);
                            events.Repeat(Seconds(6));
                            break;
                        case EVENT_MIND_BLAST:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 100.0f, true, -int32(sSpellMgr->GetSpellIdForDifficulty(SPELL_SLEEP, me))))
                                DoCast(target, SPELL_MIND_BLAST);
                            else
                                DoCastVictim(SPELL_MIND_BLAST);
                            events.Repeat(Seconds(8), Seconds(12));
                            break;
                        case EVENT_VAMPIRIC_TOUCH:
                            DoCastSelf(SPELL_VAMPIRIC_TOUCH);
                            events.Repeat(Seconds(30));
                            break;
                        case EVENT_SLEEP:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 100.0f))
                                DoCast(target, SPELL_SLEEP);
                            else
                                DoCastVictim(SPELL_SLEEP);
                            events.Repeat(Seconds(10), Seconds(15));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            void KilledUnit(Unit* victim) override
            {
                if (!_defeated && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

        private:
            bool _defeated;
            bool _hadYell30;
            bool _hadYell15;
        };
};

void AddSC_boss_mal_ganis()
{
    new boss_mal_ganis();
}
