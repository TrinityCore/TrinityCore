/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "PlayerDump.h"
#include "AccountMgr.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include <sstream>

struct DumpTable
{
    char const* name;
    DumpTableType type;
};

DumpTable const dumpTables[] =
{
    { "characters",                       DTT_CHARACTER  },
    { "character_account_data",           DTT_CHAR_TABLE },
    { "character_achievement",            DTT_CHAR_TABLE },
    { "character_achievement_progress",   DTT_CHAR_TABLE },
    { "character_action",                 DTT_CHAR_TABLE },
    // { "character_aura",                   DTT_CHAR_TABLE }, /// @todo: reguid casterguid (full guid)
    // { "character_aura_effect",            DTT_CHAR_TABLE }, /// @todo: reguid casterguid (full guid)
    { "character_cuf_profiles",           DTT_CHAR_TABLE },
    { "character_currency",               DTT_CURRENCY   },
    { "character_declinedname",           DTT_CHAR_TABLE },
    { "character_fishingsteps",           DTT_CHAR_TABLE },
    { "character_garrison",               DTT_CHAR_TABLE },
    { "character_garrison_blueprints",    DTT_CHAR_TABLE },
    { "character_garrison_buildings",     DTT_CHAR_TABLE },
    /// @todo: character_garrison_follower_abilities
    /// @todo: character_garrison_followers
    { "character_glyphs",                 DTT_CHAR_TABLE },
    { "character_homebind",               DTT_CHAR_TABLE },
    { "character_inventory",              DTT_INVENTORY  },
    { "character_pet",                    DTT_PET        },
    { "character_pet_declinedname",       DTT_PET        },
    { "character_queststatus",            DTT_CHAR_TABLE },
    { "character_queststatus_daily",      DTT_CHAR_TABLE },
    { "character_queststatus_monthly",    DTT_CHAR_TABLE },
    { "character_queststatus_objectives", DTT_CHAR_TABLE },
    { "character_queststatus_objectives_criteria", DTT_CHAR_TABLE },
    { "character_queststatus_objectives_criteria_progress", DTT_CHAR_TABLE },
    { "character_queststatus_weekly",     DTT_CHAR_TABLE },
    { "character_queststatus_seasonal",   DTT_CHAR_TABLE },
    { "character_queststatus_rewarded",   DTT_CHAR_TABLE },
    { "character_reputation",             DTT_CHAR_TABLE },
    { "character_skills",                 DTT_CHAR_TABLE },
    { "character_spell",                  DTT_CHAR_TABLE },
    { "character_spell_charges",          DTT_CHAR_TABLE },
    { "character_spell_cooldown",         DTT_CHAR_TABLE },
    { "character_talent",                 DTT_CHAR_TABLE },
    { "character_transmog_outfits",       DTT_CHAR_TRANSMOG },
    /// @todo: character_void_storage
    { "mail",                             DTT_MAIL       },
    { "mail_items",                       DTT_MAIL_ITEM  }, // must be after mail
    // { "pet_aura",                         DTT_PET_TABLE  }, // must be after character_pet /// @todo: reguid casterguid (full guid)
    // { "pet_aura_effect",                  DTT_PET_TABLE  }, // must be after character_pet /// @todo: reguid casterguid (full guid)
    { "pet_spell",                        DTT_PET_TABLE  }, // must be after character_pet
    { "pet_spell_charges",                DTT_PET_TABLE  }, // must be after character_pet
    { "pet_spell_cooldown",               DTT_PET_TABLE  }, // must be after character_pet
    { "item_instance",                    DTT_ITEM       }, // must be after character_inventory and mail_items
    { "character_equipmentsets",          DTT_EQSET_TABLE}, // must be after item_instance
    { "character_gifts",                  DTT_ITEM_GIFT  }, // must be after item_instance
    { "item_instance_artifact",           DTT_ITEM_TABLE }, // must be after item_instance
    { "item_instance_artifact_powers",    DTT_ITEM_TABLE }, // must be after item_instance
    { "item_instance_gems",               DTT_ITEM_TABLE }, // must be after item_instance
    { "item_instance_modifiers",          DTT_ITEM_TABLE }, // must be after item_instance
    { "item_instance_transmog",           DTT_ITEM_TABLE }, // must be after item_instance
};
size_t constexpr dumpTablesCount = std::extent<decltype(dumpTables)>::value;

namespace
{
    std::unordered_map<std::pair<std::string, std::string>, uint32> ColumnDefinitions;
}

void PlayerDump::InitializeColumnDefinition()
{
    uint32 oldMSTime = getMSTime();

    for (size_t i = 0; i < dumpTablesCount; ++i)
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT column_name, ordinal_position FROM information_schema.columns WHERE table_schema=SCHEMA() AND table_name = \"%s\"", dumpTables[i].name);
        WPFatal(result, "Error while initializing PlayerDump ColumnDefinitions. Table \"%s\" does not exist.", dumpTables[i].name);

        Field* fields = result->Fetch();

        do
        {
            ColumnDefinitions[std::make_pair(std::string(dumpTables[i].name), fields[0].GetString())] = uint32(fields[1].GetUInt64());
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Initialized " SZFMTD " PlayerDump ColumnDefinitions in %u ms.", ColumnDefinitions.size(), GetMSTimeDiffToNow(oldMSTime));
}

// Low level functions
static uint32 GetColNumber(std::string const& table, std::string const& column)
{
    auto itr = ColumnDefinitions.find(std::make_pair(table, column));
    ASSERT(itr != ColumnDefinitions.end(), "ColumnDefinition (Table: \"%s\", Column: \"%s\") not found.", table.c_str(), column.c_str());
    return itr->second;
}

static bool FindTokNth(std::string const& str, uint32 n, std::string::size_type& s, std::string::size_type& e)
{
    s = e = 0;

    uint32 i = 1;
    for (; s < str.size() && i < n; ++s)
        if (str[s] == ' ')
            ++i;

    if (i < n)
        return false;

    e = str.find(' ', s);

    return e != std::string::npos;
}

std::string GetTokNth(std::string const& str, uint32 n)
{
    std::string::size_type s = 0, e = 0;
    if (!FindTokNth(str, n, s, e))
        return "";

    return str.substr(s, e - s);
}

bool FindNth(std::string const& str, uint32 n, std::string::size_type& s, std::string::size_type& e)
{
    s = str.find("VALUES ('") + 9;
    if (s == std::string::npos)
        return false;

    do
    {
        e = str.find('\'', s);
        if (e == std::string::npos)
            return false;
    } while (str[e - 1] == '\\');

    for (uint32 i = 1; i < n; ++i)
    {
        do
        {
            s = e + 4;
            e = str.find('\'', s);
            if (e == std::string::npos)
                return false;
        } while (str[e - 1] == '\\');
    }
    return true;
}

std::string GetTableName(std::string const& str)
{
    static std::string::size_type const s = 13;
    std::string::size_type e = str.find('`', s);
    if (e == std::string::npos)
        return "";

    return str.substr(s, e - s);
}

bool ChangeNth(std::string& str, uint32 n, char const* with, bool insert = false, bool allowZero = false)
{
    std::string::size_type s, e;
    if (!FindNth(str, n, s, e))
        return false;

    if (allowZero && str.substr(s, e - s) == "0")
        return true;                                        // not an error

    if (!insert)
        str.replace(s, e - s, with);
    else
        str.insert(s, with);

    return true;
}

std::string GetNth(std::string& str, uint32 n)
{
    std::string::size_type s, e;
    if (!FindNth(str, n, s, e))
        return "";

    return str.substr(s, e-s);
}

bool ChangeTokNth(std::string& str, uint32 n, char const* with, bool insert = false, bool allowZero = false)
{
    std::string::size_type s = 0, e = 0;
    if (!FindTokNth(str, n, s, e))
        return false;

    if (allowZero && str.substr(s, e - s) == "0")
        return true;                                        // not an error

    if (!insert)
        str.replace(s, e-s, with);
    else
        str.insert(s, with);

    return true;
}

ObjectGuid::LowType RegisterNewGuid(ObjectGuid::LowType oldGuid, PlayerDump::DumpGuidMap& guidMap, ObjectGuid::LowType guidOffset)
{
    PlayerDumpWriter::DumpGuidMap::const_iterator itr = guidMap.find(oldGuid);
    if (itr != guidMap.end())
        return itr->second;

    ObjectGuid::LowType newguid = guidOffset + guidMap.size();
    guidMap[oldGuid] = newguid;
    return newguid;
}

bool ChangeGuid(std::string& str, uint32 n, PlayerDump::DumpGuidMap& guidMap, ObjectGuid::LowType guidOffset, bool allowZero = false)
{
    ObjectGuid::LowType oldGuid = strtoull(GetNth(str, n).c_str(), nullptr, 10);
    if (allowZero && !oldGuid)
        return true;                                        // not an error

    char chritem[21];
    ObjectGuid::LowType newGuid = RegisterNewGuid(oldGuid, guidMap, guidOffset);
    snprintf(chritem, 21, UI64FMTD, newGuid);

    return ChangeNth(str, n, chritem, false, allowZero);
}

std::string CreateDumpString(char const* tableName, QueryResult result)
{
    if (!tableName || !result) return "";
    std::ostringstream ss;
    ss << "INSERT INTO `" << tableName << "` VALUES (";
    Field* fields = result->Fetch();
    for (uint32 i = 0; i < result->GetFieldCount(); ++i)
    {
        if (i == 0) ss << '\'';
        else ss << ", '";

        std::string s = fields[i].GetString();
        CharacterDatabase.EscapeString(s);
        ss << s;

        ss << '\'';
    }
    ss << ");";
    return ss.str();
}

std::string PlayerDumpWriter::GenerateWhereStr(char const* field, ObjectGuid::LowType guid)
{
    std::ostringstream wherestr;
    wherestr << field << " = '" << guid << '\'';
    return wherestr.str();
}

std::string PlayerDumpWriter::GenerateWhereStr(char const* field, DumpGuidSet const& guids, DumpGuidSet::const_iterator& itr)
{
    std::ostringstream wherestr;
    wherestr << field << " IN ('";
    for (; itr != guids.end();)
    {
        wherestr << *itr;
        ++itr;

        if (wherestr.str().size() > MAX_QUERY_LEN - 50)      // near to max query
            break;

        if (itr != guids.end())
            wherestr << "', '";
    }
    wherestr << "')";
    return wherestr.str();
}

void StoreGUID(QueryResult result, uint32 field, PlayerDump::DumpGuidSet &guids)
{
    Field* fields = result->Fetch();
    ObjectGuid::LowType guid = fields[field].GetUInt64();
    if (guid)
        guids.insert(guid);
}

void StoreGUID(QueryResult result, uint32 data, uint32 field, PlayerDump::DumpGuidSet& guids)
{
    Field* fields = result->Fetch();
    std::string dataStr = fields[data].GetString();
    ObjectGuid::LowType guid = strtoull(GetTokNth(dataStr, field).c_str(), nullptr, 10);
    if (guid)
        guids.insert(guid);
}

// Writing - High-level functions
bool PlayerDumpWriter::DumpTable(std::string& dump, ObjectGuid::LowType guid, char const* tableFrom, char const* tableTo, DumpTableType type)
{
    DumpGuidSet const* guids = nullptr;
    char const* fieldname = nullptr;

    switch (type)
    {
        case DTT_CURRENCY:  fieldname = "CharacterGuid";             break;
        case DTT_ITEM:      fieldname = "guid";      guids = &items; break;
        case DTT_ITEM_GIFT: fieldname = "item_guid"; guids = &items; break;
        case DTT_ITEM_TABLE: fieldname = "itemGuid"; guids = &items; break;
        case DTT_PET:       fieldname = "owner";                     break;
        case DTT_PET_TABLE: fieldname = "guid";      guids = &pets;  break;
        case DTT_MAIL:      fieldname = "receiver";                  break;
        case DTT_MAIL_ITEM: fieldname = "mail_id";   guids = &mails; break;
        default:            fieldname = "guid";                      break;
    }

    // for guid set stop if set is empty
    if (guids && guids->empty())
        return true;                                            // nothing to do

    // setup for guids case start position
    DumpGuidSet::const_iterator guidsItr;
    if (guids)
        guidsItr = guids->begin();

    do
    {
        std::string wherestr;

        if (guids)                                              // set case, get next guids string
            wherestr = GenerateWhereStr(fieldname, *guids, guidsItr);
        else                                                    // not set case, get single guid string
            wherestr = GenerateWhereStr(fieldname, guid);

        QueryResult result = CharacterDatabase.PQuery("SELECT * FROM %s WHERE %s", tableFrom, wherestr.c_str());
        if (!result)
            return true;

        do
        {
            // collect guids
            switch (type)
            {
                case DTT_INVENTORY:
                    StoreGUID(result, GetColNumber(tableFrom, "item") - 1, items);                         // item guid collection (character_inventory.item)
                    break;
                case DTT_PET:
                    StoreGUID(result, GetColNumber(tableFrom, "id") - 1, pets);                            // pet petnumber collection (character_pet.id)
                    break;
                case DTT_MAIL:
                    StoreGUID(result, GetColNumber(tableFrom, "id") - 1, mails);                           // mail id collection (mail.id)
                    break;
                case DTT_MAIL_ITEM:
                    StoreGUID(result, GetColNumber(tableFrom, "item_guid") - 1, items);                    // item guid collection (mail_items.item_guid)
                    break;
                case DTT_CHARACTER:
                {
                    if (result->GetFieldCount() <= GetColNumber(tableFrom, "deleteInfos_Account") - 1)     // avoid crashes on next check
                    {
                        TC_LOG_FATAL("misc", "PlayerDumpWriter::DumpTable - Trying to access non-existing or wrong positioned field (`deleteInfos_Account`) in `characters` table.");
                        return false;
                    }

                    if (result->Fetch()[GetColNumber(tableFrom, "deleteInfos_Account") - 1].GetUInt32())   // characters.deleteInfos_Account - if filled error
                        return false;
                    break;
                }
                default:
                    break;
            }

            dump += CreateDumpString(tableTo, result);
            dump += "\n";
        }
        while (result->NextRow());
    }
    while (guids && guidsItr != guids->end());                  // not set case iterate single time, set case iterate for all guids
    return true;
}

bool PlayerDumpWriter::GetDump(ObjectGuid::LowType guid, std::string &dump)
{
    dump =  "IMPORTANT NOTE: THIS DUMPFILE IS MADE FOR USE WITH THE 'PDUMP' COMMAND ONLY - EITHER THROUGH INGAME CHAT OR ON CONSOLE!\n";
    dump += "IMPORTANT NOTE: DO NOT apply it directly - it will irreversibly DAMAGE and CORRUPT your database! You have been warned!\n\n";

    for (size_t i = 0; i < dumpTablesCount; ++i)
        if (!DumpTable(dump, guid, dumpTables[i].name, dumpTables[i].name, dumpTables[i].type))
            return false;

    /// @todo Add instance/group..
    /// @todo Add a dump level option to skip some non-important tables

    return true;
}

DumpReturn PlayerDumpWriter::WriteDump(const std::string& file, ObjectGuid::LowType guid)
{
    if (sWorld->getBoolConfig(CONFIG_PDUMP_NO_PATHS))
        if (strstr(file.c_str(), "\\") || strstr(file.c_str(), "/"))
            return DUMP_FILE_OPEN_ERROR;

    if (sWorld->getBoolConfig(CONFIG_PDUMP_NO_OVERWRITE))
        if (FILE* f = fopen(file.c_str(), "r"))
        {
            fclose(f);
            return DUMP_FILE_OPEN_ERROR;
        }

    FILE* fout = fopen(file.c_str(), "w");
    if (!fout)
        return DUMP_FILE_OPEN_ERROR;

    DumpReturn ret = DUMP_SUCCESS;
    std::string dump;
    if (!GetDump(guid, dump))
        ret = DUMP_CHARACTER_DELETED;

    fprintf(fout, "%s\n", dump.c_str());
    fclose(fout);
    return ret;
}

// Reading - High-level functions
#define ROLLBACK(DR) {fclose(fin); return (DR);}

void fixNULLfields(std::string& line)
{
    static std::string const nullString("'NULL'");
    size_t pos = line.find(nullString);
    while (pos != std::string::npos)
    {
        line.replace(pos, nullString.length(), "NULL");
        pos = line.find(nullString);
    }
}

DumpReturn PlayerDumpReader::LoadDump(std::string const& file, uint32 account, std::string name, ObjectGuid::LowType guid)
{
    uint32 charcount = AccountMgr::GetCharactersCount(account);
    if (charcount >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM))
        return DUMP_TOO_MANY_CHARS;

    FILE* fin = fopen(file.c_str(), "r");
    if (!fin)
        return DUMP_FILE_OPEN_ERROR;

    char newguid[20], chraccount[20];

    // make sure the same guid doesn't already exist and is safe to use
    bool incHighest = true;
    if (guid && guid < sObjectMgr->GetGenerator<HighGuid::Player>().GetNextAfterMaxUsed())
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_GUID);
        stmt->setUInt64(0, guid);
        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
            guid = sObjectMgr->GetGenerator<HighGuid::Player>().GetNextAfterMaxUsed();                     // use first free if exists
        else
            incHighest = false;
    }
    else
        guid = sObjectMgr->GetGenerator<HighGuid::Player>().GetNextAfterMaxUsed();

    // normalize the name if specified and check if it exists
    if (!normalizePlayerName(name))
        name.clear();

    if (ObjectMgr::CheckPlayerName(name, sWorld->GetDefaultDbcLocale(), true) == CHAR_NAME_SUCCESS)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
        stmt->setString(0, name);
        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
            name.clear();                                       // use the one from the dump
    }
    else
        name.clear();

    // name encoded or empty

    snprintf(newguid, 20, UI64FMTD, guid);
    snprintf(chraccount, 20, "%u", account);

    DumpGuidMap items;
    DumpGuidMap mails;
    char buf[32000] = "";

    typedef std::map<uint32 /*old*/, uint32 /*new*/> PetIds;
    PetIds petIds;

    uint8 gender = GENDER_NONE;
    uint8 race = RACE_NONE;
    uint8 playerClass = 0;
    uint8 level = 1;

    ObjectGuid::LowType itemLowGuidOffset = sObjectMgr->GetGenerator<HighGuid::Item>().GetNextAfterMaxUsed();

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    while (!feof(fin))
    {
        if (!fgets(buf, 32000, fin))
        {
            if (feof(fin))
                break;
            ROLLBACK(DUMP_FILE_BROKEN);
        }

        std::string line; line.assign(buf);

        // skip empty strings
        size_t nw_pos = line.find_first_not_of(" \t\n\r\7");
        if (nw_pos == std::string::npos)
            continue;

        // skip logfile-side dump start notice, the important notes and dump end notices
        if ((line.substr(nw_pos, 16) == "== START DUMP ==") ||
            (line.substr(nw_pos, 15) == "IMPORTANT NOTE:") ||
            (line.substr(nw_pos, 14) == "== END DUMP =="))
            continue;

        // add required_ check
        /*
        if (line.substr(nw_pos, 41) == "UPDATE character_db_version SET required_")
        {
            if (!CharacterDatabase.Execute(line.c_str()))
                ROLLBACK(DUMP_FILE_BROKEN);

            continue;
        }
        */

        // determine table name and load type
        std::string tn = GetTableName(line);
        if (tn.empty())
        {
            TC_LOG_ERROR("misc", "LoadPlayerDump: Can't extract table name from line: '%s'!", line.c_str());
            ROLLBACK(DUMP_FILE_BROKEN);
        }

        DumpTableType type = DumpTableType(0);
        size_t i;
        for (i = 0; i < dumpTablesCount; ++i)
        {
            if (tn == dumpTables[i].name)
            {
                type = dumpTables[i].type;
                break;
            }
        }

        if (i == dumpTablesCount)
        {
            TC_LOG_ERROR("misc", "LoadPlayerDump: Unknown table: '%s'!", tn.c_str());
            ROLLBACK(DUMP_FILE_BROKEN);
        }

        // change the data to server values
        switch (type)
        {
            case DTT_CHARACTER:
            {
                if (!ChangeNth(line, GetColNumber(tn, "guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                if (!ChangeNth(line, GetColNumber(tn, "account"), chraccount))
                    ROLLBACK(DUMP_FILE_BROKEN);

                race = uint8(atoul(GetNth(line, GetColNumber(tn, "race")).c_str()));
                playerClass = uint8(atoul(GetNth(line, GetColNumber(tn, "class")).c_str()));
                gender = uint8(atoul(GetNth(line, GetColNumber(tn, "gender")).c_str()));
                level = uint8(atoul(GetNth(line, GetColNumber(tn, "level")).c_str()));
                if (name.empty())
                {
                    // check if the original name already exists
                    name = GetNth(line, GetColNumber(tn, "name"));

                    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
                    stmt->setString(0, name);
                    PreparedQueryResult result = CharacterDatabase.Query(stmt);

                    if (result)
                        if (!ChangeNth(line, GetColNumber(tn, "at_login"), "1"))      // characters.at_login set to "rename on login"
                            ROLLBACK(DUMP_FILE_BROKEN);
                }
                else if (!ChangeNth(line, GetColNumber(tn, "name"), name.c_str()))
                    ROLLBACK(DUMP_FILE_BROKEN);

                const char null[5] = "NULL";
                if (!ChangeNth(line, GetColNumber(tn, "deleteInfos_Account"), null))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeNth(line, GetColNumber(tn, "deleteInfos_Name"), null))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeNth(line, GetColNumber(tn, "deleteDate"), null))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_CHAR_TABLE:
            {
                if (!ChangeNth(line, GetColNumber(tn, "guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_CURRENCY:
            {
                if (!ChangeNth(line, GetColNumber(tn, "CharacterGuid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_EQSET_TABLE:
            {
                if (!ChangeNth(line, GetColNumber(tn, "guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                char newSetGuid[24];
                snprintf(newSetGuid, 24, UI64FMTD, sObjectMgr->GenerateEquipmentSetGuid());
                if (!ChangeNth(line, GetColNumber(tn, "setguid"), newSetGuid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                for (uint8 slot = 0; slot < EQUIPMENT_SLOT_END; ++slot)
                    if (!ChangeGuid(line, GetColNumber(tn, "item" + std::to_string(slot)), items, itemLowGuidOffset, true))
                        ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_INVENTORY:
            {
                if (!ChangeNth(line, GetColNumber(tn, "guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                if (!ChangeGuid(line, GetColNumber(tn, "bag"), items, itemLowGuidOffset, true))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeGuid(line, GetColNumber(tn, "item"), items, itemLowGuidOffset))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_CHAR_TRANSMOG:
            {
                if (!ChangeNth(line, GetColNumber(tn, "guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                char newSetGuid[24];
                snprintf(newSetGuid, 24, UI64FMTD, sObjectMgr->GenerateEquipmentSetGuid());
                if (!ChangeNth(line, GetColNumber(tn, "setguid"), newSetGuid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_MAIL:
            {
                if (!ChangeGuid(line, GetColNumber(tn, "id"), mails, sObjectMgr->_mailId))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeNth(line, GetColNumber(tn, "receiver"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_MAIL_ITEM:
            {
                if (!ChangeGuid(line, GetColNumber(tn, "mail_id"), mails, sObjectMgr->_mailId))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeGuid(line, GetColNumber(tn, "item_guid"), items, itemLowGuidOffset))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeNth(line, GetColNumber(tn, "receiver"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_ITEM:
            {
                if (!ChangeGuid(line, GetColNumber(tn, "guid"), items, itemLowGuidOffset))
                   ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeNth(line, GetColNumber(tn, "owner_guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_ITEM_GIFT:
            {
                if (!ChangeNth(line, GetColNumber(tn, "guid"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeGuid(line, GetColNumber(tn, "item_guid"), items, itemLowGuidOffset))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_ITEM_TABLE:
            {
                if (!ChangeGuid(line, GetColNumber(tn, "itemGuid"), items, itemLowGuidOffset))
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_PET:
            {
                // store a map of old pet id to new inserted pet id for use by DTT_PET_TABLE tables
                std::string petIdStr = GetNth(line, GetColNumber(tn, "id"));

                uint32 currentPetId = atoul(petIdStr.c_str());

                PetIds::const_iterator petIdsItr = petIds.find(currentPetId);
                if (petIdsItr != petIds.end())              // duplicate pets
                    ROLLBACK(DUMP_FILE_BROKEN);

                uint32 newPetId = sObjectMgr->GeneratePetNumber();
                petIds[currentPetId] = newPetId;

                if (!ChangeNth(line, GetColNumber(tn, "id"), std::to_string(newPetId).c_str()))
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!ChangeNth(line, GetColNumber(tn, "owner"), newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                break;
            }
            case DTT_PET_TABLE:                             // pet_aura, pet_spell, pet_spell_cooldown
            {
                std::string petIdStr = GetNth(line, GetColNumber(tn, "id"));

                // lookup currpetid and match to new inserted pet id
                PetIds::const_iterator petIdsItr = petIds.find(atoul(petIdStr.c_str()));
                if (petIdsItr == petIds.end())              // couldn't find new inserted id
                    ROLLBACK(DUMP_FILE_BROKEN);

                if (!ChangeNth(line, GetColNumber(tn, "guid"), std::to_string(petIdsItr->second).c_str()))
                    ROLLBACK(DUMP_FILE_BROKEN);

                break;
            }
            default:
                TC_LOG_ERROR("misc", "Unknown dump table type: %u", type);
                break;
        }

        fixNULLfields(line);

        trans->Append(line.c_str());
    }

    CharacterDatabase.CommitTransaction(trans);

    // in case of name conflict player has to rename at login anyway
    sWorld->AddCharacterInfo(ObjectGuid::Create<HighGuid::Player>(guid), account, name, gender, race, playerClass, level, false);

    sObjectMgr->GetGenerator<HighGuid::Item>().Set(sObjectMgr->GetGenerator<HighGuid::Item>().GetNextAfterMaxUsed() + items.size());
    sObjectMgr->_mailId     += mails.size();

    if (incHighest)
        sObjectMgr->GetGenerator<HighGuid::Player>().Generate();

    fclose(fin);

    return DUMP_SUCCESS;
}
