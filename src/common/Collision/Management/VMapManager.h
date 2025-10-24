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

#ifndef TRINITYCORE_VMAP_MANAGER2_H
#define TRINITYCORE_VMAP_MANAGER2_H

#include "Define.h"
#include "ModelIgnoreFlags.h"
#include "Optional.h"
#include <memory>
#include <mutex>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

//===========================================================

/**
This is the main Class to manage loading and unloading of maps, line of sight, height calculation and so on.
For each map or map tile to load it reads a directory file that contains the ModelContainer files used by this map or map tile.
Each global map or instance has its own dynamic BSP-Tree.
The loaded ModelContainers are included in one of these BSP-Trees.
Additionally a table to match map ids and map names is used.
*/

//===========================================================

namespace VMAP
{
    class ManagedModel;
    class ModelInstance;
    class StaticMapTree;
    class WorldModel;

    typedef std::unordered_map<uint32, std::unique_ptr<StaticMapTree>> InstanceTreeMap;
    typedef std::unordered_map<std::string, std::weak_ptr<ManagedModel>> ModelFileMap;

    enum DisableTypes : uint8
    {
        VMAP_DISABLE_AREAFLAG       = 0x1,
        VMAP_DISABLE_HEIGHT         = 0x2,
        VMAP_DISABLE_LOS            = 0x4,
        VMAP_DISABLE_LIQUIDSTATUS   = 0x8
    };

    enum class LoadResult : uint8
    {
        Success,
        FileNotFound,
        VersionMismatch,
        ReadFromFileFailed,
        DisabledInConfig
    };

    #define VMAP_INVALID_HEIGHT       -100000.0f            // for check
    #define VMAP_INVALID_HEIGHT_VALUE -200000.0f            // real assigned value in unknown height case

    struct AreaAndLiquidData
    {
        struct AreaInfo
        {
            AreaInfo() = default;
            AreaInfo(int32 _groupId, int32 _adtId, int32 _rootId, uint32 _mogpFlags, uint32 _uniqueId)
                : groupId(_groupId), adtId(_adtId), rootId(_rootId), mogpFlags(_mogpFlags), uniqueId(_uniqueId) { }
            int32 groupId = 0;
            int32 adtId = 0;
            int32 rootId = 0;
            uint32 mogpFlags = 0;
            uint32 uniqueId = 0;
        };
        struct LiquidInfo
        {
            LiquidInfo() = default;
            LiquidInfo(uint32 _type, float _level) : type(_type), level(_level) { }
            uint32 type = 0;
            float level = 0.0f;
        };

        float floorZ = VMAP_INVALID_HEIGHT;
        Optional<AreaInfo> areaInfo;
        Optional<LiquidInfo> liquidInfo;
    };

    class TC_COMMON_API VMapManager
    {
        protected:
            bool iEnableLineOfSightCalc;
            bool iEnableHeightCalc;
            bool thread_safe_environment;
            // Tree to check collision
            ModelFileMap iLoadedModelFiles;
            InstanceTreeMap iInstanceMapTrees;
            std::unordered_map<uint32, uint32> iParentMapData;
            // Mutex for iLoadedModelFiles
            std::mutex LoadedModelFilesLock;

            InstanceTreeMap::const_iterator GetMapTree(uint32 mapId) const;

        public:
            // public for debug
            static std::string getMapFileName(uint32 mapId);
            static std::string getTileFileName(uint32 mapID, uint32 tileX, uint32 tileY, std::string_view extension);

            VMapManager();

            VMapManager(VMapManager const&) = delete;
            VMapManager(VMapManager&&) = delete;

            VMapManager& operator=(VMapManager const&) = delete;
            VMapManager& operator=(VMapManager&&) = delete;

            ~VMapManager();

            void InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData);
            void InitializeThreadUnsafe(uint32 mapId, int32 parentMapId);
            /**
                Enable/disable LOS calculation
                It is enabled by default. If it is enabled in mid game the maps have to loaded manualy
            */
            void setEnableLineOfSightCalc(bool enableLineOfSightCalc) { iEnableLineOfSightCalc = enableLineOfSightCalc; }

            /**
                Enable/disable model height calculation
                It is enabled by default. If it is enabled in mid game the maps have to loaded manualy
            */
            void setEnableHeightCalc(bool enableHeightCalc) { iEnableHeightCalc = enableHeightCalc; }

            bool isLineOfSightCalcEnabled() const { return iEnableLineOfSightCalc; }
            bool isHeightCalcEnabled() const { return iEnableHeightCalc; }
            bool isMapLoadingEnabled() const { return iEnableLineOfSightCalc || iEnableHeightCalc; }

            LoadResult loadMap(std::string const& basePath, uint32 mapId, uint32 x, uint32 y);

            void unloadMap(uint32 mapId, uint32 x, uint32 y);

            void unloadMap(uint32 mapId);

            bool isInLineOfSight(uint32 mapId, float x1, float y1, float z1, float x2, float y2, float z2, ModelIgnoreFlags ignoreFlags);
            /**
                test if we hit an object. return true if we hit one. rx, ry, rz will hold the hit position or the dest position, if no intersection was found
                return a position, that is modifyDist closer to the origin
            */
            bool getObjectHitPos(uint32 mapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float& ry, float& rz, float modifyDist);
            float getHeight(uint32 mapId, float x, float y, float z, float maxSearchDist);

            /**
                Query world model area info.
            */
            bool getAreaAndLiquidData(uint32 mapId, float x, float y, float z, Optional<uint8> reqLiquidType, AreaAndLiquidData& data) const;

            std::shared_ptr<WorldModel> acquireModelInstance(std::string const& basepath, std::string const& filename);
            void releaseModelInstance(std::string const& filename);

            // what's the use of this? o.O
            static std::string getDirFileName(uint32 mapId, uint32 x, uint32 y)
            {
                return getTileFileName(mapId, x, y, "vmtile");
            }
            LoadResult existsMap(std::string const& basePath, uint32 mapId, uint32 x, uint32 y);

            std::span<ModelInstance const> getModelsOnMap(uint32 mapId) const;

            int32 getParentMapId(uint32 mapId) const;

            typedef uint32(*GetLiquidFlagsFn)(uint32 liquidType);
            GetLiquidFlagsFn GetLiquidFlagsPtr;

            typedef bool(*IsVMAPDisabledForFn)(uint32 entry, uint8 flags);
            IsVMAPDisabledForFn IsVMAPDisabledForPtr;
    };
}

#endif // TRINITYCORE_VMAP_MANAGER2_H
