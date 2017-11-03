#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "DKMultipliers.h"
#include "GenericDKNonCombatStrategy.h"

using namespace ai;

class GenericDKNonCombatStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericDKNonCombatStrategyActionNodeFactory()
    {
        creators["bone shield"] = &bone_shield;
        creators["horn of winter"] = &horn_of_winter;
    }
private:
    static ActionNode* bone_shield(PlayerbotAI* ai)
    {
        return new ActionNode ("bone shield",
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
};

GenericDKNonCombatStrategy::GenericDKNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericDKNonCombatStrategyActionNodeFactory());
}

void GenericDKNonCombatStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

	triggers.push_back(new TriggerNode(
		"raise dead",
		NextAction::array(0, new NextAction("raise dead", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "horn of winter",
        NextAction::array(0, new NextAction("horn of winter", 21.0f), NULL)));

	triggers.push_back(new TriggerNode(
		"bone shield",
		NextAction::array(0, new NextAction("bone shield", 21.0f), NULL)));

}


void DKBuffDpsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    triggers.push_back(new TriggerNode(
        "improved icy talons",
        NextAction::array(0, new NextAction("improved icy talons", 19.0f), NULL)));
}
