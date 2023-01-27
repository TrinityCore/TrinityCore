#pragma once

#include "GenericDruidStrategy.h"
#include "DruidAiObjectContext.h"

namespace ai
{
    class ShapeshiftDruidStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
    {
    public:
        ShapeshiftDruidStrategyActionNodeFactory()
        {
            creators["rejuvenation"] = &rejuvenation;
            creators["regrowth"] = &regrowth;
            creators["healing touch"] = &healing_touch;
            creators["rejuvenation on party"] = &rejuvenation_on_party;
            creators["regrowth on party"] = &regrowth_on_party;
            creators["healing touch on party"] = &healing_touch_on_party;
        }
    private:
        static ActionNode* regrowth(PlayerbotAI* ai)
        {
            return new ActionNode ("regrowth",
                /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
                /*A*/ NextAction::array(0, new NextAction("healing touch"), NULL),
                /*C*/ NextAction::array(0, new NextAction("melee", 10.0f), NULL));
        }
        static ActionNode* rejuvenation(PlayerbotAI* ai)
        {
            return new ActionNode ("rejuvenation",
                /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* healing_touch(PlayerbotAI* ai)
        {
            return new ActionNode ("healing touch",
                /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* regrowth_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("regrowth on party",
                /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
                /*A*/ NextAction::array(0, new NextAction("healing touch on party"), NULL),
                /*C*/ NextAction::array(0, new NextAction("melee", 10.0f), NULL));
        }
        static ActionNode* rejuvenation_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("rejuvenation on party",
                /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* healing_touch_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("healing touch on party",
                /*P*/ NextAction::array(0, new NextAction("caster form"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
    };

    class FeralDruidStrategy : public GenericDruidStrategy
    {
    protected:
        FeralDruidStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual int GetType() { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_MELEE; }
    };

}
