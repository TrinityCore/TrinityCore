/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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

#include "MMapFactory.h"
#include "World.h"
#include "Config.h"
#include "DisableMgr.h"

namespace MMAP
{
    // ######################## MMapFactory ########################
    // our global singleton copy
    MMapManager* _manager = NULL;

    MMapManager* MMapFactory::CreateOrGetMMapManager()
    {
        if (_manager == NULL)
            _manager = new MMapManager();

        return _manager;
    }

    bool MMapFactory::IsPathfindingEnabled(uint32 mapId)
    {
        return sWorld->getBoolConfig(CONFIG_ENABLE_MMAPS)
            && !DisableMgr::IsDisabledFor(DISABLE_TYPE_MMAP, mapId, NULL, MMAP_DISABLE_PATHFINDING);
    }

    void MMapFactory::Clear()
    {
        if (_manager)
        {
            delete _manager;
            _manager = NULL;
        }
    }
}