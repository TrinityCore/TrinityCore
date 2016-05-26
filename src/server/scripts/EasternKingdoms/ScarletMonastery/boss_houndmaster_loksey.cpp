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

enum Yells
{
    SAY_AGGRO                       = 0,
};

enum Spells
{
    SPELL_SUMMONSCARLETHOUND        = 17164,
    SPELL_BLOODLUST                 = 6742
};

enum Events
{
    EVENT_BLOODLUST                 = 1
};

class boss_houndmaster_loksey : public CreatureScript
{
    public:
        boss_houndmaster_loksey() : CreatureScript("boss_houndmaster_loksey") { }

        struct boss_houndmaster_lokseyAI : public BossAI
        {
            boss_houndmaster_lokseyAI(Creature* creature) : BossAI(creature, DATA_HOUNDMASTER_LOKSEY) { }

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                events.ScheduleEvent(EVENT_BLOODLUST, 20000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_BLOODLUST:
                        DoCast(me, SPELL_BLOODLUST);
                        events.ScheduleEvent(EVENT_BLOODLUST, 20000);
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetScarletMonasteryAI<boss_houndmaster_lokseyAI>(creature);
        }
};

void AddSC_boss_houndmaster_loksey()
{
    new boss_houndmaster_loksey();
}
