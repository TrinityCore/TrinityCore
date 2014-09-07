#pragma once

#include "GenericShamanStrategy.h"

namespace ai
{
    class TotemsShamanStrategy : public GenericShamanStrategy
    {
    public:
        TotemsShamanStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "totems"; }
		virtual int GetType() { return STRATEGY_TYPE_HEAL; }
    };
}
