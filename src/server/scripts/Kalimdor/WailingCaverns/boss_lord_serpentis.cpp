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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "wailing_caverns.h"

enum Texts
{
    SAY_AGGRO = 0
};

enum Spells
{
    SPELL_LIGHTNING_BOLT = 12167,
    SPELL_DRUID_SLUMBER  = 8040,
    SPELL_HEALING_TOUCH  = 23381
};

enum Events
{
    EVENT_LIGHTNING_BOLT = 1,
    EVENT_HEALING_TOUCH  = 2,
    EVENT_DRUID_SLUMBER  = 3
};

class boss_lord_serpentis : public CreatureScript
{
public:
    boss_lord_serpentis() : CreatureScript("boss_lord_serpentis") { }

    struct boss_lord_serpentisAI : public BossAI
    {
        boss_lord_serpentisAI(Creature* creature) : BossAI(creature, DATA_LORD_SERPENTIS) { }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, Seconds(1));
            events.ScheduleEvent(EVENT_HEALING_TOUCH, Seconds(27));
            events.ScheduleEvent(EVENT_DRUID_SLUMBER, Seconds(7));
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
                    case EVENT_LIGHTNING_BOLT:
                        DoCastVictim(SPELL_LIGHTNING_BOLT);
                        events.Repeat(Seconds(15));
                        break;
                    case EVENT_HEALING_TOUCH:
                        DoCastSelf(SPELL_HEALING_TOUCH);
                        events.Repeat(Seconds(9));
                        break;
                    case EVENT_DRUID_SLUMBER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_DRUID_SLUMBER);
                        events.Repeat(Seconds(40));
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
        return GetWailingCavernsAI<boss_lord_serpentisAI>(creature);
    }
};


void AddSC_boss_lord_serpentis()
{
    new boss_lord_serpentis();
}
