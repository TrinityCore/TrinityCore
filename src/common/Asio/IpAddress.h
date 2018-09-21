/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef IpAddress_h__
#define IpAddress_h__

#include "Define.h"
#include <boost/asio/ip/address.hpp>

namespace Trinity
{
    namespace Net
    {
#if BOOST_VERSION >= 106600
        using boost::asio::ip::make_address;
        using boost::asio::ip::make_address_v4;
        inline uint32 address_to_uint(boost::asio::ip::address_v4 const& address) { return address.to_uint(); }
#else
        inline boost::asio::ip::address make_address(char const* str) { return boost::asio::ip::address::from_string(str); }
        inline boost::asio::ip::address make_address(char const* str, boost::system::error_code& ec) { return boost::asio::ip::address::from_string(str, ec); }
        inline boost::asio::ip::address make_address(std::string const& str) { return boost::asio::ip::address::from_string(str); }
        inline boost::asio::ip::address make_address(std::string const& str, boost::system::error_code& ec) { return boost::asio::ip::address::from_string(str, ec); }
        inline boost::asio::ip::address_v4 make_address_v4(char const* str) { return boost::asio::ip::address_v4::from_string(str); }
        inline boost::asio::ip::address_v4 make_address_v4(char const* str, boost::system::error_code& ec) { return boost::asio::ip::address_v4::from_string(str, ec); }
        inline boost::asio::ip::address_v4 make_address_v4(std::string const& str) { return boost::asio::ip::address_v4::from_string(str); }
        inline boost::asio::ip::address_v4 make_address_v4(std::string const& str, boost::system::error_code& ec) { return boost::asio::ip::address_v4::from_string(str, ec); }
        inline uint32 address_to_uint(boost::asio::ip::address_v4 const& address) { return address.to_ulong(); }
#endif
    }
}

#endif // IpAddress_h__
