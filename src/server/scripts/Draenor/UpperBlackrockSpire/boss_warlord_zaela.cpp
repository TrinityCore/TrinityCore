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

enum Spells
{
    SPELL_BLACK_IRON_CYCLONE = 155721,
    SPELL_DESTRUCTIVE_SMITE = 155673
};

enum Events
{
    EVENT_BLACK_IRON_CYCLONE = 1,
    EVENT_DESTRUCTIVE_SMITE
};

class boss_warlord_zaela : public CreatureScript
{
public:
    boss_warlord_zaela() : CreatureScript("boss_warlord_zaela") { }

    struct boss_warlord_zaelaAI : public BossAI
    {
        boss_warlord_zaelaAI(Creature* creature) : BossAI(creature, 77120)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_BLACK_IRON_CYCLONE, 4000);
            events.ScheduleEvent(EVENT_DESTRUCTIVE_SMITE, 8000);
        }

        void KilledUnit(Unit * /*victim*/) override
        {
        }

        void JustDied(Unit * /*victim*/) override
        {
            _JustDied();
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
                case EVENT_BLACK_IRON_CYCLONE:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target,SPELL_BLACK_IRON_CYCLONE);
                    events.ScheduleEvent(EVENT_BLACK_IRON_CYCLONE, 4000);
                    break;
                case EVENT_DESTRUCTIVE_SMITE:
                    DoCastVictim(SPELL_DESTRUCTIVE_SMITE);
                    events.ScheduleEvent(EVENT_DESTRUCTIVE_SMITE, 8000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_warlord_zaelaAI(creature);
    }
};

void AddSC_boss_warlord_zaela()
{
    new boss_warlord_zaela();
}
