#include "botpch.h"
#include "../../playerbot.h"
#include "LootStrategyAction.h"
#include "../values/LootStrategyValue.h"
#include "LootAction.h"

using namespace ai;


bool LootStrategyAction::Execute(Event event)
{
    string strategy = event.getParam();

    LootObjectStack* lootItems = AI_VALUE(LootObjectStack*, "available loot");
    set<uint32>& alwaysLootItems = AI_VALUE(set<uint32>&, "always loot list");
    Value<LootStrategy*>* lootStrategy = context->GetValue<LootStrategy*>("loot strategy");

    if (strategy == "?")
    {
        {
            ostringstream out;
            out << "Loot strategy: ";
            out << lootStrategy->Get()->GetName();
            ai->TellMaster(out);
        }

        {
            ostringstream out;
            out << "Always loot items: ";

            for (set<uint32>::iterator i = alwaysLootItems.begin(); i != alwaysLootItems.end(); i++)
            {
                ItemPrototype const *proto = sItemStorage.LookupEntry<ItemPrototype>(*i);
                if (!proto)
                    continue;

                out << chat->formatItem(proto);
            }
            ai->TellMaster(out);
        }
    }
    else
    {
        ItemIds items = chat->parseItems(strategy);

        if (items.size() == 0)
        {
            lootStrategy->Set(LootStrategyValue::instance(strategy));
            ostringstream out;
            out << "Loot strategy set to " << lootStrategy->Get()->GetName();
            ai->TellMaster(out);
            return true;
        }

        bool remove = strategy.size() > 1 && strategy.substr(0, 1) == "-";
        bool query = strategy.size() > 1 && strategy.substr(0, 1) == "?";
        for (ItemIds::iterator i = items.begin(); i != items.end(); i++)
        {
            uint32 itemid = *i;
            if (query)
            {
                ItemPrototype const *proto = sObjectMgr.GetItemPrototype(itemid);
                if (proto)
                {
                    ostringstream out;
                    out << (StoreLootAction::IsLootAllowed(itemid, ai) ? "|cFF000000Will loot " : "|c00FF0000Won't loot ") << ChatHelper::formatItem(proto);
                    ai->TellMaster(out.str());
                }
            }
            else if (remove)
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

