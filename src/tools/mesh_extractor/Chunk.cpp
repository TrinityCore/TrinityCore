/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Chunk.h"
#include "Utils.h"

int32 Chunk::FindSubChunkOffset(std::string name)
{
    // Reverse the name
    name = std::string(name.rbegin(), name.rend());
    if (name.size() != 4)
        return -1;

    Stream* stream = GetStream();
    uint32 matched = 0;
    while (stream->GetPos() < stream->GetSize())
    {
        char b = stream->Read<char>();
        if (b != name[matched])
            matched = 0;
        else
            ++matched;

        if (matched == 4)
            return stream->GetPos() - 4;
    }
    return -1;
}

Stream* Chunk::GetStream()
{
    _Stream->Seek(Offset, SEEK_SET);
    return _Stream;
}
