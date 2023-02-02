#include "botpch.h"
#include "../../playerbot.h"
#include "QueryItemUsageAction.h"
#include "../../../ahbot/AhBot.h"
#include "../values/ItemUsageValue.h"
#include "../../RandomPlayerbotMgr.h"


using namespace ai;


bool QueryItemUsageAction::Execute(Event event)
{
    if (!GetMaster())
        return false;

    WorldPacket& data = event.getPacket();
    if (!data.empty())
    {
        data.rpos(0);

        ObjectGuid guid;
        data >> guid;
        if (guid != bot->GetObjectGuid())
            return false;

        uint32 received, created, isShowChatMessage, notUsed, itemId,
            suffixFactor, itemRandomPropertyId, count, invCount;
        uint8 bagSlot;

        data >> received;                               // 0=looted, 1=from npc
        data >> created;                                // 0=received, 1=created
        data >> isShowChatMessage;                                      // IsShowChatMessage
        data >> bagSlot;
                                                                // item slot, but when added to stack: 0xFFFFFFFF
        data >> notUsed;
        data >> itemId;
        data >> suffixFactor;
        data >> itemRandomPropertyId;
        data >> count;
        // data >> invCount; // [-ZERO] count of items in inventory

        ItemPrototype const *item = sItemStorage.LookupEntry<ItemPrototype>(itemId);
        if (!item)
            return false;

        ai->TellMaster(QueryItem(item, count, GetCount(item)));
        return true;
    }

    string text = event.getParam();
    ItemIds items = chat->parseItems(text);
    for (ItemIds::iterator i = items.begin(); i != items.end(); i++)
    {
        ItemPrototype const *item = sItemStorage.LookupEntry<ItemPrototype>(*i);
        if (!item) continue;

        ai->TellMaster(QueryItem(item, 0, GetCount(item)));
    }
    return true;
}

uint32 QueryItemUsageAction::GetCount(ItemPrototype const *item)
{
    uint32 total = 0;
    list<Item*> items = InventoryAction::parseItems(item->Name1);
    if (!items.empty())
    {
        for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
        {
            total += (*i)->GetCount();
        }
    }
    return total;
}

string QueryItemUsageAction::QueryItem(ItemPrototype const *item, uint32 count, uint32 total)
{
    ostringstream out;
    string usage = QueryItemUsage(item);
    string quest = QueryQuestItem(item->ItemId);
    string price = QueryItemPrice(item);
    if (usage.empty())
        usage = (quest.empty() ? "Useless" : "Quest");

    out << chat->formatItem(item, count, total) << ": " << usage;
    if (!quest.empty())
        out << ", " << quest;
    if (!price.empty())
        out << ", " << price;
    return out.str();
}

string QueryItemUsageAction::QueryItemUsage(ItemPrototype const *item)
{
    ostringstream out; out << item->ItemId;
    ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());
    switch (usage)
    {
    case ITEM_USAGE_EQUIP:
        return "Equip";
    case ITEM_USAGE_REPLACE:
        return "Equip (replace)";
    case ITEM_USAGE_SKILL:
        return "Tradeskill";
    case ITEM_USAGE_USE:
        return "Use";
	case ITEM_USAGE_GUILD_TASK:
		return "Guild task";
	case ITEM_USAGE_DISENCHANT:
		return "Disenchant";
	}

    return "";
}

string QueryItemUsageAction::QueryItemPrice(ItemPrototype const *item)
{
    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
        return "";

    if (item->Bonding == BIND_WHEN_PICKED_UP)
        return "";

    ostringstream msg;
    list<Item*> items = InventoryAction::parseItems(item->Name1);
    int32 sellPrice = 0;
    if (!items.empty())
    {
        for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
        {
            Item* sell = *i;
            sellPrice = sell->GetCount() * auctionbot.GetSellPrice(sell->GetProto()) * sRandomPlayerbotMgr.GetSellMultiplier(bot);
            msg << "Sell: " << chat->formatMoney(sellPrice);
        }
    }

    ostringstream out; out << item->ItemId;
    ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());
    if (usage == ITEM_USAGE_NONE)
        return msg.str();

    int32 buyPrice = auctionbot.GetBuyPrice(item) * sRandomPlayerbotMgr.GetBuyMultiplier(bot);
    if (buyPrice)
    {
        if (sellPrice) msg << " ";
        msg << "Buy: " << chat->formatMoney(buyPrice);
    }

    return msg.str();
}

string QueryItemUsageAction::QueryQuestItem(uint32 itemId)
{
    Player *bot = ai->GetBot();
    QuestStatusMap& questMap = bot->getQuestStatusMap();
    for (QuestStatusMap::const_iterator i = questMap.begin(); i != questMap.end(); i++)
    {
        const Quest *questTemplate = sObjectMgr.GetQuestTemplate( i->first );
        if( !questTemplate )
            continue;

        uint32 questId = questTemplate->GetQuestId();
        QuestStatus status = bot->GetQuestStatus(questId);
        if (status == QUEST_STATUS_INCOMPLETE || (status == QUEST_STATUS_COMPLETE && !bot->GetQuestRewardStatus(questId)))
        {
            QuestStatusData const& questStatus = i->second;
            string usage = QueryQuestItem(itemId, questTemplate, &questStatus);
            if (!usage.empty()) return usage;
        }
    }

    return "";
}


string QueryItemUsageAction::QueryQuestItem(uint32 itemId, const Quest *questTemplate, const QuestStatusData *questStatus)
{
    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; i++)
    {
        if (questTemplate->ReqItemId[i] != itemId)
            continue;

        int required = questTemplate->ReqItemCount[i];
        int available = questStatus->m_itemcount[i];

        if (!required)
            continue;

        return chat->formatQuestObjective(chat->formatQuest(questTemplate), available, required);
    }

    return "";
}

