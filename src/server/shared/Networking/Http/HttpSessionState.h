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

#ifndef TRINITYCORE_HTTP_SESSION_STATE_H
#define TRINITYCORE_HTTP_SESSION_STATE_H

#include "Duration.h"
#include <boost/asio/ip/address.hpp>
#include <boost/uuid/uuid.hpp>

namespace Trinity::Net::Http
{
struct SessionState
{
    boost::uuids::uuid Id = { };
    boost::asio::ip::address RemoteAddress;
    TimePoint InactiveTimestamp = TimePoint::max();
};
}

#endif // TRINITYCORE_HTTP_SESSION_STATE_H
