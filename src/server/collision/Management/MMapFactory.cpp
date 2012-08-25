/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include <set>

namespace MMAP
{
    // ######################## MMapFactory ########################
    // our global singleton copy
    MMapManager *g_MMapManager = NULL;

    // stores list of mapids which do not use pathfinding
    std::set<uint32>* g_mmapDisabledIds = NULL;

    MMapManager* MMapFactory::createOrGetMMapManager()
    {
        if (g_MMapManager == NULL)
            g_MMapManager = new MMapManager();

        return g_MMapManager;
    }

    void MMapFactory::preventPathfindingOnMaps(const char* ignoreMapIds)
    {
        if (!g_mmapDisabledIds)
            g_mmapDisabledIds = new std::set<uint32>();

        uint32 strLenght = strlen(ignoreMapIds)+1;
        char* mapList = new char[strLenght];
        memcpy(mapList, ignoreMapIds, sizeof(char)*strLenght);

        char* idstr = strtok(mapList, ",");
        while (idstr)
        {
            g_mmapDisabledIds->insert(uint32(atoi(idstr)));
            idstr = strtok(NULL, ",");
        }

        delete[] mapList;
    }

    bool MMapFactory::IsPathfindingEnabled(uint32 mapId)
    {
        return sWorld->getBoolConfig(CONFIG_ENABLE_MMAPS)
            && g_mmapDisabledIds->find(mapId) == g_mmapDisabledIds->end();
    }

    void MMapFactory::clear()
    {
        if (g_mmapDisabledIds)
        {
            delete g_mmapDisabledIds;
            g_mmapDisabledIds = NULL;
        }

        if (g_MMapManager)
        {
            delete g_MMapManager;
            g_MMapManager = NULL;
        }
    }
}