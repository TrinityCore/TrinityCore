/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#define MMAP_VERSION 8

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

enum NavTerrain
{
    NAV_EMPTY   = 0x00,
    NAV_GROUND  = 0x01,
    NAV_MAGMA   = 0x02,
    NAV_SLIME   = 0x04,
    NAV_WATER   = 0x08,
    NAV_UNUSED1 = 0x10,
    NAV_UNUSED2 = 0x20,
    NAV_UNUSED3 = 0x40,
    NAV_UNUSED4 = 0x80
    // we only have 8 bits
};

#endif /* _MAPDEFINES_H */
