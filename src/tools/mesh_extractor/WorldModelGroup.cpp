#include "WorldModelGroup.h"
#include "ChunkedData.h"
#include "Chunk.h"

WorldModelGroup::WorldModelGroup( std::string path, int groupIndex ) : GroupIndex(groupIndex), IsBad(false)
{
    Data = new ChunkedData(path);
    if (!Data->Stream)
    {
        IsBad = true;
        return;
    }
    Chunk* mainChunk = Data->GetChunkByName("MOGP");
    int32 firstSub = mainChunk->FindSubChunkOffset("MOPY");
    if (firstSub == -1)
        return;
    FILE* stream = mainChunk->GetStream();
    fseek(stream, firstSub, SEEK_SET);
    SubData = new ChunkedData(stream, mainChunk->Length - firstSub);

    ReadBoundingBox();
    ReadMaterials();
    ReadTriangles();
    ReadVertices();
    ReadNormals();
    ReadLiquid();
}

void WorldModelGroup::ReadNormals()
{
    Chunk* chunk = SubData->GetChunkByName("MONR");
    if (!chunk)
        return;

    uint32 normalCount = chunk->Length / 12;
    ASSERT(normalCount == Vertices.size() && "normalCount is different than the Vertices count");
    Normals.reserve(normalCount);
    FILE* stream = chunk->GetStream();
    for (uint32 i = 0; i < normalCount; i++)
        Normals.push_back(Vector3::Read(stream));
}

void WorldModelGroup::ReadLiquid()
{
    Chunk* chunk = SubData->GetChunkByName("MLIQ");
    if (!chunk)
        return;

    HasLiquidData = true;
    FILE* stream = chunk->GetStream();
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
    FILE* stream = chunk->GetStream();
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
    FILE* stream = chunk->GetStream();
    Triangles.reserve(triangleCount);
    for (uint32 i = 0; i < triangleCount; i++)
    {
        uint16 v0;
        uint16 v1;
        uint16 v2;
        fread(&v0, sizeof(uint16), 1, stream);
        fread(&v1, sizeof(uint16), 1, stream);
        fread(&v2, sizeof(uint16), 1, stream);
        Triangles.push_back(Triangle<uint16>(Constants::TRIANGLE_TYPE_WMO, v0, v1, v2));
    }
}

void WorldModelGroup::ReadMaterials()
{
    Chunk* chunk = SubData->GetChunkByName("MOPY");
    if (!chunk)
        return;

    FILE* stream = chunk->GetStream();
    uint32 triangleCount = chunk->Length / 2;
    TriangleFlags.reserve(triangleCount);
    TriangleMaterials.reserve(triangleCount);
    for (uint32 i = 0; i < triangleCount; i++)
    {
        uint8 tmp;
        fread(&tmp, sizeof(uint8), 1, stream);
        TriangleFlags.push_back(tmp);
        // Read again for material.
        fread(&tmp, sizeof(uint8), 1, stream);
        TriangleMaterials.push_back(tmp);
    }
}

void WorldModelGroup::ReadBoundingBox()
{
    Chunk* chunk = Data->GetChunkByName("MOGP");
    if (!chunk)
        return;

    FILE* stream = chunk->GetStream();
    fseek(stream, 8, SEEK_CUR);
    fread(&Flags, sizeof(uint32), 1, stream);
    BoundingBox[0] = Vector3::Read(stream);
    BoundingBox[1] = Vector3::Read(stream);
}
