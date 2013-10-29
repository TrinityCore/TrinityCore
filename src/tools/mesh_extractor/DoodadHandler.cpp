/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

void DoodadHandler::ProcessInternal(MapChunk* mcnk)
{
    if (!IsSane())
        return;
    
    uint32 refCount = mcnk->Header.DoodadRefs;
    Stream* stream = mcnk->Source->GetStream();
    stream->Seek(mcnk->Source->Offset + mcnk->Header.OffsetMCRF, SEEK_SET);

    for (uint32 i = 0; i < refCount; i++)
    {
        int32 index = stream->Read<int32>();
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
        if (!model->IsCollidable)
            continue;

        Vertices.reserve(refCount * model->Vertices.size() * 0.2);
        Triangles.reserve(refCount * model->Triangles.size() * 0.2);

        InsertModelGeometry(doodad, model);
    }
    // Restore the stream position
    stream->Seek(mcnk->Source->Offset, SEEK_SET);
}

void DoodadHandler::ReadDoodadDefinitions( Chunk* chunk )
{
    int32 count = chunk->Length / 36;
    _definitions = new std::vector<DoodadDefinition>;
    _definitions->reserve(count);
    Stream* stream = chunk->GetStream();
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
        Stream* idStream = id->GetStream();
        idStream->Seek(i * 4, SEEK_CUR);
        uint32 offset = idStream->Read<uint32>();

        Stream* dataStream = data->GetStream();
        dataStream->Seek(offset + data->Offset, SEEK_SET);
        _paths->push_back(dataStream->ReadString());
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
