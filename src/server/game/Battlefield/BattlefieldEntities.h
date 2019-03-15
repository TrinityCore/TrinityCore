/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_BATTLEFIELD_ENTITIES_H_
#define TRINITY_BATTLEFIELD_ENTITIES_H_

#include "Common.h"
#include "SharedDefines.h"

class Battlefield;
class GameObject;
class ObjectGuid;

enum BattlefieldBuildingType : uint8
{
    BATTLEFIELD_BUILDING_TYPE_DOOR,
    BATTLEFIELD_BUILDING_TYPE_TITANRELIC,
    BATTLEFIELD_BUILDING_TYPE_WALL,
    BATTLEFIELD_BUILDING_TYPE_DOOR_LAST,
    BATTLEFIELD_BUILDING_TYPE_KEEP_TOWER,
    BATTLEFIELD_BUILDING_TYPE_TOWER
};

enum BattlefieldBuildingState : uint8
{
    BATTLEFIELD_BUILDING_STATE_NONE,
    BATTLEFIELD_BUILDING_STATE_NEUTRAL_INTACT,
    BATTLEFIELD_BUILDING_STATE_NEUTRAL_DAMAGED,
    BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED,
    BATTLEFIELD_BUILDING_STATE_HORDE_INTACT,
    BATTLEFIELD_BUILDING_STATE_HORDE_DAMAGED,
    BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED,
    BATTLEFIELD_BUILDING_STATE_ALLIANCE_INTACT,
    BATTLEFIELD_BUILDING_STATE_ALLIANCE_DAMAGED,
    BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED
};

class BattlefieldBuildingInfo
{
public:
    explicit BattlefieldBuildingInfo(uint8 type, uint32 gameObjectEntry, uint32 worldState);

    uint8 Type;
    uint32 GameObjectEntry;
    uint32 WorldState;

private:
    BattlefieldBuildingInfo(BattlefieldBuildingInfo const&) = delete;
};

class TC_GAME_API BattlefieldBuilding
{
public:
    explicit BattlefieldBuilding(Battlefield* battlefield, uint32 entry, uint32 worldState);

    ObjectGuid const GetGameObjectGUID() const { return _gameObjectGUID; }
    uint32 GetGameObjectEntry() const { return _info.GameObjectEntry; }
    bool IsIntact() const { return _state == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED || _state == BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED || _state == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED; }
    bool IsDestroyed() const { return _state == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED || _state == BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED || _state == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED; }
    bool IsDamaged() const { return _state == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DAMAGED || _state == BATTLEFIELD_BUILDING_STATE_HORDE_DAMAGED || _state == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DAMAGED; }

private:
    BattlefieldBuilding(BattlefieldBuilding const&) = delete;

    // constant information
    Battlefield* _battlefield;
    BattlefieldBuildingInfo const _info;
    BattlefieldBuildingType _type;

    BattlefieldBuildingState _state;
    ObjectGuid _gameObjectGUID;
    PvPTeamId _teamControl;
};

#endif
