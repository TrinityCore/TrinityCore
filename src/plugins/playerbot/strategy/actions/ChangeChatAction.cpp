#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ChangeChatAction.h"


using namespace ai;


bool ChangeChatAction::Execute(Event event)
{
    string text = event.getParam();
    ChatMsg parsed = chat->parseChat(text);
    if (parsed == CHAT_MSG_SYSTEM)
    {
        ostringstream out; out << "Current chat is " << chat->formatChat(*context->GetValue<ChatMsg>("chat"));
        ai->TellMaster(out);
    }
    else
    {
        context->GetValue<ChatMsg>("chat")->Set(parsed);
        ostringstream out; out << "Chat set to " << chat->formatChat(parsed);
        ai->TellMaster(out);
    }
    
    return true;
}
