/*
 * Copyright (C) 2011-2016 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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
    ModelFile = Utils::ReadString(fileChunk->GetStream());
    Model = new WorldModelRoot(ModelFile);
}

void WDT::ReadTileTable()
{
    Chunk* chunk = Data->GetChunkByName("MAIN");
    if (!chunk)
        return;
    IsValid = true;
    FILE* stream = chunk->GetStream();
    for (int y = 0; y < 64; ++y)
    {
        for (int x = 0; x < 64; ++x)
        {
            const uint32 hasTileFlag = 0x1;
            uint32 flags;
            uint32 discard;
            int count = 0;
            count += fread(&flags, sizeof(uint32), 1, stream);
            count += fread(&discard, sizeof(uint32), 1, stream);

            if (count != 2)
                printf("WDT::ReadTileTable: Failed to read some data expected 2, read %d\n", count);

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
