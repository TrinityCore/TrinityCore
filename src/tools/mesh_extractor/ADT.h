#ifndef ADT_H
#define ADT_H
#include "ChunkedData.h"
#include "MapChunk.h"
#include "DoodadHandler.h"
#include "WorldModelHandler.h"
#include "LiquidHandler.h"

class ADT
{
public:
    ADT(std::string file);
    ~ADT();
    
    void Read();

    ChunkedData* ObjectData;
    ChunkedData* Data;
    std::vector<MapChunk*> MapChunks;
    MHDR Header;
    // Can we dispose of this?
    bool HasObjectData;

    DoodadHandler* _DoodadHandler;
    WorldModelHandler* _WorldModelHandler;
    LiquidHandler* _LiquidHandler;
};
#endif