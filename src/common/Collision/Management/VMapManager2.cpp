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

#include "VMapManager2.h"
#include "Errors.h"
#include "Log.h"
#include "MapTree.h"
#include "ModelInstance.h"
#include "VMapDefinitions.h"
#include "WorldModel.h"
#include <G3D/Vector3.h>
#include <string>

using G3D::Vector3;

namespace VMAP
{
    class ManagedModel
    {
    public:
        explicit ManagedModel(VMapManager2& mgr, std::string const& name) : _mgr(mgr), _name(name) { }

        ~ManagedModel()
        {
            _mgr.releaseModelInstance(_name);
        }

        WorldModel Model;

    private:
        VMapManager2& _mgr;
        std::string const& _name;   // valid only while model is held in VMapManager2::iLoadedModelFiles
    };

    bool readChunk(FILE* rf, char* dest, const char* compare, uint32 len)
    {
        if (fread(dest, sizeof(char), len, rf) != len) return false;
        return memcmp(dest, compare, len) == 0;
    }

    VMapManager2::VMapManager2()
    {
        GetLiquidFlagsPtr = &GetLiquidFlagsDummy;
        IsVMAPDisabledForPtr = &IsVMAPDisabledForDummy;
        thread_safe_environment = true;
    }

    VMapManager2::~VMapManager2()
    {
        for (std::pair<uint32 const, StaticMapTree*>& iInstanceMapTree : iInstanceMapTrees)
            delete iInstanceMapTree.second;
    }

    InstanceTreeMap::const_iterator VMapManager2::GetMapTree(uint32 mapId) const
    {
        // return the iterator if found or end() if not found/NULL
        auto itr = iInstanceMapTrees.find(mapId);
        if (itr != iInstanceMapTrees.cend() && !itr->second)
            itr = iInstanceMapTrees.cend();

        return itr;
    }

    void VMapManager2::InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData)
    {
        // the caller must pass the list of all mapIds that will be used in the VMapManager2 lifetime
        for (std::pair<uint32 const, std::vector<uint32>> const& mapId : mapData)
        {
            iInstanceMapTrees.insert(InstanceTreeMap::value_type(mapId.first, nullptr));
            for (uint32 childMapId : mapId.second)
                iParentMapData[childMapId] = mapId.first;
        }

        thread_safe_environment = false;
    }

    Vector3 VMapManager2::convertPositionToInternalRep(float x, float y, float z) const
    {
        Vector3 pos;
        const float mid = 0.5f * 64.0f * 533.33333333f;
        pos.x = mid - x;
        pos.y = mid - y;
        pos.z = z;

        return pos;
    }

    // move to MapTree too?
    std::string VMapManager2::getMapFileName(unsigned int mapId)
    {
        return Trinity::StringFormat("{:04}/{:04}.vmtree", mapId, mapId);
    }

    LoadResult VMapManager2::loadMap(char const* basePath, unsigned int mapId, int x, int y)
    {
        if (!isMapLoadingEnabled())
            return LoadResult::DisabledInConfig;

        auto instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree == iInstanceMapTrees.end())
        {
            if (thread_safe_environment)
                instanceTree = iInstanceMapTrees.insert(InstanceTreeMap::value_type(mapId, nullptr)).first;
            else
                ABORT_MSG("Invalid mapId %u tile [%u, %u] passed to VMapManager2 after startup in thread unsafe environment",
                    mapId, x, y);
        }

        if (!instanceTree->second)
        {
            std::string mapFileName = getMapFileName(mapId);
            StaticMapTree* newTree = new StaticMapTree(mapId, basePath);
            LoadResult treeInitResult = newTree->InitMap(mapFileName);
            if (treeInitResult != LoadResult::Success)
            {
                delete newTree;
                return treeInitResult;
            }
            instanceTree->second = newTree;
        }

        return instanceTree->second->LoadMapTile(x, y, this);
    }

    void VMapManager2::unloadMap(unsigned int mapId, int x, int y)
    {
        auto instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree != iInstanceMapTrees.end() && instanceTree->second)
        {
            instanceTree->second->UnloadMapTile(x, y, this);
            if (instanceTree->second->numLoadedTiles() == 0)
            {
                delete instanceTree->second;
                instanceTree->second = nullptr;
            }
        }
    }

    void VMapManager2::unloadMap(unsigned int mapId)
    {
        auto instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree != iInstanceMapTrees.end() && instanceTree->second)
        {
            instanceTree->second->UnloadMap();
            if (instanceTree->second->numLoadedTiles() == 0)
            {
                delete instanceTree->second;
                instanceTree->second = nullptr;
            }
        }
    }

    bool VMapManager2::isInLineOfSight(unsigned int mapId, float x1, float y1, float z1, float x2, float y2, float z2, ModelIgnoreFlags ignoreFlags)
    {
        if (!isLineOfSightCalcEnabled() || IsVMAPDisabledForPtr(mapId, VMAP_DISABLE_LOS))
            return true;

        auto instanceTree = GetMapTree(mapId);
        if (instanceTree != iInstanceMapTrees.end())
        {
            Vector3 pos1 = convertPositionToInternalRep(x1, y1, z1);
            Vector3 pos2 = convertPositionToInternalRep(x2, y2, z2);
            if (pos1 != pos2)
                return instanceTree->second->isInLineOfSight(pos1, pos2, ignoreFlags);
        }

        return true;
    }

    /**
    get the hit position and return true if we hit something
    otherwise the result pos will be the dest pos
    */
    bool VMapManager2::getObjectHitPos(unsigned int mapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float modifyDist)
    {
        if (isLineOfSightCalcEnabled() && !IsVMAPDisabledForPtr(mapId, VMAP_DISABLE_LOS))
        {
            auto instanceTree = GetMapTree(mapId);
            if (instanceTree != iInstanceMapTrees.end())
            {
                Vector3 pos1 = convertPositionToInternalRep(x1, y1, z1);
                Vector3 pos2 = convertPositionToInternalRep(x2, y2, z2);
                Vector3 resultPos;
                bool result = instanceTree->second->getObjectHitPos(pos1, pos2, resultPos, modifyDist);
                resultPos = convertPositionToInternalRep(resultPos.x, resultPos.y, resultPos.z);
                rx = resultPos.x;
                ry = resultPos.y;
                rz = resultPos.z;
                return result;
            }
        }

        rx = x2;
        ry = y2;
        rz = z2;

        return false;
    }

    /**
    get height or INVALID_HEIGHT if no height available
    */

    float VMapManager2::getHeight(unsigned int mapId, float x, float y, float z, float maxSearchDist)
    {
        if (isHeightCalcEnabled() && !IsVMAPDisabledForPtr(mapId, VMAP_DISABLE_HEIGHT))
        {
            auto instanceTree = GetMapTree(mapId);
            if (instanceTree != iInstanceMapTrees.end())
            {
                Vector3 pos = convertPositionToInternalRep(x, y, z);
                float height = instanceTree->second->getHeight(pos, maxSearchDist);
                if (!(height < G3D::finf()))
                    return height = VMAP_INVALID_HEIGHT_VALUE; // No height

                return height;
            }
        }

        return VMAP_INVALID_HEIGHT_VALUE;
    }

    bool VMapManager2::getAreaAndLiquidData(unsigned int mapId, float x, float y, float z, Optional<uint8> reqLiquidType, AreaAndLiquidData& data) const
    {
        InstanceTreeMap::const_iterator instanceTree = GetMapTree(mapId);
        if (instanceTree != iInstanceMapTrees.end())
        {
            LocationInfo info;
            Vector3 pos = convertPositionToInternalRep(x, y, z);
            if (instanceTree->second->GetLocationInfo(pos, info))
            {
                data.floorZ = info.ground_Z;
                if (!IsVMAPDisabledForPtr(mapId, VMAP_DISABLE_LIQUIDSTATUS))
                {
                    uint32 liquidType = info.hitModel->GetLiquidType(); // entry from LiquidType.dbc
                    float liquidLevel;
                    if (!reqLiquidType || (GetLiquidFlagsPtr(liquidType) & *reqLiquidType))
                        if (info.hitInstance->GetLiquidLevel(pos, info, liquidLevel))
                            data.liquidInfo.emplace(liquidType, liquidLevel);
                }

                if (!IsVMAPDisabledForPtr(mapId, VMAP_DISABLE_AREAFLAG))
                    data.areaInfo.emplace(info.hitModel->GetWmoID(), info.hitInstance->adtId, info.rootId, info.hitModel->GetMogpFlags(), info.hitInstance->ID);

                return true;
            }
        }

        return false;
    }

    std::shared_ptr<WorldModel> VMapManager2::acquireModelInstance(std::string const& basepath, std::string const& filename)
    {
        std::shared_ptr<ManagedModel> worldmodel; // this is intentionally declared before lock so that it is destroyed after it to prevent deadlocks in releaseModelInstance

        //! Critical section, thread safe access to iLoadedModelFiles
        std::lock_guard<std::mutex> lock(LoadedModelFilesLock);

        auto& [key, model] = *iLoadedModelFiles.try_emplace(filename).first;
        worldmodel = model.lock();
        if (worldmodel)
            return std::shared_ptr<WorldModel>(worldmodel, &worldmodel->Model);

        worldmodel = std::make_shared<ManagedModel>(*this, key);
        if (!worldmodel->Model.readFile(basepath + filename + ".vmo"))
        {
            TC_LOG_ERROR("misc", "VMapManager2: could not load '{}{}.vmo'", basepath, filename);
            return nullptr;
        }
        TC_LOG_DEBUG("maps", "VMapManager2: loading file '{}{}'", basepath, filename);

        model = worldmodel;

        return std::shared_ptr<WorldModel>(worldmodel, &worldmodel->Model);
    }

    void VMapManager2::releaseModelInstance(std::string const& filename)
    {
        //! Critical section, thread safe access to iLoadedModelFiles
        std::lock_guard<std::mutex> lock(LoadedModelFilesLock);

        TC_LOG_DEBUG("maps", "VMapManager2: unloading file '{}'", filename);

        std::size_t erased = iLoadedModelFiles.erase(filename);
        if (!erased)
            TC_LOG_ERROR("misc", "VMapManager2: trying to unload non-loaded file '{}'", filename);
    }

    LoadResult VMapManager2::existsMap(char const* basePath, unsigned int mapId, int x, int y)
    {
        return StaticMapTree::CanLoadMap(std::string(basePath), mapId, x, y, this);
    }

    void VMapManager2::getInstanceMapTree(InstanceTreeMap &instanceMapTree)
    {
        instanceMapTree = iInstanceMapTrees;
    }

    int32 VMapManager2::getParentMapId(uint32 mapId) const
    {
        auto itr = iParentMapData.find(mapId);
        if (itr != iParentMapData.end())
            return int32(itr->second);

        return -1;
    }

} // namespace VMAP
