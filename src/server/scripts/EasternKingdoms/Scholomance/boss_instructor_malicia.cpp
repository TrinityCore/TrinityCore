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

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

enum MaliciaSpells
{
    SPELL_CALL_OF_GRAVES        = 17831,
    SPELL_CORRUPTION            = 11672,
    SPELL_FLASH_HEAL            = 10917,
    SPELL_RENEW                 = 10929,
    SPELL_HEALING_TOUCH         = 9889
};

enum MaliciaEvents
{
    EVENT_CALL_OF_GRAVES = 1,
    EVENT_CORRUPTION,
    EVENT_FLASH_HEAL,
    EVENT_RENEW,
    EVENT_HEALING_TOUCH
};

// 10505 - Instructor Malicia
struct boss_instructor_malicia : public BossAI
{
    boss_instructor_malicia(Creature* creature) : BossAI(creature, DATA_INSTRUCTOR_MALICIA)
    {
        Initialize();
    }

    void Initialize()
    {
        FlashCounter = 0;
        TouchCounter = 0;
    }

    uint32 FlashCounter;
    uint32 TouchCounter;

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CALL_OF_GRAVES, 4s);
        events.ScheduleEvent(EVENT_CORRUPTION, 8s);
        events.ScheduleEvent(EVENT_RENEW, 32s);
        events.ScheduleEvent(EVENT_FLASH_HEAL, 38s);
        events.ScheduleEvent(EVENT_HEALING_TOUCH, 45s);
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
                case EVENT_CALL_OF_GRAVES:
                    DoCastSelf(SPELL_CALL_OF_GRAVES);
                    events.Repeat(65s);
                    break;
                case EVENT_CORRUPTION:
                    DoCast(SelectTarget(SelectTargetMethod::Random, 0, 100, true), SPELL_CORRUPTION);
                    events.Repeat(24s);
                    break;
                case EVENT_RENEW:
                    DoCastSelf(SPELL_RENEW);
                    events.Repeat(10s);
                    break;
                case EVENT_FLASH_HEAL:
                    // 5 Flash Heal will be cast
                    DoCastSelf(SPELL_FLASH_HEAL);
                    if (FlashCounter < 2)
                    {
                        events.ScheduleEvent(EVENT_FLASH_HEAL, 5s);
                        ++FlashCounter;
                    }
                    else
                    {
                        FlashCounter=0;
                        events.ScheduleEvent(EVENT_FLASH_HEAL, 30s);
                    }
                    break;
                case EVENT_HEALING_TOUCH:
                    // 3 Healing Touch will be cast
                    DoCastSelf(SPELL_HEALING_TOUCH);
                    if (TouchCounter < 2)
                    {
                        events.ScheduleEvent(EVENT_HEALING_TOUCH, 5500ms);
                        ++TouchCounter;
                    }
                    else
                    {
                        TouchCounter=0;
                        events.ScheduleEvent(EVENT_HEALING_TOUCH, 30s);
                    }
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

void AddSC_boss_instructormalicia()
{
    RegisterScholomanceCreatureAI(boss_instructor_malicia);
}
