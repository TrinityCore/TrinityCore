/*
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

#include "Anticheat.h"

AnticheatManager* AnticheatManager::instance()
{
    static AnticheatManager i;
    return &i;
}

AnticheatManager* GetAnticheatLib()
{
    return AnticheatManager::instance();
}

#ifdef USE_ANTICHEAT

#include "World.h"
#include "WorldSession.h"

#include "MovementAnticheat/MovementAnticheat.h"
#include "WardenAnticheat/Warden.h"
#include "WardenAnticheat/WardenWin.h"
#include "WardenAnticheat/WardenMac.h"

void AnticheatManager::LoadAnticheatData()
{
    sLog.outString();
    sLog.outString("Loading warden checks...");
    sWardenMgr->LoadWardenChecks();
    
    sLog.outString();
    sLog.outString("Loading warden modules...");
    sWardenMgr->LoadWardenModules();
}

MovementAnticheat* AnticheatManager::CreateAnticheatFor(Player* player)
{
    MovementAnticheat* cd = new MovementAnticheat(player);
    cd->Init();
    return cd;
}

Warden* AnticheatManager::CreateWardenFor(WorldSession* client, BigNumber* K)
{
    if ((client->GetSecurity() != SEC_PLAYER) &&
        sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_PLAYERS_ONLY))
        return nullptr;

    Warden* warden;
    ClientOSType os = client->GetOS();

    if (os == CLIENT_OS_MAC && sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_OSX_ENABLED))
        warden = new WardenMac();
    else if (os == CLIENT_OS_WIN && sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_WIN_ENABLED))
        warden = new WardenWin();
    else
        return nullptr;

    warden->Init(client, K);

    return warden;
}

#endif