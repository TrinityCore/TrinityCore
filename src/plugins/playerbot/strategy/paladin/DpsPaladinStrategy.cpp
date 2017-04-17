#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PaladinMultipliers.h"
#include "DpsPaladinStrategy.h"

using namespace ai;

class DpsPaladinStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsPaladinStrategyActionNodeFactory()
    {
		creators["seal of the crusader"] = &seal_of_the_crusader;
        creators["seal of vengeance"] = &seal_of_vengeance;
        creators["seal of command"] = &seal_of_command;
        creators["blessing of might"] = &blessing_of_might;
        creators["crusader strike"] = &crusader_strike;
    }

private:
    static ActionNode* seal_of_vengeance(PlayerbotAI* ai)
    {
        return new ActionNode ("seal of vengeance",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("seal of command"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* seal_of_the_crusader(PlayerbotAI* ai)
	{
		return new ActionNode("seal of the crusader",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("seal of command"), NULL),
			/*C*/ NULL);
    }
    static ActionNode* seal_of_command(PlayerbotAI* ai)
    {
        return new ActionNode ("seal of command",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("seal of wisdom"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* blessing_of_might(PlayerbotAI* ai)
    {
        return new ActionNode ("blessing of might",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("blessing of kings"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* crusader_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("crusader strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* judgement(PlayerbotAI* ai)
	{
			return new ActionNode("judgement",
				/*P*/ NULL,
				/*A*/ NextAction::array(0, new NextAction("melee"), NULL),
				/*C*/ NULL);
    }

};

DpsPaladinStrategy::DpsPaladinStrategy(PlayerbotAI* ai) : GenericPaladinStrategy(ai)
{
    actionNodeFactories.Add(new DpsPaladinStrategyActionNodeFactory());
}

NextAction** DpsPaladinStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("crusader strike", ACTION_NORMAL + 1),
    new NextAction("melee", ACTION_NORMAL + 1), NULL);
}

void DpsPaladinStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericPaladinStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("divine shield", ACTION_CRITICAL_HEAL + 2), new NextAction("holy light", ACTION_CRITICAL_HEAL + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "judgement of wisdom",
        NextAction::array(0, new NextAction("judgement of wisdom", ACTION_NORMAL + 2), NULL)));
        
        triggers.push_back(new TriggerNode(
		"judgement",
		NextAction::array(0, new NextAction("judgement", ACTION_NORMAL + 2), NULL)));


triggers.push_back(new TriggerNode(
		"medium aoe",
	NextAction::array(0, new NextAction("divine storm", ACTION_HIGH + 1), new NextAction("consecration", ACTION_HIGH + 1), NULL)));

	triggers.push_back(new TriggerNode(
		"hammer of justice interrupt",
		NextAction::array(0, new NextAction("hammer of justice", ACTION_INTERRUPT), new NextAction("judgement", ACTION_NORMAL + 1), NULL)));
		

	triggers.push_back(new TriggerNode(
		"hammer of justice on enemy healer",
		NextAction::array(0, new NextAction("hammer of justice on enemy healer", ACTION_INTERRUPT), new NextAction("judgement", ACTION_NORMAL + 1), NULL)));


	triggers.push_back(new TriggerNode(
		"art of war",
		NextAction::array(0, new NextAction("exorcism", ACTION_HIGH + 2), NULL)));
}

