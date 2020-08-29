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

#define CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER
#include "tc_catch2.h"

#include "Timer.h"

TEST_CASE("TimeTracker: Check if time passed")
{
    TimeTracker tracker(1000 /*ms*/);
    REQUIRE_FALSE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 1s);

    tracker.Update(500 /*ms*/);
    REQUIRE_FALSE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 500ms);

    tracker.Update(500 /*ms*/);
    REQUIRE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 0s);

    tracker.Update(500 /*ms*/);
    REQUIRE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == -500ms);
}

TEST_CASE("TimeTracker: Reset timer")
{
    TimeTracker tracker(1000 /*ms*/);
    REQUIRE_FALSE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 1s);

    tracker.Update(1000 /*ms*/);
    REQUIRE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 0s);

    tracker.Reset(1000 /*ms*/);
    REQUIRE_FALSE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 1s);

    tracker.Update(1000 /*ms*/);
    REQUIRE(tracker.Passed());
    REQUIRE(tracker.GetExpiry() == 0s);
}
