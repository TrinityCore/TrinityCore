#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "BuffAction.h"

#include "../values/ItemCountValue.h"

using namespace ai;

class FindBuffVisitor : public IterateItemsVisitor {
public:
    FindBuffVisitor(Player* bot) : IterateItemsVisitor(), bot(bot)
    {
    }

    virtual bool Visit(Item* item)
    {
        if (bot->CanUseItem(item->GetTemplate()) != EQUIP_ERR_OK)
            return true;

        const ItemTemplate* proto = item->GetTemplate();

        if (proto->Class != ITEM_CLASS_CONSUMABLE)
            return true;

        if (proto->SubClass != ITEM_SUBCLASS_ELIXIR && 
            proto->SubClass != ITEM_SUBCLASS_FLASK &&
            proto->SubClass != ITEM_SUBCLASS_SCROLL && 
            proto->SubClass != ITEM_SUBCLASS_FOOD &&
            proto->SubClass != ITEM_SUBCLASS_CONSUMABLE_OTHER &&
            proto->SubClass != ITEM_SUBCLASS_ITEM_ENHANCEMENT)
            return true;

        for (int i=0; i<MAX_ITEM_PROTO_SPELLS; i++)
        {
            uint32 spellId = proto->Spells[i].SpellId;
            if (!spellId)
                continue;

            if (bot->HasAura(spellId))
                return true;

            Item* itemForSpell = *bot->GetPlayerbotAI()->GetAiObjectContext()->GetValue<Item*>("item for spell", spellId);
            if (itemForSpell && itemForSpell->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
                return true;
        
            if (items.find(proto->SubClass) == items.end())
                items[proto->SubClass] = list<Item*>();

            items[proto->SubClass].push_back(item);
            break;
        }

        return true;
    }

public:
    map<uint32, list<Item*> > items;

private:
    Player* bot;
};

void BuffAction::TellHeader(uint32 subClass)
{
    switch (subClass)
    {
    case ITEM_SUBCLASS_ELIXIR:
        ai->TellMaster("--- Elixir ---");
        return;
    case ITEM_SUBCLASS_FLASK:
        ai->TellMaster("--- Flask ---");
        return;
    case ITEM_SUBCLASS_SCROLL:
        ai->TellMaster("--- Scroll ---");
        return;
    case ITEM_SUBCLASS_FOOD:
        ai->TellMaster("--- Food ---");
        return;
    case ITEM_SUBCLASS_GENERIC:
        ai->TellMaster("--- Other ---");
        return;
    case ITEM_SUBCLASS_ITEM_ENHANCEMENT:
        ai->TellMaster("--- Enchant ---");
        return;
    }
}


bool BuffAction::Execute(Event event)
{
    string text = event.getParam();

    FindBuffVisitor visitor(bot);
    IterateItems(&visitor);

    uint32 oldSubClass = -1;
    for (map<uint32, list<Item*> >::iterator i = visitor.items.begin(); i != visitor.items.end(); ++i)
    {
        list<Item*> items = i->second;

        uint32 subClass = i->first;
        if (oldSubClass != subClass)
        {
            if (!items.empty())
                TellHeader(subClass);
            oldSubClass = subClass;
        }
        for (list<Item*>::iterator j = items.begin(); j != items.end(); ++j)
        {
            Item* item = *j;
            ostringstream out;
            out << chat->formatItem(item->GetTemplate(), item->GetCount());
            ai->TellMaster(out);
        }
    }
    
    return true;
}
