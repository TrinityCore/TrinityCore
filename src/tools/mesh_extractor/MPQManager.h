#ifndef MPQ_MANAGER_H
#define MPQ_MANAGER_H

#include "MPQ.h"

class DBC;
class MPQManager
{
public:
    MPQManager() {}
    ~MPQManager() {}
    
    void Initialize();
    void LoadMaps();
    FILE* GetFile(std::string path);
    DBC* GetDBC(std::string name);

    std::deque<MPQArchive*> Archives;
    uint32 CurLocale;

    static char* Files[];
    static char* Languages[];
protected:
    void InitializeDBC();
};

extern MPQManager* MPQHandler;
#endif