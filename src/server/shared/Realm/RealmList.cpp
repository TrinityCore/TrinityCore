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

#include "RealmList.h"
#include "BattlenetRpcErrorCodes.h"
#include "CryptoRandom.h"
#include "DatabaseEnv.h"
#include "DeadlineTimer.h"
#include "Log.h"
#include "MapUtils.h"
#include "ProtobufJSON.h"
#include "Resolver.h"
#include "Util.h"
#include "game_utilities_service.pb.h"
#include "RealmList.pb.h"
#include <boost/asio/ip/tcp.hpp>
#include <zlib.h>

namespace
{
bool CompressJson(std::string const& json, std::vector<uint8>* compressed)
{
    uLong uncompressedLength = uLong(json.length() + 1);
    uLong compressedLength = compressBound(uLong(json.length()));
    compressed->resize(compressedLength + 4);
    memcpy(compressed->data(), &uncompressedLength, sizeof(uncompressedLength));

    if (compress(compressed->data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.data()), uncompressedLength) != Z_OK)
    {
        compressed->clear();
        return false;
    }

    compressed->resize(compressedLength + 4);   // trim excess bytes
    return true;
}
}

RealmList::RealmList() : _updateInterval(0)
{
}

RealmList::~RealmList() = default;

RealmList* RealmList::Instance()
{
    static RealmList instance;
    return &instance;
}

// Load the realm list from the database
void RealmList::Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval)
{
    _updateInterval = updateInterval;
    _updateTimer = std::make_unique<Trinity::Asio::DeadlineTimer>(ioContext);
    _resolver = std::make_unique<Trinity::Asio::Resolver>(ioContext);

    LoadBuildInfo();
    // Get the content of the realmlist table in the database
    UpdateRealms();
}

void RealmList::Close()
{
    _updateTimer->cancel();
}

void RealmList::LoadBuildInfo()
{
    //                                                              0             1              2              3      4              5              6
    if (QueryResult result = LoginDatabase.Query("SELECT majorVersion, minorVersion, bugfixVersion, hotfixVersion, build, win64AuthSeed, mac64AuthSeed, macArmAuthSeed FROM build_info ORDER BY build ASC"))
    {
        do
        {
            Field* fields = result->Fetch();
            _builds.emplace_back();
            RealmBuildInfo& build = _builds.back();
            build.MajorVersion = fields[0].GetUInt32();
            build.MinorVersion = fields[1].GetUInt32();
            build.BugfixVersion = fields[2].GetUInt32();
            std::string hotfixVersion = fields[3].GetString();
            if (hotfixVersion.length() < build.HotfixVersion.size())
                std::ranges::copy(hotfixVersion, build.HotfixVersion.begin());
            else
                build.HotfixVersion = { };

            build.Build = fields[4].GetUInt32();
            std::string win64AuthSeedHexStr = fields[5].GetString();
            if (win64AuthSeedHexStr.length() == build.Win64AuthSeed.size() * 2)
                HexStrToByteArray(win64AuthSeedHexStr, build.Win64AuthSeed);
            else
                build.Win64AuthSeed = { };

            std::string mac64AuthSeedHexStr = fields[6].GetString();
            if (mac64AuthSeedHexStr.length() == build.Mac64AuthSeed.size() * 2)
                HexStrToByteArray(mac64AuthSeedHexStr, build.Mac64AuthSeed);
            else
                build.Mac64AuthSeed = { };

            std::string macArmAuthSeedHexStr = fields[7].GetString();
            if (macArmAuthSeedHexStr.length() == build.MacArmAuthSeed.size() * 2)
                HexStrToByteArray(macArmAuthSeedHexStr, build.MacArmAuthSeed);
            else
                build.MacArmAuthSeed = { };

        } while (result->NextRow());
    }
}

void RealmList::UpdateRealm(Realm& realm, Battlenet::RealmHandle const& id, uint32 build, std::string const& name,
    boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr,
    uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel,
    RealmPopulationState population)
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
    realm.Addresses.resize(2);
    realm.Addresses[0] = std::move(address);
    realm.Addresses[1] = std::move(localAddr);
    realm.Port = port;
}

void RealmList::UpdateRealms()
{
    TC_LOG_DEBUG("realmlist", "Updating Realm List...");

    LoginDatabasePreparedStatement *stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALMLIST);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    std::map<Battlenet::RealmHandle, std::string> existingRealms;
    for (auto const& p : _realms)
        existingRealms[p.first] = p.second->Name;

    std::unordered_set<std::string> newSubRegions;
    RealmMap newRealms;

    // Circle through results and add them to the realm map
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 realmId = fields[0].GetUInt32();
            std::string name = fields[1].GetString();
            std::string externalAddressString = fields[2].GetString();
            std::string localAddressString = fields[3].GetString();

            Optional<boost::asio::ip::tcp::endpoint> externalAddress = _resolver->Resolve(boost::asio::ip::tcp::v4(), externalAddressString, "");
            if (!externalAddress)
            {
                TC_LOG_ERROR("realmlist", "Could not resolve address {} for realm \"{}\" id {}", externalAddressString, name, realmId);
                continue;
            }

            Optional<boost::asio::ip::tcp::endpoint> localAddress = _resolver->Resolve(boost::asio::ip::tcp::v4(), localAddressString, "");
            if (!localAddress)
            {
                TC_LOG_ERROR("realmlist", "Could not resolve localAddress {} for realm \"{}\" id {}", localAddressString, name, realmId);
                continue;
            }

            uint16 port = fields[4].GetUInt16();
            uint8 icon = fields[5].GetUInt8();
            if (icon == REALM_TYPE_FFA_PVP)
                icon = REALM_TYPE_PVP;
            if (icon >= MAX_CLIENT_REALM_TYPE)
                icon = REALM_TYPE_NORMAL;
            RealmFlags flag = ConvertLegacyRealmFlags(Trinity::Legacy::RealmFlags(fields[6].GetUInt8()));
            uint8 timezone = fields[7].GetUInt8();
            uint8 allowedSecurityLevel = fields[8].GetUInt8();
            RealmPopulationState pop = ConvertLegacyPopulationState(Trinity::Legacy::RealmFlags(fields[6].GetUInt8()), fields[9].GetFloat());
            uint32 build = fields[10].GetUInt32();
            uint8 region = fields[11].GetUInt8();
            uint8 battlegroup = fields[12].GetUInt8();

            Battlenet::RealmHandle id{ region, battlegroup, realmId };

            UpdateRealm(*newRealms.try_emplace(id, std::make_shared<Realm>()).first->second, id, build, name, externalAddress->address(), localAddress->address(), port, icon,
                flag, timezone, (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), pop);

            newSubRegions.insert(Battlenet::RealmHandle{ region, battlegroup, 0 }.GetAddressString());

            if (!existingRealms.erase(id))
                TC_LOG_INFO("realmlist", "Added realm \"{}\" at {}:{}.", name, externalAddressString, port);
            else
                TC_LOG_DEBUG("realmlist", "Updating realm \"{}\" at {}:{}.", name, externalAddressString, port);
        }
        while (result->NextRow());
    }

    for (auto itr = existingRealms.begin(); itr != existingRealms.end(); ++itr)
        TC_LOG_INFO("realmlist", "Removed realm \"{}\".", itr->second);

    {
        std::unique_lock<std::shared_mutex> lock(_realmsMutex);

        _subRegions.swap(newSubRegions);
        _realms.swap(newRealms);
        _removedRealms.swap(existingRealms);

        if (_currentRealmId)
            if (std::shared_ptr<Realm> realm = Trinity::Containers::MapGetValuePtr(_realms, *_currentRealmId))
                _currentRealmId = realm->Id;    // fill other fields of realm id
    }

    if (_updateInterval)
    {
        _updateTimer->expires_from_now(boost::posix_time::seconds(_updateInterval));
        _updateTimer->async_wait([this](boost::system::error_code const& error)
        {
            if (error)
                return;

            UpdateRealms();
        });
    }
}

std::shared_ptr<Realm const> RealmList::GetRealm(Battlenet::RealmHandle const& id) const
{
    std::shared_lock<std::shared_mutex> lock(_realmsMutex);
    return Trinity::Containers::MapGetValuePtr(_realms, id);
}

Battlenet::RealmHandle RealmList::GetCurrentRealmId() const
{
    return _currentRealmId ? *_currentRealmId : Battlenet::RealmHandle();
}

void RealmList::SetCurrentRealmId(Battlenet::RealmHandle const& id)
{
    _currentRealmId = id;
}

std::shared_ptr<Realm const> RealmList::GetCurrentRealm() const
{
    if (_currentRealmId)
        return GetRealm(*_currentRealmId);
    return nullptr;
}

RealmBuildInfo const* RealmList::GetBuildInfo(uint32 build) const
{
    auto buildInfo = std::ranges::find(_builds, build, &RealmBuildInfo::Build);
    return buildInfo != _builds.end() ? &*buildInfo : nullptr;
}

uint32 RealmList::GetMinorMajorBugfixVersionForBuild(uint32 build) const
{
    auto buildInfo = std::ranges::lower_bound(_builds, build, {}, &RealmBuildInfo::Build);
    return buildInfo != _builds.end() ? (buildInfo->MajorVersion * 10000 + buildInfo->MinorVersion * 100 + buildInfo->BugfixVersion) : 0;
}

void RealmList::WriteSubRegions(bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse* response) const
{
    std::shared_lock<std::shared_mutex> lock(_realmsMutex);
    for (std::string const& subRegion : _subRegions)
        response->add_attribute_value()->set_string_value(subRegion);
}

void RealmList::FillRealmEntry(Realm const& realm, uint32 clientBuild, AccountTypes accountSecurityLevel, JSON::RealmList::RealmEntry* realmEntry) const
{
    realmEntry->set_wowrealmaddress(realm.Id.GetAddress());
    realmEntry->set_cfgtimezonesid(1);
    if (accountSecurityLevel >= realm.AllowedSecurityLevel || realm.PopulationLevel == RealmPopulationState::Offline)
        realmEntry->set_populationstate(AsUnderlyingType(realm.PopulationLevel));
    else
        realmEntry->set_populationstate(AsUnderlyingType(RealmPopulationState::Locked));

    realmEntry->set_cfgcategoriesid(realm.Timezone);

    JSON::RealmList::ClientVersion* version = realmEntry->mutable_version();
    if (RealmBuildInfo const* buildInfo = GetBuildInfo(realm.Build))
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
        version->set_versionbuild(realm.Build);
    }

    RealmFlags flag = realm.Flags;
    if (realm.Build != clientBuild)
        flag |= RealmFlags::VersionMismatch;

    realmEntry->set_cfgrealmsid(realm.Id.Realm);
    realmEntry->set_flags(AsUnderlyingType(flag));
    realmEntry->set_name(realm.Name);
    realmEntry->set_cfgconfigsid(realm.GetConfigId());
    realmEntry->set_cfglanguagesid(1);
}

std::vector<uint8> RealmList::GetRealmEntryJSON(Battlenet::RealmHandle const& id, uint32 build, AccountTypes accountSecurityLevel) const
{
    std::vector<uint8> compressed;
    if (std::shared_ptr<Realm const> realm = GetRealm(id))
    {
        if (realm->PopulationLevel != RealmPopulationState::Offline && realm->Build == build && accountSecurityLevel >= realm->AllowedSecurityLevel)
        {
            JSON::RealmList::RealmEntry realmEntry;
            FillRealmEntry(*realm, build, accountSecurityLevel, &realmEntry);

            std::string json = "JamJSONRealmEntry:" + JSON::Serialize(realmEntry);
            CompressJson(json, &compressed);
        }
    }

    return compressed;
}

std::vector<uint8> RealmList::GetRealmList(uint32 build, AccountTypes accountSecurityLevel, std::string const& subRegion) const
{
    JSON::RealmList::RealmListUpdates realmList;
    {
        std::shared_lock<std::shared_mutex> lock(_realmsMutex);
        for (auto const& [_, realm] : _realms)
        {
            if (realm->Id.GetSubRegionAddress() != subRegion)
                continue;

            JSON::RealmList::RealmListUpdatePart* state = realmList.add_updates();
            FillRealmEntry(*realm, build, accountSecurityLevel, state->mutable_update());
            state->set_deleting(false);
        }

        for (auto const& [id, _] : _removedRealms)
        {
            if (id.GetSubRegionAddress() != subRegion)
                continue;

            JSON::RealmList::RealmListUpdatePart* state = realmList.add_updates();
            state->set_wowrealmaddress(id.GetAddress());
            state->set_deleting(true);
        }
    }

    std::string json = "JSONRealmListUpdates:" + JSON::Serialize(realmList);
    std::vector<uint8> compressed;
    CompressJson(json, &compressed);
    return compressed;
}

uint32 RealmList::JoinRealm(uint32 realmAddress, uint32 build, boost::asio::ip::address const& clientAddress, std::array<uint8, 32> const& clientSecret,
    LocaleConstant locale, std::string const& os, Minutes timezoneOffset, std::string const& accountName, AccountTypes accountSecurityLevel,
    bgs::protocol::game_utilities::v1::ClientResponse* response) const
{
    if (std::shared_ptr<Realm const> realm = GetRealm(realmAddress))
    {
        if (realm->PopulationLevel == RealmPopulationState::Offline || realm->Build != build || accountSecurityLevel < realm->AllowedSecurityLevel)
            return ERROR_USER_SERVER_NOT_PERMITTED_ON_REALM;

        JSON::RealmList::RealmListServerIPAddresses serverAddresses;
        JSON::RealmList::RealmIPAddressFamily* addressFamily = serverAddresses.add_families();
        addressFamily->set_family(1);

        JSON::RealmList::IPAddress* address = addressFamily->add_addresses();
        address->set_ip(realm->GetAddressForClient(clientAddress).to_string());
        address->set_port(realm->Port);

        std::string json = "JSONRealmListServerIPAddresses:" + JSON::Serialize(serverAddresses);
        std::vector<uint8> compressed;

        if (!CompressJson(json, &compressed))
            return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

        std::array<uint8, 32> serverSecret = Trinity::Crypto::GetRandomBytes<32>();

        std::array<uint8, 64> keyData;
        auto keyDestItr = keyData.begin();
        keyDestItr = std::ranges::copy(clientSecret, keyDestItr).out;
        keyDestItr = std::ranges::copy(serverSecret, keyDestItr).out;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LOGIN_INFO);
        stmt->setBinary(0, keyData);
        stmt->setString(1, clientAddress.to_string());
        stmt->setUInt32(2, build);
        stmt->setUInt8(3, locale);
        stmt->setString(4, os);
        stmt->setInt16(5, timezoneOffset.count());
        stmt->setString(6, accountName);
        LoginDatabase.DirectExecute(stmt);

        bgs::protocol::Attribute* attribute = response->add_attribute();
        attribute->set_name("Param_RealmJoinTicket");
        attribute->mutable_value()->set_blob_value(accountName);

        attribute = response->add_attribute();
        attribute->set_name("Param_ServerAddresses");
        attribute->mutable_value()->set_blob_value(compressed.data(), compressed.size());

        attribute = response->add_attribute();
        attribute->set_name("Param_JoinSecret");
        attribute->mutable_value()->set_blob_value(serverSecret.data(), serverSecret.size());
        return ERROR_OK;
    }

    return ERROR_UTIL_SERVER_UNKNOWN_REALM;
}
