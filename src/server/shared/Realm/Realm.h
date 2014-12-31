/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef Realm_h__
#define Realm_h__

#include "Common.h"
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace boost::asio;

enum RealmFlags
{
    REALM_FLAG_NONE         = 0x00,
    REALM_FLAG_INVALID      = 0x01,
    REALM_FLAG_OFFLINE      = 0x02,
    REALM_FLAG_SPECIFYBUILD = 0x04,
    REALM_FLAG_UNK1         = 0x08,
    REALM_FLAG_UNK2         = 0x10,
    REALM_FLAG_RECOMMENDED  = 0x20,
    REALM_FLAG_NEW          = 0x40,
    REALM_FLAG_FULL         = 0x80
};

#pragma pack(push, 1)

namespace Battlenet
{
    struct RealmHandle;

    struct RealmId
    {
        RealmId() : Region(0), Battlegroup(0), Index(0), Build(0) { }
        RealmId(uint8 region, uint8 battlegroup, uint32 index, uint32 build)
            : Region(region), Battlegroup(battlegroup), Index(index), Build(build) { }

        uint8 Region;
        uint8 Battlegroup;
        uint32 Index;
        uint32 Build;

        bool operator<(RealmId const& r) const
        {
            return memcmp(this, &r, sizeof(RealmId) - sizeof(Build)) < 0;
        }
    };
}

#pragma pack(pop)

// Storage object for a realm
struct Realm
{
    Battlenet::RealmId Id;
    ip::address ExternalAddress;
    ip::address LocalAddress;
    ip::address LocalSubnetMask;
    uint16 Port;
    std::string Name;
    uint8 Type;
    RealmFlags Flags;
    uint8 Timezone;
    AccountTypes AllowedSecurityLevel;
    float PopulationLevel;
    bool Updated;
    bool Keep;

    ip::tcp::endpoint GetAddressForClient(ip::address const& clientAddr) const;
};

#endif // Realm_h__
