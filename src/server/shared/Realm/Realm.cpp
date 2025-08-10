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

#include "Realm.h"
#include "IpAddress.h"
#include "IpNetwork.h"
#include "StringFormat.h"
#include <algorithm>
#include <cctype>

void Realm::SetName(std::string name)
{
    Name = name;
    NormalizedName = std::move(name);
    std::erase_if(NormalizedName, [](char c) { return std::isspace(static_cast<unsigned char>(c)); });
}

boost::asio::ip::address Realm::GetAddressForClient(boost::asio::ip::address const& clientAddr) const
{
    if (auto addressIndex = Trinity::Net::SelectAddressForClient(clientAddr, Addresses))
        return Addresses[*addressIndex];

    if (Addresses.size() > 1 && clientAddr.is_loopback())
        return Addresses[1];

    return Addresses[0];
}

uint32 Realm::GetConfigId() const
{
    return ConfigIdByType[Type];
}

uint32 const Realm::ConfigIdByType[MAX_CLIENT_REALM_TYPE] =
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
};

std::string Battlenet::RealmHandle::GetAddressString() const
{
    return Trinity::StringFormat("{}-{}-{}", Region, Site, Realm);
}

std::string Battlenet::RealmHandle::GetSubRegionAddress() const
{
    return Trinity::StringFormat("{}-{}-0", Region, Site);
}
