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

#include "BattlenetPackets.h"
#include "PacketOperators.h"
#include "PacketUtilities.h"

namespace WorldPackets::Battlenet
{
ByteBuffer& operator<<(ByteBuffer& data, MethodCall const& method)
{
    data << uint64(method.Type);
    data << uint64(method.ObjectId);
    data << uint32(method.Token);
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, MethodCall& method)
{
    data >> method.Type;
    data >> method.ObjectId;
    data >> method.Token;
    return data;
}

WorldPacket const* Notification::Write()
{
    _worldPacket << Method;
    _worldPacket << Size<uint32>(Data);
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* Response::Write()
{
    _worldPacket << uint32(BnetStatus);
    _worldPacket << Method;
    _worldPacket << Size<uint32>(Data);
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* ConnectionStatus::Write()
{
    _worldPacket << Bits<2>(State);
    _worldPacket << Bits<1>(SuppressNotification);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* ChangeRealmTicketResponse::Write()
{
    _worldPacket << uint32(Token);
    _worldPacket << Bits<1>(Allow);
    _worldPacket << Size<uint32>(Ticket);
    _worldPacket.append(Ticket);

    return &_worldPacket;
}

void Request::Read()
{
    uint32 protoSize;

    _worldPacket >> Method;
    _worldPacket >> protoSize;

    if (protoSize > 0xFFFF)
        OnInvalidArraySize(protoSize, 0xFFFF);

    if (protoSize)
    {
        Data.Resize(protoSize);
        _worldPacket.read(Data.GetWritePointer(), Data.GetRemainingSpace());
        Data.WriteCompleted(protoSize);
    }
}

void ChangeRealmTicket::Read()
{
    _worldPacket >> Token;
    _worldPacket.read(Secret.data(), Secret.size());
}
}
