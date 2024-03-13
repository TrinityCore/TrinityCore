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

#include "PlayerDump.h"
#include "AccountMgr.h"
#include "CharacterCache.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "StringConvert.h"
#include "World.h"
#include <boost/algorithm/string/find.hpp>
#include <fstream>
#include <sstream>

// static data
enum GuidType : uint8
{
    // 32 bit long guids
    GUID_TYPE_ACCOUNT,
    GUID_TYPE_MAIL,

    // 64 bit long guids
    GUID_TYPE_CHAR,
    GUID_TYPE_EQUIPMENT_SET,
    GUID_TYPE_ITEM,
    GUID_TYPE_PET,

    // special types
    GUID_TYPE_NULL // set to null
};

// for RAII
struct FileCloser
{
    void operator()(FILE* f) const
    {
        if (f)
            fclose(f);
    }
};
typedef std::unique_ptr<FILE, FileCloser> FileHandle;

inline FileHandle GetFileHandle(char const* path, char const* mode)
{
    return FileHandle(fopen(path, mode), FileCloser());
}

struct BaseTable
{
    char const* TableName;
    char const* PrimaryKey;
    char const* PlayerGuid;

    GuidType StoredType;
};

BaseTable const BaseTables[] =
{
    { "character_pet",              "id",      "owner",      GUID_TYPE_PET           },
    { "mail",                       "id",      "receiver",   GUID_TYPE_MAIL          },
    { "item_instance",              "guid",    "owner_guid", GUID_TYPE_ITEM          },

    { "character_equipmentsets",    "setguid", "guid",       GUID_TYPE_EQUIPMENT_SET },
    { "character_transmog_outfits", "setguid", "guid",       GUID_TYPE_EQUIPMENT_SET }
};

struct DumpTable
{
    char const* Name;
    DumpTableType Type;
};

DumpTable const DumpTables[] =
{
    { "characters",                       DTT_CHARACTER  },
    { "character_account_data",           DTT_CHAR_TABLE },
    { "character_achievement",            DTT_CHAR_TABLE },
    { "character_achievement_progress",   DTT_CHAR_TABLE },
    { "character_action",                 DTT_CHAR_TABLE },
    { "character_aura",                   DTT_CHAR_TABLE },
    { "character_aura_effect",            DTT_CHAR_TABLE },
    { "character_cuf_profiles",           DTT_CHAR_TABLE },
    { "character_currency",               DTT_CURRENCY   },
    { "character_declinedname",           DTT_CHAR_TABLE },
    { "character_favorite_auctions",      DTT_CHAR_TABLE },
    { "character_fishingsteps",           DTT_CHAR_TABLE },
    { "character_glyphs",                 DTT_CHAR_TABLE },
    { "character_homebind",               DTT_CHAR_TABLE },
    { "character_inventory",              DTT_INVENTORY  },
    { "character_pet",                    DTT_PET        },
    { "character_pet_declinedname",       DTT_PET        },
    { "character_pvp_talent",             DTT_CHAR_TABLE },
    { "character_queststatus",            DTT_CHAR_TABLE },
    { "character_queststatus_daily",      DTT_CHAR_TABLE },
    { "character_queststatus_monthly",    DTT_CHAR_TABLE },
    { "character_queststatus_objectives", DTT_CHAR_TABLE },
    { "character_queststatus_objectives_criteria", DTT_CHAR_TABLE },
    { "character_queststatus_objectives_criteria_progress", DTT_CHAR_TABLE },
    { "character_queststatus_rewarded",   DTT_CHAR_TABLE },
    { "character_queststatus_seasonal",   DTT_CHAR_TABLE },
    { "character_queststatus_weekly",     DTT_CHAR_TABLE },
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
    { "pet_aura",                         DTT_PET_TABLE  }, // must be after character_pet
    { "pet_aura_effect",                  DTT_PET_TABLE  }, // must be after character_pet
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

uint32 const DUMP_TABLE_COUNT = std::extent<decltype(DumpTables)>::value;

// helper class to dump sql queries to a printable string
class StringTransaction
{
    public:
        StringTransaction() : _buf() { }

        void Append(char const* sql)
        {
            std::ostringstream oss;
            oss << sql << '\n';
            _buf += oss.str();
        }

        char const* GetBuffer() const
        {
            return _buf.c_str();
        }

    private:
        std::string _buf;
};

// dynamic data, loaded at startup
struct TableField
{
    std::string FieldName;

    GuidType FieldGuidType = GUID_TYPE_ACCOUNT;
    bool IsDependentField = false;
    bool IsBinaryField = false;
};

struct TableStruct
{
    std::string TableName;
    std::string WhereFieldName;
    std::vector<TableField> TableFields;

    // for lookup
    std::unordered_map<std::string /*fieldName*/, int32 /*index*/> FieldIndices;
};

std::vector<TableStruct> CharacterTables;

inline bool StringsEqualCaseInsensitive(std::string const& left, std::string const& right)
{
    std::string upperLeftString = left;
    bool leftResult = Utf8ToUpperOnlyLatin(upperLeftString);
    ASSERT(leftResult);

    std::string upperRightString = right;
    bool rightResult = Utf8ToUpperOnlyLatin(upperRightString);
    ASSERT(rightResult);

    return upperLeftString == upperRightString;
}

inline auto FindColumnByName(TableStruct& tableStruct, std::string const& columnName) -> decltype(tableStruct.TableFields.begin())
{
    return std::find_if(tableStruct.TableFields.begin(), tableStruct.TableFields.end(), [columnName](TableField const& tableField) -> bool
    {
        return StringsEqualCaseInsensitive(tableField.FieldName, columnName);
    });
}

inline int32 GetColumnIndexByName(TableStruct const& tableStruct, std::string const& columnName)
{
    auto itr = tableStruct.FieldIndices.find(columnName);
    if (itr == tableStruct.FieldIndices.end())
        return -1;

    return itr->second;
}

inline void MarkDependentColumn(TableStruct& tableStruct, std::string const& columnName, GuidType dependentType)
{
    auto itr = FindColumnByName(tableStruct, columnName);
    if (itr == tableStruct.TableFields.end())
    {
        TC_LOG_FATAL("server.loading", "Column `{}` declared in table `{}` marked as dependent but doesn't exist, PlayerDump will not work properly, please update table definitions",
            columnName, tableStruct.TableName);
        ABORT();
        return;
    }

    if (itr->IsDependentField)
    {
        TC_LOG_FATAL("server.loading", "Attempt to mark column `{}` in table `{}` as dependent column but already marked! please check your code.",
            columnName, tableStruct.TableName);
        ABORT();
        return;
    }

    itr->IsDependentField = true;
    itr->FieldGuidType = dependentType;
}

inline void MarkWhereField(TableStruct& tableStruct, std::string const& whereField)
{
    ASSERT(tableStruct.WhereFieldName.empty());

    auto whereFieldItr = FindColumnByName(tableStruct, whereField);
    if (whereFieldItr == tableStruct.TableFields.end())
    {
        TC_LOG_FATAL("server.loading", "Column name `{}` set as 'WHERE' column for table `{}` doesn't exist. PlayerDump won't work properly",
            whereField, tableStruct.TableName);
        ABORT();
        return;
    }

    tableStruct.WhereFieldName = whereField;
}

inline void AssertBaseTable(BaseTable const& baseTable)
{
    auto itr = std::find_if(CharacterTables.begin(), CharacterTables.end(), [baseTable](TableStruct const& tableStruct) -> bool
    {
        return StringsEqualCaseInsensitive(tableStruct.TableName, baseTable.TableName);
    });

    ASSERT(itr != CharacterTables.end());

    auto columnItr = FindColumnByName(*itr, baseTable.PrimaryKey);
    ASSERT(columnItr != itr->TableFields.end());

    columnItr = FindColumnByName(*itr, baseTable.PlayerGuid);
    ASSERT(columnItr != itr->TableFields.end());
}

void PlayerDump::InitializeTables()
{
    uint32 oldMSTime = getMSTime();

    for (DumpTable const& dumpTable : DumpTables)
    {
        TableStruct t;
        t.TableName = dumpTable.Name;

        QueryResult result = CharacterDatabase.PQuery("DESC {}", dumpTable.Name);
        // prepared statement is correct (checked at startup) so table must exist
        ASSERT(result);

        int32 i = 0;
        do
        {
            std::string columnName = (*result)[0].GetString();
            std::string typeName = (*result)[1].GetString();
            t.FieldIndices.emplace(columnName, i++);

            TableField f;
            f.FieldName = columnName;
            f.IsBinaryField = !boost::ifind_first(typeName, "binary").empty() || !boost::ifind_first(typeName, "blob").empty();

            bool toUpperResult = Utf8ToUpperOnlyLatin(columnName);
            ASSERT(toUpperResult);

            t.TableFields.emplace_back(std::move(f));
        } while (result->NextRow());

        switch (dumpTable.Type)
        {
            case DTT_CHARACTER:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_CHAR);
                MarkDependentColumn(t, "account", GUID_TYPE_ACCOUNT);

                MarkDependentColumn(t, "deleteInfos_Account", GUID_TYPE_NULL);
                MarkDependentColumn(t, "deleteInfos_Name", GUID_TYPE_NULL);
                MarkDependentColumn(t, "deleteDate", GUID_TYPE_NULL);
                break;
            case DTT_CHAR_TABLE:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_CHAR);
                break;
            case DTT_CURRENCY:
                MarkWhereField(t, "CharacterGuid");

                MarkDependentColumn(t, "CharacterGuid", GUID_TYPE_CHAR);
                break;
            case DTT_EQSET_TABLE:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_CHAR);
                MarkDependentColumn(t, "setguid", GUID_TYPE_EQUIPMENT_SET);

                // item0 - item18
                for (uint32 j = 0; j < EQUIPMENT_SLOT_END; ++j)
                {
                    std::string itColumn = Trinity::StringFormat("item{}", j);
                    MarkDependentColumn(t, itColumn, GUID_TYPE_ITEM);
                }
                break;
            case DTT_INVENTORY:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_CHAR);
                MarkDependentColumn(t, "bag", GUID_TYPE_ITEM);
                MarkDependentColumn(t, "item", GUID_TYPE_ITEM);
                break;
            case DTT_CHAR_TRANSMOG:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_CHAR);
                MarkDependentColumn(t, "setguid", GUID_TYPE_EQUIPMENT_SET);
                break;
            case DTT_MAIL:
                MarkWhereField(t, "receiver");

                MarkDependentColumn(t, "id", GUID_TYPE_MAIL);
                MarkDependentColumn(t, "receiver", GUID_TYPE_CHAR);
                break;
            case DTT_MAIL_ITEM:
                MarkWhereField(t, "mail_id");

                MarkDependentColumn(t, "mail_id", GUID_TYPE_MAIL);
                MarkDependentColumn(t, "item_guid", GUID_TYPE_ITEM);
                MarkDependentColumn(t, "receiver", GUID_TYPE_CHAR);
                break;
            case DTT_ITEM:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_ITEM);
                MarkDependentColumn(t, "owner_guid", GUID_TYPE_CHAR);
                break;
            case DTT_ITEM_GIFT:
                MarkWhereField(t, "item_guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_CHAR);
                MarkDependentColumn(t, "item_guid", GUID_TYPE_ITEM);
                break;
            case DTT_ITEM_TABLE:
                MarkWhereField(t, "itemGuid");

                MarkDependentColumn(t, "itemGuid", GUID_TYPE_ITEM);
                break;
            case DTT_PET:
                MarkWhereField(t, "owner");

                MarkDependentColumn(t, "id", GUID_TYPE_PET);
                MarkDependentColumn(t, "owner", GUID_TYPE_CHAR);
                break;
            case DTT_PET_TABLE:
                MarkWhereField(t, "guid");

                MarkDependentColumn(t, "guid", GUID_TYPE_PET);
                break;
            default:
                TC_LOG_FATAL("server.loading", "Wrong dump table type {}, probably added a new table type without updating code", uint32(dumpTable.Type));
                ABORT();
                return;
        }

        CharacterTables.emplace_back(std::move(t));
    }

    // perform some sanity checks
    for (TableStruct const& tableStruct : CharacterTables)
    {
        if (tableStruct.WhereFieldName.empty())
        {
            TC_LOG_FATAL("server.loading", "Table `{}` defined in player dump doesn't have a WHERE query field", tableStruct.TableName);
            ABORT();
        }
    }

    for (BaseTable const& baseTable : BaseTables)
        AssertBaseTable(baseTable);

    ASSERT(CharacterTables.size() == DUMP_TABLE_COUNT);

    TC_LOG_INFO("server.loading", ">> Initialized tables for PlayerDump in {} ms.", GetMSTimeDiffToNow(oldMSTime));
}

// Low level functions
inline bool FindColumn(TableStruct const& ts, std::string const& str, std::string const& column, std::string::size_type& s, std::string::size_type& e)
{
    int32 columnIndex = GetColumnIndexByName(ts, column);
    if (columnIndex == -1)
        return false;

    // array indices start at 0, compensate
    ++columnIndex;

    s = str.find("VALUES (");
    if (s == std::string::npos)
        return false;
    s += 8;
    e = s;

    bool isQuoted = str[s] == '\'';
    if (isQuoted)
    {
        ++s;
        ++e;
        // find first unescaped quote
        do
        {
            e = str.find('\'', e);
            if (e == std::string::npos)
                return false;
            if (str[e - 1] == '\\')
                continue;
            if (e + 1 < str.length() && str[e + 1] == '\'')
            {
                ++e;
                continue;
            }
            break;
        } while (true);
    }
    else
        e = str.find_first_of(",)", e);

    for (int32 i = 1; i < columnIndex; ++i)
    {
        // if previous value was quoted, move old e to comma
        if (isQuoted)
            ++e;

        // move past ", "
        s = e + 2;
        e = s;
        isQuoted = str[s] == '\'';
        if (isQuoted)
        {
            ++s;
            ++e;
            // find first unescaped quote
            do
            {
                e = str.find('\'', e);
                if (e == std::string::npos)
                    return false;
                if (str[e - 1] == '\\')
                    continue;
                if (e + 1 < str.length() && str[e + 1] == '\'')
                {
                    ++e;
                    continue;
                }
                break;
            } while (str[e - 1] == '\\');
        }
        else
            e = str.find_first_of(",)", e);
    }

    return true;
}

inline std::string GetTableName(std::string const& str)
{
    // length of "INSERT INTO `"
    static std::string::size_type const s = 13;
    std::string::size_type e = str.find('`', s);
    if (e == std::string::npos)
        return "";

    return str.substr(s, e - s);
}

inline bool ValidateFields(TableStruct const& ts, std::string const& str, size_t lineNumber)
{
    std::string::size_type s = str.find("` VALUES (");
    if (s != std::string::npos) // old dump format (no column names)
        return true;

    // new format has insert with columns, need validation else we risk executing an invalid query
    s = str.find("` (`");
    if (s == std::string::npos)
    {
        TC_LOG_ERROR("misc", "LoadPlayerDump: (line {}) dump format not recognized.", lineNumber);
        return false;
    }
    s += 4;

    std::string::size_type valPos = str.find("VALUES ('");
    std::string::size_type e = str.find('`', s);
    if (e == std::string::npos || valPos == std::string::npos)
    {
        TC_LOG_ERROR("misc", "LoadPlayerDump: (line {}) unexpected end of line", lineNumber);
        return false;
    }

    do
    {
        std::string column = str.substr(s, e - s);
        int32 columnIndex = GetColumnIndexByName(ts, column);
        if (columnIndex == -1)
        {
            TC_LOG_ERROR("misc", "LoadPlayerDump: (line {}) unknown column name `{}` for table `{}`, aborting due to incompatible DB structure.", lineNumber, column, ts.TableName);
            return false;
        }

        // length of "`, `"
        s = e + 4;
        e = str.find('`', s);
    } while (e < valPos);

    return true;
}

inline bool ChangeColumn(TableStruct const& ts, std::string& str, std::string const& column, std::string const& with, bool allowZero = false)
{
    std::string::size_type s, e;
    if (!FindColumn(ts, str, column, s, e))
        return false;

    if (allowZero && str.substr(s, e - s) == "0")
        return true;                                        // not an error

    str.replace(s, e - s, with);
    return true;
}

inline std::string GetColumn(TableStruct const& ts, std::string& str, std::string const& column)
{
    std::string::size_type s, e;
    if (!FindColumn(ts, str, column, s, e))
        return "";

    return str.substr(s, e - s);
}

template <typename T, template<class, class, class...> class MapType, class... Rest>
inline T RegisterNewGuid(T oldGuid, MapType<T, T, Rest...>& guidMap, T guidOffset)
{
    auto itr = guidMap.find(oldGuid);
    if (itr != guidMap.end())
        return itr->second;

    T newguid = guidOffset + T(guidMap.size());
    guidMap.emplace(oldGuid, newguid);
    return newguid;
}

template <typename T, template<class, class, class...> class MapType, class... Rest>
inline bool ChangeGuid(TableStruct const& ts, std::string& str, std::string const& column, MapType<T, T, Rest...>& guidMap, T guidOffset, bool allowZero = false)
{
    T oldGuid = Trinity::StringTo<T>(GetColumn(ts, str, column)).template value_or<T>(0);
    if (allowZero && !oldGuid)
        return true;                                        // not an error

    std::string chritem;
    T newGuid = RegisterNewGuid(oldGuid, guidMap, guidOffset);
    chritem = std::to_string(newGuid);

    return ChangeColumn(ts, str, column, chritem, allowZero);
}

inline void AppendTableDump(StringTransaction& trans, TableStruct const& tableStruct, QueryResult result)
{
    if (!result)
        return;

    do
    {
        std::ostringstream ss;
        ss << "INSERT INTO `" << tableStruct.TableName << "` (";
        for (auto itr = tableStruct.TableFields.begin(); itr != tableStruct.TableFields.end();)
        {
            ss << '`' << itr->FieldName << '`';
            ++itr;

            if (itr != tableStruct.TableFields.end())
                ss << ", ";
        }
        ss << ") VALUES (";

        uint32 const fieldSize = uint32(tableStruct.TableFields.size());
        Field* fields = result->Fetch();

        for (uint32 i = 0; i < fieldSize;)
        {
            if (fields[i].IsNull())
                ss << "'NULL'";
            else
            {
                if (!tableStruct.TableFields[i].IsBinaryField)
                {
                    std::string s(fields[i].GetString());
                    CharacterDatabase.EscapeString(s);
                    ss << '\'' << s << '\'';
                }
                else
                {
                    std::vector<uint8> b(fields[i].GetBinary());

                    if (!b.empty())
                        ss << "0x" << ByteArrayToHexStr(b);
                    else
                        ss << '\'' << '\'';
                }
            }

            ++i;
            if (i != fieldSize)
                ss << ", ";
        }
        ss << ");";

        trans.Append(ss.str().c_str());
    } while (result->NextRow());
}

inline std::string GenerateWhereStr(std::string const& field, ObjectGuid::LowType guid)
{
    std::ostringstream whereStr;
    whereStr << field << " = '" << guid << '\'';
    return whereStr.str();
}

template <typename T, template<class, class...> class SetType, class... Rest>
inline std::string GenerateWhereStr(std::string const& field, SetType<T, Rest...> const& guidSet)
{
    std::ostringstream whereStr;
    whereStr << field << " IN ('";
    for (auto itr = guidSet.begin(); itr != guidSet.end();)
    {
        whereStr << *itr;
        ++itr;

        if (whereStr.str().size() > MAX_QUERY_LEN - 50)      // near to max query
            break;

        if (itr != guidSet.end())
            whereStr << "','";
    }
    whereStr << "')";
    return whereStr.str();
}

// Writing - High-level functions
void PlayerDumpWriter::PopulateGuids(ObjectGuid::LowType guid)
{
    for (BaseTable const& baseTable : BaseTables)
    {
        switch (baseTable.StoredType)
        {
            case GUID_TYPE_ITEM:
            case GUID_TYPE_MAIL:
            case GUID_TYPE_PET:
            case GUID_TYPE_EQUIPMENT_SET:
                break;
            default:
                return;
        }

        std::string whereStr = GenerateWhereStr(baseTable.PlayerGuid, guid);
        QueryResult result = CharacterDatabase.PQuery("SELECT {} FROM {} WHERE {}", baseTable.PrimaryKey, baseTable.TableName, whereStr);
        if (!result)
            continue;

        do
        {
            switch (baseTable.StoredType)
            {
                case GUID_TYPE_ITEM:
                    if (ObjectGuid::LowType itemLowGuid = (*result)[0].GetUInt32())
                        _items.insert(itemLowGuid);
                    break;
                case GUID_TYPE_MAIL:
                    if (uint32 mailLowGuid = (*result)[0].GetUInt32())
                        _mails.insert(mailLowGuid);
                    break;
                case GUID_TYPE_PET:
                    if (uint32 petLowGuid = (*result)[0].GetUInt32())
                        _pets.insert(petLowGuid);
                    break;
                case GUID_TYPE_EQUIPMENT_SET:
                    if (uint64 eqSetId = (*result)[0].GetUInt64())
                        _itemSets.insert(eqSetId);
                    break;
                default:
                    break;
            }
        } while (result->NextRow());
    }
}

bool PlayerDumpWriter::AppendTable(StringTransaction& trans, ObjectGuid::LowType guid, TableStruct const& tableStruct, DumpTable const& dumpTable)
{
    std::string whereStr;
    switch (dumpTable.Type)
    {
        case DTT_ITEM:
        case DTT_ITEM_GIFT:
        case DTT_ITEM_TABLE:
            if (_items.empty())
                return true;

            whereStr = GenerateWhereStr(tableStruct.WhereFieldName, _items);
            break;
        case DTT_PET_TABLE:
            if (_pets.empty())
                return true;

            whereStr = GenerateWhereStr(tableStruct.WhereFieldName, _pets);
            break;
        case DTT_MAIL_ITEM:
            if (_mails.empty())
                return true;

            whereStr = GenerateWhereStr(tableStruct.WhereFieldName, _mails);
            break;
        case DTT_EQSET_TABLE:
        case DTT_CHAR_TRANSMOG:
            if (_itemSets.empty())
                return true;

            whereStr = GenerateWhereStr(tableStruct.WhereFieldName, _itemSets);
            break;
        default:
            // not set case, get single guid string
            whereStr = GenerateWhereStr(tableStruct.WhereFieldName, guid);
            break;
    }

    QueryResult result = CharacterDatabase.PQuery("SELECT * FROM {} WHERE {}", dumpTable.Name, whereStr);
    switch (dumpTable.Type)
    {
        case DTT_CHARACTER:
            if (result)
            {
                // characters.deleteInfos_Account - if filled error
                int32 index = GetColumnIndexByName(tableStruct, "deleteInfos_Account");
                ASSERT(index != -1); // checked at startup

                if ((*result)[index].GetUInt32())
                    return false;
            }
            break;
        default:
            break;
    }

    AppendTableDump(trans, tableStruct, result);
    return true;
}

bool PlayerDumpWriter::GetDump(ObjectGuid::LowType guid, std::string& dump)
{
    dump =  "IMPORTANT NOTE: THIS DUMPFILE IS MADE FOR USE WITH THE 'PDUMP' COMMAND ONLY - EITHER THROUGH INGAME CHAT OR ON CONSOLE!\n";
    dump += "IMPORTANT NOTE: DO NOT apply it directly - it will irreversibly DAMAGE and CORRUPT your database! You have been warned!\n\n";

    StringTransaction trans;

    // collect guids
    PopulateGuids(guid);
    for (uint32 i = 0; i < DUMP_TABLE_COUNT; ++i)
        if (!AppendTable(trans, guid, CharacterTables[i], DumpTables[i]))
            return false;

    dump += trans.GetBuffer();

    /// @todo Add instance/group..
    /// @todo Add a dump level option to skip some non-important tables

    return true;
}

DumpReturn PlayerDumpWriter::WriteDumpToFile(std::string const& file, ObjectGuid::LowType guid)
{
    if (sWorld->getBoolConfig(CONFIG_PDUMP_NO_PATHS))
        if (strchr(file.c_str(), '\\') || strchr(file.c_str(), '/'))
            return DUMP_FILE_OPEN_ERROR;

    if (sWorld->getBoolConfig(CONFIG_PDUMP_NO_OVERWRITE))
    {
        // check if file exists already
        if (GetFileHandle(file.c_str(), "r"))
            return DUMP_FILE_OPEN_ERROR;
    }

    FileHandle fout = GetFileHandle(file.c_str(), "w");
    if (!fout)
        return DUMP_FILE_OPEN_ERROR;

    DumpReturn ret = DUMP_SUCCESS;
    std::string dump;
    if (!GetDump(guid, dump))
        ret = DUMP_CHARACTER_DELETED;

    fprintf(fout.get(), "%s", dump.c_str());
    return ret;
}

DumpReturn PlayerDumpWriter::WriteDumpToString(std::string& dump, ObjectGuid::LowType guid)
{
    DumpReturn ret = DUMP_SUCCESS;
    if (!GetDump(guid, dump))
        ret = DUMP_CHARACTER_DELETED;
    return ret;
}

// Reading - High-level functions
inline void FixNULLfields(std::string& line)
{
    static std::string const NullString("'NULL'");
    size_t pos = line.find(NullString);
    while (pos != std::string::npos)
    {
        line.replace(pos, NullString.length(), "NULL");
        pos = line.find(NullString);
    }
}

DumpReturn PlayerDumpReader::LoadDump(std::istream& input, uint32 account, std::string name, ObjectGuid::LowType guid)
{
    uint32 charcount = AccountMgr::GetCharactersCount(account);
    if (charcount >= sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM))
        return DUMP_TOO_MANY_CHARS;

    std::string newguid, chraccount;

    // make sure the same guid doesn't already exist and is safe to use
    bool incHighest = true;
    if (guid && guid < sObjectMgr->GetGenerator<HighGuid::Player>().GetNextAfterMaxUsed())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_GUID);
        stmt->setUInt64(0, guid);

        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
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
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHECK_NAME);
        stmt->setString(0, name);

        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
            name.clear();                                       // use the one from the dump
    }
    else
        name.clear();

    // name encoded or empty
    newguid = std::to_string(guid);
    chraccount = std::to_string(account);

    std::map<ObjectGuid::LowType, ObjectGuid::LowType> items;
    ObjectGuid::LowType itemLowGuidOffset = sObjectMgr->GetGenerator<HighGuid::Item>().GetNextAfterMaxUsed();

    std::map<uint64, uint64> mails;
    uint64 mailLowGuidOffset = sObjectMgr->_mailId;

    std::map<uint32, uint32> petIds;
    uint32 petLowGuidOffset = sObjectMgr->_hiPetNumber;

    std::map<uint64, uint64> equipmentSetIds;
    uint64 equipmentSetGuidOffset = sObjectMgr->_equipmentSetGuid;

    std::string line;

    uint8 gender = GENDER_NONE;
    uint8 race = RACE_NONE;
    uint8 playerClass = CLASS_NONE;
    uint8 level = 1;

    // for logs
    size_t lineNumber = 0;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    while (std::getline(input, line))
    {
        ++lineNumber;

        // skip empty strings
        size_t nw_pos = line.find_first_not_of(" \t\n\r\7");
        if (nw_pos == std::string::npos)
            continue;

        // skip the important notes
        static std::string const SkippedLine = "IMPORTANT NOTE:";
        if (line.substr(nw_pos, SkippedLine.size()) == SkippedLine)
            continue;

        // determine table name and load type
        std::string tn = GetTableName(line);
        if (tn.empty())
        {
            TC_LOG_ERROR("misc", "LoadPlayerDump: (line {}) Can't extract table name!", lineNumber);
            return DUMP_FILE_BROKEN;
        }

        DumpTableType type = DTT_CHARACTER;
        uint32 i;
        for (i = 0; i < DUMP_TABLE_COUNT; ++i)
        {
            if (tn == DumpTables[i].Name)
            {
                type = DumpTables[i].Type;
                break;
            }
        }

        if (i == DUMP_TABLE_COUNT)
        {
            TC_LOG_ERROR("misc", "LoadPlayerDump: (line {}) Unknown table: `{}`!", lineNumber, tn);
            return DUMP_FILE_BROKEN;
        }

        TableStruct const& ts = CharacterTables[i];
        if (!ValidateFields(ts, line, lineNumber))
            return DUMP_FILE_BROKEN;

        // per field guid offsetting
        for (TableField const& field : ts.TableFields)
        {
            if (!field.IsDependentField)
                continue;

            switch (field.FieldGuidType)
            {
                case GUID_TYPE_ACCOUNT:
                    if (!ChangeColumn(ts, line, field.FieldName, chraccount))
                        return DUMP_FILE_BROKEN;
                    break;
                case GUID_TYPE_CHAR:
                    if (!ChangeColumn(ts, line, field.FieldName, newguid))
                        return DUMP_FILE_BROKEN;
                    break;
                case GUID_TYPE_PET:
                    if (!ChangeGuid(ts, line, field.FieldName, petIds, petLowGuidOffset))
                        return DUMP_FILE_BROKEN;
                    break;
                case GUID_TYPE_MAIL:
                    if (!ChangeGuid(ts, line, field.FieldName, mails, mailLowGuidOffset))
                        return DUMP_FILE_BROKEN;
                    break;
                case GUID_TYPE_ITEM:
                    if (!ChangeGuid(ts, line, field.FieldName, items, itemLowGuidOffset, true))
                        return DUMP_FILE_BROKEN;
                    break;
                case GUID_TYPE_EQUIPMENT_SET:
                    if (!ChangeGuid(ts, line, field.FieldName, equipmentSetIds, equipmentSetGuidOffset))
                        return DUMP_FILE_BROKEN;
                    break;
                case GUID_TYPE_NULL:
                {
                    static std::string const NullString("NULL");
                    if (!ChangeColumn(ts, line, field.FieldName, NullString))
                        return DUMP_FILE_BROKEN;
                    break;
                }
            }
        }

        // extra modifications for other tables
        switch (type)
        {
            case DTT_CHARACTER:
            {
                race = Trinity::StringTo<uint8>(GetColumn(ts, line, "race")).value_or<uint8>(0);
                playerClass = Trinity::StringTo<uint8>(GetColumn(ts, line, "class")).value_or<uint8>(0);
                gender = Trinity::StringTo<uint8>(GetColumn(ts, line, "gender")).value_or<uint8>(0);
                level = Trinity::StringTo<uint8>(GetColumn(ts, line, "level")).value_or<uint8>(0);
                if (name.empty())
                {
                    // generate a temporary name
                    std::string guidPart = Trinity::StringFormat("{:X}", guid);
                    std::size_t maxCharsFromOriginalName = MAX_PLAYER_NAME - guidPart.length();

                    name = GetColumn(ts, line, "name").substr(0, maxCharsFromOriginalName) + guidPart;

                    // characters.at_login set to "rename on login"
                    if (!ChangeColumn(ts, line, "name", name))
                        return DUMP_FILE_BROKEN;
                    if (!ChangeColumn(ts, line, "at_login", "1"))
                        return DUMP_FILE_BROKEN;
                }
                else if (!ChangeColumn(ts, line, "name", name)) // characters.name
                    return DUMP_FILE_BROKEN;
                break;
            }
            default:
                break;
        }

        FixNULLfields(line);

        trans->Append(line.c_str());
    }

    if (input.fail() && !input.eof())
        return DUMP_FILE_BROKEN;

    CharacterDatabase.CommitTransaction(trans);

    // in case of name conflict player has to rename at login anyway
    sCharacterCache->AddCharacterCacheEntry(ObjectGuid::Create<HighGuid::Player>(guid), account, name, gender, race, playerClass, level, false);

    sObjectMgr->GetGenerator<HighGuid::Item>().Set(sObjectMgr->GetGenerator<HighGuid::Item>().GetNextAfterMaxUsed() + items.size());
    sObjectMgr->_mailId += mails.size();
    sObjectMgr->_hiPetNumber += petIds.size();
    sObjectMgr->_equipmentSetGuid += equipmentSetIds.size();

    if (incHighest)
        sObjectMgr->GetGenerator<HighGuid::Player>().Generate();

    sWorld->UpdateRealmCharCount(account);

    return DUMP_SUCCESS;
}

DumpReturn PlayerDumpReader::LoadDumpFromString(std::string const& dump, uint32 account, std::string name, ObjectGuid::LowType guid)
{
    std::istringstream input(dump);
    return LoadDump(input, account, name, guid);
}

DumpReturn PlayerDumpReader::LoadDumpFromFile(std::string const& file, uint32 account, std::string name, ObjectGuid::LowType guid)
{
    std::ifstream input(file);
    if (!input)
        return DUMP_FILE_OPEN_ERROR;
    return LoadDump(input, account, name, guid);
}
