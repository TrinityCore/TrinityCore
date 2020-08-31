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

#include "DummyData.h"
#include "Hyperlinks.h"
#include "World.h"

using namespace std::string_view_literals;
using namespace Trinity::Hyperlinks;

TEST_CASE("Basic link structure", "[Hyperlinks]")
{
    SECTION("Link without data")
    {
        HyperlinkInfo info = ParseSingleHyperlink("|cabcdef01|HTag|h[text]|h|r");
        REQUIRE(info.ok);
        REQUIRE(info.color == 0xabcdef01);
        REQUIRE(info.color.a == 0xab);
        REQUIRE(info.color.r == 0xcd);
        REQUIRE(info.color.g == 0xef);
        REQUIRE(info.color.b == 0x01);
        REQUIRE(info.tag == "Tag");
        REQUIRE(info.data == "");
        REQUIRE(info.text == "text");
        REQUIRE(info.tail == "");
    }
    SECTION("Link with data")
    {
        HyperlinkInfo info = ParseSingleHyperlink("|c12345678|Htag:data1:data2:data3:data4:data5|h[Text]|h|rtail");
        REQUIRE(info.ok);
        REQUIRE(info.color == 0x12345678);
        REQUIRE(info.color.a == 0x12);
        REQUIRE(info.color.r == 0x34);
        REQUIRE(info.color.g == 0x56);
        REQUIRE(info.color.b == 0x78);
        REQUIRE(info.tag == "tag");
        REQUIRE(info.data == "data1:data2:data3:data4:data5");
        REQUIRE(info.text == "Text");
        REQUIRE(info.tail == "tail");
    }
}

TEST_CASE("|Hitem validation", "[Hyperlinks]")
{
    UnitTestDataLoader::LoadItemTemplates();
    sWorld->setIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY, 1);

    SECTION("Basic item link")
    {
        REQUIRE(true  == CheckAllLinks("This is my |cffffffff|Hitem:6948::::::::60:::::|h[Hearthstone]|h|r. There are many like it, but this one is mine."));
        REQUIRE(true  == CheckAllLinks("Some might call it their |cffffffff|Hitem:6948::::::::60:::::|h[Piedra de hogar]|h|r. They all still take you home."));
        REQUIRE(false == CheckAllLinks("However, if you call it a |cffffffff|Hitem:6948::::::::60:::::|h|h[Doormat]|h|r, that's a step too far. Get it? Step?"));
        REQUIRE(false == CheckAllLinks("Or if you try to pronounce |cffffffff|Hitem::::::::::::::|h|h[Cthulhu fhtagn]|h|r. Also too far."));
        REQUIRE(false == CheckAllLinks("I'm out of witty one-liners. |cffffffff|Hitem|h[This]|h|r is just lacking data."));
        REQUIRE(false == CheckAllLinks("This is a mis-colored |cffa335ee|Hitem:6948::::::::60:::::|h[Hearthstone]|h|r."));
        REQUIRE(false == CheckAllLinks("This is a |cffffffff|Hitem:6948:-1:::::::60:::::|h[Hearthstone]|h|r that is quite negative."));
    }
}

TEST_CASE("|Hachievement validation", "[Hyperlinks]")
{
    UnitTestDataLoader::LoadAchievementTemplates();
    sWorld->setIntConfig(CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY, 1);

    REQUIRE(true  == CheckAllLinks("|cffffff00|Hachievement:4298:Player-0-000000FD:0:0:0:-1:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffffff00|Hachievement|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffffff00|Hachievement:1:Player-0-000000FD:0:0:0:-1:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffff0000|Hachievement:4298:Player-0-000000FD:0:0:0:-1:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffffff00|Hachievement:4298:00000000000000XY:0:0:0:-1:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(true  == CheckAllLinks("|cffffff00|Hachievement:4298:Player-0-000000FD:1:12:20:12:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffffff00|Hachievement:4298:Player-0-000000FD:1:12:40:12:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffffff00|Hachievement:4298:Player-0-000000FD:1:14:20:12:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));
    REQUIRE(false == CheckAllLinks("|cffffff00|Hachievement:4298:Player-0-000000FD:1:0:0:-1:0:0:0:0|h[Heroic: Trial of the Champion]|h|r"));

    REQUIRE(true  == CheckAllLinks("|cffffff00|Hachievement:4298:Player-0-000000FD:1:12:20:12:0:0:0:0|h[Heroico: Prueba del Campe\xc3\xb3n]|h|r"));
}
