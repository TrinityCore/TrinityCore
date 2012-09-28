#include "Model.h"
#include "MPQManager.h"
#include "Utils.h"

Model::Model( std::string path )
{
    Stream = MPQHandler->GetFile(Utils::FixModelPath(path));
    Header.Read(Stream);
    if (Header.OffsetBoundingNormals > 0 && Header.OffsetBoundingVertices > 0 &&
        Header.OffsetBoundingTriangles > 0 && Header.BoundingRadius > 0.0f)
    {
        IsCollidable = true;
        ReadVertices(Stream);
        ReadBoundingNormals(Stream);
        ReadBoundingTriangles(Stream);
    }
}

void Model::ReadVertices( FILE* stream )
{
    fseek(stream, Header.OffsetBoundingVertices, SEEK_SET);
    Vertices.reserve(Header.CountBoundingVertices);
    for (int i = 0; i < Header.CountBoundingVertices; ++i)
        Vertices[i] = Vector3::Read(stream);
}

void Model::ReadBoundingTriangles( FILE* stream )
{
    fseek(stream, Header.OffsetBoundingTriangles, SEEK_SET);
    Triangles.reserve(Header.CountBoundingTriangles / 3);
    for (int i = 0; i < Header.CountBoundingTriangles / 3; i++)
    {
        Triangle<uint16> tri;
        tri.Type = Constants::TRIANGLE_TYPE_DOODAD;
        fread(&tri.V0, sizeof(uint16), 1, stream);
        fread(&tri.V1, sizeof(uint16), 1, stream);
        fread(&tri.V2, sizeof(uint16), 1, stream);
        Triangles[i] = tri;
    }
}

void Model::ReadBoundingNormals( FILE* stream )
{
    fseek(stream, Header.OffsetBoundingNormals, SEEK_SET);
    Normals.reserve(Header.CountBoundingNormals);
    for (int i = 0; i < Header.CountBoundingNormals; i++)
        Normals[i] = Vector3::Read(stream);
}

