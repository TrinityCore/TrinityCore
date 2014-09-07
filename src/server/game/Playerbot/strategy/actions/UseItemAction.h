#pragma once

#include "../Action.h"

namespace ai
{
	class UseItemAction : public Action {
	public:
		UseItemAction(PlayerbotAI* ai, string name = "use", bool selfOnly = false) : Action(ai, name), selfOnly(selfOnly) {}

    public:
        virtual bool Execute(Event event);
        virtual bool isPossible();

    private:
        bool UseItemAuto(Item* item);
        bool UseItemOnGameObject(Item* item, ObjectGuid go);
        bool UseItemOnItem(Item* item, Item* itemTarget);
        bool UseItem(Item* item, ObjectGuid go, Item* itemTarget);
        bool UseGameObject(ObjectGuid guid);
        bool SocketItem(Item* item, Item* gem, bool replace = false);

    private:
        bool selfOnly;
    };

    class UseSpellItemAction : public UseItemAction {
    public:
        UseSpellItemAction(PlayerbotAI* ai, string name, bool selfOnly = false) : UseItemAction(ai, name, selfOnly) {}

    public:
        virtual bool isUseful();
    };

    class UseHealingPotion : public UseItemAction {
    public:
        UseHealingPotion(PlayerbotAI* ai) : UseItemAction(ai, "healing potion") {}
        virtual bool isUseful() { return AI_VALUE2(bool, "combat", "self target"); }
    };

    class UseManaPotion : public UseItemAction
    {
    public:
        UseManaPotion(PlayerbotAI* ai) : UseItemAction(ai, "mana potion") {}
        virtual bool isUseful() { return AI_VALUE2(bool, "combat", "self target"); }
    };
}
