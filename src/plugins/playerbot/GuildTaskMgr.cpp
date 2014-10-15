#include "../pchdef.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "GuildTaskMgr.h"

#include "../../plugins/ahbot/AhBot.h"
#include "../../server/game/Guilds/GuildMgr.h"
#include "../../shared/Database/DatabaseEnv.h"
#include "../../server/game/Mails/Mail.h"
#include "PlayerbotAI.h"

#include "../../plugins/ahbot/AhBotConfig.h"

char * strstri (const char* str1, const char* str2);

enum GuildTaskType
{
    GUILD_TASK_TYPE_NONE = 0,
    GUILD_TASK_TYPE_ITEM = 1,
    GUILD_TASK_TYPE_KILL = 2
};

GuildTaskMgr::GuildTaskMgr()
{
}

GuildTaskMgr::~GuildTaskMgr()
{
}

void GuildTaskMgr::Update(Player* player, Player* guildMaster)
{
    if (!sPlayerbotAIConfig.guildTaskEnabled)
        return;

    uint32 guildId = guildMaster->GetGuildId();
    if (!guildId || !guildMaster->GetPlayerbotAI() || !guildMaster->GetGuild())
        return;

    if (!player->IsFriendlyTo(guildMaster))
        return;

    if (!guildMaster->GetPlayerbotAI()->GetSecurity()->CheckLevelFor(PLAYERBOT_SECURITY_INVITE, true, player, true))
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: skipping guild task update - not enough security level",
                guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        return;
    }

    uint32 owner = (uint32)player->GetGUID().GetRawValue();

    uint32 activeTask = GetTaskValue(owner, guildId, "activeTask");
    if (!activeTask)
    {
        SetTaskValue(owner, guildId, "itemTask", 0, 0);
        SetTaskValue(owner, guildId, "itemCount", 0, 0);
        SetTaskValue(owner, guildId, "killTask", 0, 0);
        SetTaskValue(owner, guildId, "killCount", 0, 0);
        SetTaskValue(owner, guildId, "payment", 0, 0);
        SetTaskValue(owner, guildId, "thanks", 1, 2 * sPlayerbotAIConfig.maxGuildTaskChangeTime);
        SetTaskValue(owner, guildId, "reward", 1, 2 * sPlayerbotAIConfig.maxGuildTaskChangeTime);

        uint32 task = CreateTask(owner, guildId);

        if (task == GUILD_TASK_TYPE_NONE)
        {
            sLog->outMessage("gtask", LOG_LEVEL_ERROR, "%s / %s: error creating guild task",
                    guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        }

        uint32 time = urand(sPlayerbotAIConfig.minGuildTaskChangeTime, sPlayerbotAIConfig.maxGuildTaskChangeTime);
        SetTaskValue(owner, guildId, "activeTask", task, time);
        SetTaskValue(owner, guildId, "advertisement", 1,
                urand(sPlayerbotAIConfig.minGuildTaskAdvertisementTime, sPlayerbotAIConfig.maxGuildTaskAdvertisementTime));

        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: guild task %u is set for %u secs",
                guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str(),
                task, time);
        return;
    }

    uint32 advertisement = GetTaskValue(owner, guildId, "advertisement");
    if (!advertisement)
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: sending advertisement",
                guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        if (SendAdvertisement(owner, guildId))
        {
            SetTaskValue(owner, guildId, "advertisement", 1,
                    urand(sPlayerbotAIConfig.minGuildTaskAdvertisementTime, sPlayerbotAIConfig.maxGuildTaskAdvertisementTime));
        }
        else
        {
            sLog->outMessage("gtask", LOG_LEVEL_ERROR, "%s / %s: error sending advertisement",
                    guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        }
    }

    uint32 thanks = GetTaskValue(owner, guildId, "thanks");
    if (!thanks)
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: sending thanks",
                guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        if (SendThanks(owner, guildId))
        {
            SetTaskValue(owner, guildId, "thanks", 1, 2 * sPlayerbotAIConfig.maxGuildTaskChangeTime);
        }
        else
        {
            sLog->outMessage("gtask", LOG_LEVEL_ERROR, "%s / %s: error sending thanks",
                    guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        }
    }

    uint32 reward = GetTaskValue(owner, guildId, "reward");
    if (!reward)
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: sending reward",
                guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        if (Reward(owner, guildId))
        {
            SetTaskValue(owner, guildId, "reward", 1, 2 * sPlayerbotAIConfig.maxGuildTaskChangeTime);
        }
        else
        {
            sLog->outMessage("gtask", LOG_LEVEL_ERROR, "%s / %s: error sending reward",
                    guildMaster->GetGuild()->GetName().c_str(), player->GetName().c_str());
        }
    }
}

uint32 GuildTaskMgr::CreateTask(uint32 owner, uint32 guildId)
{
    if (CreateItemTask(owner, guildId))
        return GUILD_TASK_TYPE_ITEM;

    return GUILD_TASK_TYPE_NONE;
    /*
    switch (urand(0, 1))
    {
    case 0:
        CreateItemTask(owner, guildId);
        return GUILD_TASK_TYPE_ITEM;
    default:
        CreateKillTask(owner, guildId);
        return GUILD_TASK_TYPE_KILL;
    }*/
}

bool GuildTaskMgr::CreateItemTask(uint32 owner, uint32 guildId)
{
    Player* player = sObjectMgr->GetPlayerByLowGUID(owner);
    if (!player)
        return false;

    vector<uint32> items;
    ItemTemplateContainer const* itemTemplates = sObjectMgr->GetItemTemplateStore();
    for (ItemTemplateContainer::const_iterator i = itemTemplates->begin(); i != itemTemplates->end(); ++i)
    {
        uint32 itemId = i->first;
        ItemTemplate const* proto = &i->second;
        if (!proto)
            continue;

        if (proto->Bonding == BIND_WHEN_PICKED_UP ||
                proto->Bonding == BIND_QUEST_ITEM ||
                proto->Bonding == BIND_WHEN_USE)
            continue;

        if (proto->Quality < ITEM_QUALITY_UNCOMMON)
            continue;

        if (proto->RequiredLevel > sAhBotConfig.maxRequiredLevel || proto->ItemLevel > sAhBotConfig.maxItemLevel)
            continue;

        if (proto->Duration & 0x80000000)
            continue;

        if (sAhBotConfig.ignoreItemIds.find(proto->ItemId) != sAhBotConfig.ignoreItemIds.end())
            continue;

        if (strstri(proto->Name1.c_str(), "qa") || strstri(proto->Name1.c_str(), "test") || strstri(proto->Name1.c_str(), "deprecated"))
            continue;

        if ((proto->Class == ITEM_CLASS_ARMOR || proto->Class == ITEM_CLASS_WEAPON) && proto->Quality < ITEM_QUALITY_RARE)
            continue;

        if (proto->Class != ITEM_CLASS_TRADE_GOODS && proto->Class != ITEM_CLASS_CONSUMABLE)
            continue;

        items.push_back(itemId);
    }

    if (items.empty())
    {
        sLog->outMessage("gtask", LOG_LEVEL_ERROR, "%s / %s: no items avaible for item task",
                sGuildMgr->GetGuildById(guildId)->GetName().c_str(), player->GetName().c_str());
        return false;
    }

    uint32 index = urand(0, items.size() - 1);
    uint32 itemId = items[index];

    uint32 count = GetMaxItemTaskCount(itemId);

    sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: item task %u (x%d)",
            sGuildMgr->GetGuildById(guildId)->GetName().c_str(), player->GetName().c_str(),
            itemId, count);

    SetTaskValue(owner, guildId, "itemCount", count, sPlayerbotAIConfig.maxGuildTaskChangeTime);
    SetTaskValue(owner, guildId, "itemTask", itemId, sPlayerbotAIConfig.maxGuildTaskChangeTime);
    return true;
}

bool GuildTaskMgr::CreateKillTask(uint32 owner, uint32 guildId)
{
    return false;
}

bool GuildTaskMgr::SendAdvertisement(uint32 owner, uint32 guildId)
{
    Guild *guild = sGuildMgr->GetGuildById(guildId);
    if (!guild)
        return false;

    Player* player = sObjectMgr->GetPlayerByLowGUID(owner);
    if (!player)
        return false;

    Player* leader = sObjectMgr->GetPlayerByLowGUID(guild->GetLeaderGUID());
    if (!leader)
        return false;

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask)
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemTask);
        if (!proto)
            return false;

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        ostringstream body;
        body << "Hello, " << player->GetName() << ",\n";
        body << "\n";
        body << "We are in a great need of " << proto->Name1 << ". If you could sell us ";
        uint32 count = GetTaskValue(owner, guildId, "itemCount");
        if (count > 1)
            body << "at least " << count << " of them ";
        else
            body << "some ";
        body << "we'd really appreciate that and pay a high price.\n";
        body << "\n";
        body << "Best Regards,\n";
        body << guild->GetName() << "\n";
        body << leader->GetName() << "\n";
        MailDraft("Guild Task Advertisement", body.str()).SendMailTo(trans, MailReceiver(player), MailSender(leader));
        CharacterDatabase.CommitTransaction(trans);

        return true;
    }

    return false;
}

bool GuildTaskMgr::SendThanks(uint32 owner, uint32 guildId)
{
    Guild *guild = sGuildMgr->GetGuildById(guildId);
    if (!guild)
        return false;

    Player* player = sObjectMgr->GetPlayerByLowGUID(owner);
    if (!player)
        return false;

    Player* leader = sObjectMgr->GetPlayerByLowGUID(guild->GetLeaderGUID());
    if (!leader)
        return false;

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask)
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemTask);
        if (!proto)
            return false;

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        ostringstream body;
        body << "Hello, " << player->GetName() << ",\n";
        body << "\n";
        body << "One of our guild members wishes to thank you for the " << proto->Name1 << "! If we have another ";
        uint32 count = GetTaskValue(owner, guildId, "itemCount");
        body << count << " of them that would help us tremendously.\n";
        body << "\n";
        body << "Thanks again,\n";
        body << guild->GetName() << "\n";
        body << leader->GetName() << "\n";
        MailDraft("Thank You", body.str()).SendMailTo(trans, MailReceiver(player), MailSender(leader));
        CharacterDatabase.CommitTransaction(trans);

        return true;
    }

    return false;
}

uint32 GuildTaskMgr::GetMaxItemTaskCount(uint32 itemId)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId);
    if (!proto)
        return 0;

    if (proto->Quality < ITEM_QUALITY_RARE && proto->Stackable && proto->GetMaxStackSize() > 1)
        return proto->GetMaxStackSize();

    return 1;
}

bool GuildTaskMgr::IsGuildTaskItem(uint32 itemId, uint32 guildId)
{
    uint32 value = 0;

    QueryResult results = CharacterDatabase.PQuery(
            "select `value`, `time`, validIn from ai_playerbot_guild_tasks where `value` = '%u' and guildid = '%u' and `type` = 'itemTask'",
            itemId, guildId);

    if (results)
    {
        Field* fields = results->Fetch();
        value = fields[0].GetUInt32();
        uint32 lastChangeTime = fields[1].GetUInt32();
        uint32 validIn = fields[2].GetUInt32();
        if ((time(0) - lastChangeTime) >= validIn)
            value = 0;
    }

    return value;
}

uint32 GuildTaskMgr::GetTaskValue(uint32 owner, uint32 guildId, string type, uint32 *validIn /* = NULL */)
{
    uint32 value = 0;

    QueryResult results = CharacterDatabase.PQuery(
            "select `value`, `time`, validIn from ai_playerbot_guild_tasks where owner = '%u' and guildid = '%u' and `type` = '%s'",
            owner, guildId, type.c_str());

    if (results)
    {
        Field* fields = results->Fetch();
        value = fields[0].GetUInt32();
        uint32 lastChangeTime = fields[1].GetUInt32();
        uint32 secs = fields[2].GetUInt32();
        if ((time(0) - lastChangeTime) >= secs)
            value = 0;

        if (validIn) *validIn = secs;
    }

    return value;
}

uint32 GuildTaskMgr::SetTaskValue(uint32 owner, uint32 guildId, string type, uint32 value, uint32 validIn)
{
    CharacterDatabase.PExecute("delete from ai_playerbot_guild_tasks where owner = '%u' and guildid = '%u' and `type` = '%s'",
            owner, guildId, type.c_str());
    if (value)
    {
        CharacterDatabase.PExecute(
                "insert into ai_playerbot_guild_tasks (owner, guildid, `time`, validIn, `type`, `value`) values ('%u', '%u', '%u', '%u', '%s', '%u')",
                owner, guildId, (uint32)time(0), validIn, type.c_str(), value);
    }

    return value;
}

bool GuildTaskMgr::HandleConsoleCommand(ChatHandler* handler, char const* args)
{
    if (!sPlayerbotAIConfig.guildTaskEnabled)
    {
        sLog->outMessage("gtask", LOG_LEVEL_ERROR, "Guild task system is currently disabled!");
        return false;
    }

    if (!args || !*args)
    {
        sLog->outMessage("gtask", LOG_LEVEL_ERROR, "Usage: gtask stats/reset");
        return false;
    }

    string cmd = args;

    if (cmd == "reset")
    {
        CharacterDatabase.PExecute("delete from ai_playerbot_guild_tasks");
        sLog->outMessage("gtask", LOG_LEVEL_INFO, "Guild tasks were reset for all players");
        return true;
    }

    if (cmd == "stats")
    {
        sLog->outMessage("gtask", LOG_LEVEL_INFO, "Usage: gtask stats <player name>");
        return true;
    }

    if (cmd.find("stats ") != string::npos)
    {
        string charName = cmd.substr(cmd.find("stats ") + 6);
        ObjectGuid guid = sObjectMgr->GetPlayerGUIDByName(charName);
        if (!guid)
        {
            sLog->outMessage("gtask", LOG_LEVEL_ERROR, "Player %s not found", charName.c_str());
            return false;
        }

        uint32 owner = (uint32)guid.GetRawValue();

        QueryResult result = CharacterDatabase.PQuery(
                "select `value`, `time`, validIn, guildid, `type` from ai_playerbot_guild_tasks where owner = '%u' order by guildid, `type`",
                owner);

        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                uint32 value = fields[0].GetUInt32();
                uint32 lastChangeTime = fields[1].GetUInt32();
                uint32 validIn = fields[2].GetUInt32();
                if ((time(0) - lastChangeTime) >= validIn)
                    value = 0;
                uint32 guildId = fields[3].GetUInt32();
                string type = fields[4].GetString();

                Guild *guild = sGuildMgr->GetGuildById(guildId);
                if (!guild)
                    continue;

                sLog->outMessage("gtask", LOG_LEVEL_INFO, "Player '%s' Guild '%s' %s=%u (%u secs)",
                        charName.c_str(), guild->GetName().c_str(),
                        type.c_str(), value, validIn);

            } while (result->NextRow());

            Field* fields = result->Fetch();
        }

        return true;
    }

    return false;
}

void GuildTaskMgr::CheckItemTask(uint32 itemId, uint32 obtained, Player* ownerPlayer, Player* bot, bool byMail)
{
    uint32 guildId = bot->GetGuildId();
    if (!guildId)
        return;

    uint32 owner = (uint32)ownerPlayer->GetGUID().GetRawValue();

    sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: checking guild task",
            bot->GetGuild()->GetName().c_str(), ownerPlayer->GetName().c_str());

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask != itemId)
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: item %u is not guild task item (%u)",
                bot->GetGuild()->GetName().c_str(), ownerPlayer->GetName().c_str(),
                itemId, itemTask);
        return;
    }

    if (byMail)
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId);
        if (!proto)
            return;

        SetTaskValue(owner, guildId, "payment", auctionbot.GetBuyPrice(proto) * obtained,
                urand(sPlayerbotAIConfig.minGuildTaskRewardTime, sPlayerbotAIConfig.maxGuildTaskRewardTime));
    }

    uint32 count = GetTaskValue(owner, guildId, "itemCount");
    if (obtained >= count)
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: guild task complete",
                bot->GetGuild()->GetName().c_str(), ownerPlayer->GetName().c_str());
        SetTaskValue(owner, guildId, "reward", 1,
                urand(sPlayerbotAIConfig.minGuildTaskRewardTime, sPlayerbotAIConfig.maxGuildTaskRewardTime));
    }
    else
    {
        sLog->outMessage("gtask", LOG_LEVEL_DEBUG, "%s / %s: guild task progress",
                bot->GetGuild()->GetName().c_str(), ownerPlayer->GetName().c_str());
        SetTaskValue(owner, guildId, "itemCount", count - obtained, sPlayerbotAIConfig.maxGuildTaskChangeTime);
        SetTaskValue(owner, guildId, "thanks", 1,
                urand(sPlayerbotAIConfig.minGuildTaskRewardTime, sPlayerbotAIConfig.maxGuildTaskRewardTime));
    }
}

bool GuildTaskMgr::Reward(uint32 owner, uint32 guildId)
{
    Guild *guild = sGuildMgr->GetGuildById(guildId);
    if (!guild)
        return false;

    Player* player = sObjectMgr->GetPlayerByLowGUID(owner);
    if (!player)
        return false;

    Player* leader = sObjectMgr->GetPlayerByLowGUID(guild->GetLeaderGUID());
    if (!leader)
        return false;

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask)
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemTask);
        if (!proto)
            return false;

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        ostringstream body;
        body << "Hello, " << player->GetName() << ",\n";
        body << "\n";
        body << "We wish to thank you for the " << proto->Name1 << " you provided so kindly. We really appreciate this and may this small gift bring you our thanks!\n";
        body << "\n";
        body << "Many thanks,\n";
        body << guild->GetName() << "\n";
        body << leader->GetName() << "\n";

        vector<uint32> items;
        ItemTemplateContainer const* itemTemplates = sObjectMgr->GetItemTemplateStore();
        for (ItemTemplateContainer::const_iterator i = itemTemplates->begin(); i != itemTemplates->end(); ++i)
        {
            uint32 itemId = i->first;
            ItemTemplate const* proto = &i->second;
            if (!proto)
                continue;

            if (proto->Bonding == BIND_WHEN_PICKED_UP ||
                    proto->Bonding == BIND_QUEST_ITEM ||
                    proto->Bonding == BIND_WHEN_USE)
                continue;

            if (proto->Quality < ITEM_QUALITY_RARE)
                continue;

            if (proto->RequiredLevel > sAhBotConfig.maxRequiredLevel || proto->ItemLevel > sAhBotConfig.maxItemLevel)
                continue;

            if (proto->Duration & 0x80000000)
                continue;

            if (sAhBotConfig.ignoreItemIds.find(proto->ItemId) != sAhBotConfig.ignoreItemIds.end())
                continue;

            if (strstri(proto->Name1.c_str(), "qa") || strstri(proto->Name1.c_str(), "test") || strstri(proto->Name1.c_str(), "deprecated"))
                continue;

            items.push_back(itemId);
        }

        if (items.empty())
        {
            sLog->outMessage("gtask", LOG_LEVEL_ERROR, "%s / %s: no items available for item task",
                    sGuildMgr->GetGuildById(guildId)->GetName().c_str(), player->GetName().c_str());
            return false;
        }

        uint32 index = urand(0, items.size() - 1);
        uint32 itemId = items[index];

        Item* item = Item::CreateItem(itemId, 1, leader);
        MailDraft("Thank You", body.str()).
                AddItem(item).
                AddMoney(GetTaskValue(owner, guildId, "payment")).
                SendMailTo(trans, MailReceiver(player), MailSender(leader));
        CharacterDatabase.CommitTransaction(trans);

        return true;
    }

    return false;
}
