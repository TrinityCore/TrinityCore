#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "ListQuestsActions.h"


using namespace ai;

bool ListQuestsAction::Execute(Event event)
{
    if (event.getParam() == "completed")
    {
        ListQuests(QUEST_LIST_FILTER_COMPLETED);
    }
    else if (event.getParam() == "incompleted")
    {
        ListQuests(QUEST_LIST_FILTER_INCOMPLETED);
    }
    else if (event.getParam() == "all")
    {
        ListQuests(QUEST_LIST_FILTER_ALL);
    }
    else
    {
        ListQuests(QUEST_LIST_FILTER_SUMMARY);
    }
    return true;
}

void ListQuestsAction::ListQuests(QuestListFilter filter)
{
    bool showIncompleted = filter & QUEST_LIST_FILTER_INCOMPLETED;
    bool showCompleted = filter & QUEST_LIST_FILTER_COMPLETED;

    if (showIncompleted)
        ai->TellMaster("--- Incomplete quests ---");
    int incompleteCount = ListQuests(false, !showIncompleted);

    if (showCompleted)
        ai->TellMaster("--- Complete quests ---");
    int completeCount = ListQuests(true, !showCompleted);

    ai->TellMaster("--- Summary ---");
    std::ostringstream out;
    out << "Total: " << (completeCount + incompleteCount) << " / 25 (incomplete: " << incompleteCount << ", complete: " << completeCount << ")";
    ai->TellMaster(out);
}

int ListQuestsAction::ListQuests(bool completed, bool silent)
{
    int count = 0;
    for (uint16 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 questId = bot->GetQuestSlotQuestId(slot);
        if (!questId)
            continue;

        Quest const* pQuest = sObjectMgr->GetQuestTemplate(questId);
        bool isCompletedQuest = bot->GetQuestStatus(questId) == QUEST_STATUS_COMPLETE;
        if (completed != isCompletedQuest)
            continue;

        count++;

        if (silent)
            continue;

        ai->TellMaster(chat->formatQuest(pQuest));
    }

    return count;
}
