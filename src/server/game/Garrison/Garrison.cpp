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
#include "GameTime.h"
#include "GarrisonMgr.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "VehicleDefines.h"
#include "advstd.h"

// We could move this do a database table if needed
static constexpr GarrisonType SiteIdToGarrType(uint32 siteId)
{
    switch (siteId)
    {
        case 2:
        case 71:
            return GARRISON_TYPE_GARRISON;
        case 161:
        case 163:
            return GARRISON_TYPE_CLASS_ORDER;
        case 168:
        case 169:
            return GARRISON_TYPE_WAR_CAMPAIGN;
        case 296:
        case 299:
            return GARRISON_TYPE_COVENANT;
        default: // Later expansions seem to have GarrisonSites, but not mapped to a GarrisonType
            TC_LOG_WARN("player.garrison", "Unknown siteId '{}' passed to retrieve GarrTypeId.", siteId);
            return GARRISON_TYPE_NONE;
    }
}

Garrison::Garrison(Player* owner) : _owner(owner) { }

bool Garrison::LoadFromDB(PreparedQueryResult garrisons, PreparedQueryResult blueprints, PreparedQueryResult buildings,
    PreparedQueryResult followers, PreparedQueryResult abilities)
{
    if (!garrisons)
        return true; // make sure we always create the garrison object

    Field* fields;
    do
    {
        // SELECT garrTypeId, siteLevelId, followerActivationsRemainingToday FROM character_garrison WHERE guid = ?
        fields = garrisons->Fetch();

        uint8 garrTypeId = fields[0].GetUInt8();
        GarrTypeEntry const* garrTypeEntry = sGarrTypeStore.LookupEntry(garrTypeId);
        if (!garrTypeEntry)
        {
            TC_LOG_WARN("player.garrison", "Player '{}' has unknown GarrType '{}'!", _owner->GetGUID(), garrTypeId);
            continue;
        }

        uint32 garrSiteLevelId = fields[0].GetUInt32();
        GarrSiteLevelEntry const* garrSiteLevel = sGarrSiteLevelStore.LookupEntry(fields[1].GetUInt32());
        if (!garrSiteLevel)
        {
            TC_LOG_WARN("player.garrison", "Player '{}' has unknown GarrSiteLevel '{}'!", _owner->GetGUID(), garrSiteLevelId);
            continue;
        }

        GarrisonInfo garrInfo(garrTypeEntry, garrSiteLevel);

        garrInfo.NumFollowerActivationsRemainingToday = fields[2].GetUInt32();
        _garrisonInfo.emplace(garrTypeEntry->ID, std::move(garrInfo));

    } while (garrisons->NextRow());

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
            time_t timeBuilt = fields[2].GetInt64();
            bool active = fields[3].GetBool();

            Plot* plot = GetPlot(plotInstanceId);
            if (!plot)
                continue;

            if (!sGarrBuildingStore.LookupEntry(buildingId))
                continue;

            plot->BuildingInfo.PacketInfo.emplace();
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
    for (auto const& [_, garrInfo] : _garrisonInfo )
    {
        stmt->setUInt64(0, _owner->GetGUID().GetCounter());
        stmt->setUInt8(1, garrInfo.GarrType->ID);
        stmt->setUInt32(2, garrInfo.GarrSiteLevel->ID);
        stmt->setUInt32(3, garrInfo.NumFollowerActivationsRemainingToday);
        trans->Append(stmt);
    }

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
            stmt->setInt64(3, plot.BuildingInfo.PacketInfo->TimeBuilt);
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

    GarrTypeEntry const* garrType = sGarrTypeStore.LookupEntry(SiteIdToGarrType(siteLevel->GarrSiteID));
    if (!garrType)
        return false;

    // check if garrison already exists
    if (_garrisonInfo.contains(garrType->ID))
        return false;

    _garrisonInfo.emplace(garrType->ID, GarrisonInfo(garrType, siteLevel));

    InitializePlots();

    WorldPackets::Garrison::GarrisonCreateResult garrisonCreateResult;
    garrisonCreateResult.GarrSiteLevelID = siteLevel->ID;
    _owner->SendDirectMessage(garrisonCreateResult.Write());
    PhasingHandler::OnConditionChange(_owner);
    SendRemoteInfo();
    return true;
}

void Garrison::Delete(uint32 garrSiteId)
{
    GarrisonType type = SiteIdToGarrType(garrSiteId);
    if (!_garrisonInfo.contains(type))
    {
        WorldPackets::Garrison::GarrisonDeleteResult garrisonDelete;
        garrisonDelete.Result = GARRISON_ERROR_INVALID_GARRISON_TYPE;
        garrisonDelete.GarrSiteID = garrSiteId;
        _owner->SendDirectMessage(garrisonDelete.Write());
        return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    DeleteFromDB(_owner->GetGUID().GetCounter(), trans);
    CharacterDatabase.CommitTransaction(trans);

    WorldPackets::Garrison::GarrisonDeleteResult garrisonDelete;
    garrisonDelete.Result = GARRISON_SUCCESS;
    garrisonDelete.GarrSiteID = garrSiteId;

    _garrisonInfo.erase(type);
    // TODO what about followers? Missions? Buildings? ...

    _owner->SendDirectMessage(garrisonDelete.Write());
}

void Garrison::InitializePlots()
{
    for (auto const& [_, garrisonInfo] : _garrisonInfo)
    {
        if (std::vector<GarrSiteLevelPlotInstEntry const*> const* plots = sGarrisonMgr.GetGarrPlotInstForSiteLevel(garrisonInfo.GarrSiteLevel->ID))
        {
            for (std::size_t i = 0; i < plots->size(); ++i)
            {
                uint32 garrPlotInstanceId = plots->at(i)->GarrPlotInstanceID;
                GarrPlotInstanceEntry const* plotInstance = sGarrPlotInstanceStore.LookupEntry(garrPlotInstanceId);
                GameObjectsEntry const* gameObject = sGarrisonMgr.GetPlotGameObject(garrisonInfo.GarrSiteLevel->MapID, garrPlotInstanceId);
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
                plotInfo.PlotEntry = plot;
                plotInfo.SiteLevelPlotInstEntry = plots->at(i);
            }
        }
    }
}

void Garrison::Upgrade()
{
}

void Garrison::Enter() const
{
    GarrisonInfo const* garrInfo = GetGarrisonInfo(GARRISON_TYPE_GARRISON);
    if (!garrInfo)
        return;

    if (MapEntry const* map = sMapStore.LookupEntry(garrInfo->GarrSiteLevel->MapID))
        if (int32(_owner->GetMapId()) == map->ParentMapID)
            _owner->TeleportTo(WorldLocation(garrInfo->GarrSiteLevel->MapID, *_owner), TELE_TO_SEAMLESS);
}

void Garrison::Leave() const
{
    GarrisonInfo const* garrInfo = GetGarrisonInfo(GARRISON_TYPE_GARRISON);
    if (!garrInfo)
        return;

    if (MapEntry const* map = sMapStore.LookupEntry(garrInfo->GarrSiteLevel->MapID))
        if (_owner->GetMapId() == garrInfo->GarrSiteLevel->MapID)
            _owner->TeleportTo(WorldLocation(map->ParentMapID, *_owner), TELE_TO_SEAMLESS);
}

GarrisonFactionIndex Garrison::GetFaction() const
{
    return GetFaction(_owner->GetTeam());
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
    GarrBuildingEntry const* garrBuilding = sGarrBuildingStore.LookupEntry(garrBuildingId);

    WorldPackets::Garrison::GarrisonLearnBlueprintResult learnBlueprintResult;
    learnBlueprintResult.GarrTypeID = garrBuilding ? garrBuilding->GarrTypeID : 0;
    learnBlueprintResult.BuildingID = garrBuildingId;
    learnBlueprintResult.Result = GARRISON_SUCCESS;

    if (!garrBuilding)
        learnBlueprintResult.Result = GARRISON_ERROR_INVALID_BUILDINGID;
    else if (HasBlueprint(garrBuildingId))
        learnBlueprintResult.Result = GARRISON_ERROR_BLUEPRINT_EXISTS;
    else
        _knownBuildings.insert(garrBuildingId);

    _owner->SendDirectMessage(learnBlueprintResult.Write());
}

void Garrison::UnlearnBlueprint(uint32 garrBuildingId)
{
    GarrBuildingEntry const* garrBuilding = sGarrBuildingStore.LookupEntry(garrBuildingId);

    WorldPackets::Garrison::GarrisonUnlearnBlueprintResult unlearnBlueprintResult;
    unlearnBlueprintResult.GarrTypeID = garrBuilding ? garrBuilding->GarrTypeID : 0;
    unlearnBlueprintResult.BuildingID = garrBuildingId;
    unlearnBlueprintResult.Result = GARRISON_SUCCESS;

    if (!garrBuilding)
        unlearnBlueprintResult.Result = GARRISON_ERROR_INVALID_BUILDINGID;
    else if (!HasBlueprint(garrBuildingId))
        unlearnBlueprintResult.Result = GARRISON_ERROR_REQUIRES_BLUEPRINT;
    else
        _knownBuildings.erase(garrBuildingId);

    _owner->SendDirectMessage(unlearnBlueprintResult.Write());
}

void Garrison::PlaceBuilding(uint32 garrPlotInstanceId, uint32 garrBuildingId)
{
    GarrBuildingEntry const* garrBuilding = sGarrBuildingStore.LookupEntry(garrBuildingId);
    if (!garrBuilding)
    {
        WorldPackets::Garrison::GarrisonPlaceBuildingResult placeBuildingResult;
        placeBuildingResult.Result = GARRISON_ERROR_INVALID_BUILDINGID;
        _owner->SendDirectMessage(placeBuildingResult.Write());
    }

    GarrisonInfo const* garrisonInfo = GetGarrisonInfo(static_cast<GarrisonType>(garrBuilding->GarrTypeID));
    if (!garrisonInfo)
    {
        WorldPackets::Garrison::GarrisonPlaceBuildingResult placeBuildingResult;
        placeBuildingResult.Result = GARRISON_ERROR_INVALID_GARRISON;
        _owner->SendDirectMessage(placeBuildingResult.Write());
        return;
    }

    WorldPackets::Garrison::GarrisonPlaceBuildingResult placeBuildingResult;
    placeBuildingResult.GarrTypeID = garrBuilding->GarrTypeID;
    placeBuildingResult.Result = CheckBuildingPlacement(garrPlotInstanceId, garrBuildingId);
    if (placeBuildingResult.Result == GARRISON_SUCCESS)
    {
        placeBuildingResult.BuildingInfo.GarrPlotInstanceID = garrPlotInstanceId;
        placeBuildingResult.BuildingInfo.GarrBuildingID = garrBuildingId;
        placeBuildingResult.BuildingInfo.TimeBuilt = GameTime::GetGameTime();

        Plot* plot = GetPlot(garrPlotInstanceId);
        uint32 oldBuildingId = 0;
        Map* map = FindMap(garrisonInfo->GarrSiteLevel);
        GarrBuildingEntry const* building = sGarrBuildingStore.AssertEntry(garrBuildingId);
        if (map)
            plot->DeleteGameObject(map);

        if (plot->BuildingInfo.PacketInfo)
        {
            oldBuildingId = plot->BuildingInfo.PacketInfo->GarrBuildingID;
            if (sGarrBuildingStore.AssertEntry(oldBuildingId)->BuildingType != building->BuildingType)
                plot->ClearBuildingInfo(static_cast<GarrisonType>(garrisonInfo->GarrType->ID), _owner);
        }

        plot->SetBuildingInfo(placeBuildingResult.BuildingInfo, _owner);
        if (map)
            if (GameObject* go = plot->CreateGameObject(map, GetFaction()))
                map->AddToMap(go);

        _owner->RemoveCurrency(building->CurrencyTypeID, building->CurrencyQty, CurrencyDestroyReason::Garrison);
        _owner->ModifyMoney(-building->GoldCost * GOLD, false);

        if (oldBuildingId)
        {
            WorldPackets::Garrison::GarrisonBuildingRemoved buildingRemoved;
            buildingRemoved.GarrTypeID = static_cast<GarrisonType>(garrisonInfo->GarrType->ID);
            buildingRemoved.Result = GARRISON_SUCCESS;
            buildingRemoved.GarrPlotInstanceID = garrPlotInstanceId;
            buildingRemoved.GarrBuildingID = oldBuildingId;
            _owner->SendDirectMessage(buildingRemoved.Write());
        }

        _owner->UpdateCriteria(CriteriaType::PlaceGarrisonBuilding, garrBuildingId);
    }

    _owner->SendDirectMessage(placeBuildingResult.Write());
}

void Garrison::CancelBuildingConstruction(uint32 garrPlotInstanceId)
{
    GarrPlotInstanceEntry const* plotInstance = sGarrPlotInstanceStore.LookupEntry(garrPlotInstanceId);
    if (!plotInstance)
    {
        WorldPackets::Garrison::GarrisonBuildingRemoved buildingRemoved;
        buildingRemoved.Result = GARRISON_ERROR_INVALID_PLOT_INSTANCEID;
        buildingRemoved.GarrTypeID = 0;
        _owner->SendDirectMessage(buildingRemoved.Write());
        return;
    }

    WorldPackets::Garrison::GarrisonBuildingRemoved buildingRemoved;
    buildingRemoved.GarrTypeID = 0;
    buildingRemoved.Result = CheckBuildingRemoval(garrPlotInstanceId);
    if (buildingRemoved.Result == GARRISON_SUCCESS)
    {
        Plot* plot = GetPlot(garrPlotInstanceId);

        buildingRemoved.GarrPlotInstanceID = garrPlotInstanceId;
        buildingRemoved.GarrBuildingID = plot->BuildingInfo.PacketInfo->GarrBuildingID;

        GarrSiteLevelPlotInstEntry const* siteLevelPlotInst = sGarrSiteLevelPlotInstStore.AssertEntry(plot->GarrSiteLevelPlotInstId);
        GarrSiteLevelEntry const* siteLevel = sGarrSiteLevelStore.AssertEntry(siteLevelPlotInst->GarrSiteLevelID);
        GarrisonType garrType = SiteIdToGarrType(siteLevel->GarrSiteID);

        Map* map = FindMap(siteLevel);
        if (map)
            plot->DeleteGameObject(map);

        plot->ClearBuildingInfo(garrType, _owner);
        _owner->SendDirectMessage(buildingRemoved.Write());

        GarrBuildingEntry const* constructing = sGarrBuildingStore.AssertEntry(buildingRemoved.GarrBuildingID);
        // Refund construction/upgrade cost
        _owner->AddCurrency(constructing->CurrencyTypeID, constructing->CurrencyQty, CurrencyGainSource::GarrisonBuildingRefund);
        _owner->ModifyMoney(constructing->GoldCost * GOLD, false);

        if (constructing->UpgradeLevel > 1)
        {
            // Restore previous level building
            uint32 restored = sGarrisonMgr.GetPreviousLevelBuildingId(constructing->BuildingType, constructing->UpgradeLevel);
            ASSERT(restored);

            WorldPackets::Garrison::GarrisonPlaceBuildingResult placeBuildingResult;
            placeBuildingResult.GarrTypeID = garrType;
            placeBuildingResult.Result = GARRISON_SUCCESS;
            placeBuildingResult.BuildingInfo.GarrPlotInstanceID = garrPlotInstanceId;
            placeBuildingResult.BuildingInfo.GarrBuildingID = restored;
            placeBuildingResult.BuildingInfo.TimeBuilt = GameTime::GetGameTime();
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
            GarrSiteLevelPlotInstEntry const* siteLevelPlotInst = sGarrSiteLevelPlotInstStore.AssertEntry(plot->GarrSiteLevelPlotInstId);
            GarrSiteLevelEntry const* siteLevel = sGarrSiteLevelStore.AssertEntry(siteLevelPlotInst->GarrSiteLevelID);
            if (Map* map = FindMap(siteLevel))
            {
                plot->DeleteGameObject(map);
                if (GameObject* go = plot->CreateGameObject(map, GetFaction()))
                    map->AddToMap(go);
            }

            WorldPackets::Garrison::GarrisonBuildingActivated buildingActivated;
            buildingActivated.GarrPlotInstanceID = garrPlotInstanceId;
            _owner->SendDirectMessage(buildingActivated.Write());

            _owner->UpdateCriteria(CriteriaType::ActivateAnyGarrisonBuilding, plot->BuildingInfo.PacketInfo->GarrBuildingID);
        }
    }
}

void Garrison::AddFollower(uint32 garrFollowerId)
{
    GarrFollowerEntry const* followerEntry = sGarrFollowerStore.LookupEntry(garrFollowerId);
    WorldPackets::Garrison::GarrisonAddFollowerResult addFollowerResult;
    if (_followerIds.contains(garrFollowerId) || !followerEntry)
    {
        addFollowerResult.Result = GARRISON_ERROR_FOLLOWER_EXISTS;
        _owner->SendDirectMessage(addFollowerResult.Write());
        return;
    }

    addFollowerResult.GarrTypeID = followerEntry->GarrTypeID;
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

    _owner->UpdateCriteria(CriteriaType::RecruitGarrisonFollower, follower.PacketInfo.DbID);
}

Garrison::Follower const* Garrison::GetFollower(uint64 dbId) const
{
    auto itr = _followers.find(dbId);
    if (itr != _followers.end())
        return &itr->second;

    return nullptr;
}

void Garrison::SendRemoteInfo() const
{
    WorldPackets::Garrison::GarrisonRemoteInfo remoteInfo;

    for (auto const& [_, garrisonInfo] : _garrisonInfo)
    {
        MapEntry const* garrisonMap = sMapStore.LookupEntry(garrisonInfo.GarrSiteLevel->MapID);
        if (!garrisonMap || int32(_owner->GetMapId()) != garrisonMap->ParentMapID)
            continue;

        WorldPackets::Garrison::GarrisonRemoteSiteInfo& remoteSiteInfo = remoteInfo.Sites.emplace_back();
        remoteSiteInfo.GarrSiteLevelID = garrisonInfo.GarrSiteLevel->ID;
        for (const auto& [plotInstanceId, plot] : _plots)
            if (plot.BuildingInfo.GarrBuilding && plot.BuildingInfo.GarrBuilding->GarrTypeID == garrisonInfo.GarrType->ID)
                remoteSiteInfo.Buildings.emplace_back(plotInstanceId, plot.BuildingInfo.GarrBuilding->ID);
    }

    _owner->SendDirectMessage(remoteInfo.Write());
}

void Garrison::SendBlueprintAndSpecializationData()
{
    WorldPackets::Garrison::GarrisonRequestBlueprintAndSpecializationDataResult data;
    data.GarrTypeID = GARRISON_TYPE_GARRISON;
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

Map* Garrison::FindMap(GarrSiteLevelEntry const* garrSiteLevel) const
{
    ASSERT(garrSiteLevel);
    return sMapMgr->FindMap(garrSiteLevel->MapID, _owner->GetGUID().GetCounter());
}

GarrisonError Garrison::CheckBuildingPlacement(uint32 garrPlotInstanceId, uint32 garrBuildingId) const
{
    Plot const* plot = GetPlot(garrPlotInstanceId);
    if (!plot)
        return GARRISON_ERROR_INVALID_PLOT_INSTANCEID;

    GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(garrBuildingId);
    if (!building)
        return GARRISON_ERROR_INVALID_BUILDINGID;

    if (!sGarrisonMgr.IsPlotMatchingBuilding(plot->PlotInstanceEntry->GarrPlotID, garrBuildingId))
        return GARRISON_ERROR_INVALID_PLOT_BUILDING;

    GarrSiteLevelEntry const* siteLevel = sGarrSiteLevelStore.AssertEntry(plot->SiteLevelPlotInstEntry->GarrSiteLevelID);
    // Cannot place buldings of higher level than garrison level
    if (building->UpgradeLevel > siteLevel->MaxBuildingLevel)
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

template<class T, void(T::*SecondaryRelocate)(Position const&)>
T* BuildingSpawnHelper(GameObject* building, ObjectGuid::LowType spawnId, Map* map)
{
    T* spawn = new T();
    if (!spawn->LoadFromDB(spawnId, map, false, false))
    {
        delete spawn;
        return nullptr;
    }

    Position globalPosition = building->GetPositionWithOffset(spawn->GetPosition());

    spawn->Relocate(globalPosition);
    (spawn->*SecondaryRelocate)(globalPosition);

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
        TC_LOG_ERROR("garrison", "Garrison attempted to spawn gameobject whose template doesn't exist ({})", entry);
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
        if (CellObjectGuidsMap const* cells = sObjectMgr->GetMapObjectGuids(building->GetGOInfo()->garrisonBuilding.SpawnMap, map->GetDifficultyID()))
        {
            for (auto const& [cellId, guids] : *cells)
            {
                for (ObjectGuid::LowType spawnId : guids.gameobjects)
                    if (GameObject* spawn = BuildingSpawnHelper<GameObject, &GameObject::RelocateStationaryPosition>(building, spawnId, map))
                        BuildingInfo.Spawns.insert(spawn->GetGUID());

                for (ObjectGuid::LowType spawnId : guids.creatures)
                    if (Creature* spawn = BuildingSpawnHelper<Creature, &Creature::SetHomePosition>(building, spawnId, map))
                        BuildingInfo.Spawns.insert(spawn->GetGUID());
            }
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

    BuildingInfo.PacketInfo.reset();
}

void Garrison::Plot::SetBuildingInfo(WorldPackets::Garrison::GarrisonBuildingInfo const& buildingInfo, Player* owner)
{
    if (!BuildingInfo.PacketInfo)
    {
        WorldPackets::Garrison::GarrisonPlotRemoved plotRemoved;
        plotRemoved.GarrPlotInstanceID = PacketInfo.GarrPlotInstanceID;
        owner->SendDirectMessage(plotRemoved.Write());
    }

    BuildingInfo.GarrBuilding = sGarrBuildingStore.AssertEntry(buildingInfo.GarrBuildingID);
    BuildingInfo.PacketInfo = buildingInfo;
}

bool Garrison::Building::CanActivate() const
{
    if (PacketInfo)
    {
        GarrBuildingEntry const* building = sGarrBuildingStore.AssertEntry(PacketInfo->GarrBuildingID);
        if (PacketInfo->TimeBuilt + building->BuildSeconds <= GameTime::GetGameTime())
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
    return advstd::ranges::contains(PacketInfo.AbilityID, garrAbilityId, &GarrAbilityEntry::ID);
}

void Garrison::SendInfoResult() const
{
    WorldPackets::Garrison::GetGarrisonInfoResult result;
    result.FactionIndex = GetFaction(_owner->GetTeam());
    result.FollowerSoftCaps.reserve(_followerSoftCaps.size());
    result.Garrisons.reserve(_garrisonInfo.size());

    std::ranges::transform(_followerSoftCaps, std::back_inserter(result.FollowerSoftCaps), [&](FollowerSoftCapInfo const& softCapInfo)
    {
        WorldPackets::Garrison::FollowerSoftCapInfo info;
        info.Count = softCapInfo.Count;
        info.GarrFollowerTypeID = softCapInfo.FollowerTypeID;
        return info;
    });

    std::unordered_map<uint8 /*garrType*/, std::vector<WorldPackets::Garrison::GarrisonPlotInfo const*>> plotsByGarrType;
    std::unordered_map<uint8 /*garrType*/, std::vector<WorldPackets::Garrison::GarrisonBuildingInfo const*>> buildingsByGarrType;
    for (auto const& [_, plot] : _plots)
    {
        GarrSiteLevelEntry const* siteLevelStore = sGarrSiteLevelStore.AssertEntry(plot.SiteLevelPlotInstEntry->GarrSiteLevelID);

        plotsByGarrType[SiteIdToGarrType(siteLevelStore->GarrSiteID)].push_back(&plot.PacketInfo);
        if (plot.BuildingInfo.PacketInfo)
            buildingsByGarrType[SiteIdToGarrType(siteLevelStore->GarrSiteID)].push_back(&*plot.BuildingInfo.PacketInfo);
    }

    std::unordered_map<uint8 /*garrType*/, std::vector<WorldPackets::Garrison::GarrisonFollower const*>> followersByGarrType;
    for (auto const& [_, follower] : _followers)
        followersByGarrType[follower.FollowerEntry->GarrTypeID].push_back(&follower.PacketInfo);

    std::ranges::transform(_garrisonInfo, std::back_inserter(result.Garrisons), [&](auto const& kv)
    {
        GarrisonInfo const& garrisonInfo = kv.second;
        WorldPackets::Garrison::GarrisonInfo garrison;
        garrison.GarrTypeID = garrisonInfo.GarrType->ID;
        garrison.GarrSiteID = garrisonInfo.GarrSiteLevel->GarrSiteID;
        garrison.GarrSiteLevelID = garrisonInfo.GarrSiteLevel->ID;
        garrison.NumFollowerActivationsRemaining = garrisonInfo.NumFollowerActivationsRemainingToday;

        if (plotsByGarrType.contains(garrisonInfo.GarrType->ID))
            garrison.Plots = std::move(plotsByGarrType[garrisonInfo.GarrType->ID]);

        if (buildingsByGarrType.contains(garrisonInfo.GarrType->ID))
            garrison.Buildings = std::move(buildingsByGarrType[garrisonInfo.GarrType->ID]);

        if (followersByGarrType.contains(garrisonInfo.GarrType->ID))
            garrison.Followers = std::move(followersByGarrType[garrisonInfo.GarrType->ID]);

        return garrison;
    });

    _owner->SendDirectMessage(result.Write());
}
