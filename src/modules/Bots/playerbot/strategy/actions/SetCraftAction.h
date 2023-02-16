#pragma once

#include "../Action.h"
#include "../values/CraftValue.h"

namespace ai
{
    class SetCraftAction : public Action {
    public:
        SetCraftAction(PlayerbotAI* ai) : Action(ai, "craft") {}
        virtual bool Execute(Event event);

    public:
        static uint32 GetCraftFee(CraftData&);

    private:
        void TellCraft();

    private:
        static map<uint32, SkillLineAbilityEntry const*> skillSpells;

    };

}
