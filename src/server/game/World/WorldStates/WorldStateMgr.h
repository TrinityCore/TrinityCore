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


#ifndef WorldStateMgr_h__
#define WorldStateMgr_h__

#include "Define.h"
#include "Optional.h"
#include <unordered_map>
#include <vector>

namespace WorldPackets
{
    namespace WorldState
    {
        struct WorldStateInfo;
    }
}

typedef std::unordered_map<uint32, int32> WorldStateDataMap;

class TC_GAME_API WorldStateMgr
{
public:
    static WorldStateMgr* instance();

    void LoadFromDB();

    void FillDefaultWorldStatesForMap(WorldStateDataMap& worldStates, uint32 mapId);
    void AppendRealmWorldStates(std::vector<WorldPackets::WorldState::WorldStateInfo>& worldStates);

    void SetRealmWorldStateValue(uint32 worldStateId, int32 value);
    int32 GetRealmWorldStateValue(uint32 worldStateId) const;

private:
    std::unordered_map<uint32 /*mapId*/, WorldStateDataMap> _mapWorldStates;
    std::unordered_map<uint32 /*worldStateId*/, int32 /*value*/> _realmWorldStates;
};

#define sWorldStateMgr WorldStateMgr::instance()

#endif
