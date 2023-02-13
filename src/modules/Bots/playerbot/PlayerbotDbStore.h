#ifndef _PlayerbotDbStore_H
#define _PlayerbotDbStore_H

#include "Common.h"
#include "PlayerbotAIBase.h"
#include "PlayerbotMgr.h"

using namespace std;

class PlayerbotDbStore
{
public:
    PlayerbotDbStore() {}
    virtual ~PlayerbotDbStore() {}
    static PlayerbotDbStore& instance()
    {
        static PlayerbotDbStore instance;
        return instance;
    }

    void Save(PlayerbotAI *ai);
    void Load(PlayerbotAI *ai);
    void Reset(PlayerbotAI *ai);

private:
    void SaveValue(uint64 guid, string key, string value);
    string FormatStrategies(string type, list<string> strategies);
};

#define sPlayerbotDbStore PlayerbotDbStore::instance()

#endif
