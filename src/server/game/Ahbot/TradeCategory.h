#pragma once
#include "Category.h"

using namespace std;

namespace ahbot
{
    class Cloth : public Trade
    {
    public:
        Cloth() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_CLOTH;
        }

        virtual string GetName() { return "Cloth"; }
    };

    class Leather : public Trade
    {
    public:
        Leather() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_LEATHER;
        }

        virtual string GetName() { return "Leather"; }
    };

    class Elemental : public Trade
    {
    public:
        Elemental() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                proto->SubClass == ITEM_SUBCLASS_ELEMENTAL;
        }

        virtual string GetName() { return "Elemental"; }
    };

    class Herb : public Trade
    {
    public:
        Herb() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_HERB;
        }

        virtual string GetName() { return "Herb"; }
    };

    class Meat : public Trade
    {
    public:
        Meat() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_MEAT;
        }

        virtual string GetName() { return "Meat"; }
    };

    class Metal : public Trade
    {
    public:
        Metal() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_METAL_STONE;
        }

        virtual string GetName() { return "Metal"; }
    };

    class Disenchants : public Trade
    {
    public:
        Disenchants() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_ENCHANTING;
        }

        virtual string GetName() { return "Disenchants"; }
    };

    class SimpleGems : public Trade
    {
    public:
        SimpleGems() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_GEM && proto->SubClass == ITEM_SUBCLASS_GEM_SIMPLE;
        }

        virtual string GetName() { return "SimpleGems"; }
    };

    class SocketGems : public Trade
    {
    public:
        SocketGems() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return proto->Class == ITEM_CLASS_GEM && proto->SubClass != ITEM_SUBCLASS_GEM_SIMPLE;
        }

        virtual string GetName() { return "SocketGems"; }
    };

    class Engineering : public Trade
    {
    public:
        Engineering() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_PARTS ||
                    proto->SubClass == ITEM_SUBCLASS_DEVICES ||
                    proto->SubClass == ITEM_SUBCLASS_MATERIAL ||
                    proto->SubClass == ITEM_SUBCLASS_EXPLOSIVES);
        }

        virtual string GetName() { return "Engineering"; }
    };

    class OtherTrade : public Trade
    {
    public:
        OtherTrade() : Trade() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Trade::Contains(proto) &&
                    proto->SubClass != ITEM_SUBCLASS_PARTS &&
                    proto->SubClass != ITEM_SUBCLASS_DEVICES &&
                    proto->SubClass != ITEM_SUBCLASS_MATERIAL &&
                    proto->SubClass != ITEM_SUBCLASS_EXPLOSIVES &&
                    proto->SubClass != ITEM_SUBCLASS_ENCHANTING &&
                    proto->SubClass != ITEM_SUBCLASS_JEWELCRAFTING &&
                    proto->SubClass != ITEM_SUBCLASS_METAL_STONE &&
                    proto->SubClass != ITEM_SUBCLASS_MEAT &&
                    proto->SubClass != ITEM_SUBCLASS_HERB &&
                    proto->SubClass != ITEM_SUBCLASS_LEATHER &&
                    proto->SubClass != ITEM_SUBCLASS_CLOTH;
        }

        virtual string GetName() { return "OtherTrade"; }
    };
};
