//#include "common.h"
#include "model.h"
//#include "world.h"
#include <cassert>
#include <algorithm>

//int globalTime = 0;

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
    if(header.nBoundingTriangles > 0) {

#if 0
        animated = isAnimated(f);
        if(animated)
        {
            f.close();
            return false;
        }
#endif
        trans = 1.0f;
        origVertices = (ModelVertex*)(f.getBuffer() + header.ofsVertices);

        vertices = new Vec3D[header.nVertices];
        normals = new Vec3D[header.nVertices];

        for (size_t i=0; i<header.nVertices; i++)
        {
            origVertices[i].pos = fixCoordSystem(origVertices[i].pos);
            origVertices[i].normal = fixCoordSystem(origVertices[i].normal);
            vertices[i] = origVertices[i].pos;
            normals[i] = origVertices[i].normal.normalize();
        }

        ModelView *view = (ModelView*)(f.getBuffer() + header.ofsViews);

        uint16 *indexLookup = (uint16*)(f.getBuffer() + view->ofsIndex);
        uint16 *triangles = (uint16*)(f.getBuffer() + view->ofsTris);

        nIndices = view->nTris;
        indices = new uint16[nIndices];
        for (size_t i = 0; i<nIndices; i++)
        {
            indices[i] = indexLookup[triangles[i]];
        }
        f.close();
    } else {
        //printf("not included %s\n", filename.c_str());
        return false;
    }
    return true;

}

bool Model::isAnimated(MPQFile &f)
{
    // see if we have any animated bones
    ModelBoneDef *bo = (ModelBoneDef*)(f.getBuffer() + header.ofsBones);

    animGeometry = false;
    animBones = false;
    ind = false;

    ModelVertex *verts = (ModelVertex*)(f.getBuffer() + header.ofsVertices);
    for (size_t i=0; i<header.nVertices && !animGeometry; i++) {
        for (size_t b=0; b<4; b++) {
            if (verts[i].weights[b]>0) {
                ModelBoneDef &bb = bo[verts[i].bones[b]];
                if (bb.translation.type || bb.rotation.type || bb.scaling.type || (bb.flags&8)) {
                    if (bb.flags&8) {
                        // if we have billboarding, the model will need per-instance animation
                        ind = true;
                    }
                    animGeometry = true;
                    break;
                }
            }
        }
    }

    if (animGeometry) animBones = true;
    else {
        for (size_t i=0; i<header.nBones; i++) {
            ModelBoneDef &bb = bo[i];
            if (bb.translation.type || bb.rotation.type || bb.scaling.type) {
                animBones = true;
                break;
            }
        }
    }

    animTextures = header.nTexAnims > 0;

    bool animMisc = header.nCameras>0 || // why waste time, pretty much all models with cameras need animation
        header.nLights>0 || // same here
        header.nParticleEmitters>0 ||
        header.nRibbonEmitters>0;

    if (animMisc) animBones = true;

    // animated colors
    if (header.nColors) {
        ModelColorDef *cols = (ModelColorDef*)(f.getBuffer() + header.ofsColors);
        for (size_t i=0; i<header.nColors; i++) {
            if (cols[i].color.type!=0 || cols[i].opacity.type!=0) {
                animMisc = true;
                break;
            }
        }
    }

    // animated opacity
    if (header.nTransparency && !animMisc) {
        ModelTransDef *trs = (ModelTransDef*)(f.getBuffer() + header.ofsTransparency);
        for (size_t i=0; i<header.nTransparency; i++) {
            if (trs[i].trans.type!=0) {
                animMisc = true;
                break;
            }
        }
    }

    // guess not...
    return animGeometry || animTextures || animMisc;
}

bool Model::ConvertToVMAPModel(char * outfilename)
{

    int N[] = {0x00000000};
    FILE * output=fopen(outfilename,"wb");
    if(!output)
    {
        printf("Can't create the output file '%s'\n",outfilename);
        return false;
    }
    fwrite("VMAP002",8,1,output);
    int nVertices = header.nVertices;
    fwrite(&nVertices, sizeof(int), 1, output);
    uint32 nofgroups = 1;
    fwrite(&nofgroups,sizeof(uint32), 1, output);
    fwrite(N,4,1,output);
    fwrite("GRP ",4,1,output);
    uint32 branches = 1;
    int wsize;
    wsize = sizeof(branches) + sizeof(uint32) * branches;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&branches,sizeof(branches), 1, output);
    uint32 nIdexes = (uint32) nIndices;
    fwrite(&nIndices,sizeof(uint32), 1, output);
    fwrite("INDX",4, 1, output);
    wsize = sizeof(uint32) + sizeof(unsigned short) * nIdexes;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nIdexes, sizeof(uint32), 1, output);
    if(nIdexes >0)
    {
        fwrite(indices, sizeof(unsigned short), nIdexes, output);
    }
    fwrite("VERT",4, 1, output);
    wsize = sizeof(int) + sizeof(float) * 3 * nVertices;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nVertices, sizeof(int), 1, output);
    if(nVertices >0)
    {
        for(int vpos=0; vpos <nVertices; ++vpos)
        {
            float sy = vertices[vpos].y;
            vertices[vpos].y = vertices[vpos].z;
            vertices[vpos].z = sy;
        }
        fwrite(vertices, sizeof(float)*3, nVertices, output);
    }

    delete[] vertices;
    delete[] indices;
    delete[] normals;

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

ModelInstance::ModelInstance(MPQFile &f,const char* ModelInstName,const char*MapName,  FILE *pDirfile)
{
    float ff[3];
    f.read(&d1, 4);
    f.read(ff,12);
    pos = Vec3D(ff[0],ff[1],ff[2]);
    f.read(ff,12);
    rot = Vec3D(ff[0],ff[1],ff[2]);
    f.read(&scale,4);
    // scale factor - divide by 1024. blizzard devs must be on crack, why not just use a float?
    sc = scale / 1024.0f;

    char tempname[512];
    sprintf(tempname, ".\\buildings\\%s", ModelInstName);
    FILE *input;
    input = fopen(tempname, "r+b");
    if(!input)
    {
        return;
    }
    fseek(input, 8, SEEK_SET); // get the correct no of vertices
    int nVertices;
    fread(&nVertices, sizeof (int), 1, input);
    fclose(input);
    if(nVertices == 0)
    {
        return;
    }

    if(pDirfile)
    {
        int realx1 = (int) ((float) pos.x / 533.333333f);
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
            );
    }
}

