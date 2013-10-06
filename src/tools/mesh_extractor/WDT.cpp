#include "WDT.h"
#include "Chunk.h"
#include "ChunkedData.h"
#include "Utils.h"
#include "WorldModelHandler.h"

WDT::WDT(std::string file) : IsGlobalModel(false), IsValid(false), Model(NULL)
{
    Data = new ChunkedData(file, 2);
    ReadTileTable();
    ReadGlobalModel();
}

void WDT::ReadGlobalModel()
{
    Chunk* fileChunk = Data->GetChunkByName("MWMO");
    Chunk* defChunk = Data->GetChunkByName("MODF");
    if (!fileChunk || !defChunk)
        return;

    IsGlobalModel = true;
    ModelDefinition = WorldModelDefinition::Read(defChunk->GetStream());
    ModelFile = fileChunk->GetStream()->ReadString();
    Model = new WorldModelRoot(ModelFile);
}

void WDT::ReadTileTable()
{
    Chunk* chunk = Data->GetChunkByName("MAIN");
    if (!chunk)
        return;
    IsValid = true;
    Stream* stream = chunk->GetStream();
    for (int y = 0; y < 64; ++y)
    {
        for (int x = 0; x < 64; ++x)
        {
            const uint32 hasTileFlag = 0x1;
            uint32 flags = stream->Read<uint32>();
            uint32 discard = stream->Read<uint32>();

            if (flags & hasTileFlag)
                TileTable.push_back(TilePos(x, y));

        }
    }
}

bool WDT::HasTile( int x, int y )
{
    for (std::vector<TilePos>::iterator itr = TileTable.begin(); itr != TileTable.end(); ++itr)
        if (itr->X == x && itr->Y == y)
            return true;
    return false;
}
