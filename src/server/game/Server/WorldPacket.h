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

#include "Common.h"
#include "Opcodes.h"
#include "ByteBuffer.h"
#include <chrono>

struct z_stream_s;

class WorldPacket : public ByteBuffer
{
    public:
                                                            // just container for later use
        WorldPacket() : ByteBuffer(0), m_opcode(UNKNOWN_OPCODE), _connection(CONNECTION_TYPE_DEFAULT), _compressionStream(nullptr)
        {
        }

        WorldPacket(uint16 opcode, size_t res = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ByteBuffer(res),
            m_opcode(opcode), _connection(connection), _compressionStream(nullptr) { }

        WorldPacket(WorldPacket&& packet) noexcept : ByteBuffer(std::move(packet)), m_opcode(packet.m_opcode), _connection(packet._connection), _compressionStream(nullptr)
        {
        }

        WorldPacket(WorldPacket&& packet, std::chrono::steady_clock::time_point receivedTime) : ByteBuffer(std::move(packet)), m_opcode(packet.m_opcode), _connection(packet._connection), _compressionStream(nullptr), m_receivedTime(receivedTime)
        {
        }

        WorldPacket(WorldPacket const& right) : ByteBuffer(right), m_opcode(right.m_opcode), _connection(right._connection), _compressionStream(nullptr)
        {
        }

        WorldPacket& operator=(WorldPacket const& right)
        {
            if (this != &right)
            {
                m_opcode = right.m_opcode;
                _connection = right._connection;
                ByteBuffer::operator=(right);
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

        WorldPacket(uint16 opcode, MessageBuffer&& buffer, ConnectionType connection) : ByteBuffer(std::move(buffer)), m_opcode(opcode), _connection(connection), _compressionStream(nullptr)
        {
        }

        void Initialize(uint16 opcode, size_t newres = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT)
        {
            clear();
            _storage.reserve(newres);
            m_opcode = opcode;
            _connection = connection;
        }

        uint16 GetOpcode() const { return m_opcode; }
        void SetOpcode(uint16 opcode) { m_opcode = opcode; }
        bool IsCompressed() const { return (m_opcode & COMPRESSED_OPCODE_MASK) != 0; }
        void Compress(z_stream_s* compressionStream);
        void Compress(z_stream_s* compressionStream, WorldPacket const* source);

        ConnectionType GetConnection() const { return _connection; }

        std::chrono::steady_clock::time_point GetReceivedTime() const { return m_receivedTime; }

    protected:
        uint16 m_opcode;
        ConnectionType _connection;
        void Compress(void* dst, uint32 *dst_size, const void* src, int src_size);
        z_stream_s* _compressionStream;
        std::chrono::steady_clock::time_point m_receivedTime; // only set for a specific set of opcodes, for performance reasons.
};

#endif
