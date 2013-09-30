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
    if (Data)
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
            Groups.push_back(group);
    }
}

void WorldModelRoot::ReadDoodadSets()
{
    Chunk* chunk = Data->GetChunkByName("MODS");
    if (!chunk)
        return;

    FILE* stream = chunk->GetStream();
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
        FILE* stream = chunk->GetStream();
        fseek(stream, instanceSize * i, SEEK_CUR);
        DoodadInstance instance = DoodadInstance::Read(stream);
        FILE* nameStream = nameChunk->GetStream();
        if (instance.FileOffset >= nameChunk->Length)
            continue;
        fseek(nameStream, instance.FileOffset, SEEK_CUR);
        instance.File = Utils::ReadString(nameStream);
        DoodadInstances.push_back(instance);
    }
}

void WorldModelRoot::ReadHeader()
{
    Chunk* chunk = Data->GetChunkByName("MOHD");
    if (!chunk)
        return;

    FILE* stream = chunk->GetStream();
    Header = WorldModelHeader::Read(stream);
}
