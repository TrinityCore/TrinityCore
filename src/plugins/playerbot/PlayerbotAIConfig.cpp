#include "../pchdef.h"
#include "PlayerbotAIConfig.h"
#include "playerbot.h"
#include "RandomPlayerbotFactory.h"
#include "AccountMgr.h"
#include "World.h"

using namespace std;

PlayerbotAIConfig::PlayerbotAIConfig()
{
}

template <class T>
void LoadList(string value, T &list)
{
    vector<string> ids = split(value, ',');
    for (vector<string>::iterator i = ids.begin(); i != ids.end(); i++)
    {
        uint32 id = atoi((*i).c_str());
        if (!id)
            continue;

        list.push_back(id);
    }
}

bool PlayerbotAIConfig::Initialize()
{
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Initializing AI Playerbot by ike3, based on the original Playerbot by blueboy and updated by LordPsyan");

    string error;
    vector<string> args;
    if (!sWorld->getBoolConfig(CONFIG_AIPLYERBOT_ENABLED))
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "AI Playerbot is Disabled. Unable to open configuration file worldserver.conf");
        return false;
    }

    enabled = sConfigMgr->GetBoolDefault("AiPlayerbot.Enabled", true);
    if (!enabled)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_INFO, "AI Playerbot is Disabled in worldserver.conf");
        return false;
    }

    // thesawolf - not so random bot creation
    notrandom = sConfigMgr->GetBoolDefault("AiPlayerbot.NotSoRandom", true);
    
    // thesawolf - ARAC chargen support
    aracgen = sConfigMgr->GetBoolDefault("AiPlayerbot.ARAC", false);

    globalCoolDown = (uint32) sWorld->getIntConfig(CONFIG_AIPLYERBOT_GLOBALCOOLDOWN);
    maxWaitForMove = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXWAITFORMOVE);
    reactDelay = (uint32) sWorld->getIntConfig(CONFIG_AIPLYERBOT_REACTDELAY);

    sightDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_SIGHTDISTANCE);
    spellDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_SPELLDISTANCE);
	shootDistance = sConfigMgr->GetFloatDefault("AiPlayerbot.ShootDistance", 11.0f);
    reactDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_REACTDISTANCE);
    grindDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_GRINDDISTANCE);
    lootDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_LOOTDISTANCE);
    fleeDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_FLEEDISTANCE);
    tooCloseDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_TOOCLOSEDISTANCE);
    meleeDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_MELEEDISTANCE);
    followDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_FOLLOWDISTANCE);
    whisperDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_WHISPERDISTANCE);
    contactDistance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_CONTACTDISTANCE);

    criticalHealth = sWorld->getIntConfig(CONFIG_AIPLYERBOT_CRITICALHEALTH);
    lowHealth = sWorld->getIntConfig(CONFIG_AIPLYERBOT_LOWHEALTH);
    mediumHealth = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MEDIUMHEALTH);
    almostFullHealth = sWorld->getIntConfig(CONFIG_AIPLYERBOT_ALMOSTFULLHEALTH);
    lowMana = sWorld->getIntConfig(CONFIG_AIPLYERBOT_LOWMANA);
    mediumMana = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MEDIUMMANA);

    randomGearLoweringChance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_RANDOMGEARLOWERINGCHANCE);
    randomBotMaxLevelChance = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_RANDOMBOTMAXLEVELCHANCE);

    iterationsPerTick = sWorld->getIntConfig(CONFIG_AIPLYERBOT_ITERATIONSPERTICK);

    allowGuildBots = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_ALLOWGUILDBOTS);

    randomBotMapsAsString = sConfigMgr->GetStringDefault("AiPlayerbot.RandomBotMaps", "0,1,530,571");
    LoadList<vector<uint32> >(randomBotMapsAsString, randomBotMaps);
    LoadList<list<uint32> >(sConfigMgr->GetStringDefault("AiPlayerbot.RandomBotQuestItems", "6948,5175,5176,5177,5178"), randomBotQuestItems);
    LoadList<list<uint32> >(sConfigMgr->GetStringDefault("AiPlayerbot.RandomBotSpellIds", "54197"), randomBotSpellIds);

    randomBotAutologin = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_RANDOMBOTAUTOLOGIN);
    minRandomBots = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINRANDOMBOTS);
    maxRandomBots = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXRANDOMBOTS);
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "Reading min/max bots of %u - %u", minRandomBots, maxRandomBots);
    randomBotUpdateInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTUPDATEINTERVAL);
    randomBotCountChangeMinInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTCOUNTCHANGEMININTERVAL);
    randomBotCountChangeMaxInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTCOUNTCHANGEMAXINTERVAL);
    minRandomBotInWorldTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINRANDOMBOTINWORLDTIME);
    maxRandomBotInWorldTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXRANDOMBOTINWORLDTIME);
    minRandomBotRandomizeTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINRANDOMBOTRANDOMIZETIME);
    maxRandomBotRandomizeTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXRANDOMBOTRANDOMIZETIME);
    minRandomBotReviveTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINRANDOMBOTREVIVETIME);
    maxRandomBotReviveTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXRANDOMBOTREVIVETIME);
    randomBotTeleportDistance = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTTELEPORTDISTANCE);
    minRandomBotsPerInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINRANDOMBOTSPERINTERVAL);
    maxRandomBotsPerInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXRANDOMBOTSPERINTERVAL);
    minRandomBotsPriceChangeInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINRANDOMBOTSPRICECHANGEINTERVAL);
    maxRandomBotsPriceChangeInterval = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXRANDOMBOTSPRICECHANGEINTERVAL);
    randomBotJoinLfg = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_RANDOMBOTJOINLFG);
    randomBotJoinBG = sConfigMgr->GetBoolDefault("AiPlayerbot.RandomBotJoinBG", true);
    logInGroupOnly = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_LOGINGROUPONLY);
    logValuesPerTick = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_LOGVALUESPERTICK);
    fleeingEnabled = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_FLEEINGENABLED);
    randomBotMinLevel = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTMINLEVEL);
    randomBotMaxLevel = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTMAXLEVEL);
    randomBotBracketPlayer = sConfigMgr->GetBoolDefault("AIPlayerbot.RandomBotBracketPlayer", true);
    randomBotLoginAtStartup = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_RANDOMBOTLOGINATSTARTUP);
    randomBotTeleLevel = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTTELELEVEL);
	randomBotInitQuest = sConfigMgr->GetBoolDefault("AiPlayerbot.randomBotInitQuest", true);
	randomBotShowHelmet = sConfigMgr->GetBoolDefault("AiPlayerbot.randomBotShowHelmet", true);

    randomChangeMultiplier = sWorld->getFloatConfig(CONFIG_AIPLYERBOT_RANDOMCHANGEMULTIPLIER);

    randomBotCombatStrategies = sConfigMgr->GetStringDefault("AiPlayerbot.RandomBotCombatStrategies", "+dps,+attack weak,-threat");
    randomBotNonCombatStrategies = sConfigMgr->GetStringDefault("AiPlayerbot.RandomBotNonCombatStrategies", "+grind,+move random,+loot");
	combatStrategies = config.GetStringDefault("AiPlayerbot.CombatStrategies", "+custom::say");
	nonCombatStrategies = config.GetStringDefault("AiPlayerbot.NonCombatStrategies", "+custom::say");

    commandPrefix = sConfigMgr->GetStringDefault("AiPlayerbot.CommandPrefix", "");

    commandServerPort = sWorld->getIntConfig(CONFIG_AIPLYERBOT_COMMANDSERVERPORT);

    for (uint32 cls = 0; cls < MAX_CLASSES; ++cls)
    {
        for (uint32 spec = 0; spec < 3; ++spec)
        {
            ostringstream os; os << "AiPlayerbot.RandomClassSpecProbability." << cls << "." << spec;
            specProbability[cls][spec] = sConfigMgr->GetIntDefault(os.str().c_str(), 33);
        }
    }

    randomBotAccountPrefix = sConfigMgr->GetStringDefault("AiPlayerbot.RandomBotAccountPrefix", "rndbot");
    randomBotAccountCount = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTACCOUNTCOUNT);
    deleteRandomBotAccounts = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_DELETERANDOMBOTACCOUNTS);
    randomBotGuildCount = sWorld->getIntConfig(CONFIG_AIPLYERBOT_RANDOMBOTGUILDCOUNT);
    deleteRandomBotGuilds = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_DELETERANDOMBOTGUILDS);

    guildTaskEnabled = sWorld->getBoolConfig(CONFIG_AIPLYERBOT_GUILDTASKENABLED);
    minGuildTaskChangeTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINGUILDTASKCHANGETIME);
    maxGuildTaskChangeTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXGUILDTASKCHANGETIME);
    minGuildTaskAdvertisementTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINGUILDTASKADVERTISEMENTTIME);
    maxGuildTaskAdvertisementTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXGUILDTASKADVERTISEMENTTIME);
    minGuildTaskRewardTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MINGUILDTASKREWARDTIME);
    maxGuildTaskRewardTime = sWorld->getIntConfig(CONFIG_AIPLYERBOT_MAXGUILDTASKREWARDTIME);

    CharacterDatabase.Execute("delete from ai_playerbot_random_bots");

    RandomPlayerbotFactory::CreateRandomBots();
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, "AI Playerbot configuration loaded");

    return true;
}


bool PlayerbotAIConfig::IsInRandomAccountList(uint32 id)
{
    return find(randomBotAccounts.begin(), randomBotAccounts.end(), id) != randomBotAccounts.end();
}

bool PlayerbotAIConfig::IsInRandomQuestItemList(uint32 id)
{
    return find(randomBotQuestItems.begin(), randomBotQuestItems.end(), id) != randomBotQuestItems.end();
}

string PlayerbotAIConfig::GetValue(string name)
{
    ostringstream out;

    if (name == "GlobalCooldown")
        out << globalCoolDown;
    else if (name == "ReactDelay")
        out << reactDelay;

    else if (name == "SightDistance")
        out << sightDistance;
    else if (name == "SpellDistance")
        out << spellDistance;
    else if (name == "ReactDistance")
        out << reactDistance;
    else if (name == "GrindDistance")
        out << grindDistance;
    else if (name == "LootDistance")
        out << lootDistance;
    else if (name == "FleeDistance")
        out << fleeDistance;

    else if (name == "CriticalHealth")
        out << criticalHealth;
    else if (name == "LowHealth")
        out << lowHealth;
    else if (name == "MediumHealth")
        out << mediumHealth;
    else if (name == "AlmostFullHealth")
        out << almostFullHealth;
    else if (name == "LowMana")
        out << lowMana;

    else if (name == "IterationsPerTick")
        out << iterationsPerTick;

    return out.str();
}

void PlayerbotAIConfig::SetValue(string name, string value)
{
    istringstream out(value, istringstream::in);

    if (name == "GlobalCooldown")
        out >> globalCoolDown;
    else if (name == "ReactDelay")
        out >> reactDelay;

    else if (name == "SightDistance")
        out >> sightDistance;
    else if (name == "SpellDistance")
        out >> spellDistance;
    else if (name == "ReactDistance")
        out >> reactDistance;
    else if (name == "GrindDistance")
        out >> grindDistance;
    else if (name == "LootDistance")
        out >> lootDistance;
    else if (name == "FleeDistance")
        out >> fleeDistance;

    else if (name == "CriticalHealth")
        out >> criticalHealth;
    else if (name == "LowHealth")
        out >> lowHealth;
    else if (name == "MediumHealth")
        out >> mediumHealth;
    else if (name == "AlmostFullHealth")
        out >> almostFullHealth;
    else if (name == "LowMana")
        out >> lowMana;

    else if (name == "IterationsPerTick")
        out >> iterationsPerTick;
}
