#ifndef ADT_H
#define ADT_H
#include "ChunkedData.h"
#include "MapChunk.h"
#include "DoodadHandler.h"
#include "WorldModelHandler.h"

class ADT
{
public:
    ADT();
    ~ADT() { delete[] MapChunks; delete ObjectData; delete Data; }

    ChunkedData* ObjectData;
    ChunkedData* Data;
    // This here is not a pointer, is an array of objects ( made this way to allow the dynamic allocation )
    MapChunk* MapChunks;
    MHDR Header;
    // Can we dispose of this?
    bool HasObjectData;

    DoodadHandler* _DoodadHandler;
    WorldModelHandler* _WorldModelHandler;
    LiquidHandler* _LiquidHandler;
};
#endif