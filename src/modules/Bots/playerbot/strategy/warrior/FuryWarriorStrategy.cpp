#include "botpch.h"
#include "../../playerbot.h"
#include "WarriorMultipliers.h"
#include "FuryWarriorStrategy.h"

using namespace ai;

class FuryWarriorStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    FuryWarriorStrategyActionNodeFactory()
    {
        creators["melee"] = &melee;
        creators["charge"] = &charge;
        creators["bloodthirst"] = &bloodthirst;
        creators["rampage"] = &rampage;
        creators["whirlwind"] = &whirlwind;
        creators["slam"] = &slam;
        creators["death wish"] = &death_wish;
        creators["execute"] = &execute;
    }
private:
    
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("charge"), NULL),
            /*A*/ NextAction::array(0, new NextAction("bloodthirst"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* charge(PlayerbotAI* ai)
    {
        return new ActionNode ("charge",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("reach melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* bloodthirst(PlayerbotAI* ai)
    {
        return new ActionNode ("bloodthirst",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NextAction::array(0, new NextAction("whirlwind"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* rampage(PlayerbotAI* ai)
    {
        return new ActionNode ("rampage",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* whirlwind(PlayerbotAI* ai)
    {
        return new ActionNode ("whirlwind",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* slam(PlayerbotAI* ai)
    {
        return new ActionNode ("slam",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* death_wish(PlayerbotAI* ai)
    {
        return new ActionNode ("death wish",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("berserker rage"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* execute(PlayerbotAI* ai)
    {
        return new ActionNode ("execute",
            /*P*/ NextAction::array(0, new NextAction("berserker stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

FuryWarriorStrategy::FuryWarriorStrategy(PlayerbotAI* ai) : GenericWarriorStrategy(ai)
{
    actionNodeFactories.Add(new FuryWarriorStrategyActionNodeFactory());
}

NextAction** FuryWarriorStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("bloodthirst", ACTION_HIGH + 5), NULL);
}

void FuryWarriorStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericWarriorStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "enemy out of melee",
        NextAction::array(0, new NextAction("charge", ACTION_NORMAL + 9), NULL)));

    triggers.push_back(new TriggerNode(
        "high rage available",
        NextAction::array(0, new NextAction("heroic strike", ACTION_HIGH + 4), NULL)));

    triggers.push_back(new TriggerNode(
        "target critical health",
        NextAction::array(0, new NextAction("execute", ACTION_HIGH + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"hamstring",
		NextAction::array(0, new NextAction("hamstring", ACTION_INTERRUPT), NULL)));

    triggers.push_back(new TriggerNode(
        "rampage",
        NextAction::array(0, new NextAction("rampage", ACTION_HIGH + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"victory rush",
		NextAction::array(0, new NextAction("victory rush", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "death wish",
        NextAction::array(0, new NextAction("death wish", ACTION_HIGH + 2), NULL)));
}


void FuryWarriorAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "rend on attacker",
        NextAction::array(0, new NextAction("rend on attacker", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "light aoe",
        NextAction::array(0, new NextAction("thunder clap", ACTION_HIGH + 2), new NextAction("demoralizing shout", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("cleave", ACTION_HIGH + 3), NULL)));
}
