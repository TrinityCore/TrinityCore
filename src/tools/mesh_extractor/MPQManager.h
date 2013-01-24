#ifndef MPQ_MANAGER_H
#define MPQ_MANAGER_H

#include "MPQ.h"
#include <ace/Synch.h>
#include <set>
#include <map>

class DBC;
class MPQManager
{
public:
    MPQManager() {}
    ~MPQManager() {}

    void Initialize();
    FILE* GetFile(std::string path);
    FILE* GetFileFrom(std::string path, MPQArchive* file);
    DBC* GetDBC(std::string name);
    std::vector<std::string> GetAllFiles(std::string extension);

    std::deque<MPQArchive*> Archives;
    int32 BaseLocale;
    std::set<uint32> AvailableLocales;
    std::map<uint32, MPQArchive*> LocaleFiles;

    static char const* Files[];
    static char const* Languages[];
protected:
    void InitializeDBC();
private:
    ACE_Thread_Mutex mutex;
};

extern MPQManager* MPQHandler;
#endif