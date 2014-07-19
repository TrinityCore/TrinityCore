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

#include <boost/asio/ip/tcp.hpp>
#include "Common.h"
#include "RealmList.h"
#include "BattlenetManager.h"
#include "Database/DatabaseEnv.h"
#include "Util.h"

namespace boost { namespace asio { namespace ip { class address; } } }
ACE_INET_Addr const& Realm::GetAddressForClient(ACE_INET_Addr const& clientAddr) const
{
    // Attempt to send best address for client
    if (clientAddr.is_loopback())
        // Assume that user connecting from the machine that authserver is located on
        // has all realms available in his local network
        return LocalAddress;

    // Check if connecting client is in the same network
    if (IsIPAddrInNetwork(LocalAddress, clientAddr, LocalSubnetMask))
        return LocalAddress;

    // Return external IP
    return ExternalAddress;
}

RealmList::RealmList() : m_UpdateInterval(0), m_NextUpdateTime(time(NULL))
{
}

RealmList::RealmList() : m_UpdateInterval(0), m_NextUpdateTime(time(NULL)), _resolver(nullptr) { }
RealmList::~RealmList()
{
    delete _resolver;
}

// Load the realm list from the database
void RealmList::Initialize(boost::asio::io_service& ioService, uint32 updateInterval)
{
    _resolver = new boost::asio::ip::tcp::resolver(ioService);
    m_UpdateInterval = updateInterval;

    // Get the content of the realmlist table in the database
    UpdateRealms(true);
}

void RealmList::UpdateRealm(uint32 id, const std::string& name, ip::address const& address, ip::address const& localAddr, 
    ip::address const& localSubmask, uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float population, uint32 build, uint8 region, uint8 battlegroup)
{
    // Create new if not exist or update existed
    Realm& realm = m_realms[name];

    realm.m_ID = id;
    realm.name = name;
    realm.icon = icon;
    realm.flag = flag;
    realm.timezone = timezone;
    realm.allowedSecurityLevel = allowedSecurityLevel;
    realm.populationLevel = population;

    // Append port to IP address.

    realm.ExternalAddress = address;
    realm.LocalAddress = localAddr;
    realm.LocalSubnetMask = localSubmask;
    realm.port = port;
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
            try
            {
                boost::asio::ip::tcp::resolver::iterator end;

                Field* fields = result->Fetch();
                uint32 realmId = fields[0].GetUInt32();
                std::string name = fields[1].GetString();
                boost::asio::ip::tcp::resolver::query externalAddressQuery(fields[2].GetString(), "");
                boost::asio::ip::tcp::resolver::iterator endPoint = _resolver->resolve(externalAddressQuery);
                if (endPoint == end)
                {
                    TC_LOG_ERROR("server.authserver", "Could not resolve address %s", fields[2].GetString().c_str());
                    return;
                }

                ip::address externalAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localAddressQuery(fields[3].GetString(), "");
                endPoint = _resolver->resolve(localAddressQuery);
                if (endPoint == end)
                {
                    TC_LOG_ERROR("server.authserver", "Could not resolve address %s", fields[3].GetString().c_str());
                    return;
                }

                ip::address localAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localSubmaskQuery(fields[4].GetString(), "");
                endPoint = _resolver->resolve(localSubmaskQuery);
                if (endPoint == end)
                {
                    TC_LOG_ERROR("server.authserver", "Could not resolve address %s", fields[4].GetString().c_str());
                    return;
                }

                ip::address localSubmask = (*endPoint).endpoint().address();

                uint16 port = fields[5].GetUInt16();
                uint8 icon = fields[6].GetUInt8();
                RealmFlags flag = RealmFlags(fields[7].GetUInt8());
                uint8 timezone = fields[8].GetUInt8();
                uint8 allowedSecurityLevel = fields[9].GetUInt8();
                float pop = fields[10].GetFloat();
                uint32 build = fields[11].GetUInt32();
                uint8 region                = fields[12].GetUInt8();
                uint8 battlegroup           = fields[13].GetUInt8();

                UpdateRealm(realmId, name, externalAddress, localAddress, localSubmask, port, icon, flag, timezone,
                    (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop, build, region, battlegroup);

                if (init)
                    TC_LOG_INFO("server.authserver", "Added realm \"%s\" at %s:%u.", name.c_str(), m_realms[name].ExternalAddress.to_string().c_str(), port);
            }
            catch (std::exception& ex)
            {
                TC_LOG_ERROR("server.authserver", "Realmlist::UpdateRealms has thrown an exception: %s", ex.what());
                ASSERT(false);
            }
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
