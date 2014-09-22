#include "../pchdef.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotFactory.h"
#include "../../shared/Database/DatabaseEnv.h"
#include "PlayerbotAI.h"
#include "../Entities/Player/Player.h"
#include "RandomPlayerbotFactory.h"
#include "SystemConfig.h"

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

bool RandomPlayerbotFactory::CreateRandomBot(uint8 cls)
{
    sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Creating new random bot for class %d", cls);

    uint8 gender = rand() % 2 ? GENDER_MALE : GENDER_FEMALE;

    uint8 race = availableRaces[cls][urand(0, availableRaces[cls].size() - 1)];
    string name = CreateRandomBotName();
    if (name.empty())
        return false;

    uint8 skin = urand(0, 7);
    uint8 face = urand(0, 7);
    uint8 hairStyle = urand(0, 7);
    uint8 hairColor = urand(0, 7);
    uint8 facialHair = urand(0, 7);
    uint8 outfitId = 0;

    WorldSession* session = new WorldSession(accountId, NULL, SEC_PLAYER, 2, 0, LOCALE_enUS, 0, false);
    if (!session)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Couldn't create session for random bot account %d", accountId);
        delete session;
        return false;
    }

    Player *player = new Player(session);
    WorldPacket data;
    CharacterCreateInfo cci(name, race, cls, gender, skin, face, hairStyle,hairColor, facialHair, outfitId, data);
    if (!player->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_PLAYER), &cci))
    {
        player->DeleteFromDB(player->GetGUID(), accountId, true, true);
        delete session;
        delete player;
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Unable to create random bot for account %d - name: \"%s\"; race: %u; class: %u; gender: %u; skin: %u; face: %u; hairStyle: %u; hairColor: %u; facialHair: %u; outfitId: %u",
                accountId, name.c_str(), race, cls, gender, skin, face, hairStyle, hairColor, facialHair, outfitId);
        return false;
    }

    player->setCinematic(2);
    player->SetAtLoginFlag(AT_LOGIN_NONE);
    player->SaveToDB(true);

    sLog->outMessage("playerbot", LOG_LEVEL_DEBUG, "Random bot created for account %d - name: \"%s\"; race: %u; class: %u; gender: %u; skin: %u; face: %u; hairStyle: %u; hairColor: %u; facialHair: %u; outfitId: %u",
            accountId, name.c_str(), race, cls, gender, skin, face, hairStyle, hairColor, facialHair, outfitId);

    return true;
}

string RandomPlayerbotFactory::CreateRandomBotName()
{
    QueryResult result = CharacterDatabase.Query("SELECT MAX(name_id) FROM ai_playerbot_names");
    if (!result)
        return "";

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

