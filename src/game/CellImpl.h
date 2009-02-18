/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#endif

