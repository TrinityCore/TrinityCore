#ifndef CONT_BUILDER_H
#define CONT_BUILDER_H
#include <string>
#include "WDT.h"

class ContinentBuilder
{
public:
    ContinentBuilder(std::string continent, WDT* wdt) : Continent(continent), TileMap(wdt) {}
    void Build();
private:
    std::string Continent;
    WDT* TileMap;
};
#endif