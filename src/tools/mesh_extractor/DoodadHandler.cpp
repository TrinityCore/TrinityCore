#include "DoodadHandler.h"
#include "Chunk.h"
#include "Cache.h"
#include "Model.h"
#include "G3D/Matrix4.h"

DoodadHandler::DoodadHandler( ADT* adt ) : 
    ObjectDataHandler(adt), _definitions(NULL), _paths(NULL)
{
    Chunk* mddf = adt->ObjectData->GetChunkByName("MDDF");
    if (mddf)
        ReadDoodadDefinitions(mddf);

    Chunk* mmid = adt->ObjectData->GetChunkByName("MMID");
    Chunk* mmdx = adt->ObjectData->GetChunkByName("MMDX");
    if (mmid && mmdx)
        ReadDoodadPaths(mmid, mmdx);
}

void DoodadHandler::ProcessInternal( MapChunk* mcnk )
{
    if (!IsSane())
        return;
    
    uint32 refCount = mcnk->Header.DoodadRefs;
    FILE* stream = mcnk->Source->GetStream();
    fseek(stream, mcnk->Source->Offset + mcnk->Header.OffsetMCRF, SEEK_SET);
    for (uint32 i = 0; i < refCount; i++)
    {
        int32 index;
        int32 count;
        if ((count = fread(&index, sizeof(int32), 1, stream)) != 1)
            printf("DoodadHandler::ProcessInternal: Failed to read some data expected 1, read %d\n", count);
        if (index < 0 || uint32(index) >= _definitions->size())
            continue;
        DoodadDefinition doodad = (*_definitions)[index];
        if (_drawn.find(doodad.UniqueId) != _drawn.end())
            continue;
        _drawn.insert(doodad.UniqueId);
        if (doodad.MmidIndex >= _paths->size())
            continue;

        std::string path = (*_paths)[doodad.MmidIndex];
        Model* model = Cache->ModelCache.Get(path);
        if (!model)
        {
            model = new Model(path);
            Cache->ModelCache.Insert(path, model);
        }
        if (!model->IsCollidable)
            continue;

        Vertices.reserve(refCount * model->Vertices.size() * 0.2);
        Triangles.reserve(refCount * model->Triangles.size() * 0.2);

        InsertModelGeometry(doodad, model);
    }
    // Restore the stream position
    fseek(stream, mcnk->Source->Offset, SEEK_SET);
}

void DoodadHandler::ReadDoodadDefinitions( Chunk* chunk )
{
    int32 count = chunk->Length / 36;
    _definitions = new std::vector<DoodadDefinition>;
    _definitions->reserve(count);
    FILE* stream = chunk->GetStream();
    for (int i = 0; i < count; i++)
    {
        DoodadDefinition def;
        def.Read(stream);
        _definitions->push_back(def);
    }
}

void DoodadHandler::ReadDoodadPaths( Chunk* id, Chunk* data )
{
    int paths = id->Length / 4;
    _paths = new std::vector<std::string>();
    _paths->reserve(paths);
    for (int i = 0; i < paths; i++)
    {
        FILE* idStream = id->GetStream();
        fseek(idStream, i * 4, SEEK_CUR);
        uint32 offset;
        if (fread(&offset, sizeof(uint32), 1, idStream) != 1)
            printf("DoodadHandler::ReadDoodadPaths: Failed to read some data expected 1, read 0\n");
        FILE* dataStream = data->GetStream();
        fseek(dataStream, offset + data->Offset, SEEK_SET);
        _paths->push_back(Utils::ReadString(dataStream));
    }
}

void DoodadHandler::InsertModelGeometry(const DoodadDefinition& def, Model* model)
{
    uint32 vertOffset = Vertices.size();
    
    for (std::vector<Vector3>::iterator itr = model->Vertices.begin(); itr != model->Vertices.end(); ++itr)
        Vertices.push_back(Utils::TransformDoodadVertex(def, *itr)); // Vertices have to be converted based on the information from the DoodadDefinition struct

    for (std::vector<Triangle<uint16> >::iterator itr = model->Triangles.begin(); itr != model->Triangles.end(); ++itr)
        Triangles.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_DOODAD, itr->V0 + vertOffset, itr->V1 + vertOffset, itr->V2 + vertOffset));
}

DoodadHandler::~DoodadHandler()
{
    delete _definitions;
    delete _paths;
}
