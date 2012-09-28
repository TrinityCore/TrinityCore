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

void ExtractAllMaps()
{
    DBC* dbc = MPQHandler->GetDBC("Map");
    for (std::vector<Record*>::iterator itr = dbc->Records.begin(); itr != dbc->Records.end(); ++itr)
    {
        std::string name = (*itr)->GetString(1);
        WDT wdt("World\\maps\\" + name + "\\" + name + ".wdt");
        if (!wdt.IsValid || wdt.IsGlobalModel)
            continue;
        ContinentBuilder builder(name, (*itr)->Values[0], &wdt);
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
    ExtractAllMaps();
	return 0;
}

