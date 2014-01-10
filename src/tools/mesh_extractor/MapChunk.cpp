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

#include "MapChunk.h"
#include "ADT.h"
#include "LiquidHandler.h"

MapChunk::MapChunk( ADT* _adt, Chunk* chunk ) : Adt(_adt), Source(chunk)
{
    Stream* stream = chunk->GetStream();
    Header.Read(stream);
    stream->Seek(chunk->Offset, SEEK_SET);
    Index = Header.IndexX + Header.IndexY * 16;
    GenerateVertices(stream);
}

void MapChunk::GenerateTriangles()
{
    Triangles.reserve(256);
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (HasHole(Header.Holes, x / 2, y / 2))
                continue;

            uint32 topLeft = (17 * y) + x;
            uint32 topRight = (17 * y) + x + 1;
            uint32 bottomLeft = (17 * (y + 1)) + x;
            uint32 bottomRight = (17 * (y + 1)) + x + 1;
            uint32 center = (17 * y) + 9 + x;

            Constants::TriangleType triangleType = Constants::TRIANGLE_TYPE_TERRAIN;
            if (Adt->_LiquidHandler && !Adt->_LiquidHandler->MCNKData.empty())
            {
                MCNKLiquidData* data = Adt->_LiquidHandler->MCNKData[Index];
                float maxHeight = std::max(
                    std::max(
                    std::max(std::max(Vertices[topLeft].z, Vertices[topRight].z), Vertices[bottomLeft].z),
                    Vertices[bottomRight].z), Vertices[center].z);
                if (data->IsWater(x, y, maxHeight))
                    triangleType = Constants::TRIANGLE_TYPE_WATER;
            }

            Triangles.push_back(Triangle<uint8>(triangleType, topRight, topLeft, center));
            Triangles.push_back(Triangle<uint8>(triangleType, topLeft, bottomLeft, center));
            Triangles.push_back(Triangle<uint8>(triangleType, bottomLeft, bottomRight, center));
            Triangles.push_back(Triangle<uint8>(triangleType, bottomRight, topRight, center));
        }
    }
}

void MapChunk::GenerateVertices(Stream* stream)
{
    stream->Seek(Header.OffsetMCVT, SEEK_CUR);
    Vertices.reserve(125);

    for (int j = 0; j < 17; j++)
    {
        int values = j % 2 ? 8 : 9;
        for (int i = 0; i < values; i++)
        {
            float tmp = stream->Read<float>();
            Vector3 vert(Header.Position.x - (j * (Constants::UnitSize * 0.5f)), Header.Position.y - (i * Constants::UnitSize), Header.Position.z + tmp);
            if (values == 8)
                vert.y -= Constants::UnitSize * 0.5f;
            Vertices.push_back(vert);
        }
    }
    // Restore stream position.
    stream->Seek(Source->Offset, SEEK_SET);
}

bool MapChunk::HasHole( uint32 map, int x, int y )
{
    return (map & 0x0000FFFF) & ((1 << x) << (y << 2));
}
