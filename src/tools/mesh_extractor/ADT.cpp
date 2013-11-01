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

#include "ADT.h"
#include "DoodadHandler.h"
#include "LiquidHandler.h"
#include "WorldModelHandler.h"

ADT::ADT( std::string file, int x, int y ) : ObjectData(NULL), Data(NULL), HasObjectData(false),
    _DoodadHandler(NULL), _WorldModelHandler(NULL), _LiquidHandler(NULL), X(x), Y(y)
{
    Data = new ChunkedData(file);
    ObjectData = new ChunkedData(file);
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
    Header.Read(Data->GetChunkByName("MHDR")->GetStream());
    MapChunks.reserve(16 * 16);

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
