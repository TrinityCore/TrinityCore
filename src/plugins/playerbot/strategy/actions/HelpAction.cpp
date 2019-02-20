#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "HelpAction.h"
#include "ChatActionContext.h"

using namespace ai;

HelpAction::HelpAction(PlayerbotAI* ai) : Action(ai, "help")
{
    chatContext = new ChatActionContext();
}

HelpAction::~HelpAction()
{
    delete chatContext;
}

bool HelpAction::Execute(Event event)
{
    TellChatCommands();
    TellStrategies();
    return true;
}

void HelpAction::TellChatCommands()
{
    ostringstream out;
    out << "Whisper any of: ";
    out << CombineSupported(chatContext->supports());
    out << ", [item], [quest] or [object] link";
    ai->TellMaster(out);
}

void HelpAction::TellStrategies()
{
    ostringstream out;
    out << "Possible strategies (co/nc/dead commands): ";
    out << CombineSupported(ai->GetAiObjectContext()->GetSupportedStrategies());
    ai->TellMaster(out);
}

string HelpAction::CombineSupported(set<string> commands)
{
    ostringstream out;

    for (set<string>::iterator i = commands.begin(); i != commands.end(); )
	{
        out << *i;
		if (++i != commands.end())
			out << ", ";
	}

    return out.str();
}
