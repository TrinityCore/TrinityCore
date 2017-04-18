#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DKMultipliers.h"
#include "UnholyDKStrategy.h"

using namespace ai;

class UnholyDKStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
	UnholyDKStrategyActionNodeFactory()
	{
		// Unholy
		//creators["bone shield"] = &bone_shield;
		creators["plague strike"] = &plague_strike;
		creators["death grip"] = &death_grip;
		creators["death coil"] = &death_coil;
		creators["death strike"] = &death_strike;
		creators["unholy blight"] = &unholy_blight;
		creators["scourge strike"] = &scourge_strike;
		//creators["death and decay"] = &death_and_decay;
		//creators["unholy pressence"] = &unholy_pressence;
		//creators["raise dead"] = &raise_dead;
		//creators["army of the dead"] = &army of the dead;
		//creators["summon gargoyle"] = &army of the dead;
		//creators["anti magic shell"] = &anti_magic_shell;
		//creators["anti magic zone"] = &anti_magic_zone;
		//creators["ghoul frenzy"] = &ghoul_frenzy;
		//creators["corpse explosion"] = &corpse_explosion;
	}
private:
	static ActionNode* plague_strike(PlayerbotAI* ai)
	{
		return new ActionNode("plague strike",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("melee"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* death_coil(PlayerbotAI* ai)
	{
		return new ActionNode("death coil",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("death strike"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* death_strike(PlayerbotAI* ai)
	{
		return new ActionNode("death strike",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* unholy_blight(PlayerbotAI* ai)
	{
		return new ActionNode("unholy blight",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* death_grip(PlayerbotAI* ai)
	{
		return new ActionNode("death grip",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* scourge_strike(PlayerbotAI* ai)
	{
		return new ActionNode("scourge strike",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("unholy blight"), NULL),
			/*C*/ NULL);
	}
};


	NextAction** UnholyDKStrategy::getDefaultActions()
	{
    return NextAction::array(0, new NextAction("scourge strike", 5.0f), NULL);
	}

void UnholyDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "low health",
        NextAction::array(0, new NextAction("rune tap", 50.0f), NULL)));
}

void UnholyDKAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("death and decay", 20.0f), NULL)));
}

