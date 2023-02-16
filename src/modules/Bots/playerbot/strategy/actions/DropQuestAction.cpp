#include "botpch.h"
#include "../../playerbot.h"
#include "DropQuestAction.h"


using namespace ai;

bool DropQuestAction::Execute(Event event)
{
    string link = event.getParam();
    if (!GetMaster())
        return false;

    PlayerbotChatHandler handler(GetMaster());
    uint32 entry = handler.extractQuestId(link);
    if (!entry)
        return false;

    Quest const* quest = sObjectMgr.GetQuestTemplate(entry);
    if (!quest)
        return false;

    // remove all quest entries for 'entry' from quest log
    for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 logQuest = bot->GetQuestSlotQuestId(slot);
        if (logQuest == entry)
        {
            bot->SetQuestSlot(slot, 0);

            // we ignore unequippable quest items in this case, its' still be equipped
            bot->TakeQuestSourceItem(logQuest, false);
        }
    }

    bot->SetQuestStatus(entry, QUEST_STATUS_NONE);
    bot->getQuestStatusMap()[entry].m_rewarded = false;

    ai->TellMaster("Quest removed");
    return true;
}
