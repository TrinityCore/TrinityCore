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
#include "Optional.h"
#include <array>

/// Represents a map magic value of 4 bytes (used in versions)
using u_map_magic = std::array<char, 4>;

TC_COMMON_API extern u_map_magic const MapMagic;
TC_COMMON_API extern uint32 const MapVersionMagic;
TC_COMMON_API extern u_map_magic const MapAreaMagic;
TC_COMMON_API extern u_map_magic const MapHeightMagic;
TC_COMMON_API extern u_map_magic const MapLiquidMagic;

// ******************************************
// Map file format defines
// ******************************************
struct map_fileheader
{
    u_map_magic mapMagic;
    uint32 versionMagic;
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

enum ZLiquidStatus : uint32
{
    LIQUID_MAP_NO_WATER     = 0x00000000,
    LIQUID_MAP_ABOVE_WATER  = 0x00000001,
    LIQUID_MAP_WATER_WALK   = 0x00000002,
    LIQUID_MAP_IN_WATER     = 0x00000004,
    LIQUID_MAP_UNDER_WATER  = 0x00000008,
    LIQUID_MAP_OCEAN_FLOOR  = 0x00000010
};

#define MAP_LIQUID_STATUS_SWIMMING (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER)
#define MAP_LIQUID_STATUS_IN_CONTACT (MAP_LIQUID_STATUS_SWIMMING | LIQUID_MAP_WATER_WALK)

struct LiquidData
{
    EnumFlag<map_liquidHeaderTypeFlags> type_flags = map_liquidHeaderTypeFlags::NoWater;
    uint32 entry;
    float  level;
    float  depth_level;
};

struct WmoLocation
{
    WmoLocation() = default;
    WmoLocation(int32 groupId, int32 nameSetId, int32 rootId, uint32 uniqueId)
        : GroupId(groupId), NameSetId(nameSetId), RootId(rootId), UniqueId(uniqueId) { }

    int32 GroupId = 0;
    int32 NameSetId = 0;
    int32 RootId = 0;
    uint32 UniqueId = 0;
};

struct PositionFullTerrainStatus
{
    PositionFullTerrainStatus() : areaId(0), floorZ(0.0f), outdoors(true), liquidStatus(LIQUID_MAP_NO_WATER) { }
    uint32 areaId;
    float floorZ;
    bool outdoors;
    ZLiquidStatus liquidStatus;
    Optional<WmoLocation> wmoLocation;
    Optional<LiquidData> liquidInfo;
};

#endif // MapDefines_h__
