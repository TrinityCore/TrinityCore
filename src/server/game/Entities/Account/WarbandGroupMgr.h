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

#ifndef TRINITYCORE_WARBAND_GROUP_MGR_H
#define TRINITYCORE_WARBAND_GROUP_MGR_H

#include "CharacterPackets.h"
#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "ObjectGuid.h"
#include <span>
#include <string>
#include <unordered_set>
#include <vector>

class CollectionMgr;
class WorldSession;

class TC_GAME_API WarbandGroupMgr
{
public:
    static constexpr uint32 MaxWarbandGroups = 20;
    static constexpr uint32 MaxWarbandGroupMembers = 4;

    explicit WarbandGroupMgr(WorldSession* owner);

    void LoadAccountGroups(PreparedQueryResult groupsResult, PreparedQueryResult membersResult);
    void EnsureDefaultGroup(std::span<ObjectGuid const> accountCharacterGuids);
    bool ReplaceGroups(std::vector<WorldPackets::Character::SetupWarbandGroup> const& groups, CollectionMgr const& collectionMgr, std::unordered_set<ObjectGuid> const& validCharacterGuids);
    std::vector<WorldPackets::Character::WarbandGroup> BuildEnumGroups() const;

private:
    struct StoredMember
    {
        uint32 WarbandScenePlacementID = 0;
        int32 Type = 0;
        int32 ContentSetID = 0;
        ObjectGuid Guid;
    };

    struct StoredGroup
    {
        uint64 GroupID = 0;
        uint8 OrderIndex = 0;
        uint32 WarbandSceneID = 0;
        uint32 Flags = 0;
        int32 ContentSetID = 0;
        std::vector<StoredMember> Members;
        std::string Name;
    };

    static uint32 GetDefaultWarbandSceneId();
    static std::vector<uint32> GetDefaultPlacementIdsForScene(uint32 warbandSceneId, uint32 memberCount);
    void SaveToDB();

    WorldSession* _owner;
    std::vector<StoredGroup> _groups;
};

#endif // TRINITYCORE_WARBAND_GROUP_MGR_H
