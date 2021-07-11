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

#include "GridStates.h"
#include "GridNotifiers.h"
#include "GameSystem/Grid.h"
#include "Log.h"

void
InvalidState::Update(Map&, NGridType&, GridInfo&, uint32 const& /*x*/, uint32 const& /*y*/, uint32 const&) const
{
}

void
ActiveState::Update(Map& m, NGridType& grid, GridInfo& info, uint32 const& x, uint32 const& y, uint32 const& t_diff) const
{
    // Only check grid activity every (grid_expiry/10) ms, because it's really useless to do it every cycle
    info.UpdateTimeTracker(t_diff);
    if (info.getTimeTracker().Passed())
    {
        if (grid.ActiveObjectsInGrid() == 0 && !m.ActiveObjectsNearGrid(x, y))
        {
            ObjectGridStoper stoper(grid);
            stoper.StopN();
            grid.SetGridState(GRID_STATE_IDLE);
        }
        else
            m.ResetGridExpiry(grid, 0.1f);
    }
}

void
IdleState::Update(Map& m, NGridType& grid, GridInfo&, uint32 const& x, uint32 const& y, uint32 const&) const
{
    m.ResetGridExpiry(grid);
    grid.SetGridState(GRID_STATE_REMOVAL);
    DEBUG_LOG("Grid[%u,%u] on map %u moved to IDLE state", x, y, m.GetId());
}

void
RemovalState::Update(Map& m, NGridType& grid, GridInfo& info, uint32 const& x, uint32 const& y, uint32 const& t_diff) const
{
    if (!info.getUnloadLock())
    {
        info.UpdateTimeTracker(t_diff);
        if (info.getTimeTracker().Passed())
        {
            if (!m.UnloadGrid(x, y, false))
            {
                DEBUG_LOG("Grid[%u,%u] for map %u differed unloading due to players or active objects nearby", x, y, m.GetId());
                m.ResetGridExpiry(grid);
            }
        }
    }
}
