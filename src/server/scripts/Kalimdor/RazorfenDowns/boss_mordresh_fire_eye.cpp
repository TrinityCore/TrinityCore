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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "razorfen_downs.h"

enum Say
{
    SAY_OOC_1               = 0,
    SAY_OOC_2               = 1,
    SAY_OOC_3               = 2,
    SAY_AGGRO               = 3
};

enum Spells
{
    SPELL_FIREBALL          = 12466,
    SPELL_FIRE_NOVA         = 12470
};

enum Events
{
    EVENT_OOC_1            = 1,
    EVENT_OOC_2            = 2,
    EVENT_OOC_3            = 3,
    EVENT_OOC_4            = 4,
    EVENT_FIREBALL         = 5,
    EVENT_FIRE_NOVA        = 6
};

class boss_mordresh_fire_eye : public CreatureScript
{
public:
    boss_mordresh_fire_eye() : CreatureScript("boss_mordresh_fire_eye") { }

    struct boss_mordresh_fire_eyeAI : public BossAI
    {
        boss_mordresh_fire_eyeAI(Creature* creature) : BossAI(creature, DATA_MORDRESH_FIRE_EYE) { }

        void Reset() override
        {
            _Reset();
            events.ScheduleEvent(EVENT_OOC_1, 10000);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            events.Reset();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_FIREBALL, 100ms);
            events.ScheduleEvent(EVENT_FIRE_NOVA, 8s, 12s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_OOC_1:
                            Talk(SAY_OOC_1);
                            events.ScheduleEvent(EVENT_OOC_2, 8000);
                            break;
                        case EVENT_OOC_2:
                            Talk(SAY_OOC_2);
                            events.ScheduleEvent(EVENT_OOC_3, 3000);
                            break;
                        case EVENT_OOC_3:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            events.ScheduleEvent(EVENT_OOC_4, 6000);
                            break;
                        case EVENT_OOC_4:
                            Talk(SAY_OOC_3);
                            events.ScheduleEvent(EVENT_OOC_1, 14000);
                            break;
                    }
                }
                return;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIREBALL:
                        DoCastVictim(SPELL_FIREBALL);
                        events.ScheduleEvent(EVENT_FIREBALL, 2400ms, 3800ms);
                        break;
                    case EVENT_FIRE_NOVA:
                        DoCast(me, SPELL_FIRE_NOVA);
                        events.ScheduleEvent(EVENT_FIRE_NOVA, 11s, 16s);
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
        return GetRazorfenDownsAI<boss_mordresh_fire_eyeAI>(creature);
    }
};

void AddSC_boss_mordresh_fire_eye()
{
    new boss_mordresh_fire_eye();
}
