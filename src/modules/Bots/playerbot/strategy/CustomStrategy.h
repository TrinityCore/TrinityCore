#pragma once
#include "Strategy.h"

namespace ai
{
    class CustomStrategy : public Strategy, public Qualified
    {
    public:
        CustomStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "custom::" + qualifier; }
        void Reset();

    private:
        list<string> actionLines;
        void LoadActionLines(uint32 owner);

    public:
        static map<string, string> actionLinesCache;
    };
}
