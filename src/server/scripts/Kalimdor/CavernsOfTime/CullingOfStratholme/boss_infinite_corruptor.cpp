/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CORRUPTING_BLIGHT                     = 60588,
    SPELL_VOID_STRIKE                           = 60590,
    SPELL_CORRUPTION_OF_TIME_CHANNEL            = 60422,
    SPELL_CORRUPTION_OF_TIME_TARGET             = 60451
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_DEATH                                   = 1,
    SAY_FAIL                                    = 2
};

enum Events
{
    EVENT_CORRUPTING_BLIGHT                     = 1,
    EVENT_VOID_STRIKE
};

class boss_infinite_corruptor : public CreatureScript
{
    public:
        boss_infinite_corruptor() : CreatureScript("boss_infinite_corruptor") { }

        struct boss_infinite_corruptorAI : public BossAI
        {
            boss_infinite_corruptorAI(Creature* creature) : BossAI(creature, DATA_INFINITE) { }

            void Reset() override
            {
                _Reset();

                if (Creature* guardian = me->FindNearestCreature(NPC_GUARDIAN_OF_TIME, 100.0f))
                {
                    DoCast((Unit*)NULL, SPELL_CORRUPTION_OF_TIME_CHANNEL, false);
                    guardian->CastSpell(guardian, SPELL_CORRUPTION_OF_TIME_TARGET, false);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_CORRUPTING_BLIGHT, 7000);
                events.ScheduleEvent(EVENT_VOID_STRIKE, 5000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();

                if (Creature* guardian = me->FindNearestCreature(NPC_GUARDIAN_OF_TIME, 100.0f))
                {
                    guardian->RemoveAurasDueToSpell(SPELL_CORRUPTION_OF_TIME_TARGET);
                    guardian->DespawnOrUnsummon(5000);
                }

                if (Creature* rift = me->FindNearestCreature(NPC_TIME_RIFT, 100.0f))
                    rift->DespawnOrUnsummon();
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CORRUPTING_BLIGHT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                            DoCast(target, SPELL_CORRUPTING_BLIGHT);
                        events.ScheduleEvent(EVENT_CORRUPTING_BLIGHT, 17000);
                        break;
                    case EVENT_VOID_STRIKE:
                        DoCastVictim(SPELL_VOID_STRIKE);
                        events.ScheduleEvent(EVENT_VOID_STRIKE, 5000);
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_infinite_corruptorAI>(creature);
        }
};

void AddSC_boss_infinite_corruptor()
{
    new boss_infinite_corruptor();
}
