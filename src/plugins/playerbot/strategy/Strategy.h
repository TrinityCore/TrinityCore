#pragma once
#include "Action.h"
#include "Multiplier.h"
#include "Trigger.h"
#include "NamedObjectContext.h"

namespace ai
{
	enum StrategyType
	{
		STRATEGY_TYPE_GENERIC = 0,
		STRATEGY_TYPE_COMBAT = 1,
		STRATEGY_TYPE_NONCOMBAT = 2,
		STRATEGY_TYPE_TANK = 4,
		STRATEGY_TYPE_DPS = 8,
		STRATEGY_TYPE_HEAL = 16,
		STRATEGY_TYPE_RANGED = 32,
		STRATEGY_TYPE_MELEE = 64
	};

	enum ActionPriority
	{
	    ACTION_IDLE = 0,
	    ACTION_NORMAL = 10,
	    ACTION_HIGH = 20,
	    ACTION_MOVE = 30,
	    ACTION_INTERRUPT = 40,
	    ACTION_DISPEL = 50,
	    ACTION_LIGHT_HEAL = 60,
	    ACTION_MEDIUM_HEAL = 70,
	    ACTION_CRITICAL_HEAL = 80,
	    ACTION_EMERGENCY = 90
	};

    class Strategy : public PlayerbotAIAware
    {
    public:
        Strategy(PlayerbotAI* ai);
        virtual ~Strategy() {}

    public:
        virtual NextAction** getDefaultActions() { return NULL; }
        virtual void InitTriggers(std::list<TriggerNode*> &triggers) {}
        virtual void InitMultipliers(std::list<Multiplier*> &multipliers) {}
        virtual string getName() = 0;
		virtual int GetType() { return STRATEGY_TYPE_GENERIC; }
        virtual ActionNode* GetAction(string name);
        void Update() {}
        void Reset() {}

    protected:
        NamedObjectFactoryList<ActionNode> actionNodeFactories;
    };

}
