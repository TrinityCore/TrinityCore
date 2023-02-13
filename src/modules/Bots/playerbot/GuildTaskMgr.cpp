#include "../botpch.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "GuildTaskMgr.h"

#include "../../modules/Bots/ahbot/AhBot.h"
#include "GuildMgr.h"
#include "DatabaseEnv.h"
#include "Mail.h"
#include "PlayerbotAI.h"

#include "../../modules/Bots/ahbot/AhBotConfig.h"
#include "RandomItemMgr.h"
#include "ServerFacade.h"

INSTANTIATE_SINGLETON_1(GuildTaskMgr);

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

    if (!GetTaskValue(0, 0, "advert_cleanup"))
    {
        CleanupAdverts();
        RemoveDuplicatedAdverts();
        SetTaskValue(0, 0, "advert_cleanup", 1, sPlayerbotAIConfig.guildTaskAdvertCleanupTime);
    }

    uint32 guildId = guildMaster->GetGuildId();
    if (!guildId || !guildMaster->GetPlayerbotAI() || !guildMaster->GetGuildId())
        return;

    if (!sServerFacade.IsFriendlyTo(player, guildMaster))
        return;

	Guild *guild = sGuildMgr.GetGuildById(guildMaster->GetGuildId());
    DenyReason reason = PLAYERBOT_DENY_NONE;
    PlayerbotSecurityLevel secLevel = guildMaster->GetPlayerbotAI()->GetSecurity()->LevelFor(player, &reason);
    if (secLevel == PLAYERBOT_SECURITY_DENY_ALL || (secLevel == PLAYERBOT_SECURITY_TALK && reason != PLAYERBOT_DENY_FAR))
    {
        sLog.outDebug("%s / %s: skipping guild task update - not enough security level, reason = %u",
			guild->GetName(), player->GetName(), reason);
        return;
    }

    sLog.outDebug("%s: guild task update for player %s", guild->GetName(), player->GetName());

    uint32 owner = (uint32)player->GetGUIDLow();

    uint32 activeTask = GetTaskValue(owner, guildId, "activeTask");
    if (!activeTask)
    {
        SetTaskValue(owner, guildId, "killTask", 0, 0);
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
            sLog.outError( "%s / %s: error creating guild task",
				guild->GetName(), player->GetName());
        }

        uint32 time = urand(sPlayerbotAIConfig.minGuildTaskChangeTime, sPlayerbotAIConfig.maxGuildTaskChangeTime);
        SetTaskValue(owner, guildId, "activeTask", task, time);
        SetTaskValue(owner, guildId, "advertisement", 1,
                urand(sPlayerbotAIConfig.minGuildTaskAdvertisementTime, sPlayerbotAIConfig.maxGuildTaskAdvertisementTime));

        sLog.outDebug("%s / %s: guild task %u is set for %u secs",
				guild->GetName(), player->GetName(),
                task, time);
        return;
    }

    uint32 advertisement = GetTaskValue(owner, guildId, "advertisement");
    if (!advertisement)
    {
        sLog.outDebug("%s / %s: sending advertisement",
				guild->GetName(), player->GetName());
        if (SendAdvertisement(owner, guildId))
        {
            SetTaskValue(owner, guildId, "advertisement", 1,
                    urand(sPlayerbotAIConfig.minGuildTaskAdvertisementTime, sPlayerbotAIConfig.maxGuildTaskAdvertisementTime));
        }
        else
        {
            sLog.outError( "%s / %s: error sending advertisement",
					guild->GetName(), player->GetName());
        }
    }

    uint32 thanks = GetTaskValue(owner, guildId, "thanks");
    if (!thanks)
    {
        sLog.outDebug("%s / %s: sending thanks",
				guild->GetName(), player->GetName());
        if (SendThanks(owner, guildId))
        {
            SetTaskValue(owner, guildId, "thanks", 1, 2 * sPlayerbotAIConfig.maxGuildTaskChangeTime);
            SetTaskValue(owner, guildId, "payment", 0, 0);
        }
        else
        {
            sLog.outError( "%s / %s: error sending thanks",
					guild->GetName(), player->GetName());
        }
    }

    uint32 reward = GetTaskValue(owner, guildId, "reward");
    if (!reward)
    {
        sLog.outDebug("%s / %s: sending reward",
				guild->GetName(), player->GetName());
        if (Reward(owner, guildId))
        {
            SetTaskValue(owner, guildId, "reward", 1, 2 * sPlayerbotAIConfig.maxGuildTaskChangeTime);
            SetTaskValue(owner, guildId, "payment", 0, 0);
        }
        else
        {
            sLog.outError( "%s / %s: error sending reward",
					guild->GetName(), player->GetName());
        }
    }
}

uint32 GuildTaskMgr::CreateTask(uint32 owner, uint32 guildId)
{
    switch (urand(0, 1))
    {
    case 0:
        CreateItemTask(owner, guildId);
        return GUILD_TASK_TYPE_ITEM;
    default:
        CreateKillTask(owner, guildId);
        return GUILD_TASK_TYPE_KILL;
    }
}

bool GuildTaskMgr::CreateItemTask(uint32 owner, uint32 guildId)
{
    Player* player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, owner));
    if (!player || player->getLevel() < 5)
        return false;

    uint32 itemId = sRandomItemMgr.GetRandomItem(player->getLevel() - 5, RANDOM_ITEM_GUILD_TASK);
    if (!itemId)
    {
        sLog.outError( "%s / %s: no items avaible for item task",
                sGuildMgr.GetGuildById(guildId)->GetName().c_str(), player->GetName());
        return false;
    }

    uint32 count = GetMaxItemTaskCount(itemId);

    sLog.outDebug("%s / %s: item task %u (x%d)",
            sGuildMgr.GetGuildById(guildId)->GetName().c_str(), player->GetName(),
            itemId, count);

    SetTaskValue(owner, guildId, "itemCount", count, sPlayerbotAIConfig.maxGuildTaskChangeTime);
    SetTaskValue(owner, guildId, "itemTask", itemId, sPlayerbotAIConfig.maxGuildTaskChangeTime);
    return true;
}

bool GuildTaskMgr::CreateKillTask(uint32 owner, uint32 guildId)
{
    Player* player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, owner));
    if (!player)
        return false;

    uint32 rank = !urand(0, 2) ? CREATURE_ELITE_RAREELITE : CREATURE_ELITE_RARE;
    vector<uint32> ids;
	for (uint32 id = 0; id < sCreatureStorage.GetMaxEntry(); ++id)
	{
		CreatureInfo const* co = sCreatureStorage.LookupEntry<CreatureInfo>(id);
		if (!co)
			continue;

        if (co->Rank != rank)
            continue;

        if (co->MaxLevel > player->getLevel() + 4 || co->MinLevel < player->getLevel() - 3)
            continue;

        if (strstr(co->Name, "UNUSED"))
            continue;

        ids.push_back(id);
    }

    if (ids.empty())
    {
        sLog.outError( "%s / %s: no rare creatures available for kill task",
                sGuildMgr.GetGuildById(guildId)->GetName().c_str(), player->GetName());
        return false;
    }

    uint32 index = urand(0, ids.size() - 1);
    uint32 creatureId = ids[index];

    sLog.outDebug("%s / %s: kill task %u",
            sGuildMgr.GetGuildById(guildId)->GetName().c_str(), player->GetName(),
            creatureId);

    SetTaskValue(owner, guildId, "killTask", creatureId, sPlayerbotAIConfig.maxGuildTaskChangeTime);
    return true;
}

bool GuildTaskMgr::SendAdvertisement(uint32 owner, uint32 guildId)
{
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    if (!guild)
        return false;

    Player* leader = sObjectMgr.GetPlayer(guild->GetLeaderGuid());
    if (!leader)
        return false;

    uint32 validIn;
    GetTaskValue(owner, guildId, "activeTask", &validIn);

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask)
        return SendItemAdvertisement(itemTask, owner, guildId, validIn);

    uint32 killTask = GetTaskValue(owner, guildId, "killTask");
    if (killTask)
        return SendKillAdvertisement(killTask, owner, guildId, validIn);

    return false;
}

string formatTime(uint32 secs)
{
    ostringstream out;
    if (secs < 3600)
    {
        out << secs / 60 << " min";
    }
    else if (secs < 7200)
    {
        out << "1 hr " << (secs - 3600) / 60 << " min";
    }
    else if (secs < 3600 * 24)
    {
        out << secs / 3600 << " hr";
    } else
    {
        out << secs / 3600 / 24 << " days";
    }

    return out.str();
}

string formatDateTime(uint32 secs)
{
    time_t rawtime = time(0) + secs;
    tm* timeinfo = localtime (&rawtime);

    char buffer[256];
    strftime(buffer, sizeof(buffer), "%b %d, %H:%M", timeinfo);
    return string(buffer);
}

string GetHelloText(uint32 owner)
{
    ostringstream body;
    body << "Hello";
    string playerName;
    sObjectMgr.GetPlayerNameByGUID(ObjectGuid(HIGHGUID_PLAYER, owner), playerName);
    if (!playerName.empty()) body << ", " << playerName;
    body << ",\n\n";
    return body.str();
}

bool GuildTaskMgr::SendItemAdvertisement(uint32 itemId, uint32 owner, uint32 guildId, uint32 validIn)
{
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    Player* leader = sObjectMgr.GetPlayer(guild->GetLeaderGuid());

    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemId);
    if (!proto)
        return false;

    ostringstream body;
    body << GetHelloText(owner);
    body << "We are in a great need of " << proto->Name1 << ". If you could sell us ";
    uint32 count = GetTaskValue(owner, guildId, "itemCount");
    if (count > 1)
        body << "at least " << count << " of them ";
    else
        body << "some ";
    body << "we'd really appreciate that and pay a high price.\n\n";
    body << "The task will expire at " << formatDateTime(validIn) << "\n";
    body << "\n";
    body << "Best Regards,\n";
    body << guild->GetName() << "\n";
    body << leader->GetName() << "\n";

    ostringstream subject;
    subject << "Guild Task: " << proto->Name1;
    if (count > 1) subject << " (x" << count << ")";
    MailDraft(subject.str(), body.str()).SendMailTo(MailReceiver(ObjectGuid(HIGHGUID_PLAYER, owner)), MailSender(leader));

    return true;
}


bool GuildTaskMgr::SendKillAdvertisement(uint32 creatureId, uint32 owner, uint32 guildId, uint32 validIn)
{
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    Player* leader = sObjectMgr.GetPlayer(guild->GetLeaderGuid());

    CreatureInfo const* proto = sObjectMgr.GetCreatureTemplate(creatureId);
    if (!proto)
        return false;

    QueryResult *result = WorldDatabase.PQuery("SELECT map, position_x, position_y, position_z FROM creature where id = '%u'", creatureId);
    if (!result)
        return false;

    string location;
    do
    {
        Field* fields = result->Fetch();
        uint32 mapid = fields[0].GetUInt32();
        float x = fields[1].GetFloat();
        float y = fields[2].GetFloat();
        float z = fields[3].GetFloat();
        Map* map = sMapMgr.FindMap(mapid, 0);
        if (!map) continue;
        uint32 area = map->GetTerrain()->GetAreaId(x, y, z);
        const AreaTableEntry* entry = GetAreaEntryByAreaID(area);
        if (!entry) continue;
        location = entry->area_name[0];
        break;
    } while (result->NextRow());
    delete result;

    ostringstream body;
    body << GetHelloText(owner);
    body << "As you probably know " << proto->Name << " is wanted dead for the crimes it did against our guild. If you should kill it ";
    body << "we'd really appreciate that.\n\n";
    if (!location.empty())
        body << proto->Name << "'s the last known location was " << location << ".\n";
    body << "The task will expire at " << formatDateTime(validIn) << "\n";
    body << "\n";
    body << "Best Regards,\n";
    body << guild->GetName() << "\n";
    body << leader->GetName() << "\n";

    ostringstream subject;
    subject << "Guild Task: ";
    if (proto->Rank == CREATURE_ELITE_ELITE || proto->Rank == CREATURE_ELITE_RAREELITE || proto->Rank == CREATURE_ELITE_WORLDBOSS)
        subject << "(Elite) ";
    subject << proto->Name;
    if (!location.empty())
        subject << ", " << location;

    MailDraft(subject.str(), body.str()).SendMailTo(MailReceiver(ObjectGuid(HIGHGUID_PLAYER, owner)), MailSender(leader));

    return true;
}

bool GuildTaskMgr::SendThanks(uint32 owner, uint32 guildId)
{
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    if (!guild)
        return false;

    Player* leader = sObjectMgr.GetPlayer(guild->GetLeaderGuid());
    if (!leader)
        return false;

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask)
    {
        ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemTask);
        if (!proto)
            return false;

        ostringstream body;
        body << GetHelloText(owner);
        body << "One of our guild members wishes to thank you for the " << proto->Name1 << "!";
        uint32 count = GetTaskValue(owner, guildId, "itemCount");
        if (count)
        {
            body << " If we have another ";
            body << count << " of them that would help us tremendously.\n";
        }
        body << "\n";
        body << "Thanks again,\n";
        body << guild->GetName() << "\n";
        body << leader->GetName() << "\n";

        MailDraft("Thank You", body.str()).
                SetMoney(GetTaskValue(owner, guildId, "payment")).
                SendMailTo(MailReceiver(ObjectGuid(HIGHGUID_PLAYER, owner)), MailSender(leader));

        Player* player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, owner));
        if (player)
            SendCompletionMessage(player, "payed for");

        return true;
    }

    return false;
}

uint32 GuildTaskMgr::GetMaxItemTaskCount(uint32 itemId)
{
    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemId);
    if (!proto)
        return 0;

    if (!proto->Stackable || proto->GetMaxStackSize() == 1)
        return 1;

    if (proto->Quality == ITEM_QUALITY_NORMAL)
    {
        switch (proto->GetMaxStackSize())
        {
        case 5:
            return urand(1, 3) * proto->GetMaxStackSize();
        case 10:
            return urand(2, 6) * proto->GetMaxStackSize() / 2;
        case 20:
            return urand(4, 12) * proto->GetMaxStackSize() / 4;
        default:
            return proto->GetMaxStackSize();
        }
    }

    if (proto->Quality < ITEM_QUALITY_RARE)
    {
        switch (proto->GetMaxStackSize())
        {
        case 5:
            return proto->GetMaxStackSize();
        case 10:
            return urand(1, 2) * proto->GetMaxStackSize() / 2;
        case 20:
            return urand(1, 4) * proto->GetMaxStackSize() / 4;
        default:
            return proto->GetMaxStackSize();
        }
    }

    return 1;
}

bool GuildTaskMgr::IsGuildTaskItem(uint32 itemId, uint32 guildId)
{
    uint32 value = 0;

    QueryResult* results = PlayerbotDatabase.PQuery(
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

		delete results;
    }

    return value;
}

map<uint32,uint32> GuildTaskMgr::GetTaskValues(uint32 owner, string type, uint32 *validIn /* = NULL */)
{
    map<uint32,uint32> result;

    QueryResult* results = PlayerbotDatabase.PQuery(
            "select `value`, `time`, validIn, guildid from ai_playerbot_guild_tasks where owner = '%u' and `type` = '%s'",
            owner, type.c_str());

    if (!results)
        return result;

    do
    {
        Field* fields = results->Fetch();
        uint32 value = fields[0].GetUInt32();
        uint32 lastChangeTime = fields[1].GetUInt32();
        uint32 secs = fields[2].GetUInt32();
        uint32 guildId = fields[3].GetUInt32();
        if ((time(0) - lastChangeTime) >= secs)
            value = 0;

        result[guildId] = value;

    } while (results->NextRow());

	delete results;
	return result;
}

uint32 GuildTaskMgr::GetTaskValue(uint32 owner, uint32 guildId, string type, uint32 *validIn /* = NULL */)
{
    uint32 value = 0;

    QueryResult* results = PlayerbotDatabase.PQuery(
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

	delete results;
	return value;
}

uint32 GuildTaskMgr::SetTaskValue(uint32 owner, uint32 guildId, string type, uint32 value, uint32 validIn)
{
    PlayerbotDatabase.DirectPExecute("delete from ai_playerbot_guild_tasks where owner = '%u' and guildid = '%u' and `type` = '%s'",
            owner, guildId, type.c_str());
    if (value)
    {
        PlayerbotDatabase.DirectPExecute(
                "insert into ai_playerbot_guild_tasks (owner, guildid, `time`, validIn, `type`, `value`) values ('%u', '%u', '%u', '%u', '%s', '%u')",
                owner, guildId, (uint32)time(0), validIn, type.c_str(), value);
    }

    return value;
}

bool GuildTaskMgr::HandleConsoleCommand(ChatHandler* handler, char const* args)
{
    if (!sPlayerbotAIConfig.guildTaskEnabled)
    {
        sLog.outError( "Guild task system is currently disabled!");
        return false;
    }

    if (!args || !*args)
    {
        sLog.outError( "Usage: gtask stats/reset");
        return false;
    }

    string cmd = args;

    if (cmd == "reset")
    {
        PlayerbotDatabase.PExecute("delete from ai_playerbot_guild_tasks");
        sLog.outString("Guild tasks were reset for all players");
        return true;
    }

    if (cmd == "stats")
    {
        sLog.outString("Usage: gtask stats <player name>");
        return true;
    }

    if (cmd.find("stats ") != string::npos)
    {
        string charName = cmd.substr(cmd.find("stats ") + 6);
        ObjectGuid guid = sObjectMgr.GetPlayerGuidByName(charName);
        if (!guid)
        {
            sLog.outError( "Player %s not found", charName.c_str());
            return false;
        }

        uint32 owner = (uint32)guid.GetRawValue();

        QueryResult* result = PlayerbotDatabase.PQuery(
                "select `value`, `time`, validIn, guildid from ai_playerbot_guild_tasks where owner = '%u' and type='activeTask' order by guildid",
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

                Guild *guild = sGuildMgr.GetGuildById(guildId);
                if (!guild)
                    continue;

                ostringstream name;
                if (value == GUILD_TASK_TYPE_ITEM)
                {
                    name << "ItemTask";
                    uint32 itemId = sGuildTaskMgr.GetTaskValue(owner, guildId, "itemTask");
                    uint32 itemCount = sGuildTaskMgr.GetTaskValue(owner, guildId, "itemCount");
                    ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemId);
                    if (proto)
                    {
                        name << " (" << proto->Name1 << " x" << itemCount << ",";
                        switch (proto->Quality)
                        {
                        case ITEM_QUALITY_UNCOMMON:
                            name << "green";
                            break;
                        case ITEM_QUALITY_NORMAL:
                            name << "white";
                            break;
                        case ITEM_QUALITY_RARE:
                            name << "blue";
                            break;
                        case ITEM_QUALITY_EPIC:
                            name << "epic";
                            break;
                        }
                        name << ")";
                    }
                }
                else if (value == GUILD_TASK_TYPE_KILL)
                {
                    name << "KillTask";
                    uint32 creatureId = sGuildTaskMgr.GetTaskValue(owner, guildId, "killTask");
                    CreatureInfo const* proto = sObjectMgr.GetCreatureTemplate(creatureId);
                    if (proto)
                    {
                        name << " (" << proto->Name << ",";
                        switch (proto->Rank)
                        {
                        case CREATURE_ELITE_RARE:
                            name << "rare";
                            break;
                        case CREATURE_ELITE_RAREELITE:
                            name << "rare elite";
                            break;
                        }
                        name << ")";
                    }
                }
                else
                    continue;

                uint32 advertValidIn = 0;
                uint32 advert = sGuildTaskMgr.GetTaskValue(owner, guildId, "advertisement", &advertValidIn);
                if (advert && advertValidIn < validIn)
                    name << " advert in " << formatTime(advertValidIn);

                uint32 thanksValidIn = 0;
                uint32 thanks = sGuildTaskMgr.GetTaskValue(owner, guildId, "thanks", &thanksValidIn);
                if (thanks && thanksValidIn < validIn)
                    name << " thanks in " << formatTime(thanksValidIn);

                uint32 rewardValidIn = 0;
                uint32 reward = sGuildTaskMgr.GetTaskValue(owner, guildId, "reward", &rewardValidIn);
                if (reward && rewardValidIn < validIn)
                    name << " reward in " << formatTime(rewardValidIn);

                uint32 paymentValidIn = 0;
                uint32 payment = sGuildTaskMgr.GetTaskValue(owner, guildId, "payment", &paymentValidIn);
                if (payment && paymentValidIn < validIn)
                    name << " payment " << ChatHelper::formatMoney(payment) << " in " << formatTime(paymentValidIn);

                sLog.outString("%s: %s valid in %s ['%s']",
                        charName.c_str(), name.str().c_str(), formatTime(validIn).c_str(), guild->GetName().c_str());

            } while (result->NextRow());

            Field* fields = result->Fetch();
			delete result;
        }

        return true;
    }

    if (cmd == "cleanup")
    {
        sGuildTaskMgr.CleanupAdverts();
        sGuildTaskMgr.RemoveDuplicatedAdverts();
        return true;
    }

    if (cmd == "reward")
    {
        sLog.outString("Usage: gtask reward <player name>");
        return true;
    }

    if (cmd == "advert")
    {
        sLog.outString("Usage: gtask advert <player name>");
        return true;
    }

    bool reward = cmd.find("reward ") != string::npos;
    bool advert = cmd.find("advert ") != string::npos;
    if (reward || advert)
    {
        string charName;
        if (reward) charName = cmd.substr(cmd.find("reward ") + 7);
        if (advert) charName = cmd.substr(cmd.find("advert ") + 7);
        ObjectGuid guid = sObjectMgr.GetPlayerGuidByName(charName);
        if (!guid)
        {
            sLog.outError( "Player %s not found", charName.c_str());
            return false;
        }

        uint32 owner = (uint32)guid.GetRawValue();
        QueryResult* result = PlayerbotDatabase.PQuery(
                "select distinct guildid from ai_playerbot_guild_tasks where owner = '%u'",
                owner);

        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                uint32 guildId = fields[0].GetUInt32();
                Guild *guild = sGuildMgr.GetGuildById(guildId);
                if (!guild)
                    continue;

                if (reward) sGuildTaskMgr.Reward(owner, guildId);
                if (advert) sGuildTaskMgr.SendAdvertisement(owner, guildId);
            } while (result->NextRow());

            Field* fields = result->Fetch();
			delete result;
            return true;
        }
    }

    return false;
}

bool GuildTaskMgr::CheckItemTask(uint32 itemId, uint32 obtained, Player* ownerPlayer, Player* bot, bool byMail)
{
    if (!bot) return false;
    uint32 guildId = bot->GetGuildId();
    if (!guildId)
        return false;

    uint32 owner = (uint32)ownerPlayer->GetGUIDLow();
	Guild *guild = sGuildMgr.GetGuildById(bot->GetGuildId());
	if (!guild)
		return false;

	if (!sRandomPlayerbotMgr.IsRandomBot(bot))
	    return false;

    sLog.outDebug("%s / %s: checking guild task",
			guild->GetName().c_str(), ownerPlayer->GetName());

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    if (itemTask != itemId)
    {
        sLog.outDebug("%s / %s: item %u is not guild task item (%u)",
				guild->GetName().c_str(), ownerPlayer->GetName(),
                itemId, itemTask);
        SendCompletionMessage(ownerPlayer, "made a mistake with");
        return false;
    }

    uint32 count = GetTaskValue(owner, guildId, "itemCount");
    if (!count) {
        return false;
    }

    uint32 rewardTime = urand(sPlayerbotAIConfig.minGuildTaskRewardTime, sPlayerbotAIConfig.maxGuildTaskRewardTime);
    if (byMail)
    {
        ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemId);
        if (!proto)
            return false;

        uint32 money = GetTaskValue(owner, guildId, "payment");
        SetTaskValue(owner, guildId, "payment", money + auctionbot.GetBuyPrice(proto) * obtained, rewardTime + 300);
    }

    if (obtained >= count)
    {
        sLog.outDebug("%s / %s: guild task complete",
				guild->GetName().c_str(), ownerPlayer->GetName());
        SetTaskValue(owner, guildId, "reward", 1, rewardTime - 15);
        SetTaskValue(owner, guildId, "itemCount", 0, 0);
        SetTaskValue(owner, guildId, "thanks", 0, 0);
        SendCompletionMessage(ownerPlayer, "completed");
    }
    else
    {
        sLog.outDebug("%s / %s: guild task progress %u/%u",
				guild->GetName().c_str(), ownerPlayer->GetName(), obtained, count);
        SetTaskValue(owner, guildId, "itemCount", count - obtained, sPlayerbotAIConfig.maxGuildTaskChangeTime);
        SetTaskValue(owner, guildId, "thanks", 1, rewardTime - 30);
        SendCompletionMessage(ownerPlayer, "made a progress with");
    }
    return true;
}

bool GuildTaskMgr::Reward(uint32 owner, uint32 guildId)
{
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    if (!guild)
        return false;

    Player* leader = sObjectMgr.GetPlayer(guild->GetLeaderGuid());
    if (!leader)
        return false;

    Player* player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, owner), false);
    if (!player)
        return false;

    uint32 itemTask = GetTaskValue(owner, guildId, "itemTask");
    uint32 killTask = GetTaskValue(owner, guildId, "killTask");
    if (!itemTask && !killTask)
        return false;

    ostringstream body;
    body << GetHelloText(owner);

    RandomItemType rewardType;
    if (itemTask)
    {
        ItemPrototype const* proto = sObjectMgr.GetItemPrototype(itemTask);
        if (!proto)
            return false;

        body << "We wish to thank you for the " << proto->Name1 << " you provided so kindly. We really appreciate this and may this small gift bring you our thanks!\n";
        body << "\n";
        body << "Many thanks,\n";
        body << guild->GetName() << "\n";
        body << leader->GetName() << "\n";
        rewardType = proto->Quality > ITEM_QUALITY_NORMAL ? RANDOM_ITEM_GUILD_TASK_REWARD_EQUIP_BLUE : RANDOM_ITEM_GUILD_TASK_REWARD_EQUIP_GREEN;
    }
    else if (killTask)
    {
        CreatureInfo const* proto = sObjectMgr.GetCreatureTemplate(killTask);
        if (!proto)
            return false;

        body << "We wish to thank you for the " << proto->Name << " you've killed recently. We really appreciate this and may this small gift bring you our thanks!\n";
        body << "\n";
        body << "Many thanks,\n";
        body << guild->GetName() << "\n";
        body << leader->GetName() << "\n";
        rewardType = RANDOM_ITEM_GUILD_TASK_REWARD_TRADE;
    }

    uint32 payment = GetTaskValue(owner, guildId, "payment");
    if (payment)
        SendThanks(owner, guildId);

    MailDraft draft("Thank You", body.str());

    uint32 itemId = sRandomItemMgr.GetRandomItem(player->getLevel(), rewardType);
    if (itemId)
    {
        Item* item = Item::CreateItem(itemId, 1, leader);
        item->SaveToDB();
        draft.AddItem(item);
    }

    draft.SendMailTo(MailReceiver(ObjectGuid(HIGHGUID_PLAYER, owner)), MailSender(leader));
    player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, owner));
    if (player)
        SendCompletionMessage(player, "rewarded for");

    SetTaskValue(owner, guildId, "activeTask", 0, 0);
    SetTaskValue(owner, guildId, "payment", 0, 0);
    return true;
}

void GuildTaskMgr::CheckKillTask(Player* player, Unit* victim)
{
    if (!player) return;
	Group *group = player->GetGroup();
    if (group)
    {
        for (GroupReference *gr = group->GetFirstMember(); gr; gr = gr->next())
        {
            CheckKillTaskInternal(gr->getSource(), victim);
        }
    }
    else
    {
        CheckKillTaskInternal(player, victim);
    }
}

void GuildTaskMgr::SendCompletionMessage(Player* player, string verb)
{
    ostringstream out; out << player->GetName() << " has " << verb << " a guild task";

    Group* group = player->GetGroup();
    if (group)
    {
        for (GroupReference* gr = group->GetFirstMember(); gr; gr = gr->next())
        {
            Player* member = gr->getSource();
            if (member != player)
                ChatHandler(member->GetSession()).PSendSysMessage(out.str().c_str());
        }
    }
    else
    {
        PlayerbotAI *ai = player->GetPlayerbotAI();
        if (ai && ai->GetMaster())
            ChatHandler(ai->GetMaster()->GetSession()).PSendSysMessage(out.str().c_str());
    }

    ostringstream self; self << "You have " << verb << " a guild task";
    ChatHandler(player->GetSession()).PSendSysMessage(self.str().c_str());
}

void GuildTaskMgr::CheckKillTaskInternal(Player* player, Unit* victim)
{
    uint32 owner = player->GetGUIDLow();
    if (victim->GetTypeId() != TYPEID_UNIT)
        return;

    Creature* creature = reinterpret_cast<Creature*>(victim);
    if (!creature)
        return;

    map<uint32,uint32> tasks = GetTaskValues(owner, "killTask");
    for (map<uint32,uint32>::iterator i = tasks.begin(); i != tasks.end(); ++i)
    {
        uint32 guildId = i->first;
        uint32 value = i->second;
        Guild* guild = sGuildMgr.GetGuildById(guildId);

        if (value != creature->GetCreatureInfo()->Entry)
            continue;

        sLog.outDebug("%s / %s: guild task complete",
                guild->GetName().c_str(), player->GetName());
        SetTaskValue(owner, guildId, "reward", 1,
                urand(sPlayerbotAIConfig.minGuildTaskRewardTime, sPlayerbotAIConfig.maxGuildTaskRewardTime));

        SendCompletionMessage(player, "completed");
    }
}

void GuildTaskMgr::CleanupAdverts()
{
    uint32 deliverTime = time(0) - sPlayerbotAIConfig.maxGuildTaskChangeTime;
    QueryResult *result = CharacterDatabase.PQuery("select id, receiver from mail where subject like 'Guild Task%%' and deliver_time <= '%u'", deliverTime);
    if (!result)
        return;

    int count = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        uint32 receiver = fields[1].GetUInt32();
        Player *player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, receiver));
        if (player) player->RemoveMail(id);
        count++;
    } while (result->NextRow());
    delete result;

    if (count > 0)
    {
        CharacterDatabase.PExecute("delete from mail where subject like 'Guild Task%%' and deliver_time <= '%u'", deliverTime);
        sLog.outBasic("%d old gtask adverts removed", count);
    }
}

void GuildTaskMgr::RemoveDuplicatedAdverts()
{
    uint32 deliverTime = time(0);
    QueryResult *result = CharacterDatabase.PQuery(
            "select m.id, m.receiver from (SELECT max(id) as id, subject, receiver FROM mail where subject like 'Guild Task%%' and deliver_time <= '%u' group by subject, receiver) q "
            "join mail m on m.subject = q.subject where m.id <> q.id and m.deliver_time <= '%u'",
            deliverTime, deliverTime);
    if (!result)
        return;

    list<uint32> ids;
    int count = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        uint32 receiver = fields[1].GetUInt32();
        Player *player = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, receiver));
        if (player) player->RemoveMail(id);
        count++;
        ids.push_back(id);
    } while (result->NextRow());
    delete result;

    if (count > 0)
    {
        list<uint32> buffer;
        for (list<uint32>::iterator i = ids.begin(); i != ids.end(); ++i)
        {
            buffer.push_back(*i);
            if (buffer.size() > 50)
            {
                DeleteMail(buffer);
                buffer.clear();
            }
        }
        DeleteMail(buffer);
        sLog.outBasic("%d duplicated gtask adverts removed", count);
    }

}

void GuildTaskMgr::DeleteMail(list<uint32> buffer)
{
    ostringstream sql;
    sql << "delete from mail where id in ( ";
    bool first = true;
    for (list<uint32>::iterator j = buffer.begin(); j != buffer.end(); ++j)
    {
        if (first) first = false; else sql << ",";
        sql << "'" << *j << "'";
    }
    sql << ")";
    CharacterDatabase.PExecute(sql.str().c_str());
}
