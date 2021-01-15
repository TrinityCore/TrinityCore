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
#include "ModelInstance.h"
#include "VMapManager2.h"
#include "VMapDefinitions.h"
#include "Log.h"
#include "Errors.h"
#include "Metric.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

using G3D::Vector3;

namespace VMAP
{
    class MapRayCallback
    {
        public:
            MapRayCallback(ModelInstance* val, ModelIgnoreFlags ignoreFlags) : prims(val), hit(false), flags(ignoreFlags) { }
            bool operator()(const G3D::Ray& ray, uint32 entry, float& distance, bool pStopAtFirstHit = true)
            {
                bool result = prims[entry].intersectRay(ray, distance, pStopAtFirstHit, flags);
                if (result)
                    hit = true;
                return result;
            }
            bool didHit() { return hit; }
        protected:
            ModelInstance* prims;
            bool hit;
            ModelIgnoreFlags flags;
    };

    class AreaInfoCallback
    {
        public:
            AreaInfoCallback(ModelInstance* val) : prims(val) { }
            void operator()(Vector3 const& point, uint32 entry)
            {
#ifdef VMAP_DEBUG
                TC_LOG_DEBUG("maps", "AreaInfoCallback: trying to intersect '%s'", prims[entry].name.c_str());
#endif
                prims[entry].intersectPoint(point, aInfo);
            }

            ModelInstance* prims;
            AreaInfo aInfo;
    };

    class LocationInfoCallback
    {
        public:
            LocationInfoCallback(ModelInstance* val, LocationInfo& info) : prims(val), locInfo(info), result(false) { }
            void operator()(Vector3 const& point, uint32 entry)
            {
#ifdef VMAP_DEBUG
                TC_LOG_DEBUG("maps", "LocationInfoCallback: trying to intersect '%s'", prims[entry].name.c_str());
#endif
                if (prims[entry].GetLocationInfo(point, locInfo))
                    result = true;
            }

            ModelInstance* prims;
            LocationInfo& locInfo;
            bool result;
    };

    //=========================================================

    std::string StaticMapTree::getTileFileName(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        std::stringstream tilefilename;
        tilefilename.fill('0');
        tilefilename << std::setw(4) << mapID << '_';
        //tilefilename << std::setw(2) << tileX << '_' << std::setw(2) << tileY << ".vmtile";
        tilefilename << std::setw(2) << tileY << '_' << std::setw(2) << tileX << ".vmtile";
        return tilefilename.str();
    }

    bool StaticMapTree::getAreaInfo(Vector3& pos, uint32& flags, int32& adtId, int32& rootId, int32& groupId) const
    {
        AreaInfoCallback intersectionCallBack(iTreeValues);
        iTree.intersectPoint(pos, intersectionCallBack);
        if (intersectionCallBack.aInfo.result)
        {
            flags = intersectionCallBack.aInfo.flags;
            adtId = intersectionCallBack.aInfo.adtId;
            rootId = intersectionCallBack.aInfo.rootId;
            groupId = intersectionCallBack.aInfo.groupId;
            pos.z = intersectionCallBack.aInfo.ground_Z;
            return true;
        }
        return false;
    }

    bool StaticMapTree::GetLocationInfo(Vector3 const& pos, LocationInfo& info) const
    {
        LocationInfoCallback intersectionCallBack(iTreeValues, info);
        iTree.intersectPoint(pos, intersectionCallBack);
        return intersectionCallBack.result;
    }

    StaticMapTree::StaticMapTree(uint32 mapID, std::string const& basePath)
        : iMapID(mapID), iTreeValues(nullptr), iNTreeValues(0), iBasePath(basePath)
    {
        if (iBasePath.length() > 0 && iBasePath[iBasePath.length() - 1] != '/' && iBasePath[iBasePath.length() - 1] != '\\')
        {
            iBasePath.push_back('/');
        }
    }

    //=========================================================
    //! Make sure to call unloadMap() to unregister acquired model references before destroying
    StaticMapTree::~StaticMapTree()
    {
        delete[] iTreeValues;
    }

    //=========================================================
    /**
    If intersection is found within pMaxDist, sets pMaxDist to intersection distance and returns true.
    Else, pMaxDist is not modified and returns false;
    */

    bool StaticMapTree::getIntersectionTime(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit, ModelIgnoreFlags ignoreFlags) const
    {
        float distance = pMaxDist;
        MapRayCallback intersectionCallBack(iTreeValues, ignoreFlags);
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

    StaticMapTree::TileFileOpenResult StaticMapTree::OpenMapTileFile(std::string const& basePath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        TileFileOpenResult result;
        result.Name = basePath + getTileFileName(mapID, tileX, tileY);
        result.File = fopen(result.Name.c_str(), "rb");
        result.UsedMapId = mapID;
        if (!result.File)
        {
            int32 parentMapId = vm->getParentMapId(mapID);
            while (parentMapId != -1)
            {
                result.Name = basePath + getTileFileName(parentMapId, tileX, tileY);
                result.File = fopen(result.Name.c_str(), "rb");
                result.UsedMapId = parentMapId;
                if (result.File)
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

        LoadResult result = LoadResult::Success;

        FILE* rf = fopen(fullname.c_str(), "rb");
        if (!rf)
            return LoadResult::FileNotFound;

        char chunk[8];
        if (!readChunk(rf, chunk, VMAP_MAGIC, 8))
        {
            fclose(rf);
            return LoadResult::VersionMismatch;
        }
        FILE* tf = OpenMapTileFile(basePath, mapID, tileX, tileY, vm).File;
        if (!tf)
        {
            fclose(rf);
            return LoadResult::FileNotFound;
        }
        else
        {
            std::string tilefile = basePath + getTileFileName(mapID, tileX, tileY);
            FILE* tf = fopen(tilefile.c_str(), "rb");
            if (!tf)
                result = LoadResult::FileNotFound;
            else
            {
                if (!readChunk(tf, chunk, VMAP_MAGIC, 8))
                    result = LoadResult::VersionMismatch;
                fclose(tf);
            }
        }
        fclose(rf);
        return result;
    }

    //=========================================================

    LoadResult StaticMapTree::InitMap(std::string const& fname)
    {
        TC_LOG_DEBUG("maps", "StaticMapTree::InitMap() : initializing StaticMapTree '%s'", fname.c_str());
        std::string fullname = iBasePath + fname;
        FILE* rf = fopen(fullname.c_str(), "rb");
        if (!rf)
            return LoadResult::FileNotFound;

        LoadResult result = LoadResult::Success;
        char chunk[8];

        if (!readChunk(rf, chunk, VMAP_MAGIC, 8))
            result = LoadResult::VersionMismatch;

        if (result == LoadResult::Success &&
            readChunk(rf, chunk, "NODE", 4) &&
            iTree.readFromFile(rf))
        {
            iNTreeValues = iTree.primCount();
            iTreeValues = new ModelInstance[iNTreeValues];
            result = LoadResult::Success;
        }

        if (result == LoadResult::Success)
        {
            result = readChunk(rf, chunk, "SIDX", 4) ? LoadResult::Success : LoadResult::ReadFromFileFailed;
            uint32 spawnIndicesSize = 0;
            uint32 spawnId;
            if (result == LoadResult::Success && fread(&spawnIndicesSize, sizeof(uint32), 1, rf) != 1)
                result = LoadResult::ReadFromFileFailed;
            for (uint32 i = 0; i < spawnIndicesSize && result == LoadResult::Success; ++i)
            {
                if (fread(&spawnId, sizeof(uint32), 1, rf) == 1)
                    iSpawnIndices[spawnId] = i;
                else
                    result = LoadResult::ReadFromFileFailed;
            }
        }

        fclose(rf);
        return result;
    }

    //=========================================================

    void StaticMapTree::UnloadMap(VMapManager2* vm)
    {
        for (loadedSpawnMap::iterator i = iLoadedSpawns.begin(); i != iLoadedSpawns.end(); ++i)
        {
            iTreeValues[i->first].setUnloaded();
            for (uint32 refCount = 0; refCount < i->second; ++refCount)
                vm->releaseModelInstance(iTreeValues[i->first].name);
        }
        iLoadedSpawns.clear();
        iLoadedTiles.clear();
    }

    //=========================================================

    LoadResult StaticMapTree::LoadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        if (!iTreeValues)
        {
            TC_LOG_ERROR("misc", "StaticMapTree::LoadMapTile() : tree has not been initialized [%u, %u]", tileX, tileY);
            return LoadResult::ReadFromFileFailed;
        }
        LoadResult result = LoadResult::FileNotFound;

        TileFileOpenResult fileResult = OpenMapTileFile(iBasePath, iMapID, tileX, tileY, vm);
        if (fileResult.File)
        {
            char chunk[8];

            result = LoadResult::Success;
            if (!readChunk(fileResult.File, chunk, VMAP_MAGIC, 8))
                result = LoadResult::VersionMismatch;
            uint32 numSpawns = 0;
            if (result == LoadResult::Success && fread(&numSpawns, sizeof(uint32), 1, fileResult.File) != 1)
                result = LoadResult::ReadFromFileFailed;
            for (uint32 i = 0; i < numSpawns && result == LoadResult::Success; ++i)
            {
                // read model spawns
                ModelSpawn spawn;
                if (ModelSpawn::readFromFile(fileResult.File, spawn))
                {
                    // acquire model instance
                    WorldModel* model = vm->acquireModelInstance(iBasePath, spawn.name, spawn.flags);
                    if (!model)
                        TC_LOG_ERROR("misc", "StaticMapTree::LoadMapTile() : could not acquire WorldModel pointer [%u, %u]", tileX, tileY);

                    // update tree
                    auto spawnIndex = iSpawnIndices.find(spawn.ID);
                    if (spawnIndex != iSpawnIndices.end())
                    {
                        uint32 referencedVal = spawnIndex->second;
                        if (!iLoadedSpawns.count(referencedVal))
                        {
                            if (referencedVal >= iNTreeValues)
                            {
                                TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : invalid tree element (%u/%u) referenced in tile %s", referencedVal, iNTreeValues, fileResult.Name.c_str());
                                continue;
                            }

                            iTreeValues[referencedVal] = ModelInstance(spawn, model);
                            iLoadedSpawns[referencedVal] = 1;
                        }
                        else
                        {
                            ++iLoadedSpawns[referencedVal];
#ifdef VMAP_DEBUG
                            if (iTreeValues[referencedVal].ID != spawn.ID)
                                TC_LOG_DEBUG("maps", "StaticMapTree::LoadMapTile() : trying to load wrong spawn in node");
                            else if (iTreeValues[referencedVal].name != spawn.name)
                                TC_LOG_DEBUG("maps", "StaticMapTree::LoadMapTile() : name collision on GUID=%u", spawn.ID);
#endif
                        }
                    }
                    else if (int32(iMapID) == fileResult.UsedMapId)
                    {
                        // unknown parent spawn might appear in because it overlaps multiple tiles
                        // in case the original tile is swapped but its neighbour is now (adding this spawn)
                        // we want to not mark it as loading error and just skip that model
                        TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : invalid tree element (spawn %u) referenced in tile %s by map %u", spawn.ID, fileResult.Name.c_str(), iMapID);
                        result = LoadResult::ReadFromFileFailed;
                    }
                }
                else
                {
                    TC_LOG_ERROR("maps", "StaticMapTree::LoadMapTile() : cannot read model from file (spawn index %u) referenced in tile %s by map %u", i, fileResult.Name.c_str(), iMapID);
                    result = LoadResult::ReadFromFileFailed;
                }
            }
            iLoadedTiles[packTileID(tileX, tileY)] = true;
            fclose(fileResult.File);
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
            TC_LOG_ERROR("misc", "StaticMapTree::UnloadMapTile() : trying to unload non-loaded tile - Map:%u X:%u Y:%u", iMapID, tileX, tileY);
            return;
        }
        if (tile->second) // file associated with tile
        {
            TileFileOpenResult fileResult = OpenMapTileFile(iBasePath, iMapID, tileX, tileY, vm);
            if (fileResult.File)
            {
                bool result = true;
                char chunk[8];
                if (!readChunk(fileResult.File, chunk, VMAP_MAGIC, 8))
                    result = false;
                uint32 numSpawns;
                if (fread(&numSpawns, sizeof(uint32), 1, fileResult.File) != 1)
                    result = false;
                for (uint32 i = 0; i < numSpawns && result; ++i)
                {
                    // read model spawns
                    ModelSpawn spawn;
                    result = ModelSpawn::readFromFile(fileResult.File, spawn);
                    if (result)
                    {
                        // release model instance
                        vm->releaseModelInstance(spawn.name);

                        // update tree
                        auto spawnIndex = iSpawnIndices.find(spawn.ID);
                        if (spawnIndex != iSpawnIndices.end())
                        {
                            uint32 referencedNode = spawnIndex->second;
                            if (!iLoadedSpawns.count(referencedNode))
                                TC_LOG_ERROR("misc", "StaticMapTree::UnloadMapTile() : trying to unload non-referenced model '%s' (ID:%u)", spawn.name.c_str(), spawn.ID);
                            else if (--iLoadedSpawns[referencedNode] == 0)
                            {
                                iTreeValues[referencedNode].setUnloaded();
                                iLoadedSpawns.erase(referencedNode);
                            }
                        }
                        else if (int32(iMapID) == fileResult.UsedMapId) // logic documented in StaticMapTree::LoadMapTile
                            result = false;
                    }
                }
                fclose(fileResult.File);
            }
        }
        iLoadedTiles.erase(tile);
        TC_METRIC_EVENT("map_events", "UnloadMapTile",
            "Map: " + std::to_string(iMapID) + " TileX: " + std::to_string(tileX) + " TileY: " + std::to_string(tileY));
    }

    void StaticMapTree::getModelInstances(ModelInstance*& models, uint32& count)
    {
        models = iTreeValues;
        count = iNTreeValues;
    }
}
