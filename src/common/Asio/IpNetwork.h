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

#ifndef IpNetwork_h__
#define IpNetwork_h__

#include "AsioHacksFwd.h"
#include "Define.h"
#include "Optional.h"
#include <span>

namespace Trinity::Net
{
TC_COMMON_API bool IsInLocalNetwork(boost::asio::ip::address const& clientAddress);

TC_COMMON_API bool IsInNetwork(boost::asio::ip::network_v4 const& network, boost::asio::ip::address_v4 const& clientAddress);

TC_COMMON_API bool IsInNetwork(boost::asio::ip::network_v6 const& network, boost::asio::ip::address_v6 const& clientAddress);

TC_COMMON_API Optional<std::size_t> SelectAddressForClient(boost::asio::ip::address const& clientAddress, std::span<boost::asio::ip::address const> const& addresses);

TC_COMMON_API void ScanLocalNetworks();
}

#endif // IpNetwork_h__
