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

#include "BattlefieldEntities.h"
#include "Errors.h"

BattlefieldEntity::BattlefieldEntity(Battlefield* battlefield, BattlefieldEntityInfo const info) : Battle(battlefield), Info(info)
{
    ASSERT(battlefield, "BattlefieldBuilding::BattlefieldEntity: Tried to construct an entity without a battlefield! (type: %u, entry: %u, worldState: %u)", info.EntityType, info.Entry, info.WorldState);
}

BattlefieldBuilding::BattlefieldBuilding(Battlefield* battlefield, BattlefieldBuildingInfo const info) : BattlefieldEntity(battlefield, info.Info), BuildingType(info.Type), State(BATTLEFIELD_BUILDING_STATE_NEUTRAL_INTACT)
{
}

PvPTeamId BattlefieldBuilding::GetPvPTeamId() const
{
    switch (State)
    {
        case BATTLEFIELD_BUILDING_STATE_HORDE_INTACT:
        case BATTLEFIELD_BUILDING_STATE_HORDE_DAMAGED:
        case BATTLEFIELD_BUILDING_STATE_HORDE_DESTROYED:
            return PVP_TEAM_HORDE;
        case BATTLEFIELD_BUILDING_STATE_ALLIANCE_INTACT:
        case BATTLEFIELD_BUILDING_STATE_ALLIANCE_DAMAGED:
        case BATTLEFIELD_BUILDING_STATE_ALLIANCE_DESTROYED:
            return PVP_TEAM_ALLIANCE;
        default:
            return PVP_TEAM_NEUTRAL;
    }
}

BattlefieldCapturePoint::BattlefieldCapturePoint(Battlefield* battlefield, BattlefieldEntityInfo const info) : BattlefieldEntity(battlefield, info), State(BATTLEFIELD_CAPTUREPOINT_STATE_NEUTRAL)
{
}

PvPTeamId BattlefieldCapturePoint::GetPvPTeamId() const
{
    switch (State)
    {
        case BATTLEFIELD_CAPTUREPOINT_STATE_HORDE:
        case BATTLEFIELD_CAPTUREPOINT_STATE_HORDE_ALLIANCE_CHALLENGE:
            return PVP_TEAM_HORDE;
        case BATTLEFIELD_CAPTUREPOINT_STATE_ALLIANCE:
        case BATTLEFIELD_CAPTUREPOINT_STATE_ALLIANCE_HORDE_CHALLENGE:
            return PVP_TEAM_ALLIANCE;
        default:
            return PVP_TEAM_NEUTRAL;
    }
}

BattlefieldGraveyard::BattlefieldGraveyard(Battlefield* battlefield, BattlefieldEntityInfo const info) : BattlefieldEntity(battlefield, info), State(BATTLEFIELD_GRAVEYARD_STATE_NEUTRAL)
{
}

PvPTeamId BattlefieldGraveyard::GetPvPTeamId() const
{
    switch (State)
    {
        case BATTLEFIELD_GRAVEYARD_STATE_HORDE:
            return PVP_TEAM_HORDE;
        case BATTLEFIELD_GRAVEYARD_STATE_ALLIANCE:
            return PVP_TEAM_ALLIANCE;
        default:
            return PVP_TEAM_NEUTRAL;
    }
}
