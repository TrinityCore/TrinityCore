/*
 * Copyright 2023 AzgathCore
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
#include "hellfire_citadel.h"

enum Spells
{
    SPELL_UNSTABLE_ORB = 182001,
    SPELL_ENERGIZED_FIST = 181355,
    SPELL_BARRAGE = 185282,
    SPELL_FIREBOMB = 181999,
    SPELL_FALLING_SLAM = 186449,
    SPELL_ARTILLERY = 182094,
    SPELL_IMMOLATION = 179896,
    SPELL_BLITZ = 179889,
    SPELL_POUNDING = 182020,
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
};

struct boss_iron_reaver : public BossAI
{
    boss_iron_reaver(Creature* creature) : BossAI(creature, DATA_IRON_REAVER) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_UNSTABLE_ORB, 10s);
        events.ScheduleEvent(SPELL_ENERGIZED_FIST, 5s);
        events.ScheduleEvent(SPELL_BARRAGE, 15s);
        events.ScheduleEvent(SPELL_FIREBOMB, 15s);
        events.ScheduleEvent(SPELL_FALLING_SLAM, 15s);
        events.ScheduleEvent(SPELL_ARTILLERY, 15s);
        events.ScheduleEvent(SPELL_IMMOLATION, 15s);
        events.ScheduleEvent(SPELL_BLITZ, 15s);
        events.ScheduleEvent(SPELL_POUNDING, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {

        case SPELL_UNSTABLE_ORB:
        {
            DoCast(SPELL_UNSTABLE_ORB);
            events.Repeat(15s);
            break;
        }
        case SPELL_ENERGIZED_FIST:
        {
            DoCast(SPELL_ENERGIZED_FIST);
            events.Repeat(5s);
            break;
        }
        case SPELL_BARRAGE:
        {
            DoCast(SPELL_BARRAGE);
            events.Repeat(15s);
            break;
        }
        case SPELL_FIREBOMB:
        {
            DoCast(SPELL_FIREBOMB);
            events.Repeat(15s);
            break;
        }
        case SPELL_FALLING_SLAM:
        {
            DoCast(SPELL_FALLING_SLAM);
            events.Repeat(15s);
            break;
        }
        case SPELL_ARTILLERY:
        {
            DoCast(SPELL_ARTILLERY);
            events.Repeat(15s);
            break;
        }
        case SPELL_IMMOLATION:
        {
            DoCast(SPELL_IMMOLATION);
            events.Repeat(15s);
            break;
        }
        case SPELL_BLITZ:
        {
            DoCast(SPELL_BLITZ);
            events.Repeat(15s);
            break;
        }
        case SPELL_POUNDING:
        {
            DoCast(SPELL_POUNDING);
            events.Repeat(15s);
            break;
        }
        default:
            break;
        }
    }
};

void AddSC_boss_iron_reaver()
{
    RegisterCreatureAI(boss_iron_reaver);
}
