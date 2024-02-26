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

#ifndef TRINITY_THREAD_POOL_H
#define TRINITY_THREAD_POOL_H

#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <thread>

namespace Trinity
{
class ThreadPool
{
public:
    explicit ThreadPool(std::size_t numThreads = std::thread::hardware_concurrency()) : _impl(numThreads) { }

    template<typename T>
    decltype(auto) PostWork(T&& work)
    {
        return boost::asio::post(_impl, std::forward<T>(work));
    }

    void Join()
    {
        _impl.join();
    }

private:
    boost::asio::thread_pool _impl;
};
}

#endif // TRINITY_THREAD_POOL_H
