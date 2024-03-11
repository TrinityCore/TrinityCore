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

#include "UniqueTrackingPtr.h"

struct TestObj
{
    TestObj(bool* deleted = nullptr) : Deleted(deleted) { }

    ~TestObj()
    {
        if (Deleted)
            *Deleted = true;
    }

    bool* Deleted = nullptr;
};

TEST_CASE("Trinity::unique_trackable_ptr frees memory", "[UniqueTrackingPtr]")
{
    bool deleted = false;

    SECTION("reassigning new object deletes old one")
    {
        Trinity::unique_trackable_ptr<TestObj> ptr = Trinity::make_unique_trackable<TestObj>(&deleted);

        ptr.reset(new TestObj());

        REQUIRE(deleted == true);
    }

    SECTION("going out of scope deletes object")
    {
        REQUIRE(deleted == false);

        {
            Trinity::unique_trackable_ptr<TestObj> ptr = Trinity::make_unique_trackable<TestObj>(&deleted);
        }

        REQUIRE(deleted == true);
    }
}

TEST_CASE("Trinity::unique_weak_ptr", "[UniqueTrackingPtr]")
{
    Trinity::unique_trackable_ptr<int> ptr = Trinity::make_unique_trackable<int>();

    Trinity::unique_weak_ptr<int> weakRef = ptr;

    SECTION("when unique_trackable_ptr no longer holds a value then weak cannot retrieve it")
    {
        ptr.reset();

        REQUIRE(weakRef.expired());
        REQUIRE(!weakRef.lock());
    }

    SECTION("when unique_trackable_ptr is reassigned then weak cannot retrieve old value")
    {
        ptr.reset(new int);

        Trinity::unique_weak_ptr<int> weakRef2 = ptr;

        REQUIRE(weakRef.expired());
        REQUIRE(!weakRef2.expired());
        REQUIRE(weakRef.lock() != weakRef2.lock());
    }

    SECTION("when unique_trackable_ptr holds a value then weak can retrieve it")
    {
        REQUIRE(!weakRef.expired());
        REQUIRE(!!weakRef.lock());
    }
}
