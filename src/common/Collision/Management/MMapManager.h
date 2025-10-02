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

#ifndef _MMAP_MANAGER_H
#define _MMAP_MANAGER_H

#include "Define.h"
#include <DetourNavMesh.h>
#include <DetourNavMeshQuery.h>
#include <memory>
#include <string_view>
#include <unordered_map>
#include <vector>

//  move map related classes
namespace MMAP
{
    struct MMapData;

    typedef std::unordered_map<uint32, std::unique_ptr<MMapData>> MMapDataSet;

    enum class LoadResult : uint8
    {
        Success,
        AlreadyLoaded,
        FileNotFound,
        VersionMismatch,
        ReadFromFileFailed,
        LibraryError
    };

    // singleton class
    // holds all all access to mmap loading unloading and meshes
    class TC_COMMON_API MMapManager
    {
        public:
            MMapManager();
            MMapManager(MMapManager const& other) = delete;
            MMapManager(MMapManager&& other) noexcept = delete;
            MMapManager& operator=(MMapManager const& other) = delete;
            MMapManager& operator=(MMapManager&& other) noexcept = delete;
            ~MMapManager();

            static MMapManager* instance();

            void InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData);
            LoadResult loadMap(std::string_view basePath, uint32 mapId, int32 x, int32 y);
            bool loadMapInstance(std::string_view basePath, uint32 meshMapId, uint32 instanceMapId, uint32 instanceId);
            bool unloadMap(uint32 mapId, int32 x, int32 y);
            bool unloadMap(uint32 mapId);
            bool unloadMapInstance(uint32 meshMapId, uint32 instanceMapId, uint32 instanceId);

            // the returned [dtNavMeshQuery const*] is NOT threadsafe
            dtNavMeshQuery const* GetNavMeshQuery(uint32 meshMapId, uint32 instanceMapId, uint32 instanceId);
            dtNavMesh const* GetNavMesh(uint32 mapId);

            uint32 getLoadedTilesCount() const { return loadedTiles; }
            uint32 getLoadedMapsCount() const { return uint32(loadedMMaps.size()); }
        private:
            LoadResult loadMapData(std::string_view basePath, uint32 mapId);
            uint32 packTileID(int32 x, int32 y);

            MMapDataSet::const_iterator GetMMapData(uint32 mapId) const;
            MMapDataSet loadedMMaps;
            uint32 loadedTiles = 0;
            bool thread_safe_environment = true;

            std::unordered_map<uint32, uint32> parentMapData;
    };
}

#endif
