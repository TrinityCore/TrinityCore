#include "../../pchdef.h"
#include "../playerbot.h"
#include "Strategy.h"
#include "NamedObjectContext.h"

using namespace ai;
using namespace std;


class ActionNodeFactoryInternal : public NamedObjectFactory<ActionNode>
{
public:
    ActionNodeFactoryInternal()
    {
        creators["melee"] = &melee;
        creators["healthstone"] = &healthstone;
        creators["be near"] = &follow_master_random;
        creators["attack anything"] = &attack_anything;
        creators["move random"] = &move_random;
        creators["move to loot"] = &move_to_loot;
        creators["food"] = &food;
        creators["drink"] = &drink;
        creators["mana potion"] = &mana_potion;
        creators["healing potion"] = &healing_potion;
        creators["flee"] = &flee;
    }

private:
    static ActionNode* melee(PlayerbotAI* ai)
    {
        return new ActionNode ("melee",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* healthstone(PlayerbotAI* ai)
    {
        return new ActionNode ("healthstone",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("healing potion"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* follow_master_random(PlayerbotAI* ai)
    {
        return new ActionNode ("be near",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("follow"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* attack_anything(PlayerbotAI* ai)
    {
        return new ActionNode ("attack anything",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* move_random(PlayerbotAI* ai)
    {
        return new ActionNode ("move random",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("stay line"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* move_to_loot(PlayerbotAI* ai)
    {
        return new ActionNode ("move to loot",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* food(PlayerbotAI* ai)
    {
        return new ActionNode ("food",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* drink(PlayerbotAI* ai)
    {
        return new ActionNode ("drink",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* mana_potion(PlayerbotAI* ai)
    {
        return new ActionNode ("mana potion",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("drink"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* healing_potion(PlayerbotAI* ai)
    {
        return new ActionNode ("healing potion",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("food"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* flee(PlayerbotAI* ai)
    {
        return new ActionNode ("flee",
            /*P*/ NULL,
            /*A*/ NULL,
            /*C*/ NULL);
    }
};

Strategy::Strategy(PlayerbotAI* ai) : PlayerbotAIAware(ai)
{
    actionNodeFactories.Add(new ActionNodeFactoryInternal());
}

ActionNode* Strategy::GetAction(string name)
{
    return actionNodeFactories.GetObject(name, ai);
}

