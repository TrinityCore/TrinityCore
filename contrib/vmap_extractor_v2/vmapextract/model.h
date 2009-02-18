#ifndef MODEL_H
#define MODEL_H

#include "vec3d.h"
#include "mpq.h"
#include "modelheaders.h"
//#include "quaternion.h"
#include <vector>

class Model;
class WMOInstance;

Vec3D fixCoordSystem(Vec3D v);




class Model
{
public:
    ModelHeader header;
    ModelAnimation *anims;
    int *globalSequences;

public:
    bool animGeometry,animTextures,animBones;
    bool animated;

    bool isAnimated(MPQFile &f);
    ModelVertex *origVertices;
    Vec3D *vertices, *normals;
    uint16 *indices;
    size_t nIndices;

    bool open();
    bool ConvertToVMAPModel(char * outfilename);

public:

    bool ok;
    bool ind;

    float rad;
    float trans;
    bool animcalc;
    int anim, animtime;

    Model(std::string &filename);
    ~Model();

private:
    std::string filename;
    char outfilename;
};

class ModelInstance
{
public:
    Model *model;

    int id;

    Vec3D pos, rot;
    unsigned int d1, scale;

    float frot,w,sc;

    int light;
    Vec3D ldir;
    Vec3D lcol;

    ModelInstance() {}
    ModelInstance(MPQFile &f,const char* ModelInstName,const char*MapName, FILE *pDirfile);

};

#endif

