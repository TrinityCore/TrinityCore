#ifndef MPQ_MANAGER_H
#define MPQ_MANAGER_H

#include "MPQ.h"
#include "Stream.h"
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
    Stream* GetFile(const std::string& path);
    Stream* GetFileFrom(const std::string& path, MPQArchive* file);
    Stream* GetFileFromLocale(const std::string& path, uint32 locale);

    DBC* GetDBC(const std::string& name);
    std::vector<std::string> GetAllFiles(std::string extension);

    std::deque<MPQArchive*> Archives;
    int32 BaseLocale;
    std::set<uint32> AvailableLocales;
    std::map<uint32, std::deque<MPQArchive*> > LocaleFiles;

    static char const* Files[];
    static char const* LocalePatchFiles[];
    static char const* Languages[];
protected:
    void InitializeDBC();
private:
    ACE_Thread_Mutex mutex;
};

extern MPQManager* MPQHandler;
#endif