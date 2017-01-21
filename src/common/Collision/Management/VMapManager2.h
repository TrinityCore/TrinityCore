/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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

#ifndef _VMAPMANAGER2_H
#define _VMAPMANAGER2_H

#include <mutex>
#include <unordered_map>
#include <vector>
#include "Define.h"
#include "IVMapManager.h"

//===========================================================

#define MAP_FILENAME_EXTENSION2 ".vmtree"

#define FILENAMEBUFFER_SIZE 500

/**
This is the main Class to manage loading and unloading of maps, line of sight, height calculation and so on.
For each map or map tile to load it reads a directory file that contains the ModelContainer files used by this map or map tile.
Each global map or instance has its own dynamic BSP-Tree.
The loaded ModelContainers are included in one of these BSP-Trees.
Additionally a table to match map ids and map names is used.
*/

//===========================================================

namespace G3D
{
    class Vector3;
}

namespace VMAP
{
    class StaticMapTree;
    class WorldModel;

    class TC_COMMON_API ManagedModel
    {
        public:
            ManagedModel() : iModel(nullptr), iRefCount(0) { }
            void setModel(WorldModel* model) { iModel = model; }
            WorldModel* getModel() { return iModel; }
            void incRefCount() { ++iRefCount; }
            int decRefCount() { return --iRefCount; }
        protected:
            WorldModel* iModel;
            int iRefCount;
    };

    typedef std::unordered_map<uint32, StaticMapTree*> InstanceTreeMap;
    typedef std::unordered_map<std::string, ManagedModel> ModelFileMap;

    enum DisableTypes
    {
        VMAP_DISABLE_AREAFLAG       = 0x1,
        VMAP_DISABLE_HEIGHT         = 0x2,
        VMAP_DISABLE_LOS            = 0x4,
        VMAP_DISABLE_LIQUIDSTATUS   = 0x8
    };

    class TC_COMMON_API VMapManager2 : public IVMapManager
    {
        protected:
            // Tree to check collision
            ModelFileMap iLoadedModelFiles;
            InstanceTreeMap iInstanceMapTrees;
            std::unordered_map<uint32, std::vector<uint32>> iChildMapData;
            std::unordered_map<uint32, uint32> iParentMapData;
            bool thread_safe_environment;
            // Mutex for iLoadedModelFiles
            std::mutex LoadedModelFilesLock;

            static uint32 GetLiquidFlagsDummy(uint32) { return 0; }
            static bool IsVMAPDisabledForDummy(uint32 /*entry*/, uint8 /*flags*/) { return false; }

            InstanceTreeMap::const_iterator GetMapTree(uint32 mapId) const;

        public:
            // public for debug
            G3D::Vector3 convertPositionToInternalRep(float x, float y, float z) const;
            static std::string getMapFileName(unsigned int mapId);

            VMapManager2();
            ~VMapManager2();

            void InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData);

            int loadMap(const char* pBasePath, unsigned int mapId, int x, int y) override;
            bool loadSingleMap(uint32 mapId, const std::string& basePath, uint32 tileX, uint32 tileY);

            void unloadMap(unsigned int mapId, int x, int y) override;
            void unloadSingleMap(uint32 mapId, int x, int y);

            void unloadMap(unsigned int mapId) override;
            void unloadSingleMap(uint32 mapId);

            bool isInLineOfSight(unsigned int mapId, float x1, float y1, float z1, float x2, float y2, float z2, ModelIgnoreFlags ignoreFlags) override ;
            /**
            fill the hit pos and return true, if an object was hit
            */
            bool getObjectHitPos(unsigned int mapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float& ry, float& rz, float modifyDist) override;
            float getHeight(unsigned int mapId, float x, float y, float z, float maxSearchDist) override;

            bool processCommand(char* /*command*/) override { return false; } // for debug and extensions

            bool getAreaInfo(unsigned int pMapId, float x, float y, float& z, uint32& flags, int32& adtId, int32& rootId, int32& groupId) const override;
            bool GetLiquidLevel(uint32 pMapId, float x, float y, float z, uint8 reqLiquidType, float& level, float& floor, uint32& type) const override;

            WorldModel* acquireModelInstance(const std::string& basepath, const std::string& filename, uint32 flags = 0);
            void releaseModelInstance(const std::string& filename);

            // what's the use of this? o.O
            virtual std::string getDirFileName(unsigned int mapId, int /*x*/, int /*y*/) const override
            {
                return getMapFileName(mapId);
            }
            virtual bool existsMap(const char* basePath, unsigned int mapId, int x, int y) override;

            void getInstanceMapTree(InstanceTreeMap &instanceMapTree);

            int32 getParentMapId(uint32 mapId) const;

            typedef uint32(*GetLiquidFlagsFn)(uint32 liquidType);
            GetLiquidFlagsFn GetLiquidFlagsPtr;

            typedef bool(*IsVMAPDisabledForFn)(uint32 entry, uint8 flags);
            IsVMAPDisabledForFn IsVMAPDisabledForPtr;
    };
}

#endif
