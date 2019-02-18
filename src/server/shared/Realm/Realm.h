/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "AsioHacksFwd.h"

enum RealmFlags
{
    REALM_FLAG_NONE             = 0x00,
    REALM_FLAG_VERSION_MISMATCH = 0x01,
    REALM_FLAG_OFFLINE          = 0x02,
    REALM_FLAG_SPECIFYBUILD     = 0x04,
    REALM_FLAG_UNK1             = 0x08,
    REALM_FLAG_UNK2             = 0x10,
    REALM_FLAG_RECOMMENDED      = 0x20,
    REALM_FLAG_NEW              = 0x40,
    REALM_FLAG_FULL             = 0x80
};

namespace Battlenet
{
    struct TC_SHARED_API RealmHandle
    {
        RealmHandle() : Region(0), Site(0), Realm(0) { }
        RealmHandle(uint8 region, uint8 battlegroup, uint32 index)
            : Region(region), Site(battlegroup), Realm(index) { }
        RealmHandle(uint32 realmAddress) : Region((realmAddress >> 24) & 0xFF), Site((realmAddress >> 16) & 0xFF), Realm(realmAddress & 0xFFFF) { }

        uint8 Region;
        uint8 Site;
        uint32 Realm;   // primary key in `realmlist` table

        bool operator<(RealmHandle const& r) const
        {
            return Realm < r.Realm;
        }

        uint32 GetAddress() const { return (Region << 24) | (Site << 16) | uint16(Realm); }
        std::string GetAddressString() const;
        std::string GetSubRegionAddress() const;
    };
}

/// Type of server, this is values from second column of Cfg_Configs.dbc
enum RealmType
{
    REALM_TYPE_NORMAL       = 0,
    REALM_TYPE_PVP          = 1,
    REALM_TYPE_NORMAL2      = 4,
    REALM_TYPE_RP           = 6,
    REALM_TYPE_RPPVP        = 8,

    MAX_CLIENT_REALM_TYPE   = 14,

    REALM_TYPE_FFA_PVP      = 16                            // custom, free for all pvp mode like arena PvP in all zones except rest activated places and sanctuaries
                                                            // replaced by REALM_PVP in realm list
};

// Storage object for a realm
struct TC_SHARED_API Realm
{
    Battlenet::RealmHandle Id;
    uint32 Build;
    std::unique_ptr<boost::asio::ip::address> ExternalAddress;
    std::unique_ptr<boost::asio::ip::address> LocalAddress;
    std::unique_ptr<boost::asio::ip::address> LocalSubnetMask;
    uint16 Port;
    std::string Name;
    std::string NormalizedName;
    uint8 Type;
    RealmFlags Flags;
    uint8 Timezone;
    AccountTypes AllowedSecurityLevel;
    float PopulationLevel;

    void SetName(std::string name);

    boost::asio::ip::address GetAddressForClient(boost::asio::ip::address const& clientAddr) const;
    uint32 GetConfigId() const;

    static uint32 const ConfigIdByType[MAX_CLIENT_REALM_TYPE];
};

#endif // Realm_h__
