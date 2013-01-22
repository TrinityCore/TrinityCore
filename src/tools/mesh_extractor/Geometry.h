#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <vector>

#include "Utils.h"

class ADT;
class Geometry
{
public:
    Geometry();

    void CalculateBoundingBox(float*& min, float*& max);
    void CalculateMinMaxHeight(float& min, float& max);
    void AddData(std::vector<Vector3>& verts, std::vector<Triangle<uint32> >& tris);
    void AddAdt(ADT* adt);
    void GetRawData(float*& verts, int*& tris, uint8*& areas);

    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    bool Transform;
};
#endif