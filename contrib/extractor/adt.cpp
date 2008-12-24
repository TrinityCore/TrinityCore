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

uint32 iRes = 256;
extern uint16 *areas;
extern uint16 *LiqType;
extern uint32 maxAreaId;

vec wmoc;

Cell *cell;
mcell *mcells;
int holetab_h[4] = {0x1111, 0x2222, 0x4444, 0x8888};
int holetab_v[4] = {0x000F, 0x00F0, 0x0F00, 0xF000};

bool LoadADT(char* filename)
{
    size_t size;
    MPQFile mf(filename);

    if(mf.isEof())
    {
        //printf("No such file %s\n", filename);
        return false;
    }

    MapLiqFlag = new uint8[256];
    for(uint32 j = 0; j < 256; ++j)
        MapLiqFlag[j] = 0;                                  // no water

    MapLiqHeight = new float[16384];
    for(uint32 j = 0; j < 16384; ++j)
        MapLiqHeight[j] = -999999;                          // no water

    mcells = new mcell;

    wmoc.x = 65 * TILESIZE;
    wmoc.z = 65 * TILESIZE;

    size_t mcnk_offsets[256], mcnk_sizes[256];

    chunk_num = 0;
    k = 0;
    m = 0;
    while (!mf.isEof())
    {
        uint32 fourcc;
        mf.read(&fourcc, 4);
        mf.read(&size, 4);

        size_t nextpos = mf.getPos() + size;

        //if(fourcc==0x4d484452)                            // MHDR header
        //if(fourcc==0x4d564552)                            // MVER
        if(fourcc == 0x4d43494e)                            // MCIN
        {
            for (uint32 i = 0; i < 256; ++i)
            {
                mf.read(&mcnk_offsets[i], 4);
                mf.read(&mcnk_sizes[i], 4);
                mf.seekRelative(8);
            }
        }
        //if(fourcc == 0x4d544558)                          // MTEX textures (strings)
        //if(fourcc == 0x4d4d4458)                          // MMDX m2 models (strings)
        //if(fourcc == 0x4d4d4944)                          // MMID offsets for strings in MMDX
        //if(fourcc == 0x4d574d4f)                          // MWMO
        //if(fourcc == 0x4d574944)                          // MWID offsets for strings in MWMO
        //if(fourcc == 0x4d444446)                          // MDDF
        //if(fourcc == 0x4d4f4446)                          // MODF
        if(fourcc == 0x4d48324f)                            // MH2O new in WotLK
        {
            // здесь надо запомнить базовую позицию в файле тк все смещения будут от него
            uint32 base_pos = mf.getPos();
            uint32 header_pos = 0;
            MH2O_offsData *LiqOffsData = new MH2O_offsData;
            MH2O_Data1 *LiqChunkData1 = new MH2O_Data1;
            float *ChunkLiqHeight = new float[81];
            for(chunk_num = 0; chunk_num < 256; ++chunk_num)
            {
                mf.read(LiqOffsData, 0x0C);
                header_pos = mf.getPos();
                if(LiqOffsData->offsData1 != 0)             // если данные в Data1 о воде есть, то их надо конвертировать
                {
                    // переходим по смещению из offsData1 ОТ НАЧАЛА куска
                    mf.seek(base_pos + LiqOffsData->offsData1);
                    mf.read(LiqChunkData1, 0x18);           // считываем сами данные в структуру типа MH2O_Data1
                    // заносим данные флага для куска
                    if(LiqType[LiqChunkData1->LiquidTypeId] == 0xffff)
                        printf("\nCan't find Liquid type for map %s\nchunk %d\n", filename, chunk_num);
                    else if(LiqType[LiqChunkData1->LiquidTypeId] == LIQUID_TYPE_WATER || LiqType[LiqChunkData1->LiquidTypeId] == LIQUID_TYPE_OCEAN)
                        MapLiqFlag[chunk_num] |= 1;         // water/ocean
                    else if(LiqType[LiqChunkData1->LiquidTypeId] == LIQUID_TYPE_MAGMA || LiqType[LiqChunkData1->LiquidTypeId] == LIQUID_TYPE_SLIME)
                        MapLiqFlag[chunk_num] |= 2;         // magma/slime
                    // предварительно заполняем весь кусок данными - нет воды
                    for(int j = 0; j < 81; ++j)
                    {
                        ChunkLiqHeight[j] = -999999;        // no liquid/water
                    }
<<<<<<< HEAD:contrib/extractor/adt.cpp

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
=======
                    // теперь вычисляем те что с водой и перезаписываем их в куске 
                    for(int b = 0; b <= LiqChunkData1->height; ++b)
>>>>>>> upstream/master:contrib/extractor/adt.cpp
                    {
                        for(int c = LiqChunkData1->xOffset; c <= (LiqChunkData1->xOffset + LiqChunkData1->width); ++c)
                        {
                            int n = (9 * (LiqChunkData1->yOffset + b)) + c;
                            ChunkLiqHeight[n] = LiqChunkData1->heightLevel1;
                        }
                    }
                    mf.seek(header_pos);                    // и не забыть вернуться на исходную позицию именно В ХИДЕРЕ
                }
                else                                        // если данных в Data1 нет, то надо заполнить весь кусок, но данными - нет воды
                {
                    for(int j = 0; j < 81; ++j)
                        ChunkLiqHeight[j] = -999999;        // no liquid/water
                }

                if(!(chunk_num % 16))
                    m = 1024 * (chunk_num / 16);            // смещение по рядам кусков с перекрытием = 1024
                k = m + (chunk_num % 16) * 8;               // устанавливаемся на начальный индекс для заполнения ряда
                // заносим данные куска в массив для карты, с перекрытием и обрезанием кусков тк данных 81
                // это аналог старого обрезания граничных правых-боковых и нижних данных
                for(int p = 0; p < 72; p += 9)              // нижние 8 не заносим тк они дублируется след куском
                {
                    for(int s = 0; s < 8; ++s)              // 9 значение в строке не заносим тк оно дублируется след куском, а в правых-боковых обрезается для 128х128
                    {
                        MapLiqHeight[k] = ChunkLiqHeight[p + s];
                        ++k;
                    }
<<<<<<< HEAD:contrib/extractor/adt.cpp
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
=======
                    k = k + 120;
                }
>>>>>>> upstream/master:contrib/extractor/adt.cpp
            }
            delete LiqOffsData;
            delete LiqChunkData1;
            delete []ChunkLiqHeight;

        }
        //case 0x4d434e4b:                                  // MCNK
        //case 0x4d46424f:                                  // MFBO new in BC
        //case 0x4d545846:                                  // MTXF new in WotLK
        mf.seek(nextpos);
    }

    //printf("Loading chunks info\n");
    // read individual map chunks
    chunk_num = 0;
    k = 0;
    m = 0;
    for (int j = 0; j < 16; ++j)
    {
        for (int i = 0; i < 16; ++i)
        {
            mf.seek((int)mcnk_offsets[j * 16 + i]);
            LoadMapChunk(mf, &(mcells->ch[i][j]));
            ++chunk_num;
        }
    }
    mf.close();
    return true;
}

bool isHole(int holes, int i, int j)
{
    int testi = i / 2;
    int testj = j / 4;
    if(testi > 3) testi = 3;
    if(testj > 3) testj = 3;
    return (holes & holetab_h[testi] & holetab_v[testj]) != 0;
}

inline void LoadMapChunk(MPQFile &mf, chunk *_chunk)
{
    float h;
    uint32 fourcc;
    uint32 size;
    MapChunkHeader header;

    mf.seekRelative(4);
    mf.read(&size, 4);

    size_t lastpos = mf.getPos() + size;
    mf.read(&header, 0x80);                                 // what if header size got changed?
    _chunk->area_id = header.areaid;

    float xbase = header.xpos;
    float ybase = header.ypos;
    float zbase = header.zpos;
    zbase = TILESIZE * 32 - zbase;
    xbase = TILESIZE * 32 - xbase;
    if(wmoc.x > xbase) wmoc.x = xbase;
    if(wmoc.z > zbase) wmoc.z = zbase;
    int chunkflags = header.flags;
    //printf("LMC: flags %X\n", chunkflags);
    float zmin = 999999999.0f;
    float zmax = -999999999.0f;
    // must be there, bl!zz uses some crazy format
    while (mf.getPos() < lastpos)
    {
        mf.read(&fourcc, 4);
        mf.read(&size, 4);
        size_t nextpos = mf.getPos() + size;
        if(fourcc == 0x4d435654)                            // MCVT
        {
            for (int j = 0; j < 17; ++j)
            {
                for (int i = 0; i < ((j % 2) ? 8 : 9); ++i)
                {
                    mf.read(&h, 4);
                    float z = h + ybase;
                    if (j % 2)
                    {
                        if(isHole(header.holes, i, j))
                            _chunk->v8[i][j / 2] = -1000;
                        else
                            _chunk->v8[i][j / 2] = z;
                    }
                    else
                    {
                        if(isHole(header.holes, i, j))
                            _chunk->v9[i][j / 2] = -1000;
                        else
                            _chunk->v9[i][j / 2] = z;
                    }

                    if(z > zmax) zmax = z;
                    //if(z < zmin) zmin = z;
                }
            }
        }
        else if(fourcc == 0x4d434e52)                       // MCNR
        {
            nextpos = mf.getPos() + 0x1C0;                  // size fix
        }
        else if(fourcc == 0x4d434c51)                       // не будем учитывать если уже были данные в MH2O, перестраховка :)                      // MCLQ
        {
            // liquid / water level
            char fcc1[5];
            mf.read(fcc1, 4);
            flipcc(fcc1);
            fcc1[4] = 0;
            float *ChunkLiqHeight = new float[81];

            if (!strcmp(fcc1, "MCSE"))
            {
                for(int j = 0; j < 81; ++j)
                {
                    ChunkLiqHeight[j] = -999999;            // no liquid/water
                }
            }
            else
            {
                float maxheight;
                mf.read(&maxheight, 4);
                for(int j = 0; j < 81; ++j)
                {
                    LiqData liq;
                    mf.read(&liq, 8);

                    if(liq.height > maxheight)
                        ChunkLiqHeight[j] = -999999;
                    else
                        ChunkLiqHeight[j] = h;
                }

                if(chunkflags & 4 || chunkflags & 8)
                    MapLiqFlag[chunk_num] |= 1;             // water
                if(chunkflags & 16)
<<<<<<< HEAD:contrib/extractor/adt.cpp
                    _chunk->flag |=2;

=======
                    MapLiqFlag[chunk_num] |= 2;             // magma/slime
            }
            // заполнем так же как в MH2O
            if(!(chunk_num % 16))
                m = 1024 * (chunk_num / 16);
            k = m + (chunk_num % 16) * 8;
            
            for(int p = 0; p < 72; p += 9)
            {
                for(int s = 0; s < 8; ++s)
                {
                    MapLiqHeight[k] = ChunkLiqHeight[p + s];
                    ++k;    
                }
                k = k + 120;
>>>>>>> upstream/master:contrib/extractor/adt.cpp
            }
            delete []ChunkLiqHeight;
            break;
        }
        mf.seek(nextpos);
    }
}

double solve (vec *v,vec *p)
{
    double a = v[0].y * (v[1].z - v[2].z) + v[1].y * (v[2].z - v[0].z) + v[2].y * (v[0].z - v[1].z);
    double b = v[0].z * (v[1].x - v[2].x) + v[1].z * (v[2].x - v[0].x) + v[2].z * (v[0].x - v[1].x);
    double c = v[0].x * (v[1].y - v[2].y) + v[1].x * (v[2].y - v[0].y) + v[2].x * (v[0].y - v[1].y);
    double d = v[0].x * (v[1].y * v[2].z - v[2].y * v[1].z) + v[1].x * (v[2].y * v[0].z - v[0].y * v[2].z) + v[2].x * (v[0].y * v[1].z - v[1].y * v[0].z);
    // -d

    // plane equation ax+by+cz+d=0
    return ((a*p->x+c*p->z-d)/b);
}

inline double GetZ(double x, double z)
{
    vec v[3];
    vec p;
    {
        // find out quadrant
        int xc = (int)(x / UNITSIZE);
        int zc = (int)(z / UNITSIZE);
        if(xc > 127) xc = 127;
        if(zc > 127) zc = 127;

        double lx = x - xc * UNITSIZE;
        double lz = z - zc * UNITSIZE;
        p.x = lx;
        p.z = lz;

        v[0].x = UNITSIZE / 2;
        v[0].y = cell->v8[xc][zc];
        v[0].z = UNITSIZE / 2;

        if(lx > lz)
        {
            v[1].x = UNITSIZE;
            v[1].y = cell->v9[xc + 1][zc];
            v[1].z = 0.0f;
        }
        else
        {
            v[1].x = 0.0f;
            v[1].y = cell->v9[xc][zc + 1];
            v[1].z = UNITSIZE;
        }

        if(lz > UNITSIZE - lx)
        {
            v[2].x = UNITSIZE;
            v[2].y = cell->v9[xc + 1][zc + 1];
            v[2].z = UNITSIZE;
        }
        else
        {
            v[2].x = 0.0f;
            v[2].y = cell->v9[xc][zc];
            v[2].z = 0.0f;
        }

        return -solve(v, &p);
    }
}

inline void TransformData()
{
    cell = new Cell;

    for(uint32 x = 0; x < 128; ++x)
    {
        for(uint32 y = 0; y < 128; ++y)
        {
            cell->v8[x][y] = (float)mcells->ch[x / 8][y / 8].v8[x % 8][y % 8];
            cell->v9[x][y] = (float)mcells->ch[x / 8][y / 8].v9[x % 8][y % 8];
        }

        // extra 1 point on bounds
        cell->v9[x][128] = (float)mcells->ch[x / 8][15].v9[x % 8][8];
        // x == y
        cell->v9[128][x] = (float)mcells->ch[15][x / 8].v9[8][x % 8];

    }

    // and the last 1
    cell->v9[128][128] = (float)mcells->ch[15][15].v9[8][8];

    delete mcells;
}

const char MAP_MAGIC[] = "MAP_2.01";

bool ConvertADT(char *filename, char *filename2)
{
    if(!LoadADT(filename))
        return false;

    FILE *output=fopen(filename2, "wb");
    if(!output)
    {
        printf("Can't create the output file '%s'\n", filename2);
        delete [] MapLiqHeight;
        delete [] MapLiqFlag;
        return false;
    }

    // write magic header
    fwrite(MAP_MAGIC, 1, 8, output);

    for(uint32 x = 0; x < 16; ++x)
    {
        for(uint32 y = 0; y < 16; ++y)
        {
            if(mcells->ch[y][x].area_id && mcells->ch[y][x].area_id <= maxAreaId)
            {
                if(areas[mcells->ch[y][x].area_id] == 0xffff)
                    printf("\nCan't find area flag for areaid %u.\n", mcells->ch[y][x].area_id);

                fwrite(&areas[mcells->ch[y][x].area_id], 1, 2, output);
            }
            else
            {
                uint16 flag = 0xffff;
                fwrite(&flag, 1, 2, output);
            }
        }
    }

    fwrite(MapLiqFlag, 1, 256, output);
    delete [] MapLiqFlag;

    fwrite(MapLiqHeight, sizeof(float), 16384, output);
    delete [] MapLiqHeight;

    TransformData();

    for(uint32 x = 0; x < iRes; ++x)
    {
        for(uint32 y = 0; y < iRes; ++y)
        {
            float z = (float)GetZ(
                (((double)(y)) * TILESIZE) / ((double)(iRes - 1)),
                (((double)(x)) * TILESIZE) / ((double)(iRes - 1)));

            fwrite(&z, 1, sizeof(z), output);
        }
    }

    fclose(output);
    delete cell;
    
    return true;
}
