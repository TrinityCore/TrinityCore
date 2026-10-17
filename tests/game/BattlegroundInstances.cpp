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
#include "BattlegroundMgr.h"
#include "DB2Stores.h"
#include "DB2Structure.h"
#include "DummyData.h"
#include "Util.h"

struct BattlegroundTestAccess
{
    static uint32 CreateClientVisibleInstanceId(BattlegroundTypeId type, BattlegroundBracketId bracket)
    {
        return sBattlegroundMgr->CreateClientVisibleInstanceId(type, bracket);
    }
};

namespace
{
struct BattlegroundCleanup
{
    BattlegroundCleanup() { sBattlegroundMgr->DeleteAllBattlegrounds(); }
    ~BattlegroundCleanup() { sBattlegroundMgr->DeleteAllBattlegrounds(); }
};
}

TEST_CASE("Arena client instance IDs use client metadata for newer maps", "[Battleground][Instances]")
{
    static UnitTestDataLoader::DB2<BattlemasterListEntry, &BattlemasterListEntry::ID> battlemasters(sBattlemasterListStore);
    constexpr uint32 battlemasterId = 20001;
    BattlemasterType type = GENERATE(BattlemasterType::Arena, BattlemasterType::Battleground);
    {
        auto loader = battlemasters.Loader();
        BattlemasterListEntry& entry = loader.Add();
        entry.ID = battlemasterId;
        entry.PvpType = AsUnderlyingType(type);
    }
    BattlegroundCleanup cleanup;

    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BattlegroundTypeId(battlemasterId), BG_BRACKET_ID_FIRST) == (type == BattlemasterType::Arena ? 0 : 1));
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AA, BG_BRACKET_ID_FIRST) == 0);
}
