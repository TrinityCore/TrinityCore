/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#define MAX_NUMBER_OF_CELLS     8

#define MAX_NUMBER_OF_GRIDS      64

#define SIZE_OF_GRIDS            533.33333f
#define CENTER_GRID_ID           (MAX_NUMBER_OF_GRIDS/2)

#define CENTER_GRID_OFFSET      (SIZE_OF_GRIDS/2)

#define MIN_GRID_DELAY          (MINUTE*IN_MILLISECONDS)
#define MIN_MAP_UPDATE_DELAY    50

#define SIZE_OF_GRID_CELL       (SIZE_OF_GRIDS/MAX_NUMBER_OF_CELLS)

#define CENTER_GRID_CELL_ID     (MAX_NUMBER_OF_CELLS*MAX_NUMBER_OF_GRIDS/2)
#define CENTER_GRID_CELL_OFFSET (SIZE_OF_GRID_CELL/2)

#define TOTAL_NUMBER_OF_CELLS_PER_MAP    (MAX_NUMBER_OF_GRIDS*MAX_NUMBER_OF_CELLS)

#define MAP_RESOLUTION 128

#define MAP_SIZE                (SIZE_OF_GRIDS*MAX_NUMBER_OF_GRIDS)
#define MAP_HALFSIZE            (MAP_SIZE/2)

// Creature used instead pet to simplify *::Visit templates (not required duplicate code for Creature->Pet case)
typedef TYPELIST_4(Player, Creature/*pets*/, Corpse/*resurrectable*/, DynamicObject/*farsight target*/) AllWorldObjectTypes;
typedef TYPELIST_5(GameObject, Creature/*except pets*/, DynamicObject, Corpse/*Bones*/, AreaTrigger) AllGridObjectTypes;

typedef GridRefManager<Corpse>          CorpseMapType;
typedef GridRefManager<Creature>        CreatureMapType;
typedef GridRefManager<DynamicObject>   DynamicObjectMapType;
typedef GridRefManager<GameObject>      GameObjectMapType;
typedef GridRefManager<Player>          PlayerMapType;
typedef GridRefManager<AreaTrigger>     AreaTriggerMapType;

enum GridMapTypeMask
{
    GRID_MAP_TYPE_MASK_CORPSE           = 0x01,
    GRID_MAP_TYPE_MASK_CREATURE         = 0x02,
    GRID_MAP_TYPE_MASK_DYNAMICOBJECT    = 0x04,
    GRID_MAP_TYPE_MASK_GAMEOBJECT       = 0x08,
    GRID_MAP_TYPE_MASK_PLAYER           = 0x10,
    GRID_MAP_TYPE_MASK_AREATRIGGER      = 0x20,
    GRID_MAP_TYPE_MASK_ALL              = 0x3F
};

typedef Grid<Player, AllWorldObjectTypes, AllGridObjectTypes> GridType;
typedef NGrid<MAX_NUMBER_OF_CELLS, Player, AllWorldObjectTypes, AllGridObjectTypes> NGridType;

typedef TypeMapContainer<AllGridObjectTypes> GridTypeMapContainer;
typedef TypeMapContainer<AllWorldObjectTypes> WorldTypeMapContainer;

template<uint32 LIMIT>
struct CoordPair
{
    CoordPair(uint32 x=0, uint32 y=0)
        : x_coord(x), y_coord(y)
    {}

    CoordPair(const CoordPair<LIMIT> &obj)
        : x_coord(obj.x_coord), y_coord(obj.y_coord)
    {}

    CoordPair<LIMIT> & operator=(const CoordPair<LIMIT> &obj)
    {
        x_coord = obj.x_coord;
        y_coord = obj.y_coord;
        return *this;
    }

    void dec_x(uint32 val)
    {
        if (x_coord > val)
            x_coord -= val;
        else
            x_coord = 0;
    }

    void inc_x(uint32 val)
    {
        if (x_coord + val < LIMIT)
            x_coord += val;
        else
            x_coord = LIMIT - 1;
    }

    void dec_y(uint32 val)
    {
        if (y_coord > val)
            y_coord -= val;
        else
            y_coord = 0;
    }

    void inc_y(uint32 val)
    {
        if (y_coord + val < LIMIT)
            y_coord += val;
        else
            y_coord = LIMIT - 1;
    }

    bool IsCoordValid() const
    {
        return x_coord < LIMIT && y_coord < LIMIT;
    }

    CoordPair& normalize()
    {
        x_coord = std::min(x_coord, LIMIT - 1);
        y_coord = std::min(y_coord, LIMIT - 1);
        return *this;
    }

    uint32 GetId() const
    {
        return y_coord * LIMIT + x_coord;
    }

    uint32 x_coord;
    uint32 y_coord;
};

template<uint32 LIMIT>
bool operator==(const CoordPair<LIMIT> &p1, const CoordPair<LIMIT> &p2)
{
    return (p1.x_coord == p2.x_coord && p1.y_coord == p2.y_coord);
}

template<uint32 LIMIT>
bool operator!=(const CoordPair<LIMIT> &p1, const CoordPair<LIMIT> &p2)
{
    return !(p1 == p2);
}

typedef CoordPair<MAX_NUMBER_OF_GRIDS> GridCoord;
typedef CoordPair<TOTAL_NUMBER_OF_CELLS_PER_MAP> CellCoord;

namespace Trinity
{
    template<class RET_TYPE, int CENTER_VAL>
    inline RET_TYPE Compute(float x, float y, float center_offset, float size)
    {
        // calculate and store temporary values in double format for having same result as same mySQL calculations
        double x_offset = (double(x) - center_offset)/size;
        double y_offset = (double(y) - center_offset)/size;

        int x_val = int(x_offset + CENTER_VAL + 0.5f);
        int y_val = int(y_offset + CENTER_VAL + 0.5f);
        return RET_TYPE(x_val, y_val);
    }

    inline GridCoord ComputeGridCoord(float x, float y)
    {
        return Compute<GridCoord, CENTER_GRID_ID>(x, y, CENTER_GRID_OFFSET, SIZE_OF_GRIDS);
    }

    inline CellCoord ComputeCellCoord(float x, float y)
    {
        return Compute<CellCoord, CENTER_GRID_CELL_ID>(x, y, CENTER_GRID_CELL_OFFSET, SIZE_OF_GRID_CELL);
    }

    inline CellCoord ComputeCellCoord(float x, float y, float &x_off, float &y_off)
    {
        double x_offset = (double(x) - CENTER_GRID_CELL_OFFSET)/SIZE_OF_GRID_CELL;
        double y_offset = (double(y) - CENTER_GRID_CELL_OFFSET)/SIZE_OF_GRID_CELL;

        int x_val = int(x_offset + CENTER_GRID_CELL_ID + 0.5f);
        int y_val = int(y_offset + CENTER_GRID_CELL_ID + 0.5f);
        x_off = (float(x_offset) - x_val + CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL;
        y_off = (float(y_offset) - y_val + CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL;
        return CellCoord(x_val, y_val);
    }

    inline void NormalizeMapCoord(float &c)
    {
        if (c > MAP_HALFSIZE - 0.5f)
            c = MAP_HALFSIZE - 0.5f;
        else if (c < -(MAP_HALFSIZE - 0.5f))
            c = -(MAP_HALFSIZE - 0.5f);
    }

    inline bool IsValidMapCoord(float c)
    {
        return finite(c) && (std::fabs(c) <= MAP_HALFSIZE - 0.5f);
    }

    inline bool IsValidMapCoord(float x, float y)
    {
        return IsValidMapCoord(x) && IsValidMapCoord(y);
    }

    inline bool IsValidMapCoord(float x, float y, float z)
    {
        return IsValidMapCoord(x, y) && finite(z);
    }

    inline bool IsValidMapCoord(float x, float y, float z, float o)
    {
        return IsValidMapCoord(x, y, z) && finite(o);
    }
}
#endif
