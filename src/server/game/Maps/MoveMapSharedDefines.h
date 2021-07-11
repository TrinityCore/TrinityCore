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

#ifndef _MOVE_MAP_SHARED_DEFINES_H
#define _MOVE_MAP_SHARED_DEFINES_H

#include "Platform/Define.h"
#include "../recastnavigation/Detour/Include/DetourNavMesh.h"

#define MMAP_MAGIC 0x4d4d4150   // 'MMAP'
#define MMAP_VERSION 6

struct MmapTileHeader
{
    uint32 mmapMagic;
    uint32 dtVersion;
    uint32 mmapVersion;
    uint32 size;
    uint32 usesLiquids;

    MmapTileHeader() : mmapMagic(MMAP_MAGIC), dtVersion(DT_NAVMESH_VERSION),
                       mmapVersion(MMAP_VERSION), size(0), usesLiquids(0) {}
};

enum NavTerrain
{
    NAV_EMPTY        = 0x00,
    NAV_GROUND       = 0x01,
    NAV_MAGMA        = 0x02,
    NAV_SLIME        = 0x04,
    NAV_WATER        = 0x08,
    NAV_STEEP_SLOPES = 0x10, // Slopes above player climb angle
    NAV_UNUSED2      = 0x20,
    NAV_UNUSED3      = 0x40,
    NAV_UNUSED4      = 0x80
    // we only have 8 bits
};

#endif  // _MOVE_MAP_SHARED_DEFINES_H
