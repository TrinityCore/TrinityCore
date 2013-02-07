#ifndef LIQUID_H
#define LIQUID_H
#include "ADT.h"
#include "Utils.h"
#include "Define.h"

#include <vector>

class LiquidHandler
{
public:
    LiquidHandler(ADT* adt);

    ADT* Source;
    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    std::vector<MCNKLiquidData> MCNKData;
private:
    void HandleNewLiquid();
};
#endif