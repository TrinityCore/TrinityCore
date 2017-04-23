#pragma once
#include "PricingStrategy.h"
#include "../Entities/Item/ItemTemplate.h"

using namespace std;

namespace ahbot
{
    class Category
    {
    public:
        Category() : pricingStrategy(NULL) {}
        virtual ~Category() { if (pricingStrategy) delete pricingStrategy; }

    public:
        virtual bool Contains(ItemTemplate const* proto) { return false; }
        virtual string GetName() { return "default"; }
        virtual string GetDisplayName() { return GetName(); }

        virtual uint32 GetMaxAllowedAuctionCount();
        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto);
        virtual uint32 GetStackCount(ItemTemplate const* proto);

        virtual PricingStrategy* GetPricingStrategy();

    private:
        PricingStrategy *pricingStrategy;
    };

    class Consumable : public Category
    {
    public:
        Consumable() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_CONSUMABLE;
        }

        virtual string GetName() { return "consumable"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 10;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            if (proto->Quality > ITEM_QUALITY_UNCOMMON)
                return 1;

            uint32 maxStackSize = proto->GetMaxStackSize();
            if (maxStackSize == 1)
                return 1;

            if (maxStackSize <= 10)
                return urand(1, 10);

            return urand(1, 4) * maxStackSize / 5;
        }
    };

    class Quest : public Category
    {
    public:
        Quest() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_QUEST;
        }
        virtual string GetName() { return "quest"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 5;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            if (proto->Quality > ITEM_QUALITY_UNCOMMON)
                return 1;

            uint32 maxStackSize = proto->GetMaxStackSize();
            if (proto->Quality == ITEM_QUALITY_UNCOMMON && maxStackSize > 10)
                maxStackSize = urand(1, 10);

            if (maxStackSize > 20)
                maxStackSize = urand(1, 20);

            return maxStackSize;
        }
    };

    class Trade : public Category
    {
    public:
        Trade() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_TRADE_GOODS;
        }
        virtual string GetName() { return "trade"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 5;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            uint32 maxStack = proto->GetMaxStackSize();
            if (maxStack < 2)
                return maxStack;

            switch (proto->Quality)
            {
            case ITEM_QUALITY_NORMAL:
                return maxStack;
            case ITEM_QUALITY_UNCOMMON:
                return urand(1, maxStack);
            }

            return 1;
        }
    };

    class Enchant : public Category
    {
    public:
        Enchant() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_PERMANENT && proto->ItemLevel > 1;
        }
        virtual string GetName() { return "enchant"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 5;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class Reagent : public Category
    {
    public:
        Reagent() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_REAGENT && proto->ItemLevel > 1;
        }
        virtual string GetName() { return "reagent"; }
    };

    class Recipe : public Category
    {
    public:
        Recipe() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_RECIPE && proto->ItemLevel > 1;
        }
        virtual string GetName() { return "recipe"; }
        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 1;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class Equip : public Category
    {
    public:
        Equip() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return (proto->Class == ITEM_CLASS_WEAPON ||
                proto->Class == ITEM_CLASS_ARMOR) && proto->ItemLevel > 1;
        }
        virtual string GetName() { return "equip"; }
        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 1;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class Other : public Category
    {
    public:
        Other() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Quality > ITEM_QUALITY_POOR && (
                proto->Class == ITEM_CLASS_MISC ||
                proto->Class == ITEM_CLASS_GENERIC ||
                proto->Class == ITEM_CLASS_MONEY) && proto->ItemLevel > 1 && proto->SubClass != ITEM_SUBCLASS_JUNK_MOUNT;
        }
        virtual string GetName() { return "other"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 1;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class Quiver : public Category
    {
    public:
        Quiver() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_QUIVER && proto->ItemLevel > 1;
        }

        virtual string GetName() { return "quiver"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 1;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class Projectile : public Category
    {
    public:
        Projectile() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_PROJECTILE;
        }

        virtual string GetName() { return "projectile"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 5;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return proto->GetMaxStackSize();
        }
    };

    class Container : public Category
    {
    public:
        Container() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_CONTAINER && proto->ItemLevel > 1;
        }

        virtual string GetName() { return "container"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 1;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class Glyph : public Category
    {
    public:
        Glyph() : Category() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_GLYPH;
        }

        virtual string GetName() { return "glyph"; }

        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
        {
            return 1;
        }

        virtual uint32 GetStackCount(ItemTemplate const* proto)
        {
            return 1;
        }
    };

    class QualityCategoryWrapper : public Category
    {
    public:
        QualityCategoryWrapper(Category* category, uint32 quality);

    public:
        virtual bool Contains(ItemTemplate const* proto);
        virtual uint32 GetMaxAllowedAuctionCount();
        virtual string GetName() { return category->GetName(); }
        virtual string GetDisplayName() { return combinedName; }
        virtual uint32 GetMaxAllowedItemAuctionCount(ItemTemplate const* proto);
        virtual uint32 GetStackCount(ItemTemplate const* proto) { return category->GetStackCount(proto); }
        virtual PricingStrategy* GetPricingStrategy() { return category->GetPricingStrategy(); }

    private:
        uint32 quality;
        Category* category;
        string combinedName;
    };
};
