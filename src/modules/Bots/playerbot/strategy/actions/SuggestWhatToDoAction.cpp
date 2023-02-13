#include "botpch.h"
#include "../../playerbot.h"
#include "SuggestWhatToDoAction.h"
#include "../../../ahbot/AhBot.h"
#include "../../../ahbot/PricingStrategy.h"
#include "../../AiFactory.h"
#include "ChannelMgr.h"
#include "../../PlayerbotAIConfig.h"
#include "../../PlayerbotTextMgr.h"

using ahbot::PricingStrategy;

using namespace ai;

map<string, int> SuggestWhatToDoAction::instances;
map<string, int> SuggestWhatToDoAction::factions;

SuggestWhatToDoAction::SuggestWhatToDoAction(PlayerbotAI* ai, string name) : InventoryAction(ai, name)
{
    suggestions.push_back(&SuggestWhatToDoAction::instance);
    suggestions.push_back(&SuggestWhatToDoAction::specificQuest);
    suggestions.push_back(&SuggestWhatToDoAction::grindMaterials);
    suggestions.push_back(&SuggestWhatToDoAction::grindReputation);
    suggestions.push_back(&SuggestWhatToDoAction::something);
}

bool SuggestWhatToDoAction::Execute(Event event)
{
    if (!sRandomPlayerbotMgr.IsRandomBot(bot) || bot->GetGroup() || bot->GetInstanceId())
        return false;

    int index = rand() % suggestions.size();
    (this->*suggestions[index])();

    string qualifier = "suggest what to do";
    time_t lastSaid = AI_VALUE2(time_t, "last said", qualifier);
    ai->GetAiObjectContext()->GetValue<time_t>("last said", qualifier)->Set(time(0) + urand(1, 60));

    return true;
}

void SuggestWhatToDoAction::instance()
{
    if (instances.empty())
    {
        instances["Ragefire Chasm"] = 15;
        instances["Deadmines"] = 18;
        instances["Wailing Caverns"] = 18;
        instances["Shadowfang Keep"] = 25;
        instances["Blackfathom Deeps"] = 20;
        instances["Stockade"] = 20;
        instances["Gnomeregan"] = 35;
        instances["Razorfen Kraul"] = 35;
        instances["Maraudon"] = 50;
        instances["Scarlet Monestery"] = 40;
        instances["Uldaman"] = 45;
        instances["Dire Maul"] = 58;
        instances["Scholomance"] = 59;
        instances["Razorfen Downs"] = 40;
        instances["Strathholme"] = 59;
        instances["Zul'Farrak"] = 45;
        instances["Blackrock Depths"] = 55;
        instances["Temple of Atal'Hakkar"] = 55;
        instances["Lower Blackrock Spire"] = 57;

        instances["Hellfire Citidel"] = 65;
        instances["Coilfang Reservoir"] = 65;
        instances["Auchindoun"] = 65;
        instances["Cavens of Time"] = 68;
        instances["Tempest Keep"] = 69;
        instances["Magister's Terrace"] = 70;

        instances["Utgarde Keep"] = 75;
        instances["The Nexus"] = 75;
        instances["Ahn'kahet: The Old Kingdom"] = 75;
        instances["Azjol-Nerub"] = 75;
        instances["Drak'Tharon Keep"] = 75;
        instances["Violet Hold"] = 80;
        instances["Gundrak"] = 77;
        instances["Halls of Stone"] = 77;
        instances["Halls of Lightning"] = 77;
        instances["Oculus"] = 77;
        instances["Utgarde Pinnacle"] = 77;
        instances["Trial of the Champion"] = 80;
        instances["Forge of Souls"] = 80;
        instances["Pit of Saron"] = 80;
        instances["Halls of Reflection"] = 80;
    }

    vector<string> allowedInstances;
    for (map<string, int>::iterator i = instances.begin(); i != instances.end(); ++i)
    {
        if (bot->getLevel() >= i->second) allowedInstances.push_back(i->first);
    }

    if (allowedInstances.empty()) return;

    map<string, string> placeholders;
    placeholders["%role"] = chat->formatClass(bot, AiFactory::GetPlayerSpecTab(bot));

    ostringstream itemout;
    itemout << "|c00b000b0" << allowedInstances[urand(0, allowedInstances.size() - 1)] << "|r";
    placeholders["%instance"] = itemout.str();

    spam(sPlayerbotTextMgr.Format("suggest_instance", placeholders));
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

    Quest const* quest = sObjectMgr.GetQuestTemplate(quests[index]);

    map<string, string> placeholders;
    placeholders["%role"] = chat->formatClass(bot, AiFactory::GetPlayerSpecTab(bot));
    placeholders["%quest"] = chat->formatQuest(quest);

    spam(sPlayerbotTextMgr.Format("suggest_quest", placeholders));
}

void SuggestWhatToDoAction::grindMaterials()
{
    if (bot->getLevel() <= 5)
        return;

    QueryResult *result = PlayerbotDatabase.PQuery("SELECT distinct category, multiplier FROM ahbot_category where category not in ('other', 'quest', 'trade', 'reagent') and multiplier > 3 order by multiplier desc limit 10");
    if (!result)
        return;

    map<string, double> categories;
    do
    {
        Field* fields = result->Fetch();
        categories[fields[0].GetCppString()] = fields[1].GetFloat();
    } while (result->NextRow());
    delete result;

    for (map<string, double>::iterator i = categories.begin(); i != categories.end(); ++i)
    {
        if (urand(0, 10) < 3) {
            string name = i->first;
            double multiplier = i->second;

            for (int j = 0; j < ahbot::CategoryList::instance.size(); j++)
            {
                ahbot::Category* category = ahbot::CategoryList::instance[j];
                if (name == category->GetName())
                {
                    string item = category->GetLabel();
                    transform(item.begin(), item.end(), item.begin(), tolower);
                    ostringstream itemout;
                    itemout << "|c0000b000" << item << "|r";
                    item = itemout.str();

                    map<string, string> placeholders;
                    placeholders["%role"] = chat->formatClass(bot, AiFactory::GetPlayerSpecTab(bot));
                    placeholders["%category"] = item;

                    spam(sPlayerbotTextMgr.Format("suggest_trade", placeholders));
                    return;
                }
            }
        }
    }
}

void SuggestWhatToDoAction::grindReputation()
{
    if (factions.empty())
    {
        factions["Argent Dawn"] = 60;
        factions["Bloodsail Buccaneers"] = 40;
        factions["Brood of Nozdormu"] = 60;
        factions["Cenarion Circle"] = 55;
        factions["Darkmoon Faire"] = 20;
        factions["Hydraxian Waterlords"] = 60;
        factions["Ravenholdt"] = 20;
        factions["Thorium Brotherhood"] = 40;
        factions["Timbermaw Hold"] = 50;
        factions["Wintersaber Trainers"] = 50;
        factions["Booty Bay"] = 30;
        factions["Everlook"] = 40;
        factions["Gadgetzan"] = 50;
        factions["Ratchet"] = 20;

#ifdef MANGOSBOT_ONE
        factions["Ashtongue Deathsworn"] = 70;
        factions["Cenarion Expedition"] = 62;
        factions["The Consortium"] = 65;
        factions["Honor Hold"] = 66;
        factions["Keepers of Time"] = 68;
        factions["Netherwing"] = 65;
        factions["Ogri'la"] = 65;
        factions["The Scale of the Sands"] = 65;
        factions["Sporeggar"] = 65;
        factions["Tranquillien"] = 10;
        factions["The Violet Eye"] = 70;
#endif

#ifdef MANGOSBOT_TWO
        factions["Argent Crusade"] = 75;
        factions["Ashen Verdict"] = 75;
        factions["The Kalu'ak"] = 72;
        factions["Kirin Tor"] = 75;
        factions["Knights of the Ebon Blade"] = 77;
        factions["The Sons of Hodir"] = 78;
        factions["The Wyrmrest Accord"] = 77;
#endif
    }

    vector<string> levels;
    levels.push_back("honored");
    levels.push_back("revered");
    levels.push_back("exalted");

    vector<string> allowedFactions;
    for (map<string, int>::iterator i = factions.begin(); i != factions.end(); ++i) {
        if (bot->getLevel() >= i->second) allowedFactions.push_back(i->first);
    }

    if (allowedFactions.empty()) return;

    map<string, string> placeholders;
    placeholders["%role"] = chat->formatClass(bot, AiFactory::GetPlayerSpecTab(bot));
    placeholders["%level"] = levels[urand(0, 2)];
    ostringstream rnd; rnd << urand(1, 5) << "K";
    placeholders["%rndK"] = rnd.str();

    ostringstream itemout;
    itemout << "|c004040b0" << allowedFactions[urand(0, allowedFactions.size() - 1)] << "|r";
    placeholders["%faction"] = itemout.str();

    spam(sPlayerbotTextMgr.Format("suggest_faction", placeholders));
}

void SuggestWhatToDoAction::something()
{
    map<string, string> placeholders;
    placeholders["%role"] = chat->formatClass(bot, AiFactory::GetPlayerSpecTab(bot));

    AreaTableEntry const* entry = GetAreaEntryByAreaID(bot->GetAreaId());
    if (!entry)
        return;

    ostringstream out;
    out << "|cffb04040" << entry->area_name[0] << "|r";
    placeholders["%zone"] = out.str();

    spam(sPlayerbotTextMgr.Format("suggest_something", placeholders));
}

void SuggestWhatToDoAction::spam(string msg, uint32 channelId)
{
    set<string> said;
    for (uint32 i = 0; i < sChatChannelsStore.GetNumRows(); ++i)
    {
        ChatChannelsEntry const* channel = sChatChannelsStore.LookupEntry(i);
        if (!channel || channel->ChannelID != channelId) continue;

        for (uint32 j = 0; j < sAreaStore.GetNumRows(); ++j)
        {
            AreaTableEntry const* area = sAreaStore.LookupEntry(j);
            if (!area) continue;

            char channelName[255];
            snprintf(channelName, 255, channel->pattern[0], area->area_name[0]);
            if (said.find(channelName) != said.end()) continue;

            if (ChannelMgr* cMgr = channelMgr(bot->GetTeam()))
            {
                if (Channel* chn = cMgr->GetJoinChannel(channelName
#ifdef MANGOSBOT_ONE
                    , channel->ChannelID
#endif
                ))
                {
                    chn->Join(bot, "");
                    chn->Say(bot, msg.c_str(), LANG_UNIVERSAL);
                    said.insert(channelName);
                }
            }
        }
    }
}


class FindTradeItemsVisitor : public IterateItemsVisitor
{
public:
    FindTradeItemsVisitor(uint32 quality) : quality(quality), IterateItemsVisitor() {}

    virtual bool Visit(Item* item)
    {
        ItemPrototype const* proto = item->GetProto();
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


SuggestTradeAction::SuggestTradeAction(PlayerbotAI* ai) : SuggestWhatToDoAction(ai, "suggest trade")
{
}

bool SuggestTradeAction::Execute(Event event)
{
    if (!sRandomPlayerbotMgr.IsRandomBot(bot) || bot->GetGroup() || bot->GetInstanceId())
        return false;

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
        return false;

    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(item);
    if (!proto)
        return false;

    uint32 price = PricingStrategy::RoundPrice(auctionbot.GetSellPrice(proto) * sRandomPlayerbotMgr.GetSellMultiplier(bot) * count);
    if (!price)
        return false;

    map<string, string> placeholders;
    placeholders["%item"] = chat->formatItem(proto, count);
    placeholders["%gold"] = chat->formatMoney(price);

    spam(sPlayerbotTextMgr.Format("suggest_sell", placeholders));
    return true;
}

bool SuggestWhatToDoAction::isUseful()
{
    string qualifier = "suggest what to do";
    time_t lastSaid = AI_VALUE2(time_t, "last said", qualifier);
    return (time(0) - lastSaid) > 30;
}
