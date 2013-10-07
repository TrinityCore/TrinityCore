#ifndef ODATA_HNDL_H
#define ODATA_HNDL_H
#include "ADT.h"
#include "MapChunk.h"

class ObjectDataHandler
{
public:
    ObjectDataHandler(ADT* _adt) : Source(_adt) {}

    void ProcessMapChunk(MapChunk* chunk);
    virtual void ProcessInternal(MapChunk* data) = 0;
    ADT* Source;
};
#endif