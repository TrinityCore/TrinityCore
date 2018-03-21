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

#ifndef Strand_h__
#define Strand_h__

#include "IoContext.h"
#include <boost/asio/strand.hpp>

#if BOOST_VERSION >= 106600
#include <boost/asio/bind_executor.hpp>
#endif

namespace Trinity
{
    namespace Asio
    {
        /**
          Hack to make it possible to forward declare strand (which is a inner class)
        */
        class Strand : public IoContextBaseNamespace::IoContextBase::strand
        {
        public:
            Strand(IoContext& ioContext) : IoContextBaseNamespace::IoContextBase::strand(ioContext) { }
        };

#if BOOST_VERSION >= 106600
        using boost::asio::bind_executor;
#else
        template<typename T>
        inline decltype(auto) bind_executor(Strand& strand, T&& t)
        {
            return strand.wrap(std::forward<T>(t));
        }
#endif
    }
}

#endif // Strand_h__
