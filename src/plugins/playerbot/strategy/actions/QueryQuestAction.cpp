#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "QueryQuestAction.h"


using namespace ai;

void QueryQuestAction::TellObjective(string name, int available, int required)
{
    ai->TellMaster(chat->formatQuestObjective(name, available, required));
}


bool QueryQuestAction::Execute(Event event)
{

    Player *bot = ai->GetBot();
    string text = event.getParam();

    PlayerbotChatHandler ch(bot);
    uint32 questId = ch.extractQuestId(text);
    if (!questId)
        return false;

    for (uint16 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        if(questId != bot->GetQuestSlotQuestId(slot))
            continue;

        ostringstream out;
        out << "--- " << chat->formatQuest(sObjectMgr->GetQuestTemplate(questId)) << " ";
        if (bot->GetQuestStatus(questId) == QUEST_STATUS_COMPLETE)
        {
            out << "|c0000FF00completed|r ---";
            ai->TellMaster(out);
        }
        else
        {
            out << "|c00FF0000not completed|r ---";
            ai->TellMaster(out);
            TellObjectives(questId);
        }

        return true;
    }

    return false;
}

void QueryQuestAction::TellObjectives(uint32 questId)
{
    Quest const* questTemplate = sObjectMgr->GetQuestTemplate(questId);
    QuestStatusMap &questMap = bot->getQuestStatusMap();
    QuestStatusData questStatus = questMap[questId];

    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; i++)
    {
        if (!questTemplate->ObjectiveText[i].empty())
            ai->TellMaster(questTemplate->ObjectiveText[i]);

        if (questTemplate->RequiredItemId[i])
        {
            int required = questTemplate->RequiredItemCount[i];
            int available = questStatus.ItemCount[i];
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(questTemplate->RequiredItemId[i]);
            TellObjective(chat->formatItem(proto), available, required);
        }

        if (questTemplate->RequiredNpcOrGo[i])
        {
            int required = questTemplate->RequiredNpcOrGoCount[i];
            int available = questStatus.CreatureOrGOCount[i];

            if (questTemplate->RequiredNpcOrGo[i] < 0)
            {
                GameObjectTemplate const* info = sObjectMgr->GetGameObjectTemplate(questTemplate->RequiredNpcOrGo[i]);
                if (info)
                    TellObjective(info->name, available, required);
            }
            else
            {

                CreatureTemplate const* info = sObjectMgr->GetCreatureTemplate(questTemplate->RequiredNpcOrGo[i]);
                if (info)
                    TellObjective(info->Name, available, required);
            }
        }
    }
}
