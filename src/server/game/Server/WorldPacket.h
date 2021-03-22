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

#ifndef TRINITYCORE_WORLDPACKET_H
#define TRINITYCORE_WORLDPACKET_H

#include "ByteBuffer.h"
#include "Opcodes.h"

class WorldPacket : public ByteBuffer
{
    public:
                                                            // just container for later use
        WorldPacket() : ByteBuffer(0, Reserve{}), m_opcode(UNKNOWN_OPCODE), _connection(CONNECTION_TYPE_DEFAULT)
        {
        }

        WorldPacket(uint32 opcode, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ByteBuffer(0, Reserve{}),
            m_opcode(opcode), _connection(connection) { }

        WorldPacket(uint32 opcode, size_t res, Reserve, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ByteBuffer(res, Reserve{}),
            m_opcode(opcode), _connection(connection) { }

        WorldPacket(uint32 opcode, size_t res, Resize, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ByteBuffer(res, Resize{}),
            m_opcode(opcode), _connection(connection) { }

        WorldPacket(uint32 opcode, size_t res, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : WorldPacket(opcode, res, Reserve{}, connection) { }

        WorldPacket(WorldPacket&& packet) noexcept : ByteBuffer(std::move(packet)), m_opcode(packet.m_opcode), _connection(packet._connection)
        {
        }

        WorldPacket(WorldPacket const& right) = default;

        WorldPacket& operator=(WorldPacket const& right)
        {
            if (this != &right)
            {
                m_opcode = right.m_opcode;
                _connection = right._connection;
                ByteBuffer::operator =(right);
            }

            return *this;
        }

        WorldPacket& operator=(WorldPacket&& right) noexcept
        {
            if (this != &right)
            {
                m_opcode = right.m_opcode;
                _connection = right._connection;
                ByteBuffer::operator=(std::move(right));
            }

            return *this;
        }

        WorldPacket(MessageBuffer&& buffer, ConnectionType connection) : ByteBuffer(std::move(buffer)), m_opcode(UNKNOWN_OPCODE), _connection(connection) { }

        void Initialize(uint32 opcode, size_t newres = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT)
        {
            clear();
            _storage.reserve(newres);
            m_opcode = opcode;
            _connection = connection;
        }

        uint32 GetOpcode() const { return m_opcode; }
        void SetOpcode(uint32 opcode) { m_opcode = opcode; }

        ConnectionType GetConnection() const { return _connection; }

    protected:
        uint32 m_opcode;
        ConnectionType _connection;
};

#endif
