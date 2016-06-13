#pragma once

#include "GenericShamanStrategy.h"
#include "MeleeShamanStrategy.h"

namespace ai
{
    class CasterShamanStrategy : public GenericShamanStrategy
    {
    public:
        CasterShamanStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual NextAction** getDefaultActions();
        virtual string getName() { return "caster"; }
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_RANGED; }
    };

    class CasterAoeShamanStrategy : public MeleeAoeShamanStrategy
    {
    public:
        CasterAoeShamanStrategy(PlayerbotAI* ai) : MeleeAoeShamanStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "caster aoe"; }
    };
}
