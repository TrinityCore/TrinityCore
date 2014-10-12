#pragma once

#include "../Action.h"
#include "../../LootObjectStack.h"
#include "MovementActions.h"

namespace ai
{
    class LootAction : public MovementAction
    {
    public:
        LootAction(PlayerbotAI* ai) : MovementAction(ai, "loot") {}
        virtual bool Execute(Event event);
    };

    class OpenLootAction : public MovementAction
    {
    public:
        OpenLootAction(PlayerbotAI* ai) : MovementAction(ai, "open loot") {}
        virtual bool Execute(Event event);

    private:
        bool DoLoot(LootObject& lootObject);
        uint32 GetOpeningSpell(LootObject& lootObject);
        uint32 GetOpeningSpell(LootObject& lootObject, GameObject* go);
        bool CanOpenLock(LootObject& lootObject, const SpellInfo* pSpellInfo, GameObject* go);
        bool CanOpenLock(uint32 skillId, uint32 reqSkillValue);
    };

    class StoreLootAction : public MovementAction
    {
    public:
        StoreLootAction(PlayerbotAI* ai) : MovementAction(ai, "store loot") {}
        virtual bool Execute(Event event);

    protected:
        bool IsLootAllowed(uint32 itemid);
    };
}
