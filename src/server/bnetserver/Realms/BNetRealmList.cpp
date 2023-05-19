/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "BNetRealmList.h"
#include "DatabaseEnv.h"
#include "DeadlineTimer.h"
#include "DeadlineTimer.h"
#include "IoContext.h"
#include "Log.h"
#include "Resolver.h"
#include "SessionManager.h"
#include "Util.h"
#include "WorldListener.h"
#include <boost/asio/ip/tcp.hpp>

BNetRealmList::BNetRealmList() : _updateInterval(0)
{
}

BNetRealmList::~BNetRealmList() = default;

BNetRealmList* BNetRealmList::Instance()
{
    static BNetRealmList instance;
    return &instance;
}

// Load the realm list from the database
void BNetRealmList::Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval, uint16 worldListenPort)
{
    _updateInterval = updateInterval;
    _updateTimer = Trinity::make_unique<Trinity::Asio::DeadlineTimer>(ioContext);
    _resolver = Trinity::make_unique<Trinity::Asio::Resolver>(ioContext);

    // Get the content of the realmlist table in the database
    UpdateRealms(boost::system::error_code());

    _worldListener = Trinity::make_unique<WorldListener>(worldListenPort);
    _worldListener->Start();
}

void BNetRealmList::Close()
{
    _worldListener->End();
    _updateTimer->cancel();
}

template <typename FieldType>
inline void UpdateField(FieldType& out, FieldType const& in, bool& changed)
{
    if (out != in)
    {
        out = in;
        changed = true;
    }
}

inline void UpdateAddress(std::unique_ptr<boost::asio::ip::address>& out, boost::asio::ip::address&& in, bool& changed)
{
    if (!out || *out != in)
    {
        out = Trinity::make_unique<boost::asio::ip::address>(std::move(in));
        changed = true;
    }
}

void BNetRealmList::UpdateRealm(Battlenet::RealmHandle const& id, uint32 build, std::string const& name,
    boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr, boost::asio::ip::address&& localSubmask,
    uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float population)
{
    // Create new if not exist or update existed
    Realm& realm = _realms[id];
    realm.Keep = true;
    realm.Updated = false;

    realm.Id = id;
    UpdateField(realm.Build, build, realm.Updated);
    UpdateField(realm.Name, name, realm.Updated);
    UpdateField(realm.Type, icon, realm.Updated);
    UpdateField(realm.Flags, flag, realm.Updated);
    UpdateField(realm.Timezone, timezone, realm.Updated);
    UpdateField(realm.AllowedSecurityLevel, allowedSecurityLevel, realm.Updated);
    UpdateField(realm.PopulationLevel, population, realm.Updated);

    UpdateAddress(realm.ExternalAddress, std::forward<boost::asio::ip::address>(address), realm.Updated);
    UpdateAddress(realm.LocalAddress, std::forward<boost::asio::ip::address>(localAddr), realm.Updated);
    UpdateAddress(realm.LocalSubnetMask, std::forward<boost::asio::ip::address>(localSubmask), realm.Updated);

    UpdateField(realm.Port, port, realm.Updated);
}

void BNetRealmList::UpdateRealms(boost::system::error_code const& error)
{
    if (error)
        return;

    TC_LOG_DEBUG("server.bnetserver", "Updating Realm List...");

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALMLIST);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Circle through results and add them to the realm map
    if (result)
    {
        do
        {
            try
            {
                Field* fields = result->Fetch();
                uint32 realmId = fields[0].GetUInt32();
                std::string name = fields[1].GetString();
                std::string externalAddressString = fields[2].GetString();
                std::string localAddressString = fields[3].GetString();
                std::string localSubmaskString = fields[4].GetString();

                Optional<boost::asio::ip::tcp::endpoint> externalAddress = _resolver->Resolve(boost::asio::ip::tcp::v4(), externalAddressString, "");
                if (!externalAddress)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s", externalAddressString.c_str());
                    continue;
                }

                Optional<boost::asio::ip::tcp::endpoint> localAddress = _resolver->Resolve(boost::asio::ip::tcp::v4(), localAddressString, "");
                if (!localAddress)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s", localAddressString.c_str());
                    continue;
                }

                Optional<boost::asio::ip::tcp::endpoint> localSubmask =_resolver->Resolve(boost::asio::ip::tcp::v4(), localSubmaskString, "");
                if (!localSubmask)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s", localSubmaskString.c_str());
                    continue;
                }

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
                uint32 build = fields[11].GetUInt32();
                uint8 region = fields[12].GetUInt8();
                uint8 battlegroup = fields[13].GetUInt8();

                Battlenet::RealmHandle id{ region, battlegroup, realmId };

                UpdateRealm(id, build, name, externalAddress->address(), localAddress->address(), localSubmask->address(), port, icon, flag,
                    timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop);

                TC_LOG_TRACE("server.bnetserver", "Realm \"%s\" at %s:%u.", name.c_str(), externalAddressString.c_str(), port);
            }
            catch (std::exception& ex)
            {
                TC_LOG_ERROR("server.bnetserver", "BNetRealmList::UpdateRealms has thrown an exception: %s", ex.what());
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
        _updateTimer->async_wait(std::bind(&BNetRealmList::UpdateRealms, this, std::placeholders::_1));
    }
}

Realm const* BNetRealmList::GetRealm(Battlenet::RealmHandle const& id) const
{
    auto itr = _realms.find(id);
    if (itr != _realms.end())
        return &itr->second;

    return nullptr;
}
