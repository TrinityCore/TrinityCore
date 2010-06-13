#include "vmapexport.h"
#include "model.h"
#include "wmo.h"
#include "mpq_libmpq04.h"
#include <cassert>
#include <algorithm>
#include <cstdio>

Model::Model(std::string &filename) : filename(filename)
{
}

bool Model::open()
{
    MPQFile f(filename.c_str());

    ok = !f.isEof();

    if (!ok)
    {
        f.close();
        printf("Error loading model %s\n", filename.c_str());
        return false;
    }

    memcpy(&header, f.getBuffer(), sizeof(ModelHeader));
    if(header.nBoundingTriangles > 0)
    {
        f.seek(0);
        f.seekRelative(header.ofsBoundingVertices);
        vertices = new Vec3D[header.nBoundingVertices];
        f.read(vertices,header.nBoundingVertices*12);
        for (uint32 i=0; i<header.nBoundingVertices; i++)
        {
            vertices[i] = fixCoordSystem(vertices[i]);
        }
        f.seek(0);
        f.seekRelative(header.ofsBoundingTriangles);
        indices = new uint16[header.nBoundingTriangles];
        f.read(indices,header.nBoundingTriangles*2);
        f.close();
    }
    else
    {
        //printf("not included %s\n", filename.c_str());
        f.close();
        return false;
    }
    return true;
}

bool Model::ConvertToVMAPModel(char * outfilename)
{
    int N[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    FILE * output=fopen(outfilename,"wb");
    if(!output)
    {
        printf("Can't create the output file '%s'\n",outfilename);
        return false;
    }
    fwrite("VMAP003",8,1,output);
    uint32 nVertices = 0;
    nVertices = header.nBoundingVertices;
    fwrite(&nVertices, sizeof(int), 1, output);
    uint32 nofgroups = 1;
    fwrite(&nofgroups,sizeof(uint32), 1, output);
    fwrite(N,4*3,1,output);// rootwmoid, flags, groupid
    fwrite(N,sizeof(float),3*2,output);//bbox, only needed for WMO currently
    fwrite(N,4,1,output);// liquidflags
    fwrite("GRP ",4,1,output);
    uint32 branches = 1;
    int wsize;
    wsize = sizeof(branches) + sizeof(uint32) * branches;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&branches,sizeof(branches), 1, output);
    uint32 nIndexes = 0;
    nIndexes = header.nBoundingTriangles;
    fwrite(&nIndexes,sizeof(uint32), 1, output);
    fwrite("INDX",4, 1, output);
    wsize = sizeof(uint32) + sizeof(unsigned short) * nIndexes;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nIndexes, sizeof(uint32), 1, output);
    if(nIndexes >0)
    {
        fwrite(indices, sizeof(unsigned short), nIndexes, output);
    }
    fwrite("VERT",4, 1, output);
    wsize = sizeof(int) + sizeof(float) * 3 * nVertices;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nVertices, sizeof(int), 1, output);
    if(nVertices >0)
    {
        for(uint32 vpos=0; vpos <nVertices; ++vpos)
        {
            float sy = vertices[vpos].y;
            vertices[vpos].y = vertices[vpos].z;
            vertices[vpos].z = sy;
        }
        fwrite(vertices, sizeof(float)*3, nVertices, output);
    }

    delete[] vertices;
    delete[] indices;

    fclose(output);

    return true;
}

Model::~Model()
{
}

Vec3D fixCoordSystem(Vec3D v)
{
    return Vec3D(v.x, v.z, -v.y);
}

Vec3D fixCoordSystem2(Vec3D v)
{
    return Vec3D(v.x, v.z, v.y);
}

ModelInstance::ModelInstance(MPQFile &f,const char* ModelInstName, uint32 mapID, uint32 tileX, uint32 tileY, FILE *pDirfile)
{
    float ff[3];
    f.read(&id, 4);
    f.read(ff,12);
    pos = fixCoords(Vec3D(ff[0],ff[1],ff[2]));
    f.read(ff,12);
    rot = Vec3D(ff[0],ff[1],ff[2]);
    f.read(&scale,4);
    // scale factor - divide by 1024. blizzard devs must be on crack, why not just use a float?
    sc = scale / 1024.0f;

    char tempname[512];
    sprintf(tempname, "%s/%s", szWorkDirWmo, ModelInstName);
    FILE *input;
    input = fopen(tempname, "r+b");

    if(!input)
    {
        //printf("ModelInstance::ModelInstance couldn't open %s\n", tempname);
        return;
    }

    fseek(input, 8, SEEK_SET); // get the correct no of vertices
    int nVertices;
    fread(&nVertices, sizeof (int), 1, input);
    fclose(input);

    if(nVertices == 0)
        return;

    uint16 adtId = 0;// not used for models
    uint32 flags = MOD_M2;
	if(tileX == 65 && tileY == 65) flags |= MOD_WORLDSPAWN;
    //write mapID, tileX, tileY, Flags, ID, Pos, Rot, Scale, name
    fwrite(&mapID, sizeof(uint32), 1, pDirfile);
    fwrite(&tileX, sizeof(uint32), 1, pDirfile);
    fwrite(&tileY, sizeof(uint32), 1, pDirfile);
    fwrite(&flags, sizeof(uint32), 1, pDirfile);
    fwrite(&adtId, sizeof(uint16), 1, pDirfile);
    fwrite(&id, sizeof(uint32), 1, pDirfile);
    fwrite(&pos, sizeof(float), 3, pDirfile);
    fwrite(&rot, sizeof(float), 3, pDirfile);
    fwrite(&sc, sizeof(float), 1, pDirfile);
    uint32 nlen=strlen(ModelInstName);
    fwrite(&nlen, sizeof(uint32), 1, pDirfile);
    fwrite(ModelInstName, sizeof(char), nlen, pDirfile);

    /* int realx1 = (int) ((float) pos.x / 533.333333f);
    int realy1 = (int) ((float) pos.z / 533.333333f);
    int realx2 = (int) ((float) pos.x / 533.333333f);
    int realy2 = (int) ((float) pos.z / 533.333333f);

    fprintf(pDirfile,"%s/%s %f,%f,%f_%f,%f,%f %f %d %d %d,%d %d\n",
        MapName,
        ModelInstName,
        (float) pos.x, (float) pos.y, (float) pos.z,
        (float) rot.x, (float) rot.y, (float) rot.z,
        sc,
        nVertices,
        realx1, realy1,
        realx2, realy2
        ); */
}
