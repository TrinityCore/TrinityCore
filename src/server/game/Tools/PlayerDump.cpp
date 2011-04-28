/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "PlayerDump.h"
#include "DatabaseEnv.h"
#include "UpdateFields.h"
#include "ObjectMgr.h"
#include "AccountMgr.h"

#define DUMP_TABLE_COUNT 27
struct DumpTable
{
    char const* name;
    DumpTableType type;
};

static DumpTable dumpTables[DUMP_TABLE_COUNT] =
{
    { "characters",                       DTT_CHARACTER  },
    { "character_account_data",           DTT_CHAR_TABLE },
    { "character_achievement",            DTT_CHAR_TABLE },
    { "character_achievement_progress",   DTT_CHAR_TABLE },
    { "character_action",                 DTT_CHAR_TABLE },
    { "character_aura",                   DTT_CHAR_TABLE },
    { "character_declinedname",           DTT_CHAR_TABLE },
    { "character_equipmentsets",          DTT_EQSET_TABLE},
    { "character_gifts",                  DTT_ITEM_GIFT  },
    { "character_glyphs",                 DTT_CHAR_TABLE },
    { "character_homebind",               DTT_CHAR_TABLE },
    { "character_inventory",              DTT_INVENTORY  },
    { "character_pet",                    DTT_PET        },
    { "character_pet_declinedname",       DTT_PET        },
    { "character_queststatus",            DTT_CHAR_TABLE },
    { "character_queststatus_rewarded",   DTT_CHAR_TABLE },
    { "character_reputation",             DTT_CHAR_TABLE },
    { "character_skills",                 DTT_CHAR_TABLE },
    { "character_spell",                  DTT_CHAR_TABLE },
    { "character_spell_cooldown",         DTT_CHAR_TABLE },
    { "character_talent",                 DTT_CHAR_TABLE },
    { "item_instance",                    DTT_ITEM       },
    { "mail",                             DTT_MAIL       },
    { "mail_items",                       DTT_MAIL_ITEM  },
    { "pet_aura",                         DTT_PET_TABLE  },
    { "pet_spell",                        DTT_PET_TABLE  },
    { "pet_spell_cooldown",               DTT_PET_TABLE  },
};

// Low level functions
static bool findtoknth(std::string &str, int n, std::string::size_type &s, std::string::size_type &e)
{
    int i; s = e = 0;
    std::string::size_type size = str.size();
    for (i = 1; s < size && i < n; s++) if (str[s] == ' ') ++i;
    if (i < n)
        return false;

    e = str.find(' ', s);

    return e != std::string::npos;
}

std::string gettoknth(std::string &str, int n)
{
    std::string::size_type s = 0, e = 0;
    if (!findtoknth(str, n, s, e))
        return "";

    return str.substr(s, e-s);
}

bool findnth(std::string &str, int n, std::string::size_type &s, std::string::size_type &e)
{
    s = str.find("VALUES ('")+9;
    if (s == std::string::npos) return false;

    do
    {
        e = str.find("'",s);
        if (e == std::string::npos) return false;
    } while (str[e-1] == '\\');

    for (int i = 1; i < n; ++i)
    {
        do
        {
            s = e+4;
            e = str.find("'",s);
            if (e == std::string::npos) return false;
        } while (str[e-1] == '\\');
    }
    return true;
}

std::string gettablename(std::string &str)
{
    std::string::size_type s = 13;
    std::string::size_type e = str.find(_TABLE_SIM_, s);
    if (e == std::string::npos)
        return "";

    return str.substr(s, e-s);
}

bool changenth(std::string &str, int n, const char *with, bool insert = false, bool nonzero = false)
{
    std::string::size_type s, e;
    if (!findnth(str,n,s,e))
        return false;

    if (nonzero && str.substr(s,e-s) == "0")
        return true;                                        // not an error
    if (!insert)
        str.replace(s,e-s, with);
    else
        str.insert(s, with);

    return true;
}

std::string getnth(std::string &str, int n)
{
    std::string::size_type s, e;
    if (!findnth(str,n,s,e))
        return "";

    return str.substr(s, e-s);
}

bool changetoknth(std::string &str, int n, const char *with, bool insert = false, bool nonzero = false)
{
    std::string::size_type s = 0, e = 0;
    if (!findtoknth(str, n, s, e))
        return false;
    if (nonzero && str.substr(s,e-s) == "0")
        return true;                                        // not an error
    if (!insert)
        str.replace(s, e-s, with);
    else
        str.insert(s, with);

    return true;
}

uint32 registerNewGuid(uint32 oldGuid, std::map<uint32, uint32> &guidMap, uint32 hiGuid)
{
    std::map<uint32, uint32>::const_iterator itr = guidMap.find(oldGuid);
    if (itr != guidMap.end())
        return itr->second;

    uint32 newguid = hiGuid + guidMap.size();
    guidMap[oldGuid] = newguid;
    return newguid;
}

bool changeGuid(std::string &str, int n, std::map<uint32, uint32> &guidMap, uint32 hiGuid, bool nonzero = false)
{
    char chritem[20];
    uint32 oldGuid = atoi(getnth(str, n).c_str());
    if (nonzero && oldGuid == 0)
        return true;                                        // not an error

    uint32 newGuid = registerNewGuid(oldGuid, guidMap, hiGuid);
    snprintf(chritem, 20, "%d", newGuid);

    return changenth(str, n, chritem, false, nonzero);
}

bool changetokGuid(std::string &str, int n, std::map<uint32, uint32> &guidMap, uint32 hiGuid, bool nonzero = false)
{
    char chritem[20];
    uint32 oldGuid = atoi(gettoknth(str, n).c_str());
    if (nonzero && oldGuid == 0)
        return true;                                        // not an error

    uint32 newGuid = registerNewGuid(oldGuid, guidMap, hiGuid);
    snprintf(chritem, 20, "%d", newGuid);

    return changetoknth(str, n, chritem, false, nonzero);
}

std::string CreateDumpString(char const* tableName, QueryResult result)
{
    if (!tableName || !result) return "";
    std::ostringstream ss;
    ss << "INSERT INTO "<< _TABLE_SIM_ << tableName << _TABLE_SIM_ << " VALUES (";
    Field *fields = result->Fetch();
    for (uint32 i = 0; i < result->GetFieldCount(); ++i)
    {
        if (i == 0) ss << "'";
        else ss << ", '";

        std::string s = fields[i].GetString();
        CharacterDatabase.escape_string(s);
        ss << s;

        ss << "'";
    }
    ss << ");";
    return ss.str();
}

std::string PlayerDumpWriter::GenerateWhereStr(char const* field, uint32 guid)
{
    std::ostringstream wherestr;
    wherestr << field << " = '" << guid << "'";
    return wherestr.str();
}

std::string PlayerDumpWriter::GenerateWhereStr(char const* field, GUIDs const& guids, GUIDs::const_iterator& itr)
{
    std::ostringstream wherestr;
    wherestr << field << " IN ('";
    for (; itr != guids.end(); ++itr)
    {
        wherestr << *itr;

        if (wherestr.str().size() > MAX_QUERY_LEN - 50)      // near to max query
        {
            ++itr;
            break;
        }

        GUIDs::const_iterator itr2 = itr;
        if (++itr2 != guids.end())
            wherestr << "','";
    }
    wherestr << "')";
    return wherestr.str();
}

void StoreGUID(QueryResult result,uint32 field,std::set<uint32>& guids)
{
    Field* fields = result->Fetch();
    uint32 guid = fields[field].GetUInt32();
    if (guid)
        guids.insert(guid);
}

void StoreGUID(QueryResult result,uint32 data,uint32 field, std::set<uint32>& guids)
{
    Field* fields = result->Fetch();
    std::string dataStr = fields[data].GetString();
    uint32 guid = atoi(gettoknth(dataStr, field).c_str());
    if (guid)
        guids.insert(guid);
}

// Writing - High-level functions
bool PlayerDumpWriter::DumpTable(std::string& dump, uint32 guid, char const*tableFrom, char const*tableTo, DumpTableType type)
{
    GUIDs const* guids = NULL;
    char const* fieldname = NULL;

    switch (type)
    {
        case DTT_ITEM:      fieldname = "guid";      guids = &items; break;
        case DTT_ITEM_GIFT: fieldname = "item_guid"; guids = &items; break;
        case DTT_PET:       fieldname = "owner";                     break;
        case DTT_PET_TABLE: fieldname = "guid";      guids = &pets;  break;
        case DTT_MAIL:      fieldname = "receiver";                  break;
        case DTT_MAIL_ITEM: fieldname = "mail_id";   guids = &mails; break;
        default:            fieldname = "guid";                      break;
    }

    // for guid set stop if set is empty
    if (guids && guids->empty())
        return true;                                        // nothing to do

    // setup for guids case start position
    GUIDs::const_iterator guids_itr;
    if (guids)
        guids_itr = guids->begin();

    do
    {
        std::string wherestr;

        if (guids)                                           // set case, get next guids string
            wherestr = GenerateWhereStr(fieldname,*guids,guids_itr);
        else                                                // not set case, get single guid string
            wherestr = GenerateWhereStr(fieldname,guid);

        QueryResult result = CharacterDatabase.PQuery("SELECT * FROM %s WHERE %s", tableFrom, wherestr.c_str());
        if (!result)
            return true;

        do
        {
            // collect guids
            switch (type)
            {
                case DTT_INVENTORY:
                    StoreGUID(result,3,items); break;       // item guid collection (character_inventory.item)
                case DTT_PET:
                    StoreGUID(result,0,pets);  break;       // pet petnumber collection (character_pet.id)
                case DTT_MAIL:
                    StoreGUID(result,0,mails);              // mail id collection (mail.id)
                case DTT_MAIL_ITEM:
                    StoreGUID(result,1,items); break;       // item guid collection (mail_items.item_guid)
                case DTT_CHARACTER:
                {
                    if (result->GetFieldCount() <= 67)      // avoid crashes on next check
                        return true;
                    if (result->Fetch()[67].GetUInt32())    // characters.deleteInfos_Account - if filled error
                        return false;
                    break;
                }
                default:                       break;
            }

            dump += CreateDumpString(tableTo, result);
            dump += "\n";
        }
        while (result->NextRow());
    }
    while (guids && guids_itr != guids->end());              // not set case iterate single time, set case iterate for all guids
    return true;
}

bool PlayerDumpWriter::GetDump(uint32 guid, std::string &dump)
{
    dump = "";

    dump += "IMPORTANT NOTE: THIS DUMPFILE IS MADE FOR USE WITH THE 'PDUMP' COMMAND ONLY - EITHER THROUGH INGAME CHAT OR ON CONSOLE!\n";
    dump += "IMPORTANT NOTE: DO NOT apply it directly - it will irreversibly DAMAGE and CORRUPT your database! You have been warned!\n\n";

    for (int i = 0; i < DUMP_TABLE_COUNT; ++i)
        if (!DumpTable(dump, guid, dumpTables[i].name, dumpTables[i].name, dumpTables[i].type))
            return false;

    // TODO: Add instance/group..
    // TODO: Add a dump level option to skip some non-important tables

    return true;
}

DumpReturn PlayerDumpWriter::WriteDump(const std::string& file, uint32 guid)
{
    FILE *fout = fopen(file.c_str(), "w");
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

void fixNULLfields(std::string &line)
{
    std::string nullString("'NULL'");
    size_t pos = line.find(nullString);
    while (pos != std::string::npos)
    {
        line.replace(pos, nullString.length(), "NULL");
        pos = line.find(nullString);
    }
}

DumpReturn PlayerDumpReader::LoadDump(const std::string& file, uint32 account, std::string name, uint32 guid)
{
    uint32 charcount = sAccountMgr->GetCharactersCount(account);
    if (charcount >= 10)
        return DUMP_TOO_MANY_CHARS;

    FILE *fin = fopen(file.c_str(), "r");
    if (!fin)
        return DUMP_FILE_OPEN_ERROR;

    QueryResult result = QueryResult(NULL);
    char newguid[20], chraccount[20], newpetid[20], currpetid[20], lastpetid[20];

    // make sure the same guid doesn't already exist and is safe to use
    bool incHighest = true;
    if (guid != 0 && guid < sObjectMgr->m_hiCharGuid)
    {
        result = CharacterDatabase.PQuery("SELECT 1 FROM characters WHERE guid = '%d'", guid);
        if (result)
            guid = sObjectMgr->m_hiCharGuid;                     // use first free if exists
        else incHighest = false;
    }
    else
        guid = sObjectMgr->m_hiCharGuid;

    // normalize the name if specified and check if it exists
    if (!normalizePlayerName(name))
        name = "";

    if (ObjectMgr::CheckPlayerName(name,true) == CHAR_NAME_SUCCESS)
    {
        CharacterDatabase.escape_string(name);              // for safe, we use name only for sql quearies anyway
        result = CharacterDatabase.PQuery("SELECT 1 FROM characters WHERE name = '%s'", name.c_str());
        if (result)
            name = "";                                      // use the one from the dump
    }
    else
        name = "";

    // name encoded or empty

    snprintf(newguid, 20, "%d", guid);
    snprintf(chraccount, 20, "%d", account);
    snprintf(newpetid, 20, "%d", sObjectMgr->GeneratePetNumber());
    snprintf(lastpetid, 20, "%s", "");

    std::map<uint32,uint32> items;
    std::map<uint32,uint32> mails;
    char buf[32000] = "";

    typedef std::map<uint32, uint32> PetIds;                // old->new petid relation
    typedef PetIds::value_type PetIdsPair;
    PetIds petids;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    while (!feof(fin))
    {
        if (!fgets(buf, 32000, fin))
        {
            if (feof(fin)) break;
            ROLLBACK(DUMP_FILE_BROKEN);
        }

        std::string line; line.assign(buf);

        // skip empty strings
        size_t nw_pos = line.find_first_not_of(" \t\n\r\7");
        if (nw_pos == std::string::npos)
            continue;

        // skip logfile-side dump start notice, the important notes and dump end notices
        if ((line.substr(nw_pos,16) == "== START DUMP ==") ||
            (line.substr(nw_pos,15) == "IMPORTANT NOTE:") ||
            (line.substr(nw_pos,14) == "== END DUMP =="))
            continue;

        // add required_ check
        /*
        if (line.substr(nw_pos,41) == "UPDATE character_db_version SET required_")
        {
            if (!CharacterDatabase.Execute(line.c_str()))
                ROLLBACK(DUMP_FILE_BROKEN);

            continue;
        }
        */

        // determine table name and load type
        std::string tn = gettablename(line);
        if (tn.empty())
        {
            sLog->outError("LoadPlayerDump: Can't extract table name from line: '%s'!", line.c_str());
            ROLLBACK(DUMP_FILE_BROKEN);
        }

        DumpTableType type = DumpTableType(0);
        uint8 i;
        for (i = 0; i < DUMP_TABLE_COUNT; ++i)
        {
            if (tn == dumpTables[i].name)
            {
                type = dumpTables[i].type;
                break;
            }
        }

        if (i == DUMP_TABLE_COUNT)
        {
            sLog->outError("LoadPlayerDump: Unknown table: '%s'!", tn.c_str());
            ROLLBACK(DUMP_FILE_BROKEN);
        }

        // change the data to server values
        switch(type)
        {
            case DTT_CHARACTER:
            {
                if (!changenth(line, 1, newguid))           // characters.guid update
                    ROLLBACK(DUMP_FILE_BROKEN);

                if (!changenth(line, 2, chraccount))        // characters.account update
                    ROLLBACK(DUMP_FILE_BROKEN);

                if (name == "")
                {
                    // check if the original name already exists
                    name = getnth(line, 3);
                    CharacterDatabase.escape_string(name);

                    result = CharacterDatabase.PQuery("SELECT 1 FROM characters WHERE name = '%s'", name.c_str());
                    if (result)
                    {
                        if (!changenth(line, 37, "1"))       // characters.at_login set to "rename on login"
                            ROLLBACK(DUMP_FILE_BROKEN);
                    }
                }
                else if (!changenth(line, 3, name.c_str())) // characters.name
                    ROLLBACK(DUMP_FILE_BROKEN);

                const char null[5] = "NULL";
                if (!changenth(line, 68, null))             // characters.deleteInfos_Account
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!changenth(line, 69, null))             // characters.deleteInfos_Name
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!changenth(line, 70, null))             // characters.deleteDate
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_CHAR_TABLE:
            {
                if (!changenth(line, 1, newguid))           // character_*.guid update
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_EQSET_TABLE:
            {
                if (!changenth(line, 1, newguid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // character_equipmentsets.guid

                char newSetGuid[24];
                snprintf(newSetGuid, 24, UI64FMTD, sObjectMgr->GenerateEquipmentSetGuid());
                if (!changenth(line, 2, newSetGuid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // character_equipmentsets.setguid
                break;
            }
            case DTT_INVENTORY:
            {
                if (!changenth(line, 1, newguid))           // character_inventory.guid update
                    ROLLBACK(DUMP_FILE_BROKEN);

                if (!changeGuid(line, 2, items, sObjectMgr->m_hiItemGuid, true))
                    ROLLBACK(DUMP_FILE_BROKEN);             // character_inventory.bag update
                if (!changeGuid(line, 4, items, sObjectMgr->m_hiItemGuid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // character_inventory.item update
                break;
            }
            case DTT_MAIL:                                  // mail
            {
                if (!changeGuid(line, 1, mails, sObjectMgr->m_mailid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // mail.id update
                if (!changenth(line, 6, newguid))           // mail.receiver update
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_MAIL_ITEM:                             // mail_items
            {
                if (!changeGuid(line, 1, mails, sObjectMgr->m_mailid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // mail_items.id
                if (!changeGuid(line, 2, items, sObjectMgr->m_hiItemGuid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // mail_items.item_guid
                if (!changenth(line, 3, newguid))           // mail_items.receiver
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_ITEM:
            {
                // item, owner, data field:item, owner guid
                if (!changeGuid(line, 1, items, sObjectMgr->m_hiItemGuid))
                   ROLLBACK(DUMP_FILE_BROKEN);              // item_instance.guid update
                if (!changenth(line, 3, newguid))           // item_instance.owner_guid update
                    ROLLBACK(DUMP_FILE_BROKEN);
                break;
            }
            case DTT_ITEM_GIFT:
            {
                if (!changenth(line, 1, newguid))           // character_gifts.guid update
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!changeGuid(line, 2, items, sObjectMgr->m_hiItemGuid))
                    ROLLBACK(DUMP_FILE_BROKEN);             // character_gifts.item_guid update
                break;
            }
            case DTT_PET:
            {
                //store a map of old pet id to new inserted pet id for use by type 5 tables
                snprintf(currpetid, 20, "%s", getnth(line, 1).c_str());
                if (*lastpetid == '\0')
                    snprintf(lastpetid, 20, "%s", currpetid);
                if (strcmp(lastpetid,currpetid) != 0)
                {
                    snprintf(newpetid, 20, "%d", sObjectMgr->GeneratePetNumber());
                    snprintf(lastpetid, 20, "%s", currpetid);
                }

                std::map<uint32, uint32> :: const_iterator petids_iter = petids.find(atoi(currpetid));

                if (petids_iter == petids.end())
                {
                    petids.insert(PetIdsPair(atoi(currpetid), atoi(newpetid)));
                }

                if (!changenth(line, 1, newpetid))          // character_pet.id update
                    ROLLBACK(DUMP_FILE_BROKEN);
                if (!changenth(line, 3, newguid))           // character_pet.owner update
                    ROLLBACK(DUMP_FILE_BROKEN);

                break;
            }
            case DTT_PET_TABLE:                             // pet_aura, pet_spell, pet_spell_cooldown
            {
                snprintf(currpetid, 20, "%s", getnth(line, 1).c_str());

                // lookup currpetid and match to new inserted pet id
                std::map<uint32, uint32> :: const_iterator petids_iter = petids.find(atoi(currpetid));
                if (petids_iter == petids.end())             // couldn't find new inserted id
                    ROLLBACK(DUMP_FILE_BROKEN);

                snprintf(newpetid, 20, "%d", petids_iter->second);

                if (!changenth(line, 1, newpetid))
                    ROLLBACK(DUMP_FILE_BROKEN);

                break;
            }
            default:
                sLog->outError("Unknown dump table type: %u",type);
                break;
        }

        fixNULLfields(line);

        trans->Append(line.c_str());
    }

    CharacterDatabase.CommitTransaction(trans);

    sObjectMgr->m_hiItemGuid += items.size();
    sObjectMgr->m_mailid     += mails.size();

    if (incHighest)
        ++sObjectMgr->m_hiCharGuid;

    fclose(fin);

    return DUMP_SUCCESS;
}

