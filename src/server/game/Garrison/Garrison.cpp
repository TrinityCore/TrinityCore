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

#include "Garrison.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GarrisonMgr.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "VehicleDefines.h"

Garrison::Garrison(Player* owner) : _owner(owner), _siteLevel(nullptr), _followerActivationsRemainingToday(1)
{
}

bool Garrison::LoadFromDB(PreparedQueryResult garrison, PreparedQueryResult blueprints, PreparedQueryResult buildings,
    PreparedQueryResult followers, PreparedQueryResult abilities)
{
    if (!garrison)
        return false;

    Field* fields = garrison->Fetch();
    _siteLevel = sGarrSiteLevelStore.LookupEntry(fields[0].GetUInt32());
    _followerActivationsRemainingToday = fields[1].GetUInt32();
    if (!_siteLevel)
        return false;

    InitializePlots();

    if (blueprints)
    {
        do
        {
            fields = blueprints->Fetch();
            if (GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(fields[0].GetUInt32()))
                _knownBuildings.insert(building->ID);

        } while (blueprints->NextRow());
    }

    if (buildings)
    {
        do
        {
            fields = buildings->Fetch();
            uint32 plotInstanceId = fields[0].GetUInt32();
            uint32 buildingId = fields[1].GetUInt32();
            time_t timeBuilt = time_t(fields[2].GetUInt64());
            bool active = fields[3].GetBool();


            Plot* plot = GetPlot(plotInstanceId);
            if (!plot)
                continue;

            if (!sGarrBuildingStore.LookupEntry(buildingId))
                continue;

            plot->BuildingInfo.PacketInfo = boost::in_place();
            plot->BuildingInfo.PacketInfo->GarrPlotInstanceID = plotInstanceId;
            plot->BuildingInfo.PacketInfo->GarrBuildingID = buildingId;
            plot->BuildingInfo.PacketInfo->TimeBuilt = timeBuilt;
            plot->BuildingInfo.PacketInfo->Active = active;

        } while (buildings->NextRow());
    }

    //           0           1        2      3                4               5   6                7               8       9
    // SELECT dbId, followerId, quality, level, itemLevelWeapon, itemLevelArmor, xp, currentBuilding, currentMission, status FROM character_garrison_followers WHERE guid = ?
    if (followers)
    {
        do
        {
            fields = followers->Fetch();

            uint64 dbId = fields[0].GetUInt64();
            uint32 followerId = fields[1].GetUInt32();
            if (!sGarrFollowerStore.LookupEntry(followerId))
                continue;

            _followerIds.insert(followerId);
            Follower& follower = _followers[dbId];
            follower.PacketInfo.DbID = dbId;
            follower.PacketInfo.GarrFollowerID = followerId;
            follower.PacketInfo.Quality = fields[2].GetUInt32();
            follower.PacketInfo.FollowerLevel = fields[3].GetUInt32();
            follower.PacketInfo.ItemLevelWeapon = fields[4].GetUInt32();
            follower.PacketInfo.ItemLevelArmor = fields[5].GetUInt32();
            follower.PacketInfo.Xp = fields[6].GetUInt32();
            follower.PacketInfo.CurrentBuildingID = fields[7].GetUInt32();
            follower.PacketInfo.CurrentMissionID = fields[8].GetUInt32();
            follower.PacketInfo.FollowerStatus = fields[9].GetUInt32();
            if (!sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID))
                follower.PacketInfo.CurrentBuildingID = 0;

            //if (!sGarrMissionStore.LookupEntry(follower.PacketInfo.CurrentMissionID))
            //    follower.PacketInfo.CurrentMissionID = 0;

        } while (followers->NextRow());

        if (abilities)
        {
            do
            {
                fields = abilities->Fetch();
                uint64 dbId = fields[0].GetUInt64();
                GarrAbilityEntry const* ability = sGarrAbilityStore.LookupEntry(fields[1].GetUInt32());

                if (!ability)
                    continue;

                auto itr = _followers.find(dbId);
                if (itr == _followers.end())
                    continue;

                itr->second.PacketInfo.AbilityID.push_back(ability);
            } while (abilities->NextRow());
        }
    }

    return true;
}

void Garrison::SaveToDB(CharacterDatabaseTransaction trans)
{
    DeleteFromDB(_owner->GetGUID().GetCounter(), trans);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON);
    stmt->setUInt64(0, _owner->GetGUID().GetCounter());
    stmt->setUInt32(1, _siteLevel->ID);
    stmt->setUInt32(2, _followerActivationsRemainingToday);
    trans->Append(stmt);

    for (uint32 building : _knownBuildings)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_BLUEPRINTS);
        stmt->setUInt64(0, _owner->GetGUID().GetCounter());
        stmt->setUInt32(1, building);
        trans->Append(stmt);
    }

    for (auto const& p : _plots)
    {
        Plot const& plot = p.second;
        if (plot.BuildingInfo.PacketInfo)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_BUILDINGS);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, plot.BuildingInfo.PacketInfo->GarrPlotInstanceID);
            stmt->setUInt32(2, plot.BuildingInfo.PacketInfo->GarrBuildingID);
            stmt->setUInt64(3, plot.BuildingInfo.PacketInfo->TimeBuilt);
            stmt->setBool(4, plot.BuildingInfo.PacketInfo->Active);
            trans->Append(stmt);
        }
    }

    for (auto const& p : _followers)
    {
        Follower const& follower = p.second;
        uint8 index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_FOLLOWERS);
        stmt->setUInt64(index++, follower.PacketInfo.DbID);
        stmt->setUInt64(index++, _owner->GetGUID().GetCounter());
        stmt->setUInt32(index++, follower.PacketInfo.GarrFollowerID);
        stmt->setUInt32(index++, follower.PacketInfo.Quality);
        stmt->setUInt32(index++, follower.PacketInfo.FollowerLevel);
        stmt->setUInt32(index++, follower.PacketInfo.ItemLevelWeapon);
        stmt->setUInt32(index++, follower.PacketInfo.ItemLevelArmor);
        stmt->setUInt32(index++, follower.PacketInfo.Xp);
        stmt->setUInt32(index++, follower.PacketInfo.CurrentBuildingID);
        stmt->setUInt32(index++, follower.PacketInfo.CurrentMissionID);
        stmt->setUInt32(index++, follower.PacketInfo.FollowerStatus);
        trans->Append(stmt);

        uint8 slot = 0;
        for (GarrAbilityEntry const* ability : follower.PacketInfo.AbilityID)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_FOLLOWER_ABILITIES);
            stmt->setUInt64(0, follower.PacketInfo.DbID);
            stmt->setUInt32(1, ability->ID);
            stmt->setUInt8(2, slot++);
            trans->Append(stmt);
        }
    }
}

void Garrison::DeleteFromDB(ObjectGuid::LowType ownerGuid, CharacterDatabaseTransaction trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON);
    stmt->setUInt64(0, ownerGuid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_BLUEPRINTS);
    stmt->setUInt64(0, ownerGuid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_BUILDINGS);
    stmt->setUInt64(0, ownerGuid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_FOLLOWERS);
    stmt->setUInt64(0, ownerGuid);
    trans->Append(stmt);
}

bool Garrison::Create(uint32 garrSiteId)
{
    GarrSiteLevelEntry const* siteLevel = sGarrisonMgr.GetGarrSiteLevelEntry(garrSiteId, 1);
    if (!siteLevel)
        return false;

    _siteLevel = siteLevel;

    InitializePlots();

    WorldPackets::Garrison::GarrisonCreateResult garrisonCreateResult;
    garrisonCreateResult.GarrSiteLevelID = _siteLevel->ID;
    _owner->SendDirectMessage(garrisonCreateResult.Write());
    PhasingHandler::OnConditionChange(_owner);
    SendRemoteInfo();
    return true;
}

void Garrison::Delete()
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    DeleteFromDB(_owner->GetGUID().GetCounter(), trans);
    CharacterDatabase.CommitTransaction(trans);

    WorldPackets::Garrison::GarrisonDeleteResult garrisonDelete;
    garrisonDelete.Result = GARRISON_SUCCESS;
    garrisonDelete.GarrSiteID = _siteLevel->GarrSiteID;
    _owner->SendDirectMessage(garrisonDelete.Write());
}

void Garrison::InitializePlots()
{
    if (std::vector<GarrSiteLevelPlotInstEntry const*> const* plots = sGarrisonMgr.GetGarrPlotInstForSiteLevel(_siteLevel->ID))
    {
        for (std::size_t i = 0; i < plots->size(); ++i)
        {
            uint32 garrPlotInstanceId = plots->at(i)->GarrPlotInstanceID;
            GarrPlotInstanceEntry const* plotInstance = sGarrPlotInstanceStore.LookupEntry(garrPlotInstanceId);
            GameObjectsEntry const* gameObject = sGarrisonMgr.GetPlotGameObject(_siteLevel->MapID, garrPlotInstanceId);
            if (!plotInstance || !gameObject)
                continue;

            GarrPlotEntry const* plot = sGarrPlotStore.LookupEntry(plotInstance->GarrPlotID);
            if (!plot)
                continue;

            Plot& plotInfo = _plots[garrPlotInstanceId];
            plotInfo.PacketInfo.GarrPlotInstanceID = garrPlotInstanceId;
            plotInfo.PacketInfo.PlotPos = Position(gameObject->Pos.X, gameObject->Pos.Y, gameObject->Pos.Z, 2 * std::acos(gameObject->Rot[3]));
            plotInfo.PacketInfo.PlotType = plot->PlotType;
            plotInfo.Rotation = QuaternionData(gameObject->Rot[0], gameObject->Rot[1], gameObject->Rot[2], gameObject->Rot[3]);
            plotInfo.EmptyGameObjectId = gameObject->ID;
            plotInfo.GarrSiteLevelPlotInstId = plots->at(i)->ID;
        }
    }
}

void Garrison::Upgrade()
{
}

void Garrison::Enter() const
{
    if (MapEntry const* map = sMapStore.LookupEntry(_siteLevel->MapID))
    {
        if (int32(_owner->GetMapId()) == map->ParentMapID)
        {
            WorldLocation loc(_siteLevel->MapID);
            loc.Relocate(_owner);
            _owner->TeleportTo(loc, TELE_TO_SEAMLESS);
        }
    }
}

void Garrison::Leave() const
{
    if (MapEntry const* map = sMapStore.LookupEntry(_siteLevel->MapID))
    {
        if (_owner->GetMapId() == _siteLevel->MapID)
        {
            WorldLocation loc(map->ParentMapID);
            loc.Relocate(_owner);
            _owner->TeleportTo(loc, TELE_TO_SEAMLESS);
        }
    }
}

GarrisonFactionIndex Garrison::GetFaction() const
{
    return _owner->GetTeam() == HORDE ? GARRISON_FACTION_INDEX_HORDE : GARRISON_FACTION_INDEX_ALLIANCE;
}

std::vector<Garrison::Plot*> Garrison::GetPlots()
{
    std::vector<Plot*> plots;
    plots.reserve(_plots.size());
    for (auto& p : _plots)
        plots.push_back(&p.second);

    return plots;
}

Garrison::Plot* Garrison::GetPlot(uint32 garrPlotInstanceId)
{
    auto itr = _plots.find(garrPlotInstanceId);
    if (itr != _plots.end())
        return &itr->second;

    return nullptr;
}

Garrison::Plot const* Garrison::GetPlot(uint32 garrPlotInstanceId) const
{
    auto itr = _plots.find(garrPlotInstanceId);
    if (itr != _plots.end())
        return &itr->second;

    return nullptr;
}

void Garrison::LearnBlueprint(uint32 garrBuildingId)
{
    WorldPackets::Garrison::GarrisonLearnBlueprintResult learnBlueprintResult;
    learnBlueprintResult.GarrTypeID = GetType();
    learnBlueprintResult.BuildingID = garrBuildingId;
    learnBlueprintResult.Result = GARRISON_SUCCESS;

    if (!sGarrBuildingStore.LookupEntry(garrBuildingId))
        learnBlueprintResult.Result = GARRISON_ERROR_INVALID_BUILDINGID;
    else if (HasBlueprint(garrBuildingId))
        learnBlueprintResult.Result = GARRISON_ERROR_BLUEPRINT_EXISTS;
    else
        _knownBuildings.insert(garrBuildingId);

    _owner->SendDirectMessage(learnBlueprintResult.Write());
}

void Garrison::UnlearnBlueprint(uint32 garrBuildingId)
{
    WorldPackets::Garrison::GarrisonUnlearnBlueprintResult unlearnBlueprintResult;
    unlearnBlueprintResult.GarrTypeID = GetType();
    unlearnBlueprintResult.BuildingID = garrBuildingId;
    unlearnBlueprintResult.Result = GARRISON_SUCCESS;

    if (!sGarrBuildingStore.LookupEntry(garrBuildingId))
        unlearnBlueprintResult.Result = GARRISON_ERROR_INVALID_BUILDINGID;
    else if (!HasBlueprint(garrBuildingId))
        unlearnBlueprintResult.Result = GARRISON_ERROR_REQUIRES_BLUEPRINT;
    else
        _knownBuildings.erase(garrBuildingId);

    _owner->SendDirectMessage(unlearnBlueprintResult.Write());
}

void Garrison::PlaceBuilding(uint32 garrPlotInstanceId, uint32 garrBuildingId)
{
    WorldPackets::Garrison::GarrisonPlaceBuildingResult placeBuildingResult;
    placeBuildingResult.GarrTypeID = GetType();
    placeBuildingResult.Result = CheckBuildingPlacement(garrPlotInstanceId, garrBuildingId);
    if (placeBuildingResult.Result == GARRISON_SUCCESS)
    {
        placeBuildingResult.BuildingInfo.GarrPlotInstanceID = garrPlotInstanceId;
        placeBuildingResult.BuildingInfo.GarrBuildingID = garrBuildingId;
        placeBuildingResult.BuildingInfo.TimeBuilt = time(nullptr);

        Plot* plot = GetPlot(garrPlotInstanceId);
        uint32 oldBuildingId = 0;
        Map* map = FindMap();
        GarrBuildingEntry const* building = sGarrBuildingStore.AssertEntry(garrBuildingId);
        if (map)
            plot->DeleteGameObject(map);

        if (plot->BuildingInfo.PacketInfo)
        {
            oldBuildingId = plot->BuildingInfo.PacketInfo->GarrBuildingID;
            if (sGarrBuildingStore.AssertEntry(oldBuildingId)->BuildingType != building->BuildingType)
                plot->ClearBuildingInfo(GetType(), _owner);
        }

        plot->SetBuildingInfo(placeBuildingResult.BuildingInfo, _owner);
        if (map)
            if (GameObject* go = plot->CreateGameObject(map, GetFaction()))
                map->AddToMap(go);

        _owner->ModifyCurrency(building->CurrencyTypeID, -building->CurrencyQty, false, true);
        _owner->ModifyMoney(-building->GoldCost * GOLD, false);

        if (oldBuildingId)
        {
            WorldPackets::Garrison::GarrisonBuildingRemoved buildingRemoved;
            buildingRemoved.GarrTypeID = GetType();
            buildingRemoved.Result = GARRISON_SUCCESS;
            buildingRemoved.GarrPlotInstanceID = garrPlotInstanceId;
            buildingRemoved.GarrBuildingID = oldBuildingId;
            _owner->SendDirectMessage(buildingRemoved.Write());
        }

        _owner->UpdateCriteria(CRITERIA_TYPE_PLACE_GARRISON_BUILDING, garrBuildingId);
    }

    _owner->SendDirectMessage(placeBuildingResult.Write());
}

void Garrison::CancelBuildingConstruction(uint32 garrPlotInstanceId)
{
    WorldPackets::Garrison::GarrisonBuildingRemoved buildingRemoved;
    buildingRemoved.GarrTypeID = GetType();
    buildingRemoved.Result = CheckBuildingRemoval(garrPlotInstanceId);
    if (buildingRemoved.Result == GARRISON_SUCCESS)
    {
        Plot* plot = GetPlot(garrPlotInstanceId);

        buildingRemoved.GarrPlotInstanceID = garrPlotInstanceId;
        buildingRemoved.GarrBuildingID = plot->BuildingInfo.PacketInfo->GarrBuildingID;

        Map* map = FindMap();
        if (map)
            plot->DeleteGameObject(map);

        plot->ClearBuildingInfo(GetType(), _owner);
        _owner->SendDirectMessage(buildingRemoved.Write());

        GarrBuildingEntry const* constructing = sGarrBuildingStore.AssertEntry(buildingRemoved.GarrBuildingID);
        // Refund construction/upgrade cost
        _owner->ModifyCurrency(constructing->CurrencyTypeID, constructing->CurrencyQty, false, true);
        _owner->ModifyMoney(constructing->GoldCost * GOLD, false);

        if (constructing->UpgradeLevel > 1)
        {
            // Restore previous level building
            uint32 restored = sGarrisonMgr.GetPreviousLevelBuildingId(constructing->BuildingType, constructing->UpgradeLevel);
            ASSERT(restored);

            WorldPackets::Garrison::GarrisonPlaceBuildingResult placeBuildingResult;
            placeBuildingResult.GarrTypeID = GetType();
            placeBuildingResult.Result = GARRISON_SUCCESS;
            placeBuildingResult.BuildingInfo.GarrPlotInstanceID = garrPlotInstanceId;
            placeBuildingResult.BuildingInfo.GarrBuildingID = restored;
            placeBuildingResult.BuildingInfo.TimeBuilt = time(nullptr);
            placeBuildingResult.BuildingInfo.Active = true;

            plot->SetBuildingInfo(placeBuildingResult.BuildingInfo, _owner);
            _owner->SendDirectMessage(placeBuildingResult.Write());
        }

        if (map)
            if (GameObject* go = plot->CreateGameObject(map, GetFaction()))
                map->AddToMap(go);
    }
    else
        _owner->SendDirectMessage(buildingRemoved.Write());
}

void Garrison::ActivateBuilding(uint32 garrPlotInstanceId)
{
    if (Plot* plot = GetPlot(garrPlotInstanceId))
    {
        if (plot->BuildingInfo.CanActivate() && plot->BuildingInfo.PacketInfo && !plot->BuildingInfo.PacketInfo->Active)
        {
            plot->BuildingInfo.PacketInfo->Active = true;
            if (Map* map = FindMap())
            {
                plot->DeleteGameObject(map);
                if (GameObject* go = plot->CreateGameObject(map, GetFaction()))
                    map->AddToMap(go);
            }

            WorldPackets::Garrison::GarrisonBuildingActivated buildingActivated;
            buildingActivated.GarrPlotInstanceID = garrPlotInstanceId;
            _owner->SendDirectMessage(buildingActivated.Write());
        }
    }
}

void Garrison::AddFollower(uint32 garrFollowerId)
{
    WorldPackets::Garrison::GarrisonAddFollowerResult addFollowerResult;
    addFollowerResult.GarrTypeID = GetType();
    GarrFollowerEntry const* followerEntry = sGarrFollowerStore.LookupEntry(garrFollowerId);
    if (_followerIds.count(garrFollowerId) || !followerEntry)
    {
        addFollowerResult.Result = GARRISON_ERROR_FOLLOWER_EXISTS;
        _owner->SendDirectMessage(addFollowerResult.Write());
        return;
    }

    _followerIds.insert(garrFollowerId);
    uint64 dbId = sGarrisonMgr.GenerateFollowerDbId();
    Follower& follower = _followers[dbId];
    follower.PacketInfo.DbID = dbId;
    follower.PacketInfo.GarrFollowerID = garrFollowerId;
    follower.PacketInfo.Quality = followerEntry->Quality;   // TODO: handle magic upgrades
    follower.PacketInfo.FollowerLevel = followerEntry->FollowerLevel;
    follower.PacketInfo.ItemLevelWeapon = followerEntry->ItemLevelWeapon;
    follower.PacketInfo.ItemLevelArmor = followerEntry->ItemLevelArmor;
    follower.PacketInfo.Xp = 0;
    follower.PacketInfo.CurrentBuildingID = 0;
    follower.PacketInfo.CurrentMissionID = 0;
    follower.PacketInfo.AbilityID = sGarrisonMgr.RollFollowerAbilities(garrFollowerId, followerEntry, follower.PacketInfo.Quality, GetFaction(), true);
    follower.PacketInfo.FollowerStatus = 0;

    addFollowerResult.Follower = follower.PacketInfo;
    _owner->SendDirectMessage(addFollowerResult.Write());

    _owner->UpdateCriteria(CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER, follower.PacketInfo.DbID);
}

Garrison::Follower const* Garrison::GetFollower(uint64 dbId) const
{
    auto itr = _followers.find(dbId);
    if (itr != _followers.end())
        return &itr->second;

    return nullptr;
}

void Garrison::SendInfo()
{
    WorldPackets::Garrison::GetGarrisonInfoResult garrisonInfo;
    garrisonInfo.FactionIndex = GetFaction();
    garrisonInfo.Garrisons.emplace_back();

    WorldPackets::Garrison::GarrisonInfo& garrison = garrisonInfo.Garrisons.back();
    garrison.GarrTypeID = GetType();
    garrison.GarrSiteID = _siteLevel->GarrSiteID;
    garrison.GarrSiteLevelID = _siteLevel->ID;
    garrison.NumFollowerActivationsRemaining = _followerActivationsRemainingToday;
    for (auto& p : _plots)
    {
        Plot& plot = p.second;
        garrison.Plots.push_back(&plot.PacketInfo);
        if (plot.BuildingInfo.PacketInfo)
            garrison.Buildings.push_back(plot.BuildingInfo.PacketInfo.get_ptr());
    }

    for (auto const& p : _followers)
        garrison.Followers.push_back(&p.second.PacketInfo);

    _owner->SendDirectMessage(garrisonInfo.Write());
}

void Garrison::SendRemoteInfo() const
{
    MapEntry const* garrisonMap = sMapStore.LookupEntry(_siteLevel->MapID);
    if (!garrisonMap || int32(_owner->GetMapId()) != garrisonMap->ParentMapID)
        return;

    WorldPackets::Garrison::GarrisonRemoteInfo remoteInfo;
    remoteInfo.Sites.resize(1);

    WorldPackets::Garrison::GarrisonRemoteSiteInfo& remoteSiteInfo = remoteInfo.Sites[0];
    remoteSiteInfo.GarrSiteLevelID = _siteLevel->ID;
    for (auto const& p : _plots)
        if (p.second.BuildingInfo.PacketInfo)
            remoteSiteInfo.Buildings.emplace_back(p.first, p.second.BuildingInfo.PacketInfo->GarrBuildingID);

    _owner->SendDirectMessage(remoteInfo.Write());
}

void Garrison::SendBlueprintAndSpecializationData()
{
    WorldPackets::Garrison::GarrisonRequestBlueprintAndSpecializationDataResult data;
    data.GarrTypeID = GetType();
    data.BlueprintsKnown = &_knownBuildings;
    _owner->SendDirectMessage(data.Write());
}

void Garrison::SendMapData(Player* receiver) const
{
    WorldPackets::Garrison::GarrisonMapDataResponse mapData;
    mapData.Buildings.reserve(_plots.size());

    for (auto const& p : _plots)
    {
        Plot const& plot = p.second;
        if (plot.BuildingInfo.PacketInfo)
            if (uint32 garrBuildingPlotInstId = sGarrisonMgr.GetGarrBuildingPlotInst(plot.BuildingInfo.PacketInfo->GarrBuildingID, plot.GarrSiteLevelPlotInstId))
                mapData.Buildings.emplace_back(garrBuildingPlotInstId, plot.PacketInfo.PlotPos.Pos);
    }

    receiver->SendDirectMessage(mapData.Write());
}

Map* Garrison::FindMap() const
{
    return sMapMgr->FindMap(_siteLevel->MapID, _owner->GetGUID().GetCounter());
}

GarrisonError Garrison::CheckBuildingPlacement(uint32 garrPlotInstanceId, uint32 garrBuildingId) const
{
    GarrPlotInstanceEntry const* plotInstance = sGarrPlotInstanceStore.LookupEntry(garrPlotInstanceId);
    Plot const* plot = GetPlot(garrPlotInstanceId);
    if (!plotInstance || !plot)
        return GARRISON_ERROR_INVALID_PLOT_INSTANCEID;

    GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(garrBuildingId);
    if (!building)
        return GARRISON_ERROR_INVALID_BUILDINGID;

    if (!sGarrisonMgr.IsPlotMatchingBuilding(plotInstance->GarrPlotID, garrBuildingId))
        return GARRISON_ERROR_INVALID_PLOT_BUILDING;

    // Cannot place buldings of higher level than garrison level
    if (building->UpgradeLevel > _siteLevel->MaxBuildingLevel)
        return GARRISON_ERROR_INVALID_BUILDINGID;

    if (building->Flags & GARRISON_BUILDING_FLAG_NEEDS_PLAN)
    {
        if (!HasBlueprint(garrBuildingId))
            return GARRISON_ERROR_REQUIRES_BLUEPRINT;
    }
    else // Building is built as a quest reward
        return GARRISON_ERROR_INVALID_BUILDINGID;

    // Check all plots to find if we already have this building
    GarrBuildingEntry const* existingBuilding;
    for (auto const& p : _plots)
    {
        if (p.second.BuildingInfo.PacketInfo)
        {
            existingBuilding = sGarrBuildingStore.AssertEntry(p.second.BuildingInfo.PacketInfo->GarrBuildingID);
            if (existingBuilding->BuildingType == building->BuildingType)
                if (p.first != garrPlotInstanceId || existingBuilding->UpgradeLevel + 1 != building->UpgradeLevel)    // check if its an upgrade in same plot
                    return GARRISON_ERROR_BUILDING_EXISTS;
        }
    }

    if (!_owner->HasCurrency(building->CurrencyTypeID, building->CurrencyQty))
        return GARRISON_ERROR_NOT_ENOUGH_CURRENCY;

    if (!_owner->HasEnoughMoney(uint64(building->GoldCost) * GOLD))
        return GARRISON_ERROR_NOT_ENOUGH_GOLD;

    // New building cannot replace another building currently under construction
    if (plot->BuildingInfo.PacketInfo)
        if (!plot->BuildingInfo.PacketInfo->Active)
            return GARRISON_ERROR_NO_BUILDING;

    return GARRISON_SUCCESS;
}

GarrisonError Garrison::CheckBuildingRemoval(uint32 garrPlotInstanceId) const
{
    Plot const* plot = GetPlot(garrPlotInstanceId);
    if (!plot)
        return GARRISON_ERROR_INVALID_PLOT_INSTANCEID;

    if (!plot->BuildingInfo.PacketInfo)
        return GARRISON_ERROR_NO_BUILDING;

    if (plot->BuildingInfo.CanActivate())
        return GARRISON_ERROR_BUILDING_EXISTS;

    return GARRISON_SUCCESS;
}

template<class T, void(T::*SecondaryRelocate)(float,float,float,float)>
T* BuildingSpawnHelper(GameObject* building, ObjectGuid::LowType spawnId, Map* map)
{
    T* spawn = new T();
    if (!spawn->LoadFromDB(spawnId, map, false, false))
    {
        delete spawn;
        return nullptr;
    }

    float x = spawn->GetPositionX();
    float y = spawn->GetPositionY();
    float z = spawn->GetPositionZ();
    float o = spawn->GetOrientation();
    TransportBase::CalculatePassengerPosition(x, y, z, &o, building->GetPositionX(), building->GetPositionY(), building->GetPositionZ(), building->GetOrientation());

    spawn->Relocate(x, y, z, o);
    (spawn->*SecondaryRelocate)(x, y, z, o);

    if (!spawn->IsPositionValid())
    {
        delete spawn;
        return nullptr;
    }

    if (!map->AddToMap(spawn))
    {
        delete spawn;
        return nullptr;
    }

    return spawn;
}

GameObject* Garrison::Plot::CreateGameObject(Map* map, GarrisonFactionIndex faction)
{
    uint32 entry = EmptyGameObjectId;
    if (BuildingInfo.PacketInfo)
    {
        GarrPlotInstanceEntry const* plotInstance = sGarrPlotInstanceStore.AssertEntry(PacketInfo.GarrPlotInstanceID);
        GarrPlotEntry const* plot = sGarrPlotStore.AssertEntry(plotInstance->GarrPlotID);
        GarrBuildingEntry const* building = sGarrBuildingStore.AssertEntry(BuildingInfo.PacketInfo->GarrBuildingID);
        entry = faction == GARRISON_FACTION_INDEX_HORDE ? plot->HordeConstructObjID : plot->AllianceConstructObjID;
        if (BuildingInfo.PacketInfo->Active || !entry)
            entry = faction == GARRISON_FACTION_INDEX_HORDE ? building->HordeGameObjectID : building->AllianceGameObjectID;
    }

    if (!sObjectMgr->GetGameObjectTemplate(entry))
    {
        TC_LOG_ERROR("garrison", "Garrison attempted to spawn gameobject whose template doesn't exist (%u)", entry);
        return nullptr;
    }

    GameObject* building = GameObject::CreateGameObject(entry, map, PacketInfo.PlotPos.Pos, Rotation, 255, GO_STATE_READY);
    if (!building)
        return nullptr;

    if (BuildingInfo.CanActivate() && BuildingInfo.PacketInfo && !BuildingInfo.PacketInfo->Active)
    {
        if (FinalizeGarrisonPlotGOInfo const* finalizeInfo = sGarrisonMgr.GetPlotFinalizeGOInfo(PacketInfo.GarrPlotInstanceID))
        {
            Position const& pos2 = finalizeInfo->FactionInfo[faction].Pos;
            if (GameObject* finalizer = GameObject::CreateGameObject(finalizeInfo->FactionInfo[faction].GameObjectId, map, pos2, QuaternionData::fromEulerAnglesZYX(pos2.GetOrientation(), 0.0f, 0.0f), 255, GO_STATE_READY))
            {
                // set some spell id to make the object delete itself after use
                finalizer->SetSpellId(finalizer->GetGOInfo()->goober.spell);
                finalizer->SetRespawnTime(0);

                if (uint16 animKit = finalizeInfo->FactionInfo[faction].AnimKitId)
                    finalizer->SetAnimKitId(animKit, false);

                map->AddToMap(finalizer);
            }
        }
    }

    if (building->GetGoType() == GAMEOBJECT_TYPE_GARRISON_BUILDING && building->GetGOInfo()->garrisonBuilding.SpawnMap)
    {
        for (CellObjectGuidsMap::value_type const& cellGuids : sObjectMgr->GetMapObjectGuids(building->GetGOInfo()->garrisonBuilding.SpawnMap, map->GetDifficultyID()))
        {
            for (ObjectGuid::LowType spawnId : cellGuids.second.creatures)
                if (Creature* spawn = BuildingSpawnHelper<Creature, &Creature::SetHomePosition>(building, spawnId, map))
                    BuildingInfo.Spawns.insert(spawn->GetGUID());

            for (ObjectGuid::LowType spawnId : cellGuids.second.gameobjects)
                if (GameObject* spawn = BuildingSpawnHelper<GameObject, &GameObject::RelocateStationaryPosition>(building, spawnId, map))
                    BuildingInfo.Spawns.insert(spawn->GetGUID());
        }
    }

    BuildingInfo.Guid = building->GetGUID();
    return building;
}

void Garrison::Plot::DeleteGameObject(Map* map)
{
    if (BuildingInfo.Guid.IsEmpty())
        return;

    for (ObjectGuid const& guid : BuildingInfo.Spawns)
    {
        WorldObject* object = nullptr;
        switch (guid.GetHigh())
        {
            case HighGuid::Creature:
                object = map->GetCreature(guid);
                break;
            case HighGuid::GameObject:
                object = map->GetGameObject(guid);
                break;
            default:
                continue;
        }

        if (object)
            object->AddObjectToRemoveList();
    }

    BuildingInfo.Spawns.clear();

    if (GameObject* oldBuilding = map->GetGameObject(BuildingInfo.Guid))
        oldBuilding->Delete();

    BuildingInfo.Guid.Clear();
}

void Garrison::Plot::ClearBuildingInfo(GarrisonType garrisonType, Player* owner)
{
    WorldPackets::Garrison::GarrisonPlotPlaced plotPlaced;
    plotPlaced.GarrTypeID = garrisonType;
    plotPlaced.PlotInfo = &PacketInfo;
    owner->SendDirectMessage(plotPlaced.Write());

    BuildingInfo.PacketInfo = boost::none;
}

void Garrison::Plot::SetBuildingInfo(WorldPackets::Garrison::GarrisonBuildingInfo const& buildingInfo, Player* owner)
{
    if (!BuildingInfo.PacketInfo)
    {
        WorldPackets::Garrison::GarrisonPlotRemoved plotRemoved;
        plotRemoved.GarrPlotInstanceID = PacketInfo.GarrPlotInstanceID;
        owner->SendDirectMessage(plotRemoved.Write());
    }

    BuildingInfo.PacketInfo = buildingInfo;
}

bool Garrison::Building::CanActivate() const
{
    if (PacketInfo)
    {
        GarrBuildingEntry const* building = sGarrBuildingStore.AssertEntry(PacketInfo->GarrBuildingID);
        if (PacketInfo->TimeBuilt + building->BuildSeconds <= time(nullptr))
            return true;
    }

    return false;
}

uint32 Garrison::Follower::GetItemLevel() const
{
    return (PacketInfo.ItemLevelWeapon + PacketInfo.ItemLevelArmor) / 2;
}

bool Garrison::Follower::HasAbility(uint32 garrAbilityId) const
{
    return std::find_if(PacketInfo.AbilityID.begin(), PacketInfo.AbilityID.end(), [garrAbilityId](GarrAbilityEntry const* garrAbility)
    {
        return garrAbility->ID == garrAbilityId;
    }) != PacketInfo.AbilityID.end();
}
