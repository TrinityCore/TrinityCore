/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef TRINITY_CELLIMPL_H
#define TRINITY_CELLIMPL_H
#include <cmath>
#include "Cell.h"
#include "Map.h"
#include "Object.h"
inline Cell::Cell(CellPair const& p)
{
    data.Part.grid_x = p.x_coord / MAX_NUMBER_OF_CELLS;
    data.Part.grid_y = p.y_coord / MAX_NUMBER_OF_CELLS;
    data.Part.cell_x = p.x_coord % MAX_NUMBER_OF_CELLS;
    data.Part.cell_y = p.y_coord % MAX_NUMBER_OF_CELLS;
    data.Part.nocreate = 0;
    data.Part.reserved = 0;
}
template<class LOCK_TYPE,class T, class CONTAINER>
inline void
Cell::Visit(const CellLock<LOCK_TYPE> &l, TypeContainerVisitor<T, CONTAINER> &visitor, Map &m) const
{
    const CellPair &standing_cell = l.i_cellPair;
    if (standing_cell.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || standing_cell.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
        return;
    uint16 district = (District)this->data.Part.reserved;
    if(district == CENTER_DISTRICT)
    {
        m.Visit(l, visitor);
        return;
    }
    // set up the cell range based on the district
    // the overloaded operators handle range checking
    CellPair begin_cell = standing_cell;
    CellPair end_cell = standing_cell;
    switch( district )
    {
        case ALL_DISTRICT:
        {
            begin_cell << 1; begin_cell -= 1;               // upper left
            end_cell >> 1; end_cell += 1;                   // lower right
            break;
        }
        case UPPER_LEFT_DISTRICT:
        {
            begin_cell << 1; begin_cell -= 1;               // upper left
            break;
        }
        case UPPER_RIGHT_DISTRICT:
        {
            begin_cell -= 1;                                // up
            end_cell >> 1;                                  // right
            break;
        }
        case LOWER_LEFT_DISTRICT:
        {
            begin_cell << 1;                                // left
            end_cell += 1;                                  // down
            break;
        }
        case LOWER_RIGHT_DISTRICT:
        {
            end_cell >> 1; end_cell += 1;                   // lower right
            break;
        }
        case LEFT_DISTRICT:
        {
            begin_cell -= 1;                                // up
            end_cell >> 1; end_cell += 1;                   // lower right
            break;
        }
        case RIGHT_DISTRICT:
        {
            begin_cell << 1; begin_cell -= 1;               // upper left
            end_cell += 1;                                  // down
            break;
        }
        case UPPER_DISTRICT:
        {
            begin_cell << 1; begin_cell -= 1;               // upper left
            end_cell >> 1;                                  // right
            break;
        }
        case LOWER_DISTRICT:
        {
            begin_cell << 1;                                // left
            end_cell >> 1; end_cell += 1;                   // lower right
            break;
        }
        default:
        {
            assert( false );
            break;
        }
    }
    // loop the cell range
    for(uint32 x = begin_cell.x_coord; x <= end_cell.x_coord; x++)
    {
        for(uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; y++)
        {
            CellPair cell_pair(x,y);
            Cell r_zone(cell_pair);
            r_zone.data.Part.nocreate = l->data.Part.nocreate;
            CellLock<LOCK_TYPE> lock(r_zone, cell_pair);
            m.Visit(lock, visitor);
        }
    }
}
template<class LOCK_TYPE,class T, class CONTAINER>
inline void
Cell::Visit(const CellLock<LOCK_TYPE> &l, TypeContainerVisitor<T, CONTAINER> &visitor, Map &m, float radius, float x_off, float y_off) const
{
    const CellPair &standing_cell = l.i_cellPair;
    if (standing_cell.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || standing_cell.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
        return;
    int left = 0, right = 0, upper = 0, lower = 0;
    // Origin = (CENTER_GRID_CELL_OFFSET, CENTER_GRID_CELL_OFFSET)
    if(CENTER_GRID_CELL_OFFSET - x_off < radius)
        ++right;
    if(CENTER_GRID_CELL_OFFSET + x_off < radius)
        ++left;
    if(CENTER_GRID_CELL_OFFSET - y_off < radius)
        ++upper;
    if(CENTER_GRID_CELL_OFFSET + y_off < radius)
        ++lower;
    if(!left && !right && !upper && !lower)
    {
        m.Visit(l, visitor);
        return;
    }
    CellPair begin_cell = standing_cell;
    CellPair end_cell = standing_cell;
    begin_cell << left; //note: need change << if left > 1
    begin_cell -= lower;
    end_cell >> right;
    end_cell += upper;
    // loop the cell range
    for(uint32 x = begin_cell.x_coord; x <= end_cell.x_coord; x++)
    {
        for(uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; y++)
        {
            CellPair cell_pair(x,y);
            Cell r_zone(cell_pair);
            r_zone.data.Part.nocreate = l->data.Part.nocreate;
            CellLock<LOCK_TYPE> lock(r_zone, cell_pair);
            m.Visit(lock, visitor);
        }
    }
}
inline int CellHelper(const float radius)
{
    if(radius < 1.0f)
        return 0;
    return (int)ceilf(radius/SIZE_OF_GRID_CELL);
}
inline CellArea Cell::CalculateCellArea(const WorldObject &obj, float radius)
{
    if(radius <= 0.0f)
        return CellArea();
    //we should increase search radius by object's radius, otherwise
    //we could have problems with huge creatures, which won't attack nearest players etc
    radius += obj.GetObjectSize();
    //lets calculate object coord offsets from cell borders.
    //TODO: add more correct/generic method for this task
    const float x_offset = (obj.GetPositionX() - CENTER_GRID_CELL_OFFSET)/SIZE_OF_GRID_CELL;
    const float y_offset = (obj.GetPositionY() - CENTER_GRID_CELL_OFFSET)/SIZE_OF_GRID_CELL;
    const float x_val = floor(x_offset + CENTER_GRID_CELL_ID + 0.5f);
    const float y_val = floor(y_offset + CENTER_GRID_CELL_ID + 0.5f);
    const float x_off = (x_offset - x_val + CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL;
    const float y_off = (y_offset - y_val + CENTER_GRID_CELL_ID) * SIZE_OF_GRID_CELL;
    const float tmp_diff = radius - CENTER_GRID_CELL_OFFSET;
    //lets calculate upper/lower/right/left corners for cell search
    int right = CellHelper(tmp_diff + x_off);
    int left = CellHelper(tmp_diff - x_off);
    int upper = CellHelper(tmp_diff + y_off);
    int lower = CellHelper(tmp_diff - y_off);
    return CellArea(right, left, upper, lower);
}
template<class LOCK_TYPE, class T, class CONTAINER>
inline void
Cell::Visit(const CellLock<LOCK_TYPE> &l, TypeContainerVisitor<T, CONTAINER> &visitor, Map &m, const WorldObject &obj, float radius) const
{
    const CellPair &standing_cell = l.i_cellPair;
    if (standing_cell.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || standing_cell.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP)
        return;
    //no jokes here... Actually placing ASSERT() here was good idea, but
    //we had some problems with DynamicObjects, which pass radius = 0.0f (DB issue?)
    //maybe it is better to just return when radius <= 0.0f?
    if(radius <= 0.0f)
    {
        m.Visit(l, visitor);
        return;
    }
    //lets limit the upper value for search radius
    if(radius > 333.0f)
        radius = 333.0f;
    //lets calculate object coord offsets from cell borders.
    CellArea area = Cell::CalculateCellArea(obj, radius);
    //if radius fits inside standing cell
    if(!area)
    {
        m.Visit(l, visitor);
        return;
    }
    CellPair begin_cell = standing_cell;
    CellPair end_cell = standing_cell;
    area.ResizeBorders(begin_cell, end_cell);
    //visit all cells, found in CalculateCellArea()
    //if radius is known to reach cell area more than 4x4 then we should call optimized VisitCircle
    //currently this technique works with MAX_NUMBER_OF_CELLS 16 and higher, with lower values
    //there are nothing to optimize because SIZE_OF_GRID_CELL is too big...
    if(((end_cell.x_coord - begin_cell.x_coord) > 4) && ((end_cell.y_coord - begin_cell.y_coord) > 4))
    {
        VisitCircle(l, visitor, m, begin_cell, end_cell);
        return;
    }
    //ALWAYS visit standing cell first!!! Since we deal with small radiuses
    //it is very essential to call visitor for standing cell firstly...
    m.Visit(l, visitor);
    // loop the cell range
    for(uint32 x = begin_cell.x_coord; x <= end_cell.x_coord; x++)
    {
        for(uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; y++)
        {
            CellPair cell_pair(x,y);
            //lets skip standing cell since we already visited it
            if(cell_pair != standing_cell)
            {
                Cell r_zone(cell_pair);
                r_zone.data.Part.nocreate = l->data.Part.nocreate;
                CellLock<LOCK_TYPE> lock(r_zone, cell_pair);
                m.Visit(lock, visitor);
            }
        }
    }
}
template<class LOCK_TYPE, class T, class CONTAINER>
inline void
Cell::VisitCircle(const CellLock<LOCK_TYPE> &l, TypeContainerVisitor<T, CONTAINER> &visitor, Map &m, const CellPair& begin_cell, const CellPair& end_cell) const
{
    //here is an algorithm for 'filling' circum-squared octagon
    uint32 x_shift = (uint32)ceilf((end_cell.x_coord - begin_cell.x_coord) * 0.3f - 0.5f);
    //lets calculate x_start/x_end coords for central strip...
    const uint32 x_start = begin_cell.x_coord + x_shift;
    const uint32 x_end = end_cell.x_coord - x_shift;
    //visit central strip with constant width...
    for(uint32 x = x_start; x <= x_end; ++x)
    {
        for(uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; ++y)
        {
            CellPair cell_pair(x,y);
            Cell r_zone(cell_pair);
            r_zone.data.Part.nocreate = l->data.Part.nocreate;
            CellLock<LOCK_TYPE> lock(r_zone, cell_pair);
            m.Visit(lock, visitor);
        }
    }
    //if x_shift == 0 then we have too small cell area, which were already
    //visited at previous step, so just return from procedure...
    if(x_shift == 0)
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
            r_zone_left.data.Part.nocreate = l->data.Part.nocreate;
            CellLock<LOCK_TYPE> lock_left(r_zone_left, cell_pair_left);
            m.Visit(lock_left, visitor);
            //right trapezoid cell visit
            CellPair cell_pair_right(x_end + step, y);
            Cell r_zone_right(cell_pair_right);
            r_zone_right.data.Part.nocreate = l->data.Part.nocreate;
            CellLock<LOCK_TYPE> lock_right(r_zone_right, cell_pair_right);
            m.Visit(lock_right, visitor);
        }
    }
}
#endif

