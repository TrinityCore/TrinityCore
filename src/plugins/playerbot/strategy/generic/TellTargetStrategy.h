#pragma once

namespace ai
{
    class TellTargetStrategy : public Strategy
    {
    public:
        TellTargetStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "TellTarget"; }
    };


}
