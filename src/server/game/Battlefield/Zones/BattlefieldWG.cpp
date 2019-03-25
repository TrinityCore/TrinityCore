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

#include "BattlefieldWG.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Player.h"
#include <vector>

static std::vector<BattlefieldBuildingInfo> const wintergraspBuildingInfo =
{
    { WORLDSTATE_WINTERGRASP_FORTRESS_GATE,            GO_WINTERGRASP_FORTRESS_GATE,            BATTLEFIELD_BUILDING_TYPE_DOOR },
    { WORLDSTATE_WINTERGRASP_FORTRESS_VAULT_GATE,      GO_WINTERGRASP_FORTRESS_VAULT_GATE,      BATTLEFIELD_BUILDING_TYPE_DOOR_LAST },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_1,          GO_WINTERGRASP_FORTRESS_WALL_1,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_2,          GO_WINTERGRASP_FORTRESS_WALL_2,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_3,          GO_WINTERGRASP_FORTRESS_WALL_3,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_4,          GO_WINTERGRASP_FORTRESS_WALL_4,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_5,          GO_WINTERGRASP_FORTRESS_WALL_5,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_6,          GO_WINTERGRASP_FORTRESS_WALL_6,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_7,          GO_WINTERGRASP_FORTRESS_WALL_7,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_8,          GO_WINTERGRASP_FORTRESS_WALL_8,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_9,          GO_WINTERGRASP_FORTRESS_WALL_9,          BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_10,         GO_WINTERGRASP_FORTRESS_WALL_10,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_11,         GO_WINTERGRASP_FORTRESS_WALL_11,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_12,         GO_WINTERGRASP_FORTRESS_WALL_12,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_13,         GO_WINTERGRASP_FORTRESS_WALL_13,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_14,         GO_WINTERGRASP_FORTRESS_WALL_14,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_15,         GO_WINTERGRASP_FORTRESS_WALL_15,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_16,         GO_WINTERGRASP_FORTRESS_WALL_16,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_17,         GO_WINTERGRASP_FORTRESS_WALL_17,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_18,         GO_WINTERGRASP_FORTRESS_WALL_18,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_19,         GO_WINTERGRASP_FORTRESS_WALL_19,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_WALL_20,         GO_WINTERGRASP_FORTRESS_WALL_20,         BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_INTERIOR_WALL_1, GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_1, BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_INTERIOR_WALL_2, GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_2, BATTLEFIELD_BUILDING_TYPE_WALL },
    { WORLDSTATE_WINTERGRASP_FORTRESS_INTERIOR_WALL_3, GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_3, BATTLEFIELD_BUILDING_TYPE_WALL }
};

BattlefieldWintergrasp::BattlefieldWintergrasp() : Battlefield(BATTLEFIELD_BATTLEID_WINTERGRASP, BATTLEFIELD_ZONEID_WINTERGRASP)
{
    for (auto itr = wintergraspBuildingInfo.begin(); itr != wintergraspBuildingInfo.end(); ++itr)
    {
        WintergraspBuildingPointer building = std::make_unique<WintergraspBuilding>(this, *itr);
        _buildings.emplace(itr->Info.GetSingleObjectEntry(), std::move(building));
    }
}

BattlefieldWintergrasp::~BattlefieldWintergrasp()
{
}

void BattlefieldWintergrasp::OnGameObjectCreate(GameObject* object)
{
    switch (object->GetEntry())
    {
        case GO_WINTERGRASP_FORTRESS_GATE:
        case GO_WINTERGRASP_FORTRESS_VAULT_GATE:
        case GO_WINTERGRASP_FORTRESS_WALL_1:
        case GO_WINTERGRASP_FORTRESS_WALL_2:
        case GO_WINTERGRASP_FORTRESS_WALL_3:
        case GO_WINTERGRASP_FORTRESS_WALL_4:
        case GO_WINTERGRASP_FORTRESS_WALL_5:
        case GO_WINTERGRASP_FORTRESS_WALL_6:
        case GO_WINTERGRASP_FORTRESS_WALL_7:
        case GO_WINTERGRASP_FORTRESS_WALL_8:
        case GO_WINTERGRASP_FORTRESS_WALL_9:
        case GO_WINTERGRASP_FORTRESS_WALL_10:
        case GO_WINTERGRASP_FORTRESS_WALL_11:
        case GO_WINTERGRASP_FORTRESS_WALL_12:
        case GO_WINTERGRASP_FORTRESS_WALL_13:
        case GO_WINTERGRASP_FORTRESS_WALL_14:
        case GO_WINTERGRASP_FORTRESS_WALL_15:
        case GO_WINTERGRASP_FORTRESS_WALL_16:
        case GO_WINTERGRASP_FORTRESS_WALL_17:
        case GO_WINTERGRASP_FORTRESS_WALL_18:
        case GO_WINTERGRASP_FORTRESS_WALL_19:
        case GO_WINTERGRASP_FORTRESS_WALL_20:
        case GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_1:
        case GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_2:
        case GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_3:
            if (WintergraspBuildingPointer& building = _buildings[object->GetEntry()])
                building->OnObjectCreate(object);
            break;
        default:
            break;
    }
}

void BattlefieldWintergrasp::OnGameObjectRemove(GameObject* object)
{
    switch (object->GetEntry())
    {
        case GO_WINTERGRASP_FORTRESS_GATE:
        case GO_WINTERGRASP_FORTRESS_VAULT_GATE:
        case GO_WINTERGRASP_FORTRESS_WALL_1:
        case GO_WINTERGRASP_FORTRESS_WALL_2:
        case GO_WINTERGRASP_FORTRESS_WALL_3:
        case GO_WINTERGRASP_FORTRESS_WALL_4:
        case GO_WINTERGRASP_FORTRESS_WALL_5:
        case GO_WINTERGRASP_FORTRESS_WALL_6:
        case GO_WINTERGRASP_FORTRESS_WALL_7:
        case GO_WINTERGRASP_FORTRESS_WALL_8:
        case GO_WINTERGRASP_FORTRESS_WALL_9:
        case GO_WINTERGRASP_FORTRESS_WALL_10:
        case GO_WINTERGRASP_FORTRESS_WALL_11:
        case GO_WINTERGRASP_FORTRESS_WALL_12:
        case GO_WINTERGRASP_FORTRESS_WALL_13:
        case GO_WINTERGRASP_FORTRESS_WALL_14:
        case GO_WINTERGRASP_FORTRESS_WALL_15:
        case GO_WINTERGRASP_FORTRESS_WALL_16:
        case GO_WINTERGRASP_FORTRESS_WALL_17:
        case GO_WINTERGRASP_FORTRESS_WALL_18:
        case GO_WINTERGRASP_FORTRESS_WALL_19:
        case GO_WINTERGRASP_FORTRESS_WALL_20:
        case GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_1:
        case GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_2:
        case GO_WINTERGRASP_FORTRESS_INTERIOR_WALL_3:
            if (WintergraspBuildingPointer& building = _buildings[object->GetEntry()])
                building->OnObjectRemove(object);
            break;
        default:
            break;
    }
}

void BattlefieldWintergrasp::SendGlobalWorldStates(Player const* player) const
{
    if (!IsEnabled())
        return;

    player->SendUpdateWorldState(WORLDSTATE_WINTERGRASP_SHOW_NOWAR_TIMER, IsWarTime() ? 0 : 1);

    uint32 timer = 0;
    if (IsWarTime())
        timer = GetTimer() / 1000;

    player->SendUpdateWorldState(WORLDSTATE_WINTERGRASP_TIME_TO_NEXT_BATTLE, GameTime::GetGameTime() + timer);
}

bool BattlefieldWintergrasp::IsSpellAreaAllowed(uint32 spellId, Player const* player, uint32 /*newArea*/) const
{
    if (!player)
        return false;

    switch (spellId)
    {
        case SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA:
            if (IsFlyingMountAllowed())
                return false;
            if (!player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) && !player->HasAuraType(SPELL_AURA_FLY))
                return false;
            break;
        case SPELL_WINTERGRASP_ESSENCE_OF_WINTERGRASP:
            return IsEnabled() && (player->GetTeamId() == GetControllingTeamId()) && !IsWarTime();
        case SPELL_WINTERGRASP_ESSENCE_OF_WINTERGRASP_NORTHREND:
            return false;
        case SPELL_WINTERGRASP_BATTLEGROUND_DAMPENING:
            return IsEnabled() && IsWarTime();
        default:
            break;
    }

    return true;
}

WintergraspBuilding::WintergraspBuilding(Battlefield* battlefield, BattlefieldBuildingInfo const info) : BattlefieldBuilding(battlefield, info)
{
}

void WintergraspBuilding::OnObjectCreate(WorldObject* object)
{
    if (object->GetTypeId() != TYPEID_GAMEOBJECT)
        return;

    BattlefieldBuilding::OnObjectCreate(object);
}

void WintergraspBuilding::OnObjectRemove(WorldObject* object)
{
    if (object->GetTypeId() != TYPEID_GAMEOBJECT)
        return;

    BattlefieldBuilding::OnObjectRemove(object);
}

WintergraspCapturePoint::WintergraspCapturePoint(Battlefield* battlefield, BattlefieldEntityInfo const info) : BattlefieldCapturePoint(battlefield, info)
{
}

void WintergraspCapturePoint::OnObjectCreate(WorldObject* object)
{
    if (object->GetTypeId() != TYPEID_GAMEOBJECT)
        return;

    BattlefieldCapturePoint::OnObjectCreate(object);
}

void WintergraspCapturePoint::OnObjectRemove(WorldObject* object)
{
    if (object->GetTypeId() != TYPEID_GAMEOBJECT)
        return;

    BattlefieldCapturePoint::OnObjectRemove(object);
}

WintergraspGraveyard::WintergraspGraveyard(Battlefield* battlefield, BattlefieldGraveyardInfo const info) : BattlefieldGraveyard(battlefield, info)
{
}

void WintergraspGraveyard::OnObjectCreate(WorldObject* object)
{
    if (object->GetTypeId() != TYPEID_UNIT)
        return;

    BattlefieldGraveyard::OnObjectCreate(object);
}

void WintergraspGraveyard::OnObjectRemove(WorldObject* object)
{
    if (object->GetTypeId() != TYPEID_UNIT)
        return;

    BattlefieldGraveyard::OnObjectRemove(object);
}
