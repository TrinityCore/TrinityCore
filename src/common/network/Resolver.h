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

#ifndef TRINITYCORE_RESOLVER_H
#define TRINITYCORE_RESOLVER_H

#include "Define.h"
#include "IoContext.h"
#include "Optional.h"
#include <boost/asio/ip/tcp.hpp>
#include <string_view>
#include <vector>

namespace Trinity::Net
{
/**
  Hack to make it possible to forward declare resolver (one of its template arguments is a typedef to something super long and using nested classes)
*/
class TC_NETWORK_API Resolver
{
public:
    explicit Resolver(Asio::IoContext& ioContext) : _impl(ioContext) { }

    Optional<boost::asio::ip::tcp::endpoint> Resolve(boost::asio::ip::tcp const& protocol, std::string_view host, std::string_view service);

    std::vector<boost::asio::ip::tcp::endpoint> ResolveAll(std::string_view host, std::string_view service);

private:
    boost::asio::ip::basic_resolver<boost::asio::ip::tcp, Asio::IoContext::Executor> _impl;
};
}

#endif // TRINITYCORE_RESOLVER_H
