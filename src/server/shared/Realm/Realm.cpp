/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

ip::tcp::endpoint Realm::GetAddressForClient(ip::address const& clientAddr) const
{
    ip::address realmIp;

    // Attempt to send best address for client
    if (clientAddr.is_loopback())
    {
        // Try guessing if realm is also connected locally
        if (LocalAddress.is_loopback() || ExternalAddress.is_loopback())
            realmIp = clientAddr;
        else
        {
            // Assume that user connecting from the machine that bnetserver is located on
            // has all realms available in his local network
            realmIp = LocalAddress;
        }
    }
    else
    {
        if (clientAddr.is_v4() &&
            (clientAddr.to_v4().to_ulong() & LocalSubnetMask.to_v4().to_ulong()) ==
            (LocalAddress.to_v4().to_ulong() & LocalSubnetMask.to_v4().to_ulong()))
        {
            realmIp = LocalAddress;
        }
        else
            realmIp = ExternalAddress;
    }

    ip::tcp::endpoint endpoint(realmIp, Port);

    // Return external IP
    return endpoint;
}
