/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "WorldConfigMgr.h"
#include "DatabaseEnv.h"
#include "GridDefines.h"
#include "ObjectDefines.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Player.h"
#include "World.h"
#include "Util.h"

WorldConfig* WorldConfig::instance()
{
    static WorldConfig instance;
    return &instance;
}

void WorldConfig::AddOption(std::string const& /*optionName*/, WorldConfigType type, uint32 IDinTypeGroup, std::string const& defaultValue, std::string const& value)
{
    switch (type)
    {
    case WorldConfigType::GAME_CONFIG_TYPE_BOOL:
        AddBoolOption(IDinTypeGroup, value.empty() ? StringToBool(defaultValue) : StringToBool(value));
        break;
    case WorldConfigType::GAME_CONFIG_TYPE_INT:
        AddIntOption(IDinTypeGroup, value.empty() ? (uint32)std::stoi(defaultValue) : (uint32)std::stoi(value));
        break;
    case WorldConfigType::GAME_CONFIG_TYPE_FLOAT:
        AddFloatOption(IDinTypeGroup, value.empty() ? std::stof(defaultValue) : std::stof(value));
        break;
    case WorldConfigType::GAME_CONFIG_TYPE_RATES:
        AddRateOption(IDinTypeGroup, value.empty() ? std::stof(defaultValue) : std::stof(value));
        break;
    case WorldConfigType::GAME_CONFIG_TYPE_STRINGS:
        AddStringOption(IDinTypeGroup, value.empty() ? defaultValue : value);
        break;
    default:
        ABORT();
        break;
    }
}

void WorldConfig::Load()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.PQuery("SELECT `OptionName`, `Type`, `IDInTypeGroup`, `DefaultValue`, `CustomValue` FROM world_config");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 game config options. DB table `game_config` is empty.");
        TC_LOG_INFO("server.loading", "");
        return;
    }

    uint32 count = 0;

    auto GetTypeString = [](std::string optionType) -> WorldConfigType
    {
        if (optionType == "bool")
            return WorldConfigType::GAME_CONFIG_TYPE_BOOL;
        else if (optionType == "int")
            return WorldConfigType::GAME_CONFIG_TYPE_INT;
        else if (optionType == "float")
            return WorldConfigType::GAME_CONFIG_TYPE_FLOAT;
        else if (optionType == "rate")
            return WorldConfigType::GAME_CONFIG_TYPE_RATES;
        else if (optionType == "string")
            return WorldConfigType::GAME_CONFIG_TYPE_STRINGS;
        else
            return WorldConfigType::GAME_CONFIG_TYPE_UNKNOWN;
    };

    do
    {
        Field* fields = result->Fetch();

        std::string const& optionName   = fields[0].GetString();
        std::string const& optionType   = fields[1].GetString();
        uint32 IDinTypeGroup            = fields[2].GetUInt32();
        std::string const& defaultValue = fields[3].GetString();
        std::string const& customValue  = fields[4].GetString();

        auto _type = GetTypeString(optionType);

        if (_type == WorldConfigType::GAME_CONFIG_TYPE_UNKNOWN)
        {
            TC_LOG_ERROR("config", "> Don't support type (%s) for option (%s)", optionType.c_str(), optionName.c_str());
            continue;
        }

        AddOption(optionName, _type, IDinTypeGroup, defaultValue, customValue);

        count++;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u game config option in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    TC_LOG_INFO("server.loading", "");
}

void WorldConfig::RecheckAndFixDependancy()
{
    uint32 oldMSTime = getMSTime();
    // for float
    for (uint32 i = 0; i < WorldFloatConfigs::FLOAT_CONFIG_VALUE_COUNT; i++)
    {
        float value = sWorld->getFloatConfig(WorldFloatConfigs(i));
        // TODO: this 2 case should be moved in Rate
        switch (WorldFloatConfigs(i))
        {
            case WorldFloatConfigs::CONFIG_RESPAWN_DYNAMICRATE_CREATURE:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Respawn.DynamicRateCreature (%f) must be positive. Set to 10.", value);
                    sWorld->setFloatConfig(WorldFloatConfigs(i), 10.0f);
                }
                break;
            }
            case WorldFloatConfigs::CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Respawn.DynamicRateGameObject (%f) must be positive. Set to 10.", value);
                    sWorld->setFloatConfig(WorldFloatConfigs(i), 10.0f);
                }
                break;
            }
            case WorldFloatConfigs::CONFIG_VISIBLITY_DISTANCE_CONTINENTS:
            {
                if (value < 45 * sWorld->getRate(RATE_CREATURE_AGGRO))
                {
                    TC_LOG_ERROR("config", "Visibility.Distance.Continents can't be less max aggro radius %f", 45 * sWorld->getRate(RATE_CREATURE_AGGRO));
                    sWorld->setFloatConfig(WorldFloatConfigs(i), 45 * sWorld->getRate(RATE_CREATURE_AGGRO));
                }
                else if (value > MAX_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("server.loading", "Visibility.Distance.Continents can't be greater %f", MAX_VISIBILITY_DISTANCE);
                    sWorld->setFloatConfig(WorldFloatConfigs(i), MAX_VISIBILITY_DISTANCE);
                }
                break;
            }
            case WorldFloatConfigs::CONFIG_VISIBILITY_DISTANCE_INSTANCES:
            {
                if (value < 45 * sWorld->getRate(RATE_CREATURE_AGGRO))
                {
                    TC_LOG_ERROR("server.loading", "Visibility.Distance.Instances can't be less max aggro radius %f", 45 * sWorld->getRate(RATE_CREATURE_AGGRO));
                    sWorld->setFloatConfig(WorldFloatConfigs(i), 45 * sWorld->getRate(RATE_CREATURE_AGGRO));
                }
                else if (value > MAX_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("server.loading", "Visibility.Distance.Instances can't be greater %f", MAX_VISIBILITY_DISTANCE);
                    sWorld->setFloatConfig(WorldFloatConfigs(i), MAX_VISIBILITY_DISTANCE);
                }
                break;
            }
            case WorldFloatConfigs::CONFIG_VISIBILITY_DISTANCE_BGARENAS:
            {
                if (value < 45 * sWorld->getRate(RATE_CREATURE_AGGRO))
                {
                    TC_LOG_ERROR("server.loading", "Visibility.Distance.BGArenas can't be less max aggro radius %f", 45 * sWorld->getRate(RATE_CREATURE_AGGRO));
                    sWorld->setFloatConfig(WorldFloatConfigs(i), 45 * sWorld->getRate(RATE_CREATURE_AGGRO));
                }
                else if (value > MAX_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("server.loading", "Visibility.Distance.BGArenas can't be greater %f", MAX_VISIBILITY_DISTANCE);
                    sWorld->setFloatConfig(WorldFloatConfigs(i), MAX_VISIBILITY_DISTANCE);
                }
                break;
            }
            default:
                break;
        }
    }

    // for rate
    for (uint32 i = 0; i < Rates::MAX_RATES; i++)
    {
        float value = sWorld->getRate(Rates(i));
        switch (Rates(i))
        {
            case Rates::RATE_HEALTH:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.Health (%f) must be > 0. Using 1 instead.", value);
                    sWorld->setRate(Rates(i), 1.0f);
                }
                break;
            }
            case Rates::RATE_POWER_MANA:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.Mana (%f) must be > 0. Using 1 instead.", value);
                    sWorld->setRate(Rates(i), 1.0f);
                }
                break;
            }
            case Rates::RATE_POWER_RAGE_LOSS:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.Rage.Loss (%f) must be > 0. Using 1 instead.", value);
                    sWorld->setRate(Rates(i), 1.0f);
                }
                break;
            }
            case Rates::RATE_POWER_RUNICPOWER_LOSS:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.RunicPower.Loss (%f) must be > 0. Using 1 instead.", value);
                    sWorld->setRate(Rates(i), 1.0f);
                }
                break;
            }
            case Rates::RATE_REPAIRCOST:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.RepairCost (%f) must be >=0. Using 0.0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            case Rates::RATE_TALENT:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.Talent (%f) must be > 0. Using 1 instead.", value);
                    sWorld->setRate(Rates(i), 1.0f);
                }
                break;
            }
            case Rates::RATE_DURABILITY_LOSS_ON_DEATH:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "DurabilityLoss.OnDeath (%f) must be >=0. Using 0.0 instead.", value);
                    value = 0.0f;
                }
                else if (value > 100.0f)
                {
                    TC_LOG_ERROR("config", "DurabilityLoss.OnDeath (%f) must be <= 100. Using 100.0 instead.", value);
                    value = 100.0f;
                }
                value /= 100.0f;
                break;
            }
            case Rates::RATE_DURABILITY_LOSS_DAMAGE:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "DurabilityLossChance.Damage (%f) must be >=0. Using 0.0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            case Rates::RATE_DURABILITY_LOSS_PARRY:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "DurabilityLossChance.Parry (%f) must be >=0. Using 0.0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            case Rates::RATE_DURABILITY_LOSS_ABSORB:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "DurabilityLossChance.Absorb (%f) must be >=0. Using 0.0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            case Rates::RATE_DURABILITY_LOSS_BLOCK:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "DurabilityLossChance.Block (%f) must be >=0. Using 0.0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            case Rates::RATE_MOVESPEED:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.MoveSpeed (%f) must be > 0. Using 1 instead.", value);
                    sWorld->setRate(Rates(i), 1.0f);
                }
                break;
            }
            case Rates::RATE_MONEY_QUEST:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.Quest.Money.Reward (%f) must be >=0. Using 0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            case Rates::RATE_MONEY_MAX_LEVEL_QUEST:
            {
                if (value < 0.0f)
                {
                    TC_LOG_ERROR("config", "Rate.Quest.Money.Max.Level.Reward (%f) must be >=0. Using 0 instead.", value);
                    sWorld->setRate(Rates(i), 0.0f);
                }
                break;
            }
            default:
                break;
        }
    }

    // for int
    for (uint32 i = 0; i < WorldIntConfigs::INT_CONFIG_VALUE_COUNT; i++)
    {
        uint32 value = sWorld->getIntConfig(WorldIntConfigs(i));
        switch (WorldIntConfigs(i))
        {
            case WorldIntConfigs::CONFIG_COMPRESSION:
            {
                if (value < 1 || value > 9)
                {
                    TC_LOG_ERROR("config", "Compression level (%i) must be in range 1..9. Using default compression level (1).", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 1);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_INTERVAL_GRIDCLEAN:
            {
                if (value < MIN_GRID_DELAY)
                {
                    TC_LOG_ERROR("config", "GridCleanUpDelay (%i) must be greater %u. Use this minimal value.", value, MIN_GRID_DELAY);
                    sWorld->setIntConfig(WorldIntConfigs(i), MIN_GRID_DELAY);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_INTERVAL_MAPUPDATE:
            {
                if (value < MIN_MAP_UPDATE_DELAY)
                {
                    TC_LOG_ERROR("config", "MapUpdateInterval (%i) must be greater %u. Use this minimal value.", value, MIN_MAP_UPDATE_DELAY);
                    sWorld->setIntConfig(WorldIntConfigs(i), MIN_MAP_UPDATE_DELAY);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MIN_PLAYER_NAME:
            {
                if (value < 1 || value > MAX_PLAYER_NAME)
                {
                    TC_LOG_ERROR("config", "MinPlayerName (%i) must be in range 1..%u. Set to 2.", value, MAX_PLAYER_NAME);
                    sWorld->setIntConfig(WorldIntConfigs(i), 2);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MIN_CHARTER_NAME:
            {
                if (value < 1 || value > MAX_CHARTER_NAME)
                {
                    TC_LOG_ERROR("config", "MinCharterName (%i) must be in range 1..%u. Set to 2.", value, MAX_CHARTER_NAME);
                    sWorld->setIntConfig(WorldIntConfigs(i), 2);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MIN_PET_NAME:
            {
                if (value < 1 || value > MAX_PET_NAME)
                {
                    TC_LOG_ERROR("config", "MinPetName (%i) must be in range 1..%u. Set to 2.", value, MAX_PET_NAME);
                    sWorld->setIntConfig(WorldIntConfigs(i), 2);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_CHARACTERS_PER_REALM:
            {
                if (value < 1 || value > 10)
                {
                    TC_LOG_ERROR("config", "CharactersPerRealm (%i) must be in range 1..10. Set to 10.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 10);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_CHARACTERS_PER_ACCOUNT:
            {
                uint32 accPerAcc = sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM);
                if (value < accPerAcc)
                {
                    TC_LOG_ERROR("config", "CharactersPerAccount (%i) can't be less than CharactersPerRealm (%i).", value, accPerAcc);
                    sWorld->setIntConfig(WorldIntConfigs(i), accPerAcc);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_DEATH_KNIGHTS_PER_REALM:
            {
                if (value < 0 || value > 10)
                {
                    TC_LOG_ERROR("config", "DeathKnightsPerRealm (%i) must be in range 0..10. Set to 1.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 1);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_SKIP_CINEMATICS:
            {
                if (value < 0 || value > 2)
                {
                    TC_LOG_ERROR("config", "SkipCinematics (%i) must be in range 0..2. Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MAX_PLAYER_LEVEL:
            {
                if (value < 1 || value > STRONG_MAX_LEVEL)
                {
                    TC_LOG_ERROR("config", "MaxPlayerLevel (%i) must be in range 1..255. Set to 1.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 1);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_START_PLAYER_LEVEL:
            {
                uint32 maxStartLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
                if (value < 1 || value > maxStartLevel)
                {
                    TC_LOG_ERROR("config", "StartPlayerLevel (%i) must be in range 0..(%i). Set to max.", value, maxStartLevel);
                    sWorld->setIntConfig(WorldIntConfigs(i), maxStartLevel);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL:
            {
                uint32 minDKStartLevel = sWorld->getIntConfig(CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_DEATH_KNIGHT);
                uint32 maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
                if (value < minDKStartLevel)
                {
                    TC_LOG_ERROR("config", "StartDeathKnightPlayerLevel (%i) must be in range (%i)..(%i). Set to min.", value, minDKStartLevel, maxLevel);
                    sWorld->setIntConfig(WorldIntConfigs(i), minDKStartLevel);
                }
                else if (value > maxLevel)
                {
                    TC_LOG_ERROR("config", "StartDeathKnightPlayerLevel (%i) must be in range (%i)..(%i). Set to max.", value, minDKStartLevel, maxLevel);
                    sWorld->setIntConfig(WorldIntConfigs(i), maxLevel);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_START_PLAYER_MONEY:
            {
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "StartPlayerMoney (%i) must be in range 0..%u. Set to 0.", value, MAX_MONEY_AMOUNT);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                else if (value > MAX_MONEY_AMOUNT)
                {
                    TC_LOG_ERROR("config", "StartPlayerMoney (%i) must be in range 0..%u. Set to max.", value, MAX_MONEY_AMOUNT);
                    sWorld->setIntConfig(WorldIntConfigs(i), MAX_MONEY_AMOUNT);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MAX_HONOR_POINTS:
            {
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "MaxHonorPoints (%i) can't be negative. Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_START_HONOR_POINTS:
            {
                uint32 maxHonor = sWorld->getIntConfig(CONFIG_MAX_HONOR_POINTS);
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "MaxHonorPoints (%i) can't be negative. Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                else if (value > maxHonor)
                {
                    TC_LOG_ERROR("config", "StartHonorPoints (%i) must be in range 0..MaxHonorPoints(%u). Set to %u.", value, maxHonor, maxHonor);
                    sWorld->setIntConfig(WorldIntConfigs(i), maxHonor);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MAX_ARENA_POINTS:
            {
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "MaxArenaPoints (%i) can't be negative. Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_START_ARENA_POINTS:
            {
                uint32 maxAP = sWorld->getIntConfig(CONFIG_MAX_ARENA_POINTS);
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "StartArenaPoints (%i) can't be negative. Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                else if (value > maxAP)
                {
                    TC_LOG_ERROR("config", "StartArenaPoints (%i) must be in range 0..MaxArenaPoints(%u). Set to %u.", value, maxAP, maxAP);
                    sWorld->setIntConfig(WorldIntConfigs(i), maxAP);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL:
            {
                uint32 maxLVL = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "RecruitAFriend.MaxLevel (%i) can't be negative. Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                else if (value > maxLVL)
                {
                    TC_LOG_ERROR("config", "RecruitAFriend.MaxLevel (%i) must be in range 0..MaxPlayerLevel(%u). Set to %u.", value, maxLVL, maxLVL);
                    sWorld->setIntConfig(WorldIntConfigs(i), maxLVL);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_DAILY_QUEST_RESET_TIME_HOUR:
            {
                if (value > 23)
                {
                    TC_LOG_ERROR("config", "Quests.DailyResetTime (%i) must be in range 0..23. Set to 3.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 3);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY:
            {
                if (value > 6)
                {
                    TC_LOG_ERROR("config", "Quests.WeeklyResetDay (%i) must be in range 0..6. Set to 3 (Wednesday).", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 6);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MIN_PETITION_SIGNS:
            {
                if (value > 9)
                {
                    TC_LOG_ERROR("config", "MinPetitionSigns (%i) must be in range 0..9. Set to 9.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 9);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_UPTIME_UPDATE:
            {
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "UpdateUptimeInterval (%i) must be > 0, set to default 10.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MAX_OVERSPEED_PINGS:
            {
                if (value < 0)
                {
                    TC_LOG_ERROR("config", "MaxOverspeedPings (%i) must be > 0, set to default 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                else if (value != 0 && value < 2)
                {
                    TC_LOG_ERROR("config", "MaxOverspeedPings (%i) must be in range 2..infinity (or 0 to disable check). Set to 2.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 2);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_BATTLEGROUND_REPORT_AFK:
            {
                if (value < 1)
                {
                    TC_LOG_ERROR("config", "Battleground.ReportAFK (%i) must be > 0, set to min 1.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 1);
                }
                else if (value > 9)
                {
                    TC_LOG_ERROR("config", "Battleground.ReportAFK (%i) must be < 10. Set max (10).", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 10);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_LOGDB_CLEARINTERVAL:
            {
                if (value <= 0)
                {
                    TC_LOG_ERROR("config", "LogDB.Opt.ClearInterval (%i) must be > 0, set to default 10.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 10);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_GUILD_EVENT_LOG_COUNT:
            {
                if (value > GUILD_EVENTLOG_MAX_RECORDS)
                {
                    TC_LOG_ERROR("config", "Guild.EventLogRecordsCount (%i) must be < 100, set to default 100.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 100);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_GUILD_BANK_EVENT_LOG_COUNT:
            {
                if (value > GUILD_BANKLOG_MAX_RECORDS)
                {
                    TC_LOG_ERROR("config", "Guild.BankEventLogRecordsCount (%i) must be < 25, set to default 25.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 25);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_MIN_LEVEL_STAT_SAVE:
            {
                uint32 maxStartLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
                if (value > maxStartLevel)
                {
                    TC_LOG_ERROR("config", "PlayerSave.Stats.MinLevel (%i) must be in range 0..(%i). Using default, do not save character stats (0).", value, maxStartLevel);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_RANDOM_BG_RESET_HOUR:
            {
                if (value > 23)
                {
                    TC_LOG_ERROR("config", "Battleground.Random.ResetHour (%i) can't be load. Set to 6.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 6);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR:
            {
                if (value > 23)
                {
                    TC_LOG_ERROR("config", "Calendar.DeleteOldEventsHour (%i) can't be load. Set to 6.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 6);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_GUILD_RESET_HOUR:
            {
                if (value > 23)
                {
                    TC_LOG_ERROR("config", "Guild.ResetHour (%i) can't be load. Set to 6.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 6);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_AUCTION_SEARCH_DELAY:
            {
                uint32 delay = sWorld->getIntConfig(CONFIG_AUCTION_GETALL_DELAY);
                if (value < 100 || value > delay)
                {
                    TC_LOG_ERROR("config", "Auction.SearchDelay (%i) must be between 100 and 10000. Using default of 300ms", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 300);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_RESPAWN_DYNAMICMODE:
            {
                if (value > 1)
                {
                    TC_LOG_ERROR("config", "Invalid value for Respawn.DynamicMode (%u). Set to 0.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 0);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_RESPAWN_GUIDWARNLEVEL:
            {
                if (value > 16777215)
                {
                    TC_LOG_ERROR("config", "Respawn.GuidWarnLevel (%u) cannot be greater than maximum GUID (16777215). Set to 12000000.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 12000000);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_RESPAWN_GUIDALERTLEVEL:
            {
                if (value > 16777215)
                {
                    TC_LOG_ERROR("config", "Respawn.GuidWarnLevel (%u) cannot be greater than maximum GUID (16777215). Set to 16000000.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 16000000);
                }
                break;
            }
            case WorldIntConfigs::CONFIG_RESPAWN_RESTARTQUIETTIME:
            {
                if (value > 23)
                {
                    TC_LOG_ERROR("config", "Respawn.RestartQuietTime (%u) must be an hour, between 0 and 23. Set to 3.", value);
                    sWorld->setIntConfig(WorldIntConfigs(i), 3);
                }
                break;
            }
            default:
                break;
        }
    }

    // for bool
    for (uint32 i = 0; i < WorldBoolConfigs::BOOL_CONFIG_VALUE_COUNT; i++)
    {
        bool value = sWorld->getBoolConfig(WorldBoolConfigs(i));
        switch (WorldBoolConfigs(i))
        {
            case WorldBoolConfigs::CONFIG_BASEMAP_LOAD_GRIDS:
            {
                bool unloadgrid = sWorld->getBoolConfig(CONFIG_GRID_UNLOAD);
                if (value && unloadgrid)
                {
                    TC_LOG_ERROR("config", "BaseMapLoadAllGrids enabled, but GridUnload also enabled. GridUnload must be disabled to enable base map pre-loading. Base map pre-loading disabled");
                    sWorld->setBoolConfig(WorldBoolConfigs(i), 0);
                }
                break;
            }
            case WorldBoolConfigs::CONFIG_INSTANCEMAP_LOAD_GRIDS:
            {
                bool unloadgrid = sWorld->getBoolConfig(CONFIG_GRID_UNLOAD);
                if (value && unloadgrid)
                {
                    TC_LOG_ERROR("config", "InstanceMapLoadAllGrids enabled, but GridUnload also enabled. GridUnload must be disabled to enable instance map pre-loading. Instance map pre-loading disabled");
                    sWorld->setBoolConfig(WorldBoolConfigs(i), 0);
                }
                break;
            }
            case WorldBoolConfigs::CONFIG_CHECK_GOBJECT_LOS:
            {
                bool vmap = sWorld->getBoolConfig(CONFIG_DETECT_POS_COLLISION);
                if (value && !vmap)
                {
                    TC_LOG_ERROR("config", "CheckGameObjectLoS enabled, but DetectPosCollision disabled. CheckGameObjectLoS disabled");
                    sWorld->setBoolConfig(WorldBoolConfigs(i), 0);
                }
                break;
            }
            default:
                break;
        }
    }

    TC_LOG_INFO("server.loading", ">> RecheckAndFixDependancy handled in %u ms", GetMSTimeDiffToNow(oldMSTime));
    TC_LOG_INFO("server.loading", "");
}

void WorldConfig::AddBoolOption(uint32 IDinTypeGroup, bool value /*= false*/)
{
    if (!sWorld->setBoolConfig(WorldBoolConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Bool option (%u) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void WorldConfig::AddIntOption(uint32 IDinTypeGroup, uint32 value /*= 0*/)
{
    if (!sWorld->setIntConfig(WorldIntConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Int option (%u) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void WorldConfig::AddFloatOption(uint32 IDinTypeGroup, float value /*= 1.0f*/)
{
    if (!sWorld->setFloatConfig(WorldFloatConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Float option (%u) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void WorldConfig::AddRateOption(uint32 IDinTypeGroup, float value /*= 1.0f*/)
{
    if (!sWorld->setRate(Rates(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> Rate option (%u) did not registered in core!", IDinTypeGroup);
        return;
    }
}

void WorldConfig::AddStringOption(uint32 IDinTypeGroup, std::string value /*= ""*/)
{
    if (!sWorld->setStringConfig(WorldStringConfigs(IDinTypeGroup), value))
    {
        TC_LOG_ERROR("config", "> String option (%u) did not registered in core!", IDinTypeGroup);
        return;
    }
}
