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
class WorldObject;

enum BattlefieldEntityType : uint8
{
    BATTLEFIELD_ENTITY_TYPE_BUILDING = 0,
    BATTLEFIELD_ENTITY_TYPE_CAPTUREPOINT,
    BATTLEFIELD_ENTITY_TYPE_GRAVEYARD
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

enum BattlefieldGraveyardState : uint8
{
    BATTLEFIELD_GRAVEYARD_STATE_NEUTRAL = 0,
    BATTLEFIELD_GRAVEYARD_STATE_ALLIANCE,
    BATTLEFIELD_GRAVEYARD_STATE_HORDE,
};

struct BattlefieldEntityInfo
{
    BattlefieldEntityInfo(BattlefieldEntityType type, uint32 entry, uint32 worldState) : EntityType(type), Entry(entry), WorldState(worldState) { }

    BattlefieldEntityType EntityType;
    uint32 Entry;
    uint32 WorldState;
};

class BattlefieldEntity
{
public:
    explicit BattlefieldEntity(Battlefield* battlefield, BattlefieldEntityType type, uint32 entry, uint32 worldState) : BattlefieldEntity(battlefield, BattlefieldEntityInfo(type, entry, worldState)) { }
    explicit BattlefieldEntity(Battlefield* battlefield, BattlefieldEntityInfo const info);
    virtual ~BattlefieldEntity() { }

    virtual void Initialize(WorldObject* object);
    virtual void Update(uint32 /*diff*/) { }
    virtual PvPTeamId GetPvPTeamId() const { return PVP_TEAM_NEUTRAL; }

    uint32 GetObjectEntry() const { return Info.Entry; }
    ObjectGuid const GetObjectGUID() const { return ObjectGUID; }

    Battlefield* Battle;
    BattlefieldEntityInfo const Info;
    ObjectGuid ObjectGUID;
};

struct BattlefieldBuildingInfo
{
    BattlefieldBuildingInfo(uint32 entry, uint32 worldState, BattlefieldBuildingType type) : BattlefieldBuildingInfo(BattlefieldEntityInfo(BATTLEFIELD_ENTITY_TYPE_BUILDING, entry, worldState), type) { }
    BattlefieldBuildingInfo(BattlefieldEntityInfo const info, BattlefieldBuildingType type) : Info(info), Type(type) { }

    BattlefieldEntityInfo Info;
    BattlefieldBuildingType Type;
};

class BattlefieldBuilding : public BattlefieldEntity
{
public:
    explicit BattlefieldBuilding(Battlefield* battlefield, uint32 entry, uint32 worldState, BattlefieldBuildingType type) : BattlefieldBuilding(battlefield, BattlefieldBuildingInfo(BattlefieldEntityInfo(BATTLEFIELD_ENTITY_TYPE_BUILDING, entry, worldState), type)) { }
    explicit BattlefieldBuilding(Battlefield* battlefield, BattlefieldBuildingInfo const info);
    virtual ~BattlefieldBuilding() { }

    PvPTeamId GetPvPTeamId() const override;

    bool IsIntact() const { return State == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED; }
    bool IsDestroyed() const { return State == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED || State == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED; }
    bool IsDamaged() const { return State == BATTLEFIELD_BUILDING_STATE_NEUTRAL_DAMAGED || State == BATTLEFIELD_BUILDING_STATE_HORDE_DAMAGED || State == BATTLEFIELD_BUILDING_STATE_ALLIANCE_DAMAGED; }

protected:
    BattlefieldBuildingType BuildingType;
    BattlefieldBuildingState State;
};

class BattlefieldCapturePoint : public BattlefieldEntity
{
public:
    explicit BattlefieldCapturePoint(Battlefield* battlefield, uint32 entry, uint32 worldState) : BattlefieldCapturePoint(battlefield, BattlefieldEntityInfo(BATTLEFIELD_ENTITY_TYPE_CAPTUREPOINT, entry, worldState)) { }
    explicit BattlefieldCapturePoint(Battlefield* battlefield, BattlefieldEntityInfo const info);
    virtual ~BattlefieldCapturePoint() { }

    PvPTeamId GetPvPTeamId() const override;

protected:
    BattlefieldCapturePointState State;
};

class BattlefieldGraveyard : public BattlefieldEntity
{
public:
    explicit BattlefieldGraveyard(Battlefield* battlefield, uint32 entry, uint32 worldState) : BattlefieldGraveyard(battlefield, BattlefieldEntityInfo(BATTLEFIELD_ENTITY_TYPE_GRAVEYARD, entry, worldState)) { }
    explicit BattlefieldGraveyard(Battlefield* battlefield, BattlefieldEntityInfo const info);
    virtual ~BattlefieldGraveyard() { }

    PvPTeamId GetPvPTeamId() const override;

protected:
    BattlefieldGraveyardState State;
};

#endif
