/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "ByteBuffer.h"

class WorldPacket : public ByteBuffer
{
    public:
                                                            // just container for later use
        WorldPacket()                                       : ByteBuffer(0), m_opcode(0)
        {
        }

        explicit WorldPacket(uint16 opcode, size_t res=200) : ByteBuffer(res), m_opcode(opcode) { }

        WorldPacket(WorldPacket&& packet) : ByteBuffer(std::move(packet)), m_opcode(packet.m_opcode)
        {
        }

        WorldPacket(WorldPacket const& right) : ByteBuffer(right), m_opcode(right.m_opcode)
        {
        }

        WorldPacket& operator=(WorldPacket const& right)
        {
            if (this != &right)
            {
                m_opcode = right.m_opcode;
                ByteBuffer::operator =(right);
            }

            return *this;
        }

        WorldPacket(uint16 opcode, MessageBuffer&& buffer) : ByteBuffer(std::move(buffer)), m_opcode(opcode) { }

        void Initialize(uint16 opcode, size_t newres=200)
        {
            clear();
            _storage.reserve(newres);
            m_opcode = opcode;
        }

        uint16 GetOpcode() const { return m_opcode; }
        void SetOpcode(uint16 opcode) { m_opcode = opcode; }

    protected:
        uint16 m_opcode;
};

#endif
