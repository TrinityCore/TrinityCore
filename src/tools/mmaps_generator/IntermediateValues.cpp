/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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
        char fileName[255];
        char tileString[25];
        sprintf(tileString, "[%02u,%02u]: ", tileX, tileY);

        printf("%sWriting debug output...                       \r", tileString);

        std::string name("meshes/%03u%02i%02i.");

#define DEBUG_WRITE(fileExtension,data) \
    do { \
    sprintf(fileName, (name + fileExtension).c_str(), mapID, tileY, tileX); \
    FILE* file = fopen(fileName, "wb"); \
    if (!file) \
        { \
        char message[1024]; \
        sprintf(message, "%sFailed to open %s for writing!\n",  tileString, fileName); \
        perror(message); \
        } \
            else \
            debugWrite(file, data); \
            if (file) fclose(file); \
            printf("%sWriting debug output...                       \r", tileString); \
    } while (false)

        if (heightfield)
            DEBUG_WRITE("hf", heightfield);
        if (compactHeightfield)
            DEBUG_WRITE("chf", compactHeightfield);
        if (contours)
            DEBUG_WRITE("cs", contours);
        if (polyMesh)
            DEBUG_WRITE("pmesh", polyMesh);
        if (polyMeshDetail)
            DEBUG_WRITE("dmesh", polyMeshDetail);

#undef DEBUG_WRITE
    }

    void IntermediateValues::debugWrite(FILE* file, const rcHeightfield* mesh)
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

    void IntermediateValues::debugWrite(FILE* file, const rcCompactHeightfield* chf)
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

    void IntermediateValues::debugWrite(FILE* file, const rcContourSet* cs)
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

    void IntermediateValues::debugWrite(FILE* file, const rcPolyMesh* mesh)
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

    void IntermediateValues::debugWrite(FILE* file, const rcPolyMeshDetail* mesh)
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

    void IntermediateValues::generateObjFile(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData)
    {
        char objFileName[255];
        sprintf(objFileName, "meshes/map%03u%02u%02u.obj", mapID, tileY, tileX);

        FILE* objFile = fopen(objFileName, "wb");
        if (!objFile)
        {
            char message[1024];
            sprintf(message, "Failed to open %s for writing!\n", objFileName);
            perror(message);
            return;
        }

        G3D::Array<float> allVerts;
        G3D::Array<int> allTris;

        allTris.append(meshData.liquidTris);
        allVerts.append(meshData.liquidVerts);
        TerrainBuilder::copyIndices(meshData.solidTris, allTris, allVerts.size() / 3);
        allVerts.append(meshData.solidVerts);

        float* verts = allVerts.getCArray();
        int vertCount = allVerts.size() / 3;
        int* tris = allTris.getCArray();
        int triCount = allTris.size() / 3;

        for (int i = 0; i < allVerts.size() / 3; i++)
            fprintf(objFile, "v %f %f %f\n", verts[i*3], verts[i*3 + 1], verts[i*3 + 2]);

        for (int i = 0; i < allTris.size() / 3; i++)
            fprintf(objFile, "f %i %i %i\n", tris[i*3] + 1, tris[i*3 + 1] + 1, tris[i*3 + 2] + 1);

        fclose(objFile);


        char tileString[25];
        sprintf(tileString, "[%02u,%02u]: ", tileY, tileX);
        printf("%sWriting debug output...                       \r", tileString);

        sprintf(objFileName, "meshes/%03u.map", mapID);

        objFile = fopen(objFileName, "wb");
        if (!objFile)
        {
            char message[1024];
            sprintf(message, "Failed to open %s for writing!\n", objFileName);
            perror(message);
            return;
        }

        char b = '\0';
        fwrite(&b, sizeof(char), 1, objFile);
        fclose(objFile);

        sprintf(objFileName, "meshes/%03u%02u%02u.mesh", mapID, tileY, tileX);
        objFile = fopen(objFileName, "wb");
        if (!objFile)
        {
            char message[1024];
            sprintf(message, "Failed to open %s for writing!\n", objFileName);
            perror(message);
            return;
        }

        fwrite(&vertCount, sizeof(int), 1, objFile);
        fwrite(verts, sizeof(float), vertCount*3, objFile);
        fflush(objFile);

        fwrite(&triCount, sizeof(int), 1, objFile);
        fwrite(tris, sizeof(int), triCount*3, objFile);
        fflush(objFile);

        fclose(objFile);
    }
}
