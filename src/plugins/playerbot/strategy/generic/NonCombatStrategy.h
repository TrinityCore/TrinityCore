#pragma once

namespace ai
{
    class NonCombatStrategy : public Strategy
    {
    public:
        NonCombatStrategy(PlayerbotAI* ai) : Strategy(ai) {}
		virtual int GetType() { return STRATEGY_TYPE_NONCOMBAT; }
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

    class LfgStrategy : public Strategy
    {
    public:
        LfgStrategy(PlayerbotAI* ai) : Strategy(ai) {}
		virtual int GetType() { return STRATEGY_TYPE_NONCOMBAT; }
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "lfg"; }
    };
}
