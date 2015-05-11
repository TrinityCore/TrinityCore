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

#ifndef GarrisonMgr_h__
#define GarrisonMgr_h__

#include <unordered_set>

#include "DB2Stores.h"

class GarrisonMgr
{
public:
    static GarrisonMgr& Instance()
    {
        static GarrisonMgr instance;
        return instance;
    }

    void Initialize();

    GarrSiteLevelEntry const* GetGarrSiteLevelEntry(uint32 garrSiteId, uint32 level) const;
    std::vector<GarrSiteLevelPlotInstEntry const*> const* GetGarrPlotInstForSiteLevel(uint32 garrSiteLevelId) const;
    GameObjectsEntry const* GetPlotGameObject(uint32 mapId, uint32 garrPlotInstanceId) const;
    bool IsPlotMatchingBuilding(uint32 garrPlotId, uint32 garrBuildingId) const;
    uint32 GetGarrBuildingPlotInst(uint32 garrBuildingId, uint32 garrSiteLevelPlotInstId) const;
    GarrBuildingEntry const* GetPreviousLevelBuilding(uint32 buildingType, uint32 currentLevel) const;

private:
    std::unordered_map<uint32 /*garrSiteId*/, std::vector<GarrSiteLevelPlotInstEntry const*>> _garrisonPlotInstBySiteLevel;
    std::unordered_map<uint32 /*mapId*/, std::unordered_map<uint32 /*garrPlotId*/, GameObjectsEntry const*>> _garrisonPlots;
    std::unordered_map<uint32 /*garrPlotId*/, std::unordered_set<uint32/*garrBuildingId*/>> _garrisonBuildingsByPlot;
    std::unordered_map<uint64 /*garrBuildingId | garrSiteLevelPlotInstId << 32*/, uint32 /*garrBuildingPlotInstId*/> _garrisonBuildingPlotInstances;
    std::unordered_map<uint32 /*buildingType*/, std::vector<GarrBuildingEntry const*>> _garrisonBuildingsByType;
};

#define sGarrisonMgr GarrisonMgr::Instance()

#endif // GarrisonMgr_h__
