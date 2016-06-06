#pragma once

#include "../Action.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class MovementAction : public Action {
    public:
        MovementAction(PlayerbotAI* ai, string name) : Action(ai, name)
        {
            bot = ai->GetBot();
        }

    protected:
        bool MoveNear(uint32 mapId, float x, float y, float z, float distance = sPlayerbotAIConfig.followDistance);
        bool MoveTo(uint32 mapId, float x, float y, float z);
        bool MoveTo(Unit* target, float distance = 0.0f);
        bool MoveNear(WorldObject* target, float distance = sPlayerbotAIConfig.followDistance);
        float GetFollowAngle();
        bool Follow(Unit* target, float distance = sPlayerbotAIConfig.followDistance);
        bool Follow(Unit* target, float distance, float angle);
        void WaitForReach(float distance);
        bool IsMovingAllowed(Unit* target);
        bool IsMovingAllowed(uint32 mapId, float x, float y, float z);
        bool IsMovingAllowed();
        bool Flee(Unit *target);

    protected:
        Player* bot;
    };

    class FleeAction : public MovementAction
    {
    public:
        FleeAction(PlayerbotAI* ai, float distance = sPlayerbotAIConfig.spellDistance) : MovementAction(ai, "flee")
        {
			this->distance = distance;
		}

        virtual bool Execute(Event event);
        virtual bool isUseful();

	private:
		float distance;
    };


    class RunAwayAction : public MovementAction
    {
    public:
        RunAwayAction(PlayerbotAI* ai) : MovementAction(ai, "runaway") {}
        virtual bool Execute(Event event);
    };

    class MoveRandomAction : public MovementAction
    {
    public:
        MoveRandomAction(PlayerbotAI* ai) : MovementAction(ai, "move random") {}
        virtual bool Execute(Event event);
        virtual bool isPossible()
        {
            return MovementAction::isPossible() &&
                    AI_VALUE2(uint8, "health", "self target") > sPlayerbotAIConfig.mediumHealth &&
                    (!AI_VALUE2(uint8, "mana", "self target") || AI_VALUE2(uint8, "mana", "self target") > sPlayerbotAIConfig.mediumMana);
        }
    };

    class MoveToLootAction : public MovementAction
    {
    public:
        MoveToLootAction(PlayerbotAI* ai) : MovementAction(ai, "move to loot") {}
        virtual bool Execute(Event event);
    };

    class MoveOutOfEnemyContactAction : public MovementAction
    {
    public:
        MoveOutOfEnemyContactAction(PlayerbotAI* ai) : MovementAction(ai, "move out of enemy contact") {}
        virtual bool Execute(Event event);
        virtual bool isUseful();
    };

    class SetFacingTargetAction : public MovementAction
    {
    public:
        SetFacingTargetAction(PlayerbotAI* ai) : MovementAction(ai, "set facing") {}
        virtual bool Execute(Event event);
        virtual bool isUseful();
    };

}
