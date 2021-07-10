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

#include "WorldSession.h"
#include "InspectPackets.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"

void WorldSession::HandleRequestHonorStatsOpcode(WorldPackets::Inspect::RequestHonorStats& packet) 
{
    Player* player = ObjectAccessor::GetPlayer(*_player, packet.TargetGUID);
    if (!player)
    {
        TC_LOG_DEBUG("network", "CMSG_REQUEST_HONOR_STATS: No player found from %s", packet.TargetGUID.ToString().c_str());
        return;
    }

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    WorldPackets::Inspect::InspectHonorStats inspectHonorStats;
    inspectHonorStats.PlayerGUID = player->GetGUID();
    inspectHonorStats.LifetimeHK  = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    inspectHonorStats.YesterdayHK = player->GetUInt16Value(PLAYER_FIELD_KILLS, 1);
    inspectHonorStats.TodayHK     = player->GetUInt16Value(PLAYER_FIELD_KILLS, 0);
    inspectHonorStats.LifetimeMaxRank = 0; // @todo

    SendPacket(inspectHonorStats.Write());
}

void WorldSession::HandleRequestInspectRatedBgStatsOpcode(WorldPackets::Inspect::RequestInspectRatedBgStats& packet)
{
    Player* player = ObjectAccessor::GetPlayer(*_player, packet.TargetGUID);
    if (!player)
    {
        TC_LOG_DEBUG("network", "CMSG_REQUEST_INSPECT_RATED_BG_STATS: No player found from %s", packet.TargetGUID.ToString().c_str());
        return;
    }

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    WorldPackets::Inspect::InspectRatedBgStats inspectRatedBgStats;
    inspectRatedBgStats.PlayerGUID = player->GetGUID();
    inspectRatedBgStats.Played = 0; // @todo
    inspectRatedBgStats.Rating = 0; // @todo
    inspectRatedBgStats.Won = 0; // @todo

    SendPacket(inspectRatedBgStats.Write());
}
