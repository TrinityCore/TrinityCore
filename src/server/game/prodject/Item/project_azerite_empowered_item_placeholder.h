#ifndef PROJECT_EMPOWERED_AZERITE_ITEM_PLACEHOLDER
#define PROJECT_EMPOWERED_AZERITE_ITEM_PLACEHOLDER

#ifdef PROJECT_CUSTOM
#include "project_azerite_empowered_item.h"
#else

#include "Common.h"
#include "Item.h"

#define AZERITE_POWER_MAX_TIER 4

namespace PROJECT
{
namespace AzeriteEmpoweredItem
{
class TC_GAME_API Manager : public Item
{
public:
    Manager() : Item() {};
    ~Manager() {};

    void LoadAzeriteEmpowered(Player* player, PreparedQueryResult result) {};
    void SetContext() {};
};
}
}

#endif
#endif
