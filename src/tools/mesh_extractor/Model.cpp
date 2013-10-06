#include "Model.h"
#include "MPQManager.h"
#include "Utils.h"

Model::Model(std::string path) : IsCollidable(false), IsBad(false)
{
    _Stream = MPQHandler->GetFile(Utils::FixModelPath(path));
    if (!_Stream)
    {
        IsBad = true;
        return;
    }
    Header.Read(_Stream);
    if (Header.OffsetBoundingNormals > 0 && Header.OffsetBoundingVertices > 0 &&
        Header.OffsetBoundingTriangles > 0 && Header.BoundingRadius > 0.0f)
    {
        IsCollidable = true;
        ReadVertices();
        ReadBoundingNormals();
        ReadBoundingTriangles();
    }
}

Model::~Model()
{
    if (_Stream)
        delete _Stream;
}

void Model::ReadVertices()
{
    _Stream->Seek(Header.OffsetBoundingVertices, SEEK_SET);
    Vertices.reserve(Header.CountBoundingVertices);
    for (uint32 i = 0; i < Header.CountBoundingVertices; ++i)
    {
        Vertices.push_back(Vector3::Read(_Stream));
        if (Constants::ToWoWCoords)
            Vertices[i] = Utils::ToWoWCoords(Vertices[i]);
    }
}

void Model::ReadBoundingTriangles()
{
    _Stream->Seek(Header.OffsetBoundingTriangles, SEEK_SET);
    Triangles.reserve(Header.CountBoundingTriangles / 3);
    for (uint32 i = 0; i < Header.CountBoundingTriangles / 3; i++)
    {
        Triangle<uint16> tri;
        tri.Type = Constants::TRIANGLE_TYPE_DOODAD;
        tri.V0 = _Stream->Read<uint16>();
        tri.V1 = _Stream->Read<uint16>();
        tri.V2 = _Stream->Read<uint16>();
        Triangles.push_back(tri);
    }
}

void Model::ReadBoundingNormals()
{
    _Stream->Seek(Header.OffsetBoundingNormals, SEEK_SET);
    Normals.reserve(Header.CountBoundingNormals);
    for (uint32 i = 0; i < Header.CountBoundingNormals; i++)
        Normals.push_back(Vector3::Read(_Stream));
}

