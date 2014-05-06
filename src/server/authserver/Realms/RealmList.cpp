/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "BattlenetManager.h"
#include "Database/DatabaseEnv.h"

RealmList::RealmList() : m_UpdateInterval(0), m_NextUpdateTime(time(NULL)) { }

// Load the realm list from the database
void RealmList::Initialize(uint32 updateInterval)
{
    m_UpdateInterval = updateInterval;

    // Get the content of the realmlist table in the database
    UpdateRealms(true);
}

void RealmList::UpdateRealm(uint32 id, const std::string& name, ACE_INET_Addr const& address, ACE_INET_Addr const& localAddr, ACE_INET_Addr const& localSubmask, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float popu, uint32 build, uint8 region, uint8 battlegroup)
{
    // Create new if not exist or update existed
    Realm& realm = m_realms[name];

    realm.m_ID = id;
    realm.name = name;
    realm.icon = icon;
    realm.flag = flag;
    realm.timezone = timezone;
    realm.allowedSecurityLevel = allowedSecurityLevel;
    realm.populationLevel = popu;

    // Append port to IP address.
    realm.ExternalAddress = address;
    realm.LocalAddress = localAddr;
    realm.LocalSubnetMask = localSubmask;
    realm.gamebuild = build;
    realm.Region = region;
    realm.Battlegroup = battlegroup;
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
    TC_LOG_INFO("server.authserver", "Updating Realm List...");

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALMLIST);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Circle through results and add them to the realm map
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 realmId              = fields[0].GetUInt32();
            std::string name            = fields[1].GetString();
            std::string externalAddress = fields[2].GetString();
            std::string localAddress    = fields[3].GetString();
            std::string localSubmask    = fields[4].GetString();
            uint16 port                 = fields[5].GetUInt16();
            uint8 icon                  = fields[6].GetUInt8();
            RealmFlags flag             = RealmFlags(fields[7].GetUInt8());
            uint8 timezone              = fields[8].GetUInt8();
            uint8 allowedSecurityLevel  = fields[9].GetUInt8();
            float pop                   = fields[10].GetFloat();
            uint32 build                = fields[11].GetUInt32();
            uint8 region                = fields[12].GetUInt8();
            uint8 battlegroup           = fields[13].GetUInt8();

            ACE_INET_Addr externalAddr(port, externalAddress.c_str(), AF_INET);
            ACE_INET_Addr localAddr(port, localAddress.c_str(), AF_INET);
            ACE_INET_Addr submask(0, localSubmask.c_str(), AF_INET);

            UpdateRealm(realmId, name, externalAddr, localAddr, submask, icon, flag, timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop, build, region, battlegroup);

            if (init)
                TC_LOG_INFO("server.authserver", "Added realm \"%s\" at %s:%u.", name.c_str(), m_realms[name].ExternalAddress.get_host_addr(), port);
        }
        while (result->NextRow());
    }
}

Realm const* RealmList::GetRealm(Battlenet::RealmId const& id) const
{
    auto itr = std::find_if(m_realms.begin(), m_realms.end(), [id](RealmMap::value_type const& pair)
    {
        return pair.second.Region == id.Region && pair.second.Battlegroup == id.Battlegroup && pair.second.m_ID == id.Index;
    });

    if (itr != m_realms.end())
        return &itr->second;

    return NULL;
}
