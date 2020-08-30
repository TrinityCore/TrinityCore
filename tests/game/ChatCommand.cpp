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

#include "tc_catch2.h"

#include "ChatCommand.h"

using namespace Trinity::ChatCommands;
using namespace std::string_view_literals;

template <typename F>
static void TestChatCommand(char const* c, F f, Optional<bool> expected = true)
{
    bool r = ChatCommand("", 0, false, +f, "")(nullptr, c);
    if (expected)
        REQUIRE(r == *expected);
}

TEST_CASE("Command return pass-through", "[ChatCommand]")
{
    TestChatCommand("", [](ChatHandler*) { return true; }, true);
    TestChatCommand("", [](ChatHandler*) { return false; }, false);
}

TEST_CASE("Command argument parsing", "[ChatCommand]")
{
    SECTION("Single uint32 argument")
    {
        TestChatCommand("42", [](ChatHandler*, uint32 u)
        {
            REQUIRE(u == 42);
            return true;
        });
        TestChatCommand("true", [](ChatHandler*, uint32) { return true; }, false);
    }

    SECTION("std::vector<uint8>")
    {
        TestChatCommand("1 2 3 4 5 6 7 8 9 10", [](ChatHandler*, std::vector<uint8> v)
        {
            REQUIRE(v.size() == 10);
            for (size_t i = 0; i < 10; ++i)
                REQUIRE(v[i] == (i + 1));
            return true;
        });
    }

    SECTION("Hyperlink<player>")
    {
        TestChatCommand("|cffff0000|Hplayer:Test|h[Test]|h|r",
            [](ChatHandler*, Hyperlink<player> player)
            {
                REQUIRE("Test"sv == *player);
                return true;
            }
        );
    }

    SECTION("Two strings")
    {
        TestChatCommand("two strings", [](ChatHandler*, std::string_view v1, std::string_view v2)
        {
            REQUIRE(v1 == "two");
            REQUIRE(v2 == "strings");
            return true;
        });
        TestChatCommand("two strings", [](ChatHandler*, std::string_view) { return true; }, false);
        TestChatCommand("two strings", [](ChatHandler*, Tail t)
        {
            REQUIRE(t == "two strings");
            return true;
        });
    }
}
