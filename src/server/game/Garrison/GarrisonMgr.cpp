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

#include "GarrisonMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Garrison.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Random.h"
#include "Timer.h"
#include "World.h"

GarrisonMgr& GarrisonMgr::Instance()
{
    static GarrisonMgr instance;
    return instance;
}

void GarrisonMgr::Initialize()
{
    for (GarrSiteLevelPlotInstEntry const* siteLevelPlotInst : sGarrSiteLevelPlotInstStore)
        _garrisonPlotInstBySiteLevel[siteLevelPlotInst->GarrSiteLevelID].push_back(siteLevelPlotInst);

    for (GameObjectsEntry const* gameObject : sGameObjectsStore)
        if (gameObject->TypeID == GAMEOBJECT_TYPE_GARRISON_PLOT)
            _garrisonPlots[gameObject->OwnerID][gameObject->PropValue[0]] = gameObject;

    for (GarrPlotBuildingEntry const* plotBuilding : sGarrPlotBuildingStore)
        _garrisonBuildingsByPlot[plotBuilding->GarrPlotID].insert(plotBuilding->GarrBuildingID);

    for (GarrBuildingPlotInstEntry const* buildingPlotInst : sGarrBuildingPlotInstStore)
        _garrisonBuildingPlotInstances[std::make_pair(buildingPlotInst->GarrBuildingID, buildingPlotInst->GarrSiteLevelPlotInstID)] = buildingPlotInst->ID;

    for (GarrBuildingEntry const* building : sGarrBuildingStore)
        _garrisonBuildingsByType[building->BuildingType].push_back(building->ID);

    for (GarrFollowerXAbilityEntry const* followerAbility : sGarrFollowerXAbilityStore)
    {
        if (GarrAbilityEntry const* ability = sGarrAbilityStore.LookupEntry(followerAbility->GarrAbilityID))
        {
            if (ability->GarrFollowerTypeID != FOLLOWER_TYPE_GARRISON)
                continue;

            if (!(ability->Flags & GARRISON_ABILITY_CANNOT_ROLL) && ability->Flags & GARRISON_ABILITY_FLAG_TRAIT)
                _garrisonFollowerRandomTraits.insert(ability);

            if (followerAbility->FactionIndex < 2)
            {
                if (ability->Flags & GARRISON_ABILITY_FLAG_TRAIT)
                    _garrisonFollowerAbilities[followerAbility->FactionIndex][followerAbility->GarrFollowerID].Traits.insert(ability);
                else
                    _garrisonFollowerAbilities[followerAbility->FactionIndex][followerAbility->GarrFollowerID].Counters.insert(ability);
            }
        }
    }

    InitializeDbIdSequences();
    LoadPlotFinalizeGOInfo();
    LoadFollowerClassSpecAbilities();
}

GarrSiteLevelEntry const* GarrisonMgr::GetGarrSiteLevelEntry(uint32 garrSiteId, uint32 level) const
{
    for (GarrSiteLevelEntry const* siteLevel : sGarrSiteLevelStore)
        if (siteLevel->GarrSiteID == garrSiteId && siteLevel->GarrLevel == level)
            return siteLevel;

    return nullptr;
}

std::vector<GarrSiteLevelPlotInstEntry const*> const* GarrisonMgr::GetGarrPlotInstForSiteLevel(uint32 garrSiteLevelId) const
{
    auto itr = _garrisonPlotInstBySiteLevel.find(garrSiteLevelId);
    if (itr != _garrisonPlotInstBySiteLevel.end())
        return &itr->second;

    return nullptr;
}

GameObjectsEntry const* GarrisonMgr::GetPlotGameObject(uint32 mapId, uint32 garrPlotInstanceId) const
{
    auto mapItr = _garrisonPlots.find(mapId);
    if (mapItr != _garrisonPlots.end())
    {
        auto plotItr = mapItr->second.find(garrPlotInstanceId);
        if (plotItr != mapItr->second.end())
            return plotItr->second;
    }

    return nullptr;
}

bool GarrisonMgr::IsPlotMatchingBuilding(uint32 garrPlotId, uint32 garrBuildingId) const
{
    auto plotItr = _garrisonBuildingsByPlot.find(garrPlotId);
    if (plotItr != _garrisonBuildingsByPlot.end())
        return plotItr->second.count(garrBuildingId) > 0;

    return false;
}

uint32 GarrisonMgr::GetGarrBuildingPlotInst(uint32 garrBuildingId, uint32 garrSiteLevelPlotInstId) const
{
    auto itr = _garrisonBuildingPlotInstances.find(std::make_pair(garrBuildingId, garrSiteLevelPlotInstId));
    if (itr != _garrisonBuildingPlotInstances.end())
        return itr->second;

    return 0;
}

uint32 GarrisonMgr::GetPreviousLevelBuildingId(uint32 buildingType, uint32 currentLevel) const
{
    auto itr = _garrisonBuildingsByType.find(buildingType);
    if (itr != _garrisonBuildingsByType.end())
        for (uint32 buildingId : itr->second)
            if (sGarrBuildingStore.AssertEntry(buildingId)->UpgradeLevel == currentLevel - 1)
                return buildingId;

    return 0;
}

FinalizeGarrisonPlotGOInfo const* GarrisonMgr::GetPlotFinalizeGOInfo(uint32 garrPlotInstanceID) const
{
    auto itr = _finalizePlotGOInfo.find(garrPlotInstanceID);
    if (itr != _finalizePlotGOInfo.end())
        return &itr->second;

    return nullptr;
}

uint64 GarrisonMgr::GenerateFollowerDbId()
{
    if (_followerDbIdGenerator >= std::numeric_limits<uint64>::max())
    {
        TC_LOG_ERROR("misc", "Garrison follower db id overflow! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }

    return _followerDbIdGenerator++;
}

uint32 const AbilitiesForQuality[][2] =
{
    // Counters, Traits
    { 0, 0 },
    { 1, 0 },
    { 1, 1 },   // Uncommon
    { 1, 2 },   // Rare
    { 2, 3 },   // Epic
    { 2, 3 }    // Legendary
};

std::list<GarrAbilityEntry const*> GarrisonMgr::RollFollowerAbilities(uint32 garrFollowerId, GarrFollowerEntry const* follower, uint32 quality, uint32 faction, bool initial) const
{
    ASSERT(faction < 2);

    bool hasForcedExclusiveTrait = false;
    std::list<GarrAbilityEntry const*> result;
    uint32 slots[2] = { AbilitiesForQuality[quality][0], AbilitiesForQuality[quality][1] };

    GarrAbilities const* abilities = nullptr;
    auto itr = _garrisonFollowerAbilities[faction].find(garrFollowerId);
    if (itr != _garrisonFollowerAbilities[faction].end())
        abilities = &itr->second;

    std::list<GarrAbilityEntry const*> abilityList, forcedAbilities, traitList, forcedTraits;
    if (abilities)
    {
        for (GarrAbilityEntry const* ability : abilities->Counters)
        {
            if (ability->Flags & GARRISON_ABILITY_HORDE_ONLY && faction != GARRISON_FACTION_INDEX_HORDE)
                continue;
            else if (ability->Flags & GARRISON_ABILITY_ALLIANCE_ONLY && faction != GARRISON_FACTION_INDEX_ALLIANCE)
                continue;

            if (ability->Flags & GARRISON_ABILITY_FLAG_CANNOT_REMOVE)
                forcedAbilities.push_back(ability);
            else
                abilityList.push_back(ability);
        }

        for (GarrAbilityEntry const* ability : abilities->Traits)
        {
            if (ability->Flags & GARRISON_ABILITY_HORDE_ONLY && faction != GARRISON_FACTION_INDEX_HORDE)
                continue;
            else if (ability->Flags & GARRISON_ABILITY_ALLIANCE_ONLY && faction != GARRISON_FACTION_INDEX_ALLIANCE)
                continue;

            if (ability->Flags & GARRISON_ABILITY_FLAG_CANNOT_REMOVE)
                forcedTraits.push_back(ability);
            else
                traitList.push_back(ability);
        }
    }

    Trinity::Containers::RandomResize(abilityList, std::max<int32>(0, slots[0] - forcedAbilities.size()));
    Trinity::Containers::RandomResize(traitList, std::max<int32>(0, slots[1] - forcedTraits.size()));

    // Add abilities specified in GarrFollowerXAbility.db2 before generic classspec ones on follower creation
    if (initial)
    {
        forcedAbilities.splice(forcedAbilities.end(), abilityList);
        forcedTraits.splice(forcedTraits.end(), traitList);
    }

    forcedAbilities.sort();
    abilityList.sort();
    forcedTraits.sort();
    traitList.sort();

    // check if we have a trait from exclusive category
    for (GarrAbilityEntry const* ability : forcedTraits)
    {
        if (ability->Flags & GARRISON_ABILITY_FLAG_EXCLUSIVE)
        {
            hasForcedExclusiveTrait = true;
            break;
        }
    }

    if (slots[0] > forcedAbilities.size() + abilityList.size())
    {
        std::list<GarrAbilityEntry const*> classSpecAbilities = GetClassSpecAbilities(follower, faction);
        std::list<GarrAbilityEntry const*> classSpecAbilitiesTemp, classSpecAbilitiesTemp2;
        classSpecAbilitiesTemp2.swap(abilityList);
        std::set_difference(classSpecAbilities.begin(), classSpecAbilities.end(), forcedAbilities.begin(), forcedAbilities.end(), std::back_inserter(classSpecAbilitiesTemp));
        std::set_union(classSpecAbilitiesTemp.begin(), classSpecAbilitiesTemp.end(), classSpecAbilitiesTemp2.begin(), classSpecAbilitiesTemp2.end(), std::back_inserter(abilityList));

        Trinity::Containers::RandomResize(abilityList, std::max<int32>(0, slots[0] - forcedAbilities.size()));
    }

    if (slots[1] > forcedTraits.size() + traitList.size())
    {
        std::list<GarrAbilityEntry const*> genericTraits, genericTraitsTemp;
        for (GarrAbilityEntry const* ability : _garrisonFollowerRandomTraits)
        {
            if (ability->Flags & GARRISON_ABILITY_HORDE_ONLY && faction != GARRISON_FACTION_INDEX_HORDE)
                continue;
            else if (ability->Flags & GARRISON_ABILITY_ALLIANCE_ONLY && faction != GARRISON_FACTION_INDEX_ALLIANCE)
                continue;

            // forced exclusive trait exists, skip other ones entirely
            if (hasForcedExclusiveTrait && ability->Flags & GARRISON_ABILITY_FLAG_EXCLUSIVE)
                continue;

            genericTraitsTemp.push_back(ability);
        }

        std::set_difference(genericTraitsTemp.begin(), genericTraitsTemp.end(), forcedTraits.begin(), forcedTraits.end(), std::back_inserter(genericTraits));
        genericTraits.splice(genericTraits.begin(), traitList);
        // "split" the list into two parts [nonexclusive, exclusive] to make selection later easier
        genericTraits.sort([](GarrAbilityEntry const* a1, GarrAbilityEntry const* a2)
        {
            uint32 e1 = a1->Flags & GARRISON_ABILITY_FLAG_EXCLUSIVE;
            uint32 e2 = a2->Flags & GARRISON_ABILITY_FLAG_EXCLUSIVE;
            if (e1 != e2)
                return e1 < e2;

            return a1->ID < a2->ID;
        });
        genericTraits.unique();

        std::size_t firstExclusive = 0, total = genericTraits.size();
        for (auto genericTraitItr = genericTraits.begin(); genericTraitItr != genericTraits.end(); ++genericTraitItr, ++firstExclusive)
            if ((*genericTraitItr)->Flags & GARRISON_ABILITY_FLAG_EXCLUSIVE)
                break;

        while (traitList.size() < size_t(std::max<int32>(0, slots[1] - forcedTraits.size())) && total)
        {
            auto genericTraitItr = genericTraits.begin();
            std::advance(genericTraitItr, urand(0, total-- - 1));
            if ((*genericTraitItr)->Flags & GARRISON_ABILITY_FLAG_EXCLUSIVE)
                total = firstExclusive; // selected exclusive trait - no other can be selected now
            else
                --firstExclusive;

            traitList.push_back(*genericTraitItr);
            genericTraits.erase(genericTraitItr);
        }
    }

    result.splice(result.end(), forcedAbilities);
    result.splice(result.end(), abilityList);
    result.splice(result.end(), forcedTraits);
    result.splice(result.end(), traitList);

    return result;
}

std::list<GarrAbilityEntry const*> GarrisonMgr::GetClassSpecAbilities(GarrFollowerEntry const* follower, uint32 faction) const
{
    std::list<GarrAbilityEntry const*> abilities;
    uint32 classSpecId;
    switch (faction)
    {
        case GARRISON_FACTION_INDEX_HORDE:
            classSpecId = follower->HordeGarrClassSpecID;
            break;
        case GARRISON_FACTION_INDEX_ALLIANCE:
            classSpecId = follower->AllianceGarrClassSpecID;
            break;
        default:
            return abilities;
    }

    if (!sGarrClassSpecStore.LookupEntry(classSpecId))
        return abilities;

    auto itr = _garrisonFollowerClassSpecAbilities.find(classSpecId);
    if (itr != _garrisonFollowerClassSpecAbilities.end())
        abilities = itr->second;

    return abilities;
}

void GarrisonMgr::InitializeDbIdSequences()
{
    if (QueryResult result = CharacterDatabase.Query("SELECT MAX(dbId) FROM character_garrison_followers"))
        _followerDbIdGenerator = (*result)[0].GetUInt64() + 1;
}

void GarrisonMgr::LoadPlotFinalizeGOInfo()
{
    //                                                                0                  1       2       3       4       5               6
    QueryResult result = WorldDatabase.Query("SELECT garrPlotInstanceId, hordeGameObjectId, hordeX, hordeY, hordeZ, hordeO, hordeAnimKitId, "
    //                      7          8          9         10         11                 12
        "allianceGameObjectId, allianceX, allianceY, allianceZ, allianceO, allianceAnimKitId FROM garrison_plot_finalize_info");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 garrison follower class spec abilities. DB table `garrison_plot_finalize_info` is empty.");
        return;
    }

    uint32 msTime = getMSTime();
    do
    {
        Field* fields = result->Fetch();
        uint32 garrPlotInstanceId = fields[0].GetUInt32();
        uint32 hordeGameObjectId = fields[1].GetUInt32();
        uint32 allianceGameObjectId = fields[7].GetUInt32();
        uint16 hordeAnimKitId = fields[6].GetUInt16();
        uint16 allianceAnimKitId = fields[12].GetUInt16();

        if (!sGarrPlotInstanceStore.LookupEntry(garrPlotInstanceId))
        {
            TC_LOG_ERROR("sql.sql", "Non-existing GarrPlotInstance.db2 entry %u was referenced in `garrison_plot_finalize_info`.", garrPlotInstanceId);
            continue;
        }

        GameObjectTemplate const* goTemplate = sObjectMgr->GetGameObjectTemplate(hordeGameObjectId);
        if (!goTemplate)
        {
            TC_LOG_ERROR("sql.sql", "Non-existing gameobject_template entry %u was referenced in `garrison_plot_finalize_info`.`hordeGameObjectId` for garrPlotInstanceId %u.",
                hordeGameObjectId, garrPlotInstanceId);
            continue;
        }

        if (goTemplate->type != GAMEOBJECT_TYPE_GOOBER)
        {
            TC_LOG_ERROR("sql.sql", "Invalid gameobject type %u (entry %u) was referenced in `garrison_plot_finalize_info`.`hordeGameObjectId` for garrPlotInstanceId %u.",
                goTemplate->type, hordeGameObjectId, garrPlotInstanceId);
            continue;
        }

        goTemplate = sObjectMgr->GetGameObjectTemplate(allianceGameObjectId);
        if (!goTemplate)
        {
            TC_LOG_ERROR("sql.sql", "Non-existing gameobject_template entry %u was referenced in `garrison_plot_finalize_info`.`allianceGameObjectId` for garrPlotInstanceId %u.",
                allianceGameObjectId, garrPlotInstanceId);
            continue;
        }

        if (goTemplate->type != GAMEOBJECT_TYPE_GOOBER)
        {
            TC_LOG_ERROR("sql.sql", "Invalid gameobject type %u (entry %u) was referenced in `garrison_plot_finalize_info`.`allianceGameObjectId` for garrPlotInstanceId %u.",
                goTemplate->type, allianceGameObjectId, garrPlotInstanceId);
            continue;
        }

        if (hordeAnimKitId && !sAnimKitStore.LookupEntry(hordeAnimKitId))
        {
            TC_LOG_ERROR("sql.sql", "Non-existing AnimKit.dbc entry %u was referenced in `garrison_plot_finalize_info`.`hordeAnimKitId` for garrPlotInstanceId %u.",
                hordeAnimKitId, garrPlotInstanceId);
            continue;
        }

        if (allianceAnimKitId && !sAnimKitStore.LookupEntry(allianceAnimKitId))
        {
            TC_LOG_ERROR("sql.sql", "Non-existing AnimKit.dbc entry %u was referenced in `garrison_plot_finalize_info`.`allianceAnimKitId` for garrPlotInstanceId %u.",
                allianceAnimKitId, garrPlotInstanceId);
            continue;
        }

        FinalizeGarrisonPlotGOInfo& info = _finalizePlotGOInfo[garrPlotInstanceId];
        info.FactionInfo[GARRISON_FACTION_INDEX_HORDE].GameObjectId = hordeGameObjectId;
        info.FactionInfo[GARRISON_FACTION_INDEX_HORDE].Pos.Relocate(fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat(), fields[5].GetFloat());
        info.FactionInfo[GARRISON_FACTION_INDEX_HORDE].AnimKitId = hordeAnimKitId;

        info.FactionInfo[GARRISON_FACTION_INDEX_ALLIANCE].GameObjectId = allianceGameObjectId;
        info.FactionInfo[GARRISON_FACTION_INDEX_ALLIANCE].Pos.Relocate(fields[8].GetFloat(), fields[9].GetFloat(), fields[10].GetFloat(), fields[11].GetFloat());
        info.FactionInfo[GARRISON_FACTION_INDEX_ALLIANCE].AnimKitId = allianceAnimKitId;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u garrison plot finalize entries in %u.", uint32(_finalizePlotGOInfo.size()), GetMSTimeDiffToNow(msTime));
}

void GarrisonMgr::LoadFollowerClassSpecAbilities()
{
    QueryResult result = WorldDatabase.Query("SELECT classSpecId, abilityId FROM garrison_follower_class_spec_abilities");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 garrison follower class spec abilities. DB table `garrison_follower_class_spec_abilities` is empty.");
        return;
    }

    uint32 msTime = getMSTime();
    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 classSpecId = fields[0].GetUInt32();
        uint32 abilityId = fields[1].GetUInt32();

        if (!sGarrClassSpecStore.LookupEntry(classSpecId))
        {
            TC_LOG_ERROR("sql.sql", "Non-existing GarrClassSpec.db2 entry %u was referenced in `garrison_follower_class_spec_abilities` by row (%u, %u).", classSpecId, classSpecId, abilityId);
            continue;
        }

        GarrAbilityEntry const* ability = sGarrAbilityStore.LookupEntry(abilityId);
        if (!ability)
        {
            TC_LOG_ERROR("sql.sql", "Non-existing GarrAbility.db2 entry %u was referenced in `garrison_follower_class_spec_abilities` by row (%u, %u).", abilityId, classSpecId, abilityId);
            continue;
        }

        _garrisonFollowerClassSpecAbilities[classSpecId].push_back(ability);
        ++count;

    } while (result->NextRow());

    for (auto& pair : _garrisonFollowerClassSpecAbilities)
        pair.second.sort();

    TC_LOG_INFO("server.loading", ">> Loaded %u garrison follower class spec abilities in %u.", count, GetMSTimeDiffToNow(msTime));
}
