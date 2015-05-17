/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "Garrison.h"
#include "ObjectDefines.h"
#include "World.h"

void GarrisonMgr::Initialize()
{
    for (GarrSiteLevelPlotInstEntry const* plotInstance : sGarrSiteLevelPlotInstStore)
        _garrisonPlotInstBySiteLevel[plotInstance->GarrSiteLevelID].push_back(plotInstance);

    for (GameObjectsEntry const* gameObject : sGameObjectsStore)
        if (gameObject->Type == GAMEOBJECT_TYPE_GARRISON_PLOT)
            _garrisonPlots[gameObject->MapID][gameObject->Data[0]] = gameObject;

    for (GarrPlotBuildingEntry const* plotBuilding : sGarrPlotBuildingStore)
        _garrisonBuildingsByPlot[plotBuilding->GarrPlotID].insert(plotBuilding->GarrBuildingID);

    for (GarrBuildingPlotInstEntry const* buildingPlotInst : sGarrBuildingPlotInstStore)
        _garrisonBuildingPlotInstances[MAKE_PAIR64(buildingPlotInst->GarrBuildingID, buildingPlotInst->GarrSiteLevelPlotInstID)] = buildingPlotInst->ID;

    for (GarrBuildingEntry const* building : sGarrBuildingStore)
        _garrisonBuildingsByType[building->Type].push_back(building);

    for (GarrFollowerXAbilityEntry const* followerAbility : sGarrFollowerXAbilityStore)
    {
        if (GarrAbilityEntry const* ability = sGarrAbilityStore.LookupEntry(followerAbility->GarrAbilityID))
        {
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
}

GarrSiteLevelEntry const* GarrisonMgr::GetGarrSiteLevelEntry(uint32 garrSiteId, uint32 level) const
{
    for (GarrSiteLevelEntry const* garrSiteLevel : sGarrSiteLevelStore)
        if (garrSiteLevel->SiteID == garrSiteId && garrSiteLevel->Level == level)
            return garrSiteLevel;

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
    auto itr = _garrisonBuildingPlotInstances.find(MAKE_PAIR64(garrBuildingId, garrSiteLevelPlotInstId));
    if (itr != _garrisonBuildingPlotInstances.end())
        return itr->second;

    return 0;
}

GarrBuildingEntry const* GarrisonMgr::GetPreviousLevelBuilding(uint32 buildingType, uint32 currentLevel) const
{
    auto itr = _garrisonBuildingsByType.find(buildingType);
    if (itr != _garrisonBuildingsByType.end())
        for (GarrBuildingEntry const* building : itr->second)
            if (building->Level == currentLevel - 1)
                return building;

    return nullptr;
}

uint64 GarrisonMgr::GenerateFollowerDbId()
{
    if (_followerDbIdGenerator >= std::numeric_limits<uint64>::max())
    {
        TC_LOG_ERROR("misc", "Garrison follower db id oberflow! Can't continue, shutting down server. ");
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

std::list<uint32> GarrisonMgr::RollFollowerAbilities(GarrFollowerEntry const* follower, uint32 quality, uint32 faction, bool initial) const
{
    ASSERT(faction < 2);

    std::list<uint32> result;
    int32 slots[2] = { AbilitiesForQuality[quality][0], AbilitiesForQuality[quality][1] };

    GarrAbilities const* abilities = nullptr;
    auto itr = _garrisonFollowerAbilities[faction].find(follower->ID);
    if (itr != _garrisonFollowerAbilities[faction].end())
        abilities = &itr->second;

    std::list<uint32> abilityList, forcedAbilities, traitList, forcedTraits;
    if (abilities)
    {
        for (GarrAbilityEntry const* ability : abilities->Counters)
        {
            if (ability->Flags & GARRISON_ABILITY_HORDE_ONLY && faction != GARRISON_FACTION_INDEX_HORDE)
                continue;
            else if (ability->Flags & GARRISON_ABILITY_ALLIANCE_ONLY && faction != GARRISON_FACTION_INDEX_ALLIANCE)
                continue;

            if (ability->Flags & GARRISON_ABILITY_FLAG_CANNOT_REMOVE)
                forcedAbilities.push_back(ability->ID);
            else
                abilityList.push_back(ability->ID);
        }

        for (GarrAbilityEntry const* ability : abilities->Traits)
        {
            if (ability->Flags & GARRISON_ABILITY_HORDE_ONLY && faction != GARRISON_FACTION_INDEX_HORDE)
                continue;
            else if (ability->Flags & GARRISON_ABILITY_ALLIANCE_ONLY && faction != GARRISON_FACTION_INDEX_ALLIANCE)
                continue;

            if (ability->Flags & GARRISON_ABILITY_FLAG_CANNOT_REMOVE)
                forcedTraits.push_back(ability->ID);
            else
                traitList.push_back(ability->ID);
        }
    }

    Trinity::Containers::RandomResizeList(abilityList, std::max<int32>(0, slots[0] - forcedAbilities.size()));
    Trinity::Containers::RandomResizeList(traitList, std::max<int32>(0, slots[1] - forcedTraits.size()));

    // Add counters specified in GarrFollowerXAbility.db2 before generic classspec ones on follower creation
    if (initial)
    {
        forcedAbilities.splice(forcedAbilities.end(), abilityList);
        forcedTraits.splice(forcedTraits.end(), traitList);
    }

    if (slots[0] > forcedAbilities.size() + abilityList.size())
    {
        std::list<uint32> classSpecAbilities; // = GetDefaultClassSpecAbilities(follower, faction)

        abilityList.splice(abilityList.end(), classSpecAbilities);
        abilityList.sort();
        abilityList.unique();

        Trinity::Containers::RandomResizeList(abilityList, std::max<int32>(0, slots[0] - forcedAbilities.size()));
    }

    if (slots[1] > forcedTraits.size() + traitList.size())
    {
        std::list<uint32> genericTraits;
        for (GarrAbilityEntry const* ability : _garrisonFollowerRandomTraits)
        {
            if (ability->Flags & GARRISON_ABILITY_HORDE_ONLY && faction != GARRISON_FACTION_INDEX_HORDE)
                continue;
            else if (ability->Flags & GARRISON_ABILITY_ALLIANCE_ONLY && faction != GARRISON_FACTION_INDEX_ALLIANCE)
                continue;

            genericTraits.push_back(ability->ID);
        }

        traitList.splice(traitList.end(), genericTraits);
        traitList.sort();
        traitList.unique();

        Trinity::Containers::RandomResizeList(traitList, std::max<int32>(0, slots[1] - forcedTraits.size()));
    }

    result.splice(result.end(), forcedAbilities);
    result.splice(result.end(), abilityList);
    result.splice(result.end(), forcedTraits);
    result.splice(result.end(), traitList);

    return result;
}
