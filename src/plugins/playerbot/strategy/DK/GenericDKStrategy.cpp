#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DKMultipliers.h"
#include "GenericDKStrategy.h"
#include "DKAiObjectContext.h"

using namespace ai;

class GenericDKStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericDKStrategyActionNodeFactory()
    {
		//blood
		//creators["rune tap"] = &rune_tap; cd
		//creators["vampiric blood"] = &vampiric_blood;
		//creators["death pact"] = &death_pact;
		//creators["hysteria"] = &hysteria; boost party
		//creators["dancing rune weapon"] = &dancing_rune_weapon; //cd
		//creators["dark command"] = &dark_command; taunt
		
		//frost
		//creators["chains of ice"] = &chains_of_ice;
		//creators["icy clutch"] = &icy_clutch;
		creators["horn of winter"] = &horn_of_winter;
		creators["killing machine"] = &killing_machine;	// buff
		//creators["deathchill"] = &deathchill;		//boost
		creators["icebound fortitude"] = &icebound_fortitude;
		//creators["mind freeze"] = &mind_freeze; interrupt
		//creators["empower rune weapon"] = &empower_rune_weapon; boost
		//creators["hungering cold"] = &hungering_cold; snare
		//creators["unbreakable armor"] = &unbreakable_armor; boost +cd
		//creators["improved icy talons"] = &improved_icy_talons; boost party
		
		//unholy
		//creators["death and decay"] = &death_and_decay;
		//creators["raise dead"] = &raise_dead;
		//creators["army of the dead"] = &army of the dead;
		//creators["summon gargoyle"] = &army of the dead;
		//creators["anti magic shell"] = &anti_magic_shell; cd
		creators["anti magic zone"] = &anti_magic_zone; 
		//creators["ghoul frenzy"] = &ghoul_frenzy;
		creators["corpse explosion"] = &corpse_explosion;
		creators["bone shield"] = &bone_shield;
		creators["heart strike"] = &heart_strike;
		creators["death grip"] = &death_grip;
		creators["plague strike"] = &plague_strike;
		creators["pestilence"] = &pestilence;
		creators["icy touch"] = &icy_touch;
	
    }
private:
	static ActionNode* death_coil(PlayerbotAI* ai)
	{
		return new ActionNode("death coil",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("death strike"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* death_grip(PlayerbotAI* ai)
	{
		return new ActionNode("death grip",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("icy touch"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* plague_strike(PlayerbotAI* ai)
	{
		return new ActionNode("plague strike",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* icy_touch(PlayerbotAI* ai)
	{
		return new ActionNode("icy touch",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* heart_strike(PlayerbotAI* ai)
	{
		return new ActionNode("heart strike",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("blood strike"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* pestilence(PlayerbotAI* ai)
	{
		return new ActionNode("pestilence",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
    static ActionNode* horn_of_winter(PlayerbotAI* ai)
    {
        return new ActionNode ("horn of winter",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* bone_shield(PlayerbotAI* ai)
    {
        return new ActionNode ("bone shield",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* killing_machine(PlayerbotAI* ai)
    {
        return new ActionNode ("killing machine",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("improved icy talons"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* corpse_explosion(PlayerbotAI* ai)
    {
        return new ActionNode ("corpse explosion",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* anti_magic_zone(PlayerbotAI* ai)
    {
        return new ActionNode ("anti magic zone",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("anti magic shell"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* icebound_fortitude(PlayerbotAI* ai)
    {
        return new ActionNode ("icebound fortitude",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
   
    }
};

GenericDKStrategy::GenericDKStrategy(PlayerbotAI* ai) : MeleeCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericDKStrategyActionNodeFactory());
}

void GenericDKStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	MeleeCombatStrategy::InitTriggers(triggers);

	triggers.push_back(new TriggerNode(
		"high aoe",
		NextAction::array(0,
			new NextAction("anti magic shell", ACTION_NORMAL + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"death coil",
		NextAction::array(0, new NextAction("death coil", ACTION_NORMAL + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"critical aoe heal",
		NextAction::array(0, new NextAction("anti magic zone", ACTION_EMERGENCY + 1), NULL)));

	triggers.push_back(new TriggerNode(
		"no pet",
		NextAction::array(0, new NextAction("raise dead", ACTION_NORMAL + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "mind freeze",
        NextAction::array(0, new NextAction("mind freeze", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "bone shield",
        NextAction::array(0, new NextAction("bone shield", ACTION_NORMAL + 1), NULL)));

	triggers.push_back(new TriggerNode(
		"horn of winter",
		NextAction::array(0, new NextAction("horn of winter", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "mind freeze on enemy healer",
        NextAction::array(0, new NextAction("mind freeze on enemy healer", ACTION_HIGH + 1), NULL)));

	
	triggers.push_back(new TriggerNode(
		"enemy out of melee",
		NextAction::array(0, new NextAction("icy touch", ACTION_NORMAL + 9),
			new NextAction("death grip", ACTION_NORMAL + 9),
			new NextAction("reach melee", ACTION_NORMAL + 8), NULL)));

	triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("icebound fortitude", ACTION_HIGH + 5),
			new NextAction("rune tap", ACTION_HIGH + 4), NULL)));


	triggers.push_back(new TriggerNode(
		"medium health",
		NextAction::array(0, new NextAction("rune tap", ACTION_NORMAL + 4),
			new NextAction("death strike", ACTION_NORMAL + 3), NULL)));

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
			new NextAction("unholy blight", ACTION_NORMAL + 6),
			new NextAction("death and decay", ACTION_NORMAL + 5),
			new NextAction("pestilence", ACTION_NORMAL + 4),
			new NextAction("blood boil", ACTION_NORMAL + 3), NULL)));

	triggers.push_back(new TriggerNode(
		"medium aoe",
		NextAction::array(0,
			new NextAction("death and decay", ACTION_NORMAL + 5),
			new NextAction("pestilence", ACTION_NORMAL + 4),
			new NextAction("blood boil", ACTION_NORMAL + 3), NULL)));

	triggers.push_back(new TriggerNode("light aoe",
		NextAction::array(0,
			new NextAction("howling blast", ACTION_NORMAL + 5),
			new NextAction("pestilence", ACTION_NORMAL + 4),
			new NextAction("hearth strike", ACTION_NORMAL + 3),
			new NextAction("blood boil", ACTION_NORMAL + 3), NULL)));


}
