#ifndef _PlayerbotCommandServer_H
#define _PlayerbotCommandServer_H

#include "Common.h"
#include "PlayerbotAIBase.h"
#include "PlayerbotMgr.h"

using namespace std;

class PlayerbotCommandServer
{
public:
    PlayerbotCommandServer() {}
    virtual ~PlayerbotCommandServer() {}
    static PlayerbotCommandServer& instance()
    {
        static PlayerbotCommandServer instance;
        return instance;
    }

    void Start();
};

#define sPlayerbotCommandServer PlayerbotCommandServer::instance()

#endif
