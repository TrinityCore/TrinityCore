#include "ADT.h"
#include "DoodadHandler.h"
#include "LiquidHandler.h"
#include "WorldModelHandler.h"

ADT::ADT( std::string file ) : ObjectData(NULL), Data(NULL), _DoodadHandler(NULL), _WorldModelHandler(NULL), _LiquidHandler(NULL), HasObjectData(false)
{
    Data = new ChunkedData(file);
    ObjectData = new ChunkedData(Utils::Replace(file, ".adt", "_obj0.adt"));
    if (ObjectData->Stream)
        HasObjectData = true;
    else
        ObjectData = NULL;
}

ADT::~ADT()
{
    delete ObjectData;
    delete Data;
    
    for (std::vector<MapChunk*>::iterator itr = MapChunks.begin(); itr != MapChunks.end(); ++itr)
        delete *itr;

    MapChunks.clear();
    delete _DoodadHandler;
    delete _WorldModelHandler;
    delete _LiquidHandler;
}

void ADT::Read()
{
    Chunk* mhdr = Data->GetChunkByName("MHDR");
    if (!mhdr)
    {
        delete Data;
        Data = NULL;
        return;
    }
    Header.Read(mhdr->GetStream());
    MapChunks.reserve(16 * 16);
    int mapChunkIndex = 0;

    for (std::vector<Chunk*>::iterator itr = Data->Chunks.begin(); itr != Data->Chunks.end(); ++itr)
        if ((*itr)->Name == "MCNK")
            MapChunks.push_back(new MapChunk(this, *itr));

    _LiquidHandler = new LiquidHandler(this);

    // do this separate from map chunk initialization to access liquid data
    for (std::vector<MapChunk*>::iterator itr = MapChunks.begin(); itr != MapChunks.end(); ++itr)
        (*itr)->GenerateTriangles();

    _DoodadHandler = new DoodadHandler(this);
    for (std::vector<MapChunk*>::iterator itr = MapChunks.begin(); itr != MapChunks.end(); ++itr)
        _DoodadHandler->ProcessMapChunk(*itr);

    _WorldModelHandler = new WorldModelHandler(this);
    for (std::vector<MapChunk*>::iterator itr = MapChunks.begin(); itr != MapChunks.end(); ++itr)
        _WorldModelHandler->ProcessMapChunk(*itr);
}
