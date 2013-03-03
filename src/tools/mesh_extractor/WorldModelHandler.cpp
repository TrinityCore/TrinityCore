#include "WorldModelHandler.h"
#include "WorldModelRoot.h"
#include "Chunk.h"
#include "Cache.h"
#include "Model.h"
#include "Define.h"
#include "G3D/Matrix4.h"
#include <cstdio>

WorldModelDefinition WorldModelDefinition::Read( FILE* file )
{
    WorldModelDefinition ret;
    int count = 0;
    count += fread(&ret.MwidIndex, sizeof(uint32), 1, file);
    count += fread(&ret.UniqueId, sizeof(uint32), 1, file);
    ret.Position = Vector3::Read(file);
    ret.Rotation = Vector3::Read(file);
    ret.UpperExtents = Vector3::Read(file);
    ret.LowerExtents = Vector3::Read(file);
    count += fread(&ret.Flags, sizeof(uint16), 1, file);
    count += fread(&ret.DoodadSet, sizeof(uint16), 1, file);
    uint32 discard;
    count += fread(&discard, sizeof(uint32), 1, file);

    if (count != 5)
         printf("WorldModelDefinition::Read: Error reading data, expected 5, read %d\n", count);
    return ret;
}


WorldModelHandler::WorldModelHandler( ADT* adt ) : ObjectDataHandler(adt), _definitions(NULL), _paths(NULL)
{
    if (!adt->HasObjectData)
        return;
    ReadModelPaths();
    ReadDefinitions();
}

void WorldModelHandler::ProcessInternal( ChunkedData* subChunks )
{
    if (!IsSane())
        return;
    Chunk* wmoReferencesChunk = subChunks->GetChunkByName("MCRW");
    if (!wmoReferencesChunk)
        return;
    FILE* stream = wmoReferencesChunk->GetStream();
    uint32 refCount = wmoReferencesChunk->Length / 4;
    for (uint32 i = 0; i < refCount; i++)
    {
        int32 index;
        if (fread(&index, sizeof(int32), 1, stream) != 1)
            printf("WorldModelDefinition::Read: Error reading data, expected 1, read 0\n");

        if (index < 0 || uint32(index) >= _definitions->size())
            continue;

        WorldModelDefinition wmo = (*_definitions)[index];

        if (_drawn.find(wmo.UniqueId) != _drawn.end())
            continue;
        _drawn.insert(wmo.UniqueId);

        if (wmo.MwidIndex >= _paths->size())
            continue;

        std::string path = (*_paths)[wmo.MwidIndex];
        WorldModelRoot* model = Cache->WorldModelCache.Get(path);
        if (!model)
        {
            model = new WorldModelRoot(path);
            Cache->WorldModelCache.Insert(path, model);
        }

        Vertices.reserve(1000);
        Triangles.reserve(1000);

        InsertModelGeometry(Vertices, Triangles, wmo, model);
    }
}

void WorldModelHandler::InsertModelGeometry( std::vector<Vector3>& verts, std::vector<Triangle<uint32> >& tris, WorldModelDefinition& def, WorldModelRoot* root )
{
    G3D::Matrix4 transformation = Utils::GetTransformation(def);
    for (std::vector<WorldModelGroup>::iterator group =  root->Groups.begin(); group != root->Groups.end(); ++group)
    {
        uint32 vertOffset = verts.size();
        for (std::vector<Vector3>::iterator itr2 = group->Vertices.begin(); itr2 != group->Vertices.end(); ++itr2)
            verts.push_back(Utils::VectorTransform(*itr2, transformation));

        for (uint32 i = 0; i < group->Triangles.size(); ++i)
        {
            // only include collidable tris
            if ((group->TriangleFlags[i] & 0x04) != 0 && group->TriangleMaterials[i] != 0xFF)
                continue;
            Triangle<uint16> tri = group->Triangles[i];
            tris.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WMO, tri.V0 + vertOffset, tri.V1 + vertOffset, tri.V2 + vertOffset));
        }
    }

    if (def.DoodadSet < root->DoodadSets.size())
    {
        DoodadSet set = root->DoodadSets[def.DoodadSet];
        std::vector<DoodadInstance> instances;
        instances.reserve(set.CountInstances);
        for (uint32 i = set.FirstInstanceIndex; i < (set.CountInstances + set.FirstInstanceIndex); i++)
        {
            if (i >= root->DoodadInstances.size())
                break;
            instances.push_back(root->DoodadInstances[i]);
        }

        for (std::vector<DoodadInstance>::iterator instance = instances.begin(); instance != instances.end(); ++instance)
        {
            Model* model = Cache->ModelCache.Get(instance->File);
            if (!model)
            {
                model = new Model(instance->File);
                Cache->ModelCache.Insert(instance->File, model);
            }

            if (!model->IsCollidable)
                continue;
            G3D::Matrix4 doodadTransformation = Utils::GetWmoDoodadTransformation(*instance, def);
            int vertOffset = verts.size();
            for (std::vector<Vector3>::iterator itr2 = model->Vertices.begin(); itr2 != model->Vertices.end(); ++itr2)
                verts.push_back(Utils::VectorTransform(*itr2, doodadTransformation));
            for (std::vector<Triangle<uint16> >::iterator itr2 = model->Triangles.begin(); itr2 != model->Triangles.end(); ++itr2)
                tris.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WMO, itr2->V0 + vertOffset, itr2->V1 + vertOffset, itr2->V2 + vertOffset));
        }

        for (std::vector<WorldModelGroup>::iterator group =  root->Groups.begin(); group != root->Groups.end(); ++group)
        {
            if (!group->HasLiquidData)
                continue;

            for (uint32 y = 0; y < group->LiquidDataHeader.Height; y++)
            {
                for (uint32 x = 0; x < group->LiquidDataHeader.Width; x++)
                {
                    if (!group->LiquidDataGeometry.ShouldRender(x, y))
                        continue;

                    uint32 vertOffset = verts.size();
                    verts.push_back(Utils::GetLiquidVert(transformation, group->LiquidDataHeader.BaseLocation,
                        group->LiquidDataGeometry.HeightMap[x][y], x, y));
                    verts.push_back(Utils::GetLiquidVert(transformation, group->LiquidDataHeader.BaseLocation,
                        group->LiquidDataGeometry.HeightMap[x + 1][y], x + 1, y));
                    verts.push_back(Utils::GetLiquidVert(transformation, group->LiquidDataHeader.BaseLocation,
                        group->LiquidDataGeometry.HeightMap[x][y + 1], x, y + 1));
                    verts.push_back(Utils::GetLiquidVert(transformation, group->LiquidDataHeader.BaseLocation,
                        group->LiquidDataGeometry.HeightMap[x + 1][y + 1], x + 1, y + 1));

                    tris.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WATER, vertOffset, vertOffset + 2, vertOffset + 1));
                    tris.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WATER, vertOffset + 2, vertOffset + 3, vertOffset + 1));

                }
            }
        }
    }
}

void WorldModelHandler::ReadDefinitions()
{
    Chunk* chunk = Source->ObjectData->GetChunkByName("MODF");
    if (!chunk)
        return;

    const int32 definitionSize = 64;
    uint32 definitionCount = chunk->Length / definitionSize;
    _definitions = new std::vector<WorldModelDefinition>;
    _definitions->reserve(definitionCount);
    FILE* stream = chunk->GetStream();
    for (uint32 i = 0; i < definitionCount; i++)
        _definitions->push_back(WorldModelDefinition::Read(stream));
}

void WorldModelHandler::ReadModelPaths()
{
    Chunk* mwid = Source->ObjectData->GetChunkByName("MWID");
    Chunk* mwmo = Source->ObjectData->GetChunkByName("MWMO");
    if (!mwid || !mwmo)
        return;

    uint32 paths = mwid->Length / 4;
    _paths = new std::vector<std::string>;
    _paths->reserve(paths);
    for (uint32 i = 0; i < paths; i++)
    {
        FILE* stream = mwid->GetStream();
        fseek(stream, i * 4, SEEK_CUR);
        uint32 offset;
        if (fread(&offset, sizeof(uint32), 1, stream) != 1)
            printf("WorldModelDefinition::Read: Error reading data, expected 1, read 0\n");
        FILE* dataStream = mwmo->GetStream();
        fseek(dataStream, offset + mwmo->Offset, SEEK_SET);
        _paths->push_back(Utils::ReadString(dataStream));
    }
}

WorldModelHandler::~WorldModelHandler()
{
    delete _definitions;
    delete _paths;
}
