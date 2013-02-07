#ifndef WMOGROUP_H
#define WMOGROUP_H
#include "ChunkedData.h"
#include "Utils.h"

class WorldModelGroup
{
public:
    WorldModelGroup(std::string path, int groupIndex);
    ChunkedData* Data;
    ChunkedData* SubData;
    int GroupIndex;
    std::string Name;
    WMOGroupHeader Header;

    std::vector<uint8> TriangleFlags;
    std::vector<uint8> TriangleMaterials;
    std::vector<Triangle<uint16> > Triangles;
    std::vector<Vector3> Vertices;
    std::vector<Vector3> Normals;
    // @ToDo: Research.
    uint16* MOBA;
    uint32 MOBALength;

    bool HasLiquidData;
    bool IsBad;
    LiquidHeader LiquidDataHeader;
    LiquidData LiquidDataGeometry;
private:
    void ReadNormals();
    void ReadLiquid();
    void ReadVertices();
    void ReadTriangles();
    void ReadMaterials();
    void ReadHeader();
    void ReadBatches();
};
#endif