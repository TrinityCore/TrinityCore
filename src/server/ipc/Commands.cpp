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

#include "Commands.h"
#include <zmqpp/message.hpp>

zmqpp::message& operator>>(zmqpp::message& msg, IPC::Header& header)
{
    msg >> header.Channel;
    msg >> header.Command;
    return msg;
}

zmqpp::message& operator>>(zmqpp::message& msg, Battlenet::RealmHandle& realm)
{
    msg >> realm.Region;
    msg >> realm.Site;
    msg >> realm.Realm;
    return msg;
}

zmqpp::message& operator>>(zmqpp::message& msg, IPC::BattlenetComm::Header& header)
{
    msg >> header.Ipc;
    msg >> header.Realm;
    return msg;
}

zmqpp::message& operator>>(zmqpp::message& msg, IPC::BattlenetComm::ToonHandle& toonHandle)
{
    msg >> toonHandle.AccountId;
    msg >> toonHandle.GameAccountId;
    msg >> toonHandle.Guid;
    msg >> toonHandle.Name;
    return msg;
}

zmqpp::message& operator<<(zmqpp::message& msg, IPC::Header const& header)
{
    msg << header.Channel;
    msg << header.Command;
    return msg;
}

zmqpp::message& operator<<(zmqpp::message& msg, Battlenet::RealmHandle const& realm)
{
    msg << realm.Region;
    msg << realm.Site;
    msg << realm.Realm;
    return msg;
}

zmqpp::message& operator<<(zmqpp::message& msg, IPC::BattlenetComm::Header const& header)
{
    msg << header.Ipc;
    msg << header.Realm;
    return msg;
}

zmqpp::message& operator<<(zmqpp::message& msg, IPC::BattlenetComm::ToonHandle const& toonHandle)
{
    msg << toonHandle.AccountId;
    msg << toonHandle.GameAccountId;
    msg << toonHandle.Guid;
    msg << toonHandle.Name;
    return msg;
}
