#pragma once
#include "PassTroughStrategy.h"

namespace ai
{
    class WorldPacketHandlerStrategy : public PassTroughStrategy
    {
    public:
        WorldPacketHandlerStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "default"; }
    };

    class ReadyCheckStrategy : public PassTroughStrategy
    {
    public:
        ReadyCheckStrategy(PlayerbotAI* ai) : PassTroughStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "ready check"; }
    };
}
