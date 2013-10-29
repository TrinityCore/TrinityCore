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

#include "WorldModelGroup.h"
#include "ChunkedData.h"
#include "Chunk.h"
#include "Utils.h"

WorldModelGroup::WorldModelGroup(std::string path, int groupIndex) : GroupIndex(groupIndex), MOBA(NULL), IsBad(false), HasLiquidData(false)
{
    Data = new ChunkedData(path);
    if (!Data->_Stream)
    {
        IsBad = true;
        return;
    }
    Chunk* mainChunk = Data->GetChunkByName("MOGP");
    int32 firstSub = mainChunk->FindSubChunkOffset("MOPY");
    if (firstSub == -1)
        return;

    Name = Utils::GetPlainName(path.c_str());

    Stream* stream = mainChunk->GetStream();
    stream->Seek(firstSub, SEEK_SET);
    SubData = new ChunkedData(stream, mainChunk->Length - firstSub);

    ReadHeader();
    ReadMaterials();
    ReadTriangles();
    ReadVertices();
    ReadNormals();
    ReadLiquid();
    ReadBatches();
}

void WorldModelGroup::ReadNormals()
{
    Chunk* chunk = SubData->GetChunkByName("MONR");
    if (!chunk)
        return;

    uint32 normalCount = chunk->Length / 12;
    ASSERT(normalCount == Vertices.size() && "normalCount is different than the Vertices count");
    Normals.reserve(normalCount);
    Stream* stream = chunk->GetStream();
    for (uint32 i = 0; i < normalCount; i++)
        Normals.push_back(Vector3::Read(stream));
}

void WorldModelGroup::ReadLiquid()
{
    Chunk* chunk = SubData->GetChunkByName("MLIQ");
    if (!chunk)
        return;

    HasLiquidData = true;
    Stream* stream = chunk->GetStream();
    LiquidDataHeader = LiquidHeader::Read(stream);
    LiquidDataGeometry = LiquidData::Read(stream, LiquidDataHeader);
}

void WorldModelGroup::ReadVertices()
{
    Chunk* chunk = SubData->GetChunkByName("MOVT");
    if (!chunk)
        return;

    uint32 verticeCount = chunk->Length / 12;
    Vertices.reserve(verticeCount);
    Stream* stream = chunk->GetStream();
    for (uint32 i = 0; i < verticeCount; i++)
        Vertices.push_back(Vector3::Read(stream));
}

void WorldModelGroup::ReadTriangles()
{
    Chunk* chunk = SubData->GetChunkByName("MOVI");
    if (!chunk)
        return;

    uint32 triangleCount = chunk->Length / 6;
    ASSERT(triangleCount == TriangleFlags.size() && "triangleCount != TriangleFlags.size()");
    Stream* stream = chunk->GetStream();
    Triangles.reserve(triangleCount);
    for (uint32 i = 0; i < triangleCount; i++)
    {
        uint16 v0 = stream->Read<uint16>();
        uint16 v1 = stream->Read<uint16>();
        uint16 v2 = stream->Read<uint16>();

        Triangles.push_back(Triangle<uint16>(Constants::TRIANGLE_TYPE_WMO, v0, v1, v2));
    }
}

void WorldModelGroup::ReadMaterials()
{
    Chunk* chunk = SubData->GetChunkByName("MOPY");
    if (!chunk)
        return;

    Stream* stream = chunk->GetStream();
    uint32 triangleCount = chunk->Length / 2;
    TriangleFlags.reserve(triangleCount);
    TriangleMaterials.reserve(triangleCount);
    for (uint32 i = 0; i < triangleCount; i++)
    {
        TriangleFlags.push_back(stream->Read<uint8>());
        // Read again for material.
        TriangleMaterials.push_back(stream->Read<uint8>());
    }
}

void WorldModelGroup::ReadHeader()
{
    Chunk* chunk = Data->GetChunkByName("MOGP");
    if (!chunk)
        return;

    Stream* stream = chunk->GetStream();
    Header = WMOGroupHeader::Read(stream);
}

void WorldModelGroup::ReadBatches()
{
    Chunk* chunk = Data->GetChunkByName("MOBA");
    if (!chunk)
        return;

    MOBALength = chunk->Length / 2;
    MOBA = new uint16[MOBALength];
    chunk->GetStream()->Read(MOBA, sizeof(uint16) * MOBALength);
}
