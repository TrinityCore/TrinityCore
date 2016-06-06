#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "RewardAction.h"
#include "../ItemVisitors.h"
#include "../values/ItemCountValue.h"

using namespace ai;

bool RewardAction::Execute(Event event)
{
    string link = event.getParam();

    ItemIds itemIds = chat->parseItems(link);
    if (itemIds.empty())
        return false;

    uint32 itemId = *itemIds.begin();

    list<ObjectGuid> npcs = AI_VALUE(list<ObjectGuid>, "nearest npcs");
    for (list<ObjectGuid>::iterator i = npcs.begin(); i != npcs.end(); i++)
    {
        Unit* npc = ai->GetUnit(*i);
        if (npc && Reward(itemId, npc))
            return true;
    }

    list<ObjectGuid> gos = AI_VALUE(list<ObjectGuid>, "nearest game objects");
    for (list<ObjectGuid>::iterator i = gos.begin(); i != gos.end(); i++)
    {
        GameObject* go = ai->GetGameObject(*i);
        if (go && Reward(itemId, go))
            return true;
    }

    ai->TellMaster("Cannot talk to quest giver");
    return false;
}

bool RewardAction::Reward(uint32 itemId, Object* questGiver)
{
    QuestMenu& questMenu = bot->PlayerTalkClass->GetQuestMenu();
    for (uint32 iI = 0; iI < questMenu.GetMenuItemCount(); ++iI)
    {
        QuestMenuItem const& qItem = questMenu.GetItem(iI);

        uint32 questID = qItem.QuestId;
        Quest const* pQuest = sObjectMgr->GetQuestTemplate(questID);
        QuestStatus status = bot->GetQuestStatus(questID);

        // if quest is complete, turn it in
        if (status == QUEST_STATUS_COMPLETE &&
            ! bot->GetQuestRewardStatus(questID) &&
            pQuest->GetRewChoiceItemsCount() > 1 &&
            bot->CanRewardQuest(pQuest, false))
        {
            for (uint8 rewardIdx=0; rewardIdx < pQuest->GetRewChoiceItemsCount(); ++rewardIdx)
            {
                ItemTemplate const * const pRewardItem = sObjectMgr->GetItemTemplate(pQuest->RewardChoiceItemId[rewardIdx]);
                if (itemId == pRewardItem->ItemId)
                {
                    bot->RewardQuest(pQuest, rewardIdx, questGiver, false);

                    string questTitle  = pQuest->GetTitle();
                    string itemName = pRewardItem->Name1;

                    ostringstream out; out << chat->formatItem(pRewardItem) << " rewarded";
                    ai->TellMaster(out);
                    return true;
                }
            }
        }
    }

    return false;
}
