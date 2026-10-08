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
#include "BattlegroundQueue.h"
#include "DB2Structure.h"
#include "Group.h"
#include "Util.h"

namespace
{
struct BattlegroundCleanup
{
    BattlegroundCleanup() { sBattlegroundMgr->DeleteAllBattlegrounds(); }
    ~BattlegroundCleanup() { sBattlegroundMgr->DeleteAllBattlegrounds(); }
};
}

TEST_CASE("Arena queue cancellation releases the invited slot on the actual arena map", "[Battleground][Queue]")
{
    BattlemasterListEntry entry = {};
    bool const arena = GENERATE(false, true);
    entry.PvpType = AsUnderlyingType(arena ? BattlemasterType::Arena : BattlemasterType::Battleground);
    BattlegroundTemplate bgTemplate = {};
    bgTemplate.Id = arena ? BATTLEGROUND_NA : BATTLEGROUND_AV;
    bgTemplate.BattlemasterEntry = &entry;
    PVPDifficultyEntry bracket = {};
    BattlegroundCleanup cleanup;
    Battleground* bg = new Battleground(&bgTemplate);
    bg->SetInstanceID(200002);
    bg->SetBracket(&bracket);
    sBattlegroundMgr->AddBattleground(bg);
    REQUIRE(sBattlegroundMgr->GetBattleground(200002, BATTLEGROUND_TYPE_NONE) == bg);
    REQUIRE(sBattlegroundMgr->GetBattleground(200002, BATTLEGROUND_AA) == (arena ? bg : nullptr));
    REQUIRE(sBattlegroundMgr->GetBattleground(200002, BATTLEGROUND_WS) == nullptr);
    if (!arena)
        return;

    bg->IncreaseInvitedCount(ALLIANCE);
    BattlegroundQueue queue(BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_AA, BattlegroundQueueIdType::Arena, true, 2));
    Group group;
    GroupQueueInfo* groupInfo = queue.AddGroup(nullptr, &group, ALLIANCE, &bracket, false, 0, 0);
    ObjectGuid const guid = ObjectGuid::Create<HighGuid::Player>(200002);
    PlayerQueueInfo& playerInfo = queue.m_QueuedPlayers[guid];
    playerInfo = { 0, groupInfo };
    groupInfo->Players[guid] = &playerInfo;
    groupInfo->IsInvitedToBGInstanceGUID = bg->GetInstanceID();

    queue.RemovePlayer(guid, true);

    REQUIRE(bg->GetInvitedCount(ALLIANCE) == 0);
    REQUIRE(queue.m_QueuedPlayers.empty());
    REQUIRE(queue.m_QueuedGroups[bracket.GetBracketId()][BG_QUEUE_PREMADE_ALLIANCE].empty());
}
