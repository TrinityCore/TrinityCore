/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ChunkedData.h"
#include "MPQManager.h"
#include "Utils.h"

#include <string>

ChunkedData::ChunkedData( FILE* stream, uint32 maxLength, uint32 chunksHint /*= 300*/ ) :
Stream(stream)
{
    if (!Stream)
        return;
    Load(maxLength, chunksHint);
}

ChunkedData::ChunkedData( const std::string& file, uint32 chunksHint /*= 300*/ )
{
    Stream = MPQHandler->GetFile(file);
    if (!Stream)
        return;
    Load(0, chunksHint);
}

void ChunkedData::Load( uint32 maxLength, uint32 chunksHint )
{
    if (!maxLength)
        maxLength = Utils::Size(Stream);
    Chunks.reserve(chunksHint);
    uint32 baseOffset = ftell(Stream);
    uint32 calcOffset = 0;
    while ((calcOffset + baseOffset) < Utils::Size(Stream) && (calcOffset < maxLength))
    {
        char nameBytes[5];
        uint32 read = fread(&nameBytes, sizeof(char), 4, Stream);
        nameBytes[read] = '\0';
        std::string name = std::string(nameBytes);
        // Utils::Reverse(nameBytes);
        name = std::string(name.rbegin(), name.rend());
        uint32 length;
        if (fread(&length, sizeof(uint32), 1, Stream) != 1)
            continue;
        calcOffset += 8;
        Chunks.push_back(new Chunk(name.c_str(), length, calcOffset + baseOffset, Stream));
        calcOffset += length;
        // save an extra seek at the end
        if ((calcOffset + baseOffset) < Utils::Size(Stream) && calcOffset < maxLength)
            fseek(Stream, length, SEEK_CUR);
    }
}

int ChunkedData::GetFirstIndex( const std::string& name )
{
    for (uint32 i = 0; i < Chunks.size(); ++i)
        if (Chunks[i]->Name == name)
            return i;
    return -1;
}

Chunk* ChunkedData::GetChunkByName( const std::string& name )
{
    for (uint32 i = 0; i < Chunks.size(); ++i)
        if (Chunks[i]->Name == name)
            return Chunks[i];
    return NULL;
}

ChunkedData::~ChunkedData()
{
    for (std::vector<Chunk*>::iterator itr = Chunks.begin(); itr != Chunks.end(); ++itr)
        delete *itr;

    Chunks.clear();
    if (Stream)
        fclose(Stream);
}
