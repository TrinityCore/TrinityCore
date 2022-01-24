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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "oculus.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_MAGIC_PULL                              = 51336,
    SPELL_THUNDERING_STOMP                        = 50774,
    SPELL_UNSTABLE_SPHERE_PASSIVE                 = 50756,
    SPELL_UNSTABLE_SPHERE_PULSE                   = 50757,
    SPELL_UNSTABLE_SPHERE_TIMER                   = 50758,
    NPC_UNSTABLE_SPHERE                           = 28166,
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_KILL                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_PULL                                      = 3,
    SAY_STOMP                                     = 4
};

enum DrakosAchievement
{
    ACHIEV_TIMED_START_EVENT                      = 18153,
};

enum DrakosEvents
{
    EVENT_MAGIC_PULL = 1,
    EVENT_STOMP,
    EVENT_BOMB_SUMMON
};

class boss_drakos : public CreatureScript
{
    public:
        boss_drakos() : CreatureScript("boss_drakos") { }

        struct boss_drakosAI : public BossAI
        {
            boss_drakosAI(Creature* creature) : BossAI(creature, DATA_DRAKOS)
            {
                Initialize();
            }

            void Initialize()
            {
                postPull = false;
            }

            void Reset() override
            {
                _Reset();

                events.ScheduleEvent(EVENT_MAGIC_PULL, 15s);
                events.ScheduleEvent(EVENT_STOMP, 15s);
                events.ScheduleEvent(EVENT_BOMB_SUMMON, 2s);

                Initialize();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOMB_SUMMON:
                            {
                                for (uint8 i = 0; i <= (postPull ? 3 : 0); i++)
                                {
                                    Position position = me->GetRandomNearPosition(frand(0.0f, 10.0f));
                                    me->SummonCreature(NPC_UNSTABLE_SPHERE, position);
                                }
                            }
                            events.ScheduleEvent(EVENT_BOMB_SUMMON, 2s);
                            break;
                        case EVENT_MAGIC_PULL:
                            DoCast(SPELL_MAGIC_PULL);
                            postPull = true;
                            events.ScheduleEvent(EVENT_MAGIC_PULL, 15s);
                            break;
                        case EVENT_STOMP:
                            Talk(SAY_STOMP);
                            DoCast(SPELL_THUNDERING_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, 15s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);

                // start achievement timer (kill Eregos within 20 min)
                instance->DoStartCriteriaTimer(CriteriaStartEvent::SendEvent, ACHIEV_TIMED_START_EVENT);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

        private:
            bool postPull;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetOculusAI<boss_drakosAI>(creature);
        }
};

class npc_unstable_sphere : public CreatureScript
{
    public:
        npc_unstable_sphere() : CreatureScript("npc_unstable_sphere") { }

        struct npc_unstable_sphereAI : public ScriptedAI
        {
            npc_unstable_sphereAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                pulseTimer = 3000;
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveRandom(40.0f);

                me->AddAura(SPELL_UNSTABLE_SPHERE_PASSIVE, me);
                me->AddAura(SPELL_UNSTABLE_SPHERE_TIMER, me);

                Initialize();

                me->DespawnOrUnsummon(19s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (pulseTimer <= diff)
                {
                    DoCast(SPELL_UNSTABLE_SPHERE_PULSE);
                    pulseTimer = 3 * IN_MILLISECONDS;
                }
                else
                    pulseTimer -= diff;
            }

        private:
            uint32 pulseTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetOculusAI<npc_unstable_sphereAI>(creature);
        }
};

void AddSC_boss_drakos()
{
    new boss_drakos();
    new npc_unstable_sphere();
}
