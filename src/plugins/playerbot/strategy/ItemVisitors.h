#pragma once

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
            if (!Accept(item->GetTemplate()))
                return true;

            result.push_back(item);
            return true;
        }

        list<Item*>& GetResult() { return result; }

    protected:
        virtual bool Accept(const ItemTemplate* proto) = 0;

    private:
        list<Item*> result;
    };

    enum IterateItemsMask
    {
        ITERATE_ITEMS_IN_BAGS = 1,
        ITERATE_ITEMS_IN_EQUIP = 2,
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
            if (bot->CanUseItem(item->GetTemplate()) == EQUIP_ERR_OK)
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
            if (item->GetTemplate()->Quality != quality)
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

            if (item->GetTemplate()->Class != itemClass || item->GetTemplate()->SubClass != itemSubClass)
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
            if (item->GetTemplate()->ItemId == itemId)
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
            const ItemTemplate* proto = item->GetTemplate();
            if (proto && !proto->Name1.empty() && strstri(proto->Name1.c_str(), name.c_str()))
                count += item->GetCount();

            return true;
        }

    private:
        string name;
    };

    class FindUsableNamedItemVisitor : public FindUsableItemVisitor {
    public:
        FindUsableNamedItemVisitor(Player* bot, string name) : FindUsableItemVisitor(bot)
        {
            this->name = name;
        }

        virtual bool Accept(const ItemTemplate* proto)
        {
            return proto && !proto->Name1.empty() && strstri(proto->Name1.c_str(), name.c_str());
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

        virtual bool Accept(const ItemTemplate* proto)
        {
            return proto->ItemId == id;
        }

    private:
        uint32 id;
    };

    class ListItemsVisitor : public IterateItemsVisitor
    {
    public:
        ListItemsVisitor() : IterateItemsVisitor() {}

        map<uint32, int> items;

        virtual bool Visit(Item* item)
        {
            uint32 id = item->GetTemplate()->ItemId;

            if (items.find(id) == items.end())
                items[id] = 0;

            items[id] += item->GetCount();
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
            count[item->GetTemplate()->Quality]++;
            return true;
        }

    public:
        map<uint32, int> count;
    };
}
