#include "../pchdef.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotFactory.h"
#include "../../server/database/Database/DatabaseEnv.h"
#include "PlayerbotAI.h"
#include "../../server/game/Entities/Player/Player.h"
#include "../../server/game/Guilds/Guild.h"
#include "../../server/game/Guilds/GuildMgr.h"
#include "RandomPlayerbotFactory.h"

map<uint8, vector<uint8> > RandomPlayerbotFactory::availableRaces;

RandomPlayerbotFactory::RandomPlayerbotFactory(uint32 accountId) : accountId(accountId)
{
    availableRaces[CLASS_WARRIOR].push_back(RACE_HUMAN);
    availableRaces[CLASS_WARRIOR].push_back(RACE_NIGHTELF);
    availableRaces[CLASS_WARRIOR].push_back(RACE_GNOME);
    availableRaces[CLASS_WARRIOR].push_back(RACE_DWARF);
    availableRaces[CLASS_WARRIOR].push_back(RACE_ORC);
    availableRaces[CLASS_WARRIOR].push_back(RACE_UNDEAD_PLAYER);
    availableRaces[CLASS_WARRIOR].push_back(RACE_TAUREN);
    availableRaces[CLASS_WARRIOR].push_back(RACE_TROLL);
    availableRaces[CLASS_WARRIOR].push_back(RACE_DRAENEI);

    availableRaces[CLASS_PALADIN].push_back(RACE_HUMAN);
    availableRaces[CLASS_PALADIN].push_back(RACE_DWARF);
    availableRaces[CLASS_PALADIN].push_back(RACE_DRAENEI);
    availableRaces[CLASS_PALADIN].push_back(RACE_BLOODELF);

    availableRaces[CLASS_ROGUE].push_back(RACE_HUMAN);
    availableRaces[CLASS_ROGUE].push_back(RACE_DWARF);
    availableRaces[CLASS_ROGUE].push_back(RACE_NIGHTELF);
    availableRaces[CLASS_ROGUE].push_back(RACE_GNOME);
    availableRaces[CLASS_ROGUE].push_back(RACE_ORC);
    availableRaces[CLASS_ROGUE].push_back(RACE_TROLL);
    availableRaces[CLASS_ROGUE].push_back(RACE_BLOODELF);

    availableRaces[CLASS_PRIEST].push_back(RACE_HUMAN);
    availableRaces[CLASS_PRIEST].push_back(RACE_DWARF);
    availableRaces[CLASS_PRIEST].push_back(RACE_NIGHTELF);
    availableRaces[CLASS_PRIEST].push_back(RACE_DRAENEI);
    availableRaces[CLASS_PRIEST].push_back(RACE_TROLL);
    availableRaces[CLASS_PRIEST].push_back(RACE_UNDEAD_PLAYER);
    availableRaces[CLASS_PRIEST].push_back(RACE_BLOODELF);

    availableRaces[CLASS_MAGE].push_back(RACE_HUMAN);
    availableRaces[CLASS_MAGE].push_back(RACE_GNOME);
    availableRaces[CLASS_MAGE].push_back(RACE_DRAENEI);
    availableRaces[CLASS_MAGE].push_back(RACE_UNDEAD_PLAYER);
    availableRaces[CLASS_MAGE].push_back(RACE_TROLL);
    availableRaces[CLASS_MAGE].push_back(RACE_BLOODELF);

    availableRaces[CLASS_WARLOCK].push_back(RACE_HUMAN);
    availableRaces[CLASS_WARLOCK].push_back(RACE_GNOME);
    availableRaces[CLASS_WARLOCK].push_back(RACE_UNDEAD_PLAYER);
    availableRaces[CLASS_WARLOCK].push_back(RACE_ORC);
    availableRaces[CLASS_WARLOCK].push_back(RACE_BLOODELF);

    availableRaces[CLASS_SHAMAN].push_back(RACE_DRAENEI);
    availableRaces[CLASS_SHAMAN].push_back(RACE_ORC);
    availableRaces[CLASS_SHAMAN].push_back(RACE_TAUREN);
    availableRaces[CLASS_SHAMAN].push_back(RACE_TROLL);

    availableRaces[CLASS_HUNTER].push_back(RACE_DWARF);
    availableRaces[CLASS_HUNTER].push_back(RACE_NIGHTELF);
    availableRaces[CLASS_HUNTER].push_back(RACE_DRAENEI);
    availableRaces[CLASS_HUNTER].push_back(RACE_ORC);
    availableRaces[CLASS_HUNTER].push_back(RACE_TAUREN);
    availableRaces[CLASS_HUNTER].push_back(RACE_TROLL);
    availableRaces[CLASS_HUNTER].push_back(RACE_BLOODELF);

    availableRaces[CLASS_DRUID].push_back(RACE_NIGHTELF);
    availableRaces[CLASS_DRUID].push_back(RACE_TAUREN);
}

typedef std::multimap<uint32, CharSectionsEntry const*> CharSectionsMap;
extern CharSectionsMap sCharSectionMap;
CharSectionsEntry const* GetRandomCharSection(uint8 race, CharSectionType genType, uint8 gender, uint8 color = 255)
{
    vector<CharSectionsEntry const*> charSections;
    std::pair<CharSectionsMap::const_iterator, CharSectionsMap::const_iterator> eqr = sCharSectionMap.equal_range(uint32(genType) | uint32(gender << 8) | uint32(race << 16));
    for (CharSectionsMap::const_iterator itr = eqr.first; itr != eqr.second; ++itr)
    {
        CharSectionsEntry const* charSection = itr->second;
        if ((charSection->Flags & SECTION_FLAG_PLAYER) && !(charSection->Flags & SECTION_FLAG_DEATH_KNIGHT)
                && (charSection->Color == color || color == 255))
        {
            charSections.push_back(itr->second);
        }
    }
    if (charSections.empty())
    {
        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "No match for race=%u gender=%u color=%u type=%u",
                race, gender, color, genType);
        return NULL;
    }

    uint32 charSectionIndex = urand(0, charSections.size() - 1);
    return charSections[charSectionIndex];
}

bool RandomPlayerbotFactory::CreateRandomBot(uint8 cls)
{
    sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Creating new random bot for class %d", cls);

    uint8 gender = rand() % 2 ? GENDER_MALE : GENDER_FEMALE;

    uint8 race = availableRaces[cls][urand(0, availableRaces[cls].size() - 1)];
    string name = CreateRandomBotName();
    if (name.empty())
        return false;

    CharSectionsEntry const* skin = GetRandomCharSection(race, SECTION_TYPE_SKIN, gender);
    CharSectionsEntry const* face = GetRandomCharSection(race, SECTION_TYPE_FACE, gender, skin->Color);
    CharSectionsEntry const* hair = GetRandomCharSection(race, SECTION_TYPE_HAIR, gender);
    CharSectionsEntry const* facialHair = GetRandomCharSection(race, SECTION_TYPE_FACIAL_HAIR, gender, hair->Color);
    uint8 outfitId = 0;

    WorldSession* session = new WorldSession(accountId, "rndbot", NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false);
    if (!session)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Couldn't create session for random bot account %d", accountId);
        delete session;
        return false;
    }

    Player *player = new Player(session);

    CharacterCreateInfo cci;
    cci.Name = name;
    cci.Race = race;
    cci.Class = cls;
    cci.Gender = gender;
    cci.Skin = skin->Color;
    cci.Face = face->Type;
    cci.HairStyle = hair->Type;
    cci.HairColor = hair->Color;
    cci.FacialHair = facialHair ? facialHair->Type : 0;
    cci.OutfitId = outfitId;

    if (!player->Create(sObjectMgr->GetGenerator<HighGuid::Player>().Generate(), &cci))
    {
        player->DeleteFromDB(player->GetGUID(), accountId, true, true);
        delete session;
        delete player;
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Unable to create random bot for account %d - name: \"%s\"; race: %u; class: %u",
                accountId, name.c_str(), race, cls);
        return false;
    }

    player->setCinematic(2);
    player->SetAtLoginFlag(AT_LOGIN_NONE);
    player->SaveToDB(true);

    sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Random bot created for account %d - name: \"%s\"; race: %u; class: %u",
            accountId, name.c_str(), race, cls);

    return true;
}

string RandomPlayerbotFactory::CreateRandomBotName()
{
    QueryResult result = CharacterDatabase.Query("SELECT MAX(name_id) FROM ai_playerbot_names");
    if (!result)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "No more names left for random guilds");
        return "";
    }

    Field *fields = result->Fetch();
    uint32 maxId = fields[0].GetUInt32();

    uint32 id = urand(0, maxId);
    result = CharacterDatabase.PQuery("SELECT n.name FROM ai_playerbot_names n "
            "LEFT OUTER JOIN characters e ON e.name = n.name "
            "WHERE e.guid IS NULL AND n.name_id >= '%u' LIMIT 1", id);
    if (!result)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "No more names left for random bots");
        return "";
    }

	fields = result->Fetch();
    return fields[0].GetString();
}


void RandomPlayerbotFactory::CreateRandomBots()
{
    if (sPlayerbotAIConfig.deleteRandomBotAccounts)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Deleting random bot accounts...");
        QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username like '%s%%'", sPlayerbotAIConfig.randomBotAccountPrefix.c_str());
        if (results)
        {
            do
            {
                Field* fields = results->Fetch();
                sAccountMgr->DeleteAccount(fields[0].GetUInt32());
            } while (results->NextRow());
        }

        CharacterDatabase.Execute("DELETE FROM ai_playerbot_random_bots");
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Random bot accounts deleted");
    }

    for (int accountNumber = 0; accountNumber < sPlayerbotAIConfig.randomBotAccountCount; ++accountNumber)
    {
        ostringstream out; out << sPlayerbotAIConfig.randomBotAccountPrefix << accountNumber;
        string accountName = out.str();
        QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username = '%s'", accountName.c_str());
        if (results)
        {
            continue;
        }

        string password = "";
        for (int i = 0; i < 10; i++)
        {
            password += (char)urand('!', 'z');
        }
        sAccountMgr->CreateAccount(accountName, password, "playerbot");

        sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Account %s created for random bots", accountName.c_str());
    }

    LoginDatabase.PExecute("UPDATE account SET expansion = '%u' where username like '%s%%'", 2, sPlayerbotAIConfig.randomBotAccountPrefix.c_str());

    int totalRandomBotChars = 0;
    for (int accountNumber = 0; accountNumber < sPlayerbotAIConfig.randomBotAccountCount; ++accountNumber)
    {
        ostringstream out; out << sPlayerbotAIConfig.randomBotAccountPrefix << accountNumber;
        string accountName = out.str();

        QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username = '%s'", accountName.c_str());
        if (!results)
            continue;

        Field* fields = results->Fetch();
        uint32 accountId = fields[0].GetUInt32();

        sPlayerbotAIConfig.randomBotAccounts.push_back(accountId);

        int count = sAccountMgr->GetCharactersCount(accountId);
        if (count >= 10)
        {
            totalRandomBotChars += count;
            continue;
        }

        RandomPlayerbotFactory factory(accountId);
        for (uint8 cls = CLASS_WARRIOR; cls < MAX_CLASSES; ++cls)
        {
            if (cls != 10 && cls != CLASS_DEATH_KNIGHT)
                factory.CreateRandomBot(cls);
        }

        totalRandomBotChars += sAccountMgr->GetCharactersCount(accountId);
    }

    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "%d random bot accounts with %d characters available", sPlayerbotAIConfig.randomBotAccounts.size(), totalRandomBotChars);
}


void RandomPlayerbotFactory::CreateRandomGuilds()
{
    vector<uint32> randomBots;
    QueryResult results = LoginDatabase.PQuery("SELECT id FROM account where username like '%s%%'", sPlayerbotAIConfig.randomBotAccountPrefix.c_str());
    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            uint32 accountId = fields[0].GetUInt32();

            QueryResult results2 = CharacterDatabase.PQuery("SELECT guid FROM characters where account  = '%u'", accountId);
            if (results2)
            {
                do
                {
                    Field* fields = results2->Fetch();
                    uint32 guid = fields[0].GetUInt32();
                    randomBots.push_back(guid);
                } while (results2->NextRow());
            }

        } while (results->NextRow());
    }

    if (sPlayerbotAIConfig.deleteRandomBotGuilds)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Deleting random bot guilds...");
        for (vector<uint32>::iterator i = randomBots.begin(); i != randomBots.end(); ++i)
        {
            ObjectGuid leader(HighGuid::Player, *i);
            Guild* guild = sGuildMgr->GetGuildByLeader(leader);
            if (guild) guild->Disband();
        }
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Random bot guilds deleted");
    }

    int guildNumber = 0;
    vector<ObjectGuid> availableLeaders;
    for (vector<uint32>::iterator i = randomBots.begin(); i != randomBots.end(); ++i)
    {
        ObjectGuid leader(HighGuid::Player, *i);
        Guild* guild = sGuildMgr->GetGuildByLeader(leader);
        if (guild)
        {
            ++guildNumber;
            sPlayerbotAIConfig.randomBotGuilds.push_back(guild->GetId());
        }
        else
        {
            Player* player = sObjectMgr->GetPlayerByLowGUID(leader);
            if (player)
                availableLeaders.push_back(leader);
        }
    }

    for (; guildNumber < sPlayerbotAIConfig.randomBotGuildCount; ++guildNumber)
    {
        string guildName = CreateRandomGuildName();
        if (guildName.empty())
            break;

        if (availableLeaders.empty())
        {
            sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "No leaders for random guilds available");
            break;
        }

        int index = urand(0, availableLeaders.size() - 1);
        ObjectGuid leader = availableLeaders[index];
        Player* player = sObjectMgr->GetPlayerByLowGUID(leader);
        if (!player)
        {
            sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Cannot find player for leader %u", leader);
            break;
        }

        Guild* guild = new Guild();
        if (!guild->Create(player, guildName))
        {
            sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Error creating guild %s", guildName.c_str());
            break;
        }

        sGuildMgr->AddGuild(guild);
        sPlayerbotAIConfig.randomBotGuilds.push_back(guild->GetId());
    }

    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "%d random bot guilds available", guildNumber);
}

string RandomPlayerbotFactory::CreateRandomGuildName()
{
    QueryResult result = CharacterDatabase.Query("SELECT MAX(name_id) FROM ai_playerbot_guild_names");
    if (!result)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "No more names left for random guilds");
        return "";
    }

    Field *fields = result->Fetch();
    uint32 maxId = fields[0].GetUInt32();

    uint32 id = urand(0, maxId);
    result = CharacterDatabase.PQuery("SELECT n.name FROM ai_playerbot_guild_names n "
            "LEFT OUTER JOIN guild e ON e.name = n.name "
            "WHERE e.guildid IS NULL AND n.name_id >= '%u' LIMIT 1", id);
    if (!result)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "No more names left for random guilds");
        return "";
    }

    fields = result->Fetch();
    return fields[0].GetString();
}

