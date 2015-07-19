/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "WorldModelHandler.h"
#include "WorldModelRoot.h"
#include "Chunk.h"
#include "Cache.h"
#include "Model.h"
#include "Define.h"
#include "G3D/Matrix4.h"
#include "G3D/Quat.h"
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
    ReadModelPaths();
    ReadDefinitions();
}

void WorldModelHandler::ProcessInternal( MapChunk* mcnk )
{
    if (!IsSane())
        return;

    uint32 refCount = mcnk->Header.MapObjectRefs;
    FILE* stream = mcnk->Source->GetStream();
    fseek(stream, mcnk->Source->Offset + mcnk->Header.OffsetMCRF, SEEK_SET);
    // Start looping at the last Doodad Ref index
    for (uint32 i = mcnk->Header.DoodadRefs; i < refCount; i++)
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
    // Restore the stream position
    fseek(stream, mcnk->Source->Offset, SEEK_SET);
}

void WorldModelHandler::InsertModelGeometry( std::vector<Vector3>& verts, std::vector<Triangle<uint32> >& tris, const WorldModelDefinition& def, WorldModelRoot* root, bool translate )
{
    for (std::vector<WorldModelGroup>::iterator group =  root->Groups.begin(); group != root->Groups.end(); ++group)
    {
        uint32 vertOffset = verts.size();
        for (std::vector<Vector3>::iterator itr2 = group->Vertices.begin(); itr2 != group->Vertices.end(); ++itr2)
        {
            Vector3 v = Utils::TransformDoodadVertex(def, *itr2, translate);
            // If translate is false, then we were called directly from the TileBuilder to add data to it's _Geometry member, hence, we have to manually convert the vertices to Recast format.
            verts.push_back(translate ? v : Utils::ToRecast(v)); // Transform the vertex to world space
        }

        for (uint32 i = 0; i < group->Triangles.size(); ++i)
        {
            // only include colliding tris
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
            int vertOffset = verts.size();
            for (std::vector<Vector3>::iterator itr2 = model->Vertices.begin(); itr2 != model->Vertices.end(); ++itr2)
            {
                Vector3 v = Utils::TransformDoodadVertex(def, Utils::TransformWmoDoodad(*instance, def, *itr2, false), translate);
                verts.push_back(translate ? v : Utils::ToRecast(v));
            }
            for (std::vector<Triangle<uint16> >::iterator itr2 = model->Triangles.begin(); itr2 != model->Triangles.end(); ++itr2)
                tris.push_back(Triangle<uint32>(Constants::TRIANGLE_TYPE_WMO, itr2->V0 + vertOffset, itr2->V1 + vertOffset, itr2->V2 + vertOffset));
        }

        for (std::vector<WorldModelGroup>::iterator group =  root->Groups.begin(); group != root->Groups.end(); ++group)
        {
            if (!group->HasLiquidData)
                continue;

            const LiquidHeader& liquidHeader = group->LiquidDataHeader;
            LiquidData& liquidDataGeometry = group->LiquidDataGeometry;

            for (uint32 y = 0; y < liquidHeader.Height; y++)
            {
                for (uint32 x = 0; x < liquidHeader.Width; x++)
                {

                    if (!liquidDataGeometry.ShouldRender(x, y))
                        continue;

                    uint32 vertOffset = verts.size();

                    Vector3 v1 = Utils::GetLiquidVert(def, liquidHeader.BaseLocation,
                        liquidDataGeometry.HeightMap[x][y], x, y, translate);
                    Vector3 v2 = Utils::GetLiquidVert(def, liquidHeader.BaseLocation,
                        liquidDataGeometry.HeightMap[x + 1][y], x + 1, y, translate);
                    Vector3 v3 = Utils::GetLiquidVert(def, liquidHeader.BaseLocation,
                        liquidDataGeometry.HeightMap[x][y + 1], x, y + 1, translate);
                    Vector3 v4 = Utils::GetLiquidVert(def, liquidHeader.BaseLocation,
                        liquidDataGeometry.HeightMap[x + 1][y + 1], x + 1, y + 1, translate);

                    verts.push_back(translate ? v1 : Utils::ToRecast(v1));
                    verts.push_back(translate ? v2 : Utils::ToRecast(v2));
                    verts.push_back(translate ? v3 : Utils::ToRecast(v3));
                    verts.push_back(translate ? v4 : Utils::ToRecast(v4));

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
