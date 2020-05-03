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
    NormalizedName.erase(std::remove_if(NormalizedName.begin(), NormalizedName.end(), ::isspace), NormalizedName.end());
}

boost::asio::ip::address Realm::GetAddressForClient(boost::asio::ip::address const& clientAddr) const
{
    boost::asio::ip::address realmIp;

    // Attempt to send best address for client
    if (clientAddr.is_loopback())
    {
        // Try guessing if realm is also connected locally
        if (LocalAddress->is_loopback() || ExternalAddress->is_loopback())
            realmIp = clientAddr;
        else
        {
            // Assume that user connecting from the machine that bnetserver is located on
            // has all realms available in his local network
            realmIp = *LocalAddress;
        }
    }
    else
    {
        if (clientAddr.is_v4() && Trinity::Net::IsInNetwork(LocalAddress->to_v4(), LocalSubnetMask->to_v4(), clientAddr.to_v4()))
            realmIp = *LocalAddress;
        else
            realmIp = *ExternalAddress;
    }

    // Return external IP
    return realmIp;
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
    return Trinity::StringFormat("%u-%u-%u", Region, Site, Realm);
}

std::string Battlenet::RealmHandle::GetSubRegionAddress() const
{
    return Trinity::StringFormat("%u-%u-0", Region, Site);
}
