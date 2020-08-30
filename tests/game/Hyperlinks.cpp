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

#include "Hyperlinks.h"
#include "ChatCommand.h"

using namespace std::string_view_literals;
using namespace Trinity::Hyperlinks;

TEST_CASE("Basic link structure", "[Hyperlinks]")
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
