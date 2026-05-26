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

/*
 * Timers requires update
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "razorfen_downs.h"

enum MordreshTexts
{
    SAY_OOC_1               = 0,
    SAY_OOC_2               = 1,
    SAY_OOC_3               = 2,
    SAY_AGGRO               = 3
};

enum MordreshSpells
{
    SPELL_FIREBALL          = 12466,
    SPELL_FIRE_NOVA         = 12470
};

enum MordreshEvents
{
    EVENT_OOC_1            = 1,
    EVENT_OOC_2,
    EVENT_OOC_3,
    EVENT_OOC_4,

    EVENT_FIREBALL,
    EVENT_FIRE_NOVA
};

// 7357 - Mordresh Fire Eye
struct boss_mordresh_fire_eye : public BossAI
{
    boss_mordresh_fire_eye(Creature* creature) : BossAI(creature, DATA_MORDRESH_FIRE_EYE) { }

    void Reset() override
    {
        _Reset();
        events.ScheduleEvent(EVENT_OOC_1, 10s);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.Reset();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_FIREBALL, 0s);
        events.ScheduleEvent(EVENT_FIRE_NOVA, 8s, 12s);
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
                        events.ScheduleEvent(EVENT_OOC_2, 8s);
                        break;
                    case EVENT_OOC_2:
                        Talk(SAY_OOC_2);
                        events.ScheduleEvent(EVENT_OOC_3, 3s);
                        break;
                    case EVENT_OOC_3:
                        me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                        events.ScheduleEvent(EVENT_OOC_4, 6s);
                        break;
                    case EVENT_OOC_4:
                        Talk(SAY_OOC_3);
                        events.ScheduleEvent(EVENT_OOC_1, 14s);
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
                    events.Repeat(2400ms, 3800ms);
                    break;
                case EVENT_FIRE_NOVA:
                    DoCastSelf(SPELL_FIRE_NOVA);
                    events.Repeat(11s, 16s);
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

void AddSC_boss_mordresh_fire_eye()
{
    RegisterRazorfenDownsCreatureAI(boss_mordresh_fire_eye);
}
