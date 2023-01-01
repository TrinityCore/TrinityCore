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
#include "WorldStateDefines.h"

class Map;

namespace WorldPackets::WorldState
{
    class InitWorldStates;
}

class TC_GAME_API WorldStateMgr
{
public:
    static WorldStateMgr* instance();

    void LoadFromDB();

    WorldStateTemplate const* GetWorldStateTemplate(int32 worldStateId) const;

    int32 GetValue(int32 worldStateId, Map const* map) const;
    void SetValue(int32 worldStateId, int32 value, bool hidden, Map* map);
    void SaveValueInDb(int32 worldStateId, int32 value);
    void SetValueAndSaveInDb(int32 worldStateId, int32 value, bool hidden, Map* map);

    WorldStateValueContainer GetInitialWorldStatesForMap(Map const* map) const;

    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& initWorldStates, Map const* map, uint32 playerAreaId) const;
};

#define sWorldStateMgr WorldStateMgr::instance()

#endif
