/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

/** \file
    \ingroup realmd
*/

#include "Common.h"
#include "RealmList.h"
#include "Database/DatabaseEnv.h"

RealmList::RealmList() : m_UpdateInterval(0), m_NextUpdateTime(time(NULL))
{
}

/// Load the realm list from the database
void RealmList::Initialize(uint32 updateInterval)
{
    m_UpdateInterval = updateInterval;

    ///- Get the content of the realmlist table in the database
    UpdateRealms(true);
}

void RealmList::UpdateRealm(uint32 ID, const std::string& name, const std::string& address, uint32 port, uint8 icon, uint8 color, uint8 timezone, AccountTypes allowedSecurityLevel, float popu, uint32 build)
{
    ///- Create new if not exist or update existed
    Realm& realm = m_realms[name];

    realm.m_ID      = ID;
    realm.name      = name;
    realm.icon      = icon;
    realm.color     = color;
    realm.timezone  = timezone;
    realm.allowedSecurityLevel = allowedSecurityLevel;
    realm.populationLevel        = popu;

    ///- Append port to IP address.
    std::ostringstream ss;
    ss << address << ":" << port;
    realm.address   = ss.str();
    realm.gamebuild = build;
}

void RealmList::UpdateIfNeed()
{
    // maybe disabled or updated recently
    if (!m_UpdateInterval || m_NextUpdateTime > time(NULL))
        return;

    m_NextUpdateTime = time(NULL) + m_UpdateInterval;

    // Clears Realm list
    m_realms.clear();

    // Get the content of the realmlist table in the database
    UpdateRealms(false);
}

void RealmList::UpdateRealms(bool init)
{
    sLog.outDetail("Updating Realm List...");

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_REALMLIST);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    ///- Circle through results and add them to the realm map
    if (result)
    {
        do
        {
            uint32 realmId = result->GetUInt32(0); 
            const std::string& name = result->GetString(1);
            const std::string& address = result->GetString(2);
            uint32 port = result->GetUInt32(3);
            uint8 icon = result->GetUInt8(4);
            uint8 color = result->GetUInt8(5);
            uint8 timezone = result->GetUInt8(6);
            uint8 allowedSecurityLevel = result->GetUInt8(7);
            float pop = result->GetFloat(8);
            uint32 build = result->GetUInt32(9);
                        
            UpdateRealm(realmId, name, address, port, icon, color, timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop, build);

            if (init)
                sLog.outString("Added realm \"%s\".", result->GetString(1).c_str());
        }
        while (result->NextRow());
    }
}
