#ifndef WMODEL_HNDL_H
#define WMODEL_HNDL_H
#include "Common.h"
#include "Utils.h"
#include "ObjectDataHandler.h"
#include "ADT.h"

#include <set>
#include <vector>

struct WorldModelDefinition : IDefinition
{
public:
    WorldModelDefinition() {}

    uint32 MwidIndex;
    uint32 UniqueId;
    Vector3 UpperExtents;
    Vector3 LowerExtents;
    uint16 Flags;
    uint16 DoodadSet;

    virtual float Scale() const { return 1.0f; }

    static WorldModelDefinition Read(FILE* file);
};

class WorldModelHandler : public ObjectDataHandler
{
public:
    WorldModelHandler(ADT* adt);

    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    bool IsSane() { return _definitions && _paths; }
    void InsertModelGeometry(std::vector<Vector3> verts, std::vector<Triangle<uint32> > tris, WorldModelDefinition& def, WorldModelRoot* root);
protected:
    void ProcessInternal(ChunkedData* data);
private:
    void ReadDefinitions();
    void ReadModelPaths();
    std::set<uint32> _drawn;
    std::vector<WorldModelDefinition>* _definitions;
    std::vector<std::string>* _paths;
};
#endif