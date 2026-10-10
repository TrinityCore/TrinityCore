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

TEST_CASE("Battleground client instance IDs are unique within each map and bracket", "[Battleground][Instances]")
{
    BattlegroundCleanup cleanup;

    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, BG_BRACKET_ID_FIRST) == 1);
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, BG_BRACKET_ID_FIRST) == 2);
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, BG_BRACKET_ID_FIRST) == 3);
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_WS, BG_BRACKET_ID_FIRST) == 1);
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, BattlegroundBracketId(1)) == 1);
}

TEST_CASE("Deleted battlegrounds release the lowest client instance ID", "[Battleground][Instances]")
{
    BattlemasterListEntry entry = {};
    BattlegroundTemplate bgTemplate = {};
    bgTemplate.Id = BATTLEGROUND_AV;
    bgTemplate.BattlemasterEntry = &entry;
    PVPDifficultyEntry bracket = {};
    BattlegroundCleanup cleanup;
    uint32 const clientId = GENERATE(1u, 2u);
    for (uint32 id = 1; id <= 3; ++id)
        REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, bracket.GetBracketId()) == id);
    Battleground* bg = new Battleground(&bgTemplate);
    bg->SetInstanceID(200001);
    bg->SetClientInstanceID(clientId);
    bg->SetBracket(&bracket);
    sBattlegroundMgr->AddBattleground(bg);

    sBattlegroundMgr->Update(BATTLEGROUND_OBJECTIVE_UPDATE_INTERVAL + 1);

    REQUIRE(sBattlegroundMgr->GetBattleground(200001, BATTLEGROUND_AV) == nullptr);
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, bracket.GetBracketId()) == clientId);
    REQUIRE(BattlegroundTestAccess::CreateClientVisibleInstanceId(BATTLEGROUND_AV, bracket.GetBracketId()) == 4);
}
