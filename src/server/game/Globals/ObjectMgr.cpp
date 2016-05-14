/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "BattlegroundMgr.h"
#include "Chat.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DB2Structure.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GossipDef.h"
#include "GroupMgr.h"
#include "GuildMgr.h"
#include "InstanceSaveMgr.h"
#include "Language.h"
#include "LFGMgr.h"
#include "Log.h"
#include "MapManager.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "PoolMgr.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "UpdateMask.h"
#include "Util.h"
#include "Vehicle.h"
#include "World.h"

ScriptMapMap sSpellScripts;
ScriptMapMap sEventScripts;
ScriptMapMap sWaypointScripts;

std::string GetScriptsTableNameByType(ScriptsType type)
{
    std::string res = "";
    switch (type)
    {
        case SCRIPTS_SPELL:         res = "spell_scripts";      break;
        case SCRIPTS_EVENT:         res = "event_scripts";      break;
        case SCRIPTS_WAYPOINT:      res = "waypoint_scripts";   break;
        default: break;
    }
    return res;
}

ScriptMapMap* GetScriptsMapByType(ScriptsType type)
{
    ScriptMapMap* res = NULL;
    switch (type)
    {
        case SCRIPTS_SPELL:         res = &sSpellScripts;       break;
        case SCRIPTS_EVENT:         res = &sEventScripts;       break;
        case SCRIPTS_WAYPOINT:      res = &sWaypointScripts;    break;
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
        case SCRIPT_COMMAND_FIELD_SET: res = "SCRIPT_COMMAND_FIELD_SET"; break;
        case SCRIPT_COMMAND_MOVE_TO: res = "SCRIPT_COMMAND_MOVE_TO"; break;
        case SCRIPT_COMMAND_FLAG_SET: res = "SCRIPT_COMMAND_FLAG_SET"; break;
        case SCRIPT_COMMAND_FLAG_REMOVE: res = "SCRIPT_COMMAND_FLAG_REMOVE"; break;
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
        case SCRIPT_COMMAND_PLAY_ANIMKIT: res = "SCRIPT_COMMAND_PLAY_ANIMKIT"; break;
        default:
        {
            char sz[32];
            sprintf(sz, "Unknown command: %d", command);
            res = sz;
            break;
        }
    }
    return res;
}

std::string ScriptInfo::GetDebugInfo() const
{
    char sz[256];
    sprintf(sz, "%s ('%s' script id: %u)", GetScriptCommandName(command).c_str(), GetScriptsTableNameByType(type).c_str(), id);
    return std::string(sz);
}

bool normalizePlayerName(std::string& name)
{
    if (name.empty())
        return false;

    wchar_t wstr_buf[MAX_INTERNAL_PLAYER_NAME+1];
    size_t wstr_len = MAX_INTERNAL_PLAYER_NAME;

    if (!Utf8toWStr(name, &wstr_buf[0], wstr_len))
        return false;

    wstr_buf[0] = wcharToUpper(wstr_buf[0]);
    for (size_t i = 1; i < wstr_len; ++i)
        wstr_buf[i] = wcharToLower(wstr_buf[i]);

    if (!WStrToUtf8(wstr_buf, wstr_len, name))
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

LanguageDesc lang_description[LANGUAGES_COUNT] =
{
    { LANG_ADDON,           0, 0                       },
    { LANG_UNIVERSAL,       0, 0                       },
    { LANG_ORCISH,        669, SKILL_LANG_ORCISH       },
    { LANG_DARNASSIAN,    671, SKILL_LANG_DARNASSIAN   },
    { LANG_TAURAHE,       670, SKILL_LANG_TAURAHE      },
    { LANG_DWARVISH,      672, SKILL_LANG_DWARVEN      },
    { LANG_COMMON,        668, SKILL_LANG_COMMON       },
    { LANG_DEMONIC,       815, SKILL_LANG_DEMON_TONGUE },
    { LANG_TITAN,         816, SKILL_LANG_TITAN        },
    { LANG_THALASSIAN,    813, SKILL_LANG_THALASSIAN   },
    { LANG_DRACONIC,      814, SKILL_LANG_DRACONIC     },
    { LANG_KALIMAG,       817, SKILL_LANG_OLD_TONGUE   },
    { LANG_GNOMISH,      7340, SKILL_LANG_GNOMISH      },
    { LANG_TROLL,        7341, SKILL_LANG_TROLL        },
    { LANG_GUTTERSPEAK, 17737, SKILL_LANG_GUTTERSPEAK  },
    { LANG_DRAENEI,     29932, SKILL_LANG_DRAENEI      },
    { LANG_ZOMBIE,          0, 0                       },
    { LANG_GNOMISH_BINARY,  0, 0                       },
    { LANG_GOBLIN_BINARY,   0, 0                       },
    { LANG_WORGEN,      69270, SKILL_LANG_WORGEN       },
    { LANG_GOBLIN,      69269, SKILL_LANG_GOBLIN       },
    { LANG_PANDAREN_NEUTRAL,  108127, SKILL_LANG_PANDAREN_NEUTRAL  },
    { LANG_PANDAREN_ALLIANCE, 108130, SKILL_LANG_PANDAREN_ALLIANCE },
    { LANG_PANDAREN_HORDE,    108131, SKILL_LANG_PANDAREN_HORDE    }
};

LanguageDesc const* GetLanguageDescByID(uint32 lang)
{
    for (uint8 i = 0; i < LANGUAGES_COUNT; ++i)
    {
        if (uint32(lang_description[i].lang_id) == lang)
            return &lang_description[i];
    }

    return NULL;
}

bool SpellClickInfo::IsFitToRequirements(Unit const* clicker, Unit const* clickee) const
{
    Player const* playerClicker = clicker->ToPlayer();
    if (!playerClicker)
        return true;

    Unit const* summoner = NULL;
    // Check summoners for party
    if (clickee->IsSummon())
        summoner = clickee->ToTempSummon()->GetSummoner();
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
    _itemTextId(1),
    _mailId(1),
    _hiPetNumber(1),
    _voidItemId(1),
    _creatureSpawnId(1),
    _gameObjectSpawnId(1),
    DBCLocaleIndex(LOCALE_enUS)
{
    for (uint8 i = 0; i < MAX_CLASSES; ++i)
        for (uint8 j = 0; j < MAX_RACES; ++j)
            _playerInfo[j][i] = NULL;
}

ObjectMgr* ObjectMgr::instance()
{
    static ObjectMgr instance;
    return &instance;
}

ObjectMgr::~ObjectMgr()
{
    for (QuestMap::iterator i = _questTemplates.begin(); i != _questTemplates.end(); ++i)
        delete i->second;

    for (PetLevelInfoContainer::iterator i = _petInfoStore.begin(); i != _petInfoStore.end(); ++i)
        delete[] i->second;

    for (int race = 0; race < MAX_RACES; ++race)
    {
        for (int class_ = 0; class_ < MAX_CLASSES; ++class_)
        {
            if (_playerInfo[race][class_])
                delete[] _playerInfo[race][class_]->levelInfo;
            delete _playerInfo[race][class_];
        }
    }

    for (CacheVendorItemContainer::iterator itr = _cacheVendorItemStore.begin(); itr != _cacheVendorItemStore.end(); ++itr)
        itr->second.Clear();

    _cacheTrainerSpellStore.clear();

    for (DungeonEncounterContainer::iterator itr =_dungeonEncounterStore.begin(); itr != _dungeonEncounterStore.end(); ++itr)
        for (DungeonEncounterList::iterator encounterItr = itr->second.begin(); encounterItr != itr->second.end(); ++encounterItr)
            delete *encounterItr;

    for (AccessRequirementContainer::iterator itr = _accessRequirementStore.begin(); itr != _accessRequirementStore.end(); ++itr)
        delete itr->second;

    for (QuestGreetingContainer::iterator itr = _questGreetingStore.begin(); itr != _questGreetingStore.end(); ++itr)
        for (std::unordered_map<uint32, QuestGreeting const*>::iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            delete itr2->second;
}

void ObjectMgr::AddLocaleString(std::string const& value, LocaleConstant localeConstant, StringVector& data)
{
    if (!value.empty())
    {
        if (data.size() <= size_t(localeConstant))
            data.resize(localeConstant + 1);

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

        uint32 id               = fields[0].GetUInt32();
        std::string localeName  = fields[1].GetString();

        std::string name        = fields[2].GetString();
        std::string nameAlt     = fields[3].GetString();
        std::string title       = fields[4].GetString();
        std::string titleAlt    = fields[5].GetString();

        CreatureLocale& data = _creatureLocaleStore[id];
        LocaleConstant locale = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        AddLocaleString(name,       locale, data.Name);
        AddLocaleString(nameAlt,    locale, data.NameAlt);
        AddLocaleString(title,      locale, data.Title);
        AddLocaleString(titleAlt,   locale, data.TitleAlt);

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature locale strings in %u ms", uint32(_creatureLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenuItemsLocales()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenuItemsLocaleStore.clear();                              // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT menu_id, id, "
        "option_text_loc1, box_text_loc1, option_text_loc2, box_text_loc2, "
        "option_text_loc3, box_text_loc3, option_text_loc4, box_text_loc4, "
        "option_text_loc5, box_text_loc5, option_text_loc6, box_text_loc6, "
        "option_text_loc7, box_text_loc7, option_text_loc8, box_text_loc8 "
        "FROM locales_gossip_menu_option");

    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint16 menuId   = fields[0].GetUInt16();
        uint16 id       = fields[1].GetUInt16();

        GossipMenuItemsLocale& data = _gossipMenuItemsLocaleStore[MAKE_PAIR32(menuId, id)];

        for (uint8 i = OLD_TOTAL_LOCALES - 1; i > 0; --i)
        {
            LocaleConstant locale = (LocaleConstant) i;
            AddLocaleString(fields[2 + 2 * (i - 1)].GetString(), locale, data.OptionText);
            AddLocaleString(fields[2 + 2 * (i - 1) + 1].GetString(), locale, data.BoxText);
        }
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u gossip_menu_option locale strings in %u ms", uint32(_gossipMenuItemsLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
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

        uint32 id               = fields[0].GetUInt32();
        std::string localeName  = fields[1].GetString();
        std::string name        = fields[2].GetString();

        PointOfInterestLocale& data = _pointOfInterestLocaleStore[id];
        LocaleConstant locale = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        AddLocaleString(name, locale, data.Name);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u points_of_interest locale strings in %u ms", uint32(_pointOfInterestLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplates()
{
    uint32 oldMSTime = getMSTime();

    //                                               0      1                   2                   3                   4            5            6         7         8
    QueryResult result = WorldDatabase.Query("SELECT entry, difficulty_entry_1, difficulty_entry_2, difficulty_entry_3, KillCredit1, KillCredit2, modelid1, modelid2, modelid3, "
    //                                        9         10    11          12       13        14              15        16        17   18       19       20       21          22
                                             "modelid4, name, femaleName, subname, IconName, gossip_menu_id, minlevel, maxlevel, exp, exp_unk, faction, npcflag, speed_walk, speed_run, "
    //                                        23     24    25         26              27               28            29             30          31          32
                                             "scale, rank, dmgschool, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, unit_class, unit_flags, unit_flags2, "
    //                                        33            34      35            36             37            38
                                             "dynamicflags, family, trainer_type, trainer_class, trainer_race, type, "
    //                                        39          40           41      42              43        44           45           46           47           48           49
                                             "type_flags, type_flags2, lootid, pickpocketloot, skinloot, resistance1, resistance2, resistance3, resistance4, resistance5, resistance6, "
    //                                        50      51      52      53      54      55      56      57      58         59       60       61      62
                                             "spell1, spell2, spell3, spell4, spell5, spell6, spell7, spell8, VehicleId, mingold, maxgold, AIName, MovementType, "
    //                                        63           64           65              66                   67            68                 69             70              71
                                             "InhabitType, HoverHeight, HealthModifier, HealthModifierExtra, ManaModifier, ManaModifierExtra, ArmorModifier, DamageModifier, ExperienceModifier, "
    //                                        72            73          74           75                    76           77
                                             "RacialLeader, movementId, RegenHealth, mechanic_immune_mask, flags_extra, ScriptName FROM creature_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 creature template definitions. DB table `creature_template` is empty.");
        return;
    }

    _creatureTemplateStore.rehash(result->GetRowCount());
    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        LoadCreatureTemplate(fields);
        ++count;
    }
    while (result->NextRow());

    // Checking needs to be done after loading because of the difficulty self referencing
    for (CreatureTemplateContainer::const_iterator itr = _creatureTemplateStore.begin(); itr != _creatureTemplateStore.end(); ++itr)
        CheckCreatureTemplate(&itr->second);

    TC_LOG_INFO("server.loading", ">> Loaded %u creature definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureTemplate(Field* fields)
{
    uint32 entry = fields[0].GetUInt32();

    CreatureTemplate& creatureTemplate = _creatureTemplateStore[entry];

    creatureTemplate.Entry = entry;

    for (uint8 i = 0; i < MAX_CREATURE_DIFFICULTIES; ++i)
        creatureTemplate.DifficultyEntry[i] = fields[1 + i].GetUInt32();

    for (uint8 i = 0; i < MAX_KILL_CREDIT; ++i)
        creatureTemplate.KillCredit[i] = fields[4 + i].GetUInt32();

    creatureTemplate.Modelid1          = fields[6].GetUInt32();
    creatureTemplate.Modelid2          = fields[7].GetUInt32();
    creatureTemplate.Modelid3          = fields[8].GetUInt32();
    creatureTemplate.Modelid4          = fields[9].GetUInt32();
    creatureTemplate.Name              = fields[10].GetString();
    creatureTemplate.FemaleName        = fields[11].GetString();
    creatureTemplate.SubName           = fields[12].GetString();
    creatureTemplate.IconName          = fields[13].GetString();
    creatureTemplate.GossipMenuId      = fields[14].GetUInt32();
    creatureTemplate.minlevel          = fields[15].GetInt16();
    creatureTemplate.maxlevel          = fields[16].GetInt16();
    creatureTemplate.expansion         = fields[17].GetInt16();
    creatureTemplate.expansionUnknown  = fields[18].GetUInt16();
    creatureTemplate.faction           = fields[19].GetUInt16();
    creatureTemplate.npcflag           = fields[20].GetUInt64();
    creatureTemplate.speed_walk        = fields[21].GetFloat();
    creatureTemplate.speed_run         = fields[22].GetFloat();
    creatureTemplate.scale             = fields[23].GetFloat();
    creatureTemplate.rank              = uint32(fields[24].GetUInt8());
    creatureTemplate.dmgschool         = uint32(fields[25].GetInt8());
    creatureTemplate.BaseAttackTime    = fields[26].GetUInt32();
    creatureTemplate.RangeAttackTime   = fields[27].GetUInt32();
    creatureTemplate.BaseVariance      = fields[28].GetFloat();
    creatureTemplate.RangeVariance     = fields[29].GetFloat();
    creatureTemplate.unit_class        = uint32(fields[30].GetUInt8());
    creatureTemplate.unit_flags        = fields[31].GetUInt32();
    creatureTemplate.unit_flags2       = fields[32].GetUInt32();
    creatureTemplate.dynamicflags      = fields[33].GetUInt32();
    creatureTemplate.family            = uint32(fields[34].GetUInt8());
    creatureTemplate.trainer_type      = uint32(fields[35].GetUInt8());
    creatureTemplate.trainer_class     = uint32(fields[36].GetUInt8());
    creatureTemplate.trainer_race      = uint32(fields[37].GetUInt8());
    creatureTemplate.type              = uint32(fields[38].GetUInt8());
    creatureTemplate.type_flags        = fields[39].GetUInt32();
    creatureTemplate.type_flags2       = fields[40].GetUInt32();
    creatureTemplate.lootid            = fields[41].GetUInt32();
    creatureTemplate.pickpocketLootId  = fields[42].GetUInt32();
    creatureTemplate.SkinLootId        = fields[43].GetUInt32();

    for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
        creatureTemplate.resistance[i] = fields[44 + i - 1].GetInt16();

    for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        creatureTemplate.spells[i] = fields[50 + i].GetUInt32();

    creatureTemplate.VehicleId      = fields[58].GetUInt32();
    creatureTemplate.mingold        = fields[59].GetUInt32();
    creatureTemplate.maxgold        = fields[60].GetUInt32();
    creatureTemplate.AIName         = fields[61].GetString();
    creatureTemplate.MovementType   = uint32(fields[62].GetUInt8());
    creatureTemplate.InhabitType    = uint32(fields[63].GetUInt8());
    creatureTemplate.HoverHeight    = fields[64].GetFloat();
    creatureTemplate.ModHealth      = fields[65].GetFloat();
    creatureTemplate.ModHealthExtra = fields[66].GetFloat();
    creatureTemplate.ModMana        = fields[67].GetFloat();
    creatureTemplate.ModManaExtra   = fields[68].GetFloat();
    creatureTemplate.ModArmor       = fields[69].GetFloat();
    creatureTemplate.ModDamage      = fields[70].GetFloat();
    creatureTemplate.ModExperience  = fields[71].GetFloat();
    creatureTemplate.RacialLeader   = fields[72].GetBool();

    creatureTemplate.movementId         = fields[73].GetUInt32();
    creatureTemplate.RegenHealth        = fields[74].GetBool();
    creatureTemplate.MechanicImmuneMask = fields[75].GetUInt32();
    creatureTemplate.flags_extra        = fields[76].GetUInt32();
    creatureTemplate.ScriptID           = GetScriptId(fields[77].GetString());
}

void ObjectMgr::LoadCreatureTemplateAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                                0       1       2      3       4       5      6
    QueryResult result = WorldDatabase.Query("SELECT entry, path_id, mount, bytes1, bytes2, emote, auras FROM creature_template_addon");

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

        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Creature template (Entry: %u) does not exist but has a record in `creature_template_addon`", entry);
            continue;
        }

        CreatureAddon& creatureAddon = _creatureTemplateAddonStore[entry];

        creatureAddon.path_id = fields[1].GetUInt32();
        creatureAddon.mount   = fields[2].GetUInt32();
        creatureAddon.bytes1  = fields[3].GetUInt32();
        creatureAddon.bytes2  = fields[4].GetUInt32();
        creatureAddon.emote   = fields[5].GetUInt32();

        Tokenizer tokens(fields[6].GetString(), ' ');
        uint8 i = 0;
        creatureAddon.auras.resize(tokens.size());
        for (Tokenizer::const_iterator itr = tokens.begin(); itr != tokens.end(); ++itr)
        {
            uint32 spellId = uint32(atoul(*itr));
            SpellInfo const* AdditionalSpellInfo = sSpellMgr->GetSpellInfo(spellId);
            if (!AdditionalSpellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong spell %u defined in `auras` field in `creature_template_addon`.", entry, spellId);
                continue;
            }

            if (AdditionalSpellInfo->HasAura(DIFFICULTY_NONE, SPELL_AURA_CONTROL_VEHICLE))
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has SPELL_AURA_CONTROL_VEHICLE aura %u defined in `auras` field in `creature_template_addon`.", entry, spellId);

            if (std::find(creatureAddon.auras.begin(), creatureAddon.auras.end(), spellId) != creatureAddon.auras.end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has duplicate aura (spell %u) in `auras` field in `creature_template_addon`.", entry, spellId);
                continue;
            }

            creatureAddon.auras[i++] = spellId;
        }

        if (creatureAddon.mount)
        {
            if (!sCreatureDisplayInfoStore.LookupEntry(creatureAddon.mount))
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid displayInfoId (%u) for mount defined in `creature_template_addon`", entry, creatureAddon.mount);
                creatureAddon.mount = 0;
            }
        }

        if (!sEmotesStore.LookupEntry(creatureAddon.emote))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid emote (%u) defined in `creature_template_addon`.", entry, creatureAddon.emote);
            creatureAddon.emote = 0;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature template addons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::CheckCreatureTemplate(CreatureTemplate const* cInfo)
{
    if (!cInfo)
        return;

    bool ok = true;                                     // bool to allow continue outside this loop
    for (uint32 diff = 0; diff < MAX_CREATURE_DIFFICULTIES && ok; ++diff)
    {
        if (!cInfo->DifficultyEntry[diff])
            continue;
        ok = false;                                     // will be set to true at the end of this loop again

        CreatureTemplate const* difficultyInfo = GetCreatureTemplate(cInfo->DifficultyEntry[diff]);
        if (!difficultyInfo)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has `difficulty_entry_%u`=%u but creature entry %u does not exist.",
                cInfo->Entry, diff + 1, cInfo->DifficultyEntry[diff], cInfo->DifficultyEntry[diff]);
            continue;
        }

        bool ok2 = true;
        for (uint32 diff2 = 0; diff2 < MAX_CREATURE_DIFFICULTIES && ok2; ++diff2)
        {
            ok2 = false;
            if (_difficultyEntries[diff2].find(cInfo->Entry) != _difficultyEntries[diff2].end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) is listed as `difficulty_entry_%u` of another creature, but itself lists %u in `difficulty_entry_%u`.",
                    cInfo->Entry, diff2 + 1, cInfo->DifficultyEntry[diff], diff + 1);
                continue;
            }

            if (_difficultyEntries[diff2].find(cInfo->DifficultyEntry[diff]) != _difficultyEntries[diff2].end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) already listed as `difficulty_entry_%u` for another entry.", cInfo->DifficultyEntry[diff], diff2 + 1);
                continue;
            }

            if (_hasDifficultyEntries[diff2].find(cInfo->DifficultyEntry[diff]) != _hasDifficultyEntries[diff2].end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has `difficulty_entry_%u`=%u but creature entry %u has itself a value in `difficulty_entry_%u`.",
                    cInfo->Entry, diff + 1, cInfo->DifficultyEntry[diff], cInfo->DifficultyEntry[diff], diff2 + 1);
                continue;
            }
            ok2 = true;
        }

        if (!ok2)
            continue;

        if (cInfo->expansion > difficultyInfo->expansion)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, exp %u) has different `exp` in difficulty %u mode (Entry: %u, exp %u).",
                cInfo->Entry, cInfo->expansion, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->expansion);
        }

        if (cInfo->faction != difficultyInfo->faction)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, faction %u) has different `faction` in difficulty %u mode (Entry: %u, faction %u).",
                cInfo->Entry, cInfo->faction, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->faction);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `faction`=%u WHERE `entry`=%u;",
                cInfo->faction, cInfo->DifficultyEntry[diff]);
        }

        if (cInfo->unit_class != difficultyInfo->unit_class)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, class %u) has different `unit_class` in difficulty %u mode (Entry: %u, class %u).",
                cInfo->Entry, cInfo->unit_class, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->unit_class);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `unit_class`=%u WHERE `entry`=%u;",
                cInfo->unit_class, cInfo->DifficultyEntry[diff]);
            continue;
        }

        if (cInfo->npcflag != difficultyInfo->npcflag)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, `npcflag`: " UI64FMTD ") has different `npcflag` in difficulty %u mode (Entry: %u, `npcflag`: " UI64FMTD ").",
                cInfo->Entry, cInfo->npcflag, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->npcflag);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `npcflag`=" UI64FMTD " WHERE `entry`=%u;",
                cInfo->npcflag, cInfo->DifficultyEntry[diff]);
            continue;
        }

        if (cInfo->family != difficultyInfo->family)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, family %u) has different `family` in difficulty %u mode (Entry: %u, family %u).",
                cInfo->Entry, cInfo->family, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->family);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `family`=%u WHERE `entry`=%u;",
                cInfo->family, cInfo->DifficultyEntry[diff]);
        }

        if (cInfo->trainer_class != difficultyInfo->trainer_class)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, trainer_class: %u) has different `trainer_class` in difficulty %u mode (Entry: %u, trainer_class: %u).",
                cInfo->Entry, cInfo->trainer_class, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->trainer_class);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `trainer_class`=%u WHERE `entry`=%u;",
                cInfo->trainer_class, cInfo->DifficultyEntry[diff]);
            continue;
        }

        if (cInfo->trainer_race != difficultyInfo->trainer_race)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, trainer_race: %u) has different `trainer_race` in difficulty %u mode (Entry: %u, trainer_race: %u).",
                cInfo->Entry, cInfo->trainer_race, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->trainer_race);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `trainer_race`=%u WHERE `entry`=%u;",
                cInfo->trainer_race, cInfo->DifficultyEntry[diff]);
            continue;
        }

        if (cInfo->trainer_type != difficultyInfo->trainer_type)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, trainer_type: %u) has different `trainer_type` in difficulty %u mode (Entry: %u, trainer_type: %u).",
                cInfo->Entry, cInfo->trainer_type, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->trainer_type);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `trainer_type`=%u WHERE `entry`=%u;",
                cInfo->trainer_type, cInfo->DifficultyEntry[diff]);
            continue;
        }

        if (cInfo->type != difficultyInfo->type)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, type %u) has different `type` in difficulty %u mode (Entry: %u, type %u).",
                cInfo->Entry, cInfo->type, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->type);
            TC_LOG_ERROR("sql.sql", "Possible FIX: UPDATE `creature_template` SET `type`=%u WHERE `entry`=%u;",
                cInfo->type, cInfo->DifficultyEntry[diff]);
        }

        if (!cInfo->VehicleId && difficultyInfo->VehicleId)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u, VehicleId %u) has different `VehicleId` in difficulty %u mode (Entry: %u, VehicleId %u).",
                cInfo->Entry, cInfo->VehicleId, diff + 1, cInfo->DifficultyEntry[diff], difficultyInfo->VehicleId);
        }

        if (!difficultyInfo->AIName.empty())
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists difficulty %u mode entry %u with `AIName` filled in. `AIName` of difficulty 0 mode creature is always used instead.",
                cInfo->Entry, diff + 1, cInfo->DifficultyEntry[diff]);
            continue;
        }

        if (difficultyInfo->ScriptID)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists difficulty %u mode entry %u with `ScriptName` filled in. `ScriptName` of difficulty 0 mode creature is always used instead.",
                cInfo->Entry, diff + 1, cInfo->DifficultyEntry[diff]);
            continue;
        }

        _hasDifficultyEntries[diff].insert(cInfo->Entry);
        _difficultyEntries[diff].insert(cInfo->DifficultyEntry[diff]);
        ok = true;
    }

    FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(cInfo->faction);
    if (!factionTemplate)
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has non-existing faction template (%u).", cInfo->Entry, cInfo->faction);

    // used later for scale
    CreatureDisplayInfoEntry const* displayScaleEntry = NULL;

    if (cInfo->Modelid1)
    {
        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(cInfo->Modelid1);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists non-existing Modelid1 id (%u), this can crash the client.", cInfo->Entry, cInfo->Modelid1);
            const_cast<CreatureTemplate*>(cInfo)->Modelid1 = 0;
        }
        else if (!displayScaleEntry)
            displayScaleEntry = displayEntry;

        CreatureModelInfo const* modelInfo = GetCreatureModelInfo(cInfo->Modelid1);
        if (!modelInfo)
            TC_LOG_ERROR("sql.sql", "No model data exist for `Modelid1` = %u listed by creature (Entry: %u).", cInfo->Modelid1, cInfo->Entry);
    }

    if (cInfo->Modelid2)
    {
        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(cInfo->Modelid2);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists non-existing Modelid2 id (%u), this can crash the client.", cInfo->Entry, cInfo->Modelid2);
            const_cast<CreatureTemplate*>(cInfo)->Modelid2 = 0;
        }
        else if (!displayScaleEntry)
            displayScaleEntry = displayEntry;

        CreatureModelInfo const* modelInfo = GetCreatureModelInfo(cInfo->Modelid2);
        if (!modelInfo)
            TC_LOG_ERROR("sql.sql", "No model data exist for `Modelid2` = %u listed by creature (Entry: %u).", cInfo->Modelid2, cInfo->Entry);
    }

    if (cInfo->Modelid3)
    {
        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(cInfo->Modelid3);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists non-existing Modelid3 id (%u), this can crash the client.", cInfo->Entry, cInfo->Modelid3);
            const_cast<CreatureTemplate*>(cInfo)->Modelid3 = 0;
        }
        else if (!displayScaleEntry)
            displayScaleEntry = displayEntry;

        CreatureModelInfo const* modelInfo = GetCreatureModelInfo(cInfo->Modelid3);
        if (!modelInfo)
            TC_LOG_ERROR("sql.sql", "No model data exist for `Modelid3` = %u listed by creature (Entry: %u).", cInfo->Modelid3, cInfo->Entry);
    }

    if (cInfo->Modelid4)
    {
        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(cInfo->Modelid4);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists non-existing Modelid4 id (%u), this can crash the client.", cInfo->Entry, cInfo->Modelid4);
            const_cast<CreatureTemplate*>(cInfo)->Modelid4 = 0;
        }
        else if (!displayScaleEntry)
            displayScaleEntry = displayEntry;

        CreatureModelInfo const* modelInfo = GetCreatureModelInfo(cInfo->Modelid4);
        if (!modelInfo)
            TC_LOG_ERROR("sql.sql", "No model data exist for `Modelid4` = %u listed by creature (Entry: %u).", cInfo->Modelid4, cInfo->Entry);
    }

    if (!displayScaleEntry)
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) does not have any existing display id in Modelid1/Modelid2/Modelid3/Modelid4.", cInfo->Entry);

    for (int k = 0; k < MAX_KILL_CREDIT; ++k)
    {
        if (cInfo->KillCredit[k])
        {
            if (!GetCreatureTemplate(cInfo->KillCredit[k]))
            {
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) lists non-existing creature entry %u in `KillCredit%d`.", cInfo->Entry, cInfo->KillCredit[k], k + 1);
                const_cast<CreatureTemplate*>(cInfo)->KillCredit[k] = 0;
            }
        }
    }

    if (!cInfo->unit_class || ((1 << (cInfo->unit_class-1)) & CLASSMASK_ALL_CREATURES) == 0)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid unit_class (%u) in creature_template. Set to 1 (UNIT_CLASS_WARRIOR).", cInfo->Entry, cInfo->unit_class);
        const_cast<CreatureTemplate*>(cInfo)->unit_class = UNIT_CLASS_WARRIOR;
    }

    if (cInfo->dmgschool >= MAX_SPELL_SCHOOL)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid spell school value (%u) in `dmgschool`.", cInfo->Entry, cInfo->dmgschool);
        const_cast<CreatureTemplate*>(cInfo)->dmgschool = SPELL_SCHOOL_NORMAL;
    }

    if (cInfo->BaseAttackTime == 0)
        const_cast<CreatureTemplate*>(cInfo)->BaseAttackTime  = BASE_ATTACK_TIME;

    if (cInfo->RangeAttackTime == 0)
        const_cast<CreatureTemplate*>(cInfo)->RangeAttackTime = BASE_ATTACK_TIME;

    if ((cInfo->npcflag & UNIT_NPC_FLAG_TRAINER) && cInfo->trainer_type >= MAX_TRAINER_TYPE)
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong trainer type %u.", cInfo->Entry, cInfo->trainer_type);

    if (cInfo->speed_walk == 0.0f)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong value (%f) in speed_walk, set to 1.", cInfo->Entry, cInfo->speed_walk);
        const_cast<CreatureTemplate*>(cInfo)->speed_walk = 1.0f;
    }

    if (cInfo->speed_run == 0.0f)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong value (%f) in speed_run, set to 1.14286.", cInfo->Entry, cInfo->speed_run);
        const_cast<CreatureTemplate*>(cInfo)->speed_run = 1.14286f;
    }

    if (cInfo->type && !sCreatureTypeStore.LookupEntry(cInfo->type))
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid creature type (%u) in `type`.", cInfo->Entry, cInfo->type);
        const_cast<CreatureTemplate*>(cInfo)->type = CREATURE_TYPE_HUMANOID;
    }

    // must exist or used hidden but used in data horse case
    if (cInfo->family && !sCreatureFamilyStore.LookupEntry(cInfo->family) && cInfo->family != CREATURE_FAMILY_HORSE_CUSTOM)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid creature family (%u) in `family`.", cInfo->Entry, cInfo->family);
        const_cast<CreatureTemplate*>(cInfo)->family = 0;
    }

    if (cInfo->InhabitType <= 0 || cInfo->InhabitType > INHABIT_ANYWHERE)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong value (%u) in `InhabitType`, creature will not correctly walk/swim/fly.", cInfo->Entry, cInfo->InhabitType);
        const_cast<CreatureTemplate*>(cInfo)->InhabitType = INHABIT_ANYWHERE;
    }

    if (cInfo->HoverHeight < 0.0f)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong value (%f) in `HoverHeight`", cInfo->Entry, cInfo->HoverHeight);
        const_cast<CreatureTemplate*>(cInfo)->HoverHeight = 1.0f;
    }

    if (cInfo->VehicleId)
    {
        VehicleEntry const* vehId = sVehicleStore.LookupEntry(cInfo->VehicleId);
        if (!vehId)
        {
             TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has a non-existing VehicleId (%u). This *WILL* cause the client to freeze!", cInfo->Entry, cInfo->VehicleId);
             const_cast<CreatureTemplate*>(cInfo)->VehicleId = 0;
        }
    }

    for (uint8 j = 0; j < CREATURE_MAX_SPELLS; ++j)
    {
        if (cInfo->spells[j] && !sSpellMgr->GetSpellInfo(cInfo->spells[j]))
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has non-existing Spell%d (%u), set to 0.", cInfo->Entry, j+1, cInfo->spells[j]);
            const_cast<CreatureTemplate*>(cInfo)->spells[j] = 0;
        }
    }

    if (cInfo->MovementType >= MAX_DB_MOTION_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has wrong movement generator type (%u), ignored and set to IDLE.", cInfo->Entry, cInfo->MovementType);
        const_cast<CreatureTemplate*>(cInfo)->MovementType = IDLE_MOTION_TYPE;
    }

    /// if not set custom creature scale then load scale from CreatureDisplayInfo.dbc
    if (cInfo->scale <= 0.0f)
    {
        if (displayScaleEntry)
            const_cast<CreatureTemplate*>(cInfo)->scale = displayScaleEntry->CreatureModelScale;
        else
            const_cast<CreatureTemplate*>(cInfo)->scale = 1.0f;
    }

    if (cInfo->expansion > (MAX_EXPANSIONS - 1))
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: %u) with `exp` %u. Ignored and set to 0.", cInfo->Entry, cInfo->expansion);
        const_cast<CreatureTemplate*>(cInfo)->expansion = 0;
    }

    if (cInfo->expansionUnknown > MAX_EXPANSIONS)
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: %u) with `exp_unk` %u. Ignored and set to 0.", cInfo->Entry, cInfo->expansionUnknown);
        const_cast<CreatureTemplate*>(cInfo)->expansionUnknown = 0;
    }

    if (uint32 badFlags = (cInfo->flags_extra & ~CREATURE_FLAG_EXTRA_DB_ALLOWED))
    {
        TC_LOG_ERROR("sql.sql", "Table `creature_template` lists creature (Entry: %u) with disallowed `flags_extra` %u, removing incorrect flag.", cInfo->Entry, badFlags);
        const_cast<CreatureTemplate*>(cInfo)->flags_extra &= CREATURE_FLAG_EXTRA_DB_ALLOWED;
    }

    // -1 is used in the client for auto-updating the levels
    // having their expansion set to it to the latest one
    if (cInfo->expansion == -1)
    {
        const_cast<CreatureTemplate*>(cInfo)->minlevel = (MAX_LEVEL + cInfo->minlevel);
        const_cast<CreatureTemplate*>(cInfo)->maxlevel = (MAX_LEVEL + cInfo->maxlevel);
        const_cast<CreatureTemplate*>(cInfo)->expansion = CURRENT_EXPANSION;
    }

    if (cInfo->minlevel < 1 || cInfo->minlevel > STRONG_MAX_LEVEL)
    {
        TC_LOG_ERROR("sql.sql", "Creature (ID: %u): MinLevel %i is not within [1, 255], value has been set to 1.", cInfo->Entry, cInfo->minlevel);
        const_cast<CreatureTemplate*>(cInfo)->minlevel = 1;
    }

    if (cInfo->maxlevel < 1 || cInfo->maxlevel > STRONG_MAX_LEVEL)
    {
        TC_LOG_ERROR("sql.sql", "Creature (ID: %u): MaxLevel %i is not within [1, 255], value has been set to 1.", cInfo->Entry, cInfo->maxlevel);
        const_cast<CreatureTemplate*>(cInfo)->maxlevel = 1;
    }

    const_cast<CreatureTemplate*>(cInfo)->ModDamage *= Creature::_GetDamageMod(cInfo->rank);
}

void ObjectMgr::LoadCreatureAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                                0       1       2      3       4       5      6
    QueryResult result = WorldDatabase.Query("SELECT guid, path_id, mount, bytes1, bytes2, emote, auras FROM creature_addon");

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
            TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") does not exist but has a record in `creature_addon`", guid);
            continue;
        }

        CreatureAddon& creatureAddon = _creatureAddonStore[guid];

        creatureAddon.path_id = fields[1].GetUInt32();
        if (creData->movementType == WAYPOINT_MOTION_TYPE && !creatureAddon.path_id)
        {
            const_cast<CreatureData*>(creData)->movementType = IDLE_MOTION_TYPE;
            TC_LOG_ERROR("sql.sql", "Creature (GUID " UI64FMTD ") has movement type set to WAYPOINT_MOTION_TYPE but no path assigned", guid);
        }

        creatureAddon.mount   = fields[2].GetUInt32();
        creatureAddon.bytes1  = fields[3].GetUInt32();
        creatureAddon.bytes2  = fields[4].GetUInt32();
        creatureAddon.emote   = fields[5].GetUInt32();

        Tokenizer tokens(fields[6].GetString(), ' ');
        uint8 i = 0;
        creatureAddon.auras.resize(tokens.size());
        for (Tokenizer::const_iterator itr = tokens.begin(); itr != tokens.end(); ++itr)
        {
            uint32 spellId = uint32(atoul(*itr));
            SpellInfo const* AdditionalSpellInfo = sSpellMgr->GetSpellInfo(spellId);
            if (!AdditionalSpellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") has wrong spell %u defined in `auras` field in `creature_addon`.", guid, spellId);
                continue;
            }

            if (AdditionalSpellInfo->HasAura(DIFFICULTY_NONE, SPELL_AURA_CONTROL_VEHICLE))
                TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") has SPELL_AURA_CONTROL_VEHICLE aura %u defined in `auras` field in `creature_addon`.", guid, spellId);

            if (std::find(creatureAddon.auras.begin(), creatureAddon.auras.end(), spellId) != creatureAddon.auras.end())
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") has duplicate aura (spell %u) in `auras` field in `creature_addon`.", guid, spellId);
                continue;
            }

            creatureAddon.auras[i++] = spellId;
        }

        if (creatureAddon.mount)
        {
            if (!sCreatureDisplayInfoStore.LookupEntry(creatureAddon.mount))
            {
                TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") has invalid displayInfoId (%u) for mount defined in `creature_addon`", guid, creatureAddon.mount);
                creatureAddon.mount = 0;
            }
        }

        if (!sEmotesStore.LookupEntry(creatureAddon.emote))
        {
            TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") has invalid emote (%u) defined in `creature_addon`.", guid, creatureAddon.emote);
            creatureAddon.emote = 0;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature addons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGameObjectAddons()
{
    uint32 oldMSTime = getMSTime();

    //                                               0     1                 2
    QueryResult result = WorldDatabase.Query("SELECT guid, invisibilityType, invisibilityValue FROM gameobject_addon");

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

        const GameObjectData* goData = GetGOData(guid);
        if (!goData)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: " UI64FMTD ") does not exist but has a record in `gameobject_addon`", guid);
            continue;
        }

        GameObjectAddon& gameObjectAddon = _gameObjectAddonStore[guid];
        gameObjectAddon.invisibilityType = InvisibilityType(fields[1].GetUInt8());
        gameObjectAddon.InvisibilityValue = fields[2].GetUInt32();

        if (gameObjectAddon.invisibilityType >= TOTAL_INVISIBILITY_TYPES)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: " UI64FMTD ") has invalid InvisibilityType in `gameobject_addon`", guid);
            gameObjectAddon.invisibilityType = INVISIBILITY_GENERAL;
            gameObjectAddon.InvisibilityValue = 0;
        }

        if (gameObjectAddon.invisibilityType && !gameObjectAddon.InvisibilityValue)
        {
            TC_LOG_ERROR("sql.sql", "GameObject (GUID: " UI64FMTD ") has InvisibilityType set but has no InvisibilityValue in `gameobject_addon`, set to 1", guid);
            gameObjectAddon.InvisibilityValue = 1;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u gameobject addons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

GameObjectAddon const* ObjectMgr::GetGameObjectAddon(ObjectGuid::LowType lowguid)
{
    GameObjectAddonContainer::const_iterator itr = _gameObjectAddonStore.find(lowguid);
    if (itr != _gameObjectAddonStore.end())
        return &(itr->second);

    return NULL;
}

CreatureAddon const* ObjectMgr::GetCreatureAddon(ObjectGuid::LowType lowguid)
{
    CreatureAddonContainer::const_iterator itr = _creatureAddonStore.find(lowguid);
    if (itr != _creatureAddonStore.end())
        return &(itr->second);

    return NULL;
}

CreatureAddon const* ObjectMgr::GetCreatureTemplateAddon(uint32 entry)
{
    CreatureTemplateAddonContainer::const_iterator itr = _creatureTemplateAddonStore.find(entry);
    if (itr != _creatureTemplateAddonStore.end())
        return &(itr->second);

    return NULL;
}

EquipmentInfo const* ObjectMgr::GetEquipmentInfo(uint32 entry, int8& id)
{
    EquipmentInfoContainer::const_iterator itr = _equipmentInfoStore.find(entry);
    if (itr == _equipmentInfoStore.end())
        return NULL;

    if (itr->second.empty())
        return NULL;

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

    return NULL;
}

void ObjectMgr::LoadEquipmentTemplates()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0     1       2           3           4
    QueryResult result = WorldDatabase.Query("SELECT CreatureID, ID, ItemID1, ItemID2, ItemID3 FROM creature_equip_template");

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

        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Creature template (CreatureID: %u) does not exist but has a record in `creature_equip_template`", entry);
            continue;
        }

        uint8 id = fields[1].GetUInt8();
        if (!id)
        {
            TC_LOG_ERROR("sql.sql", "Creature equipment template with id 0 found for creature %u, skipped.", entry);
            continue;
        }

        EquipmentInfo& equipmentInfo = _equipmentInfoStore[entry][id];

        equipmentInfo.ItemEntry[0] = fields[2].GetUInt32();
        equipmentInfo.ItemEntry[1] = fields[3].GetUInt32();
        equipmentInfo.ItemEntry[2] = fields[4].GetUInt32();

        for (uint8 i = 0; i < MAX_EQUIPMENT_ITEMS; ++i)
        {
            if (!equipmentInfo.ItemEntry[i])
                continue;

            ItemEntry const* dbcItem = sItemStore.LookupEntry(equipmentInfo.ItemEntry[i]);

            if (!dbcItem)
            {
                TC_LOG_ERROR("sql.sql", "Unknown item (ID=%u) in creature_equip_template.ItemID%u for CreatureID = %u and ID=%u, forced to 0.",
                    equipmentInfo.ItemEntry[i], i+1, entry, id);
                equipmentInfo.ItemEntry[i] = 0;
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
                TC_LOG_ERROR("sql.sql", "Item (ID=%u) in creature_equip_template.ItemID%u for CreatureID = %u and ID = %u is not equipable in a hand, forced to 0.",
                    equipmentInfo.ItemEntry[i], i+1, entry, id);
                equipmentInfo.ItemEntry[i] = 0;
            }
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u equipment templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

CreatureModelInfo const* ObjectMgr::GetCreatureModelInfo(uint32 modelId)
{
    CreatureModelContainer::const_iterator itr = _creatureModelStore.find(modelId);
    if (itr != _creatureModelStore.end())
        return &(itr->second);

    return NULL;
}

uint32 ObjectMgr::ChooseDisplayId(CreatureTemplate const* cinfo, CreatureData const* data /*= NULL*/)
{
    // Load creature model (display id)
    if (data && data->displayid)
        return data->displayid;

    if (!(cinfo->flags_extra & CREATURE_FLAG_EXTRA_TRIGGER))
        return cinfo->GetRandomValidModelId();

    // Triggers by default receive the invisible model
    return cinfo->GetFirstInvisibleModel();
}

void ObjectMgr::ChooseCreatureFlags(CreatureTemplate const* cinfo, uint64& npcflag, uint32& unit_flags, uint32& dynamicflags, CreatureData const* data /*= NULL*/)
{
    npcflag = cinfo->npcflag;
    unit_flags = cinfo->unit_flags;
    dynamicflags = cinfo->dynamicflags;

    if (data)
    {
        if (data->npcflag)
            npcflag = data->npcflag;

        if (data->unit_flags)
            unit_flags = data->unit_flags;

        if (data->dynamicflags)
            dynamicflags = data->dynamicflags;
    }
}

CreatureModelInfo const* ObjectMgr::GetCreatureModelRandomGender(uint32* displayID)
{
    CreatureModelInfo const* modelInfo = GetCreatureModelInfo(*displayID);
    if (!modelInfo)
        return NULL;

    // If a model for another gender exists, 50% chance to use it
    if (modelInfo->displayId_other_gender != 0 && urand(0, 1) == 0)
    {
        CreatureModelInfo const* minfo_tmp = GetCreatureModelInfo(modelInfo->displayId_other_gender);
        if (!minfo_tmp)
            TC_LOG_ERROR("sql.sql", "Model (Entry: %u) has modelid_other_gender %u not found in table `creature_model_info`. ", *displayID, modelInfo->displayId_other_gender);
        else
        {
            // DisplayID changed
            *displayID = modelInfo->displayId_other_gender;
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

    _creatureModelStore.rehash(result->GetRowCount());
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
            TC_LOG_ERROR("sql.sql", "Table `creature_model_info` has a non-existent DisplayID (ID: %u). Skipped.", displayId);
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
            //TC_LOG_ERROR("sql.sql", "Table `creature_model_info` has an unimplemented Gender (ID: %i) being used by DisplayID (ID: %u). Gender set to GENDER_MALE.", modelInfo.gender, modelId);
            modelInfo.gender = GENDER_MALE;
        }

        if (modelInfo.displayId_other_gender && !sCreatureDisplayInfoStore.LookupEntry(modelInfo.displayId_other_gender))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_model_info` has a non-existent DisplayID_Other_Gender (ID: %u) being used by DisplayID (ID: %u).", modelInfo.displayId_other_gender, displayId);
            modelInfo.displayId_other_gender = 0;
        }

        if (modelInfo.combat_reach < 0.1f)
            modelInfo.combat_reach = DEFAULT_COMBAT_REACH;

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

    TC_LOG_INFO("server.loading", ">> Loaded %u creature model based info in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadLinkedRespawn()
{
    uint32 oldMSTime = getMSTime();

    _linkedRespawnStore.clear();
    //                                                 0        1          2
    QueryResult result = WorldDatabase.Query("SELECT guid, linkedGuid, linkType FROM linked_respawn ORDER BY guid ASC");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 linked respawns. DB table `linked_respawn` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guidLow = fields[0].GetUInt64();
        ObjectGuid::LowType linkedGuidLow = fields[1].GetUInt64();
        uint8  linkType = fields[2].GetUInt8();

        ObjectGuid guid, linkedGuid;
        bool error = false;
        switch (linkType)
        {
            case CREATURE_TO_CREATURE:
            {
                const CreatureData* slave = GetCreatureData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (guid) '" UI64FMTD "' not found in creature table", guidLow);
                    error = true;
                    break;
                }

                const CreatureData* master = GetCreatureData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (linkedGuid) '" UI64FMTD "' not found in creature table", linkedGuidLow);
                    error = true;
                    break;
                }

                const MapEntry* const map = sMapStore.LookupEntry(master->mapid);
                if (!map || !map->Instanceable() || (master->mapid != slave->mapid))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '" UI64FMTD "' linking to Creature '" UI64FMTD "' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                if (!(master->spawnMask & slave->spawnMask))  // they must have a possibility to meet (normal/heroic difficulty)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '" UI64FMTD "' linking to Creature '" UI64FMTD "' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::Creature>(slave->mapid, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::Creature>(master->mapid, master->id, linkedGuidLow);
                break;
            }
            case CREATURE_TO_GO:
            {
                const CreatureData* slave = GetCreatureData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (guid) '" UI64FMTD "' not found in creature table", guidLow);
                    error = true;
                    break;
                }

                const GameObjectData* master = GetGOData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (linkedGuid) '" UI64FMTD "' not found in gameobject table", linkedGuidLow);
                    error = true;
                    break;
                }

                const MapEntry* const map = sMapStore.LookupEntry(master->mapid);
                if (!map || !map->Instanceable() || (master->mapid != slave->mapid))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '" UI64FMTD "' linking to Gameobject '" UI64FMTD "' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                if (!(master->spawnMask & slave->spawnMask))  // they must have a possibility to meet (normal/heroic difficulty)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '" UI64FMTD "' linking to Gameobject '" UI64FMTD "' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::Creature>(slave->mapid, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::GameObject>(master->mapid, master->id, linkedGuidLow);
                break;
            }
            case GO_TO_GO:
            {
                const GameObjectData* slave = GetGOData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (guid) '" UI64FMTD "' not found in gameobject table", guidLow);
                    error = true;
                    break;
                }

                const GameObjectData* master = GetGOData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (linkedGuid) '" UI64FMTD "' not found in gameobject table", linkedGuidLow);
                    error = true;
                    break;
                }

                const MapEntry* const map = sMapStore.LookupEntry(master->mapid);
                if (!map || !map->Instanceable() || (master->mapid != slave->mapid))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '" UI64FMTD "' linking to Gameobject '" UI64FMTD "' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                if (!(master->spawnMask & slave->spawnMask))  // they must have a possibility to meet (normal/heroic difficulty)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '" UI64FMTD "' linking to Gameobject '" UI64FMTD "' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::GameObject>(slave->mapid, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::GameObject>(master->mapid, master->id, linkedGuidLow);
                break;
            }
            case GO_TO_CREATURE:
            {
                const GameObjectData* slave = GetGOData(guidLow);
                if (!slave)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject (guid) '" UI64FMTD "' not found in gameobject table", guidLow);
                    error = true;
                    break;
                }

                const CreatureData* master = GetCreatureData(linkedGuidLow);
                if (!master)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature (linkedGuid) '" UI64FMTD "' not found in creature table", linkedGuidLow);
                    error = true;
                    break;
                }

                const MapEntry* const map = sMapStore.LookupEntry(master->mapid);
                if (!map || !map->Instanceable() || (master->mapid != slave->mapid))
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '" UI64FMTD "' linking to Creature '" UI64FMTD "' on an unpermitted map.", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                if (!(master->spawnMask & slave->spawnMask))  // they must have a possibility to meet (normal/heroic difficulty)
                {
                    TC_LOG_ERROR("sql.sql", "LinkedRespawn: Gameobject '" UI64FMTD "' linking to Creature '" UI64FMTD "' with not corresponding spawnMask", guidLow, linkedGuidLow);
                    error = true;
                    break;
                }

                guid = ObjectGuid::Create<HighGuid::GameObject>(slave->mapid, slave->id, guidLow);
                linkedGuid = ObjectGuid::Create<HighGuid::Creature>(master->mapid, master->id, linkedGuidLow);
                break;
            }
        }

        if (!error)
            _linkedRespawnStore[guid] = linkedGuid;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " UI64FMTD " linked respawns in %u ms", uint64(_linkedRespawnStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::SetCreatureLinkedRespawn(ObjectGuid::LowType guidLow, ObjectGuid::LowType linkedGuidLow)
{
    if (!guidLow)
        return false;

    CreatureData const* master = GetCreatureData(guidLow);
    ASSERT(master);
    ObjectGuid guid = ObjectGuid::Create<HighGuid::Creature>(master->mapid, master->id, guidLow);

    if (!linkedGuidLow) // we're removing the linking
    {
        _linkedRespawnStore.erase(guid);
        PreparedStatement *stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CRELINKED_RESPAWN);
        stmt->setUInt64(0, guidLow);
        WorldDatabase.Execute(stmt);
        return true;
    }

    CreatureData const* slave = GetCreatureData(linkedGuidLow);
    if (!slave)
    {
        TC_LOG_ERROR("sql.sql", "Creature '" UI64FMTD "' linking to non-existent creature '" UI64FMTD "'.", guidLow, linkedGuidLow);
        return false;
    }

    MapEntry const* map = sMapStore.LookupEntry(master->mapid);
    if (!map || !map->Instanceable() || (master->mapid != slave->mapid))
    {
        TC_LOG_ERROR("sql.sql", "Creature '" UI64FMTD "' linking to '" UI64FMTD "' on an unpermitted map.", guidLow, linkedGuidLow);
        return false;
    }

    if (!(master->spawnMask & slave->spawnMask))  // they must have a possibility to meet (normal/heroic difficulty)
    {
        TC_LOG_ERROR("sql.sql", "LinkedRespawn: Creature '" UI64FMTD "' linking to '" UI64FMTD "' with not corresponding spawnMask", guidLow, linkedGuidLow);
        return false;
    }

    ObjectGuid linkedGuid = ObjectGuid::Create<HighGuid::Creature>(slave->mapid, slave->id, linkedGuidLow);

    _linkedRespawnStore[guid] = linkedGuid;
    PreparedStatement *stmt = WorldDatabase.GetPreparedStatement(WORLD_REP_CREATURE_LINKED_RESPAWN);
    stmt->setUInt64(0, guidLow);
    stmt->setUInt64(1, linkedGuidLow);
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
                    TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has summoner with non existing entry %u for creature summoner type, skipped.", summonerId);
                    continue;
                }
                break;
            case SUMMONER_TYPE_GAMEOBJECT:
                if (!GetGameObjectTemplate(summonerId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has summoner with non existing entry %u for gameobject summoner type, skipped.", summonerId);
                    continue;
                }
                break;
            case SUMMONER_TYPE_MAP:
                if (!sMapStore.LookupEntry(summonerId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has summoner with non existing entry %u for map summoner type, skipped.", summonerId);
                    continue;
                }
                break;
            default:
                TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has unhandled summoner type %u for summoner %u, skipped.", summonerType, summonerId);
                continue;
        }

        TempSummonData data;
        data.entry                      = fields[3].GetUInt32();

        if (!GetCreatureTemplate(data.entry))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has creature in group [Summoner ID: %u, Summoner Type: %u, Group ID: %u] with non existing creature entry %u, skipped.", summonerId, summonerType, group, data.entry);
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
            TC_LOG_ERROR("sql.sql", "Table `creature_summon_groups` has unhandled temp summon type %u in group [Summoner ID: %u, Summoner Type: %u, Group ID: %u] for creature entry %u, skipped.", data.type, summonerId, summonerType, group, data.entry);
            continue;
        }

        data.time                       = fields[9].GetUInt32();

        TempSummonGroupKey key(summonerId, summonerType, group);
        _tempSummonDataStore[key].push_back(data);

        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u temp summons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatures()
{
    uint32 oldMSTime = getMSTime();

    //                                               0              1   2    3        4             5           6           7           8            9              10
    QueryResult result = WorldDatabase.Query("SELECT creature.guid, id, map, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, "
    //   11               12         13       14            15         16          17          18                19                   20                     21                22
        "currentwaypoint, curhealth, curmana, MovementType, spawnMask, eventEntry, pool_entry, creature.npcflag, creature.unit_flags, creature.dynamicflags, creature.phaseid, creature.phasegroup "
        "FROM creature "
        "LEFT OUTER JOIN game_event_creature ON creature.guid = game_event_creature.guid "
        "LEFT OUTER JOIN pool_creature ON creature.guid = pool_creature.guid");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 creatures. DB table `creature` is empty.");
        return;
    }

    // Build single time for check spawnmask
    std::map<uint32, uint32> spawnMasks;
    for (auto& mapDifficultyPair : sMapDifficultyMap)
        for (auto& difficultyPair : mapDifficultyPair.second)
            spawnMasks[mapDifficultyPair.first] |= (1 << difficultyPair.first);


    _creatureDataStore.rehash(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guid = fields[0].GetUInt64();
        uint32 entry        = fields[1].GetUInt32();

        CreatureTemplate const* cInfo = GetCreatureTemplate(entry);
        if (!cInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD ") with non existing creature entry %u, skipped.", guid, entry);
            continue;
        }

        CreatureData& data = _creatureDataStore[guid];
        data.id             = entry;
        data.mapid          = fields[2].GetUInt16();
        data.displayid      = fields[3].GetUInt32();
        data.equipmentId    = fields[4].GetInt8();
        data.posX           = fields[5].GetFloat();
        data.posY           = fields[6].GetFloat();
        data.posZ           = fields[7].GetFloat();
        data.orientation    = fields[8].GetFloat();
        data.spawntimesecs  = fields[9].GetUInt32();
        data.spawndist      = fields[10].GetFloat();
        data.currentwaypoint= fields[11].GetUInt32();
        data.curhealth      = fields[12].GetUInt32();
        data.curmana        = fields[13].GetUInt32();
        data.movementType   = fields[14].GetUInt8();
        data.spawnMask      = fields[15].GetUInt32();
        int16 gameEvent     = fields[16].GetInt8();
        uint32 PoolId       = fields[17].GetUInt32();
        data.npcflag        = fields[18].GetUInt64();
        data.unit_flags     = fields[19].GetUInt32();
        data.dynamicflags   = fields[20].GetUInt32();
        data.phaseid        = fields[21].GetUInt32();
        data.phaseGroup     = fields[22].GetUInt32();

        MapEntry const* mapEntry = sMapStore.LookupEntry(data.mapid);
        if (!mapEntry)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD ") that spawned at nonexistent map (Id: %u), skipped.", guid, data.mapid);
            continue;
        }

        // Skip spawnMask check for transport maps
        if (!IsTransportMap(data.mapid) && data.spawnMask & ~spawnMasks[data.mapid])
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD ") that have wrong spawn mask %u including unsupported difficulty modes for map (Id: %u).", guid, data.spawnMask, data.mapid);

        bool ok = true;
        for (uint32 diff = 0; diff < MAX_CREATURE_DIFFICULTIES && ok; ++diff)
        {
            if (_difficultyEntries[diff].find(data.id) != _difficultyEntries[diff].end())
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD ") that is listed as difficulty %u template (entry: %u) in `creature_template`, skipped.",
                    guid, diff + 1, data.id);
                ok = false;
            }
        }
        if (!ok)
            continue;

        // -1 random, 0 no equipment
        if (data.equipmentId != 0)
        {
            if (!GetEquipmentInfo(data.id, data.equipmentId))
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (Entry: %u) with equipment_id %u not found in table `creature_equip_template`, set to no equipment.", data.id, data.equipmentId);
                data.equipmentId = 0;
            }
        }

        if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
        {
            if (!mapEntry || !mapEntry->IsDungeon())
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD " Entry: %u) with `creature_template`.`flags_extra` including CREATURE_FLAG_EXTRA_INSTANCE_BIND but creature is not in instance.", guid, data.id);
        }

        if (data.spawndist < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD " Entry: %u) with `spawndist`< 0, set to 0.", guid, data.id);
            data.spawndist = 0.0f;
        }
        else if (data.movementType == RANDOM_MOTION_TYPE)
        {
            if (data.spawndist == 0.0f)
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD " Entry: %u) with `MovementType`=1 (random movement) but with `spawndist`=0, replace by idle movement type (0).", guid, data.id);
                data.movementType = IDLE_MOTION_TYPE;
            }
        }
        else if (data.movementType == IDLE_MOTION_TYPE)
        {
            if (data.spawndist != 0.0f)
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD " Entry: %u) with `MovementType`=0 (idle) have `spawndist`<>0, set to 0.", guid, data.id);
                data.spawndist = 0.0f;
            }
        }

        if (std::abs(data.orientation) > 2 * float(M_PI))
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` has creature (GUID: " UI64FMTD " Entry: %u) with abs(`orientation`) > 2*PI (orientation is expressed in radians), normalized.", guid, data.id);
            data.orientation = Position::NormalizeOrientation(data.orientation);
        }

        data.phaseMask = 1;

        if (data.phaseGroup && data.phaseid)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: " UI64FMTD " Entry: %u) with both `phaseid` and `phasegroup` set, `phasegroup` set to 0", guid, data.id);
            data.phaseGroup = 0;
        }

        if (data.phaseid)
        {
            PhaseEntry const* phase = sPhaseStore.LookupEntry(data.phaseid);
            if (!phase)
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: " UI64FMTD " Entry: %u) with `phaseid` %u does not exist, set to 0", guid, data.id, data.phaseid);
                data.phaseid = 0;
            }
        }

        if (data.phaseGroup)
        {
            if (sDB2Manager.GetPhasesForGroup(data.phaseGroup).empty())
            {
                TC_LOG_ERROR("sql.sql", "Table `creature` have creature (GUID: " UI64FMTD " Entry: %u) with `phasegroup` %u does not exist, set to 0", guid, data.id, data.phaseGroup);
                data.phaseGroup = 0;
            }
        }

        if (sWorld->getBoolConfig(CONFIG_CALCULATE_CREATURE_ZONE_AREA_DATA))
        {
            uint32 zoneId = 0;
            uint32 areaId = 0;
            sMapMgr->GetZoneAndAreaId(zoneId, areaId, data.mapid, data.posX, data.posY, data.posZ);

            PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_ZONE_AREA_DATA);

            stmt->setUInt32(0, zoneId);
            stmt->setUInt32(1, areaId);
            stmt->setUInt64(2, guid);

            WorldDatabase.Execute(stmt);
        }

        // Add to grid if not managed by the game event or pool system
        if (gameEvent == 0 && PoolId == 0)
            AddCreatureToGrid(guid, &data);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " creatures in %u ms", _creatureDataStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::AddCreatureToGrid(ObjectGuid::LowType guid, CreatureData const* data)
{
    uint32 mask = data->spawnMask;
    for (uint8 i = 0; mask != 0; i++, mask >>= 1)
    {
        if (mask & 1)
        {
            CellCoord cellCoord = Trinity::ComputeCellCoord(data->posX, data->posY);
            CellObjectGuids& cell_guids = _mapObjectGuidsStore[MAKE_PAIR32(data->mapid, i)][cellCoord.GetId()];
            cell_guids.creatures.insert(guid);
        }
    }
}

void ObjectMgr::RemoveCreatureFromGrid(ObjectGuid::LowType guid, CreatureData const* data)
{
    uint32 mask = data->spawnMask;
    for (uint8 i = 0; mask != 0; i++, mask >>= 1)
    {
        if (mask & 1)
        {
            CellCoord cellCoord = Trinity::ComputeCellCoord(data->posX, data->posY);
            CellObjectGuids& cell_guids = _mapObjectGuidsStore[MAKE_PAIR32(data->mapid, i)][cellCoord.GetId()];
            cell_guids.creatures.erase(guid);
        }
    }
}

ObjectGuid::LowType ObjectMgr::AddGOData(uint32 entry, uint32 mapId, float x, float y, float z, float o, uint32 spawntimedelay, float rotation0, float rotation1, float rotation2, float rotation3)
{
    GameObjectTemplate const* goinfo = GetGameObjectTemplate(entry);
    if (!goinfo)
        return UI64LIT(0);

    Map* map = sMapMgr->CreateBaseMap(mapId);
    if (!map)
        return UI64LIT(0);

    ObjectGuid::LowType guid = GenerateGameObjectSpawnId();
    GameObjectData& data = NewGOData(guid);
    data.id             = entry;
    data.mapid          = mapId;
    data.posX           = x;
    data.posY           = y;
    data.posZ           = z;
    data.orientation    = o;
    data.rotation0      = rotation0;
    data.rotation1      = rotation1;
    data.rotation2      = rotation2;
    data.rotation3      = rotation3;
    data.spawntimesecs  = spawntimedelay;
    data.animprogress   = 100;
    data.spawnMask      = 1;
    data.go_state       = GO_STATE_READY;
    data.phaseMask      = PHASEMASK_NORMAL;
    data.artKit         = goinfo->type == GAMEOBJECT_TYPE_CONTROL_ZONE ? 21 : 0;
    data.dbData = false;

    AddGameobjectToGrid(guid, &data);

    // Spawn if necessary (loaded grids only)
    // We use spawn coords to spawn
    if (!map->Instanceable() && map->IsGridLoaded(x, y))
    {
        GameObject* go = new GameObject;
        if (!go->LoadGameObjectFromDB(guid, map))
        {
            TC_LOG_ERROR("misc", "AddGOData: cannot add gameobject entry %u to map", entry);
            delete go;
            return UI64LIT(0);
        }
    }

    TC_LOG_DEBUG("maps", "AddGOData: dbguid " UI64FMTD " entry %u map %u x %f y %f z %f o %f", guid, entry, mapId, x, y, z, o);

    return guid;
}

ObjectGuid::LowType ObjectMgr::AddCreatureData(uint32 entry, uint32 mapId, float x, float y, float z, float o, uint32 spawntimedelay /*= 0*/)
{
    CreatureTemplate const* cInfo = GetCreatureTemplate(entry);
    if (!cInfo)
        return UI64LIT(0);

    uint32 level = cInfo->minlevel == cInfo->maxlevel ? cInfo->minlevel : urand(cInfo->minlevel, cInfo->maxlevel); // Only used for extracting creature base stats
    CreatureBaseStats const* stats = GetCreatureBaseStats(level, cInfo->unit_class);
    Map* map = sMapMgr->CreateBaseMap(mapId);
    if (!map)
        return UI64LIT(0);

    ObjectGuid::LowType guid = GenerateCreatureSpawnId();
    CreatureData& data = NewOrExistCreatureData(guid);
    data.id = entry;
    data.mapid = mapId;
    data.displayid = 0;
    data.equipmentId = 0;
    data.posX = x;
    data.posY = y;
    data.posZ = z;
    data.orientation = o;
    data.spawntimesecs = spawntimedelay;
    data.spawndist = 0;
    data.currentwaypoint = 0;
    data.curhealth = stats->GenerateHealth(cInfo);
    data.curmana = stats->GenerateMana(cInfo);
    data.movementType = cInfo->MovementType;
    data.spawnMask = 1;
    data.phaseMask = PHASEMASK_NORMAL;
    data.dbData = false;
    data.npcflag = cInfo->npcflag;
    data.unit_flags = cInfo->unit_flags;
    data.dynamicflags = cInfo->dynamicflags;

    AddCreatureToGrid(guid, &data);

    // We use spawn coords to spawn
    if (!map->Instanceable() && !map->IsRemovalGrid(x, y))
    {
        Creature* creature = new Creature();
        if (!creature->LoadCreatureFromDB(guid, map))
        {
            TC_LOG_ERROR("misc", "AddCreature: Cannot add creature entry %u to map", entry);
            delete creature;
            return UI64LIT(0);
        }
    }

    return guid;
}

void ObjectMgr::LoadGameobjects()
{
    uint32 oldMSTime = getMSTime();

    //                                                0                1   2    3           4           5           6
    QueryResult result = WorldDatabase.Query("SELECT gameobject.guid, id, map, position_x, position_y, position_z, orientation, "
    //   7          8          9          10         11             12            13     14         15          16          17       18
        "rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, spawnMask, eventEntry, pool_entry, phaseid, phasegroup "
        "FROM gameobject LEFT OUTER JOIN game_event_gameobject ON gameobject.guid = game_event_gameobject.guid "
        "LEFT OUTER JOIN pool_gameobject ON gameobject.guid = pool_gameobject.guid");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 gameobjects. DB table `gameobject` is empty.");
        return;
    }

    // build single time for check spawnmask
    std::map<uint32, uint32> spawnMasks;
    for (auto& mapDifficultyPair : sMapDifficultyMap)
        for (auto& difficultyPair : mapDifficultyPair.second)
            spawnMasks[mapDifficultyPair.first] |= (1 << difficultyPair.first);

    _gameObjectDataStore.rehash(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType guid = fields[0].GetUInt64();
        uint32 entry        = fields[1].GetUInt32();

        GameObjectTemplate const* gInfo = GetGameObjectTemplate(entry);
        if (!gInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD ") with non existing gameobject entry %u, skipped.", guid, entry);
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
                    TC_LOG_ERROR("sql.sql", "Gameobject (GUID: " UI64FMTD " Entry %u GoType: %u) doesn't have a displayId (%u), not loaded.", guid, entry, gInfo->type, gInfo->displayId);
                    break;
            }
        }

        if (gInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(gInfo->displayId))
        {
            TC_LOG_ERROR("sql.sql", "Gameobject (GUID: " UI64FMTD " Entry %u GoType: %u) has an invalid displayId (%u), not loaded.", guid, entry, gInfo->type, gInfo->displayId);
            continue;
        }

        GameObjectData& data = _gameObjectDataStore[guid];

        data.id             = entry;
        data.mapid          = fields[2].GetUInt16();
        data.posX           = fields[3].GetFloat();
        data.posY           = fields[4].GetFloat();
        data.posZ           = fields[5].GetFloat();
        data.orientation    = fields[6].GetFloat();
        data.rotation0      = fields[7].GetFloat();
        data.rotation1      = fields[8].GetFloat();
        data.rotation2      = fields[9].GetFloat();
        data.rotation3      = fields[10].GetFloat();
        data.spawntimesecs  = fields[11].GetInt32();

        MapEntry const* mapEntry = sMapStore.LookupEntry(data.mapid);
        if (!mapEntry)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) spawned on a non-existed map (Id: %u), skip", guid, data.id, data.mapid);
            continue;
        }

        if (data.spawntimesecs == 0 && gInfo->IsDespawnAtAction())
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) with `spawntimesecs` (0) value, but the gameobejct is marked as despawnable at action.", guid, data.id);
        }

        data.animprogress   = fields[12].GetUInt8();
        data.artKit         = 0;

        uint32 go_state     = fields[13].GetUInt8();
        if (go_state >= MAX_GO_STATE)
        {
            if (gInfo->type != GAMEOBJECT_TYPE_TRANSPORT || go_state > GO_STATE_TRANSPORT_ACTIVE + MAX_GO_STATE_TRANSPORT_STOP_FRAMES)
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) with invalid `state` (%u) value, skip", guid, data.id, go_state);
                continue;
            }
        }
        data.go_state       = GOState(go_state);

        data.spawnMask      = fields[14].GetUInt32();

        if (!IsTransportMap(data.mapid) && data.spawnMask & ~spawnMasks[data.mapid])
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) that has wrong spawn mask %u including unsupported difficulty modes for map (Id: %u), skip", guid, data.id, data.spawnMask, data.mapid);

        int16 gameEvent     = fields[15].GetInt8();
        uint32 PoolId       = fields[16].GetUInt32();
        data.phaseid        = fields[17].GetUInt32();
        data.phaseGroup     = fields[18].GetUInt32();

        if (data.phaseGroup && data.phaseid)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: " UI64FMTD " Entry: %u) with both `phaseid` and `phasegroup` set, `phasegroup` set to 0", guid, data.id);
            data.phaseGroup = 0;
        }

        if (data.phaseid)
        {
            PhaseEntry const* phase = sPhaseStore.LookupEntry(data.phaseid);
            if (!phase)
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: " UI64FMTD " Entry: %u) with `phaseid` %u does not exist, set to 0", guid, data.id, data.phaseid);
                data.phaseid = 0;
            }
        }

        if (data.phaseGroup)
        {
            if (sDB2Manager.GetPhasesForGroup(data.phaseGroup).empty())
            {
                TC_LOG_ERROR("sql.sql", "Table `gameobject` have gameobject (GUID: " UI64FMTD " Entry: %u) with `phaseGroup` %u does not exist, set to 0", guid, data.id, data.phaseGroup);
                data.phaseGroup = 0;
            }
        }

        if (std::abs(data.orientation) > 2 * float(M_PI))
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) with abs(`orientation`) > 2*PI (orientation is expressed in radians), normalized.", guid, data.id);
            data.orientation = Position::NormalizeOrientation(data.orientation);
        }

        if (data.rotation2 < -1.0f || data.rotation2 > 1.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) with invalid rotation2 (%f) value, skip", guid, data.id, data.rotation2);
            continue;
        }

        if (data.rotation3 < -1.0f || data.rotation3 > 1.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) with invalid rotation3 (%f) value, skip", guid, data.id, data.rotation3);
            continue;
        }

        if (!MapManager::IsValidMapCoord(data.mapid, data.posX, data.posY, data.posZ, data.orientation))
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject` has gameobject (GUID: " UI64FMTD " Entry: %u) with invalid coordinates, skip", guid, data.id);
            continue;
        }

        data.phaseMask = 1;

        if (sWorld->getBoolConfig(CONFIG_CALCULATE_GAMEOBJECT_ZONE_AREA_DATA))
        {
            uint32 zoneId = 0;
            uint32 areaId = 0;
            sMapMgr->GetZoneAndAreaId(zoneId, areaId, data.mapid, data.posX, data.posY, data.posZ);

            PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_GAMEOBJECT_ZONE_AREA_DATA);

            stmt->setUInt32(0, zoneId);
            stmt->setUInt32(1, areaId);
            stmt->setUInt64(2, guid);

            WorldDatabase.Execute(stmt);
        }

        if (gameEvent == 0 && PoolId == 0)                      // if not this is to be managed by GameEvent System or Pool system
            AddGameobjectToGrid(guid, &data);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " gameobjects in %u ms", _gameObjectDataStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::AddGameobjectToGrid(ObjectGuid::LowType guid, GameObjectData const* data)
{
    uint32 mask = data->spawnMask;
    for (uint8 i = 0; mask != 0; i++, mask >>= 1)
    {
        if (mask & 1)
        {
            CellCoord cellCoord = Trinity::ComputeCellCoord(data->posX, data->posY);
            CellObjectGuids& cell_guids = _mapObjectGuidsStore[MAKE_PAIR32(data->mapid, i)][cellCoord.GetId()];
            cell_guids.gameobjects.insert(guid);
        }
    }
}

void ObjectMgr::RemoveGameobjectFromGrid(ObjectGuid::LowType guid, GameObjectData const* data)
{
    uint32 mask = data->spawnMask;
    for (uint8 i = 0; mask != 0; i++, mask >>= 1)
    {
        if (mask & 1)
        {
            CellCoord cellCoord = Trinity::ComputeCellCoord(data->posX, data->posY);
            CellObjectGuids& cell_guids = _mapObjectGuidsStore[MAKE_PAIR32(data->mapid, i)][cellCoord.GetId()];
            cell_guids.gameobjects.erase(guid);
        }
    }
}

Player* ObjectMgr::GetPlayerByLowGUID(ObjectGuid::LowType lowguid) const
{
    return ObjectAccessor::FindPlayer(ObjectGuid::Create<HighGuid::Player>(lowguid));
}

// name must be checked to correctness (if received) before call this function
ObjectGuid ObjectMgr::GetPlayerGUIDByName(std::string const& name)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUID_BY_NAME);
    stmt->setString(0, name);

    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        return ObjectGuid::Create<HighGuid::Player>((*result)[0].GetUInt64());

    return ObjectGuid::Empty;
}

bool ObjectMgr::GetPlayerNameByGUID(ObjectGuid const& guid, std::string& name)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
    {
        name = player->GetName();
        return true;
    }

    if (CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(guid))
    {
        name = characterInfo->Name;
        return true;
    }

    return false;
}

bool ObjectMgr::GetPlayerNameAndClassByGUID(ObjectGuid const& guid, std::string& name, uint8& _class)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
    {
        name = player->GetName();
        _class = player->getClass();
        return true;
    }

    if (CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(guid))
    {
        name = characterInfo->Name;
        _class = characterInfo->Class;
        return true;
    }

    return false;
}

uint32 ObjectMgr::GetPlayerTeamByGUID(ObjectGuid const& guid)
{
    if (CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(guid))
        return Player::TeamForRace(characterInfo->Race);

    return 0;
}

uint32 ObjectMgr::GetPlayerAccountIdByGUID(ObjectGuid const& guid)
{
    if (CharacterInfo const* characterInfo = sWorld->GetCharacterInfo(guid))
        return characterInfo->AccountId;

    return 0;
}

uint32 ObjectMgr::GetPlayerAccountIdByPlayerName(std::string const& name)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_BY_NAME);
    stmt->setString(0, name);

    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        return (*result)[0].GetUInt32();

    return 0;
}

uint32 FillMaxDurability(uint32 itemClass, uint32 itemSubClass, uint32 inventoryType, uint32 quality, uint32 itemLevel)
{
    if (itemClass != ITEM_CLASS_ARMOR && itemClass != ITEM_CLASS_WEAPON)
        return 0;

    static float const qualityMultipliers[MAX_ITEM_QUALITY] =
    {
        1.0f, 1.0f, 1.0f, 1.17f, 1.37f, 1.68f, 0.0f, 0.0f
    };

    static float const armorMultipliers[MAX_INVTYPE] =
    {
        0.00f, // INVTYPE_NON_EQUIP
        0.59f, // INVTYPE_HEAD
        0.00f, // INVTYPE_NECK
        0.59f, // INVTYPE_SHOULDERS
        0.00f, // INVTYPE_BODY
        1.00f, // INVTYPE_CHEST
        0.35f, // INVTYPE_WAIST
        0.75f, // INVTYPE_LEGS
        0.49f, // INVTYPE_FEET
        0.35f, // INVTYPE_WRISTS
        0.35f, // INVTYPE_HANDS
        0.00f, // INVTYPE_FINGER
        0.00f, // INVTYPE_TRINKET
        0.00f, // INVTYPE_WEAPON
        1.00f, // INVTYPE_SHIELD
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
    };

    static float const weaponMultipliers[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        0.89f, // ITEM_SUBCLASS_WEAPON_AXE
        1.03f, // ITEM_SUBCLASS_WEAPON_AXE2
        0.77f, // ITEM_SUBCLASS_WEAPON_BOW
        0.77f, // ITEM_SUBCLASS_WEAPON_GUN
        0.89f, // ITEM_SUBCLASS_WEAPON_MACE
        1.03f, // ITEM_SUBCLASS_WEAPON_MACE2
        1.03f, // ITEM_SUBCLASS_WEAPON_POLEARM
        0.89f, // ITEM_SUBCLASS_WEAPON_SWORD
        1.03f, // ITEM_SUBCLASS_WEAPON_SWORD2
        0.00f, // ITEM_SUBCLASS_WEAPON_Obsolete
        1.03f, // ITEM_SUBCLASS_WEAPON_STAFF
        0.00f, // ITEM_SUBCLASS_WEAPON_EXOTIC
        0.00f, // ITEM_SUBCLASS_WEAPON_EXOTIC2
        0.64f, // ITEM_SUBCLASS_WEAPON_FIST_WEAPON
        0.00f, // ITEM_SUBCLASS_WEAPON_MISCELLANEOUS
        0.64f, // ITEM_SUBCLASS_WEAPON_DAGGER
        0.64f, // ITEM_SUBCLASS_WEAPON_THROWN
        0.00f, // ITEM_SUBCLASS_WEAPON_SPEAR
        0.77f, // ITEM_SUBCLASS_WEAPON_CROSSBOW
        0.64f, // ITEM_SUBCLASS_WEAPON_WAND
        0.64f, // ITEM_SUBCLASS_WEAPON_FISHING_POLE
    };

    float levelPenalty = 1.0f;
    if (itemLevel <= 28)
        levelPenalty = 0.966f - float(28u - itemLevel) / 54.0f;

    if (itemClass == ITEM_CLASS_ARMOR)
    {
        if (inventoryType > INVTYPE_ROBE)
            return 0;

        return 5 * uint32(23.0f * qualityMultipliers[quality] * armorMultipliers[inventoryType] * levelPenalty + 0.5f);
    }

    return 5 * uint32(17.0f * qualityMultipliers[quality] * weaponMultipliers[itemSubClass] * levelPenalty + 0.5f);
};

void FillDisenchantFields(uint32* disenchantID, uint32* requiredDisenchantSkill, ItemTemplate const& itemTemplate)
{
    *disenchantID = 0;
    *(int32*)requiredDisenchantSkill = -1;
    if ((itemTemplate.GetFlags() & (ITEM_FLAG_CONJURED | ITEM_FLAG_UNK6)) ||
        itemTemplate.GetBonding() == BIND_QUEST_ITEM || itemTemplate.GetArea() || itemTemplate.GetMap() ||
        itemTemplate.GetMaxStackSize() > 1 ||
        itemTemplate.GetQuality() < ITEM_QUALITY_UNCOMMON || itemTemplate.GetQuality() > ITEM_QUALITY_EPIC ||
        !(itemTemplate.GetClass() == ITEM_CLASS_ARMOR || itemTemplate.GetClass() == ITEM_CLASS_WEAPON) ||
        !(Item::GetSpecialPrice(&itemTemplate) || sItemCurrencyCostStore.LookupEntry(itemTemplate.GetId())))
        return;

    for (uint32 i = 0; i < sItemDisenchantLootStore.GetNumRows(); ++i)
    {
        ItemDisenchantLootEntry const* disenchant = sItemDisenchantLootStore.LookupEntry(i);
        if (!disenchant)
            continue;

        if (disenchant->ItemClass == itemTemplate.GetClass() &&
            disenchant->ItemQuality == itemTemplate.GetQuality() &&
            disenchant->MinItemLevel <= itemTemplate.GetBaseItemLevel() &&
            disenchant->MaxItemLevel >= itemTemplate.GetBaseItemLevel())
        {
            if (disenchant->ID == 60 || disenchant->ID == 61)   // epic item disenchant ilvl range 66-99 (classic)
            {
                if (itemTemplate.GetBaseRequiredLevel() > 60 || itemTemplate.GetRequiredSkillRank() > 300)
                    continue;                                   // skip to epic item disenchant ilvl range 90-199 (TBC)
            }
            else if (disenchant->ID == 66 || disenchant->ID == 67)  // epic item disenchant ilvl range 90-199 (TBC)
            {
                if (itemTemplate.GetBaseRequiredLevel() <= 60 || (itemTemplate.GetRequiredSkill() && itemTemplate.GetRequiredSkillRank() <= 300))
                    continue;
            }

            *disenchantID = disenchant->ID;
            *requiredDisenchantSkill = disenchant->RequiredDisenchantSkill;
            return;
        }
    }
}

struct ItemSpecStats
{
    uint32 ItemType;
    uint32 ItemSpecStatTypes[MAX_ITEM_PROTO_STATS];
    uint32 ItemSpecStatCount;

    ItemSpecStats(ItemEntry const* item, ItemSparseEntry const* sparse) : ItemType(0), ItemSpecStatCount(0)
    {
        memset(ItemSpecStatTypes, -1, sizeof(ItemSpecStatTypes));

        if (item->Class == ITEM_CLASS_WEAPON)
        {
            ItemType = 5;
            switch (item->SubClass)
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
        else if (item->Class == ITEM_CLASS_ARMOR && item->SubClass > 5 && item->SubClass <= 11)
        {
            switch (item->SubClass)
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
                    ItemType = 6;
                    if (item->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
                        AddStat(ITEM_SPEC_STAT_SHIELD);
                    else if (item->SubClass > ITEM_SUBCLASS_ARMOR_SHIELD && item->SubClass <= ITEM_SUBCLASS_ARMOR_RELIC)
                        AddStat(ITEM_SPEC_STAT_RELIC);
                    break;
            }
        }
        else
            ItemType = 0;

        for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
            if (sparse->ItemStatType[i] != -1)
                AddModStat(sparse->ItemStatType[i]);
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
            case ITEM_MOD_SPIRIT:
                AddStat(ITEM_SPEC_STAT_SPIRIT);
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
            case ITEM_MOD_HASTE_MELEE_RATING:
            case ITEM_MOD_HASTE_RANGED_RATING:
            case ITEM_MOD_HASTE_SPELL_RATING:
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
    uint32 sparseCount = 0;

    for (ItemSparseEntry const* sparse : sItemSparseStore)
    {
        ItemEntry const* db2Data = sItemStore.LookupEntry(sparse->ID);
        if (!db2Data)
            continue;

        ItemTemplate& itemTemplate = _itemTemplateStore[sparse->ID];

        itemTemplate.BasicData = db2Data;
        itemTemplate.ExtendedData = sparse;

        itemTemplate.MaxDurability = FillMaxDurability(db2Data->Class, db2Data->SubClass, sparse->InventoryType, sparse->Quality, sparse->ItemLevel);
        itemTemplate.ScriptId = 0;
        FillDisenchantFields(&itemTemplate.DisenchantID, &itemTemplate.RequiredDisenchantSkill, itemTemplate);
        itemTemplate.FoodType = 0;
        itemTemplate.MinMoneyLoot = 0;
        itemTemplate.MaxMoneyLoot = 0;
        itemTemplate.FlagsCu = 0;
        itemTemplate.SpellPPMRate = 0.0f;

        if (std::vector<ItemSpecOverrideEntry const*> const* itemSpecOverrides = sDB2Manager.GetItemSpecOverrides(sparse->ID))
        {
            for (ItemSpecOverrideEntry const* itemSpecOverride : *itemSpecOverrides)
                itemTemplate.Specializations[0].insert(itemSpecOverride->SpecID);

            itemTemplate.Specializations[1] = itemTemplate.Specializations[0];
        }
        else
        {
            ItemSpecStats itemSpecStats(db2Data, sparse);

            if (itemSpecStats.ItemSpecStatCount)
            {
                for (ItemSpecEntry const* itemSpec : sItemSpecStore)
                {
                    if (itemSpecStats.ItemType != itemSpec->ItemType)
                        continue;

                    bool hasPrimary = false;
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

                    if (ChrSpecializationEntry const* specialization = sChrSpecializationStore.LookupEntry(itemSpec->SpecID))
                        if ((1 << (specialization->ClassID - 1)) & sparse->AllowableClass)
                            itemTemplate.Specializations[itemSpec->MaxLevel > 40].insert(itemSpec->SpecID);
                }
            }
        }

        ++sparseCount;
    }

    // Load item effects (spells)
    for (ItemEffectEntry const* effectEntry : sItemEffectStore)
    {
        auto itemItr = _itemTemplateStore.find(effectEntry->ItemID);
        if (itemItr == _itemTemplateStore.end())
            continue;

        itemItr->second.Effects.push_back(effectEntry);
    }

    // Check if item templates for DBC referenced character start outfit are present
    std::set<uint32> notFoundOutfit;
    for (CharStartOutfitEntry const* entry : sCharStartOutfitStore)
    {
        for (int j = 0; j < MAX_OUTFIT_ITEMS; ++j)
        {
            if (entry->ItemID[j] <= 0)
                continue;

            uint32 item_id = entry->ItemID[j];

            if (!GetItemTemplate(item_id))
                notFoundOutfit.insert(item_id);
        }
    }

    for (std::set<uint32>::const_iterator itr = notFoundOutfit.begin(); itr != notFoundOutfit.end(); ++itr)
        TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not exist in `item_template` but is referenced in `CharStartOutfit.dbc`", *itr);

    TC_LOG_INFO("server.loading", ">> Loaded %u item templates in %u ms", sparseCount, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadItemTemplateAddon()
{
    uint32 oldMSTime = getMSTime();
    uint32 count = 0;

    QueryResult result = WorldDatabase.Query("SELECT Id, FlagsCu, FoodType, MinMoneyLoot, MaxMoneyLoot, SpellPPMChance FROM item_template_addon");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 itemId = fields[0].GetUInt32();
            if (!GetItemTemplate(itemId))
            {
                TC_LOG_ERROR("sql.sql", "Item %u specified in `item_template_addon` does not exist, skipped.", itemId);
                continue;
            }

            uint32 minMoneyLoot = fields[3].GetUInt32();
            uint32 maxMoneyLoot = fields[4].GetUInt32();
            if (minMoneyLoot > maxMoneyLoot)
            {
                TC_LOG_ERROR("sql.sql", "Minimum money loot specified in `item_template_addon` for item %u was greater than maximum amount, swapping.", itemId);
                std::swap(minMoneyLoot, maxMoneyLoot);
            }
            ItemTemplate& itemTemplate = _itemTemplateStore[itemId];
            itemTemplate.FlagsCu = fields[1].GetUInt32();
            itemTemplate.FoodType = fields[2].GetUInt8();
            itemTemplate.MinMoneyLoot = minMoneyLoot;
            itemTemplate.MaxMoneyLoot = maxMoneyLoot;
            itemTemplate.SpellPPMRate = fields[5].GetFloat();
            ++count;
        } while (result->NextRow());
    }
    TC_LOG_INFO("server.loading", ">> Loaded %u item addon templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            if (!GetItemTemplate(itemId))
            {
                TC_LOG_ERROR("sql.sql", "Item %u specified in `item_script_names` does not exist, skipped.", itemId);
                continue;
            }

            _itemTemplateStore[itemId].ScriptId = GetScriptId(fields[1].GetString());
            ++count;
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u item script names in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}
ItemTemplate const* ObjectMgr::GetItemTemplate(uint32 entry)
{
    ItemTemplateContainer::const_iterator itr = _itemTemplateStore.find(entry);
    if (itr != _itemTemplateStore.end())
        return &(itr->second);
    return NULL;
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
        TC_LOG_ERROR("server.loading", ">> Loaded 0 vehicle template accessories. DB table `vehicle_template_accessory` is empty.");
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

        if (!sObjectMgr->GetCreatureTemplate(entry))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template_accessory`: creature template entry %u does not exist.", entry);
            continue;
        }

        if (!sObjectMgr->GetCreatureTemplate(accessory))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template_accessory`: Accessory %u does not exist.", accessory);
            continue;
        }

        if (_spellClickInfoStore.find(entry) == _spellClickInfoStore.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_template_accessory`: creature template entry %u has no data in npc_spellclick_spells", entry);
            continue;
        }

        _vehicleTemplateAccessoryStore[entry].push_back(VehicleAccessory(accessory, seatId, isMinion, summonType, summonTimer));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Vehicle Template Accessories in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
        TC_LOG_INFO("server.loading", ">> Loaded 0 Vehicle Accessories in %u ms", GetMSTimeDiffToNow(oldMSTime));
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

        if (!sObjectMgr->GetCreatureTemplate(uiAccessory))
        {
            TC_LOG_ERROR("sql.sql", "Table `vehicle_accessory`: Accessory %u does not exist.", uiAccessory);
            continue;
        }

        _vehicleAccessoryStore[uiGUID].push_back(VehicleAccessory(uiAccessory, uiSeat, bMinion, uiSummonType, uiSummonTimer));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Vehicle Accessories in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPetLevelInfo()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0               1      2   3     4    5    6    7     8    9
    QueryResult result = WorldDatabase.Query("SELECT creature_entry, level, hp, mana, str, agi, sta, inte, spi, armor FROM pet_levelstats");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 level pet stats definitions. DB table `pet_levelstats` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 creature_id = fields[0].GetUInt32();
        if (!sObjectMgr->GetCreatureTemplate(creature_id))
        {
            TC_LOG_ERROR("sql.sql", "Wrong creature id %u in `pet_levelstats` table, ignoring.", creature_id);
            continue;
        }

        uint32 current_level = fields[1].GetUInt8();
        if (current_level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            if (current_level > STRONG_MAX_LEVEL)        // hardcoded level maximum
                TC_LOG_ERROR("sql.sql", "Wrong (> %u) level %u in `pet_levelstats` table, ignoring.", STRONG_MAX_LEVEL, current_level);
            else
            {
                TC_LOG_INFO("misc", "Unused (> MaxPlayerLevel in worldserver.conf) level %u in `pet_levelstats` table, ignoring.", current_level);
                ++count;                                // make result loading percent "expected" correct in case disabled detail mode for example.
            }
            continue;
        }
        else if (current_level < 1)
        {
            TC_LOG_ERROR("sql.sql", "Wrong (<1) level %u in `pet_levelstats` table, ignoring.", current_level);
            continue;
        }

        PetLevelInfo*& pInfoMapEntry = _petInfoStore[creature_id];

        if (pInfoMapEntry == NULL)
            pInfoMapEntry = new PetLevelInfo[sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)];

        // data for level 1 stored in [0] array element, ...
        PetLevelInfo* pLevelInfo = &pInfoMapEntry[current_level-1];

        pLevelInfo->health = fields[2].GetUInt16();
        pLevelInfo->mana   = fields[3].GetUInt16();
        pLevelInfo->armor  = fields[9].GetUInt32();

        for (int i = 0; i < MAX_STATS; i++)
        {
            pLevelInfo->stats[i] = fields[i+4].GetUInt16();
        }

        ++count;
    }
    while (result->NextRow());

    // Fill gaps and check integrity
    for (PetLevelInfoContainer::iterator itr = _petInfoStore.begin(); itr != _petInfoStore.end(); ++itr)
    {
        PetLevelInfo* pInfo = itr->second;

        // fatal error if no level 1 data
        if (!pInfo || pInfo[0].health == 0)
        {
            TC_LOG_ERROR("sql.sql", "Creature %u does not have pet stats data for Level 1!", itr->first);
            exit(1);
        }

        // fill level gaps
        for (uint8 level = 1; level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL); ++level)
        {
            if (pInfo[level].health == 0)
            {
                TC_LOG_ERROR("sql.sql", "Creature %u has no data for Level %i pet stats data, using data of Level %i.", itr->first, level + 1, level);
                pInfo[level] = pInfo[level - 1];
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u level pet stats definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

PetLevelInfo const* ObjectMgr::GetPetLevelInfo(uint32 creature_id, uint8 level) const
{
    if (level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        level = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);

    PetLevelInfoContainer::const_iterator itr = _petInfoStore.find(creature_id);
    if (itr == _petInfoStore.end())
        return NULL;

    return &itr->second[level-1];                           // data for level 1 stored in [0] array element, ...
}

void ObjectMgr::PlayerCreateInfoAddItemHelper(uint32 race_, uint32 class_, uint32 itemId, int32 count)
{
    if (!_playerInfo[race_][class_])
        return;

    if (count > 0)
        _playerInfo[race_][class_]->item.push_back(PlayerCreateInfoItem(itemId, count));
    else
    {
        if (count < -1)
            TC_LOG_ERROR("sql.sql", "Invalid count %i specified on item %u be removed from original player create info (use -1)!", count, itemId);

        for (uint32 gender = 0; gender < GENDER_NONE; ++gender)
        {
            if (CharStartOutfitEntry const* entry = sDB2Manager.GetCharStartOutfitEntry(race_, class_, gender))
            {
                bool found = false;
                for (uint8 x = 0; x < MAX_OUTFIT_ITEMS; ++x)
                {
                    if (entry->ItemID[x] > 0 && uint32(entry->ItemID[x]) == itemId)
                    {
                        found = true;
                        const_cast<CharStartOutfitEntry*>(entry)->ItemID[x] = 0;
                        break;
                    }
                }

                if (!found)
                    TC_LOG_ERROR("sql.sql", "Item %u specified to be removed from original create info not found in dbc!", itemId);
            }
        }
    }
}

void ObjectMgr::LoadPlayerInfo()
{
    // Load playercreate
    {
        uint32 oldMSTime = getMSTime();
        //                                                0     1      2    3        4          5           6
        QueryResult result = WorldDatabase.Query("SELECT race, class, map, zone, position_x, position_y, position_z, orientation FROM playercreateinfo");

        if (!result)
        {
            TC_LOG_ERROR("server.loading", ">> Loaded 0 player create definitions. DB table `playercreateinfo` is empty.");
            exit(1);
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
                uint32 areaId        = fields[3].GetUInt32(); // zone
                float  positionX     = fields[4].GetFloat();
                float  positionY     = fields[5].GetFloat();
                float  positionZ     = fields[6].GetFloat();
                float  orientation   = fields[7].GetFloat();

                if (current_race >= MAX_RACES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race %u in `playercreateinfo` table, ignoring.", current_race);
                    continue;
                }

                ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(current_race);
                if (!rEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race %u in `playercreateinfo` table, ignoring.", current_race);
                    continue;
                }

                if (current_class >= MAX_CLASSES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class %u in `playercreateinfo` table, ignoring.", current_class);
                    continue;
                }

                if (!sChrClassesStore.LookupEntry(current_class))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class %u in `playercreateinfo` table, ignoring.", current_class);
                    continue;
                }

                // accept DB data only for valid position (and non instanceable)
                if (!MapManager::IsValidMapCoord(mapId, positionX, positionY, positionZ, orientation))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong home position for class %u race %u pair in `playercreateinfo` table, ignoring.", current_class, current_race);
                    continue;
                }

                if (sMapStore.LookupEntry(mapId)->Instanceable())
                {
                    TC_LOG_ERROR("sql.sql", "Home position in instanceable map for class %u race %u pair in `playercreateinfo` table, ignoring.", current_class, current_race);
                    continue;
                }

                PlayerInfo* info = new PlayerInfo();
                info->mapId = mapId;
                info->areaId = areaId;
                info->positionX = positionX;
                info->positionY = positionY;
                info->positionZ = positionZ;
                info->orientation = orientation;
                info->displayId_m = rEntry->MaleDisplayID;
                info->displayId_f = rEntry->FemaleDisplayID;
                _playerInfo[current_race][current_class] = info;

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u player create definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate items
    TC_LOG_INFO("server.loading", "Loading Player Create Items Data...");
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
                    TC_LOG_ERROR("sql.sql", "Wrong race %u in `playercreateinfo_item` table, ignoring.", current_race);
                    continue;
                }

                uint32 current_class = fields[1].GetUInt8();
                if (current_class >= MAX_CLASSES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class %u in `playercreateinfo_item` table, ignoring.", current_class);
                    continue;
                }

                uint32 item_id = fields[2].GetUInt32();

                if (!GetItemTemplate(item_id))
                {
                    TC_LOG_ERROR("sql.sql", "Item id %u (race %u class %u) in `playercreateinfo_item` table but not listed in `item_template`, ignoring.", item_id, current_race, current_class);
                    continue;
                }

                int32 amount   = fields[3].GetInt8();

                if (!amount)
                {
                    TC_LOG_ERROR("sql.sql", "Item id %u (class %u race %u) have amount == 0 in `playercreateinfo_item` table, ignoring.", item_id, current_race, current_class);
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

            TC_LOG_INFO("server.loading", ">> Loaded %u custom player create items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate skills
    TC_LOG_INFO("server.loading", "Loading Player Create Skill Data...");
    {
        uint32 oldMSTime = getMSTime();

        for (SkillRaceClassInfoEntry const* rcInfo : sSkillRaceClassInfoStore)
            if (rcInfo->Availability == 1)
                for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
                    if (rcInfo->RaceMask == -1 || ((1 << (raceIndex - 1)) & rcInfo->RaceMask))
                        for (uint32 classIndex = CLASS_WARRIOR; classIndex < MAX_CLASSES; ++classIndex)
                            if (rcInfo->ClassMask == -1 || ((1 << (classIndex - 1)) & rcInfo->ClassMask))
                                if (PlayerInfo* info = _playerInfo[raceIndex][classIndex])
                                    info->skills.push_back(rcInfo);

        TC_LOG_INFO("server.loading", ">> Loaded player create skills in %u ms", GetMSTimeDiffToNow(oldMSTime));
    }

    // Load playercreate custom spells
    TC_LOG_INFO("server.loading", "Loading Player Create Custom Spell Data...");
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.PQuery("SELECT racemask, classmask, Spell FROM playercreateinfo_spell_custom");

        if (!result)
        {
            TC_LOG_ERROR("server.loading", ">> Loaded 0 player create custom spells. DB table `playercreateinfo_spell_custom` is empty.");
        }
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields = result->Fetch();
                uint32 raceMask = fields[0].GetUInt32();
                uint32 classMask = fields[1].GetUInt32();
                uint32 spellId = fields[2].GetUInt32();

                if (raceMask != 0 && !(raceMask & RACEMASK_ALL_PLAYABLE))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race mask %u in `playercreateinfo_spell_custom` table, ignoring.", raceMask);
                    continue;
                }

                if (classMask != 0 && !(classMask & CLASSMASK_ALL_PLAYABLE))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class mask %u in `playercreateinfo_spell_custom` table, ignoring.", classMask);
                    continue;
                }

                for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
                {
                    if (raceMask == 0 || ((1 << (raceIndex - 1)) & raceMask))
                    {
                        for (uint32 classIndex = CLASS_WARRIOR; classIndex < MAX_CLASSES; ++classIndex)
                        {
                            if (classMask == 0 || ((1 << (classIndex - 1)) & classMask))
                            {
                                if (PlayerInfo* info = _playerInfo[raceIndex][classIndex])
                                {
                                    info->customSpells.push_back(spellId);
                                    ++count;
                                }
                                // We need something better here, the check is not accounting for spells used by multiple races/classes but not all of them.
                                // Either split the masks per class, or per race, which kind of kills the point yet.
                                // else if (raceMask != 0 && classMask != 0)
                                //     TC_LOG_ERROR("sql.sql", "Racemask/classmask (%u/%u) combination was found containing an invalid race/class combination (%u/%u) in `%s` (Spell %u), ignoring.", raceMask, classMask, raceIndex, classIndex, tableName.c_str(), spellId);
                            }
                        }
                    }
                }
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u custom player create spells in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Load playercreate cast spell
    TC_LOG_INFO("server.loading", "Loading Player Create Cast Spell Data...");
    {
        uint32 oldMSTime = getMSTime();

        QueryResult result = WorldDatabase.PQuery("SELECT raceMask, classMask, spell FROM playercreateinfo_cast_spell");

        if (!result)
            TC_LOG_ERROR("server.loading", ">> Loaded 0 player create cast spells. DB table `playercreateinfo_cast_spell` is empty.");
        else
        {
            uint32 count = 0;

            do
            {
                Field* fields       = result->Fetch();
                uint32 raceMask     = fields[0].GetUInt32();
                uint32 classMask    = fields[1].GetUInt32();
                uint32 spellId      = fields[2].GetUInt32();

                if (raceMask != 0 && !(raceMask & RACEMASK_ALL_PLAYABLE))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong race mask %u in `playercreateinfo_cast_spell` table, ignoring.", raceMask);
                    continue;
                }

                if (classMask != 0 && !(classMask & CLASSMASK_ALL_PLAYABLE))
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class mask %u in `playercreateinfo_cast_spell` table, ignoring.", classMask);
                    continue;
                }

                for (uint32 raceIndex = RACE_HUMAN; raceIndex < MAX_RACES; ++raceIndex)
                {
                    if (raceMask == 0 || ((1 << (raceIndex - 1)) & raceMask))
                    {
                        for (uint32 classIndex = CLASS_WARRIOR; classIndex < MAX_CLASSES; ++classIndex)
                        {
                            if (classMask == 0 || ((1 << (classIndex - 1)) & classMask))
                            {
                                if (PlayerInfo* info = _playerInfo[raceIndex][classIndex])
                                {
                                    info->castSpells.push_back(spellId);
                                    ++count;
                                }
                            }
                        }
                    }
                }
            } while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u player create cast spells in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("server.loading", ">> Loaded 0 player create actions. DB table `playercreateinfo_action` is empty.");
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
                    TC_LOG_ERROR("sql.sql", "Wrong race %u in `playercreateinfo_action` table, ignoring.", current_race);
                    continue;
                }

                uint32 current_class = fields[1].GetUInt8();
                if (current_class >= MAX_CLASSES)
                {
                    TC_LOG_ERROR("sql.sql", "Wrong class %u in `playercreateinfo_action` table, ignoring.", current_class);
                    continue;
                }

                if (PlayerInfo* info = _playerInfo[current_race][current_class])
                    info->action.push_back(PlayerCreateInfoAction(fields[2].GetUInt16(), fields[3].GetUInt32(), fields[4].GetUInt16()));

                ++count;
            }
            while (result->NextRow());

            TC_LOG_INFO("server.loading", ">> Loaded %u player create actions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
        }
    }

    // Loading levels data (class/race dependent)
    TC_LOG_INFO("server.loading", "Loading Player Create Level Stats Data...");
    {
        uint32 oldMSTime = getMSTime();

        //                                                 0     1      2      3    4    5    6    7
        QueryResult result  = WorldDatabase.Query("SELECT race, class, level, str, agi, sta, inte, spi FROM player_levelstats");

        if (!result)
        {
            TC_LOG_ERROR("server.loading", ">> Loaded 0 level stats definitions. DB table `player_levelstats` is empty.");
            exit(1);
        }

        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            uint32 current_race = fields[0].GetUInt8();
            if (current_race >= MAX_RACES)
            {
                TC_LOG_ERROR("sql.sql", "Wrong race %u in `player_levelstats` table, ignoring.", current_race);
                continue;
            }

            uint32 current_class = fields[1].GetUInt8();
            if (current_class >= MAX_CLASSES)
            {
                TC_LOG_ERROR("sql.sql", "Wrong class %u in `player_levelstats` table, ignoring.", current_class);
                continue;
            }

            uint32 current_level = fields[2].GetUInt8();
            if (current_level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
            {
                if (current_level > STRONG_MAX_LEVEL)        // hardcoded level maximum
                    TC_LOG_ERROR("sql.sql", "Wrong (> %u) level %u in `player_levelstats` table, ignoring.", STRONG_MAX_LEVEL, current_level);
                else
                {
                    TC_LOG_INFO("misc", "Unused (> MaxPlayerLevel in worldserver.conf) level %u in `player_levelstats` table, ignoring.", current_level);
                    ++count;                                // make result loading percent "expected" correct in case disabled detail mode for example.
                }
                continue;
            }

            if (PlayerInfo* info = _playerInfo[current_race][current_class])
            {
                if (!info->levelInfo)
                    info->levelInfo = new PlayerLevelInfo[sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)];

                PlayerLevelInfo& levelInfo = info->levelInfo[current_level - 1];
                for (int i = 0; i < MAX_STATS; i++)
                    levelInfo.stats[i] = fields[i + 3].GetUInt16();
            }

            ++count;
        }
        while (result->NextRow());

        // Fill gaps and check integrity
        for (int race = 0; race < MAX_RACES; ++race)
        {
            // skip non existed races
            if (!sChrRacesStore.LookupEntry(race))
                continue;

            for (int class_ = 0; class_ < MAX_CLASSES; ++class_)
            {
                // skip non existed classes
                if (!sChrClassesStore.LookupEntry(class_))
                    continue;

                PlayerInfo* info = _playerInfo[race][class_];
                if (!info)
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

                // fatal error if no level 1 data
                if (!info->levelInfo || info->levelInfo[0].stats[0] == 0)
                {
                    TC_LOG_ERROR("sql.sql", "Race %i Class %i Level 1 does not have stats data!", race, class_);
                    exit(1);
                }

                // fill level gaps
                for (uint8 level = 1; level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL); ++level)
                {
                    if (info->levelInfo[level].stats[0] == 0)
                    {
                        TC_LOG_ERROR("sql.sql", "Race %i Class %i Level %i does not have stats data. Using stats data of level %i.", race, class_, level + 1, level);
                        info->levelInfo[level] = info->levelInfo[level - 1];
                    }
                }
            }
        }

        TC_LOG_INFO("server.loading", ">> Loaded %u level stats definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }

    // Loading xp per level data
    TC_LOG_INFO("server.loading", "Loading Player Create XP Data...");
    {
        uint32 oldMSTime = getMSTime();

        _playerXPperLevel.resize(sGtOCTLevelExperienceStore.GetTableRowCount() + 1, 0);

        //                                               0      1
        QueryResult result = WorldDatabase.Query("SELECT Level, Experience FROM player_xp_for_level");

        // load the DBC's levels at first...
        GtOCTLevelExperienceEntry const* exp;
        for (uint32 level = 0; level < sGtOCTLevelExperienceStore.GetTableRowCount(); ++level)
        {
            exp = sGtOCTLevelExperienceStore.EvaluateTable(level, 0);
            _playerXPperLevel[level + 1] = exp->Data;
        }

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
                        TC_LOG_ERROR("sql.sql", "Wrong (> %u) level %u in `player_xp_for_level` table, ignoring.", STRONG_MAX_LEVEL, current_level);
                    else
                    {
                        TC_LOG_INFO("misc", "Unused (> MaxPlayerLevel in worldserver.conf) level %u in `player_xp_for_level` table, ignoring.", current_level);
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
                TC_LOG_ERROR("sql.sql", "Level %i does not have XP for level data. Using data of level [%i] + 12000.", level + 1, level);
                _playerXPperLevel[level] = _playerXPperLevel[level - 1] + 12000;
            }
        }

        TC_LOG_INFO("server.loading", ">> Loaded %u xp for level definition(s) from database in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
}

void ObjectMgr::GetPlayerClassLevelInfo(uint32 class_, uint8 level, uint32& baseHP, uint32& baseMana) const
{
    if (level < 1 || class_ >= MAX_CLASSES)
        return;

    if (level > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        level = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);

    GtOCTBaseHPByClassEntry const* hp = sGtOCTBaseHPByClassStore.EvaluateTable(level - 1, class_ - 1);
    GtOCTBaseMPByClassEntry const* mp = sGtOCTBaseMPByClassStore.EvaluateTable(level - 1, class_ - 1);

    if (!hp || !mp)
    {
        TC_LOG_ERROR("misc", "Tried to get non-existant Class-Level combination data for base hp/mp. Class %u Level %u", class_, level);
        return;
    }

    baseHP = uint32(hp->ratio);
    baseMana = uint32(mp->ratio);
}

void ObjectMgr::GetPlayerLevelInfo(uint32 race, uint32 class_, uint8 level, PlayerLevelInfo* info) const
{
    if (level < 1 || race >= MAX_RACES || class_ >= MAX_CLASSES)
        return;

    PlayerInfo const* pInfo = _playerInfo[race][class_];
    if (!pInfo)
        return;

    if (level <= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        *info = pInfo->levelInfo[level-1];
    else
        BuildPlayerLevelInfo(race, class_, level, info);
}

void ObjectMgr::BuildPlayerLevelInfo(uint8 race, uint8 _class, uint8 level, PlayerLevelInfo* info) const
{
    // base data (last known level)
    *info = _playerInfo[race][_class]->levelInfo[sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)-1];

    // if conversion from uint32 to uint8 causes unexpected behaviour, change lvl to uint32
    for (uint8 lvl = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)-1; lvl < level; ++lvl)
    {
        switch (_class)
        {
            case CLASS_WARRIOR:
                info->stats[STAT_STRENGTH]  += (lvl > 23 ? 2: (lvl > 1  ? 1: 0));
                info->stats[STAT_STAMINA]   += (lvl > 23 ? 2: (lvl > 1  ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 36 ? 1: (lvl > 6 && (lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_SPIRIT]    += (lvl > 9 && !(lvl%2) ? 1: 0);
                break;
            case CLASS_PALADIN:
                info->stats[STAT_STRENGTH]  += (lvl > 3  ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 33 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 38 ? 1: (lvl > 7 && !(lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 6 && (lvl%2) ? 1: 0);
                info->stats[STAT_SPIRIT]    += (lvl > 7 ? 1: 0);
                break;
            case CLASS_HUNTER:
                info->stats[STAT_STRENGTH]  += (lvl > 4  ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 4  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 33 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 8 && (lvl%2) ? 1: 0);
                info->stats[STAT_SPIRIT]    += (lvl > 38 ? 1: (lvl > 9 && !(lvl%2) ? 1: 0));
                break;
            case CLASS_ROGUE:
                info->stats[STAT_STRENGTH]  += (lvl > 5  ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 4  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 16 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 8 && !(lvl%2) ? 1: 0);
                info->stats[STAT_SPIRIT]    += (lvl > 38 ? 1: (lvl > 9 && !(lvl%2) ? 1: 0));
                break;
            case CLASS_PRIEST:
                info->stats[STAT_STRENGTH]  += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 5  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 38 ? 1: (lvl > 8 && (lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 22 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_SPIRIT]    += (lvl > 3  ? 1: 0);
                break;
            case CLASS_SHAMAN:
                info->stats[STAT_STRENGTH]  += (lvl > 34 ? 1: (lvl > 6 && (lvl%2) ? 1: 0));
                info->stats[STAT_STAMINA]   += (lvl > 4 ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 7 && !(lvl%2) ? 1: 0);
                info->stats[STAT_INTELLECT] += (lvl > 5 ? 1: 0);
                info->stats[STAT_SPIRIT]    += (lvl > 4 ? 1: 0);
                break;
            case CLASS_MAGE:
                info->stats[STAT_STRENGTH]  += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 5  ? 1: 0);
                info->stats[STAT_AGILITY]   += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_INTELLECT] += (lvl > 24 ? 2: (lvl > 1 ? 1: 0));
                info->stats[STAT_SPIRIT]    += (lvl > 33 ? 2: (lvl > 2 ? 1: 0));
                break;
            case CLASS_WARLOCK:
                info->stats[STAT_STRENGTH]  += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_STAMINA]   += (lvl > 38 ? 2: (lvl > 3 ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 9 && !(lvl%2) ? 1: 0);
                info->stats[STAT_INTELLECT] += (lvl > 33 ? 2: (lvl > 2 ? 1: 0));
                info->stats[STAT_SPIRIT]    += (lvl > 38 ? 2: (lvl > 3 ? 1: 0));
                break;
            case CLASS_DRUID:
                info->stats[STAT_STRENGTH]  += (lvl > 38 ? 2: (lvl > 6 && (lvl%2) ? 1: 0));
                info->stats[STAT_STAMINA]   += (lvl > 32 ? 2: (lvl > 4 ? 1: 0));
                info->stats[STAT_AGILITY]   += (lvl > 38 ? 2: (lvl > 8 && (lvl%2) ? 1: 0));
                info->stats[STAT_INTELLECT] += (lvl > 38 ? 3: (lvl > 4 ? 1: 0));
                info->stats[STAT_SPIRIT]    += (lvl > 38 ? 3: (lvl > 5 ? 1: 0));
        }
    }
}

void ObjectMgr::LoadQuests()
{
    uint32 oldMSTime = getMSTime();

    // For reload case
    for (QuestMap::const_iterator itr=_questTemplates.begin(); itr != _questTemplates.end(); ++itr)
        delete itr->second;
    _questTemplates.clear();

    mExclusiveQuestGroups.clear();

    QueryResult result = WorldDatabase.Query("SELECT "
        //0  1          2           3               4         5            6            7                  8                9                   10
        "ID, QuestType, QuestLevel, QuestPackageID, MinLevel, QuestSortID, QuestInfoID, SuggestedGroupNum, RewardNextQuest, RewardXPDifficulty, RewardXPMultiplier, "
        //11          12                     13                     14                15                  16           17           18               19         20     21
        "RewardMoney, RewardMoneyDifficulty, RewardMoneyMultiplier, RewardBonusMoney, RewardDisplaySpell, RewardSpell, RewardHonor, RewardKillHonor, StartItem, Flags, FlagsEx, "
        //22          23             24         25                 26           27             28         29
        "RewardItem1, RewardAmount1, ItemDrop1, ItemDropQuantity1, RewardItem2, RewardAmount2, ItemDrop2, ItemDropQuantity2, "
        //30          31             32         33                 34           35             36         37
        "RewardItem3, RewardAmount3, ItemDrop3, ItemDropQuantity3, RewardItem4, RewardAmount4, ItemDrop4, ItemDropQuantity4, "
        //38                  39                         40                          41                   42                         43
        "RewardChoiceItemID1, RewardChoiceItemQuantity1, RewardChoiceItemDisplayID1, RewardChoiceItemID2, RewardChoiceItemQuantity2, RewardChoiceItemDisplayID2, "
        //44                  45                         46                          47                   48                         49
        "RewardChoiceItemID3, RewardChoiceItemQuantity3, RewardChoiceItemDisplayID3, RewardChoiceItemID4, RewardChoiceItemQuantity4, RewardChoiceItemDisplayID4, "
        //50                  51                         52                          53                   54                         55
        "RewardChoiceItemID5, RewardChoiceItemQuantity5, RewardChoiceItemDisplayID5, RewardChoiceItemID6, RewardChoiceItemQuantity6, RewardChoiceItemDisplayID6, "
        //56           57    58    59           60           61             62                 63                 64                 65             66
        "POIContinent, POIx, POIy, POIPriority, RewardTitle, RewardTalents, RewardArenaPoints, RewardSkillLineID, RewardNumSkillUps, PortraitGiver, PortraitTurnIn, "
        //67               68                   69                      70                71                   72
        "RewardFactionID1, RewardFactionValue1, RewardFactionOverride1, RewardFactionID2, RewardFactionValue2, RewardFactionOverride2, "
        //73               74                   75                      76                77                   78
        "RewardFactionID3, RewardFactionValue3, RewardFactionOverride3, RewardFactionID4, RewardFactionValue4, RewardFactionOverride4, "
        //79               80                   81                      82
        "RewardFactionID5, RewardFactionValue5, RewardFactionOverride5, RewardFactionFlags, "
        //83                84                  85                 86                  87                 88                  89                 90
        "RewardCurrencyID1, RewardCurrencyQty1, RewardCurrencyID2, RewardCurrencyQty2, RewardCurrencyID3, RewardCurrencyQty3, RewardCurrencyID4, RewardCurrencyQty4, "
        //91                 92                  93           94           95
        "AcceptedSoundKitID, CompleteSoundKitID, AreaGroupID, TimeAllowed, AllowableRaces, "
        //96       97              98                99               100                101                102                 103                 104
        "LogTitle, LogDescription, QuestDescription, AreaDescription, PortraitGiverText, PortraitGiverName, PortraitTurnInText, PortraitTurnInName, QuestCompletionLog"
        " FROM quest_template");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quests definitions. DB table `quest_template` is empty.");
        return;
    }

    // create multimap previous quest for each existed quest
    // some quests can have many previous maps set by NextQuestId in previous quest
    // for example set of race quests can lead to single not race specific quest
    do
    {
        Field* fields = result->Fetch();

        Quest* newQuest = new Quest(fields);
        _questTemplates[newQuest->GetQuestId()] = newQuest;
    } while (result->NextRow());

    // Load `quest_details`
    //                                   0   1       2       3       4       5            6            7            8
    result = WorldDatabase.Query("SELECT ID, Emote1, Emote2, Emote3, Emote4, EmoteDelay1, EmoteDelay2, EmoteDelay3, EmoteDelay4 FROM quest_details");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest details. DB table `quest_details` is empty.");
    }
    else
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 questId = fields[0].GetUInt32();

            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second->LoadQuestDetails(fields);
            else
                TC_LOG_ERROR("server.loading", "Table `quest_details` has data for quest %u but such quest does not exist", questId);
        } while (result->NextRow());
    }

    // Load `quest_request_items`
    //                                   0   1                2                  3                     4                       5
    result = WorldDatabase.Query("SELECT ID, EmoteOnComplete, EmoteOnIncomplete, EmoteOnCompleteDelay, EmoteOnIncompleteDelay, CompletionText FROM quest_request_items");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest request items. DB table `quest_request_items` is empty.");
    }
    else
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 questId = fields[0].GetUInt32();

            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second->LoadQuestRequestItems(fields);
            else
                TC_LOG_ERROR("server.loading", "Table `quest_request_items` has data for quest %u but such quest does not exist", questId);
        } while (result->NextRow());
    }

    // Load `quest_offer_reward`
    //                                   0   1       2       3       4       5            6            7            8            9
    result = WorldDatabase.Query("SELECT ID, Emote1, Emote2, Emote3, Emote4, EmoteDelay1, EmoteDelay2, EmoteDelay3, EmoteDelay4, RewardText FROM quest_offer_reward");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest reward emotes. DB table `quest_offer_reward` is empty.");
    }
    else
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 questId = fields[0].GetUInt32();

            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second->LoadQuestOfferReward(fields);
            else
                TC_LOG_ERROR("server.loading", "Table `quest_offer_reward` has data for quest %u but such quest does not exist", questId);
        } while (result->NextRow());
    }

    // Load `quest_template_addon`
    //                                   0   1         2                 3              4            5            6               7                     8
    result = WorldDatabase.Query("SELECT ID, MaxLevel, AllowableClasses, SourceSpellID, PrevQuestID, NextQuestID, ExclusiveGroup, RewardMailTemplateID, RewardMailDelay, "
        //9               10                   11                     12                     13                   14                   15                 16
        "RequiredSkillID, RequiredSkillPoints, RequiredMinRepFaction, RequiredMaxRepFaction, RequiredMinRepValue, RequiredMaxRepValue, ProvidedItemCount, SpecialFlags FROM quest_template_addon");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest template addons. DB table `quest_template_addon` is empty.");
    }
    else
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 questId = fields[0].GetUInt32();

            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second->LoadQuestTemplateAddon(fields);
            else
                TC_LOG_ERROR("server.loading", "Table `quest_template_addon` has data for quest %u but such quest does not exist", questId);
        } while (result->NextRow());
    }

    // Load `quest_objectives` order by descending storage index to reduce resizes
    //                                   0   1        2     3             4         5       6      7         8
    result = WorldDatabase.Query("SELECT ID, QuestID, Type, StorageIndex, ObjectID, Amount, Flags, UnkFloat, Description FROM quest_objectives ORDER BY StorageIndex DESC");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest objectives. DB table `quest_objectives` is empty.");
    }
    else
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 questId = fields[1].GetUInt32();

            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second->LoadQuestObjective(fields);
            else
                TC_LOG_ERROR("server.loading", "Table `quest_objectives` has objective for quest %u but such quest does not exist", questId);
        } while (result->NextRow());
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
                TC_LOG_ERROR("server.loading", "Table `quest_visual_effect` has visual effect for objective %u but such objective does not exist.", vID);
                continue;
            }

            uint32 questId = fields[2].GetUInt32();

            // Do not throw error here because error for non existing quest is thrown while loading quest objectives. we do not need duplication
            auto itr = _questTemplates.find(questId);
            if (itr != _questTemplates.end())
                itr->second->LoadQuestObjectiveVisualEffect(fields);
        } while (result->NextRow());
    }

    std::map<uint32, uint32> usedMailTemplates;

    // Post processing
    for (QuestMap::iterator iter = _questTemplates.begin(); iter != _questTemplates.end(); ++iter)
    {
        // skip post-loading checks for disabled quests
        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_QUEST, iter->first, NULL))
            continue;

        Quest* qinfo = iter->second;

        // additional quest integrity checks (GO, creature_template and item_template must be loaded already)

        if (qinfo->GetQuestType() >= MAX_QUEST_TYPES)
            TC_LOG_ERROR("sql.sql", "Quest %u has `Method` = %u, expected values are 0, 1 or 2.", qinfo->GetQuestId(), qinfo->GetQuestType());

        if (qinfo->SpecialFlags & ~QUEST_SPECIAL_FLAGS_DB_ALLOWED)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `SpecialFlags` = %u > max allowed value. Correct `SpecialFlags` to value <= %u",
                qinfo->GetQuestId(), qinfo->SpecialFlags, QUEST_SPECIAL_FLAGS_DB_ALLOWED);
            qinfo->SpecialFlags &= QUEST_SPECIAL_FLAGS_DB_ALLOWED;
        }

        if (qinfo->Flags & QUEST_FLAGS_DAILY && qinfo->Flags & QUEST_FLAGS_WEEKLY)
        {
            TC_LOG_ERROR("sql.sql", "Weekly Quest %u is marked as daily quest in `Flags`, removed daily flag.", qinfo->GetQuestId());
            qinfo->Flags &= ~QUEST_FLAGS_DAILY;
        }

        if (qinfo->Flags & QUEST_FLAGS_DAILY)
        {
            if (!(qinfo->SpecialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE))
            {
                TC_LOG_DEBUG("sql.sql", "Daily Quest %u not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
                qinfo->SpecialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
            }
        }

        if (qinfo->Flags & QUEST_FLAGS_WEEKLY)
        {
            if (!(qinfo->SpecialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE))
            {
                TC_LOG_DEBUG("sql.sql", "Weekly Quest %u not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
                qinfo->SpecialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
            }
        }

        if (qinfo->SpecialFlags & QUEST_SPECIAL_FLAGS_MONTHLY)
        {
            if (!(qinfo->SpecialFlags & QUEST_SPECIAL_FLAGS_REPEATABLE))
            {
                TC_LOG_DEBUG("sql.sql", "Monthly quest %u not marked as repeatable in `SpecialFlags`, added.", qinfo->GetQuestId());
                qinfo->SpecialFlags |= QUEST_SPECIAL_FLAGS_REPEATABLE;
            }
        }

        if (qinfo->Flags & QUEST_FLAGS_TRACKING)
        {
            // at auto-reward can be rewarded only RewardChoiceItemId[0]
            for (int j = 1; j < QUEST_REWARD_CHOICES_COUNT; ++j )
            {
                if (uint32 id = qinfo->RewardChoiceItemId[j])
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardChoiceItemId%d` = %u but item from `RewardChoiceItemId%d` can't be rewarded with quest flag QUEST_FLAGS_TRACKING.",
                        qinfo->GetQuestId(), j+1, id, j+1);
                    // no changes, quest ignore this data
                }
            }
        }

        if (qinfo->MinLevel == -1 || qinfo->MinLevel > DEFAULT_MAX_LEVEL)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u should be disabled because `MinLevel` = %i", qinfo->GetQuestId(), int32(qinfo->MinLevel));
            // no changes needed, sending -1 in SMSG_QUEST_QUERY_RESPONSE is valid
        }

        // client quest log visual (area case)
        if (qinfo->QuestSortID > 0)
        {
            if (!sAreaTableStore.LookupEntry(qinfo->QuestSortID))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `QuestSortID` = %u (zone case) but zone with this id does not exist.",
                    qinfo->GetQuestId(), qinfo->QuestSortID);
                // no changes, quest not dependent from this value but can have problems at client
            }
        }
        // client quest log visual (sort case)
        if (qinfo->QuestSortID < 0)
        {
            QuestSortEntry const* qSort = sQuestSortStore.LookupEntry(-int32(qinfo->QuestSortID));
            if (!qSort)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `QuestSortID` = %i (sort case) but quest sort with this id does not exist.",
                    qinfo->GetQuestId(), qinfo->QuestSortID);
                // no changes, quest not dependent from this value but can have problems at client (note some may be 0, we must allow this so no check)
            }
            //check for proper RequiredSkillId value (skill case)
            if (uint32 skill_id = SkillByQuestSort(-int32(qinfo->QuestSortID)))
            {
                if (qinfo->RequiredSkillId != skill_id)
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `QuestSortID` = %i but `RequiredSkillId` does not have a corresponding value (%d).",
                        qinfo->GetQuestId(), qinfo->QuestSortID, skill_id);
                    //override, and force proper value here?
                }
            }
        }

        // AllowableClasses, can be 0/CLASSMASK_ALL_PLAYABLE to allow any class
        if (qinfo->AllowableClasses)
        {
            if (!(qinfo->AllowableClasses & CLASSMASK_ALL_PLAYABLE))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u does not contain any playable classes in `AllowableClasses` (%u), value set to 0 (all classes).", qinfo->GetQuestId(), qinfo->AllowableClasses);
                qinfo->AllowableClasses = 0;
            }
        }
        // AllowableRaces, can be -1/RACEMASK_ALL_PLAYABLE to allow any race
        if (qinfo->AllowableRaces != -1)
        {
            if (qinfo->AllowableRaces > 0 && !(uint32(qinfo->AllowableRaces) & RACEMASK_ALL_PLAYABLE))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u does not contain any playable races in `AllowableRaces` (%d), value set to 0 (all races).", qinfo->GetQuestId(), qinfo->AllowableRaces);
                qinfo->AllowableRaces = -1;
            }
        }
        // RequiredSkillId, can be 0
        if (qinfo->RequiredSkillId)
        {
            if (!sSkillLineStore.LookupEntry(qinfo->RequiredSkillId))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredSkillId` = %u but this skill does not exist",
                    qinfo->GetQuestId(), qinfo->RequiredSkillId);
            }
        }

        if (qinfo->RequiredSkillPoints)
        {
            if (qinfo->RequiredSkillPoints > sWorld->GetConfigMaxSkillValue())
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredSkillPoints` = %u but max possible skill is %u, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->RequiredSkillPoints, sWorld->GetConfigMaxSkillValue());
                // no changes, quest can't be done for this requirement
            }
        }
        // else Skill quests can have 0 skill level, this is ok

        if (qinfo->RequiredMinRepFaction && !sFactionStore.LookupEntry(qinfo->RequiredMinRepFaction))
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredMinRepFaction` = %u but faction template %u does not exist, quest can't be done.",
                qinfo->GetQuestId(), qinfo->RequiredMinRepFaction, qinfo->RequiredMinRepFaction);
            // no changes, quest can't be done for this requirement
        }

        if (qinfo->RequiredMaxRepFaction && !sFactionStore.LookupEntry(qinfo->RequiredMaxRepFaction))
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredMaxRepFaction` = %u but faction template %u does not exist, quest can't be done.",
                qinfo->GetQuestId(), qinfo->RequiredMaxRepFaction, qinfo->RequiredMaxRepFaction);
            // no changes, quest can't be done for this requirement
        }

        if (qinfo->RequiredMinRepValue && qinfo->RequiredMinRepValue > ReputationMgr::Reputation_Cap)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredMinRepValue` = %d but max reputation is %u, quest can't be done.",
                qinfo->GetQuestId(), qinfo->RequiredMinRepValue, ReputationMgr::Reputation_Cap);
            // no changes, quest can't be done for this requirement
        }

        if (qinfo->RequiredMinRepValue && qinfo->RequiredMaxRepValue && qinfo->RequiredMaxRepValue <= qinfo->RequiredMinRepValue)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredMaxRepValue` = %d and `RequiredMinRepValue` = %d, quest can't be done.",
                qinfo->GetQuestId(), qinfo->RequiredMaxRepValue, qinfo->RequiredMinRepValue);
            // no changes, quest can't be done for this requirement
        }

        if (!qinfo->RequiredMinRepFaction && qinfo->RequiredMinRepValue != 0)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredMinRepValue` = %d but `RequiredMinRepFaction` is 0, value has no effect",
                qinfo->GetQuestId(), qinfo->RequiredMinRepValue);
            // warning
        }

        if (!qinfo->RequiredMaxRepFaction && qinfo->RequiredMaxRepValue != 0)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RequiredMaxRepValue` = %d but `RequiredMaxRepFaction` is 0, value has no effect",
                qinfo->GetQuestId(), qinfo->RequiredMaxRepValue);
            // warning
        }

        if (qinfo->RewardTitleId && !sCharTitlesStore.LookupEntry(qinfo->RewardTitleId))
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `RewardTitleId` = %u but CharTitle Id %u does not exist, quest can't be rewarded with title.",
                qinfo->GetQuestId(), qinfo->RewardTitleId, qinfo->RewardTitleId);
            qinfo->RewardTitleId = 0;
            // quest can't reward this title
        }

        if (qinfo->SourceItemId)
        {
            if (!sObjectMgr->GetItemTemplate(qinfo->SourceItemId))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `SourceItemId` = %u but item with entry %u does not exist, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->SourceItemId, qinfo->SourceItemId);
                qinfo->SourceItemId = 0;                       // quest can't be done for this requirement
            }
            else if (qinfo->SourceItemIdCount == 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `StartItem` = %u but `ProvidedItemCount` = 0, set to 1 but need fix in DB.",
                    qinfo->GetQuestId(), qinfo->SourceItemId);
                qinfo->SourceItemIdCount = 1;                    // update to 1 for allow quest work for backward compatibility with DB
            }
        }
        else if (qinfo->SourceItemIdCount>0)
        {
            TC_LOG_ERROR("sql.sql", "Quest %u has `SourceItemId` = 0 but `SourceItemIdCount` = %u, useless value.",
                qinfo->GetQuestId(), qinfo->SourceItemIdCount);
            qinfo->SourceItemIdCount=0;                          // no quest work changes in fact
        }

        if (qinfo->SourceSpellID)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(qinfo->SourceSpellID);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `SourceSpellid` = %u but spell %u doesn't exist, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->SourceSpellID, qinfo->SourceSpellID);
                qinfo->SourceSpellID = 0;                        // quest can't be done for this requirement
            }
            else if (!SpellMgr::IsSpellValid(spellInfo))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `SourceSpellid` = %u but spell %u is broken, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->SourceSpellID, qinfo->SourceSpellID);
                qinfo->SourceSpellID = 0;                        // quest can't be done for this requirement
            }
        }

        for (QuestObjective const& obj : qinfo->GetObjectives())
        {
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
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has invalid StorageIndex = %d for objective type %u", qinfo->GetQuestId(), obj.ID, obj.StorageIndex, obj.Type);
                        break;
                    default:
                        break;
                }
            }

            switch (obj.Type)
            {
                case QUEST_OBJECTIVE_ITEM:
                    qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_DELIVER);
                    if (!sObjectMgr->GetItemTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing item entry %u, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_MONSTER:
                    qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST);
                    if (!sObjectMgr->GetCreatureTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing creature entry %u, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_GAMEOBJECT:
                    qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_KILL | QUEST_SPECIAL_FLAGS_CAST);
                    if (!sObjectMgr->GetGameObjectTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing gameobject entry %u, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_TALKTO:
                    // Need checks (is it creature only?)
                    qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_CAST | QUEST_SPECIAL_FLAGS_SPEAKTO);
                    break;
                case QUEST_OBJECTIVE_MIN_REPUTATION:
                case QUEST_OBJECTIVE_MAX_REPUTATION:
                    if (!sFactionStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing faction id %d", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_PLAYERKILLS:
                    qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_PLAYER_KILL);
                    if (obj.Amount <= 0)
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has invalid player kills count %d", qinfo->GetQuestId(), obj.ID, obj.Amount);
                    break;
                case QUEST_OBJECTIVE_CURRENCY:
                case QUEST_OBJECTIVE_HAVE_CURRENCY:
                case QUEST_OBJECTIVE_OBTAIN_CURRENCY:
                    if (!sCurrencyTypesStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing currency %d", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    if (obj.Amount <= 0)
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has invalid currency amount %d", qinfo->GetQuestId(), obj.ID, obj.Amount);
                    break;
                case QUEST_OBJECTIVE_LEARNSPELL:
                    if (!sSpellMgr->GetSpellInfo(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing spell id %d", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_WINPETBATTLEAGAINSTNPC:
                    if (obj.ObjectID && !sObjectMgr->GetCreatureTemplate(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing creature entry %u, quest can't be done.",
                            qinfo->GetQuestId(), obj.ID, uint32(obj.ObjectID));
                    break;
                case QUEST_OBJECTIVE_DEFEATBATTLEPET:
                    if (!sBattlePetSpeciesStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing battlepet species id %d", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_CRITERIA_TREE:
                    if (!sCriteriaTreeStore.LookupEntry(obj.ObjectID))
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing criteria tree id %d", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_AREATRIGGER:
                    if (sAreaTriggerStore.LookupEntry(uint32(obj.ObjectID)))
                        _questAreaTriggerStore[obj.ObjectID].insert(qinfo->ID);
                    else if (obj.ObjectID != -1)
                        TC_LOG_ERROR("sql.sql", "Quest %u objective %u has non existing areatrigger id %d", qinfo->GetQuestId(), obj.ID, obj.ObjectID);
                    break;
                case QUEST_OBJECTIVE_MONEY:
                case QUEST_OBJECTIVE_WINPVPPETBATTLES:
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "Quest %u objective %u has unhandled type %u", qinfo->GetQuestId(), obj.ID, obj.Type);
                    break;
            }
        }

        for (uint8 j = 0; j < QUEST_ITEM_DROP_COUNT; ++j)
        {
            uint32 id = qinfo->ItemDrop[j];
            if (id)
            {
                if (!sObjectMgr->GetItemTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `ItemDrop%d` = %u but item with entry %u does not exist, quest can't be done.",
                        qinfo->GetQuestId(), j+1, id, id);
                    // no changes, quest can't be done for this requirement
                }
            }
            else
            {
                if (qinfo->ItemDropQuantity[j]>0)
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `ItemDrop%d` = 0 but `ItemDropQuantity%d` = %u.",
                        qinfo->GetQuestId(), j+1, j+1, qinfo->ItemDropQuantity[j]);
                    // no changes, quest ignore this data
                }
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_CHOICES_COUNT; ++j)
        {
            uint32 id = qinfo->RewardChoiceItemId[j];
            if (id)
            {
                if (!sObjectMgr->GetItemTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardChoiceItemId%d` = %u but item with entry %u does not exist, quest will not reward this item.",
                        qinfo->GetQuestId(), j+1, id, id);
                    qinfo->RewardChoiceItemId[j] = 0;          // no changes, quest will not reward this
                }

                if (!qinfo->RewardChoiceItemCount[j])
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardChoiceItemId%d` = %u but `RewardChoiceItemCount%d` = 0, quest can't be done.",
                        qinfo->GetQuestId(), j+1, id, j+1);
                    // no changes, quest can't be done
                }
            }
            else if (qinfo->RewardChoiceItemCount[j]>0)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardChoiceItemId%d` = 0 but `RewardChoiceItemCount%d` = %u.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardChoiceItemCount[j]);
                // no changes, quest ignore this data
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_ITEM_COUNT; ++j)
        {
            uint32 id = qinfo->RewardItemId[j];
            if (id)
            {
                if (!sObjectMgr->GetItemTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardItemId%d` = %u but item with entry %u does not exist, quest will not reward this item.",
                        qinfo->GetQuestId(), j+1, id, id);
                    qinfo->RewardItemId[j] = 0;                // no changes, quest will not reward this item
                }

                if (!qinfo->RewardItemCount[j])
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardItemId%d` = %u but `RewardItemCount%d` = 0, quest will not reward this item.",
                        qinfo->GetQuestId(), j+1, id, j+1);
                    // no changes
                }
            }
            else if (qinfo->RewardItemCount[j]>0)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardItemId%d` = 0 but `RewardItemCount%d` = %u.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardItemCount[j]);
                // no changes, quest ignore this data
            }
        }

        for (uint8 j = 0; j < QUEST_REWARD_REPUTATIONS_COUNT; ++j)
        {
            if (qinfo->RewardFactionId[j])
            {
                if (abs(qinfo->RewardFactionValue[j]) > 9)
                {
               TC_LOG_ERROR("sql.sql", "Quest %u has RewardFactionValueId%d = %i. That is outside the range of valid values (-9 to 9).", qinfo->GetQuestId(), j+1, qinfo->RewardFactionValue[j]);
                }
                if (!sFactionStore.LookupEntry(qinfo->RewardFactionId[j]))
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardFactionId%d` = %u but raw faction (faction.dbc) %u does not exist, quest will not reward reputation for this faction.", qinfo->GetQuestId(), j+1, qinfo->RewardFactionId[j], qinfo->RewardFactionId[j]);
                    qinfo->RewardFactionId[j] = 0;            // quest will not reward this
                }
            }

            else if (qinfo->RewardFactionOverride[j] != 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardFactionId%d` = 0 but `RewardFactionValueIdOverride%d` = %i.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardFactionOverride[j]);
                // no changes, quest ignore this data
            }
        }

        if (qinfo->RewardDisplaySpell)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(qinfo->RewardDisplaySpell);

            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSpell` = %u but spell %u does not exist, spell removed as display reward.",
                    qinfo->GetQuestId(), qinfo->RewardDisplaySpell, qinfo->RewardDisplaySpell);
                qinfo->RewardDisplaySpell = 0;                        // no spell reward will display for this quest
            }

            else if (!SpellMgr::IsSpellValid(spellInfo))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSpell` = %u but spell %u is broken, quest will not have a spell reward.",
                    qinfo->GetQuestId(), qinfo->RewardDisplaySpell, qinfo->RewardDisplaySpell);
                qinfo->RewardDisplaySpell = 0;                        // no spell reward will display for this quest
            }
        }

        if (qinfo->RewardSpell > 0)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(qinfo->RewardSpell);

            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSpellCast` = %u but spell %u does not exist, quest will not have a spell reward.",
                    qinfo->GetQuestId(), qinfo->RewardSpell, qinfo->RewardSpell);
                qinfo->RewardSpell = 0;                    // no spell will be cast on player
            }

            else if (!SpellMgr::IsSpellValid(spellInfo))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSpellCast` = %u but spell %u is broken, quest will not have a spell reward.",
                    qinfo->GetQuestId(), qinfo->RewardSpell, qinfo->RewardSpell);
                qinfo->RewardSpell = 0;                    // no spell will be cast on player
            }
        }

        if (qinfo->RewardMailTemplateId)
        {
            if (!sMailTemplateStore.LookupEntry(qinfo->RewardMailTemplateId))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardMailTemplateId` = %u but mail template  %u does not exist, quest will not have a mail reward.",
                    qinfo->GetQuestId(), qinfo->RewardMailTemplateId, qinfo->RewardMailTemplateId);
                qinfo->RewardMailTemplateId = 0;               // no mail will send to player
                qinfo->RewardMailDelay = 0;                // no mail will send to player
            }
            else if (usedMailTemplates.find(qinfo->RewardMailTemplateId) != usedMailTemplates.end())
            {
                std::map<uint32, uint32>::const_iterator used_mt_itr = usedMailTemplates.find(qinfo->RewardMailTemplateId);
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardMailTemplateId` = %u but mail template  %u already used for quest %u, quest will not have a mail reward.",
                    qinfo->GetQuestId(), qinfo->RewardMailTemplateId, qinfo->RewardMailTemplateId, used_mt_itr->second);
                qinfo->RewardMailTemplateId = 0;               // no mail will send to player
                qinfo->RewardMailDelay = 0;                // no mail will send to player
            }
            else
                usedMailTemplates[qinfo->RewardMailTemplateId] = qinfo->GetQuestId();
        }

        if (qinfo->NextQuestInChain)
        {
            QuestMap::iterator qNextItr = _questTemplates.find(qinfo->NextQuestInChain);
            if (qNextItr == _questTemplates.end())
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `NextQuestInChain` = %u but quest %u does not exist, quest chain will not work.",
                    qinfo->GetQuestId(), qinfo->NextQuestInChain, qinfo->NextQuestInChain);
                qinfo->NextQuestInChain = 0;
            }
            else
                qNextItr->second->prevChainQuests.push_back(qinfo->GetQuestId());
        }

        for (uint8 j = 0; j < QUEST_REWARD_CURRENCY_COUNT; ++j)
        {
            if (qinfo->RewardCurrencyId[j])
            {
                if (qinfo->RewardCurrencyCount[j] == 0)
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardCurrencyId%d` = %u but `RewardCurrencyCount%d` = 0, quest can't be done.",
                        qinfo->GetQuestId(), j+1, qinfo->RewardCurrencyId[j], j+1);
                    // no changes, quest can't be done for this requirement
                }

                if (!sCurrencyTypesStore.LookupEntry(qinfo->RewardCurrencyId[j]))
                {
                    TC_LOG_ERROR("sql.sql", "Quest %u has `RewardCurrencyId%d` = %u but currency with entry %u does not exist, quest can't be done.",
                        qinfo->GetQuestId(), j+1, qinfo->RewardCurrencyId[j], qinfo->RewardCurrencyId[j]);
                    qinfo->RewardCurrencyCount[j] = 0;             // prevent incorrect work of quest
                }
            }
            else if (qinfo->RewardCurrencyCount[j] > 0)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardCurrencyId%d` = 0 but `RewardCurrencyCount%d` = %u, quest can't be done.",
                    qinfo->GetQuestId(), j+1, j+1, qinfo->RewardCurrencyCount[j]);
                qinfo->RewardCurrencyCount[j] = 0;                 // prevent incorrect work of quest
            }
        }

        if (qinfo->SoundAccept)
        {
            if (!sSoundEntriesStore.LookupEntry(qinfo->SoundAccept))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `SoundAccept` = %u but sound %u does not exist, set to 0.",
                    qinfo->GetQuestId(), qinfo->SoundAccept, qinfo->SoundAccept);
                qinfo->SoundAccept = 0;                        // no sound will be played
            }
        }

        if (qinfo->SoundTurnIn)
        {
            if (!sSoundEntriesStore.LookupEntry(qinfo->SoundTurnIn))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `SoundTurnIn` = %u but sound %u does not exist, set to 0.",
                    qinfo->GetQuestId(), qinfo->SoundTurnIn, qinfo->SoundTurnIn);
                qinfo->SoundTurnIn = 0;                        // no sound will be played
            }
        }

        if (qinfo->RewardSkillId)
        {
            if (!sSkillLineStore.LookupEntry(qinfo->RewardSkillId))
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSkillId` = %u but this skill does not exist",
                    qinfo->GetQuestId(), qinfo->RewardSkillId);
            }
            if (!qinfo->RewardSkillPoints)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSkillId` = %u but `RewardSkillPoints` is 0",
                    qinfo->GetQuestId(), qinfo->RewardSkillId);
            }
        }

        if (qinfo->RewardSkillPoints)
        {
            if (qinfo->RewardSkillPoints > sWorld->GetConfigMaxSkillValue())
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSkillPoints` = %u but max possible skill is %u, quest can't be done.",
                    qinfo->GetQuestId(), qinfo->RewardSkillPoints, sWorld->GetConfigMaxSkillValue());
                // no changes, quest can't be done for this requirement
            }
            if (!qinfo->RewardSkillId)
            {
                TC_LOG_ERROR("sql.sql", "Quest %u has `RewardSkillPoints` = %u but `RewardSkillId` is 0",
                    qinfo->GetQuestId(), qinfo->RewardSkillPoints);
            }
        }

        // fill additional data stores
        if (qinfo->PrevQuestID)
        {
            if (_questTemplates.find(abs(qinfo->GetPrevQuestId())) == _questTemplates.end())
                TC_LOG_ERROR("sql.sql", "Quest %d has PrevQuestId %i, but no such quest", qinfo->GetQuestId(), qinfo->GetPrevQuestId());
            else
                qinfo->prevQuests.push_back(qinfo->PrevQuestID);
        }

        if (qinfo->NextQuestID)
        {
            QuestMap::iterator qNextItr = _questTemplates.find(abs(qinfo->GetNextQuestId()));
            if (qNextItr == _questTemplates.end())
                TC_LOG_ERROR("sql.sql", "Quest %d has NextQuestId %i, but no such quest", qinfo->GetQuestId(), qinfo->GetNextQuestId());
            else
            {
                int32 signedQuestId = qinfo->NextQuestID < 0 ? -int32(qinfo->GetQuestId()) : int32(qinfo->GetQuestId());
                qNextItr->second->prevQuests.push_back(signedQuestId);
            }
        }

        if (qinfo->ExclusiveGroup)
            mExclusiveQuestGroups.insert(std::pair<int32, uint32>(qinfo->ExclusiveGroup, qinfo->GetQuestId()));
        if (qinfo->LimitTime)
            qinfo->SetSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED);
    }

    // check QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT for spell with SPELL_EFFECT_QUEST_COMPLETE
    for (uint32 i = 0; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(i);
        if (!spellInfo)
            continue;

        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (!effect || effect->Effect != SPELL_EFFECT_QUEST_COMPLETE)
                continue;

            uint32 quest_id = effect->MiscValue;

            Quest const* quest = GetQuestTemplate(quest_id);

            // some quest referenced in spells not exist (outdated spells)
            if (!quest)
                continue;

            if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
            {
                TC_LOG_ERROR("sql.sql", "Spell (id: %u) have SPELL_EFFECT_QUEST_COMPLETE for quest %u, but quest not have flag QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT. Quest flags must be fixed, quest modified to enable objective.", spellInfo->Id, quest_id);

                // this will prevent quest completing without objective
                const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT);
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %lu quests definitions in %u ms", (unsigned long)_questTemplates.size(), GetMSTimeDiffToNow(oldMSTime));
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
        std::string localeName          = fields[1].GetString();

        std::string logTitle            = fields[2].GetString();
        std::string logDescription      = fields[3].GetString();
        std::string questDescription    = fields[4].GetString();
        std::string areaDescription     = fields[5].GetString();
        std::string portraitGiverText   = fields[6].GetString();
        std::string portraitGiverName   = fields[7].GetString();
        std::string portraitTurnInText  = fields[8].GetString();
        std::string portraitTurnInName  = fields[9].GetString();
        std::string questCompletionLog  = fields[10].GetString();

        QuestTemplateLocale& data = _questTemplateLocaleStore[id];
        LocaleConstant locale = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        AddLocaleString(logTitle,               locale, data.LogTitle);
        AddLocaleString(logDescription,         locale, data.LogDescription);
        AddLocaleString(questDescription,       locale, data.QuestDescription);
        AddLocaleString(areaDescription,        locale, data.AreaDescription);
        AddLocaleString(portraitGiverText,      locale, data.PortraitGiverText);
        AddLocaleString(portraitGiverName,      locale, data.PortraitGiverName);
        AddLocaleString(portraitTurnInText,     locale, data.PortraitTurnInText);
        AddLocaleString(portraitTurnInName,     locale, data.PortraitTurnInName);
        AddLocaleString(questCompletionLog,     locale, data.QuestCompletionLog);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Quest Tempalate locale strings in %u ms", uint32(_questTemplateLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
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
        std::string localeName              = fields[1].GetString();

        std::string Description             = fields[2].GetString();

        QuestObjectivesLocale& data = _questObjectivesLocaleStore[id];
        LocaleConstant locale = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        AddLocaleString(Description, locale, data.Description);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Quest Objectives locale strings in %u ms", uint32(_questObjectivesLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
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

    TC_LOG_INFO("server.loading", "Loading %s...", tableName.c_str());

    scripts->clear();                                       // need for reload support

    bool isSpellScriptTable = (type == SCRIPTS_SPELL);
    //                                                 0    1       2         3         4          5    6  7  8  9
    QueryResult result = WorldDatabase.PQuery("SELECT id, delay, command, datalong, datalong2, dataint, x, y, z, o%s FROM %s", isSpellScriptTable ? ", effIndex" : "", tableName.c_str());

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 script definitions. DB table `%s` is empty!", tableName.c_str());
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
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid talk type (datalong = %u) in SCRIPT_COMMAND_TALK for script id %u",
                        tableName.c_str(), tmp.Talk.ChatType, tmp.id);
                    continue;
                }
                if (!sBroadcastTextStore.LookupEntry(uint32(tmp.Talk.TextID)))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid talk text id (dataint = %i) in SCRIPT_COMMAND_TALK for script id %u",
                        tableName.c_str(), tmp.Talk.TextID, tmp.id);
                    continue;
                }

                break;
            }

            case SCRIPT_COMMAND_EMOTE:
            {
                if (!sEmotesStore.LookupEntry(tmp.Emote.EmoteID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid emote id (datalong = %u) in SCRIPT_COMMAND_EMOTE for script id %u",
                        tableName.c_str(), tmp.Emote.EmoteID, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_TELEPORT_TO:
            {
                if (!sMapStore.LookupEntry(tmp.TeleportTo.MapID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid map (Id: %u) in SCRIPT_COMMAND_TELEPORT_TO for script id %u",
                        tableName.c_str(), tmp.TeleportTo.MapID, tmp.id);
                    continue;
                }

                if (!Trinity::IsValidMapCoord(tmp.TeleportTo.DestX, tmp.TeleportTo.DestY, tmp.TeleportTo.DestZ, tmp.TeleportTo.Orientation))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid coordinates (X: %f Y: %f Z: %f O: %f) in SCRIPT_COMMAND_TELEPORT_TO for script id %u",
                        tableName.c_str(), tmp.TeleportTo.DestX, tmp.TeleportTo.DestY, tmp.TeleportTo.DestZ, tmp.TeleportTo.Orientation, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_QUEST_EXPLORED:
            {
                Quest const* quest = GetQuestTemplate(tmp.QuestExplored.QuestID);
                if (!quest)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid quest (ID: %u) in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u",
                        tableName.c_str(), tmp.QuestExplored.QuestID, tmp.id);
                    continue;
                }

                if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has quest (ID: %u) in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u, but quest not have flag QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT in quest flags. Script command or quest flags wrong. Quest modified to require objective.",
                        tableName.c_str(), tmp.QuestExplored.QuestID, tmp.id);

                    // this will prevent quest completing without objective
                    const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT);

                    // continue; - quest objective requirement set and command can be allowed
                }

                if (float(tmp.QuestExplored.Distance) > DEFAULT_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has too large distance (%u) for exploring objective complete in `datalong2` in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u",
                        tableName.c_str(), tmp.QuestExplored.Distance, tmp.id);
                    continue;
                }

                if (tmp.QuestExplored.Distance && float(tmp.QuestExplored.Distance) > DEFAULT_VISIBILITY_DISTANCE)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has too large distance (%u) for exploring objective complete in `datalong2` in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u, max distance is %f or 0 for disable distance check",
                        tableName.c_str(), tmp.QuestExplored.Distance, tmp.id, DEFAULT_VISIBILITY_DISTANCE);
                    continue;
                }

                if (tmp.QuestExplored.Distance && float(tmp.QuestExplored.Distance) < INTERACTION_DISTANCE)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has too small distance (%u) for exploring objective complete in `datalong2` in SCRIPT_COMMAND_QUEST_EXPLORED in `datalong` for script id %u, min distance is %f or 0 for disable distance check",
                        tableName.c_str(), tmp.QuestExplored.Distance, tmp.id, INTERACTION_DISTANCE);
                    continue;
                }

                break;
            }

            case SCRIPT_COMMAND_KILL_CREDIT:
            {
                if (!GetCreatureTemplate(tmp.KillCredit.CreatureEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid creature (Entry: %u) in SCRIPT_COMMAND_KILL_CREDIT for script id %u",
                        tableName.c_str(), tmp.KillCredit.CreatureEntry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_RESPAWN_GAMEOBJECT:
            {
                GameObjectData const* data = GetGOData(tmp.RespawnGameobject.GOGuid);
                if (!data)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid gameobject (GUID: %u) in SCRIPT_COMMAND_RESPAWN_GAMEOBJECT for script id %u",
                        tableName.c_str(), tmp.RespawnGameobject.GOGuid, tmp.id);
                    continue;
                }

                GameObjectTemplate const* info = GetGameObjectTemplate(data->id);
                if (!info)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has gameobject with invalid entry (GUID: %u Entry: %u) in SCRIPT_COMMAND_RESPAWN_GAMEOBJECT for script id %u",
                        tableName.c_str(), tmp.RespawnGameobject.GOGuid, data->id, tmp.id);
                    continue;
                }

                if (info->type == GAMEOBJECT_TYPE_FISHINGNODE ||
                    info->type == GAMEOBJECT_TYPE_FISHINGHOLE ||
                    info->type == GAMEOBJECT_TYPE_DOOR        ||
                    info->type == GAMEOBJECT_TYPE_BUTTON      ||
                    info->type == GAMEOBJECT_TYPE_TRAP)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has gameobject type (%u) unsupported by command SCRIPT_COMMAND_RESPAWN_GAMEOBJECT for script id %u",
                        tableName.c_str(), info->entry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_TEMP_SUMMON_CREATURE:
            {
                if (!Trinity::IsValidMapCoord(tmp.TempSummonCreature.PosX, tmp.TempSummonCreature.PosY, tmp.TempSummonCreature.PosZ, tmp.TempSummonCreature.Orientation))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid coordinates (X: %f Y: %f Z: %f O: %f) in SCRIPT_COMMAND_TEMP_SUMMON_CREATURE for script id %u",
                        tableName.c_str(), tmp.TempSummonCreature.PosX, tmp.TempSummonCreature.PosY, tmp.TempSummonCreature.PosZ, tmp.TempSummonCreature.Orientation, tmp.id);
                    continue;
                }

                if (!GetCreatureTemplate(tmp.TempSummonCreature.CreatureEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid creature (Entry: %u) in SCRIPT_COMMAND_TEMP_SUMMON_CREATURE for script id %u",
                        tableName.c_str(), tmp.TempSummonCreature.CreatureEntry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_OPEN_DOOR:
            case SCRIPT_COMMAND_CLOSE_DOOR:
            {
                GameObjectData const* data = GetGOData(tmp.ToggleDoor.GOGuid);
                if (!data)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid gameobject (GUID: %u) in %s for script id %u",
                        tableName.c_str(), tmp.ToggleDoor.GOGuid, GetScriptCommandName(tmp.command).c_str(), tmp.id);
                    continue;
                }

                GameObjectTemplate const* info = GetGameObjectTemplate(data->id);
                if (!info)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has gameobject with invalid entry (GUID: %u Entry: %u) in %s for script id %u",
                        tableName.c_str(), tmp.ToggleDoor.GOGuid, data->id, GetScriptCommandName(tmp.command).c_str(), tmp.id);
                    continue;
                }

                if (info->type != GAMEOBJECT_TYPE_DOOR)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has gameobject type (%u) unsupported by command %s for script id %u",
                        tableName.c_str(), info->entry, GetScriptCommandName(tmp.command).c_str(), tmp.id);
                    continue;
                }

                break;
            }

            case SCRIPT_COMMAND_REMOVE_AURA:
            {
                if (!sSpellMgr->GetSpellInfo(tmp.RemoveAura.SpellID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` using non-existent spell (id: %u) in SCRIPT_COMMAND_REMOVE_AURA for script id %u",
                        tableName.c_str(), tmp.RemoveAura.SpellID, tmp.id);
                    continue;
                }
                if (tmp.RemoveAura.Flags & ~0x1)                    // 1 bits (0, 1)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` using unknown flags in datalong2 (%u) in SCRIPT_COMMAND_REMOVE_AURA for script id %u",
                        tableName.c_str(), tmp.RemoveAura.Flags, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_CAST_SPELL:
            {
                if (!sSpellMgr->GetSpellInfo(tmp.CastSpell.SpellID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` using non-existent spell (id: %u) in SCRIPT_COMMAND_CAST_SPELL for script id %u",
                        tableName.c_str(), tmp.CastSpell.SpellID, tmp.id);
                    continue;
                }
                if (tmp.CastSpell.Flags > 4)                      // targeting type
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` using unknown target in datalong2 (%u) in SCRIPT_COMMAND_CAST_SPELL for script id %u",
                        tableName.c_str(), tmp.CastSpell.Flags, tmp.id);
                    continue;
                }
                if (tmp.CastSpell.Flags != 4 && tmp.CastSpell.CreatureEntry & ~0x1)                      // 1 bit (0, 1)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` using unknown flags in dataint (%u) in SCRIPT_COMMAND_CAST_SPELL for script id %u",
                        tableName.c_str(), tmp.CastSpell.CreatureEntry, tmp.id);
                    continue;
                }
                else if (tmp.CastSpell.Flags == 4 && !GetCreatureTemplate(tmp.CastSpell.CreatureEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` using invalid creature entry in dataint (%u) in SCRIPT_COMMAND_CAST_SPELL for script id %u",
                        tableName.c_str(), tmp.CastSpell.CreatureEntry, tmp.id);
                    continue;
                }
                break;
            }

            case SCRIPT_COMMAND_CREATE_ITEM:
            {
                if (!GetItemTemplate(tmp.CreateItem.ItemEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has nonexistent item (entry: %u) in SCRIPT_COMMAND_CREATE_ITEM for script id %u",
                        tableName.c_str(), tmp.CreateItem.ItemEntry, tmp.id);
                    continue;
                }
                if (!tmp.CreateItem.Amount)
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` SCRIPT_COMMAND_CREATE_ITEM but amount is %u for script id %u",
                        tableName.c_str(), tmp.CreateItem.Amount, tmp.id);
                    continue;
                }
                break;
            }
            case SCRIPT_COMMAND_PLAY_ANIMKIT:
            {
                if (!sAnimKitStore.LookupEntry(tmp.PlayAnimKit.AnimKitID))
                {
                    TC_LOG_ERROR("sql.sql", "Table `%s` has invalid AnimKid id (datalong = %u) in SCRIPT_COMMAND_PLAY_ANIMKIT for script id %u",
                        tableName.c_str(), tmp.PlayAnimKit.AnimKitID, tmp.id);
                    continue;
                }
                break;
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

    TC_LOG_INFO("server.loading", ">> Loaded %u script definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadSpellScripts()
{
    LoadScripts(SCRIPTS_SPELL);

    // check ids
    for (ScriptMapMap::const_iterator itr = sSpellScripts.begin(); itr != sSpellScripts.end(); ++itr)
    {
        uint32 spellId = uint32(itr->first) & 0x00FFFFFF;
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);

        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `spell_scripts` has not existing spell (Id: %u) as script id", spellId);
            continue;
        }

        uint8 i = (uint8)((uint32(itr->first) >> 24) & 0x000000FF);
        //check for correct spellEffect
        SpellEffectInfo const* effect = spellInfo->GetEffect(i);
        if (effect && (!effect->Effect || (effect->Effect != SPELL_EFFECT_SCRIPT_EFFECT && effect->Effect != SPELL_EFFECT_DUMMY)))
            TC_LOG_ERROR("sql.sql", "Table `spell_scripts` - spell %u effect %u is not SPELL_EFFECT_SCRIPT_EFFECT or SPELL_EFFECT_DUMMY", spellId, i);
    }
}

void ObjectMgr::LoadEventScripts()
{
    LoadScripts(SCRIPTS_EVENT);

    std::set<uint32> evt_scripts;
    // Load all possible script entries from gameobjects
    GameObjectTemplateContainer const* gotc = sObjectMgr->GetGameObjectTemplates();
    for (GameObjectTemplateContainer::const_iterator itr = gotc->begin(); itr != gotc->end(); ++itr)
        if (uint32 eventId = itr->second.GetEventScriptId())
            evt_scripts.insert(eventId);

    // Load all possible script entries from spells
    for (uint32 i = 1; i < sSpellMgr->GetSpellInfoStoreSize(); ++i)
        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(i))
            for (SpellEffectInfo const* effect : spell->GetEffectsForDifficulty(DIFFICULTY_NONE))
                if (effect && effect->Effect == SPELL_EFFECT_SEND_EVENT)
                    if (effect->MiscValue)
                        evt_scripts.insert(effect->MiscValue);

    for (size_t path_idx = 0; path_idx < sTaxiPathNodesByPath.size(); ++path_idx)
    {
        for (size_t node_idx = 0; node_idx < sTaxiPathNodesByPath[path_idx].size(); ++node_idx)
        {
            TaxiPathNodeEntry const* node = sTaxiPathNodesByPath[path_idx][node_idx];

            if (node->ArrivalEventID)
                evt_scripts.insert(node->ArrivalEventID);

            if (node->DepartureEventID)
                evt_scripts.insert(node->DepartureEventID);
        }
    }

    // Then check if all scripts are in above list of possible script entries
    for (ScriptMapMap::const_iterator itr = sEventScripts.begin(); itr != sEventScripts.end(); ++itr)
    {
        std::set<uint32>::const_iterator itr2 = evt_scripts.find(itr->first);
        if (itr2 == evt_scripts.end())
            TC_LOG_ERROR("sql.sql", "Table `event_scripts` has script (Id: %u) not referring to any gameobject_template type 10 data2 field, type 3 data6 field, type 13 data 2 field or any spell effect %u",
                itr->first, SPELL_EFFECT_SEND_EVENT);
    }
}

//Load WP Scripts
void ObjectMgr::LoadWaypointScripts()
{
    LoadScripts(SCRIPTS_WAYPOINT);

    std::set<uint32> actionSet;

    for (ScriptMapMap::const_iterator itr = sWaypointScripts.begin(); itr != sWaypointScripts.end(); ++itr)
        actionSet.insert(itr->first);

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_WAYPOINT_DATA_ACTION);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 action = fields[0].GetUInt32();

            actionSet.erase(action);
        }
        while (result->NextRow());
    }

    for (std::set<uint32>::iterator itr = actionSet.begin(); itr != actionSet.end(); ++itr)
        TC_LOG_ERROR("sql.sql", "There is no waypoint which links to the waypoint script %u", *itr);
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

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Scriptname: `%s` spell (Id: %d) does not exist.", scriptName.c_str(), fields[0].GetInt32());
            continue;
        }

        if (allRanks)
        {
            if (!spellInfo->IsRanked())
                TC_LOG_ERROR("sql.sql", "Scriptname: `%s` spell (Id: %d) has no ranks of spell.", scriptName.c_str(), fields[0].GetInt32());

            if (spellInfo->GetFirstRankSpell()->Id != uint32(spellId))
            {
                TC_LOG_ERROR("sql.sql", "Scriptname: `%s` spell (Id: %d) is not first rank of spell.", scriptName.c_str(), fields[0].GetInt32());
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
                TC_LOG_ERROR("sql.sql", "Scriptname: `%s` spell (Id: %d) is ranked spell. Perhaps not all ranks are assigned to this script.", scriptName.c_str(), spellId);

            _spellScriptsStore.insert(SpellScriptsContainer::value_type(spellInfo->Id, std::make_pair(GetScriptId(scriptName), true)));
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell script names in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

    for (auto spell : _spellScriptsStore)
    {
        SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(spell.first);

        auto const bounds = sObjectMgr->GetSpellScriptsBounds(spell.first);

        for (auto itr = bounds.first; itr != bounds.second; ++itr)
        {
            if (SpellScriptLoader* spellScriptLoader = sScriptMgr->GetSpellScriptLoader(itr->second.first))
            {
                ++count;

                std::unique_ptr<SpellScript> spellScript(spellScriptLoader->GetSpellScript());
                std::unique_ptr<AuraScript> auraScript(spellScriptLoader->GetAuraScript());

                if (!spellScript && !auraScript)
                {
                    TC_LOG_ERROR("scripts", "Functions GetSpellScript() and GetAuraScript() of script `%s` do not return objects - script skipped", GetScriptName(itr->second.first).c_str());

                    itr->second.second = false;
                    continue;
                }

                if (spellScript)
                {
                    spellScript->_Init(&spellScriptLoader->GetName(), spellEntry->Id);
                    spellScript->_Register();

                    if (!spellScript->_Validate(spellEntry))
                    {
                        itr->second.second = false;
                        continue;
                    }
                }

                if (auraScript)
                {
                    auraScript->_Init(&spellScriptLoader->GetName(), spellEntry->Id);
                    auraScript->_Register();

                    if (!auraScript->_Validate(spellEntry))
                    {
                        itr->second.second = false;
                        continue;
                    }
                }

                // Enable the script when all checks passed
                itr->second.second = true;
            }
            else
                itr->second.second = false;
        }
    }

    TC_LOG_INFO("server.loading", ">> Validated %u scripts in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPageTexts()
{
    uint32 oldMSTime = getMSTime();

    //                                               0   1     2
    QueryResult result = WorldDatabase.Query("SELECT ID, Text, NextPageID FROM page_text");
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

        ++count;
    }
    while (result->NextRow());

    for (PageTextContainer::const_iterator itr = _pageTextStore.begin(); itr != _pageTextStore.end(); ++itr)
    {
        if (itr->second.NextPageID)
        {
            PageTextContainer::const_iterator itr2 = _pageTextStore.find(itr->second.NextPageID);
            if (itr2 == _pageTextStore.end())
                TC_LOG_ERROR("sql.sql", "Page text (ID: %u) has non-existing `NextPageID` (%u)", itr->first, itr->second.NextPageID);

        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u page texts in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

PageText const* ObjectMgr::GetPageText(uint32 pageEntry)
{
    PageTextContainer::const_iterator itr = _pageTextStore.find(pageEntry);
    if (itr != _pageTextStore.end())
        return &(itr->second);

    return NULL;
}

void ObjectMgr::LoadPageTextLocales()
{
    uint32 oldMSTime = getMSTime();

    _pageTextLocaleStore.clear(); // needed for reload case

    //                                               0      1     2
    QueryResult result = WorldDatabase.Query("SELECT ID, locale, Text FROM page_text_locale");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        std::string localeName      = fields[1].GetString();
        std::string text            = fields[2].GetString();

        PageTextLocale& data = _pageTextLocaleStore[id];
        LocaleConstant locale = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        AddLocaleString(text, locale, data.Text);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u PageText locale strings in %u ms", uint32(_pageTextLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadInstanceTemplate()
{
    uint32 oldMSTime = getMSTime();

    //                                                0     1       2        4
    QueryResult result = WorldDatabase.Query("SELECT map, parent, script, allowMount FROM instance_template");

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

        if (!MapManager::IsValidMAP(mapID, true))
        {
            TC_LOG_ERROR("sql.sql", "ObjectMgr::LoadInstanceTemplate: bad mapid %d for template!", mapID);
            continue;
        }

        InstanceTemplate instanceTemplate;

        instanceTemplate.AllowMount = fields[3].GetBool();
        instanceTemplate.Parent     = uint32(fields[1].GetUInt16());
        instanceTemplate.ScriptId   = sObjectMgr->GetScriptId(fields[2].GetString());

        _instanceTemplateStore[mapID] = instanceTemplate;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u instance templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

InstanceTemplate const* ObjectMgr::GetInstanceTemplate(uint32 mapID)
{
    InstanceTemplateContainer::const_iterator itr = _instanceTemplateStore.find(uint16(mapID));
    if (itr != _instanceTemplateStore.end())
        return &(itr->second);

    return NULL;
}

void ObjectMgr::LoadInstanceEncounters()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0         1            2                3
    QueryResult result = WorldDatabase.Query("SELECT entry, creditType, creditEntry, lastEncounterDungeon FROM instance_encounters");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 instance encounters, table is empty!");
        return;
    }

    uint32 count = 0;
    std::map<uint32, DungeonEncounterEntry const*> dungeonLastBosses;
    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();
        uint8 creditType = fields[1].GetUInt8();
        uint32 creditEntry = fields[2].GetUInt32();
        uint32 lastEncounterDungeon = fields[3].GetUInt16();
        DungeonEncounterEntry const* dungeonEncounter = sDungeonEncounterStore.LookupEntry(entry);
        if (!dungeonEncounter)
        {
            TC_LOG_ERROR("sql.sql", "Table `instance_encounters` has an invalid encounter id %u, skipped!", entry);
            continue;
        }

        if (lastEncounterDungeon && !sLFGMgr->GetLFGDungeonEntry(lastEncounterDungeon))
        {
            TC_LOG_ERROR("sql.sql", "Table `instance_encounters` has an encounter %u (%s) marked as final for invalid dungeon id %u, skipped!", entry, dungeonEncounter->Name_lang, lastEncounterDungeon);
            continue;
        }

        std::map<uint32, DungeonEncounterEntry const*>::const_iterator itr = dungeonLastBosses.find(lastEncounterDungeon);
        if (lastEncounterDungeon)
        {
            if (itr != dungeonLastBosses.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `instance_encounters` specified encounter %u (%s) as last encounter but %u (%s) is already marked as one, skipped!", entry, dungeonEncounter->Name_lang, itr->second->ID, itr->second->Name_lang);
                continue;
            }

            dungeonLastBosses[lastEncounterDungeon] = dungeonEncounter;
        }

        switch (creditType)
        {
            case ENCOUNTER_CREDIT_KILL_CREATURE:
            {
                CreatureTemplate const* creatureInfo = GetCreatureTemplate(creditEntry);
                if (!creatureInfo)
                {
                    TC_LOG_ERROR("sql.sql", "Table `instance_encounters` has an invalid creature (entry %u) linked to the encounter %u (%s), skipped!", creditEntry, entry, dungeonEncounter->Name_lang);
                    continue;
                }
                const_cast<CreatureTemplate*>(creatureInfo)->flags_extra |= CREATURE_FLAG_EXTRA_DUNGEON_BOSS;
                break;
            }
            case ENCOUNTER_CREDIT_CAST_SPELL:
                if (!sSpellMgr->GetSpellInfo(creditEntry))
                {
                    TC_LOG_ERROR("sql.sql", "Table `instance_encounters` has an invalid spell (entry %u) linked to the encounter %u (%s), skipped!", creditEntry, entry, dungeonEncounter->Name_lang);
                    continue;
                }
                break;
            default:
                TC_LOG_ERROR("sql.sql", "Table `instance_encounters` has an invalid credit type (%u) for encounter %u (%s), skipped!", creditType, entry, dungeonEncounter->Name_lang);
                continue;
        }

        if (!dungeonEncounter->DifficultyID)
        {
            for (uint32 i = 0; i < MAX_DIFFICULTY; ++i)
            {
                if (GetMapDifficultyData(dungeonEncounter->MapID, Difficulty(i)))
                {
                    DungeonEncounterList& encounters = _dungeonEncounterStore[MAKE_PAIR64(dungeonEncounter->MapID, i)];
                    encounters.push_back(new DungeonEncounter(dungeonEncounter, EncounterCreditType(creditType), creditEntry, lastEncounterDungeon));
                }
            }
        }
        else
        {
            DungeonEncounterList& encounters = _dungeonEncounterStore[MAKE_PAIR64(dungeonEncounter->MapID, dungeonEncounter->DifficultyID)];
            encounters.push_back(new DungeonEncounter(dungeonEncounter, EncounterCreditType(creditType), creditEntry, lastEncounterDungeon));
        }

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u instance encounters in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

NpcText const* ObjectMgr::GetNpcText(uint32 Text_ID) const
{
    NpcTextContainer::const_iterator itr = _npcTextStore.find(Text_ID);
    if (itr != _npcTextStore.end())
        return &itr->second;
    return NULL;
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

    _npcTextStore.rehash(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        uint32 textID = fields[0].GetUInt32();
        if (!textID)
        {
            TC_LOG_ERROR("sql.sql", "Table `npc_text` has record with reserved id 0, ignore.");
            continue;
        }

        NpcText& npcText = _npcTextStore[textID];

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
                    TC_LOG_ERROR("sql.sql", "NPCText (ID: %u) has a non-existing or incompatible BroadcastText (ID: %u, Index: %u)", textID, npcText.Data[i].BroadcastTextID, i);
                    npcText.Data[i].BroadcastTextID = 0;
                }
            }
        }

        for (uint8 i = 0; i < MAX_NPC_TEXT_OPTIONS; i++)
        {
            if (npcText.Data[i].Probability > 0 && npcText.Data[i].BroadcastTextID == 0)
            {
                TC_LOG_ERROR("sql.sql", "NPCText (ID: %u) has a probability (Index: %u) set, but no BroadcastTextID to go with it", textID, i);
                npcText.Data[i].Probability = 0;
            }
        }
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u npc texts in %u ms", uint32(_npcTextStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

//not very fast function but it is called only once a day, or on starting-up
void ObjectMgr::ReturnOrDeleteOldMails(bool serverUp)
{
    uint32 oldMSTime = getMSTime();

    time_t curTime = time(NULL);
    tm lt;
    localtime_r(&curTime, &lt);
    uint64 basetime(curTime);
    TC_LOG_INFO("misc", "Returning mails current time: hour: %d, minute: %d, second: %d ", lt.tm_hour, lt.tm_min, lt.tm_sec);

    // Delete all old mails without item and without body immediately, if starting server
    if (!serverUp)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_EMPTY_EXPIRED_MAIL);
        stmt->setUInt64(0, basetime);
        CharacterDatabase.Execute(stmt);
    }
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_EXPIRED_MAIL);
    stmt->setUInt64(0, basetime);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> No expired mails found.");
        return;                                             // any mails need to be returned or deleted
    }

    std::map<uint32 /*messageId*/, MailItemInfoVec> itemsCache;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_EXPIRED_MAIL_ITEMS);
    stmt->setUInt32(0, (uint32)basetime);
    if (PreparedQueryResult items = CharacterDatabase.Query(stmt))
    {
        MailItemInfo item;
        do
        {
            Field* fields = items->Fetch();
            item.item_guid = fields[0].GetUInt64();
            item.item_template = fields[1].GetUInt32();
            uint32 mailId = fields[2].GetUInt32();
            itemsCache[mailId].push_back(item);
        } while (items->NextRow());
    }

    uint32 deletedCount = 0;
    uint32 returnedCount = 0;
    do
    {
        Field* fields = result->Fetch();
        Mail* m = new Mail;
        m->messageID      = fields[0].GetUInt32();
        m->messageType    = fields[1].GetUInt8();
        m->sender         = fields[2].GetUInt64();
        m->receiver       = fields[3].GetUInt64();
        bool has_items    = fields[4].GetBool();
        m->expire_time    = time_t(fields[5].GetUInt32());
        m->deliver_time   = 0;
        m->COD            = fields[6].GetUInt64();
        m->checked        = fields[7].GetUInt8();
        m->mailTemplateId = fields[8].GetInt16();

        Player* player = NULL;
        if (serverUp)
            player = ObjectAccessor::FindConnectedPlayer(ObjectGuid::Create<HighGuid::Player>(m->receiver));

        if (player && player->m_mailsLoaded)
        {                                                   // this code will run very improbably (the time is between 4 and 5 am, in game is online a player, who has old mail
            // his in mailbox and he has already listed his mails)
            delete m;
            continue;
        }

        // Delete or return mail
        if (has_items)
        {
            // read items from cache
            m->items.swap(itemsCache[m->messageID]);

            // if it is mail from non-player, or if it's already return mail, it shouldn't be returned, but deleted
            if (m->messageType != MAIL_NORMAL || (m->checked & (MAIL_CHECK_MASK_COD_PAYMENT | MAIL_CHECK_MASK_RETURNED)))
            {
                // mail open and then not returned
                for (MailItemInfoVec::iterator itr2 = m->items.begin(); itr2 != m->items.end(); ++itr2)
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
                    stmt->setUInt64(0, itr2->item_guid);
                    CharacterDatabase.Execute(stmt);
                }
            }
            else
            {
                // Mail will be returned
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_RETURNED);
                stmt->setUInt64(0, m->receiver);
                stmt->setUInt64(1, m->sender);
                stmt->setUInt32(2, basetime + 30 * DAY);
                stmt->setUInt32(3, basetime);
                stmt->setUInt8 (4, uint8(MAIL_CHECK_MASK_RETURNED));
                stmt->setUInt32(5, m->messageID);
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
        stmt->setUInt32(0, m->messageID);
        CharacterDatabase.Execute(stmt);
        delete m;
        ++deletedCount;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Processed %u expired mails: %u deleted and %u returned in %u ms", deletedCount + returnedCount, deletedCount, returnedCount, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Area trigger (ID:%u) does not exist in `AreaTrigger.dbc`.", trigger_ID);
            continue;
        }

        Quest const* quest = GetQuestTemplate(quest_ID);

        if (!quest)
        {
            TC_LOG_ERROR("sql.sql", "Table `areatrigger_involvedrelation` has record (id: %u) for not existing quest %u", trigger_ID, quest_ID);
            continue;
        }

        if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT))
        {
            TC_LOG_ERROR("sql.sql", "Table `areatrigger_involvedrelation` has record (id: %u) for not quest %u, but quest not have flag QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT. Trigger or quest flags must be fixed, quest modified to require objective.", trigger_ID, quest_ID);

            // this will prevent quest completing without objective
            const_cast<Quest*>(quest)->SetSpecialFlag(QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT);

            // continue; - quest modified to required objective and trigger can be allowed.
        }

        _questAreaTriggerStore[trigger_ID].insert(quest_ID);

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u quest trigger points in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

QuestGreeting const* ObjectMgr::GetQuestGreeting(ObjectGuid guid) const
{
    auto itr = _questGreetingStore.find(guid.GetTypeId());
    if (itr == _questGreetingStore.end())
        return nullptr;

    auto questItr = itr->second.find(guid.GetEntry());
    if (questItr == itr->second.end())
        return nullptr;

    return questItr->second;
}

void ObjectMgr::LoadQuestGreetings()
{
    uint32 oldMSTime = getMSTime();

    _questGreetingStore.clear(); // need for reload case

    //                                                0   1          2                3
    QueryResult result = WorldDatabase.Query("SELECT ID, type, GreetEmoteType, GreetEmoteDelay, Greeting FROM quest_greeting");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 npc texts, table is empty!");
        return;
    }

    _questGreetingStore.rehash(result->GetRowCount());

    do
    {
        Field* fields = result->Fetch();

        uint32 id                   = fields[0].GetUInt32();
        uint8 type                  = fields[1].GetUInt8();
        // overwrite
        switch (type)
        {
            case 0: // Creature
                type = TYPEID_UNIT;
                if (!sObjectMgr->GetCreatureTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_greeting`: creature template entry %u does not exist.", id);
                    continue;
                }
                break;
            case 1: // GameObject
                type = TYPEID_GAMEOBJECT;
                if (!sObjectMgr->GetGameObjectTemplate(id))
                {
                    TC_LOG_ERROR("sql.sql", "Table `quest_greeting`: gameobject template entry %u does not exist.", id);
                    continue;
                }
                break;
            default:
                continue;
        }

        uint16 greetEmoteType       = fields[2].GetUInt16();
        uint32 greetEmoteDelay      = fields[3].GetUInt32();
        std::string greeting        = fields[4].GetString();

        _questGreetingStore[type][id] = new QuestGreeting(greetEmoteType, greetEmoteDelay, greeting);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u quest_greeting in %u ms", uint32(_questGreetingStore.size()), GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Area trigger (ID:%u) does not exist in `AreaTrigger.dbc`.", Trigger_ID);
            continue;
        }

        _tavernAreaTriggerStore.insert(Trigger_ID);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u tavern triggers in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "AreaTrigger (ID: %u) does not exist in `AreaTrigger.dbc`.", triggerId);
            continue;
        }
        _areaTriggerScriptStore[triggerId] = GetScriptId(scriptName);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " areatrigger scripts in %u ms", _areaTriggerScriptStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

uint32 ObjectMgr::GetNearestTaxiNode(float x, float y, float z, uint32 mapid, uint32 team)
{
    bool found = false;
    float dist = 10000;
    uint32 id = 0;

    uint32 requireFlag = (team == ALLIANCE) ? TAXI_NODE_FLAG_ALLIANCE : TAXI_NODE_FLAG_HORDE;
    for (TaxiNodesEntry const* node : sTaxiNodesStore)
    {
        if (!node || node->MapID != mapid || !(node->Flags & requireFlag))
            continue;

        uint8  field   = (uint8)((node->ID - 1) / 8);
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
    TaxiPathSetBySource::iterator src_i = sTaxiPathSetBySource.find(source);
    if (src_i == sTaxiPathSetBySource.end())
    {
        path = 0;
        cost = 0;
        return;
    }

    TaxiPathSetForSource& pathSet = src_i->second;

    TaxiPathSetForSource::iterator dest_i = pathSet.find(destination);
    if (dest_i == pathSet.end())
    {
        path = 0;
        cost = 0;
        return;
    }

    cost = dest_i->second.price;
    path = dest_i->second.ID;
}

uint32 ObjectMgr::GetTaxiMountDisplayId(uint32 id, uint32 team, bool allowed_alt_team /* = false */)
{
    uint32 mount_id = 0;

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

        CreatureTemplate const* mount_info = GetCreatureTemplate(mount_entry);
        if (mount_info)
        {
            mount_id = mount_info->GetRandomValidModelId();
            if (!mount_id)
            {
                TC_LOG_ERROR("sql.sql", "No displayid found for the taxi mount with the entry %u! Can't load it!", mount_entry);
                return 0;
            }
        }
    }

    // minfo is not actually used but the mount_id was updated
    GetCreatureModelRandomGender(&mount_id);

    return mount_id;
}

void ObjectMgr::LoadGraveyardZones()
{
    uint32 oldMSTime = getMSTime();

    GraveYardStore.clear(); // needed for reload case

    //                                               0   1          2
    QueryResult result = WorldDatabase.Query("SELECT ID, GhostZone, Faction FROM graveyard_zone");

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
        uint32 team   = fields[2].GetUInt16();

        WorldSafeLocsEntry const* entry = sWorldSafeLocsStore.LookupEntry(safeLocId);
        if (!entry)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a record for non-existing graveyard (WorldSafeLocsID: %u), skipped.", safeLocId);
            continue;
        }

        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId);
        if (!areaEntry)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a record for non-existing Zone (ID: %u), skipped.", zoneId);
            continue;
        }

        if (areaEntry->ParentAreaID != 0)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a record for SubZone (ID: %u) instead of zone, skipped.", zoneId);
            continue;
        }

        if (team != 0 && team != HORDE && team != ALLIANCE)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a record for non player faction (%u), skipped.", team);
            continue;
        }

        if (!AddGraveYardLink(safeLocId, zoneId, team, false))
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has a duplicate record for Graveyard (ID: %u) and Zone (ID: %u), skipped.", safeLocId, zoneId);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u graveyard-zone links in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

WorldSafeLocsEntry const* ObjectMgr::GetDefaultGraveYard(uint32 team)
{
    enum DefaultGraveyard
    {
        HORDE_GRAVEYARD    = 10, // Crossroads
        ALLIANCE_GRAVEYARD = 4   // Westfall
    };

    if (team == HORDE)
        return sWorldSafeLocsStore.LookupEntry(HORDE_GRAVEYARD);
    else if (team == ALLIANCE)
        return sWorldSafeLocsStore.LookupEntry(ALLIANCE_GRAVEYARD);
    else return NULL;
}

WorldSafeLocsEntry const* ObjectMgr::GetClosestGraveYard(float x, float y, float z, uint32 MapId, uint32 team)
{
    // search for zone associated closest graveyard
    uint32 zoneId = sMapMgr->GetZoneId(MapId, x, y, z);

    if (!zoneId)
    {
        if (z > -500)
        {
            TC_LOG_ERROR("misc", "ZoneId not found for map %u coords (%f, %f, %f)", MapId, x, y, z);
            return GetDefaultGraveYard(team);
        }
    }

    // Simulate std. algorithm:
    //   found some graveyard associated to (ghost_zone, ghost_map)
    //
    //   if mapId == graveyard.mapId (ghost in plain zone or city or battleground) and search graveyard at same map
    //     then check faction
    //   if mapId != graveyard.mapId (ghost in instance) and search any graveyard associated
    //     then check faction
    GraveYardMapBounds range = GraveYardStore.equal_range(zoneId);
    MapEntry const* map = sMapStore.LookupEntry(MapId);

    // not need to check validity of map object; MapId _MUST_ be valid here
    if (range.first == range.second && !map->IsBattlegroundOrArena())
    {
        if (zoneId != 0) // zone == 0 can't be fixed, used by bliz for bugged zones
            TC_LOG_ERROR("sql.sql", "Table `game_graveyard_zone` incomplete: Zone %u Team %u does not have a linked graveyard.", zoneId, team);
        return GetDefaultGraveYard(team);
    }

    // at corpse map
    bool foundNear = false;
    float distNear = 10000;
    WorldSafeLocsEntry const* entryNear = NULL;

    // at entrance map for corpse map
    bool foundEntr = false;
    float distEntr = 10000;
    WorldSafeLocsEntry const* entryEntr = NULL;

    // some where other
    WorldSafeLocsEntry const* entryFar = NULL;

    MapEntry const* mapEntry = sMapStore.LookupEntry(MapId);

    for (; range.first != range.second; ++range.first)
    {
        GraveYardData const& data = range.first->second;

        WorldSafeLocsEntry const* entry = sWorldSafeLocsStore.LookupEntry(data.safeLocId);
        if (!entry)
        {
            TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` has record for non-existing graveyard (WorldSafeLocsID: %u), skipped.", data.safeLocId);
            continue;
        }

        // skip enemy faction graveyard
        // team == 0 case can be at call from .neargrave
        if (data.team != 0 && team != 0 && data.team != team)
            continue;

        // find now nearest graveyard at other map
        if (MapId != entry->MapID)
        {
            // if find graveyard at different map from where entrance placed (or no entrance data), use any first
            if (!mapEntry
                || mapEntry->CorpseMapID < 0
                || uint32(mapEntry->CorpseMapID) != entry->MapID
                || (mapEntry->CorpsePos.X == 0 && mapEntry->CorpsePos.Y == 0)) // Check X and Y
            {
                // not have any corrdinates for check distance anyway
                entryFar = entry;
                continue;
            }

            // at entrance map calculate distance (2D);
            float dist2 = (entry->Loc.X - mapEntry->CorpsePos.X)*(entry->Loc.X - mapEntry->CorpsePos.X)
                +(entry->Loc.Y - mapEntry->CorpsePos.Y)*(entry->Loc.Y - mapEntry->CorpsePos.Y);
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
            float dist2 = (entry->Loc.X - x)*(entry->Loc.X - x)+(entry->Loc.Y - y)*(entry->Loc.Y - y)+(entry->Loc.Z - z)*(entry->Loc.Z - z);
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

GraveYardData const* ObjectMgr::FindGraveYardData(uint32 id, uint32 zoneId)
{
    GraveYardMapBounds range = GraveYardStore.equal_range(zoneId);
    for (; range.first != range.second; ++range.first)
    {
        GraveYardData const& data = range.first->second;
        if (data.safeLocId == id)
            return &data;
    }
    return NULL;
}

bool ObjectMgr::AddGraveYardLink(uint32 id, uint32 zoneId, uint32 team, bool persist /*= true*/)
{
    if (FindGraveYardData(id, zoneId))
        return false;

    // add link to loaded data
    GraveYardData data;
    data.safeLocId = id;
    data.team = team;

    GraveYardStore.insert(GraveYardContainer::value_type(zoneId, data));

    // add link to DB
    if (persist)
    {
        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_GRAVEYARD_ZONE);

        stmt->setUInt32(0, id);
        stmt->setUInt32(1, zoneId);
        stmt->setUInt16(2, uint16(team));

        WorldDatabase.Execute(stmt);
    }

    return true;
}

void ObjectMgr::RemoveGraveYardLink(uint32 id, uint32 zoneId, uint32 team, bool persist /*= false*/)
{
    GraveYardMapBoundsNonConst range = GraveYardStore.equal_range(zoneId);
    if (range.first == range.second)
    {
        //TC_LOG_ERROR("sql.sql", "Table `graveyard_zone` incomplete: Zone %u Team %u does not have a linked graveyard.", zoneId, team);
        return;
    }

    bool found = false;


    for (; range.first != range.second; ++range.first)
    {
        GraveYardData & data = range.first->second;

        // skip not matching safezone id
        if (data.safeLocId != id)
            continue;

        // skip enemy faction graveyard at same map (normal area, city, or battleground)
        // team == 0 case can be at call from .neargrave
        if (data.team != 0 && team != 0 && data.team != team)
            continue;

        found = true;
        break;
    }

    // no match, return
    if (!found)
        return;

    // remove from links
    GraveYardStore.erase(range.first);

    // remove link from DB
    if (persist)
    {
        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GRAVEYARD_ZONE);

        stmt->setUInt32(0, id);
        stmt->setUInt32(1, zoneId);
        stmt->setUInt16(2, uint16(team));

        WorldDatabase.Execute(stmt);
    }
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

        WorldSafeLocsEntry const* portLoc = sWorldSafeLocsStore.LookupEntry(PortLocID);
        if (!portLoc)
        {
            TC_LOG_ERROR("sql.sql", "Area Trigger (ID: %u) has a non-existing Port Loc (ID: %u) in WorldSafeLocs.dbc, skipped", Trigger_ID, PortLocID);
            continue;
        }

        AreaTriggerStruct at;

        at.target_mapId       = portLoc->MapID;
        at.target_X           = portLoc->Loc.X;
        at.target_Y           = portLoc->Loc.Y;
        at.target_Z           = portLoc->Loc.Z;
        at.target_Orientation = (portLoc->Facing * M_PI) / 180; // Orientation is initially in degrees

        AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(Trigger_ID);
        if (!atEntry)
        {
            TC_LOG_ERROR("sql.sql", "Area Trigger (ID: %u) does not exist in AreaTrigger.dbc.", Trigger_ID);
            continue;
        }

        _areaTriggerStore[Trigger_ID] = at;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u area trigger teleport definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadAccessRequirements()
{
    uint32 oldMSTime = getMSTime();

    if (!_accessRequirementStore.empty())
    {
        for (AccessRequirementContainer::iterator itr = _accessRequirementStore.begin(); itr != _accessRequirementStore.end(); ++itr)
            delete itr->second;

        _accessRequirementStore.clear();                                  // need for reload case
    }

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
            TC_LOG_ERROR("sql.sql", "Map %u referenced in `access_requirement` does not exist, skipped.", mapid);
            continue;
        }

        uint32 difficulty = fields[1].GetUInt8();
        if (!GetMapDifficultyData(mapid, Difficulty(difficulty)))
        {
            TC_LOG_ERROR("sql.sql", "Map %u referenced in `access_requirement` does not have difficulty %u, skipped", mapid, difficulty);
            continue;
        }

        uint64 requirement_ID = MAKE_PAIR64(mapid, difficulty);

        AccessRequirement* ar   = new AccessRequirement();
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
                TC_LOG_ERROR("sql.sql", "Key item %u does not exist for map %u difficulty %u, removing key requirement.", ar->item, mapid, difficulty);
                ar->item = 0;
            }
        }

        if (ar->item2)
        {
            ItemTemplate const* pProto = GetItemTemplate(ar->item2);
            if (!pProto)
            {
                TC_LOG_ERROR("sql.sql", "Second item %u does not exist for map %u difficulty %u, removing key requirement.", ar->item2, mapid, difficulty);
                ar->item2 = 0;
            }
        }

        if (ar->quest_A)
        {
            if (!GetQuestTemplate(ar->quest_A))
            {
                TC_LOG_ERROR("sql.sql", "Required Alliance Quest %u not exist for map %u difficulty %u, remove quest done requirement.", ar->quest_A, mapid, difficulty);
                ar->quest_A = 0;
            }
        }

        if (ar->quest_H)
        {
            if (!GetQuestTemplate(ar->quest_H))
            {
                TC_LOG_ERROR("sql.sql", "Required Horde Quest %u not exist for map %u difficulty %u, remove quest done requirement.", ar->quest_H, mapid, difficulty);
                ar->quest_H = 0;
            }
        }

        if (ar->achievement)
        {
            if (!sAchievementStore.LookupEntry(ar->achievement))
            {
                TC_LOG_ERROR("sql.sql", "Required Achievement %u not exist for map %u difficulty %u, remove quest done requirement.", ar->achievement, mapid, difficulty);
                ar->achievement = 0;
            }
        }

        _accessRequirementStore[requirement_ID] = ar;
        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u access requirement definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

/*
 * Searches for the areatrigger which teleports players out of the given map with instance_template.parent field support
 */
AreaTriggerStruct const* ObjectMgr::GetGoBackTrigger(uint32 Map) const
{
    bool useParentDbValue = false;
    uint32 parentId = 0;
    const MapEntry* mapEntry = sMapStore.LookupEntry(Map);
    if (!mapEntry || mapEntry->CorpseMapID < 0)
        return NULL;

    if (mapEntry->IsDungeon())
    {
        const InstanceTemplate* iTemplate = sObjectMgr->GetInstanceTemplate(Map);

        if (!iTemplate)
            return NULL;

        parentId = iTemplate->Parent;
        useParentDbValue = true;
    }

    uint32 entrance_map = uint32(mapEntry->CorpseMapID);
    for (AreaTriggerContainer::const_iterator itr = _areaTriggerStore.begin(); itr != _areaTriggerStore.end(); ++itr)
        if ((!useParentDbValue && itr->second.target_mapId == entrance_map) || (useParentDbValue && itr->second.target_mapId == parentId))
        {
            AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(itr->first);
            if (atEntry && atEntry->MapID == Map)
                return &itr->second;
        }
    return NULL;
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
    return NULL;
}

void ObjectMgr::SetHighestGuids()
{
    QueryResult result = CharacterDatabase.Query("SELECT MAX(guid) FROM characters");
    if (result)
        GetGuidSequenceGenerator<HighGuid::Player>().Set((*result)[0].GetUInt64() + 1);

    result = CharacterDatabase.Query("SELECT MAX(guid) FROM item_instance");
    if (result)
        GetGuidSequenceGenerator<HighGuid::Item>().Set((*result)[0].GetUInt64() + 1);

    // Cleanup other tables from nonexistent guids ( >= _hiItemGuid)
    CharacterDatabase.PExecute("DELETE FROM character_inventory WHERE item >= '%u'", GetGuidSequenceGenerator<HighGuid::Item>().GetNextAfterMaxUsed());    // One-time query
    CharacterDatabase.PExecute("DELETE FROM mail_items WHERE item_guid >= '%u'", GetGuidSequenceGenerator<HighGuid::Item>().GetNextAfterMaxUsed());        // One-time query
    CharacterDatabase.PExecute("DELETE FROM auctionhouse WHERE itemguid >= '%u'", GetGuidSequenceGenerator<HighGuid::Item>().GetNextAfterMaxUsed());       // One-time query
    CharacterDatabase.PExecute("DELETE FROM guild_bank_item WHERE item_guid >= '%u'", GetGuidSequenceGenerator<HighGuid::Item>().GetNextAfterMaxUsed());   // One-time query

    result = WorldDatabase.Query("SELECT MAX(guid) FROM transports");
    if (result)
        GetGuidSequenceGenerator<HighGuid::Transport>().Set((*result)[0].GetUInt64() + 1);

    result = CharacterDatabase.Query("SELECT MAX(id) FROM auctionhouse");
    if (result)
        _auctionId = (*result)[0].GetUInt32()+1;

    result = CharacterDatabase.Query("SELECT MAX(id) FROM mail");
    if (result)
        _mailId = (*result)[0].GetUInt32()+1;

    result = CharacterDatabase.Query("SELECT MAX(arenateamid) FROM arena_team");
    if (result)
        sArenaTeamMgr->SetNextArenaTeamId((*result)[0].GetUInt32()+1);

    result = CharacterDatabase.Query("SELECT MAX(setguid) FROM character_equipmentsets");
    if (result)
        _equipmentSetGuid = (*result)[0].GetUInt64()+1;

    result = CharacterDatabase.Query("SELECT MAX(guildId) FROM guild");
    if (result)
        sGuildMgr->SetNextGuildId((*result)[0].GetUInt64()+1);

    result = CharacterDatabase.Query("SELECT MAX(guid) FROM groups");
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

uint32 ObjectMgr::GenerateAuctionID()
{
    if (_auctionId >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR("misc", "Auctions ids overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _auctionId++;
}

uint64 ObjectMgr::GenerateEquipmentSetGuid()
{
    if (_equipmentSetGuid >= uint64(0xFFFFFFFFFFFFFFFELL))
    {
        TC_LOG_ERROR("misc", "EquipmentSet guid overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _equipmentSetGuid++;
}

uint32 ObjectMgr::GenerateMailID()
{
    if (_mailId >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR("misc", "Mail ids overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _mailId++;
}

uint32 ObjectMgr::GeneratePetNumber()
{
    if (_hiPetNumber >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR("misc", "_hiPetNumber Id overflow!! Can't continue, shutting down server. ");
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
        TC_LOG_ERROR("misc", "Creature spawn id overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return _creatureSpawnId++;
}

uint64 ObjectMgr::GenerateGameObjectSpawnId()
{
    if (_gameObjectSpawnId >= uint64(0xFFFFFFFFFFFFFFFELL))
    {
        TC_LOG_ERROR("misc", "Creature spawn id overflow!! Can't continue, shutting down server. ");
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
        std::string localeName      = fields[1].GetString();

        std::string name            = fields[2].GetString();
        std::string castBarCaption  = fields[3].GetString();
        std::string unk1            = fields[4].GetString();

        GameObjectLocale& data = _gameObjectLocaleStore[id];
        LocaleConstant locale = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        AddLocaleString(name, locale, data.Name);
        AddLocaleString(castBarCaption, locale, data.CastBarCaption);
        AddLocaleString(unk1, locale, data.Unk1);

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u gameobject_template_locale strings in %u ms", uint32(_gameObjectLocaleStore.size()), GetMSTimeDiffToNow(oldMSTime));
}

inline void CheckGOLockId(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    if (sLockStore.LookupEntry(dataN))
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u GoType: %u) have data%d=%u but lock (Id: %u) not found.",
        goInfo->entry, goInfo->type, N, goInfo->door.open, goInfo->door.open);
}

inline void CheckGOLinkedTrapId(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    if (GameObjectTemplate const* trapInfo = sObjectMgr->GetGameObjectTemplate(dataN))
    {
        if (trapInfo->type != GAMEOBJECT_TYPE_TRAP)
            TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u GoType: %u) have data%d=%u but GO (Entry %u) have not GAMEOBJECT_TYPE_TRAP (%u) type.",
            goInfo->entry, goInfo->type, N, dataN, dataN, GAMEOBJECT_TYPE_TRAP);
    }
}

inline void CheckGOSpellId(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    if (sSpellMgr->GetSpellInfo(dataN))
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u GoType: %u) have data%d=%u but Spell (Entry %u) not exist.",
        goInfo->entry, goInfo->type, N, dataN, dataN);
}

inline void CheckAndFixGOChairHeightId(GameObjectTemplate const* goInfo, uint32& dataN, uint32 N)
{
    if (dataN <= (UNIT_STAND_STATE_SIT_HIGH_CHAIR-UNIT_STAND_STATE_SIT_LOW_CHAIR))
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u GoType: %u) have data%d=%u but correct chair height in range 0..%i.",
        goInfo->entry, goInfo->type, N, dataN, UNIT_STAND_STATE_SIT_HIGH_CHAIR-UNIT_STAND_STATE_SIT_LOW_CHAIR);

    // prevent client and server unexpected work
    dataN = 0;
}

inline void CheckGONoDamageImmuneId(GameObjectTemplate* goTemplate, uint32 dataN, uint32 N)
{
    // 0/1 correct values
    if (dataN <= 1)
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u GoType: %u) have data%d=%u but expected boolean (0/1) noDamageImmune field value.", goTemplate->entry, goTemplate->type, N, dataN);
}

inline void CheckGOConsumable(GameObjectTemplate const* goInfo, uint32 dataN, uint32 N)
{
    // 0/1 correct values
    if (dataN <= 1)
        return;

    TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u GoType: %u) have data%d=%u but expected boolean (0/1) consumable field value.",
        goInfo->entry, goInfo->type, N, dataN);
}

void ObjectMgr::LoadGameObjectTemplate()
{
    uint32 oldMSTime = getMSTime();

    for (GameObjectsEntry const* db2go : sGameObjectsStore)
    {
        GameObjectTemplate& go = _gameObjectTemplateStore[db2go->ID];
        go.entry = db2go->ID;
        go.type = db2go->Type;
        go.displayId = db2go->DisplayID;
        go.name = db2go->Name->Str[sWorld->GetDefaultDbcLocale()];
        go.faction = 0;
        go.flags = 0;
        go.size = db2go->Size;
        memset(go.raw.data, 0, sizeof(go.raw.data));
        memcpy(go.raw.data, db2go->Data, std::min(sizeof(db2go->Data), sizeof(go.raw.data)));
        go.unkInt32 = 0;
        go.ScriptId = 0;
    }

    //                                               0      1     2          3     4         5               6     7        8      9
    QueryResult result = WorldDatabase.Query("SELECT entry, type, displayId, name, IconName, castBarCaption, unk1, faction, flags, size, "
    //                                        10     11     12     13     14     15     16     17     18     19     20      21      22
                                             "Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Data8, Data9, Data10, Data11, Data12, "
    //                                        23      24      25      26      27      28      29      30      31      32      33      34      35      36      37      38
                                             "Data13, Data14, Data15, Data16, Data17, Data18, Data19, Data20, Data21, Data22, Data23, Data24, Data25, Data26, Data27, Data28, "
    //                                        39      40       41     42      43        44      45
                                             "Data29, Data30, Data31, Data32, unkInt32, AIName, ScriptName "
                                             "FROM gameobject_template");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 gameobject definitions. DB table `gameobject_template` is empty.");
        return;
    }

    _gameObjectTemplateStore.rehash(result->GetRowCount());
    uint32 count = 0;
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
        got.faction        = uint32(fields[7].GetUInt16());
        got.flags          = fields[8].GetUInt32();
        got.size           = fields[9].GetFloat();

        for (uint8 i = 0; i < MAX_GAMEOBJECT_DATA; ++i)
            got.raw.data[i] = fields[10 + i].GetUInt32();

        got.unkInt32 = fields[43].GetInt32();
        got.AIName = fields[44].GetString();
        got.ScriptId = GetScriptId(fields[45].GetString());

        // Checks

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
                        TC_LOG_ERROR("sql.sql", "GameObject (Entry: %u GoType: %u) have data0=%u but SpellFocus (Id: %u) not exist.",
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
                        TC_LOG_ERROR("sql.sql", "GameObject (Entry: %u GoType: %u) have data7=%u but PageText (Entry %u) not exist.",
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
                        TC_LOG_ERROR("sql.sql", "GameObject (Entry: %u GoType: %u) have data0=%u but TaxiPath (Id: %u) not exist.",
                            entry, got.type, got.moTransport.taxiPathID, got.moTransport.taxiPathID);
                }
                if (uint32 transportMap = got.moTransport.mapID)
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
                    TC_LOG_ERROR("sql.sql", "GameObject (Entry: %u GoType: %u) have data2 = %u but AnimKit.dbc (Id: %u) not exist, set to 0.",
                       entry, got.type, got.barberChair.SitAnimKit, got.barberChair.SitAnimKit);
                    got.barberChair.SitAnimKit = 0;
                }
                break;
            case GAMEOBJECT_TYPE_GARRISON_BUILDING:
                if (uint32 transportMap = got.garrisonBuilding.mapID)
                    _transportMaps.insert(transportMap);
                break;
        }

       ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u game object templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadExplorationBaseXP()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT level, basexp FROM exploration_basexp");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 BaseXP definitions. DB table `exploration_basexp` is empty.");
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

    TC_LOG_INFO("server.loading", ">> Loaded %u BaseXP definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

    TC_LOG_INFO("server.loading", ">> Loaded %u pet name parts in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

    TC_LOG_INFO("server.loading", ">> Loaded the max pet number: %d in %u ms", _hiPetNumber-1, GetMSTimeDiffToNow(oldMSTime));
}

std::string ObjectMgr::GeneratePetName(uint32 entry)
{
    StringVector& list0 = _petHalfName0[entry];
    StringVector& list1 = _petHalfName1[entry];

    if (list0.empty() || list1.empty())
    {
        CreatureTemplate const* cinfo = GetCreatureTemplate(entry);
        if (!cinfo)
            return std::string();

        char const* petname = GetCreatureFamilyPetName(cinfo->family, sWorld->GetDefaultDbcLocale());
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
        TC_LOG_ERROR("server.loading", ">> Loaded `reputation_reward_rate`, table is empty!");
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
            TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) %u does not exist but is used in `reputation_reward_rate`", factionId);
            continue;
        }

        if (repRate.questRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_rate with invalid rate %f, skipping data for faction %u", repRate.questRate, factionId);
            continue;
        }

        if (repRate.questDailyRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_daily_rate with invalid rate %f, skipping data for faction %u", repRate.questDailyRate, factionId);
            continue;
        }

        if (repRate.questWeeklyRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_weekly_rate with invalid rate %f, skipping data for faction %u", repRate.questWeeklyRate, factionId);
            continue;
        }

        if (repRate.questMonthlyRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_monthly_rate with invalid rate %f, skipping data for faction %u", repRate.questMonthlyRate, factionId);
            continue;
        }

        if (repRate.questRepeatableRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has quest_repeatable_rate with invalid rate %f, skipping data for faction %u", repRate.questRepeatableRate, factionId);
            continue;
        }

        if (repRate.creatureRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has creature_rate with invalid rate %f, skipping data for faction %u", repRate.creatureRate, factionId);
            continue;
        }

        if (repRate.spellRate < 0.0f)
        {
            TC_LOG_ERROR("sql.sql", "Table reputation_reward_rate has spell_rate with invalid rate %f, skipping data for faction %u", repRate.spellRate, factionId);
            continue;
        }

        _repRewardRateStore[factionId] = repRate;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u reputation_reward_rate in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
        TC_LOG_ERROR("server.loading", ">> Loaded 0 creature award reputation definitions. DB table `creature_onkill_reputation` is empty.");
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
            TC_LOG_ERROR("sql.sql", "Table `creature_onkill_reputation` has data for nonexistent creature entry (%u), skipped", creature_id);
            continue;
        }

        if (repOnKill.RepFaction1)
        {
            FactionEntry const* factionEntry1 = sFactionStore.LookupEntry(repOnKill.RepFaction1);
            if (!factionEntry1)
            {
                TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) %u does not exist but is used in `creature_onkill_reputation`", repOnKill.RepFaction1);
                continue;
            }
        }

        if (repOnKill.RepFaction2)
        {
            FactionEntry const* factionEntry2 = sFactionStore.LookupEntry(repOnKill.RepFaction2);
            if (!factionEntry2)
            {
                TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) %u does not exist but is used in `creature_onkill_reputation`", repOnKill.RepFaction2);
                continue;
            }
        }

        _repOnKillStore[creature_id] = repOnKill;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature award reputation definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) %u does not exist but is used in `reputation_spillover_template`", factionId);
            continue;
        }

        if (factionEntry->ParentFactionID == 0)
        {
            TC_LOG_ERROR("sql.sql", "Faction (faction.dbc) %u in `reputation_spillover_template` does not belong to any team, skipping", factionId);
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
                    TC_LOG_ERROR("sql.sql", "Spillover faction (faction.dbc) %u does not exist but is used in `reputation_spillover_template` for faction %u, skipping", repTemplate.faction[i], factionId);
                    invalidSpilloverFaction = true;
                    break;
                }

                if (!factionSpillover->CanHaveReputation())
                {
                    TC_LOG_ERROR("sql.sql", "Spillover faction (faction.dbc) %u for faction %u in `reputation_spillover_template` can not be listed for client, and then useless, skipping", repTemplate.faction[i], factionId);
                    invalidSpilloverFaction = true;
                    break;
                }

                if (repTemplate.faction_rank[i] >= MAX_REPUTATION_RANK)
                {
                    TC_LOG_ERROR("sql.sql", "Rank %u used in `reputation_spillover_template` for spillover faction %u is not valid, skipping", repTemplate.faction_rank[i], repTemplate.faction[i]);
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

    TC_LOG_INFO("server.loading", ">> Loaded %u reputation_spillover_template in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadPointsOfInterest()
{
    uint32 oldMSTime = getMSTime();

    _pointsOfInterestStore.clear(); // need for reload case

    uint32 count = 0;

    //                                               0   1          2          3     4      5           6
    QueryResult result = WorldDatabase.Query("SELECT ID, PositionX, PositionY, Icon, Flags, Importance, Name FROM points_of_interest");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 Points of Interest definitions. DB table `points_of_interest` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();

        PointOfInterest pointOfInterest;
        pointOfInterest.ID              = id;
        pointOfInterest.Pos.x           = fields[1].GetFloat();
        pointOfInterest.Pos.y           = fields[2].GetFloat();
        pointOfInterest.Icon            = fields[3].GetUInt32();
        pointOfInterest.Flags           = fields[4].GetUInt32();
        pointOfInterest.Importance      = fields[5].GetUInt32();
        pointOfInterest.Name            = fields[6].GetString();

        if (!Trinity::IsValidMapCoord(pointOfInterest.Pos.x, pointOfInterest.Pos.y))
        {
            TC_LOG_ERROR("sql.sql", "Table `points_of_interest` (ID: %u) have invalid coordinates (PositionX: %f PositionY: %f), ignored.", id, pointOfInterest.Pos.x, pointOfInterest.Pos.y);
            continue;
        }

        _pointsOfInterestStore[id] = pointOfInterest;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Points of Interest definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadQuestPOI()
{
    uint32 oldMSTime = getMSTime();

    _questPOIStore.clear(); // need for reload case

    uint32 count = 0;

    //                                                   0        1        2            3           4                 5           6         7            8       9       10         11              12             13
    QueryResult result = WorldDatabase.Query("SELECT QuestID, BlobIndex, Idx1, ObjectiveIndex, QuestObjectiveID, QuestObjectID, MapID, WorldMapAreaId, Floor, Priority, Flags, WorldEffectID, PlayerConditionID, WoDUnk1 FROM quest_poi order by QuestID, Idx1");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest POI definitions. DB table `quest_poi` is empty.");
        return;
    }

    //                                                0        1    2  3
    QueryResult points = WorldDatabase.Query("SELECT QuestID, Idx1, X, Y FROM quest_poi_points ORDER BY QuestID DESC, Idx1, Idx2");

    std::vector<std::vector<std::vector<QuestPOIPoint>>> POIs;

    if (points)
    {
        // The first result should have the highest questId
        Field* fields = points->Fetch();
        uint32 questIdMax = fields[0].GetInt32();
        POIs.resize(questIdMax + 1);

        do
        {
            fields = points->Fetch();

            int32 QuestID             = fields[0].GetInt32();
            int32 Idx1                = fields[1].GetInt32();
            int32 X                   = fields[2].GetInt32();
            int32 Y                   = fields[3].GetInt32();

            if (int32(POIs[QuestID].size()) <= Idx1 + 1)
                POIs[QuestID].resize(Idx1 + 10);

            QuestPOIPoint point(X, Y);
            POIs[QuestID][Idx1].push_back(point);
        } while (points->NextRow());
    }

    do
    {
        Field* fields = result->Fetch();

        int32 QuestID               = fields[0].GetInt32();
        int32 BlobIndex             = fields[1].GetInt32();
        int32 Idx1                  = fields[2].GetInt32();
        int32 ObjectiveIndex        = fields[3].GetInt32();
        int32 QuestObjectiveID      = fields[4].GetInt32();
        int32 QuestObjectID         = fields[5].GetInt32();
        int32 MapID                 = fields[6].GetInt32();
        int32 WorldMapAreaId        = fields[7].GetInt32();
        int32 Floor                 = fields[8].GetInt32();
        int32 Priority              = fields[9].GetInt32();
        int32 Flags                 = fields[10].GetInt32();
        int32 WorldEffectID         = fields[11].GetInt32();
        int32 PlayerConditionID     = fields[12].GetInt32();
        int32 WoDUnk1               = fields[13].GetInt32();

        if (!sObjectMgr->GetQuestTemplate(QuestID))
            TC_LOG_ERROR("sql.sql", "`quest_poi` quest id (%u) Idx1 (%u) does not exist in `quest_template`", QuestID, Idx1);

        QuestPOI POI(BlobIndex, ObjectiveIndex, QuestObjectiveID, QuestObjectID, MapID, WorldMapAreaId, Floor, Priority, Flags, WorldEffectID, PlayerConditionID, WoDUnk1);
        if (QuestID < int32(POIs.size()) && Idx1 < int32(POIs[QuestID].size()))
        {
            POI.points = POIs[QuestID][Idx1];
            _questPOIStore[QuestID].push_back(POI);
        }
        else
            TC_LOG_ERROR("server.loading", "Table quest_poi references unknown quest points for quest %i POI id %i", QuestID, BlobIndex);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u quest POI definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadNPCSpellClickSpells()
{
    uint32 oldMSTime = getMSTime();

    _spellClickInfoStore.clear();
    //                                                0          1         2            3
    QueryResult result = WorldDatabase.Query("SELECT npc_entry, spell_id, cast_flags, user_type FROM npc_spellclick_spells");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 spellclick spells. DB table `npc_spellclick_spells` is empty.");
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
            TC_LOG_ERROR("sql.sql", "Table npc_spellclick_spells references unknown creature_template %u. Skipping entry.", npc_entry);
            continue;
        }

        uint32 spellid = fields[1].GetUInt32();
        SpellInfo const* spellinfo = sSpellMgr->GetSpellInfo(spellid);
        if (!spellinfo)
        {
            TC_LOG_ERROR("sql.sql", "Table npc_spellclick_spells creature: %u references unknown spellid %u. Skipping entry.", npc_entry, spellid);
            continue;
        }

        uint8 userType = fields[3].GetUInt16();
        if (userType >= SPELL_CLICK_USER_MAX)
            TC_LOG_ERROR("sql.sql", "Table npc_spellclick_spells creature: %u  references unknown user type %u. Skipping entry.", npc_entry, uint32(userType));

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
    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        if ((itr->second.npcflag & UNIT_NPC_FLAG_SPELLCLICK) && _spellClickInfoStore.find(itr->second.Entry) == _spellClickInfoStore.end())
        {
            TC_LOG_ERROR("sql.sql", "npc_spellclick_spells: Creature template %u has UNIT_NPC_FLAG_SPELLCLICK but no data in spellclick table! Removing flag", itr->second.Entry);
            const_cast<CreatureTemplate*>(&itr->second)->npcflag &= ~UNIT_NPC_FLAG_SPELLCLICK;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spellclick definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::DeleteCreatureData(ObjectGuid::LowType guid)
{
    // remove mapid*cellid -> guid_set map
    CreatureData const* data = GetCreatureData(guid);
    if (data)
        RemoveCreatureFromGrid(guid, data);

    _creatureDataStore.erase(guid);
}

void ObjectMgr::DeleteGOData(ObjectGuid::LowType guid)
{
    // remove mapid*cellid -> guid_set map
    GameObjectData const* data = GetGOData(guid);
    if (data)
        RemoveGameobjectFromGrid(guid, data);

    _gameObjectDataStore.erase(guid);
}

void ObjectMgr::LoadQuestRelationsHelper(QuestRelations& map, QuestRelationsReverse* reverseMap, std::string const& table, bool starter, bool go)
{
    uint32 oldMSTime = getMSTime();

    map.clear();                                            // need for reload case

    uint32 count = 0;

    QueryResult result = WorldDatabase.PQuery("SELECT id, quest, pool_entry FROM %s qr LEFT JOIN pool_quest pq ON qr.quest = pq.entry", table.c_str());

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 quest relations from `%s`, table is empty.", table.c_str());
        return;
    }

    PooledQuestRelation* poolRelationMap = go ? &sPoolMgr->mQuestGORelation : &sPoolMgr->mQuestCreatureRelation;
    if (starter)
        poolRelationMap->clear();

    do
    {
        uint32 id     = result->Fetch()[0].GetUInt32();
        uint32 quest  = result->Fetch()[1].GetUInt32();
        uint32 poolId = result->Fetch()[2].GetUInt32();

        if (_questTemplates.find(quest) == _questTemplates.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `%s`: Quest %u listed for entry %u does not exist.", table.c_str(), quest, id);
            continue;
        }

        if (!poolId || !starter)
        {
            map.insert(QuestRelations::value_type(id, quest));
            if (reverseMap)
                reverseMap->insert(QuestRelationsReverse::value_type(quest, id));
        }
        else if (starter)
            poolRelationMap->insert(PooledQuestRelation::value_type(quest, id));

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u quest relations from %s in %u ms", count, table.c_str(), GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGameobjectQuestStarters()
{
    LoadQuestRelationsHelper(_goQuestRelations, nullptr, "gameobject_queststarter", true, true);

    for (QuestRelations::iterator itr = _goQuestRelations.begin(); itr != _goQuestRelations.end(); ++itr)
    {
        GameObjectTemplate const* goInfo = GetGameObjectTemplate(itr->first);
        if (!goInfo)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_queststarter` has data for nonexistent gameobject entry (%u) and existed quest %u", itr->first, itr->second);
        else if (goInfo->type != GAMEOBJECT_TYPE_QUESTGIVER)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_queststarter` has data gameobject entry (%u) for quest %u, but GO is not GAMEOBJECT_TYPE_QUESTGIVER", itr->first, itr->second);
    }
}

void ObjectMgr::LoadGameobjectQuestEnders()
{
    LoadQuestRelationsHelper(_goQuestInvolvedRelations, &_goQuestInvolvedRelationsReverse, "gameobject_questender", false, true);

    for (QuestRelations::iterator itr = _goQuestInvolvedRelations.begin(); itr != _goQuestInvolvedRelations.end(); ++itr)
    {
        GameObjectTemplate const* goInfo = GetGameObjectTemplate(itr->first);
        if (!goInfo)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questender` has data for nonexistent gameobject entry (%u) and existed quest %u", itr->first, itr->second);
        else if (goInfo->type != GAMEOBJECT_TYPE_QUESTGIVER)
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questender` has data gameobject entry (%u) for quest %u, but GO is not GAMEOBJECT_TYPE_QUESTGIVER", itr->first, itr->second);
    }
}

void ObjectMgr::LoadCreatureQuestStarters()
{
    LoadQuestRelationsHelper(_creatureQuestRelations, nullptr, "creature_queststarter", true, false);

    for (QuestRelations::iterator itr = _creatureQuestRelations.begin(); itr != _creatureQuestRelations.end(); ++itr)
    {
        CreatureTemplate const* cInfo = GetCreatureTemplate(itr->first);
        if (!cInfo)
            TC_LOG_ERROR("sql.sql", "Table `creature_queststarter` has data for nonexistent creature entry (%u) and existed quest %u", itr->first, itr->second);
        else if (!(cInfo->npcflag & UNIT_NPC_FLAG_QUESTGIVER))
            TC_LOG_ERROR("sql.sql", "Table `creature_queststarter` has creature entry (%u) for quest %u, but npcflag does not include UNIT_NPC_FLAG_QUESTGIVER", itr->first, itr->second);
    }
}

void ObjectMgr::LoadCreatureQuestEnders()
{
    LoadQuestRelationsHelper(_creatureQuestInvolvedRelations, &_creatureQuestInvolvedRelationsReverse, "creature_questender", false, false);

    for (QuestRelations::iterator itr = _creatureQuestInvolvedRelations.begin(); itr != _creatureQuestInvolvedRelations.end(); ++itr)
    {
        CreatureTemplate const* cInfo = GetCreatureTemplate(itr->first);
        if (!cInfo)
            TC_LOG_ERROR("sql.sql", "Table `creature_questender` has data for nonexistent creature entry (%u) and existed quest %u", itr->first, itr->second);
        else if (!(cInfo->npcflag & UNIT_NPC_FLAG_QUESTGIVER))
            TC_LOG_ERROR("sql.sql", "Table `creature_questender` has creature entry (%u) for quest %u, but npcflag does not include UNIT_NPC_FLAG_QUESTGIVER", itr->first, itr->second);
    }
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
            TC_LOG_ERROR("misc", "Table `reserved_name` has invalid name: %s", name.c_str());
            continue;
        }

        wstrToLower(wstr);

        _reservedNamesStore.insert(wstr);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u reserved player names in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::IsReservedName(const std::string& name) const
{
    std::wstring wstr;
    if (!Utf8toWStr (name, wstr))
        return false;

    wstrToLower(wstr);

    return _reservedNamesStore.find(wstr) != _reservedNamesStore.end();
}

enum LanguageType
{
    LT_BASIC_LATIN    = 0x0000,
    LT_EXTENDEN_LATIN = 0x0001,
    LT_CYRILLIC       = 0x0002,
    LT_EAST_ASIA      = 0x0004,
    LT_ANY            = 0xFFFF
};

static LanguageType GetRealmLanguageType(bool create)
{
    switch (sWorld->getIntConfig(CONFIG_REALM_ZONE))
    {
        case REALM_ZONE_UNKNOWN:                            // any language
        case REALM_ZONE_DEVELOPMENT:
        case REALM_ZONE_TEST_SERVER:
        case REALM_ZONE_QA_SERVER:
            return LT_ANY;
        case REALM_ZONE_UNITED_STATES:                      // extended-Latin
        case REALM_ZONE_OCEANIC:
        case REALM_ZONE_LATIN_AMERICA:
        case REALM_ZONE_ENGLISH:
        case REALM_ZONE_GERMAN:
        case REALM_ZONE_FRENCH:
        case REALM_ZONE_SPANISH:
            return LT_EXTENDEN_LATIN;
        case REALM_ZONE_KOREA:                              // East-Asian
        case REALM_ZONE_TAIWAN:
        case REALM_ZONE_CHINA:
            return LT_EAST_ASIA;
        case REALM_ZONE_RUSSIAN:                            // Cyrillic
            return LT_CYRILLIC;
        default:
            return create ? LT_BASIC_LATIN : LT_ANY;        // basic-Latin at create, any at login
    }
}

bool isValidString(const std::wstring& wstr, uint32 strictMask, bool numericOrSpace, bool create = false)
{
    if (strictMask == 0)                                       // any language, ignore realm
    {
        if (isExtendedLatinString(wstr, numericOrSpace))
            return true;
        if (isCyrillicString(wstr, numericOrSpace))
            return true;
        if (isEastAsianString(wstr, numericOrSpace))
            return true;
        return false;
    }

    if (strictMask & 0x2)                                    // realm zone specific
    {
        LanguageType lt = GetRealmLanguageType(create);
        if (lt & LT_EXTENDEN_LATIN)
            if (isExtendedLatinString(wstr, numericOrSpace))
                return true;
        if (lt & LT_CYRILLIC)
            if (isCyrillicString(wstr, numericOrSpace))
                return true;
        if (lt & LT_EAST_ASIA)
            if (isEastAsianString(wstr, numericOrSpace))
                return true;
    }

    if (strictMask & 0x1)                                    // basic Latin
    {
        if (isBasicLatinString(wstr, numericOrSpace))
            return true;
    }

    return false;
}

ResponseCodes ObjectMgr::CheckPlayerName(std::string const& name, LocaleConstant locale, bool create /*= false*/)
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

    return sDB2Manager.ValidateName(name, locale);
}

bool ObjectMgr::IsValidCharterName(const std::string& name)
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

PetNameInvalidReason ObjectMgr::CheckPetName(const std::string& name)
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

    if (sObjectMgr->GetGameObjectTemplates()->empty())
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 GameObjects for quests");
        return;
    }

    uint32 count = 0;

    // collect GO entries for GO that must activated
    GameObjectTemplateContainer const* gotc = sObjectMgr->GetGameObjectTemplates();
    for (GameObjectTemplateContainer::const_iterator itr = gotc->begin(); itr != gotc->end(); ++itr)
    {
        switch (itr->second.type)
        {
            case GAMEOBJECT_TYPE_QUESTGIVER:
                _gameObjectForQuestStore.insert(itr->second.entry);
                ++count;
                break;
            case GAMEOBJECT_TYPE_CHEST:
            {
                // scan GO chest with loot including quest items
                uint32 loot_id = (itr->second.GetLootId());

                // find quest loot for GO
                if (itr->second.chest.questID || LootTemplates_Gameobject.HaveQuestLootFor(loot_id))
                {
                    _gameObjectForQuestStore.insert(itr->second.entry);
                    ++count;
                }
                break;
            }
            case GAMEOBJECT_TYPE_GENERIC:
            {
                if (itr->second.generic.questID > 0)            //quests objects
                {
                    _gameObjectForQuestStore.insert(itr->second.entry);
                    ++count;
                }
                break;
            }
            case GAMEOBJECT_TYPE_GOOBER:
            {
                if (itr->second.goober.questID > 0)              //quests objects
                {
                    _gameObjectForQuestStore.insert(itr->second.entry);
                    ++count;
                }
                break;
            }
            default:
                break;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u GameObjects for quests in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool ObjectMgr::LoadTrinityStrings()
{
    uint32 oldMSTime = getMSTime();

    _trinityStringStore.clear(); // for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, content_default, content_loc1, content_loc2, content_loc3, content_loc4, content_loc5, content_loc6, content_loc7, content_loc8 FROM trinity_string");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 trinity strings. DB table `trinity_string` is empty.");
        return false;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        TrinityString& data = _trinityStringStore[entry];

        data.Content.resize(DEFAULT_LOCALE + 1);

        for (int8 i = OLD_TOTAL_LOCALES - 1; i >= 0; --i)
            AddLocaleString(fields[i + 1].GetString(), LocaleConstant(i), data.Content);
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " trinity strings in %u ms", _trinityStringStore.size(), GetMSTimeDiffToNow(oldMSTime));
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

    TC_LOG_ERROR("sql.sql", "Trinity string entry %u not found in DB.", entry);
    return "<error>";
}

void ObjectMgr::LoadFishingBaseSkillLevel()
{
    uint32 oldMSTime = getMSTime();

    _fishingBaseForAreaStore.clear();                            // for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, skill FROM skill_fishing_base_level");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 areas for fishing base skill level. DB table `skill_fishing_base_level` is empty.");
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
            TC_LOG_ERROR("sql.sql", "AreaId %u defined in `skill_fishing_base_level` does not exist", entry);
            continue;
        }

        _fishingBaseForAreaStore[entry] = skill;
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u areas for fishing base skill level in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

    TC_LOG_INFO("server.loading", ">> Loaded %u skill max values in %u ms", uint32(_skillTiers.size()), GetMSTimeDiffToNow(oldMSTime));
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

uint32 ObjectMgr::GetAreaTriggerScriptId(uint32 trigger_id)
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

// this allows calculating base reputations to offline players, just by race and class
int32 ObjectMgr::GetBaseReputationOf(FactionEntry const* factionEntry, uint8 race, uint8 playerClass)
{
    if (!factionEntry)
        return 0;

    uint32 raceMask = (1 << (race - 1));
    uint32 classMask = (1 << (playerClass-1));

    for (int i = 0; i < 4; i++)
    {
        if ((!factionEntry->ReputationClassMask[i] ||
            factionEntry->ReputationClassMask[i] & classMask) &&
            (!factionEntry->ReputationRaceMask[i] ||
            factionEntry->ReputationRaceMask[i] & raceMask))
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

    if (rcEntry->SkillID == SKILL_RUNEFORGING || rcEntry->SkillID == SKILL_RUNEFORGING_2)
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
        TC_LOG_ERROR("server.loading", ">> Loaded 0 GameTeleports. DB table `game_tele` is empty!");
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
            TC_LOG_ERROR("sql.sql", "Wrong position for id %u (name: %s) in `game_tele` table, ignoring.", id, gt.name.c_str());
            continue;
        }

        if (!Utf8toWStr(gt.name, gt.wnameLow))
        {
            TC_LOG_ERROR("sql.sql", "Wrong UTF8 name for id %u in `game_tele` table, ignoring.", id);
            continue;
        }

        wstrToLower(gt.wnameLow);

        _gameTeleStore[id] = gt;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u GameTeleports in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

GameTele const* ObjectMgr::GetGameTele(const std::string& name) const
{
    // explicit name case
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return NULL;

    // converting string that we try to find to lower case
    wstrToLower(wname);

    // Alternative first GameTele what contains wnameLow as substring in case no GameTele location found
    const GameTele* alt = NULL;
    for (GameTeleContainer::const_iterator itr = _gameTeleStore.begin(); itr != _gameTeleStore.end(); ++itr)
    {
        if (itr->second.wnameLow == wname)
            return &itr->second;
        else if (alt == NULL && itr->second.wnameLow.find(wname) != std::wstring::npos)
            alt = &itr->second;
    }

    return alt;
}

GameTele const* ObjectMgr::GetGameTeleExactName(const std::string& name) const
{
    // explicit name case
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return NULL;

    // converting string that we try to find to lower case
    wstrToLower(wname);

    for (GameTeleContainer::const_iterator itr = _gameTeleStore.begin(); itr != _gameTeleStore.end(); ++itr)
    {
        if (itr->second.wnameLow == wname)
            return &itr->second;
    }

    return NULL;
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

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_GAME_TELE);

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

bool ObjectMgr::DeleteGameTele(const std::string& name)
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
            PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAME_TELE);

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
        TC_LOG_ERROR("server.loading", ">> Loaded 0 level dependent mail rewards. DB table `mail_level_reward` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint8 level           = fields[0].GetUInt8();
        uint32 raceMask       = fields[1].GetUInt32();
        uint32 mailTemplateId = fields[2].GetUInt32();
        uint32 senderEntry    = fields[3].GetUInt32();

        if (level > MAX_LEVEL)
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has data for level %u that more supported by client (%u), ignoring.", level, MAX_LEVEL);
            continue;
        }

        if (!(raceMask & RACEMASK_ALL_PLAYABLE))
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has raceMask (%u) for level %u that not include any player races, ignoring.", raceMask, level);
            continue;
        }

        if (!sMailTemplateStore.LookupEntry(mailTemplateId))
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has invalid mailTemplateId (%u) for level %u that invalid not include any player races, ignoring.", mailTemplateId, level);
            continue;
        }

        if (!GetCreatureTemplate(senderEntry))
        {
            TC_LOG_ERROR("sql.sql", "Table `mail_level_reward` has nonexistent sender creature entry (%u) for level %u that invalid not include any player races, ignoring.", senderEntry, level);
            continue;
        }

        _mailLevelRewardStore[level].push_back(MailLevelReward(raceMask, mailTemplateId, senderEntry));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u level dependent mail rewards in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::AddSpellToTrainer(uint32 ID, uint32 SpellID, uint32 MoneyCost, uint32 ReqSkillLine, uint32 ReqSkillRank, uint32 ReqLevel)
{
    if (ID >= TRINITY_TRAINER_START_REF)
        return;

    CreatureTemplate const* cInfo = GetCreatureTemplate(ID);
    if (!cInfo)
    {
        TC_LOG_ERROR("sql.sql", "Table `npc_trainer` contains entries for a non-existing creature template (ID: %u), ignoring", ID);
        return;
    }

    if (!(cInfo->npcflag & UNIT_NPC_FLAG_TRAINER))
    {
        TC_LOG_ERROR("sql.sql", "Table `npc_trainer` contains entries for a creature template (ID: %u) without any trainer flag, ignoring", ID);
        return;
    }

    SpellInfo const* spellinfo = sSpellMgr->GetSpellInfo(SpellID);
    if (!spellinfo)
    {
        TC_LOG_ERROR("sql.sql", "Table `npc_trainer` contains an ID (%u) for a non-existing spell (Spell: %u), ignoring", ID, SpellID);
        return;
    }

    if (!SpellMgr::IsSpellValid(spellinfo))
    {
        TC_LOG_ERROR("sql.sql", "Table `npc_trainer` contains an ID (%u) for a broken spell (Spell: %u), ignoring", ID, SpellID);
        return;
    }

    TrainerSpellData& data = _cacheTrainerSpellStore[ID];

    TrainerSpell& trainerSpell = data.spellList[SpellID];
    trainerSpell.SpellID       = SpellID;
    trainerSpell.MoneyCost     = MoneyCost;
    trainerSpell.ReqSkillLine  = ReqSkillLine;
    trainerSpell.ReqSkillRank  = ReqSkillRank;
    trainerSpell.ReqLevel      = ReqLevel;

    if (!trainerSpell.ReqLevel)
        trainerSpell.ReqLevel = spellinfo->SpellLevel;

    // calculate learned spell for profession case when stored cast-spell
    trainerSpell.ReqAbility[0] = SpellID;
    for (SpellEffectInfo const* effect : spellinfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
    {
        if (!effect || effect->Effect != SPELL_EFFECT_LEARN_SPELL)
            continue;
        if (trainerSpell.ReqAbility[0] == SpellID)
            trainerSpell.ReqAbility[0] = 0;
        // player must be able to cast spell on himself
        if (effect->TargetA.GetTarget() != 0 && effect->TargetA.GetTarget() != TARGET_UNIT_TARGET_ALLY
            && effect->TargetA.GetTarget() != TARGET_UNIT_TARGET_ANY && effect->TargetA.GetTarget() != TARGET_UNIT_CASTER)
        {
            TC_LOG_ERROR("sql.sql", "Table `npc_trainer` has spell %u for trainer entry %u with learn effect which has incorrect target type, ignoring learn effect!", SpellID, ID);
            continue;
        }

        trainerSpell.ReqAbility[effect->EffectIndex] = effect->TriggerSpell;

        if (trainerSpell.ReqAbility[effect->EffectIndex])
        {
            SpellInfo const* learnedSpellInfo = sSpellMgr->GetSpellInfo(trainerSpell.ReqAbility[effect->EffectIndex]);
            if (learnedSpellInfo && learnedSpellInfo->IsProfession())
                data.trainerType = 2;
        }
    }

    return;
}

void ObjectMgr::LoadTrainerSpell()
{
    uint32 oldMSTime = getMSTime();

    // For reload case
    _cacheTrainerSpellStore.clear();

    QueryResult result = WorldDatabase.Query("SELECT b.ID, a.SpellID, a.MoneyCost, a.ReqSkillLine, a.ReqSkillRank, a.Reqlevel FROM npc_trainer AS a "
                                             "INNER JOIN npc_trainer AS b ON a.ID = -(b.SpellID) "
                                             "UNION SELECT * FROM npc_trainer WHERE SpellID > 0");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">>  Loaded 0 Trainers. DB table `npc_trainer` is empty!");

        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 ID           = fields[0].GetUInt32();
        uint32 SpellID      = fields[1].GetUInt32();
        uint32 MoneyCost    = fields[2].GetUInt32();
        uint32 ReqSkillLine = fields[3].GetUInt16();
        uint32 ReqSkillRank = fields[4].GetUInt16();
        uint32 ReqLevel     = fields[5].GetUInt8();

        AddSpellToTrainer(ID, SpellID, MoneyCost, ReqSkillLine, ReqSkillRank, ReqLevel);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %d Trainers in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

int ObjectMgr::LoadReferenceVendor(int32 vendor, int32 item, uint8 referenceType, std::set<uint32> *skip_vendors)
{
    // find all items from the reference vendor
    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_NPC_VENDOR_REF);
    stmt->setUInt32(0, uint32(item));
    stmt->setUInt8(1, referenceType);
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
            count += LoadReferenceVendor(vendor, -item_id, referenceType, skip_vendors);
        else
        {
            int32  maxcount     = fields[1].GetUInt32();
            uint32 incrtime     = fields[2].GetUInt32();
            uint32 ExtendedCost = fields[3].GetUInt32();
            uint8  type         = fields[4].GetUInt8();

            if (!IsVendorItemValid(vendor, item_id, maxcount, incrtime, ExtendedCost, type, NULL, skip_vendors))
                continue;

            VendorItemData& vList = _cacheVendorItemStore[vendor];

            vList.AddItem(item_id, maxcount, incrtime, ExtendedCost, type);
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

    QueryResult result = WorldDatabase.Query("SELECT entry, item, maxcount, incrtime, ExtendedCost, type FROM npc_vendor ORDER BY entry, slot ASC");
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
            count += LoadReferenceVendor(entry, -item_id, 0, &skip_vendors);
        else
        {
            uint32 maxcount     = fields[2].GetUInt32();
            uint32 incrtime     = fields[3].GetUInt32();
            uint32 ExtendedCost = fields[4].GetUInt32();
            uint8  type         = fields[5].GetUInt8();

            if (!IsVendorItemValid(entry, item_id, maxcount, incrtime, ExtendedCost, type, NULL, &skip_vendors))
                continue;

            VendorItemData& vList = _cacheVendorItemStore[entry];

            vList.AddItem(item_id, maxcount, incrtime, ExtendedCost, type);
            ++count;
        }
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %d Vendors in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenu()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenusStore.clear();

    QueryResult result = WorldDatabase.Query("SELECT entry, text_id FROM gossip_menu");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0  gossip_menu entries. DB table `gossip_menu` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        GossipMenus gMenu;

        gMenu.entry             = fields[0].GetUInt16();
        gMenu.text_id           = fields[1].GetUInt32();

        if (!GetNpcText(gMenu.text_id))
        {
            TC_LOG_ERROR("sql.sql", "Table gossip_menu entry %u are using non-existing text_id %u", gMenu.entry, gMenu.text_id);
            continue;
        }

        _gossipMenusStore.insert(GossipMenusContainer::value_type(gMenu.entry, gMenu));

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u gossip_menu entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadGossipMenuItems()
{
    uint32 oldMSTime = getMSTime();

    _gossipMenuItemsStore.clear();

    QueryResult result = WorldDatabase.Query(
        //      0        1   2            3            4                      5          6                   7               8              9          10         11        12
        "SELECT menu_id, id, option_icon, option_text, OptionBroadcastTextID, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text, BoxBroadcastTextID "
        "FROM gossip_menu_option ORDER BY menu_id, id");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 gossip_menu_option entries. DB table `gossip_menu_option` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        GossipMenuItems gMenuItem;

        gMenuItem.MenuId                = fields[0].GetUInt16();
        gMenuItem.OptionIndex           = fields[1].GetUInt16();
        gMenuItem.OptionIcon            = fields[2].GetUInt32();
        gMenuItem.OptionText            = fields[3].GetString();
        gMenuItem.OptionBroadcastTextId = fields[4].GetUInt32();
        gMenuItem.OptionType            = fields[5].GetUInt8();
        gMenuItem.OptionNpcflag         = fields[6].GetUInt64();
        gMenuItem.ActionMenuId          = fields[7].GetUInt32();
        gMenuItem.ActionPoiId           = fields[8].GetUInt32();
        gMenuItem.BoxCoded              = fields[9].GetBool();
        gMenuItem.BoxMoney              = fields[10].GetUInt32();
        gMenuItem.BoxText               = fields[11].GetString();
        gMenuItem.BoxBroadcastTextId    = fields[12].GetUInt32();

        if (gMenuItem.OptionIcon >= GOSSIP_ICON_MAX)
        {
            TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu %u, id %u has unknown icon id %u. Replacing with GOSSIP_ICON_CHAT", gMenuItem.MenuId, gMenuItem.OptionIndex, gMenuItem.OptionIcon);
            gMenuItem.OptionIcon = GOSSIP_ICON_CHAT;
        }

        if (gMenuItem.OptionBroadcastTextId)
        {
            if (!sBroadcastTextStore.LookupEntry(gMenuItem.OptionBroadcastTextId))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu %u, id %u has non-existing or incompatible OptionBroadcastTextId %u, ignoring.", gMenuItem.MenuId, gMenuItem.OptionIndex, gMenuItem.OptionBroadcastTextId);
                gMenuItem.OptionBroadcastTextId = 0;
            }
        }

        if (gMenuItem.OptionType >= GOSSIP_OPTION_MAX)
            TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu %u, id %u has unknown option id %u. Option will not be used", gMenuItem.MenuId, gMenuItem.OptionIndex, gMenuItem.OptionType);

        if (gMenuItem.ActionPoiId && !GetPointOfInterest(gMenuItem.ActionPoiId))
        {
            TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu %u, id %u use non-existing action_poi_id %u, ignoring", gMenuItem.MenuId, gMenuItem.OptionIndex, gMenuItem.ActionPoiId);
            gMenuItem.ActionPoiId = 0;
        }

        if (gMenuItem.BoxBroadcastTextId)
        {
            if (!sBroadcastTextStore.LookupEntry(gMenuItem.BoxBroadcastTextId))
            {
                TC_LOG_ERROR("sql.sql", "Table `gossip_menu_option` for menu %u, id %u has non-existing or incompatible BoxBroadcastTextId %u, ignoring.", gMenuItem.MenuId, gMenuItem.OptionIndex, gMenuItem.BoxBroadcastTextId);
                gMenuItem.BoxBroadcastTextId = 0;
            }
        }

        _gossipMenuItemsStore.insert(GossipMenuItemsContainer::value_type(gMenuItem.MenuId, gMenuItem));
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u gossip_menu_option entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::AddVendorItem(uint32 entry, uint32 item, int32 maxcount, uint32 incrtime, uint32 extendedCost, uint8 type, bool persist /*= true*/)
{
    VendorItemData& vList = _cacheVendorItemStore[entry];
    vList.AddItem(item, maxcount, incrtime, extendedCost, type);

    if (persist)
    {
        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_NPC_VENDOR);

        stmt->setUInt32(0, entry);
        stmt->setUInt32(1, item);
        stmt->setUInt8(2, maxcount);
        stmt->setUInt32(3, incrtime);
        stmt->setUInt32(4, extendedCost);
        stmt->setUInt8(5, type);

        WorldDatabase.Execute(stmt);
    }
}

bool ObjectMgr::RemoveVendorItem(uint32 entry, uint32 item, uint8 type, bool persist /*= true*/)
{
    CacheVendorItemContainer::iterator  iter = _cacheVendorItemStore.find(entry);
    if (iter == _cacheVendorItemStore.end())
        return false;

    if (!iter->second.RemoveItem(item, type))
        return false;

    if (persist)
    {
        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_NPC_VENDOR);

        stmt->setUInt32(0, entry);
        stmt->setUInt32(1, item);
        stmt->setUInt8(2, type);

        WorldDatabase.Execute(stmt);
    }

    return true;
}

bool ObjectMgr::IsVendorItemValid(uint32 vendor_entry, uint32 id, int32 maxcount, uint32 incrtime, uint32 ExtendedCost, uint8 type, Player* player, std::set<uint32>* skip_vendors, uint32 ORnpcflag) const
{
    CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(vendor_entry);
    if (!cInfo)
    {
        if (player)
            ChatHandler(player->GetSession()).SendSysMessage(LANG_COMMAND_VENDORSELECTION);
        else
            TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has data for nonexistent creature template (Entry: %u), ignore", vendor_entry);
        return false;
    }

    if (!((cInfo->npcflag | ORnpcflag) & UNIT_NPC_FLAG_VENDOR))
    {
        if (!skip_vendors || skip_vendors->count(vendor_entry) == 0)
        {
            if (player)
                ChatHandler(player->GetSession()).SendSysMessage(LANG_COMMAND_VENDORSELECTION);
            else
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has data for creature template (Entry: %u) without vendor flag, ignore", vendor_entry);

            if (skip_vendors)
                skip_vendors->insert(vendor_entry);
        }
        return false;
    }

    if ((type == ITEM_VENDOR_TYPE_ITEM && !sObjectMgr->GetItemTemplate(id)) ||
        (type == ITEM_VENDOR_TYPE_CURRENCY && !sCurrencyTypesStore.LookupEntry(id)))
    {
        if (player)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_ITEM_NOT_FOUND, id, type);
        else
            TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` for Vendor (Entry: %u) have in item list non-existed item (%u, type %u), ignore", vendor_entry, id, type);
        return false;
    }

    if (ExtendedCost && !sItemExtendedCostStore.LookupEntry(ExtendedCost))
    {
        if (player)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_EXTENDED_COST_NOT_EXIST, ExtendedCost);
        else
            TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has Item (Entry: %u) with wrong ExtendedCost (%u) for vendor (%u), ignore", id, ExtendedCost, vendor_entry);
        return false;
    }

    if (type == ITEM_VENDOR_TYPE_ITEM) // not applicable to currencies
    {
        if (maxcount > 0 && incrtime == 0)
        {
            if (player)
                ChatHandler(player->GetSession()).PSendSysMessage("MaxCount != 0 (%u) but IncrTime == 0", maxcount);
            else
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has `maxcount` (%u) for item %u of vendor (Entry: %u) but `incrtime`=0, ignore", maxcount, id, vendor_entry);
            return false;
        }
        else if (maxcount == 0 && incrtime > 0)
        {
            if (player)
                ChatHandler(player->GetSession()).PSendSysMessage("MaxCount == 0 but IncrTime<>= 0");
            else
                TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` has `maxcount`=0 for item %u of vendor (Entry: %u) but `incrtime`<>0, ignore", id, vendor_entry);
            return false;
        }
    }

    VendorItemData const* vItems = GetNpcVendorItemList(vendor_entry);
    if (!vItems)
        return true;                                        // later checks for non-empty lists

    if (vItems->FindItemCostPair(id, ExtendedCost, type))
    {
        if (player)
            ChatHandler(player->GetSession()).PSendSysMessage(LANG_ITEM_ALREADY_IN_LIST, id, ExtendedCost, type);
        else
            TC_LOG_ERROR("sql.sql", "Table `npc_vendor` has duplicate items %u (with extended cost %u, type %u) for vendor (Entry: %u), ignoring", id, ExtendedCost, type, vendor_entry);
        return false;
    }

    if (type == ITEM_VENDOR_TYPE_CURRENCY && maxcount == 0)
    {
        TC_LOG_ERROR("sql.sql", "Table `(game_event_)npc_vendor` have Item (Entry: %u, type: %u) with missing maxcount for vendor (%u), ignore", id, type, vendor_entry);
        return false;
    }

    return true;
}

void ObjectMgr::LoadScriptNames()
{
    uint32 oldMSTime = getMSTime();

    // We insert an empty placeholder here so we can use the
    // script id 0 as dummy for "no script found".
    _scriptNamesStore.emplace_back("");

    QueryResult result = WorldDatabase.Query(
        "SELECT DISTINCT(ScriptName) FROM battleground_template WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM creature_template WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM criteria_data WHERE ScriptName <> '' AND type = 11 "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM gameobject_template WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM item_script_names WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM areatrigger_scripts WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM spell_script_names WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM transports WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM game_weather WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM conditions WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(ScriptName) FROM outdoorpvp_template WHERE ScriptName <> '' "
        "UNION "
        "SELECT DISTINCT(script) FROM instance_template WHERE script <> ''");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded empty set of Script Names!");
        return;
    }

    do
    {
        _scriptNamesStore.push_back((*result)[0].GetString());
    }
    while (result->NextRow());

    std::sort(_scriptNamesStore.begin(), _scriptNamesStore.end());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " ScriptNames in %u ms", _scriptNamesStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

ObjectMgr::ScriptNameContainer const& ObjectMgr::GetAllScriptNames() const
{
    return _scriptNamesStore;
}

std::string const& ObjectMgr::GetScriptName(uint32 id) const
{
    static std::string const empty = "";
    return (id < _scriptNamesStore.size()) ? _scriptNamesStore[id] : empty;
}

uint32 ObjectMgr::GetScriptId(std::string const& name)
{
    // use binary search to find the script name in the sorted vector
    // assume "" is the first element
    if (name.empty())
        return 0;

    ScriptNameContainer::const_iterator itr = std::lower_bound(_scriptNamesStore.begin(), _scriptNamesStore.end(), name);
    if (itr == _scriptNamesStore.end() || *itr != name)
        return 0;

    return uint32(itr - _scriptNamesStore.begin());
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
            BaseArmor = 1;
            for (uint8 j = 0; j < MAX_EXPANSIONS; ++j)
            {
                BaseHealth[j] = 1;
                BaseDamage[j] = 0.0f;
            }
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
    //                                               0      1      2         3          4            5                  6            7            8            9            10           11
    QueryResult result = WorldDatabase.Query("SELECT level, class, basemana, basearmor, attackpower, rangedattackpower, damage_base, damage_exp1, damage_exp2, damage_exp3, damage_exp4, damage_exp5 FROM creature_classlevelstats");

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
            TC_LOG_ERROR("sql.sql", "Creature base stats for level %u has invalid class %u", Level, Class);

        GtNpcTotalHpEntry const* HpExp0 = sGtNpcTotalHpStore.EvaluateTable(Level - 1, Class - 1);
        GtNpcTotalHpExp1Entry const* HpExp1 = sGtNpcTotalHpExp1Store.EvaluateTable(Level - 1, Class - 1);
        GtNpcTotalHpExp2Entry const* HpExp2 = sGtNpcTotalHpExp2Store.EvaluateTable(Level - 1, Class - 1);
        GtNpcTotalHpExp3Entry const* HpExp3 = sGtNpcTotalHpExp3Store.EvaluateTable(Level - 1, Class - 1);
        GtNpcTotalHpExp4Entry const* HpExp4 = sGtNpcTotalHpExp4Store.EvaluateTable(Level - 1, Class - 1);
        GtNpcTotalHpExp5Entry const* HpExp5 = sGtNpcTotalHpExp5Store.EvaluateTable(Level - 1, Class - 1);

        CreatureBaseStats stats;

        stats.BaseHealth[0] = uint32(HpExp0->HP);
        stats.BaseHealth[1] = uint32(HpExp1->HP);
        stats.BaseHealth[2] = uint32(HpExp2->HP);
        stats.BaseHealth[3] = uint32(HpExp3->HP);
        stats.BaseHealth[4] = uint32(HpExp4->HP);
        stats.BaseHealth[5] = uint32(HpExp5->HP);

        for (uint8 i = 0; i < MAX_EXPANSIONS; ++i)
        {
            stats.BaseDamage[i] = fields[6 + i].GetFloat();
            if (stats.BaseDamage[i] < 0.0f)
            {
                TC_LOG_ERROR("sql.sql", "Creature base stats for class %u, level %u has invalid negative base damage[%u] - set to 0.0", Class, Level, i);
                stats.BaseDamage[i] = 0.0f;
            }
        }

        stats.BaseMana = fields[2].GetUInt32();
        stats.BaseArmor = fields[3].GetUInt32();

        stats.AttackPower = fields[4].GetUInt16();
        stats.RangedAttackPower = fields[5].GetUInt16();

        _creatureBaseStatsStore[MAKE_PAIR16(Level, Class)] = stats;

        ++count;
    }
    while (result->NextRow());

    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        for (uint16 lvl = itr->second.minlevel; lvl <= itr->second.maxlevel; ++lvl)
        {
            if (_creatureBaseStatsStore.find(MAKE_PAIR16(lvl, itr->second.unit_class)) == _creatureBaseStatsStore.end())
                TC_LOG_ERROR("sql.sql", "Missing base stats for creature class %u level %u", itr->second.unit_class, lvl);
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u creature base stats in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeAchievements()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_achievement");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 faction change achievement pairs. DB table `player_factionchange_achievement` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sAchievementStore.LookupEntry(alliance))
            TC_LOG_ERROR("sql.sql", "Achievement %u (alliance_id) referenced in `player_factionchange_achievement` does not exist, pair skipped!", alliance);
        else if (!sAchievementStore.LookupEntry(horde))
            TC_LOG_ERROR("sql.sql", "Achievement %u (horde_id) referenced in `player_factionchange_achievement` does not exist, pair skipped!", horde);
        else
            FactionChangeAchievements[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u faction change achievement pairs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeItems()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_items");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 faction change item pairs. DB table `player_factionchange_items` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!GetItemTemplate(alliance))
            TC_LOG_ERROR("sql.sql", "Item %u (alliance_id) referenced in `player_factionchange_items` does not exist, pair skipped!", alliance);
        else if (!GetItemTemplate(horde))
            TC_LOG_ERROR("sql.sql", "Item %u (horde_id) referenced in `player_factionchange_items` does not exist, pair skipped!", horde);
        else
            FactionChangeItems[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u faction change item pairs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeQuests()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_quests");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 faction change quest pairs. DB table `player_factionchange_quests` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sObjectMgr->GetQuestTemplate(alliance))
            TC_LOG_ERROR("sql.sql", "Quest %u (alliance_id) referenced in `player_factionchange_quests` does not exist, pair skipped!", alliance);
        else if (!sObjectMgr->GetQuestTemplate(horde))
            TC_LOG_ERROR("sql.sql", "Quest %u (horde_id) referenced in `player_factionchange_quests` does not exist, pair skipped!", horde);
        else
            FactionChangeQuests[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u faction change quest pairs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Reputation %u (alliance_id) referenced in `player_factionchange_reputations` does not exist, pair skipped!", alliance);
        else if (!sFactionStore.LookupEntry(horde))
            TC_LOG_ERROR("sql.sql", "Reputation %u (horde_id) referenced in `player_factionchange_reputations` does not exist, pair skipped!", horde);
        else
            FactionChangeReputation[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u faction change reputation pairs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadFactionChangeSpells()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT alliance_id, horde_id FROM player_factionchange_spells");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 faction change spell pairs. DB table `player_factionchange_spells` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 alliance = fields[0].GetUInt32();
        uint32 horde = fields[1].GetUInt32();

        if (!sSpellMgr->GetSpellInfo(alliance))
            TC_LOG_ERROR("sql.sql", "Spell %u (alliance_id) referenced in `player_factionchange_spells` does not exist, pair skipped!", alliance);
        else if (!sSpellMgr->GetSpellInfo(horde))
            TC_LOG_ERROR("sql.sql", "Spell %u (horde_id) referenced in `player_factionchange_spells` does not exist, pair skipped!", horde);
        else
            FactionChangeSpells[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u faction change spell pairs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Title %u (alliance_id) referenced in `player_factionchange_title` does not exist, pair skipped!", alliance);
        else if (!sCharTitlesStore.LookupEntry(horde))
            TC_LOG_ERROR("sql.sql", "Title %u (horde_id) referenced in `player_factionchange_title` does not exist, pair skipped!", horde);
        else
            FactionChangeTitles[alliance] = horde;

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u faction change title pairs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadTerrainSwapDefaults()
{
    _terrainMapDefaultStore.clear();

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
            TC_LOG_ERROR("sql.sql", "Map %u defined in `terrain_swap_defaults` does not exist, skipped.", mapId);
            continue;
        }

        uint32 terrainSwap = fields[1].GetUInt32();

        if (!sMapStore.LookupEntry(terrainSwap))
        {
            TC_LOG_ERROR("sql.sql", "TerrainSwapMap %u defined in `terrain_swap_defaults` does not exist, skipped.", terrainSwap);
            continue;
        }

        _terrainMapDefaultStore[mapId].push_back(terrainSwap);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u terrain swap defaults in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadTerrainPhaseInfo()
{
    _terrainPhaseInfoStore.clear();

    uint32 oldMSTime = getMSTime();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT Id, TerrainSwapMap FROM `terrain_phase_info`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 terrain phase infos. DB table `terrain_phase_info` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 phaseId = fields[0].GetUInt32();

        PhaseEntry const* phase = sPhaseStore.LookupEntry(phaseId);
        if (!phase)
        {
            TC_LOG_ERROR("sql.sql", "Phase %u defined in `terrain_phase_info` does not exist, skipped.", phaseId);
            continue;
        }

        uint32 terrainSwap = fields[1].GetUInt32();

        _terrainPhaseInfoStore[phaseId].push_back(terrainSwap);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u terrain phase infos in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadTerrainWorldMaps()
{
    _terrainWorldMapStore.clear();

    uint32 oldMSTime = getMSTime();

    //                                               0               1
    QueryResult result = WorldDatabase.Query("SELECT TerrainSwapMap, WorldMapArea FROM `terrain_worldmap`");

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

        if (!sMapStore.LookupEntry(mapId))
        {
            TC_LOG_ERROR("sql.sql", "TerrainSwapMap %u defined in `terrain_worldmap` does not exist, skipped.", mapId);
            continue;
        }

        uint32 worldMapArea = fields[1].GetUInt32();

        _terrainWorldMapStore[mapId].push_back(worldMapArea);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u terrain world maps in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadAreaPhases()
{
    _phases.clear();

    uint32 oldMSTime = getMSTime();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT AreaId, PhaseId FROM `phase_area`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 phase areas. DB table `phase_area` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        PhaseInfoStruct phase;
        uint32 area = fields[0].GetUInt32();
        phase.Id = fields[1].GetUInt32();
        _phases[area].push_back(phase);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u phase areas in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

GameObjectTemplate const* ObjectMgr::GetGameObjectTemplate(uint32 entry)
{
    GameObjectTemplateContainer::const_iterator itr = _gameObjectTemplateStore.find(entry);
    if (itr != _gameObjectTemplateStore.end())
        return &(itr->second);

    return NULL;
}

CreatureTemplate const* ObjectMgr::GetCreatureTemplate(uint32 entry)
{
    CreatureTemplateContainer::const_iterator itr = _creatureTemplateStore.find(entry);
    if (itr != _creatureTemplateStore.end())
        return &(itr->second);

    return NULL;
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
    return NULL;
}

PlayerInfo const* ObjectMgr::GetPlayerInfo(uint32 race, uint32 class_) const
{
    if (race >= MAX_RACES)
        return NULL;
    if (class_ >= MAX_CLASSES)
        return NULL;
    PlayerInfo const* info = _playerInfo[race][class_];
    if (!info)
        return NULL;
    return info;
}

void ObjectMgr::LoadRaceAndClassExpansionRequirements()
{
    uint32 oldMSTime = getMSTime();
    _raceExpansionRequirementStore.clear();

    //                                               0       1
    QueryResult result = WorldDatabase.Query("SELECT raceID, expansion FROM `race_expansion_requirement`");

    if (result)
    {
        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();

            uint8 raceID = fields[0].GetInt8();
            uint8 expansion = fields[1].GetInt8();

            ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(raceID);
            if (!raceEntry)
            {
                TC_LOG_ERROR("sql.sql", "Race %u defined in `race_expansion_requirement` does not exists, skipped.", raceID);
                continue;
            }

            if (expansion >= MAX_EXPANSIONS)
            {
                TC_LOG_ERROR("sql.sql", "Race %u defined in `race_expansion_requirement` has incorrect expansion %u, skipped.", raceID, expansion);
                continue;
            }

            _raceExpansionRequirementStore[raceID] = expansion;

            ++count;
        }
        while (result->NextRow());
        TC_LOG_INFO("server.loading", ">> Loaded %u race expansion requirements in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 race expansion requirements. DB table `race_expansion_requirement` is empty.");

    oldMSTime = getMSTime();
    _classExpansionRequirementStore.clear();

    //                                   0        1
    result = WorldDatabase.Query("SELECT classID, expansion FROM `class_expansion_requirement`");

    if (result)
    {
        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();

            uint8 classID = fields[0].GetInt8();
            uint8 expansion = fields[1].GetInt8();

            ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(classID);
            if (!classEntry)
            {
                TC_LOG_ERROR("sql.sql", "Class %u defined in `class_expansion_requirement` does not exists, skipped.", classID);
                continue;
            }

            if (expansion >= MAX_EXPANSIONS)
            {
                TC_LOG_ERROR("sql.sql", "Class %u defined in `class_expansion_requirement` has incorrect expansion %u, skipped.", classID, expansion);
                continue;
            }

            _classExpansionRequirementStore[classID] = expansion;

            ++count;
        }
        while (result->NextRow());
        TC_LOG_INFO("server.loading", ">> Loaded %u class expansion requirements in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 class expansion requirements. DB table `class_expansion_requirement` is empty.");
}

void ObjectMgr::LoadCharacterTemplates()
{
    uint32 oldMSTime = getMSTime();
    _characterTemplateStore.clear();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_TEMPLATES);
    PreparedQueryResult templates = CharacterDatabase.Query(stmt);

    if (!templates)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 character templates. DB table `character_template` is empty.");
        return;
    }

    PreparedQueryResult classes;
    uint32 count = 0;

    do
    {
        Field* fields = templates->Fetch();

        uint32 templateSetId = fields[0].GetUInt32();

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_TEMPLATE_CLASSES);
        stmt->setUInt32(0, templateSetId);
        classes = CharacterDatabase.Query(stmt);

        if (classes)
        {
            CharacterTemplate templ;
            templ.TemplateSetId = templateSetId;
            templ.Name = fields[1].GetString();
            templ.Description = fields[2].GetString();
            templ.Level = fields[3].GetUInt8();

            do
            {
                fields = classes->Fetch();

                uint8 factionGroup = fields[0].GetUInt8();
                uint8 classID = fields[1].GetUInt8();

                if (!((factionGroup & (FACTION_MASK_PLAYER | FACTION_MASK_ALLIANCE)) == (FACTION_MASK_PLAYER | FACTION_MASK_ALLIANCE)) &&
                    !((factionGroup & (FACTION_MASK_PLAYER | FACTION_MASK_HORDE)) == (FACTION_MASK_PLAYER | FACTION_MASK_HORDE)))
                {
                    TC_LOG_ERROR("sql.sql", "Faction group %u defined for character template %u in `character_template_class` is invalid. Skipped.", factionGroup, templateSetId);
                    continue;
                }

                ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(classID);
                if (!classEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Class %u defined for character template %u in `character_template_class` does not exists, skipped.", classID, templateSetId);
                    continue;
                }

                templ.Classes.emplace_back(factionGroup, classID);

            } while (classes->NextRow());

            if (!templ.Classes.empty())
            {
                _characterTemplateStore[templateSetId] = templ;
                ++count;
            }
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Character template %u does not have any classes defined in `character_template_class`. Skipped.", templateSetId);
            continue;
        }
    } while (templates->NextRow());
    TC_LOG_INFO("server.loading", ">> Loaded %u character templates in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadRealmNames()
{
    uint32 oldMSTime = getMSTime();
    _realmNameStore.clear();

    //                                               0   1
    QueryResult result = LoginDatabase.Query("SELECT id, name FROM `realmlist`");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 realm names. DB table `realmlist` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 realmId = fields[0].GetUInt32();
        std::string realmName = fields[1].GetString();

        _realmNameStore[realmId] = realmName;

        ++count;
    }
    while (result->NextRow());
    TC_LOG_INFO("server.loading", ">> Loaded %u realm names in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

std::string ObjectMgr::GetRealmName(uint32 realmId) const
{
    RealmNameContainer::const_iterator iter = _realmNameStore.find(realmId);
    return iter != _realmNameStore.end() ? iter->second : "";
}

std::string ObjectMgr::GetNormalizedRealmName(uint32 realmId) const
{
    std::string name = GetRealmName(realmId);
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    return name;
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
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questitem` has data for nonexistent gameobject (entry: %u, idx: %u), skipped", entry, idx);
            continue;
        };

        ItemEntry const* db2Data = sItemStore.LookupEntry(item);
        if (!db2Data)
        {
            TC_LOG_ERROR("sql.sql", "Table `gameobject_questitem` has nonexistent item (ID: %u) in gameobject (entry: %u, idx: %u), skipped", item, entry, idx);
            continue;
        };

        _gameObjectQuestItemStore[entry].push_back(item);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u gameobject quest items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ObjectMgr::LoadCreatureQuestItems()
{
    uint32 oldMSTime = getMSTime();

    //                                               0              1       2
    QueryResult result = WorldDatabase.Query("SELECT CreatureEntry, ItemId, Idx FROM creature_questitem ORDER BY Idx ASC");

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
        uint32 item  = fields[1].GetUInt32();
        uint32 idx   = fields[2].GetUInt32();

        CreatureTemplate const* creatureInfo = GetCreatureTemplate(entry);
        if (!creatureInfo)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_questitem` has data for nonexistent creature (entry: %u, idx: %u), skipped", entry, idx);
            continue;
        };

        ItemEntry const* db2Data = sItemStore.LookupEntry(item);
        if (!db2Data)
        {
            TC_LOG_ERROR("sql.sql", "Table `creature_questitem` has nonexistent item (ID: %u) in creature (entry: %u, idx: %u), skipped", item, entry, idx);
            continue;
        };

        _creatureQuestItemStore[entry].push_back(item);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u creature quest items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}
