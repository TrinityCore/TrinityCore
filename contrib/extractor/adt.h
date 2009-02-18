#ifndef ADT_H
#define ADT_H

#define TILESIZE (533.33333f)
#define CHUNKSIZE ((TILESIZE) / 16.0f)
#define UNITSIZE (CHUNKSIZE / 8.0f)

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
class Liquid;
typedef struct {
float x;
float y;
float z;
}svec;

typedef struct {
double x;
double y;
double z;
}vec;

typedef struct{
    vec v[3];
}triangle;

typedef struct{
float v9[16*8+1][16*8+1];
float v8[16*8][16*8];
}Cell;

typedef struct{
double v9[9][9];
double v8[8][8];
uint16 area_id;
//Liquid *lq;
float waterlevel[9][9];
uint8 flag;
}chunk;

class WMO;
class WMOManager;
void fixname(std::string &name);

typedef struct
{
chunk ch[16][16];
}mcell;
class MPQFile;
void LoadMapChunk(MPQFile &,chunk*);
bool LoadWMO(char* filename);
#endif


