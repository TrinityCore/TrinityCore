/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
            if (ability->GarrFollowerTypeID != FOLLOWER_TYPE_GARRISON && ability->GarrFollowerTypeID != FOLLOWER_TYPE_CLASS_HALL)
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

uint64 GarrisonMgr::GenerateMissionDbId()
{
    if (_missionDbIdGenerator >= std::numeric_limits<uint64>::max())
    {
        TC_LOG_ERROR("misc", "Garrison mission db id overflow! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }

    return _missionDbIdGenerator++;
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

uint32 GarrisonMgr::GetMissionSuccessChance(Garrison* /*garrison*/, uint32 /*missionId*/)
{
    uint32 winChance = 100;

    /*GarrMissionEntry const* l_MissionTemplate = sGarrMissionStore.LookupEntry(p_MissionRecID);

    std::vector<uint32>                     l_Encounters;
    std::vector<std::pair<uint32, uint32>>  l_EncoutersMechanics;
    std::vector<GarrisonFollower*>          l_MissionFollowers = GetMissionFollowers(p_MissionRecID);
    std::vector<uint32>                     l_PassiveEffects = GetBuildingsPassiveAbilityEffects();
    std::map<uint64, double>                l_FollowersBiasMap;
    std::vector<uint32>                     l_CounterAbilityUsed; 

    for (uint32 l_I = 0; l_I < sGarrMissionXEncouterStore.GetNumRows(); ++l_I)
    {
        GarrMissionXEncouterEntry const* l_Encounter = sGarrMissionXEncouterStore.LookupEntry(l_I);

        if (l_Encounter && l_Encounter->MissionID == p_MissionRecID)
            l_Encounters.push_back(l_Encounter->EncounterID);
    }

    for (uint32 l_I = 0; l_I < l_Encounters.size(); l_I++)
    {
        for (uint32 l_Y = 0; l_Y < sGarrEncouterXMechanicStore.GetNumRows(); ++l_Y)
        {
            GarrEncouterXMechanicEntry const* l_EncounterMechanic = sGarrEncouterXMechanicStore.LookupEntry(l_Y);

            if (l_EncounterMechanic && l_EncounterMechanic->EncounterID == l_Encounters[l_I])
                l_EncoutersMechanics.push_back(std::make_pair(l_Encounters[l_I], l_EncounterMechanic->MechanicID));
        }
    }

    for (uint32 l_Y = 0; l_Y < l_MissionFollowers.size(); ++l_Y)
    {
        double l_FollowerBias = (l_MissionFollowers[l_Y]->Level - l_MissionTemplate->RequiredLevel) * 0.33333334;

        if (l_MissionTemplate->RequiredLevel == Globals::MaxFollowerLevel)
        {
            if (l_MissionTemplate->RequiredItemLevel > 0)
            {
                uint32 l_TotalFollowerItemLevel = l_MissionFollowers[l_Y]->ItemLevelArmor + l_MissionFollowers[l_Y]->ItemLevelWeapon;
                l_FollowerBias = (((l_TotalFollowerItemLevel >> 1) - l_MissionTemplate->RequiredItemLevel) * 0.06666667) + l_FollowerBias;
            }
        }

        if (l_FollowerBias < -1.0)
            l_FollowerBias = -1.0;
        else if (l_FollowerBias > 1.0)
            l_FollowerBias = 1.0;

        l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] = l_FollowerBias;

        #ifdef GARRISON_CHEST_FORMULA_DEBUG
            printf("Follower %u bias %Lf\n", l_MissionFollowers[l_Y]->FollowerID, l_FollowerBias);
        #endif // GARRISON_CHEST_FORMULA_DEBUG
    }

    double l_Float8 = 100.0;
    double l_FloatC = 150.0;

    double l_V8 = l_MissionTemplate->RequiredFollowersCount * l_Float8;
    double l_V60 = l_MissionTemplate->RequiredFollowersCount * l_Float8;

    for (uint32 l_I = 0; l_I < l_EncoutersMechanics.size(); ++l_I)
    {
        GarrMechanicEntry     const* l_MechanicEntry     = sGarrMechanicStore.LookupEntry(l_EncoutersMechanics[l_I].second);
        GarrMechanicTypeEntry const* l_MechanicTypeEntry = sGarrMechanicTypeStore.LookupEntry(l_MechanicEntry->MechanicTypeID);

        if (l_MechanicTypeEntry && l_MechanicTypeEntry->Type != MechanicTypes::Ability)
        {
            l_V8 = l_V60;
        }
        else
        {
            l_V8  = l_MechanicEntry->Unk2 + l_V60;
            l_V60 = l_MechanicEntry->Unk2 + l_V60;
        }
    }

    double l_CurrentAdditionalWinChance = 0;

    double l_V11 = 100.0 / l_V8;
    double l_V62 = 100.0 / l_V8;

    /// OK 100%
    #pragma region Followers Bias
    for (uint32 l_Y = 0; l_Y < l_MissionFollowers.size(); ++l_Y)
    {
        double l_Seil = 0;

        if (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] >= 0.0)
            l_Seil = (l_FloatC - l_Float8) * l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + l_Float8;
        else
            l_Seil = (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + 1.0) * l_Float8;

        l_V8 = (l_Seil * l_V11) + l_CurrentAdditionalWinChance; ///< l_V8 is never read 01/18/16
        l_CurrentAdditionalWinChance = (l_Seil * l_V11) + l_CurrentAdditionalWinChance;

        #ifdef GARRISON_CHEST_FORMULA_DEBUG
            printf("Added %.2f to success due to follower %u bias.\n", (l_Seil * l_V11), l_MissionFollowers[l_Y]->FollowerID);
        #endif // GARRISON_CHEST_FORMULA_DEBUG
    }
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// OK 100%
    #pragma region Counter mechanic
    for (uint32 l_I = 0; l_I < l_EncoutersMechanics.size(); ++l_I)
    {
        GarrMechanicEntry     const* l_MechanicEntry     = sGarrMechanicStore.LookupEntry(l_EncoutersMechanics[l_I].second);
        GarrMechanicTypeEntry const* l_MechanicTypeEntry = sGarrMechanicTypeStore.LookupEntry(l_MechanicEntry->MechanicTypeID);

        if (l_MechanicTypeEntry->Type == MechanicTypes::Ability)
        {
            double l_Unk1 = l_MechanicEntry->Unk2; ///< l_Unk1 is never read 01/18/16
            double l_Unk2 = l_MechanicEntry->Unk2;

            if (l_MissionFollowers.size() > 0)
            {
                for (uint32 l_Y = 0; l_Y < l_MissionFollowers.size(); ++l_Y)
                {
                    for (uint32 l_Z = 0; l_Z < l_MissionFollowers[l_Y]->Abilities.size(); l_Z++)
                    {
                        uint32 l_CurrentAbilityID = l_MissionFollowers[l_Y]->Abilities[l_Z];

                        for (uint32 l_EffectI = 0; l_EffectI < sGarrAbilityEffectStore.GetNumRows(); l_EffectI++)
                        {
                            GarrAbilityEffectEntry const* l_AbilityEffectEntry = sGarrAbilityEffectStore.LookupEntry(l_EffectI);

                            if (!l_AbilityEffectEntry || l_AbilityEffectEntry->AbilityID != l_CurrentAbilityID)
                                continue;

                            if (l_AbilityEffectEntry->CounterMechanicTypeID == l_MechanicTypeEntry->ID && !(l_AbilityEffectEntry->Unk3 & 1))
                            {
                                l_Unk1 = l_Unk2; ///< l_Unk1 is never read 01/18/16
                                if (l_Unk2 != 0.0)
                                {
                                    float l_Seil = 0;

                                    if (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] >= 0.0)
                                        l_Seil = (l_AbilityEffectEntry->ModMax - l_AbilityEffectEntry->ModMin) * l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + l_AbilityEffectEntry->ModMin;
                                    else
                                        l_Seil = (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + 1.0) * l_AbilityEffectEntry->ModMin;

                                    l_Unk1 = l_MechanicEntry->Unk2;

                                    if (l_Seil <= l_Unk1)
                                        l_Unk1 = l_Seil;

                                    l_Unk2 = l_Unk2 - l_Unk1;
                                }
                            }
                        }
                    }
                }
            }

            if (l_Unk2 < 0.0)
                l_Unk2 = 0.0;

            l_Unk1 = l_MechanicEntry->Unk2;
            l_Unk1 = (l_Unk1 - l_Unk2) * l_V62;
            l_CurrentAdditionalWinChance = l_Unk1 + l_CurrentAdditionalWinChance;

            #ifdef GARRISON_CHEST_FORMULA_DEBUG
                printf("Added %.2f to success due to followers countering boss mechanic %u.\n", l_Unk1, l_EncoutersMechanics[l_I].second);
            #endif // GARRISON_CHEST_FORMULA_DEBUG
        }
    }
    #pragma endregion

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// UNTESTED
    #pragma region Race Ability Counter
    for (uint32 l_I = 0; l_I < l_EncoutersMechanics.size(); ++l_I)
    {
        GarrMechanicEntry     const* l_MechanicEntry     = sGarrMechanicStore.LookupEntry(l_EncoutersMechanics[l_I].second);
        GarrMechanicTypeEntry const* l_MechanicTypeEntry = sGarrMechanicTypeStore.LookupEntry(l_MechanicEntry->MechanicTypeID);

        if (l_MechanicTypeEntry->Type == MechanicTypes::Racial)
        {
            for (uint32 l_Y = 0; l_Y < l_MissionFollowers.size(); ++l_Y)
            {
                for (uint32 l_Z = 0; l_Z < l_MissionFollowers[l_Y]->Abilities.size(); l_Z++)
                {
                    uint32 l_CurrentAbilityID = l_MissionFollowers[l_Y]->Abilities[l_Z];

                    for (uint32 l_EffectI = 0; l_EffectI < sGarrAbilityEffectStore.GetNumRows(); l_EffectI++)
                    {
                        GarrAbilityEffectEntry const* l_AbilityEffectEntry = sGarrAbilityEffectStore.LookupEntry(l_EffectI);

                        if (!l_AbilityEffectEntry || l_AbilityEffectEntry->AbilityID != l_CurrentAbilityID)
                            continue;

                        if (l_AbilityEffectEntry->CounterMechanicTypeID == l_MissionTemplate->GarrMechanicTypeRecID)
                        {
                            double l_Seil = 0;

                            if (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] >= 0.0)
                                l_Seil = (l_AbilityEffectEntry->ModMax - l_AbilityEffectEntry->ModMin) * l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + l_AbilityEffectEntry->ModMin;
                            else
                                l_Seil = (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + 1.0) * l_AbilityEffectEntry->ModMin;

                            l_CurrentAdditionalWinChance = (l_Seil * l_V62) + l_CurrentAdditionalWinChance;

                            #ifdef GARRISON_CHEST_FORMULA_DEBUG
                                printf("Added %.2f to success due to follower %u enemy race ability %d.\n", (l_Seil * l_V62), 0, l_CurrentAbilityID);
                            #endif // GARRISON_CHEST_FORMULA_DEBUG
                        }
                    }
                }
            }
        }
    }
    #pragma endregion 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// OK 100%
    #pragma region Environment Ability
    for (uint32 l_Y = 0; l_Y < l_MissionFollowers.size(); ++l_Y)
    {
        for (uint32 l_Z = 0; l_Z < l_MissionFollowers[l_Y]->Abilities.size(); l_Z++)
        {
            uint32 l_CurrentAbilityID = l_MissionFollowers[l_Y]->Abilities[l_Z];

            for (uint32 l_EffectI = 0; l_EffectI < sGarrAbilityEffectStore.GetNumRows(); l_EffectI++)
            {
                GarrAbilityEffectEntry const* l_AbilityEffectEntry = sGarrAbilityEffectStore.LookupEntry(l_EffectI);

                if (!l_AbilityEffectEntry || l_AbilityEffectEntry->AbilityID != l_CurrentAbilityID)
                    continue;

                if (l_AbilityEffectEntry->CounterMechanicTypeID == l_MissionTemplate->GarrMechanicTypeRecID)
                {
                    double l_Seil = 0;

                    if (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] >= 0.0)
                        l_Seil = (l_AbilityEffectEntry->ModMax - l_AbilityEffectEntry->ModMin) * l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + l_AbilityEffectEntry->ModMin;
                    else
                        l_Seil = (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + 1.0) * l_AbilityEffectEntry->ModMin;

                    l_CurrentAdditionalWinChance = (l_Seil * l_V62) + l_CurrentAdditionalWinChance;

                    #ifdef GARRISON_CHEST_FORMULA_DEBUG
                        printf("Added %.2f to success due to follower %u environment ability %u.\n", (l_Seil * l_V62), l_MissionFollowers[l_Y]->FollowerID, l_CurrentAbilityID);
                    #endif // GARRISON_CHEST_FORMULA_DEBUG
                }
            }
        }
    }
    #pragma endregion 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// OK 100%
    #pragma region Follower Trait
    double l_MissionDuration = GetMissionDuration(p_MissionRecID);
    double l_MissionTravelTime = GetMissionTravelDuration(p_MissionRecID);

    for (uint32 l_Y = 0; l_Y < l_MissionFollowers.size(); ++l_Y)
    {
        for (uint32 l_Z = 0; l_Z < l_MissionFollowers[l_Y]->Abilities.size(); l_Z++)
        {
            uint32 l_CurrentAbilityID = l_MissionFollowers[l_Y]->Abilities[l_Z];

            for (uint32 l_EffectI = 0; l_EffectI < sGarrAbilityEffectStore.GetNumRows(); l_EffectI++)
            {
                GarrAbilityEffectEntry const* l_AbilityEffectEntry = sGarrAbilityEffectStore.LookupEntry(l_EffectI);

                if (!l_AbilityEffectEntry || l_AbilityEffectEntry->AbilityID != l_CurrentAbilityID)
                    continue;

                bool l_Proc = false;

                switch (l_AbilityEffectEntry->EffectType)
                {
                    /// Proc if MissionFollowerCount == 1
                    case AbilityEffectTypes::ModWinRateSolo:
                        l_Proc = l_MissionFollowers.size() == 1;
                        break;

                    /// Proc every time, no condition
                    case AbilityEffectTypes::ModWinRate:
                        l_Proc = true;
                        break;

                    /// Proc if Find(MissionFollowers[Class], MiscValueA) != NULL
                    case AbilityEffectTypes::ModWinRateClass:
                        for (uint32 l_W = 0; l_W < l_MissionFollowers.size(); ++l_W)
                        {
                            if (l_W != l_Y)
                            {
                                GarrFollowerEntry const* l_FollowerTemplate = sGarrFollowerStore.LookupEntry(l_MissionFollowers[l_W]->FollowerID);

                                if (l_FollowerTemplate && l_FollowerTemplate->CreatureID[GetGarrisonFactionIndex()] == l_AbilityEffectEntry->MiscValueA)
                                {
                                    l_Proc = true;
                                    break;
                                }
                            }
                        }
                        break;

                    /// Proc if Duration > (3600 * MiscValueB)
                    case AbilityEffectTypes::ModWinRateDurationMore:
                        l_Proc = l_MissionDuration > (3600 * l_AbilityEffectEntry->MiscValueB);
                        break;

                    /// Proc if Duration < (3600 * MiscValueB)
                    case AbilityEffectTypes::ModWinRateDurationLess:
                        l_Proc = l_MissionDuration < (3600 * l_AbilityEffectEntry->MiscValueB);
                        break;

                    /// Proc if TravelDuration > (3600 * MiscValueB)
                    case AbilityEffectTypes::ModWinRateTravelDurationMore:
                        l_Proc = l_MissionTravelTime > (3600 * l_AbilityEffectEntry->MiscValueB);
                        break;

                    /// Proc if TravelDuration < (3600 * MiscValueB)
                    case AbilityEffectTypes::ModWinRateTravelDurationLess:
                        l_Proc = l_MissionTravelTime < (3600 * l_AbilityEffectEntry->MiscValueB);
                        break;

                    case AbilityEffectTypes::ModUnk0:
                    case AbilityEffectTypes::ModTravelTime:
                    case AbilityEffectTypes::ModXpGain:
                    case AbilityEffectTypes::ModGarrCurrencyDrop:
                    case AbilityEffectTypes::ModUnk11:
                    case AbilityEffectTypes::ModDummyProduction:
                    case AbilityEffectTypes::ModBronzeTreasureDrop:
                    case AbilityEffectTypes::ModSilverTreasureDrop:
                    case AbilityEffectTypes::ModGoldTreasureDrop:
                    case AbilityEffectTypes::ModChestDropRate:
                    case AbilityEffectTypes::ModMissionDuration:
                        break;

                    default:
                        break;

                }

                if (!l_Proc)
                    break;

                double l_Seil = 0.0;

                if (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] >= 0.0)
                    l_Seil = (l_AbilityEffectEntry->ModMax - l_AbilityEffectEntry->ModMin) * l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + l_AbilityEffectEntry->ModMin;
                else
                    l_Seil = (l_FollowersBiasMap[l_MissionFollowers[l_Y]->DatabaseID] + 1.0) * l_AbilityEffectEntry->ModMin;

                l_CurrentAdditionalWinChance = (l_Seil * l_V62) + l_CurrentAdditionalWinChance;

                #ifdef GARRISON_CHEST_FORMULA_DEBUG
                    printf("Added %.2f to success due to follower %u trait %u.\n", (l_Seil * l_V62), l_MissionFollowers[l_Y]->FollowerID, l_AbilityEffectEntry->EffectType);
                #endif // GARRISON_CHEST_FORMULA_DEBUG
            }
        }
    }
    #pragma endregion 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /// UNTESTED
    #pragma region Passive Effect
    for (uint32 l_Y = 0; l_Y < l_PassiveEffects.size(); ++l_Y)
    {
        GarrAbilityEffectEntry const* l_AbilityEffectEntry = sGarrAbilityEffectStore.LookupEntry(l_PassiveEffects[l_Y]);

        if (!l_AbilityEffectEntry)
            continue;

        if (l_AbilityEffectEntry->EffectType == AbilityEffectTypes::ModWinRate)
        {
            l_CurrentAdditionalWinChance = (l_AbilityEffectEntry->ModMin * l_V62) + l_CurrentAdditionalWinChance;

            #ifdef GARRISON_CHEST_FORMULA_DEBUG
                printf("Added %.2f to success due to passive effect %u.\n", l_AbilityEffectEntry->ModMin * l_V62, l_AbilityEffectEntry->AbilityID);
            #endif // GARRISON_CHEST_FORMULA_DEBUG
        }
    }
    #pragma endregion 

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    l_CurrentAdditionalWinChance = (((100.0 - l_MissionTemplate->BaseBonusChance) * l_CurrentAdditionalWinChance) * 0.0099999998) + l_MissionTemplate->BaseBonusChance;

    if (l_CurrentAdditionalWinChance > 100.0)
        l_CurrentAdditionalWinChance = 100.0;

    #ifdef GARRISON_CHEST_FORMULA_DEBUG
        printf("Total success chance: %.2f.\n", l_CurrentAdditionalWinChance);
    #endif // GARRISON_CHEST_FORMULA_DEBUG*/

    return winChance;
}

uint32 GarrisonMgr::GetClassByMissionType(uint32 missionType)
{
    switch (missionType)
    {
        case GarrisonMission::Type::ArtifactMonk:           return CLASS_MONK;
        case GarrisonMission::Type::ArtifactShaman:         return CLASS_SHAMAN;
        case GarrisonMission::Type::ArtifactDruid:          return CLASS_DRUID;
        case GarrisonMission::Type::ArtifactMage:           return CLASS_MAGE;
        case GarrisonMission::Type::ArtifactHunter:         return CLASS_HUNTER;
        case GarrisonMission::Type::ArtifactPaladin:        return CLASS_PALADIN;
        case GarrisonMission::Type::ArtifactWarlock:        return CLASS_WARLOCK;
        case GarrisonMission::Type::ArtifactDemonHunter:    return CLASS_DEMON_HUNTER;
        case GarrisonMission::Type::ArtifactRogue:          return CLASS_ROGUE;
        case GarrisonMission::Type::ArtifactPriest:         return CLASS_PRIEST;
        case GarrisonMission::Type::ArtifactDeathKnight:    return CLASS_DEATH_KNIGHT;
        case GarrisonMission::Type::ArtifactWarrior:        return CLASS_WARRIOR;
        default:
            return CLASS_NONE;
    }
}

uint32 GarrisonMgr::GetFactionByMissionType(uint32 missionType)
{
    switch (missionType)
    {
        case GarrisonMission::Type::ZoneSupportAlliance:    return TEAM_ALLIANCE;
        case GarrisonMission::Type::ZoneSupportHorde:       return TEAM_HORDE;
        default:
            return TEAM_OTHER;
    }
}

void GarrisonMgr::InitializeDbIdSequences()
{
    if (QueryResult result = CharacterDatabase.Query("SELECT MAX(dbId) FROM character_garrison_followers"))
        _followerDbIdGenerator = (*result)[0].GetUInt64() + 1;

    if (QueryResult result = CharacterDatabase.Query("SELECT MAX(dbId) FROM character_garrison_missions"))
        _missionDbIdGenerator = (*result)[0].GetUInt64() + 1;
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
