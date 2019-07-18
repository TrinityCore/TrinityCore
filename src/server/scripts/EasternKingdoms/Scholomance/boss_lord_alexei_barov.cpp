/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Lord_Alexei_Barov
SD%Complete: 100
SDComment: aura applied/defined in database
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"

enum Spells
{
    SPELL_IMMOLATE                  = 20294,
    SPELL_VEILOFSHADOW              = 17820,
    SPELL_UNHOLY_AURA               = 17467
};

enum Events
{
    EVENT_IMMOLATE                  = 1,
    EVENT_VEILOFSHADOW              = 2
};

class boss_lord_alexei_barov : public CreatureScript
{
    public: boss_lord_alexei_barov() : CreatureScript("boss_lord_alexei_barov") { }

        struct boss_lordalexeibarovAI : public BossAI
        {
            boss_lordalexeibarovAI(Creature* creature) : BossAI(creature, DATA_LORDALEXEIBAROV) { }

            void Reset() override
            {
                _Reset();

                if (!me->HasAura(SPELL_UNHOLY_AURA))
                    DoCast(me, SPELL_UNHOLY_AURA);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_IMMOLATE, 7000);
                events.ScheduleEvent(EVENT_VEILOFSHADOW, 15000);
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
                        case EVENT_IMMOLATE:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_IMMOLATE, true);
                            events.ScheduleEvent(EVENT_IMMOLATE, 12000);
                            break;
                        case EVENT_VEILOFSHADOW:
                            DoCastVictim(SPELL_VEILOFSHADOW, true);
                            events.ScheduleEvent(EVENT_VEILOFSHADOW, 20000);
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
            return GetScholomanceAI<boss_lordalexeibarovAI>(creature);
        }
};

void AddSC_boss_lordalexeibarov()
{
    new boss_lord_alexei_barov();
}
