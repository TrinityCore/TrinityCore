/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef WodGarrison_h__
#define WodGarrison_h__

#include "Player.h"
#include "GameObjectData.h"
#include "Garrison.h"

#define WOD_GARRISON_LEVEL_MAX 3

enum GarrisonBuildingFlags
{
    GARRISON_BUILDING_FLAG_NEEDS_PLAN = 0x1
};

class GameObject;
class Map;

// Garrison hearthstone teleport coords
static const Position GarrisonHearthstoneCoordinates[2][3] =
{
    {
        // Alliance
        { 1850.71f,   254.430f,  78.08300f, 1.76f   }, // Alliance Level 1
        { 1947.08f,   324.883f,  90.28076f, 0.00f   }, // Alliance Level 2
        { 1936.9f,    341.35f,   90.28f,    0.56f   }  // Alliance Level 3
    },
    {
        // Horde
        { 5561.15f,  4508.785f, 132.70000f, 3.406f  }, // Horde Level 1
        { 5565.86f,  4593.500f, 140.89300f, 0.000f  }, // Horde Level 2
        { 5563.70f,  4599.920f, 141.71100f, 0.000f  }, // Horde Level 3
    }
};

class TC_GAME_API WodGarrison : public Garrison
{
public:
    struct Building
    {
        bool CanActivate() const;

        ObjectGuid Guid;
        std::unordered_set<ObjectGuid> Spawns;
        Optional<WorldPackets::Garrison::GarrisonBuildingInfo> PacketInfo;
    };

    struct Plot
    {
        GameObject* CreateGameObject(Map* map, GarrisonFactionIndex faction);
        void DeleteGameObject(Map* map);
        void ClearBuildingInfo(Player* owner);
        void SetBuildingInfo(WorldPackets::Garrison::GarrisonBuildingInfo const& buildingInfo, Player* owner);

        WorldPackets::Garrison::GarrisonPlotInfo PacketInfo;
        QuaternionData Rotation;
        uint32 EmptyGameObjectId = 0;
        uint32 GarrSiteLevelPlotInstId = 0;
        Building BuildingInfo;
    };

    explicit WodGarrison(Player* owner);

    bool LoadFromDB() override;
    void SaveToDB(SQLTransaction& trans) override;

    bool Create(uint32 garrSiteId) override;
    bool CanUpgrade(bool checkCost = true);
    bool Upgrade();
    void TeleportOwnerAndPlayMovie() const;
    void Delete() override;

    void Enter() override;
    void Leave() override;

    bool IsAllowedArea(AreaTableEntry const* area) const override;

    // Plots
    std::vector<Plot*> GetPlots();
    Plot* GetPlot(uint32 garrPlotInstanceId);
    Plot const* GetPlot(uint32 garrPlotInstanceId) const;

    // Buildings
    void LearnBlueprint(uint32 garrBuildingId);
    void UnlearnBlueprint(uint32 garrBuildingId);
    void PlaceBuilding(uint32 garrPlotInstanceId, uint32 garrBuildingId);
    void CancelBuildingConstruction(uint32 garrPlotInstanceId);
    void ActivateBuilding(uint32 garrPlotInstanceId);
    std::unordered_set<uint32 /*garrBuildingId*/> const& GetKnownBuildings() const;

    void SendBuildingLandmarks(Player* receiver) const;

private:
    void InitializePlots();
    GarrisonError CheckBuildingPlacement(uint32 garrPlotInstanceId, uint32 garrBuildingId) const;
    GarrisonError CheckBuildingRemoval(uint32 garrPlotInstanceId) const;

    std::unordered_map<uint32 /*garrPlotInstanceId*/, Plot> _plots;
    std::unordered_set<uint32 /*garrBuildingId*/> _knownBuildings;
};

#endif // WodGarrison_h__
