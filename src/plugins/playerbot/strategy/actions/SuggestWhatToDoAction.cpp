#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SuggestWhatToDoAction.h"
#include "../../../ahbot/AhBot.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

SuggestWhatToDoAction::SuggestWhatToDoAction(PlayerbotAI* ai) : InventoryAction(ai, "suggest what to do"), suggested(false)
{
    suggestions.push_back(&SuggestWhatToDoAction::instance);
    suggestions.push_back(&SuggestWhatToDoAction::specificQuest);
    suggestions.push_back(&SuggestWhatToDoAction::newQuest);
    suggestions.push_back(&SuggestWhatToDoAction::grindMaterials);
    suggestions.push_back(&SuggestWhatToDoAction::trade);
    suggestions.push_back(&SuggestWhatToDoAction::grindReputation);
    suggestions.push_back(&SuggestWhatToDoAction::nothing);
    suggestions.push_back(&SuggestWhatToDoAction::relax);
    suggestions.push_back(&SuggestWhatToDoAction::achievement);
}

bool SuggestWhatToDoAction::Execute(Event event)
{
    if (suggested)
    {
        trade();
        return true;
    }

    if (bot->GetInstanceId() || suggested)
        return false;

    int index = rand() % suggestions.size();
    (this->*suggestions[index])();

    return suggested = true;
}

void SuggestWhatToDoAction::instance()
{
    uint32 level = bot->getLevel();
    if (level > 15)
    {
        switch (urand(0, 5))
        {
        case 0:
            spam("Need a tank for an instance run");
            break;
        case 1:
            spam("Need a healer for an instance run");
            break;
        case 2:
            spam("I would like to do an instance run. Would you like to join me?");
            break;
        case 3:
            spam("Need better equipment. Why not do an instance run?");
            break;
        case 4:
            spam("Have dungeon quests? Can join your group!");
            break;
        case 5:
            spam("Have group quests? Invite me!");
            break;
        default:
            spam("Hey, why not join Dungeon Finder?");
        }
    }
}

vector<uint32> SuggestWhatToDoAction::GetIncompletedQuests()
{
    vector<uint32> result;

    for (uint16 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 questId = bot->GetQuestSlotQuestId(slot);
        if (!questId)
            continue;

        QuestStatus status = bot->GetQuestStatus(questId);
        if (status == QUEST_STATUS_INCOMPLETE || status == QUEST_STATUS_NONE)
            result.push_back(questId);
    }

    return result;
}

void SuggestWhatToDoAction::specificQuest()
{
    vector<uint32> quests = GetIncompletedQuests();
    if (quests.empty())
        return;

    int index = rand() % quests.size();

    Quest const* quest = sObjectMgr->GetQuestTemplate(quests[index]);
    ostringstream out; out << "We could do some quest, for instance " << chat->formatQuest(quest);
    spam(out.str());
}

void SuggestWhatToDoAction::newQuest()
{
    vector<uint32> quests = GetIncompletedQuests();
    if (quests.size() < MAX_QUEST_LOG_SIZE - 5)
        spam("I would like to pick up and do a new quest. Just invite me!");
}

void SuggestWhatToDoAction::grindMaterials()
{
    if (bot->getLevel() <= 5)
        return;

    switch (urand(0, 5))
    {
    case 0:
        spam("Need help for tradeskill?");
        break;
    case 1:
        spam("Can we have some trade material grinding?");
        break;
    case 2:
        spam("I have some trade materials for sell");
        break;
    default:
        spam("I am going to grind some trade materials. Would you like to join me?");
    }
}

void SuggestWhatToDoAction::grindReputation()
{
    if (bot->getLevel() > 15)
        ai->TellMasterNoFacing("I think we should do something to improve our reputation", PLAYERBOT_SECURITY_ALLOW_ALL);
}

void SuggestWhatToDoAction::nothing()
{
    ai->TellMasterNoFacing("I don't want to do anything", PLAYERBOT_SECURITY_ALLOW_ALL);
}

void SuggestWhatToDoAction::relax()
{
    ai->TellMasterNoFacing("It is so boring... We could relax a bit", PLAYERBOT_SECURITY_ALLOW_ALL);
}

void SuggestWhatToDoAction::achievement()
{
    if (bot->getLevel() > 15)
        spam("I would like to get some achievement. Would you like to join me?");
}

class FindTradeItemsVisitor : public IterateItemsVisitor
{
public:
    FindTradeItemsVisitor(uint32 quality) : quality(quality), IterateItemsVisitor() {}

    virtual bool Visit(Item* item)
    {
        ItemTemplate const* proto = item->GetTemplate();
        if (proto->Quality != quality)
            return true;

        if (proto->Class == ITEM_CLASS_TRADE_GOODS && proto->Bonding == NO_BIND)
        {
            if(proto->Quality == ITEM_QUALITY_NORMAL && item->GetCount() > 1 && item->GetCount() == item->GetMaxStackCount())
                stacks.push_back(proto->ItemId);

            items.push_back(proto->ItemId);
            count[proto->ItemId] += item->GetCount();
        }

        return true;
    }

    map<uint32, int > count;
    vector<uint32> stacks;
    vector<uint32> items;

private:
    uint32 quality;
};


void SuggestWhatToDoAction::trade()
{
    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
        return;

    uint32 quality = urand(0, 100);
    if (quality > 90)
        quality = ITEM_QUALITY_EPIC;
    else if (quality >75)
        quality = ITEM_QUALITY_RARE;
    else if (quality > 50)
        quality = ITEM_QUALITY_UNCOMMON;
    else
        quality = ITEM_QUALITY_NORMAL;

    uint32 item = 0, count = 0;
    while (quality-- > ITEM_QUALITY_POOR)
    {
        FindTradeItemsVisitor visitor(quality);
        IterateItems(&visitor);
        if (!visitor.stacks.empty())
        {
            int index = urand(0, visitor.stacks.size() - 1);
            item = visitor.stacks[index];
        }

        if (!item)
        {
            if (!visitor.items.empty())
            {
                int index = urand(0, visitor.items.size() - 1);
                item = visitor.items[index];
            }
        }

        if (item)
        {
            count = visitor.count[item];
            break;
        }
    }

    if (!item || !count)
        return;

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item);
    if (!proto)
        return;

    uint32 price = auctionbot.GetSellPrice(proto) * sRandomPlayerbotMgr.GetSellMultiplier(bot) * count;
    if (!price)
        return;

    ostringstream out; out << "Selling " << chat->formatItem(proto, count) << " for " << chat->formatMoney(price);
    spam(out.str());
}

void SuggestWhatToDoAction::spam(string msg)
{
    Player* player = sRandomPlayerbotMgr.GetRandomPlayer();
    if (!player || !player->IsInWorld())
        return;

    if (!ai->GetSecurity()->CheckLevelFor(PLAYERBOT_SECURITY_TALK, true, player))
        return;

    if (sPlayerbotAIConfig.whisperDistance && !bot->GetGroup() && sRandomPlayerbotMgr.IsRandomBot(bot) &&
            player->GetSession()->GetSecurity() < SEC_GAMEMASTER &&
            (bot->GetMapId() != player->GetMapId() || bot->GetDistance(player) > sPlayerbotAIConfig.whisperDistance))
        return;

    bot->Whisper(msg, LANG_UNIVERSAL, player);
}
