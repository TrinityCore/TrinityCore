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

#include "MapTree.h"
#include "Errors.h"
#include "Log.h"
#include "Memory.h"
#include "Metric.h"
#include "ModelInstance.h"
#include "VMapDefinitions.h"
#include "VMapManager2.h"
#include "WorldModel.h"
#include <limits>
#include <string>

using G3D::Vector3;

namespace VMAP
{
    class MapRayCallback
    {
        public:
            MapRayCallback(ModelInstance const* val, ModelIgnoreFlags ignoreFlags) : prims(val), hit(false), flags(ignoreFlags) { }
            bool operator()(const G3D::Ray& ray, uint32 entry, float& distance, bool pStopAtFirstHit = true)
            {
                bool result = prims[entry].intersectRay(ray, distance, pStopAtFirstHit, flags);
                if (result)
                    hit = true;
                return result;
            }
            bool didHit() { return hit; }
        protected:
            ModelInstance const* prims;
            bool hit;
            ModelIgnoreFlags flags;
    };

    class LocationInfoCallback
    {
        public:
            LocationInfoCallback(ModelInstance const* val, LocationInfo& info) : prims(val), locInfo(info), result(false) { }
            void operator()(Vector3 const& point, uint32 entry)
            {
#ifdef VMAP_DEBUG
                TC_LOG_DEBUG("maps", "LocationInfoCallback: trying to intersect '{}'", prims[entry].name);
#endif
                if (prims[entry].GetLocationInfo(point, locInfo))
                    result = true;
            }

            ModelInstance const* prims;
            LocationInfo& locInfo;
            bool result;
    };

    //=========================================================

    std::string getTileFileName(uint32 mapID, uint32 tileX, uint32 tileY, std::string_view extension)
    {
        return Trinity::StringFormat("{:04}_{:02}_{:02}.{}", mapID, tileY, tileX, extension);
    }

    bool StaticMapTree::GetLocationInfo(Vector3 const& pos, LocationInfo& info) const
    {
        LocationInfoCallback intersectionCallBack(iTreeValues.data(), info);
        iTree.intersectPoint(pos, intersectionCallBack);
        return intersectionCallBack.result;
    }

    StaticMapTree::StaticMapTree(uint32 mapID, std::string const& basePath)
        : iMapID(mapID), iBasePath(basePath)
    {
        if (iBasePath.length() > 0 && iBasePath[iBasePath.length() - 1] != '/' && iBasePath[iBasePath.length() - 1] != '\\')
        {
            iBasePath.push_back('/');
        }
    }

    //=========================================================
    //! Make sure to call unloadMap() to unregister acquired model references before destroying
    StaticMapTree::~StaticMapTree() = default;

    //=========================================================
    /**
    If intersection is found within pMaxDist, sets pMaxDist to intersection distance and returns true.
    Else, pMaxDist is not modified and returns false;
    */

    bool StaticMapTree::getIntersectionTime(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit, ModelIgnoreFlags ignoreFlags) const
    {
        float distance = pMaxDist;
        MapRayCallback intersectionCallBack(iTreeValues.data(), ignoreFlags);
        iTree.intersectRay(pRay, intersectionCallBack, distance, pStopAtFirstHit);
        if (intersectionCallBack.didHit())
            pMaxDist = distance;
        return intersectionCallBack.didHit();
    }
    //=========================================================

    bool StaticMapTree::isInLineOfSight(Vector3 const& pos1, Vector3 const& pos2, ModelIgnoreFlags ignoreFlag) const
    {
        float maxDist = (pos2 - pos1).magnitude();
        // return false if distance is over max float, in case of cheater teleporting to the end of the universe
        if (maxDist == std::numeric_limits<float>::max() || !std::isfinite(maxDist))
            return false;

        // valid map coords should *never ever* produce float overflow, but this would produce NaNs too
        ASSERT(maxDist < std::numeric_limits<float>::max());
        // prevent NaN values which can cause BIH intersection to enter infinite loop
        if (maxDist < 1e-10f)
            return true;
        // direction with length of 1
        G3D::Ray ray = G3D::Ray::fromOriginAndDirection(pos1, (pos2 - pos1) / maxDist);
        if (getIntersectionTime(ray, maxDist, true, ignoreFlag))
            return false;

        return true;
    }
    //=========================================================
    /**
    When moving from pos1 to pos2 check if we hit an object. Return true and the position if we hit one
    Return the hit pos or the original dest pos
    */

    bool StaticMapTree::getObjectHitPos(Vector3 const& pPos1, Vector3 const& pPos2, Vector3& pResultHitPos, float pModifyDist) const
    {
        bool result = false;
        float maxDist = (pPos2 - pPos1).magnitude();
        // valid map coords should *never ever* produce float overflow, but this would produce NaNs too
        ASSERT(maxDist < std::numeric_limits<float>::max());
        // prevent NaN values which can cause BIH intersection to enter infinite loop
        if (maxDist < 1e-10f)
        {
            pResultHitPos = pPos2;
            return false;
        }
        Vector3 dir = (pPos2 - pPos1) / maxDist;              // direction with length of 1
        G3D::Ray ray(pPos1, dir);
        float dist = maxDist;
        if (getIntersectionTime(ray, dist, false, ModelIgnoreFlags::Nothing))
        {
            pResultHitPos = pPos1 + dir * dist;
            if (pModifyDist < 0)
            {
                if ((pResultHitPos - pPos1).magnitude() > -pModifyDist)
                {
                    pResultHitPos = pResultHitPos + dir * pModifyDist;
                }
                else
                {
                    pResultHitPos = pPos1;
                }
            }
            else
            {
                pResultHitPos = pResultHitPos + dir * pModifyDist;
            }
            result = true;
        }
        else
        {
            pResultHitPos = pPos2;
            result = false;
        }
        return result;
    }

    //=========================================================

    float StaticMapTree::getHeight(Vector3 const& pPos, float maxSearchDist) const
    {
        float height = G3D::finf();
        Vector3 dir = Vector3(0, 0, -1);
        G3D::Ray ray(pPos, dir);   // direction with length of 1
        float maxDist = maxSearchDist;
        if (getIntersectionTime(ray, maxDist, false, ModelIgnoreFlags::Nothing))
        {
            height = pPos.z - maxDist;
        }
        return(height);
    }

    struct TileFileOpenResult
    {
        using FileHandle = decltype(Trinity::make_unique_ptr_with_deleter<FILE>(nullptr, &::fclose));

        std::string Name;
        FileHandle TileFile = { nullptr, &::fclose };
        FileHandle SpawnIndicesFile = { nullptr, &::fclose };
        int32 UsedMapId;

        explicit operator bool() const { return TileFile && SpawnIndicesFile; }
    };

    TileFileOpenResult OpenMapTileFile(std::string const& basePath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        TileFileOpenResult result;
        result.Name = basePath + getTileFileName(mapID, tileX, tileY, "vmtile");
        result.TileFile.reset(fopen(result.Name.c_str(), "rb"));
        result.SpawnIndicesFile.reset(fopen((basePath + getTileFileName(mapID, tileX, tileY, "vmtileidx")).c_str(), "rb"));
        result.UsedMapId = mapID;
        if (!result.TileFile)
        {
            int32 parentMapId = vm->getParentMapId(mapID);
            while (parentMapId != -1)
            {
                result.Name = basePath + getTileFileName(parentMapId, tileX, tileY, "vmtile");
                result.TileFile.reset(fopen(result.Name.c_str(), "rb"));
                result.UsedMapId = parentMapId;
                if (result.TileFile)
                    break;

                parentMapId = vm->getParentMapId(uint32(parentMapId));
            }
        }

        return result;
    }

    //=========================================================
    LoadResult StaticMapTree::CanLoadMap(const std::string& vmapPath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        std::string basePath = vmapPath;
        if (basePath.length() > 0 && basePath[basePath.length() - 1] != '/' && basePath[basePath.length() - 1] != '\\')
            basePath.push_back('/');
        std::string fullname = basePath + VMapManager2::getMapFileName(mapID);

        auto rf = Trinity::make_unique_ptr_with_deleter(fopen(fullname.c_str(), "rb"), &::fclose);
        if (!rf)
            return LoadResult::FileNotFound;

        char chunk[8];
        if (!readChunk(rf.get(), chunk, VMAP_MAGIC, 8))
            return LoadResult::VersionMismatch;

        TileFileOpenResult fileResult = OpenMapTileFile(basePath, mapID, tileX, tileY, vm);
        if (!fileResult)
            return LoadResult::FileNotFound;

        if (!readChunk(fileResult.TileFile.get(), chunk, VMAP_MAGIC, 8))
            return LoadResult::VersionMismatch;

        return LoadResult::Success;
    }

    //=========================================================

    LoadResult StaticMapTree::InitMap(std::string const& fname)
    {
        TC_LOG_DEBUG("maps", "StaticMapTree::InitMap() : initializing StaticMapTree '{}'", fname);
        std::string fullname = iBasePath + fname;
        auto rf = Trinity::make_unique_ptr_with_deleter(fopen(fullname.c_str(), "rb"), &::fclose);
        if (!rf)
            return LoadResult::FileNotFound;

        char chunk[8];

        if (!readChunk(rf.get(), chunk, VMAP_MAGIC, 8))
            return LoadResult::VersionMismatch;

        if (!readChunk(rf.get(), chunk, "NODE", 4)
            || !iTree.readFromFile(rf.get()))
            return LoadResult::ReadFromFileFailed;

        iTreeValues.resize(iTree.primCount());

        return LoadResult::Success;
    }

    //=========================================================

    void StaticMapTree::UnloadMap()
    {
        iTreeValues.clear();
        iLoadedTiles.clear();
    }

    //=========================================================

    LoadResult StaticMapTree::LoadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        if (iTreeValues.empty())
        {
            TC_LOG_ERROR("misc", "StaticMapTree::LoadMapTile() : tree has not been initialized [{}, {}]", tileX, tileY);
            return LoadResult::ReadFromFileFailed;
        }
        LoadResult result = LoadResult::FileNotFound;

        TileFileOpenResult fileResult = OpenMapTileFile(iBasePath, iMapID, tileX, tileY, vm);
        if (fileResult)
        {
            char chunk[8];

            result = LoadResult::Success;
            if (!readChunk(fileResult.TileFile.get(), chunk, VMAP_MAGIC, 8))
                result = LoadResult::VersionMismatch;
            if (!readChunk(fileResult.SpawnIndicesFile.get(), chunk, VMAP_MAGIC, 8))
                result = LoadResult::VersionMismatch;
            uint32 numSpawns = 0;
            if (result == LoadResult::Success && fread(&numSpawns, sizeof(uint32), 1, fileResult.TileFile.get()) != 1)
                result = LoadResult::ReadFromFileFailed;
            uint32 numSpawnIndices = 0;
            if (result == LoadResult::Success && fread(&numSpawnIndices, sizeof(uint32), 1, fileResult.SpawnIndicesFile.get()) != 1)
                result = LoadResult::ReadFromFileFailed;
            if (numSpawns != numSpawnIndices)
                result = LoadResult::ReadFromFileFailed;
            for (uint32 i = 0; i < numSpawns && result == LoadResult::Success; ++i)
            {
                // read model spawns
                ModelSpawn spawn;
                if (ModelSpawn::readFromFile(fileResult.TileFile.get(), spawn))
                {
                    // acquire model instance
                    std::shared_ptr<WorldModel> model = vm->acquireModelInstance(iBasePath, spawn.name);
                    if (!model)
                        TC_LOG_ERROR("misc", "StaticMapTree::LoadMapTile() : could not acquire WorldModel pointer [{}, {}]", tileX, tileY);

                    // update tree
                    uint32 referencedVal = 0;
                    if (fread(&referencedVal, sizeof(uint32), 1, fileResult.SpawnIndicesFile.get()) != 1)
                    {
                        TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : invalid tree element (spawn {}) referenced in tile {} by map {}", spawn.ID, fileResult.Name, iMapID);
                        result = LoadResult::ReadFromFileFailed;
                        break;
                    }

                    if (referencedVal >= iTreeValues.size())
                    {
                        TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : invalid tree element ({}/{}) referenced in tile {}", referencedVal, iTreeValues.size(), fileResult.Name);
                        continue;
                    }

                    if (!iTreeValues[referencedVal].getWorldModel())
                        iTreeValues[referencedVal] = ModelInstance(spawn, std::move(model));
#ifdef VMAP_DEBUG
                    else
                    {
                        if (iTreeValues[referencedVal].ID != spawn.ID)
                            TC_LOG_DEBUG("maps", "StaticMapTree::LoadMapTile() : trying to load wrong spawn in node");
                        else if (iTreeValues[referencedVal].name != spawn.name)
                            TC_LOG_DEBUG("maps", "StaticMapTree::LoadMapTile() : name collision on GUID={}", spawn.ID);
                    }
#endif
                    iTreeValues[referencedVal].AddTileReference();
                }
                else
                {
                    TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : cannot read model from file (spawn index {}) referenced in tile {} by map {}", i, fileResult.Name, iMapID);
                    result = LoadResult::ReadFromFileFailed;
                }
            }
            iLoadedTiles[packTileID(tileX, tileY)] = true;
        }
        else
            iLoadedTiles[packTileID(tileX, tileY)] = false;
        TC_METRIC_EVENT("map_events", "LoadMapTile",
            "Map: " + std::to_string(iMapID) + " TileX: " + std::to_string(tileX) + " TileY: " + std::to_string(tileY));
        return result;
    }

    //=========================================================

    void StaticMapTree::UnloadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        uint32 tileID = packTileID(tileX, tileY);
        loadedTileMap::iterator tile = iLoadedTiles.find(tileID);
        if (tile == iLoadedTiles.end())
        {
            TC_LOG_ERROR("misc", "StaticMapTree::UnloadMapTile() : trying to unload non-loaded tile - Map:{} X:{} Y:{}", iMapID, tileX, tileY);
            return;
        }
        if (tile->second) // file associated with tile
        {
            TileFileOpenResult fileResult = OpenMapTileFile(iBasePath, iMapID, tileX, tileY, vm);
            if (fileResult)
            {
                bool result = true;
                char chunk[8];
                if (!readChunk(fileResult.TileFile.get(), chunk, VMAP_MAGIC, 8))
                    result = false;
                uint32 numSpawns;
                if (fread(&numSpawns, sizeof(uint32), 1, fileResult.TileFile.get()) != 1)
                    result = false;
                uint32 numSpawnIndices = 0;
                if (result && fread(&numSpawnIndices, sizeof(uint32), 1, fileResult.SpawnIndicesFile.get()) != 1)
                    result = false;
                if (numSpawns != numSpawnIndices)
                    result = false;
                for (uint32 i = 0; i < numSpawns && result; ++i)
                {
                    // read model spawns
                    ModelSpawn spawn;
                    result = ModelSpawn::readFromFile(fileResult.TileFile.get(), spawn);
                    if (result)
                    {
                        // update tree
                        uint32 referencedNode = 0;
                        if (fread(&referencedNode, sizeof(uint32), 1, fileResult.SpawnIndicesFile.get()) != 1)
                        {
                            TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : invalid tree element (spawn {}) referenced in tile {} by map {}", spawn.ID, fileResult.Name, iMapID);
                            result = false;
                            break;
                        }

                        if (referencedNode >= iTreeValues.size())
                        {
                            TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : invalid tree element ({}/{}) referenced in tile {}", referencedNode, iTreeValues.size(), fileResult.Name);
                            continue;
                        }

                        if (!iTreeValues[referencedNode].getWorldModel())
                            TC_LOG_ERROR("misc", "StaticMapTree::UnloadMapTile() : trying to unload non-referenced model '{}' (ID:{})", spawn.name, spawn.ID);
                        else if (!iTreeValues[referencedNode].RemoveTileReference())
                            iTreeValues[referencedNode].setUnloaded();
                    }
                }
            }
        }
        iLoadedTiles.erase(tile);
        TC_METRIC_EVENT("map_events", "UnloadMapTile",
            "Map: " + std::to_string(iMapID) + " TileX: " + std::to_string(tileX) + " TileY: " + std::to_string(tileY));
    }

    void StaticMapTree::getModelInstances(ModelInstance*& models, uint32& count)
    {
        models = iTreeValues.data();
        count = iTreeValues.size();
    }
}
