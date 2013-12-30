/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "Cache.h"

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
    Model = Cache->WorldModelCache.Get(ModelFile);
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
