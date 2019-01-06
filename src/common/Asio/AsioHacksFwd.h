/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef AsioHacksFwd_h__
#define AsioHacksFwd_h__

#include <boost/version.hpp>

/**
  Collection of forward declarations to improve compile time
 */
namespace boost
{
    namespace posix_time
    {
        class ptime;
    }

    namespace asio
    {
        template <typename Time>
        struct time_traits;

        namespace ip
        {
            class address;

            class tcp;

            template <typename InternetProtocol>
            class basic_endpoint;

            typedef basic_endpoint<tcp> tcp_endpoint;
        }

#if BOOST_VERSION >= 106600
        template <typename Time, typename TimeTraits>
        class basic_deadline_timer;

        typedef basic_deadline_timer<posix_time::ptime, time_traits<posix_time::ptime>> deadline_timer;

        namespace ip
        {
            template <typename InternetProtocol>
            class basic_resolver;

            typedef basic_resolver<tcp> tcp_resolver;
    }
#else
        template <typename TimeType, typename TimeTraits>
        class deadline_timer_service;

        template <typename Time, typename TimeTraits, typename TimerService>
        class basic_deadline_timer;

        typedef basic_deadline_timer<posix_time::ptime, time_traits<posix_time::ptime>, deadline_timer_service<posix_time::ptime, time_traits<posix_time::ptime>>> deadline_timer;

        namespace ip
        {
            template <typename InternetProtocol>
            class resolver_service;

            template <typename InternetProtocol, typename ResolverService>
            class basic_resolver;

            typedef basic_resolver<tcp, resolver_service<tcp>> tcp_resolver;
        }
#endif
    }
}

namespace Trinity
{
    namespace Asio
    {
        class Strand;
    }
}

#endif // AsioHacksFwd_h__
