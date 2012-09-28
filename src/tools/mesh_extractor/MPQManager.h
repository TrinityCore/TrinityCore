#ifndef MPQ_MANAGER_H
#define MPQ_MANAGER_H

#include "MPQ.h"

class MPQManager
{
public:
    MPQManager() {}
    ~MPQManager() {}
    
    void Initialize();
    void LoadMaps();
    FILE* GetFile(std::string path);

    std::deque<MPQArchive*> Archives;

    static char* Files[];
protected:
    void LoadMPQs();
};

extern MPQManager* MPQHandler;
#endif