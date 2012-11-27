/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "RealmList.h"
#include "Database/DatabaseEnv.h"

RealmList::RealmList() : m_UpdateInterval(0), m_NextUpdateTime(time(NULL)) { }

// Load the realm list from the database
void RealmList::Initialize(uint32 updateInterval)
{
    m_UpdateInterval = updateInterval;

    // Get the content of the realmlist table in the database
    UpdateRealms(true);
}

void RealmList::UpdateRealm(uint32 ID, const std::string& name, ACE_INET_Addr const& address, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float popu, uint32 build)
{
    // Create new if not exist or update existed
    Realm& realm = m_realms[name];

    realm.m_ID = ID;
    realm.name = name;
    realm.icon = icon;
    realm.flag = flag;
    realm.timezone = timezone;
    realm.allowedSecurityLevel = allowedSecurityLevel;
    realm.populationLevel = popu;

    // Append port to IP address.
    address.addr_to_string(realm.address, ACE_MAX_FULLY_QUALIFIED_NAME_LEN + 16);
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
    UpdateRealms();
}

void RealmList::UpdateRealms(bool init)
{
    sLog->outInfo(LOG_FILTER_AUTHSERVER, "Updating Realm List...");

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALMLIST);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Circle through results and add them to the realm map
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 realmId             = fields[0].GetUInt32();
            std::string name           = fields[1].GetString();
            std::string address        = fields[2].GetString();
            uint16 port                = fields[3].GetUInt16();
            uint8 icon                 = fields[4].GetUInt8();
            RealmFlags flag            = RealmFlags(fields[5].GetUInt8());
            uint8 timezone             = fields[6].GetUInt8();
            uint8 allowedSecurityLevel = fields[7].GetUInt8();
            float pop                  = fields[8].GetFloat();
            uint32 build               = fields[9].GetUInt32();

            ACE_INET_Addr addr(port, address.c_str(), AF_INET);

            UpdateRealm(realmId, name, addr, icon, flag, timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop, build);

            if (init)
                sLog->outInfo(LOG_FILTER_AUTHSERVER, "Added realm \"%s\" at %s.", name.c_str(), m_realms[name].address);
        }
        while (result->NextRow());
    }
}
