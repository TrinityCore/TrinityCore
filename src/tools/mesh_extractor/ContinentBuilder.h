#ifndef CONT_BUILDER_H
#define CONT_BUILDER_H
#include <string>
#include "WDT.h"
#include "Common.h"

class ContinentBuilder
{
public:
    ContinentBuilder(std::string continent, uint32 mapId, WDT* wdt, uint32 tn) : MapId(mapId), Continent(continent), TileMap(wdt), NumberOfThreads(tn) {}
    void Build(bool debug);
private:
    std::string Continent;
    WDT* TileMap;
    uint32 MapId;
    uint32 NumberOfThreads;
};
#endif