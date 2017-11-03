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
		//creators["blood strike"] = &blood_strike;
		creators["rune strike"] = &rune_strike;
		creators["heart strike"] = &heart_strike;
		creators["death strike"] = &death_strike;
		//creators["death grip"] = &death_grip;
		//creators["plague strike"] = &plague_strike;
		//creators["pestilence"] = &pestilence;
		//creators["icy touch"] = &icy_touch;
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
		new NextAction("heart strike", ACTION_NORMAL + 5),
		new NextAction("death strike", ACTION_NORMAL + 4),
		new NextAction("rune strike", ACTION_NORMAL + 3), NULL);
}

void BloodDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);

triggers.push_back(new TriggerNode(
	"rune strike",
	NextAction::array(0, new NextAction("rune strike", ACTION_NORMAL + 3), NULL)));

triggers.push_back(new TriggerNode(
	"blood tap",
	NextAction::array(0, new NextAction("blood tap", ACTION_HIGH + 5), NULL)));


triggers.push_back(new TriggerNode(
	"lose aggro",
	NextAction::array(0, new NextAction("dark command", ACTION_HIGH + 3), NULL)));


triggers.push_back(new TriggerNode(
	"low health",
	NextAction::array(0,
		new NextAction("blood tap", ACTION_HIGH + 5),
		new NextAction("vampiric blood", ACTION_HIGH + 3),
		new NextAction("death strike", ACTION_HIGH + 4), NULL)));



}
