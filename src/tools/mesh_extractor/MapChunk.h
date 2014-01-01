/*
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

#ifndef MAPCHUNK_H
#define MAPCHUNK_H
#include "Chunk.h"
#include "Utils.h"
#include "Constants.h"
#include <vector>
class ADT;

class MapChunk
{
public:
    MapChunk(ADT* _adt, Chunk* chunk);

    void GenerateTriangles();
    void GenerateVertices(Stream* stream);
    static bool HasHole(uint32 map, int x, int y);
    ADT* Adt;
    Chunk* Source;
    MapChunkHeader Header;
    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint8> > Triangles;
    int32 Index;
};
#endif