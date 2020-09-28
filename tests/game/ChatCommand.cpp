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

#include "Chat.h"
#include "ChatCommand.h"

using namespace Trinity::ChatCommands;
using namespace std::string_view_literals;

struct DummyChatHandler : ChatHandler
{
    DummyChatHandler() : ChatHandler(nullptr) {}
    void SendSysMessage(std::string_view, bool) override {}
    char const* GetTrinityString(uint32) const override { return ""; }
};

template <typename F>
static void TestChatCommand(std::string_view c, F f, Optional<bool> expected = true)
{
    DummyChatHandler handler;
    bool r = Trinity::Impl::ChatCommands::CommandInvoker(*+f)(&handler, c);
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

    SECTION("Floating point argument")
    {
        TestChatCommand("0.5", [](ChatHandler*, float f)
        {
            REQUIRE(f == 0.5);
            return true;
        });
        TestChatCommand("true", [](ChatHandler*, float) { return true; }, false);
    }

    SECTION("std::vector<uint16>")
    {
        TestChatCommand("1 2 3 4 5 6 7 8 9 10", [](ChatHandler*, std::vector<uint16> v)
        {
            REQUIRE(v == std::vector<uint16>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
            return true;
        });
    }

    SECTION("std::array<uint16>")
    {
        TestChatCommand("1 2 3 4 5 6 7 8 9 10", [](ChatHandler*, std::array<uint16, 10> v)
        {
            REQUIRE(v == std::array<uint16, 10>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
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

    SECTION("Variant<>")
    {
        TestChatCommand("0x1ffff", [](ChatHandler*, Variant<uint16, uint32> v)
        {
            REQUIRE(v.holds_alternative<uint32>());
            REQUIRE(v.get<uint32>() == 0x1ffff);
            return true;
        });
        TestChatCommand("0xffff", [](ChatHandler*, Variant<uint16, uint32> v)
        {
            REQUIRE(v.holds_alternative<uint16>());
            REQUIRE(v.get<uint16>() == 0xffff);
            return true;
        });
        TestChatCommand("0x1ffff", [](ChatHandler*, Variant<uint32, uint16> v)
        {
            REQUIRE(v.holds_alternative<uint32>());
            REQUIRE(v.get<uint32>() == 0x1ffff);
            return true;
        });
    }
}
