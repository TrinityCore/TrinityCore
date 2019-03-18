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
#include "ObjectGuid.h"
#include "SharedDefines.h"

class Battlefield;
class GameObject;

enum BattlefieldEntityType : uint8
{
    BATTLEFIELD_ENTITY_TYPE_BUILDING = 0,
    BATTLEFIELD_ENTITY_TYPE_CAPTUREPOINT
};

enum BattlefieldBuildingType : uint8
{
    BATTLEFIELD_BUILDING_TYPE_TOWER = 0,
    BATTLEFIELD_BUILDING_TYPE_WALL,
    BATTLEFIELD_BUILDING_TYPE_KEEP_TOWER,
    BATTLEFIELD_BUILDING_TYPE_DOOR,
    BATTLEFIELD_BUILDING_TYPE_DOOR_LAST,
    BATTLEFIELD_BUILDING_TYPE_TITANRELIC
};

enum BattlefieldBuildingState : uint8
{
    BATTLEFIELD_BUILDING_STATE_NONE = 0,
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

enum BattlefieldCapturePointState : uint8
{
    BATTLEFIELD_CAPTUREPOINT_STATE_NEUTRAL = 0,
    BATTLEFIELD_CAPTUREPOINT_STATE_ALLIANCE,
    BATTLEFIELD_CAPTUREPOINT_STATE_HORDE,
    BATTLEFIELD_CAPTUREPOINT_STATE_NEUTRAL_ALLIANCE_CHALLENGE,
    BATTLEFIELD_CAPTUREPOINT_STATE_NEUTRAL_HORDE_CHALLENGE,
    BATTLEFIELD_CAPTUREPOINT_STATE_ALLIANCE_HORDE_CHALLENGE,
    BATTLEFIELD_CAPTUREPOINT_STATE_HORDE_ALLIANCE_CHALLENGE
};

struct BattlefieldEntityInfo
{
    BattlefieldEntityInfo(BattlefieldEntityType type, uint32 entry, uint32 worldState) :
        EntityType(type), GameObjectEntry(entry), WorldState(worldState) { }

    BattlefieldEntityType EntityType;
    uint32 GameObjectEntry;
    uint32 WorldState;
};

class BattlefieldEntity
{
public:
    explicit BattlefieldEntity(Battlefield* battlefield, BattlefieldEntityType type, uint32 entry, uint32 worldState);
    virtual ~BattlefieldEntity() { }

    Battlefield* Battle;
    BattlefieldEntityInfo const Info;
    ObjectGuid GameObjectGUID;
};

class BattlefieldBuilding : public BattlefieldEntity
{
public:
    explicit BattlefieldBuilding(Battlefield* battlefield, uint32 entry, uint32 worldState, BattlefieldBuildingType type);
    virtual ~BattlefieldBuilding() { }

    uint32 GetGameObjectEntry() const { return Info.GameObjectEntry; }
    bool IsIntact() const { return State == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED; }
    bool IsDestroyed() const { return State == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED; }
    bool IsDamaged() const { return State == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DAMAGED || State == BATTLEFIELD_BUILDING_STATE_HORDE_DAMAGED || State == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DAMAGED; }
    ObjectGuid const GetGameObjectGUID() const { return GameObjectGUID; }
    PvPTeamId GetPvPTeamId() const;

protected:
    BattlefieldBuildingType BuildingType;
    BattlefieldBuildingState State;
};

class BattlefieldCapturePoint : public BattlefieldEntity
{
public:
    explicit BattlefieldCapturePoint(Battlefield* battlefield, uint32 entry, uint32 worldState);
    virtual ~BattlefieldCapturePoint() { }

    virtual void Update(uint32 /*diff*/) { }

    uint32 GetGameObjectEntry() const { return Info.GameObjectEntry; }
    PvPTeamId GetPvPTeamId() const;

protected:
    BattlefieldCapturePointState State;
};

#endif
