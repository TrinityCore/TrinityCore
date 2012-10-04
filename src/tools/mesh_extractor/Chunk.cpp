#include "Chunk.h"
#include "Utils.h"

int32 Chunk::FindSubChunkOffset(std::string name)
{
    // Reverse the name
    name = std::string(name.rbegin(), name.rend());
    if (name.size() != 4)
        return -1;

    FILE* stream = GetStream();
    uint32 matched = 0;
    while (uint32(ftell(stream)) < Utils::Size(stream))
    {
        char b;
        fread(&b, sizeof(char), 1, stream);
        if (b == name[matched])
            ++matched;
        else
            matched = 0;
        if (matched == 4)
            return ftell(stream) - 4;
    }
    return -1;
}

FILE* Chunk::GetStream()
{
    fseek(Stream, Offset, SEEK_SET);
    return Stream;
}
