#define _CRT_SECURE_NO_DEPRECATE

#ifdef WIN32
#include <windows.h>
#endif

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>
#include <set>

#include "adt.h"
#include "mpq_libmpq.h"

//#include <windows.h>
unsigned int iRes=256;
extern uint16*areas;

vec wmoc;

Cell * cell;
uint32 wmo_count;
mcell *mcells;

int holetab_h[4] = {0x1111, 0x2222, 0x4444, 0x8888};
int holetab_v[4] = {0x000F, 0x00F0, 0x0F00, 0xF000};

bool LoadADT(char* filename)
{
    size_t size;
    MPQFile mf(filename);

    if(mf.isEof())
    {
        //printf("No such file.\n");
        return false;
    }
    mcells=new mcell;

    wmoc.x =65*TILESIZE;
    wmoc.z =65*TILESIZE;

    size_t mcnk_offsets[256], mcnk_sizes[256];

    wmo_count=0;
    bool found=false;
    //uint32 fs=mf.getSize()-3;
    //while (mf.getPos()<fs)
    while (!mf.isEof())
    {
        uint32 fourcc;
        mf.read(&fourcc,4);
        mf.read(&size, 4);

        size_t nextpos = mf.getPos() + size;
        switch(fourcc)
        {
            case 0x4d43494e:                                // MCIN
            {
                //printf("Found chunks info\n");
                // mapchunk offsets/sizes
                for (int i=0; i<256; i++)
                {
                    mf.read(&mcnk_offsets[i],4);
                    mf.read(&mcnk_sizes[i],4);
                    mf.seekRelative(8);
                }
                break;
            }
            case 0x4d4f4446:                                // MODF
            {
                /*
                if(size)
                {
                    //printf("\nwmo count %d\n",size/64);
                    wmo_count =size/64;
                    for (int i=0; i<wmo_count; i++)
                    {
                        int id;
                        mf.read(&id, 4);
                        WMO *wmo = (WMO*)wmomanager.items[wmomanager.get(wmos[id])];
                        WMOInstance inst(wmo, mf);
                        wmois.push_back(inst);
                    }

                }*/
                break;
            }
            case 0x4d574d4f:                                // MWMO
            {
                /*
                if (size)
                {
                    char *buf = new char[size];
                    mf.read(buf, size);
                    char *p=buf;
                    while (p<buf+size)
                    {
                    std::string path(p);
                        p+=strlen(p)+1;
                        fixname(path);

                        wmomanager.add(path);
                        wmos.push_back(path);
                    }
                    delete[] buf;
                }*/
                break;
            }
            case 0x4d564552:                                // MVER
            case 0x4d484452:                                // MHDR header
            case 0x4d434e4b:                                // MCNK
            case 0x4d544558:                                // MTEX textures (strings)
            case 0x4d4d4458:                                // MMDX m2 models (strings)
            case 0x4d4d4944:                                // MMID offsets for strings in MMDX
            case 0x4d574944:                                // MWID offsets for strings in MWMO
            case 0x4d444446:                                // MDDF
            case 0x4d46424f:                                // MFBO new in BC
            case 0x4d48324f:                                // MH2O new in WotLK
                break;
            default:
            {
                // mf.seekRelative(-3);
                printf("Unhandled map chunk: %u\n",fourcc);
                break;
            }
        }
        mf.seek(nextpos);
    }

    //printf("Loading chunks info\n");
    // read individual map chunks
    for (int j=0; j<16; j++)
        for (int i=0; i<16; i++)
        {
            mf.seek((int)mcnk_offsets[j*16+i]);
            LoadMapChunk(mf,&(mcells->ch[i][j]));
        }

    /*
    for(uint32 t=0;t<wmo_count ;t++)
    {
        wmois[t].draw();
    }*/

    mf.close();
    return true;
}

struct MapChunkHeader {
    uint32 flags;
    uint32 ix;
    uint32 iy;
    uint32 nLayers;
    uint32 nDoodadRefs;
    uint32 ofsHeight;
    uint32 ofsNormal;
    uint32 ofsLayer;
    uint32 ofsRefs;
    uint32 ofsAlpha;
    uint32 sizeAlpha;
    uint32 ofsShadow;
    uint32 sizeShadow;
    uint32 areaid;
    uint32 nMapObjRefs;
    uint32 holes;
    uint16 s1;
    uint16 s2;
    uint32 d1;
    uint32 d2;
    uint32 d3;
    uint32 predTex;
    uint32 nEffectDoodad;
    uint32 ofsSndEmitters;
    uint32 nSndEmitters;
    uint32 ofsLiquid;
    uint32 sizeLiquid;
    float  zpos;
    float  xpos;
    float  ypos;
    uint32 textureId;
    uint32 props;
    uint32 effectId;
};

bool isHole(int holes, int i, int j)
{
    int testi = i/2;
    int testj = j/4;
    if(testi>3) testi = 3;
    if(testj>3) testj = 3;
    return (holes & holetab_h[testi] & holetab_v[testj])!=0;
}

inline
void LoadMapChunk(MPQFile & mf, chunk*_chunk)
{
    float h;
    uint32 fourcc;
    uint32 size;
    MapChunkHeader header;

    mf.seekRelative(4);
    mf.read(&size, 4);

    size_t lastpos = mf.getPos() + size;
    mf.read(&header, 0x80);
    _chunk->area_id =header.areaid ;
    _chunk->flag =0;

    float xbase = header.xpos;
    float ybase = header.ypos;
    float zbase = header.zpos;
    zbase = TILESIZE*32-zbase;
    xbase = TILESIZE*32-xbase;
    if(wmoc.x >xbase)wmoc.x =xbase;
    if(wmoc.z >zbase)wmoc.z =zbase;
    int chunkflags = header.flags;
    float zmin=999999999.0f;
    float zmax=-999999999.0f;
    //must be there, bl!zz uses some crazy format
    int nTextures;
    while (mf.getPos() < lastpos)
    {
        mf.read(&fourcc,4);
        mf.read(&size, 4);
        //if(size!=580)
        //    printf("\n sz=%d",size);
        size_t nextpos = mf.getPos()  + size;
        if(fourcc==0x4d435654)                              // MCVT
        {
            for (int j=0; j<17; j++)
                for (int i=0; i<((j%2)?8:9); i++)
                {
                    mf.read(&h,4);
                    float z=h+ybase;
                    if (j%2)
                    {
                        if(isHole(header.holes,i,j))
                            _chunk->v8[i][j/2] = -1000;
                        else
                            _chunk->v8[i][j/2] = z;
                    }
                    else
                    {
                        if(isHole(header.holes,i,j))
                            _chunk->v9[i][j/2] = -1000;
                        else
                            _chunk->v9[i][j/2] = z;
                    }

                    if(z>zmax)zmax=z;
                    //if(z<zmin)zmin=z;
                }
        }
        else if(fourcc==0x4d434e52)                         // MCNR
        {
            nextpos = mf.getPos() + 0x1C0; // size fix
        }
        else if(fourcc==0x4d434c51)                         // MCLQ
        {
            // liquid / water level
            //bool haswater;
            char fcc1[5];
            mf.read(fcc1,4);
            flipcc(fcc1);
            fcc1[4]=0;

            if (!strcmp(fcc1,"MCSE"))
            {
                for(int i=0;i<9;i++)
                    for(int j=0;j<9;j++)
                        _chunk->waterlevel[i][j]=-999999; // no liquid/water
            }
            else
            {
                float maxheight;
                mf.read(&maxheight, 4);

                for(int j=0;j<9;j++)
                    for(int i=0;i<9;i++)
                    {
                        mf.read(&h, 4);
                        mf.read(&h, 4);
                        if(h > maxheight)
                            _chunk->waterlevel[i][j]=-999999;
                        else
                            _chunk->waterlevel[i][j]=h;
                    }

                if(chunkflags & 4 || chunkflags & 8)
                    _chunk->flag |=1;
                if(chunkflags & 16)
                    _chunk->flag |=2;

            }
            break;
        }
        else if (fourcc==0x4d434c59)                        // MCLY
        {
            // texture info
            nTextures = (int)size;
        }
        else if (fourcc==0x4d43414c)                        // MCAL
        {
            if (nTextures<=0)
                continue;
        }

        mf.seek(nextpos);
    }
}

double solve (vec *v,vec *p)
{
    double a = v[0].y *(v[1].z - v[2].z) + v[1].y *(v[2].z - v[0].z) + v[2].y *(v[0].z - v[1].z);
    double b = v[0].z *(v[1].x - v[2].x) + v[1].z *(v[2].x - v[0].x) + v[2].z *(v[0].x - v[1].x);
    double c = v[0].x *(v[1].y - v[2].y) + v[1].x *(v[2].y - v[0].y) + v[2].x *(v[0].y - v[1].y);
    double d = v[0].x *(v[1].y*v[2].z - v[2].y*v[1].z) + v[1].x* (v[2].y*v[0].z - v[0].y*v[2].z) + v[2].x* (v[0].y*v[1].z - v[1].y*v[0].z);
    //-d

    //plane equation ax+by+cz+d=0
    return ((a*p->x+c*p->z-d)/b);
}

inline
double GetZ(double x,double z)
{
    vec v[3];
    vec p;

    //bool inWMO=false;

    //if(!inWMO)
    {
        //find out quadrant
        int xc=(int)(x/UNITSIZE);
        int zc=(int)(z/UNITSIZE);
        if(xc>127)xc=127;
        if(zc>127)zc=127;

        double lx=x-xc*UNITSIZE;
        double lz=z-zc*UNITSIZE;
        p.x=lx;
        p.z=lz;

        v[0].x=UNITSIZE/2;
        v[0].y =cell->v8[xc][zc];
        v[0].z=UNITSIZE/2;

        if(lx>lz)
        {
            v[1].x=UNITSIZE;
            v[1].y =cell->v9[xc+1][zc];
            v[1].z=0;
        }
        else
        {
            v[1].x=0.0;
            v[1].y =cell->v9[xc][zc+1];
            v[1].z=UNITSIZE;
        }

        if(lz>UNITSIZE-lx)
        {
            v[2].x=UNITSIZE;
            v[2].y =cell->v9[xc+1][zc+1];
            v[2].z=UNITSIZE;
        }
        else
        {
            v[2].x=0;
            v[2].y=cell->v9[xc][zc];
            v[2].z=0;
        }

        return -solve(v,&p);
    }
}

inline
void TransformWaterData()
{
    cell= new Cell;

    for(int x=0;x<128;x++)
        for(int y=0;y<128;y++)
            cell->v9[x][y] = mcells->ch[x/8][y/8].waterlevel[x%8][y%8];

    //and the last 1
    cell->v9[128][128] = mcells->ch[15][15].waterlevel[8][8];
}

inline
void TransformData()
{
    cell= new Cell;

    for(int x=0;x<128;x++)
    {
        for(int y=0;y<128;y++)
        {
            cell->v8[y][x] = (float)mcells->ch[x/8][y/8].v8[x%8][y%8];
            cell->v9[y][x] = (float)mcells->ch[x/8][y/8].v9[x%8][y%8];
        }

        //extra 1 point on bounds
        cell->v9[128][x] = (float)mcells->ch[x/8][15].v9[x%8][8];
        //x==y
        cell->v9[x][128] = (float)mcells->ch[15][x/8].v9[8][x%8];
    }

    //and the last 1
    cell->v9[128][128] = (float)mcells->ch[15][15].v9[8][8];

    delete mcells;
}

const char MAP_MAGIC[] = "MAP_2.50";

bool ConvertADT(char * filename,char * filename2)
{
    //if(!strstr(filename,"oth_32_48"))return false;
    if(!LoadADT(filename))
        return false;

    FILE *output=fopen(filename2,"wb");
    if(!output)
    {
        printf("Can't create the output file '%s'\n",filename2);
        return false;
    }

    // write magic header
    fwrite(MAP_MAGIC,1,8,output);

    for(unsigned int x=0;x<16;x++)
    {
        for(unsigned int y=0;y<16;y++)
        {
            if(mcells->ch[y][x].area_id && mcells->ch[y][x].area_id < 0x102D)
            {
                if(areas[mcells->ch[y][x].area_id]==0xffff)
                    printf("\nCan't find area flag for areaid %u.\n",mcells->ch[y][x].area_id);

                fwrite(&areas[mcells->ch[y][x].area_id],1,2,output);
            }
            else
            {
                uint16 flag=0xffff;
                fwrite(&flag,1,2,output);
            }
        }
    }

    for(unsigned int x=0;x<16;x++)
        for(unsigned int y=0;y<16;y++)
            fwrite(&mcells->ch[y][x].flag,1,1,output);

    TransformWaterData();

    for(unsigned int x=0;x<128;x++)
        for(unsigned int y=0;y<128;y++)
            fwrite(&cell->v9[y][x],1,sizeof(float),output);

    delete cell;
    TransformData();

    /*
    for(unsigned int x=0;x<iRes;x++)
    for(unsigned int y=0;y<iRes;y++)
    {
        float z=(float)GetZ(
                    (((double)(y))*TILESIZE)/((double)(iRes-1)),
                    (((double)(x))*TILESIZE)/((double)(iRes-1)));

        fwrite(&z,1,sizeof(z),output);
    }*/

    fwrite(&cell->v9, 1, sizeof(cell->v9), output);
    fwrite(&cell->v8, 1, sizeof(cell->v8), output);
    fclose(output);
    delete cell;
/*
    for (std::vector<std::string>::iterator it = wmos.begin(); it != wmos.end(); ++it)
    wmomanager.delbyname(*it);

    wmos.clear();
    wmois.clear();

    for (std::vector<model>::iterator it = wmomodel.begin(); it != wmomodel.end(); ++it)
    {
        it->tr.clear();

    }
    //printf("\n %d \n",in);
    wmomodel.clear();
    //polygons.clear();*/
    return true;
}

