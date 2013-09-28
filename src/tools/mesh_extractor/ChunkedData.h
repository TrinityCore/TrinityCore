#ifndef CHNK_H
#define CHNK_H

#include <vector>
#include "Chunk.h"

class ChunkedData
{
public:
    ChunkedData(FILE* stream, uint32 maxLength, uint32 chunksHint = 300);
    ChunkedData(const std::string &file, uint32 chunksHint = 300);
    ~ChunkedData();

    int GetFirstIndex(const std::string& name);
    Chunk* GetChunkByName(const std::string& name);

    void Load(uint32 maxLength, uint32 chunksHint);
    std::vector<Chunk*> Chunks;
    FILE* Stream;
};
#endif