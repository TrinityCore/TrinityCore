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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "GridStates.h"
#include "GridNotifiers.h"
#include "GameSystem/Grid.h"
#include "Log.h"

void
InvalidState::Update(Map &, NGridType &, GridInfo &, const uint32 &/*x*/, const uint32 &/*y*/, const uint32 &) const
{
}

void
ActiveState::Update(Map &m, NGridType &grid, GridInfo & info, const uint32 &x, const uint32 &y, const uint32 &t_diff) const
{
    // Only check grid activity every (grid_expiry/10) ms, because it's really useless to do it every cycle
    info.UpdateTimeTracker(t_diff);
    if( info.getTimeTracker().Passed() )
    {
        if( grid.ActiveObjectsInGrid() == 0 && !m.ActiveObjectsNearGrid(x, y) )
        {
            ObjectGridStoper stoper(grid);
            stoper.StopN();
            grid.SetGridState(GRID_STATE_IDLE);
        }
        else
        {
            m.ResetGridExpiry(grid, 0.1f);
        }
    }
}

void
IdleState::Update(Map &m, NGridType &grid, GridInfo &, const uint32 &x, const uint32 &y, const uint32 &) const
{
    m.ResetGridExpiry(grid);
    grid.SetGridState(GRID_STATE_REMOVAL);
    sLog.outDebug("Grid[%u,%u] on map %u moved to IDLE state", x, y, m.GetId());
}

void
RemovalState::Update(Map &m, NGridType &grid, GridInfo &info, const uint32 &x, const uint32 &y, const uint32 &t_diff) const
{
    if(!info.getUnloadLock())
    {
        info.UpdateTimeTracker(t_diff);
        if( info.getTimeTracker().Passed() )
        {
            if( !m.UnloadGrid(x, y, false) )
            {
                sLog.outDebug("Grid[%u,%u] for map %u differed unloading due to players or active objects nearby", x, y, m.GetId());
                m.ResetGridExpiry(grid);
            }
        }
    }
}

