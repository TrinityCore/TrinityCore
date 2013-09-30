#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "Utils.h"

class Model
{
public:
    Model(std::string path);
    ~Model();

    void ReadVertices();
    void ReadBoundingTriangles();
    void ReadBoundingNormals();
    ModelHeader Header;
    std::vector<Vector3> Vertices;
    std::vector<Vector3> Normals;
    std::vector<Triangle<uint16> > Triangles;
    bool IsCollidable;
    FILE* Stream;
    bool IsBad;
};
#endif