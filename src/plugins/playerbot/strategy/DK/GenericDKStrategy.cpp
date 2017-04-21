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
	
    }
private:
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
		"enemy out of melee",
		NextAction::array(0, new NextAction("death grip", ACTION_NORMAL + 9),
			new NextAction("reach melee", ACTION_NORMAL + 9), NULL)));

	triggers.push_back(new TriggerNode(
		"icy touch",
		NextAction::array(0, new NextAction("icy touch", 49.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"plague strike",
		NextAction::array(0, new NextAction("plague strike", 49.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "mind freeze",
        NextAction::array(0, new NextAction("mind freeze", 49.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "bone shield",
        NextAction::array(0, new NextAction("bone shield", 50.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"horn of winter",
		NextAction::array(0, new NextAction("horn of winter", 50.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "mind freeze on enemy healer",
        NextAction::array(0, new NextAction("mind freeze on enemy healer", 40.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"low health",
		NextAction::array(0, new NextAction("vampiric blood", 80.0f), NULL)));

}
