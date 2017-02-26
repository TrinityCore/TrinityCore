#include "../../pchdef.h"
#include "../playerbot.h"
#include "AiObject.h"

AiObject::AiObject(PlayerbotAI* ai) :
    PlayerbotAIAware(ai),
    bot(ai->GetBot()),
    context(ai->GetAiObjectContext()),
    chat(ai->GetChatHelper())
{
}

Player* AiObject::GetMaster()
{
    return ai->GetMaster();
}
