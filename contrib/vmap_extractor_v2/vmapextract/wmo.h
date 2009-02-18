#ifndef WMO_H
#define WMO_H
#define __STORMLIB_SELF__
#define TILESIZE (533.33333f)
#define CHUNKSIZE ((TILESIZE) / 16.0f)

#include "Stormlib.h"
#include <string>
#include "vec3d.h"
#include <set>
#include "mpq.h"


class WMOInstance;
class WMOManager;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


class WMORoot
{
public:
    int nTextures, nGroups, nP, nLights, nModels, nDoodads, nDoodadSets, RootID;
    unsigned int col;
    int bbcorn1[3];
    int bbcorn2[3];

    WMORoot(std::string &filename);
    ~WMORoot();

    bool open();
    bool ConvertToVMAPRootWmo(FILE *output);
private:
    std::string filename;
    char outfilename;

};

class WMOGroup
{
public:

    int offsize,flag,flag1,Xid,Xid2,Xid3,zero1,Xflag,nTexture,GroupID;
    int mopy_size,moba_size,hlq_xverts,hlq_yverts;
    int MopyEx_size,IndexExTr_size,LiquEx_size;
    unsigned int nVertices; // number when loaded
    int nTriangles; // number when loaded
    int bbcorn1[3];
    int bbcorn2[3];
    int * IndexExTr;
    char* MOPY;
    char* MopyEx;
    uint16* MOVI;
    uint16* MoviEx;
    uint16* MoviExSort;
    float* MOVT;
    float* MovtEx;
    uint16* MovtExSort;
    float* MONR;
    float* MonrEx;
    uint16* MOBA;
    int* MobaEx;
    float* LiquEx;
    uint32 liquflags;

    WMOGroup(std::string &filename);
    ~WMOGroup();

    bool open();
    int ConvertToVMAPGroupWmo(FILE *output, bool pPreciseVectorData);

private:
    std::string filename;
    char outfilename;

};

struct WMOLiquidHeader
{
    int xverts, yverts, xtiles, ytiles;
    float pos_x;
    float pos_y;
    float pos_z;
    short type;
};

class WMOInstance
{
    static std::set<int> ids;
public:
    string MapName;
    int currx;
    int curry;
    WMOGroup *wmo;
    Vec3D pos;
    Vec3D pos2, pos3, rot;
    int indx,id, d2, d3;
    int doodadset;

    WMOInstance(MPQFile &f,const char* WmoInstName,const char*MapName, FILE *pDirfile);

    static void reset();
};

#endif

