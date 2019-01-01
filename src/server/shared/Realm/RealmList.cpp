/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "RealmList.h"
#include "BattlenetRpcErrorCodes.h"
#include "BigNumber.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "IoContext.h"
#include "Log.h"
#include "ProtobufJSON.h"
#include "Resolver.h"
#include "Util.h"
#include "game_utilities_service.pb.h"
#include "RealmList.pb.h"
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <zlib.h>

RealmList::RealmList() : _updateInterval(0)
{
    _realmsMutex = Trinity::make_unique<boost::shared_mutex>();
}

RealmList::~RealmList()
{
}

RealmList* RealmList::Instance()
{
    static RealmList instance;
    return &instance;
}

// Load the realm list from the database
void RealmList::Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval)
{
    _updateInterval = updateInterval;
    _updateTimer = Trinity::make_unique<boost::asio::deadline_timer>(ioContext);
    _resolver = Trinity::make_unique<boost::asio::ip::tcp::resolver>(ioContext);

    // Get the content of the realmlist table in the database
    UpdateRealms(boost::system::error_code());
}

void RealmList::Close()
{
    _updateTimer->cancel();
}

void RealmList::UpdateRealm(Realm& realm, Battlenet::RealmHandle const& id, uint32 build, std::string const& name,
    boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr, boost::asio::ip::address&& localSubmask,
    uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel,
    float population)
{
    realm.Id = id;
    realm.Build = build;
    if (realm.Name != name)
        realm.SetName(name);
    realm.Type = icon;
    realm.Flags = flag;
    realm.Timezone = timezone;
    realm.AllowedSecurityLevel = allowedSecurityLevel;
    realm.PopulationLevel = population;
    if (!realm.ExternalAddress || *realm.ExternalAddress != address)
        realm.ExternalAddress = Trinity::make_unique<boost::asio::ip::address>(std::move(address));
    if (!realm.LocalAddress || *realm.LocalAddress != localAddr)
        realm.LocalAddress = Trinity::make_unique<boost::asio::ip::address>(std::move(localAddr));
    if (!realm.LocalSubnetMask || *realm.LocalSubnetMask != localSubmask)
        realm.LocalSubnetMask = Trinity::make_unique<boost::asio::ip::address>(std::move(localSubmask));
    realm.Port = port;
}

void RealmList::UpdateRealms(boost::system::error_code const& error)
{
    if (error)
        return;

    TC_LOG_DEBUG("realmlist", "Updating Realm List...");

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALMLIST);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    std::map<Battlenet::RealmHandle, std::string> existingRealms;
    for (auto const& p : _realms)
        existingRealms[p.first] = p.second.Name;

    std::unordered_set<std::string> newSubRegions;
    RealmMap newRealms;

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

                Optional<boost::asio::ip::tcp::endpoint> externalAddress = Trinity::Net::Resolve(*_resolver, boost::asio::ip::tcp::v4(), externalAddressString, "");
                if (!externalAddress)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s for realm \"%s\" id %u", externalAddressString.c_str(), name.c_str(), realmId);
                    continue;
                }

                Optional<boost::asio::ip::tcp::endpoint> localAddress = Trinity::Net::Resolve(*_resolver, boost::asio::ip::tcp::v4(), localAddressString, "");
                if (!localAddress)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve localAddress %s for realm \"%s\" id %u", localAddressString.c_str(), name.c_str(), realmId);
                    continue;
                }

                Optional<boost::asio::ip::tcp::endpoint> localSubmask = Trinity::Net::Resolve(*_resolver, boost::asio::ip::tcp::v4(), localSubmaskString, "");
                if (!localSubmask)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve localSubnetMask %s for realm \"%s\" id %u", localSubmaskString.c_str(), name.c_str(), realmId);
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

                UpdateRealm(newRealms[id], id, build, name, externalAddress->address(), localAddress->address(), localSubmask->address(), port, icon,
                    flag, timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop);

                newSubRegions.insert(Battlenet::RealmHandle{ region, battlegroup, 0 }.GetAddressString());

                if (!existingRealms.count(id))
                    TC_LOG_INFO("realmlist", "Added realm \"%s\" at %s:%u.", name.c_str(), externalAddressString.c_str(), port);
                else
                    TC_LOG_DEBUG("realmlist", "Updating realm \"%s\" at %s:%u.", name.c_str(), externalAddressString.c_str(), port);

                existingRealms.erase(id);
            }
            catch (std::exception& ex)
            {
                TC_LOG_ERROR("realmlist", "Realmlist::UpdateRealms has thrown an exception: %s", ex.what());
                ABORT();
            }
        }
        while (result->NextRow());
    }

    for (auto itr = existingRealms.begin(); itr != existingRealms.end(); ++itr)
        TC_LOG_INFO("realmlist", "Removed realm \"%s\".", itr->second.c_str());

    {
        std::unique_lock<boost::shared_mutex> lock(*_realmsMutex);

        _subRegions.swap(newSubRegions);
        _realms.swap(newRealms);
    }

    if (_updateInterval)
    {
        _updateTimer->expires_from_now(boost::posix_time::seconds(_updateInterval));
        _updateTimer->async_wait(std::bind(&RealmList::UpdateRealms, this, std::placeholders::_1));
    }
}

Realm const* RealmList::GetRealm(Battlenet::RealmHandle const& id) const
{
    boost::shared_lock<boost::shared_mutex> lock(*_realmsMutex);
    auto itr = _realms.find(id);
    if (itr != _realms.end())
        return &itr->second;

    return NULL;
}

RealmBuildInfo const* RealmList::GetBuildInfo(uint32 build) const
{
    // List of client builds for verbose version info in realmlist packet
    static std::vector<RealmBuildInfo> const ClientBuilds =
    {
        { 21355, 6, 2, 4, ' ' },
        { 20726, 6, 2, 3, ' ' },
        { 20574, 6, 2, 2, 'a' },
        { 20490, 6, 2, 2, 'a' },
        { 15595, 4, 3, 4, ' ' },
        { 14545, 4, 2, 2, ' ' },
        { 13623, 4, 0, 6, 'a' },
        { 13930, 3, 3, 5, 'a' },                                  // 3.3.5a China Mainland build
        { 12340, 3, 3, 5, 'a' },
        { 11723, 3, 3, 3, 'a' },
        { 11403, 3, 3, 2, ' ' },
        { 11159, 3, 3, 0, 'a' },
        { 10505, 3, 2, 2, 'a' },
        { 9947,  3, 1, 3, ' ' },
        { 8606,  2, 4, 3, ' ' },
        { 6141,  1, 12, 3, ' ' },
        { 6005,  1, 12, 2, ' ' },
        { 5875,  1, 12, 1, ' ' },
    };

    for (std::size_t i = 0; i < ClientBuilds.size(); ++i)
        if (ClientBuilds[i].Build == build)
            return &ClientBuilds[i];

    return nullptr;
}

void RealmList::WriteSubRegions(bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse* response) const
{
    boost::shared_lock<boost::shared_mutex> lock(*_realmsMutex);
    for (std::string const& subRegion : _subRegions)
        response->add_attribute_value()->set_string_value(subRegion);
}

std::vector<uint8> RealmList::GetRealmEntryJSON(Battlenet::RealmHandle const& id, uint32 build) const
{
    std::vector<uint8> compressed;
    boost::shared_lock<boost::shared_mutex> lock(*_realmsMutex);
    if (Realm const* realm = GetRealm(id))
    {
        if (!(realm->Flags & REALM_FLAG_OFFLINE) && realm->Build == build)
        {
            JSON::RealmList::RealmEntry realmEntry;
            realmEntry.set_wowrealmaddress(realm->Id.GetAddress());
            realmEntry.set_cfgtimezonesid(1);
            realmEntry.set_populationstate(std::max(uint32(realm->PopulationLevel), 1u));
            realmEntry.set_cfgcategoriesid(realm->Timezone);

            JSON::RealmList::ClientVersion* version = realmEntry.mutable_version();
            if (RealmBuildInfo const* buildInfo = GetBuildInfo(realm->Build))
            {
                version->set_versionmajor(buildInfo->MajorVersion);
                version->set_versionminor(buildInfo->MinorVersion);
                version->set_versionrevision(buildInfo->BugfixVersion);
                version->set_versionbuild(buildInfo->Build);
            }
            else
            {
                version->set_versionmajor(6);
                version->set_versionminor(2);
                version->set_versionrevision(4);
                version->set_versionbuild(realm->Build);
            }

            realmEntry.set_cfgrealmsid(realm->Id.Realm);
            realmEntry.set_flags(realm->Flags);
            realmEntry.set_name(realm->Name);
            realmEntry.set_cfgconfigsid(realm->GetConfigId());
            realmEntry.set_cfglanguagesid(1);

            lock.unlock();

            std::string json = "JamJSONRealmEntry:" + JSON::Serialize(realmEntry);

            uLong compressedLength = compressBound(uLong(json.length()));
            compressed.resize(compressedLength + 4);
            *reinterpret_cast<uint32*>(compressed.data()) = uint32(json.length() + 1);

            if (compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), uLong(json.length() + 1)) == Z_OK)
                compressed.resize(compressedLength + 4);
            else
                compressed.clear();
        }
    }

    return compressed;
}

std::vector<uint8> RealmList::GetRealmList(uint32 build, std::string const& subRegion) const
{
    JSON::RealmList::RealmListUpdates realmList;
    {
        boost::shared_lock<boost::shared_mutex> lock(*_realmsMutex);
        for (auto const& realm : _realms)
        {
            if (realm.second.Id.GetSubRegionAddress() != subRegion)
                continue;

            uint32 flag = realm.second.Flags;
            if (realm.second.Build != build)
                flag |= REALM_FLAG_VERSION_MISMATCH;

            JSON::RealmList::RealmState* state = realmList.add_updates();
            state->mutable_update()->set_wowrealmaddress(realm.second.Id.GetAddress());
            state->mutable_update()->set_cfgtimezonesid(1);
            state->mutable_update()->set_populationstate((realm.second.Flags & REALM_FLAG_OFFLINE) ? 0u : std::max(uint32(realm.second.PopulationLevel), 1u));
            state->mutable_update()->set_cfgcategoriesid(realm.second.Timezone);

            JSON::RealmList::ClientVersion* version = state->mutable_update()->mutable_version();
            if (RealmBuildInfo const* buildInfo = GetBuildInfo(realm.second.Build))
            {
                version->set_versionmajor(buildInfo->MajorVersion);
                version->set_versionminor(buildInfo->MinorVersion);
                version->set_versionrevision(buildInfo->BugfixVersion);
                version->set_versionbuild(buildInfo->Build);
            }
            else
            {
                version->set_versionmajor(6);
                version->set_versionminor(2);
                version->set_versionrevision(4);
                version->set_versionbuild(realm.second.Build);
            }

            state->mutable_update()->set_cfgrealmsid(realm.second.Id.Realm);
            state->mutable_update()->set_flags(flag);
            state->mutable_update()->set_name(realm.second.Name);
            state->mutable_update()->set_cfgconfigsid(realm.second.GetConfigId());
            state->mutable_update()->set_cfglanguagesid(1);

            state->set_deleting(false);
        }
    }

    std::string json = "JSONRealmListUpdates:" + JSON::Serialize(realmList);

    uLong compressedLength = compressBound(uLong(json.length()));
    std::vector<uint8> compressed;
    compressed.resize(4 + compressedLength);
    *reinterpret_cast<uint32*>(compressed.data()) = uint32(json.length() + 1);

    compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), uLong(json.length() + 1));

    compressed.resize(compressedLength + 4);

    return compressed;
}

uint32 RealmList::JoinRealm(uint32 realmAddress, uint32 build, boost::asio::ip::address const& clientAddress, std::array<uint8, 32> const& clientSecret,
    LocaleConstant locale, std::string const& os, std::string accountName, bgs::protocol::game_utilities::v1::ClientResponse* response) const
{
    boost::shared_lock<boost::shared_mutex> lock(*_realmsMutex);
    if (Realm const* realm = GetRealm(Battlenet::RealmHandle(realmAddress)))
    {
        if (realm->Flags & REALM_FLAG_OFFLINE || realm->Build != build)
            return ERROR_USER_SERVER_NOT_PERMITTED_ON_REALM;

        JSON::RealmList::RealmListServerIPAddresses serverAddresses;
        JSON::RealmList::RealmIPAddressFamily* addressFamily = serverAddresses.add_families();
        addressFamily->set_family(1);

        JSON::RealmList::IPAddress* address = addressFamily->add_addresses();
        address->set_ip(realm->GetAddressForClient(clientAddress).to_string());
        address->set_port(realm->Port);

        lock.unlock();

        std::string json = "JSONRealmListServerIPAddresses:" + JSON::Serialize(serverAddresses);

        uLong compressedLength = compressBound(uLong(json.length()));
        std::vector<uint8> compressed;
        compressed.resize(4 + compressedLength);
        *reinterpret_cast<uint32*>(compressed.data()) = uint32(json.length() + 1);

        if (compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), uLong(json.length() + 1)) != Z_OK)
            return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

        BigNumber serverSecret;
        serverSecret.SetRand(8 * 32);

        std::array<uint8, 64> keyData;
        memcpy(&keyData[0], clientSecret.data(), 32);
        memcpy(&keyData[32], serverSecret.AsByteArray(32).get(), 32);

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LOGIN_INFO);
        stmt->setString(0, ByteArrayToHexStr(keyData.data(), keyData.size()));
        stmt->setString(1, clientAddress.to_string());
        stmt->setUInt8(2, locale);
        stmt->setString(3, os);
        stmt->setString(4, accountName);
        LoginDatabase.DirectExecute(stmt);

        bgs::protocol::Attribute* attribute = response->add_attribute();
        attribute->set_name("Param_RealmJoinTicket");
        attribute->mutable_value()->set_blob_value(accountName);

        attribute = response->add_attribute();
        attribute->set_name("Param_ServerAddresses");
        attribute->mutable_value()->set_blob_value(compressed.data(), compressedLength + 4);

        attribute = response->add_attribute();
        attribute->set_name("Param_JoinSecret");
        attribute->mutable_value()->set_blob_value(serverSecret.AsByteArray(32).get(), 32);
        return ERROR_OK;
    }

    return ERROR_UTIL_SERVER_UNKNOWN_REALM;
}
