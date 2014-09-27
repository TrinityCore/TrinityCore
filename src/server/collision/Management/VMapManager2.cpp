/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "VMapManager2.h"
#include "MapTree.h"
#include "ModelInstance.h"
#include "WorldModel.h"
#include <G3D/Vector3.h>
#include "DisableMgr.h"
#include "DBCStores.h"
#include "Log.h"
#include "VMapDefinitions.h"

using G3D::Vector3;

namespace VMAP
{
    VMapManager2::VMapManager2()
    {
    }

    VMapManager2::~VMapManager2(void)
    {
        for (InstanceTreeMap::iterator i = iInstanceMapTrees.begin(); i != iInstanceMapTrees.end(); ++i)
        {
            delete i->second;
        }
        for (ModelFileMap::iterator i = iLoadedModelFiles.begin(); i != iLoadedModelFiles.end(); ++i)
        {
            delete i->second.getModel();
        }
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
        std::stringstream fname;
        fname.width(3);
        fname << std::setfill('0') << mapId << std::string(MAP_FILENAME_EXTENSION2);

        return fname.str();
    }

    int VMapManager2::loadMap(const char* basePath, unsigned int mapId, int x, int y)
    {
        int result = VMAP_LOAD_RESULT_IGNORED;
        if (isMapLoadingEnabled())
        {
            if (_loadMap(mapId, basePath, x, y))
                result = VMAP_LOAD_RESULT_OK;
            else
                result = VMAP_LOAD_RESULT_ERROR;
        }

        return result;
    }

    // load one tile (internal use only)
    bool VMapManager2::_loadMap(unsigned int mapId, const std::string& basePath, uint32 tileX, uint32 tileY)
    {
        InstanceTreeMap::iterator instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree == iInstanceMapTrees.end())
        {
            std::string mapFileName = getMapFileName(mapId);
            StaticMapTree* newTree = new StaticMapTree(mapId, basePath);
            if (!newTree->InitMap(mapFileName, this))
            {
                delete newTree;
                return false;
            }
            instanceTree = iInstanceMapTrees.insert(InstanceTreeMap::value_type(mapId, newTree)).first;
        }

        return instanceTree->second->LoadMapTile(tileX, tileY, this);
    }

    void VMapManager2::unloadMap(unsigned int mapId)
    {
        InstanceTreeMap::iterator instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree != iInstanceMapTrees.end())
        {
            instanceTree->second->UnloadMap(this);
            if (instanceTree->second->numLoadedTiles() == 0)
            {
                delete instanceTree->second;
                iInstanceMapTrees.erase(mapId);
            }
        }
    }

    void VMapManager2::unloadMap(unsigned int mapId, int x, int y)
    {
        InstanceTreeMap::iterator instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree != iInstanceMapTrees.end())
        {
            instanceTree->second->UnloadMapTile(x, y, this);
            if (instanceTree->second->numLoadedTiles() == 0)
            {
                delete instanceTree->second;
                iInstanceMapTrees.erase(mapId);
            }
        }
    }

    bool VMapManager2::isInLineOfSight(unsigned int mapId, float x1, float y1, float z1, float x2, float y2, float z2)
    {
        if (!isLineOfSightCalcEnabled() || DisableMgr::IsDisabledFor(DISABLE_TYPE_VMAP, mapId, NULL, VMAP_DISABLE_LOS))
            return true;

        InstanceTreeMap::iterator instanceTree = iInstanceMapTrees.find(mapId);
        if (instanceTree != iInstanceMapTrees.end())
        {
            Vector3 pos1 = convertPositionToInternalRep(x1, y1, z1);
            Vector3 pos2 = convertPositionToInternalRep(x2, y2, z2);
            if (pos1 != pos2)
            {
                return instanceTree->second->isInLineOfSight(pos1, pos2);
            }
        }

        return true;
    }

    /**
    get the hit position and return true if we hit something
    otherwise the result pos will be the dest pos
    */
    bool VMapManager2::getObjectHitPos(unsigned int mapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float modifyDist)
    {
        if (isLineOfSightCalcEnabled() && !DisableMgr::IsDisabledFor(DISABLE_TYPE_VMAP, mapId, NULL, VMAP_DISABLE_LOS))
        {
            InstanceTreeMap::iterator instanceTree = iInstanceMapTrees.find(mapId);
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
        if (isHeightCalcEnabled() && !DisableMgr::IsDisabledFor(DISABLE_TYPE_VMAP, mapId, NULL, VMAP_DISABLE_HEIGHT))
        {
            InstanceTreeMap::iterator instanceTree = iInstanceMapTrees.find(mapId);
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

    bool VMapManager2::getAreaInfo(unsigned int mapId, float x, float y, float& z, uint32& flags, int32& adtId, int32& rootId, int32& groupId) const
    {
        if (!DisableMgr::IsDisabledFor(DISABLE_TYPE_VMAP, mapId, NULL, VMAP_DISABLE_AREAFLAG))
        {
            InstanceTreeMap::const_iterator instanceTree = iInstanceMapTrees.find(mapId);
            if (instanceTree != iInstanceMapTrees.end())
            {
                Vector3 pos = convertPositionToInternalRep(x, y, z);
                bool result = instanceTree->second->getAreaInfo(pos, flags, adtId, rootId, groupId);
                // z is not touched by convertPositionToInternalRep(), so just copy
                z = pos.z;
                return result;
            }
        }

        return false;
    }

    bool VMapManager2::GetLiquidLevel(uint32 mapId, float x, float y, float z, uint8 reqLiquidType, float& level, float& floor, uint32& type) const
    {
        if (!DisableMgr::IsDisabledFor(DISABLE_TYPE_VMAP, mapId, NULL, VMAP_DISABLE_LIQUIDSTATUS))
        {
            InstanceTreeMap::const_iterator instanceTree = iInstanceMapTrees.find(mapId);
            if (instanceTree != iInstanceMapTrees.end())
            {
                LocationInfo info;
                Vector3 pos = convertPositionToInternalRep(x, y, z);
                if (instanceTree->second->GetLocationInfo(pos, info))
                {
                    floor = info.ground_Z;
                    ASSERT(floor < std::numeric_limits<float>::max());
                    type = info.hitModel->GetLiquidType();  // entry from LiquidType.dbc
                    if (reqLiquidType && !(GetLiquidFlags(type) & reqLiquidType))
                        return false;
                    if (info.hitInstance->GetLiquidLevel(pos, info, level))
                        return true;
                }
            }
        }

        return false;
    }

    WorldModel* VMapManager2::acquireModelInstance(const std::string& basepath, const std::string& filename)
    {
        //! Critical section, thread safe access to iLoadedModelFiles
        std::lock_guard<std::mutex> lock(LoadedModelFilesLock);

        ModelFileMap::iterator model = iLoadedModelFiles.find(filename);
        if (model == iLoadedModelFiles.end())
        {
            WorldModel* worldmodel = new WorldModel();
            if (!worldmodel->readFile(basepath + filename + ".vmo"))
            {
                VMAP_ERROR_LOG("misc", "VMapManager2: could not load '%s%s.vmo'", basepath.c_str(), filename.c_str());
                delete worldmodel;
                return NULL;
            }
            VMAP_DEBUG_LOG("maps", "VMapManager2: loading file '%s%s'", basepath.c_str(), filename.c_str());
            model = iLoadedModelFiles.insert(std::pair<std::string, ManagedModel>(filename, ManagedModel())).first;
            model->second.setModel(worldmodel);
        }
        model->second.incRefCount();
        return model->second.getModel();
    }

    void VMapManager2::releaseModelInstance(const std::string &filename)
    {
        //! Critical section, thread safe access to iLoadedModelFiles
        std::lock_guard<std::mutex> lock(LoadedModelFilesLock);

        ModelFileMap::iterator model = iLoadedModelFiles.find(filename);
        if (model == iLoadedModelFiles.end())
        {
            VMAP_ERROR_LOG("misc", "VMapManager2: trying to unload non-loaded file '%s'", filename.c_str());
            return;
        }
        if (model->second.decRefCount() == 0)
        {
            VMAP_DEBUG_LOG("maps", "VMapManager2: unloading file '%s'", filename.c_str());
            delete model->second.getModel();
            iLoadedModelFiles.erase(model);
        }
    }

    bool VMapManager2::existsMap(const char* basePath, unsigned int mapId, int x, int y)
    {
        return StaticMapTree::CanLoadMap(std::string(basePath), mapId, x, y);
    }

} // namespace VMAP
