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

#ifndef _REALMLIST_H
#define _REALMLIST_H

#include "Define.h"
#include "Duration.h"
#include "Optional.h"
#include "Realm.h"
#include <array>
#include <map>
#include <memory>
#include <shared_mutex>
#include <unordered_set>
#include <vector>

struct RealmBuildInfo
{
    uint32 Build;
    uint32 MajorVersion;
    uint32 MinorVersion;
    uint32 BugfixVersion;
    std::array<char, 4> HotfixVersion;
    std::array<uint8, 16> Win64AuthSeed;
    std::array<uint8, 16> Mac64AuthSeed;
};

namespace bgs::protocol::game_utilities::v1
{
class ClientResponse;
class GetAllValuesForAttributeResponse;
}

namespace JSON::RealmList
{
class RealmEntry;
}

/// Storage object for the list of realms on the server
class TC_SHARED_API RealmList
{
public:
    typedef std::map<Battlenet::RealmHandle, std::shared_ptr<Realm>> RealmMap;

    static RealmList* Instance();

    RealmList(RealmList const&) = delete;
    RealmList(RealmList&&) = delete;
    RealmList& operator=(RealmList const&) = delete;
    RealmList& operator=(RealmList&&) = delete;

    ~RealmList();

    void Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval);
    void Close();

    std::shared_ptr<Realm const> GetRealm(Battlenet::RealmHandle const& id) const;
    Battlenet::RealmHandle GetCurrentRealmId() const;
    void SetCurrentRealmId(Battlenet::RealmHandle const& id);
    std::shared_ptr<Realm const> GetCurrentRealm() const;

    RealmBuildInfo const* GetBuildInfo(uint32 build) const;
    uint32 GetMinorMajorBugfixVersionForBuild(uint32 build) const;
    void WriteSubRegions(bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse* response) const;
    std::vector<uint8> GetRealmEntryJSON(Battlenet::RealmHandle const& id, uint32 build, AccountTypes accountSecurityLevel) const;
    std::vector<uint8> GetRealmList(uint32 build, AccountTypes accountSecurityLevel, std::string const& subRegion) const;
    uint32 JoinRealm(uint32 realmAddress, uint32 build, boost::asio::ip::address const& clientAddress, std::array<uint8, 32> const& clientSecret,
        LocaleConstant locale, std::string const& os, Minutes timezoneOffset, std::string const& accountName, AccountTypes accountSecurityLevel,
        bgs::protocol::game_utilities::v1::ClientResponse* response) const;

private:
    RealmList();

    void LoadBuildInfo();
    void UpdateRealms();
    static void UpdateRealm(Realm& realm, Battlenet::RealmHandle const& id, uint32 build, std::string const& name,
        boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr,
        uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, RealmPopulationState population);
    void FillRealmEntry(Realm const& realm, uint32 clientBuild, AccountTypes accountSecurityLevel, JSON::RealmList::RealmEntry* realmEntry) const;

    std::vector<RealmBuildInfo> _builds;
    mutable std::shared_mutex _realmsMutex;
    RealmMap _realms;
    std::map<Battlenet::RealmHandle, std::string> _removedRealms;
    std::unordered_set<std::string> _subRegions;
    uint32 _updateInterval;
    std::unique_ptr<Trinity::Asio::DeadlineTimer> _updateTimer;
    std::unique_ptr<Trinity::Asio::Resolver> _resolver;
    Optional<Battlenet::RealmHandle> _currentRealmId;
};

#define sRealmList RealmList::Instance()

#endif
