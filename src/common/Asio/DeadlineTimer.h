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

#ifndef TRINITYCORE_DEADLINE_TIMER_H
#define TRINITYCORE_DEADLINE_TIMER_H

#include "Duration.h"
#include "IoContext.h"
#include <boost/asio/basic_waitable_timer.hpp>

namespace Trinity::Asio
{
class DeadlineTimer : public boost::asio::basic_waitable_timer<std::chrono::steady_clock, boost::asio::wait_traits<std::chrono::steady_clock>, IoContextExecutor>
{
public:
    using basic_waitable_timer::basic_waitable_timer;
};
}

#endif // TRINITYCORE_DEADLINE_TIMER_H
