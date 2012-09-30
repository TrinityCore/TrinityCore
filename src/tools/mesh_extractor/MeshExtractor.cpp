#include "MPQManager.h"
#include "WDT.h"
#include "ContinentBuilder.h"
#include "Cache.h"
#include "DBC.h"

#include <set>

#include "Common.h"
#include "LoginDatabase.h"
#include "Util.h"
LoginDatabaseWorkerPool LoginDatabase;

MPQManager* MPQHandler;
CacheClass* Cache;

void ExtractAllMaps(std::set<uint32>& mapIds, uint32 threads)
{
    DBC* dbc = MPQHandler->GetDBC("Map");
    for (std::vector<Record*>::iterator itr = dbc->Records.begin(); itr != dbc->Records.end(); ++itr)
    {
        uint32 mapId = (*itr)->Values[0];

        // Skip this map if a list of specific maps was provided and this one is not contained in it.
        if (!mapIds.empty() && mapIds.find(mapId) == mapIds.end())
            continue;

        std::string name = (*itr)->GetString(1);
        WDT wdt("World\\maps\\" + name + "\\" + name + ".wdt");
        if (!wdt.IsValid || wdt.IsGlobalModel)
            continue;
        printf("Building %s MapId %u\n", name.c_str(), mapId);
        ContinentBuilder builder(name, mapId, &wdt, threads);
        builder.Build();
    }
}

bool HandleArgs(int argc, char** argv, uint32& threads, std::set<uint32>& mapList)
{
    char* param = NULL;
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--threads") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            threads = atoi(param);
            printf("Using %i threads\n", threads);
        }
        if (strcmp(argv[i], "--maps") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            std::string maps = std::string(param);
            Tokens tokens(maps, ',');

            for (Tokens::iterator itr = tokens.begin(); itr != tokens.end(); ++itr)
                mapList.insert(atoi(*itr));

            printf("Extracting only provided list of maps (%u).\n", mapList.size());
        }
    }
    return true;
}

void PrintUsage()
{
    printf("MeshExtractor help.\n");
    printf("* Use \"--threads <number>\" to specify <number> threads, default to 4\n");
    printf("* Use \"--maps a,b,c,d,e\" to extract only the maps specified ( do not use spaces )\n");
}

int main(int argc, char* argv[])
{
    system("pause");
    Cache = new CacheClass();
    MPQHandler = new MPQManager();
    MPQHandler->Initialize();
    uint32 threads = 4;
    std::set<uint32> mapIds;

    if (!HandleArgs(argc, argv, threads, mapIds))
    {
        PrintUsage();
        return -1;
    }

    ExtractAllMaps(mapIds, threads);
    return 0;
}

