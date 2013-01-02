/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "the_botanica.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_KILL                    = 1,
    SAY_ARCANE_RESONANCE        = 2,
    SAY_ARCANE_DEVASTATION      = 3,
    EMOTE_SUMMON                = 4,
    SAY_SUMMON                  = 5,
    SAY_DEATH                   = 6
};

enum Spells
{
    SPELL_ARCANE_RESONANCE      = 34794,
    SPELL_ARCANE_DEVASTATION    = 34799,
    SPELL_SUMMON_REINFORCEMENTS = 34803
};

enum
{
    EVENT_ARCANE_RESONANCE      = 1,
    EVENT_ARCANE_DEVASTATION    = 2
};

class boss_commander_sarannis : public CreatureScript
{
    public: boss_commander_sarannis() : CreatureScript("boss_commander_sarannis") { }

        struct boss_commander_sarannisAI : public BossAI
        {
            boss_commander_sarannisAI(Creature* creature) : BossAI(creature, DATA_COMMANDER_SARANNIS) { }

            void Reset()
            {
                _Reset();
                _phase = true;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_ARCANE_RESONANCE, 42700);
                events.ScheduleEvent(EVENT_ARCANE_DEVASTATION, 15200);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void DamageTaken(Unit* /*killer*/, uint32 &damage)
            {
                if (me->HealthBelowPctDamaged(50, damage) && _phase)
                {
                    _phase = false;
                    Talk(EMOTE_SUMMON);
                    Talk(SAY_SUMMON);
                    DoCast(me, SPELL_SUMMON_REINFORCEMENTS);
                }
            }

            void JustSummoned(Creature* summon)
            {
                BossAI::JustSummoned(summon);
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_ARCANE_RESONANCE:
                            Talk(SAY_ARCANE_RESONANCE);
                            DoCastVictim(SPELL_ARCANE_RESONANCE, true);
                            events.ScheduleEvent(EVENT_ARCANE_RESONANCE, 42700);
                            break;
                        case EVENT_ARCANE_DEVASTATION:
                            Talk(SAY_ARCANE_DEVASTATION);
                            DoCastVictim(SPELL_ARCANE_DEVASTATION, true);
                            events.ScheduleEvent(EVENT_ARCANE_DEVASTATION, urand(11000, 19200));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _phase;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_commander_sarannisAI(creature);
        }
};

void AddSC_boss_commander_sarannis()
{
    new boss_commander_sarannis();
}
