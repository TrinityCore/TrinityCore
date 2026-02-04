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

#ifndef TRINITYCORE_SOCKET_CONNECTION_INITIALIZER_H
#define TRINITYCORE_SOCKET_CONNECTION_INITIALIZER_H

#include <memory>
#include <span>

namespace Trinity::Net
{
struct SocketConnectionInitializer : public std::enable_shared_from_this<SocketConnectionInitializer>
{
    SocketConnectionInitializer() = default;

    SocketConnectionInitializer(SocketConnectionInitializer const&) = delete;
    SocketConnectionInitializer(SocketConnectionInitializer&&) noexcept = default;
    SocketConnectionInitializer& operator=(SocketConnectionInitializer const&) = delete;
    SocketConnectionInitializer& operator=(SocketConnectionInitializer&&) noexcept = default;

    virtual ~SocketConnectionInitializer() = default;

    virtual void Start() = 0;

    void InvokeNext()
    {
        if (next)
            next->Start();
    }

    std::shared_ptr<SocketConnectionInitializer> next;

    static std::shared_ptr<SocketConnectionInitializer>& SetupChain(std::span<std::shared_ptr<SocketConnectionInitializer>> initializers)
    {
        for (std::size_t i = initializers.size(); i > 1; --i)
            initializers[i - 2]->next.swap(initializers[i - 1]);

        return initializers[0];
    }
};
}

#endif // TRINITYCORE_SOCKET_CONNECTION_INITIALIZER_H
