#ifndef CONT_BUILDER_H
#define CONT_BUILDER_H
#include <string>
#include "WDT.h"
#include "Common.h"

class ContinentBuilder
{
public:
    ContinentBuilder(std::string continent, uint32 mapId, WDT* wdt) : MapId(mapId), Continent(continent), TileMap(wdt) {}
    void Build();
private:
    std::string Continent;
    WDT* TileMap;
    uint32 MapId;
};
#endif