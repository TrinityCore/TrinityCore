#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SayAction.h"

using namespace ai;

map<string, vector<string> > SayAction::sayTable;
map<string, vector<string> > SayAction::yellTable;

SayAction::SayAction(PlayerbotAI* ai) : Action(ai, "say"), Qualified()
{
    if (yellTable.empty())
    {
        yellTable["critical health"].push_back("Heal me! Quick!");
        yellTable["critical health"].push_back("Almost dead! Heal me!");
        yellTable["critical health"].push_back("Help! Heal me!");
    }

    if (sayTable.empty())
    {
        sayTable["low health"].push_back("Heal me");
        sayTable["low health"].push_back("Low health");
        sayTable["low health"].push_back("Need heal");

        sayTable["low mana"].push_back("OOM");
        sayTable["low mana"].push_back("Low mana");
        sayTable["low mana"].push_back("Need more mana");

        sayTable["taunt"].push_back("Attack me not them, you lunatic!");
        sayTable["taunt"].push_back("Charge!");
        sayTable["taunt"].push_back("I am going, I am going!");
        sayTable["taunt"].push_back("Aaaaargh!");
        sayTable["taunt"].push_back("For the honor!");
        sayTable["taunt"].push_back("Wait, I'll get him");
        sayTable["taunt"].push_back("I am the tank!");

        sayTable["aoe"].push_back("Holy shit!");
        sayTable["aoe"].push_back("This ends now");
        sayTable["aoe"].push_back("We're done for");

        sayTable["loot"].push_back("This is interesting");
        sayTable["loot"].push_back("This is valuable");
        sayTable["loot"].push_back("This is useless");
        sayTable["loot"].push_back("I can use this");
        sayTable["loot"].push_back("I can sell this later");
        sayTable["loot"].push_back("I hope there will be some money there");
        sayTable["loot"].push_back("Shit, crap again");
    }
}

bool SayAction::Execute(Event event)
{
    if (urand(0, 10) < 5) return false;

    bool yell = false;
    vector<string> &strings = yellTable[qualifier];
    if (strings.empty())
    {
        strings = sayTable[qualifier];
        yell = true;
    }
    if (strings.empty()) return false;

    uint32 idx = urand(0, strings.size() - 1);
    string text = strings[idx];

    if (yell)
        bot->Yell(text, LANG_UNIVERSAL);
    else
        bot->Say(text, LANG_UNIVERSAL);

    ai->GetAiObjectContext()->GetValue<time_t>("last said", qualifier)->Set(time(0));
}


bool SayAction::isUseful()
{
    time_t lastSaid = AI_VALUE2(time_t, "last said", qualifier);
    return (time(0) - lastSaid) > 30;
}