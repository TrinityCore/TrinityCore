#pragma once

#include "GenericHunterStrategy.h"
#include "../generic/CombatStrategy.h"

namespace ai
{
    class DpsHunterStrategy : public GenericHunterStrategy
    {
    public:
        DpsHunterStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dps"; }
        virtual NextAction** getDefaultActions();

    };

    class DpsAoeHunterStrategy : public CombatStrategy
    {
    public:
        DpsAoeHunterStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "aoe"; }
    };

    class DpsHunterDebuffStrategy : public CombatStrategy
    {
    public:
        DpsHunterDebuffStrategy(PlayerbotAI* ai) : CombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "dps debuff"; }
    };
}
