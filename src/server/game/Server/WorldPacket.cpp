/*
 * Copyright (C) 2011 TrinityCore <http://www.trinitycore.org/>
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

#include <zlib.h>
#include "WorldPacket.h"
#include "World.h"

void WorldPacket::Compress(z_stream* compressionStream)
{
    Opcodes uncompressedOpcode = GetOpcode();
    Opcodes opcode = Opcodes(uncompressedOpcode | COMPRESSED_OPCODE_MASK);
    uint32 size = wpos();
    uint32 destsize = compressBound(size);

    std::vector<uint8> storage(destsize);

    _compressionStream = compressionStream;
    Compress(static_cast<void*>(&storage[0]), &destsize, static_cast<const void*>(contents()), size);
    if (destsize == 0)
        return;

    clear();
    reserve(destsize + sizeof(uint32));
    *this << uint32(size);
    append(&storage[0], destsize);
    SetOpcode(opcode);

    sLog->outStaticDebug("Successfully compressed opcode %u (len %u) to %u (len %u)", uncompressedOpcode, size, opcode, destsize);
}

void WorldPacket::Compress(void* dst, uint32 *dst_size, const void* src, int src_size)
{
    _compressionStream->next_out = (Bytef*)dst;
    _compressionStream->avail_out = *dst_size;
    _compressionStream->next_in = (Bytef*)src;
    _compressionStream->avail_in = (uInt)src_size;

    int32 z_res = deflate(_compressionStream, Z_SYNC_FLUSH);
    if (z_res != Z_OK)
    {
        sLog->outError("Can't compress packet (zlib: deflate) Error code: %i (%s, msg: %s)", z_res, zError(z_res), _compressionStream->msg);
        *dst_size = 0;
        return;
    }

    if (_compressionStream->avail_in != 0)
    {
        sLog->outError("Can't compress packet (zlib: deflate not greedy)");
        *dst_size = 0;
        return;
    }

    *dst_size -= _compressionStream->avail_out;
}
