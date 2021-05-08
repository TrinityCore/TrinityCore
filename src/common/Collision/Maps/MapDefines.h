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

#ifndef _MAPDEFINES_H
#define _MAPDEFINES_H

#include "Define.h"
#include "DetourNavMesh.h"

const uint32 MMAP_MAGIC = 0x4d4d4150; // 'MMAP'
#define MMAP_VERSION 15

struct MmapTileHeader
{
    uint32 mmapMagic;
    uint32 dtVersion;
    uint32 mmapVersion;
    uint32 size;
    char usesLiquids;
    char padding[3];

    MmapTileHeader() : mmapMagic(MMAP_MAGIC), dtVersion(DT_NAVMESH_VERSION),
        mmapVersion(MMAP_VERSION), size(0), usesLiquids(true), padding() { }
};

// All padding fields must be handled and initialized to ensure mmaps_generator will produce binary-identical *.mmtile files
static_assert(sizeof(MmapTileHeader) == 20, "MmapTileHeader size is not correct, adjust the padding field size");
static_assert(sizeof(MmapTileHeader) == (sizeof(MmapTileHeader::mmapMagic) +
                                         sizeof(MmapTileHeader::dtVersion) +
                                         sizeof(MmapTileHeader::mmapVersion) +
                                         sizeof(MmapTileHeader::size) +
                                         sizeof(MmapTileHeader::usesLiquids) +
                                         sizeof(MmapTileHeader::padding)), "MmapTileHeader has uninitialized padding fields");

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

enum NavTerrainFlag
{
    NAV_EMPTY        = 0x00,
    NAV_GROUND       = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_GROUND),
    NAV_GROUND_STEEP = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_GROUND_STEEP),
    NAV_WATER        = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_WATER),
    NAV_MAGMA_SLIME  = 1 << (NAV_AREA_MAX_VALUE - NAV_AREA_MAGMA_SLIME)
};

#endif /* _MAPDEFINES_H */
