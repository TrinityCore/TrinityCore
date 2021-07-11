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

#ifndef MANGOS_CELLIMPL_H
#define MANGOS_CELLIMPL_H

#include "Common.h"
#include "Cell.h"
#include "Map.h"
#include <cmath>

inline Cell::Cell(CellPair const& p)
{
    data.Part.grid_x = p.x_coord / MAX_NUMBER_OF_CELLS;
    data.Part.grid_y = p.y_coord / MAX_NUMBER_OF_CELLS;
    data.Part.cell_x = p.x_coord % MAX_NUMBER_OF_CELLS;
    data.Part.cell_y = p.y_coord % MAX_NUMBER_OF_CELLS;
    data.Part.nocreate = 0;
    data.Part.reserved = 0;
}

inline CellArea Cell::CalculateCellArea(float x, float y, float radius)
{
    if (radius <= 0.0f)
    {
        CellPair center = MaNGOS::ComputeCellPair(x, y).normalize();
        return CellArea(center, center);
    }

    return CellArea
    (
        MaNGOS::ComputeCellPair(x - radius, y - radius).normalize(),
        MaNGOS::ComputeCellPair(x + radius, y + radius).normalize()
    );
}

template<class T, class CONTAINER>
inline void
Cell::Visit(CellPair const& standing_cell, TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, WorldObject const& obj, float radius) const
{
    Cell::Visit(standing_cell, visitor, m, obj.GetPositionX(), obj.GetPositionY(), radius + obj.GetObjectBoundingRadius());
}


template<class T, class CONTAINER>
inline void
Cell::Visit(CellPair const& standing_cell, TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, float x, float y, float radius) const
{
    if (standing_cell.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || standing_cell.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
        return;

    //no jokes here... Actually placing ASSERT() here was good idea, but
    //we had some problems with DynamicObjects, which pass radius = 0.0f (DB issue?)
    //maybe it is better to just return when radius <= 0.0f?
    if (radius <= 0.0f)
    {
        m.Visit(*this, visitor);
        return;
    }
    //lets limit the upper value for search radius
    if (radius > 333.0f)
        radius = 333.0f;

    //lets calculate object coord offsets from cell borders.
    CellArea area = Cell::CalculateCellArea(x, y, radius);
    //if radius fits inside standing cell
    if (!area)
    {
        m.Visit(*this, visitor);
        return;
    }

    CellPair& begin_cell = area.low_bound;
    CellPair& end_cell = area.high_bound;
    //visit all cells, found in CalculateCellArea()
    //if radius is known to reach cell area more than 4x4 then we should call optimized VisitCircle
    //currently this technique works with MAX_NUMBER_OF_CELLS 16 and higher, with lower values
    //there are nothing to optimize because SIZE_OF_GRID_CELL is too big...
    if (((end_cell.x_coord - begin_cell.x_coord) > 4) && ((end_cell.y_coord - begin_cell.y_coord) > 4))
    {
        VisitCircle(visitor, m, begin_cell, end_cell);
        return;
    }

    //ALWAYS visit standing cell first!!! Since we deal with small radiuses
    //it is very essential to call visitor for standing cell firstly...
    m.Visit(*this, visitor);

    // loop the cell range
    for(uint32 x = begin_cell.x_coord; x <= end_cell.x_coord; x++)
    {
        for(uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; y++)
        {
            CellPair cell_pair(x,y);
            //lets skip standing cell since we already visited it
            if (cell_pair != standing_cell)
            {
                Cell r_zone(cell_pair);
                r_zone.data.Part.nocreate = data.Part.nocreate;
                m.Visit(r_zone, visitor);
            }
        }
    }
}

template<class T, class CONTAINER>
inline void
Cell::VisitCircle(TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, CellPair const& begin_cell, CellPair const& end_cell) const
{
    //here is an algorithm for 'filling' circum-squared octagon
    uint32 x_shift = (uint32)ceilf((end_cell.x_coord - begin_cell.x_coord) * 0.3f - 0.5f);
    //lets calculate x_start/x_end coords for central strip...
    uint32 const x_start = begin_cell.x_coord + x_shift;
    uint32 const x_end = end_cell.x_coord - x_shift;

    //visit central strip with constant width...
    for(uint32 x = x_start; x <= x_end; ++x)
    {
        for(uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; ++y)
        {
            CellPair cell_pair(x,y);
            Cell r_zone(cell_pair);
            r_zone.data.Part.nocreate = data.Part.nocreate;
            m.Visit(r_zone, visitor);
        }
    }

    //if x_shift == 0 then we have too small cell area, which were already
    //visited at previous step, so just return from procedure...
    if (x_shift == 0)
        return;

    uint32 y_start = end_cell.y_coord;
    uint32 y_end = begin_cell.y_coord;
    //now we are visiting borders of an octagon...
    for (uint32 step = 1; step <= (x_start - begin_cell.x_coord); ++step)
    {
        //each step reduces strip height by 2 cells...
        y_end += 1;
        y_start -= 1;
        for (uint32 y = y_start; y >= y_end; --y)
        {
            //we visit cells symmetrically from both sides, heading from center to sides and from up to bottom
            //e.g. filling 2 trapezoids after filling central cell strip...
            CellPair cell_pair_left(x_start - step, y);
            Cell r_zone_left(cell_pair_left);
            r_zone_left.data.Part.nocreate = data.Part.nocreate;
            m.Visit(r_zone_left, visitor);

            //right trapezoid cell visit
            CellPair cell_pair_right(x_end + step, y);
            Cell r_zone_right(cell_pair_right);
            r_zone_right.data.Part.nocreate = data.Part.nocreate;
            m.Visit(r_zone_right, visitor);
        }
    }
}

template<class T>
inline void Cell::VisitGridObjects(WorldObject const* center_obj, T &visitor, float radius, bool dont_load)
{
    CellPair p(MaNGOS::ComputeCellPair(center_obj->GetPositionX(), center_obj->GetPositionY()));
    Cell cell(p);
    if (dont_load)
        cell.SetNoCreate();
    TypeContainerVisitor<T, GridTypeMapContainer > gnotifier(visitor);
    cell.Visit(p, gnotifier, *center_obj->GetMap(), *center_obj, radius);
}

template<class T>
inline void Cell::VisitWorldObjects(WorldObject const* center_obj, T &visitor, float radius, bool dont_load)
{
    CellPair p(MaNGOS::ComputeCellPair(center_obj->GetPositionX(), center_obj->GetPositionY()));
    Cell cell(p);
    if (dont_load)
        cell.SetNoCreate();
    TypeContainerVisitor<T, WorldTypeMapContainer > gnotifier(visitor);
    cell.Visit(p, gnotifier, *center_obj->GetMap(), *center_obj, radius);
}

template<class T>
inline void Cell::VisitAllObjects(WorldObject const* center_obj, T &visitor, float radius, bool dont_load)
{
    CellPair p(MaNGOS::ComputeCellPair(center_obj->GetPositionX(), center_obj->GetPositionY()));
    Cell cell(p);
    if (dont_load)
        cell.SetNoCreate();
    TypeContainerVisitor<T, GridTypeMapContainer > gnotifier(visitor);
    TypeContainerVisitor<T, WorldTypeMapContainer > wnotifier(visitor);
    cell.Visit(p, gnotifier, *center_obj->GetMap(), *center_obj, radius);
    cell.Visit(p, wnotifier, *center_obj->GetMap(), *center_obj, radius);
}

template<class T>
inline void Cell::VisitGridObjects(float x, float y, Map* map, T &visitor, float radius, bool dont_load)
{
    CellPair p(MaNGOS::ComputeCellPair(x, y));
    Cell cell(p);
    if (dont_load)
        cell.SetNoCreate();
    TypeContainerVisitor<T, GridTypeMapContainer > gnotifier(visitor);
    cell.Visit(p, gnotifier, *map, x, y, radius);
}

template<class T>
inline void Cell::VisitWorldObjects(float x, float y, Map* map, T &visitor, float radius, bool dont_load)
{
    CellPair p(MaNGOS::ComputeCellPair(x, y));
    Cell cell(p);
    if (dont_load)
        cell.SetNoCreate();
    TypeContainerVisitor<T, WorldTypeMapContainer > gnotifier(visitor);
    cell.Visit(p ,gnotifier, *map, x, y, radius);
}

template<class T>
inline void Cell::VisitAllObjects(float x, float y, Map* map, T &visitor, float radius, bool dont_load)
{
    CellPair p(MaNGOS::ComputeCellPair(x, y));
    Cell cell(p);
    if (dont_load)
        cell.SetNoCreate();
    TypeContainerVisitor<T, GridTypeMapContainer > gnotifier(visitor);
    TypeContainerVisitor<T, WorldTypeMapContainer > wnotifier(visitor);
    cell.Visit(p, gnotifier, *map, x, y, radius);
    cell.Visit(p, wnotifier, *map, x, y, radius);
}

#endif
