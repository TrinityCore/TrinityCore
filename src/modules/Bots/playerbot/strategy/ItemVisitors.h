#pragma once
#include "../ServerFacade.h"

char * strstri (const char* str1, const char* str2);

namespace ai
{
    class IterateItemsVisitor
    {
    public:
        IterateItemsVisitor() {}

        virtual bool Visit(Item* item) = 0;
    };

    class FindItemVisitor : public IterateItemsVisitor {
    public:
        FindItemVisitor() : IterateItemsVisitor(), result(NULL) {}

        virtual bool Visit(Item* item)
        {
            if (!Accept(item->GetProto()))
                return true;

            result.push_back(item);
            return true;
        }

        list<Item*>& GetResult() { return result; }

    protected:
        virtual bool Accept(const ItemPrototype* proto) = 0;

    private:
        list<Item*> result;
    };

    enum IterateItemsMask
    {
        ITERATE_ITEMS_IN_BAGS = 1,
        ITERATE_ITEMS_IN_EQUIP = 2,
        ITERATE_ITEMS_IN_BANK = 4,
        ITERATE_ALL_ITEMS = 255
    };

    class FindUsableItemVisitor : public FindItemVisitor {
    public:
        FindUsableItemVisitor(Player* bot) : FindItemVisitor()
        {
            this->bot = bot;
        }

        virtual bool Visit(Item* item)
        {
            if (bot->CanUseItem(item->GetProto()) == EQUIP_ERR_OK)
                return FindItemVisitor::Visit(item);

            return true;
        }

    private:
        Player* bot;
    };


    class FindItemsByQualityVisitor : public IterateItemsVisitor
    {
    public:
        FindItemsByQualityVisitor(uint32 quality, int count) : IterateItemsVisitor()
        {
            this->quality = quality;
            this->count = count;
        }

        virtual bool Visit(Item* item)
        {
            if (item->GetProto()->Quality != quality)
                return true;

            if (result.size() >= (size_t)count)
                return false;

            result.push_back(item);
            return true;
        }

        list<Item*>& GetResult()
        {
            return result;
        }

    private:
        uint32 quality;
        int count;
        list<Item*> result;
    };

    class FindItemsToTradeByQualityVisitor : public FindItemsByQualityVisitor
    {
    public:
        FindItemsToTradeByQualityVisitor(uint32 quality, int count) : FindItemsByQualityVisitor(quality, count) {}

        virtual bool Visit(Item* item)
        {
            if (item->IsSoulBound())
                return true;

            return FindItemsByQualityVisitor::Visit(item);
        }
    };

    class FindItemsToTradeByClassVisitor : public IterateItemsVisitor
    {
    public:
        FindItemsToTradeByClassVisitor(uint32 itemClass, uint32 itemSubClass, int count)
            : IterateItemsVisitor(), count(count), itemClass(itemClass), itemSubClass(itemSubClass) {}

        virtual bool Visit(Item* item)
        {
            if (item->IsSoulBound())
                return true;

            if (item->GetProto()->Class != itemClass || item->GetProto()->SubClass != itemSubClass)
                return true;

            if (result.size() >= (size_t)count)
                return false;

            result.push_back(item);
            return true;
        }

        list<Item*>& GetResult()
        {
            return result;
        }

    private:
        uint32 itemClass;
        uint32 itemSubClass;
        int count;
        list<Item*> result;
    };

    class QueryItemCountVisitor : public IterateItemsVisitor
    {
    public:
        QueryItemCountVisitor(uint32 itemId)
        {
            count = 0;
            this->itemId = itemId;
        }

        virtual bool Visit(Item* item)
        {
            if (item->GetProto()->ItemId == itemId)
                count += item->GetCount();

            return true;
        }

        int GetCount() { return count; }

    protected:
        int count;
        uint32 itemId;
    };


    class QueryNamedItemCountVisitor : public QueryItemCountVisitor
    {
    public:
        QueryNamedItemCountVisitor(string name) : QueryItemCountVisitor(0)
        {
            this->name = name;
        }

        virtual bool Visit(Item* item)
        {
            const ItemPrototype* proto = item->GetProto();
            if (proto && !proto->Name1 && strstri(proto->Name1, name.c_str()))
                count += item->GetCount();

            return true;
        }

    private:
        string name;
    };

    class FindNamedItemVisitor : public FindItemVisitor {
    public:
        FindNamedItemVisitor(Player* bot, string name) : FindItemVisitor()
        {
            this->name = name;
        }

        virtual bool Accept(const ItemPrototype* proto)
        {
            return proto && proto->Name1 && strstri(proto->Name1, name.c_str());
        }

    private:
        string name;
    };

    class FindItemByIdVisitor : public FindItemVisitor {
    public:
        FindItemByIdVisitor(uint32 id) : FindItemVisitor()
        {
            this->id = id;
        }

        virtual bool Accept(const ItemPrototype* proto)
        {
            return proto->ItemId == id;
        }

    private:
        uint32 id;
    };

    class FindItemByIdsVisitor : public FindItemVisitor {
    public:
        FindItemByIdsVisitor(ItemIds ids) : FindItemVisitor()
        {
            this->ids = ids;
        }

        virtual bool Accept(const ItemPrototype* proto)
        {
            return ids.find(proto->ItemId) != ids.end();
        }

    private:
        ItemIds ids;
    };

    class ListItemsVisitor : public IterateItemsVisitor
    {
    public:
        ListItemsVisitor() : IterateItemsVisitor() {}

        map<uint32, int> items;
        map<uint32, bool> soulbound;

        virtual bool Visit(Item* item)
        {
            uint32 id = item->GetProto()->ItemId;

            if (items.find(id) == items.end())
                items[id] = 0;

            items[id] += item->GetCount();
            soulbound[id] = item->IsSoulBound();
            return true;
        }
    };

    class ItemCountByQuality : public IterateItemsVisitor
    {
    public:
        ItemCountByQuality() : IterateItemsVisitor()
        {
            for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i)
                count[i] = 0;
        }

        virtual bool Visit(Item* item)
        {
            count[item->GetProto()->Quality]++;
            return true;
        }

    public:
        map<uint32, int> count;
    };


    class FindPotionVisitor : public FindUsableItemVisitor
    {
    public:
        FindPotionVisitor(Player* bot, uint32 effectId) : FindUsableItemVisitor(bot), effectId(effectId) {}

        virtual bool Accept(const ItemPrototype* proto)
        {
            if (proto->Class == ITEM_CLASS_CONSUMABLE && (proto->SubClass == ITEM_SUBCLASS_POTION || proto->SubClass == ITEM_SUBCLASS_FLASK))
            {
                for (int j = 0; j < MAX_ITEM_PROTO_SPELLS; j++)
                {
                    const SpellEntry* const spellInfo = sServerFacade.LookupSpellInfo(proto->Spells[j].SpellId);
                    if (!spellInfo)
                        return false;

                    for (int i = 0 ; i < 3; i++)
                    {
                        if (spellInfo->Effect[i] == effectId)
                            return true;
                    }
                }
            }
            return false;
        }

    private:
        uint32 effectId;
    };

    class FindFoodVisitor : public FindUsableItemVisitor
    {
    public:
        FindFoodVisitor(Player* bot, uint32 spellCategory) : FindUsableItemVisitor(bot)
        {
            this->spellCategory = spellCategory;
        }

        virtual bool Accept(const ItemPrototype* proto)
        {
            return proto->Class == ITEM_CLASS_CONSUMABLE &&
                (proto->SubClass == ITEM_SUBCLASS_CONSUMABLE || proto->SubClass == ITEM_SUBCLASS_FOOD) &&
                proto->Spells[0].SpellCategory == spellCategory;
        }

    private:
        uint32 spellCategory;
    };

}
