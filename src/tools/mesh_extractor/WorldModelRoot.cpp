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

#include "WorldModelRoot.h"
#include "ChunkedData.h"
#include "Utils.h"

WorldModelRoot::WorldModelRoot( std::string path )
{
    Data = new ChunkedData(path);
    Path = path;
    ReadHeader();
    ReadGroups();
    ReadDoodadInstances();
    ReadDoodadSets();
}

WorldModelRoot::~WorldModelRoot()
{
    delete Data;
}

void WorldModelRoot::ReadGroups()
{
    std::string pathBase = Utils::GetPathBase(Path);
    Groups.reserve(Header.CountGroups);
    for (uint32 i = 0; i < Header.CountGroups; i++)
    {
        char name[200];
        sprintf(name, "%s_%03u.wmo", pathBase.c_str(), i);
        WorldModelGroup group(name, i);
        if (!group.IsBad)
            Groups.push_back(std::move(group));
    }
}

void WorldModelRoot::ReadDoodadSets()
{
    Chunk* chunk = Data->GetChunkByName("MODS");
    if (!chunk)
        return;

    Stream* stream = chunk->GetStream();
    ASSERT(chunk->Length / 32 == Header.CountSets && "chunk.Length / 32 == Header.CountSets");
    DoodadSets.reserve(Header.CountSets);
    for (uint32 i = 0; i < Header.CountSets; i++)
        DoodadSets.push_back(DoodadSet::Read(stream));
}

void WorldModelRoot::ReadDoodadInstances()
{
    Chunk* chunk = Data->GetChunkByName("MODD");
    Chunk* nameChunk = Data->GetChunkByName("MODN");
    if (!chunk || !nameChunk)
        return;

    const uint32 instanceSize = 40;
    uint32 countInstances = chunk->Length / instanceSize;
    DoodadInstances.reserve(countInstances);
    for (uint32 i = 0; i < countInstances; i++)
    {
        Stream* stream = chunk->GetStream();
        stream->Seek(instanceSize * i, SEEK_CUR);
        DoodadInstance instance = DoodadInstance::Read(stream);
        Stream* nameStream = nameChunk->GetStream();
        if (instance.FileOffset >= nameChunk->Length)
            continue;
        nameStream->Seek(instance.FileOffset, SEEK_CUR);
        instance.File = nameStream->ReadString();
        DoodadInstances.push_back(instance);
    }
}

void WorldModelRoot::ReadHeader()
{
    Chunk* chunk = Data->GetChunkByName("MOHD");
    if (!chunk)
        return;

    Stream* stream = chunk->GetStream();
    Header.Read(stream);
}
