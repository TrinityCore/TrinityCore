/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _VMAPMANAGER2_H
#define _VMAPMANAGER2_H

#include "IVMapManager.h"
#include "Dynamic/UnorderedMap.h"
#include "Define.h"
#include <G3D/Vector3.h>

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

namespace VMAP
{
    class StaticMapTree;
    class WorldModel;

    class ManagedModel
    {
        public:
            ManagedModel(): iModel(0), iRefCount(0) {}
            void setModel(WorldModel *model) { iModel = model; }
            WorldModel *getModel() { return iModel; }
            void incRefCount() { ++iRefCount; }
            int decRefCount() { return --iRefCount; }
        protected:
            WorldModel *iModel;
            int iRefCount;
    };

    typedef UNORDERED_MAP<uint32 , StaticMapTree *> InstanceTreeMap;
    typedef UNORDERED_MAP<std::string, ManagedModel> ModelFileMap;

    class VMapManager2 : public IVMapManager
    {
        protected:
            // Tree to check collision
            ModelFileMap iLoadedModelFiles;
            InstanceTreeMap iInstanceMapTrees;
            // UNORDERED_MAP<unsigned int , bool> iMapsSplitIntoTiles;
            UNORDERED_MAP<unsigned int , bool> iIgnoreMapIds;

            bool _loadMap(uint32 pMapId, const std::string &basePath, uint32 tileX, uint32 tileY);
            /* void _unloadMap(uint32 pMapId, uint32 x, uint32 y); */

        public:
            // public for debug
            G3D::Vector3 convertPositionToInternalRep(float x, float y, float z) const;
            G3D::Vector3 convertPositionToMangosRep(float x, float y, float z) const;
            static std::string getMapFileName(unsigned int pMapId);

            VMapManager2();
            ~VMapManager2(void);

            int loadMap(const char* pBasePath, unsigned int pMapId, int x, int y);

            void unloadMap(unsigned int pMapId, int x, int y);
            void unloadMap(unsigned int pMapId);

            bool isInLineOfSight(unsigned int pMapId, float x1, float y1, float z1, float x2, float y2, float z2) ;
            /**
            fill the hit pos and return true, if an object was hit
            */
            bool getObjectHitPos(unsigned int pMapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float pModifyDist);
            float getHeight(unsigned int pMapId, float x, float y, float z, float maxSearchDist);

            bool processCommand(char * /*pCommand*/) { return false; }      // for debug and extensions

            void preventMapsFromBeingUsed(const char* pMapIdString);
            bool getAreaInfo(unsigned int pMapId, float x, float y, float &z, uint32 &flags, int32 &adtId, int32 &rootId, int32 &groupId) const;
            bool GetLiquidLevel(uint32 pMapId, float x, float y, float z, uint8 ReqLiquidType, float &level, float &floor, uint32 &type) const;

            WorldModel* acquireModelInstance(const std::string &basepath, const std::string &filename);
            void releaseModelInstance(const std::string &filename);

            // what's the use of this? o.O
            virtual std::string getDirFileName(unsigned int pMapId, int /*x*/, int /*y*/) const
            {
                return getMapFileName(pMapId);
            }
            virtual bool existsMap(const char* pBasePath, unsigned int pMapId, int x, int y);
    };
}
#endif
