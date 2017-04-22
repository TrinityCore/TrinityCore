#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DKMultipliers.h"
#include "BloodDKStrategy.h"

using namespace ai;

class BloodDKStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    BloodDKStrategyActionNodeFactory()
    {
        //creators["melee"] = &melee;
		creators["blood strike"] = &blood_strike;
		creators["rune strike"] = &rune_strike;
		creators["heart strike"] = &heart_strike;
		creators["death strike"] = &death_strike;
		creators["death grip"] = &death_grip;
		creators["plague strike"] = &plague_strike;
		creators["pestilence"] = &pestilence;
		creators["icy touch"] = &icy_touch;
		//creators["obliterate"] = &obliterate;
		//creators["blood boil"] = &blood_boil;
		//creators["mark of_blood"] = &mark_of_blood;
		//creators["blood presence"] = &blood_presence;
		//creators["rune tap"] = &rune_tap;
		//creators["vampiric blood"] = &vampiric_blood;
		//creators["death pact"] = &death_pact;
		//creators["death rune_mastery"] = &death_rune_mastery;
		//creators["hysteria"] = &hysteria;
		//creators["dancing weapon"] = &dancing_weapon;
		//creators["dark command"] = &dark_command;
    }
private:
	static ActionNode* death_grip(PlayerbotAI* ai)
	{
		return new ActionNode("death grip",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("icy touch"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* rune_strike(PlayerbotAI* ai)
	{
		return new ActionNode("rune strike",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("death coil"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* heart_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("heart strike",
            /*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
            /*A*/ NextAction::array(0, new NextAction("death strike"), NULL),
            /*C*/ NULL);
	}
	static ActionNode* plague_strike(PlayerbotAI* ai)
	{
		return new ActionNode("plague strike",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* icy_touch(PlayerbotAI* ai)
	{
		return new ActionNode("icy touch",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
    }
	static ActionNode* blood_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("blood strike",
            /*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
            /*A*/ NextAction::array(0, new NextAction("death strike"), NULL),
            /*C*/ NULL);
    }
	static ActionNode* pestilence(PlayerbotAI* ai)
    {
        return new ActionNode ("pestilence",
            /*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
	static ActionNode* death_strike(PlayerbotAI* ai)
	{
		return new ActionNode("death strike",
			/*P*/ NextAction::array(0, new NextAction("frost presence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	
};

BloodDKStrategy::BloodDKStrategy(PlayerbotAI* ai) : GenericDKStrategy(ai)
{
    actionNodeFactories.Add(new BloodDKStrategyActionNodeFactory());
}

NextAction** BloodDKStrategy::getDefaultActions()
{
	return NextAction::array(0,
		new NextAction("heart strike", ACTION_NORMAL + 4), new NextAction("death strike", ACTION_NORMAL + 4),
		new NextAction("rune strike", ACTION_NORMAL + 3), NULL);
}

void BloodDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);

	triggers.push_back(new TriggerNode(
		"enemy out of melee",
		NextAction::array(0, new NextAction("icy touch", ACTION_NORMAL + 9),
			new NextAction("death grip", ACTION_NORMAL + 9),
			new NextAction("reach melee", ACTION_NORMAL + 8), NULL)));
	
triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, 
			new NextAction("blood tap", ACTION_HIGH + 5),
			new NextAction("vampiric blood", ACTION_HIGH + 3), 
			new NextAction("death strike", ACTION_HIGH + 4), NULL)));

triggers.push_back(new TriggerNode(
	"medium health",
	NextAction::array(0, new NextAction("rune tap", ACTION_NORMAL + 4),
		new NextAction("death strike", ACTION_NORMAL + 3), NULL)));

triggers.push_back(new TriggerNode(
	"rune strike",
	NextAction::array(0, new NextAction("rune strike", ACTION_NORMAL + 2), NULL)));

triggers.push_back(new TriggerNode(
	"blood tap",
	NextAction::array(0, new NextAction("blood tap", ACTION_NORMAL + 2), NULL)));


triggers.push_back(new TriggerNode(
	"lose aggro",
	NextAction::array(0, new NextAction("dark command", ACTION_HIGH + 3), NULL)));

triggers.push_back(new TriggerNode(
	"icy touch on attacker",
	NextAction::array(0, new NextAction("icy touch", ACTION_HIGH + 1), NULL)));

triggers.push_back(new TriggerNode(
	"icy touch",
	NextAction::array(0, new NextAction("icy touch", ACTION_HIGH + 1), NULL)));

triggers.push_back(new TriggerNode(
	"plague strike",
	NextAction::array(0, new NextAction("plague strike", ACTION_HIGH + 1), NULL)));

triggers.push_back(new TriggerNode(
	"plague strike on attacker",
	NextAction::array(0, new NextAction("plague strike", ACTION_HIGH + 1), NULL)));

	triggers.push_back(new TriggerNode(
		"high aoe",
		NextAction::array(0, 
			new NextAction("howling blast", ACTION_HIGH + 1),
			new NextAction("plague strike", ACTION_HIGH + 1), 
			new NextAction("army of the dead", ACTION_NORMAL + 5),
			new NextAction("pestilence", ACTION_NORMAL + 4),
			new NextAction("blood boil", ACTION_NORMAL + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"medium aoe",
		NextAction::array(0, 
			new NextAction("howling blast", ACTION_HIGH + 1),
			new NextAction("plague strike", ACTION_HIGH + 1),
			new NextAction("pestilence", ACTION_NORMAL + 4),
			new NextAction("blood boil", ACTION_NORMAL + 3), NULL)));

	triggers.push_back(new TriggerNode("light aoe",
		NextAction::array(0,
		new NextAction("howling blast", ACTION_HIGH + 1),
		new NextAction("plague strike", ACTION_HIGH + 1),
		new NextAction("pestilence", ACTION_NORMAL + 4), 
			new NextAction("hearth strike", ACTION_NORMAL + 3),
			new NextAction("blood boil", ACTION_NORMAL + 3), NULL)));
}
