/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#ifndef MANGOS_CELL_H
#define MANGOS_CELL_H

#include "GameSystem/TypeContainer.h"
#include "GameSystem/TypeContainerVisitor.h"
#include "GridDefines.h"
#include <cmath>

class Map;
class WorldObject;

struct CellArea
{
    CellArea() {}
    CellArea(CellPair low, CellPair high) : low_bound(low), high_bound(high) {}

    bool operator!() const { return low_bound == high_bound; }

    void ResizeBorders(CellPair& begin_cell, CellPair& end_cell) const
    {
        begin_cell = low_bound;
        end_cell = high_bound;
    }

    CellPair low_bound;
    CellPair high_bound;
};

struct Cell
{
    Cell() { data.All = 0; }
    Cell(Cell const& cell) { data.All = cell.data.All; }
    explicit Cell(CellPair const& p);

    void Compute(uint32& x, uint32& y) const
    {
        x = data.Part.grid_x*MAX_NUMBER_OF_CELLS + data.Part.cell_x;
        y = data.Part.grid_y*MAX_NUMBER_OF_CELLS + data.Part.cell_y;
    }

    bool DiffCell(Cell const& cell) const
    {
        return (data.Part.cell_x != cell.data.Part.cell_x ||
                data.Part.cell_y != cell.data.Part.cell_y);
    }

    bool DiffGrid(Cell const& cell) const
    {
        return (data.Part.grid_x != cell.data.Part.grid_x ||
                data.Part.grid_y != cell.data.Part.grid_y);
    }

    uint32 CellX() const { return data.Part.cell_x; }
    uint32 CellY() const { return data.Part.cell_y; }
    uint32 GridX() const { return data.Part.grid_x; }
    uint32 GridY() const { return data.Part.grid_y; }
    bool NoCreate() const { return data.Part.nocreate; }
    void SetNoCreate() { data.Part.nocreate = 1; }

    GridPair gridPair() const { return GridPair(GridX(),GridY()); }

    CellPair cellPair() const
    {
        return CellPair(
            data.Part.grid_x*MAX_NUMBER_OF_CELLS+data.Part.cell_x,
            data.Part.grid_y*MAX_NUMBER_OF_CELLS+data.Part.cell_y);
    }

    Cell& operator=(Cell const& cell)
    {
        data.All = cell.data.All;
        return *this;
    }

    bool operator==(Cell const& cell) const { return (data.All == cell.data.All); }
    bool operator!=(Cell const& cell) const { return !operator==(cell); }
    union
    {
        struct
        {
            unsigned grid_x : 6;
            unsigned grid_y : 6;
            unsigned cell_x : 6;
            unsigned cell_y : 6;
            unsigned nocreate : 1;
            unsigned reserved : 7;
        } Part;
        uint32 All;
    } data;

    template<class T, class CONTAINER> void Visit(CellPair const& cellPair, TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, float x, float y, float radius) const;
    template<class T, class CONTAINER> void Visit(CellPair const& cellPair, TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, WorldObject const& obj, float radius) const;

    static CellArea CalculateCellArea(float x, float y, float radius);

    template<class T> static void VisitGridObjects(WorldObject const* obj, T &visitor, float radius, bool dont_load = true);
    template<class T> static void VisitWorldObjects(WorldObject const* obj, T &visitor, float radius, bool dont_load = true);
    template<class T> static void VisitAllObjects(WorldObject const* obj, T &visitor, float radius, bool dont_load = true);

    template<class T> static void VisitGridObjects(float x, float y, Map* map, T &visitor, float radius, bool dont_load = true);
    template<class T> static void VisitWorldObjects(float x, float y, Map* map, T &visitor, float radius, bool dont_load = true);
    template<class T> static void VisitAllObjects(float x, float y, Map* map, T &visitor, float radius, bool dont_load = true);

private:
    template<class T, class CONTAINER> void VisitCircle(TypeContainerVisitor<T, CONTAINER>&, Map&, CellPair const&, CellPair const&) const;
};

#endif
