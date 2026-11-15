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

#ifndef TRINITY_GRIDDEFINES_H
#define TRINITY_GRIDDEFINES_H

#include "Common.h"
#include "NGrid.h"
#include <cmath>

// Forward class definitions
class Corpse;
class Creature;
class DynamicObject;
class GameObject;
class Pet;
class Player;
class AreaTrigger;
class SceneObject;
class Conversation;

#define MAX_NUMBER_OF_CELLS     8

#define MAX_NUMBER_OF_GRIDS      64

#define SIZE_OF_GRIDS            533.3333f
#define CENTER_GRID_ID           (MAX_NUMBER_OF_GRIDS/2)

#define CENTER_GRID_OFFSET      (SIZE_OF_GRIDS/2)

#define MIN_GRID_DELAY          (MINUTE*IN_MILLISECONDS)
#define MIN_MAP_UPDATE_DELAY    1

#define SIZE_OF_GRID_CELL       (SIZE_OF_GRIDS/MAX_NUMBER_OF_CELLS)

#define CENTER_GRID_CELL_ID     (MAX_NUMBER_OF_CELLS*MAX_NUMBER_OF_GRIDS/2)
#define CENTER_GRID_CELL_OFFSET (SIZE_OF_GRID_CELL/2)

#define TOTAL_NUMBER_OF_CELLS_PER_MAP    (MAX_NUMBER_OF_GRIDS*MAX_NUMBER_OF_CELLS)

#define MAP_RESOLUTION 128

#define MAP_SIZE                (SIZE_OF_GRIDS*MAX_NUMBER_OF_GRIDS)
#define MAP_HALFSIZE            (MAP_SIZE/2)

#define MAX_HEIGHT            100000.0f                     // can be use for find ground height at surface
#define INVALID_HEIGHT       -100000.0f                     // for check, must be equal to VMAP_INVALID_HEIGHT, real value for unknown height is VMAP_INVALID_HEIGHT_VALUE
#define MAX_FALL_DISTANCE     250000.0f                     // "unlimited fall" to find VMap ground if it is available, just larger than MAX_HEIGHT - INVALID_HEIGHT
#define DEFAULT_HEIGHT_SEARCH     50.0f                     // default search distance to find height at nearby locations

typedef GridRefManager<Corpse>          CorpseMapType;
typedef GridRefManager<Creature>        CreatureMapType;
typedef GridRefManager<DynamicObject>   DynamicObjectMapType;
typedef GridRefManager<GameObject>      GameObjectMapType;
typedef GridRefManager<Player>          PlayerMapType;
typedef GridRefManager<AreaTrigger>     AreaTriggerMapType;
typedef GridRefManager<SceneObject>     SceneObjectMapType;
typedef GridRefManager<Conversation>    ConversationMapType;

enum GridMapTypeMask
{
    GRID_MAP_TYPE_MASK_CORPSE           = 0x01,
    GRID_MAP_TYPE_MASK_CREATURE         = 0x02,
    GRID_MAP_TYPE_MASK_DYNAMICOBJECT    = 0x04,
    GRID_MAP_TYPE_MASK_GAMEOBJECT       = 0x08,
    GRID_MAP_TYPE_MASK_PLAYER           = 0x10,
    GRID_MAP_TYPE_MASK_AREATRIGGER      = 0x20,
    GRID_MAP_TYPE_MASK_SCENEOBJECT      = 0x40,
    GRID_MAP_TYPE_MASK_CONVERSATION     = 0x80,
    GRID_MAP_TYPE_MASK_ALL              = 0xFF
};

// Creature used instead pet to simplify *::Visit templates (not required duplicate code for Creature->Pet case)
extern template struct TypeListContainer<GridRefManagerContainer, GameObject, Creature/*except pets*/, DynamicObject, Corpse/*Bones*/, AreaTrigger, SceneObject, Conversation>;
extern template struct TypeListContainer<GridRefManagerContainer, Player, Creature/*pets*/, Corpse/*resurrectable*/, DynamicObject/*farsight target*/>;

typedef TypeListContainer<GridRefManagerContainer, GameObject, Creature/*except pets*/, DynamicObject, Corpse/*Bones*/, AreaTrigger, SceneObject, Conversation> GridTypeMapContainer;
typedef TypeListContainer<GridRefManagerContainer, Player, Creature/*pets*/, Corpse/*resurrectable*/, DynamicObject/*farsight target*/> WorldTypeMapContainer;

extern template class Grid<WorldTypeMapContainer, GridTypeMapContainer>;
extern template class NGrid<MAX_NUMBER_OF_CELLS, WorldTypeMapContainer, GridTypeMapContainer>;

typedef Grid<WorldTypeMapContainer, GridTypeMapContainer> GridType;
typedef NGrid<MAX_NUMBER_OF_CELLS, WorldTypeMapContainer, GridTypeMapContainer> NGridType;

template<uint32 LIMIT>
struct CoordPair
{
    constexpr CoordPair(uint32 x, uint32 y)
        : x_coord(x), y_coord(y) { }

    constexpr void dec_x(uint32 val)
    {
        if (x_coord > val)
            x_coord -= val;
        else
            x_coord = 0;
    }

    constexpr void inc_x(uint32 val)
    {
        if (x_coord + val < LIMIT)
            x_coord += val;
        else
            x_coord = LIMIT - 1;
    }

    constexpr void dec_y(uint32 val)
    {
        if (y_coord > val)
            y_coord -= val;
        else
            y_coord = 0;
    }

    constexpr void inc_y(uint32 val)
    {
        if (y_coord + val < LIMIT)
            y_coord += val;
        else
            y_coord = LIMIT - 1;
    }

    constexpr bool IsCoordValid() const
    {
        return x_coord < LIMIT && y_coord < LIMIT;
    }

    constexpr uint32 GetId() const
    {
        return y_coord * LIMIT + x_coord;
    }

    friend constexpr bool operator==(CoordPair const& p1, CoordPair const& p2) = default;

    uint32 x_coord;
    uint32 y_coord;
};

typedef CoordPair<MAX_NUMBER_OF_GRIDS> GridCoord;
typedef CoordPair<TOTAL_NUMBER_OF_CELLS_PER_MAP> CellCoord;

namespace Trinity
{
    template<int32 LIMIT, int32 CENTER_VAL>
    inline constexpr CoordPair<LIMIT> Compute(float x, float y, float center_offset, float size)
    {
        // calculate and store temporary values in double format for having same result as same mySQL calculations
        double x_offset = (double(x) - center_offset) / size;
        double y_offset = (double(y) - center_offset) / size;

        int32 x_val = int32(x_offset + CENTER_VAL + 0.5);
        int32 y_val = int32(y_offset + CENTER_VAL + 0.5);
        return CoordPair<LIMIT>(
            x_val >= 0 ? x_val < LIMIT ? x_val : LIMIT - 1 : 0,
            y_val >= 0 ? y_val < LIMIT ? y_val : LIMIT - 1 : 0
        );
    }

    inline constexpr GridCoord ComputeGridCoord(float x, float y)
    {
        return Compute<MAX_NUMBER_OF_GRIDS, CENTER_GRID_ID>(x, y, CENTER_GRID_OFFSET, SIZE_OF_GRIDS);
    }

    inline constexpr GridCoord ComputeGridCoordSimple(float x, float y)
    {
        int gx = (int)(CENTER_GRID_ID - x / SIZE_OF_GRIDS);
        int gy = (int)(CENTER_GRID_ID - y / SIZE_OF_GRIDS);
        return GridCoord((MAX_NUMBER_OF_GRIDS - 1) - gx, (MAX_NUMBER_OF_GRIDS - 1) - gy);
    }

    inline constexpr CellCoord ComputeCellCoord(float x, float y)
    {
        return Compute<TOTAL_NUMBER_OF_CELLS_PER_MAP, CENTER_GRID_CELL_ID>(x, y, CENTER_GRID_CELL_OFFSET, SIZE_OF_GRID_CELL);
    }

    inline constexpr void NormalizeMapCoord(float &c)
    {
        if (c > MAP_HALFSIZE - 0.5f)
            c = MAP_HALFSIZE - 0.5f;
        else if (c < -(MAP_HALFSIZE - 0.5f))
            c = -(MAP_HALFSIZE - 0.5f);
    }

    inline bool IsValidMapCoord(float c)
    {
        return std::isfinite(c) && (std::fabs(c) <= MAP_HALFSIZE - 0.5f);
    }

    inline bool IsValidMapCoord(float x, float y)
    {
        return IsValidMapCoord(x) && IsValidMapCoord(y);
    }

    inline bool IsValidMapCoord(float x, float y, float z)
    {
        return IsValidMapCoord(x, y) && IsValidMapCoord(z);
    }

    inline bool IsValidMapCoord(float x, float y, float z, float o)
    {
        return IsValidMapCoord(x, y, z) && std::isfinite(o);
    }
}
#endif
