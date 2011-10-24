/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "GridStates.h"
#include "GridNotifiers.h"
#include "Grid.h"
#include "Log.h"

void InvalidState::Update(Map &, NGridType &, GridInfo &, const uint32) const
{
}

void ActiveState::Update(Map &m, NGridType &grid, GridInfo & info, const uint32 t_diff) const
{
    // Only check grid activity every (grid_expiry/10) ms, because it's really useless to do it every cycle
    info.UpdateTimeTracker(t_diff);
    if (info.getTimeTracker().Passed())
    {
        if (grid.ActiveObjectsInGrid() == 0 && !m.ActiveObjectsNearGrid(grid))
        {
            ObjectGridStoper worker;
            TypeContainerVisitor<ObjectGridStoper, GridTypeMapContainer> visitor(worker);
            grid.VisitAllGrids(visitor);
            grid.SetGridState(GRID_STATE_IDLE);
            sLog->outDebug(LOG_FILTER_MAPS, "Grid[%u, %u] on map %u moved to IDLE state", grid.getX(), grid.getY(), m.GetId());
        }
        else
        {
            m.ResetGridExpiry(grid, 0.1f);
        }
    }
}

void IdleState::Update(Map &m, NGridType &grid, GridInfo &, const uint32) const
{
    m.ResetGridExpiry(grid);
    grid.SetGridState(GRID_STATE_REMOVAL);
    sLog->outDebug(LOG_FILTER_MAPS, "Grid[%u, %u] on map %u moved to REMOVAL state", grid.getX(), grid.getY(), m.GetId());
}

void RemovalState::Update(Map &m, NGridType &grid, GridInfo &info, const uint32 t_diff) const
{
    if (!info.getUnloadLock())
    {
        info.UpdateTimeTracker(t_diff);
        if (info.getTimeTracker().Passed())
        {
            if (!m.UnloadGrid(grid, false))
            {
                sLog->outDebug(LOG_FILTER_MAPS, "Grid[%u, %u] for map %u differed unloading due to players or active objects nearby", grid.getX(), grid.getY(), m.GetId());
                m.ResetGridExpiry(grid);
            }
        }
    }
}

