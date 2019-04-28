#ifndef PROJECT_AZERITE_ITEM_PLACEHOLDER
#define PROJECT_AZERITE_ITEM_PLACEHOLDER

#ifdef PROJECT_CUSTOM
#include "project_azerite_item.h"
#else

#include "Common.h"
#include "Item.h"

namespace PROJECT
{
namespace AzeriteItem
{

class TC_GAME_API Manager : public Item
{
public:
    Manager() : Item() {};
    ~Manager() {};

    void GiveXP(uint64 value) {};

    void LoadAzeriteData(PreparedQueryResult result) {};
};

}
}

#endif
#endif
