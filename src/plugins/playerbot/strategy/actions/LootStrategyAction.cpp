#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LootStrategyAction.h"


using namespace ai;


bool LootStrategyAction::Execute(Event event)
{
    string strategy = event.getParam();

    LootObjectStack* lootItems = AI_VALUE(LootObjectStack*, "available loot");
    set<uint32>& alwaysLootItems = AI_VALUE(set<uint32>&, "always loot list");
    Value<LootStrategy>* lootStrategy = context->GetValue<LootStrategy>("loot strategy");

    if (strategy == "?")
    {
        ostringstream out;
        out << "Loot strategy: ";
        out << LootStrategy2string(lootStrategy->Get());
        out << ", always loot items: ";

        for (set<uint32>::iterator i = alwaysLootItems.begin(); i != alwaysLootItems.end(); i++)
        {
            ItemTemplate const *proto = sObjectMgr->GetItemTemplate(*i);
            if (!proto)
                continue;

            out << chat->formatItem(proto);
        }
        ai->TellMaster(out);
    }
    else
    {
        ItemIds items = chat->parseItems(strategy);

        if (items.size() == 0)
        {
            lootStrategy->Set(String2LootStrategy(strategy));
            ostringstream out;
            out << "Loot strategy set to " << LootStrategy2string(lootStrategy->Get());
            ai->TellMaster(out);
            return true;
        }

        bool remove = strategy.size() > 1 && strategy.substr(0, 1) == "-";
        for (ItemIds::iterator i = items.begin(); i != items.end(); i++)
        {
            uint32 itemid = *i;
            if (remove)
            {
                set<uint32>::iterator j = alwaysLootItems.find(itemid);
                if (j != alwaysLootItems.end())
                    alwaysLootItems.erase(j);

                ai->TellMaster("Item(s) removed from always loot list");
            }
            else
            {
                alwaysLootItems.insert(itemid);
                ai->TellMaster("Item(s) added to always loot list");
            }
        }
    }

    return true;
}


LootStrategy LootStrategyAction::String2LootStrategy(string strategy)
{
    if (strategy == "*" || strategy == "all")
        return LOOTSTRATEGY_ALL;
    else if (strategy == "q" || strategy == "quest")
        return LOOTSTRATEGY_QUEST;
    else if (strategy == "s" || strategy == "skill")
        return LOOTSTRATEGY_SKILL;
    else if (strategy == "g" || strategy == "gray")
        return LOOTSTRATEGY_GRAY;
    else
        return LOOTSTRATEGY_NORMAL;
}

string LootStrategyAction::LootStrategy2string(LootStrategy lootStrategy)
{
    switch (lootStrategy)
    {
    case LOOTSTRATEGY_ALL:
        return "all";
    case LOOTSTRATEGY_QUEST:
        return "quest";
    case LOOTSTRATEGY_SKILL:
        return "skill";
    case LOOTSTRATEGY_GRAY:
        return "gray";
    default:
        return "normal";
    }
}
