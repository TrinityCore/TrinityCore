/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
            Field* fields = result->Fetch();
            uint32 realmId = fields[0].GetUInt32();
            const std::string& name = fields[1].GetString();
            const std::string& address = fields[2].GetString();
            uint32 port = fields[3].GetUInt32();
            uint8 icon = fields[4].GetUInt8();
            uint8 color = fields[5].GetUInt8();
            uint8 timezone = fields[6].GetUInt8();
            uint8 allowedSecurityLevel = fields[7].GetUInt8();
            float pop = fields[8].GetFloat();
            uint32 build = fields[9].GetUInt32();

            UpdateRealm(realmId, name, address, port, icon, color, timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop, build);

            if (init)
                sLog.outString("Added realm \"%s\".", fields[1].GetCString());
        }
        while (result->NextRow());
    }
}
