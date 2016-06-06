#ifndef _RandomItemMgr_H
#define _RandomItemMgr_H

#include "Common.h"
#include "PlayerbotAIBase.h"

using namespace std;

enum RandomItemType
{
    RANDOM_ITEM_GUILD_TASK,
    RANDOM_ITEM_GUILD_TASK_REWARD
};

class RandomItemPredicate
{
public:
    virtual bool Apply(ItemTemplate const* proto) = 0;
};

typedef vector<uint32> RandomItemList;
typedef map<RandomItemType, RandomItemList> RandomItemCache;

class RandomItemMgr
{
    public:
        RandomItemMgr();
        virtual ~RandomItemMgr();
        static RandomItemMgr& instance()
        {
            static RandomItemMgr instance;
            return instance;
        }

	public:
        static bool HandleConsoleCommand(ChatHandler* handler, char const* args);
        RandomItemList Query(RandomItemType type, RandomItemPredicate* predicate);
        uint32 GetRandomItem(RandomItemType type, RandomItemPredicate* predicate = NULL);

    private:
        RandomItemList Query(RandomItemType type);

    private:
        RandomItemCache cache;
        map<RandomItemType, RandomItemPredicate*> predicates;
};

#define sRandomItemMgr RandomItemMgr::instance()

#endif
