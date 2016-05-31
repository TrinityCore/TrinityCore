/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "scarlet_monastery.h"

enum Says
{
    SAY_AGGRO               = 0,
    SAY_HEALTH1             = 1,
    SAY_HEALTH2             = 2,
    SAY_KILL                = 3,
    SAY_TRIGGER_VORREL      = 0
};

enum Spells
{
    SPELL_SHADOW_WORD_PAIN  = 2767
};

enum Events
{
    EVENT_SHADOW_WORD_PAIN  = 1
};

class boss_interrogator_vishas : public CreatureScript
{
    public:
        boss_interrogator_vishas() : CreatureScript("boss_interrogator_vishas") { }

        struct boss_interrogator_vishasAI : public BossAI
        {
            boss_interrogator_vishasAI(Creature* creature) : BossAI(creature, DATA_INTERROGATOR_VISHAS)
            {
                Initialize();
            }

            void Initialize()
            {
                _yellCount = 0;
            }

            void Reset() override
            {
                Initialize();
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 5000);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                if (Creature* vorrel = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VORREL)))
                    vorrel->AI()->Talk(SAY_TRIGGER_VORREL);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
            {
                if (me->HealthBelowPctDamaged(60, damage) && _yellCount < 1)
                {
                    Talk(SAY_HEALTH1);
                    ++_yellCount;
                }

                if (me->HealthBelowPctDamaged(30, damage) && _yellCount < 2)
                {
                    Talk(SAY_HEALTH2);
                    ++_yellCount;
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_WORD_PAIN:
                        DoCastVictim(SPELL_SHADOW_WORD_PAIN);
                        events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, urand(5000, 15000));
                        break;
                    default:
                        break;
                }
            }

        private:
            uint8 _yellCount;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_interrogator_vishasAI>(creature);
        }
};

void AddSC_boss_interrogator_vishas()
{
    new boss_interrogator_vishas();
}
