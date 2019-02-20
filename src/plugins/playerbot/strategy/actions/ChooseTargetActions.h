#pragma once

#include "../Action.h"
#include "AttackAction.h"
#include "../../../DungeonFinding/LFGMgr.h"

namespace ai
{
    class DpsAssistAction : public AttackAction
    {
    public:
        DpsAssistAction(PlayerbotAI* ai) : AttackAction(ai, "dps assist") {}

        virtual string GetTargetName() { return "dps target"; }
    };

    class TankAssistAction : public AttackAction
    {
    public:
        TankAssistAction(PlayerbotAI* ai) : AttackAction(ai, "tank assist") {}
        virtual string GetTargetName() { return "tank target"; }
    };

    class AttackAnythingAction : public AttackAction
    {
    public:
        AttackAnythingAction(PlayerbotAI* ai) : AttackAction(ai, "attack anything") {}
        virtual string GetTargetName() { return "grind target"; }
        virtual bool Execute(Event event)
        {
            return AttackAction::Execute(event);
        }
        virtual bool isUseful() {
            return GetTarget() &&
                (AI_VALUE2(uint8, "health", "self target") > sPlayerbotAIConfig.mediumHealth &&
                (!AI_VALUE2(uint8, "mana", "self target") || AI_VALUE2(uint8, "mana", "self target") > sPlayerbotAIConfig.mediumMana)) || AI_VALUE2(bool, "combat", "self target");
        }
        virtual bool isPossible()
        {
            return AttackAction::isPossible() && GetTarget();
        }
    };

    class AttackLeastHpTargetAction : public AttackAction
    {
    public:
        AttackLeastHpTargetAction(PlayerbotAI* ai) : AttackAction(ai, "attack least hp target") {}
        virtual string GetTargetName() { return "least hp target"; }
    };

    class AttackEnemyPlayerAction : public AttackAction
    {
    public:
        AttackEnemyPlayerAction(PlayerbotAI* ai) : AttackAction(ai, "attack enemy player") {}
        virtual string GetTargetName() { return "enemy player target"; }
    };

    class AttackRtiTargetAction : public AttackAction
    {
    public:
        AttackRtiTargetAction(PlayerbotAI* ai) : AttackAction(ai, "attack rti target") {}
        virtual string GetTargetName() { return "rti target"; }
    };

    class DropTargetAction : public Action
    {
    public:
        DropTargetAction(PlayerbotAI* ai) : Action(ai, "drop target") {}

        virtual bool Execute(Event event)
        {
            context->GetValue<Unit*>("current target")->Set(NULL);
            bot->SetSelection(ObjectGuid());
            ai->ChangeEngine(BOT_STATE_NON_COMBAT);
            ai->InterruptSpell();
			return true;
        }
    };

}
