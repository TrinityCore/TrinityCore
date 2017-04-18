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
        creators["melee"] = &melee;
		creators["blood strike"] = &blood_strike;
		creators["pestilence"] = &pestilence;
		creators["obliterate"] = &obliterate;
		//creators["blood boil"] = &blood_boil;
		creators["heart strike"] = &heart_strike;
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
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NextAction::array(0, new NextAction("blood presence"), NULL),
            /*A*/ NextAction::array(0, new NextAction("heart strike"), NULL),
            /*C*/ NULL);
    }
	static ActionNode* heart_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("heart strike",
            /*P*/ NextAction::array(0, new NextAction("blood presence"), NULL),
            /*A*/ NextAction::array(0, new NextAction("blood strike"), NULL),
            /*C*/ NULL);
    }
	static ActionNode* blood_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("blood strike",
            /*P*/ NextAction::array(0, new NextAction("blood presence"), NULL),
            /*A*/ NextAction::array(0, new NextAction("pestilence"), NULL),
            /*C*/ NULL);
    }
	static ActionNode* pestilence(PlayerbotAI* ai)
    {
        return new ActionNode ("pestilence",
            /*P*/ NextAction::array(0, new NextAction("blood presence"), NULL),
            /*A*/ NextAction::array(0, new NextAction("strangulate"), NULL),
            /*C*/ NULL);
    }
	static ActionNode* obliterate(PlayerbotAI* ai)
	{
		return new ActionNode("obliterate",
			/*P*/ NextAction::array(0, new NextAction("blood presence"), NULL),
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
    return NextAction::array(0, new NextAction("melee", 10.0f), NULL);
}

void BloodDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);
	
triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("vampiric blood", 40.0f), NULL)));

triggers.push_back(new TriggerNode(
	"lose aggro",
	NextAction::array(0, new NextAction("dark command", 40.0f), NULL)));

}
void BloodDKAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"high aoe",
		NextAction::array(0, new NextAction("blood boil", 40.0f), NULL)));
}
