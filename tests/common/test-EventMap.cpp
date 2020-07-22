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

#include "catch2/catch.hpp"
#include "EventMap.h"

enum EVENTS
{
    EVENT_1 = 1,
    EVENT_2 = 2,
    EVENT_3 = 3
};

enum PHASES
{
    PHASE_1 = 1,
    PHASE_2 = 2
};

enum GROUPS
{
    GROUP_1 = 1,
    GROUP_2 = 2
};

TEST_CASE("Schedule an event", "[EventMap]")
{
    EventMap eventMap;

    REQUIRE(eventMap.Empty());

    eventMap.ScheduleEvent(EVENT_1, 1s);

    REQUIRE_FALSE(eventMap.Empty());

    SECTION("Event has not yet reached its delay")
    {
        eventMap.Update(100);
        uint32 id = eventMap.ExecuteEvent();

        REQUIRE(id == 0);
        REQUIRE_FALSE(eventMap.Empty());
        REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == 900);
    }

    SECTION("Event has reached its delay")
    {
        eventMap.Update(1000);
        uint32 id = eventMap.ExecuteEvent();

        REQUIRE(id == EVENT_1);
        REQUIRE(eventMap.Empty());
        REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == std::numeric_limits<uint32>::max());
    }
}

// TODO: The semantics of this case are not well defined.
//       Document them first, check consumers and adapt test
//       accordingly.
TEST_CASE("Schedule existing event", "[EventMap][!mayfail]")
{
    EventMap eventMap;

    eventMap.ScheduleEvent(EVENT_1, 1s);
    eventMap.ScheduleEvent(EVENT_1, 1s);

    eventMap.Update(1000);
    uint32 id = eventMap.ExecuteEvent();

    REQUIRE(id == EVENT_1);
    REQUIRE(eventMap.Empty());
}

TEST_CASE("Cancel a scheduled event", "[EventMap]")
{
    EventMap eventMap;

    eventMap.ScheduleEvent(EVENT_1, 1s);
    eventMap.ScheduleEvent(EVENT_2, 1s);

    eventMap.CancelEvent(EVENT_1);
    REQUIRE_FALSE(eventMap.Empty());

    eventMap.Update(1000);
    uint32 id = eventMap.ExecuteEvent();

    REQUIRE(id == EVENT_2);
    REQUIRE(eventMap.Empty());
}

TEST_CASE("Cancel non-existing event", "[EventMap]")
{
    EventMap eventMap;
    REQUIRE(eventMap.Empty());

    eventMap.CancelEvent(EVENT_1);
    REQUIRE(eventMap.Empty());
}

TEST_CASE("Reschedule an event", "[EventMap]")
{
    EventMap eventMap;

    eventMap.ScheduleEvent(EVENT_1, 1s);
    eventMap.RescheduleEvent(EVENT_1, 2s);

    eventMap.Update(1000);
    uint32 id = eventMap.ExecuteEvent();

    REQUIRE(id == 0);

    eventMap.Update(1000);
    id = eventMap.ExecuteEvent();

    REQUIRE(id == EVENT_1);
}

TEST_CASE("Reschedule a non-scheduled event", "[EventMap]")
{
    EventMap eventMap;

    eventMap.RescheduleEvent(EVENT_1, 2s);

    eventMap.Update(1000);
    uint32 id = eventMap.ExecuteEvent();

    REQUIRE(id == 0);

    eventMap.Update(1000);
    id = eventMap.ExecuteEvent();

    REQUIRE(id == EVENT_1);
}

TEST_CASE("Schedule event with phase", "[EventMap]")
{
    EventMap eventMap;
    REQUIRE(eventMap.Empty());

    eventMap.ScheduleEvent(EVENT_1, 1s, 0, PHASE_1);
    eventMap.ScheduleEvent(EVENT_2, 1s, 0, PHASE_2);

    SECTION("In default phase. Execute all events.")
    {
        eventMap.Update(1000);

        uint32 id = eventMap.ExecuteEvent();
        REQUIRE(id == EVENT_1);
        REQUIRE_FALSE(eventMap.Empty());

        id = eventMap.ExecuteEvent();
        REQUIRE(id == EVENT_2);
        REQUIRE(eventMap.Empty());
    }

    SECTION("Execute only events of specified phase")
    {
        eventMap.SetPhase(PHASE_1);
        eventMap.Update(1000);

        uint32 id = eventMap.ExecuteEvent();
        REQUIRE(id == EVENT_1);
        REQUIRE_FALSE(eventMap.Empty());

        id = eventMap.ExecuteEvent();
        REQUIRE(id == 0);
        REQUIRE(eventMap.Empty());
    }

    SECTION("Execute events from multiple phases (1)")
    {
        eventMap.AddPhase(PHASE_1);
        eventMap.AddPhase(PHASE_2);
        eventMap.Update(1000);

        uint32 id = eventMap.ExecuteEvent();
        REQUIRE(id == EVENT_1);
        REQUIRE_FALSE(eventMap.Empty());

        id = eventMap.ExecuteEvent();
        REQUIRE(id == EVENT_2);
        REQUIRE(eventMap.Empty());
    }

    SECTION("Execute events from multiple phases (2)")
    {
        eventMap.AddPhase(PHASE_1);
        eventMap.Update(1000);

        uint32 id = eventMap.ExecuteEvent();
        REQUIRE(id == EVENT_1);
        REQUIRE_FALSE(eventMap.Empty());

        eventMap.RemovePhase(PHASE_2);
        id = eventMap.ExecuteEvent();
        REQUIRE(id == 0);
        REQUIRE(eventMap.Empty());
    }
}

TEST_CASE("Phase helper methods", "[EventMap]")
{
    EventMap eventMap;

    eventMap.SetPhase(PHASE_1);
    REQUIRE(eventMap.GetPhaseMask() == 0x1);
    REQUIRE(eventMap.IsInPhase(PHASE_1));
    REQUIRE_FALSE(eventMap.IsInPhase(PHASE_2));

    eventMap.AddPhase(PHASE_2);
    REQUIRE(eventMap.GetPhaseMask() == 0x3);
    REQUIRE(eventMap.IsInPhase(PHASE_1));
    REQUIRE(eventMap.IsInPhase(PHASE_2));

    eventMap.RemovePhase(PHASE_1);
    REQUIRE(eventMap.GetPhaseMask() == 0x2);
    REQUIRE_FALSE(eventMap.IsInPhase(PHASE_1));
    REQUIRE(eventMap.IsInPhase(PHASE_2));
}

TEST_CASE("Cancel event group", "[EventMap]")
{
    EventMap eventMap;
    eventMap.ScheduleEvent(EVENT_2, 1s, GROUP_1);

    SECTION("Only event in group")
    {
        eventMap.CancelEventGroup(GROUP_1);
        REQUIRE(eventMap.Empty());
    }

    SECTION("Group with groupless event")
    {
        eventMap.ScheduleEvent(EVENT_1, 1s);

        eventMap.CancelEventGroup(GROUP_1);
        REQUIRE_FALSE(eventMap.Empty());
    }

    SECTION("Two groups")
    {
        eventMap.ScheduleEvent(EVENT_1, 1s);
        eventMap.ScheduleEvent(EVENT_3, 1s, GROUP_2);

        eventMap.CancelEventGroup(GROUP_1);
        REQUIRE_FALSE(eventMap.Empty());

        eventMap.CancelEventGroup(GROUP_2);
        REQUIRE_FALSE(eventMap.Empty());
    }
}

TEST_CASE("Delay all events", "[EventMap]")
{
    EventMap eventMap;
    eventMap.ScheduleEvent(EVENT_1, 1s);

    REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == 1000);

    SECTION("Without timer update")
    {
        eventMap.DelayEvents(1s);

        // Timer hasn't ticked yet, so maximum delay is 0ms
        REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == 1000);
    }

    SECTION("With timer update smaller than delay")
    {
        eventMap.Update(500);
        eventMap.DelayEvents(1s);

        REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == 1000);
    }

    SECTION("With timer update larger than delay")
    {
        eventMap.Update(2000);
        eventMap.DelayEvents(1s);

        // 1s (init) + 1s (delay) - 2s (tick) = 0s
        REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == 0);
    }
}

TEST_CASE("Delay grouped events", "[EventMap]")
{
    EventMap eventMap;
    eventMap.ScheduleEvent(EVENT_1, 1s, GROUP_1);
    eventMap.ScheduleEvent(EVENT_2, 2s, GROUP_2);
    eventMap.ScheduleEvent(EVENT_3, 6s);

    eventMap.Update(2000);
    eventMap.DelayEvents(3s, GROUP_1);

    REQUIRE(eventMap.GetTimeUntilEvent(EVENT_1) == 2000);
    REQUIRE(eventMap.GetTimeUntilEvent(EVENT_2) == 0);
    REQUIRE(eventMap.GetTimeUntilEvent(EVENT_3) == 4000);
}

TEST_CASE("Reset map", "[EventMap]")
{
    EventMap eventMap;
    eventMap.ScheduleEvent(EVENT_1, 1s);
    eventMap.Reset();

    REQUIRE(eventMap.Empty());
}
