/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "GuildMgr.h"
#include "InspectPackets.h"
#include "Player.h"

void WorldSession::HandleInspectOpcode(WorldPackets::Inspect::Inspect& inspect)
{
    Player* player = ObjectAccessor::FindPlayer(inspect.Target);
    if (!player)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleInspectOpcode: Target %s not found.", inspect.Target.ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleInspectOpcode: Target %s.", inspect.Target.ToString().c_str());

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    WorldPackets::Inspect::InspectResult inspectResult;
    inspectResult.InspecteeGUID = inspect.Target;

    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            inspectResult.Items.emplace_back(item, i);
    }

    inspectResult.ClassID = player->getClass();
    inspectResult.GenderID = player->getGender();

    if (sWorld->getBoolConfig(CONFIG_TALENTS_INSPECTING) || GetPlayer()->IsGameMaster())
    {
        PlayerTalentMap const* talents = player->GetTalentMap(player->GetActiveTalentGroup());
        for (PlayerTalentMap::value_type const& v : *talents)
        {
            if (v.second != PLAYERSPELL_REMOVED)
                inspectResult.Talents.push_back(v.first);
        }

        for (uint8 i = 0; i < MAX_GLYPH_SLOT_INDEX; ++i)
            inspectResult.Glyphs.push_back(player->GetGlyph(player->GetActiveTalentGroup(), i));
    }

    if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId()))
    {
        inspectResult.GuildData.HasValue = true;

        WorldPackets::Inspect::InspectGuildData& guildData = inspectResult.GuildData.Value;
        guildData.GuildGUID = guild->GetGUID();
        guildData.NumGuildMembers = guild->GetMembersCount();
        guildData.AchievementPoints = guild->GetAchievementMgr().GetAchievementPoints();
    }

    inspectResult.InspecteeGUID = inspect.Target;
    inspectResult.SpecializationID = player->GetSpecId(player->GetActiveTalentGroup());

    SendPacket(inspectResult.Write());
}

void WorldSession::HandleRequestHonorStatsOpcode(WorldPackets::Inspect::RequestHonorStats& request)
{
    Player* player = ObjectAccessor::FindPlayer(request.TargetGUID);
    if (!player)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleRequestHonorStatsOpcode: Target %s not found.", request.TargetGUID.ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleRequestHonorStatsOpcode: Target %s.", request.TargetGUID.ToString().c_str());

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    WorldPackets::Inspect::InspectHonorStats honorStats;
    honorStats.PlayerGUID  = request.TargetGUID;
    honorStats.LifetimeHK  = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    honorStats.YesterdayHK = player->GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_YESTERDAY_KILLS);
    honorStats.TodayHK     = player->GetUInt16Value(PLAYER_FIELD_KILLS, PLAYER_FIELD_KILLS_OFFSET_TODAY_KILLS);
    honorStats.LifetimeMaxRank = 0; /// @todo

    SendPacket(honorStats.Write());
}

void WorldSession::HandleInspectPVP(WorldPackets::Inspect::InspectPVPRequest& request)
{
    /// @todo: deal with request.InspectRealmAddress

    Player* player = ObjectAccessor::FindPlayer(request.InspectTarget);
    if (!player)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleInspectPVP: Target %s not found.", request.InspectTarget.ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleInspectPVP: Target %s, InspectRealmAddress %u.", request.InspectTarget.ToString().c_str(), request.InspectRealmAddress);

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    WorldPackets::Inspect::InspectPVPResponse response;
    response.ClientGUID = request.InspectTarget;
    /// @todo: fill brackets

    SendPacket(response.Write());
}

void WorldSession::HandleQueryInspectAchievements(WorldPackets::Inspect::QueryInspectAchievements& inspect)
{
    Player* player = ObjectAccessor::FindPlayer(inspect.Guid);
    if (!player)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleQueryInspectAchievements: [%s] inspected unknown Player [%s]", GetPlayer()->GetGUID().ToString().c_str(), inspect.Guid.ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleQueryInspectAchievements: [%s] inspected Player [%s]", GetPlayer()->GetGUID().ToString().c_str(), inspect.Guid.ToString().c_str());

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    player->SendRespondInspectAchievements(GetPlayer());
}
