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

#ifndef GarrisonMgr_h__
#define GarrisonMgr_h__

#include "Define.h"
#include "Hash.h"
#include "Position.h"
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct GameObjectsEntry;
struct GarrAbilityEntry;
struct GarrFollowerEntry;
struct GarrSiteLevelEntry;
struct GarrSiteLevelPlotInstEntry;

struct FinalizeGarrisonPlotGOInfo
{
    struct
    {
        uint32 GameObjectId;
        Position Pos;
        uint16 AnimKitId;
    } FactionInfo[2];
};

struct GarrAbilities
{
    std::unordered_set<GarrAbilityEntry const*> Counters;
    std::unordered_set<GarrAbilityEntry const*> Traits;
};

class TC_GAME_API GarrisonMgr
{
public:
    static GarrisonMgr& Instance();

    void Initialize();

    GarrSiteLevelEntry const* GetGarrSiteLevelEntry(uint32 garrSiteId, uint32 level) const;
    std::vector<GarrSiteLevelPlotInstEntry const*> const* GetGarrPlotInstForSiteLevel(uint32 garrSiteLevelId) const;
    GameObjectsEntry const* GetPlotGameObject(uint32 mapId, uint32 garrPlotInstanceId) const;
    bool IsPlotMatchingBuilding(uint32 garrPlotId, uint32 garrBuildingId) const;
    uint32 GetGarrBuildingPlotInst(uint32 garrBuildingId, uint32 garrSiteLevelPlotInstId) const;
    uint32 GetPreviousLevelBuildingId(uint32 buildingType, uint32 currentLevel) const;
    FinalizeGarrisonPlotGOInfo const* GetPlotFinalizeGOInfo(uint32 garrPlotInstanceID) const;
    uint64 GenerateFollowerDbId();
    std::list<GarrAbilityEntry const*> RollFollowerAbilities(uint32 garrFollowerId, GarrFollowerEntry const* follower, uint32 quality, uint32 faction, bool initial) const;
    std::list<GarrAbilityEntry const*> GetClassSpecAbilities(GarrFollowerEntry const* follower, uint32 faction) const;

private:
    void InitializeDbIdSequences();
    void LoadPlotFinalizeGOInfo();
    void LoadFollowerClassSpecAbilities();

    std::unordered_map<uint32 /*garrSiteId*/, std::vector<GarrSiteLevelPlotInstEntry const*>> _garrisonPlotInstBySiteLevel;
    std::unordered_map<uint32 /*mapId*/, std::unordered_map<uint32 /*garrPlotId*/, GameObjectsEntry const*>> _garrisonPlots;
    std::unordered_map<uint32 /*garrPlotId*/, std::unordered_set<uint32/*garrBuildingId*/>> _garrisonBuildingsByPlot;
    std::unordered_map<std::pair<uint32 /*garrBuildingId*/, uint32 /*garrSiteLevelPlotInstId*/>, uint32 /*garrBuildingPlotInstId*/> _garrisonBuildingPlotInstances;
    std::unordered_map<uint32 /*buildingType*/, std::vector<uint32>> _garrisonBuildingsByType;
    std::unordered_map<uint32 /*garrPlotInstanceId*/, FinalizeGarrisonPlotGOInfo> _finalizePlotGOInfo;
    std::unordered_map<uint32 /*garrFollowerId*/, GarrAbilities> _garrisonFollowerAbilities[2];
    std::unordered_map<uint32 /*classSpecId*/, std::list<GarrAbilityEntry const*>> _garrisonFollowerClassSpecAbilities;
    std::set<GarrAbilityEntry const*> _garrisonFollowerRandomTraits;

    uint64 _followerDbIdGenerator = UI64LIT(1);
};

#define sGarrisonMgr GarrisonMgr::Instance()

#endif // GarrisonMgr_h__
