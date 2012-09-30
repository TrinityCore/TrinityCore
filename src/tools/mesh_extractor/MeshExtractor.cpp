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

void ExtractAllMaps(std::set<uint32>& mapIds, uint32 threads, bool debug)
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
        builder.Build(debug);
    }
}

bool HandleArgs(int argc, char** argv, uint32& threads, std::set<uint32>& mapList, bool& debugOutput)
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
        if (strcmp(argv[i], "--debug") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            debugOutput = atoi(param);
            printf("Output will contain debug information (.obj files)\n");
        }
    }
    return true;
}

void PrintUsage()
{
    printf("MeshExtractor help.\n");
    printf("* Use \"--threads <number>\" to specify <number> threads, default to 4\n");
    printf("* Use \"--maps a,b,c,d,e\" to extract only the maps specified ( do not use spaces )\n");
    printf("* Use \"--debug 1\" to generate debug information of the tiles.\n");
}

int main(int argc, char* argv[])
{
    system("pause");
    Cache = new CacheClass();
    MPQHandler = new MPQManager();
    MPQHandler->Initialize();
    uint32 threads = 4;
    std::set<uint32> mapIds;
    bool debug = false;

    if (!HandleArgs(argc, argv, threads, mapIds, debug))
    {
        PrintUsage();
        return -1;
    }

    ExtractAllMaps(mapIds, threads, debug);
    return 0;
}