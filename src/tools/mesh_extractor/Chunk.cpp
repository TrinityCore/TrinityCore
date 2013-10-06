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
