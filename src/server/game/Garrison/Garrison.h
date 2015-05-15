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

#ifndef Garrison_h__
#define Garrison_h__

#include "Player.h"
#include "GarrisonPackets.h"

enum GarrisonFactionIndex
{
    GARRISON_FACTION_INDEX_HORDE    = 0,
    GARRISON_FACTION_INDEX_ALLIANCE = 1
};

enum GarrisonBuildingFlags
{
    GARRISON_BUILDING_FLAG_NEEDS_PLAN   = 0x1
};

enum GarrisonError
{
    GARRISON_SUCCESS                        = 0,
    GARRISON_ERROR_INVALID_PLOT             = 1,
    GARRISON_ERROR_INVALID_BUILDINGID       = 2,
    GARRISON_ERROR_INVALID_PLOT_BUILDING    = 7,
    GARRISON_ERROR_NO_BUILDING              = 8,
    GARRISON_ERROR_SPECIALIZATION_KNOWN     = 19,
    GARRISON_ERROR_BLUEPRINT_KNOWN          = 21,
    GARRISON_ERROR_BLUEPRINT_NOT_KNOWN      = 22,
    GARRISON_ERROR_BUILDING_EXISTS          = 24,
    GARRISON_ERROR_NOT_ENOUGH_CURRENCY      = 46,
    GARRISON_ERROR_NOT_ENOUGH_GOLD          = 47
};

enum GarrisonFollowerStatus
{
    FOLLOWER_STATUS_FAVORITE    = 0x01,
    FOLLOWER_STATUS_EXHAUSTED   = 0x02,
    FOLLOWER_STATUS_INACTIVE    = 0x04
};

class GameObject;
class Map;

class Garrison
{
public:
    struct Building
    {
        bool CanActivate() const;

        ObjectGuid Guid;
        Optional<WorldPackets::Garrison::GarrisonBuildingInfo> PacketInfo;
    };

    struct Plot
    {
        GameObject* CreateGameObject(Map* map, GarrisonFactionIndex faction);
        void DeleteGameObject(Map* map);
        void ClearBuildingInfo(Player* owner);
        void SetBuildingInfo(WorldPackets::Garrison::GarrisonBuildingInfo const& buildingInfo, Player* owner);

        WorldPackets::Garrison::GarrisonPlotInfo PacketInfo;
        uint32 EmptyGameObjectId = 0;
        uint32 GarrSiteLevelPlotInstId = 0;
        Building BuildingInfo;
    };

    explicit Garrison(Player* owner);

    bool LoadFromDB(PreparedQueryResult garrison, PreparedQueryResult blueprints, PreparedQueryResult buildings);
    void SaveToDB(SQLTransaction& trans);

    bool Create(uint32 garrSiteId);
    void Upgrade();

    void Enter() const;
    void Leave() const;

    GarrisonFactionIndex GetFaction() const;
    std::vector<Plot*> GetPlots();
    Plot* GetPlot(uint32 garrPlotInstanceId);
    Plot const* GetPlot(uint32 garrPlotInstanceId) const;

    void LearnBlueprint(uint32 garrBuildingId);
    void UnlearnBlueprint(uint32 garrBuildingId);
    void PlaceBuilding(uint32 garrPlotInstanceId, uint32 garrBuildingId);
    void CancelBuildingConstruction(uint32 garrPlotInstanceId);

    void SendInfo();
    void SendRemoteInfo() const;
    void SendBlueprintAndSpecializationData();
    void SendBuildingLandmarks(Player* receiver) const;

    void ResetFollowerActivationLimit() { _followerActivationsRemainingToday = 1; }

private:
    Map* FindMap() const;
    void InitializePlots();
    GarrisonError CheckBuildingPlacement(uint32 garrPlotInstanceId, uint32 garrBuildingId) const;
    GarrisonError CheckBuildingRemoval(uint32 garrPlotInstanceId) const;
    Player* _owner;
    GarrSiteLevelEntry const* _siteLevel;
    uint32 _followerActivationsRemainingToday;

    std::unordered_map<uint32 /*garrPlotInstanceId*/, Plot> _plots;
    std::unordered_set<uint32 /*garrBuildingId*/> _knownBuildings;
};

#endif // Garrison_h__
