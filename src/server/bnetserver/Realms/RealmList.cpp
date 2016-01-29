/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "Database/DatabaseEnv.h"
#include "SessionManager.h"
#include "Util.h"
#include "Commands.h"
#include "RealmList.h"
#include <boost/asio/ip/tcp.hpp>

RealmList::RealmList() : _updateInterval(0), _updateTimer(nullptr), _resolver(nullptr), _worldListener(nullptr)
{
}

RealmList::~RealmList()
{
    delete _updateTimer;
    delete _resolver;
    delete _worldListener;
}

// Load the realm list from the database
void RealmList::Initialize(boost::asio::io_service& ioService, uint32 updateInterval, uint16 worldListenPort)
{
    _updateInterval = updateInterval;
    _updateTimer = new boost::asio::deadline_timer(ioService);
    _resolver = new boost::asio::ip::tcp::resolver(ioService);

    // Get the content of the realmlist table in the database
    UpdateRealms(boost::system::error_code());

    _worldListener = new WorldListener(worldListenPort);
    _worldListener->Start();
}

void RealmList::Close()
{
    _worldListener->End();
    _updateTimer->cancel();
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

void RealmList::UpdateRealm(Battlenet::RealmHandle const& id, uint32 build, const std::string& name, ip::address const& address, ip::address const& localAddr,
    ip::address const& localSubmask, uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel,
    float population)
{
    // Create new if not exist or update existed
    Realm& realm = _realms[id];

    realm.Keep = true;

    realm.Id = id;
    UpdateField(realm.Build, build, realm.Updated);
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

    TC_LOG_DEBUG("realmlist", "Updating Realm List...");

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
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s", fields[2].GetString().c_str());
                    continue;
                }

                ip::address externalAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localAddressQuery(ip::tcp::v4(), fields[3].GetString(), "");
                endPoint = _resolver->resolve(localAddressQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s", fields[3].GetString().c_str());
                    continue;
                }

                ip::address localAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localSubmaskQuery(ip::tcp::v4(), fields[4].GetString(), "");
                endPoint = _resolver->resolve(localSubmaskQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s", fields[4].GetString().c_str());
                    continue;
                }

                ip::address localSubmask = (*endPoint).endpoint().address();

                uint16 port = fields[5].GetUInt16();
                uint8 icon = fields[6].GetUInt8();
                if (icon == REALM_TYPE_FFA_PVP)
                    icon = REALM_TYPE_PVP;
                if (icon >= MAX_CLIENT_REALM_TYPE)
                    icon = REALM_TYPE_NORMAL;
                RealmFlags flag = RealmFlags(fields[7].GetUInt8());
                uint8 timezone = fields[8].GetUInt8();
                uint8 allowedSecurityLevel = fields[9].GetUInt8();
                float pop = fields[10].GetFloat();
                uint32 realmId = fields[0].GetUInt32();
                uint32 build = fields[11].GetUInt32();
                uint8 region = fields[12].GetUInt8();
                uint8 battlegroup = fields[13].GetUInt8();

                Battlenet::RealmHandle id{ region, battlegroup, realmId };

                UpdateRealm(id, build, name, externalAddress, localAddress, localSubmask, port, icon, flag,
                    timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop);

                TC_LOG_TRACE("realmlist", "Realm \"%s\" at %s:%u.", name.c_str(), externalAddress.to_string().c_str(), port);
            }
            catch (std::exception& ex)
            {
                TC_LOG_ERROR("realmlist", "Realmlist::UpdateRealms has thrown an exception: %s", ex.what());
                ABORT();
            }
        }
        while (result->NextRow());
    }

    std::vector<Realm const*> updatedRealms;
    std::vector<Battlenet::RealmHandle> deletedRealms;

    for (RealmMap::value_type& pair : _realms)
    {
        if (pair.second.Updated)
            updatedRealms.push_back(&pair.second);
        else if (!pair.second.Keep)
            deletedRealms.push_back(pair.first);

        pair.second.Updated = false;
        pair.second.Keep = false;
    }

    for (Battlenet::RealmHandle const& deleted : deletedRealms)
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

Realm const* RealmList::GetRealm(Battlenet::RealmHandle const& id) const
{
    auto itr = _realms.find(id);
    if (itr != _realms.end())
        return &itr->second;

    return NULL;
}
