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

#include "IpAddress.h"
#include "StringFormat.h"
#include "Util.h"

template <typename FormatContext>
typename FormatContext::iterator Trinity::Net::Impl::AddressFormatter::format(boost::asio::ip::address_v4 const& address, FormatContext& ctx) const
{
    boost::system::error_code ec;
    std::array<char, boost::asio::detail::max_addr_v4_str_len> addr_str;
    if (boost::asio::detail::socket_ops::inet_ntop(AF_INET, address.to_bytes().data(), addr_str.data(), addr_str.size(), 0, ec) && !ec)
        return std::ranges::copy(addr_str.begin(), CStringSentinel.Checked(addr_str.end()), ctx.out()).out;

    return ctx.out();
}

template <typename FormatContext>
typename FormatContext::iterator Trinity::Net::Impl::AddressFormatter::format(boost::asio::ip::address_v6 const& address, FormatContext& ctx) const
{
    boost::system::error_code ec;
    std::array<char, boost::asio::detail::max_addr_v6_str_len> addr_str;
    if (boost::asio::detail::socket_ops::inet_ntop(AF_INET6, address.to_bytes().data(), addr_str.data(), addr_str.size(), address.scope_id(), ec) && !ec)
        return std::ranges::copy(addr_str.begin(), CStringSentinel.Checked(addr_str.end()), ctx.out()).out;

    return ctx.out();
}

template <typename FormatContext>
typename FormatContext::iterator Trinity::Net::Impl::AddressFormatter::format(boost::asio::ip::address const& address, FormatContext& ctx) const
{
    if (address.is_v4())
        return this->format(address.to_v4(), ctx);

    if (address.is_v6())
        return this->format(address.to_v6(), ctx);

    return ctx.out();
}

template TC_NETWORK_API fmt::appender Trinity::Net::Impl::AddressFormatter::format<fmt::format_context>(boost::asio::ip::address_v4 const&, fmt::format_context&) const;
template TC_NETWORK_API fmt::appender Trinity::Net::Impl::AddressFormatter::format<fmt::format_context>(boost::asio::ip::address_v6 const&, fmt::format_context&) const;
template TC_NETWORK_API fmt::appender Trinity::Net::Impl::AddressFormatter::format<fmt::format_context>(boost::asio::ip::address const&, fmt::format_context&) const;
