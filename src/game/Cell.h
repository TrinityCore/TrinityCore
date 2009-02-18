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

#ifndef TRINITY_CELL_H
#define TRINITY_CELL_H

#include "GameSystem/TypeContainer.h"
#include "GameSystem/TypeContainerVisitor.h"
#include "GridDefines.h"
#include <cmath>

class Map;

enum District
{
    UPPER_DISTRICT = 1,
    LOWER_DISTRICT = 1 << 1,
    LEFT_DISTRICT  = 1 << 2,
    RIGHT_DISTRICT = 1 << 3,
    CENTER_DISTRICT = 1 << 4,
    UPPER_LEFT_DISTRICT = (UPPER_DISTRICT | LEFT_DISTRICT),
    UPPER_RIGHT_DISTRICT = (UPPER_DISTRICT | RIGHT_DISTRICT),
    LOWER_LEFT_DISTRICT = (LOWER_DISTRICT | LEFT_DISTRICT),
    LOWER_RIGHT_DISTRICT = (LOWER_DISTRICT | RIGHT_DISTRICT),
    ALL_DISTRICT = (UPPER_DISTRICT | LOWER_DISTRICT | LEFT_DISTRICT | RIGHT_DISTRICT | CENTER_DISTRICT)
};

template<class T> struct CellLock;

struct TRINITY_DLL_DECL Cell
{
    Cell() { data.All = 0; }
    Cell(const Cell &cell) { data.All = cell.data.All; }
    explicit Cell(CellPair const& p);

    void operator|=(Cell &cell)
    {
        data.Part.reserved = 0;
        cell.data.Part.reserved = 0;
        uint32 x, y, old_x, old_y;
        Compute(x, y);
        cell.Compute(old_x, old_y);

        if( std::abs(int(x-old_x)) > 1 || std::abs(int(y-old_y)) > 1)
        {
            data.Part.reserved = ALL_DISTRICT;
            cell.data.Part.reserved = ALL_DISTRICT;
            return;
        }

        if( x < old_x )
        {
            data.Part.reserved |= LEFT_DISTRICT;
            cell.data.Part.reserved |= RIGHT_DISTRICT;
        }
        else if( old_x < x )
        {
            data.Part.reserved |= RIGHT_DISTRICT;
            cell.data.Part.reserved |= LEFT_DISTRICT;
        }
        if( y < old_y )
        {
            data.Part.reserved |= UPPER_DISTRICT;
            cell.data.Part.reserved |= LOWER_DISTRICT;
        }
        else if( old_y < y )
        {
            data.Part.reserved |= LOWER_DISTRICT;
            cell.data.Part.reserved |= UPPER_DISTRICT;
        }
    }

    void Compute(uint32 &x, uint32 &y) const
    {
        x = data.Part.grid_x*MAX_NUMBER_OF_CELLS + data.Part.cell_x;
        y = data.Part.grid_y*MAX_NUMBER_OF_CELLS + data.Part.cell_y;
    }

    bool DiffCell(const Cell &cell) const
    {
        return( data.Part.cell_x != cell.data.Part.cell_x ||
            data.Part.cell_y != cell.data.Part.cell_y );
    }

    bool DiffGrid(const Cell &cell) const
    {
        return( data.Part.grid_x != cell.data.Part.grid_x ||
            data.Part.grid_y != cell.data.Part.grid_y );
    }

    uint32 CellX() const { return data.Part.cell_x; }
    uint32 CellY() const { return data.Part.cell_y; }
    uint32 GridX() const { return data.Part.grid_x; }
    uint32 GridY() const { return data.Part.grid_y; }
    bool NoCreate() const { return data.Part.nocreate; }
    void SetNoCreate() { data.Part.nocreate = 1; }

    CellPair cellPair() const
    {
        return CellPair(
            data.Part.grid_x*MAX_NUMBER_OF_CELLS+data.Part.cell_x,
            data.Part.grid_y*MAX_NUMBER_OF_CELLS+data.Part.cell_y);
    }

    Cell& operator=(const Cell &cell)
    {
        this->data.All = cell.data.All;
        return *this;
    }

    bool operator==(const Cell &cell) const { return (data.All == cell.data.All); }
    bool operator!=(const Cell &cell) const { return !operator==(cell); }
    union
    {
        struct
        {
            unsigned grid_x : 6;
            unsigned grid_y : 6;
            unsigned cell_x : 4;
            unsigned cell_y : 4;
            unsigned nocreate : 1;
            unsigned reserved : 11;
        } Part;
        uint32 All;
    } data;

    template<class LOCK_TYPE, class T, class CONTAINER> void Visit(const CellLock<LOCK_TYPE> &, TypeContainerVisitor<T, CONTAINER> &visitor, Map &) const;
    template<class LOCK_TYPE, class T, class CONTAINER> void Visit(const CellLock<LOCK_TYPE> &, TypeContainerVisitor<T, CONTAINER> &visitor, Map &, float radius, float x_off, float y_off) const;
};

template<class T>
struct TRINITY_DLL_DECL CellLock
{
    const Cell& i_cell;
    const CellPair &i_cellPair;
    CellLock(const Cell &c, const CellPair &p) : i_cell(c), i_cellPair(p) {}
    CellLock(const CellLock<T> &cell) : i_cell(cell.i_cell), i_cellPair(cell.i_cellPair) {}
    const Cell* operator->(void) const { return &i_cell; }
    const Cell* operator->(void) { return &i_cell; }
    operator const Cell &(void) const { return i_cell; }
    CellLock<T>& operator=(const CellLock<T> &cell)
    {
        this->~CellLock();
        new (this) CellLock<T>(cell);
        return *this;
    }
};
#endif

