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

#include "RealmList.h"
#include "BattlenetRpcErrorCodes.h"
#include "Database/DatabaseEnv.h"
#include "ProtobufJSON.h"
#include "SHA256.h"
#include "BigNumber.h"
#include "Util.h"
#include "game_utilities_service.pb.h"
#include "RealmList.pb.h"
#include <zlib.h>

RealmList::RealmList() : _updateInterval(0), _updateTimer(nullptr), _resolver(nullptr)
{
}

RealmList::~RealmList()
{
    delete _updateTimer;
}

RealmList* RealmList::Instance()
{
    static RealmList instance;
    return &instance;
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

void RealmList::Close()
{
    _updateTimer->cancel();
}

void RealmList::UpdateRealm(Battlenet::RealmHandle const& id, uint32 build, const std::string& name, ip::address const& address, ip::address const& localAddr,
    ip::address const& localSubmask, uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel,
    float population)
{
    // Create new if not exist or update existed
    Realm& realm = _realms[id];

    realm.Id = id;
    realm.Build = build;
    realm.Name = name;
    realm.Type = icon;
    realm.Flags = flag;
    realm.Timezone = timezone;
    realm.AllowedSecurityLevel = allowedSecurityLevel;
    realm.PopulationLevel = population;
    realm.ExternalAddress = address;
    realm.LocalAddress = localAddr;
    realm.LocalSubnetMask = localSubmask;
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

    _realms.clear();

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
                boost::asio::ip::tcp::resolver::query externalAddressQuery(ip::tcp::v4(), fields[2].GetString(), "");

                boost::system::error_code ec;
                boost::asio::ip::tcp::resolver::iterator endPoint = _resolver->resolve(externalAddressQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve address %s for realm \"%s\" id %u", fields[2].GetString().c_str(), name.c_str(), realmId);
                    continue;
                }

                ip::address externalAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localAddressQuery(ip::tcp::v4(), fields[3].GetString(), "");
                endPoint = _resolver->resolve(localAddressQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve localAddress %s for realm \"%s\" id %u", fields[3].GetString().c_str(), name.c_str(), realmId);
                    continue;
                }

                ip::address localAddress = (*endPoint).endpoint().address();

                boost::asio::ip::tcp::resolver::query localSubmaskQuery(ip::tcp::v4(), fields[4].GetString(), "");
                endPoint = _resolver->resolve(localSubmaskQuery, ec);
                if (endPoint == end || ec)
                {
                    TC_LOG_ERROR("realmlist", "Could not resolve localSubnetMask %s for realm \"%s\" id %u", fields[4].GetString().c_str(), name.c_str(), realmId);
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
                uint32 build = fields[11].GetUInt32();
                uint8 region = fields[12].GetUInt8();
                uint8 battlegroup = fields[13].GetUInt8();

                Battlenet::RealmHandle id{ region, battlegroup, realmId };

                UpdateRealm(id, build, name, externalAddress, localAddress, localSubmask, port, icon, flag,
                    timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop);

                _subRegions.insert(Battlenet::RealmHandle{ region, battlegroup, 0 }.GetAddressString());

                if (!existingRealms.count(id))
                    TC_LOG_INFO("realmlist", "Added realm \"%s\" at %s:%u.", name.c_str(), externalAddress.to_string().c_str(), port);
                else
                    TC_LOG_DEBUG("realmlist", "Updating realm \"%s\" at %s:%u.", name.c_str(), externalAddress.to_string().c_str(), port);

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
    for (std::string const& subRegion : GetSubRegions())
        response->add_attribute_value()->set_string_value(subRegion);
}

std::vector<uint8> RealmList::GetRealmEntryJSON(Battlenet::RealmHandle const& id, uint32 build) const
{
    std::vector<uint8> compressed;
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

            std::string json = "JamJSONRealmEntry:" + JSON::Serialize(realmEntry);

            uLong compressedLength = compressBound(json.length());
            compressed.resize(compressedLength + 4);
            *reinterpret_cast<uint32*>(compressed.data()) = json.length() + 1;

            if (compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), json.length() + 1) == Z_OK)
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

    std::string json = "JSONRealmListUpdates:" + JSON::Serialize(realmList);

    uLong compressedLength = compressBound(json.length());
    std::vector<uint8> compressed;
    compressed.resize(4 + compressedLength);
    *reinterpret_cast<uint32*>(compressed.data()) = json.length() + 1;

    compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), json.length() + 1);

    compressed.resize(compressedLength + 4);

    return compressed;
}

uint32 RealmList::JoinRealm(uint32 realmAddress, uint32 build, boost::asio::ip::address const& clientAddress, std::array<uint8, 32> const& clientSecret,
    LocaleConstant locale, std::string const& os, std::string accountName, bgs::protocol::game_utilities::v1::ClientResponse* response) const
{
    if (Realm const* realm = GetRealm(Battlenet::RealmHandle(realmAddress)))
    {
        if (realm->Flags & REALM_FLAG_OFFLINE || realm->Build != build)
            return ERROR_USER_SERVER_NOT_PERMITTED_ON_REALM;

        JSON::RealmList::RealmListServerIPAddresses serverAddresses;
        JSON::RealmList::RealmIPAddressFamily* addressFamily = serverAddresses.add_families();
        addressFamily->set_family(1);

        JSON::RealmList::IPAddress* address = addressFamily->add_addresses();
        address->set_ip(realm->GetAddressForClient(clientAddress).address().to_string());
        address->set_port(realm->Port);

        std::string json = "JSONRealmListServerIPAddresses:" + JSON::Serialize(serverAddresses);

        uLong compressedLength = compressBound(json.length());
        std::vector<uint8> compressed;
        compressed.resize(4 + compressedLength);
        *reinterpret_cast<uint32*>(compressed.data()) = json.length() + 1;

        if (compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), json.length() + 1) != Z_OK)
            return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

        BigNumber serverSecret;
        serverSecret.SetRand(8 * 32);

        SHA256Hash wowSessionKey;
        wowSessionKey.UpdateData(clientSecret.data(), clientSecret.size());
        wowSessionKey.UpdateData(serverSecret.AsByteArray(32).get(), 32);
        wowSessionKey.Finalize();

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LOGIN_INFO);
        stmt->setString(0, ByteArrayToHexStr(wowSessionKey.GetDigest(), wowSessionKey.GetLength(), true));
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
