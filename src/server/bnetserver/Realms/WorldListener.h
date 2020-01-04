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

#ifndef WorldListener_h__
#define WorldListener_h__

#include "ZMQTask.h"
#include "Commands.h"

class WorldListener : public ZMQTask
{
public:
    explicit WorldListener(uint16 worldListenPort);
    ~WorldListener();
    void Run() override;

protected:
    void HandleOpen() override;
    void HandleClose() override;

private:
    void Dispatch(zmqpp::message& msg) const;

    typedef void(WorldListener::*PacketHandler)(Battlenet::RealmHandle const& realm, zmqpp::message& msg) const;
    class HandlerTable
    {
    public:
        HandlerTable();

        struct HandlerInfo
        {
            PacketHandler Handler;
            char const* Name;
        };

        HandlerInfo const& operator[](uint8 opcode) const { return _handlers[opcode]; }

    private:
        HandlerInfo _handlers[IPC_BNET_MAX_COMMAND];
    };

    void HandleToonOnlineStatusChange(Battlenet::RealmHandle const& realm, zmqpp::message& msg) const;

    zmqpp::socket* _worldSocket;
    uint16 _worldListenPort;
    static HandlerTable const _handlers;
};

#endif // WorldListener_h__
