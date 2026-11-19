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

#include "FlatSet.h"

TEST_CASE("Insertion", "[FlatSet]")
{
    Trinity::Containers::FlatSet<int> flat;

    REQUIRE(flat.insert(5).second == true);
    REQUIRE(flat.insert(3).second == true);
    REQUIRE(flat.insert(9).second == true);
    REQUIRE(flat.insert(7).second == true);

    REQUIRE(flat.insert(5).second == false);
    REQUIRE(flat.insert(3).second == false);
    REQUIRE(flat.insert(9).second == false);
    REQUIRE(flat.insert(7).second == false);

    REQUIRE(flat.size() == 4);

    auto itr = flat.begin();
    REQUIRE(*itr == 3);
    ++itr;
    REQUIRE(*itr == 5);
    ++itr;
    REQUIRE(*itr == 7);
    ++itr;
    REQUIRE(*itr == 9);
    ++itr;
    REQUIRE(itr == flat.end());
}

TEST_CASE("Erase", "[FlatSet]")
{
    Trinity::Containers::FlatSet<int> flat;
    flat.insert(3);
    flat.insert(5);
    flat.insert(7);
    flat.insert(9);

    REQUIRE(flat.erase(7) == 1);
    REQUIRE(flat.size() == 3);
}
