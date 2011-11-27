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

#include "WorldPacket.h"
#include <zlib.h>
#include "World.h"

void WorldPacket::Compress(Opcodes opcode)
{
    if (opcode == UNKNOWN_OPCODE || opcode == NULL)
    {
        sLog->outError("Tried to compress packet with unknown opcode (%u)", uint32(opcode));
        return;
    }
    Opcodes uncompressedOpcode = GetOpcode();
    uint32 size = wpos();
    uint32 destsize = compressBound(size);

    std::vector<uint8> storage(destsize);

    _compress(static_cast<void*>(&storage[0]), &destsize, static_cast<const void*>(contents()), size);
    if (destsize == 0)
        return;

    clear();
    reserve(destsize + sizeof(uint32));
    *this << uint32(size);
    append(&storage[0], destsize);
    SetOpcode(opcode);

    sLog->outStaticDebug("Successfully compressed opcode %u (len %u) to %u (len %u)",
        uncompressedOpcode, size, opcode, destsize);
}

void WorldPacket::_compress(void* dst, uint32 *dst_size, const void* src, int src_size)
{
    z_stream c_stream;

    c_stream.zalloc = (alloc_func)0;
    c_stream.zfree = (free_func)0;
    c_stream.opaque = (voidpf)0;

    // default Z_BEST_SPEED (1)
    int z_res = deflateInit(&c_stream, sWorld->getIntConfig(CONFIG_COMPRESSION));
    if (z_res != Z_OK)
    {
        sLog->outError("Can't compress packet (zlib: deflateInit) Error code: %i (%s)",z_res,zError(z_res));
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
        sLog->outError("Can't compress packet (zlib: deflate) Error code: %i (%s)",z_res,zError(z_res));
        *dst_size = 0;
        return;
    }

    if (c_stream.avail_in != 0)
    {
        sLog->outError("Can't compress packet (zlib: deflate not greedy)");
        *dst_size = 0;
        return;
    }

    z_res = deflate(&c_stream, Z_FINISH);
    if (z_res != Z_STREAM_END)
    {
        sLog->outError("Can't compress packet (zlib: deflate should report Z_STREAM_END instead %i (%s)",z_res,zError(z_res));
        *dst_size = 0;
        return;
    }

    z_res = deflateEnd(&c_stream);
    if (z_res != Z_OK)
    {
        sLog->outError("Can't compress packet (zlib: deflateEnd) Error code: %i (%s)",z_res,zError(z_res));
        *dst_size = 0;
        return;
    }

    *dst_size = c_stream.total_out;
}