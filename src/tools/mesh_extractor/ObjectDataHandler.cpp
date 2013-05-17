#include "ObjectDataHandler.h"
#include "Chunk.h"
#include "ADT.h"
#include "ChunkedData.h"

void ObjectDataHandler::ProcessMapChunk( MapChunk* chunk )
{
    if (!Source->HasObjectData)
        return;
    // fuck it blizzard, why is this crap necessary?
    int32 firstIndex = Source->ObjectData->GetFirstIndex("MCNK");
    if (firstIndex == -1)
        return;
    if (uint32(firstIndex + chunk->Index) > Source->ObjectData->Chunks.size())
        return;
    Chunk* ourChunk = Source->ObjectData->Chunks[firstIndex + chunk->Index];
    if (ourChunk->Length == 0)
        return;
    ChunkedData* subChunks = new ChunkedData(ourChunk->GetStream(), ourChunk->Length, 2);
    ProcessInternal(subChunks);
}
