#ifndef WDT_H
#define WDT_H
#include <string>
#include <vector>

#include "ChunkedData.h"
#include "WorldModelHandler.h"
#include "Utils.h"

class WDT
{
public:
    WDT(std::string file);

    ChunkedData* Data;
    std::vector<TilePos> TileTable;
    bool IsGlobalModel;
    bool IsValid;
    std::string ModelFile;
    WorldModelDefinition ModelDefinition;
    bool HasTile(int x, int y);
private:
    void ReadGlobalModel();
    void ReadTileTable();
};

#endif