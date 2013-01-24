#ifndef DOOADHNDL_H
#define DOOADHNDL_H
#include "ObjectDataHandler.h"
#include "Utils.h"
#include "Chunk.h"
#include "Model.h"
#include <set>
#include <vector>

class DoodadDefinition : public IDefinition
{
public:
    uint32 MmidIndex;
    uint32 UniqueId;
    uint16 DecimalScale;
    uint16 Flags;

    virtual float Scale() const { return DecimalScale / 1024.0f; }

    void Read(FILE* stream)
    {
        int count = 0;

        count += fread(&MmidIndex, sizeof(uint32), 1, stream);
        count += fread(&UniqueId, sizeof(uint32), 1, stream);
        Position = Vector3::Read(stream);
        Rotation = Vector3::Read(stream);
        count += fread(&DecimalScale, sizeof(uint16), 1, stream);
        count += fread(&Flags, sizeof(uint16), 1, stream);
        if (count != 4)
            printf("DoodadDefinition::Read: Failed to read some data expected 4, read %d\n", count);
    }
};

class DoodadHandler : public ObjectDataHandler
{
public:
    DoodadHandler(ADT* adt);
    ~DoodadHandler();

    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    bool IsSane() { return _definitions && _paths; }


protected:
    void ProcessInternal(ChunkedData* chunk);

private:
    void ReadDoodadDefinitions(Chunk* chunk);
    void ReadDoodadPaths(Chunk* id, Chunk* data);
    void InsertModelGeometry(const DoodadDefinition& def, Model* model);
    std::set<uint32> _drawn;
    std::vector<DoodadDefinition>* _definitions;
    std::vector<std::string>* _paths;
};
#endif
