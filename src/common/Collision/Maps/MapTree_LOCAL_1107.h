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

#ifndef _MAPTREE_H
#define _MAPTREE_H

#include "Define.h"
#include "BoundingIntervalHierarchy.h"
#include <unordered_map>

namespace VMAP
{
    class ModelInstance;
    class GroupModel;
    class VMapManager2;
    enum class LoadResult : uint8;
    enum class ModelIgnoreFlags : uint32;

    struct TC_COMMON_API LocationInfo
    {
        LocationInfo(): rootId(-1), hitInstance(nullptr), hitModel(nullptr), ground_Z(-G3D::finf()) { }
        int32 rootId;
        ModelInstance const* hitInstance;
        GroupModel const* hitModel;
        float ground_Z;
    };

    class TC_COMMON_API StaticMapTree
    {
        typedef std::unordered_map<uint32, bool> loadedTileMap;
        typedef std::unordered_map<uint32, uint32> loadedSpawnMap;
        private:
            uint32 iMapID;
            BIH iTree;
            ModelInstance* iTreeValues; // the tree entries
            uint32 iNTreeValues;
            std::unordered_map<uint32, uint32> iSpawnIndices;

            // Store all the map tile idents that are loaded for that map
            // some maps are not splitted into tiles and we have to make sure, not removing the map before all tiles are removed
            // empty tiles have no tile file, hence map with bool instead of just a set (consistency check)
            loadedTileMap iLoadedTiles;
            std::vector<std::pair<int32, int32>> iLoadedPrimaryTiles;
            // stores <tree_index, reference_count> to invalidate tree values, unload map, and to be able to report errors
            loadedSpawnMap iLoadedSpawns;
            std::string iBasePath;

            struct TileFileOpenResult
            {
                std::string Name;
                FILE* File;
                int32 UsedMapId;
            };

        private:
            static TileFileOpenResult OpenMapTileFile(std::string const& basePath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm);
            bool getIntersectionTime(const G3D::Ray& pRay, float &pMaxDist, bool pStopAtFirstHit, ModelIgnoreFlags ignoreFlags) const;
            //bool containsLoadedMapTile(unsigned int pTileIdent) const { return(iLoadedMapTiles.containsKey(pTileIdent)); }
        public:
            static std::string getTileFileName(uint32 mapID, uint32 tileX, uint32 tileY);
            static uint32 packTileID(uint32 tileX, uint32 tileY) { return tileX<<16 | tileY; }
            static void unpackTileID(uint32 ID, uint32 &tileX, uint32 &tileY) { tileX = ID >> 16; tileY = ID & 0xFF; }
            static LoadResult CanLoadMap(const std::string &basePath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm);

            StaticMapTree(uint32 mapID, const std::string &basePath);
            ~StaticMapTree();

            bool isInLineOfSight(const G3D::Vector3& pos1, const G3D::Vector3& pos2, ModelIgnoreFlags ignoreFlags) const;
            bool getObjectHitPos(const G3D::Vector3& pos1, const G3D::Vector3& pos2, G3D::Vector3& pResultHitPos, float pModifyDist) const;
            float getHeight(const G3D::Vector3& pPos, float maxSearchDist) const;
            bool getAreaInfo(G3D::Vector3 &pos, uint32 &flags, int32 &adtId, int32 &rootId, int32 &groupId) const;
            bool GetLocationInfo(const G3D::Vector3 &pos, LocationInfo &info) const;

            LoadResult InitMap(std::string const& fname);
            void UnloadMap(VMapManager2* vm);
            LoadResult LoadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm);
            void UnloadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm);
            uint32 numLoadedTiles() const { return uint32(iLoadedTiles.size()); }
            void getModelInstances(ModelInstance* &models, uint32 &count);

        private:
            StaticMapTree(StaticMapTree const& right) = delete;
            StaticMapTree& operator=(StaticMapTree const& right) = delete;
    };

    struct TC_COMMON_API AreaInfo
    {
        AreaInfo(): result(false), ground_Z(-G3D::finf()), flags(0), adtId(0),
            rootId(0), groupId(0) { }
        bool result;
        float ground_Z;
        uint32 flags;
        int32 adtId;
        int32 rootId;
        int32 groupId;
    };
}                                                           // VMAP

#endif // _MAPTREE_H
