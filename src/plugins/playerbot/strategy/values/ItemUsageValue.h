#pragma once
#include "../Value.h"

namespace ai
{
    enum ItemUsage
    {
        ITEM_USAGE_NONE,
        ITEM_USAGE_EQUIP,
        ITEM_USAGE_REPLACE,
        ITEM_USAGE_SKILL,
        ITEM_USAGE_USE
    };

    class ItemUsageValue : public CalculatedValue<ItemUsage>, public Qualified
	{
	public:
        ItemUsageValue(PlayerbotAI* ai) : CalculatedValue<ItemUsage>(ai) {}

    public:
        virtual ItemUsage Calculate();

    private:
        ItemUsage QueryItemUsageForEquip(ItemTemplate const * proto);
        bool IsItemUsefulForSkill(ItemTemplate const * proto);
	};
}
