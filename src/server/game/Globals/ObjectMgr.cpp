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

#include "ObjectMgr.h"
#include "ArenaTeamMgr.h"
#include "AreaTriggerDataStore.h"
#include "AreaTriggerTemplate.h"
#include "AzeriteEmpoweredItem.h"
#include "AzeriteItem.h"
#include "Chat.h"
#include "Containers.h"
#include "CreatureAIFactory.h"
#include "CriteriaHandler.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GameObject.h"
#include "GameObjectAIFactory.h"
#include "GameTables.h"
#include "GameTime.h"
#include "GridDefines.h"
#include "GossipDef.h"
#include "GroupMgr.h"
#include "GuildMgr.h"
#include "InstanceScript.h"
#include "Item.h"
#include "ItemBonusMgr.h"
#include "Language.h"
#include "LFGMgr.h"
#include "Log.h"
#include "LootMgr.h"
#include "Mail.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "ObjectDefines.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "QueryPackets.h"
#include "QuestDef.h"
#include "Random.h"
#include "Realm.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "ScriptReloadMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "StringConvert.h"
#include "TemporarySummon.h"
#include "TerrainMgr.h"
#include "ThreadPool.h"
#include "Timer.h"
#include "TransportMgr.h"
#include "Vehicle.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "World.h"
#include <G3D/g3dmath.h>
#include <numeric>
#include <limits>

ScriptMapMap sSpellScripts;
ScriptMapMap sEventScripts;

std::string GetScriptsTableNameByType(ScriptsType type)
{
    std::string res = "";
    switch (type)
    {
        case SCRIPTS_SPELL:         res = "spell_scripts";      break;
        case SCRIPTS_EVENT:         res = "event_scripts";      break;
        default: break;
    }
    return res;
}

ScriptMapMap* GetScriptsMapByType(ScriptsType type)
{
    ScriptMapMap* res = nullptr;
    switch (type)
    {
        case SCRIPTS_SPELL:         res = &sSpellScripts;       break;
        case SCRIPTS_EVENT:         res = &sEventScripts;       break;
        default: break;
    }
    return res;
}

std::string GetScriptCommandName(ScriptCommands command)
{
    std::string res = "";
    switch (command)
    {
        case SCRIPT_COMMAND_TALK: res = "SCRIPT_COMMAND_TALK"; break;
        case SCRIPT_COMMAND_EMOTE: res = "SCRIPT_COMMAND_EMOTE"; break;
        case SCRIPT_COMMAND_FIELD_SET_DEPRECATED: res = "SCRIPT_COMMAND_FIELD_SET_DEPRECATED"; break;
        case SCRIPT_COMMAND_MOVE_TO: res = "SCRIPT_COMMAND_MOVE_TO"; break;
        case SCRIPT_COMMAND_FLAG_SET_DEPRECATED: res = "SCRIPT_COMMAND_FLAG_SET_DEPRECATED"; break;
        case SCRIPT_COMMAND_FLAG_REMOVE_DEPRECATED: res = "SCRIPT_COMMAND_FLAG_REMOVE_DEPRECATED"; break;
        case SCRIPT_COMMAND_TELEPORT_TO: res = "SCRIPT_COMMAND_TELEPORT_TO"; break;
        case SCRIPT_COMMAND_QUEST_EXPLORED: res = "SCRIPT_COMMAND_QUEST_EXPLORED"; break;
        case SCRIPT_COMMAND_KILL_CREDIT: res = "SCRIPT_COMMAND_KILL_CREDIT"; break;
        case SCRIPT_COMMAND_RESPAWN_GAMEOBJECT: res = "SCRIPT_COMMAND_RESPAWN_GAMEOBJECT"; break;
        case SCRIPT_COMMAND_TEMP_SUMMON_CREATURE: res = "SCRIPT_COMMAND_TEMP_SUMMON_CREATURE"; break;
        case SCRIPT_COMMAND_OPEN_DOOR: res = "SCRIPT_COMMAND_OPEN_DOOR"; break;
        case SCRIPT_COMMAND_CLOSE_DOOR: res = "SCRIPT_COMMAND_CLOSE_DOOR"; break;
        case SCRIPT_COMMAND_ACTIVATE_OBJECT: res = "SCRIPT_COMMAND_ACTIVATE_OBJECT"; break;
        case SCRIPT_COMMAND_REMOVE_AURA: res = "SCRIPT_COMMAND_REMOVE_AURA"; break;
        case SCRIPT_COMMAND_CAST_SPELL: res = "SCRIPT_COMMAND_CAST_SPELL"; break;
        case SCRIPT_COMMAND_PLAY_SOUND: res = "SCRIPT_COMMAND_PLAY_SOUND"; break;
        case SCRIPT_COMMAND_CREATE_ITEM: res = "SCRIPT_COMMAND_CREATE_ITEM"; break;
        case SCRIPT_COMMAND_DESPAWN_SELF: res = "SCRIPT_COMMAND_DESPAWN_SELF"; break;
        case SCRIPT_COMMAND_LOAD_PATH: res = "SCRIPT_COMMAND_LOAD_PATH"; break;
        case SCRIPT_COMMAND_CALLSCRIPT_TO_UNIT: res = "SCRIPT_COMMAND_CALLSCRIPT_TO_UNIT"; break;
        case SCRIPT_COMMAND_KILL: res = "SCRIPT_COMMAND_KILL"; break;
        // TrinityCore only
        case SCRIPT_COMMAND_ORIENTATION: res = "SCRIPT_COMMAND_ORIENTATION"; break;
        case SCRIPT_COMMAND_EQUIP: res = "SCRIPT_COMMAND_EQUIP"; break;
        case SCRIPT_COMMAND_MODEL: res = "SCRIPT_COMMAND_MODEL"; break;
        case SCRIPT_COMMAND_CLOSE_GOSSIP: res = "SCRIPT_COMMAND_CLOSE_GOSSIP"; break;
        case SCRIPT_COMMAND_PLAYMOVIE: res = "SCRIPT_COMMAND_PLAYMOVIE"; break;
        case SCRIPT_COMMAND_MOVEMENT: res = "SCRIPT_COMMAND_MOVEMENT"; break;
        case SCRIPT_COMMAND_PLAY_ANIMKIT: res = "SCRIPT_COMMAND_PLAY_ANIMKIT"; break;
        default:
        {
            res = Trinity::StringFormat("Unknown command: {}", command);
            break;
        }
    }
    return res;
}

std::string ScriptInfo::GetDebugInfo() const
{
    return Trinity::StringFormat("{} ('{}' script id: {})", GetScriptCommandName(command), GetScriptsTableNameByType(type), id);
}

bool normalizePlayerName(std::string& name)
{
    if (name.empty())
        return false;

    std::wstring tmp;
    if (!Utf8toWStr(name, tmp))
        return false;

    wstrToLower(tmp);
    if (!tmp.empty())
        tmp[0] = wcharToUpper(tmp[0]);

    if (!WStrToUtf8(tmp, name))
        return false;

    return true;
}

// Extracts player and realm names delimited by -
ExtendedPlayerName ExtractExtendedPlayerName(std::string const& name)
{
    size_t pos = name.find('-');
    if (pos != std::string::npos)
        return ExtendedPlayerName(name.substr(0, pos), name.substr(pos + 1));
    else
        return ExtendedPlayerName(name, "");
}

bool SpellClickInfo::IsFitToRequirements(Unit const* clicker, Unit const* clickee) const
{
    Player const* playerClicker = clicker->ToPlayer();
    if (!playerClicker)
        return true;

    Unit const* summoner = nullptr;
    // Check summoners for party
    if (clickee->IsSummon())
        summoner = clickee->ToTempSummon()->GetSummonerUnit();
    if (!summoner)
        summoner = clickee;

    // This only applies to players
    switch (userType)
    {
        case SPELL_CLICK_USER_FRIEND:
            if (!playerClicker->IsFriendlyTo(summoner))
                return false;
            break;
        case SPELL_CLICK_USER_RAID:
            if (!playerClicker->IsInRaidWith(summoner))
                return false;
            break;
        case SPELL_CLICK_USER_PARTY:
            if (!playerClicker->IsInPartyWith(summoner))
                return false;
            break;
        default:
            break;
    }

    return true;
}

ObjectMgr::ObjectMgr():
    _auctionId(1),
    _equipmentSetGuid(1),
    _mailId(1),
    _hiPetNumber(1),
    _creatureSpawnId(1),
    _gameObjectSpawnId(1),
    _voidItemId(1),
    DBCLocaleIndex(LOCALE_enUS)
{
}

ObjectMgr* ObjectMgr::instance()
{
    static ObjectMgr instance;
    return &instance;
}

ObjectMgr::~ObjectMgr()
{
}

void ObjectMgr::AddLocaleString(std::string_view value, LocaleConstant localeConstant, std::vector<std::string>& data)
{
    if (!value.empty())
    {
        if (data.size() <= size_t(localeConstant))
        {
            data.reserve(TOTAL_LOCALES);
            data.resize(localeConstant + 1);
        }

        data[localeConstant] = value;
    }
}

void ObjectMgr::LoadCreatureLocales()
{
    uint32 oldMSTime = getMSTime();

    _creatureLocaleStore.clear(); // need for reload case

    //                                               0      1       2     3        4      5
    QueryResult result = WorldDatabase.Query("SELECT entry, locale, Name, NameAlt, Title, TitleAlt FROM creature_template_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        std::string_view localeName = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        CreatureLocale& data = _creatureLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.Name);
        AddLocaleString(fields[3].GetStringView(), locale, data.NameAlt);
        AddLocaleString(fields[4].GetStringView(), locale, data.Title);
        AddLocaleString(fields[5].GetStringView(), locale, data.TitleAlt);

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature locale strings in {} ms", uint32(_creatureLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenuItemsLocales()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenuItemsLocaleStore.clear();                              // need for reload case

    //                                               0       1            2       3           4
    QueryResult result = WorldDatabase.Query("SELECT MenuID, OptionID, Locale, OptionText, BoxText FROM gossip_menu_option_locale");

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 menuId               = fields[0].GetUInt32();
        uint32 optionId             = fields[1].GetUInt32();
        std::string_view localeName = fields[2].GetStringView();

        LocaleConstant locale   = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        GossipMenuItemsLocale& data = _gossipMenuItemsLocaleStore[std::make_pair(menuId, optionId)];
        AddLocaleString(fields[3].GetStringView(), locale, data.OptionText);
        AddLocaleString(fields[4].GetStringView(), locale, data.BoxText);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gossip_menu_option locale strings in {} ms", _gossipMenuItemsLocaleStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPointOfInterestLocales()
{
    uint32 oldMSTime = getMSTime();

    _pointOfInterestLocaleStore.clear(); // need for reload case

    //                                               0      1      2
    QueryResult result = WorldDatabase.Query("SELECT ID, locale, Name FROM points_of_interest_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        std::string_view localeName = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        PointOfInterestLocale& data = _pointOfInterestLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.Name);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} points_of_interest locale strings in {} ms", uint32(_pointOfInterestLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplates()
{
    uint32 oldMSTime = getMSTime();

    //                                               0      1            2            3     4           5
    //                                       "SELECT entry, KillCredit1, KillCredit2, name, femaleName, subname, "
    //                                        6         7         8                  9
    //                                       "TitleAlt, IconName, RequiredExpansion, VignetteID, "
    //                                        10       11       12          13         14      15     16         17              18               19            20
    //                                       "faction, npcflag, speed_walk, speed_run, scale, `rank`, dmgschool, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, "
    //                                        21          22          23           24
    //                                       "unit_class, unit_flags, unit_flags2, unit_flags3, "
    //                                        25      26             27    28         29      30
    //                                       "family, trainer_class, type, VehicleId, AIName, MovementType, "
    //                                        31                         32         33          34                        35
    //                                       "ctm.HoverInitiallyEnabled, ctm.Chase, ctm.Random, ctm.InteractionPauseTimer, ExperienceModifier, "
    //                                        36            37          38           39                        40
    //                                       "RacialLeader, movementId, WidgetSetID, WidgetSetUnitConditionID, RegenHealth, "
    //                                        41                    42
    //                                       "CreatureImmunitiesId, flags_extra, "
    //                                        43          44
    //                                       "ScriptName, StringId FROM creature_template WHERE entry = ? OR 1 = ?");

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEMPLATE);
    stmt->setUInt32(0, 0);
    stmt->setUInt32(1, 1);

    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template definitions. DB table `creature_template` is empty.");
        return;
    }

    _creatureTemplateStore.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        LoadCreatureTemplate(fields);
    } while (result->NextRow());

    LoadCreatureTemplateResistances();
    LoadCreatureTemplateSpells();

    // We load the creature models after loading but before checking
    LoadCreatureTemplateModels();

    // Checking needs to be done after loading because of the difficulty self referencing
    for (auto const& ctPair : _creatureTemplateStore)
        CheckCreatureTemplate(&ctPair.second);

    TC_LOG_INFO("server.loading", ">> Loaded {} creature definitions in {} ms", _creatureTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplate(Field* fields)
{
    uint32 entry = fields[0].GetUInt32();
    CreatureTemplate& creatureTemplate = _creatureTemplateStore[entry];

    creatureTemplate.Entry = entry;

    for (uint8 i = 0; i < MAX_KILL_CREDIT; ++i)
        creatureTemplate.KillCredit[i]      = fields[1 + i].GetUInt32();

    creatureTemplate.Name                   = fields[3].GetString();
    creatureTemplate.FemaleName             = fields[4].GetString();
    creatureTemplate.SubName                = fields[5].GetString();
    creatureTemplate.TitleAlt               = fields[6].GetString();
    creatureTemplate.IconName               = fields[7].GetString();
    creatureTemplate.RequiredExpansion      = fields[8].GetUInt32();
    creatureTemplate.VignetteID             = fields[9].GetUInt32();
    creatureTemplate.faction                = fields[10].GetUInt16();
    creatureTemplate.npcflag                = fields[11].GetUInt64();
    creatureTemplate.speed_walk             = fields[12].GetFloat();
    creatureTemplate.speed_run              = fields[13].GetFloat();
    creatureTemplate.scale                  = fields[14].GetFloat();
    creatureTemplate.Classification         = CreatureClassifications(fields[15].GetUInt8());
    creatureTemplate.dmgschool              = uint32(fields[16].GetInt8());
    creatureTemplate.BaseAttackTime         = fields[17].GetUInt32();
    creatureTemplate.RangeAttackTime        = fields[18].GetUInt32();
    creatureTemplate.BaseVariance           = fields[19].GetFloat();
    creatureTemplate.RangeVariance          = fields[20].GetFloat();
    creatureTemplate.unit_class             = uint32(fields[21].GetUInt8());
    creatureTemplate.unit_flags             = fields[22].GetUInt32();
    creatureTemplate.unit_flags2            = fields[23].GetUInt32();
    creatureTemplate.unit_flags3            = fields[24].GetUInt32();
    creatureTemplate.family                 = CreatureFamily(fields[25].GetInt32());
    creatureTemplate.trainer_class          = uint32(fields[26].GetUInt8());
    creatureTemplate.type                   = uint32(fields[27].GetUInt8());

    for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
        creatureTemplate.resistance[i] = 0;

    for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        creatureTemplate.spells[i] = 0;

    creatureTemplate.VehicleId              = fields[28].GetUInt32();
    creatureTemplate.AIName                 = fields[29].GetString();
    creatureTemplate.MovementType           = uint32(fields[30].GetUInt8());

    if (!fields[31].IsNull())
        creatureTemplate.Movement.HoverInitiallyEnabled = fields[31].GetBool();

    if (!fields[32].IsNull())
        creatureTemplate.Movement.Chase = static_cast<CreatureChaseMovementType>(fields[32].GetUInt8());

    if (!fields[33].IsNull())
        creatureTemplate.Movement.Random = static_cast<CreatureRandomMovementType>(fields[33].GetUInt8());

    if (!fields[34].IsNull())
        creatureTemplate.Movement.InteractionPauseTimer = fields[34].GetUInt32();

    creatureTemplate.ModExperience          = fields[35].GetFloat();
    creatureTemplate.RacialLeader           = fields[36].GetBool();
    creatureTemplate.movementId             = fields[37].GetUInt32();
    creatureTemplate.WidgetSetID            = fields[38].GetInt32();
    creatureTemplate.WidgetSetUnitConditionID = fields[39].GetInt32();
    creatureTemplate.RegenHealth            = fields[40].GetBool();
    creatureTemplate.CreatureImmunitiesId   = fields[41].GetInt32();
    creatureTemplate.flags_extra            = fields[42].GetUInt32();
    creatureTemplate.ScriptID               = GetScriptId(fields[43].GetString());
    creatureTemplate.StringId               = fields[44].GetString();
}

void ObjectMgr::LoadCreatureTemplateGossip()
{
    uint32 oldMSTime = getMSTime();

    //                                               0           1
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, MenuID FROM creature_template_gossip");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template gossip definitions. DB table `creature_template_gossip` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureID = fields[0].GetUInt32();
        uint32 menuID = fields[1].GetUInt32();

        CreatureTemplateContainer::iterator itr = _creatureTemplateStore.find(creatureID);
        if (itr == _creatureTemplateStore.end())
        {
            TC_LOG_ERROR("sql.sql", "creature_template_gossip has gossip definitions for creature {} but this creature doesn't exist", creatureID);
            continue;
        }

        GossipMenusMapBounds menuBounds = sObjectMgr->GetGossipMenusMapBounds(menuID);
        if (menuBounds.first == menuBounds.second)
        {
            TC_LOG_ERROR("sql.sql", "creature_template_gossip has gossip definitions for menu id {} but this menu doesn't exist", menuID);
            continue;
        }

        CreatureTemplate& creatureTemplate = itr->second;
        creatureTemplate.GossipMenuIds.push_back(menuID);

        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template gossip menus in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplateResistances()
{
    uint32 oldMSTime = getMSTime();

    //                                               0           1       2
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, School, Resistance FROM creature_template_resistance");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template resistance definitions. DB table `creature_template_resistance` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureID = fields[0].GetUInt32();
        uint8 school      = fields[1].GetUInt8();

        if (school == SPELL_SCHOOL_NORMAL || school >= MAX_SPELL_SCHOOL)
        {
            TC_LOG_ERROR("sql.sql", "creature_template_resistance has resistance definitions for creature {} but this school {} doesn't exist", creatureID, school);
            continue;
        }

        CreatureTemplateContainer::iterator itr = _creatureTemplateStore.find(creatureID);
        if (itr == _creatureTemplateStore.end())
        {
            TC_LOG_ERROR("sql.sql", "creature_template_resistance has resistance definitions for creature {} but this creature doesn't exist", creatureID);
            continue;
        }

        CreatureTemplate& creatureTemplate = itr->second;
        creatureTemplate.resistance[school] = fields[2].GetInt16();

        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template resistances in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplateSpells()
{
    uint32 oldMSTime = getMSTime();

    //                                               0           1       2
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, `Index`, Spell FROM creature_template_spell");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template spell definitions. DB table `creature_template_spell` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureID = fields[0].GetUInt32();
        uint8 index       = fields[1].GetUInt8();

        if (index >= MAX_CREATURE_SPELLS)
        {
            TC_LOG_ERROR("sql.sql", "creature_template_spell has spell definitions for creature {} with a incorrect index {}", creatureID, index);
            continue;
        }

        CreatureTemplateContainer::iterator itr = _creatureTemplateStore.find(creatureID);
        if (itr == _creatureTemplateStore.end())
        {
            TC_LOG_ERROR("sql.sql", "creature_template_spell has spell definitions for creature {} but this creature doesn't exist", creatureID);
            continue;
        }

        CreatureTemplate& creatureTemplate = itr->second;
        creatureTemplate.spells[index] = fields[2].GetUInt32();;

        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template spells in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplateModels()
{
    uint32 oldMSTime = getMSTime();

    //                                               0           1                  2             3
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, CreatureDisplayID, DisplayScale, Probability FROM creature_template_model ORDER BY Idx ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template model definitions. DB table `creature_template_model` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 creatureId = fields[0].GetUInt32();
        uint32 creatureDisplayId = fields[1].GetUInt32();
        float displayScale = fields[2].GetFloat();
        float probability = fields[3].GetFloat();

        CreatureTemplate const* cInfo = GetCreatureTemplate(creatureId);
        if (!cInfo)
        {
            TC_LOG_ERROR("sql.sql", "Creature template (Entry: {}) does not exist but has a record in `creature_template_model`", creatureId);
            continue;
        }

        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(creatureDisplayId);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) lists non-existing CreatureDisplayID id ({}), this can crash the client.", creatureId, creatureDisplayId);
            continue;
        }

        CreatureModelInfo const* modelInfo = GetCreatureModelInfo(creatureDisplayId);
        if (!modelInfo)
            TC_LOG_ERROR("sql.sql", "No model data exist for `CreatureDisplayID` = {} listed by creature (Entry: {}).", creatureDisplayId, creatureId);

        if (displayScale <= 0.0f)
            displayScale = 1.0f;

        const_cast<CreatureTemplate*>(cInfo)->Models.emplace_back(creatureDisplayId, displayScale, probability);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template models in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureSummonedData()
{
    uint32 oldMSTime = getMSTime();

    //                                               0           1                            2                     3                     4
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, CreatureIDVisibleToSummoner, GroundMountDisplayID, FlyingMountDisplayID, DespawnOnQuestsRemoved FROM creature_summoned_data");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature summoned data definitions. DB table `creature_summoned_data` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureId = fields[0].GetUInt32();
        if (!GetCreatureTemplate(creatureId))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_summoned_data` references non-existing creature {}, skipped", creatureId);
            continue;
        }

        CreatureSummonedData& summonedData = _creatureSummonedDataStore[creatureId];

        if (!fields[1].IsNull())
        {
            summonedData.CreatureIDVisibleToSummoner = fields[1].GetUInt32();
            if (!GetCreatureTemplate(*summonedData.CreatureIDVisibleToSummoner))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature_summoned_data` references non-existing creature {} in CreatureIDVisibleToSummoner for creature {}, set to 0",
                    *summonedData.CreatureIDVisibleToSummoner, creatureId);
                summonedData.CreatureIDVisibleToSummoner.reset();
            }
        }

        if (!fields[2].IsNull())
        {
            summonedData.GroundMountDisplayID = fields[2].GetUInt32();
            if (!sCreatureDisplayInfoStore.LookupEntry(*summonedData.GroundMountDisplayID))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature_summoned_data` references non-existing display id {} in GroundMountDisplayID for creature {}, set to 0",
                    *summonedData.GroundMountDisplayID, creatureId);
                summonedData.CreatureIDVisibleToSummoner.reset();
            }
        }

        if (!fields[3].IsNull())
        {
            summonedData.FlyingMountDisplayID = fields[3].GetUInt32();
            if (!sCreatureDisplayInfoStore.LookupEntry(*summonedData.FlyingMountDisplayID))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature_summoned_data` references non-existing display id {} in FlyingMountDisplayID for creature {}, set to 0",
                    *summonedData.FlyingMountDisplayID, creatureId);
                summonedData.GroundMountDisplayID.reset();
            }
        }

        if (!fields[4].IsNull())
        {
            std::vector<uint32> questList;
            for (std::string_view questStr : Trinity::Tokenize(fields[4].GetStringView(), ',', false))
            {
                Optional<uint32> questId = Trinity::StringTo<uint32>(questStr);
                if (!questId)
                    continue;

                Quest const* quest = GetQuestTemplate(*questId);
                if (!quest)
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_summoned_data` references non-existing quest {} in DespawnOnQuestsRemoved for creature {}, skipping",
                        *questId, creatureId);
                    continue;
                }

                questList.push_back(*questId);
            }

            if (!questList.empty())
                summonedData.DespawnOnQuestsRemoved = std::move(questList);
        }

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature summoned data definitions in {} ms", _creatureSummonedDataStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplateAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                               0      1        2      3           4         5         6            7         8      9          10               11            12                      13
    QueryResult result = WorldDatabase.Query("SELECT entry, PathId, mount, StandState, AnimTier, VisFlags, SheathState, PvPFlags, emote, aiAnimKit, movementAnimKit, meleeAnimKit, visibilityDistanceType, auras FROM creature_template_addon");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template addon definitions. DB table `creature_template_addon` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        if (!GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Creature template (Entry: {}) does not exist but has a record in `creature_template_addon`", entry);
            continue;
        }

        CreatureAddon& creatureAddon = _creatureTemplateAddonStore[entry];

        creatureAddon.PathId                   = fields[1].GetUInt32();
        creatureAddon.mount                     = fields[2].GetUInt32();
        creatureAddon.standState                = fields[3].GetUInt8();
        creatureAddon.animTier                  = fields[4].GetUInt8();
        creatureAddon.visFlags                  = fields[5].GetUInt8();
        creatureAddon.sheathState               = fields[6].GetUInt8();
        creatureAddon.pvpFlags                  = fields[7].GetUInt8();
        creatureAddon.emote                     = fields[8].GetUInt32();
        creatureAddon.aiAnimKit                 = fields[9].GetUInt16();
        creatureAddon.movementAnimKit           = fields[10].GetUInt16();
        creatureAddon.meleeAnimKit              = fields[11].GetUInt16();
        creatureAddon.visibilityDistanceType    = VisibilityDistanceType(fields[12].GetUInt8());

        for (std::string_view aura : Trinity::Tokenize(fields[13].GetStringView(), ' ', false))
        {
            SpellInfo const* spellInfo = nullptr;
            if (Optional<uint32> spellId = Trinity::StringTo<uint32>(aura))
                spellInfo = sSpellMgr->GetSpellInfo(*spellId, DIFFICULTY_NONE);

            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has wrong spell '{}' defined in `auras` field in `creature_template_addon`.", entry, std::string(aura));
                continue;
            }

            if (spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has SPELL_AURA_CONTROL_VEHICLE aura {} defined in `auras` field in `creature_template_addon`.", entry, spellInfo->Id);

            if (std::find(creatureAddon.auras.begin(), creatureAddon.auras.end(), spellInfo->Id) != creatureAddon.auras.end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has duplicate aura (spell {}) in `auras` field in `creature_template_addon`.", entry, spellInfo->Id);
                continue;
            }

            if (spellInfo->GetDuration() > 0)
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has temporary aura (spell {}) in `auras` field in `creature_template_addon`.", entry, spellInfo->Id);
                continue;
            }

            creatureAddon.auras.push_back(spellInfo->Id);
        }

        if (creatureAddon.mount)
        {
            if (!sCreatureDisplayInfoStore.LookupEntry(creatureAddon.mount))
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid displayInfoId ({}) for mount defined in `creature_template_addon`", entry, creatureAddon.mount);
                creatureAddon.mount = 0;
            }
        }

        if (creatureAddon.standState >= MAX_UNIT_STAND_STATE)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid unit stand state ({}) defined in `creature_template_addon`. Truncated to 0.", entry, creatureAddon.standState);
            creatureAddon.standState = 0;
        }

        if (AnimTier(creatureAddon.animTier) >= AnimTier::Max)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid animation tier ({}) defined in `creature_template_addon`. Truncated to 0.", entry, creatureAddon.animTier);
            creatureAddon.animTier = 0;
        }

        if (creatureAddon.sheathState >= MAX_SHEATH_STATE)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid sheath state ({}) defined in `creature_template_addon`. Truncated to 0.", entry, creatureAddon.sheathState);
            creatureAddon.sheathState = 0;
        }

        // PvPFlags don't need any checking for the time being since they cover the entire range of a byte

        if (!sEmotesStore.LookupEntry(creatureAddon.emote))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid emote ({}) defined in `creature_template_addon`.", entry, creatureAddon.emote);
            creatureAddon.emote = 0;
        }

        if (creatureAddon.aiAnimKit && !sAnimKitStore.LookupEntry(creatureAddon.aiAnimKit))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid aiAnimKit ({}) defined in `creature_template_addon`.", entry, creatureAddon.aiAnimKit);
            creatureAddon.aiAnimKit = 0;
        }

        if (creatureAddon.movementAnimKit && !sAnimKitStore.LookupEntry(creatureAddon.movementAnimKit))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid movementAnimKit ({}) defined in `creature_template_addon`.", entry, creatureAddon.movementAnimKit);
            creatureAddon.movementAnimKit = 0;
        }

        if (creatureAddon.meleeAnimKit && !sAnimKitStore.LookupEntry(creatureAddon.meleeAnimKit))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid meleeAnimKit ({}) defined in `creature_template_addon`.", entry, creatureAddon.meleeAnimKit);
            creatureAddon.meleeAnimKit = 0;
        }

        if (creatureAddon.visibilityDistanceType >= VisibilityDistanceType::Max)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid visibilityDistanceType ({}) defined in `creature_template_addon`.",
                entry, AsUnderlyingType(creatureAddon.visibilityDistanceType));
            creatureAddon.visibilityDistanceType = VisibilityDistanceType::Normal;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template addons in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplateSparring()
{
    uint32 oldMSTime = getMSTime();

    //                                               0      1
    QueryResult result = WorldDatabase.Query("SELECT Entry, NoNPCDamageBelowHealthPct FROM creature_template_sparring");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template sparring definitions. DB table `creature_template_sparring` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        float noNPCDamageBelowHealthPct = fields[1].GetFloat();

        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Creature template (Entry: {}) does not exist but has a record in `creature_template_sparring`", entry);
            continue;
        }

        if (noNPCDamageBelowHealthPct <= 0 || noNPCDamageBelowHealthPct > 100)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid NoNPCDamageBelowHealthPct ({}) defined in `creature_template_sparring`. Skipping",
                entry, noNPCDamageBelowHealthPct);
            continue;
        }
        _creatureTemplateSparringStore[entry].push_back(noNPCDamageBelowHealthPct);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template sparring rows in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplateDifficulty()
{
    uint32 oldMSTime = getMSTime();

    //                                               0      1             2                     3                     4                5
    QueryResult result = WorldDatabase.Query("SELECT Entry, DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, ContentTuningID, HealthScalingExpansion, "
    //   6               7             8              9               10                    11         12
        "HealthModifier, ManaModifier, ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
    //   13      14                15          16       17
        "LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax,"
    //   18            19            20            21            22            23            24            25
        "StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, StaticFlags6, StaticFlags7, StaticFlags8 "
        "FROM creature_template_difficulty ORDER BY Entry");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template difficulty definitions. DB table `creature_template_difficulty` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        Difficulty difficulty = Difficulty(fields[1].GetUInt8());

        auto itr = _creatureTemplateStore.find(entry);
        if (itr == _creatureTemplateStore.end())
        {
            TC_LOG_ERROR("sql.sql", "Creature template (Entry: {}) does not exist but has a record in `creature_template_difficulty`", entry);
            continue;
        }

        CreatureDifficulty creatureDifficulty;
        creatureDifficulty.DeltaLevelMin          = fields[2].GetInt16();
        creatureDifficulty.DeltaLevelMax          = fields[3].GetInt16();
        creatureDifficulty.ContentTuningID        = fields[4].GetInt32();
        creatureDifficulty.HealthScalingExpansion = fields[5].GetInt32();
        creatureDifficulty.HealthModifier         = fields[6].GetFloat();
        creatureDifficulty.ManaModifier           = fields[7].GetFloat();
        creatureDifficulty.ArmorModifier          = fields[8].GetFloat();
        creatureDifficulty.DamageModifier         = fields[9].GetFloat();
        creatureDifficulty.CreatureDifficultyID   = fields[10].GetInt32();
        creatureDifficulty.TypeFlags              = fields[11].GetUInt32();
        creatureDifficulty.TypeFlags2             = fields[12].GetUInt32();
        creatureDifficulty.LootID                 = fields[13].GetUInt32();
        creatureDifficulty.PickPocketLootID       = fields[14].GetUInt32();
        creatureDifficulty.SkinLootID             = fields[15].GetUInt32();
        creatureDifficulty.GoldMin                = fields[16].GetUInt32();
        creatureDifficulty.GoldMax                = fields[17].GetUInt32();
        creatureDifficulty.StaticFlags            = CreatureStaticFlagsHolder(CreatureStaticFlags(fields[18].GetUInt32()), CreatureStaticFlags2(fields[19].GetUInt32()),
            CreatureStaticFlags3(fields[20].GetUInt32()), CreatureStaticFlags4(fields[21].GetUInt32()), CreatureStaticFlags5(fields[22].GetUInt32()),
            CreatureStaticFlags6(fields[23].GetUInt32()), CreatureStaticFlags7(fields[24].GetUInt32()),  CreatureStaticFlags8(fields[25].GetUInt32()));

        // TODO: Check if this still applies
        creatureDifficulty.DamageModifier *= Creature::GetDamageMod(itr->second.Classification);

        if (creatureDifficulty.HealthScalingExpansion < EXPANSION_LEVEL_CURRENT || creatureDifficulty.HealthScalingExpansion >= MAX_EXPANSIONS)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_template_difficulty` lists creature (ID: {}) with invalid `HealthScalingExpansion` {}. Ignored and set to 0.",
                entry, creatureDifficulty.HealthScalingExpansion);
            creatureDifficulty.HealthScalingExpansion = 0;
        }

        if (creatureDifficulty.GoldMin > creatureDifficulty.GoldMax)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_template_difficulty` lists creature (ID: {}) with `GoldMin` {} greater than `GoldMax` {}, setting `GoldMax` to {}.",
                entry, creatureDifficulty.GoldMin, creatureDifficulty.GoldMax, creatureDifficulty.GoldMin);
            creatureDifficulty.GoldMax = creatureDifficulty.GoldMin;
        }

        itr->second.difficultyStore[difficulty] = creatureDifficulty;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature template difficulty data in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::CheckCreatureTemplate(CreatureTemplate const* cInfo)
{
    if (!cInfo)
        return;

    if (!cInfo->AIName.empty())
    {
        auto registryItem = sCreatureAIRegistry->GetRegistryItem(cInfo->AIName);
        if (!registryItem)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has non-registered `AIName` '{}' set, removing", cInfo->Entry, cInfo->AIName);
            const_cast<CreatureTemplate*>(cInfo)->AIName.clear();
        }
        else
        {
            DBPermit const* permit = dynamic_cast<DBPermit const*>(registryItem);
            if (!ASSERT_NOTNULL(permit)->IsScriptNameAllowedInDB())
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has not-allowed `AIName` '{}' set, removing", cInfo->Entry, cInfo->AIName);
                const_cast<CreatureTemplate*>(cInfo)->AIName.clear();
            }
        }
    }

    FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(cInfo->faction);
    if (!factionTemplate)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has non-existing faction template ({}). This can lead to crashes, set to faction 35.", cInfo->Entry, cInfo->faction);
        const_cast<CreatureTemplate*>(cInfo)->faction = sFactionTemplateStore.AssertEntry(35)->ID; // this might seem stupid but all shit will would break if faction 35 did not exist
    }

    for (uint8 k = 0; k < MAX_KILL_CREDIT; ++k)
    {
        if (cInfo->KillCredit[k])
        {
            if (!GetCreatureTemplate(cInfo->KillCredit[k]))
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) lists non-existing creature entry {} in `KillCredit{}`.", cInfo->Entry, cInfo->KillCredit[k], k + 1);
                const_cast<CreatureTemplate*>(cInfo)->KillCredit[k] = 0;
            }
        }
    }

    if (cInfo->Models.empty())
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) does not have any existing display id in creature_template_model.", cInfo->Entry);

    if (!cInfo->unit_class || ((1 << (cInfo->unit_class-1)) & CLASSMASK_ALL_CREATURES) == 0)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid unit_class ({}) in creature_template. Set to 1 (UNIT_CLASS_WARRIOR).", cInfo->Entry, cInfo->unit_class);
        const_cast<CreatureTemplate*>(cInfo)->unit_class = UNIT_CLASS_WARRIOR;
    }

    if (cInfo->dmgschool >= MAX_SPELL_SCHOOL)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid spell school value ({}) in `dmgschool`.", cInfo->Entry, cInfo->dmgschool);
        const_cast<CreatureTemplate*>(cInfo)->dmgschool = SPELL_SCHOOL_NORMAL;
    }

    if (cInfo->BaseAttackTime == 0)
        const_cast<CreatureTemplate*>(cInfo)->BaseAttackTime  = BASE_ATTACK_TIME;

    if (cInfo->RangeAttackTime == 0)
        const_cast<CreatureTemplate*>(cInfo)->RangeAttackTime = BASE_ATTACK_TIME;

    if (cInfo->speed_walk == 0.0f)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has wrong value ({}) in speed_walk, set to 1.", cInfo->Entry, cInfo->speed_walk);
        const_cast<CreatureTemplate*>(cInfo)->speed_walk = 1.0f;
    }

    if (cInfo->speed_run == 0.0f)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has wrong value ({}) in speed_run, set to 1.14286.", cInfo->Entry, cInfo->speed_run);
        const_cast<CreatureTemplate*>(cInfo)->speed_run = 1.14286f;
    }

    if (cInfo->type && !sCreatureTypeStore.LookupEntry(cInfo->type))
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid creature type ({}) in `type`.", cInfo->Entry, cInfo->type);
        const_cast<CreatureTemplate*>(cInfo)->type = CREATURE_TYPE_HUMANOID;
    }

    if (cInfo->family && !sCreatureFamilyStore.LookupEntry(cInfo->family))
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid creature family ({}) in `family`.", cInfo->Entry, cInfo->family);
        const_cast<CreatureTemplate*>(cInfo)->family = CREATURE_FAMILY_NONE;
    }

    CheckCreatureMovement("creature_template_movement", cInfo->Entry, const_cast<CreatureTemplate*>(cInfo)->Movement);

    if (cInfo->VehicleId)
    {
        VehicleEntry const* vehId = sVehicleStore.LookupEntry(cInfo->VehicleId);
        if (!vehId)
        {
             TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has a non-existing VehicleId ({}). This *WILL* cause the client to freeze!", cInfo->Entry, cInfo->VehicleId);
             const_cast<CreatureTemplate*>(cInfo)->VehicleId = 0;
        }
    }

    for (uint8 j = 0; j < MAX_CREATURE_SPELLS; ++j)
    {
        if (cInfo->spells[j] && !sSpellMgr->GetSpellInfo(cInfo->spells[j], DIFFICULTY_NONE))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has non-existing Spell{} ({}), set to 0.", cInfo->Entry, j+1, cInfo->spells[j]);
            const_cast<CreatureTemplate*>(cInfo)->spells[j] = 0;
        }
    }

    if (cInfo->MovementType >= MAX_DB_MOTION_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has wrong movement generator type ({}), ignored and set to IDLE.", cInfo->Entry, cInfo->MovementType);
        const_cast<CreatureTemplate*>(cInfo)->MovementType = IDLE_MOTION_TYPE;
    }

    if (cInfo->RequiredExpansion >= MAX_EXPANSIONS)
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: {}) with `RequiredExpansion` {}. Ignored and set to 0.", cInfo->Entry, cInfo->RequiredExpansion);
        const_cast<CreatureTemplate*>(cInfo)->RequiredExpansion = 0;
    }

    if (uint32 badFlags = (cInfo->flags_extra & ~CREATURE_FLAG_EXTRA_DB_ALLOWED))
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: {}) with disallowed `flags_extra` {}, removing incorrect flag.", cInfo->Entry, badFlags);
        const_cast<CreatureTemplate*>(cInfo)->flags_extra &= CREATURE_FLAG_EXTRA_DB_ALLOWED;
    }

    if (uint32 disallowedUnitFlags = (cInfo->unit_flags & ~UNIT_FLAG_ALLOWED))
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: {}) with disallowed `unit_flags` {}, removing incorrect flag.", cInfo->Entry, disallowedUnitFlags);
        const_cast<CreatureTemplate*>(cInfo)->unit_flags &= UNIT_FLAG_ALLOWED;
    }

    if (uint32 disallowedUnitFlags2 = (cInfo->unit_flags2 & ~UNIT_FLAG2_ALLOWED))
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: {}) with disallowed `unit_flags2` {}, removing incorrect flag.", cInfo->Entry, disallowedUnitFlags2);
        const_cast<CreatureTemplate*>(cInfo)->unit_flags2 &= UNIT_FLAG2_ALLOWED;
    }

    if (uint32 disallowedUnitFlags3 = (cInfo->unit_flags3 & ~UNIT_FLAG3_ALLOWED))
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: {}) with disallowed `unit_flags3` {}, removing incorrect flag.", cInfo->Entry, disallowedUnitFlags3);
        const_cast<CreatureTemplate*>(cInfo)->unit_flags3 &= UNIT_FLAG3_ALLOWED;
    }

    if (!cInfo->GossipMenuIds.empty() && !(cInfo->npcflag & UNIT_NPC_FLAG_GOSSIP))
        TC_LOG_INFO("sql.sql", "Creature (Entry: {}) has assigned gossip menu, but npcflag does not include UNIT_NPC_FLAG_GOSSIP.", cInfo->Entry);
    else if (cInfo->GossipMenuIds.empty() && cInfo->npcflag & UNIT_NPC_FLAG_GOSSIP)
        TC_LOG_INFO("sql.sql", "Creature (Entry: {}) has npcflag UNIT_NPC_FLAG_GOSSIP, but gossip menu is unassigned.", cInfo->Entry);
}

void ObjectMgr::CheckCreatureMovement(char const* table, uint64 id, CreatureMovementData& creatureMovement)
{
    if (creatureMovement.Chase >= CreatureChaseMovementType::Max)
    {
        TC_LOG_ERROR("sql.sql", "`{}`.`Chase` wrong value ({}) for Id {}, setting to Run.",
                     table, uint32(creatureMovement.Chase), id);
        creatureMovement.Chase = CreatureChaseMovementType::Run;
    }

    if (creatureMovement.Random >= CreatureRandomMovementType::Max)
    {
        TC_LOG_ERROR("sql.sql", "`{}`.`Random` wrong value ({}) for Id {}, setting to Walk.",
                     table, uint32(creatureMovement.Random), id);
        creatureMovement.Random = CreatureRandomMovementType::Walk;
    }
}

void ObjectMgr::LoadCreatureAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                               0     1        2      3           4         5         6            7         8      9          10               11            12                      13
    QueryResult result = WorldDatabase.Query("SELECT guid, PathId, mount, StandState, AnimTier, VisFlags, SheathState, PvPFlags, emote, aiAnimKit, movementAnimKit, meleeAnimKit, visibilityDistanceType, auras FROM creature_addon");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature addon definitions. DB table `creature_addon` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guid = fields[0].GetUInt64();

        CreatureData const* creData = GetCreatureData(guid);
        if (!creData)
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) does not exist but has a record in `creature_addon`", guid);
            continue;
        }

        CreatureAddon& creatureAddon = _creatureAddonStore[guid];

        creatureAddon.PathId = fields[1].GetUInt32();
        if (creData->movementType == WAYPOINT_MOTION_TYPE && !creatureAddon.PathId)
        {
            const_cast<CreatureData*>(creData)->movementType = IDLE_MOTION_TYPE;
            TC_LOG_ERROR("sql.sql", "Creature (GUID {}) has movement type set to WAYPOINT_MOTION_TYPE but no path assigned", guid);
        }

        creatureAddon.mount                     = fields[2].GetUInt32();
        creatureAddon.standState                = fields[3].GetUInt8();
        creatureAddon.animTier                  = fields[4].GetUInt8();
        creatureAddon.visFlags                  = fields[5].GetUInt8();
        creatureAddon.sheathState               = fields[6].GetUInt8();
        creatureAddon.pvpFlags                  = fields[7].GetUInt8();
        creatureAddon.emote                     = fields[8].GetUInt32();
        creatureAddon.aiAnimKit                 = fields[9].GetUInt16();
        creatureAddon.movementAnimKit           = fields[10].GetUInt16();
        creatureAddon.meleeAnimKit              = fields[11].GetUInt16();
        creatureAddon.visibilityDistanceType    = VisibilityDistanceType(fields[12].GetUInt8());

        for (std::string_view aura : Trinity::Tokenize(fields[13].GetStringView(), ' ', false))
        {
            SpellInfo const* spellInfo = nullptr;
            if (Optional<uint32> spellId = Trinity::StringTo<uint32>(aura))
                spellInfo = sSpellMgr->GetSpellInfo(*spellId, DIFFICULTY_NONE);

            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has wrong spell '{}' defined in `auras` field in `creature_addon`.", guid, std::string(aura));
                continue;
            }

            if (spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
                TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has SPELL_AURA_CONTROL_VEHICLE aura {} defined in `auras` field in `creature_addon`.", guid, spellInfo->Id);

            if (std::find(creatureAddon.auras.begin(), creatureAddon.auras.end(), spellInfo->Id) != creatureAddon.auras.end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has duplicate aura (spell {}) in `auras` field in `creature_addon`.", guid, spellInfo->Id);
                continue;
            }

            if (spellInfo->GetDuration() > 0)
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has temporary aura (spell {}) in `auras` field in `creature_addon`.", guid, spellInfo->Id);
                continue;
            }

            creatureAddon.auras.push_back(spellInfo->Id);
        }

        if (creatureAddon.mount)
        {
            if (!sCreatureDisplayInfoStore.LookupEntry(creatureAddon.mount))
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid displayInfoId ({}) for mount defined in `creature_addon`", guid, creatureAddon.mount);
                creatureAddon.mount = 0;
            }
        }

        if (creatureAddon.standState >= MAX_UNIT_STAND_STATE)
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid unit stand state ({}) defined in `creature_addon`. Truncated to 0.", guid, creatureAddon.standState);
            creatureAddon.standState = 0;
        }

        if (AnimTier(creatureAddon.animTier) >= AnimTier::Max)
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid animation tier ({}) defined in `creature_addon`. Truncated to 0.", guid, creatureAddon.animTier);
            creatureAddon.animTier = 0;
        }

        if (creatureAddon.sheathState >= MAX_SHEATH_STATE)
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid sheath state ({}) defined in `creature_addon`. Truncated to 0.", guid, creatureAddon.sheathState);
            creatureAddon.sheathState = 0;
        }

        // PvPFlags don't need any checking for the time being since they cover the entire range of a byte

        if (!sEmotesStore.LookupEntry(creatureAddon.emote))
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid emote ({}) defined in `creature_addon`.", guid, creatureAddon.emote);
            creatureAddon.emote = 0;
        }

        if (creatureAddon.aiAnimKit && !sAnimKitStore.LookupEntry(creatureAddon.aiAnimKit))
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid aiAnimKit ({}) defined in `creature_addon`.", guid, creatureAddon.aiAnimKit);
            creatureAddon.aiAnimKit = 0;
        }

        if (creatureAddon.movementAnimKit && !sAnimKitStore.LookupEntry(creatureAddon.movementAnimKit))
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid movementAnimKit ({}) defined in `creature_addon`.", guid, creatureAddon.movementAnimKit);
            creatureAddon.movementAnimKit = 0;
        }

        if (creatureAddon.meleeAnimKit && !sAnimKitStore.LookupEntry(creatureAddon.meleeAnimKit))
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid meleeAnimKit ({}) defined in `creature_addon`.", guid, creatureAddon.meleeAnimKit);
            creatureAddon.meleeAnimKit = 0;
        }

        if (creatureAddon.visibilityDistanceType >= VisibilityDistanceType::Max)
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) has invalid visibilityDistanceType ({}) defined in `creature_addon`.",
                guid, AsUnderlyingType(creatureAddon.visibilityDistanceType));
            creatureAddon.visibilityDistanceType = VisibilityDistanceType::Normal;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature addons in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGameObjectAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                               0     1                 2                 3                 4                 5                 6                  7              8
    QueryResult result = WorldDatabase.Query("SELECT guid, parent_rotation0, parent_rotation1, parent_rotation2, parent_rotation3, invisibilityType, invisibilityValue, WorldEffectID, AIAnimKitID FROM gameobject_addon");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject addon definitions. DB table `gameobject_addon` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guid = fields[0].GetUInt64();

        GameObjectData const* goData = GetGameObjectData(guid);
        if (!goData)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: {}) does not exist but has a record in `gameobject_addon`", guid);
            continue;
        }

        GameObjectAddon& gameObjectAddon = _gameObjectAddonStore[guid];
        gameObjectAddon.ParentRotation = QuaternionData(fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat());
        gameObjectAddon.invisibilityType = InvisibilityType(fields[5].GetUInt8());
        gameObjectAddon.InvisibilityValue = fields[6].GetUInt32();
        gameObjectAddon.WorldEffectID = fields[7].GetUInt32();
        gameObjectAddon.AIAnimKitID   = fields[8].GetUInt32();

        if (gameObjectAddon.invisibilityType >= TOTAL_INVISIBILITY_TYPES)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: {}) has invalid InvisibilityType in `gameobject_addon`, disabled invisibility", guid);
            gameObjectAddon.invisibilityType = INVISIBILITY_GENERAL;
            gameObjectAddon.InvisibilityValue = 0;
        }

        if (gameObjectAddon.invisibilityType && !gameObjectAddon.InvisibilityValue)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: {}) has InvisibilityType set but has no InvisibilityValue in `gameobject_addon`, set to 1", guid);
            gameObjectAddon.InvisibilityValue = 1;
        }

        if (!gameObjectAddon.ParentRotation.isUnit())
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: {}) has invalid parent rotation in `gameobject_addon`, set to default", guid);
            gameObjectAddon.ParentRotation = QuaternionData();
        }

        if (gameObjectAddon.WorldEffectID && !sWorldEffectStore.LookupEntry(gameObjectAddon.WorldEffectID))
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: {}) has invalid WorldEffectID ({}) in `gameobject_addon`, set to 0.", guid, gameObjectAddon.WorldEffectID);
            gameObjectAddon.WorldEffectID = 0;
        }

        if (gameObjectAddon.AIAnimKitID && !sAnimKitStore.LookupEntry(gameObjectAddon.AIAnimKitID))
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: {}) has invalid AIAnimKitID ({}) in `gameobject_addon`, set to 0.", guid, gameObjectAddon.AIAnimKitID);
            gameObjectAddon.AIAnimKitID = 0;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gameobject addons in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

GameObjectAddon const* ObjectMgr::GetGameObjectAddon(ObjectGuid::LowType lowguid) const
{
    GameObjectAddonContainer::const_iterator itr = _gameObjectAddonStore.find(lowguid);
    if (itr != _gameObjectAddonStore.end())
        return &(itr->second);

    return nullptr;
}

CreatureAddon const* ObjectMgr::GetCreatureAddon(ObjectGuid::LowType lowguid) const
{
    CreatureAddonContainer::const_iterator itr = _creatureAddonStore.find(lowguid);
    if (itr != _creatureAddonStore.end())
        return &(itr->second);

    return nullptr;
}

CreatureAddon const* ObjectMgr::GetCreatureTemplateAddon(uint32 entry) const
{
    CreatureTemplateAddonContainer::const_iterator itr = _creatureTemplateAddonStore.find(entry);
    if (itr != _creatureTemplateAddonStore.end())
        return &(itr->second);

    return nullptr;
}

std::vector<float> const* ObjectMgr::GetCreatureTemplateSparringValues(uint32 entry) const
{
    return Trinity::Containers::MapGetValuePtr(_creatureTemplateSparringStore, entry);
}

CreatureMovementData const* ObjectMgr::GetCreatureMovementOverride(ObjectGuid::LowType spawnId) const
{
    return Trinity::Containers::MapGetValuePtr(_creatureMovementOverrides, spawnId);
}

EquipmentInfo const* ObjectMgr::GetEquipmentInfo(uint32 entry, int8& id) const
{
    EquipmentInfoContainer::const_iterator itr = _equipmentInfoStore.find(entry);
    if (itr == _equipmentInfoStore.end())
        return nullptr;

    if (itr->second.empty())
        return nullptr;

    if (id == -1) // select a random element
    {
        EquipmentInfoContainerInternal::const_iterator ritr = itr->second.begin();
        std::advance(ritr, urand(0u, itr->second.size() - 1));
        id = std::distance(itr->second.begin(), ritr) + 1;
        return &ritr->second;
    }
    else
    {
        EquipmentInfoContainerInternal::const_iterator itr2 = itr->second.find(id);
        if (itr2 != itr->second.end())
            return &itr2->second;
    }

    return nullptr;
}

void ObjectMgr::LoadEquipmentTemplates()
{
    uint32 oldMSTime = getMSTime();

    //                                                        0   1        2                 3            4
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, ID, ItemID1, AppearanceModID1, ItemVisual1, "
    //                                                                     5                 6            7
                                                                    "ItemID2, AppearanceModID2, ItemVisual2, "
    //                                                                     8                 9           10
                                                                    "ItemID3, AppearanceModID3, ItemVisual3 "
                                                                    "FROM creature_equip_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature equipment templates. DB table `creature_equip_template` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        if (!GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Creature template (CreatureID: {}) does not exist but has a record in `creature_equip_template`", entry);
            continue;
        }

        uint8 id = fields[1].GetUInt8();
        if (!id)
        {
            TC_LOG_ERROR("sql.sql", "Creature equipment template with id 0 found for creature {}, skipped.", entry);
            continue;
        }

        EquipmentInfo& equipmentInfo = _equipmentInfoStore[entry][id];
        for (uint8 i = 0; i < MAX_EQUIPMENT_ITEMS; ++i)
        {
            equipmentInfo.Items[i].ItemId = fields[2 + i * 3].GetUInt32();
            equipmentInfo.Items[i].AppearanceModId = fields[3 + i * 3].GetUInt16();
            equipmentInfo.Items[i].ItemVisual = fields[4 + i * 3].GetUInt16();

            if (!equipmentInfo.Items[i].ItemId)
                continue;

            ItemEntry const* dbcItem = sItemStore.LookupEntry(equipmentInfo.Items[i].ItemId);
            if (!dbcItem)
            {
                TC_LOG_ERROR("sql.sql", "Unknown item (ID={}) in creature_equip_template.ItemID{} for CreatureID = {} and ID={}, forced to 0.",
                    equipmentInfo.Items[i].ItemId, i + 1, entry, id);
                equipmentInfo.Items[i].ItemId = 0;
                continue;
            }

            if (!sDB2Manager.GetItemModifiedAppearance(equipmentInfo.Items[i].ItemId, equipmentInfo.Items[i].AppearanceModId))
            {
                TC_LOG_ERROR("sql.sql", "Unknown item appearance for (ID={}, AppearanceModID={}) pair in creature_equip_template.ItemID{} creature_equip_template.AppearanceModID{} "
                    "for CreatureID = {} and ID={}, forced to default.",
                    equipmentInfo.Items[i].ItemId, equipmentInfo.Items[i].AppearanceModId, i + 1, i + 1, entry, id);
                if (ItemModifiedAppearanceEntry const* defaultAppearance = sDB2Manager.GetDefaultItemModifiedAppearance(equipmentInfo.Items[i].ItemId))
                    equipmentInfo.Items[i].AppearanceModId = defaultAppearance->ItemAppearanceModifierID;
                else
                    equipmentInfo.Items[i].AppearanceModId = 0;
                continue;
            }

            if (dbcItem->InventoryType != INVTYPE_WEAPON &&
                dbcItem->InventoryType != INVTYPE_SHIELD &&
                dbcItem->InventoryType != INVTYPE_RANGED &&
                dbcItem->InventoryType != INVTYPE_2HWEAPON &&
                dbcItem->InventoryType != INVTYPE_WEAPONMAINHAND &&
                dbcItem->InventoryType != INVTYPE_WEAPONOFFHAND &&
                dbcItem->InventoryType != INVTYPE_HOLDABLE &&
                dbcItem->InventoryType != INVTYPE_THROWN &&
                dbcItem->InventoryType != INVTYPE_RANGEDRIGHT)
            {
                TC_LOG_ERROR("sql.sql", "Item (ID={}) in creature_equip_template.ItemID{} for CreatureID = {} and ID = {} is not equipable in a hand, forced to 0.",
                    equipmentInfo.Items[i].ItemId, i + 1, entry, id);
                equipmentInfo.Items[i].ItemId = 0;
            }
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} equipment templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureMovementOverrides()
{
    uint32 oldMSTime = getMSTime();

    _creatureMovementOverrides.clear();

    // Load the data from creature_movement_override and if NULL fallback to creature_template_movement
    QueryResult result = WorldDatabase.Query(
        "SELECT cmo.SpawnId,"
        "COALESCE(cmo.HoverInitiallyEnabled, ctm.HoverInitiallyEnabled),"
        "COALESCE(cmo.Chase, ctm.Chase),"
        "COALESCE(cmo.Random, ctm.Random),"
        "COALESCE(cmo.InteractionPauseTimer, ctm.InteractionPauseTimer) "
        "FROM creature_movement_override AS cmo "
        "LEFT JOIN creature AS c ON c.guid = cmo.SpawnId "
        "LEFT JOIN creature_template_movement AS ctm ON ctm.CreatureId = c.id");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature movement overrides. DB table `creature_movement_override` is empty!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();
        ObjectGuid::LowType spawnId = fields[0].GetUInt64();
        if (!GetCreatureData(spawnId))
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: {}) does not exist but has a record in `creature_movement_override`", spawnId);
            continue;
        }

        CreatureMovementData& movement = _creatureMovementOverrides[spawnId];
        if (!fields[1].IsNull())
            movement.HoverInitiallyEnabled = fields[1].GetBool();
        if (!fields[2].IsNull())
            movement.Chase = static_cast<CreatureChaseMovementType>(fields[2].GetUInt8());
        if (!fields[3].IsNull())
            movement.Random = static_cast<CreatureRandomMovementType>(fields[3].GetUInt8());
        if (!fields[4].IsNull())
            movement.InteractionPauseTimer = fields[4].GetUInt32();

        CheckCreatureMovement("creature_movement_override", spawnId, movement);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} movement overrides in {} ms", _creatureMovementOverrides.size(), GetMSTimeDiffToNow(oldMSTime));
}

CreatureModelInfo const* ObjectMgr::GetCreatureModelInfo(uint32 modelId) const
{
    CreatureModelContainer::const_iterator itr = _creatureModelStore.find(modelId);
    if (itr != _creatureModelStore.end())
        return &(itr->second);

    return nullptr;
}

CreatureSummonedData const* ObjectMgr::GetCreatureSummonedData(uint32 entryId) const
{
    return Trinity::Containers::MapGetValuePtr(_creatureSummonedDataStore, entryId);
}

CreatureModel const* ObjectMgr::ChooseDisplayId(CreatureTemplate const* cinfo, CreatureData const* data /*= nullptr*/)
{
    // Load creature model (display id)
    if (data && data->display)
        return &*data->display;

    if (!(cinfo->flags_extra & CREATURE_FLAG_EXTRA_TRIGGER))
        if (CreatureModel const* model = cinfo->GetRandomValidModel())
            return model;

    // Triggers by default receive the invisible model
    return cinfo->GetFirstInvisibleModel();
}

void ObjectMgr::ChooseCreatureFlags(CreatureTemplate const* cInfo, uint64* npcFlags, uint32* unitFlags, uint32* unitFlags2, uint32* unitFlags3, CreatureStaticFlagsHolder const& staticFlags, CreatureData const* data /*= nullptr*/)
{
#define ChooseCreatureFlagSource(field) ((data && data->field.has_value()) ? *data->field : cInfo->field)

    if (npcFlags)
        *npcFlags = ChooseCreatureFlagSource(npcflag);

    if (unitFlags)
    {
        *unitFlags = ChooseCreatureFlagSource(unit_flags);
        if (staticFlags.HasFlag(CREATURE_STATIC_FLAG_CAN_SWIM))
            *unitFlags |= UNIT_FLAG_CAN_SWIM;

        if (staticFlags.HasFlag(CREATURE_STATIC_FLAG_3_CANNOT_SWIM))
            *unitFlags |= UNIT_FLAG_CANT_SWIM;
    }

    if (unitFlags2)
    {
        *unitFlags2 = ChooseCreatureFlagSource(unit_flags2);
        if (staticFlags.HasFlag(CREATURE_STATIC_FLAG_3_CANNOT_TURN))
            *unitFlags2 |= UNIT_FLAG2_CANNOT_TURN;
    }

    if (unitFlags3)
        *unitFlags3 = ChooseCreatureFlagSource(unit_flags3);

#undef ChooseCreatureFlagSource
}

CreatureModelInfo const* ObjectMgr::GetCreatureModelRandomGender(CreatureModel* model, CreatureTemplate const* creatureTemplate) const
{
    CreatureModelInfo const* modelInfo = GetCreatureModelInfo(model->CreatureDisplayID);
    if (!modelInfo)
        return nullptr;

    // If a model for another gender exists, 50% chance to use it
    if (modelInfo->displayId_other_gender != 0 && urand(0, 1) == 0)
    {
        CreatureModelInfo const* minfo_tmp = GetCreatureModelInfo(modelInfo->displayId_other_gender);
        if (!minfo_tmp)
            TC_LOG_ERROR("sql.sql", "Model (Entry: {}) has modelid_other_gender {} not found in table `creature_model_info`. ", model->CreatureDisplayID, modelInfo->displayId_other_gender);
        else
        {
            // DisplayID changed
            model->CreatureDisplayID = modelInfo->displayId_other_gender;
            if (creatureTemplate)
            {
                auto itr = std::find_if(creatureTemplate->Models.begin(), creatureTemplate->Models.end(), [&](CreatureModel const& templateModel)
                {
                    return templateModel.CreatureDisplayID == modelInfo->displayId_other_gender;
                });
                if (itr != creatureTemplate->Models.end())
                    *model = *itr;
            }
            return minfo_tmp;
        }
    }

    return modelInfo;
}

void ObjectMgr::LoadCreatureModelInfo()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender FROM creature_model_info");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature model definitions. DB table `creature_model_info` is empty.");
        return;
    }

    _creatureModelStore.reserve(result->GetRowCount());
    uint32 count = 0;

    // List of model FileDataIDs that the client treats as invisible stalker
    uint32 trigggerCreatureModelFileID[5] = { 124640, 124641, 124642, 343863, 439302 };

    do
    {
        Field* fields = result->Fetch();

        uint32 displayId = fields[0].GetUInt32();

        CreatureDisplayInfoEntry const* creatureDisplay = sCreatureDisplayInfoStore.LookupEntry(displayId);
        if (!creatureDisplay)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_model_info` has a non-existent DisplayID (ID: {}). Skipped.", displayId);
            continue;
        }

        CreatureModelInfo& modelInfo = _creatureModelStore[displayId];

        modelInfo.bounding_radius        = fields[1].GetFloat();
        modelInfo.combat_reach           = fields[2].GetFloat();
        modelInfo.displayId_other_gender = fields[3].GetUInt32();
        modelInfo.gender                 = creatureDisplay->Gender;
        modelInfo.is_trigger             = false;

        // Checks

        // to remove when the purpose of GENDER_UNKNOWN is known
        if (modelInfo.gender == GENDER_UNKNOWN)
        {
            // We don't need more errors
            //TC_LOG_ERROR("sql.sql", "Table `creature_model_info` has an unimplemented Gender (ID: {}) being used by DisplayID (ID: {}). Gender set to GENDER_MALE.", modelInfo.gender, modelId);
            modelInfo.gender = GENDER_MALE;
        }

        if (modelInfo.displayId_other_gender && !sCreatureDisplayInfoStore.LookupEntry(modelInfo.displayId_other_gender))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_model_info` has a non-existent DisplayID_Other_Gender (ID: {}) being used by DisplayID (ID: {}).", modelInfo.displayId_other_gender, displayId);
            modelInfo.displayId_other_gender = 0;
        }

        if (modelInfo.combat_reach < 0.1f)
            modelInfo.combat_reach = DEFAULT_PLAYER_COMBAT_REACH;

        if (CreatureModelDataEntry const* modelData = sCreatureModelDataStore.LookupEntry(creatureDisplay->ModelID))
        {
            for (uint32 i = 0; i < 5; ++i)
            {
                if (modelData->FileDataID == trigggerCreatureModelFileID[i])
                {
                    modelInfo.is_trigger = true;
                    break;
                }
            }
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature model based info in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadLinkedRespawn()
{
    uint32 oldMSTime = getMSTime();

    _linkedRespawnStore.clear();
    //                                                 0        1          2
    QueryResult result = WorldDatabase.Query("SELECT guid, linkedGuid, linkType FROM linked_respawn ORDER BY guid ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 linked respawns. DB table `linked_respawn` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guidLow = fields[0].GetUInt64();
        ObjectGuid::LowType linkedGuidLow = fields[1].GetUInt64();
        uint8 linkType = fields[2].GetUInt8();

        ObjectGuid guid, linkedGuid;
        bool error = false;
        switch (linkType)
        {
            case LINKED_RESPAWN_CREATURE_TO_CREATURE:
            {
                CreatureData const* slave = GetCreatureData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (guid) '{}' not found in creature table", guidLow);
                    error = true;
                    break;
                }

                CreatureData const* master = GetCreatureData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (linkedGuid) '{}' not found in creature table", linkedGuidLow);
                    error = true;
                    break;
                }

                MapEntry const* const map = sMapStore.LookupEntry(master->mapId);
                if (!map || !map->Instanceable() || (master->mapId != slave->mapId))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '{}' linking to Creature '{}' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                // they must have a possibility to meet (normal/heroic difficulty)
                if (!Trinity::Containers::Intersects(master->spawnDifficulties.begin(), master->spawnDifficulties.end(), slave->spawnDifficulties.begin(), slave->spawnDifficulties.end()))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '{}' linking to Creature '{}' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::Creature>(slave->mapId, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::Creature>(master->mapId, master->id, linkedGuidLow);
                break;
            }
            case LINKED_RESPAWN_CREATURE_TO_GO:
            {
                CreatureData const* slave = GetCreatureData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (guid) '{}' not found in creature table", guidLow);
                    error = true;
                    break;
                }

                GameObjectData const* master = GetGameObjectData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (linkedGuid) '{}' not found in gameobject table", linkedGuidLow);
                    error = true;
                    break;
                }

                MapEntry const* const map = sMapStore.LookupEntry(master->mapId);
                if (!map || !map->Instanceable() || (master->mapId != slave->mapId))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '{}' linking to Gameobject '{}' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                // they must have a possibility to meet (normal/heroic difficulty)
                if (!Trinity::Containers::Intersects(master->spawnDifficulties.begin(), master->spawnDifficulties.end(), slave->spawnDifficulties.begin(), slave->spawnDifficulties.end()))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '{}' linking to Gameobject '{}' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::Creature>(slave->mapId, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::GameObject>(master->mapId, master->id, linkedGuidLow);
                break;
            }
            case LINKED_RESPAWN_GO_TO_GO:
            {
                GameObjectData const* slave = GetGameObjectData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (guid) '{}' not found in gameobject table", guidLow);
                    error = true;
                    break;
                }

                GameObjectData const* master = GetGameObjectData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (linkedGuid) '{}' not found in gameobject table", linkedGuidLow);
                    error = true;
                    break;
                }

                MapEntry const* const map = sMapStore.LookupEntry(master->mapId);
                if (!map || !map->Instanceable() || (master->mapId != slave->mapId))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '{}' linking to Gameobject '{}' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                // they must have a possibility to meet (normal/heroic difficulty)
                if (!Trinity::Containers::Intersects(master->spawnDifficulties.begin(), master->spawnDifficulties.end(), slave->spawnDifficulties.begin(), slave->spawnDifficulties.end()))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '{}' linking to Gameobject '{}' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::GameObject>(slave->mapId, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::GameObject>(master->mapId, master->id, linkedGuidLow);
                break;
            }
            case LINKED_RESPAWN_GO_TO_CREATURE:
            {
                GameObjectData const* slave = GetGameObjectData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (guid) '{}' not found in gameobject table", guidLow);
                    error = true;
                    break;
                }

                CreatureData const* master = GetCreatureData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (linkedGuid) '{}' not found in creature table", linkedGuidLow);
                    error = true;
                    break;
                }

                MapEntry const* const map = sMapStore.LookupEntry(master->mapId);
                if (!map || !map->Instanceable() || (master->mapId != slave->mapId))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '{}' linking to Creature '{}' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                // they must have a possibility to meet (normal/heroic difficulty)
                if (!Trinity::Containers::Intersects(master->spawnDifficulties.begin(), master->spawnDifficulties.end(), slave->spawnDifficulties.begin(), slave->spawnDifficulties.end()))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '{}' linking to Creature '{}' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::GameObject>(slave->mapId, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::Creature>(master->mapId, master->id, linkedGuidLow);
                break;
            }
        }

        if (!error)
            _linkedRespawnStore[guid] = linkedGuid;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} linked respawns in {} ms", uint64(_linkedRespawnStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::SetCreatureLinkedRespawn(ObjectGuid::LowType guidLow, ObjectGuid::LowType linkedGuidLow)
{
    if (!guidLow)
        return false;

    CreatureData const* master = GetCreatureData(guidLow);
    ASSERT(master);
    ObjectGuid guid = ObjectGuid::Create<HighGuid::Creature>(master->mapId, master->id, guidLow);

    if (!linkedGuidLow) // we're removing the linking
    {
        _linkedRespawnStore.erase(guid);
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN);
        stmt->setUInt64(0, guidLow);
        stmt->setUInt32(1, LINKED_RESPAWN_CREATURE_TO_CREATURE);
        WorldDatabase.Execute(stmt);
        return true;
    }

    CreatureData const* slave = GetCreatureData(linkedGuidLow);
    if (!slave)
    {
        TC_LOG_ERROR("sql.sql", "Creature '{}' linking to non-existent creature '{}'.", guidLow, linkedGuidLow);
        return false;
    }

    MapEntry const* map = sMapStore.LookupEntry(master->mapId);
    if (!map || !map->Instanceable() || (master->mapId != slave->mapId))
    {
        TC_LOG_ERROR("sql.sql", "Creature '{}' linking to '{}' on an unpermitted map.", guidLow, linkedGuidLow);
        return false;
    }

    // they must have a possibility to meet (normal/heroic difficulty)
    if (!Trinity::Containers::Intersects(master->spawnDifficulties.begin(), master->spawnDifficulties.end(), slave->spawnDifficulties.begin(), slave->spawnDifficulties.end()))
    {
        TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '{}' linking to '{}' with not corresponding spawnMask", guidLow, linkedGuidLow);
        return false;
    }

    ObjectGuid linkedGuid = ObjectGuid::Create<HighGuid::Creature>(slave->mapId, slave->id, linkedGuidLow);

    _linkedRespawnStore[guid] = linkedGuid;
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_REP_LINKED_RESPAWN);
    stmt->setUInt64(0, guidLow);
    stmt->setUInt64(1, linkedGuidLow);
    stmt->setUInt32(2, LINKED_RESPAWN_CREATURE_TO_CREATURE);
    WorldDatabase.Execute(stmt);
    return true;
}

void ObjectMgr::LoadTempSummons()
{
    uint32 oldMSTime = getMSTime();

    _tempSummonDataStore.clear();   // needed for reload case

    //                                               0           1             2        3      4           5           6           7            8           9
    QueryResult result = WorldDatabase.Query("SELECT summonerId, summonerType, groupId, entry, position_x, position_y, position_z, orientation, summonType, summonTime FROM creature_summon_groups");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 temp summons. DB table `creature_summon_groups` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 summonerId               = fields[0].GetUInt32();
        SummonerType summonerType       = SummonerType(fields[1].GetUInt8());
        uint8 group                     = fields[2].GetUInt8();

        switch (summonerType)
        {
            case SUMMONER_TYPE_CREATURE:
                if (!GetCreatureTemplate(summonerId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has summoner with non existing entry {} for creature summoner type, skipped.", summonerId);
                    continue;
                }
                break;
            case SUMMONER_TYPE_GAMEOBJECT:
                if (!GetGameObjectTemplate(summonerId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has summoner with non existing entry {} for gameobject summoner type, skipped.", summonerId);
                    continue;
                }
                break;
            case SUMMONER_TYPE_MAP:
                if (!sMapStore.LookupEntry(summonerId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has summoner with non existing entry {} for map summoner type, skipped.", summonerId);
                    continue;
                }
                break;
            default:
                TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has unhandled summoner type {} for summoner {}, skipped.", summonerType, summonerId);
                continue;
        }

        TempSummonData data;
        data.entry                      = fields[3].GetUInt32();

        if (!GetCreatureTemplate(data.entry))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has creature in group [Summoner ID: {}, Summoner Type: {}, Group ID: {}] with non existing creature entry {}, skipped.", summonerId, summonerType, group, data.entry);
            continue;
        }

        float posX                      = fields[4].GetFloat();
        float posY                      = fields[5].GetFloat();
        float posZ                      = fields[6].GetFloat();
        float orientation               = fields[7].GetFloat();

        data.pos.Relocate(posX, posY, posZ, orientation);

        data.type                       = TempSummonType(fields[8].GetUInt8());

        if (data.type > TEMPSUMMON_MANUAL_DESPAWN)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has unhandled temp summon type {} in group [Summoner ID: {}, Summoner Type: {}, Group ID: {}] for creature entry {}, skipped.", data.type, summonerId, summonerType, group, data.entry);
            continue;
        }

        data.time                       = Milliseconds(fields[9].GetUInt32());

        TempSummonGroupKey key(summonerId, summonerType, group);
        _tempSummonDataStore[key].push_back(data);

        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} temp summons in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

std::vector<Difficulty> ObjectMgr::ParseSpawnDifficulties(std::string_view difficultyString, std::string_view table, ObjectGuid::LowType spawnId, uint32 mapId,
    std::set<Difficulty> const& mapDifficulties)
{
    std::vector<Difficulty> difficulties;
    bool isTransportMap = sObjectMgr->IsTransportMap(mapId);
    for (std::string_view token : Trinity::Tokenize(difficultyString, ',', false))
    {
        Difficulty difficultyId = Difficulty(Trinity::StringTo<std::underlying_type_t<Difficulty>>(token).value_or(DIFFICULTY_NONE));
        if (difficultyId && !sDifficultyStore.LookupEntry(difficultyId))
        {
            TC_LOG_ERROR("sql.sql", "Table `{}` has {} (GUID: {}) with non invalid difficulty id {}, skipped.",
                table, table, spawnId, uint32(difficultyId));
            continue;
        }

        if (!isTransportMap && mapDifficulties.find(difficultyId) == mapDifficulties.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `{}` has {} (GUID: {}) has unsupported difficulty {} for map (Id: {}).",
                table, table, spawnId, uint32(difficultyId), mapId);
            continue;
        }

        difficulties.push_back(difficultyId);
    }

    std::sort(difficulties.begin(), difficulties.end());
    return difficulties;
}

void ObjectMgr::LoadCreatures()
{
    uint32 oldMSTime = getMSTime();

    //                                               0              1   2    3           4           5           6            7        8             9              10
    QueryResult result = WorldDatabase.Query("SELECT creature.guid, id, map, position_x, position_y, position_z, orientation, modelid, equipment_id, spawntimesecs, wander_distance, "
    //   11               12         13       14            15                 16          17           18                19                   20                    21
        "currentwaypoint, curhealth, curmana, MovementType, spawnDifficulties, eventEntry, poolSpawnId, creature.npcflag, creature.unit_flags, creature.unit_flags2, creature.unit_flags3, "
    //   22                      23                24                   25                       26                   27
        "creature.phaseUseFlags, creature.phaseid, creature.phasegroup, creature.terrainSwapMap, creature.ScriptName, creature.StringId "
        "FROM creature "
        "LEFT OUTER JOIN game_event_creature ON creature.guid = game_event_creature.guid "
        "LEFT OUTER JOIN pool_members ON pool_members.type = 0 AND creature.guid = pool_members.spawnId");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creatures. DB table `creature` is empty.");
        return;
    }

    // Build single time for check spawnmask
    std::unordered_map<uint32, std::set<Difficulty>> spawnMasks;
    for (MapDifficultyEntry const* mapDifficulty : sMapDifficultyStore)
        spawnMasks[mapDifficulty->MapID].insert(Difficulty(mapDifficulty->DifficultyID));

    PhaseShift phaseShift;

    _creatureDataStore.reserve(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guid = fields[0].GetUInt64();
        uint32 entry        = fields[1].GetUInt32();

        CreatureTemplate const* cInfo = GetCreatureTemplate(entry);
        if (!cInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {}) with non existing creature entry {}, skipped.", guid, entry);
            continue;
        }

        CreatureData& data = _creatureDataStore[guid];
        data.spawnId        = guid;
        data.id             = entry;
        data.mapId          = fields[2].GetUInt16();
        data.spawnPoint.Relocate(fields[3].GetFloat(), fields[4].GetFloat(), fields[5].GetFloat(), fields[6].GetFloat());
        if (uint32 displayId = fields[7].GetUInt32())
            data.display.emplace(displayId, DEFAULT_PLAYER_DISPLAY_SCALE, 1.0f);
        data.equipmentId    = fields[8].GetInt8();
        data.spawntimesecs  = fields[9].GetUInt32();
        data.wander_distance = fields[10].GetFloat();
        data.currentwaypoint= fields[11].GetUInt32();
        data.curhealth      = fields[12].GetUInt32();
        data.curmana        = fields[13].GetUInt32();
        data.movementType   = fields[14].GetUInt8();
        data.spawnDifficulties = ParseSpawnDifficulties(fields[15].GetStringView(), "creature", guid, data.mapId, spawnMasks[data.mapId]);
        int16 gameEvent     = fields[16].GetInt8();
        data.poolId         = fields[17].GetUInt32();
        if (!fields[18].IsNull())
            data.npcflag = fields[18].GetUInt64();
        if (!fields[19].IsNull())
            data.unit_flags = fields[19].GetUInt32();
        if (!fields[20].IsNull())
            data.unit_flags2 = fields[20].GetUInt32();
        if (!fields[21].IsNull())
            data.unit_flags3 = fields[21].GetUInt32();
        data.phaseUseFlags  = fields[22].GetUInt8();
        data.phaseId        = fields[23].GetUInt32();
        data.phaseGroup     = fields[24].GetUInt32();
        data.terrainSwapMap = fields[25].GetInt32();
        data.scriptId       = GetScriptId(fields[26].GetString());
        data.StringId       = fields[27].GetString();
        data.spawnGroupData = IsTransportMap(data.mapId) ? GetLegacySpawnGroup() : GetDefaultSpawnGroup(); // transport spawns default to compatibility group

        MapEntry const* mapEntry = sMapStore.LookupEntry(data.mapId);
        if (!mapEntry)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {}) that spawned at nonexistent map (Id: {}), skipped.", guid, data.mapId);
            continue;
        }

        if (sWorld->getBoolConfig(CONFIG_CREATURE_CHECK_INVALID_POSITION))
        {
            if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
            {
                if (vmgr->isMapLoadingEnabled() && !IsTransportMap(data.mapId))
                {
                    GridCoord gridCoord = Trinity::ComputeGridCoord(data.spawnPoint.GetPositionX(), data.spawnPoint.GetPositionY());
                    int gx = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.x_coord;
                    int gy = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.y_coord;

                    VMAP::LoadResult result = vmgr->existsMap((sWorld->GetDataPath() + "vmaps").c_str(), data.mapId, gx, gy);
                    if (result != VMAP::LoadResult::Success)
                        TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {} MapID: {}) spawned on a possible invalid position ({})",
                            guid, data.id, data.mapId, data.spawnPoint.ToString());
                }
            }
        }

        if (data.spawnDifficulties.empty())
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {}) that is not spawned in any difficulty, skipped.", guid);
            continue;
        }

        // -1 random, 0 no equipment
        if (data.equipmentId != 0)
        {
            if (!GetEquipmentInfo(data.id, data.equipmentId))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (Entry: {}) with equipment_id {} not found in table `creature_equip_template`, set to no equipment.", data.id, data.equipmentId);
                data.equipmentId = 0;
            }
        }

        if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
        {
            if (!mapEntry->IsDungeon())
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with `creature_template`.`flags_extra` including CREATURE_FLAG_EXTRA_INSTANCE_BIND but creature is not in instance.", guid, data.id);
        }

        if (data.movementType >= MAX_DB_MOTION_TYPE)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with wrong movement generator type ({}), ignored and set to IDLE.", guid, data.id, data.movementType);
            data.movementType = IDLE_MOTION_TYPE;
        }

        if (data.wander_distance < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with `wander_distance`< 0, set to 0.", guid, data.id);
            data.wander_distance = 0.0f;
        }
        else if (data.wander_distance > 0.0f && data.wander_distance < 0.1f)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with `wander_distance` below the allowed minimum distance of 0.1, set to 0.", guid, data.id);
            data.wander_distance = 0.0f;
        }
        else if (data.movementType == RANDOM_MOTION_TYPE)
        {
            if (G3D::fuzzyEq(data.wander_distance, 0.0f))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with `MovementType`=1 (random movement) but with `wander_distance`=0, replace by idle movement type (0).", guid, data.id);
                data.movementType = IDLE_MOTION_TYPE;
            }
        }
        else if (data.movementType == IDLE_MOTION_TYPE)
        {
            if (data.wander_distance != 0.0f)
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with `MovementType`=0 (idle) have `wander_distance`<>0, set to 0.", guid, data.id);
                data.wander_distance = 0.0f;
            }
        }

        if (data.phaseUseFlags & ~PHASE_USE_FLAGS_ALL)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) has unknown `phaseUseFlags` set, removed unknown value.", guid, data.id);
            data.phaseUseFlags &= PHASE_USE_FLAGS_ALL;
        }

        if (data.phaseUseFlags & PHASE_USE_FLAGS_ALWAYS_VISIBLE && data.phaseUseFlags & PHASE_USE_FLAGS_INVERSE)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) has both `phaseUseFlags` PHASE_USE_FLAGS_ALWAYS_VISIBLE and PHASE_USE_FLAGS_INVERSE,"
                " removing PHASE_USE_FLAGS_INVERSE.", guid, data.id);
            data.phaseUseFlags &= ~PHASE_USE_FLAGS_INVERSE;
        }

        if (data.phaseGroup && data.phaseId)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) with both `phaseid` and `phasegroup` set, `phasegroup` set to 0", guid, data.id);
            data.phaseGroup = 0;
        }

        if (data.phaseId)
        {
            if (!sPhaseStore.LookupEntry(data.phaseId))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) with `phaseid` {} does not exist, set to 0", guid, data.id, data.phaseId);
                data.phaseId = 0;
            }
        }

        if (data.phaseGroup)
        {
            if (!sDB2Manager.GetPhasesForGroup(data.phaseGroup))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) with `phasegroup` {} does not exist, set to 0", guid, data.id, data.phaseGroup);
                data.phaseGroup = 0;
            }
        }

        if (data.terrainSwapMap != -1)
        {
            MapEntry const* terrainSwapEntry = sMapStore.LookupEntry(data.terrainSwapMap);
            if (!terrainSwapEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) with `terrainSwapMap` {} does not exist, set to -1", guid, data.id, data.terrainSwapMap);
                data.terrainSwapMap = -1;
            }
            else if (terrainSwapEntry->ParentMapID != int16(data.mapId))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: {} Entry: {}) with `terrainSwapMap` {} which cannot be used on spawn map, set to -1", guid, data.id, data.terrainSwapMap);
                data.terrainSwapMap = -1;
            }
        }

        if (data.unit_flags.has_value())
        {
            if (uint32 disallowedUnitFlags = (*data.unit_flags & ~UNIT_FLAG_ALLOWED))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with disallowed `unit_flags` {}, removing incorrect flag.", guid, data.id, disallowedUnitFlags);
                *data.unit_flags &= UNIT_FLAG_ALLOWED;
            }
        }

        if (data.unit_flags2.has_value())
        {
            if (uint32 disallowedUnitFlags2 = (*data.unit_flags2 & ~UNIT_FLAG2_ALLOWED))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with disallowed `unit_flags2` {}, removing incorrect flag.", guid, data.id, disallowedUnitFlags2);
                *data.unit_flags2 &= UNIT_FLAG2_ALLOWED;
            }
        }

        if (data.unit_flags3.has_value())
        {
            if (uint32 disallowedUnitFlags3 = (*data.unit_flags3 & ~UNIT_FLAG3_ALLOWED))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {} Entry: {}) with disallowed `unit_flags3` {}, removing incorrect flag.", guid, data.id, disallowedUnitFlags3);
                *data.unit_flags3 &= UNIT_FLAG3_ALLOWED;
            }
        }

        if (sWorld->getBoolConfig(CONFIG_CALCULATE_CREATURE_ZONE_AREA_DATA))
        {
            uint32 zoneId = 0;
            uint32 areaId = 0;
            PhasingHandler::InitDbVisibleMapId(phaseShift, data.terrainSwapMap);
            sTerrainMgr.GetZoneAndAreaId(phaseShift, zoneId, areaId, data.mapId, data.spawnPoint);

            WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_ZONE_AREA_DATA);

            stmt->setUInt32(0, zoneId);
            stmt->setUInt32(1, areaId);
            stmt->setUInt64(2, guid);

            WorldDatabase.Execute(stmt);
        }

        // Add to grid if not managed by the game event
        if (gameEvent == 0)
            AddCreatureToGrid(&data);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creatures in {} ms", _creatureDataStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

CellObjectGuids const* ObjectMgr::GetCellObjectGuids(uint32 mapid, Difficulty spawnMode, uint32 cell_id)
{
    if (CellObjectGuidsMap const* mapGuids = Trinity::Containers::MapGetValuePtr(_mapObjectGuidsStore, { mapid, spawnMode }))
        return Trinity::Containers::MapGetValuePtr(*mapGuids, cell_id);

    return nullptr;
}

CellObjectGuidsMap const* ObjectMgr::GetMapObjectGuids(uint32 mapid, Difficulty spawnMode)
{
    return Trinity::Containers::MapGetValuePtr(_mapObjectGuidsStore, { mapid, spawnMode });
}

bool ObjectMgr::HasPersonalSpawns(uint32 mapid, Difficulty spawnMode, uint32 phaseId) const
{
    return Trinity::Containers::MapGetValuePtr(_mapPersonalObjectGuidsStore, { mapid, spawnMode, phaseId }) != nullptr;
}

CellObjectGuids const* ObjectMgr::GetCellPersonalObjectGuids(uint32 mapid, Difficulty spawnMode, uint32 phaseId, uint32 cell_id) const
{
    if (CellObjectGuidsMap const* guids = Trinity::Containers::MapGetValuePtr(_mapPersonalObjectGuidsStore, { mapid, spawnMode, phaseId }))
        return Trinity::Containers::MapGetValuePtr(*guids, cell_id);

    return nullptr;
}

template<CellGuidSet CellObjectGuids::*guids>
void ObjectMgr::AddSpawnDataToGrid(SpawnData const* data)
{
    uint32 cellId = Trinity::ComputeCellCoord(data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY()).GetId();
    bool isPersonalPhase = PhasingHandler::IsPersonalPhase(data->phaseId);
    if (!isPersonalPhase)
    {
        for (Difficulty difficulty : data->spawnDifficulties)
            (_mapObjectGuidsStore[{ data->mapId, difficulty }][cellId].*guids).insert(data->spawnId);
    }
    else
    {
        for (Difficulty difficulty : data->spawnDifficulties)
            (_mapPersonalObjectGuidsStore[{ data->mapId, difficulty, data->phaseId }][cellId].*guids).insert(data->spawnId);
    }
}

template<CellGuidSet CellObjectGuids::*guids>
void ObjectMgr::RemoveSpawnDataFromGrid(SpawnData const* data)
{
    uint32 cellId = Trinity::ComputeCellCoord(data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY()).GetId();
    bool isPersonalPhase = PhasingHandler::IsPersonalPhase(data->phaseId);
    if (!isPersonalPhase)
    {
        for (Difficulty difficulty : data->spawnDifficulties)
            (_mapObjectGuidsStore[{ data->mapId, difficulty }][cellId].*guids).erase(data->spawnId);
    }
    else
    {
        for (Difficulty difficulty : data->spawnDifficulties)
            (_mapPersonalObjectGuidsStore[{ data->mapId, difficulty, data->phaseId }][cellId].*guids).erase(data->spawnId);
    }
}

void ObjectMgr::AddCreatureToGrid(CreatureData const* data)
{
    AddSpawnDataToGrid<&CellObjectGuids::creatures>(data);
}

void ObjectMgr::RemoveCreatureFromGrid(CreatureData const* data)
{
    RemoveSpawnDataFromGrid<&CellObjectGuids::creatures>(data);
}

void ObjectMgr::LoadGameObjects()
{
    uint32 oldMSTime = getMSTime();

    //                                                0                1   2    3           4           5           6
    QueryResult result = WorldDatabase.Query("SELECT gameobject.guid, id, map, position_x, position_y, position_z, orientation, "
    //   7          8          9          10         11             12            13     14                 15          16
        "rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, spawnDifficulties, eventEntry, poolSpawnId, "
    //   17             18       19          20              21          22
        "phaseUseFlags, phaseid, phasegroup, terrainSwapMap, ScriptName, StringId "
        "FROM gameobject LEFT OUTER JOIN game_event_gameobject ON gameobject.guid = game_event_gameobject.guid "
        "LEFT OUTER JOIN pool_members ON pool_members.type = 1 AND gameobject.guid = pool_members.spawnId");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobjects. DB table `gameobject` is empty.");
        return;
    }

    // build single time for check spawnmask
    std::unordered_map<uint32, std::set<Difficulty>> spawnMasks;
    for (MapDifficultyEntry const* mapDifficulty : sMapDifficultyStore)
        spawnMasks[mapDifficulty->MapID].insert(Difficulty(mapDifficulty->DifficultyID));

    PhaseShift phaseShift;

    _gameObjectDataStore.reserve(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guid = fields[0].GetUInt64();
        uint32 entry        = fields[1].GetUInt32();

        GameObjectTemplate const* gInfo = GetGameObjectTemplate(entry);
        if (!gInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {}) with non existing gameobject entry {}, skipped.", guid, entry);
            continue;
        }

        if (!gInfo->displayId)
        {
            switch (gInfo->type)
            {
                case GAMEOBJECT_TYPE_TRAP:
                case GAMEOBJECT_TYPE_SPELL_FOCUS:
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "Gameobject (GUID: {} Entry {} GoType: {}) doesn't have a displayId ({}), not loaded.", guid, entry, gInfo->type, gInfo->displayId);
                    break;
            }
        }

        if (gInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(gInfo->displayId))
        {
            TC_LOG_ERROR("sql.sql", "Gameobject (GUID: {} Entry {} GoType: {}) has an invalid displayId ({}), not loaded.", guid, entry, gInfo->type, gInfo->displayId);
            continue;
        }

        GameObjectData& data = _gameObjectDataStore[guid];

        data.spawnId        = guid;
        data.id             = entry;
        data.mapId          = fields[2].GetUInt16();
        data.spawnPoint.Relocate(fields[3].GetFloat(), fields[4].GetFloat(), fields[5].GetFloat(), fields[6].GetFloat());
        data.rotation.x     = fields[7].GetFloat();
        data.rotation.y     = fields[8].GetFloat();
        data.rotation.z     = fields[9].GetFloat();
        data.rotation.w     = fields[10].GetFloat();
        data.spawntimesecs  = fields[11].GetInt32();
        data.spawnGroupData = IsTransportMap(data.mapId) ? GetLegacySpawnGroup() : GetDefaultSpawnGroup(); // transport spawns default to compatibility group

        MapEntry const* mapEntry = sMapStore.LookupEntry(data.mapId);
        if (!mapEntry)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) spawned on a non-existed map (Id: {}), skip", guid, data.id, data.mapId);
            continue;
        }

        if (sWorld->getBoolConfig(CONFIG_GAME_OBJECT_CHECK_INVALID_POSITION))
        {
            if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
            {
                if (vmgr->isMapLoadingEnabled() && !IsTransportMap(data.mapId))
                {
                    GridCoord gridCoord = Trinity::ComputeGridCoord(data.spawnPoint.GetPositionX(), data.spawnPoint.GetPositionY());
                    int gx = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.x_coord;
                    int gy = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.y_coord;

                    VMAP::LoadResult result = vmgr->existsMap((sWorld->GetDataPath() + "vmaps").c_str(), data.mapId, gx, gy);
                    if (result != VMAP::LoadResult::Success)
                        TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {} MapID: {}) spawned on a possible invalid position ({})",
                            guid, data.id, data.mapId, data.spawnPoint.ToString());
                }
            }
        }

        if (data.spawntimesecs == 0 && gInfo->IsDespawnAtAction())
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with `spawntimesecs` (0) value, but the gameobejct is marked as despawnable at action.", guid, data.id);
        }

        data.animprogress   = fields[12].GetUInt8();
        data.artKit         = 0;

        uint32 go_state     = fields[13].GetUInt8();
        if (go_state >= MAX_GO_STATE)
        {
            if (gInfo->type != GAMEOBJECT_TYPE_TRANSPORT || go_state > GO_STATE_TRANSPORT_ACTIVE + MAX_GO_STATE_TRANSPORT_STOP_FRAMES)
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid `state` ({}) value, skip", guid, data.id, go_state);
                continue;
            }
        }
        data.goState       = GOState(go_state);

        data.spawnDifficulties      = ParseSpawnDifficulties(fields[14].GetStringView(), "gameobject", guid, data.mapId, spawnMasks[data.mapId]);
        if (data.spawnDifficulties.empty())
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: {}) that is not spawned in any difficulty, skipped.", guid);
            continue;
        }

        int16 gameEvent     = fields[15].GetInt8();
        data.poolId         = fields[16].GetUInt32();
        data.phaseUseFlags  = fields[17].GetUInt8();
        data.phaseId        = fields[18].GetUInt32();
        data.phaseGroup     = fields[19].GetUInt32();

        if (data.phaseUseFlags & ~PHASE_USE_FLAGS_ALL)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) has unknown `phaseUseFlags` set, removed unknown value.", guid, data.id);
            data.phaseUseFlags &= PHASE_USE_FLAGS_ALL;
        }

        if (data.phaseUseFlags & PHASE_USE_FLAGS_ALWAYS_VISIBLE && data.phaseUseFlags & PHASE_USE_FLAGS_INVERSE)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) has both `phaseUseFlags` PHASE_USE_FLAGS_ALWAYS_VISIBLE and PHASE_USE_FLAGS_INVERSE,"
                " removing PHASE_USE_FLAGS_INVERSE.", guid, data.id);
            data.phaseUseFlags &= ~PHASE_USE_FLAGS_INVERSE;
        }

        if (data.phaseGroup && data.phaseId)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) with both `phaseid` and `phasegroup` set, `phasegroup` set to 0", guid, data.id);
            data.phaseGroup = 0;
        }

        if (data.phaseId)
        {
            if (!sPhaseStore.LookupEntry(data.phaseId))
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) with `phaseid` {} does not exist, set to 0", guid, data.id, data.phaseId);
                data.phaseId = 0;
            }
        }

        if (data.phaseGroup)
        {
            if (!sDB2Manager.GetPhasesForGroup(data.phaseGroup))
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) with `phaseGroup` {} does not exist, set to 0", guid, data.id, data.phaseGroup);
                data.phaseGroup = 0;
            }
        }

        data.terrainSwapMap = fields[20].GetInt32();
        if (data.terrainSwapMap != -1)
        {
            MapEntry const* terrainSwapEntry = sMapStore.LookupEntry(data.terrainSwapMap);
            if (!terrainSwapEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) with `terrainSwapMap` {} does not exist, set to -1", guid, data.id, data.terrainSwapMap);
                data.terrainSwapMap = -1;
            }
            else if (terrainSwapEntry->ParentMapID != int16(data.mapId))
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: {} Entry: {}) with `terrainSwapMap` {} which cannot be used on spawn map, set to -1", guid, data.id, data.terrainSwapMap);
                data.terrainSwapMap = -1;
            }
        }

        data.scriptId = GetScriptId(fields[21].GetString());
        data.StringId = fields[22].GetString();

        if (data.rotation.x < -1.0f || data.rotation.x > 1.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid rotationX ({}) value, skip", guid, data.id, data.rotation.x);
            continue;
        }

        if (data.rotation.y < -1.0f || data.rotation.y > 1.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid rotationY ({}) value, skip", guid, data.id, data.rotation.y);
            continue;
        }

        if (data.rotation.z < -1.0f || data.rotation.z > 1.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid rotationZ ({}) value, skip", guid, data.id, data.rotation.z);
            continue;
        }

        if (data.rotation.w < -1.0f || data.rotation.w > 1.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid rotationW ({}) value, skip", guid, data.id, data.rotation.w);
            continue;
        }

        if (!MapManager::IsValidMapCoord(data.mapId, data.spawnPoint))
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid coordinates, skip", guid, data.id);
            continue;
        }

        if (!data.rotation.isUnit())
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: {} Entry: {}) with invalid rotation quaternion (non-unit), defaulting to orientation on Z axis only", guid, data.id);
            data.rotation = QuaternionData::fromEulerAnglesZYX(data.spawnPoint.GetOrientation(), 0.0f, 0.0f);
        }

        if (sWorld->getBoolConfig(CONFIG_CALCULATE_GAMEOBJECT_ZONE_AREA_DATA))
        {
            uint32 zoneId = 0;
            uint32 areaId = 0;
            PhasingHandler::InitDbVisibleMapId(phaseShift, data.terrainSwapMap);
            sTerrainMgr.GetZoneAndAreaId(phaseShift, zoneId, areaId, data.mapId, data.spawnPoint);

            WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_GAMEOBJECT_ZONE_AREA_DATA);

            stmt->setUInt32(0, zoneId);
            stmt->setUInt32(1, areaId);
            stmt->setUInt64(2, guid);

            WorldDatabase.Execute(stmt);
        }

        if (gameEvent == 0)                      // if not this is to be managed by GameEvent System
            AddGameobjectToGrid(&data);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gameobjects in {} ms", _gameObjectDataStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadSpawnGroupTemplates()
{
    uint32 oldMSTime = getMSTime();

    //                                               0        1          2
    QueryResult result = WorldDatabase.Query("SELECT groupId, groupName, groupFlags FROM spawn_group_template");

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 groupId = fields[0].GetUInt32();
            SpawnGroupTemplateData& group = _spawnGroupDataStore[groupId];
            group.groupId = groupId;
            group.name = fields[1].GetString();
            group.mapId = SPAWNGROUP_MAP_UNSET;
            uint32 flags = fields[2].GetUInt32();
            if (flags & ~SPAWNGROUP_FLAGS_ALL)
            {
                flags &= SPAWNGROUP_FLAGS_ALL;
                TC_LOG_ERROR("sql.sql", "Invalid spawn group flag {} on group ID {} ({}), reduced to valid flag {}.", flags, groupId, group.name, uint32(group.flags));
            }
            if (flags & SPAWNGROUP_FLAG_SYSTEM && flags & SPAWNGROUP_FLAG_MANUAL_SPAWN)
            {
                flags &= ~SPAWNGROUP_FLAG_MANUAL_SPAWN;
                TC_LOG_ERROR("sql.sql", "System spawn group {} ({}) has invalid manual spawn flag. Ignored.", groupId, group.name);
            }
            group.flags = SpawnGroupFlags(flags);
        } while (result->NextRow());
    }

    if (_spawnGroupDataStore.find(0) == _spawnGroupDataStore.end())
    {
        TC_LOG_ERROR("sql.sql", "Default spawn group (index 0) is missing from DB! Manually inserted.");
        SpawnGroupTemplateData& data = _spawnGroupDataStore[0];
        data.groupId = 0;
        data.name = "Default Group";
        data.mapId = 0;
        data.flags = SPAWNGROUP_FLAG_SYSTEM;
    }
    if (_spawnGroupDataStore.find(1) == _spawnGroupDataStore.end())
    {
        TC_LOG_ERROR("sql.sql", "Default legacy spawn group (index 1) is missing from DB! Manually inserted.");
        SpawnGroupTemplateData&data = _spawnGroupDataStore[1];
        data.groupId = 1;
        data.name = "Legacy Group";
        data.mapId = 0;
        data.flags = SpawnGroupFlags(SPAWNGROUP_FLAG_SYSTEM | SPAWNGROUP_FLAG_COMPATIBILITY_MODE);
    }

    if (result)
        TC_LOG_INFO("server.loading", ">> Loaded {} spawn group templates in {} ms", _spawnGroupDataStore.size(), GetMSTimeDiffToNow(oldMSTime));
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 spawn group templates. DB table `spawn_group_template` is empty.");

    return;
}

void ObjectMgr::LoadSpawnGroups()
{
    uint32 oldMSTime = getMSTime();

    //                                               0        1          2
    QueryResult result = WorldDatabase.Query("SELECT groupId, spawnType, spawnId FROM spawn_group");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spawn group members. DB table `spawn_group` is empty.");
        return;
    }

    uint32 numMembers = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 groupId = fields[0].GetUInt32();
        SpawnObjectType spawnType = SpawnObjectType(fields[1].GetUInt8());
        if (!SpawnData::TypeIsValid(spawnType))
        {
            TC_LOG_ERROR("sql.sql", "Spawn data with invalid type {} listed for spawn group {}. Skipped.", uint32(spawnType), groupId);
            continue;
        }
        ObjectGuid::LowType spawnId = fields[2].GetUInt64();

        SpawnMetadata const* data = GetSpawnMetadata(spawnType, spawnId);
        if (!data)
        {
            TC_LOG_ERROR("sql.sql", "Spawn data with ID ({},{}) not found, but is listed as a member of spawn group {}!", uint32(spawnType), spawnId, groupId);
            continue;
        }
        else if (data->spawnGroupData->groupId)
        {
            TC_LOG_ERROR("sql.sql", "Spawn with ID ({},{}) is listed as a member of spawn group {}, but is already a member of spawn group {}. Skipping.", uint32(spawnType), spawnId, groupId, data->spawnGroupData->groupId);
            continue;
        }
        auto it = _spawnGroupDataStore.find(groupId);
        if (it == _spawnGroupDataStore.end())
        {
            TC_LOG_ERROR("sql.sql", "Spawn group {} assigned to spawn ID ({},{}), but group is found!", groupId, uint32(spawnType), spawnId);
            continue;
        }
        else
        {
            SpawnGroupTemplateData& groupTemplate = it->second;
            if (groupTemplate.mapId == SPAWNGROUP_MAP_UNSET)
            {
                groupTemplate.mapId = data->mapId;
                _spawnGroupsByMap[data->mapId].push_back(groupId);
            }
            else if (groupTemplate.mapId != data->mapId && !(groupTemplate.flags & SPAWNGROUP_FLAG_SYSTEM))
            {
                TC_LOG_ERROR("sql.sql", "Spawn group {} has map ID {}, but spawn ({},{}) has map id {} - spawn NOT added to group!", groupId, groupTemplate.mapId, uint32(spawnType), spawnId, data->mapId);
                continue;
            }
            const_cast<SpawnMetadata*>(data)->spawnGroupData = &groupTemplate;
            if (!(groupTemplate.flags & SPAWNGROUP_FLAG_SYSTEM))
                _spawnGroupMapStore.emplace(groupId, data);
            ++numMembers;
        }
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spawn group members in {} ms", numMembers, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadInstanceSpawnGroups()
{
    uint32 oldMSTime = getMSTime();

    //                                               0              1            2           3             4
    QueryResult result = WorldDatabase.Query("SELECT instanceMapId, bossStateId, bossStates, spawnGroupId, flags FROM instance_spawn_groups");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 instance spawn groups. DB table `instance_spawn_groups` is empty.");
        return;
    }

    uint32 n = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 const spawnGroupId = fields[3].GetUInt32();
        auto it = _spawnGroupDataStore.find(spawnGroupId);
        if (it == _spawnGroupDataStore.end() || (it->second.flags & SPAWNGROUP_FLAG_SYSTEM))
        {
            TC_LOG_ERROR("sql.sql", "Invalid spawn group {} specified for instance {}. Skipped.", spawnGroupId, fields[0].GetUInt16());
            continue;
        }

        uint16 const instanceMapId = fields[0].GetUInt16();
        if (it->second.mapId != instanceMapId)
        {
            TC_LOG_ERROR("sql.sql", "Instance spawn group {} specified for instance {} has spawns on a different map {}. Skipped.",
                spawnGroupId, instanceMapId, it->second.mapId);
            continue;
        }

        InstanceSpawnGroupInfo& info = _instanceSpawnGroupStore[instanceMapId].emplace_back();
        info.SpawnGroupId = spawnGroupId;
        info.BossStateId = fields[1].GetUInt8();

        uint8 const ALL_STATES = (1 << TO_BE_DECIDED) - 1;
        uint8 const states = fields[2].GetUInt8();
        if (states & ~ALL_STATES)
        {
            info.BossStates = states & ALL_STATES;
            TC_LOG_ERROR("sql.sql", "Instance spawn group ({},{}) had invalid boss state mask {} - truncated to {}.", instanceMapId, spawnGroupId, states, info.BossStates);
        }
        else
            info.BossStates = states;

        uint8 const flags = fields[4].GetUInt8();
        if (flags & ~InstanceSpawnGroupInfo::FLAG_ALL)
        {
            info.Flags = flags & InstanceSpawnGroupInfo::FLAG_ALL;
            TC_LOG_ERROR("sql.sql", "Instance spawn group ({},{}) had invalid flags {} - truncated to {}.", instanceMapId, spawnGroupId, flags, info.Flags);
        }
        else
            info.Flags = flags;

        if ((flags & InstanceSpawnGroupInfo::FLAG_ALLIANCE_ONLY) && (flags & InstanceSpawnGroupInfo::FLAG_HORDE_ONLY))
        {
            info.Flags = flags & ~(InstanceSpawnGroupInfo::FLAG_ALLIANCE_ONLY | InstanceSpawnGroupInfo::FLAG_HORDE_ONLY);
            TC_LOG_ERROR("sql.sql", "Instance spawn group ({},{}) FLAG_ALLIANCE_ONLY and FLAG_HORDE_ONLY may not be used together in a single entry - truncated to {}.", instanceMapId, spawnGroupId, info.Flags);
        }

        ++n;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} instance spawn groups in {} ms", n, GetMSTimeDiffToNow(oldMSTime));
}

SpawnData const* ObjectMgr::GetSpawnData(SpawnObjectType type, ObjectGuid::LowType spawnId) const
{
    if (!SpawnData::TypeHasData(type))
        return nullptr;
    switch (type)
    {
        case SPAWN_TYPE_CREATURE:
            return GetCreatureData(spawnId);
        case SPAWN_TYPE_GAMEOBJECT:
            return GetGameObjectData(spawnId);
        case SPAWN_TYPE_AREATRIGGER:
            return sAreaTriggerDataStore->GetAreaTriggerSpawn(spawnId);
        default:
            ABORT_MSG("Invalid spawn object type %u", uint32(type));
            return nullptr;
    }
}

void ObjectMgr::OnDeleteSpawnData(SpawnData const* data)
{
    auto templateIt = _spawnGroupDataStore.find(data->spawnGroupData->groupId);
    ASSERT(templateIt != _spawnGroupDataStore.end(), "Creature data for (%u," UI64FMTD ") is being deleted and has invalid spawn group index %u!", uint32(data->type), data->spawnId, data->spawnGroupData->groupId);
    if (templateIt->second.flags & SPAWNGROUP_FLAG_SYSTEM) // system groups don't store their members in the map
        return;

    auto pair = _spawnGroupMapStore.equal_range(data->spawnGroupData->groupId);
    for (auto it = pair.first; it != pair.second; ++it)
    {
        if (it->second != data)
            continue;
        _spawnGroupMapStore.erase(it);
        return;
    }
    ABORT_MSG("Spawn data (%u," UI64FMTD ") being removed is member of spawn group %u, but not actually listed in the lookup table for that group!", uint32(data->type), data->spawnId, data->spawnGroupData->groupId);
}

void ObjectMgr::AddGameobjectToGrid(GameObjectData const* data)
{
    AddSpawnDataToGrid<&CellObjectGuids::gameobjects>(data);
}

void ObjectMgr::RemoveGameobjectFromGrid(GameObjectData const* data)
{
    RemoveSpawnDataFromGrid<&CellObjectGuids::gameobjects>(data);
}

uint32 FillMaxDurability(uint32 itemClass, uint32 itemSubClass, uint32 inventoryType, uint32 quality, uint32 itemLevel)
{
    if (itemClass != ITEM_CLASS_ARMOR && itemClass != ITEM_CLASS_WEAPON)
        return 0;

    static float const qualityMultipliers[MAX_ITEM_QUALITY] =
    {
        0.92f, 0.92f, 0.92f, 1.11f, 1.32f, 1.61f, 0.0f, 0.0f
    };

    static float const armorMultipliers[MAX_INVTYPE] =
    {
        0.00f, // INVTYPE_NON_EQUIP
        0.60f, // INVTYPE_HEAD
        0.00f, // INVTYPE_NECK
        0.60f, // INVTYPE_SHOULDERS
        0.00f, // INVTYPE_BODY
        1.00f, // INVTYPE_CHEST
        0.33f, // INVTYPE_WAIST
        0.72f, // INVTYPE_LEGS
        0.48f, // INVTYPE_FEET
        0.33f, // INVTYPE_WRISTS
        0.33f, // INVTYPE_HANDS
        0.00f, // INVTYPE_FINGER
        0.00f, // INVTYPE_TRINKET
        0.00f, // INVTYPE_WEAPON
        0.72f, // INVTYPE_SHIELD
        0.00f, // INVTYPE_RANGED
        0.00f, // INVTYPE_CLOAK
        0.00f, // INVTYPE_2HWEAPON
        0.00f, // INVTYPE_BAG
        0.00f, // INVTYPE_TABARD
        1.00f, // INVTYPE_ROBE
        0.00f, // INVTYPE_WEAPONMAINHAND
        0.00f, // INVTYPE_WEAPONOFFHAND
        0.00f, // INVTYPE_HOLDABLE
        0.00f, // INVTYPE_AMMO
        0.00f, // INVTYPE_THROWN
        0.00f, // INVTYPE_RANGEDRIGHT
        0.00f, // INVTYPE_QUIVER
        0.00f, // INVTYPE_RELIC
        0.00f, // INVTYPE_PROFESSION_TOOL
        0.00f, // INVTYPE_PROFESSION_GEAR
        0.00f, // INVTYPE_EQUIPABLE_SPELL_OFFENSIVE
        0.00f, // INVTYPE_EQUIPABLE_SPELL_UTILITY
        0.00f, // INVTYPE_EQUIPABLE_SPELL_DEFENSIVE
        0.00f, // INVTYPE_EQUIPABLE_SPELL_MOBILITY
    };

    static float const weaponMultipliers[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        0.91f, // ITEM_SUBCLASS_WEAPON_AXE
        1.00f, // ITEM_SUBCLASS_WEAPON_AXE2
        1.00f, // ITEM_SUBCLASS_WEAPON_BOW
        1.00f, // ITEM_SUBCLASS_WEAPON_GUN
        0.91f, // ITEM_SUBCLASS_WEAPON_MACE
        1.00f, // ITEM_SUBCLASS_WEAPON_MACE2
        1.00f, // ITEM_SUBCLASS_WEAPON_POLEARM
        0.91f, // ITEM_SUBCLASS_WEAPON_SWORD
        1.00f, // ITEM_SUBCLASS_WEAPON_SWORD2
        1.00f, // ITEM_SUBCLASS_WEAPON_WARGLAIVES
        1.00f, // ITEM_SUBCLASS_WEAPON_STAFF
        0.00f, // ITEM_SUBCLASS_WEAPON_EXOTIC
        0.00f, // ITEM_SUBCLASS_WEAPON_EXOTIC2
        0.66f, // ITEM_SUBCLASS_WEAPON_FIST_WEAPON
        0.00f, // ITEM_SUBCLASS_WEAPON_MISCELLANEOUS
        0.66f, // ITEM_SUBCLASS_WEAPON_DAGGER
        0.00f, // ITEM_SUBCLASS_WEAPON_THROWN
        0.00f, // ITEM_SUBCLASS_WEAPON_SPEAR
        1.00f, // ITEM_SUBCLASS_WEAPON_CROSSBOW
        0.66f, // ITEM_SUBCLASS_WEAPON_WAND
        0.66f, // ITEM_SUBCLASS_WEAPON_FISHING_POLE
    };

    float levelPenalty = 1.0f;
    if (itemLevel <= 28)
        levelPenalty = 0.966f - float(28u - itemLevel) / 54.0f;

    if (itemClass == ITEM_CLASS_ARMOR)
    {
        if (inventoryType > INVTYPE_ROBE)
            return 0;

        return 5 * uint32(round(25.0f * qualityMultipliers[quality] * armorMultipliers[inventoryType] * levelPenalty));
    }

    return 5 * uint32(round(18.0f * qualityMultipliers[quality] * weaponMultipliers[itemSubClass] * levelPenalty));
};

struct ItemSpecStats
{
    uint32 ItemType;
    uint32 ItemSpecStatTypes[MAX_ITEM_PROTO_STATS];
    uint32 ItemSpecStatCount;

    ItemSpecStats(ItemEntry const* item, ItemSparseEntry const* sparse) : ItemType(0), ItemSpecStatCount(0)
    {
        memset(ItemSpecStatTypes, -1, sizeof(ItemSpecStatTypes));

        if (item->ClassID == ITEM_CLASS_WEAPON)
        {
            ItemType = 5;
            switch (item->SubclassID)
            {
                case ITEM_SUBCLASS_WEAPON_AXE:
                    AddStat(ITEM_SPEC_STAT_ONE_HANDED_AXE);
                    break;
                case ITEM_SUBCLASS_WEAPON_AXE2:
                    AddStat(ITEM_SPEC_STAT_TWO_HANDED_AXE);
                    break;
                case ITEM_SUBCLASS_WEAPON_BOW:
                    AddStat(ITEM_SPEC_STAT_BOW);
                    break;
                case ITEM_SUBCLASS_WEAPON_GUN:
                    AddStat(ITEM_SPEC_STAT_GUN);
                    break;
                case ITEM_SUBCLASS_WEAPON_MACE:
                    AddStat(ITEM_SPEC_STAT_ONE_HANDED_MACE);
                    break;
                case ITEM_SUBCLASS_WEAPON_MACE2:
                    AddStat(ITEM_SPEC_STAT_TWO_HANDED_MACE);
                    break;
                case ITEM_SUBCLASS_WEAPON_POLEARM:
                    AddStat(ITEM_SPEC_STAT_POLEARM);
                    break;
                case ITEM_SUBCLASS_WEAPON_SWORD:
                    AddStat(ITEM_SPEC_STAT_ONE_HANDED_SWORD);
                    break;
                case ITEM_SUBCLASS_WEAPON_SWORD2:
                    AddStat(ITEM_SPEC_STAT_TWO_HANDED_SWORD);
                    break;
                case ITEM_SUBCLASS_WEAPON_WARGLAIVES:
                    AddStat(ITEM_SPEC_STAT_WARGLAIVES);
                    break;
                case ITEM_SUBCLASS_WEAPON_STAFF:
                    AddStat(ITEM_SPEC_STAT_STAFF);
                    break;
                case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                    AddStat(ITEM_SPEC_STAT_FIST_WEAPON);
                    break;
                case ITEM_SUBCLASS_WEAPON_DAGGER:
                    AddStat(ITEM_SPEC_STAT_DAGGER);
                    break;
                case ITEM_SUBCLASS_WEAPON_THROWN:
                    AddStat(ITEM_SPEC_STAT_THROWN);
                    break;
                case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    AddStat(ITEM_SPEC_STAT_CROSSBOW);
                    break;
                case ITEM_SUBCLASS_WEAPON_WAND:
                    AddStat(ITEM_SPEC_STAT_WAND);
                    break;
                default:
                    break;
            }
        }
        else if (item->ClassID == ITEM_CLASS_ARMOR)
        {
            switch (item->SubclassID)
            {
                case ITEM_SUBCLASS_ARMOR_CLOTH:
                    if (sparse->InventoryType != INVTYPE_CLOAK)
                    {
                        ItemType = 1;
                        break;
                    }

                    ItemType = 0;
                    AddStat(ITEM_SPEC_STAT_CLOAK);
                    break;
                case ITEM_SUBCLASS_ARMOR_LEATHER:
                    ItemType = 2;
                    break;
                case ITEM_SUBCLASS_ARMOR_MAIL:
                    ItemType = 3;
                    break;
                case ITEM_SUBCLASS_ARMOR_PLATE:
                    ItemType = 4;
                    break;
                default:
                    if (item->SubclassID == ITEM_SUBCLASS_ARMOR_SHIELD)
                    {
                        ItemType = 6;
                        AddStat(ITEM_SPEC_STAT_SHIELD);
                    }
                    else if (item->SubclassID > ITEM_SUBCLASS_ARMOR_SHIELD && item->SubclassID <= ITEM_SUBCLASS_ARMOR_RELIC)
                    {
                        ItemType = 6;
                        AddStat(ITEM_SPEC_STAT_RELIC);
                    }
                    else
                        ItemType = 0;
                    break;
            }
        }
        else if (item->ClassID == ITEM_CLASS_GEM)
        {
            ItemType = 7;
            if (GemPropertiesEntry const* gem = sGemPropertiesStore.LookupEntry(sparse->GemProperties))
            {
                if (gem->Type & SOCKET_COLOR_RELIC_IRON)
                    AddStat(ITEM_SPEC_STAT_RELIC_IRON);
                if (gem->Type & SOCKET_COLOR_RELIC_BLOOD)
                    AddStat(ITEM_SPEC_STAT_RELIC_BLOOD);
                if (gem->Type & SOCKET_COLOR_RELIC_SHADOW)
                    AddStat(ITEM_SPEC_STAT_RELIC_SHADOW);
                if (gem->Type & SOCKET_COLOR_RELIC_FEL)
                    AddStat(ITEM_SPEC_STAT_RELIC_FEL);
                if (gem->Type & SOCKET_COLOR_RELIC_ARCANE)
                    AddStat(ITEM_SPEC_STAT_RELIC_ARCANE);
                if (gem->Type & SOCKET_COLOR_RELIC_FROST)
                    AddStat(ITEM_SPEC_STAT_RELIC_FROST);
                if (gem->Type & SOCKET_COLOR_RELIC_FIRE)
                    AddStat(ITEM_SPEC_STAT_RELIC_FIRE);
                if (gem->Type & SOCKET_COLOR_RELIC_WATER)
                    AddStat(ITEM_SPEC_STAT_RELIC_WATER);
                if (gem->Type & SOCKET_COLOR_RELIC_LIFE)
                    AddStat(ITEM_SPEC_STAT_RELIC_LIFE);
                if (gem->Type & SOCKET_COLOR_RELIC_WIND)
                    AddStat(ITEM_SPEC_STAT_RELIC_WIND);
                if (gem->Type & SOCKET_COLOR_RELIC_HOLY)
                    AddStat(ITEM_SPEC_STAT_RELIC_HOLY);
            }
        }
        else
            ItemType = 0;

        for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
            if (sparse->StatModifierBonusStat[i] != -1)
                AddModStat(sparse->StatModifierBonusStat[i]);
    }

    void AddStat(ItemSpecStat statType)
    {
        if (ItemSpecStatCount >= MAX_ITEM_PROTO_STATS)
            return;

        for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
            if (ItemSpecStatTypes[i] == uint32(statType))
                return;

        ItemSpecStatTypes[ItemSpecStatCount++] = statType;
    }

    void AddModStat(int32 itemStatType)
    {
        switch (itemStatType)
        {
            case ITEM_MOD_AGILITY:
                AddStat(ITEM_SPEC_STAT_AGILITY);
                break;
            case ITEM_MOD_STRENGTH:
                AddStat(ITEM_SPEC_STAT_STRENGTH);
                break;
            case ITEM_MOD_INTELLECT:
                AddStat(ITEM_SPEC_STAT_INTELLECT);
                break;
            case ITEM_MOD_DODGE_RATING:
                AddStat(ITEM_SPEC_STAT_DODGE);
                break;
            case ITEM_MOD_PARRY_RATING:
                AddStat(ITEM_SPEC_STAT_PARRY);
                break;
            case ITEM_MOD_CRIT_MELEE_RATING:
            case ITEM_MOD_CRIT_RANGED_RATING:
            case ITEM_MOD_CRIT_SPELL_RATING:
            case ITEM_MOD_CRIT_RATING:
                AddStat(ITEM_SPEC_STAT_CRIT);
                break;
            case ITEM_MOD_HASTE_RATING:
                AddStat(ITEM_SPEC_STAT_HASTE);
                break;
            case ITEM_MOD_HIT_RATING:
                AddStat(ITEM_SPEC_STAT_HIT);
                break;
            case ITEM_MOD_EXTRA_ARMOR:
                AddStat(ITEM_SPEC_STAT_BONUS_ARMOR);
                break;
            case ITEM_MOD_AGI_STR_INT:
                AddStat(ITEM_SPEC_STAT_AGILITY);
                AddStat(ITEM_SPEC_STAT_STRENGTH);
                AddStat(ITEM_SPEC_STAT_INTELLECT);
                break;
            case ITEM_MOD_AGI_STR:
                AddStat(ITEM_SPEC_STAT_AGILITY);
                AddStat(ITEM_SPEC_STAT_STRENGTH);
                break;
            case ITEM_MOD_AGI_INT:
                AddStat(ITEM_SPEC_STAT_AGILITY);
                AddStat(ITEM_SPEC_STAT_INTELLECT);
                break;
            case ITEM_MOD_STR_INT:
                AddStat(ITEM_SPEC_STAT_STRENGTH);
                AddStat(ITEM_SPEC_STAT_INTELLECT);
                break;
        }
    }
};

void ObjectMgr::LoadItemTemplates()
{
    uint32 oldMSTime = getMSTime();

    for (ItemSparseEntry const* sparse : sItemSparseStore)
    {
        ItemEntry const* db2Data = sItemStore.LookupEntry(sparse->ID);
        if (!db2Data)
            continue;

        ItemTemplate& itemTemplate = _itemTemplateStore[sparse->ID];

        itemTemplate.BasicData = db2Data;
        itemTemplate.ExtendedData = sparse;

        itemTemplate.MaxDurability = FillMaxDurability(db2Data->ClassID, db2Data->SubclassID, sparse->InventoryType, sparse->OverallQualityID, sparse->ItemLevel);
        itemTemplate.ScriptId = 0;
        itemTemplate.FoodType = 0;
        itemTemplate.MinMoneyLoot = 0;
        itemTemplate.MaxMoneyLoot = 0;
        itemTemplate.FlagsCu = 0;
        itemTemplate.SpellPPMRate = 0.0f;
        itemTemplate.RandomBonusListTemplateId = 0;
        itemTemplate.ItemSpecClassMask = 0;
        itemTemplate.QuestLogItemId = 0;

        if (std::vector<ItemSpecOverrideEntry const*> const* itemSpecOverrides = sDB2Manager.GetItemSpecOverrides(sparse->ID))
        {
            for (ItemSpecOverrideEntry const* itemSpecOverride : *itemSpecOverrides)
            {
                if (ChrSpecializationEntry const* specialization = sChrSpecializationStore.LookupEntry(itemSpecOverride->SpecID))
                {
                    itemTemplate.ItemSpecClassMask |= 1 << (specialization->ClassID - 1);
                    itemTemplate.Specializations[0].set(ItemTemplate::CalculateItemSpecBit(specialization));
                    itemTemplate.Specializations[1] |= itemTemplate.Specializations[0];
                    itemTemplate.Specializations[2] |= itemTemplate.Specializations[0];
                }
            }
        }
        else
        {
            ItemSpecStats itemSpecStats(db2Data, sparse);

            for (ItemSpecEntry const* itemSpec : sItemSpecStore)
            {
                if (itemSpecStats.ItemType != itemSpec->ItemType)
                    continue;

                bool hasPrimary = itemSpec->PrimaryStat == ITEM_SPEC_STAT_NONE;
                bool hasSecondary = itemSpec->SecondaryStat == ITEM_SPEC_STAT_NONE;
                for (uint32 i = 0; i < itemSpecStats.ItemSpecStatCount; ++i)
                {
                    if (itemSpecStats.ItemSpecStatTypes[i] == itemSpec->PrimaryStat)
                        hasPrimary = true;
                    if (itemSpecStats.ItemSpecStatTypes[i] == itemSpec->SecondaryStat)
                        hasSecondary = true;
                }

                if (!hasPrimary || !hasSecondary)
                    continue;

                if (ChrSpecializationEntry const* specialization = sChrSpecializationStore.LookupEntry(itemSpec->SpecializationID))
                {
                    if ((1 << (specialization->ClassID - 1)) & sparse->AllowableClass)
                    {
                        itemTemplate.ItemSpecClassMask |= 1 << (specialization->ClassID - 1);
                        std::size_t specBit = ItemTemplate::CalculateItemSpecBit(specialization);
                        itemTemplate.Specializations[0].set(specBit);
                        if (itemSpec->MaxLevel > 40)
                            itemTemplate.Specializations[1].set(specBit);
                        if (itemSpec->MaxLevel >= 110)
                            itemTemplate.Specializations[2].set(specBit);
                    }
                }
            }
        }

        // Items that have no specializations set can be used by everyone
        for (auto& specs : itemTemplate.Specializations)
            if (specs.count() == 0)
                specs.set();
    }

    // Load item effects (spells)
    for (ItemXItemEffectEntry const* effectEntry : sItemXItemEffectStore)
        if (ItemTemplate* item = Trinity::Containers::MapGetValuePtr(_itemTemplateStore, effectEntry->ItemID))
            if (ItemEffectEntry const* effect = sItemEffectStore.LookupEntry(effectEntry->ItemEffectID))
                item->Effects.push_back(effect);

    TC_LOG_INFO("server.loading", ">> Loaded {} item templates in {} ms", _itemTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadItemTemplateAddon()
{
    uint32 oldMSTime = getMSTime();
    uint32 count = 0;

    QueryResult result = WorldDatabase.Query("SELECT Id, FlagsCu, FoodType, MinMoneyLoot, MaxMoneyLoot, SpellPPMChance, RandomBonusListTemplateId, QuestLogItemId FROM item_template_addon");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 itemId = fields[0].GetUInt32();
            ItemTemplate* itemTemplate = const_cast<ItemTemplate*>(GetItemTemplate(itemId));
            if (!itemTemplate)
            {
                TC_LOG_ERROR("sql.sql", "Item {} specified in `item_template_addon` does not exist, skipped.", itemId);
                continue;
            }

            uint32 minMoneyLoot = fields[3].GetUInt32();
            uint32 maxMoneyLoot = fields[4].GetUInt32();
            if (minMoneyLoot > maxMoneyLoot)
            {
                TC_LOG_ERROR("sql.sql", "Minimum money loot specified in `item_template_addon` for item {} was greater than maximum amount, swapping.", itemId);
                std::swap(minMoneyLoot, maxMoneyLoot);
            }
            itemTemplate->FlagsCu = fields[1].GetUInt32();
            itemTemplate->FoodType = fields[2].GetUInt8();
            itemTemplate->MinMoneyLoot = minMoneyLoot;
            itemTemplate->MaxMoneyLoot = maxMoneyLoot;
            itemTemplate->SpellPPMRate = fields[5].GetFloat();
            itemTemplate->RandomBonusListTemplateId = fields[6].GetUInt32();
            itemTemplate->QuestLogItemId = fields[7].GetInt32();
            ++count;
        } while (result->NextRow());
    }
    TC_LOG_INFO("server.loading", ">> Loaded {} item addon templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadItemScriptNames()
{
    uint32 oldMSTime = getMSTime();
    uint32 count = 0;

    QueryResult result = WorldDatabase.Query("SELECT Id, ScriptName FROM item_script_names");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 itemId = fields[0].GetUInt32();
            ItemTemplate* itemTemplate = const_cast<ItemTemplate*>(GetItemTemplate(itemId));
            if (!itemTemplate)
            {
                TC_LOG_ERROR("sql.sql", "Item {} specified in `item_script_names` does not exist, skipped.", itemId);
                continue;
            }

            itemTemplate->ScriptId = GetScriptId(fields[1].GetString());
            ++count;
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} item script names in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

ItemTemplate const* ObjectMgr::GetItemTemplate(uint32 entry) const
{
    return Trinity::Containers::MapGetValuePtr(_itemTemplateStore, entry);
}

void ObjectMgr::LoadVehicleTemplateAccessories()
{
    uint32 oldMSTime = getMSTime();

    _vehicleTemplateAccessoryStore.clear();                           // needed for reload case

    uint32 count = 0;

    //                                                  0             1              2          3           4             5
    QueryResult result = WorldDatabase.Query("SELECT `entry`, `accessory_entry`, `seat_id`, `minion`, `summontype`, `summontimer` FROM `vehicle_template_accessory`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 vehicle template accessories. DB table `vehicle_template_accessory` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 entry        = fields[0].GetUInt32();
        uint32 accessory    = fields[1].GetUInt32();
        int8   seatId       = fields[2].GetInt8();
        bool   isMinion     = fields[3].GetBool();
        uint8  summonType   = fields[4].GetUInt8();
        uint32 summonTimer  = fields[5].GetUInt32();

        if (!GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template_accessory`: creature template entry {} does not exist.", entry);
            continue;
        }

        if (!GetCreatureTemplate(accessory))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template_accessory`: Accessory {} does not exist.", accessory);
            continue;
        }

        if (_spellClickInfoStore.find(entry) == _spellClickInfoStore.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template_accessory`: creature template entry {} has no data in npc_spellclick_spells", entry);
            continue;
        }

        _vehicleTemplateAccessoryStore[entry].push_back(VehicleAccessory(accessory, seatId, isMinion, summonType, summonTimer));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Vehicle Template Accessories in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadVehicleTemplate()
{
    uint32 oldMSTime = getMSTime();

    _vehicleTemplateStore.clear();

    //                                               0           1
    QueryResult result = WorldDatabase.Query("SELECT creatureId, despawnDelayMs FROM vehicle_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 vehicle template. DB table `vehicle_template` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 creatureId = fields[0].GetUInt32();

        if (!GetCreatureTemplate(creatureId))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template`: Vehicle {} does not exist.", creatureId);
            continue;
        }

        VehicleTemplate& vehicleTemplate = _vehicleTemplateStore[creatureId];
        vehicleTemplate.DespawnDelay = Milliseconds(fields[1].GetInt32());

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Vehicle Template entries in {} ms", _vehicleTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadVehicleAccessories()
{
    uint32 oldMSTime = getMSTime();

    _vehicleAccessoryStore.clear();                           // needed for reload case

    uint32 count = 0;

    //                                                  0             1             2          3           4             5
    QueryResult result = WorldDatabase.Query("SELECT `guid`, `accessory_entry`, `seat_id`, `minion`, `summontype`, `summontimer` FROM `vehicle_accessory`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Vehicle Accessories in {} ms", GetMSTimeDiffToNow(oldMSTime));
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType uiGUID = fields[0].GetUInt64();
        uint32 uiAccessory  = fields[1].GetUInt32();
        int8   uiSeat       = int8(fields[2].GetInt16());
        bool   bMinion      = fields[3].GetBool();
        uint8  uiSummonType = fields[4].GetUInt8();
        uint32 uiSummonTimer= fields[5].GetUInt32();

        if (!GetCreatureTemplate(uiAccessory))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_accessory`: Accessory {} does not exist.", uiAccessory);
            continue;
        }

        _vehicleAccessoryStore[uiGUID].push_back(VehicleAccessory(uiAccessory, uiSeat, bMinion, uiSummonType, uiSummonTimer));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Vehicle Accessories in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadVehicleSeatAddon()
{
    uint32 oldMSTime = getMSTime();

    _vehicleSeatAddonStore.clear();                           // needed for reload case

    uint32 count = 0;

    //                                                0            1                  2             3             4             5             6
    QueryResult result = WorldDatabase.Query("SELECT `SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue` FROM `vehicle_seat_addon`");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 vehicle seat addons. DB table `vehicle_seat_addon` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 seatID = fields[0].GetUInt32();
        float orientation = fields[1].GetFloat();
        float exitX = fields[2].GetFloat();
        float exitY = fields[3].GetFloat();
        float exitZ = fields[4].GetFloat();
        float exitO = fields[5].GetFloat();
        uint8 exitParam = fields[6].GetUInt8();

        if (!sVehicleSeatStore.LookupEntry(seatID))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_seat_addon`: SeatID: {} does not exist in VehicleSeat.dbc. Skipping entry.", seatID);
            continue;
        }

        // Sanitizing values
        if (orientation > float(M_PI * 2))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_seat_addon`: SeatID: {} is using invalid angle offset value ({}). Set Value to 0.", seatID, orientation);
            orientation = 0.0f;
        }

        if (exitParam >= AsUnderlyingType(VehicleExitParameters::VehicleExitParamMax))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_seat_addon`: SeatID: {} is using invalid exit parameter value ({}). Setting to 0 (none).", seatID, exitParam);
            continue;
        }

        _vehicleSeatAddonStore[seatID] = VehicleSeatAddon(orientation, exitX, exitY, exitZ, exitO, exitParam);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Vehicle Seat Addon entries in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPetLevelInfo()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0               1      2   3     4    5    6    7     8    9
    QueryResult result = WorldDatabase.Query("SELECT creature_entry, level, hp, mana, str, agi, sta, inte, spi, armor FROM pet_levelstats");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 level pet stats definitions. DB table `pet_levelstats` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 creature_id = fields[0].GetUInt32();
        if (!GetCreatureTemplate(creature_id))
        {
            TC_LOG_ERROR("sql.sql", "Wrong creature id {} in `pet_levelstats` table, ignoring.", creature_id);
            continue;
        }

        uint32 current_level = fields[1].GetUInt8();
        if (current_level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            if (current_level > STRONG_MAX_LEVEL)        // hardcoded level maximum
                TC_LOG_ERROR("sql.sql", "Wrong (> {}) level {} in `pet_levelstats` table, ignoring.", STRONG_MAX_LEVEL, current_level);
            else
            {
                TC_LOG_INFO("misc", "Unused (> MaxPlayerLevel in worldserver.conf) level {} in `pet_levelstats` table, ignoring.", current_level);
                ++count;                                // make result loading percent "expected" correct in case disabled detail mode for example.
            }
            continue;
        }
        else if (current_level < 1)
        {
            TC_LOG_ERROR("sql.sql", "Wrong (<1) level {} in `pet_levelstats` table, ignoring.", current_level);
            continue;
        }

        auto& pInfoMapEntry = _petInfoStore[creature_id];
        if (!pInfoMapEntry)
            pInfoMapEntry = std::make_unique<PetLevelInfo[]>(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));

        // data for level 1 stored in [0] array element, ...
        PetLevelInfo* pLevelInfo = &pInfoMapEntry[current_level - 1];

        pLevelInfo->health = fields[2].GetUInt16();
        pLevelInfo->mana   = fields[3].GetUInt16();
        pLevelInfo->armor  = fields[9].GetUInt32();

        for (uint8 i = 0; i < MAX_STATS; i++)
            pLevelInfo->stats[i] = fields[i + 4].GetUInt16();

        ++count;
    }
    while (result->NextRow());

    // Fill gaps and check integrity
    for (PetLevelInfoContainer::iterator itr = _petInfoStore.begin(); itr != _petInfoStore.end(); ++itr)
    {
        auto& pInfo = itr->second;

        // fatal error if no level 1 data
        if (!pInfo || pInfo[0].health == 0)
        {
            TC_LOG_ERROR("sql.sql", "Creature {} does not have pet stats data for Level 1!", itr->first);
            ABORT();
        }

        // fill level gaps
        for (uint8 level = 1; level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL); ++level)
        {
            if (pInfo[level].health == 0)
            {
                TC_LOG_ERROR("sql.sql", "Creature {} has no data for Level {} pet stats data, using data of Level {}.", itr->first, level + 1, level);
                pInfo[level] = pInfo[level - 1];
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} level pet stats definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

PetLevelInfo const* ObjectMgr::GetPetLevelInfo(uint32 creature_id, uint8 level) const
{
    if (level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        level = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);

    auto itr = _petInfoStore.find(creature_id);
    if (itr == _petInfoStore.end())
        return nullptr;

    return &itr->second[level - 1];                         // data for level 1 stored in [0] array element, ...
}

void ObjectMgr::PlayerCreateInfoAddItemHelper(uint32 race_, uint32 class_, uint32 itemId, int32 count)
{
    std::unique_ptr<PlayerInfo>* playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(race_), Classes(class_) });
    if (!playerInfo)
        return;

    if (count > 0)
        playerInfo->get()->item.emplace_back(itemId, count);
    else
    {
        if (count < -1)
            TC_LOG_ERROR("sql.sql", "Invalid count {} specified on item {} be removed from original player create info (use -1)!", count, itemId);

        PlayerCreateInfoItems& items = playerInfo->get()->item;

        auto erased = std::remove_if(items.begin(), items.end(), [itemId](PlayerCreateInfoItem const& item) { return item.item_id == itemId; });
        if (erased == items.end())
        {
            TC_LOG_ERROR("sql.sql", "Item {} specified to be removed from original create info not found in db2!", itemId);
            return;
        }

        items.erase(erased, items.end());
    }
}

void ObjectMgr::LoadPlayerInfo()
{
    // Load playercreate
    {
        uint32 oldMSTime = getMSTime();
        //                                                0     1      2       3           4           5           6           7           8               9               10              11                 12                13              14                15
        QueryResult result = WorldDatabase.Query("SELECT race, class, map, position_x, position_y, position_z, orientation, npe_map, npe_position_x, npe_position_y, npe_position_z, npe_orientation, npe_transport_guid, intro_movie_id, intro_scene_id, npe_intro_scene_id FROM playercreateinfo");

        if (!result)
        {
            TC_LOG_ERROR("server.loading", ">> Loaded 0 player create definitions. DB table `playercreateinfo` is empty.");
            ABORT();
        }
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields = result->Fetch();

                uint32 current_race  = fields[0].GetUInt8();
                uint32 current_class = fields[1].GetUInt8();
                uint32 mapId         = fields[2].GetUInt16();
                float  positionX     = fields[3].GetFloat();
                float  positionY     = fields[4].GetFloat();
                float  positionZ     = fields[5].GetFloat();
                float  orientation   = fields[6].GetFloat();

                if (!sChrRacesStore.LookupEntry(current_race))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race {} in `playercreateinfo` table, ignoring.", current_race);
                    continue;
                }

                if (!sChrClassesStore.LookupEntry(current_class))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class {} in `playercreateinfo` table, ignoring.", current_class);
                    continue;
                }

                // accept DB data only for valid position (and non instanceable)
                if (!MapManager::IsValidMapCoord(mapId, positionX, positionY, positionZ, orientation))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong home position for class {} race {} pair in `playercreateinfo` table, ignoring.", current_class, current_race);
                    continue;
                }

                if (sMapStore.LookupEntry(mapId)->Instanceable())
                {
                    TC_LOG_ERROR("sql.sql", "Home position in instanceable map for class {} race {} pair in `playercreateinfo` table, ignoring.", current_class, current_race);
                    continue;
                }

                if (!sDB2Manager.GetChrModel(current_race, GENDER_MALE))
                {
                    TC_LOG_ERROR("sql.sql", "Missing male model for race {}, ignoring.", current_race);
                    continue;
                }

                if (!sDB2Manager.GetChrModel(current_race, GENDER_FEMALE))
                {
                    TC_LOG_ERROR("sql.sql", "Missing female model for race {}, ignoring.", current_race);
                    continue;
                }

                std::unique_ptr<PlayerInfo> info = std::make_unique<PlayerInfo>();
                info->createPosition.Loc.WorldRelocate(mapId, positionX, positionY, positionZ, orientation);

                if (std::none_of(fields + 7, fields + 12, [](Field const& field) { return field.IsNull(); }))
                {
                    info->createPositionNPE.emplace();

                    info->createPositionNPE->Loc.WorldRelocate(fields[7].GetUInt32(), fields[8].GetFloat(), fields[9].GetFloat(), fields[10].GetFloat(), fields[11].GetFloat());
                    if (!fields[12].IsNull())
                        info->createPositionNPE->TransportGuid = fields[12].GetUInt64();

                    if (!sMapStore.LookupEntry(info->createPositionNPE->Loc.GetMapId()))
                    {
                        TC_LOG_ERROR("sql.sql", "Invalid NPE map id {} for class {} race {} pair in `playercreateinfo` table, ignoring.",
                            info->createPositionNPE->Loc.GetMapId(), current_class, current_race);
                        info->createPositionNPE.reset();
                    }

                    if (info->createPositionNPE && info->createPositionNPE->TransportGuid && !sTransportMgr->GetTransportSpawn(*info->createPositionNPE->TransportGuid))
                    {
                        TC_LOG_ERROR("sql.sql", "Invalid NPE transport spawn id {} for class {} race {} pair in `playercreateinfo` table, ignoring.",
                            *info->createPositionNPE->TransportGuid, current_class, current_race);
                        info->createPositionNPE.reset(); // remove entire NPE data - assume user put transport offsets into npe_position fields
                    }
                }

                if (!fields[13].IsNull())
                {
                    uint32 introMovieId = fields[13].GetUInt32();
                    if (sMovieStore.LookupEntry(introMovieId))
                        info->introMovieId = introMovieId;
                    else
                        TC_LOG_ERROR("sql.sql", "Invalid intro movie id {} for class {} race {} pair in `playercreateinfo` table, ignoring.",
                            introMovieId, current_class, current_race);
                }

                if (!fields[14].IsNull())
                {
                    uint32 introSceneId = fields[14].GetUInt32();
                    if (GetSceneTemplate(introSceneId))
                        info->introSceneId = introSceneId;
                    else
                        TC_LOG_ERROR("sql.sql", "Invalid intro scene id {} for class {} race {} pair in `playercreateinfo` table, ignoring.",
                            introSceneId, current_class, current_race);
                }

                if (!fields[15].IsNull())
                {
                    uint32 introSceneId = fields[15].GetUInt32();
                    if (GetSceneTemplate(introSceneId))
                        info->introSceneIdNPE = introSceneId;
                    else
                        TC_LOG_ERROR("sql.sql", "Invalid NPE intro scene id {} for class {} race {} pair in `playercreateinfo` table, ignoring.",
                            introSceneId, current_class, current_race);
                }

                _playerInfo[{ Races(current_race), Classes(current_class) }] = std::move(info);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded {} player create definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate items
    TC_LOG_INFO("server.loading", "Loading Player Create Items Data...");
    {
        std::unordered_map<uint32, std::vector<ItemTemplate const*>> itemsByCharacterLoadout;
        for (CharacterLoadoutItemEntry const* characterLoadoutItem : sCharacterLoadoutItemStore)
            if (ItemTemplate const* itemTemplate = GetItemTemplate(characterLoadoutItem->ItemID))
                itemsByCharacterLoadout[characterLoadoutItem->CharacterLoadoutID].push_back(itemTemplate);

        for (CharacterLoadoutEntry const* characterLoadout : sCharacterLoadoutStore)
        {
            if (!characterLoadout->IsForNewCharacter())
                continue;

            std::vector<ItemTemplate const*> const* items = Trinity::Containers::MapGetValuePtr(itemsByCharacterLoadout, characterLoadout->ID);
            if (!items)
                continue;

            for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
            {
                if (!characterLoadout->RaceMask.HasRace(raceIndex))
                    continue;

                if (auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(raceIndex), Classes(characterLoadout->ChrClassID) }))
                {
                    playerInfo->get()->itemContext = ItemContext(characterLoadout->ItemContext);

                    for (ItemTemplate const* itemTemplate : *items)
                    {
                        // BuyCount by default
                        uint32 count = itemTemplate->GetBuyCount();

                        // special amount for food/drink
                        if (itemTemplate->GetClass() == ITEM_CLASS_CONSUMABLE && itemTemplate->GetSubClass() == ITEM_SUBCLASS_FOOD_DRINK)
                        {
                            if (!itemTemplate->Effects.empty())
                            {
                                switch (itemTemplate->Effects[0]->SpellCategoryID)
                                {
                                    case SPELL_CATEGORY_FOOD:                                // food
                                        count = characterLoadout->ChrClassID == CLASS_DEATH_KNIGHT ? 10 : 4;
                                        break;
                                    case SPELL_CATEGORY_DRINK:                                // drink
                                        count = 2;
                                        break;
                                }
                            }
                            if (itemTemplate->GetMaxStackSize() < count)
                                count = itemTemplate->GetMaxStackSize();
                        }

                        playerInfo->get()->item.emplace_back(itemTemplate->GetId(), count);
                    }
                }
            }
        }
    }

    TC_LOG_INFO("server.loading", "Loading Player Create Items Override Data...");
    {
        uint32 oldMSTime = getMSTime();
        //                                                0     1      2       3
        QueryResult result = WorldDatabase.Query("SELECT race, class, itemid, amount FROM playercreateinfo_item");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 custom player create items. DB table `playercreateinfo_item` is empty.");
        }
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields = result->Fetch();

                uint32 current_race = fields[0].GetUInt8();
                if (current_race >= MAX_RACES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race {} in `playercreateinfo_item` table, ignoring.", current_race);
                    continue;
                }

                uint32 current_class = fields[1].GetUInt8();
                if (current_class >= MAX_CLASSES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class {} in `playercreateinfo_item` table, ignoring.", current_class);
                    continue;
                }

                uint32 item_id = fields[2].GetUInt32();

                if (!GetItemTemplate(item_id))
                {
                    TC_LOG_ERROR("sql.sql", "Item id {} (race {} class {}) in `playercreateinfo_item` table but it does not exist, ignoring.", item_id, current_race, current_class);
                    continue;
                }

                int32 amount   = fields[3].GetInt8();

                if (!amount)
                {
                    TC_LOG_ERROR("sql.sql", "Item id {} (class {} race {}) have amount == 0 in `playercreateinfo_item` table, ignoring.", item_id, current_race, current_class);
                    continue;
                }

                if (!current_race || !current_class)
                {
                    uint32 min_race = current_race ? current_race : 1;
                    uint32 max_race = current_race ? current_race + 1 : MAX_RACES;
                    uint32 min_class = current_class ? current_class : 1;
                    uint32 max_class = current_class ? current_class + 1 : MAX_CLASSES;
                    for (uint32 r = min_race; r < max_race; ++r)
                        for (uint32 c = min_class; c < max_class; ++c)
                            PlayerCreateInfoAddItemHelper(r, c, item_id, amount);
                }
                else
                    PlayerCreateInfoAddItemHelper(current_race, current_class, item_id, amount);

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded {} custom player create items in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate skills
    TC_LOG_INFO("server.loading", "Loading Player Create Skill Data...");
    {
        uint32 oldMSTime = getMSTime();

        for (SkillRaceClassInfoEntry const* rcInfo : sSkillRaceClassInfoStore)
            if (rcInfo->Availability == 1)
                for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
                    if (rcInfo->RaceMask.IsEmpty() || rcInfo->RaceMask.HasRace(raceIndex))
                        for (uint32 classIndex = CLASS_WARRIOR; classIndex < MAX_CLASSES; ++classIndex)
                            if (rcInfo->ClassMask == -1 || rcInfo->ClassMask == 0 || ((1 << (classIndex - 1)) & rcInfo->ClassMask))
                                if (auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(raceIndex), Classes(classIndex) }))
                                    playerInfo->get()->skills.push_back(rcInfo);

        TC_LOG_INFO("server.loading", ">> Loaded player create skills in {} ms", GetMSTimeDiffToNow(oldMSTime));
    }

    // Load playercreate custom spells
    TC_LOG_INFO("server.loading", "Loading Player Create Custom Spell Data...");
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.PQuery("SELECT racemask, classmask, Spell FROM playercreateinfo_spell_custom");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 player create custom spells. DB table `playercreateinfo_spell_custom` is empty.");
        }
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields = result->Fetch();
                Trinity::RaceMask<uint64> raceMask = { fields[0].GetUInt64() };
                uint32 classMask = fields[1].GetUInt32();
                uint32 spellId = fields[2].GetUInt32();

                if (!raceMask.IsEmpty() && (raceMask & RACEMASK_ALL_PLAYABLE).IsEmpty())
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race mask {} in `playercreateinfo_spell_custom` table, ignoring.", raceMask.RawValue);
                    continue;
                }

                if (classMask != 0 && !(classMask & CLASSMASK_ALL_PLAYABLE))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class mask {} in `playercreateinfo_spell_custom` table, ignoring.", classMask);
                    continue;
                }

                for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
                {
                    if (raceMask.IsEmpty() || raceMask.HasRace(raceIndex))
                    {
                        for (uint32 classIndex = CLASS_WARRIOR; classIndex < MAX_CLASSES; ++classIndex)
                        {
                            if (classMask == 0 || ((1 << (classIndex - 1)) & classMask))
                            {
                                if (auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(raceIndex), Classes(classIndex) }))
                                {
                                    playerInfo->get()->customSpells.push_back(spellId);
                                    ++count;
                                }
                                // We need something better here, the check is not accounting for spells used by multiple races/classes but not all of them.
                                // Either split the masks per class, or per race, which kind of kills the point yet.
                                // else if (raceMask != 0 && classMask != 0)
                                //     TC_LOG_ERROR("sql.sql", "Racemask/classmask ({}/{}) combination was found containing an invalid race/class combination ({}/{}) in `{}` (Spell {}), ignoring.", raceMask, classMask, raceIndex, classIndex, tableName, spellId);
                            }
                        }
                    }
                }
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded {} custom player create spells in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate cast spell
    TC_LOG_INFO("server.loading", "Loading Player Create Cast Spell Data...");
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.PQuery("SELECT raceMask, classMask, spell, createMode FROM playercreateinfo_cast_spell");

        if (!result)
            TC_LOG_INFO("server.loading", ">> Loaded 0 player create cast spells. DB table `playercreateinfo_cast_spell` is empty.");
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields       = result->Fetch();
                Trinity::RaceMask<uint64> raceMask = { fields[0].GetUInt64() };
                uint32 classMask    = fields[1].GetUInt32();
                uint32 spellId      = fields[2].GetUInt32();
                int8 playerCreateMode = fields[3].GetInt8();

                if (!raceMask.IsEmpty() && (raceMask & RACEMASK_ALL_PLAYABLE).IsEmpty())
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race mask {} in `playercreateinfo_cast_spell` table, ignoring.", raceMask.RawValue);
                    continue;
                }

                if (classMask != 0 && !(classMask & CLASSMASK_ALL_PLAYABLE))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class mask {} in `playercreateinfo_cast_spell` table, ignoring.", classMask);
                    continue;
                }

                if (playerCreateMode < 0 || playerCreateMode >= AsUnderlyingType(PlayerCreateMode::Max))
                {
                    TC_LOG_ERROR("sql.sql", "Uses invalid createMode {} in `playercreateinfo_cast_spell` table, ignoring.", playerCreateMode);
                    continue;
                }

                for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
                {
                    if (raceMask.IsEmpty() || raceMask.HasRace(raceIndex))
                    {
                        for (uint32 classIndex = CLASS_WARRIOR; classIndex < MAX_CLASSES; ++classIndex)
                        {
                            if (classMask == 0 || ((1 << (classIndex - 1)) & classMask))
                            {
                                if (auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(raceIndex), Classes(classIndex) }))
                                {
                                    playerInfo->get()->castSpells[playerCreateMode].push_back(spellId);
                                    ++count;
                                }
                            }
                        }
                    }
                }
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded {} player create cast spells in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate actions
    TC_LOG_INFO("server.loading", "Loading Player Create Action Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                0     1      2       3       4
        QueryResult result = WorldDatabase.Query("SELECT race, class, button, action, type FROM playercreateinfo_action");

        if (!result)
        {
            TC_LOG_INFO("server.loading", ">> Loaded 0 player create actions. DB table `playercreateinfo_action` is empty.");
        }
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields = result->Fetch();

                uint32 current_race = fields[0].GetUInt8();
                if (current_race >= MAX_RACES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race {} in `playercreateinfo_action` table, ignoring.", current_race);
                    continue;
                }

                uint32 current_class = fields[1].GetUInt8();
                if (current_class >= MAX_CLASSES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class {} in `playercreateinfo_action` table, ignoring.", current_class);
                    continue;
                }

                if (auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(current_race), Classes(current_class) }))
                    playerInfo->get()->action.push_back(PlayerCreateInfoAction(fields[2].GetUInt16(), fields[3].GetUInt32(), fields[4].GetUInt16()));

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded {} player create actions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Loading levels data (class/race dependent)
    TC_LOG_INFO("server.loading", "Loading Player Create Level Stats Data...");
    {
        struct RaceStats
        {
            std::array<int16, MAX_STATS> StatModifier = { };
        };

        std::array<RaceStats, MAX_RACES> raceStatModifiers = { };

        uint32 oldMSTime = getMSTime();

        QueryResult raceStatsResult = WorldDatabase.Query("SELECT race, str, agi, sta, inte FROM player_racestats");

        if (!raceStatsResult)
        {
            TC_LOG_ERROR("server.loading", ">> Loaded 0 race stats definitions. DB table `player_racestats` is empty.");
            ABORT();
        }

        do
        {
            Field* fields = raceStatsResult->Fetch();

            uint32 current_race = fields[0].GetUInt8();
            if (current_race >= MAX_RACES)
            {
                TC_LOG_ERROR("sql.sql", "Wrong race {} in `player_racestats` table, ignoring.", current_race);
                continue;
            }

            for (uint32 i = 0; i < MAX_STATS; ++i)
                raceStatModifiers[current_race].StatModifier[i] = fields[i + 1].GetInt16();

        } while (raceStatsResult->NextRow());

        //                                                  0      1     2    3    4    5
        QueryResult result  = WorldDatabase.Query("SELECT class, level, str, agi, sta, inte FROM player_classlevelstats");

        if (!result)
        {
            TC_LOG_ERROR("server.loading", ">> Loaded 0 level stats definitions. DB table `player_classlevelstats` is empty.");
            ABORT();
        }

        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            uint32 current_class = fields[0].GetUInt8();
            if (current_class >= MAX_CLASSES)
            {
                TC_LOG_ERROR("sql.sql", "Wrong class {} in `player_classlevelstats` table, ignoring.", current_class);
                continue;
            }

            uint32 current_level = fields[1].GetUInt8();
            if (current_level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            {
                if (current_level > STRONG_MAX_LEVEL)        // hardcoded level maximum
                    TC_LOG_ERROR("sql.sql", "Wrong (> {}) level {} in `player_classlevelstats` table, ignoring.", STRONG_MAX_LEVEL, current_level);
                else
                    TC_LOG_INFO("misc", "Unused (> MaxPlayerLevel in worldserver.conf) level {} in `player_classlevelstats` table, ignoring.", current_level);

                continue;
            }

            for (std::size_t race = 0; race < raceStatModifiers.size(); ++race)
            {
                if (auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(race), Classes(current_class) }))
                {
                    if (!playerInfo->get()->levelInfo)
                        playerInfo->get()->levelInfo = std::make_unique<PlayerLevelInfo[]>(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));

                    PlayerLevelInfo& levelInfo = playerInfo->get()->levelInfo[current_level - 1];
                    for (uint8 i = 0; i < MAX_STATS; ++i)
                        levelInfo.stats[i] = fields[i + 2].GetUInt16() + raceStatModifiers[race].StatModifier[i];
                }
            }

            ++count;
        }
        while (result->NextRow());

        // Fill gaps and check integrity
        for (uint8 race = 0; race < MAX_RACES; ++race)
        {
            // skip non existed races
            if (!sChrRacesStore.LookupEntry(race))
                continue;

            for (uint8 class_ = 0; class_ < MAX_CLASSES; ++class_)
            {
                // skip non existed classes
                if (!sChrClassesStore.LookupEntry(class_))
                    continue;

                auto const& playerInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(race), Classes(class_) });
                if (!playerInfo)
                    continue;

                // skip expansion races if not playing with expansion
                if (sWorld->getIntConfig(CONFIG_EXPANSION) < EXPANSION_THE_BURNING_CRUSADE && (race == RACE_BLOODELF || race == RACE_DRAENEI))
                    continue;

                // skip expansion classes if not playing with expansion
                if (sWorld->getIntConfig(CONFIG_EXPANSION) < EXPANSION_WRATH_OF_THE_LICH_KING && class_ == CLASS_DEATH_KNIGHT)
                    continue;

                // skip expansion races if not playing with expansion
                if (sWorld->getIntConfig(CONFIG_EXPANSION) < EXPANSION_CATACLYSM && (race == RACE_GOBLIN || race == RACE_WORGEN))
                    continue;

                if (sWorld->getIntConfig(CONFIG_EXPANSION) < EXPANSION_MISTS_OF_PANDARIA && (race == RACE_PANDAREN_NEUTRAL || race == RACE_PANDAREN_HORDE || race == RACE_PANDAREN_ALLIANCE))
                    continue;

                if (sWorld->getIntConfig(CONFIG_EXPANSION) < EXPANSION_LEGION && class_ == CLASS_DEMON_HUNTER)
                    continue;

                if (sWorld->getIntConfig(CONFIG_EXPANSION) < EXPANSION_DRAGONFLIGHT && class_ == CLASS_EVOKER)
                    continue;

                // fatal error if no level 1 data
                if (!playerInfo->get()->levelInfo || playerInfo->get()->levelInfo[0].stats[0] == 0)
                {
                    TC_LOG_ERROR("sql.sql", "Race {} Class {} Level 1 does not have stats data!", race, class_);
                    ABORT();
                }

                // fill level gaps
                for (uint8 level = 1; level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL); ++level)
                {
                    if (playerInfo->get()->levelInfo[level].stats[0] == 0)
                    {
                        TC_LOG_ERROR("sql.sql", "Race {} Class {} Level {} does not have stats data. Using stats data of level {}.", race, class_, level + 1, level);
                        playerInfo->get()->levelInfo[level] = playerInfo->get()->levelInfo[level - 1];
                    }
                }
            }
        }

        TC_LOG_INFO("server.loading", ">> Loaded {} level stats definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }

    // Loading xp per level data
    TC_LOG_INFO("server.loading", "Loading Player Create XP Data...");
    {
        uint32 oldMSTime = getMSTime();

        _playerXPperLevel.resize(sXpGameTable.GetTableRowCount(), 0);

        //                                               0      1
        QueryResult result = WorldDatabase.Query("SELECT Level, Experience FROM player_xp_for_level");

        // load the DBC's levels at first...
        for (uint32 level = 1; level < sXpGameTable.GetTableRowCount(); ++level)
            _playerXPperLevel[level] = sXpGameTable.GetRow(level)->Total;

        uint32 count = 0;

        // ...overwrite if needed (custom values)
        if (result)
        {
            do
            {
                Field* fields = result->Fetch();

                uint32 current_level = fields[0].GetUInt8();
                uint32 current_xp = fields[1].GetUInt32();

                if (current_level >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
                {
                    if (current_level > STRONG_MAX_LEVEL)        // hardcoded level maximum
                        TC_LOG_ERROR("sql.sql", "Wrong (> {}) level {} in `player_xp_for_level` table, ignoring.", STRONG_MAX_LEVEL, current_level);
                    else
                    {
                        TC_LOG_INFO("misc", "Unused (> MaxPlayerLevel in worldserver.conf) level {} in `player_xp_for_level` table, ignoring.", current_level);
                        ++count;                                // make result loading percent "expected" correct in case disabled detail mode for example.
                    }
                    continue;
                }
                //PlayerXPperLevel
                _playerXPperLevel[current_level] = current_xp;
                ++count;
            } while (result->NextRow());
        }

        // fill level gaps - only accounting levels > MAX_LEVEL
        for (uint8 level = 1; level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL); ++level)
        {
            if (_playerXPperLevel[level] == 0)
            {
                TC_LOG_ERROR("sql.sql", "Level {} does not have XP for level data. Using data of level [{}] + 12000.", level + 1, level);
                _playerXPperLevel[level] = _playerXPperLevel[level - 1] + 12000;
            }
        }

        TC_LOG_INFO("server.loading", ">> Loaded {} xp for level definition(s) from database in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
}

void ObjectMgr::GetPlayerClassLevelInfo(uint32 class_, uint8 level, uint32& baseMana) const
{
    if (level < 1 || class_ >= MAX_CLASSES)
        return;

    if (level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        level = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);

    GtBaseMPEntry const* mp = sBaseMPGameTable.GetRow(level);
    if (!mp)
    {
        TC_LOG_ERROR("misc", "Tried to get non-existant Class-Level combination data for base hp/mp. Class {} Level {}", class_, level);
        return;
    }

    baseMana = uint32(GetGameTableColumnForClass(mp, class_));
}

void ObjectMgr::GetPlayerLevelInfo(uint32 race, uint32 class_, uint8 level, PlayerLevelInfo* info) const
{
    if (level < 1 || race >= MAX_RACES || class_ >= MAX_CLASSES)
        return;

    auto const& pInfo = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(race), Classes(class_) });
    if (!pInfo)
        return;

    if (level <= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        *info = pInfo->get()->levelInfo[level - 1];
    else
        BuildPlayerLevelInfo(race, class_, level, info);
}

void ObjectMgr::BuildPlayerLevelInfo(uint8 race, uint8 _class, uint8 level, PlayerLevelInfo* info) const
{
    // base data (last known level)
    *info = ASSERT_NOTNULL(Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(race), Classes(_class) }))->get()->levelInfo[sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) - 1];

    // if conversion from uint32 to uint8 causes unexpected behaviour, change lvl to uint32
    for (uint8 lvl = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) - 1; lvl < level; ++lvl)
    {
        switch (_class)
        {
            case CLASS_WARRIOR:
                info->stats[STAT_STRENGTH]  += (lvl > 23 ? 2: (lvl > 1  ? 1: 0));
                info->stats[STAT_STAMINA]   += (lvl > 23 ? 2: (lvl > 1  ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 36 ? 1: (lvl > 6 && (lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 9 && !(lvl%2) ? 1: 0);
                break;
            case CLASS_PALADIN:
                info->stats[STAT_STRENGTH]  += (lvl > 3  ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 33 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 38 ? 1: (lvl > 7 && !(lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 6 && (lvl%2) ? 1: 0);
                break;
            case CLASS_HUNTER:
                info->stats[STAT_STRENGTH]  += (lvl > 4  ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 4  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 33 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 8 && (lvl%2) ? 1: 0);
                break;
            case CLASS_ROGUE:
                info->stats[STAT_STRENGTH]  += (lvl > 5  ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 4  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 16 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 8 && !(lvl%2) ? 1: 0);
                break;
            case CLASS_PRIEST:
                info->stats[STAT_STRENGTH]  += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 5  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 38 ? 1: (lvl > 8 && (lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 22 ? 2: (lvl > 1 ? 1: 0));
                break;
            case CLASS_SHAMAN:
                info->stats[STAT_STRENGTH]  += (lvl > 34 ? 1: (lvl > 6 && (lvl%2) ? 1: 0));
                info->stats[STAT_STAMINA]   += (lvl > 4 ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 7 && !(lvl%2) ? 1: 0);
                info->stats[STAT_INTELLECT] += (lvl > 5 ? 1: 0);
                break;
            case CLASS_MAGE:
                info->stats[STAT_STRENGTH]  += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 5  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_INTELLECT] += (lvl > 24 ? 2: (lvl > 1 ? 1: 0));
                break;
            case CLASS_WARLOCK:
                info->stats[STAT_STRENGTH]  += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 38 ? 2: (lvl > 3 ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_INTELLECT] += (lvl > 33 ? 2: (lvl > 2 ? 1: 0));
                break;
            case CLASS_DRUID:
                info->stats[STAT_STRENGTH]  += (lvl > 38 ? 2: (lvl > 6 && (lvl%2) ? 1: 0));
                info->stats[STAT_STAMINA]   += (lvl > 32 ? 2: (lvl > 4 ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 38 ? 2: (lvl > 8 && (lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 38 ? 3: (lvl > 4 ? 1: 0));
                break;
        }
    }
}

std::vector<uint32> const* ObjectMgr::GetCreatureQuestItemList(uint32 creatureEntry, Difficulty difficulty) const
{
    if (std::vector<uint32> const* items = Trinity::Containers::MapGetValuePtr(_creatureQuestItemStore, { creatureEntry, difficulty }))
        return items;

    // If there is no data for the difficulty, try to get data for the fallback difficulty
    if (DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty))
        return GetCreatureQuestItemList(creatureEntry, Difficulty(difficultyEntry->FallbackDifficultyID));

    return nullptr;
}

std::vector<int32> const* ObjectMgr::GetCreatureQuestCurrencyList(uint32 creatureId) const
{
    return Trinity::Containers::MapGetValuePtr(_creatureQuestCurrenciesStore, creatureId);
}

void ObjectMgr::LoadQuests()
{
    uint32 oldMSTime = getMSTime();

    _questTemplates.clear();
    _questTemplatesAutoPush.clear();
    _questObjectives.clear();

    _exclusiveQuestGroups.clear();

    QueryResult result = WorldDatabase.Query("SELECT "
        //0  1          2               3                4            5            6                  7                8                   9
        "ID, QuestType, QuestPackageID, ContentTuningID, QuestSortID, QuestInfoID, SuggestedGroupNum, RewardNextQuest, RewardXPDifficulty, RewardXPMultiplier, "
        //10                    11                     12                13           14           15               16
        "RewardMoneyDifficulty, RewardMoneyMultiplier, RewardBonusMoney, RewardSpell, RewardHonor, RewardKillHonor, StartItem, "
        //17                         18                          19                        20     21       22
        "RewardArtifactXPDifficulty, RewardArtifactXPMultiplier, RewardArtifactCategoryID, Flags, FlagsEx, FlagsEx2, "
        //23          24             25         26                 27           28             29         30
        "RewardItem1, RewardAmount1, ItemDrop1, ItemDropQuantity1, RewardItem2, RewardAmount2, ItemDrop2, ItemDropQuantity2, "
        //31          32             33         34                 35           36             37         38
        "RewardItem3, RewardAmount3, ItemDrop3, ItemDropQuantity3, RewardItem4, RewardAmount4, ItemDrop4, ItemDropQuantity4, "
        //39                  40                         41                          42                   43                         44
        "RewardChoiceItemID1, RewardChoiceItemQuantity1, RewardChoiceItemDisplayID1, RewardChoiceItemID2, RewardChoiceItemQuantity2, RewardChoiceItemDisplayID2, "
        //45                  46                         47                          48                   49                         50
        "RewardChoiceItemID3, RewardChoiceItemQuantity3, RewardChoiceItemDisplayID3, RewardChoiceItemID4, RewardChoiceItemQuantity4, RewardChoiceItemDisplayID4, "
        //51                  52                         53                          54                   55                         56
        "RewardChoiceItemID5, RewardChoiceItemQuantity5, RewardChoiceItemDisplayID5, RewardChoiceItemID6, RewardChoiceItemQuantity6, RewardChoiceItemDisplayID6, "
        //57           58    59    60           61           62                 63                 64
        "POIContinent, POIx, POIy, POIPriority, RewardTitle, RewardArenaPoints, RewardSkillLineID, RewardNumSkillUps, "
        //65            66                  67                         68
        "PortraitGiver, PortraitGiverMount, PortraitGiverModelSceneID, PortraitTurnIn, "
        //69               70                   71                      72                   73                74                   75                      76
        "RewardFactionID1, RewardFactionValue1, RewardFactionOverride1, RewardFactionCapIn1, RewardFactionID2, RewardFactionValue2, RewardFactionOverride2, RewardFactionCapIn2, "
        //77               78                   79                      80                   81                82                   83                      84
        "RewardFactionID3, RewardFactionValue3, RewardFactionOverride3, RewardFactionCapIn3, RewardFactionID4, RewardFactionValue4, RewardFactionOverride4, RewardFactionCapIn4, "
        //85               86                   87                      88                   89
        "RewardFactionID5, RewardFactionValue5, RewardFactionOverride5, RewardFactionCapIn5, RewardFactionFlags, "
        //90                91                  92                 93                  94                 95                  96                 97
        "RewardCurrencyID1, RewardCurrencyQty1, RewardCurrencyID2, RewardCurrencyQty2, RewardCurrencyID3, RewardCurrencyQty3, RewardCurrencyID4, RewardCurrencyQty4, "
        //98                 99                  100          101          102             103               104        105                  106
        "AcceptedSoundKitID, CompleteSoundKitID, AreaGroupID, TimeAllowed, AllowableRaces, TreasurePickerID, Expansion, ManagedWorldStateID, QuestSessionBonus, "
        //107      108             109               110              111                112                113                 114                 115
        "LogTitle, LogDescription, QuestDescription, AreaDescription, PortraitGiverText, PortraitGiverName, PortraitTurnInText, PortraitTurnInName, QuestCompletionLog "
        "FROM quest_template");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 quests definitions. DB table `quest_template` is empty.");
        return;
    }

    _questTemplates.reserve(result->GetRowCount());

    // create multimap previous quest for each existed quest
    // some quests can have many previous maps set by NextQuestId in previous quest
    // for example set of race quests can lead to single not race specific quest
    do
    {
        Field* fields = result->Fetch();

        uint32 questId = fields[0].GetUInt32();
        auto itr = _questTemplates.emplace(std::piecewise_construct, std::forward_as_tuple(questId), std::forward_as_tuple(fields)).first;
        if (itr->second.IsAutoPush())
            _questTemplatesAutoPush.push_back(&itr->second);
    } while (result->NextRow());

    struct QuestLoaderHelper
    {
        typedef void(Quest::* QuestLoaderFunction)(Field* fields);

        char const* QueryFields;
        char const* TableName;
        char const* QueryExtra;
        char const* TableDesc;
        QuestLoaderFunction LoaderFunction;
    };

    // QuestID needs to be fields[0]
    QuestLoaderHelper const QuestLoaderHelpers[] =
    {
        // 0        1      2      3      4      5      6
        { "QuestID, Type1, Type2, Type3, Type4, Type5, Type6",                                                                                                            "quest_reward_choice_items", "",                                  "reward choice items", &Quest::LoadRewardChoiceItems },

        // 0        1        2                  3
        { "QuestID, SpellID, PlayerConditionID, Type",                                                                                                                    "quest_reward_display_spell", "ORDER BY QuestID ASC, Idx ASC",    "reward display spells", &Quest::LoadRewardDisplaySpell },

        // 0   1       2       3       4       5            6            7            8
        { "ID, Emote1, Emote2, Emote3, Emote4, EmoteDelay1, EmoteDelay2, EmoteDelay3, EmoteDelay4",                                                                       "quest_details",        "",                                       "details",             &Quest::LoadQuestDetails       },

        // 0   1                2                  3                     4                       5
        { "ID, EmoteOnComplete, EmoteOnIncomplete, EmoteOnCompleteDelay, EmoteOnIncompleteDelay, CompletionText",                                                         "quest_request_items",  "",                                       "request items",       &Quest::LoadQuestRequestItems  },

        // 0   1       2       3       4       5            6            7            8            9
        { "ID, Emote1, Emote2, Emote3, Emote4, EmoteDelay1, EmoteDelay2, EmoteDelay3, EmoteDelay4, RewardText",                                                           "quest_offer_reward",   "",                                       "reward emotes",       &Quest::LoadQuestOfferReward   },

        // 0   1         2                 3              4            5            6               7                     8                     9
        { "ID, MaxLevel, AllowableClasses, SourceSpellID, PrevQuestID, NextQuestID, ExclusiveGroup, BreadcrumbForQuestId, RewardMailTemplateID, RewardMailDelay,"
        // 10              11                   12                     13                     14                   15                   16                 17
        " RequiredSkillID, RequiredSkillPoints, RequiredMinRepFaction, RequiredMaxRepFaction, RequiredMinRepValue, RequiredMaxRepValue, ProvidedItemCount, SpecialFlags,"
        // 18
        " ScriptName",                                                                                                                                                    "quest_template_addon", "",                                       "template addons",     &Quest::LoadQuestTemplateAddon },

        // 0        1
        { "QuestId, RewardMailSenderEntry",                                                                                                                               "quest_mail_sender",    "",                                       "mail sender entries", &Quest::LoadQuestMailSender    },

        // 0           1      2        3                4            5          6         7          8                     9
        { "qo.QuestID, qo.ID, qo.Type, qo.StorageIndex, qo.ObjectID, qo.Amount, qo.Flags, qo.Flags2, qo.ProgressBarWeight, qo.Description, "
        //   10                11            12                   13                     14
            "qoce.GameEventID, qoce.SpellID, qoce.ConversationID, qoce.UpdatePhaseShift, qoce.UpdateZoneAuras",                                                           "quest_objectives qo",  "LEFT JOIN quest_objectives_completion_effect qoce ON qo.ID = qoce.ObjectiveID ORDER BY `Order` ASC, StorageIndex ASC", "quest objectives",    &Quest::LoadQuestObjective     },

        // 0        1                  2                     3       4
        { "QuestId, PlayerConditionId, QuestgiverCreatureId, Text, locale",                                                                                               "quest_description_conditional", "ORDER BY OrderIndex",           "conditional details", &Quest::LoadConditionalConditionalQuestDescription },

        // 0        1                  2                     3     4
        { "QuestId, PlayerConditionId, QuestgiverCreatureId, Text, locale",                                                                                               "quest_request_items_conditional", "ORDER BY OrderIndex",         "conditional request items", &Quest::LoadConditionalConditionalRequestItemsText },

        // 0        1                  2                     3     4
        { "QuestId, PlayerConditionId, QuestgiverCreatureId, Text, locale",                                                                                               "quest_offer_reward_conditional", "ORDER BY OrderIndex",          "conditional reward",  &Quest::LoadConditionalConditionalOfferRewardText },

        // 0        1                  2                     3     4
        { "QuestId, PlayerConditionId, QuestgiverCreatureId, Text, locale",                                                                                               "quest_completion_log_conditional", "ORDER BY OrderIndex",        "conditional completion log", &Quest::LoadConditionalConditionalQuestCompletionLog }
    };

    for (QuestLoaderHelper const& loader : QuestLoaderHelpers)
    {
        result = WorldDatabase.PQuery("SELECT {} FROM {} {}", loader.QueryFields, loader.TableName, loader.QueryExtra);

        if (!result)
            TC_LOG_INFO("server.loading", ">> Loaded 0 quest {}. DB table `{}` is empty.", loader.TableDesc, loader.TableName);
        else
        {
            do
            {
                Field* fields = result->Fetch();
                uint32 questId = fields[0].GetUInt32();

                auto itr = _questTemplates.find(questId);
                if (itr != _questTemplates.end())
                    (itr->second.*loader.LoaderFunction)(fields);
                else
                    TC_LOG_ERROR("server.loading", "Table `{}` has data for quest {} but such quest does not exist", loader.TableName, questId);
            } while (result->NextRow());
        }
    }

    // Load `quest_visual_effect` join table with quest_objectives because visual effects are based on objective ID (core stores objectives by their index in quest)
    //                                   0     1     2          3        4
    result = WorldDatabase.Query("SELECT v.ID, o.ID, o.QuestID, v.Index, v.VisualEffect FROM quest_visual_effect AS v LEFT JOIN quest_objectives AS o ON v.ID = o.ID ORDER BY v.Index DESC");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest visual effects. DB table `quest_visual_effect` is empty.");
    }
    else
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 vID = fields[0].GetUInt32();
            uint32 oID = fields[1].GetUInt32();

            if (!vID)
            {
                TC_LOG_ERROR("server.loading", "Table `quest_visual_effect` has visual effect for null objective id");
                continue;
            }

            // objID will be null if match for table join is not found
            if (vID != oID)
            {
                TC_LOG_ERROR("server.loading", "Table `quest_visual_effect` has visual effect for objective {} but such objective does not exist.", vID);
                continue;
            }

            uint32 questId = fields[2].GetUInt32();

            // Do not throw error here because error for non existing quest is thrown while loading quest objectives. we do not need duplication
            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second.LoadQuestObjectiveVisualEffect(fields);
        } while (result->NextRow());
    }

    std::map<uint32, uint32> usedMailTemplates;

    // Post processing
    for (auto& questPair : _questTemplates)
    {
        // skip post-loading checks for disabled quests
        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, questPair.first, nullptr))
            continue;

        Quest* qinfo = &questPair.second;

        // additional quest integrity checks (GO, creature_template and items must be loaded already)

        if (qinfo->GetQuestType() >= MAX_DB_ALLOWED_QUEST_TYPES)
            TC_LOG_ERROR("sql.sql", "Quest {} has `Method` = {}, expected values are 0, 1 or 2.", qinfo->GetQuestId(), qinfo->GetQuestType());

        if (qinfo->_specialFlags & ~QUEST_SPECIAL_FLAGS_DB_ALLOWED)
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `SpecialFlags` = {} > max allowed value. Correct `SpecialFlags` to value <= {}",
                qinfo->GetQuestId(), qinfo->_specialFlags, QUEST_SPECIAL_FLAGS_DB_ALLOWED);
            qinfo->_specialFlags &= QUEST_SPECIAL_FLAGS_DB_ALLOWED;
        }

        if (qinfo->_flags & QUEST_FLAGS_DAILY && qinfo->_flags & QUEST_FLAGS_WEEKLY)
        {
            TC_LOG_ERROR("sql.sql", "Weekly Quest {} is marked as daily quest in `Flags`, removed daily flag.", qinfo->GetQuestId());
            qinfo->_flags &= ~QUEST_FLAGS_DAILY;
        }

        if (qinfo->_flags & QUEST_FLAGS_DAILY)
        {
            if (!(qinfo->_specialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE))
            {
                TC_LOG_DEBUG("sql.sql", "Daily Quest {} not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
                qinfo->_specialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
            }
        }

        if (qinfo->_flags & QUEST_FLAGS_WEEKLY)
        {
            if (!(qinfo->_specialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE))
            {
                TC_LOG_DEBUG("sql.sql", "Weekly Quest {} not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
                qinfo->_specialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
            }
        }

        if (qinfo->_specialFlags & QUEST_SPECIAL_FLAGS_MONTHLY)
        {
            if (!(qinfo->_specialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE))
            {
                TC_LOG_DEBUG("sql.sql", "Monthly quest {} not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
                qinfo->_specialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
            }
        }

        if (qinfo->_flags & QUEST_FLAGS_TRACKING_EVENT)
        {
            // at auto-reward can be rewarded only RewardChoiceItemId[0]
            for (uint32 j = 1; j < QUEST_REWARD_CHOICES_COUNT; ++j )
            {
                if (uint32 id = qinfo->RewardChoiceItemId[j])
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardChoiceItemId{}` = {} but item from `RewardChoiceItemId{}` can't be rewarded with quest flag QUEST_FLAGS_TRACKING.",
                        qinfo->GetQuestId(), j + 1, id, j + 1);
                    // no changes, quest ignore this data
                }
            }
        }

        if (qinfo->_contentTuningID && !sContentTuningStore.LookupEntry(qinfo->_contentTuningID))
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `ContentTuningID` = {} but content tuning with this id does not exist.",
                qinfo->GetQuestId(), qinfo->_contentTuningID);
        }

        // client quest log visual (area case)
        if (qinfo->_questSortID > 0)
        {
            if (!sAreaTableStore.LookupEntry(qinfo->_questSortID))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `QuestSortID` = {} (zone case) but zone with this id does not exist.",
                    qinfo->GetQuestId(), qinfo->_questSortID);
                // no changes, quest not dependent from this value but can have problems at client
            }
        }
        // client quest log visual (sort case)
        if (qinfo->_questSortID < 0)
        {
            QuestSortEntry const* qSort = sQuestSortStore.LookupEntry(-int32(qinfo->_questSortID));
            if (!qSort)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `QuestSortID` = {} (sort case) but quest sort with this id does not exist.",
                    qinfo->GetQuestId(), qinfo->_questSortID);
                // no changes, quest not dependent from this value but can have problems at client (note some may be 0, we must allow this so no check)
            }
            //check for proper RequiredSkillId value (skill case)
            if (uint32 skill_id = SkillByQuestSort(-int32(qinfo->_questSortID)))
            {
                if (qinfo->_requiredSkillId != skill_id)
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `QuestSortID` = {} but `RequiredSkillId` does not have a corresponding value ({}).",
                        qinfo->GetQuestId(), qinfo->_questSortID, skill_id);
                    //override, and force proper value here?
                }
            }
        }

        // AllowableClasses, can be 0/CLASSMASK_ALL_PLAYABLE to allow any class
        if (qinfo->_allowableClasses)
        {
            if (!(qinfo->_allowableClasses & CLASSMASK_ALL_PLAYABLE))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} does not contain any playable classes in `AllowableClasses` ({}), value set to 0 (all classes).", qinfo->GetQuestId(), qinfo->_allowableClasses);
                qinfo->_allowableClasses = 0;
            }
        }
        // AllowableRaces, can be -1/RACEMASK_ALL_PLAYABLE to allow any race
        if (qinfo->_allowableRaces.RawValue != uint64(-1))
        {
            if (!qinfo->_allowableRaces.IsEmpty() && (qinfo->_allowableRaces & RACEMASK_ALL_PLAYABLE).IsEmpty())
            {
                TC_LOG_ERROR("sql.sql", "Quest {} does not contain any playable races in `AllowableRaces` ({}), value set to -1 (all races).", qinfo->GetQuestId(), qinfo->_allowableRaces.RawValue);
                qinfo->_allowableRaces.RawValue = uint64(-1);
            }
        }
        // RequiredSkillId, can be 0
        if (qinfo->_requiredSkillId)
        {
            if (!sSkillLineStore.LookupEntry(qinfo->_requiredSkillId))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredSkillId` = {} but this skill does not exist",
                    qinfo->GetQuestId(), qinfo->_requiredSkillId);
            }
        }

        if (qinfo->_requiredSkillPoints)
        {
            if (qinfo->_requiredSkillPoints > sWorld->GetConfigMaxSkillValue())
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredSkillPoints` = {} but max possible skill is {}, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->_requiredSkillPoints, sWorld->GetConfigMaxSkillValue());
                // no changes, quest can't be done for this requirement
            }
        }
        // else Skill quests can have 0 skill level, this is ok

        if (qinfo->_requiredMinRepFaction && !sFactionStore.LookupEntry(qinfo->_requiredMinRepFaction))
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredMinRepFaction` = {} but faction template {} does not exist, quest can't be done.",
                qinfo->GetQuestId(), qinfo->_requiredMinRepFaction, qinfo->_requiredMinRepFaction);
            // no changes, quest can't be done for this requirement
        }

        if (qinfo->_requiredMaxRepFaction && !sFactionStore.LookupEntry(qinfo->_requiredMaxRepFaction))
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredMaxRepFaction` = {} but faction template {} does not exist, quest can't be done.",
                qinfo->GetQuestId(), qinfo->_requiredMaxRepFaction, qinfo->_requiredMaxRepFaction);
            // no changes, quest can't be done for this requirement
        }

        if (qinfo->_requiredMinRepValue && qinfo->_requiredMinRepValue > ReputationMgr::Reputation_Cap)
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredMinRepValue` = {} but max reputation is {}, quest can't be done.",
                qinfo->GetQuestId(), qinfo->_requiredMinRepValue, ReputationMgr::Reputation_Cap);
            // no changes, quest can't be done for this requirement
        }

        if (qinfo->_requiredMinRepValue && qinfo->_requiredMaxRepValue && qinfo->_requiredMaxRepValue <= qinfo->_requiredMinRepValue)
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredMaxRepValue` = {} and `RequiredMinRepValue` = {}, quest can't be done.",
                qinfo->GetQuestId(), qinfo->_requiredMaxRepValue, qinfo->_requiredMinRepValue);
            // no changes, quest can't be done for this requirement
        }

        if (!qinfo->_requiredMinRepFaction && qinfo->_requiredMinRepValue != 0)
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredMinRepValue` = {} but `RequiredMinRepFaction` is 0, value has no effect",
                qinfo->GetQuestId(), qinfo->_requiredMinRepValue);
            // warning
        }

        if (!qinfo->_requiredMaxRepFaction && qinfo->_requiredMaxRepValue != 0)
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RequiredMaxRepValue` = {} but `RequiredMaxRepFaction` is 0, value has no effect",
                qinfo->GetQuestId(), qinfo->_requiredMaxRepValue);
            // warning
        }

        if (qinfo->_rewardTitleId && !sCharTitlesStore.LookupEntry(qinfo->_rewardTitleId))
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `RewardTitleId` = {} but CharTitle Id {} does not exist, quest can't be rewarded with title.",
                qinfo->GetQuestId(), qinfo->_rewardTitleId, qinfo->_rewardTitleId);
            qinfo->_rewardTitleId = 0;
            // quest can't reward this title
        }

        if (qinfo->_sourceItemId)
        {
            if (!GetItemTemplate(qinfo->_sourceItemId))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `SourceItemId` = {} but item with entry {} does not exist, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->_sourceItemId, qinfo->_sourceItemId);
                qinfo->_sourceItemId = 0;                       // quest can't be done for this requirement
            }
            else if (qinfo->_sourceItemIdCount == 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `StartItem` = {} but `ProvidedItemCount` = 0, set to 1 but need fix in DB.",
                    qinfo->GetQuestId(), qinfo->_sourceItemId);
                qinfo->_sourceItemIdCount = 1;                    // update to 1 for allow quest work for backward compatibility with DB
            }
        }
        else if (qinfo->_sourceItemIdCount > 0)
        {
            TC_LOG_ERROR("sql.sql", "Quest {} has `SourceItemId` = 0 but `SourceItemIdCount` = {}, useless value.",
                qinfo->GetQuestId(), qinfo->_sourceItemIdCount);
            qinfo->_sourceItemIdCount = 0;                          // no quest work changes in fact
        }

        if (qinfo->_sourceSpellID)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(qinfo->_sourceSpellID, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `SourceSpellid` = {} but spell {} doesn't exist, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->_sourceSpellID, qinfo->_sourceSpellID);
                qinfo->_sourceSpellID = 0;                        // quest can't be done for this requirement
            }
            else if (!SpellMgr::IsSpellValid(spellInfo))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `SourceSpellid` = {} but spell {} is broken, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->_sourceSpellID, qinfo->_sourceSpellID);
                qinfo->_sourceSpellID = 0;                        // quest can't be done for this requirement
            }
        }

        for (QuestObjective const& obj : qinfo->GetObjectives())
        {
            // Store objective for lookup by id
            _questObjectives[obj.ID] = &obj;

            // Check storage index for objectives which store data
            if (obj.StorageIndex < 0)
            {
                switch (obj.Type)
                {
                    case QUEST_OBJECTIVE_MONSTER:
                    case QUEST_OBJECTIVE_ITEM:
                    case QUEST_OBJECTIVE_GAMEOBJECT:
                    case QUEST_OBJECTIVE_TALKTO:
                    case QUEST_OBJECTIVE_PLAYERKILLS:
                    case QUEST_OBJECTIVE_AREATRIGGER:
                    case QUEST_OBJECTIVE_WINPETBATTLEAGAINSTNPC:
                    case QUEST_OBJECTIVE_OBTAIN_CURRENCY:
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has invalid StorageIndex = {} for objective type {}", qinfo->GetQuestId(), obj.ID, obj.StorageIndex, obj.Type);
                        break;
                    default:
                        break;
                }
            }

            switch (obj.Type)
            {
                case QUEST_OBJECTIVE_ITEM:
                    if (!GetItemTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing item entry {}, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_MONSTER:
                    if (!GetCreatureTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing creature entry {}, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_GAMEOBJECT:
                    if (!GetGameObjectTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing gameobject entry {}, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_TALKTO:
                    if (!GetCreatureTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing creature entry {}, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_MIN_REPUTATION:
                case QUEST_OBJECTIVE_MAX_REPUTATION:
                case QUEST_OBJECTIVE_INCREASE_REPUTATION:
                    if (!sFactionStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing faction id {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_PLAYERKILLS:
                    if (obj.Amount <= 0)
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has invalid player kills count {}", qinfo->GetQuestId(), obj.ID, obj.Amount);
                    break;
                case QUEST_OBJECTIVE_CURRENCY:
                case QUEST_OBJECTIVE_HAVE_CURRENCY:
                case QUEST_OBJECTIVE_OBTAIN_CURRENCY:
                    if (!sCurrencyTypesStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing currency {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    if (obj.Amount <= 0)
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has invalid currency amount {}", qinfo->GetQuestId(), obj.ID, obj.Amount);
                    break;
                case QUEST_OBJECTIVE_LEARNSPELL:
                    if (!sSpellMgr->GetSpellInfo(obj.ObjectID, DIFFICULTY_NONE))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing spell id {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_WINPETBATTLEAGAINSTNPC:
                    if (obj.ObjectID && !GetCreatureTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing creature entry {}, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_DEFEATBATTLEPET:
                    if (!sBattlePetSpeciesStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing battlepet species id {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_CRITERIA_TREE:
                    if (!sCriteriaTreeStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing criteria tree id {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_AREATRIGGER:
                    if (!sAreaTriggerStore.LookupEntry(uint32(obj.ObjectID)) && obj.ObjectID != -1)
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing AreaTrigger.db2 id {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_AREA_TRIGGER_ENTER:
                case QUEST_OBJECTIVE_AREA_TRIGGER_EXIT:
                    if (!sAreaTriggerDataStore->GetAreaTriggerTemplate({ uint32(obj.ObjectID), false }) && !sAreaTriggerDataStore->GetAreaTriggerTemplate({ uint32(obj.ObjectID), true }))
                        TC_LOG_ERROR("sql.sql", "Quest {} objective {} has non existing areatrigger id {}", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_MONEY:
                case QUEST_OBJECTIVE_WINPVPPETBATTLES:
                case QUEST_OBJECTIVE_PROGRESS_BAR:
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "Quest {} objective {} has unhandled type {}", qinfo->GetQuestId(), obj.ID, obj.Type);
                    break;
            }

            if (obj.Flags & QUEST_OBJECTIVE_FLAG_SEQUENCED)
                qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_SEQUENCED_OBJECTIVES);
        }

        for (uint8 j = 0; j < QUEST_ITEM_DROP_COUNT; ++j)
        {
            uint32 id = qinfo->ItemDrop[j];
            if (id)
            {
                if (!GetItemTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `ItemDrop{}` = {} but item with entry {} does not exist, quest can't be done.",
                        qinfo->GetQuestId(), j+1, id, id);
                    // no changes, quest can't be done for this requirement
                }
            }
            else
            {
                if (qinfo->ItemDropQuantity[j]>0)
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `ItemDrop{}` = 0 but `ItemDropQuantity{}` = {}.",
                        qinfo->GetQuestId(), j+1, j+1, qinfo->ItemDropQuantity[j]);
                    // no changes, quest ignore this data
                }
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_CHOICES_COUNT; ++j)
        {
            if (uint32 id = qinfo->RewardChoiceItemId[j])
            {
                switch (qinfo->RewardChoiceItemType[j])
                {
                    case LootItemType::Item:
                        if (!GetItemTemplate(id))
                        {
                            TC_LOG_ERROR("sql.sql", "Quest {} has `RewardChoiceItemId{}` = {} but item with entry {} does not exist, quest will not reward this item.",
                                qinfo->GetQuestId(), j + 1, id, id);
                            qinfo->RewardChoiceItemId[j] = 0;          // no changes, quest will not reward this
                        }
                        break;
                    case LootItemType::Currency:
                        if (!sCurrencyTypesStore.HasRecord(id))
                        {
                            TC_LOG_ERROR("sql.sql", "Quest {} has `RewardChoiceItemId{}` = {} but currency with id {} does not exist, quest will not reward this currency.",
                                qinfo->GetQuestId(), j + 1, id, id);
                            qinfo->RewardChoiceItemId[j] = 0;          // no changes, quest will not reward this
                        }
                        break;
                    default:
                        TC_LOG_ERROR("sql.sql", "Quest {} has `RewardChoiceItemType{}` = {} but it is not a valid item type, reward removed.",
                            qinfo->GetQuestId(), j + 1, uint32(qinfo->RewardChoiceItemType[j]));
                        qinfo->RewardChoiceItemId[j] = 0;
                        break;
                }

                if (!qinfo->RewardChoiceItemCount[j])
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardChoiceItemId{}` = {} but `RewardChoiceItemCount{}` = 0.",
                        qinfo->GetQuestId(), j + 1, id, j + 1);
                }
            }
            else if (qinfo->RewardChoiceItemCount[j] > 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardChoiceItemId{}` = 0 but `RewardChoiceItemCount{}` = {}.",
                    qinfo->GetQuestId(), j + 1, j + 1, qinfo->RewardChoiceItemCount[j]);
                // no changes, quest ignore this data
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_ITEM_COUNT; ++j)
        {
            uint32 id = qinfo->RewardItemId[j];
            if (id)
            {
                if (!GetItemTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardItemId{}` = {} but item with entry {} does not exist, quest will not reward this item.",
                        qinfo->GetQuestId(), j+1, id, id);
                    qinfo->RewardItemId[j] = 0;                // no changes, quest will not reward this item
                }

                if (!qinfo->RewardItemCount[j])
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardItemId{}` = {} but `RewardItemCount{}` = 0, quest will not reward this item.",
                        qinfo->GetQuestId(), j+1, id, j+1);
                    // no changes
                }
            }
            else if (qinfo->RewardItemCount[j]>0)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardItemId{}` = 0 but `RewardItemCount{}` = {}.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardItemCount[j]);
                // no changes, quest ignore this data
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_REPUTATIONS_COUNT; ++j)
        {
            if (qinfo->RewardFactionId[j])
            {
                if (std::abs(qinfo->RewardFactionValue[j]) > 9)
                {
               TC_LOG_ERROR("sql.sql", "Quest {} has RewardFactionValueId{} = {}. That is outside the range of valid values (-9 to 9).", qinfo->GetQuestId(), j+1, qinfo->RewardFactionValue[j]);
                }
                if (!sFactionStore.LookupEntry(qinfo->RewardFactionId[j]))
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardFactionId{}` = {} but raw faction (faction.dbc) {} does not exist, quest will not reward reputation for this faction.", qinfo->GetQuestId(), j+1, qinfo->RewardFactionId[j], qinfo->RewardFactionId[j]);
                    qinfo->RewardFactionId[j] = 0;            // quest will not reward this
                }
            }

            else if (qinfo->RewardFactionOverride[j] != 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardFactionId{}` = 0 but `RewardFactionValueIdOverride{}` = {}.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardFactionOverride[j]);
                // no changes, quest ignore this data
            }
        }

        if (qinfo->_rewardSpell > 0)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(qinfo->_rewardSpell, DIFFICULTY_NONE);

            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardSpellCast` = {} but spell {} does not exist, quest will not have a spell reward.",
                    qinfo->GetQuestId(), qinfo->_rewardSpell, qinfo->_rewardSpell);
                qinfo->_rewardSpell = 0;                    // no spell will be cast on player
            }

            else if (!SpellMgr::IsSpellValid(spellInfo))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardSpellCast` = {} but spell {} is broken, quest will not have a spell reward.",
                    qinfo->GetQuestId(), qinfo->_rewardSpell, qinfo->_rewardSpell);
                qinfo->_rewardSpell = 0;                    // no spell will be cast on player
            }
        }

        if (qinfo->_rewardMailTemplateId)
        {
            if (!sMailTemplateStore.LookupEntry(qinfo->_rewardMailTemplateId))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardMailTemplateId` = {} but mail template  {} does not exist, quest will not have a mail reward.",
                    qinfo->GetQuestId(), qinfo->_rewardMailTemplateId, qinfo->_rewardMailTemplateId);
                qinfo->_rewardMailTemplateId = 0;               // no mail will send to player
                qinfo->_rewardMailDelay = 0;                // no mail will send to player
                qinfo->_rewardMailSenderEntry = 0;
            }
            else if (usedMailTemplates.find(qinfo->_rewardMailTemplateId) != usedMailTemplates.end())
            {
                auto used_mt_itr = usedMailTemplates.find(qinfo->_rewardMailTemplateId);
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardMailTemplateId` = {} but mail template  {} already used for quest {}, quest will not have a mail reward.",
                    qinfo->GetQuestId(), qinfo->_rewardMailTemplateId, qinfo->_rewardMailTemplateId, used_mt_itr->second);
                qinfo->_rewardMailTemplateId = 0;               // no mail will send to player
                qinfo->_rewardMailDelay = 0;                // no mail will send to player
                qinfo->_rewardMailSenderEntry = 0;
            }
            else
                usedMailTemplates.emplace(qinfo->_rewardMailTemplateId, qinfo->GetQuestId());
        }

        if (uint32 nextQuestInChain = qinfo->_nextQuestInChain)
        {
            if (!_questTemplates.count(nextQuestInChain))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `NextQuestInChain` = {} but quest {} does not exist, quest chain will not work.",
                    qinfo->GetQuestId(), qinfo->_nextQuestInChain, qinfo->_nextQuestInChain);
                qinfo->_nextQuestInChain = 0;
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_CURRENCY_COUNT; ++j)
        {
            if (qinfo->RewardCurrencyId[j])
            {
                if (qinfo->RewardCurrencyCount[j] == 0)
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardCurrencyId{}` = {} but `RewardCurrencyCount{}` = 0, quest can't be done.",
                        qinfo->GetQuestId(), j+1, qinfo->RewardCurrencyId[j], j+1);
                    // no changes, quest can't be done for this requirement
                }

                if (!sCurrencyTypesStore.LookupEntry(qinfo->RewardCurrencyId[j]))
                {
                    TC_LOG_ERROR("sql.sql", "Quest {} has `RewardCurrencyId{}` = {} but currency with entry {} does not exist, quest can't be done.",
                        qinfo->GetQuestId(), j+1, qinfo->RewardCurrencyId[j], qinfo->RewardCurrencyId[j]);
                    qinfo->RewardCurrencyCount[j] = 0;             // prevent incorrect work of quest
                }
            }
            else if (qinfo->RewardCurrencyCount[j] > 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardCurrencyId{}` = 0 but `RewardCurrencyCount{}` = {}, quest can't be done.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardCurrencyCount[j]);
                qinfo->RewardCurrencyCount[j] = 0;                 // prevent incorrect work of quest
            }
        }

        if (qinfo->_soundAccept)
        {
            if (!sSoundKitStore.LookupEntry(qinfo->_soundAccept))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `SoundAccept` = {} but sound {} does not exist, set to 0.",
                    qinfo->GetQuestId(), qinfo->_soundAccept, qinfo->_soundAccept);
                qinfo->_soundAccept = 0;                        // no sound will be played
            }
        }

        if (qinfo->_soundTurnIn)
        {
            if (!sSoundKitStore.LookupEntry(qinfo->_soundTurnIn))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `SoundTurnIn` = {} but sound {} does not exist, set to 0.",
                    qinfo->GetQuestId(), qinfo->_soundTurnIn, qinfo->_soundTurnIn);
                qinfo->_soundTurnIn = 0;                        // no sound will be played
            }
        }

        if (qinfo->_rewardSkillId)
        {
            if (!sSkillLineStore.LookupEntry(qinfo->_rewardSkillId))
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardSkillId` = {} but this skill does not exist",
                    qinfo->GetQuestId(), qinfo->_rewardSkillId);
            }
            if (!qinfo->_rewardSkillPoints)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardSkillId` = {} but `RewardSkillPoints` is 0",
                    qinfo->GetQuestId(), qinfo->_rewardSkillId);
            }
        }

        if (qinfo->_rewardSkillPoints)
        {
            if (qinfo->_rewardSkillPoints > sWorld->GetConfigMaxSkillValue())
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardSkillPoints` = {} but max possible skill is {}, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->_rewardSkillPoints, sWorld->GetConfigMaxSkillValue());
                // no changes, quest can't be done for this requirement
            }
            if (!qinfo->_rewardSkillId)
            {
                TC_LOG_ERROR("sql.sql", "Quest {} has `RewardSkillPoints` = {} but `RewardSkillId` is 0",
                    qinfo->GetQuestId(), qinfo->_rewardSkillPoints);
            }
        }

        // fill additional data stores
        if (uint32 prevQuestId = std::abs(qinfo->_prevQuestID))
        {
            auto prevQuestItr = _questTemplates.find(prevQuestId);
            if (prevQuestItr == _questTemplates.end())
                TC_LOG_ERROR("sql.sql", "Quest {} has PrevQuestId {}, but no such quest", qinfo->GetQuestId(), qinfo->GetPrevQuestId());
            else if (prevQuestItr->second._breadcrumbForQuestId)
                TC_LOG_ERROR("sql.sql", "Quest {} should not be unlocked by breadcrumb quest {}", qinfo->_id, prevQuestId);
            else if (qinfo->_prevQuestID > 0)
                qinfo->DependentPreviousQuests.push_back(prevQuestId);
        }

        if (uint32 nextQuestId = qinfo->_nextQuestID)
        {
            auto nextQuestItr = _questTemplates.find(nextQuestId);
            if (nextQuestItr == _questTemplates.end())
                TC_LOG_ERROR("sql.sql", "Quest {} has NextQuestId {}, but no such quest", qinfo->GetQuestId(), qinfo->_nextQuestID);
            else
                nextQuestItr->second.DependentPreviousQuests.push_back(qinfo->GetQuestId());
        }

        if (uint32 breadcrumbForQuestId = std::abs(qinfo->_breadcrumbForQuestId))
        {
            if (_questTemplates.find(breadcrumbForQuestId) == _questTemplates.end())
            {
                TC_LOG_ERROR("sql.sql", "Quest {} is a breadcrumb for quest {}, but no such quest exists", qinfo->_id, breadcrumbForQuestId);
                qinfo->_breadcrumbForQuestId = 0;
            }
            if (qinfo->_nextQuestID)
                TC_LOG_ERROR("sql.sql", "Quest {} is a breadcrumb, should not unlock quest {}", qinfo->_id, qinfo->_nextQuestID);
        }

        if (qinfo->_exclusiveGroup)
            _exclusiveQuestGroups.insert(std::pair<int32, uint32>(qinfo->_exclusiveGroup, qinfo->GetQuestId()));
    }

    // Disallow any breadcrumb loops and inform quests of their breadcrumbs
    for (auto& questPair : _questTemplates)
    {
        // skip post-loading checks for disabled quests
        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, questPair.first, nullptr))
            continue;

        Quest* qinfo = &questPair.second;
        uint32   qid = qinfo->GetQuestId();
        uint32 breadcrumbForQuestId = std::abs(qinfo->_breadcrumbForQuestId);
        std::set<uint32> questSet;

        while(breadcrumbForQuestId)
        {
            //a previously visited quest was found as a breadcrumb quest
            //breadcrumb loop found!
            if (!questSet.insert(qinfo->_id).second)
            {
                TC_LOG_ERROR("sql.sql", "Breadcrumb quests {} and {} are in a loop", qid, breadcrumbForQuestId);
                qinfo->_breadcrumbForQuestId = 0;
                break;
            }

            qinfo = const_cast<Quest*>(GetQuestTemplate(breadcrumbForQuestId));

            //every quest has a list of every breadcrumb towards it
            qinfo->DependentBreadcrumbQuests.push_back(qid);

            breadcrumbForQuestId = qinfo->GetBreadcrumbForQuestId();
        }
    }

    // don't check spells with SPELL_EFFECT_QUEST_COMPLETE, a lot of invalid db2 data

    // Make all paragon reward quests repeatable
    for (ParagonReputationEntry const* paragonReputation : sParagonReputationStore)
        if (Quest const* quest = GetQuestTemplate(paragonReputation->QuestID))
            const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_REPEATABLE);

    TC_LOG_INFO("server.loading", ">> Loaded {} quests definitions in {} ms", _questTemplates.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestStartersAndEnders()
{
    TC_LOG_INFO("server.loading", "Loading GO Start Quest Data...");
    LoadGameobjectQuestStarters();
    TC_LOG_INFO("server.loading", "Loading GO End Quest Data...");
    LoadGameobjectQuestEnders();
    TC_LOG_INFO("server.loading", "Loading Creature Start Quest Data...");
    LoadCreatureQuestStarters();
    TC_LOG_INFO("server.loading", "Loading Creature End Quest Data...");
    LoadCreatureQuestEnders();
}

void ObjectMgr::LoadQuestTemplateLocale()
{
    uint32 oldMSTime = getMSTime();

    _questTemplateLocaleStore.clear(); // need for reload case
    //                                               0     1
    QueryResult result = WorldDatabase.Query("SELECT Id, locale, "
    //      2           3                 4                5                 6                  7                   8                   9                  10
        "LogTitle, LogDescription, QuestDescription, AreaDescription, PortraitGiverText, PortraitGiverName, PortraitTurnInText, PortraitTurnInName, QuestCompletionLog"
        " FROM quest_template_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                       = fields[0].GetUInt32();
        std::string_view localeName     = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        QuestTemplateLocale& data = _questTemplateLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.LogTitle);
        AddLocaleString(fields[3].GetStringView(), locale, data.LogDescription);
        AddLocaleString(fields[4].GetStringView(), locale, data.QuestDescription);
        AddLocaleString(fields[5].GetStringView(), locale, data.AreaDescription);
        AddLocaleString(fields[6].GetStringView(), locale, data.PortraitGiverText);
        AddLocaleString(fields[7].GetStringView(), locale, data.PortraitGiverName);
        AddLocaleString(fields[8].GetStringView(), locale, data.PortraitTurnInText);
        AddLocaleString(fields[9].GetStringView(), locale, data.PortraitTurnInName);
        AddLocaleString(fields[10].GetStringView(), locale, data.QuestCompletionLog);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Quest Template locale strings in {} ms", _questTemplateLocaleStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestObjectivesLocale()
{
    uint32 oldMSTime = getMSTime();

    _questObjectivesLocaleStore.clear(); // need for reload case
    //                                               0     1          2
    QueryResult result = WorldDatabase.Query("SELECT Id, locale, Description FROM quest_objectives_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                           = fields[0].GetUInt32();
        std::string_view localeName         = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        QuestObjectivesLocale& data = _questObjectivesLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.Description);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Quest Objectives locale strings in {} ms", _questObjectivesLocaleStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestGreetingLocales()
{
    uint32 oldMSTime = getMSTime();

    for (std::size_t i = 0; i < _questGreetingLocaleStore.size(); ++i)
        _questGreetingLocaleStore[i].clear();

    //                                               0   1     2       3
    QueryResult result = WorldDatabase.Query("SELECT Id, type, locale, Greeting FROM quest_greeting_locale");
    if (!result)
        return;

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        uint8 type = fields[1].GetUInt8();
        switch (type)
        {
            case 0: // Creature
                if (!GetCreatureTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_greeting_locale`: creature template entry {} does not exist.", id);
                    continue;
                }
                break;
            case 1: // GameObject
                if (!GetGameObjectTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_greeting_locale`: gameobject template entry {} does not exist.", id);
                    continue;
                }
                break;
            default:
                continue;
        }

        std::string_view localeName = fields[2].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        QuestGreetingLocale& data = _questGreetingLocaleStore[type][id];
        AddLocaleString(fields[3].GetStringView(), locale, data.Greeting);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Quest Greeting locale strings in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestOfferRewardLocale()
{
    uint32 oldMSTime = getMSTime();

    _questOfferRewardLocaleStore.clear(); // need for reload case
    //                                               0     1          2
    QueryResult result = WorldDatabase.Query("SELECT Id, locale, RewardText FROM quest_offer_reward_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        std::string_view localeName = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        QuestOfferRewardLocale& data = _questOfferRewardLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.RewardText);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Quest Offer Reward locale strings in {} ms", _questOfferRewardLocaleStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestRequestItemsLocale()
{
    uint32 oldMSTime = getMSTime();

    _questRequestItemsLocaleStore.clear(); // need for reload case
    //                                               0     1          2
    QueryResult result = WorldDatabase.Query("SELECT Id, locale, CompletionText FROM quest_request_items_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        std::string_view localeName = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        QuestRequestItemsLocale& data = _questRequestItemsLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.CompletionText);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Quest Request Items locale strings in {} ms", _questRequestItemsLocaleStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadScripts(ScriptsType type)
{
    uint32 oldMSTime = getMSTime();

    ScriptMapMap* scripts = GetScriptsMapByType(type);
    if (!scripts)
        return;

    std::string tableName = GetScriptsTableNameByType(type);
    if (tableName.empty())
        return;

    if (sMapMgr->IsScriptScheduled())                    // function cannot be called when scripts are in use.
        return;

    TC_LOG_INFO("server.loading", "Loading {}...", tableName);

    scripts->clear();                                       // need for reload support

    bool isSpellScriptTable = (type == SCRIPTS_SPELL);
    //                                                 0    1       2         3         4          5    6  7  8  9
    QueryResult result = WorldDatabase.PQuery("SELECT id, delay, command, datalong, datalong2, dataint, x, y, z, o{} FROM {}", isSpellScriptTable ? ", effIndex" : "", tableName);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 script definitions. DB table `{}` is empty!", tableName);
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        ScriptInfo tmp;
        tmp.type      = type;
        tmp.id           = fields[0].GetUInt32();
        if (isSpellScriptTable)
            tmp.id      |= fields[10].GetUInt8() << 24;
        tmp.delay        = fields[1].GetUInt32();
        tmp.command      = ScriptCommands(fields[2].GetUInt32());
        tmp.Raw.nData[0] = fields[3].GetUInt32();
        tmp.Raw.nData[1] = fields[4].GetUInt32();
        tmp.Raw.nData[2] = fields[5].GetInt32();
        tmp.Raw.fData[0] = fields[6].GetFloat();
        tmp.Raw.fData[1] = fields[7].GetFloat();
        tmp.Raw.fData[2] = fields[8].GetFloat();
        tmp.Raw.fData[3] = fields[9].GetFloat();

        // generic command args check
        switch (tmp.command)
        {
            case SCRIPT_COMMAND_TALK:
            {
                if (tmp.Talk.ChatType > CHAT_TYPE_WHISPER && tmp.Talk.ChatType != CHAT_MSG_RAID_BOSS_WHISPER)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid talk type (datalong = {}) in SCRIPT_COMMAND_TALK for script id {}",
                        tableName, tmp.Talk.ChatType, tmp.id);
                    continue;
                }
                if (!sBroadcastTextStore.LookupEntry(uint32(tmp.Talk.TextID)))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid talk text id (dataint = {}) in SCRIPT_COMMAND_TALK for script id {}",
                        tableName, tmp.Talk.TextID, tmp.id);
                    continue;
                }

                break;
            }

            case SCRIPT_COMMAND_EMOTE:
            {
                if (!sEmotesStore.LookupEntry(tmp.Emote.EmoteID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid emote id (datalong = {}) in SCRIPT_COMMAND_EMOTE for script id {}",
                        tableName, tmp.Emote.EmoteID, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_TELEPORT_TO:
            {
                if (!sMapStore.LookupEntry(tmp.TeleportTo.MapID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid map (Id: {}) in SCRIPT_COMMAND_TELEPORT_TO for script id {}",
                        tableName, tmp.TeleportTo.MapID, tmp.id);
                    continue;
                }

                if (!Trinity::IsValidMapCoord(tmp.TeleportTo.DestX, tmp.TeleportTo.DestY, tmp.TeleportTo.DestZ, tmp.TeleportTo.Orientation))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid coordinates (X: {} Y: {} Z: {} O: {}) in SCRIPT_COMMAND_TELEPORT_TO for script id {}",
                        tableName, tmp.TeleportTo.DestX, tmp.TeleportTo.DestY, tmp.TeleportTo.DestZ, tmp.TeleportTo.Orientation, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_QUEST_EXPLORED:
            {
                Quest const* quest = GetQuestTemplate(tmp.QuestExplored.QuestID);
                if (!quest)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid quest (ID: {}) in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id {}",
                        tableName, tmp.QuestExplored.QuestID, tmp.id);
                    continue;
                }

                if (!quest->HasFlag(QUEST_FLAGS_COMPLETION_EVENT) && !quest->HasFlag(QUEST_FLAGS_COMPLETION_AREA_TRIGGER))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has quest (ID: {}) in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id {}, but quest not have QUEST_FLAGS_COMPLETION_EVENT or QUEST_FLAGS_COMPLETION_AREA_TRIGGER in quest flags. Script command will do nothing.",
                        tableName, tmp.QuestExplored.QuestID, tmp.id);
                    continue;
                }

                if (float(tmp.QuestExplored.Distance) > DEFAULT_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has too large distance ({}) for exploring objective complete in `datalong2` in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id {}",
                        tableName, tmp.QuestExplored.Distance, tmp.id);
                    continue;
                }

                if (tmp.QuestExplored.Distance && float(tmp.QuestExplored.Distance) > DEFAULT_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has too large distance ({}) for exploring objective complete in `datalong2` in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id {}, max distance is {} or 0 for disable distance check",
                        tableName, tmp.QuestExplored.Distance, tmp.id, DEFAULT_VISIBILITY_DISTANCE);
                    continue;
                }

                if (tmp.QuestExplored.Distance && float(tmp.QuestExplored.Distance) < INTERACTION_DISTANCE)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has too small distance ({}) for exploring objective complete in `datalong2` in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id {}, min distance is {} or 0 for disable distance check",
                        tableName, tmp.QuestExplored.Distance, tmp.id, INTERACTION_DISTANCE);
                    continue;
                }

                break;
            }

            case SCRIPT_COMMAND_KILL_CREDIT:
            {
                if (!GetCreatureTemplate(tmp.KillCredit.CreatureEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid creature (Entry: {}) in SCRIPT_COMMAND_KILL_CREDIT for script id {}",
                        tableName, tmp.KillCredit.CreatureEntry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_RESPAWN_GAMEOBJECT:
            {
                GameObjectData const* data = GetGameObjectData(tmp.RespawnGameobject.GOGuid);
                if (!data)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid gameobject (GUID: {}) in SCRIPT_COMMAND_RESPAWN_GAMEOBJECT for script id {}",
                        tableName, tmp.RespawnGameobject.GOGuid, tmp.id);
                    continue;
                }

                GameObjectTemplate const* info = GetGameObjectTemplate(data->id);
                if (!info)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has gameobject with invalid entry (GUID: {} Entry: {}) in SCRIPT_COMMAND_RESPAWN_GAMEOBJECT for script id {}",
                        tableName, tmp.RespawnGameobject.GOGuid, data->id, tmp.id);
                    continue;
                }

                if (info->type == GAMEOBJECT_TYPE_FISHINGNODE ||
                    info->type == GAMEOBJECT_TYPE_FISHINGHOLE ||
                    info->type == GAMEOBJECT_TYPE_DOOR        ||
                    info->type == GAMEOBJECT_TYPE_BUTTON      ||
                    info->type == GAMEOBJECT_TYPE_TRAP)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has gameobject type ({}) unsupported by command SCRIPT_COMMAND_RESPAWN_GAMEOBJECT for script id {}",
                        tableName, info->entry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_TEMP_SUMMON_CREATURE:
            {
                if (!Trinity::IsValidMapCoord(tmp.TempSummonCreature.PosX, tmp.TempSummonCreature.PosY, tmp.TempSummonCreature.PosZ, tmp.TempSummonCreature.Orientation))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid coordinates (X: {} Y: {} Z: {} O: {}) in SCRIPT_COMMAND_TEMP_SUMMON_CREATURE for script id {}",
                        tableName, tmp.TempSummonCreature.PosX, tmp.TempSummonCreature.PosY, tmp.TempSummonCreature.PosZ, tmp.TempSummonCreature.Orientation, tmp.id);
                    continue;
                }

                if (!GetCreatureTemplate(tmp.TempSummonCreature.CreatureEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid creature (Entry: {}) in SCRIPT_COMMAND_TEMP_SUMMON_CREATURE for script id {}",
                        tableName, tmp.TempSummonCreature.CreatureEntry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_OPEN_DOOR:
            case SCRIPT_COMMAND_CLOSE_DOOR:
            {
                GameObjectData const* data = GetGameObjectData(tmp.ToggleDoor.GOGuid);
                if (!data)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid gameobject (GUID: {}) in {} for script id {}",
                        tableName, tmp.ToggleDoor.GOGuid, GetScriptCommandName(tmp.command), tmp.id);
                    continue;
                }

                GameObjectTemplate const* info = GetGameObjectTemplate(data->id);
                if (!info)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has gameobject with invalid entry (GUID: {} Entry: {}) in {} for script id {}",
                        tableName, tmp.ToggleDoor.GOGuid, data->id, GetScriptCommandName(tmp.command), tmp.id);
                    continue;
                }

                if (info->type != GAMEOBJECT_TYPE_DOOR)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has gameobject type ({}) unsupported by command {} for script id {}",
                        tableName, info->entry, GetScriptCommandName(tmp.command), tmp.id);
                    continue;
                }

                break;
            }

            case SCRIPT_COMMAND_REMOVE_AURA:
            {
                if (!sSpellMgr->GetSpellInfo(tmp.RemoveAura.SpellID, DIFFICULTY_NONE))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` using non-existent spell (id: {}) in SCRIPT_COMMAND_REMOVE_AURA for script id {}",
                        tableName, tmp.RemoveAura.SpellID, tmp.id);
                    continue;
                }
                if (tmp.RemoveAura.Flags & ~0x1)                    // 1 bits (0, 1)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` using unknown flags in datalong2 ({}) in SCRIPT_COMMAND_REMOVE_AURA for script id {}",
                        tableName, tmp.RemoveAura.Flags, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_CAST_SPELL:
            {
                if (!sSpellMgr->GetSpellInfo(tmp.CastSpell.SpellID, DIFFICULTY_NONE))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` using non-existent spell (id: {}) in SCRIPT_COMMAND_CAST_SPELL for script id {}",
                        tableName, tmp.CastSpell.SpellID, tmp.id);
                    continue;
                }
                if (tmp.CastSpell.Flags > 4)                      // targeting type
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` using unknown target in datalong2 ({}) in SCRIPT_COMMAND_CAST_SPELL for script id {}",
                        tableName, tmp.CastSpell.Flags, tmp.id);
                    continue;
                }
                if (tmp.CastSpell.Flags != 4 && tmp.CastSpell.CreatureEntry & ~0x1)                      // 1 bit (0, 1)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` using unknown flags in dataint ({}) in SCRIPT_COMMAND_CAST_SPELL for script id {}",
                        tableName, tmp.CastSpell.CreatureEntry, tmp.id);
                    continue;
                }
                else if (tmp.CastSpell.Flags == 4 && !GetCreatureTemplate(tmp.CastSpell.CreatureEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` using invalid creature entry in dataint ({}) in SCRIPT_COMMAND_CAST_SPELL for script id {}",
                        tableName, tmp.CastSpell.CreatureEntry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_CREATE_ITEM:
            {
                if (!GetItemTemplate(tmp.CreateItem.ItemEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has nonexistent item (entry: {}) in SCRIPT_COMMAND_CREATE_ITEM for script id {}",
                        tableName, tmp.CreateItem.ItemEntry, tmp.id);
                    continue;
                }
                if (!tmp.CreateItem.Amount)
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` SCRIPT_COMMAND_CREATE_ITEM but amount is {} for script id {}",
                        tableName, tmp.CreateItem.Amount, tmp.id);
                    continue;
                }
                break;
            }
            case SCRIPT_COMMAND_PLAY_ANIMKIT:
            {
                if (!sAnimKitStore.LookupEntry(tmp.PlayAnimKit.AnimKitID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `{}` has invalid AnimKid id (datalong = {}) in SCRIPT_COMMAND_PLAY_ANIMKIT for script id {}",
                        tableName, tmp.PlayAnimKit.AnimKitID, tmp.id);
                    continue;
                }
                break;
            }
            case SCRIPT_COMMAND_FIELD_SET_DEPRECATED:
            case SCRIPT_COMMAND_FLAG_SET_DEPRECATED:
            case SCRIPT_COMMAND_FLAG_REMOVE_DEPRECATED:
            {
                TC_LOG_ERROR("sql.sql", "Table `{}` uses deprecated direct updatefield modify command {} for script id {}", tableName, GetScriptCommandName(tmp.command), tmp.id);
                continue;
            }
            default:
                break;
        }

        if (scripts->find(tmp.id) == scripts->end())
        {
            ScriptMap emptyMap;
            (*scripts)[tmp.id] = emptyMap;
        }
        (*scripts)[tmp.id].insert(std::pair<uint32, ScriptInfo>(tmp.delay, tmp));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} script definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadSpellScripts()
{
    LoadScripts(SCRIPTS_SPELL);

    // check ids
    for (ScriptMapMap::const_iterator itr = sSpellScripts.begin(); itr != sSpellScripts.end(); ++itr)
    {
        uint32 spellId = uint32(itr->first) & 0x00FFFFFF;
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);

        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `spell_scripts` has not existing spell (Id: {}) as script id", spellId);
            continue;
        }

        SpellEffIndex i = SpellEffIndex((uint32(itr->first) >> 24) & 0x000000FF);
        if (uint32(i) >= spellInfo->GetEffects().size())
        {
            TC_LOG_ERROR("sql.sql", "Table `spell_scripts` has too high effect index {} for spell (Id: {}) as script id", uint32(i), spellId);
            continue;
        }

        //check for correct spellEffect
        if (!spellInfo->GetEffect(i).Effect || (spellInfo->GetEffect(i).Effect != SPELL_EFFECT_SCRIPT_EFFECT && spellInfo->GetEffect(i).Effect != SPELL_EFFECT_DUMMY))
            TC_LOG_ERROR("sql.sql", "Table `spell_scripts` - spell {} effect {} is not SPELL_EFFECT_SCRIPT_EFFECT or SPELL_EFFECT_DUMMY", spellId, uint32(i));
    }
}

void ObjectMgr::LoadEventSet()
{
    _eventStore.clear();

    // Load all possible event ids from gameobjects
    for (auto const& gameObjectTemplatePair : _gameObjectTemplateStore)
    {
        EventContainer eventSet = gameObjectTemplatePair.second.GetEventScriptSet();
        _eventStore.insert(eventSet.begin(), eventSet.end());
    }

    // Load all possible event ids from spells
    for (SpellEffectEntry const* spellEffect : sSpellEffectStore)
        if (spellEffect->Effect == SPELL_EFFECT_SEND_EVENT && spellEffect->EffectMiscValue[0])
            _eventStore.insert(spellEffect->EffectMiscValue[0]);

    // Load all possible event ids from taxi path nodes
    for (TaxiPathNodeEntry const* node : sTaxiPathNodeStore)
    {
        if (node->ArrivalEventID)
            _eventStore.insert(node->ArrivalEventID);

        if (node->DepartureEventID)
            _eventStore.insert(node->DepartureEventID);
    }

    // Load all possible event ids from criterias
    auto addCriteriaEventsToStore = [&](CriteriaList const& criteriaList)
    {
        for (Criteria const* criteria : criteriaList)
            if (criteria->Entry->Asset.EventID)
                _eventStore.insert(criteria->Entry->Asset.EventID);
    };

    std::array<CriteriaType, 2> eventCriteriaTypes = { CriteriaType::PlayerTriggerGameEvent, CriteriaType::AnyoneTriggerGameEventScenario };
    for (CriteriaType criteriaType : eventCriteriaTypes)
    {
        addCriteriaEventsToStore(sCriteriaMgr->GetPlayerCriteriaByType(criteriaType, 0));
        addCriteriaEventsToStore(sCriteriaMgr->GetGuildCriteriaByType(criteriaType));
        addCriteriaEventsToStore(sCriteriaMgr->GetQuestObjectiveCriteriaByType(criteriaType));
    }

    for (ScenarioEntry const* scenario : sScenarioStore)
        for (CriteriaType criteriaType : eventCriteriaTypes)
            addCriteriaEventsToStore(sCriteriaMgr->GetScenarioCriteriaByTypeAndScenario(criteriaType, scenario->ID));

    for (auto const& [gameEventId, _] : sCriteriaMgr->GetCriteriaByStartEvent(CriteriaStartEvent::SendEvent))
        if (gameEventId)
            _eventStore.insert(gameEventId);

    for (auto const& [gameEventId, _] : sCriteriaMgr->GetCriteriaByFailEvent(CriteriaFailEvent::SendEvent))
        if (gameEventId)
            _eventStore.insert(gameEventId);
}

void ObjectMgr::LoadEventScripts()
{
    // Set of valid events referenced in several sources
    LoadEventSet();

    // Deprecated
    LoadScripts(SCRIPTS_EVENT);

    // Then check if all scripts are in above list of possible script entries
    for (ScriptMapMap::const_iterator itr = sEventScripts.begin(); itr != sEventScripts.end(); ++itr)
    {
        if (!IsValidEvent(itr->first))
            TC_LOG_ERROR("sql.sql", "Table `event_scripts` has script (Id: {}) not referring to any gameobject_template (data field referencing GameEvent), any taxi path node, any criteria asset or any spell effect {}",
                itr->first, SPELL_EFFECT_SEND_EVENT);
    }

    uint32 oldMSTime = getMSTime();

    _eventScriptStore.clear(); // Reload case

    QueryResult result = WorldDatabase.Query("SELECT Id, ScriptName FROM event_script_names");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 event scripts. DB table `event_script_names` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 eventId = fields[0].GetUInt32();
        std::string const scriptName = fields[1].GetString();

        if (!IsValidEvent(eventId))
        {
            TC_LOG_ERROR("sql.sql", "Event (ID: {}) not referring to any gameobject_template (data field referencing GameEvent), any taxi path node, any criteria asset or any spell effect {}",
                eventId, SPELL_EFFECT_SEND_EVENT);
            continue;
        }
        _eventScriptStore[eventId] = GetScriptId(scriptName);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} event scripts in {} ms", _eventScriptStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadSpellScriptNames()
{
    uint32 oldMSTime = getMSTime();

    _spellScriptsStore.clear();                            // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT spell_id, ScriptName FROM spell_script_names");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell script names. DB table `spell_script_names` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {

        Field* fields = result->Fetch();

        int32 spellId                = fields[0].GetInt32();
        std::string const scriptName = fields[1].GetString();

        bool allRanks = false;
        if (spellId < 0)
        {
            allRanks = true;
            spellId = -spellId;
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Scriptname: `{}` spell (Id: {}) does not exist.", scriptName, fields[0].GetInt32());
            continue;
        }

        if (allRanks)
        {
            if (!spellInfo->IsRanked())
                TC_LOG_ERROR("sql.sql", "Scriptname: `{}` spell (Id: {}) has no ranks of spell.", scriptName, fields[0].GetInt32());

            if (spellInfo->GetFirstRankSpell()->Id != uint32(spellId))
            {
                TC_LOG_ERROR("sql.sql", "Scriptname: `{}` spell (Id: {}) is not first rank of spell.", scriptName, fields[0].GetInt32());
                continue;
            }
            while (spellInfo)
            {
                _spellScriptsStore.insert(SpellScriptsContainer::value_type(spellInfo->Id, std::make_pair(GetScriptId(scriptName), true)));
                spellInfo = spellInfo->GetNextRankSpell();
            }
        }
        else
        {
            if (spellInfo->IsRanked())
                TC_LOG_ERROR("sql.sql", "Scriptname: `{}` spell (Id: {}) is ranked spell. Perhaps not all ranks are assigned to this script.", scriptName, spellId);

            _spellScriptsStore.insert(SpellScriptsContainer::value_type(spellInfo->Id, std::make_pair(GetScriptId(scriptName), true)));
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spell script names in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::ValidateSpellScripts()
{
    uint32 oldMSTime = getMSTime();

    if (_spellScriptsStore.empty())
    {
        TC_LOG_INFO("server.loading", ">> Validated 0 scripts.");
        return;
    }

    uint32 count = 0;

    for (auto& spell : _spellScriptsStore)
    {
        SpellInfo const* spellEntry = sSpellMgr->AssertSpellInfo(spell.first, DIFFICULTY_NONE);

        if (SpellScriptLoader* spellScriptLoader = sScriptMgr->GetSpellScriptLoader(spell.second.first))
        {
            ++count;

            std::unique_ptr<SpellScript> spellScript(spellScriptLoader->GetSpellScript());
            std::unique_ptr<AuraScript> auraScript(spellScriptLoader->GetAuraScript());

            if (!spellScript && !auraScript)
            {
                TC_LOG_ERROR("scripts", "Functions GetSpellScript() and GetAuraScript() of script `{}` do not return objects - script skipped", GetScriptName(spell.second.first));

                spell.second.second = false;
                continue;
            }

            if (spellScript)
            {
                spellScript->_Init(spellScriptLoader->GetName(), spellEntry->Id);
                spellScript->_Register();

                if (!spellScript->_Validate(spellEntry))
                {
                    spell.second.second = false;
                    continue;
                }
            }

            if (auraScript)
            {
                auraScript->_Init(spellScriptLoader->GetName(), spellEntry->Id);
                auraScript->_Register();

                if (!auraScript->_Validate(spellEntry))
                {
                    spell.second.second = false;
                    continue;
                }
            }

            // Enable the script when all checks passed
            spell.second.second = true;
        }
        else
            spell.second.second = false;
    }

    TC_LOG_INFO("server.loading", ">> Validated {} scripts in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPageTexts()
{
    uint32 oldMSTime = getMSTime();

    //                                               0    1     2           3                  4
    QueryResult result = WorldDatabase.Query("SELECT ID, `Text`, NextPageID, PlayerConditionID, Flags FROM page_text");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 page texts. DB table `page_text` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id           = fields[0].GetUInt32();

        PageText& pageText = _pageTextStore[id];
        pageText.Text       = fields[1].GetString();
        pageText.NextPageID = fields[2].GetUInt32();
        pageText.PlayerConditionID = fields[3].GetInt32();
        pageText.Flags = fields[4].GetUInt8();

        ++count;
    }
    while (result->NextRow());

    for (PageTextContainer::const_iterator itr = _pageTextStore.begin(); itr != _pageTextStore.end(); ++itr)
        if (itr->second.NextPageID)
            if (_pageTextStore.find(itr->second.NextPageID) == _pageTextStore.end())
                TC_LOG_ERROR("sql.sql", "Page text (ID: {}) has non-existing `NextPageID` ({})", itr->first, itr->second.NextPageID);

    TC_LOG_INFO("server.loading", ">> Loaded {} page texts in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

PageText const* ObjectMgr::GetPageText(uint32 pageEntry)
{
    PageTextContainer::const_iterator itr = _pageTextStore.find(pageEntry);
    if (itr != _pageTextStore.end())
        return &(itr->second);

    return nullptr;
}

void ObjectMgr::LoadPageTextLocales()
{
    uint32 oldMSTime = getMSTime();

    _pageTextLocaleStore.clear(); // needed for reload case

    //                                               0      1      2
    QueryResult result = WorldDatabase.Query("SELECT ID, locale, `Text` FROM page_text_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        std::string_view localeName = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        PageTextLocale& data = _pageTextLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.Text);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} PageText locale strings in {} ms", uint32(_pageTextLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadInstanceTemplate()
{
    uint32 oldMSTime = getMSTime();

    //                                                0     1       2
    QueryResult result = WorldDatabase.Query("SELECT map, parent, script FROM instance_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 instance templates. DB table `page_text` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint16 mapID = fields[0].GetUInt16();

        if (!MapManager::IsValidMAP(mapID))
        {
            TC_LOG_ERROR("sql.sql", "ObjectMgr::LoadInstanceTemplate: bad mapid {} for template!", mapID);
            continue;
        }

        InstanceTemplate instanceTemplate;

        instanceTemplate.Parent     = uint32(fields[1].GetUInt16());
        instanceTemplate.ScriptId   = GetScriptId(fields[2].GetString());

        _instanceTemplateStore[mapID] = instanceTemplate;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} instance templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

InstanceTemplate const* ObjectMgr::GetInstanceTemplate(uint32 mapID) const
{
    InstanceTemplateContainer::const_iterator itr = _instanceTemplateStore.find(uint16(mapID));
    if (itr != _instanceTemplateStore.end())
        return &(itr->second);

    return nullptr;
}

NpcText const* ObjectMgr::GetNpcText(uint32 Text_ID) const
{
    NpcTextContainer::const_iterator itr = _npcTextStore.find(Text_ID);
    if (itr != _npcTextStore.end())
        return &itr->second;
    return nullptr;
}

void ObjectMgr::LoadNPCText()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT ID, "
        "Probability0, Probability1, Probability2, Probability3, Probability4, Probability5, Probability6, Probability7, "
        "BroadcastTextID0, BroadcastTextID1, BroadcastTextID2, BroadcastTextID3, BroadcastTextID4, BroadcastTextID5, BroadcastTextID6, BroadcastTextID7"
        " FROM npc_text");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 npc texts, table is empty!");
        return;
    }

    _npcTextStore.reserve(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        uint32 textID = fields[0].GetUInt32();
        if (!textID)
        {
            TC_LOG_ERROR("sql.sql", "Table `npc_text` has record with reserved id 0, ignore.");
            continue;
        }

        NpcText npcText;

        for (uint8 i = 0; i < MAX_NPC_TEXT_OPTIONS; ++i)
        {
            npcText.Data[i].Probability      = fields[1 + i].GetFloat();
            npcText.Data[i].BroadcastTextID  = fields[9 + i].GetUInt32();
        }

        for (uint8 i = 0; i < MAX_NPC_TEXT_OPTIONS; i++)
        {
            if (npcText.Data[i].BroadcastTextID)
            {
                if (!sBroadcastTextStore.LookupEntry(npcText.Data[i].BroadcastTextID))
                {
                    TC_LOG_ERROR("sql.sql", "NPCText (ID: {}) has a non-existing BroadcastText (ID: {}, Index: {})", textID, npcText.Data[i].BroadcastTextID, i);
                    npcText.Data[i].Probability = 0.0f;
                    npcText.Data[i].BroadcastTextID = 0;
                }
            }
        }

        for (uint8 i = 0; i < MAX_NPC_TEXT_OPTIONS; i++)
        {
            if (npcText.Data[i].Probability > 0 && npcText.Data[i].BroadcastTextID == 0)
            {
                TC_LOG_ERROR("sql.sql", "NPCText (ID: {}) has a probability (Index: {}) set, but no BroadcastTextID to go with it", textID, i);
                npcText.Data[i].Probability = 0;
            }
        }

        float probabilitySum = std::accumulate(std::begin(npcText.Data), std::end(npcText.Data), 0.0f, [](float sum, NpcTextData const& data) { return sum + data.Probability; });
        if (probabilitySum <= 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "NPCText (ID: {}) has a probability sum 0, no text can be selected from it, skipped.", textID);
            continue;
        }

        _npcTextStore[textID] = npcText;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} npc texts in {} ms", uint32(_npcTextStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

//not very fast function but it is called only once a day, or on starting-up
void ObjectMgr::ReturnOrDeleteOldMails(bool serverUp)
{
    uint32 oldMSTime = getMSTime();

    time_t curTime = GameTime::GetGameTime();
    tm lt;
    localtime_r(&curTime, &lt);
    TC_LOG_INFO("misc", "Returning mails current time: hour: {}, minute: {}, second: {} ", lt.tm_hour, lt.tm_min, lt.tm_sec);

    // Delete all old mails without item and without body immediately, if starting server
    if (!serverUp)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EMPTY_EXPIRED_MAIL);
        stmt->setInt64(0, curTime);
        CharacterDatabase.Execute(stmt);
    }
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_EXPIRED_MAIL);
    stmt->setInt64(0, curTime);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> No expired mails found.");
        return;                                             // any mails need to be returned or deleted
    }

    std::map<uint64 /*messageId*/, MailItemInfoVec> itemsCache;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_EXPIRED_MAIL_ITEMS);
    stmt->setUInt32(0, curTime);
    if (PreparedQueryResult items = CharacterDatabase.Query(stmt))
    {
        MailItemInfo item;
        do
        {
            Field* fields = items->Fetch();
            item.item_guid = fields[0].GetUInt64();
            item.item_template = fields[1].GetUInt32();
            uint64 mailId = fields[2].GetUInt64();
            itemsCache[mailId].push_back(item);
        } while (items->NextRow());
    }

    uint32 deletedCount = 0;
    uint32 returnedCount = 0;
    do
    {
        Field* fields = result->Fetch();
        ObjectGuid::LowType receiver = fields[3].GetUInt64();
        if (serverUp && ObjectAccessor::FindConnectedPlayer(ObjectGuid::Create<HighGuid::Player>(receiver)))
            continue;

        Mail* m = new Mail;
        m->messageID      = fields[0].GetUInt64();
        m->messageType    = fields[1].GetUInt8();
        m->sender         = fields[2].GetUInt64();
        m->receiver       = receiver;
        bool has_items    = fields[4].GetBool();
        m->expire_time    = fields[5].GetInt64();
        m->deliver_time   = 0;
        m->COD            = fields[6].GetUInt64();
        m->checked        = fields[7].GetUInt8();
        m->mailTemplateId = fields[8].GetInt16();

        // Delete or return mail
        if (has_items)
        {
            // read items from cache
            m->items.swap(itemsCache[m->messageID]);

            // if it is mail from non-player, or if it's already return mail, it shouldn't be returned, but deleted
            if (m->messageType != MAIL_NORMAL || (m->checked & (MAIL_CHECK_MASK_COD_PAYMENT | MAIL_CHECK_MASK_RETURNED)))
            {
                CharacterDatabaseTransaction nonTransactional(nullptr);
                // mail open and then not returned
                for (MailItemInfoVec::iterator itr2 = m->items.begin(); itr2 != m->items.end(); ++itr2)
                {
                    Item::DeleteFromDB(nonTransactional, itr2->item_guid);
                    AzeriteItem::DeleteFromDB(nonTransactional, itr2->item_guid);
                    AzeriteEmpoweredItem::DeleteFromDB(nonTransactional, itr2->item_guid);
                }

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
                stmt->setUInt64(0, m->messageID);
                CharacterDatabase.Execute(stmt);
            }
            else
            {
                // Mail will be returned
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_RETURNED);
                stmt->setUInt64(0, m->receiver);
                stmt->setUInt64(1, m->sender);
                stmt->setInt64 (2, curTime + 30 * DAY);
                stmt->setInt64 (3, curTime);
                stmt->setUInt8 (4, uint8(MAIL_CHECK_MASK_RETURNED));
                stmt->setUInt64(5, m->messageID);
                CharacterDatabase.Execute(stmt);
                for (MailItemInfoVec::iterator itr2 = m->items.begin(); itr2 != m->items.end(); ++itr2)
                {
                    // Update receiver in mail items for its proper delivery, and in instance_item for avoid lost item at sender delete
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_ITEM_RECEIVER);
                    stmt->setUInt64(0, m->sender);
                    stmt->setUInt64(1, itr2->item_guid);
                    CharacterDatabase.Execute(stmt);

                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
                    stmt->setUInt64(0, m->sender);
                    stmt->setUInt64(1, itr2->item_guid);
                    CharacterDatabase.Execute(stmt);
                }
                delete m;
                ++returnedCount;
                continue;
            }
        }

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_BY_ID);
        stmt->setUInt64(0, m->messageID);
        CharacterDatabase.Execute(stmt);
        delete m;
        ++deletedCount;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Processed {} expired mails: {} deleted and {} returned in {} ms", deletedCount + returnedCount, deletedCount, returnedCount, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestAreaTriggers()
{
    uint32 oldMSTime = getMSTime();

    _questAreaTriggerStore.clear();                           // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT id, quest FROM areatrigger_involvedrelation");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 quest trigger points. DB table `areatrigger_involvedrelation` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        ++count;

        Field* fields = result->Fetch();

        uint32 trigger_ID = fields[0].GetUInt32();
        uint32 quest_ID   = fields[1].GetUInt32();

        AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(trigger_ID);
        if (!atEntry)
        {
            TC_LOG_ERROR("sql.sql", "Area trigger (ID:{}) does not exist in `AreaTrigger.dbc`.", trigger_ID);
            continue;
        }

        Quest const* quest = GetQuestTemplate(quest_ID);

        if (!quest)
        {
            TC_LOG_ERROR("sql.sql", "Table `areatrigger_involvedrelation` has record (id: {}) for not existing quest {}", trigger_ID, quest_ID);
            continue;
        }

        if (!quest->HasFlag(QUEST_FLAGS_COMPLETION_AREA_TRIGGER) && !quest->HasQuestObjectiveType(QUEST_OBJECTIVE_AREATRIGGER))
        {
            TC_LOG_ERROR("sql.sql", "Table `areatrigger_involvedrelation` has record (id: {}) for not quest {}, but quest not have flag QUEST_FLAGS_COMPLETION_AREA_TRIGGER and no objective with type QUEST_OBJECTIVE_AREATRIGGER. Trigger is obsolete, skipped.", trigger_ID, quest_ID);
            continue;
        }

        _questAreaTriggerStore[trigger_ID].insert(quest_ID);

    } while (result->NextRow());

    for (auto const& pair : _questObjectives)
    {
        QuestObjective const* objective = pair.second;
        if (objective->Type == QUEST_OBJECTIVE_AREATRIGGER)
            _questAreaTriggerStore[objective->ObjectID].insert(objective->QuestID);
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} quest trigger points in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

QuestGreeting const* ObjectMgr::GetQuestGreeting(TypeID type, uint32 id) const
{
    uint32 typeIndex;
    if (type == TYPEID_UNIT)
        typeIndex = 0;
    else if (type == TYPEID_GAMEOBJECT)
        typeIndex = 1;
    else
        return nullptr;

    return Trinity::Containers::MapGetValuePtr(_questGreetingStore[typeIndex], id);
}

QuestGreetingLocale const* ObjectMgr::GetQuestGreetingLocale(TypeID type, uint32 id) const
{
    uint32 typeIndex;
    if (type == TYPEID_UNIT)
        typeIndex = 0;
    else if (type == TYPEID_GAMEOBJECT)
        typeIndex = 1;
    else
        return nullptr;

    return Trinity::Containers::MapGetValuePtr(_questGreetingLocaleStore[typeIndex], id);
}

void ObjectMgr::LoadQuestGreetings()
{
    uint32 oldMSTime = getMSTime();

    for (std::size_t i = 0; i < _questGreetingStore.size(); ++i)
        _questGreetingStore[i].clear();

    //                                                0   1          2                3
    QueryResult result = WorldDatabase.Query("SELECT ID, type, GreetEmoteType, GreetEmoteDelay, Greeting FROM quest_greeting");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 npc texts, table is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        uint8 type                  = fields[1].GetUInt8();
        switch (type)
        {
            case 0: // Creature
                if (!GetCreatureTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_greeting`: creature template entry {} does not exist.", id);
                    continue;
                }
                break;
            case 1: // GameObject
                if (!GetGameObjectTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_greeting`: gameobject template entry {} does not exist.", id);
                    continue;
                }
                break;
            default:
                continue;
        }

        uint16 greetEmoteType       = fields[2].GetUInt16();
        uint32 greetEmoteDelay      = fields[3].GetUInt32();
        std::string greeting        = fields[4].GetString();

        _questGreetingStore[type].emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(greetEmoteType, greetEmoteDelay, std::move(greeting)));
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} quest_greeting in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadTavernAreaTriggers()
{
    uint32 oldMSTime = getMSTime();

    _tavernAreaTriggerStore.clear();                          // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT id FROM areatrigger_tavern");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 tavern triggers. DB table `areatrigger_tavern` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        ++count;

        Field* fields = result->Fetch();

        uint32 Trigger_ID      = fields[0].GetUInt32();

        AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(Trigger_ID);
        if (!atEntry)
        {
            TC_LOG_ERROR("sql.sql", "Area trigger (ID:{}) does not exist in `AreaTrigger.dbc`.", Trigger_ID);
            continue;
        }

        _tavernAreaTriggerStore.insert(Trigger_ID);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} tavern triggers in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadAreaTriggerScripts()
{
    uint32 oldMSTime = getMSTime();

    _areaTriggerScriptStore.clear();                            // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, ScriptName FROM areatrigger_scripts");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 areatrigger scripts. DB table `areatrigger_scripts` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 triggerId             = fields[0].GetUInt32();
        std::string const scriptName = fields[1].GetString();

        AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(triggerId);
        if (!atEntry)
        {
            TC_LOG_ERROR("sql.sql", "AreaTrigger (ID: {}) does not exist in `AreaTrigger.dbc`.", triggerId);
            continue;
        }
        _areaTriggerScriptStore[triggerId] = GetScriptId(scriptName);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} areatrigger scripts in {} ms", _areaTriggerScriptStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

uint32 ObjectMgr::GetNearestTaxiNode(float x, float y, float z, uint32 mapid, uint32 team)
{
    bool found = false;
    float dist = 10000;
    uint32 id = 0;

    TaxiNodeFlags requireFlag = (team == ALLIANCE) ? TaxiNodeFlags::ShowOnAllianceMap : TaxiNodeFlags::ShowOnHordeMap;
    for (TaxiNodesEntry const* node : sTaxiNodesStore)
    {
        if (!node || node->ContinentID != mapid || !node->GetFlags().HasFlag(requireFlag) || node->GetFlags().HasFlag(TaxiNodeFlags::IgnoreForFindNearest))
            continue;

        uint32 field   = uint32((node->ID - 1) / 8);
        uint32 submask = 1 << ((node->ID - 1) % 8);

        // skip not taxi network nodes
        if ((sTaxiNodesMask[field] & submask) == 0)
            continue;

        float dist2 = (node->Pos.X - x)*(node->Pos.X - x) + (node->Pos.Y - y)*(node->Pos.Y - y) + (node->Pos.Z - z)*(node->Pos.Z - z);
        if (found)
        {
            if (dist2 < dist)
            {
                dist = dist2;
                id = node->ID;
            }
        }
        else
        {
            found = true;
            dist = dist2;
            id = node->ID;
        }
    }

    return id;
}

void ObjectMgr::GetTaxiPath(uint32 source, uint32 destination, uint32 &path, uint32 &cost)
{
    TaxiPathEntry const* taxiPath = sDB2Manager.GetTaxiPath(source, destination);
    if (taxiPath)
    {
        path = taxiPath->ID;
        cost = taxiPath->Cost;
    }
    else
    {
        path = 0;
        cost = 0;
    }
}

uint32 ObjectMgr::GetTaxiMountDisplayId(uint32 id, uint32 team, bool allowed_alt_team /* = false */)
{
    CreatureModel mountModel;
    CreatureTemplate const* mount_info = nullptr;

    // select mount creature id
    TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(id);
    if (node)
    {
        uint32 mount_entry = 0;
        if (team == ALLIANCE)
            mount_entry = node->MountCreatureID[1];
        else
            mount_entry = node->MountCreatureID[0];

        // Fix for Alliance not being able to use Acherus taxi
        // only one mount type for both sides
        if (mount_entry == 0 && allowed_alt_team)
        {
            // Simply reverse the selection. At least one team in theory should have a valid mount ID to choose.
            mount_entry = team == ALLIANCE ? node->MountCreatureID[0] : node->MountCreatureID[1];
        }

        mount_info = GetCreatureTemplate(mount_entry);
        if (mount_info)
        {
            CreatureModel const* model = mount_info->GetRandomValidModel();
            if (!model)
            {
                TC_LOG_ERROR("sql.sql", "No displayid found for the taxi mount with the entry {}! Can't load it!", mount_entry);
                return 0;
            }
            mountModel = *model;
        }
    }

    // minfo is not actually used but the mount_id was updated
    GetCreatureModelRandomGender(&mountModel, mount_info);

    return mountModel.CreatureDisplayID;
}

Quest const* ObjectMgr::GetQuestTemplate(uint32 quest_id) const
{
    return Trinity::Containers::MapGetValuePtr(_questTemplates, quest_id);
}

void ObjectMgr::LoadGraveyardZones()
{
    uint32 oldMSTime = getMSTime();

    GraveyardStore.clear(); // needed for reload case

    //                                               0   1
    QueryResult result = WorldDatabase.Query("SELECT ID, GhostZone FROM graveyard_zone");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 graveyard-zone links. DB table `graveyard_zone` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        ++count;

        Field* fields = result->Fetch();

        uint32 safeLocId = fields[0].GetUInt32();
        uint32 zoneId = fields[1].GetUInt32();

        WorldSafeLocsEntry const* entry = GetWorldSafeLoc(safeLocId);
        if (!entry)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a record for non-existing graveyard (WorldSafeLocsID: {}), skipped.", safeLocId);
            continue;
        }

        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId);
        if (!areaEntry)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a record for non-existing Zone (ID: {}), skipped.", zoneId);
            continue;
        }

        if (!AddGraveyardLink(safeLocId, zoneId, 0, false))
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a duplicate record for Graveyard (ID: {}) and Zone (ID: {}), skipped.", safeLocId, zoneId);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} graveyard-zone links in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

WorldSafeLocsEntry const* ObjectMgr::GetDefaultGraveyard(uint32 team) const
{
    enum DefaultGraveyard
    {
        HORDE_GRAVEYARD    = 10, // Crossroads
        ALLIANCE_GRAVEYARD = 4   // Westfall
    };

    if (team == HORDE)
        return GetWorldSafeLoc(HORDE_GRAVEYARD);
    else if (team == ALLIANCE)
        return GetWorldSafeLoc(ALLIANCE_GRAVEYARD);
    else return nullptr;
}

WorldSafeLocsEntry const* ObjectMgr::GetClosestGraveyard(WorldLocation const& location, uint32 team, WorldObject* conditionObject) const
{
    float x, y, z;
    location.GetPosition(x, y, z);
    uint32 MapId = location.GetMapId();

    // search for zone associated closest graveyard
    uint32 zoneId = sTerrainMgr.GetZoneId(conditionObject ? conditionObject->GetPhaseShift() : PhasingHandler::GetEmptyPhaseShift(), MapId, x, y, z);

    if (!zoneId)
    {
        if (z > -500)
        {
            TC_LOG_ERROR("misc", "ZoneId not found for map {} coords ({}, {}, {})", MapId, x, y, z);
            return GetDefaultGraveyard(team);
        }
    }

    WorldSafeLocsEntry const* graveyard = GetClosestGraveyardInZone(location, team, conditionObject, zoneId);
    AreaTableEntry const* zoneEntry = sAreaTableStore.AssertEntry(zoneId);
    AreaTableEntry const* parentEntry = sAreaTableStore.LookupEntry(zoneEntry->ParentAreaID);

    while (!graveyard && parentEntry)
    {
        graveyard = GetClosestGraveyardInZone(location, team, conditionObject, parentEntry->ID);
        if (!graveyard && parentEntry->ParentAreaID != 0)
            parentEntry = sAreaTableStore.LookupEntry(parentEntry->ParentAreaID);
        else // nothing found, cant look further, give up.
            parentEntry = nullptr;
    }

    return graveyard;
}

WorldSafeLocsEntry const* ObjectMgr::GetClosestGraveyardInZone(WorldLocation const& location, uint32 team, WorldObject* conditionObject, uint32 zoneId) const
{
    float x, y, z;
    location.GetPosition(x, y, z);
    uint32 MapId = location.GetMapId();

    // Simulate std. algorithm:
    //   found some graveyard associated to (ghost_zone, ghost_map)
    //
    //   if mapId == graveyard.mapId (ghost in plain zone or city or battleground) and search graveyard at same map
    //     then check faction
    //   if mapId != graveyard.mapId (ghost in instance) and search any graveyard associated
    //     then check faction
    GraveyardMapBounds range = GraveyardStore.equal_range(zoneId);
    MapEntry const* mapEntry = sMapStore.LookupEntry(MapId);

    // not need to check validity of map object; MapId _MUST_ be valid here
    if (range.first == range.second && !mapEntry->IsBattlegroundOrArena())
    {
        if (zoneId != 0) // zone == 0 can't be fixed, used by bliz for bugged zones
            TC_LOG_ERROR("sql.sql", "Table `game_graveyard_zone` incomplete: Zone {} Team {} does not have a linked graveyard.", zoneId, team);
        return GetDefaultGraveyard(team);
    }

    // at corpse map
    bool foundNear = false;
    float distNear = 10000;
    WorldSafeLocsEntry const* entryNear = nullptr;

    // at entrance map for corpse map
    bool foundEntr = false;
    float distEntr = 10000;
    WorldSafeLocsEntry const* entryEntr = nullptr;

    // some where other
    WorldSafeLocsEntry const* entryFar = nullptr;

    ConditionSourceInfo conditionSource(conditionObject);

    for (; range.first != range.second; ++range.first)
    {
        GraveyardData const& data = range.first->second;

        WorldSafeLocsEntry const* entry = ASSERT_NOTNULL(GetWorldSafeLoc(data.safeLocId));

        if (conditionObject)
        {
            if (!data.Conditions.Meets(conditionSource))
                continue;

            if (int16(entry->Loc.GetMapId()) == mapEntry->ParentMapID && !conditionObject->GetPhaseShift().HasVisibleMapId(entry->Loc.GetMapId()))
                continue;
        }
        else if (team != 0)
        {
            bool teamConditionMet = true;
            if (std::shared_ptr<std::vector<Condition>> conditions = data.Conditions.Conditions.lock())
            {
                for (Condition const& cond : *conditions)
                {
                    if (cond.ConditionType != CONDITION_TEAM)
                        continue;

                    if (cond.ConditionValue1 == team)
                        continue;

                    teamConditionMet = false;
                }
            }

            if (!teamConditionMet)
                continue;
        }

        // find now nearest graveyard at other map
        if (MapId != entry->Loc.GetMapId() && int16(entry->Loc.GetMapId()) != mapEntry->ParentMapID)
        {
            // if find graveyard at different map from where entrance placed (or no entrance data), use any first
            if (!mapEntry
                || mapEntry->CorpseMapID < 0
                || uint32(mapEntry->CorpseMapID) != entry->Loc.GetMapId()
                || (mapEntry->Corpse.X == 0 && mapEntry->Corpse.Y == 0)) // Check X and Y
            {
                // not have any corrdinates for check distance anyway
                entryFar = entry;
                continue;
            }

            // at entrance map calculate distance (2D);
            float dist2 = (entry->Loc.GetPositionX() - mapEntry->Corpse.X) * (entry->Loc.GetPositionX() - mapEntry->Corpse.X)
                + (entry->Loc.GetPositionY() - mapEntry->Corpse.Y) * (entry->Loc.GetPositionY() - mapEntry->Corpse.Y);
            if (foundEntr)
            {
                if (dist2 < distEntr)
                {
                    distEntr = dist2;
                    entryEntr = entry;
                }
            }
            else
            {
                foundEntr = true;
                distEntr = dist2;
                entryEntr = entry;
            }
        }
        // find now nearest graveyard at same map
        else
        {
            float dist2 = (entry->Loc.GetPositionX() - x) * (entry->Loc.GetPositionX() - x)
                + (entry->Loc.GetPositionY() - y) * (entry->Loc.GetPositionY() - y)
                + (entry->Loc.GetPositionZ() - z) * (entry->Loc.GetPositionZ() - z);
            if (foundNear)
            {
                if (dist2 < distNear)
                {
                    distNear = dist2;
                    entryNear = entry;
                }
            }
            else
            {
                foundNear = true;
                distNear = dist2;
                entryNear = entry;
            }
        }
    }

    if (entryNear)
        return entryNear;

    if (entryEntr)
        return entryEntr;

    return entryFar;
}

GraveyardData const* ObjectMgr::FindGraveyardData(uint32 id, uint32 zoneId) const
{
    GraveyardMapBounds range = GraveyardStore.equal_range(zoneId);
    for (; range.first != range.second; ++range.first)
    {
        GraveyardData const& data = range.first->second;
        if (data.safeLocId == id)
            return &data;
    }
    return nullptr;
}

void ObjectMgr::LoadWorldSafeLocs()
{
    uint32 oldMSTime = getMSTime();

    //                                                   0   1      2     3     4     5
    if (QueryResult result = WorldDatabase.Query("SELECT ID, MapID, LocX, LocY, LocZ, Facing FROM world_safe_locs"))
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 id = fields[0].GetUInt32();
            WorldLocation loc(fields[1].GetUInt32(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat(), DegToRad(fields[5].GetFloat()));
            if (!MapManager::IsValidMapCoord(loc))
            {
                TC_LOG_ERROR("sql.sql", "World location (ID: {}) has a invalid position MapID: {} {}, skipped", id, loc.GetMapId(), loc.ToString());
                continue;
            }

            WorldSafeLocsEntry& worldSafeLocs = _worldSafeLocs[id];
            worldSafeLocs.ID = id;
            worldSafeLocs.Loc.WorldRelocate(loc);

        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} world locations {} ms", _worldSafeLocs.size(), GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 world locations. DB table `world_safe_locs` is empty.");
}

WorldSafeLocsEntry const* ObjectMgr::GetWorldSafeLoc(uint32 id) const
{
    return Trinity::Containers::MapGetValuePtr(_worldSafeLocs, id);
}

Trinity::IteratorPair<std::unordered_map<uint32, WorldSafeLocsEntry>::const_iterator> ObjectMgr::GetWorldSafeLocs() const
{
    return std::make_pair(_worldSafeLocs.begin(), _worldSafeLocs.end());
}

AreaTriggerStruct const* ObjectMgr::GetAreaTrigger(uint32 trigger) const
{
    AreaTriggerContainer::const_iterator itr = _areaTriggerStore.find(trigger);
    if (itr != _areaTriggerStore.end())
        return &itr->second;
    return nullptr;
}

AccessRequirement const* ObjectMgr::GetAccessRequirement(uint32 mapid, Difficulty difficulty) const
{
    return Trinity::Containers::MapGetValuePtr(_accessRequirementStore, MAKE_PAIR64(mapid, difficulty));
}

bool ObjectMgr::AddGraveyardLink(uint32 id, uint32 zoneId, uint32 team, bool persist /*= true*/)
{
    if (FindGraveyardData(id, zoneId))
        return false;

    // add link to loaded data
    GraveyardData data;
    data.safeLocId = id;

    GraveyardStore.insert(GraveyardContainer::value_type(zoneId, data));

    // add link to DB
    if (persist)
    {
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_GRAVEYARD_ZONE);

        stmt->setUInt32(0, id);
        stmt->setUInt32(1, zoneId);

        WorldDatabase.Execute(stmt);

        // Store graveyard condition if team is set
        if (team != 0)
        {
            WorldDatabasePreparedStatement* conditionStmt = WorldDatabase.GetPreparedStatement(WORLD_INS_CONDITION);
            conditionStmt->setUInt32(0, CONDITION_SOURCE_TYPE_GRAVEYARD); // SourceTypeOrReferenceId
            conditionStmt->setUInt32(1, zoneId); // SourceGroup
            conditionStmt->setUInt32(2, id); // SourceEntry
            conditionStmt->setUInt32(3, 0); // SourceId
            conditionStmt->setUInt32(4, 0); // ElseGroup
            conditionStmt->setUInt32(5, CONDITION_TEAM); // ConditionTypeOrReference
            conditionStmt->setUInt8(6, 0); // ConditionTarget
            conditionStmt->setUInt32(7, team); // ConditionValue1
            conditionStmt->setUInt32(8, 0); // ConditionValue2
            conditionStmt->setUInt32(9, 0); // ConditionValue3
            conditionStmt->setUInt8(10, 0); // NegativeCondition
            conditionStmt->setUInt32(11, 0); // ErrorType
            conditionStmt->setUInt32(12, 0); // ErrorTextId
            conditionStmt->setString(13, ""); // ScriptName
            conditionStmt->setString(14, ""); // Comment

            WorldDatabase.Execute(conditionStmt);

            // reload conditions to make sure everything is loaded as it should be
            sConditionMgr->LoadConditions(true);
            sScriptMgr->NotifyScriptIDUpdate();
        }
    }

    return true;
}

void ObjectMgr::LoadAreaTriggerTeleports()
{
    uint32 oldMSTime = getMSTime();

    _areaTriggerStore.clear(); // needed for reload case

    //                                               0   1
    QueryResult result = WorldDatabase.Query("SELECT ID, PortLocID FROM areatrigger_teleport");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 area trigger teleport definitions. DB table `areatrigger_teleport` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        ++count;

        uint32 Trigger_ID = fields[0].GetUInt32();
        uint32 PortLocID  = fields[1].GetUInt32();

        WorldSafeLocsEntry const* portLoc = GetWorldSafeLoc(PortLocID);
        if (!portLoc)
        {
            TC_LOG_ERROR("sql.sql", "Area Trigger (ID: {}) has a non-existing Port Loc (ID: {}) in WorldSafeLocs.dbc, skipped", Trigger_ID, PortLocID);
            continue;
        }

        AreaTriggerStruct at;

        at.target_mapId       = portLoc->Loc.GetMapId();
        at.target_X           = portLoc->Loc.GetPositionX();
        at.target_Y           = portLoc->Loc.GetPositionY();
        at.target_Z           = portLoc->Loc.GetPositionZ();
        at.target_Orientation = portLoc->Loc.GetOrientation();

        AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(Trigger_ID);
        if (!atEntry)
        {
            TC_LOG_ERROR("sql.sql", "Area Trigger (ID: {}) does not exist in AreaTrigger.dbc.", Trigger_ID);
            continue;
        }

        _areaTriggerStore[Trigger_ID] = at;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} area trigger teleport definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadAccessRequirements()
{
    uint32 oldMSTime = getMSTime();

    _accessRequirementStore.clear();                                  // need for reload case

    //                                                 0       1           2          3        4      5       6               7                8                   9
    QueryResult result = WorldDatabase.Query("SELECT mapid, difficulty, level_min, level_max, item, item2, quest_done_A, quest_done_H, completed_achievement, quest_failed_text FROM access_requirement");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 access requirement definitions. DB table `access_requirement` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 mapid = fields[0].GetUInt32();
        if (!sMapStore.LookupEntry(mapid))
        {
            TC_LOG_ERROR("sql.sql", "Map {} referenced in `access_requirement` does not exist, skipped.", mapid);
            continue;
        }

        uint32 difficulty = fields[1].GetUInt8();
        if (!sDB2Manager.GetMapDifficultyData(mapid, Difficulty(difficulty)))
        {
            TC_LOG_ERROR("sql.sql", "Map {} referenced in `access_requirement` does not have difficulty {}, skipped", mapid, difficulty);
            continue;
        }

        uint64 requirement_ID = MAKE_PAIR64(mapid, difficulty);

        AccessRequirement* ar = &_accessRequirementStore[requirement_ID];
        ar->levelMin            = fields[2].GetUInt8();
        ar->levelMax            = fields[3].GetUInt8();
        ar->item                = fields[4].GetUInt32();
        ar->item2               = fields[5].GetUInt32();
        ar->quest_A             = fields[6].GetUInt32();
        ar->quest_H             = fields[7].GetUInt32();
        ar->achievement         = fields[8].GetUInt32();
        ar->questFailedText     = fields[9].GetString();

        if (ar->item)
        {
            ItemTemplate const* pProto = GetItemTemplate(ar->item);
            if (!pProto)
            {
                TC_LOG_ERROR("sql.sql", "Key item {} does not exist for map {} difficulty {}, removing key requirement.", ar->item, mapid, difficulty);
                ar->item = 0;
            }
        }

        if (ar->item2)
        {
            ItemTemplate const* pProto = GetItemTemplate(ar->item2);
            if (!pProto)
            {
                TC_LOG_ERROR("sql.sql", "Second item {} does not exist for map {} difficulty {}, removing key requirement.", ar->item2, mapid, difficulty);
                ar->item2 = 0;
            }
        }

        if (ar->quest_A)
        {
            if (!GetQuestTemplate(ar->quest_A))
            {
                TC_LOG_ERROR("sql.sql", "Required Alliance Quest {} not exist for map {} difficulty {}, remove quest done requirement.", ar->quest_A, mapid, difficulty);
                ar->quest_A = 0;
            }
        }

        if (ar->quest_H)
        {
            if (!GetQuestTemplate(ar->quest_H))
            {
                TC_LOG_ERROR("sql.sql", "Required Horde Quest {} not exist for map {} difficulty {}, remove quest done requirement.", ar->quest_H, mapid, difficulty);
                ar->quest_H = 0;
            }
        }

        if (ar->achievement)
        {
            if (!sAchievementStore.LookupEntry(ar->achievement))
            {
                TC_LOG_ERROR("sql.sql", "Required Achievement {} not exist for map {} difficulty {}, remove quest done requirement.", ar->achievement, mapid, difficulty);
                ar->achievement = 0;
            }
        }
        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} access requirement definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

/*
 * Searches for the areatrigger which teleports players out of the given map with instance_template.parent field support
 */
AreaTriggerStruct const* ObjectMgr::GetGoBackTrigger(uint32 Map) const
{
    Optional<uint32> parentId;
    MapEntry const* mapEntry = sMapStore.LookupEntry(Map);
    if (!mapEntry || mapEntry->CorpseMapID < 0)
        return nullptr;

    if (mapEntry->IsDungeon())
        if (InstanceTemplate const* iTemplate = GetInstanceTemplate(Map))
            parentId = iTemplate->Parent;

    uint32 entrance_map = parentId.value_or(mapEntry->CorpseMapID);
    for (AreaTriggerContainer::const_iterator itr = _areaTriggerStore.begin(); itr != _areaTriggerStore.end(); ++itr)
    {
        if (itr->second.target_mapId == entrance_map)
        {
            AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(itr->first);
            if (atEntry && atEntry->ContinentID == int32(Map))
                return &itr->second;
        }
    }
    return nullptr;
}

/**
 * Searches for the areatrigger which teleports players to the given map
 */
AreaTriggerStruct const* ObjectMgr::GetMapEntranceTrigger(uint32 Map) const
{
    for (AreaTriggerContainer::const_iterator itr = _areaTriggerStore.begin(); itr != _areaTriggerStore.end(); ++itr)
    {
        if (itr->second.target_mapId == Map)
        {
            AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(itr->first);
            if (atEntry)
                return &itr->second;
        }
    }
    return nullptr;
}

void ObjectMgr::SetHighestGuids()
{
    QueryResult result = CharacterDatabase.Query("SELECT MAX(guid) FROM characters");
    if (result)
        GetGuidSequenceGenerator(HighGuid::Player).Set((*result)[0].GetUInt64() + 1);

    result = CharacterDatabase.Query("SELECT MAX(guid) FROM item_instance");
    if (result)
        GetGuidSequenceGenerator(HighGuid::Item).Set((*result)[0].GetUInt64() + 1);

    // Cleanup other tables from nonexistent guids ( >= _hiItemGuid)
    CharacterDatabase.PExecute("DELETE FROM character_inventory WHERE item >= '{}'", GetGuidSequenceGenerator(HighGuid::Item).GetNextAfterMaxUsed());    // One-time query
    CharacterDatabase.PExecute("DELETE FROM mail_items WHERE item_guid >= '{}'", GetGuidSequenceGenerator(HighGuid::Item).GetNextAfterMaxUsed());        // One-time query
    CharacterDatabase.PExecute("DELETE a, ab, ai FROM auctionhouse a LEFT JOIN auction_bidders ab ON ab.auctionId = a.id LEFT JOIN auction_items ai ON ai.auctionId = a.id WHERE ai.itemGuid >= '{}'",
        GetGuidSequenceGenerator(HighGuid::Item).GetNextAfterMaxUsed());       // One-time query
    CharacterDatabase.PExecute("DELETE FROM guild_bank_item WHERE item_guid >= '{}'", GetGuidSequenceGenerator(HighGuid::Item).GetNextAfterMaxUsed());   // One-time query

    result = WorldDatabase.Query("SELECT MAX(guid) FROM transports");
    if (result)
        GetGuidSequenceGenerator(HighGuid::Transport).Set((*result)[0].GetUInt64() + 1);

    result = CharacterDatabase.Query("SELECT MAX(id) FROM auctionhouse");
    if (result)
        _auctionId = (*result)[0].GetUInt32()+1;

    result = CharacterDatabase.Query("SELECT MAX(id) FROM mail");
    if (result)
        _mailId = (*result)[0].GetUInt64()+1;

    result = CharacterDatabase.Query("SELECT MAX(arenateamid) FROM arena_team");
    if (result)
        sArenaTeamMgr->SetNextArenaTeamId((*result)[0].GetUInt32()+1);

    result = CharacterDatabase.Query("SELECT MAX(maxguid) FROM ((SELECT MAX(setguid) AS maxguid FROM character_equipmentsets) UNION (SELECT MAX(setguid) AS maxguid FROM character_transmog_outfits)) allsets");
    if (result)
        _equipmentSetGuid = (*result)[0].GetUInt64()+1;

    result = CharacterDatabase.Query("SELECT MAX(guildId) FROM guild");
    if (result)
        sGuildMgr->SetNextGuildId((*result)[0].GetUInt64()+1);

    result = CharacterDatabase.Query("SELECT MAX(guid) FROM `groups`");
    if (result)
        sGroupMgr->SetGroupDbStoreSize((*result)[0].GetUInt32()+1);

    result = CharacterDatabase.Query("SELECT MAX(itemId) from character_void_storage");
    if (result)
        _voidItemId = (*result)[0].GetUInt64()+1;

    result = WorldDatabase.Query("SELECT MAX(guid) FROM creature");
    if (result)
        _creatureSpawnId = (*result)[0].GetUInt64() + 1;

    result = WorldDatabase.Query("SELECT MAX(guid) FROM gameobject");
    if (result)
        _gameObjectSpawnId = (*result)[0].GetUInt64() + 1;
}

ObjectGuidGenerator& ObjectMgr::GetGuidSequenceGenerator(HighGuid high)
{
    auto itr = _guidGenerators.find(high);
    if (itr == _guidGenerators.end())
        itr = _guidGenerators.insert(std::make_pair(high, std::make_unique<ObjectGuidGenerator>(high))).first;

    return *itr->second;
}

uint32 ObjectMgr::GenerateAuctionID()
{
    if (_auctionId >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR("misc", "Auctions ids overflow!! Can't continue, shutting down server. Search on forum for TCE00007 for more info. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _auctionId++;
}

uint64 ObjectMgr::GenerateEquipmentSetGuid()
{
    if (_equipmentSetGuid >= uint64(0xFFFFFFFFFFFFFFFELL))
    {
        TC_LOG_ERROR("misc", "EquipmentSet guid overflow!! Can't continue, shutting down server. Search on forum for TCE00007 for more info. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _equipmentSetGuid++;
}

uint64 ObjectMgr::GenerateMailID()
{
    if (_mailId >= UI64LIT(0xFFFFFFFFFFFFFFFE))
    {
        TC_LOG_ERROR("misc", "Mail ids overflow!! Can't continue, shutting down server. Search on forum for TCE00007 for more info. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _mailId++;
}

uint32 ObjectMgr::GeneratePetNumber()
{
    if (_hiPetNumber >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR("misc", "_hiPetNumber Id overflow!! Can't continue, shutting down server. Search on forum for TCE00007 for more info.");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _hiPetNumber++;
}

uint64 ObjectMgr::GenerateVoidStorageItemId()
{
    if (_voidItemId >= uint64(0xFFFFFFFFFFFFFFFELL))
    {
        TC_LOG_ERROR("misc", "_voidItemId overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _voidItemId++;
}

uint64 ObjectMgr::GenerateCreatureSpawnId()
{
    if (_creatureSpawnId >= uint64(0xFFFFFFFFFFFFFFFELL))
    {
        TC_LOG_ERROR("misc", "Creature spawn id overflow!! Can't continue, shutting down server. Search on forum for TCE00007 for more info.");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _creatureSpawnId++;
}

uint64 ObjectMgr::GenerateGameObjectSpawnId()
{
    if (_gameObjectSpawnId >= uint64(0xFFFFFFFFFFFFFFFELL))
    {
        TC_LOG_ERROR("misc", "GameObject spawn id overflow!! Can't continue, shutting down server. Search on forum for TCE00007 for more info. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _gameObjectSpawnId++;
}

void ObjectMgr::LoadGameObjectLocales()
{
    uint32 oldMSTime = getMSTime();

    _gameObjectLocaleStore.clear(); // need for reload case

    //                                               0      1       2     3               4
    QueryResult result = WorldDatabase.Query("SELECT entry, locale, name, castBarCaption, unk1 FROM gameobject_template_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        std::string_view localeName = fields[1].GetStringView();

        LocaleConstant locale = GetLocaleByName(localeName);
        if (!IsValidLocale(locale) || locale == LOCALE_enUS)
            continue;

        GameObjectLocale& data = _gameObjectLocaleStore[id];
        AddLocaleString(fields[2].GetStringView(), locale, data.Name);
        AddLocaleString(fields[3].GetStringView(), locale, data.CastBarCaption);
        AddLocaleString(fields[4].GetStringView(), locale, data.Unk1);

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gameobject_template_locale strings in {} ms", uint32(_gameObjectLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

inline void CheckGOLockId(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    if (sLockStore.LookupEntry(dataN))
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {} GoType: {}) have data{}={} but lock (Id: {}) not found.",
        goInfo->entry, goInfo->type, N, dataN, dataN);
}

inline void CheckGOLinkedTrapId(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    if (GameObjectTemplate const* trapInfo = sObjectMgr->GetGameObjectTemplate(dataN))
    {
        if (trapInfo->type != GAMEOBJECT_TYPE_TRAP)
            TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {} GoType: {}) have data{}={} but GO (Entry {}) have not GAMEOBJECT_TYPE_TRAP ({}) type.",
            goInfo->entry, goInfo->type, N, dataN, dataN, uint32(GAMEOBJECT_TYPE_TRAP));
    }
}

inline void CheckGOSpellId(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    if (sSpellMgr->GetSpellInfo(dataN, DIFFICULTY_NONE))
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {} GoType: {}) have data{}={} but Spell (Entry {}) not exist.",
        goInfo->entry, goInfo->type, N, dataN, dataN);
}

inline void CheckAndFixGOChairHeightId(GameObjectTemplate const* goInfo, uint32& dataN, uint32 N)
{
    if (dataN <= (UNIT_STAND_STATE_SIT_HIGH_CHAIR-UNIT_STAND_STATE_SIT_LOW_CHAIR))
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {} GoType: {}) have data{}={} but correct chair height in range 0..{}.",
        goInfo->entry, goInfo->type, N, dataN, UNIT_STAND_STATE_SIT_HIGH_CHAIR-UNIT_STAND_STATE_SIT_LOW_CHAIR);

    // prevent client and server unexpected work
    dataN = 0;
}

inline void CheckGONoDamageImmuneId(GameObjectTemplate* goTemplate, uint32 dataN, uint32 N)
{
    // 0/1 correct values
    if (dataN <= 1)
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {} GoType: {}) have data{}={} but expected boolean (0/1) noDamageImmune field value.", goTemplate->entry, goTemplate->type, N, dataN);
}

inline void CheckGOConsumable(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    // 0/1 correct values
    if (dataN <= 1)
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {} GoType: {}) have data{}={} but expected boolean (0/1) consumable field value.",
        goInfo->entry, goInfo->type, N, dataN);
}

void ObjectMgr::LoadGameObjectTemplate()
{
    uint32 oldMSTime = getMSTime();

    for (GameObjectsEntry const* db2go : sGameObjectsStore)
    {
        GameObjectTemplate& go = _gameObjectTemplateStore[db2go->ID];
        go.entry = db2go->ID;
        go.type = db2go->TypeID;
        go.displayId = db2go->DisplayID;
        go.name = db2go->Name[sWorld->GetDefaultDbcLocale()];
        go.size = db2go->Scale;
        memset(go.raw.data, 0, sizeof(go.raw.data));
        std::copy(db2go->PropValue.begin(), db2go->PropValue.end(), std::begin(go.raw.data));
        go.ContentTuningId = 0;
        go.ScriptId = 0;
    }

    //                                               0      1     2          3     4         5               6     7
    QueryResult result = WorldDatabase.Query("SELECT entry, type, displayId, name, IconName, castBarCaption, unk1, size, "
    //                                        8      9      10     11     12     13     14     15     16     17     18      19      20
                                             "Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Data8, Data9, Data10, Data11, Data12, "
    //                                        21      22      23      24      25      26      27      28      29      30      31      32      33      34      35      36
                                             "Data13, Data14, Data15, Data16, Data17, Data18, Data19, Data20, Data21, Data22, Data23, Data24, Data25, Data26, Data27, Data28, "
    //                                        37      38       39     40      41      42      43               44      45          46
                                             "Data29, Data30, Data31, Data32, Data33, Data34, ContentTuningId, AIName, ScriptName, StringId "
                                             "FROM gameobject_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject definitions. DB table `gameobject_template` is empty.");
        return;
    }

    _gameObjectTemplateStore.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        GameObjectTemplate& got = _gameObjectTemplateStore[entry];
        got.entry          = entry;
        got.type           = uint32(fields[1].GetUInt8());
        got.displayId      = fields[2].GetUInt32();
        got.name           = fields[3].GetString();
        got.IconName       = fields[4].GetString();
        got.castBarCaption = fields[5].GetString();
        got.unk1           = fields[6].GetString();
        got.size           = fields[7].GetFloat();

        for (uint8 i = 0; i < MAX_GAMEOBJECT_DATA; ++i)
            got.raw.data[i] = fields[8 + i].GetUInt32();

        got.ContentTuningId = fields[43].GetInt32();
        got.AIName = fields[44].GetString();
        got.ScriptId = GetScriptId(fields[45].GetString());
        got.StringId = fields[46].GetString();

        // Checks
        if (!got.AIName.empty() && !sGameObjectAIRegistry->HasItem(got.AIName))
        {
            TC_LOG_ERROR("sql.sql", "GameObject (Entry: {}) has non-registered `AIName` '{}' set, removing", got.entry, got.AIName);
            got.AIName.clear();
        }

        switch (got.type)
        {
            case GAMEOBJECT_TYPE_DOOR:                      //0
            {
                if (got.door.open)
                    CheckGOLockId(&got, got.door.open, 1);
                CheckGONoDamageImmuneId(&got, got.door.noDamageImmune, 3);
                break;
            }
            case GAMEOBJECT_TYPE_BUTTON:                    //1
            {
                if (got.button.open)
                    CheckGOLockId(&got, got.button.open, 1);
                CheckGONoDamageImmuneId(&got, got.button.noDamageImmune, 4);
                break;
            }
            case GAMEOBJECT_TYPE_QUESTGIVER:                //2
            {
                if (got.questgiver.open)
                    CheckGOLockId(&got, got.questgiver.open, 0);
                CheckGONoDamageImmuneId(&got, got.questgiver.noDamageImmune, 5);
                break;
            }
            case GAMEOBJECT_TYPE_CHEST:                     //3
            {
                if (got.chest.open)
                    CheckGOLockId(&got, got.chest.open, 0);

                CheckGOConsumable(&got, got.chest.consumable, 3);

                if (got.chest.linkedTrap)               // linked trap
                    CheckGOLinkedTrapId(&got, got.chest.linkedTrap, 7);
                break;
            }
            case GAMEOBJECT_TYPE_TRAP:                      //6
            {
                if (got.trap.open)
                    CheckGOLockId(&got, got.trap.open, 0);
                break;
            }
            case GAMEOBJECT_TYPE_CHAIR:                     //7
                CheckAndFixGOChairHeightId(&got, got.chair.chairheight, 1);
                break;
            case GAMEOBJECT_TYPE_SPELL_FOCUS:               //8
            {
                if (got.spellFocus.spellFocusType)
                {
                    if (!sSpellFocusObjectStore.LookupEntry(got.spellFocus.spellFocusType))
                        TC_LOG_ERROR("sql.sql", "GameObject (Entry: {} GoType: {}) have data0={} but SpellFocus (Id: {}) not exist.",
                        entry, got.type, got.spellFocus.spellFocusType, got.spellFocus.spellFocusType);
                }

                if (got.spellFocus.linkedTrap)        // linked trap
                    CheckGOLinkedTrapId(&got, got.spellFocus.linkedTrap, 2);
                break;
            }
            case GAMEOBJECT_TYPE_GOOBER:                    //10
            {
                if (got.goober.open)
                    CheckGOLockId(&got, got.goober.open, 0);

                CheckGOConsumable(&got, got.goober.consumable, 3);

                if (got.goober.pageID)                  // pageId
                {
                    if (!GetPageText(got.goober.pageID))
                        TC_LOG_ERROR("sql.sql", "GameObject (Entry: {} GoType: {}) have data7={} but PageText (Entry {}) not exist.",
                        entry, got.type, got.goober.pageID, got.goober.pageID);
                }
                CheckGONoDamageImmuneId(&got, got.goober.noDamageImmune, 11);
                if (got.goober.linkedTrap)            // linked trap
                    CheckGOLinkedTrapId(&got, got.goober.linkedTrap, 12);
                break;
            }
            case GAMEOBJECT_TYPE_AREADAMAGE:                //12
            {
                if (got.areaDamage.open)
                    CheckGOLockId(&got, got.areaDamage.open, 0);
                break;
            }
            case GAMEOBJECT_TYPE_CAMERA:                    //13
            {
                if (got.camera.open)
                    CheckGOLockId(&got, got.camera.open, 0);
                break;
            }
            case GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT:              //15
            {
                if (got.moTransport.taxiPathID)
                {
                    if (got.moTransport.taxiPathID >= sTaxiPathNodesByPath.size() || sTaxiPathNodesByPath[got.moTransport.taxiPathID].empty())
                        TC_LOG_ERROR("sql.sql", "GameObject (Entry: {} GoType: {}) have data0={} but TaxiPath (Id: {}) not exist.",
                            entry, got.type, got.moTransport.taxiPathID, got.moTransport.taxiPathID);
                }
                if (uint32 transportMap = got.moTransport.SpawnMap)
                    _transportMaps.insert(transportMap);
                break;
            }
            case GAMEOBJECT_TYPE_RITUAL:          //18
                break;
            case GAMEOBJECT_TYPE_SPELLCASTER:               //22
            {
                // always must have spell
                CheckGOSpellId(&got, got.spellCaster.spell, 0);
                break;
            }
            case GAMEOBJECT_TYPE_FLAGSTAND:                 //24
            {
                if (got.flagStand.open)
                    CheckGOLockId(&got, got.flagStand.open, 0);
                CheckGONoDamageImmuneId(&got, got.flagStand.noDamageImmune, 5);
                break;
            }
            case GAMEOBJECT_TYPE_FISHINGHOLE:               //25
            {
                if (got.fishingHole.open)
                    CheckGOLockId(&got, got.fishingHole.open, 4);
                break;
            }
            case GAMEOBJECT_TYPE_FLAGDROP:                  //26
            {
                if (got.flagDrop.open)
                    CheckGOLockId(&got, got.flagDrop.open, 0);
                CheckGONoDamageImmuneId(&got, got.flagDrop.noDamageImmune, 3);
                break;
            }
            case GAMEOBJECT_TYPE_BARBER_CHAIR:              //32
                CheckAndFixGOChairHeightId(&got, got.barberChair.chairheight, 0);

                if (got.barberChair.SitAnimKit && !sAnimKitStore.LookupEntry(got.barberChair.SitAnimKit))
                {
                    TC_LOG_ERROR("sql.sql", "GameObject (Entry: {} GoType: {}) have data2 = {} but AnimKit.dbc (Id: {}) not exist, set to 0.",
                       entry, got.type, got.barberChair.SitAnimKit, got.barberChair.SitAnimKit);
                    got.barberChair.SitAnimKit = 0;
                }
                break;
            case GAMEOBJECT_TYPE_GARRISON_BUILDING:
                if (uint32 transportMap = got.garrisonBuilding.SpawnMap)
                    _transportMaps.insert(transportMap);
                break;
            case GAMEOBJECT_TYPE_GATHERING_NODE:
                if (got.gatheringNode.open)
                    CheckGOLockId(&got, got.gatheringNode.open, 0);
                if (got.gatheringNode.linkedTrap)
                    CheckGOLinkedTrapId(&got, got.gatheringNode.linkedTrap, 20);
                break;
        }
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} game object templates in {} ms", _gameObjectTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGameObjectTemplateAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                               0       1       2      3        4        5        6        7        8        9        10             11
    QueryResult result = WorldDatabase.Query("SELECT entry, faction, flags, mingold, maxgold, artkit0, artkit1, artkit2, artkit3, artkit4, WorldEffectID, AIAnimKitID FROM gameobject_template_addon");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject template addon definitions. DB table `gameobject_template_addon` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        GameObjectTemplate const* got = GetGameObjectTemplate(entry);
        if (!got)
        {
            TC_LOG_ERROR("sql.sql", "GameObject template (Entry: {}) does not exist but has a record in `gameobject_template_addon`", entry);
            continue;
        }

        GameObjectTemplateAddon& gameObjectAddon = _gameObjectTemplateAddonStore[entry];
        gameObjectAddon.Faction       = uint32(fields[1].GetUInt16());
        gameObjectAddon.Flags         = fields[2].GetUInt32();
        gameObjectAddon.Mingold       = fields[3].GetUInt32();
        gameObjectAddon.Maxgold       = fields[4].GetUInt32();
        gameObjectAddon.WorldEffectID = fields[10].GetUInt32();
        gameObjectAddon.AIAnimKitID   = fields[11].GetUInt32();

        for (uint32 i = 0; i < gameObjectAddon.ArtKits.size(); ++i)
        {
            uint32 artKitID = fields[5 + i].GetUInt32();
            if (!artKitID)
                continue;

            if (!sGameObjectArtKitStore.LookupEntry(artKitID))
            {
                TC_LOG_ERROR("sql.sql", "GameObject (Entry: {}) has invalid `artkit{}` ({}) defined, set to zero instead.", entry, i, artKitID);
                continue;
            }

            gameObjectAddon.ArtKits[i] = artKitID;
        }

        // checks
        if (gameObjectAddon.Faction && !sFactionTemplateStore.LookupEntry(gameObjectAddon.Faction))
            TC_LOG_ERROR("sql.sql", "GameObject (Entry: {}) has invalid faction ({}) defined in `gameobject_template_addon`.", entry, gameObjectAddon.Faction);

        if (gameObjectAddon.Maxgold > 0)
        {
            switch (got->type)
            {
                case GAMEOBJECT_TYPE_CHEST:
                case GAMEOBJECT_TYPE_FISHINGHOLE:
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "GameObject (Entry {} GoType: {}) cannot be looted but has maxgold set in `gameobject_template_addon`.", entry, got->type);
                    break;
            }
        }

        if (gameObjectAddon.WorldEffectID && !sWorldEffectStore.LookupEntry(gameObjectAddon.WorldEffectID))
        {
            TC_LOG_ERROR("sql.sql", "GameObject (Entry: {}) has invalid WorldEffectID ({}) defined in `gameobject_template_addon`, set to 0.", entry, gameObjectAddon.WorldEffectID);
            gameObjectAddon.WorldEffectID = 0;
        }

        if (gameObjectAddon.AIAnimKitID && !sAnimKitStore.LookupEntry(gameObjectAddon.AIAnimKitID))
        {
            TC_LOG_ERROR("sql.sql", "GameObject (Entry: {}) has invalid AIAnimKitID ({}) defined in `gameobject_template_addon`, set to 0.", entry, gameObjectAddon.AIAnimKitID);
            gameObjectAddon.AIAnimKitID = 0;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} game object template addons in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGameObjectOverrides()
{
    uint32 oldMSTime = getMSTime();

    //                                                     0        1      2
    QueryResult result = WorldDatabase.Query("SELECT spawnId, faction, flags FROM gameobject_overrides");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject faction and flags overrides. DB table `gameobject_overrides` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType spawnId = fields[0].GetUInt64();
        GameObjectData const* goData = GetGameObjectData(spawnId);
        if (!goData)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (SpawnId: {}) does not exist but has a record in `gameobject_overrides`", spawnId);
            continue;
        }

        GameObjectOverride& gameObjectOverride = _gameObjectOverrideStore[spawnId];
        gameObjectOverride.Faction = fields[1].GetUInt16();
        gameObjectOverride.Flags = fields[2].GetUInt32();

        if (gameObjectOverride.Faction && !sFactionTemplateStore.LookupEntry(gameObjectOverride.Faction))
            TC_LOG_ERROR("sql.sql", "GameObject (SpawnId: {}) has invalid faction ({}) defined in `gameobject_overrides`.", spawnId, gameObjectOverride.Faction);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gameobject faction and flags overrides in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadExplorationBaseXP()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT level, basexp FROM exploration_basexp");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 BaseXP definitions. DB table `exploration_basexp` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint8 level  = fields[0].GetUInt8();
        uint32 basexp = fields[1].GetInt32();
        _baseXPTable[level] = basexp;
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} BaseXP definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

uint32 ObjectMgr::GetBaseXP(uint8 level)
{
    return _baseXPTable[level] ? _baseXPTable[level] : 0;
}

uint32 ObjectMgr::GetXPForLevel(uint8 level) const
{
    if (level < _playerXPperLevel.size())
        return _playerXPperLevel[level];
    return 0;
}

int32 ObjectMgr::GetFishingBaseSkillLevel(AreaTableEntry const* areaEntry) const
{
    if (!areaEntry)
        return 0;

    // Get level for the area
    FishingBaseSkillContainer::const_iterator itr = _fishingBaseForAreaStore.find(areaEntry->ID);
    if (itr != _fishingBaseForAreaStore.end())
        return itr->second;

    // If there is no data for the current area and it has a parent area, get data from the last (recursive)
    if (AreaTableEntry const* parentAreaEntry = sAreaTableStore.LookupEntry(areaEntry->ParentAreaID))
       return GetFishingBaseSkillLevel(parentAreaEntry);

    TC_LOG_ERROR("sql.sql", "Fishable areaId {} is not properly defined in `skill_fishing_base_level`.", areaEntry->ID);

    return 0;
}

SkillTiersEntry const* ObjectMgr::GetSkillTier(uint32 skillTierId) const
{
    auto itr = _skillTiers.find(skillTierId);
    return itr != _skillTiers.end() ? &itr->second : nullptr;
}

uint32 SkillTiersEntry::GetValueForTierIndex(uint32 tierIndex) const
{
    if (tierIndex >= MAX_SKILL_STEP)
        tierIndex = MAX_SKILL_STEP - 1;

    while (Value[tierIndex] == 0 && tierIndex > 0)
        --tierIndex;

    return Value[tierIndex];
}

void ObjectMgr::LoadPetNames()
{
    uint32 oldMSTime = getMSTime();
    //                                                0     1      2
    QueryResult result = WorldDatabase.Query("SELECT word, entry, half FROM pet_name_generation");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 pet name parts. DB table `pet_name_generation` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        std::string word = fields[0].GetString();
        uint32 entry     = fields[1].GetUInt32();
        bool   half      = fields[2].GetBool();
        if (half)
            _petHalfName1[entry].push_back(word);
        else
            _petHalfName0[entry].push_back(word);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} pet name parts in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPetNumber()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = CharacterDatabase.Query("SELECT MAX(id) FROM character_pet");
    if (result)
    {
        Field* fields = result->Fetch();
        _hiPetNumber = fields[0].GetUInt32()+1;
    }

    TC_LOG_INFO("server.loading", ">> Loaded the max pet number: {} in {} ms", _hiPetNumber-1, GetMSTimeDiffToNow(oldMSTime));
}

std::string ObjectMgr::GeneratePetName(uint32 entry)
{
    std::vector<std::string>& list0 = _petHalfName0[entry];
    std::vector<std::string>& list1 = _petHalfName1[entry];

    if (list0.empty() || list1.empty())
    {
        CreatureTemplate const* cinfo = GetCreatureTemplate(entry);
        if (!cinfo)
            return std::string();

        char const* petname = DB2Manager::GetCreatureFamilyPetName(cinfo->family, sWorld->GetDefaultDbcLocale());
        if (petname)
            return std::string(petname);
        else
            return cinfo->Name;
    }

    return *(list0.begin()+urand(0, list0.size()-1)) + *(list1.begin()+urand(0, list1.size()-1));
}

void ObjectMgr::LoadReputationRewardRate()
{
    uint32 oldMSTime = getMSTime();

    _repRewardRateStore.clear();                             // for reload case

    uint32 count = 0; //                                0          1             2                  3                  4                 5                      6             7
    QueryResult result = WorldDatabase.Query("SELECT faction, quest_rate, quest_daily_rate, quest_weekly_rate, quest_monthly_rate, quest_repeatable_rate, creature_rate, spell_rate FROM reputation_reward_rate");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded `reputation_reward_rate`, table is empty!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 factionId            = fields[0].GetUInt32();

        RepRewardRate repRate;

        repRate.questRate           = fields[1].GetFloat();
        repRate.questDailyRate      = fields[2].GetFloat();
        repRate.questWeeklyRate     = fields[3].GetFloat();
        repRate.questMonthlyRate    = fields[4].GetFloat();
        repRate.questRepeatableRate = fields[5].GetFloat();
        repRate.creatureRate        = fields[6].GetFloat();
        repRate.spellRate           = fields[7].GetFloat();

        FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionId);
        if (!factionEntry)
        {
            TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) {} does not exist but is used in `reputation_reward_rate`", factionId);
            continue;
        }

        if (repRate.questRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_rate with invalid rate {}, skipping data for faction {}", repRate.questRate, factionId);
            continue;
        }

        if (repRate.questDailyRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_daily_rate with invalid rate {}, skipping data for faction {}", repRate.questDailyRate, factionId);
            continue;
        }

        if (repRate.questWeeklyRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_weekly_rate with invalid rate {}, skipping data for faction {}", repRate.questWeeklyRate, factionId);
            continue;
        }

        if (repRate.questMonthlyRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_monthly_rate with invalid rate {}, skipping data for faction {}", repRate.questMonthlyRate, factionId);
            continue;
        }

        if (repRate.questRepeatableRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_repeatable_rate with invalid rate {}, skipping data for faction {}", repRate.questRepeatableRate, factionId);
            continue;
        }

        if (repRate.creatureRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has creature_rate with invalid rate {}, skipping data for faction {}", repRate.creatureRate, factionId);
            continue;
        }

        if (repRate.spellRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has spell_rate with invalid rate {}, skipping data for faction {}", repRate.spellRate, factionId);
            continue;
        }

        _repRewardRateStore[factionId] = repRate;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} reputation_reward_rate in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadReputationOnKill()
{
    uint32 oldMSTime = getMSTime();

    // For reload case
    _repOnKillStore.clear();

    uint32 count = 0;

    //                                                0            1                     2
    QueryResult result = WorldDatabase.Query("SELECT creature_id, RewOnKillRepFaction1, RewOnKillRepFaction2, "
    //   3             4             5                   6             7             8                   9
        "IsTeamAward1, MaxStanding1, RewOnKillRepValue1, IsTeamAward2, MaxStanding2, RewOnKillRepValue2, TeamDependent "
        "FROM creature_onkill_reputation");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature award reputation definitions. DB table `creature_onkill_reputation` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 creature_id = fields[0].GetUInt32();

        ReputationOnKillEntry repOnKill;
        repOnKill.RepFaction1          = fields[1].GetInt16();
        repOnKill.RepFaction2          = fields[2].GetInt16();
        repOnKill.IsTeamAward1        = fields[3].GetBool();
        repOnKill.ReputationMaxCap1  = fields[4].GetUInt8();
        repOnKill.RepValue1            = fields[5].GetInt32();
        repOnKill.IsTeamAward2        = fields[6].GetBool();
        repOnKill.ReputationMaxCap2  = fields[7].GetUInt8();
        repOnKill.RepValue2            = fields[8].GetInt32();
        repOnKill.TeamDependent       = fields[9].GetBool();

        if (!GetCreatureTemplate(creature_id))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_onkill_reputation` has data for nonexistent creature entry ({}), skipped", creature_id);
            continue;
        }

        if (repOnKill.RepFaction1)
        {
            FactionEntry const* factionEntry1 = sFactionStore.LookupEntry(repOnKill.RepFaction1);
            if (!factionEntry1)
            {
                TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) {} does not exist but is used in `creature_onkill_reputation`", repOnKill.RepFaction1);
                continue;
            }
        }

        if (repOnKill.RepFaction2)
        {
            FactionEntry const* factionEntry2 = sFactionStore.LookupEntry(repOnKill.RepFaction2);
            if (!factionEntry2)
            {
                TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) {} does not exist but is used in `creature_onkill_reputation`", repOnKill.RepFaction2);
                continue;
            }
        }

        _repOnKillStore[creature_id] = repOnKill;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature award reputation definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadReputationSpilloverTemplate()
{
    uint32 oldMSTime = getMSTime();

    _repSpilloverTemplateStore.clear();                      // for reload case

    uint32 count = 0; //                                0         1        2       3        4       5       6         7        8      9        10       11     12        13       14     15
    QueryResult result = WorldDatabase.Query("SELECT faction, faction1, rate_1, rank_1, faction2, rate_2, rank_2, faction3, rate_3, rank_3, faction4, rate_4, rank_4, faction5, rate_5, rank_5 FROM reputation_spillover_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded `reputation_spillover_template`, table is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 factionId                = fields[0].GetUInt16();

        RepSpilloverTemplate repTemplate;

        repTemplate.faction[0]          = fields[1].GetUInt16();
        repTemplate.faction_rate[0]     = fields[2].GetFloat();
        repTemplate.faction_rank[0]     = fields[3].GetUInt8();
        repTemplate.faction[1]          = fields[4].GetUInt16();
        repTemplate.faction_rate[1]     = fields[5].GetFloat();
        repTemplate.faction_rank[1]     = fields[6].GetUInt8();
        repTemplate.faction[2]          = fields[7].GetUInt16();
        repTemplate.faction_rate[2]     = fields[8].GetFloat();
        repTemplate.faction_rank[2]     = fields[9].GetUInt8();
        repTemplate.faction[3]          = fields[10].GetUInt16();
        repTemplate.faction_rate[3]     = fields[11].GetFloat();
        repTemplate.faction_rank[3]     = fields[12].GetUInt8();
        repTemplate.faction[4]          = fields[13].GetUInt16();
        repTemplate.faction_rate[4]     = fields[14].GetFloat();
        repTemplate.faction_rank[4]     = fields[15].GetUInt8();

        FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionId);

        if (!factionEntry)
        {
            TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) {} does not exist but is used in `reputation_spillover_template`", factionId);
            continue;
        }

        if (factionEntry->ParentFactionID == 0)
        {
            TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) {} in `reputation_spillover_template` does not belong to any team, skipping", factionId);
            continue;
        }

        bool invalidSpilloverFaction = false;
        for (uint32 i = 0; i < MAX_SPILLOVER_FACTIONS; ++i)
        {
            if (repTemplate.faction[i])
            {
                FactionEntry const* factionSpillover = sFactionStore.LookupEntry(repTemplate.faction[i]);

                if (!factionSpillover)
                {
                    TC_LOG_ERROR("sql.sql", "Spillover faction (faction.dbc) {} does not exist but is used in `reputation_spillover_template` for faction {}, skipping", repTemplate.faction[i], factionId);
                    invalidSpilloverFaction = true;
                    break;
                }

                if (!factionSpillover->CanHaveReputation())
                {
                    TC_LOG_ERROR("sql.sql", "Spillover faction (faction.dbc) {} for faction {} in `reputation_spillover_template` can not be listed for client, and then useless, skipping", repTemplate.faction[i], factionId);
                    invalidSpilloverFaction = true;
                    break;
                }

                if (repTemplate.faction_rank[i] >= MAX_REPUTATION_RANK)
                {
                    TC_LOG_ERROR("sql.sql", "Rank {} used in `reputation_spillover_template` for spillover faction {} is not valid, skipping", repTemplate.faction_rank[i], repTemplate.faction[i]);
                    invalidSpilloverFaction = true;
                    break;
                }
            }
        }

        if (invalidSpilloverFaction)
            continue;

        _repSpilloverTemplateStore[factionId] = repTemplate;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} reputation_spillover_template in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPointsOfInterest()
{
    uint32 oldMSTime = getMSTime();

    _pointsOfInterestStore.clear(); // need for reload case

    uint32 count = 0;

    //                                               0   1          2          3          4     5      6           7     8
    QueryResult result = WorldDatabase.Query("SELECT ID, PositionX, PositionY, PositionZ, Icon, Flags, Importance, Name, WMOGroupID FROM points_of_interest");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Points of Interest definitions. DB table `points_of_interest` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();

        PointOfInterest pointOfInterest;
        pointOfInterest.ID              = id;
        pointOfInterest.Pos.Relocate(fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat());
        pointOfInterest.Icon            = fields[4].GetUInt32();
        pointOfInterest.Flags           = fields[5].GetUInt32();
        pointOfInterest.Importance      = fields[6].GetUInt32();
        pointOfInterest.Name            = fields[7].GetString();
        pointOfInterest.WMOGroupID      = fields[8].GetInt32();

        if (!Trinity::IsValidMapCoord(pointOfInterest.Pos.GetPositionX(), pointOfInterest.Pos.GetPositionY(), pointOfInterest.Pos.GetPositionZ()))
        {
            TC_LOG_ERROR("sql.sql", "Table `points_of_interest` (ID: {}) have invalid coordinates (PositionX: {} PositionY: {}, PositionZ: {}), ignored.",
                id, pointOfInterest.Pos.GetPositionX(), pointOfInterest.Pos.GetPositionY(), pointOfInterest.Pos.GetPositionZ());
            continue;
        }

        _pointsOfInterestStore[id] = pointOfInterest;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Points of Interest definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestPOI()
{
    uint32 oldMSTime = getMSTime();

    _questPOIStore.clear();                              // need for reload case

    //                                               0        1          2     3               4                 5              6      7        8         9      10             11                 12                           13               14
    QueryResult result = WorldDatabase.Query("SELECT QuestID, BlobIndex, Idx1, ObjectiveIndex, QuestObjectiveID, QuestObjectID, MapID, UiMapID, Priority, Flags, WorldEffectID, PlayerConditionID, NavigationPlayerConditionID, SpawnTrackingID, AlwaysAllowMergingBlobs FROM quest_poi order by QuestID, Idx1");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 quest POI definitions. DB table `quest_poi` is empty.");
        return;
    }

    //                                                0        1    2  3  4
    QueryResult pointsResult = WorldDatabase.Query("SELECT QuestID, Idx1, X, Y, Z FROM quest_poi_points ORDER BY QuestID DESC, Idx1, Idx2");

    std::unordered_map<int32, std::map<int32, std::vector<QuestPOIBlobPoint>>> allPoints;

    if (pointsResult)
    {
        do
        {
            Field* fields = pointsResult->Fetch();

            int32 QuestID             = fields[0].GetInt32();
            int32 Idx1                = fields[1].GetInt32();
            int32 x                   = fields[2].GetInt32();
            int32 y                   = fields[3].GetInt32();
            int32 z                   = fields[4].GetInt32();

            allPoints[QuestID][Idx1].emplace_back(x, y, z);
        } while (pointsResult->NextRow());
    }

    do
    {
        Field* fields = result->Fetch();

        int32 questID               = fields[0].GetInt32();
        int32 blobIndex             = fields[1].GetInt32();
        int32 idx1                  = fields[2].GetInt32();
        int32 objectiveIndex        = fields[3].GetInt32();
        int32 questObjectiveID      = fields[4].GetInt32();
        int32 questObjectID         = fields[5].GetInt32();
        int32 mapID                 = fields[6].GetInt32();
        int32 uiMapID               = fields[7].GetInt32();
        int32 priority              = fields[8].GetInt32();
        int32 flags                 = fields[9].GetInt32();
        int32 worldEffectID         = fields[10].GetInt32();
        int32 playerConditionID     = fields[11].GetInt32();
        int32 navigationPlayerConditionID = fields[12].GetInt32();
        int32 spawnTrackingID       = fields[13].GetInt32();
        bool alwaysAllowMergingBlobs = fields[14].GetBool();

        if (!GetQuestTemplate(questID))
            TC_LOG_ERROR("sql.sql", "`quest_poi` quest id ({}) Idx1 ({}) does not exist in `quest_template`", questID, idx1);

        if (std::map<int32, std::vector<QuestPOIBlobPoint>>* blobs = Trinity::Containers::MapGetValuePtr(allPoints, questID))
        {
            if (std::vector<QuestPOIBlobPoint>* points = Trinity::Containers::MapGetValuePtr(*blobs, idx1))
            {
                QuestPOIData& poiData = _questPOIStore[questID];
                poiData.QuestID = questID;
                poiData.Blobs.emplace_back(blobIndex, objectiveIndex, questObjectiveID, questObjectID, mapID, uiMapID, priority, flags,
                    worldEffectID, playerConditionID, navigationPlayerConditionID, spawnTrackingID, std::move(*points), alwaysAllowMergingBlobs);
                continue;
            }
        }

        TC_LOG_ERROR("sql.sql", "Table quest_poi references unknown quest points for quest {} POI id {}", questID, blobIndex);

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} quest POI definitions in {} ms", _questPOIStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadNPCSpellClickSpells()
{
    uint32 oldMSTime = getMSTime();

    _spellClickInfoStore.clear();
    //                                                0          1         2            3
    QueryResult result = WorldDatabase.Query("SELECT npc_entry, spell_id, cast_flags, user_type FROM npc_spellclick_spells");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spellclick spells. DB table `npc_spellclick_spells` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 npc_entry = fields[0].GetUInt32();
        CreatureTemplate const* cInfo = GetCreatureTemplate(npc_entry);
        if (!cInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table npc_spellclick_spells references unknown creature_template {}. Skipping entry.", npc_entry);
            continue;
        }

        uint32 spellid = fields[1].GetUInt32();
        SpellInfo const* spellinfo = sSpellMgr->GetSpellInfo(spellid, DIFFICULTY_NONE);
        if (!spellinfo)
        {
            TC_LOG_ERROR("sql.sql", "Table npc_spellclick_spells creature: {} references unknown spellid {}. Skipping entry.", npc_entry, spellid);
            continue;
        }

        uint8 userType = fields[3].GetUInt16();
        if (userType >= SPELL_CLICK_USER_MAX)
            TC_LOG_ERROR("sql.sql", "Table npc_spellclick_spells creature: {} references unknown user type {}. Skipping entry.", npc_entry, uint32(userType));

        uint8 castFlags = fields[2].GetUInt8();
        SpellClickInfo info;
        info.spellId = spellid;
        info.castFlags = castFlags;
        info.userType = SpellClickUserTypes(userType);
        _spellClickInfoStore.insert(SpellClickInfoContainer::value_type(npc_entry, info));

        ++count;
    }
    while (result->NextRow());

    // all spellclick data loaded, now we check if there are creatures with NPC_FLAG_SPELLCLICK but with no data
    // NOTE: It *CAN* be the other way around: no spellclick flag but with spellclick data, in case of creature-only vehicle accessories
    for (auto& creatureTemplatePair : _creatureTemplateStore)
    {
        if ((creatureTemplatePair.second.npcflag & UNIT_NPC_FLAG_SPELLCLICK) && !_spellClickInfoStore.count(creatureTemplatePair.first))
        {
            TC_LOG_ERROR("sql.sql", "npc_spellclick_spells: Creature template {} has UNIT_NPC_FLAG_SPELLCLICK but no data in spellclick table! Removing flag", creatureTemplatePair.first);
            creatureTemplatePair.second.npcflag &= ~UNIT_NPC_FLAG_SPELLCLICK;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} spellclick definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::DeleteCreatureData(ObjectGuid::LowType guid)
{
    // remove mapid*cellid -> guid_set map
    CreatureData const* data = GetCreatureData(guid);
    if (data)
    {
        RemoveCreatureFromGrid(data);
        OnDeleteSpawnData(data);
    }

    _creatureDataStore.erase(guid);
}

void ObjectMgr::DeleteGameObjectData(ObjectGuid::LowType guid)
{
    // remove mapid*cellid -> guid_set map
    GameObjectData const* data = GetGameObjectData(guid);
    if (data)
    {
        RemoveGameobjectFromGrid(data);
        OnDeleteSpawnData(data);
    }

    _gameObjectDataStore.erase(guid);
}

void ObjectMgr::LoadQuestRelationsHelper(QuestRelations& map, QuestRelationsReverse* reverseMap, std::string const& table)
{
    uint32 oldMSTime = getMSTime();

    map.clear();                                            // need for reload case

    uint32 count = 0;

    QueryResult result = WorldDatabase.PQuery("SELECT id, quest FROM {}", table);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 quest relations from `{}`, table is empty.", table);
        return;
    }

    do
    {
        uint32 id     = result->Fetch()[0].GetUInt32();
        uint32 quest  = result->Fetch()[1].GetUInt32();

        if (!_questTemplates.count(quest))
        {
            TC_LOG_ERROR("sql.sql", "Table `{}`: Quest {} listed for entry {} does not exist.", table, quest, id);
            continue;
        }

        map.insert(QuestRelations::value_type(id, quest));
        if (reverseMap)
            reverseMap->insert(QuestRelationsReverse::value_type(quest, id));
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} quest relations from {} in {} ms", count, table, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGameobjectQuestStarters()
{
    LoadQuestRelationsHelper(_goQuestRelations, nullptr, "gameobject_queststarter");

    for (QuestRelations::iterator itr = _goQuestRelations.begin(); itr != _goQuestRelations.end(); ++itr)
    {
        GameObjectTemplate const* goInfo = GetGameObjectTemplate(itr->first);
        if (!goInfo)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_queststarter` has data for nonexistent gameobject entry ({}) and existed quest {}", itr->first, itr->second);
        else if (goInfo->type != GAMEOBJECT_TYPE_QUESTGIVER)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_queststarter` has data gameobject entry ({}) for quest {}, but GO is not GAMEOBJECT_TYPE_QUESTGIVER", itr->first, itr->second);
    }
}

void ObjectMgr::LoadGameobjectQuestEnders()
{
    LoadQuestRelationsHelper(_goQuestInvolvedRelations, &_goQuestInvolvedRelationsReverse, "gameobject_questender");

    for (QuestRelations::iterator itr = _goQuestInvolvedRelations.begin(); itr != _goQuestInvolvedRelations.end(); ++itr)
    {
        GameObjectTemplate const* goInfo = GetGameObjectTemplate(itr->first);
        if (!goInfo)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questender` has data for nonexistent gameobject entry ({}) and existed quest {}", itr->first, itr->second);
        else if (goInfo->type != GAMEOBJECT_TYPE_QUESTGIVER)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questender` has data gameobject entry ({}) for quest {}, but GO is not GAMEOBJECT_TYPE_QUESTGIVER", itr->first, itr->second);
    }
}

void ObjectMgr::LoadCreatureQuestStarters()
{
    LoadQuestRelationsHelper(_creatureQuestRelations, nullptr, "creature_queststarter");

    for (QuestRelations::iterator itr = _creatureQuestRelations.begin(); itr != _creatureQuestRelations.end(); ++itr)
    {
        CreatureTemplate const* cInfo = GetCreatureTemplate(itr->first);
        if (!cInfo)
            TC_LOG_ERROR("sql.sql", "Table `creature_queststarter` has data for nonexistent creature entry ({}) and existed quest {}", itr->first, itr->second);
        else if (!(cInfo->npcflag & UNIT_NPC_FLAG_QUESTGIVER))
            TC_LOG_ERROR("sql.sql", "Table `creature_queststarter` has creature entry ({}) for quest {}, but npcflag does not include UNIT_NPC_FLAG_QUESTGIVER", itr->first, itr->second);
    }
}

void ObjectMgr::LoadCreatureQuestEnders()
{
    LoadQuestRelationsHelper(_creatureQuestInvolvedRelations, &_creatureQuestInvolvedRelationsReverse, "creature_questender");

    for (QuestRelations::iterator itr = _creatureQuestInvolvedRelations.begin(); itr != _creatureQuestInvolvedRelations.end(); ++itr)
    {
        CreatureTemplate const* cInfo = GetCreatureTemplate(itr->first);
        if (!cInfo)
            TC_LOG_ERROR("sql.sql", "Table `creature_questender` has data for nonexistent creature entry ({}) and existed quest {}", itr->first, itr->second);
        else if (!(cInfo->npcflag & UNIT_NPC_FLAG_QUESTGIVER))
            TC_LOG_ERROR("sql.sql", "Table `creature_questender` has creature entry ({}) for quest {}, but npcflag does not include UNIT_NPC_FLAG_QUESTGIVER", itr->first, itr->second);
    }
}

void QuestRelationResult::Iterator::_skip()
{
    while ((_it != _end) && !Quest::IsTakingQuestEnabled(_it->second))
        ++_it;
}

bool QuestRelationResult::HasQuest(uint32 questId) const
{
    return (std::find_if(_begin, _end, [questId](QuestRelations::value_type const& pair) { return (pair.second == questId); }) != _end) && (!_onlyActive || Quest::IsTakingQuestEnabled(questId));
}

void ObjectMgr::LoadReservedPlayersNames()
{
    uint32 oldMSTime = getMSTime();

    _reservedNamesStore.clear();                                // need for reload case

    QueryResult result = CharacterDatabase.Query("SELECT name FROM reserved_name");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 reserved player names. DB table `reserved_name` is empty!");
        return;
    }

    uint32 count = 0;

    Field* fields;
    do
    {
        fields = result->Fetch();
        std::string name= fields[0].GetString();

        std::wstring wstr;
        if (!Utf8toWStr (name, wstr))
        {
            TC_LOG_ERROR("misc", "Table `reserved_name` has invalid name: {}", name);
            continue;
        }

        wstrToLower(wstr);

        _reservedNamesStore.insert(wstr);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} reserved player names in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::IsReservedName(std::string_view name) const
{
    std::wstring wstr;
    if (!Utf8toWStr (name, wstr))
        return false;

    wstrToLower(wstr);

    return _reservedNamesStore.find(wstr) != _reservedNamesStore.end();
}

static EnumFlag<CfgCategoriesCharsets> GetRealmLanguageType(bool create)
{
    if (Cfg_CategoriesEntry const* category = sCfgCategoriesStore.LookupEntry(realm.Timezone))
        return create ? category->GetCreateCharsetMask() : category->GetExistingCharsetMask();

    return create ? CfgCategoriesCharsets::English : CfgCategoriesCharsets::Any;        // basic-Latin at create, any at login
}

bool isValidString(const std::wstring& wstr, uint32 strictMask, bool numericOrSpace, bool create = false)
{
    if (strictMask == 0)                                       // any language, ignore realm
    {
        if (isExtendedLatinString(wstr, numericOrSpace))
            return true;
        if (isCyrillicString(wstr, numericOrSpace))
            return true;
        if (isKoreanString(wstr, numericOrSpace))
            return true;
        if (isChineseString(wstr, numericOrSpace))
            return true;
        return false;
    }

    if (strictMask & 0x2)                                    // realm zone specific
    {
        EnumFlag<CfgCategoriesCharsets> lt = GetRealmLanguageType(create);
        if (lt == CfgCategoriesCharsets::Any)
            return true;
        if (lt.HasFlag(CfgCategoriesCharsets::Latin1) && isExtendedLatinString(wstr, numericOrSpace))
            return true;
        if (lt.HasFlag(CfgCategoriesCharsets::English) && isBasicLatinString(wstr, numericOrSpace))
            return true;
        if (lt.HasFlag(CfgCategoriesCharsets::Russian) && isCyrillicString(wstr, numericOrSpace))
            return true;
        if (lt.HasFlag(CfgCategoriesCharsets::Korean) && isKoreanString(wstr, numericOrSpace))
            return true;
        if (lt.HasFlag(CfgCategoriesCharsets::Chinese) && isChineseString(wstr, numericOrSpace))
            return true;
    }

    if (strictMask & 0x1)                                    // basic Latin
    {
        if (isBasicLatinString(wstr, numericOrSpace))
            return true;
    }

    return false;
}

ResponseCodes ObjectMgr::CheckPlayerName(std::string_view name, LocaleConstant locale, bool create /*= false*/)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return CHAR_NAME_INVALID_CHARACTER;

    if (wname.size() > MAX_PLAYER_NAME)
        return CHAR_NAME_TOO_LONG;

    uint32 minName = sWorld->getIntConfig(CONFIG_MIN_PLAYER_NAME);
    if (wname.size() < minName)
        return CHAR_NAME_TOO_SHORT;

    uint32 strictMask = sWorld->getIntConfig(CONFIG_STRICT_PLAYER_NAMES);
    if (!isValidString(wname, strictMask, false, create))
        return CHAR_NAME_MIXED_LANGUAGES;

    wstrToLower(wname);
    for (size_t i = 2; i < wname.size(); ++i)
        if (wname[i] == wname[i-1] && wname[i] == wname[i-2])
            return CHAR_NAME_THREE_CONSECUTIVE;

    return sDB2Manager.ValidateName(wname, locale);
}

bool ObjectMgr::IsValidCharterName(std::string_view name)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return false;

    if (wname.size() > MAX_CHARTER_NAME)
        return false;

    uint32 minName = sWorld->getIntConfig(CONFIG_MIN_CHARTER_NAME);
    if (wname.size() < minName)
        return false;

    uint32 strictMask = sWorld->getIntConfig(CONFIG_STRICT_CHARTER_NAMES);

    return isValidString(wname, strictMask, true);
}

PetNameInvalidReason ObjectMgr::CheckPetName(std::string_view name)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return PET_NAME_INVALID;

    if (wname.size() > MAX_PET_NAME)
        return PET_NAME_TOO_LONG;

    uint32 minName = sWorld->getIntConfig(CONFIG_MIN_PET_NAME);
    if (wname.size() < minName)
        return PET_NAME_TOO_SHORT;

    uint32 strictMask = sWorld->getIntConfig(CONFIG_STRICT_PET_NAMES);
    if (!isValidString(wname, strictMask, false))
        return PET_NAME_MIXED_LANGUAGES;

    return PET_NAME_SUCCESS;
}

void ObjectMgr::LoadGameObjectForQuests()
{
    uint32 oldMSTime = getMSTime();

    _gameObjectForQuestStore.clear();                         // need for reload case

    if (_gameObjectTemplateStore.empty())
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GameObjects for quests");
        return;
    }

    uint32 count = 0;

    // collect GO entries for GO that must activated
    for (auto const& gameObjectTemplatePair : _gameObjectTemplateStore)
    {
        switch (gameObjectTemplatePair.second.type)
        {
            case GAMEOBJECT_TYPE_QUESTGIVER:
                break;
            case GAMEOBJECT_TYPE_CHEST:
            {
                // scan GO chest with loot including quest items
                // find quest loot for GO
                if (gameObjectTemplatePair.second.chest.questID
                    || LootTemplates_Gameobject.HaveQuestLootFor(gameObjectTemplatePair.second.chest.chestLoot)
                    || LootTemplates_Gameobject.HaveQuestLootFor(gameObjectTemplatePair.second.chest.chestPersonalLoot)
                    || LootTemplates_Gameobject.HaveQuestLootFor(gameObjectTemplatePair.second.chest.chestPushLoot))
                    break;
                continue;
            }
            case GAMEOBJECT_TYPE_GENERIC:
            {
                if (gameObjectTemplatePair.second.generic.questID > 0)             //quests objects
                    break;
                continue;
            }
            case GAMEOBJECT_TYPE_GOOBER:
            {
                if (gameObjectTemplatePair.second.goober.questID > 0)              //quests objects
                    break;
                continue;
            }
            case GAMEOBJECT_TYPE_GATHERING_NODE:
            {
                // scan GO chest with loot including quest items
                // find quest loot for GO
                if (LootTemplates_Gameobject.HaveQuestLootFor(gameObjectTemplatePair.second.gatheringNode.chestLoot))
                    break;
                continue;
            }
            default:
                continue;
        }

        _gameObjectForQuestStore.insert(gameObjectTemplatePair.first);
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} GameObjects for quests in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::LoadTrinityStrings()
{
    uint32 oldMSTime = getMSTime();

    _trinityStringStore.clear(); // for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, content_default, content_loc1, content_loc2, content_loc3, content_loc4, content_loc5, content_loc6, content_loc7, content_loc8 FROM trinity_string");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 trinity strings. DB table `trinity_string` is empty. You have imported an incorrect database for more info search for TCE00003 on forum.");
        return false;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        TrinityString& data = _trinityStringStore[entry];

        data.Content.resize(DEFAULT_LOCALE + 1);

        for (int8 i = OLD_TOTAL_LOCALES - 1; i >= 0; --i)
            AddLocaleString(fields[i + 1].GetStringView(), LocaleConstant(i), data.Content);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} trinity strings in {} ms", _trinityStringStore.size(), GetMSTimeDiffToNow(oldMSTime));
    return true;
}

char const* ObjectMgr::GetTrinityString(uint32 entry, LocaleConstant locale) const
{
    if (TrinityString const* ts = GetTrinityString(entry))
    {
        if (ts->Content.size() > size_t(locale) && !ts->Content[locale].empty())
            return ts->Content[locale].c_str();
        return ts->Content[DEFAULT_LOCALE].c_str();
    }

    TC_LOG_ERROR("sql.sql", "Trinity string entry {} not found in DB.", entry);
    return "<error>";
}

void ObjectMgr::LoadFishingBaseSkillLevel()
{
    uint32 oldMSTime = getMSTime();

    _fishingBaseForAreaStore.clear();                            // for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, skill FROM skill_fishing_base_level");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 areas for fishing base skill level. DB table `skill_fishing_base_level` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry  = fields[0].GetUInt32();
        int32 skill   = fields[1].GetInt16();

        AreaTableEntry const* fArea = sAreaTableStore.LookupEntry(entry);
        if (!fArea)
        {
            TC_LOG_ERROR("sql.sql", "AreaId {} defined in `skill_fishing_base_level` does not exist", entry);
            continue;
        }

        _fishingBaseForAreaStore[entry] = skill;
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} areas for fishing base skill level in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadSkillTiers()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT ID, Value1, Value2, Value3, Value4, Value5, Value6, Value7, Value8, Value9, Value10, "
        " Value11, Value12, Value13, Value14, Value15, Value16 FROM skill_tiers");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 skill max values. DB table `skill_tiers` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        SkillTiersEntry& tier = _skillTiers[id];
        for (uint32 i = 0; i < MAX_SKILL_STEP; ++i)
            tier.Value[i] = fields[1 + i].GetUInt32();

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} skill max values in {} ms", uint32(_skillTiers.size()), GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::CheckDeclinedNames(const std::wstring& w_ownname, DeclinedName const& names)
{
    // get main part of the name
    std::wstring mainpart = GetMainPartOfName(w_ownname, 0);
    // prepare flags
    bool x = true;
    bool y = true;

    // check declined names
    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
    {
        std::wstring wname;
        if (!Utf8toWStr(names.name[i], wname))
            return false;

        if (mainpart != GetMainPartOfName(wname, i+1))
            x = false;

        if (w_ownname != wname)
            y = false;
    }
    return (x || y);
}

uint32 ObjectMgr::GetAreaTriggerScriptId(uint32 trigger_id) const
{
    AreaTriggerScriptContainer::const_iterator i = _areaTriggerScriptStore.find(trigger_id);
    if (i!= _areaTriggerScriptStore.end())
        return i->second;
    return 0;
}

SpellScriptsBounds ObjectMgr::GetSpellScriptsBounds(uint32 spellId)
{
    return SpellScriptsBounds(_spellScriptsStore.equal_range(spellId));
}

uint32 ObjectMgr::GetEventScriptId(uint32 eventId) const
{
    EventScriptContainer::const_iterator i = _eventScriptStore.find(eventId);
    if (i != _eventScriptStore.end())
        return i->second;
    return 0;
}

// this allows calculating base reputations to offline players, just by race and class
int32 ObjectMgr::GetBaseReputationOf(FactionEntry const* factionEntry, uint8 race, uint8 playerClass) const
{
    if (!factionEntry)
        return 0;

    uint32 classMask = 1 << (playerClass - 1);

    for (uint8 i = 0; i < 4; ++i)
    {
        if ((!factionEntry->ReputationClassMask[i] ||
            factionEntry->ReputationClassMask[i] & classMask) &&
            (factionEntry->ReputationRaceMask[i].IsEmpty() ||
            factionEntry->ReputationRaceMask[i].HasRace(race)))
            return factionEntry->ReputationBase[i];
    }

    return 0;
}

SkillRangeType GetSkillRangeType(SkillRaceClassInfoEntry const* rcEntry)
{
    SkillLineEntry const* skill = sSkillLineStore.LookupEntry(rcEntry->SkillID);
    if (!skill)
        return SKILL_RANGE_NONE;

    if (sObjectMgr->GetSkillTier(rcEntry->SkillTierID))
        return SKILL_RANGE_RANK;

    if (rcEntry->SkillID == SKILL_RUNEFORGING)
        return SKILL_RANGE_MONO;

    switch (skill->CategoryID)
    {
        case SKILL_CATEGORY_ARMOR:
            return SKILL_RANGE_MONO;
        case SKILL_CATEGORY_LANGUAGES:
            return SKILL_RANGE_LANGUAGE;
    }

    return SKILL_RANGE_LEVEL;
}

void ObjectMgr::LoadGameTele()
{
    uint32 oldMSTime = getMSTime();

    _gameTeleStore.clear();                                  // for reload case

    //                                                0       1           2           3           4        5     6
    QueryResult result = WorldDatabase.Query("SELECT id, position_x, position_y, position_z, orientation, map, name FROM game_tele");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GameTeleports. DB table `game_tele` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 id         = fields[0].GetUInt32();

        GameTele gt;

        gt.position_x     = fields[1].GetFloat();
        gt.position_y     = fields[2].GetFloat();
        gt.position_z     = fields[3].GetFloat();
        gt.orientation    = fields[4].GetFloat();
        gt.mapId          = fields[5].GetUInt16();
        gt.name           = fields[6].GetString();

        if (!MapManager::IsValidMapCoord(gt.mapId, gt.position_x, gt.position_y, gt.position_z, gt.orientation))
        {
            TC_LOG_ERROR("sql.sql", "Wrong position for id {} (name: {}) in `game_tele` table, ignoring.", id, gt.name);
            continue;
        }

        if (!Utf8toWStr(gt.name, gt.wnameLow))
        {
            TC_LOG_ERROR("sql.sql", "Wrong UTF8 name for id {} in `game_tele` table, ignoring.", id);
            continue;
        }

        wstrToLower(gt.wnameLow);

        _gameTeleStore[id] = gt;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} GameTeleports in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

GameTele const* ObjectMgr::GetGameTele(std::string_view name) const
{
    // explicit name case
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return nullptr;

    // converting string that we try to find to lower case
    wstrToLower(wname);

    // Alternative first GameTele what contains wnameLow as substring in case no GameTele location found
    GameTele const* alt = nullptr;
    for (GameTeleContainer::const_iterator itr = _gameTeleStore.begin(); itr != _gameTeleStore.end(); ++itr)
    {
        if (itr->second.wnameLow == wname)
            return &itr->second;
        else if (!alt && itr->second.wnameLow.find(wname) != std::wstring::npos)
            alt = &itr->second;
    }

    return alt;
}

GameTele const* ObjectMgr::GetGameTeleExactName(std::string_view name) const
{
    // explicit name case
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return nullptr;

    // converting string that we try to find to lower case
    wstrToLower(wname);

    for (GameTeleContainer::const_iterator itr = _gameTeleStore.begin(); itr != _gameTeleStore.end(); ++itr)
    {
        if (itr->second.wnameLow == wname)
            return &itr->second;
    }

    return nullptr;
}

bool ObjectMgr::AddGameTele(GameTele& tele)
{
    // find max id
    uint32 new_id = 0;
    for (GameTeleContainer::const_iterator itr = _gameTeleStore.begin(); itr != _gameTeleStore.end(); ++itr)
        if (itr->first > new_id)
            new_id = itr->first;

    // use next
    ++new_id;

    if (!Utf8toWStr(tele.name, tele.wnameLow))
        return false;

    wstrToLower(tele.wnameLow);

    _gameTeleStore[new_id] = tele;

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_GAME_TELE);

    stmt->setUInt32(0, new_id);
    stmt->setFloat(1, tele.position_x);
    stmt->setFloat(2, tele.position_y);
    stmt->setFloat(3, tele.position_z);
    stmt->setFloat(4, tele.orientation);
    stmt->setUInt16(5, uint16(tele.mapId));
    stmt->setString(6, tele.name);

    WorldDatabase.Execute(stmt);

    return true;
}

bool ObjectMgr::DeleteGameTele(std::string_view name)
{
    // explicit name case
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return false;

    // converting string that we try to find to lower case
    wstrToLower(wname);

    for (GameTeleContainer::iterator itr = _gameTeleStore.begin(); itr != _gameTeleStore.end(); ++itr)
    {
        if (itr->second.wnameLow == wname)
        {
            WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAME_TELE);

            stmt->setString(0, itr->second.name);

            WorldDatabase.Execute(stmt);

            _gameTeleStore.erase(itr);
            return true;
        }
    }

    return false;
}

void ObjectMgr::LoadMailLevelRewards()
{
    uint32 oldMSTime = getMSTime();

    _mailLevelRewardStore.clear();                           // for reload case

    //                                                 0        1             2            3
    QueryResult result = WorldDatabase.Query("SELECT level, raceMask, mailTemplateId, senderEntry FROM mail_level_reward");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 level dependent mail rewards. DB table `mail_level_reward` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint8 level           = fields[0].GetUInt8();
        Trinity::RaceMask<uint64> raceMask = { fields[1].GetUInt64() };
        uint32 mailTemplateId = fields[2].GetUInt32();
        uint32 senderEntry    = fields[3].GetUInt32();

        if (level > MAX_LEVEL)
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has data for level {} that more supported by client ({}), ignoring.", level, MAX_LEVEL);
            continue;
        }

        if ((raceMask & RACEMASK_ALL_PLAYABLE).IsEmpty())
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has raceMask ({}) for level {} that not include any player races, ignoring.", raceMask.RawValue, level);
            continue;
        }

        if (!sMailTemplateStore.LookupEntry(mailTemplateId))
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has invalid mailTemplateId ({}) for level {} that invalid not include any player races, ignoring.", mailTemplateId, level);
            continue;
        }

        if (!GetCreatureTemplate(senderEntry))
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has nonexistent sender creature entry ({}) for level {} that invalid not include any player races, ignoring.", senderEntry, level);
            continue;
        }

        _mailLevelRewardStore[level].emplace_back(raceMask, mailTemplateId, senderEntry);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} level dependent mail rewards in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadTrainers()
{
    uint32 oldMSTime = getMSTime();

    // For reload case
    _trainers.clear();

    std::unordered_map<int32, std::vector<Trainer::Spell>> spellsByTrainer;
    if (QueryResult trainerSpellsResult = WorldDatabase.Query("SELECT TrainerId, SpellId, MoneyCost, ReqSkillLine, ReqSkillRank, ReqAbility1, ReqAbility2, ReqAbility3, ReqLevel FROM trainer_spell"))
    {
        do
        {
            Field* fields = trainerSpellsResult->Fetch();

            Trainer::Spell spell;
            uint32 trainerId = fields[0].GetUInt32();
            spell.SpellId = fields[1].GetUInt32();
            spell.MoneyCost = fields[2].GetUInt32();
            spell.ReqSkillLine = fields[3].GetUInt32();
            spell.ReqSkillRank = fields[4].GetUInt32();
            spell.ReqAbility[0] = fields[5].GetUInt32();
            spell.ReqAbility[1] = fields[6].GetUInt32();
            spell.ReqAbility[2] = fields[7].GetUInt32();
            spell.ReqLevel = fields[8].GetUInt8();

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell.SpellId, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Table `trainer_spell` references non-existing spell (SpellId: {}) for TrainerId {}, ignoring", spell.SpellId, trainerId);
                continue;
            }

            if (spell.ReqSkillLine && !sSkillLineStore.LookupEntry(spell.ReqSkillLine))
            {
                TC_LOG_ERROR("sql.sql", "Table `trainer_spell` references non-existing skill (ReqSkillLine: {}) for TrainerId {} and SpellId {}, ignoring",
                    spell.ReqSkillLine, trainerId, spell.SpellId);
                continue;
            }

            bool allReqValid = true;
            for (std::size_t i = 0; i < spell.ReqAbility.size(); ++i)
            {
                uint32 requiredSpell = spell.ReqAbility[i];
                if (requiredSpell && !sSpellMgr->GetSpellInfo(requiredSpell, DIFFICULTY_NONE))
                {
                    TC_LOG_ERROR("sql.sql", "Table `trainer_spell` references non-existing spell (ReqAbility{}: {}) for TrainerId {} and SpellId {}, ignoring",
                        i + 1, requiredSpell, trainerId, spell.SpellId);
                    allReqValid = false;
                }
            }

            if (!allReqValid)
                continue;

            spellsByTrainer[trainerId].push_back(spell);

        } while (trainerSpellsResult->NextRow());
    }

    if (QueryResult trainersResult = WorldDatabase.Query("SELECT Id, Type, Greeting FROM trainer"))
    {
        do
        {
            Field* fields = trainersResult->Fetch();
            uint32 trainerId = fields[0].GetUInt32();
            Trainer::Type trainerType = Trainer::Type(fields[1].GetUInt8());
            std::string_view greeting = fields[2].GetStringView();
            std::vector<Trainer::Spell> spells;
            auto spellsItr = spellsByTrainer.find(trainerId);
            if (spellsItr != spellsByTrainer.end())
            {
                spells = std::move(spellsItr->second);
                spellsByTrainer.erase(spellsItr);
            }

            _trainers.emplace(std::piecewise_construct, std::forward_as_tuple(trainerId), std::forward_as_tuple(trainerId, trainerType, greeting, std::move(spells)));

        } while (trainersResult->NextRow());
    }

    for (auto const& unusedSpells : spellsByTrainer)
    {
        for (Trainer::Spell const& unusedSpell : unusedSpells.second)
        {
            TC_LOG_ERROR("sql.sql", "Table `trainer_spell` references non-existing trainer (TrainerId: {}) for SpellId {}, ignoring", unusedSpells.first, unusedSpell.SpellId);
        }
    }

    if (QueryResult trainerLocalesResult = WorldDatabase.Query("SELECT Id, locale, Greeting_lang FROM trainer_locale"))
    {
        do
        {
            Field* fields = trainerLocalesResult->Fetch();
            uint32 trainerId = fields[0].GetUInt32();
            std::string localeName = fields[1].GetString();

            LocaleConstant locale = GetLocaleByName(localeName);
            if (!IsValidLocale(locale) || locale == LOCALE_enUS)
                continue;

            if (Trainer::Trainer* trainer = Trinity::Containers::MapGetValuePtr(_trainers, trainerId))
                trainer->AddGreetingLocale(locale, fields[2].GetString());
            else
                TC_LOG_ERROR("sql.sql", "Table `trainer_locale` references non-existing trainer (TrainerId: {}) for locale {}, ignoring",
                    trainerId, localeName);

        } while (trainerLocalesResult->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} Trainers in {} ms", _trainers.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTrainers()
{
    uint32 oldMSTime = getMSTime();

    _creatureDefaultTrainers.clear();

    if (QueryResult result = WorldDatabase.Query("SELECT CreatureID, TrainerID, MenuID, OptionID FROM creature_trainer"))
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 creatureId = fields[0].GetUInt32();
            uint32 trainerId = fields[1].GetUInt32();
            uint32 gossipMenuId = fields[2].GetUInt32();
            uint32 gossipOptionId = fields[3].GetUInt32();

            if (!GetCreatureTemplate(creatureId))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature_trainer` references non-existing creature template (CreatureID: {}), ignoring", creatureId);
                continue;
            }

            if (!GetTrainer(trainerId))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature_trainer` references non-existing trainer (TrainerID: {}) for CreatureID {} MenuID {} OptionID {}, ignoring",
                    trainerId, creatureId, gossipMenuId, gossipOptionId);
                continue;
            }

            if (gossipMenuId || gossipOptionId)
            {
                Trinity::IteratorPair<GossipMenuItemsContainer::const_iterator> gossipMenuItems = GetGossipMenuItemsMapBounds(gossipMenuId);
                auto gossipOptionItr = std::find_if(gossipMenuItems.begin(), gossipMenuItems.end(), [gossipOptionId](std::pair<uint32 const, GossipMenuItems> const& entry)
                {
                    return entry.second.OrderIndex == gossipOptionId;
                });
                if (gossipOptionItr == gossipMenuItems.end())
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_trainer` references non-existing gossip menu option (MenuID {} OptionID {}) for CreatureID {} and TrainerID {}, ignoring",
                        gossipMenuId, gossipOptionId, creatureId, trainerId);
                    continue;
                }
            }

            _creatureDefaultTrainers[std::make_tuple(creatureId, gossipMenuId, gossipOptionId)] = trainerId;
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} default trainers in {} ms", _creatureDefaultTrainers.size(), GetMSTimeDiffToNow(oldMSTime));
}

uint32 ObjectMgr::LoadReferenceVendor(int32 vendor, int32 item, std::set<uint32>* skip_vendors)
{
    // find all items from the reference vendor
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_NPC_VENDOR_REF);
    stmt->setUInt32(0, uint32(item));
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
        return 0;

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        int32 item_id = fields[0].GetInt32();

        // if item is a negative, its a reference
        if (item_id < 0)
            count += LoadReferenceVendor(vendor, -item_id, skip_vendors);
        else
        {
            VendorItem vItem;
            vItem.item              = item_id;
            vItem.maxcount          = fields[1].GetUInt32();
            vItem.incrtime          = fields[2].GetUInt32();
            vItem.ExtendedCost      = fields[3].GetUInt32();
            vItem.Type              = fields[4].GetUInt8();
            vItem.PlayerConditionId = fields[6].GetUInt32();
            vItem.IgnoreFiltering   = fields[7].GetBool();

            for (std::string_view token : Trinity::Tokenize(fields[5].GetStringView(), ' ', false))
                if (Optional<int32> bonusListID = Trinity::StringTo<int32>(token))
                    vItem.BonusListIDs.push_back(*bonusListID);

            if (!IsVendorItemValid(vendor, vItem, nullptr, skip_vendors))
                continue;

            VendorItemData& vList = _cacheVendorItemStore[vendor];
            vList.AddItem(std::move(vItem));
            ++count;
        }
    } while (result->NextRow());

    return count;
}

void ObjectMgr::LoadVendors()
{
    uint32 oldMSTime = getMSTime();

    // For reload case
    for (CacheVendorItemContainer::iterator itr = _cacheVendorItemStore.begin(); itr != _cacheVendorItemStore.end(); ++itr)
        itr->second.Clear();
    _cacheVendorItemStore.clear();

    std::set<uint32> skip_vendors;

    QueryResult result = WorldDatabase.Query("SELECT entry, item, maxcount, incrtime, ExtendedCost, type, BonusListIDs, PlayerConditionID, IgnoreFiltering FROM npc_vendor ORDER BY entry, slot ASC");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">>  Loaded 0 Vendors. DB table `npc_vendor` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 entry        = fields[0].GetUInt32();
        int32 item_id      = fields[1].GetInt32();

        // if item is a negative, its a reference
        if (item_id < 0)
            count += LoadReferenceVendor(entry, -item_id, &skip_vendors);
        else
        {
            VendorItem vItem;
            vItem.item              = item_id;
            vItem.maxcount          = fields[2].GetUInt32();
            vItem.incrtime          = fields[3].GetUInt32();
            vItem.ExtendedCost      = fields[4].GetUInt32();
            vItem.Type              = fields[5].GetUInt8();
            vItem.PlayerConditionId = fields[7].GetUInt32();
            vItem.IgnoreFiltering   = fields[8].GetBool();

            for (std::string_view token : Trinity::Tokenize(fields[6].GetStringView(), ' ', false))
                if (Optional<int32> bonusListID = Trinity::StringTo<int32>(token))
                    vItem.BonusListIDs.push_back(*bonusListID);

            if (!IsVendorItemValid(entry, vItem, nullptr, &skip_vendors))
                continue;

            VendorItemData& vList = _cacheVendorItemStore[entry];
            vList.AddItem(std::move(vItem));
            ++count;
        }
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Vendors in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenu()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenusStore.clear();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT MenuID, TextID FROM gossip_menu");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gossip_menu IDs. DB table `gossip_menu` is empty!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        GossipMenus gMenu;

        gMenu.MenuID = fields[0].GetUInt32();
        gMenu.TextID = fields[1].GetUInt32();

        if (!GetNpcText(gMenu.TextID))
        {
            TC_LOG_ERROR("sql.sql", "Table gossip_menu: ID {} is using non-existing TextID {}", gMenu.MenuID, gMenu.TextID);
            continue;
        }

        _gossipMenusStore.insert(GossipMenusContainer::value_type(gMenu.MenuID, gMenu));
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gossip_menu IDs in {} ms", uint32(_gossipMenusStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenuItems()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenuItemsStore.clear();

    QueryResult result = WorldDatabase.Query(
        //      0       1               2         3          4           5                      6         7      8            9             10
        "SELECT MenuID, GossipOptionID, OptionID, OptionNpc, OptionText, OptionBroadcastTextID, Language, Flags, ActionMenuID, ActionPoiID, GossipNpcOptionID, "
        //11       12        13       14                  15       16
        "BoxCoded, BoxMoney, BoxText, BoxBroadcastTextID, SpellID, OverrideIconID "
        "FROM gossip_menu_option ORDER BY MenuID, OptionID");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gossip_menu_option IDs. DB table `gossip_menu_option` is empty!");
        return;
    }

    std::unordered_map<int32, int32> optionToNpcOption;
    for (GossipNPCOptionEntry const* npcOption : sGossipNPCOptionStore)
        optionToNpcOption[npcOption->GossipOptionID] = npcOption->ID;

    do
    {
        Field* fields = result->Fetch();

        GossipMenuItems gMenuItem;

        gMenuItem.MenuID                = fields[0].GetUInt32();
        gMenuItem.GossipOptionID        = fields[1].GetInt32();
        gMenuItem.OrderIndex            = fields[2].GetUInt32();
        gMenuItem.OptionNpc             = GossipOptionNpc(fields[3].GetUInt8());
        gMenuItem.OptionText            = fields[4].GetString();
        gMenuItem.OptionBroadcastTextID = fields[5].GetUInt32();
        gMenuItem.Language              = fields[6].GetUInt32();
        gMenuItem.Flags                 = GossipOptionFlags(fields[7].GetInt32());
        gMenuItem.ActionMenuID          = fields[8].GetUInt32();
        gMenuItem.ActionPoiID           = fields[9].GetUInt32();
        if (!fields[10].IsNull())
            gMenuItem.GossipNpcOptionID = fields[10].GetInt32();

        gMenuItem.BoxCoded              = fields[11].GetBool();
        gMenuItem.BoxMoney              = fields[12].GetUInt32();
        gMenuItem.BoxText               = fields[13].GetString();
        gMenuItem.BoxBroadcastTextID    = fields[14].GetUInt32();
        if (!fields[15].IsNull())
            gMenuItem.SpellID           = fields[15].GetInt32();

        if (!fields[16].IsNull())
            gMenuItem.OverrideIconID    = fields[16].GetInt32();

        if (gMenuItem.OptionNpc >= GossipOptionNpc::Count)
        {
            TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} has unknown NPC option id {}. Replacing with GossipOptionNpc::None", gMenuItem.MenuID, gMenuItem.OrderIndex, AsUnderlyingType(gMenuItem.OptionNpc));
            gMenuItem.OptionNpc = GossipOptionNpc::None;
        }

        if (gMenuItem.OptionBroadcastTextID)
        {
            if (!sBroadcastTextStore.LookupEntry(gMenuItem.OptionBroadcastTextID))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} has non-existing or incompatible OptionBroadcastTextID {}, ignoring.", gMenuItem.MenuID, gMenuItem.OrderIndex, gMenuItem.OptionBroadcastTextID);
                gMenuItem.OptionBroadcastTextID = 0;
            }
        }

        if (gMenuItem.Language && !sLanguagesStore.LookupEntry(gMenuItem.Language))
        {
            TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} use non-existing Language {}, ignoring", gMenuItem.MenuID, gMenuItem.OrderIndex, gMenuItem.Language);
            gMenuItem.Language = 0;
        }

        if (gMenuItem.ActionMenuID && gMenuItem.OptionNpc != GossipOptionNpc::None)
        {
            TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} can not use ActionMenuID for GossipOptionNpc different from GossipOptionNpc::None, ignoring", gMenuItem.MenuID, gMenuItem.OrderIndex);
            gMenuItem.ActionMenuID = 0;
        }

        if (gMenuItem.ActionPoiID)
        {
            if (gMenuItem.OptionNpc != GossipOptionNpc::None)
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} can not use ActionPoiID for GossipOptionNpc different from GossipOptionNpc::None, ignoring", gMenuItem.MenuID, gMenuItem.OrderIndex);
                gMenuItem.ActionPoiID = 0;
            }
            else if (!GetPointOfInterest(gMenuItem.ActionPoiID))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} use non-existing ActionPoiID {}, ignoring", gMenuItem.MenuID, gMenuItem.OrderIndex, gMenuItem.ActionPoiID);
                gMenuItem.ActionPoiID = 0;
            }
        }

        if (gMenuItem.GossipNpcOptionID)
        {
            if (!sGossipNPCOptionStore.LookupEntry(*gMenuItem.GossipNpcOptionID))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} use non-existing GossipNPCOption {}, ignoring",
                    gMenuItem.MenuID, gMenuItem.OrderIndex, *gMenuItem.GossipNpcOptionID);
                gMenuItem.GossipNpcOptionID.reset();
            }
        }
        else if (int32 const* npcOptionId = Trinity::Containers::MapGetValuePtr(optionToNpcOption, gMenuItem.GossipOptionID))
            gMenuItem.GossipNpcOptionID = *npcOptionId;

        if (gMenuItem.BoxBroadcastTextID)
        {
            if (!sBroadcastTextStore.LookupEntry(gMenuItem.BoxBroadcastTextID))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} has non-existing or incompatible BoxBroadcastTextID {}, ignoring.", gMenuItem.MenuID, gMenuItem.OrderIndex, gMenuItem.BoxBroadcastTextID);
                gMenuItem.BoxBroadcastTextID = 0;
            }
        }

        if (gMenuItem.SpellID)
        {
            if (!sSpellMgr->GetSpellInfo(*gMenuItem.SpellID, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu {}, id {} use non-existing Spell {}, ignoring",
                    gMenuItem.MenuID, gMenuItem.OrderIndex, *gMenuItem.SpellID);
                gMenuItem.SpellID.reset();
            }
        }

        _gossipMenuItemsStore.insert(GossipMenuItemsContainer::value_type(gMenuItem.MenuID, gMenuItem));
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gossip_menu_option entries in {} ms", _gossipMenuItemsStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenuAddon()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenuAddonStore.clear();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT MenuID, FriendshipFactionID FROM gossip_menu_addon");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gossip_menu_addon IDs. DB table `gossip_menu_addon` is empty!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 menuID = fields[0].GetUInt32();
        GossipMenuAddon& addon = _gossipMenuAddonStore[menuID];
        addon.FriendshipFactionID = fields[1].GetInt32();

        if (FactionEntry const* faction = sFactionStore.LookupEntry(addon.FriendshipFactionID))
        {
            if (!sFriendshipReputationStore.LookupEntry(faction->FriendshipRepID))
            {
                TC_LOG_ERROR("sql.sql", "Table gossip_menu_addon: ID {} is using FriendshipFactionID {} referencing non-existing FriendshipRepID {}",
                    menuID, addon.FriendshipFactionID, faction->FriendshipRepID);
                addon.FriendshipFactionID = 0;
            }
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Table gossip_menu_addon: ID {} is using non-existing FriendshipFactionID {}", menuID, addon.FriendshipFactionID);
            addon.FriendshipFactionID = 0;
        }

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gossip_menu_addon IDs in {} ms", uint32(_gossipMenuAddonStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

Trainer::Trainer const* ObjectMgr::GetTrainer(uint32 trainerId) const
{
    return Trinity::Containers::MapGetValuePtr(_trainers, trainerId);
}

uint32 ObjectMgr::GetCreatureTrainerForGossipOption(uint32 creatureId, uint32 gossipMenuId, uint32 gossipOptionId) const
{
    auto itr = _creatureDefaultTrainers.find(std::make_tuple(creatureId, gossipMenuId, gossipOptionId));
    if (itr != _creatureDefaultTrainers.end())
        return itr->second;

    return 0;
}

void ObjectMgr::AddVendorItem(uint32 entry, VendorItem const& vItem, bool persist /*= true*/)
{
    VendorItemData& vList = _cacheVendorItemStore[entry];
    vList.AddItem(vItem);

    if (persist)
    {
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_NPC_VENDOR);

        stmt->setUInt32(0, entry);
        stmt->setUInt32(1, vItem.item);
        stmt->setUInt8(2, vItem.maxcount);
        stmt->setUInt32(3, vItem.incrtime);
        stmt->setUInt32(4, vItem.ExtendedCost);
        stmt->setUInt8(5, vItem.Type);

        WorldDatabase.Execute(stmt);
    }
}

bool ObjectMgr::RemoveVendorItem(uint32 entry, uint32 item, uint8 type, bool persist /*= true*/)
{
    CacheVendorItemContainer::iterator iter = _cacheVendorItemStore.find(entry);
    if (iter == _cacheVendorItemStore.end())
        return false;

    if (!iter->second.RemoveItem(item, type))
        return false;

    if (persist)
    {
        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_NPC_VENDOR);

        stmt->setUInt32(0, entry);
        stmt->setUInt32(1, item);
        stmt->setUInt8(2, type);

        WorldDatabase.Execute(stmt);
    }

    return true;
}

bool ObjectMgr::IsVendorItemValid(uint32 vendor_entry, VendorItem const& vItem, Player* player, std::set<uint32>* skip_vendors, uint32 ORnpcflag) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate(vendor_entry);
    if (!cInfo)
    {
        if (player)
            ChatHandler(player->GetSession()).SendSysMessage(LANG_COMMAND_VENDORSELECTION);
        else
            TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has data for nonexistent creature template (Entry: {}), ignore", vendor_entry);
        return false;
    }

    if (!((cInfo->npcflag | ORnpcflag) & UNIT_NPC_FLAG_VENDOR))
    {
        if (!skip_vendors || skip_vendors->count(vendor_entry) == 0)
        {
            if (player)
                ChatHandler(player->GetSession()).SendSysMessage(LANG_COMMAND_VENDORSELECTION);
            else
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has data for creature template (Entry: {}) without vendor flag, ignore", vendor_entry);

            if (skip_vendors)
                skip_vendors->insert(vendor_entry);
        }
        return false;
    }

    if ((vItem.Type == ITEM_VENDOR_TYPE_ITEM && !GetItemTemplate(vItem.item)) ||
        (vItem.Type == ITEM_VENDOR_TYPE_CURRENCY && !sCurrencyTypesStore.LookupEntry(vItem.item)))
    {
        if (player)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_ITEM_NOT_FOUND, vItem.item, vItem.Type);
        else
            TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` for Vendor (Entry: {}) have in item list non-existed item ({}, type {}), ignore", vendor_entry, vItem.item, vItem.Type);
        return false;
    }

    if (vItem.PlayerConditionId && !sPlayerConditionStore.LookupEntry(vItem.PlayerConditionId))
    {
        TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has Item (Entry: {}) with invalid PlayerConditionId ({}) for vendor ({}), ignore", vItem.item, vItem.PlayerConditionId, vendor_entry);
        return false;
    }

    if (vItem.ExtendedCost && !sItemExtendedCostStore.LookupEntry(vItem.ExtendedCost))
    {
        if (player)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_EXTENDED_COST_NOT_EXIST, vItem.ExtendedCost);
        else
            TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has Item (Entry: {}) with wrong ExtendedCost ({}) for vendor ({}), ignore", vItem.item, vItem.ExtendedCost, vendor_entry);
        return false;
    }

    if (vItem.Type == ITEM_VENDOR_TYPE_ITEM) // not applicable to currencies
    {
        if (vItem.maxcount > 0 && vItem.incrtime == 0)
        {
            if (player)
                ChatHandler(player->GetSession()).PSendSysMessage("MaxCount != 0 (%u) but IncrTime == 0", vItem.maxcount);
            else
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has `maxcount` ({}) for item {} of vendor (Entry: {}) but `incrtime`=0, ignore", vItem.maxcount, vItem.item, vendor_entry);
            return false;
        }
        else if (vItem.maxcount == 0 && vItem.incrtime > 0)
        {
            if (player)
                ChatHandler(player->GetSession()).PSendSysMessage("MaxCount == 0 but IncrTime<>= 0");
            else
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has `maxcount`=0 for item {} of vendor (Entry: {}) but `incrtime`<>0, ignore", vItem.item, vendor_entry);
            return false;
        }

        for (int32 bonusListId : vItem.BonusListIDs)
        {
            if (ItemBonusMgr::GetItemBonuses(bonusListId).empty())
            {
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` have Item (Entry: {}) with invalid bonus {} for vendor ({}), ignore", vItem.item, bonusListId, vendor_entry);
                return false;
            }
        }
    }

    VendorItemData const* vItems = GetNpcVendorItemList(vendor_entry);
    if (!vItems)
        return true;                                        // later checks for non-empty lists

    if (vItems->FindItemCostPair(vItem.item, vItem.ExtendedCost, vItem.Type))
    {
        if (player)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_ITEM_ALREADY_IN_LIST, vItem.item, vItem.ExtendedCost, vItem.Type);
        else
            TC_LOG_ERROR("sql.sql", "Table `npc_vendor` has duplicate items {} (with extended cost {}, type {}) for vendor (Entry: {}), ignoring", vItem.item, vItem.ExtendedCost, vItem.Type, vendor_entry);
        return false;
    }

    if (vItem.Type == ITEM_VENDOR_TYPE_CURRENCY && vItem.maxcount == 0)
    {
        TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` have Item (Entry: {}, type: {}) with missing maxcount for vendor ({}), ignore", vItem.item, vItem.Type, vendor_entry);
        return false;
    }

    return true;
}

ObjectMgr::ScriptNameContainer::ScriptNameContainer()
{
    // We insert an empty placeholder here so we can use the
    // script id 0 as dummy for "no script found".
    [[maybe_unused]] uint32 const id = insert("", false);

    ASSERT(id == 0);
}

void ObjectMgr::ScriptNameContainer::reserve(size_t capacity)
{
    IndexToName.reserve(capacity);
}

uint32 ObjectMgr::ScriptNameContainer::insert(std::string const& scriptName, bool isScriptNameBound)
{
    auto result = NameToIndex.try_emplace(scriptName, static_cast<uint32>(NameToIndex.size()), isScriptNameBound);
    if (result.second)
    {
        ASSERT(NameToIndex.size() <= std::numeric_limits<uint32>::max());
        IndexToName.emplace_back(result.first);
    }

    return result.first->second.Id;
}

size_t ObjectMgr::ScriptNameContainer::size() const
{
    return IndexToName.size();
}

ObjectMgr::ScriptNameContainer::NameMap::const_iterator ObjectMgr::ScriptNameContainer::find(size_t index) const
{
    return index < IndexToName.size() ? IndexToName[index] : end();
}

ObjectMgr::ScriptNameContainer::NameMap::const_iterator ObjectMgr::ScriptNameContainer::find(std::string const& name) const
{
    // assume "" is the first element
    if (name.empty())
        return end();

    return NameToIndex.find(name);
}

ObjectMgr::ScriptNameContainer::NameMap::const_iterator ObjectMgr::ScriptNameContainer::end() const
{
    return NameToIndex.end();
}

std::unordered_set<std::string> ObjectMgr::ScriptNameContainer::GetAllDBScriptNames() const
{
    std::unordered_set<std::string> scriptNames;

    for (std::pair<std::string const, Entry> const& entry : NameToIndex)
    {
        if (entry.second.IsScriptDatabaseBound)
        {
            scriptNames.insert(entry.first);
        }
    }

    return scriptNames;
}

std::unordered_set<std::string> ObjectMgr::GetAllDBScriptNames() const
{
    return _scriptNamesStore.GetAllDBScriptNames();
}

std::string const& ObjectMgr::GetScriptName(uint32 id) const
{
    auto const itr = _scriptNamesStore.find(id);
    if (itr != _scriptNamesStore.end())
    {
        return itr->first;
    }
    else
    {
        static std::string const empty;
        return empty;
    }
}

bool ObjectMgr::IsScriptDatabaseBound(uint32 id) const
{
    auto const itr = _scriptNamesStore.find(id);
    if (itr != _scriptNamesStore.end())
    {
        return itr->second.IsScriptDatabaseBound;
    }
    else
    {
        return false;
    }
}

uint32 ObjectMgr::GetScriptId(std::string const& name, bool isDatabaseBound)
{
    return _scriptNamesStore.insert(name, isDatabaseBound);
}

CreatureBaseStats const* ObjectMgr::GetCreatureBaseStats(uint8 level, uint8 unitClass)
{
    CreatureBaseStatsContainer::const_iterator it = _creatureBaseStatsStore.find(MAKE_PAIR16(level, unitClass));

    if (it != _creatureBaseStatsStore.end())
        return &(it->second);

    struct DefaultCreatureBaseStats : public CreatureBaseStats
    {
        DefaultCreatureBaseStats()
        {
            BaseMana = 0;
            AttackPower = 0;
            RangedAttackPower = 0;
        }
    };
    static const DefaultCreatureBaseStats defStats;
    return &defStats;
}

void ObjectMgr::LoadCreatureClassLevelStats()
{
    uint32 oldMSTime = getMSTime();
    //                                               0      1      2         3            4
    QueryResult result = WorldDatabase.Query("SELECT level, class, basemana, attackpower, rangedattackpower FROM creature_classlevelstats");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature base stats. DB table `creature_classlevelstats` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint8 Level = fields[0].GetUInt8();
        uint8 Class = fields[1].GetUInt8();

        if (!Class || ((1 << (Class - 1)) & CLASSMASK_ALL_CREATURES) == 0)
            TC_LOG_ERROR("sql.sql", "Creature base stats for level {} has invalid class {}", Level, Class);

        CreatureBaseStats stats;

        stats.BaseMana = fields[2].GetUInt32();

        stats.AttackPower = fields[3].GetUInt16();
        stats.RangedAttackPower = fields[4].GetUInt16();

        _creatureBaseStatsStore[MAKE_PAIR16(Level, Class)] = stats;

        ++count;
    }
    while (result->NextRow());

    for (uint8 unitLevel = 1; unitLevel <= DEFAULT_MAX_LEVEL + 3; ++unitLevel)
    {
        for (uint8 unitClass = 1; unitClass <= MAX_UNIT_CLASSES; ++unitClass)
        {
            uint8 unitClassMask = 1 << (unitClass - 1);
            if (!_creatureBaseStatsStore.count(MAKE_PAIR16(unitLevel, unitClassMask)))
                TC_LOG_ERROR("sql.sql", "Missing base stats for creature class {} level {}", unitClassMask, unitLevel);
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} creature base stats in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeAchievements()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_achievement");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 faction change achievement pairs. DB table `player_factionchange_achievement` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sAchievementStore.LookupEntry(alliance))
            TC_LOG_ERROR("sql.sql", "Achievement {} (alliance_id) referenced in `player_factionchange_achievement` does not exist, pair skipped!", alliance);
        else if (!sAchievementStore.LookupEntry(horde))
            TC_LOG_ERROR("sql.sql", "Achievement {} (horde_id) referenced in `player_factionchange_achievement` does not exist, pair skipped!", horde);
        else
            FactionChangeAchievements[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} faction change achievement pairs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeItems()
{
    uint32 oldMSTime = getMSTime();
    uint32 count = 0;

    for (std::pair<uint32 const, ItemTemplate> const& itemPair : _itemTemplateStore)
    {
        if (!itemPair.second.GetOtherFactionItemId())
            continue;

        if (itemPair.second.HasFlag(ITEM_FLAG2_FACTION_HORDE))
            FactionChangeItemsHordeToAlliance[itemPair.first] = itemPair.second.GetOtherFactionItemId();

        if (itemPair.second.HasFlag(ITEM_FLAG2_FACTION_ALLIANCE))
            FactionChangeItemsAllianceToHorde[itemPair.first] = itemPair.second.GetOtherFactionItemId();

        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} faction change item pairs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeQuests()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_quests");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 faction change quest pairs. DB table `player_factionchange_quests` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!GetQuestTemplate(alliance))
            TC_LOG_ERROR("sql.sql", "Quest {} (alliance_id) referenced in `player_factionchange_quests` does not exist, pair skipped!", alliance);
        else if (!GetQuestTemplate(horde))
            TC_LOG_ERROR("sql.sql", "Quest {} (horde_id) referenced in `player_factionchange_quests` does not exist, pair skipped!", horde);
        else
            FactionChangeQuests[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} faction change quest pairs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeReputations()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_reputations");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 faction change reputation pairs. DB table `player_factionchange_reputations` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sFactionStore.LookupEntry(alliance))
            TC_LOG_ERROR("sql.sql", "Reputation {} (alliance_id) referenced in `player_factionchange_reputations` does not exist, pair skipped!", alliance);
        else if (!sFactionStore.LookupEntry(horde))
            TC_LOG_ERROR("sql.sql", "Reputation {} (horde_id) referenced in `player_factionchange_reputations` does not exist, pair skipped!", horde);
        else
            FactionChangeReputation[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} faction change reputation pairs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeSpells()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_spells");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 faction change spell pairs. DB table `player_factionchange_spells` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sSpellMgr->GetSpellInfo(alliance, DIFFICULTY_NONE))
            TC_LOG_ERROR("sql.sql", "Spell {} (alliance_id) referenced in `player_factionchange_spells` does not exist, pair skipped!", alliance);
        else if (!sSpellMgr->GetSpellInfo(horde, DIFFICULTY_NONE))
            TC_LOG_ERROR("sql.sql", "Spell {} (horde_id) referenced in `player_factionchange_spells` does not exist, pair skipped!", horde);
        else
            FactionChangeSpells[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} faction change spell pairs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeTitles()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_titles");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 faction change title pairs. DB table `player_factionchange_title` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sCharTitlesStore.LookupEntry(alliance))
            TC_LOG_ERROR("sql.sql", "Title {} (alliance_id) referenced in `player_factionchange_title` does not exist, pair skipped!", alliance);
        else if (!sCharTitlesStore.LookupEntry(horde))
            TC_LOG_ERROR("sql.sql", "Title {} (horde_id) referenced in `player_factionchange_title` does not exist, pair skipped!", horde);
        else
            FactionChangeTitles[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} faction change title pairs in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPhases()
{
    for (PhaseEntry const* phase : sPhaseStore)
        _phaseInfoById.emplace(std::make_pair(phase->ID, PhaseInfoStruct{ phase->ID, std::unordered_set<uint32>{} }));

    for (MapEntry const* map : sMapStore)
        if (map->ParentMapID != -1)
            _terrainSwapInfoById.emplace(std::make_pair(map->ID, TerrainSwapInfo{ map->ID, std::vector<uint32>{} }));

    TC_LOG_INFO("server.loading", "Loading Terrain World Map definitions...");
    LoadTerrainWorldMaps();

    TC_LOG_INFO("server.loading", "Loading Terrain Swap Default definitions...");
    LoadTerrainSwapDefaults();

    TC_LOG_INFO("server.loading", "Loading Phase Area definitions...");
    LoadAreaPhases();
}

void ObjectMgr::UnloadPhaseConditions()
{
    for (auto itr = _phaseInfoByArea.begin(); itr != _phaseInfoByArea.end(); ++itr)
        for (PhaseAreaInfo& phase : itr->second)
            phase.Conditions.clear();
}

void ObjectMgr::LoadTerrainWorldMaps()
{
    uint32 oldMSTime = getMSTime();

    //                                               0               1
    QueryResult result = WorldDatabase.Query("SELECT TerrainSwapMap, UiMapPhaseId FROM `terrain_worldmap`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 terrain world maps. DB table `terrain_worldmap` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 mapId = fields[0].GetUInt32();
        uint32 uiMapPhaseId = fields[1].GetUInt32();

        if (!sMapStore.LookupEntry(mapId))
        {
            TC_LOG_ERROR("sql.sql", "TerrainSwapMap {} defined in `terrain_worldmap` does not exist, skipped.", mapId);
            continue;
        }

        if (!sDB2Manager.IsUiMapPhase(uiMapPhaseId))
        {
            TC_LOG_ERROR("sql.sql", "Phase {} defined in `terrain_worldmap` is not a valid terrain swap phase, skipped.", uiMapPhaseId);
            continue;
        }

        TerrainSwapInfo* terrainSwapInfo = &_terrainSwapInfoById[mapId];
        terrainSwapInfo->Id = mapId;
        terrainSwapInfo->UiMapPhaseIDs.push_back(uiMapPhaseId);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} terrain world maps in {} ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadTerrainSwapDefaults()
{
    uint32 oldMSTime = getMSTime();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT MapId, TerrainSwapMap FROM `terrain_swap_defaults`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 terrain swap defaults. DB table `terrain_swap_defaults` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 mapId = fields[0].GetUInt32();

        if (!sMapStore.LookupEntry(mapId))
        {
            TC_LOG_ERROR("sql.sql", "Map {} defined in `terrain_swap_defaults` does not exist, skipped.", mapId);
            continue;
        }

        uint32 terrainSwap = fields[1].GetUInt32();

        if (!sMapStore.LookupEntry(terrainSwap))
        {
            TC_LOG_ERROR("sql.sql", "TerrainSwapMap {} defined in `terrain_swap_defaults` does not exist, skipped.", terrainSwap);
            continue;
        }

        TerrainSwapInfo* terrainSwapInfo = &_terrainSwapInfoById[terrainSwap];
        terrainSwapInfo->Id = terrainSwap;
        _terrainSwapInfoByMap[mapId].push_back(terrainSwapInfo);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} terrain swap defaults in {} ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadAreaPhases()
{
    uint32 oldMSTime = getMSTime();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT AreaId, PhaseId FROM `phase_area`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 phase areas. DB table `phase_area` is empty.");
        return;
    }

    auto getOrCreatePhaseIfMissing = [this](uint32 phaseId)
    {
        PhaseInfoStruct* phaseInfo = &_phaseInfoById[phaseId];
        phaseInfo->Id = phaseId;
        return phaseInfo;
    };

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 area = fields[0].GetUInt32();
        uint32 phaseId = fields[1].GetUInt32();
        if (!sAreaTableStore.LookupEntry(area))
        {
            TC_LOG_ERROR("sql.sql", "Area {} defined in `phase_area` does not exist, skipped.", area);
            continue;
        }

        if (!sPhaseStore.LookupEntry(phaseId))
        {
            TC_LOG_ERROR("sql.sql", "Phase {} defined in `phase_area` does not exist, skipped.", phaseId);
            continue;
        }

        PhaseInfoStruct* phase = getOrCreatePhaseIfMissing(phaseId);
        phase->Areas.insert(area);
        _phaseInfoByArea[area].emplace_back(phase);

        ++count;
    } while (result->NextRow());

    for (auto itr = _phaseInfoByArea.begin(); itr != _phaseInfoByArea.end(); ++itr)
    {
        for (PhaseAreaInfo& phase : itr->second)
        {
            uint32 parentAreaId = itr->first;
            do
            {
                AreaTableEntry const* area = sAreaTableStore.LookupEntry(parentAreaId);
                if (!area)
                    break;

                parentAreaId = area->ParentAreaID;
                if (!parentAreaId)
                    break;

                if (std::vector<PhaseAreaInfo>* parentAreaPhases = Trinity::Containers::MapGetValuePtr(_phaseInfoByArea, parentAreaId))
                    for (PhaseAreaInfo& parentAreaPhase : *parentAreaPhases)
                        if (parentAreaPhase.PhaseInfo->Id == phase.PhaseInfo->Id)
                            parentAreaPhase.SubAreaExclusions.insert(itr->first);

            } while (true);
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} phase areas in {} ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

bool PhaseInfoStruct::IsAllowedInArea(uint32 areaId) const
{
    return std::any_of(Areas.begin(), Areas.end(), [areaId](uint32 areaToCheck)
    {
        return DB2Manager::IsInArea(areaId, areaToCheck);
    });
}

PhaseInfoStruct const* ObjectMgr::GetPhaseInfo(uint32 phaseId) const
{
    return Trinity::Containers::MapGetValuePtr(_phaseInfoById, phaseId);
}

std::vector<PhaseAreaInfo> const* ObjectMgr::GetPhasesForArea(uint32 areaId) const
{
    return Trinity::Containers::MapGetValuePtr(_phaseInfoByArea, areaId);
}

TerrainSwapInfo const* ObjectMgr::GetTerrainSwapInfo(uint32 terrainSwapId) const
{
    return Trinity::Containers::MapGetValuePtr(_terrainSwapInfoById, terrainSwapId);
}

GameObjectTemplate const* ObjectMgr::GetGameObjectTemplate(uint32 entry) const
{
    return Trinity::Containers::MapGetValuePtr(_gameObjectTemplateStore, entry);
}

GameObjectTemplateAddon const* ObjectMgr::GetGameObjectTemplateAddon(uint32 entry) const
{
    auto itr = _gameObjectTemplateAddonStore.find(entry);
    if (itr != _gameObjectTemplateAddonStore.end())
        return &itr->second;

    return nullptr;
}

GameObjectOverride const* ObjectMgr::GetGameObjectOverride(ObjectGuid::LowType spawnId) const
{
    return Trinity::Containers::MapGetValuePtr(_gameObjectOverrideStore, spawnId);
}

CreatureTemplate const* ObjectMgr::GetCreatureTemplate(uint32 entry) const
{
    return Trinity::Containers::MapGetValuePtr(_creatureTemplateStore, entry);
}

QuestPOIData const* ObjectMgr::GetQuestPOIData(int32 questId)
{
    return Trinity::Containers::MapGetValuePtr(_questPOIStore, questId);
}

VehicleTemplate const* ObjectMgr::GetVehicleTemplate(Vehicle* veh) const
{
    return Trinity::Containers::MapGetValuePtr(_vehicleTemplateStore, veh->GetCreatureEntry());
}

VehicleAccessoryList const* ObjectMgr::GetVehicleAccessoryList(Vehicle* veh) const
{
    if (Creature* cre = veh->GetBase()->ToCreature())
    {
        // Give preference to GUID-based accessories
        VehicleAccessoryContainer::const_iterator itr = _vehicleAccessoryStore.find(cre->GetSpawnId());
        if (itr != _vehicleAccessoryStore.end())
            return &itr->second;
    }

    // Otherwise return entry-based
    VehicleAccessoryTemplateContainer::const_iterator itr = _vehicleTemplateAccessoryStore.find(veh->GetCreatureEntry());
    if (itr != _vehicleTemplateAccessoryStore.end())
        return &itr->second;
    return nullptr;
}

PlayerInfo const* ObjectMgr::GetPlayerInfo(uint32 race, uint32 class_) const
{
    if (race >= MAX_RACES)
        return nullptr;
    if (class_ >= MAX_CLASSES)
        return nullptr;
    auto const& info = Trinity::Containers::MapGetValuePtr(_playerInfo, { Races(race), Classes(class_) });
    if (!info)
        return nullptr;
    return info->get();
}

void ObjectMgr::LoadRaceAndClassExpansionRequirements()
{
    uint32 oldMSTime = getMSTime();
    _raceUnlockRequirementStore.clear();

    //                                               0       1          2
    QueryResult result = WorldDatabase.Query("SELECT raceID, expansion, achievementId FROM `race_unlock_requirement`");

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            uint8 raceID = fields[0].GetUInt8();
            uint8 expansion = fields[1].GetUInt8();
            uint32 achievementId = fields[2].GetUInt32();

            ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(raceID);
            if (!raceEntry)
            {
                TC_LOG_ERROR("sql.sql", "Race {} defined in `race_unlock_requirement` does not exists, skipped.", raceID);
                continue;
            }

            if (expansion >= MAX_ACCOUNT_EXPANSIONS)
            {
                TC_LOG_ERROR("sql.sql", "Race {} defined in `race_unlock_requirement` has incorrect expansion {}, skipped.", raceID, expansion);
                continue;
            }

            if (achievementId && !sAchievementStore.LookupEntry(achievementId))
            {
                TC_LOG_ERROR("sql.sql", "Race {} defined in `race_unlock_requirement` has incorrect achievement {}, skipped.", raceID, achievementId);
                continue;
            }

            RaceUnlockRequirement& raceUnlockRequirement = _raceUnlockRequirementStore[raceID];
            raceUnlockRequirement.Expansion = expansion;
            raceUnlockRequirement.AchievementId = achievementId;
        }
        while (result->NextRow());
        TC_LOG_INFO("server.loading", ">> Loaded {} race expansion requirements in {} ms.", _raceUnlockRequirementStore.size(), GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 race expansion requirements. DB table `race_expansion_requirement` is empty.");

    oldMSTime = getMSTime();
    _classExpansionRequirementStore.clear();

    //                                         0       1                     2                      3
    result = WorldDatabase.Query("SELECT ClassID, RaceID, ActiveExpansionLevel, AccountExpansionLevel FROM `class_expansion_requirement`");

    if (result)
    {
        std::map<uint8, std::map<uint8, std::pair<uint8, uint8>>> temp;
        std::array<uint8, MAX_CLASSES> minRequirementForClass = { };
        minRequirementForClass.fill(MAX_ACCOUNT_EXPANSIONS);
        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();

            uint8 classID = fields[0].GetUInt8();
            uint8 raceID = fields[1].GetUInt8();
            uint8 activeExpansionLevel = fields[2].GetUInt8();
            uint8 accountExpansionLevel = fields[3].GetUInt8();

            ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(classID);
            if (!classEntry)
            {
                TC_LOG_ERROR("sql.sql", "Class {} (race {}) defined in `class_expansion_requirement` does not exists, skipped.",
                    uint32(classID), uint32(raceID));
                continue;
            }

            ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(raceID);
            if (!raceEntry)
            {
                TC_LOG_ERROR("sql.sql", "Race {} (class {}) defined in `class_expansion_requirement` does not exists, skipped.",
                    uint32(raceID), uint32(classID));
                continue;
            }

            if (activeExpansionLevel >= MAX_EXPANSIONS)
            {
                TC_LOG_ERROR("sql.sql", "Class {} Race {} defined in `class_expansion_requirement` has incorrect ActiveExpansionLevel {}, skipped.",
                    uint32(classID), uint32(raceID), activeExpansionLevel);
                continue;
            }

            if (accountExpansionLevel >= MAX_ACCOUNT_EXPANSIONS)
            {
                TC_LOG_ERROR("sql.sql", "Class {} Race {} defined in `class_expansion_requirement` has incorrect AccountExpansionLevel {}, skipped.",
                    uint32(classID), uint32(raceID), accountExpansionLevel);
                continue;
            }

            temp[raceID][classID] = { activeExpansionLevel, accountExpansionLevel };
            minRequirementForClass[classID] = std::min(minRequirementForClass[classID], activeExpansionLevel);

            ++count;
        }
        while (result->NextRow());

        for (auto&& race : temp)
        {
            RaceClassAvailability& raceClassAvailability = _classExpansionRequirementStore.emplace_back();

            raceClassAvailability.RaceID = race.first;

            for (auto&& class_ : race.second)
            {
                ClassAvailability& classAvailability = raceClassAvailability.Classes.emplace_back();

                classAvailability.ClassID = class_.first;
                classAvailability.ActiveExpansionLevel = class_.second.first;
                classAvailability.AccountExpansionLevel = class_.second.second;
                classAvailability.MinActiveExpansionLevel = minRequirementForClass[class_.first];
            }
        }

        TC_LOG_INFO("server.loading", ">> Loaded {} class expansion requirements in {} ms.", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 class expansion requirements. DB table `class_expansion_requirement` is empty.");
}

ClassAvailability const* ObjectMgr::GetClassExpansionRequirement(uint8 raceId, uint8 classId) const
{
    auto raceItr = std::find_if(_classExpansionRequirementStore.begin(), _classExpansionRequirementStore.end(), [raceId](RaceClassAvailability const& raceClass)
    {
        return raceClass.RaceID == raceId;
    });
    if (raceItr == _classExpansionRequirementStore.end())
        return nullptr;

    auto classItr = std::find_if(raceItr->Classes.begin(), raceItr->Classes.end(), [classId](ClassAvailability const& classAvailability)
    {
        return classAvailability.ClassID == classId;
    });
    if (classItr == raceItr->Classes.end())
        return nullptr;

    return &(*classItr);
}

ClassAvailability const* ObjectMgr::GetClassExpansionRequirementFallback(uint8 classId) const
{
    for (RaceClassAvailability const& raceClassAvailability : _classExpansionRequirementStore)
        for (ClassAvailability const& classAvailability : raceClassAvailability.Classes)
            if (classAvailability.ClassID == classId)
                return &classAvailability;

    return nullptr;
}

PlayerChoice const* ObjectMgr::GetPlayerChoice(int32 choiceId) const
{
    return Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
}

JumpChargeParams const* ObjectMgr::GetJumpChargeParams(int32 id) const
{
    return Trinity::Containers::MapGetValuePtr(_jumpChargeParams, id);
}

void ObjectMgr::LoadGameObjectQuestItems()
{
    uint32 oldMSTime = getMSTime();

    //                                               0                1       2
    QueryResult result = WorldDatabase.Query("SELECT GameObjectEntry, ItemId, Idx FROM gameobject_questitem ORDER BY Idx ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject quest items. DB table `gameobject_questitem` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        uint32 item  = fields[1].GetUInt32();
        uint32 idx   = fields[2].GetUInt32();

        GameObjectTemplate const* goInfo = GetGameObjectTemplate(entry);
        if (!goInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questitem` has data for nonexistent gameobject (entry: {}, idx: {}), skipped", entry, idx);
            continue;
        };

        ItemEntry const* db2Data = sItemStore.LookupEntry(item);
        if (!db2Data)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questitem` has nonexistent item (ID: {}) in gameobject (entry: {}, idx: {}), skipped", item, entry, idx);
            continue;
        };

        _gameObjectQuestItemStore[entry].push_back(item);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} gameobject quest items in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureQuestItems()
{
    uint32 oldMSTime = getMSTime();

    //                                               0              1             2       3
    QueryResult result = WorldDatabase.Query("SELECT CreatureEntry, DifficultyID, ItemId, Idx FROM creature_questitem ORDER BY Idx ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature quest items. DB table `creature_questitem` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        Difficulty difficulty = Difficulty(fields[1].GetUInt8());
        uint32 item  = fields[2].GetUInt32();
        uint32 idx   = fields[3].GetUInt32();

        CreatureTemplate const* creatureInfo = GetCreatureTemplate(entry);
        if (!creatureInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_questitem` has data for nonexistent creature (entry: {}, difficulty: {}, idx: {}), skipped", entry, difficulty, idx);
            continue;
        }

        ItemEntry const* db2Data = sItemStore.LookupEntry(item);
        if (!db2Data)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_questitem` has nonexistent item (ID: {}) in creature (entry: {}, difficulty: {}, idx: {}), skipped", item, entry, difficulty, idx);
            continue;
        }

        _creatureQuestItemStore[std::make_pair(entry, difficulty)].push_back(item);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature quest items in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureQuestCurrencies()
{
    uint32 oldMSTime = getMSTime();

    //                                               0           1
    QueryResult result = WorldDatabase.Query("SELECT CreatureId, CurrencyId FROM creature_quest_currency ORDER BY CreatureId, CurrencyId ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature quest currencies. DB table `creature_quest_currency` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        int32 currency = fields[1].GetInt32();

        if (!GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_quest_currency` has data for nonexistent creature (entry: {}, currency: {}), skipped", entry, currency);
            continue;
        }

        if (!sCurrencyTypesStore.HasRecord(currency))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_quest_currency` has nonexistent currency (ID: {}) in creature (entry: {}, currency: {}), skipped", currency, entry, currency);
            continue;
        }

        _creatureQuestCurrenciesStore[entry].push_back(currency);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} creature quest currencies in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::InitializeQueriesData(QueryDataGroup mask)
{
    uint32 oldMSTime = getMSTime();

    // cache disabled
    if (!sWorld->getBoolConfig(CONFIG_CACHE_DATA_QUERIES))
    {
        TC_LOG_INFO("server.loading", ">> Query data caching is disabled. Skipped initialization.");
        return;
    }

    Trinity::ThreadPool pool;

    // Initialize Query data for creatures
    if (mask & QUERY_DATA_CREATURES)
        for (auto& creatureTemplatePair : _creatureTemplateStore)
            pool.PostWork([creature = &creatureTemplatePair.second]() { creature->InitializeQueryData(); });

    // Initialize Query Data for gameobjects
    if (mask & QUERY_DATA_GAMEOBJECTS)
        for (auto& gameObjectTemplatePair : _gameObjectTemplateStore)
            pool.PostWork([gobj = &gameObjectTemplatePair.second]() { gobj->InitializeQueryData(); });

    // Initialize Query Data for quests
    if (mask & QUERY_DATA_QUESTS)
        for (auto& questTemplatePair : _questTemplates)
            pool.PostWork([quest = &questTemplatePair.second]() { quest->InitializeQueryData(); });

    // Initialize Quest POI data
    if (mask & QUERY_DATA_POIS)
        for (auto& poiWrapperPair : _questPOIStore)
            pool.PostWork([poi = &poiWrapperPair.second]() { poi->InitializeQueryData(); });

    pool.Join();

    TC_LOG_INFO("server.loading", ">> Initialized query cache data in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void QuestPOIData::InitializeQueryData()
{
    QueryDataBuffer << *this;
    QueryDataBuffer.shrink_to_fit();
}

void ObjectMgr::LoadSceneTemplates()
{
    uint32 oldMSTime = getMSTime();
    _sceneTemplateStore.clear();

    QueryResult templates = WorldDatabase.Query("SELECT SceneId, Flags, ScriptPackageID, Encrypted, ScriptName FROM scene_template");

    if (!templates)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 scene templates. DB table `scene_template` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = templates->Fetch();

        uint32 sceneId = fields[0].GetUInt32();
        SceneTemplate& sceneTemplate    = _sceneTemplateStore[sceneId];
        sceneTemplate.SceneId           = sceneId;
        sceneTemplate.PlaybackFlags     = static_cast<SceneFlag>(fields[1].GetUInt32());
        sceneTemplate.ScenePackageId    = fields[2].GetUInt32();
        sceneTemplate.Encrypted         = fields[3].GetUInt8() != 0;
        sceneTemplate.ScriptId          = GetScriptId(fields[4].GetCString());

    } while (templates->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} scene templates in {} ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPlayerChoices()
{
    uint32 oldMSTime = getMSTime();
    _playerChoices.clear();

    //                                                       0               1           2                3         4         5                  6                   7                    8
    QueryResult choices = WorldDatabase.Query("SELECT ChoiceId, UiTextureKitId, SoundKitId, CloseSoundKitId, Duration, Question, PendingChoiceText, HideWarboardHeader, KeepOpenAfterChoice FROM playerchoice");

    if (!choices)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 player choices. DB table `playerchoice` is empty.");
        return;
    }

    uint32 responseCount = 0;
    uint32 rewardCount = 0;
    uint32 itemRewardCount = 0;
    uint32 currencyRewardCount = 0;
    uint32 factionRewardCount = 0;
    uint32 itemChoiceRewardCount = 0;
    uint32 mawPowersCount = 0;

    do
    {
        Field* fields = choices->Fetch();

        int32 choiceId = fields[0].GetInt32();

        PlayerChoice& choice = _playerChoices[choiceId];
        choice.ChoiceId = choiceId;
        choice.UiTextureKitId = fields[1].GetInt32();
        choice.SoundKitId = fields[2].GetUInt32();
        choice.CloseSoundKitId = fields[3].GetUInt32();
        choice.Duration = fields[4].GetInt64();
        choice.Question = fields[5].GetString();
        choice.PendingChoiceText = fields[6].GetString();
        choice.HideWarboardHeader = fields[7].GetBool();
        choice.KeepOpenAfterChoice = fields[8].GetBool();

    } while (choices->NextRow());

    //                                                             0           1                   2                3      4            5
    if (QueryResult responses = WorldDatabase.Query("SELECT ChoiceId, ResponseId, ResponseIdentifier, ChoiceArtFileId, Flags, WidgetSetID, "
    //                         6           7        8               9      10      11         12              13           14            15             16
        "UiTextureAtlasElementID, SoundKitID, GroupID, UiTextureKitID, Answer, Header, SubHeader, ButtonTooltip, Description, Confirmation, RewardQuestID "
        "FROM playerchoice_response ORDER BY `Index` ASC"))
    {
        do
        {
            Field* fields = responses->Fetch();

            int32 choiceId      = fields[0].GetInt32();
            int32 responseId    = fields[1].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            choice->Responses.emplace_back();

            PlayerChoiceResponse& response = choice->Responses.back();
            response.ResponseId         = responseId;
            response.ResponseIdentifier = fields[2].GetUInt16();
            response.ChoiceArtFileId    = fields[3].GetInt32();
            response.Flags              = fields[4].GetInt32();
            response.WidgetSetID        = fields[5].GetUInt32();
            response.UiTextureAtlasElementID = fields[6].GetUInt32();
            response.SoundKitID         = fields[7].GetUInt32();
            response.GroupID            = fields[8].GetUInt8();
            response.UiTextureKitID     = fields[9].GetInt32();
            response.Answer             = fields[10].GetString();
            response.Header             = fields[11].GetString();
            response.SubHeader          = fields[12].GetString();
            response.ButtonTooltip      = fields[13].GetString();
            response.Description        = fields[14].GetString();
            response.Confirmation       = fields[15].GetString();
            if (!fields[16].IsNull())
                response.RewardQuestID  = fields[16].GetUInt32();

            ++responseCount;

        } while (responses->NextRow());
    }

    if (QueryResult rewards = WorldDatabase.Query("SELECT ChoiceId, ResponseId, TitleId, PackageId, SkillLineId, SkillPointCount, ArenaPointCount, HonorPointCount, Money, Xp FROM playerchoice_response_reward"))
    {
        do
        {
            Field* fields = rewards->Fetch();

            int32 choiceId      = fields[0].GetInt32();
            int32 responseId    = fields[1].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            auto responseItr = std::find_if(choice->Responses.begin(), choice->Responses.end(),
                [responseId](PlayerChoiceResponse const& playerChoiceResponse) { return playerChoiceResponse.ResponseId == responseId; });
            if (responseItr == choice->Responses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward` references non-existing ResponseId: {} for ChoiceId {}, skipped", responseId, choiceId);
                continue;
            }

            PlayerChoiceResponseReward* reward = &responseItr->Reward.emplace();
            reward->TitleId          = fields[2].GetInt32();
            reward->PackageId        = fields[3].GetInt32();
            reward->SkillLineId      = fields[4].GetInt32();
            reward->SkillPointCount  = fields[5].GetUInt32();
            reward->ArenaPointCount  = fields[6].GetUInt32();
            reward->HonorPointCount  = fields[7].GetUInt32();
            reward->Money            = fields[8].GetUInt64();
            reward->Xp               = fields[9].GetUInt32();
            ++rewardCount;

            if (reward->TitleId && !sCharTitlesStore.LookupEntry(reward->TitleId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward` references non-existing Title {} for ChoiceId {}, ResponseId: {}, set to 0",
                    reward->TitleId, choiceId, responseId);
                reward->TitleId = 0;
            }

            if (reward->PackageId && !sDB2Manager.GetQuestPackageItems(reward->PackageId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward` references non-existing QuestPackage {} for ChoiceId {}, ResponseId: {}, set to 0",
                    reward->TitleId, choiceId, responseId);
                reward->PackageId = 0;
            }

            if (reward->SkillLineId && !sSkillLineStore.LookupEntry(reward->SkillLineId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward` references non-existing SkillLine {} for ChoiceId {}, ResponseId: {}, set to 0",
                    reward->TitleId, choiceId, responseId);
                reward->SkillLineId = 0;
                reward->SkillPointCount = 0;
            }

        } while (rewards->NextRow());
    }

    if (QueryResult rewards = WorldDatabase.Query("SELECT ChoiceId, ResponseId, ItemId, BonusListIDs, Quantity FROM playerchoice_response_reward_item ORDER BY `Index` ASC"))
    {
        do
        {
            Field* fields = rewards->Fetch();

            int32 choiceId = fields[0].GetInt32();
            int32 responseId = fields[1].GetInt32();
            uint32 itemId = fields[2].GetUInt32();
            std::vector<int32> bonusListIds;
            for (std::string_view token : Trinity::Tokenize(fields[3].GetStringView(), ' ', false))
                if (Optional<int32> bonusListID = Trinity::StringTo<int32>(token))
                    bonusListIds.push_back(*bonusListID);
            int32 quantity = fields[4].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            auto responseItr = std::find_if(choice->Responses.begin(), choice->Responses.end(),
                [responseId](PlayerChoiceResponse const& playerChoiceResponse) { return playerChoiceResponse.ResponseId == responseId; });
            if (responseItr == choice->Responses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item` references non-existing ResponseId: {} for ChoiceId {}, skipped", responseId, choiceId);
                continue;
            }

            if (!responseItr->Reward)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item` references non-existing player choice reward for ChoiceId {}, ResponseId: {}, skipped",
                    choiceId, responseId);
                continue;
            }

            if (!GetItemTemplate(itemId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item` references non-existing item {} for ChoiceId {}, ResponseId: {}, skipped",
                    itemId, choiceId, responseId);
                continue;
            }

            responseItr->Reward->Items.emplace_back(itemId, std::move(bonusListIds), quantity);
            ++itemRewardCount;

        } while (rewards->NextRow());
    }

    if (QueryResult rewards = WorldDatabase.Query("SELECT ChoiceId, ResponseId, CurrencyId, Quantity FROM playerchoice_response_reward_currency ORDER BY `Index` ASC"))
    {
        do
        {
            Field* fields = rewards->Fetch();

            int32 choiceId = fields[0].GetInt32();
            int32 responseId = fields[1].GetInt32();
            uint32 currencyId = fields[2].GetUInt32();
            int32 quantity = fields[3].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_currency` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            auto responseItr = std::find_if(choice->Responses.begin(), choice->Responses.end(),
                [responseId](PlayerChoiceResponse const& playerChoiceResponse) { return playerChoiceResponse.ResponseId == responseId; });
            if (responseItr == choice->Responses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_currency` references non-existing ResponseId: {} for ChoiceId {}, skipped", responseId, choiceId);
                continue;
            }

            if (!responseItr->Reward)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_currency` references non-existing player choice reward for ChoiceId {}, ResponseId: {}, skipped",
                    choiceId, responseId);
                continue;
            }

            if (!sCurrencyTypesStore.LookupEntry(currencyId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_currency` references non-existing currency {} for ChoiceId {}, ResponseId: {}, skipped",
                    currencyId, choiceId, responseId);
                continue;
            }

            responseItr->Reward->Currency.emplace_back(currencyId, quantity);
            ++currencyRewardCount;

        } while (rewards->NextRow());
    }

    if (QueryResult rewards = WorldDatabase.Query("SELECT ChoiceId, ResponseId, FactionId, Quantity FROM playerchoice_response_reward_faction ORDER BY `Index` ASC"))
    {
        do
        {
            Field* fields = rewards->Fetch();

            int32 choiceId = fields[0].GetInt32();
            int32 responseId = fields[1].GetInt32();
            uint32 factionId = fields[2].GetUInt32();
            int32 quantity = fields[3].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_faction` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            auto responseItr = std::find_if(choice->Responses.begin(), choice->Responses.end(),
                [responseId](PlayerChoiceResponse const& playerChoiceResponse) { return playerChoiceResponse.ResponseId == responseId; });
            if (responseItr == choice->Responses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_faction` references non-existing ResponseId: {} for ChoiceId {}, skipped", responseId, choiceId);
                continue;
            }

            if (!responseItr->Reward)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_faction` references non-existing player choice reward for ChoiceId {}, ResponseId: {}, skipped",
                    choiceId, responseId);
                continue;
            }

            if (!sFactionStore.LookupEntry(factionId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_faction` references non-existing faction {} for ChoiceId {}, ResponseId: {}, skipped",
                    factionId, choiceId, responseId);
                continue;
            }

            responseItr->Reward->Faction.emplace_back(factionId, quantity);
            ++factionRewardCount;

        } while (rewards->NextRow());
    }

    if (QueryResult rewards = WorldDatabase.Query("SELECT ChoiceId, ResponseId, ItemId, BonusListIDs, Quantity FROM playerchoice_response_reward_item_choice ORDER BY `Index` ASC"))
    {
        do
        {
            Field* fields = rewards->Fetch();

            int32 choiceId = fields[0].GetInt32();
            int32 responseId = fields[1].GetInt32();
            uint32 itemId = fields[2].GetUInt32();
            std::vector<int32> bonusListIds;
            for (std::string_view token : Trinity::Tokenize(fields[3].GetStringView(), ' ', false))
                if (Optional<int32> bonusListID = Trinity::StringTo<int32>(token))
                    bonusListIds.push_back(*bonusListID);
            int32 quantity = fields[4].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item_choice` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            auto responseItr = std::find_if(choice->Responses.begin(), choice->Responses.end(),
                [responseId](PlayerChoiceResponse const& playerChoiceResponse) { return playerChoiceResponse.ResponseId == responseId; });
            if (responseItr == choice->Responses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item_choice` references non-existing ResponseId: {} for ChoiceId {}, skipped", responseId, choiceId);
                continue;
            }

            if (!responseItr->Reward)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item_choice` references non-existing player choice reward for ChoiceId {}, ResponseId: {}, skipped",
                    choiceId, responseId);
                continue;
            }

            if (!GetItemTemplate(itemId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_reward_item_choice` references non-existing item {} for ChoiceId {}, ResponseId: {}, skipped",
                    itemId, choiceId, responseId);
                continue;
            }

            responseItr->Reward->ItemChoices.emplace_back(itemId, std::move(bonusListIds), quantity);
            ++itemChoiceRewardCount;

        } while (rewards->NextRow());
    }

    if (QueryResult mawPowersResult = WorldDatabase.Query("SELECT ChoiceId, ResponseId, TypeArtFileID, Rarity, RarityColor, SpellID, MaxStacks FROM playerchoice_response_maw_power"))
    {
        do
        {
            Field* fields = mawPowersResult->Fetch();
            int32 choiceId = fields[0].GetInt32();
            int32 responseId = fields[1].GetInt32();

            PlayerChoice* choice = Trinity::Containers::MapGetValuePtr(_playerChoices, choiceId);
            if (!choice)
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_maw_power` references non-existing ChoiceId: {} (ResponseId: {}), skipped", choiceId, responseId);
                continue;
            }

            auto responseItr = std::find_if(choice->Responses.begin(), choice->Responses.end(),
                [responseId](PlayerChoiceResponse const& playerChoiceResponse)
            {
                return playerChoiceResponse.ResponseId == responseId;
            });
            if (responseItr == choice->Responses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_response_maw_power` references non-existing ResponseId: {} for ChoiceId {}, skipped", responseId, choiceId);
                continue;
            }

            PlayerChoiceResponseMawPower& mawPower = responseItr->MawPower.emplace();
            mawPower.TypeArtFileID = fields[2].GetInt32();
            if (!fields[3].IsNull())
                mawPower.Rarity = fields[3].GetInt32();
            if (!fields[4].IsNull())
                mawPower.RarityColor = fields[4].GetUInt32();
            mawPower.SpellID = fields[5].GetInt32();
            mawPower.MaxStacks = fields[6].GetInt32();

            ++mawPowersCount;

        } while (mawPowersResult->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} player choices, {} responses, {} rewards, {} item rewards, {} currency rewards, {} faction rewards, {} item choice rewards and {} maw powers in {} ms.",
        _playerChoices.size(), responseCount, rewardCount, itemRewardCount, currencyRewardCount, factionRewardCount, itemChoiceRewardCount, mawPowersCount, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPlayerChoicesLocale()
{
    uint32 oldMSTime = getMSTime();

    // need for reload case
    _playerChoiceLocales.clear();

    //                                                   0         1       2
    if (QueryResult result = WorldDatabase.Query("SELECT ChoiceId, locale, Question FROM playerchoice_locale"))
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 choiceId             = fields[0].GetUInt32();
            std::string_view localeName = fields[1].GetStringView();

            if (!GetPlayerChoice(choiceId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_locale` references non-existing ChoiceId: {} for locale {}, skipped", choiceId, localeName);
                continue;
            }

            LocaleConstant locale = GetLocaleByName(localeName);
            if (!IsValidLocale(locale) || locale == LOCALE_enUS)
                continue;

            PlayerChoiceLocale& data = _playerChoiceLocales[choiceId];
            AddLocaleString(fields[2].GetStringView(), locale, data.Question);
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} Player Choice locale strings in {} ms", _playerChoiceLocales.size(), GetMSTimeDiffToNow(oldMSTime));
    }

    oldMSTime = getMSTime();

    //                                                   0         1           2       3       4       5          6               7            8
    if (QueryResult result = WorldDatabase.Query("SELECT ChoiceID, ResponseID, locale, Answer, Header, SubHeader, ButtonTooltip, Description, Confirmation FROM playerchoice_response_locale"))
    {
        std::size_t count = 0;
        do
        {
            Field* fields = result->Fetch();

            int32 choiceId              = fields[0].GetInt32();
            int32 responseId            = fields[1].GetInt32();
            std::string_view localeName = fields[2].GetStringView();

            auto itr = _playerChoiceLocales.find(choiceId);
            if (itr == _playerChoiceLocales.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_locale` references non-existing ChoiceId: {} for ResponseId {} locale {}, skipped",
                    choiceId, responseId, localeName);
                continue;
            }

            PlayerChoice const* playerChoice = ASSERT_NOTNULL(GetPlayerChoice(choiceId));
            if (!playerChoice->GetResponse(responseId))
            {
                TC_LOG_ERROR("sql.sql", "Table `playerchoice_locale` references non-existing ResponseId: {} for ChoiceId {} locale {}, skipped",
                    responseId, choiceId, localeName);
                continue;
            }

            LocaleConstant locale = GetLocaleByName(localeName);
            if (!IsValidLocale(locale) || locale == LOCALE_enUS)
                continue;

            PlayerChoiceResponseLocale& data = itr->second.Responses[responseId];
            AddLocaleString(fields[3].GetStringView(), locale, data.Answer);
            AddLocaleString(fields[4].GetStringView(), locale, data.Header);
            AddLocaleString(fields[5].GetStringView(), locale, data.SubHeader);
            AddLocaleString(fields[6].GetStringView(), locale, data.ButtonTooltip);
            AddLocaleString(fields[7].GetStringView(), locale, data.Description);
            AddLocaleString(fields[8].GetStringView(), locale, data.Confirmation);
            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} Player Choice Response locale strings in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
}

void ObjectMgr::LoadJumpChargeParams()
{
    uint32 oldMSTime = getMSTime();

    // need for reload case
    _jumpChargeParams.clear();

    //                                               0   1      2                            3            4              5                6
    QueryResult result = WorldDatabase.Query("SELECT id, speed, treatSpeedAsMoveTimeSeconds, jumpGravity, spellVisualId, progressCurveId, parabolicCurveId FROM jump_charge_params");
    if (!result)
    {
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        int32 id = fields[0].GetInt32();
        float speed = fields[1].GetFloat();
        bool treatSpeedAsMoveTimeSeconds = fields[2].GetBool();
        float jumpGravity = fields[3].GetFloat();
        Optional<int32> spellVisualId;
        Optional<int32> progressCurveId;
        Optional<int32> parabolicCurveId;

        if (speed <= 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `jump_charge_params` uses invalid speed {} for id {}, set to default charge speed {}.",
                speed, id, SPEED_CHARGE);
            speed = SPEED_CHARGE;
        }

        if (jumpGravity <= 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `jump_charge_params` uses invalid jump gravity {} for id {}, set to default {}.",
                jumpGravity, id, Movement::gravity);
            jumpGravity = Movement::gravity;
        }

        if (!fields[4].IsNull())
        {
            if (sSpellVisualStore.LookupEntry(fields[4].GetInt32()))
                spellVisualId = fields[4].GetInt32();
            else
                TC_LOG_ERROR("sql.sql", "Table `jump_charge_params` references non-existing SpellVisual: {} for id {}, ignored.",
                    fields[4].GetInt32(), id);
        }

        if (!fields[5].IsNull())
        {
            if (sCurveStore.LookupEntry(fields[5].GetInt32()))
                progressCurveId = fields[5].GetInt32();
            else
                TC_LOG_ERROR("sql.sql", "Table `jump_charge_params` references non-existing progress Curve: {} for id {}, ignored.",
                    fields[4].GetInt32(), id);
        }

        if (!fields[6].IsNull())
        {
            if (sCurveStore.LookupEntry(fields[6].GetInt32()))
                parabolicCurveId = fields[6].GetInt32();
            else
                TC_LOG_ERROR("sql.sql", "Table `jump_charge_params` references non-existing parabolic Curve: {} for id {}, ignored.",
                    fields[6].GetInt32(), id);
        }

        JumpChargeParams& params = _jumpChargeParams[id];
        params.Speed = speed;
        params.TreatSpeedAsMoveTimeSeconds = treatSpeedAsMoveTimeSeconds;
        params.JumpGravity = jumpGravity;
        params.SpellVisualId = spellVisualId;
        params.ProgressCurveId = progressCurveId;
        params.ParabolicCurveId = parabolicCurveId;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} Player Choice locale strings in {} ms", _jumpChargeParams.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPhaseNames()
{
    uint32 oldMSTime = getMSTime();
    _phaseNameStore.clear();

    //                                                0     1
    QueryResult result = WorldDatabase.Query("SELECT `ID`, `Name` FROM `phase_name`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 phase names. DB table `phase_name` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 phaseId = fields[0].GetUInt32();
        std::string name = fields[1].GetString();

        _phaseNameStore[phaseId] = name;

        ++count;
    } while (result->NextRow());
    TC_LOG_INFO("server.loading", ">> Loaded {} phase names in {} ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

std::string ObjectMgr::GetPhaseName(uint32 phaseId) const
{
    PhaseNameContainer::const_iterator iter = _phaseNameStore.find(phaseId);
    return iter != _phaseNameStore.end() ? iter->second : "Unknown Name";
}
