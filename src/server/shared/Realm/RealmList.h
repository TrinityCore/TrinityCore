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
#include "Realm.h"
#include <array>
#include <map>
#include <shared_mutex>
#include <vector>
#include <unordered_set>

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

namespace boost
{
    namespace system
    {
        class error_code;
    }
}

namespace bgs
{
    namespace protocol
    {
        namespace game_utilities
        {
            namespace v1
            {
                class ClientResponse;
                class GetAllValuesForAttributeResponse;
            }
        }
    }
}

namespace JSON
{
    namespace RealmList
    {
        class RealmListUpdates;
    }
}

/// Storage object for the list of realms on the server
class TC_SHARED_API RealmList
{
public:
    typedef std::map<Battlenet::RealmHandle, Realm> RealmMap;

    static RealmList* Instance();

    ~RealmList();

    void Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval);
    void Close();

    Realm const* GetRealm(Battlenet::RealmHandle const& id) const;

    RealmBuildInfo const* GetBuildInfo(uint32 build) const;
    uint32 GetMinorMajorBugfixVersionForBuild(uint32 build) const;
    void WriteSubRegions(bgs::protocol::game_utilities::v1::GetAllValuesForAttributeResponse* response) const;
    std::vector<uint8> GetRealmEntryJSON(Battlenet::RealmHandle const& id, uint32 build) const;
    std::vector<uint8> GetRealmList(uint32 build, std::string const& subRegion) const;
    uint32 JoinRealm(uint32 realmAddress, uint32 build, boost::asio::ip::address const& clientAddress, std::array<uint8, 32> const& clientSecret,
        LocaleConstant locale, std::string const& os, std::string accountName, bgs::protocol::game_utilities::v1::ClientResponse* response) const;

private:
    RealmList();

    void LoadBuildInfo();
    void UpdateRealms(boost::system::error_code const& error);
    void UpdateRealm(Realm& realm, Battlenet::RealmHandle const& id, uint32 build, std::string const& name,
        boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr, boost::asio::ip::address&& localSubmask,
        uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float population);

    std::vector<RealmBuildInfo> _builds;
    mutable std::shared_mutex _realmsMutex;
    RealmMap _realms;
    std::unordered_set<std::string> _subRegions;
    uint32 _updateInterval;
    std::unique_ptr<Trinity::Asio::DeadlineTimer> _updateTimer;
    std::unique_ptr<Trinity::Asio::Resolver> _resolver;
};

#define sRealmList RealmList::Instance()
#endif
