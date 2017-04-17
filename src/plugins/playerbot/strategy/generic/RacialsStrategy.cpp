#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RacialsStrategy.h"

using namespace ai;


class RacialsStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    RacialsStrategyActionNodeFactory()
    {
        creators["lifeblood"] = &lifeblood;
		creators["berserking"] = &berserking;			//boost? or often?
		creators["blood fury"] = &blood_fury;			//boost? or often?
		creators["cannibalize"] = &cannibalize;			//loot
		creators["escape artist"] = &escape_artist;		//cc need trigger
		creators["shadowmeld"] = &shadowmeld;
		creators["stoneform"] = &stoneform;				//ch
		creators["war stomp"] = &war_stomp;				//cc need trigger
		creators["will of the forsaken"] = &will_of_the_forsaken;	//cc need trigger
		creators["gift of the naaru"] = &gift_of_the_naaru;
		creators["arcane torrent"] = &arcane_torrent;
		
    }
private:
    static ActionNode* lifeblood(PlayerbotAI* ai)
    {
        return new ActionNode ("lifeblood",  
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("gift of the naaru"), NULL), 
            /*C*/ NULL);
	}
	static ActionNode* berserking(PlayerbotAI* ai)
	{
		return new ActionNode("berserking",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* blood_fury(PlayerbotAI* ai)
	{
		return new ActionNode("blood fury",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* cannibalize(PlayerbotAI* ai)
	{
		return new ActionNode("cannibalize",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* escape_artist(PlayerbotAI* ai)
	{
		return new ActionNode("escape artist",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* shadowmeld(PlayerbotAI* ai)
	{
		return new ActionNode("shadowmeld",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* stoneform(PlayerbotAI* ai)
	{
		return new ActionNode("stoneform",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* war_stomp(PlayerbotAI* ai)
	{
		return new ActionNode("war stomp",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* will_of_the_forsaken(PlayerbotAI* ai)
	{
		return new ActionNode("will of the forsaken",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* gift_of_the_naaru(PlayerbotAI* ai)
	{
		return new ActionNode("gift of the naaru",
			/*P*/ NULL,
			/*A*/ NextAction::array(0, new NextAction("lifeblood"), NULL),
			/*C*/ NULL);
	}
	static ActionNode* arcane_torrent(PlayerbotAI* ai)
	{
		return new ActionNode("arcane torrent",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
	}
	static ActionNode* every_man_for_himself(PlayerbotAI* ai)
	{
		return new ActionNode("every man for himself",
			/*P*/ NULL,
			/*A*/ NULL,
			/*C*/ NULL);
    }
};

void RacialsStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	triggers.push_back(new TriggerNode(
		"low health", 
		NextAction::array(0, new NextAction("lifeblood", 71.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "low mana", 
        NextAction::array(0, new NextAction("arcane torrent", ACTION_EMERGENCY + 6), NULL)));

	triggers.push_back(new TriggerNode(
		"often",
		NextAction::array(0, new NextAction("berserking", ACTION_HIGH + 6),
			new NextAction("blood fury", ACTION_HIGH + 6),
			new NextAction("war stomp", ACTION_HIGH + 6),
			NULL)));

	triggers.push_back(new TriggerNode(
		"loot available",
		NextAction::array(0, new NextAction("cannibalize", ACTION_HIGH + 6), NULL)));
}

RacialsStrategy::RacialsStrategy(PlayerbotAI* ai) : Strategy(ai)
{
    actionNodeFactories.Add(new RacialsStrategyActionNodeFactory());
}
