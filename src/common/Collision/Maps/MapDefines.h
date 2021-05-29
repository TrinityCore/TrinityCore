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

#ifndef MapDefines_h__
#define MapDefines_h__

#include "Define.h"
#include "EnumFlag.h"
#include <array>

/// Represents a map magic value of 4 bytes (used in versions)
using u_map_magic = std::array<char, 4>;

TC_COMMON_API extern u_map_magic const MapMagic;
TC_COMMON_API extern u_map_magic const MapVersionMagic;
TC_COMMON_API extern u_map_magic const MapAreaMagic;
TC_COMMON_API extern u_map_magic const MapHeightMagic;
TC_COMMON_API extern u_map_magic const MapLiquidMagic;

// ******************************************
// Map file format defines
// ******************************************
struct map_fileheader
{
    u_map_magic mapMagic;
    u_map_magic versionMagic;
    uint32 buildMagic;
    uint32 areaMapOffset;
    uint32 areaMapSize;
    uint32 heightMapOffset;
    uint32 heightMapSize;
    uint32 liquidMapOffset;
    uint32 liquidMapSize;
    uint32 holesOffset;
    uint32 holesSize;
};

enum class map_areaHeaderFlags : uint16
{
    None    = 0x0000,
    NoArea  = 0x0001
};

DEFINE_ENUM_FLAG(map_areaHeaderFlags);

struct map_areaHeader
{
    u_map_magic areaMagic;
    EnumFlag<map_areaHeaderFlags> flags = map_areaHeaderFlags::None;
    uint16 gridArea;
};

enum class map_heightHeaderFlags : uint32
{
    None            = 0x0000,
    NoHeight        = 0x0001,
    HeightAsInt16   = 0x0002,
    HeightAsInt8    = 0x0004,
    HasFlightBounds = 0x0008
};

DEFINE_ENUM_FLAG(map_heightHeaderFlags);

struct map_heightHeader
{
    u_map_magic heightMagic;
    EnumFlag<map_heightHeaderFlags> flags = map_heightHeaderFlags::None;
    float  gridHeight;
    float  gridMaxHeight;
};

enum class map_liquidHeaderFlags : uint8
{
    None        = 0x0000,
    NoType      = 0x0001,
    NoHeight    = 0x0002
};

DEFINE_ENUM_FLAG(map_liquidHeaderFlags);

enum class map_liquidHeaderTypeFlags : uint8
{
    NoWater     = 0x00,
    Water       = 0x01,
    Ocean       = 0x02,
    Magma       = 0x04,
    Slime       = 0x08,

    DarkWater   = 0x10,

    AllLiquids  = Water | Ocean | Magma | Slime
};

DEFINE_ENUM_FLAG(map_liquidHeaderTypeFlags);

struct map_liquidHeader
{
    u_map_magic liquidMagic;
    EnumFlag<map_liquidHeaderFlags> flags = map_liquidHeaderFlags::None;
    EnumFlag<map_liquidHeaderTypeFlags> liquidFlags = map_liquidHeaderTypeFlags::NoWater;
    uint16 liquidType;
    uint8  offsetX;
    uint8  offsetY;
    uint8  width;
    uint8  height;
    float  liquidLevel;
};

#endif // MapDefines_h__
