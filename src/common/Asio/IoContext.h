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

#ifndef IoContext_h__
#define IoContext_h__

#include <boost/asio/io_context.hpp>
#include <boost/asio/post.hpp>

namespace Trinity
{
    namespace Asio
    {
        class IoContext
        {
        public:
            IoContext() : _impl() { }
            explicit IoContext(int concurrency_hint) : _impl(concurrency_hint) { }

            operator boost::asio::io_context&() { return _impl; }
            operator boost::asio::io_context const&() const { return _impl; }

            std::size_t run() { return _impl.run(); }
            void stop() { _impl.stop(); }

            boost::asio::io_context::executor_type get_executor() noexcept { return _impl.get_executor(); }

        private:
            boost::asio::io_context _impl;
        };

        template<typename T>
        inline decltype(auto) post(boost::asio::io_context& ioContext, T&& t)
        {
            return boost::asio::post(ioContext, std::forward<T>(t));
        }

        template<typename T>
        inline decltype(auto) get_io_context(T&& ioObject)
        {
            return ioObject.get_executor().context();
        }
    }
}

#endif // IoContext_h__
