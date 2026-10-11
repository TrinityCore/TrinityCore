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

#include "Resolver.h"
#include <algorithm>

Optional<boost::asio::ip::tcp::endpoint> Trinity::Net::Resolver::Resolve(boost::asio::ip::tcp const& protocol, std::string_view host, std::string_view service)
{
    boost::system::error_code ec;
    boost::asio::ip::resolver_base::flags flagsResolver = boost::asio::ip::resolver_base::all_matching;
    boost::asio::ip::tcp::resolver::results_type results = _impl.resolve(protocol, host, service, flagsResolver, ec);
    Optional<boost::asio::ip::tcp::endpoint> result;
    if (!ec)
        if (auto itr = results.begin(); itr != results.end())
            result.emplace(itr->endpoint());

    return result;
}

std::vector<boost::asio::ip::tcp::endpoint> Trinity::Net::Resolver::ResolveAll(std::string_view host, std::string_view service)
{
    boost::system::error_code ec;
    boost::asio::ip::resolver_base::flags flagsResolver = boost::asio::ip::resolver_base::all_matching;
    boost::asio::ip::tcp::resolver::results_type results = _impl.resolve(host, service, flagsResolver, ec);
    std::vector<boost::asio::ip::tcp::endpoint> result;
    if (!ec)
    {
        result.resize(results.size());
        std::ranges::transform(results, result.begin(), [](boost::asio::ip::tcp::resolver::results_type::value_type const& entry) { return entry.endpoint(); });
    }

    return result;
}
