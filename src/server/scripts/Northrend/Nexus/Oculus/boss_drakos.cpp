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
#include "oculus.h"

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
    SAY_AGGRO                                     = -1578005,
    SAY_KILL_1                                    = -1578006,
    SAY_KILL_2                                    = -1578007,
    SAY_KILL_3                                    = -1578008,
    SAY_DEATH                                     = -1578009,
    SAY_PULL_1                                    = -1578010,
    SAY_PULL_2                                    = -1578011,
    SAY_PULL_3                                    = -1578012,
    SAY_PULL_4                                    = -1578013,
    SAY_STOMP_1                                   = -1578014,
    SAY_STOMP_2                                   = -1578015,
    SAY_STOMP_3                                   = -1578016
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_drakosAI (creature);
    }

    struct boss_drakosAI : public BossAI
    {
        boss_drakosAI(Creature* creature) : BossAI(creature, DATA_DRAKOS_EVENT) {}

        void Reset()
        {
            _Reset();

            events.ScheduleEvent(EVENT_MAGIC_PULL, 15000);
            events.ScheduleEvent(EVENT_STOMP, 17000);
            events.ScheduleEvent(EVENT_BOMB_SUMMON, 2000);

            postPull = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            DoScriptText(SAY_AGGRO, me);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BOMB_SUMMON:
                        {
                            Position pPosition;
                            me->GetPosition(&pPosition);

                            for (uint8 i = 0; i <= (postPull ? 3 : 0); i++)
                            {
                                me->GetRandomNearPosition(pPosition, float(urand(0, 10)));
                                me->SummonCreature(NPC_UNSTABLE_SPHERE, pPosition);
                            }
                        }
                        events.ScheduleEvent(EVENT_BOMB_SUMMON, 2000);
                        break;
                    case EVENT_MAGIC_PULL:
                        DoCast(SPELL_MAGIC_PULL);
                        postPull = true;
                        events.ScheduleEvent(EVENT_MAGIC_PULL, 15000);
                        break;
                    case EVENT_STOMP:
                        DoScriptText(RAND(SAY_STOMP_1, SAY_STOMP_2, SAY_STOMP_3), me);
                        DoCast(SPELL_THUNDERING_STOMP);
                        events.ScheduleEvent(EVENT_STOMP, 17000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();

            DoScriptText(SAY_DEATH, me);

            // start achievement timer (kill Eregos within 20 min)
            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2, SAY_KILL_3), me);
        }
    private:
        bool postPull;
    };
};

class npc_unstable_sphere : public CreatureScript
{
public:
    npc_unstable_sphere() : CreatureScript("npc_unstable_sphere") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_unstable_sphereAI (creature);
    }

    struct npc_unstable_sphereAI : public ScriptedAI
    {
        npc_unstable_sphereAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MoveRandom(40.0f);

            me->AddAura(SPELL_UNSTABLE_SPHERE_PASSIVE, me);
            me->AddAura(SPELL_UNSTABLE_SPHERE_TIMER, me);

            pulseTimer = 3000;
            deathTimer = 19000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (pulseTimer <= diff)
            {
                DoCast(SPELL_UNSTABLE_SPHERE_PULSE);
                pulseTimer = 3*IN_MILLISECONDS;
            } else pulseTimer -= diff;

            if (deathTimer <= diff)
                me->DisappearAndDie();
            else deathTimer -= diff;
        }
    private:
        uint32 pulseTimer;
        uint32 deathTimer;
    };

};

void AddSC_boss_drakos()
{
    new boss_drakos();
    new npc_unstable_sphere();
}
