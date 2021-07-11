/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "UpdateData.h"
#include "ByteBuffer.h"
#include "WorldPacket.h"
#include "Log.h"
#include "Opcodes.h"
#include "World.h"
#include "ObjectGuid.h"
#include <zlib.h>

#define MAX_UNCOMPRESSED_PACKET_SIZE 0x8000 // 32ko

UpdateData::UpdateData()
{
}

UpdateData::~UpdateData()
{
    Clear();
}

void UpdateData::AddOutOfRangeGUID(ObjectGuidSet& guids)
{
    m_outOfRangeGUIDs.insert(guids.begin(), guids.end());
}

void UpdateData::AddOutOfRangeGUID(ObjectGuid const& guid)
{
    m_outOfRangeGUIDs.insert(guid);
}

void UpdateData::AddUpdateBlock(ByteBuffer const& block)
{
    if (m_datas.empty())
        m_datas.push_back(UpdatePacket());
    std::list<UpdatePacket>::iterator it = m_datas.end();
    --it;
    if (it->data.wpos() > MAX_UNCOMPRESSED_PACKET_SIZE)
    {
        m_datas.push_back(UpdatePacket());
        it = m_datas.end();
        --it;
    }
    it->data.append(block);
    ++it->blockCount;
}

void PacketCompressor::Compress(void* dst, uint32* dst_size, void* src, int src_size)
{
    z_stream c_stream;

    c_stream.zalloc = (alloc_func)0;
    c_stream.zfree = (free_func)0;
    c_stream.opaque = (voidpf)0;

    // default Z_BEST_SPEED (1)
    int z_res = deflateInit(&c_stream, sWorld.getConfig(CONFIG_UINT32_COMPRESSION));
    if (z_res != Z_OK)
    {
        sLog.outError("Can't compress update packet (zlib: deflateInit) Error code: %i (%s)", z_res, zError(z_res));
        *dst_size = 0;
        return;
    }

    c_stream.next_out = (Bytef*)dst;
    c_stream.avail_out = *dst_size;
    c_stream.next_in = (Bytef*)src;
    c_stream.avail_in = (uInt)src_size;

    z_res = deflate(&c_stream, Z_NO_FLUSH);
    if (z_res != Z_OK)
    {
        sLog.outError("Can't compress update packet (zlib: deflate) Error code: %i (%s)", z_res, zError(z_res));
        *dst_size = 0;
        return;
    }

    if (c_stream.avail_in != 0)
    {
        sLog.outError("Can't compress update packet (zlib: deflate not greedy)");
        *dst_size = 0;
        return;
    }

    z_res = deflate(&c_stream, Z_FINISH);
    if (z_res != Z_STREAM_END)
    {
        sLog.outError("Can't compress update packet (zlib: deflate should report Z_STREAM_END instead %i (%s)", z_res, zError(z_res));
        *dst_size = 0;
        return;
    }

    z_res = deflateEnd(&c_stream);
    if (z_res != Z_OK)
    {
        sLog.outError("Can't compress update packet (zlib: deflateEnd) Error code: %i (%s)", z_res, zError(z_res));
        *dst_size = 0;
        return;
    }

    *dst_size = c_stream.total_out;
}

bool UpdateData::BuildPacket(WorldPacket* packet, bool hasTransport)
{
    if (m_datas.empty())
        return BuildPacket(packet, nullptr, hasTransport);
    return BuildPacket(packet, &(m_datas.front()), hasTransport);
}

bool UpdateData::BuildPacket(WorldPacket* packet, UpdatePacket const* updPacket, bool hasTransport)
{
    MANGOS_ASSERT(packet->empty());                         // shouldn't happen

    ByteBuffer buf(4 + 1 + (m_outOfRangeGUIDs.empty() ? 0 : 1 + 4 + 9 * m_outOfRangeGUIDs.size()) + (updPacket ? updPacket->data.wpos() : 0));

    uint32 blockCount = updPacket ? updPacket->blockCount : 0;
    buf << (uint32)(!m_outOfRangeGUIDs.empty() ? blockCount + 1 : blockCount);
    buf << (uint8)(hasTransport ? 1 : 0);

    if (!m_outOfRangeGUIDs.empty())
    {
        buf << (uint8) UPDATETYPE_OUT_OF_RANGE_OBJECTS;
        buf << (uint32) m_outOfRangeGUIDs.size();

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        for (const auto& guid : m_outOfRangeGUIDs)
            buf << guid.WriteAsPacked();
#else
        for (const auto& guid : m_outOfRangeGUIDs)
            buf << guid;
#endif
    }

    if (updPacket)
        buf.append(updPacket->data);

    size_t pSize = buf.wpos();                              // use real used data size

    if (pSize > 100)                                       // compress large packets
    {
        if (pSize >= 900000)
            sLog.outInfo("[CRASH-CLIENT] Too large packet: %u", pSize);

        uint32 destsize = compressBound(pSize);
        packet->resize(destsize + sizeof(uint32));

        packet->put<uint32>(0, pSize);
        PacketCompressor::Compress(const_cast<uint8*>(packet->contents()) + sizeof(uint32), &destsize, (void*)buf.contents(), pSize);
        if (destsize == 0)
            return false;

        packet->resize(destsize + sizeof(uint32));
        packet->SetOpcode(SMSG_COMPRESSED_UPDATE_OBJECT);
    }
    else                                                    // send small packets without compression
    {
        packet->append(buf);
        packet->SetOpcode(SMSG_UPDATE_OBJECT);
    }

    return true;
}

void UpdateData::Send(WorldSession* session, bool hasTransport)
{
    WorldPacket data;
    if (m_datas.empty() && !m_outOfRangeGUIDs.empty())
    {
        BuildPacket(&data, nullptr, hasTransport);
        session->SendPacket(&data);
        m_outOfRangeGUIDs.clear();
        return;
    }
    for (const auto& itr : m_datas)
    {
        BuildPacket(&data, &itr, hasTransport);
        session->SendPacket(&data);
        data.clear();
        m_outOfRangeGUIDs.clear();
    }
}

void UpdateData::Clear()
{
    m_datas.clear();
    m_outOfRangeGUIDs.clear();
}

void MovementData::SetSplineOpcode(uint32 opcode, ObjectGuid const& unit)
{
    WorldPacket data(opcode, 9);
    data << unit.WriteAsPacked();
    AddPacket(data);
}

void MovementData::SetUnitSpeed(uint32 opcode, ObjectGuid const& unit, float value)
{
    WorldPacket data(opcode, 9 + 4);
    data << unit.WriteAsPacked();
    data << float(value);
    AddPacket(data);
}

void MovementData::AddPacket(WorldPacket& data)
{
    if (_owner) // Do not compress data
    {
        _owner->SendMovementMessageToSet(std::move(data), true);
        return;
    }
    ASSERT(data.wpos() + 2 <= 0xFF); // Max packet size to be stored on uint8. Client crash else.
    _buffer << uint8(data.wpos() + 2); // Packet + opcode size
    _buffer << uint16(data.GetOpcode());
    _buffer.append(data.contents(), data.wpos());
}

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
bool MovementData::BuildPacket(WorldPacket& packet)
{
    MANGOS_ASSERT(packet.empty()); // We want a clean packet !

    size_t pSize = _buffer.wpos();                              // use real used data size

    if (pSize >= 900000)
        sLog.outInfo("[CRASH-CLIENT] Too large packet size %u (SMSG_COMPRESSED_MOVES)", pSize);

    uint32 destsize = compressBound(pSize);
    packet.resize(destsize + sizeof(uint32));
    packet.put<uint32>(0, pSize);
    PacketCompressor::Compress(const_cast<uint8*>(packet.contents()) + sizeof(uint32), &destsize, (void*)_buffer.contents(), pSize);
    if (destsize == 0)
        return false;

    packet.resize(destsize + sizeof(uint32));
    packet.SetOpcode(SMSG_COMPRESSED_MOVES);
    return true;
}
#endif
