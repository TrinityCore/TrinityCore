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
		//creators["plague strike"] = &plague_strike;
		//creators["death grip"] = &death_grip;
		//creators["death coil"] = &death_coil;
		creators["death strike"] = &death_strike;
		//creators["unholy blight"] = &unholy_blight;
		creators["scourge strike"] = &scourge_strike;
		//creators["death and decay"] = &death_and_decay;
		//creators["unholy pressence"] = &unholy_pressence;
		//creators["raise dead"] = &raise_dead;
		//creators["army of the dead"] = &army of the dead;
		//creators["summon gargoyle"] = &army of the dead;
		//creators["anti magic shell"] = &anti_magic_shell;
		//creators["anti magic zone"] = &anti_magic_zone;
		//creators["ghoul frenzy"] = &ghoul_frenzy;
		creators["corpse explosion"] = &corpse_explosion;
	}
private:
	
	
	static ActionNode* death_strike(PlayerbotAI* ai)
	{
		return new ActionNode("death strike",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* corpse_explosion(PlayerbotAI* ai)
	{
		return new ActionNode("corpse explosion",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* scourge_strike(PlayerbotAI* ai)
	{
		return new ActionNode("scourge strike",
			/*P*/ NextAction::array(0, new NextAction("unholy pressence"), NULL),
			/*A*/ NextAction::array(0, new NextAction("death strike"), NULL),
			/*C*/ NULL);
	}
};


	NextAction** UnholyDKStrategy::getDefaultActions()
	{
    return NextAction::array(0, new NextAction("scourge strike" , ACTION_NORMAL + 3), NULL);
	}

void UnholyDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);

	triggers.push_back(new TriggerNode(
		"often",
		NextAction::array(0, new NextAction("ghoul frenzy", ACTION_NORMAL + 2), NULL)));

	triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("death pact", ACTION_EMERGENCY + 1), NULL)));
}


void UnholyDKAoeStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"loot available",
		NextAction::array(0, new NextAction("corpse explosion", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("death and decay", ACTION_NORMAL + 3),
			new NextAction("corpse explosion", ACTION_NORMAL + 3), NULL)));
}

