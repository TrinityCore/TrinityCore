#pragma once

#include "GenericDKStrategy.h"

namespace ai
{
    class BloodDKStrategy : public GenericDKStrategy
    {
    public:
        BloodDKStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "blood"; }
        virtual NextAction** getDefaultActions();
		virtual int GetType() { return STRATEGY_TYPE_TANK | STRATEGY_TYPE_MELEE; }
	};


}
