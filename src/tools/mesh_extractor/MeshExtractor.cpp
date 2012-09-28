#include "MPQManager.h"
#include "WDT.h"
#include "ContinentBuilder.h"
#include "Cache.h"

#include "Common.h"
#include "LoginDatabase.h"
LoginDatabaseWorkerPool LoginDatabase;

MPQManager* MPQHandler;
CacheClass* Cache;

void ExtractAllMaps()
{
    WDT wdt("World\\maps\\DalaranPrison\\DalaranPrison.wdt");
    if (!wdt.IsValid)
        return;
    printf("Model valid!");
    if (wdt.IsGlobalModel)
    {
        printf("Unsupported");
        return;
    }
    ContinentBuilder builder("DalaranPrison", &wdt);
    builder.Build();
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

