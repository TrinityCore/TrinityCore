#pragma once
#include "Category.h"

namespace ahbot
{
    using namespace std;

    class CategoryList
    {
    public:
        CategoryList();
        virtual ~CategoryList();

        Category* operator[](int index) { return categories[index]; }
        int32 size() { return categories.size(); }
        static CategoryList instance;

    private:
        void Add(Category* category);

    private:
        vector<Category*> categories;
    };

    template<class T>
    void Shuffle(vector<T>& items) 
    {
        uint32 count = items.size();
        for (uint32 i = 0; i < count * 5; i++)
        {
            int i1 = urand(0, count - 1);
            int i2 = urand(0, count - 1);

            T item = items[i1];
            items[i1] = items[i2];
            items[i2] = item;
        }
    }

    class ItemBag 
    {
    public:
        ItemBag();

    public:
        void Init(bool silent = false);
        vector<uint32>& Get(Category* category) { return content[category]; }
        int32 GetCount(Category* category) { return content[category].size(); }
        int32 GetCount(Category* category, uint32 item);
        bool Add(ItemPrototype const* proto);

    protected:
        virtual void Load() = 0;
        virtual string GetName() = 0;

    protected:
        map<Category*,vector<uint32> > content;
    };

    class AvailableItemsBag : public ItemBag
    {
    public:
        AvailableItemsBag() {}

    protected:
        virtual void Load();
        virtual string GetName() { return "available"; }
    };

    class InAuctionItemsBag : public ItemBag
    {
    public:
        InAuctionItemsBag(uint32 auctionId) : auctionId(auctionId) {}

    protected:
        virtual void Load();
        virtual string GetName();

    private:
        uint32 auctionId;
    };
};
