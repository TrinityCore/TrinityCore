#include "ContinentBuilder.h"
#include "TileBuilder.h"
#include "WDT.h"
#include "Utils.h"
#include "DetourNavMesh.h"
#include "ace/Task.h"

class BuilderThread : public ACE_Task<ACE_MT_SYNCH>
{
private:
    int X, Y, MapId;
    std::string Continent;
public:
    BuilderThread() : Free(true) {}
    void SetData(int x, int y, int map, std::string cont) { X = x; Y = y; MapId = map; Continent = cont; }

    int svc()
    {
        Free = false;
        TileBuilder builder(Continent, X, Y, MapId);
        char buff[100];
        sprintf(buff, "%03u%02u%02u.mmtile", MapId, X, Y);
        FILE* f = fopen(buff, "r");
        if (f) // Check if file already exists.
        {
            fclose(f);
            Free = true;
            return 0;
        }
        uint8* nav = builder.Build();
        if (nav)
        {
            f = fopen(buff, "wb");
            MmapTileHeader header;
            header.size = builder.DataSize;
            fwrite(&header, sizeof(MmapTileHeader), 1, f);
            fwrite(nav, sizeof(unsigned char), builder.DataSize, f);
            fclose(f);
        }
        dtFree(nav);
        printf("[%02u,%02u] Tile Built!\n", X, Y);
        Free = true;
        return 0;
    }

    bool Free;
};

void ContinentBuilder::Build()
{
    char buff[50];
    sprintf(buff, "%03u.mmap", MapId);
    FILE* mmap = fopen(buff, "wb");
    dtNavMeshParams params;
    params.maxPolys = 32768;
    params.maxTiles = 4096;
    params.orig[0] = -17066.666f;
    params.orig[1] = 0.0f;
    params.orig[2] = -17066.666f;
    params.tileHeight = 533.33333f;
    params.tileWidth = 533.33333f;
    fwrite(&params, sizeof(dtNavMeshParams), 1, mmap);
    fclose(mmap);
    std::vector<BuilderThread*> Threads;
    /*for (uint32 i = 0; i < 1; ++i)
        Threads.push_back(new BuilderThread());*/
    for (std::vector<TilePos>::iterator itr = TileMap->TileTable.begin(); itr != TileMap->TileTable.end(); ++itr)
    {
        BuilderThread th;
        th.SetData(itr->X, itr->Y, MapId, Continent);
        th.svc();
        /*bool next = false;
        while (!next)
        {
            for (std::vector<BuilderThread*>::iterator _th = Threads.begin(); _th != Threads.end(); ++_th)
            {
                if ((*_th)->Free)
                {
                    (*_th)->SetData(itr->X, itr->Y, MapId, Continent);
                    (*_th)->activate();
                    next = true;
                    break;
                }
            }
            // Wait for 20 seconds
            ACE_OS::sleep(ACE_Time_Value (0, 20000));
        }*/
    }

    /*// Free memory
    for (std::vector<BuilderThread*>::iterator _th = Threads.begin(); _th != Threads.end(); ++_th)
    {
        (*_th)->wait();
        delete *_th;
    }*/
}
