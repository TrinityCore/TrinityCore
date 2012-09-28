#include "MPQManager.h"
#include "WDT.h"
#include "ContinentBuilder.h"
#include "Cache.h"
#include "DBC.h"

#include "Common.h"
#include "LoginDatabase.h"
LoginDatabaseWorkerPool LoginDatabase;

MPQManager* MPQHandler;
CacheClass* Cache;

void ExtractAllMaps(uint32 onlyMap)
{
    DBC* dbc = MPQHandler->GetDBC("Map");
    for (std::vector<Record*>::iterator itr = dbc->Records.begin(); itr != dbc->Records.end(); ++itr)
    {
        uint32 mapId = (*itr)->Values[0];
        if (onlyMap && mapId != onlyMap)
            continue;
        std::string name = (*itr)->GetString(1);
        WDT wdt("World\\maps\\" + name + "\\" + name + ".wdt");
        if (!wdt.IsValid || wdt.IsGlobalModel)
            continue;
        printf("Building %s MapId %u\n", name, mapId);
        ContinentBuilder builder(name, mapId, &wdt);
        builder.Build();
    }
    /*
    WDT wdt("World\\maps\\DalaranPrison\\DalaranPrison.wdt");
    if (!wdt.IsValid)
        return;
    printf("Model valid!\n");
    if (wdt.IsGlobalModel)
    {
        printf("Unsupported\n");
        return;
    }
    ContinentBuilder builder("DalaranPrison", &wdt);
    builder.Build();
    */
}

int main(int argc, char* argv[])
{
    system("pause");
    Cache = new CacheClass();
    MPQHandler = new MPQManager();
    MPQHandler->Initialize();
    MPQHandler->LoadMaps();
    uint32 onlyMap = 0;
    if (argc == 2)
        onlyMap = uint32(atoi(argv[1]));
    ExtractAllMaps(onlyMap);
	return 0;
}

