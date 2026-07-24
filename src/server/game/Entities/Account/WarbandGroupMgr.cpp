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

#include "WarbandGroupMgr.h"
#include "CharacterPackets.h"
#include "CollectionMgr.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "WorldSession.h"

WarbandGroupMgr::WarbandGroupMgr(WorldSession* owner) : _owner(owner)
{
}

void WarbandGroupMgr::LoadAccountGroups(PreparedQueryResult groupsResult, PreparedQueryResult membersResult)
{
    _groups.clear();

    if (groupsResult)
    {
        do
        {
            Field* fields = groupsResult->Fetch();
            StoredGroup& group = _groups.emplace_back();
            group.GroupID = fields[0].GetUInt64();
            group.OrderIndex = fields[1].GetUInt8();
            group.WarbandSceneID = fields[2].GetUInt32();
            group.Flags = fields[3].GetUInt32();
            group.ContentSetID = fields[4].GetInt32();
            group.Name = fields[5].GetString();
        } while (groupsResult->NextRow());
    }

    if (membersResult)
    {
        do
        {
            Field* fields = membersResult->Fetch();
            uint64 groupId = fields[0].GetUInt64();
            StoredGroup* group = nullptr;
            for (StoredGroup& storedGroup : _groups)
            {
                if (storedGroup.GroupID == groupId)
                {
                    group = &storedGroup;
                    break;
                }
            }

            if (!group)
                continue;

            StoredMember& member = group->Members.emplace_back();
            member.Guid = ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt64());
            member.WarbandScenePlacementID = fields[2].GetUInt32();
            member.Type = fields[3].GetInt32();
            member.ContentSetID = fields[4].GetInt32();
        } while (membersResult->NextRow());
    }
}

uint32 WarbandGroupMgr::GetDefaultWarbandSceneId()
{
    for (WarbandSceneEntry const* warbandScene : sWarbandSceneStore)
        if (warbandScene->GetFlags().HasFlag(WarbandSceneFlags::IsDefault))
            return warbandScene->ID;

    return 29;
}

std::vector<uint32> WarbandGroupMgr::GetDefaultPlacementIdsForScene(uint32 warbandSceneId, uint32 memberCount)
{
    std::vector<uint32> result;
    std::vector<WarbandScenePlacementEntry const*> const* placements = sDB2Manager.GetWarbandScenePlacementsForScene(warbandSceneId);
    if (!placements)
        return result;

    for (WarbandScenePlacementEntry const* placement : *placements)
    {
        if (result.size() >= memberCount)
            break;

        result.push_back(placement->ID);
    }

    return result;
}

void WarbandGroupMgr::EnsureDefaultGroup(std::span<ObjectGuid const> accountCharacterGuids)
{
    if (!_groups.empty())
        return;

    StoredGroup& group = _groups.emplace_back();
    group.GroupID = 1;
    group.OrderIndex = 0;
    group.WarbandSceneID = GetDefaultWarbandSceneId();
    group.Flags = 0;
    group.ContentSetID = 0;
    group.Name = "Favorites";

    uint32 memberCount = std::min<uint32>(accountCharacterGuids.size(), MaxWarbandGroupMembers);
    std::vector<uint32> placementIds = GetDefaultPlacementIdsForScene(group.WarbandSceneID, memberCount);
    for (uint32 i = 0; i < memberCount; ++i)
    {
        StoredMember& member = group.Members.emplace_back();
        member.Type = 0;
        member.ContentSetID = 0;
        member.Guid = accountCharacterGuids[i];
        member.WarbandScenePlacementID = i < placementIds.size() ? placementIds[i] : 0;
    }

    SaveToDB();
}

bool WarbandGroupMgr::ReplaceGroups(std::vector<WorldPackets::Character::SetupWarbandGroup> const& groups, CollectionMgr const& collectionMgr, std::unordered_set<ObjectGuid> const& validCharacterGuids)
{
    if (groups.size() > MaxWarbandGroups)
    {
        TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} sent {} groups (max {})", _owner->GetBattlenetAccountId(), groups.size(), MaxWarbandGroups);
        return false;
    }

    std::unordered_set<uint64> seenGroupIds;
    std::unordered_set<ObjectGuid> seenMemberGuids;

    std::vector<StoredGroup> newGroups;
    newGroups.reserve(groups.size());

    for (WorldPackets::Character::SetupWarbandGroup const& packetGroup : groups)
    {
        if (!seenGroupIds.insert(packetGroup.GroupID).second)
        {
            TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} duplicate groupId {}", _owner->GetBattlenetAccountId(), packetGroup.GroupID);
            return false;
        }

        if (packetGroup.Members.size() > MaxWarbandGroupMembers)
        {
            TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} group {} has {} members (max {})", _owner->GetBattlenetAccountId(), packetGroup.GroupID, packetGroup.Members.size(), MaxWarbandGroupMembers);
            return false;
        }

        if (!collectionMgr.HasWarbandScene(packetGroup.WarbandSceneID))
        {
            TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} group {} uses unowned warband scene {}", _owner->GetBattlenetAccountId(), packetGroup.GroupID, packetGroup.WarbandSceneID);
            return false;
        }

        if (packetGroup.Name.empty() || packetGroup.Name.size() > 255)
        {
            TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} group {} has invalid name length {}", _owner->GetBattlenetAccountId(), packetGroup.GroupID, packetGroup.Name.size());
            return false;
        }

        if (packetGroup.OrderIndex >= MaxWarbandGroups)
        {
            TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} group {} orderIndex {} out of range", _owner->GetBattlenetAccountId(), packetGroup.GroupID, packetGroup.OrderIndex);
            return false;
        }

        StoredGroup& group = newGroups.emplace_back();
        group.GroupID = packetGroup.GroupID;
        group.OrderIndex = packetGroup.OrderIndex;
        group.WarbandSceneID = packetGroup.WarbandSceneID;
        group.Flags = packetGroup.Flags;
        group.ContentSetID = packetGroup.ContentSetID;
        group.Name = packetGroup.Name;

        for (WorldPackets::Character::WarbandGroupMember const& packetMember : packetGroup.Members)
        {
            if (packetMember.Type == 0)
            {
                if (!packetMember.Guid)
                    continue;

                if (!validCharacterGuids.contains(packetMember.Guid))
                {
                    TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} rejected guid {} for group {}", _owner->GetBattlenetAccountId(), packetMember.Guid.ToString(), packetGroup.GroupID);
                    return false;
                }

                if (!seenMemberGuids.insert(packetMember.Guid).second)
                {
                    TC_LOG_DEBUG("network", "WarbandGroupMgr::ReplaceGroups: account {} duplicate member guid {} in setup", _owner->GetBattlenetAccountId(), packetMember.Guid.ToString());
                    return false;
                }
            }

            StoredMember& member = group.Members.emplace_back();
            member.WarbandScenePlacementID = packetMember.WarbandScenePlacementID;
            member.Type = packetMember.Type;
            member.ContentSetID = packetMember.ContentSetID;
            member.Guid = packetMember.Guid;
        }
    }

    _groups = std::move(newGroups);
    SaveToDB();
    return true;
}

std::vector<WorldPackets::Character::WarbandGroup> WarbandGroupMgr::BuildEnumGroups() const
{
    std::vector<WorldPackets::Character::WarbandGroup> result;
    result.reserve(_groups.size());

    for (StoredGroup const& storedGroup : _groups)
    {
        WorldPackets::Character::WarbandGroup& group = result.emplace_back();
        group.GroupID = storedGroup.GroupID;
        group.OrderIndex = storedGroup.OrderIndex;
        group.WarbandSceneID = storedGroup.WarbandSceneID;
        group.Flags = storedGroup.Flags;
        group.ContentSetID = storedGroup.ContentSetID;
        group.Name = storedGroup.Name;
        group.Members.reserve(storedGroup.Members.size());

        for (StoredMember const& storedMember : storedGroup.Members)
        {
            WorldPackets::Character::WarbandGroupMember& member = group.Members.emplace_back();
            member.WarbandScenePlacementID = storedMember.WarbandScenePlacementID;
            member.Type = storedMember.Type;
            member.ContentSetID = storedMember.ContentSetID;
            member.Guid = storedMember.Guid;
        }
    }

    return result;
}

void WarbandGroupMgr::SaveToDB()
{
    LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_WARBAND_GROUP_MEMBERS);
    stmt->setUInt32(0, _owner->GetBattlenetAccountId());
    trans->Append(stmt);

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_WARBAND_GROUPS);
    stmt->setUInt32(0, _owner->GetBattlenetAccountId());
    trans->Append(stmt);

    for (StoredGroup const& group : _groups)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_WARBAND_GROUP);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt64(1, group.GroupID);
        stmt->setUInt8(2, group.OrderIndex);
        stmt->setUInt32(3, group.WarbandSceneID);
        stmt->setUInt32(4, group.Flags);
        stmt->setInt32(5, group.ContentSetID);
        stmt->setString(6, group.Name);
        trans->Append(stmt);

        for (StoredMember const& member : group.Members)
        {
            if (member.Type == 0 && !member.Guid)
                continue;

            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_WARBAND_GROUP_MEMBER);
            stmt->setUInt32(0, _owner->GetBattlenetAccountId());
            stmt->setUInt64(1, group.GroupID);
            stmt->setUInt64(2, member.Guid.GetCounter());
            stmt->setUInt32(3, member.WarbandScenePlacementID);
            stmt->setInt32(4, member.Type);
            stmt->setInt32(5, member.ContentSetID);
            trans->Append(stmt);
        }
    }

    LoginDatabase.CommitTransaction(trans);
}
