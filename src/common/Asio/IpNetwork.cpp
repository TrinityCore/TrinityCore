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

#include "IpNetwork.h"
#include "IpAddress.h"
#include <boost/asio/ip/network_v4.hpp>
#include <boost/asio/ip/network_v6.hpp>
#include <algorithm>

namespace
{
std::vector<boost::asio::ip::network_v4> LocalV4Networks;
std::vector<boost::asio::ip::network_v6> LocalV6Networks;
}

namespace Trinity::Net
{
bool IsInLocalNetwork(boost::asio::ip::address const& clientAddress)
{
    if (clientAddress.is_v4())
    {
        return std::any_of(LocalV4Networks.begin(), LocalV4Networks.end(), [clientAddressV4 = clientAddress.to_v4()](boost::asio::ip::network_v4 const& network)
        {
            return IsInNetwork(network, clientAddressV4);
        });
    }

    if (clientAddress.is_v6())
    {
        return std::any_of(LocalV6Networks.begin(), LocalV6Networks.end(), [clientAddressV6 = clientAddress.to_v6()](boost::asio::ip::network_v6 const& network)
        {
            return IsInNetwork(network, clientAddressV6);
        });
    }

    return false;
};

bool IsInNetwork(boost::asio::ip::network_v4 const& network, boost::asio::ip::address_v4 const& clientAddress)
{
    if (clientAddress == network.address())
        return true;

    boost::asio::ip::network_v4 endpointAsNetwork = boost::asio::ip::make_network_v4(clientAddress, 32);
    return endpointAsNetwork.is_subnet_of(network);
}

bool IsInNetwork(boost::asio::ip::network_v6 const& network, boost::asio::ip::address_v6 const& clientAddress)
{
    if (clientAddress == network.address())
        return true;

    boost::asio::ip::network_v6 endpointAsNetwork = boost::asio::ip::make_network_v6(clientAddress, 128);
    return endpointAsNetwork.is_subnet_of(network);
}

Optional<std::size_t> SelectAddressForClient(boost::asio::ip::address const& clientAddress, std::span<boost::asio::ip::address const> const& addresses)
{
    Optional<std::size_t> localIpv6Index;
    Optional<std::size_t> externalIpv6Index;
    Optional<std::size_t> loopbackIpv6Index;
    Optional<std::size_t> localIpv4Index;
    Optional<std::size_t> externalIpv4Index;
    Optional<std::size_t> loopbackIpv4Index;

    for (std::size_t i = 0; i < addresses.size(); ++i)
    {
        boost::asio::ip::address const& address = addresses[i];

        if (address.is_loopback())
        {
            if (address.is_v6() && !loopbackIpv6Index)
                loopbackIpv6Index = i;

            if (address.is_v4() && !loopbackIpv4Index)
                loopbackIpv4Index = i;
        }
        else if (IsInLocalNetwork(address))
        {
            if (address.is_v6() && !localIpv6Index)
                localIpv6Index = i;

            if (address.is_v4() && !localIpv4Index)
                localIpv4Index = i;
        }
        else
        {
            if (address.is_v6() && !externalIpv6Index)
                externalIpv6Index = i;

            if (address.is_v4() && !externalIpv4Index)
                externalIpv4Index = i;
        }
    }

    if (IsInLocalNetwork(clientAddress) || clientAddress.is_loopback())
    {
        // client is in the same network as this process, prefer local addresses

        // first, try finding a local ipv6 address
        if (clientAddress.is_v6() && localIpv6Index)
        {
            // we have a usable ipv6 local address
            return localIpv6Index;
        }

        // we dont have a local v6, return local v4
        if (localIpv4Index)
            return localIpv4Index;
    }

    if (clientAddress.is_loopback())
    {
        // fallback, search for a loopback address in configuration
        if (clientAddress.is_v6() && loopbackIpv6Index)
            return loopbackIpv6Index;

        if (loopbackIpv4Index)
            return loopbackIpv4Index;
    }

    // client is NOT in the same network as this process
    if (clientAddress.is_v6() && externalIpv6Index)
        return externalIpv6Index;

    return externalIpv4Index;
}
}

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS

#include <boost/dll/shared_library.hpp>
#include <iphlpapi.h>

void Trinity::Net::ScanLocalNetworks()
{
    LocalV4Networks.clear();
    LocalV6Networks.clear();

    boost::system::error_code dllError;
    boost::dll::shared_library iphlp("Iphlpapi.dll", dllError, boost::dll::load_mode::search_system_folders);
    if (dllError || !iphlp.is_loaded())
        return;

    auto getAdaptersAddresses = iphlp.get<decltype(GetAdaptersAddresses)>("GetAdaptersAddresses");
    if (!getAdaptersAddresses)
        return;

    ULONG queryFlags = GAA_FLAG_SKIP_UNICAST | GAA_FLAG_SKIP_ANYCAST | GAA_FLAG_SKIP_MULTICAST | GAA_FLAG_SKIP_DNS_SERVER | GAA_FLAG_INCLUDE_PREFIX | GAA_FLAG_SKIP_FRIENDLY_NAME;
    ULONG bufferSize = 0;

    if (getAdaptersAddresses(AF_UNSPEC, queryFlags, nullptr, nullptr, &bufferSize) != ERROR_BUFFER_OVERFLOW)
        return;

    std::unique_ptr<std::byte[]> addressesBuffer = std::make_unique<std::byte[]>(bufferSize);
    if (getAdaptersAddresses(AF_UNSPEC, queryFlags, nullptr, reinterpret_cast<IP_ADAPTER_ADDRESSES*>(addressesBuffer.get()), &bufferSize) != ERROR_SUCCESS)
        return;

    for (IP_ADAPTER_ADDRESSES* itr = reinterpret_cast<IP_ADAPTER_ADDRESSES*>(addressesBuffer.get()); itr; itr = itr->Next)
    {
        if (itr->IfType == IF_TYPE_SOFTWARE_LOOPBACK)
            continue;

        if (itr->OperStatus != IfOperStatusUp)
            continue;

        for (IP_ADAPTER_PREFIX_XP* prefix = itr->FirstPrefix; prefix; prefix = prefix->Next)
        {
            switch (prefix->Address.lpSockaddr->sa_family)
            {
                case AF_INET:
                {
                    SOCKADDR_IN* ipv4raw = reinterpret_cast<SOCKADDR_IN*>(prefix->Address.lpSockaddr);
                    boost::asio::ip::address_v4::bytes_type addressBytes;
                    std::memcpy(addressBytes.data(), &ipv4raw->sin_addr.s_addr, addressBytes.size());
                    boost::asio::ip::address_v4 address = make_address_v4(addressBytes);
                    if (address.is_unspecified() || address.is_multicast() || address == boost::asio::ip::address_v4::broadcast())
                        continue;

                    LocalV4Networks.push_back(boost::asio::ip::make_network_v4(address, prefix->PrefixLength));
                    break;
                }
                case AF_INET6:
                {
                    SOCKADDR_IN6* ipv6raw = reinterpret_cast<SOCKADDR_IN6*>(prefix->Address.lpSockaddr);
                    boost::asio::ip::address_v6::bytes_type addressBytes;
                    std::memcpy(addressBytes.data(), ipv6raw->sin6_addr.s6_addr, addressBytes.size());
                    boost::asio::ip::address_v6 address = make_address_v6(addressBytes, ipv6raw->sin6_scope_id);
                    if (address.is_unspecified() || address.is_multicast())
                        continue;

                    LocalV6Networks.push_back(boost::asio::ip::make_network_v6(address, prefix->PrefixLength));
                    break;
                }
                default:
                    break;
            }
        }
    }
}

#else

#include <numeric>
#include <ifaddrs.h>

void Trinity::Net::ScanLocalNetworks()
{
    LocalV4Networks.clear();
    LocalV6Networks.clear();

    ifaddrs* addressesLinkedList = nullptr;
    if (getifaddrs(&addressesLinkedList) == -1)
        return;

    for (ifaddrs* itr = addressesLinkedList; itr; itr = itr->ifa_next)
    {
        if (!itr->ifa_addr)
            continue;

        switch (itr->ifa_addr->sa_family)
        {
            case AF_INET:
            {
                sockaddr_in* ipv4raw = reinterpret_cast<sockaddr_in*>(itr->ifa_addr);
                boost::asio::ip::address_v4::bytes_type addressBytes;
                std::memcpy(addressBytes.data(), &ipv4raw->sin_addr.s_addr, addressBytes.size());
                boost::asio::ip::address_v4 address = make_address_v4(addressBytes);
                if (address.is_unspecified() || address.is_loopback() || address.is_multicast() || address == boost::asio::ip::address_v4::broadcast())
                    continue;

                if (sockaddr_in* netmask4raw = reinterpret_cast<sockaddr_in*>(itr->ifa_netmask))
                {
                    boost::asio::ip::address_v4::bytes_type netmaskBytes;
                    std::memcpy(netmaskBytes.data(), &netmask4raw->sin_addr.s_addr, netmaskBytes.size());
                    boost::asio::ip::address_v4 netmask = make_address_v4(netmaskBytes);
                    LocalV4Networks.push_back(boost::asio::ip::make_network_v4(address, netmask));
                }
                else
                    LocalV4Networks.push_back(boost::asio::ip::make_network_v4(address, 32));
                break;
            }
            case AF_INET6:
            {
                sockaddr_in6* ipv6raw = reinterpret_cast<sockaddr_in6*>(itr->ifa_addr);
                boost::asio::ip::address_v6::bytes_type addressBytes;
                std::memcpy(addressBytes.data(), ipv6raw->sin6_addr.s6_addr, addressBytes.size());
                boost::asio::ip::address_v6 address = make_address_v6(addressBytes, ipv6raw->sin6_scope_id);
                if (address.is_unspecified() || address.is_loopback() || address.is_multicast())
                    continue;

                if (sockaddr_in6* netmask6raw = reinterpret_cast<sockaddr_in6*>(itr->ifa_netmask))
                {
                    int32 prefixLength = 0;
                    for (uint8 addressByte : netmask6raw->sin6_addr.s6_addr)
                        prefixLength += std::countl_one(addressByte);

                    LocalV6Networks.push_back(boost::asio::ip::make_network_v6(address, prefixLength));
                }
                else
                    LocalV6Networks.push_back(boost::asio::ip::make_network_v6(address, 128));
                break;
            }
        }
    }

    freeifaddrs(addressesLinkedList);
}

#endif
