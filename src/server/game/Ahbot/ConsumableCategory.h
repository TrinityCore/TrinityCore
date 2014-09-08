#pragma once
#include "Category.h"

using namespace std;

namespace ahbot
{
    class Alchemy : public Consumable
    {
    public:
        Alchemy() : Consumable() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Consumable::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_POTION ||
                    proto->SubClass == ITEM_SUBCLASS_ELIXIR ||
                    proto->SubClass == ITEM_SUBCLASS_FLASK);
        }

        virtual string GetName() { return "Alchemy"; }
    };

    class Scroll : public Consumable
    {
    public:
        Scroll() : Consumable() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Consumable::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_SCROLL ||
                    proto->SubClass == ITEM_SUBCLASS_ITEM_ENHANCEMENT);
        }

        virtual string GetName() { return "Scroll"; }
    };

    class Food : public Consumable
    {
    public:
        Food() : Consumable() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Consumable::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_FOOD;
        }

        virtual string GetName() { return "Food"; }
    };

    class Bandage : public Consumable
    {
    public:
        Bandage() : Consumable() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Consumable::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_BANDAGE;
        }

        virtual string GetName() { return "Bandage"; }
    };

    class OtherConsumable : public Consumable
    {
    public:
        OtherConsumable() : Consumable() {}

    public:
        virtual bool Contains(ItemTemplate const* proto)
        {
            return Consumable::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_CONSUMABLE ||
                    proto->SubClass == ITEM_SUBCLASS_CONSUMABLE_OTHER) && (proto->RequiredSkill || proto->Flags & ITEM_FLAG_UNK6);
        }

        virtual string GetName() { return "OtherConsumable"; }
    };
};
