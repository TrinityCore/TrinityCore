/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "IntermediateValues.h"
#include "Log.h"
#include "Memory.h"
#include "StringFormat.h"

namespace MMAP
{
    IntermediateValues::~IntermediateValues()
    {
        rcFreeCompactHeightfield(compactHeightfield);
        rcFreeHeightField(heightfield);
        rcFreeContourSet(contours);
        rcFreePolyMesh(polyMesh);
        rcFreePolyMeshDetail(polyMeshDetail);
    }

    void IntermediateValues::writeIV(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        TC_LOG_INFO("maps.mmapgen.debug", "[Map {:04}] [{:02},{:02}]: Writing debug output intermediate values...", mapID, tileX, tileY);

        auto debugWrite = [&](char const* extension, auto const* data)
        {
            std::string fileName = Trinity::StringFormat("meshes/{:04}{:02}{:02}.{}", mapID, tileX, tileY, extension);
            if (auto file = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(fileName.c_str(), "wb")))
            {
                this->debugWrite(file.get(), data);
            }
            else
                TC_LOG_ERROR("maps.mmapgen.debug", "{}: [{:04}-{:02},{:02}] Failed to open {} for writing!", strerror(errno), mapID, tileX, tileY, fileName);
        };

        if (heightfield)
            debugWrite("hf", heightfield);
        if (compactHeightfield)
            debugWrite("chf", compactHeightfield);
        if (contours)
            debugWrite("cs", contours);
        if (polyMesh)
            debugWrite("pmesh", polyMesh);
        if (polyMeshDetail)
            debugWrite("dmesh", polyMeshDetail);
    }

    void IntermediateValues::debugWrite(FILE* file, rcHeightfield const* mesh)
    {
        if (!file || !mesh)
            return;

        fwrite(&(mesh->cs), sizeof(float), 1, file);
        fwrite(&(mesh->ch), sizeof(float), 1, file);
        fwrite(&(mesh->width), sizeof(int), 1, file);
        fwrite(&(mesh->height), sizeof(int), 1, file);
        fwrite(mesh->bmin, sizeof(float), 3, file);
        fwrite(mesh->bmax, sizeof(float), 3, file);

        for (int y = 0; y < mesh->height; ++y)
            for (int x = 0; x < mesh->width; ++x)
            {
                rcSpan* span = mesh->spans[x+y*mesh->width];

                // first, count the number of spans
                int spanCount = 0;
                while (span)
                {
                    spanCount++;
                    span = span->next;
                }

                // write the span count
                fwrite(&spanCount, sizeof(int), 1, file);

                // write the spans
                span = mesh->spans[x+y*mesh->width];
                while (span)
                {
                    fwrite(span, sizeof(rcSpan), 1, file);
                    span = span->next;
                }
            }
    }

    void IntermediateValues::debugWrite(FILE* file, rcCompactHeightfield const* chf)
    {
        if (!file | !chf)
            return;

        fwrite(&(chf->width), sizeof(chf->width), 1, file);
        fwrite(&(chf->height), sizeof(chf->height), 1, file);
        fwrite(&(chf->spanCount), sizeof(chf->spanCount), 1, file);

        fwrite(&(chf->walkableHeight), sizeof(chf->walkableHeight), 1, file);
        fwrite(&(chf->walkableClimb), sizeof(chf->walkableClimb), 1, file);

        fwrite(&(chf->maxDistance), sizeof(chf->maxDistance), 1, file);
        fwrite(&(chf->maxRegions), sizeof(chf->maxRegions), 1, file);

        fwrite(chf->bmin, sizeof(chf->bmin), 1, file);
        fwrite(chf->bmax, sizeof(chf->bmax), 1, file);

        fwrite(&(chf->cs), sizeof(chf->cs), 1, file);
        fwrite(&(chf->ch), sizeof(chf->ch), 1, file);

        int tmp = 0;
        if (chf->cells) tmp |= 1;
        if (chf->spans) tmp |= 2;
        if (chf->dist) tmp |= 4;
        if (chf->areas) tmp |= 8;

        fwrite(&tmp, sizeof(tmp), 1, file);

        if (chf->cells)
            fwrite(chf->cells, sizeof(rcCompactCell), chf->width*chf->height, file);
        if (chf->spans)
            fwrite(chf->spans, sizeof(rcCompactSpan), chf->spanCount, file);
        if (chf->dist)
            fwrite(chf->dist, sizeof(unsigned short), chf->spanCount, file);
        if (chf->areas)
            fwrite(chf->areas, sizeof(unsigned char), chf->spanCount, file);
    }

    void IntermediateValues::debugWrite(FILE* file, rcContourSet const* cs)
    {
        if (!file || !cs)
            return;

        fwrite(&(cs->cs), sizeof(float), 1, file);
        fwrite(&(cs->ch), sizeof(float), 1, file);
        fwrite(cs->bmin, sizeof(float), 3, file);
        fwrite(cs->bmax, sizeof(float), 3, file);
        fwrite(&(cs->nconts), sizeof(int), 1, file);
        for (int i = 0; i < cs->nconts; ++i)
        {
            fwrite(&cs->conts[i].area, sizeof(unsigned char), 1, file);
            fwrite(&cs->conts[i].reg, sizeof(unsigned short), 1, file);
            fwrite(&cs->conts[i].nverts, sizeof(int), 1, file);
            fwrite(cs->conts[i].verts, sizeof(int), cs->conts[i].nverts*4, file);
            fwrite(&cs->conts[i].nrverts, sizeof(int), 1, file);
            fwrite(cs->conts[i].rverts, sizeof(int), cs->conts[i].nrverts*4, file);
        }
    }

    void IntermediateValues::debugWrite(FILE* file, rcPolyMesh const* mesh)
    {
        if (!file || !mesh)
            return;

        fwrite(&(mesh->cs), sizeof(float), 1, file);
        fwrite(&(mesh->ch), sizeof(float), 1, file);
        fwrite(&(mesh->nvp), sizeof(int), 1, file);
        fwrite(mesh->bmin, sizeof(float), 3, file);
        fwrite(mesh->bmax, sizeof(float), 3, file);
        fwrite(&(mesh->nverts), sizeof(int), 1, file);
        fwrite(mesh->verts, sizeof(unsigned short), mesh->nverts*3, file);
        fwrite(&(mesh->npolys), sizeof(int), 1, file);
        fwrite(mesh->polys, sizeof(unsigned short), mesh->npolys*mesh->nvp*2, file);
        fwrite(mesh->flags, sizeof(unsigned short), mesh->npolys, file);
        fwrite(mesh->areas, sizeof(unsigned char), mesh->npolys, file);
        fwrite(mesh->regs, sizeof(unsigned short), mesh->npolys, file);
    }

    void IntermediateValues::debugWrite(FILE* file, rcPolyMeshDetail const* mesh)
    {
        if (!file || !mesh)
            return;

        fwrite(&(mesh->nverts), sizeof(int), 1, file);
        fwrite(mesh->verts, sizeof(float), mesh->nverts*3, file);
        fwrite(&(mesh->ntris), sizeof(int), 1, file);
        fwrite(mesh->tris, sizeof(char), mesh->ntris*4, file);
        fwrite(&(mesh->nmeshes), sizeof(int), 1, file);
        fwrite(mesh->meshes, sizeof(int), mesh->nmeshes*4, file);
    }

    void IntermediateValues::generateObjFile(uint32 mapID, uint32 tileX, uint32 tileY, MeshData const& meshData)
    {
        std::string objFileName;
        objFileName = Trinity::StringFormat("meshes/map{:04}{:02}{:02}.obj", mapID, tileX, tileY);

        auto objFile = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(objFileName.c_str(), "wb"));
        if (!objFile)
        {
            TC_LOG_ERROR("maps.mmapgen.debug", "{}: Failed to open {} for writing!", strerror(errno), objFileName);
            return;
        }

        std::vector<float> allVerts;
        std::vector<int> allTris;

        allTris.insert(allTris.end(), meshData.liquidTris.begin(), meshData.liquidTris.end());
        allVerts.insert(allVerts.end(), meshData.liquidVerts.begin(), meshData.liquidVerts.end());
        TerrainBuilder::copyIndices(meshData.solidTris, allTris, allVerts.size() / 3);
        allVerts.insert(allVerts.end(), meshData.solidVerts.begin(), meshData.solidVerts.end());

        float* verts = allVerts.data();
        int vertCount = allVerts.size() / 3;
        int* tris = allTris.data();
        int triCount = allTris.size() / 3;

        for (std::size_t i = 0; i < allVerts.size() / 3; i++)
            fprintf(objFile.get(), "v %f %f %f\n", verts[i * 3], verts[i * 3 + 1], verts[i * 3 + 2]);

        for (std::size_t i = 0; i < allTris.size() / 3; i++)
            fprintf(objFile.get(), "f %i %i %i\n", tris[i * 3] + 1, tris[i * 3 + 1] + 1, tris[i * 3 + 2] + 1);

        TC_LOG_INFO("maps.mmapgen.debug", "[Map {:04}] [{:02},{:02}]: Writing debug output object file...", mapID, tileX, tileY);

        objFileName = Trinity::StringFormat("meshes/map{:04}.map", mapID);

        objFile.reset(fopen(objFileName.c_str(), "wb"));
        if (!objFile)
        {
            TC_LOG_ERROR("maps.mmapgen.debug", "{}: Failed to open {} for writing!", strerror(errno), objFileName);
            return;
        }

        char b = '\0';
        fwrite(&b, sizeof(char), 1, objFile.get());

        objFileName = Trinity::StringFormat("meshes/map{:04}{:02}{:02}.mesh", mapID, tileX, tileY);
        objFile.reset(fopen(objFileName.c_str(), "wb"));
        if (!objFile)
        {
            TC_LOG_ERROR("maps.mmapgen.debug", "{}: Failed to open {} for writing!", strerror(errno), objFileName);
            return;
        }

        fwrite(&vertCount, sizeof(int), 1, objFile.get());
        fwrite(verts, sizeof(float), vertCount*3, objFile.get());
        fflush(objFile.get());

        fwrite(&triCount, sizeof(int), 1, objFile.get());
        fwrite(tris, sizeof(int), triCount*3, objFile.get());
        fflush(objFile.get());
    }
}
