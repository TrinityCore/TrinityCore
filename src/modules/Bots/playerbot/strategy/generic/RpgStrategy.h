#pragma once

namespace ai
{
    class RpgStrategy : public Strategy
    {
    public:
        RpgStrategy(PlayerbotAI* ai);
        virtual string getName() { return "rpg"; }

    public:
        virtual NextAction** getDefaultActions();
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

}
