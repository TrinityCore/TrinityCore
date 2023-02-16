#include "botpch.h"
#include "../../playerbot.h"
#include "LootStrategyValue.h"
#include "../values/ItemUsageValue.h"

using namespace ai;
using namespace std;

namespace ai
{
    class NormalLootStrategy : public LootStrategy
    {
    public:
        virtual bool CanLoot(ItemPrototype const *proto, AiObjectContext *context)
        {
            ostringstream out; out << proto->ItemId;
            ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());
            return usage != ITEM_USAGE_NONE;
        }
        virtual string GetName() { return "normal"; }
    };

    class GrayLootStrategy : public NormalLootStrategy
    {
    public:
        virtual bool CanLoot(ItemPrototype const *proto, AiObjectContext *context)
        {
            return NormalLootStrategy::CanLoot(proto, context) || proto->Quality == ITEM_QUALITY_POOR;
        }
        virtual string GetName() { return "gray"; }
    };

    class DisenchantLootStrategy : public NormalLootStrategy
    {
    public:
        virtual bool CanLoot(ItemPrototype const *proto, AiObjectContext *context)
        {
            return NormalLootStrategy::CanLoot(proto, context) ||
                    (proto->Quality >= ITEM_QUALITY_UNCOMMON && proto->Bonding != BIND_WHEN_PICKED_UP &&
                    (proto->Class == ITEM_CLASS_ARMOR || proto->Class == ITEM_CLASS_WEAPON));
        }
        virtual string GetName() { return "disenchant"; }
    };

    class AllLootStrategy : public LootStrategy
    {
    public:
        virtual bool CanLoot(ItemPrototype const *proto, AiObjectContext *context)
        {
            return true;
        }
        virtual string GetName() { return "all"; }
    };
}

LootStrategy *LootStrategyValue::normal = new NormalLootStrategy();
LootStrategy *LootStrategyValue::gray = new GrayLootStrategy();
LootStrategy *LootStrategyValue::disenchant = new DisenchantLootStrategy();
LootStrategy *LootStrategyValue::all = new AllLootStrategy();

LootStrategy* LootStrategyValue::instance(string strategy)
{
    if (strategy == "*" || strategy == "all")
        return all;

    if (strategy == "g" || strategy == "gray")
        return gray;

    if (strategy == "d" || strategy == "e" || strategy == "disenchant" || strategy == "enchant")
        return disenchant;

    return normal;
}
