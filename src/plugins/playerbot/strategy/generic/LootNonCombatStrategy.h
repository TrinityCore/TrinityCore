#pragma once

namespace ai
{
    class LootNonCombatStrategy : public Strategy
    {
    public:
        LootNonCombatStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "loot"; }
    };

    class GatherStrategy : public Strategy
    {
    public:
        GatherStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "gather"; }
    };
}
