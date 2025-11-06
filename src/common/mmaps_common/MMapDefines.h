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

#ifndef MMapDefines_h__
#define MMapDefines_h__

#include "Define.h"
#include <DetourNavMesh.h>

inline uint32 constexpr MMAP_MAGIC = 0x4d4d4150; // 'MMAP'
inline uint32 constexpr MMAP_VERSION = 16;

struct MmapNavMeshHeader
{
    uint32 mmapMagic = MMAP_MAGIC;
    uint32 mmapVersion = MMAP_VERSION;
    dtNavMeshParams params = { };
    uint32 offmeshConnectionCount = 0;
};

static_assert(sizeof(MmapNavMeshHeader) == 40);

struct MmapTileHeader
{
    uint32 mmapMagic = MMAP_MAGIC;
    uint32 dtVersion = DT_NAVMESH_VERSION;
    uint32 mmapVersion = MMAP_VERSION;
    uint32 size = 0;
    char usesLiquids = true;
    char padding[3] = { };
};

// All padding fields must be handled and initialized to ensure mmaps_generator will produce binary-identical *.mmtile files
static_assert(sizeof(MmapTileHeader) == 20, "MmapTileHeader size is not correct, adjust the padding field size");
static_assert(sizeof(MmapTileHeader) == sizeof(MmapTileHeader::mmapMagic) +
                                        sizeof(MmapTileHeader::dtVersion) +
                                        sizeof(MmapTileHeader::mmapVersion) +
                                        sizeof(MmapTileHeader::size) +
                                        sizeof(MmapTileHeader::usesLiquids) +
                                        sizeof(MmapTileHeader::padding), "MmapTileHeader has uninitialized padding fields");

enum NavArea
{
    NAV_AREA_EMPTY          = 0,
    // areas 1-60 will be used for destructible areas (currently skipped in vmaps, WMO with flag 1)
    // ground is the highest value to make recast choose ground over water when merging surfaces very close to each other (shallow water would be walkable)
    NAV_AREA_GROUND         = 11,
    NAV_AREA_GROUND_STEEP   = 10,
    NAV_AREA_WATER          = 9,
    NAV_AREA_MAGMA_SLIME    = 8, // don't need to differentiate between them
    NAV_AREA_MAX_VALUE      = NAV_AREA_GROUND,
    NAV_AREA_MIN_VALUE      = NAV_AREA_MAGMA_SLIME,
    NAV_AREA_ALL_MASK       = 0x3F // max allowed value
};

enum NavTerrainFlag : uint16
{
    NAV_EMPTY        = 0x00,
    NAV_GROUND       = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_GROUND),
    NAV_GROUND_STEEP = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_GROUND_STEEP),
    NAV_WATER        = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_WATER),
    NAV_MAGMA_SLIME  = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_MAGMA_SLIME)
};

enum OffMeshConnectionFlag : uint8
{
    OFFMESH_CONNECTION_FLAG_BIDIRECTIONAL   = 0x01
};

struct OffMeshData
{
    uint32 MapId;
    uint32 TileX;
    uint32 TileY;
    float From[3];
    float To[3];
    float Radius;
    OffMeshConnectionFlag ConnectionFlags;
    uint8 AreaId;
    NavTerrainFlag Flags;
};

#endif // MMapDefines_h__
