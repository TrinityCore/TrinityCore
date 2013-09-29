#include "ObjectDataHandler.h"
#include "Chunk.h"
#include "ADT.h"
#include "ChunkedData.h"

void ObjectDataHandler::ProcessMapChunk( MapChunk* chunk )
{
    /*if (!Source->HasObjectData)
        return;*/
    ProcessInternal(chunk);
}
