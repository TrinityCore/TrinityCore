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

#include "WorldStateMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "World.h"
#include "WorldStatePackets.h"

void WorldStateMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    _mapWorldStates.clear();
    _realmWorldStates.clear();

    //                                               0   1             2
    QueryResult result = WorldDatabase.Query("SELECT ID, DefaultValue, MapID FROM world_states");
    if (!result)
        return;

    uint32 worldStatesCount = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        uint32 defaultValue = fields[1].GetInt32();
        Optional<uint32> mapId;
        if (!fields[2].IsNull())
            mapId = fields[2].GetUInt32();

        if (mapId.has_value())
            _mapWorldStates[*mapId][id] = defaultValue;
        else
            _realmWorldStates[id] = defaultValue;

        ++worldStatesCount;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u map and realm world states %u ms", worldStatesCount, GetMSTimeDiffToNow(oldMSTime));
}

void WorldStateMgr::FillDefaultWorldStatesForMap(WorldStateDataMap& worldStates, uint32 mapId)
{
    std::unordered_map<uint32, WorldStateDataMap>::const_iterator itr = _mapWorldStates.find(mapId);
    if (itr != _mapWorldStates.end())
        worldStates = itr->second;
}

void WorldStateMgr::AppendRealmWorldStates(std::vector<WorldPackets::WorldState::WorldStateInfo>& worldStates)
{
    for (std::pair<uint32 const, int32>& worldState : _realmWorldStates)
        worldStates.emplace_back(worldState.first, worldState.second);
}

void WorldStateMgr::SetRealmWorldStateValue(uint32 worldStateId, int32 value)
{
    _realmWorldStates[worldStateId] = value;

    // Broadcast update to all players on the server
    WorldPackets::WorldState::UpdateWorldState packet;
    packet.VariableID = worldStateId;
    packet.Value = value;
    packet.Write();
    sWorld->SendGlobalMessage(packet.GetRawPacket());
}

int32 WorldStateMgr::GetRealmWorldStateValue(uint32 worldStateId) const
{
    auto itr = _realmWorldStates.find(worldStateId);
    if (itr != _realmWorldStates.end())
        return itr->second;

    return 0;
}

WorldStateMgr* WorldStateMgr::instance()
{
    static WorldStateMgr instance;
    return &instance;
}
