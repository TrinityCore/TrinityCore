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
#include "Database/DatabaseEnv.h"
#include "SessionManager.h"
#include "Util.h"
#include "RealmList.h"

ip::tcp::endpoint Realm::GetAddressForClient(ip::address const& clientAddr) const
{
    ip::address realmIp;

    // Attempt to send best address for client
    if (clientAddr.is_loopback())
    {
        // Try guessing if realm is also connected locally
        if (LocalAddress.is_loopback() || ExternalAddress.is_loopback())
            realmIp = clientAddr;
        else
        {
            // Assume that user connecting from the machine that bnetserver is located on
            // has all realms available in his local network
            realmIp = LocalAddress;
        }
    }
    else
    {
        if (clientAddr.is_v4() &&
            (clientAddr.to_v4().to_ulong() & LocalSubnetMask.to_v4().to_ulong()) ==
            (LocalAddress.to_v4().to_ulong() & LocalSubnetMask.to_v4().to_ulong()))
        {
            realmIp = LocalAddress;
        }
        else
            realmIp = ExternalAddress;
    }

    ip::tcp::endpoint endpoint(realmIp, Port);

    // Return external IP
    return endpoint;
}

RealmList::RealmList() : _updateInterval(0), _updateTimer(nullptr), _resolver(nullptr)
{
}

RealmList::~RealmList()
{
    delete _updateTimer;
    delete _resolver;
}

// Load the realm list from the database
void RealmList::Initialize(boost::asio::io_service& ioService, uint32 updateInterval)
{
    _updateInterval = updateInterval;
    _updateTimer = new boost::asio::deadline_timer(ioService);
    _resolver = new boost::asio::ip::tcp::resolver(ioService);

    // Get the content of the realmlist table in the database
    UpdateRealms(boost::system::error_code());
}

template<typename FieldType>
inline void UpdateField(FieldType& out, FieldType const& in, bool& changed)
{
    if (out != in)
    {
        out = in;
        changed = true;
    }
}

void RealmList::UpdateRealm(Battlenet::RealmId const& id, const std::string& name, ip::address const& address, ip::address const& localAddr,
    ip::address const& localSubmask, uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel,
    float population)
{
    // Create new if not exist or update existed
    Realm& realm = _realms[id];

    realm.Keep = true;
    realm.Updated = false;

    realm.Id = id;
    UpdateField(realm.Name, name, realm.Updated);
    UpdateField(realm.Type, icon, realm.Updated);
    UpdateField(realm.Flags, flag, realm.Updated);
    UpdateField(realm.Timezone, timezone, realm.Updated);
    UpdateField(realm.AllowedSecurityLevel, allowedSecurityLevel, realm.Updated);
    UpdateField(realm.PopulationLevel, population, realm.Updated);
    UpdateField(realm.ExternalAddress, address, realm.Updated);
    UpdateField(realm.LocalAddress, localAddr, realm.Updated);
    UpdateField(realm.LocalSubnetMask, localSubmask, realm.Updated);
    UpdateField(realm.Port, port, realm.Updated);
}

void RealmList::UpdateRealms(boost::system::error_code const& error)
{
    if (error)
        return;

    TC_LOG_INFO("server.bnetserver", "Updating Realm List...");

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
                std::string name = fields[1].GetString();
                boost::asio::ip::tcp::resolver::query externalAddressQuery(ip::tcp::v4(), fields[2].GetString(), "");

                boost::system::error_code ec;
                boost::asio::ip::tcp::resolver::iterator endPoint = _resolver->resolve(externalAddressQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("server.bnetserver", "Could not resolve address %s", fields[2].GetString().c_str());
                    continue;
                }

                ip::address externalAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localAddressQuery(ip::tcp::v4(), fields[3].GetString(), "");
                endPoint = _resolver->resolve(localAddressQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("server.bnetserver", "Could not resolve address %s", fields[3].GetString().c_str());
                    continue;
                }

                ip::address localAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localSubmaskQuery(ip::tcp::v4(), fields[4].GetString(), "");
                endPoint = _resolver->resolve(localSubmaskQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("server.bnetserver", "Could not resolve address %s", fields[4].GetString().c_str());
                    continue;
                }

                ip::address localSubmask = (*endPoint).endpoint().address();

                uint16 port = fields[5].GetUInt16();
                uint8 icon = fields[6].GetUInt8();
                RealmFlags flag = RealmFlags(fields[7].GetUInt8());
                uint8 timezone = fields[8].GetUInt8();
                uint8 allowedSecurityLevel = fields[9].GetUInt8();
                float pop = fields[10].GetFloat();
                uint32 realmId = fields[0].GetUInt32();
                uint32 build = fields[11].GetUInt32();
                uint8 region = fields[12].GetUInt8();
                uint8 battlegroup = fields[13].GetUInt8();

                Battlenet::RealmId id{ region, battlegroup, realmId, build };

                UpdateRealm(id, name, externalAddress, localAddress, localSubmask, port, icon, flag, timezone,
                    (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop);

                //TC_LOG_INFO("server.bnetserver", "Added realm \"%s\" at %s:%u.", name.c_str(), m_realms[id].ExternalAddress.to_string().c_str(), port);
            }
            catch (std::exception& ex)
            {
                TC_LOG_ERROR("server.bnetserver", "Realmlist::UpdateRealms has thrown an exception: %s", ex.what());
                ASSERT(false);
            }
        }
        while (result->NextRow());
    }

    std::vector<Realm const*> updatedRealms;
    std::vector<Battlenet::RealmId> deletedRealms;

    for (RealmMap::value_type const& pair : _realms)
    {
        if (pair.second.Updated)
            updatedRealms.push_back(&pair.second);
        if (!pair.second.Keep)
            deletedRealms.push_back(pair.first);
    }

    for (Battlenet::RealmId const& deleted : deletedRealms)
        _realms.erase(deleted);

    if (!updatedRealms.empty() || !deletedRealms.empty())
    {
        sSessionMgr.LockedForEach([&updatedRealms, &deletedRealms](Battlenet::Session* session)
        {
            if (session->IsSubscribedToRealmListUpdates())
                session->UpdateRealms(updatedRealms, deletedRealms);
        });
    }

    if (_updateInterval)
    {
        _updateTimer->expires_from_now(boost::posix_time::seconds(_updateInterval));
        _updateTimer->async_wait(std::bind(&RealmList::UpdateRealms, this, std::placeholders::_1));
    }
}

Realm const* RealmList::GetRealm(Battlenet::RealmId const& id) const
{
    auto itr = _realms.find(id);
    if (itr != _realms.end())
        return &itr->second;

    return NULL;
}
