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
#include <vector>
#include <unordered_set>

struct RealmBuildInfo
{
    uint32 Build;
    uint32 MajorVersion;
    uint32 MinorVersion;
    uint32 BugfixVersion;
    std::array<char, 4> HotfixVersion;
    std::array<uint8, 20> WindowsHash;
    std::array<uint8, 20> MacHash;
};

namespace boost
{
    namespace system
    {
        class error_code;
    }
}

namespace Trinity
{
    namespace Asio
    {
        class IoContext;
        class DeadlineTimer;
    }
}

/// Storage object for the list of realms on the server
class TC_SHARED_API RealmList
{
public:
    typedef std::map<RealmHandle, Realm> RealmMap;

    static RealmList* Instance();

    ~RealmList();

    void Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval);
    void Close();

    RealmMap const& GetRealms() const { return _realms; }
    Realm const* GetRealm(RealmHandle const& id) const;

    RealmBuildInfo const* GetBuildInfo(uint32 build) const;

private:
    RealmList();

    void LoadBuildInfo();
    void UpdateRealms(boost::system::error_code const& error);
    void UpdateRealm(RealmHandle const& id, uint32 build, std::string const& name,
        boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr, boost::asio::ip::address&& localSubmask,
        uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float population);

    std::vector<RealmBuildInfo> _builds;
    RealmMap _realms;
    uint32 _updateInterval;
    std::unique_ptr<Trinity::Asio::DeadlineTimer> _updateTimer;
    std::unique_ptr<boost::asio::ip::tcp_resolver> _resolver;
};

#define sRealmList RealmList::Instance()
#endif
