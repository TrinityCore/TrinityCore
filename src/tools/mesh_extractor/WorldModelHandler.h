#ifndef WMODEL_HNDL_H
#define WMODEL_HNDL_H
#include "Define.h"
#include "Utils.h"
#include "WorldModelRoot.h"
#include "ObjectDataHandler.h"

#include <set>
#include <vector>

class ADT;

struct WorldModelDefinition : public IDefinition
{
public:
    WorldModelDefinition() {}

    uint32 MwidIndex;
    uint32 UniqueId;
    Vector3 UpperExtents;
    Vector3 LowerExtents;
    uint16 Flags;
    uint16 DoodadSet;

    static WorldModelDefinition Read(FILE* file);
};

class WorldModelHandler : public ObjectDataHandler
{
public:
    WorldModelHandler(ADT* adt);
    ~WorldModelHandler();

    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    bool IsSane() { return _definitions && _paths; }
    void InsertModelGeometry(std::vector<Vector3>& verts, std::vector<Triangle<uint32> >& tris, WorldModelDefinition& def, WorldModelRoot* root);
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