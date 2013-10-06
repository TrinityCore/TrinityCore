#ifndef CHUNK_H
#define CHUNK_H
#include "Define.h"
#include <string>
#include "Stream.h"

class ChunkedData;

class Chunk
{
public:
    Chunk(const char* name, uint32 length, uint32 offset, Stream* stream) : Name(name), Length(length), Offset(offset), _Stream(stream) {}

    int32 FindSubChunkOffset(std::string name);
    Stream* GetStream();
    std::string Name;
    uint32 Length;
    uint32 Offset;
    Stream* _Stream;
};

#endif