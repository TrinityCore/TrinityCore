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

/*
Name: Boss_Anzu
%Complete: 80%
Comment:
Category: Auchindoun, Sethekk Halls
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "sethekk_halls.h"

enum Says
{
    SAY_SUMMON_BROOD            = 0,
    SAY_SPELL_BOMB              = 1
};

enum Spells
{
    SPELL_PARALYZING_SCREECH    = 40184,
    SPELL_SPELL_BOMB            = 40303,
    SPELL_CYCLONE_OF_FEATHERS   = 40321,
    SPELL_BANISH_SELF           = 42354,
    SPELL_FLESH_RIP             = 40199
};

enum Events
{
    EVENT_PARALYZING_SCREECH    = 1,
    EVENT_SPELL_BOMB            = 2,
    EVENT_CYCLONE_OF_FEATHERS   = 3,
    EVENT_SUMMON                = 4
};

Position const PosSummonBrood[7] =
{
    { -118.1717f, 284.5299f, 121.2287f, 2.775074f },
    { -98.15528f, 293.4469f, 109.2385f, 0.174533f },
    { -99.70160f, 270.1699f, 98.27389f, 6.178465f },
    { -69.25543f, 303.0768f, 97.84479f, 5.532694f },
    { -87.59662f, 263.5181f, 92.70478f, 1.658063f },
    { -73.54323f, 276.6267f, 94.25807f, 2.802979f },
    { -81.70527f, 280.8776f, 44.58830f, 0.526849f }
};

class boss_anzu : public CreatureScript
{
    public:
        boss_anzu() : CreatureScript("boss_anzu") { }

        struct boss_anzuAI : public BossAI
        {
            boss_anzuAI(Creature* creature) : BossAI(creature, DATA_ANZU)
            {
                Initialize();
            }

            void Initialize()
            {
                _under33Percent = false;
                _under66Percent = false;
            }

            void Reset() override
            {
                //_Reset();
                events.Reset();
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_PARALYZING_SCREECH, 14000);
                events.ScheduleEvent(EVENT_CYCLONE_OF_FEATHERS, 5000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void DamageTaken(Unit* /*killer*/, uint32 &damage) override
            {
                if (me->HealthBelowPctDamaged(33, damage) && !_under33Percent)
                {
                    _under33Percent = true;
                    Talk(SAY_SUMMON_BROOD);
                    events.ScheduleEvent(EVENT_SUMMON, 3000);
                }

                if (me->HealthBelowPctDamaged(66, damage) && !_under66Percent)
                {
                    _under66Percent = true;
                    Talk(SAY_SUMMON_BROOD);
                    events.ScheduleEvent(EVENT_SUMMON, 3000);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PARALYZING_SCREECH:
                            DoCastVictim(SPELL_PARALYZING_SCREECH);
                            events.ScheduleEvent(EVENT_PARALYZING_SCREECH, 26000);
                            break;
                        case EVENT_CYCLONE_OF_FEATHERS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CYCLONE_OF_FEATHERS);
                            events.ScheduleEvent(EVENT_CYCLONE_OF_FEATHERS, 21000);
                            break;
                        case EVENT_SUMMON:
                            // TODO: Add pathing for Brood of Anzu
                            for (uint8 i = 0; i < 7; i++)
                                me->SummonCreature(NPC_BROOD_OF_ANZU, PosSummonBrood[i], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 46000);

                            DoCast(me, SPELL_BANISH_SELF);
                            events.ScheduleEvent(EVENT_SPELL_BOMB, 12000);
                            break;
                        case EVENT_SPELL_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                if (target->getPowerType() == POWER_MANA)
                                {
                                    DoCast(target, SPELL_SPELL_BOMB);
                                    Talk(SAY_SPELL_BOMB, target);
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                bool _under33Percent;
                bool _under66Percent;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetSethekkHallsAI<boss_anzuAI>(creature);
        }
};

void AddSC_boss_anzu()
{
    new boss_anzu();
}
