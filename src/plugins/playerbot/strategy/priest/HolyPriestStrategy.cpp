#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PriestMultipliers.h"
#include "HolyPriestStrategy.h"

namespace ai
{
    class HolyPriestStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
    {
    public:
        HolyPriestStrategyActionNodeFactory()
        {
            creators["smite"] = &smite;
        }
    private:
        static ActionNode* smite(PlayerbotAI* ai)
        {
            return new ActionNode ("smite",
                /*P*/ NULL,
                /*A*/ NextAction::array(0, new NextAction("shoot"), NULL),
                /*C*/ NULL);
        }
    };
};

using namespace ai;

HolyPriestStrategy::HolyPriestStrategy(PlayerbotAI* ai) : HealPriestStrategy(ai)
{
    actionNodeFactories.Add(new HolyPriestStrategyActionNodeFactory());
}

NextAction** HolyPriestStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("holy fire", 10.0f), new NextAction("smite", 10.0f), NULL);
}

void HolyPriestStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    HealPriestStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of spell",
        NextAction::array(0, new NextAction("reach spell", ACTION_NORMAL + 9), NULL)));

}
