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

#ifndef Realm_h__
#define Realm_h__

#include "AsioHacksFwd.h"
#include "Common.h"
#include "EnumFlag.h"
#include <compare>
#include <vector>

enum class RealmFlags : uint8
{
    None                    = 0x00,
    VersionMismatch         = 0x01,
    Hidden                  = 0x02,
    Tournament              = 0x04,
    VersionBelow            = 0x08,
    VersionAbove            = 0x10,
    MobileVersionMismatch   = 0x20,
    MobileVersionBelow      = 0x40,
    MobileVersionAbove      = 0x80
};

DEFINE_ENUM_FLAG(RealmFlags);

enum class RealmPopulationState : uint8
{
    Offline     = 0,
    Low         = 1,
    Medium      = 2,
    High        = 3,
    New         = 4,
    Recommended = 5,
    Full        = 6,
    Locked      = 7
};

namespace Trinity::Legacy
{
enum RealmFlags : uint8
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

inline constexpr uint8 format_as(RealmFlags e) { return uint8(e); }

inline constexpr ::RealmFlags ConvertLegacyRealmFlags(RealmFlags legacyRealmFlags)
{
    ::RealmFlags realmFlags = ::RealmFlags::None;
    if (legacyRealmFlags & REALM_FLAG_VERSION_MISMATCH)
        realmFlags |= ::RealmFlags::VersionMismatch;
    return realmFlags;
}

inline constexpr RealmPopulationState ConvertLegacyPopulationState(RealmFlags legacyRealmFlags, float population)
{
    if (legacyRealmFlags & REALM_FLAG_OFFLINE)
        return RealmPopulationState::Offline;
    if (legacyRealmFlags & REALM_FLAG_RECOMMENDED)
        return RealmPopulationState::Recommended;
    if (legacyRealmFlags & REALM_FLAG_NEW)
        return RealmPopulationState::New;
    if (legacyRealmFlags & REALM_FLAG_FULL || population > 0.95f)
        return RealmPopulationState::Full;
    if (population > 0.66f)
        return RealmPopulationState::High;
    if (population > 0.33f)
        return RealmPopulationState::Medium;
    return RealmPopulationState::Low;
}
}

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

        bool operator==(RealmHandle const& r) const { return Realm == r.Realm; }

        std::strong_ordering operator<=>(RealmHandle const& r) const { return Realm <=> r.Realm; }

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

inline constexpr uint32 HARDCODED_DEVELOPMENT_REALM_CATEGORY_ID = 1;

// Storage object for a realm
struct TC_SHARED_API Realm
{
    Battlenet::RealmHandle Id;
    uint32 Build;
    std::vector<boost::asio::ip::address> Addresses;
    uint16 Port;
    std::string Name;
    std::string NormalizedName;
    uint8 Type;
    RealmFlags Flags;
    uint8 Timezone;
    AccountTypes AllowedSecurityLevel;
    RealmPopulationState PopulationLevel;

    void SetName(std::string name);

    boost::asio::ip::address GetAddressForClient(boost::asio::ip::address const& clientAddr) const;
    uint32 GetConfigId() const;

    static uint32 const ConfigIdByType[MAX_CLIENT_REALM_TYPE];
};

#endif // Realm_h__
