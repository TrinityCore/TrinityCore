#include "../../../pchdef.h"
#include "../../playerbot.h"

#include "HunterMultipliers.h"
#include "DpsHunterStrategy.h"

using namespace ai;

class DpsHunterStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsHunterStrategyActionNodeFactory()
    {
        creators["aimed shot"] = &aimed_shot;
        creators["chimera shot"] = &chimera_shot;
        creators["explosive shot"] = &explosive_shot;
        creators["concussive shot"] = &concussive_shot;
        creators["viper sting"] = &viper_sting;
    }
private:
    static ActionNode* viper_sting(PlayerbotAI* ai)
    {
        return new ActionNode ("viper sting",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("mana potion", 10.0f), NULL),
            /*C*/ NULL);
    }
    static ActionNode* aimed_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("aimed shot",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("chimera shot", 10.0f), NULL),
            /*C*/ NULL);
    }
    static ActionNode* chimera_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("chimera shot",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("arcane shot", 10.0f), NULL),
            /*C*/ NULL);
    }
    static ActionNode* explosive_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("explosive shot",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("aimed shot"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* concussive_shot(PlayerbotAI* ai)
    {
        return new ActionNode ("concussive shot",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NextAction::array(0, new NextAction("wyvern sting", 11.0f), NULL));
    }

};

DpsHunterStrategy::DpsHunterStrategy(PlayerbotAI* ai) : GenericHunterStrategy(ai)
{
    actionNodeFactories.Add(new DpsHunterStrategyActionNodeFactory());
}

NextAction** DpsHunterStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("explosive shot", 11.0f), new NextAction("auto shot", 10.0f), NULL);
}

void DpsHunterStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericHunterStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "black arrow",
        NextAction::array(0, new NextAction("black arrow", 51.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana",
        NextAction::array(0, new NextAction("viper sting", ACTION_EMERGENCY + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "no pet",
        NextAction::array(0, new NextAction("call pet", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "hunters pet low health",
        NextAction::array(0, new NextAction("mend pet", 60.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "hunter's mark",
        NextAction::array(0, new NextAction("hunter's mark", 52.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "freezing trap",
        NextAction::array(0, new NextAction("freezing trap", 83.0f), NULL)));
}

void DpsAoeHunterStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("multi-shot", 20.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"high aoe",
		NextAction::array(0, new NextAction("volley", 20.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"serpent sting on attacker",
		NextAction::array(0, new NextAction("serpent sting on attacker", 49.0f), NULL)));
}

void DpsHunterDebuffStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "no stings",
        NextAction::array(0, new NextAction("serpent sting", 50.0f), NULL)));
}
