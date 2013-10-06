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

    static WorldModelDefinition Read(Stream* file);
};

class WorldModelHandler : public ObjectDataHandler
{
public:
    WorldModelHandler(ADT* adt);
    ~WorldModelHandler();

    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    bool IsSane() { return _definitions && _paths; }
    static void InsertModelGeometry(std::vector<Vector3>& verts, std::vector<Triangle<uint32> >& tris, const WorldModelDefinition& def, WorldModelRoot* root, bool translate = true);
protected:
    void ProcessInternal(MapChunk* data);
private:
    void ReadDefinitions();
    void ReadModelPaths();
    std::set<uint32> _drawn;
    std::vector<WorldModelDefinition>* _definitions;
    std::vector<std::string>* _paths;
};
#endif