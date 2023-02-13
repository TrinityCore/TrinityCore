#pragma once
#include "Config/Config.h"
#include "Category.h"

using namespace std;

namespace ahbot
{
    class Alchemy : public Consumable
    {
    public:
        Alchemy() : Consumable() {}

    public:
        virtual bool Contains(ItemPrototype const* proto)
        {
            return Consumable::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_POTION ||
                    proto->SubClass == ITEM_SUBCLASS_ELIXIR ||
                    proto->SubClass == ITEM_SUBCLASS_FLASK);
        }

        virtual string GetName() { return "consumables.alchemy"; }
        virtual string GetLabel() { return "elixirs and potions"; }
    };

    class Scroll : public Consumable
    {
    public:
        Scroll() : Consumable() {}

    public:
        virtual bool Contains(ItemPrototype const* proto)
        {
            return Consumable::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_SCROLL ||
                    proto->SubClass == ITEM_SUBCLASS_ITEM_ENHANCEMENT);
        }

        virtual string GetName() { return "consumables.scroll"; }
        virtual string GetLabel() { return "scrolls"; }
    };

    class Food : public Consumable
    {
    public:
        Food() : Consumable() {}

    public:
        virtual bool Contains(ItemPrototype const* proto)
        {
            return Consumable::Contains(proto) &&
                    (proto->SubClass == ITEM_SUBCLASS_FOOD
#ifdef MANGOSBOT_ZERO
                    || proto->SubClass == ITEM_SUBCLASS_CONSUMABLE
#endif
                    );
        }

        virtual string GetName() { return "consumables.food"; }
        virtual string GetLabel() { return "food and drink"; }
    };

    class Bandage : public Consumable
    {
    public:
        Bandage() : Consumable() {}

    public:
        virtual bool Contains(ItemPrototype const* proto)
        {
            return Consumable::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_BANDAGE;
        }

        virtual string GetName() { return "consumables.bandage"; }
        virtual string GetLabel() { return "bandages"; }
    };

    class ItemEnchant : public Consumable
    {
    public:
        ItemEnchant() : Consumable() {}

    public:
        virtual bool Contains(ItemPrototype const* proto)
        {
            return Consumable::Contains(proto) &&
                    proto->SubClass == ITEM_SUBCLASS_CONSUMABLE_OTHER;
        }

        virtual string GetName() { return "consumables.enchant"; }
        virtual string GetLabel() { return "item enchants"; }
    };
};
