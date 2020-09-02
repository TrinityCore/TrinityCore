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

#include "StringConvert.h"

TEST_CASE("String to uint32", "[StringConvert]")
{
    REQUIRE(Trinity::StringTo<uint32>("42") == 42);
    REQUIRE(Trinity::StringTo<uint32>("42", 10) == 42);
    REQUIRE(Trinity::StringTo<uint32>(" 42") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("tail42") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("42tail") == std::nullopt);

    REQUIRE(Trinity::StringTo<uint32>("ff", 16) == 0xff);
    REQUIRE(Trinity::StringTo<uint32>("0xff") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("0xff", 0) == 0xff);

    REQUIRE(Trinity::StringTo<uint32>("101010", 2) == 0b101010);
    REQUIRE(Trinity::StringTo<uint32>("0b101010") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("0b101010", 0) == 0b101010);

    REQUIRE(Trinity::StringTo<uint32>("5000000000") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("100000000", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("0x100000000", 0) == std::nullopt);
    REQUIRE(Trinity::StringTo<uint32>("0xffffffff", 0) == 0xffffffff);
}

TEST_CASE("String to uint64", "[StringConvert]")
{
    REQUIRE(Trinity::StringTo<uint64>("42") == 42);
    REQUIRE(Trinity::StringTo<uint64>("42", 10) == 42);
    REQUIRE(Trinity::StringTo<uint64>(" 42") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("tail42") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("42tail") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("-1", 0) == std::nullopt);

    REQUIRE(Trinity::StringTo<uint64>("ff", 16) == 0xff);
    REQUIRE(Trinity::StringTo<uint64>("0xff") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("0xff", 0) == 0xff);

    REQUIRE(Trinity::StringTo<uint64>("101010", 2) == 0b101010);
    REQUIRE(Trinity::StringTo<uint64>("0b101010") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("0b101010", 0) == 0b101010);

    REQUIRE(Trinity::StringTo<uint64>("5000000000") == 5000000000ULL);
    REQUIRE(Trinity::StringTo<uint64>("100000000", 16) == 0x100000000ULL);

    REQUIRE(Trinity::StringTo<uint64>("20000000000000000000") == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("10000000000000000", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("0x10000000000000000", 0) == std::nullopt);
    REQUIRE(Trinity::StringTo<uint64>("0xFFFFFFFFFFFFFFFF", 0) == 0xffffffffffffffffULL);
}

TEST_CASE("String to int32", "[StringConvert]")
{
    REQUIRE(Trinity::StringTo<int32>("-42") == -42);
    REQUIRE(Trinity::StringTo<int32>("42") == 42);
    REQUIRE(Trinity::StringTo<int32>("+42") == std::nullopt);
    REQUIRE(Trinity::StringTo<int32>("--42") == std::nullopt);
    REQUIRE(Trinity::StringTo<int32>("~42") == std::nullopt);
    REQUIRE(Trinity::StringTo<int32>("42-") == std::nullopt);

    REQUIRE(Trinity::StringTo<int32>("-ffff", 16) == -0xffff);
    REQUIRE(Trinity::StringTo<int32>("ffffffff", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<int32>("7fffffff", 16) == 0x7fffffff);
}

TEST_CASE("String to int64", "[StringConvert]")
{
    REQUIRE(Trinity::StringTo<int64>("-42") == -42);
    REQUIRE(Trinity::StringTo<int64>("42") == 42);
    REQUIRE(Trinity::StringTo<int64>("+42") == std::nullopt);
    REQUIRE(Trinity::StringTo<int64>("--42") == std::nullopt);
    REQUIRE(Trinity::StringTo<int64>("~42") == std::nullopt);
    REQUIRE(Trinity::StringTo<int64>("42-") == std::nullopt);

    REQUIRE(Trinity::StringTo<int64>("-ffff", 16) == -0xffff);
    REQUIRE(Trinity::StringTo<int64>("ffffffff", 16) == 0xffffffff);
    REQUIRE(Trinity::StringTo<int64>("7fffffff", 16) == 0x7fffffff);

    REQUIRE(Trinity::StringTo<int64>("ffffffffffffffff", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<int64>("7fffffffffffffff", 16) == 0x7fffffffffffffffLL);

    REQUIRE(Trinity::StringTo<int64>("-8500000000000000", 16) == std::nullopt);
}

TEST_CASE("String to smaller integer types", "[StringConvert]")
{
    REQUIRE(Trinity::StringTo<uint8>("0xff", 0) == 0xff);
    REQUIRE(Trinity::StringTo<uint8>("0x1ff", 0) == std::nullopt);

    REQUIRE(Trinity::StringTo<int8>("0xff", 0) == std::nullopt);
    REQUIRE(Trinity::StringTo<int8>("0x7f", 0) == 0x7f);
    REQUIRE(Trinity::StringTo<int8>("-7f", 16) == -0x7f);

    REQUIRE(Trinity::StringTo<uint16>("0x1ff", 0) == 0x1ff);
    REQUIRE(Trinity::StringTo<uint16>("0x1ffff", 0) == std::nullopt);
    REQUIRE(Trinity::StringTo<uint16>("-1", 0) == std::nullopt);

    REQUIRE(Trinity::StringTo<int16>("0x1ff", 0) == 0x1ff);
    REQUIRE(Trinity::StringTo<int16>("0xffff", 0) == std::nullopt);
    REQUIRE(Trinity::StringTo<int16>("0x7fff", 0) == 0x7fff);
    REQUIRE(Trinity::StringTo<int16>("-1", 0) == -1);
}

TEST_CASE("String to boolean", "[StringConvert]")
{
    REQUIRE(Trinity::StringTo<bool>("true") == true);
    REQUIRE(Trinity::StringTo<bool>("false") == false);
    REQUIRE(Trinity::StringTo<bool>("ture") == std::nullopt);
    REQUIRE(Trinity::StringTo<bool>("true", 10) == std::nullopt);
    REQUIRE(Trinity::StringTo<bool>("1") == true);
    REQUIRE(Trinity::StringTo<bool>("1", 10) == true);
    REQUIRE(Trinity::StringTo<bool>("0", 10) == false);
}

TEST_CASE("String to double", "[StringConvert]")
{
    using namespace Catch::literals;
    REQUIRE(Trinity::StringTo<double>("0.5") == 0.5);
    REQUIRE(Trinity::StringTo<double>("0.1") == 0.1_a);
    REQUIRE(Trinity::StringTo<double>("1.2.3") == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("1e+5") == 100000.0);
    REQUIRE(Trinity::StringTo<double>("1e+3+5") == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("a1.5") == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("1.5tail") == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("0x0") == 0.0);
    REQUIRE(Trinity::StringTo<double>("0x0", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("0", 16) == 0.0);
    REQUIRE(Trinity::StringTo<double>("0x1.BC70A3D70A3D7p+6") == 0x1.BC70A3D70A3D7p+6);
    REQUIRE(Trinity::StringTo<double>("0x1.BC70A3D70A3D7p+6", 10) == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("0x1.BC70A3D70A3D7p+6", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("1.BC70A3D70A3D7p+6", 16) == 0x1.BC70A3D70A3D7p+6);
    REQUIRE(Trinity::StringTo<double>("0x1.2.3") == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("0x1.AAAp+1-3") == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("1.2.3", 16) == std::nullopt);
    REQUIRE(Trinity::StringTo<double>("1.AAAp+1-3", 16) == std::nullopt);
}
