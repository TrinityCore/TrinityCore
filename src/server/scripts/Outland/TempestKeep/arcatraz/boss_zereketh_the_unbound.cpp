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
#include "ScriptedCreature.h"
#include "arcatraz.h"

enum Say
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_SHADOW_NOVA                 = 2,
    SAY_DEATH                       = 3
};

enum Spells
{
    SPELL_VOID_ZONE                 = 36119,
    SPELL_SHADOW_NOVA               = 36127,
    SPELL_SEED_OF_CORRUPTION        = 36123
};

enum Events
{
    EVENT_VOID_ZONE                 = 1,
    EVENT_SHADOW_NOVA               = 2,
    EVENT_SEED_OF_CORRUPTION        = 3
};

class boss_zereketh_the_unbound : public CreatureScript
{
    public:
        boss_zereketh_the_unbound() : CreatureScript("boss_zereketh_the_unbound") { }

        struct boss_zereketh_the_unboundAI : public BossAI
        {
            boss_zereketh_the_unboundAI(Creature* creature) : BossAI(creature, DATA_ZEREKETH) { }

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_VOID_ZONE, urand (6000, 10000));
                events.ScheduleEvent(EVENT_SHADOW_NOVA, urand (6000, 10000));
                events.ScheduleEvent(EVENT_SEED_OF_CORRUPTION, 12s, 20s);
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
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
                        case EVENT_VOID_ZONE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                                DoCast(target, SPELL_VOID_ZONE);
                            events.ScheduleEvent(EVENT_VOID_ZONE, urand (6000, 10000));
                            break;
                        case EVENT_SHADOW_NOVA:
                            DoCastVictim(SPELL_SHADOW_NOVA, true);
                            Talk(SAY_SHADOW_NOVA);
                            events.ScheduleEvent(EVENT_SHADOW_NOVA, urand (6000, 10000));
                            break;
                        case EVENT_SEED_OF_CORRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                                DoCast(target, SPELL_SEED_OF_CORRUPTION);
                            events.ScheduleEvent(EVENT_SEED_OF_CORRUPTION, 12s, 20s);
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
            return GetArcatrazAI<boss_zereketh_the_unboundAI>(creature);
        }
};

void AddSC_boss_zereketh_the_unbound()
{
    new boss_zereketh_the_unbound();
}
