/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/** \file
    \ingroup Trinityd
*/

#include "Common.h"
#include "ObjectAccessor.h"
#include "World.h"
#include "WorldSocketMgr.h"
#include "Database/DatabaseEnv.h"
#include "ScriptMgr.h"
#include "BattlegroundMgr.h"
#include "MapManager.h"
#include "Timer.h"
#include "WorldRunnable.h"
#include "OutdoorPvPMgr.h"

#define WORLD_SLEEP_CONST 50

#ifdef _WIN32
#include "ServiceWin32.h"
extern int m_ServiceStatus;
#endif

/// Heartbeat for the World
void WorldRunnable::run()
{
    uint32 realCurrTime = 0;
    uint32 diff = 0;

    sScriptMgr->OnStartup();

    ///- While we have not World::m_stopEvent, update the world
    while (!World::IsStopped())
    {
        ++World::m_worldLoopCounter;
        realCurrTime = getMSTime();
        sWorld->Update(diff);
        diff = getMSTimeDiff(realCurrTime, getMSTime());

        if (diff < WORLD_SLEEP_CONST)
        {
            ACE_Based::Thread::Sleep(WORLD_SLEEP_CONST - diff);
            diff += WORLD_SLEEP_CONST - diff;
        }

        #ifdef _WIN32
            if (m_ServiceStatus == 0)
                World::StopNow(SHUTDOWN_EXIT_CODE);

            while (m_ServiceStatus == 2)
                Sleep(1000);
        #endif
    }

    sScriptMgr->OnShutdown();

    sWorld->KickAll();                                       // save and kick all players
    sWorld->UpdateSessions( 1 );                             // real players unload required UpdateSessions call

    // unload battleground templates before different singletons destroyed
    sBattlegroundMgr->DeleteAllBattlegrounds();

    sWorldSocketMgr->StopNetwork();

    sMapMgr->UnloadAll();                     // unload all grids (including locked in memory)
    sObjectAccessor->UnloadAll();             // unload 'i_player2corpse' storage and remove from world
    sScriptMgr->Unload();
    sOutdoorPvPMgr->Die();
}
