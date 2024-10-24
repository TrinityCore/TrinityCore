/*
 * NpcBots Data Migration System by Trickerer (onlysuffering@gmail.com)
 *
 * Last update: *09 Apr 2023*
 *
 * Saved data:
 * 1) `characters_npcbot` - spawned bots' BOT info
 * 2) `characters_npcbot_transmog` - bots' transmogs
 * 3) `item_instance` - bots' equipment
 * 4) `creature` - bot spawns
 *
 * Make sure you have bots installed, or you are in for an unpleasant surprise.
 */

#include "botdump.h"
#include "botdatamgr.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"

#include <sstream>

class BotStringTransaction
{
public:
    BotStringTransaction() : _buf() {}

    void Append(std::string const& sql)
    {
        _buf += sql;
    }

    std::string const& GetBuffer() const
    {
        return _buf;
    }

private:
    std::string _buf;
};

enum ImportDataTableType : uint8
{
    TABLE_TYPE_CHARACTERS_NPCBOT    = 0,
    TABLE_TYPE_NPCBOT_TRANSMOG      = 1,
    TABLE_TYPE_ITEM_INSTANCE        = 2,
    TABLE_TYPE_CREATURE             = 3,

    IMPORT_TABLES_COUNT             = 4,
    IMPORT_TABLE_INVALID            = 255
};

struct TableImportData
{
    std::string const name;
    std::string const fieldsStr;
    uint32 paramsCount;
    size_t guidOffsetBegin;
    size_t guidOffsetEnd;
};

TableImportData TableImportDatas[IMPORT_TABLES_COUNT] =
{
    { "`characters_npcbot` ",
      "("
      //0       1       2       3      4         5                 6           7           8           9
      "`entry`,`owner`,`roles`,`spec`,`faction`,`spells_disabled`,`equipMhEx`,`equipOhEx`,`equipRhEx`,`equipHead`,"
      //10               11           12           13          14          15           16           17
      "`equipShoulders`,`equipChest`,`equipWaist`,`equipLegs`,`equipFeet`,`equipWrist`,`equipHands`,`equipBack`,"
      //18          19             20             21              22              23
      "`equipBody`,`equipFinger1`,`equipFinger2`,`equipTrinket1`,`equipTrinket2`,`equipNeck`"
      ") VALUES ", 24, 6, 23 },

    { "`characters_npcbot_transmog` ",
      "("
      //0       1      2         3
      "`entry`,`slot`,`item_id`,`fake_id`"
      ") VALUES ", 4, 0, 0 },

    { "`item_instance` ",
      "("
      //0             1                 2       3          4         5       6
      "`creatorGuid`,`giftCreatorGuid`,`count`,`duration`,`charges`,`flags`,`enchantments`,"
      //7                  8            9            10     11     12          13
      "`randomPropertyId`,`durability`,`playedTime`,`text`,`guid`,`itemEntry`,`owner_guid`"
      ") VALUES ", 14, 11, 11 },

    { "`creature` ",
      "("
      //0      1    2     3           4           5            6            7            8             9           10
      "`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`curhealth`,`curmana`"
      ") VALUES ", 11, 0, 0 }
};

ImportDataTableType GetImportDataTableType(std::string const& name)
{
    for (uint8 i = TABLE_TYPE_CHARACTERS_NPCBOT; i != IMPORT_TABLES_COUNT; ++i)
    {
        //TC_LOG_ERROR("scripts", "import: GetImportDataTableType");
        if (!TableImportDatas[i].name.compare(name))
            return ImportDataTableType(i);
    }

    return IMPORT_TABLE_INVALID;
}

inline uint8 GetImportLineParamsCount(std::string const& line)
{
    static std::string const ParamSeparator = "','";
    uint8 count = 0;
    size_t pos = line.find(ParamSeparator);
    while (pos != std::string::npos)
    {
        //TC_LOG_ERROR("scripts", "import: GetImportLineParamsCount");
        ++count;
        pos = line.find(ParamSeparator, pos + 1);
    }
    return count + 1; //separators count is params count - 1
}

inline void FixNULLfields(std::string& line)
{
    static std::string const NullString = "'NULL'";
    size_t pos = line.find(NullString);
    while (pos != std::string::npos)
    {
        //TC_LOG_ERROR("scripts", "import: FixNULLfields");
        line.replace(pos, NullString.length(), "NULL");
        pos = line.find(NullString);
    }
}

std::set<uint32> ExistingNPCBots;
std::set<uint32> ExistingNPCBotTransmogs;

template<typename T>
void StringToVal(std::string const& /*line*/, T& /*v*/, size_t /*begin_pos*/, size_t /*end_pos*/)
{
    TC_LOG_ERROR("scripts", "StringToVal misuse");
}
/*
template<>
void StringToVal(std::string const& line, float& v, size_t begin_pos, size_t end_pos)
{
    v = atof(line.substr(begin_pos, end_pos).c_str());
    TC_LOG_ERROR("scripts", "import: StringToVal returned {}", v);
}
*/
template<>
void StringToVal(std::string const& line, uint32& v, size_t begin_pos, size_t end_pos)
{
    std::string subst = line.substr(begin_pos, end_pos - begin_pos).c_str();
    v = (uint32)atoi(subst.c_str());
    //TC_LOG_ERROR("scripts", "import: StringToVal returned {} ({} to {}: {})",
    //    v, uint32(begin_pos), uint32(end_pos), subst.c_str());
}

template<typename T>
std::string ValToString(T /*v*/)
{
    TC_LOG_ERROR("scripts", "ValToString misuse");
    return "";
}
template<>
std::string ValToString(uint32 v)
{
    std::ostringstream stv;
    stv << v;
    return stv.str();
}

template<typename T>
bool ExtractValueFromString(std::string const& line, T& v, size_t offset, std::string const sep = "'")
{
    uint32 sepNum = 0;

    size_t begin_pos = 0, end_pos = 0;

    size_t pos = line.find(sep);
    while (pos != std::string::npos)
    {
        ++sepNum;
        if (begin_pos == 0 && !((sepNum-1) % 2) && ((sepNum-1) / 2) == offset)
        {
            begin_pos = pos + 1;
            //TC_LOG_ERROR("scripts", "import: ExtractValueFromString begin_pos {}", uint32(begin_pos));
        }
        else if (end_pos == 0 && ((sepNum-1) % 2) && ((sepNum-1) / 2) == offset)
        {
            end_pos = pos;
            //TC_LOG_ERROR("scripts", "import: ExtractValueFromString end_pos {}", uint32(end_pos));
        }

        if (begin_pos && end_pos)
            break;

        pos = line.find(sep, pos + 1);
    }

    if (begin_pos && end_pos)
    {
        StringToVal(line, v, begin_pos, end_pos);
        return true;
    }

    return false;
}

typedef std::map<uint32, uint32> ReGuidMap;
ReGuidMap itemReguidMap;

inline bool ReGuidBotEquip(std::string& line, size_t ne_guid_offset)
{
    /*
    INSERT INTO `characters_npcbot` (`entry`,`owner`,`roles`,`spec`,`faction`,`spell
    s_disabled`,`equipMhEx`,`equipOhEx`,`equipRhEx`,`equipHead`,`equipShoulders`,`eq
    uipChest`,`equipWaist`,`equipLegs`,`equipFeet`,`equipWrist`,`equipHands`,`equipB
    ack`,`equipBody`,`equipFinger1`,`equipFinger2`,`equipTrinket1`,`equipTrinket2`,`
    equipNeck`) VALUES ('70027','2204','19','3','35','NULL','4305063','4305032','0','0
    ','4305069','4237321','4237326','4305049','4305067','4305055','0','4305054','430
    5029','4303835','0','0','0','0');
    */
    static const std::string ne_vals_sep = "('";
    static const std::string ne_sep = "'";

    bool reguidDone = false;
    uint32 sepNum = 0;
    size_t begin_pos = 0, end_pos = 0;

    size_t pos = line.find(ne_vals_sep);
    ASSERT(pos != std::string::npos);
    pos = line.find(ne_sep);
    ASSERT(pos != std::string::npos);
    while (pos != std::string::npos)
    {
        ++sepNum;
        //TC_LOG_ERROR("scripts", "import: ReGuidBotEquip sepNum {}", sepNum);
        if (begin_pos == 0 && !((sepNum-1) % 2) && ((sepNum-1) / 2) == ne_guid_offset)
        {
            begin_pos = pos + 1;
            //TC_LOG_ERROR("scripts", "import: ReGuidBotEquip begin_pos {}", uint32(begin_pos));
        }
        else if (end_pos == 0 && ((sepNum-1) % 2) && ((sepNum-1) / 2) == ne_guid_offset)
        {
            end_pos = pos;
            //TC_LOG_ERROR("scripts", "import: ReGuidBotEquip end_pos {}", uint32(end_pos));
        }

        if (begin_pos && end_pos)
        {
            uint32 guidVal;
            StringToVal(line, guidVal, begin_pos, end_pos);
            if (!guidVal)
            {
                //ignore no equip
                if (line.substr(begin_pos, end_pos - begin_pos) == "0")
                    return true;

                TC_LOG_ERROR("scripts", "import: ReGuidBotEquip no guidVal from {} offset {}!",
                    line.substr(begin_pos, end_pos - begin_pos), uint32(ne_guid_offset));
                break;
            }

            if (!itemReguidMap.contains(guidVal))
            {
                TC_LOG_ERROR("scripts", "import: ReGuidBotEquip reguid value not found for {}!", guidVal);
                break;
            }

            uint32 neVal = itemReguidMap[guidVal];
            //TC_LOG_ERROR("scripts", "import: ReGuidBotEquip replacing {} with {}", guidVal, neVal);
            line.replace(begin_pos, end_pos - begin_pos, ValToString(neVal));
            reguidDone = true;
            break;
        }

        pos = line.find(ne_sep, pos + 1);
    }

    return reguidDone;
}
inline bool ReGuidBotEquips(std::string& line)
{
    static const size_t ne_guid_offset_s = TableImportDatas[TABLE_TYPE_CHARACTERS_NPCBOT].guidOffsetBegin;
    static const size_t ne_guid_offset_e = TableImportDatas[TABLE_TYPE_CHARACTERS_NPCBOT].guidOffsetEnd;
    //TC_LOG_ERROR("scripts", "import: ReGuidBotEquips ne_guid_offset_s {} ne_guid_offset_e {}", uint32(ne_guid_offset_s), uint32(ne_guid_offset_e));

    for (size_t i = ne_guid_offset_s; i <= ne_guid_offset_e; ++i)
    {
        if (!ReGuidBotEquip(line, i))
            return false;
    }

    return true;
}

inline bool ReGuidItemInstance(std::string& line, uint32& nextGuid)
{
    /*
    INSERT INTO `item_instance` (`creatorGuid`,`giftCreatorGuid`,`count`,`duration`,
    `charges`,`flags`,`enchantments`,`randomPropertyId`,`durability`,`playedTime`,`t
    ext`,`guid`,`itemEntry`,`owner_guid`) VALUES ('0','0','1','0','0 0 0 0 0 ','1','
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ','0','9
    0','7200','','4296510','42490','0'),('0','0','1','0','0 0 0 0 0 ','0','0 0 0 0 0
     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ','0','100','0','
    ','4303949','48468','0'), etc.
    */
    static const size_t ii_guid_offset = TableImportDatas[TABLE_TYPE_ITEM_INSTANCE].guidOffsetBegin;
    static const std::string ii_vals_sep = "('";
    static const std::string ii_sep = "'";

    //TC_LOG_ERROR("scripts", "import: ReGuidItemInstance ii_guid_offset {}", uint32(ii_guid_offset));

    size_t pos1 = line.find(ii_vals_sep);
    ASSERT(pos1 != std::string::npos);
    while (pos1 != std::string::npos)
    {
        //TC_LOG_ERROR("scripts", "cur pos1 {}", int32(pos1));
        bool reguidDone = false;
        uint32 sepNum = 0;
        size_t begin_pos = 0, end_pos = 0;
        size_t pos2 = line.find(ii_sep, pos1 + 1);
        ASSERT(pos2 != std::string::npos);
        while (pos2 != std::string::npos)
        {
            ++sepNum;
            //TC_LOG_ERROR("scripts", "cur pos2 {} sep {} s {} e {}, cval {}",
            //    int32(pos2), sepNum, uint32(begin_pos), uint32(end_pos), uint32((sepNum-1) / 2));
            if (begin_pos == 0 && !((sepNum-1) % 2) && ((sepNum-1) / 2) == ii_guid_offset)
            {
                begin_pos = pos2 + 1;
                //TC_LOG_ERROR("scripts", "import: ReGuidItemInstance begin_pos {}", uint32(begin_pos));
            }
            else if (end_pos == 0 && ((sepNum-1) % 2) && ((sepNum-1) / 2) == ii_guid_offset)
            {
                end_pos = pos2;
                //TC_LOG_ERROR("scripts", "import: ReGuidItemInstance end_pos {}", uint32(end_pos));
            }

            if (begin_pos && end_pos)
            {
                uint32 guidVal;
                StringToVal(line, guidVal, begin_pos, end_pos);
                if (!guidVal)
                {
                    TC_LOG_ERROR("scripts", "import: ReGuidItemInstance no guidVal from {}!",
                        line.substr(begin_pos, end_pos - begin_pos));
                    return false;
                }
                //this is not checked at dump save
                if (!itemReguidMap.contains(guidVal))
                    itemReguidMap[guidVal] = nextGuid;
                else
                    TC_LOG_ERROR("scripts", "import: ReGuidItemInstance item guid {} was already reguided to {}. Saved dump contains duplicate item guids - you'll have to fix them manually, proceeding anyways...",
                        guidVal, itemReguidMap[guidVal]);

                //TC_LOG_ERROR("scripts", "import: ReGuidItemInstance replacing {} with {}", guidVal, nextGuid);
                line.replace(begin_pos, end_pos - begin_pos, ValToString(nextGuid));

                ++nextGuid;
                reguidDone = true;
                break;
            }

            pos2 = line.find(ii_sep, pos2 + 1);
        }

        if (!reguidDone)
        {
            TC_LOG_ERROR("scripts", "import: ReGuidItemInstance reguid failed for string! Was:\n{}", line);
            return false;
        }

        pos1 = line.find(ii_vals_sep, pos1 + 1);
    }

    return true;
}

inline bool ReGuidCreature(std::string& line)
{
    /*
    INSERT INTO `item_instance` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position
    _x`,`position_y`,`position_z`,`orientation`,`curhealth`,`curmana` VALUES ('12561
    3','30102','571','0','0','1','1','0','0','5735.7','-3037.58','296.551','0.558505
    ','120','0','0','1','0','0','0','0','0','','0');
    */
    static const size_t cr_guid_offset = TableImportDatas[TABLE_TYPE_CREATURE].guidOffsetBegin;
    static const std::string cr_vals_sep = "('";
    static const std::string cr_sep = "'";

    bool reguidDone = false;
    uint32 sepNum = 0;
    size_t begin_pos = 0, end_pos = 0;

    size_t pos = line.find(cr_vals_sep);
    ASSERT(pos != std::string::npos);
    pos = line.find(cr_sep);
    ASSERT(pos != std::string::npos);
    while (pos != std::string::npos)
    {
        ++sepNum;
        //TC_LOG_ERROR("scripts", "import: ReGuidCreature sepNum {}", sepNum);
        if (begin_pos == 0 && !((sepNum-1) % 2) && ((sepNum-1) / 2) == cr_guid_offset)
        {
            begin_pos = pos + 1;
            //TC_LOG_ERROR("scripts", "import: ReGuidCreature begin_pos {}", uint32(begin_pos));
        }
        else if (end_pos == 0 && ((sepNum-1) % 2) && ((sepNum-1) / 2) == cr_guid_offset)
        {
            end_pos = pos;
            //TC_LOG_ERROR("scripts", "import: ReGuidCreature end_pos {}", uint32(end_pos));
        }

        if (begin_pos && end_pos)
        {
            uint32 guidVal;
            StringToVal(line, guidVal, begin_pos, end_pos);
            if (!guidVal)
            {
                TC_LOG_ERROR("scripts", "import: ReGuidCreature no guidVal from {}!",
                    line.substr(begin_pos, end_pos - begin_pos));
                return false;
            }

            uint32 nextGuid = sObjectMgr->GenerateCreatureSpawnId();
            //TC_LOG_ERROR("scripts", "import: ReGuidCreature replacing {} with {}", guidVal, nextGuid);
            line.replace(begin_pos, end_pos - begin_pos, ValToString(nextGuid));

            reguidDone = true;
            break;
        }

        pos = line.find(cr_sep, pos + 1);
    }

    return reguidDone;
}

BotDataDumpResult NPCBotsDump::Load(std::string const& file)
{
    std::ifstream input(file.c_str());
    if (!input)
        return BOT_DUMP_FAIL_FILE_NOT_EXIST;

    return LoadDump(input);
}

BotDataDumpResult NPCBotsDump::LoadDump(std::ifstream& input)
{
    //prepare data for existing entries checks
    //bot entry
    //first - from `characters_npcbot`
    QueryResult result = CharacterDatabase.Query("SELECT `entry` FROM `characters_npcbot`");
    Field* fields;
    if (result)
    {
        fields = result->Fetch();
        do
        {
            ExistingNPCBots.insert((*fields).GetUInt32());
        } while (result->NextRow());
    }
    //second - join with entries from `creature` table (who knows what you have spawned there before you needed to import bots eh?)
    result = WorldDatabase.Query("SELECT `id` FROM `creature` WHERE `id` IN (SELECT `entry` FROM `creature_template_npcbot_extras`) ORDER BY `id`");
    if (result)
    {
        fields = result->Fetch();
        do
        {
            ExistingNPCBots.insert((*fields).GetUInt32());
        } while (result->NextRow());
    }
    //bot transmogs
    result = CharacterDatabase.Query("SELECT `entry` FROM `characters_npcbot_transmog`");
    if (result)
    {
        fields = result->Fetch();
        do
        {
            ExistingNPCBotTransmogs.insert((*fields).GetUInt32());
        } while (result->NextRow());
    }
    //item guid
    result = CharacterDatabase.Query("SELECT MAX(`guid`) FROM `item_instance`");
    ASSERT(result);
    fields = result->Fetch();
    static uint32 NextItemGuid = (*fields).GetUInt32() + 1;
    //TC_LOG_ERROR("scripts", "import: NextItemGuid {}", NextItemGuid);

    CharacterDatabaseTransaction ctrans = CharacterDatabase.BeginTransaction();
    WorldDatabaseTransaction wtrans = WorldDatabase.BeginTransaction();

    std::list<std::string> ctransStrings;
    std::list<std::string> wtransStrings;

    ImportDataTableType curImportDataTableType = IMPORT_TABLE_INVALID;
    std::string curFieldsStr;
    std::string curExecLine;
    uint8 curParamCount = 0;

    std::string line;
    uint32 lineNum = 0;
    while (std::getline(input, line))
    {
        ++lineNum;

        size_t nw_pos = line.find_first_not_of(" \t\n\r\7");
        if (nw_pos == std::string::npos)
            continue;

        static std::string const NoteLine = "IMPORTANT NOTE:";
        if (line.substr(nw_pos, NoteLine.size()) == NoteLine)
            continue;

        if (curFieldsStr.empty())
        {
            std::string table_name = line.substr(line.find_first_of('`'));
            //TC_LOG_ERROR("scripts", "import: found table {}", table_name);
            curImportDataTableType = GetImportDataTableType(table_name);
            switch (curImportDataTableType)
            {
                case TABLE_TYPE_CHARACTERS_NPCBOT:
                case TABLE_TYPE_NPCBOT_TRANSMOG:
                case TABLE_TYPE_ITEM_INSTANCE:
                case TABLE_TYPE_CREATURE:
                    curFieldsStr = TableImportDatas[curImportDataTableType].fieldsStr;
                    break;
                default:
                    TC_LOG_ERROR("scripts", "import: unknown table {} at line {}", table_name, lineNum);
                    return BOT_DUMP_FAIL_FILE_CORRUPTED;
            }

            curExecLine += line;
            continue;
        }
        else if (curParamCount == 0)
        {
            if (line.compare(curFieldsStr))
                return BOT_DUMP_FAIL_FILE_CORRUPTED;

            curParamCount = TableImportDatas[curImportDataTableType].paramsCount;
            //TC_LOG_ERROR("scripts", "import: param count {}", uint32(curParamCount));

            curExecLine += line;
            continue;
        }
        else
        {
            if (GetImportLineParamsCount(line) != curParamCount)
            {
                TC_LOG_ERROR("scripts", "import: invalid param count {} at line {}", uint32(curParamCount), lineNum);
                return BOT_DUMP_FAIL_FILE_CORRUPTED;
            }

            //check values conflicts, abort on existing values
            size_t checkOffset = 0;
            bool needCheckVal = false;
            switch (curImportDataTableType)
            {
                case TABLE_TYPE_CHARACTERS_NPCBOT:
                    //entry
                    //checkOffset = 0;
                    needCheckVal = true;
                    break;
                case TABLE_TYPE_NPCBOT_TRANSMOG:
                    //entry
                    //checkOffset = 0;
                    needCheckVal = true;
                    break;
                default:
                    break;
            }
            uint32 checkVal;
            if (needCheckVal && !ExtractValueFromString(line, checkVal, checkOffset))
            {
                TC_LOG_ERROR("scripts", "import: unable to extract value from line {} at offset {} type {}",
                    lineNum, uint32(checkOffset), uint32(curImportDataTableType));
                return BOT_DUMP_FAIL_FILE_CORRUPTED;
            }
            switch (curImportDataTableType)
            {
                case TABLE_TYPE_CHARACTERS_NPCBOT:
                    if (ExistingNPCBots.find(checkVal) != ExistingNPCBots.end())
                    {
                        TC_LOG_ERROR("scripts", "import: NPCBot id {} already exists in `characters_npcbot` or `creature` table! Aborting", checkVal);
                        return BOT_DUMP_FAIL_DATA_OCCUPIED;
                    }
                    break;
                case TABLE_TYPE_NPCBOT_TRANSMOG:
                    if (ExistingNPCBotTransmogs.find(checkVal) != ExistingNPCBotTransmogs.end())
                    {
                        TC_LOG_ERROR("scripts", "import: NPCBot id {} already exists in `characters_npcbot_transmog` table! Aborting", checkVal);
                        return BOT_DUMP_FAIL_DATA_OCCUPIED;
                    }
                    break;
                default:
                    break;
            }

            curExecLine += line;

            //multi-line import
            if (line[line.size()-1] == ',')
                continue;
            else if (line[line.size()-1] != ';')
            {
                TC_LOG_ERROR("scripts", "import: unexpected line ending at line {}", lineNum);
                return BOT_DUMP_FAIL_FILE_CORRUPTED;
            }
        }

        //reguid if needed
        switch (curImportDataTableType)
        {
            case TABLE_TYPE_ITEM_INSTANCE:
                if (!ReGuidItemInstance(curExecLine, NextItemGuid))
                {
                    TC_LOG_ERROR("scripts", "import: unable to reguid item instance at line {}!", lineNum);
                    return BOT_DUMP_FAIL_FILE_CORRUPTED;
                }
                if (!ReGuidBotEquips(ctransStrings.back()))
                {
                    TC_LOG_ERROR("scripts", "import: unable to reguid bot equips at line {}:\n{}!", lineNum, ctransStrings.back());
                    return BOT_DUMP_FAIL_FILE_CORRUPTED;
                }
                break;
            case TABLE_TYPE_CREATURE:
                if (!ReGuidCreature(curExecLine))
                {
                    TC_LOG_ERROR("scripts", "import: unable to reguid creature at line {}!", lineNum);
                    return BOT_DUMP_FAIL_FILE_CORRUPTED;
                }
                break;
            default:
                break;
        }

        switch (curImportDataTableType)
        {
            case TABLE_TYPE_CHARACTERS_NPCBOT:
            case TABLE_TYPE_NPCBOT_TRANSMOG:
            case TABLE_TYPE_ITEM_INSTANCE:
                //TC_LOG_ERROR("scripts", "import: adding to chars DB");
                ctransStrings.push_back(curExecLine);
                //ctrans->Append(curExecLine.c_str());
                break;
            case TABLE_TYPE_CREATURE:
                //TC_LOG_ERROR("scripts", "import: adding to world DB");
                wtransStrings.push_back(curExecLine);
                //wtrans->Append(curExecLine.c_str());
                break;
            default:
                ASSERT(false);
        }

        curParamCount = 0;
        curExecLine.clear();
        curFieldsStr.clear();
        curImportDataTableType = IMPORT_TABLE_INVALID;
    }

    //check incomplete last query
    if (!curExecLine.empty() || !curFieldsStr.empty() || curParamCount > 0 ||
        curImportDataTableType != IMPORT_TABLE_INVALID)
    {
        TC_LOG_ERROR("scripts", "import: unexpected file ending, incomplete query {}, fields {}, type {}!",
            curExecLine, curFieldsStr, uint32(curImportDataTableType));

        return BOT_DUMP_FAIL_FILE_CORRUPTED;
    }

    //Replace all 'NULL' values as they are saved in dump with plain NULL
    for (std::list<std::string>::iterator ci = ctransStrings.begin(); ci != ctransStrings.end(); ++ci)
        FixNULLfields(*ci);
    for (std::list<std::string>::iterator wi = wtransStrings.begin(); wi != wtransStrings.end(); ++wi)
        FixNULLfields(*wi);

    //TC_LOG_ERROR("scripts", "import: charDb execLines:");
    for (std::list<std::string>::const_iterator ci = ctransStrings.begin(); ci != ctransStrings.end(); ++ci)
    {
        //TC_LOG_ERROR("scripts", "{}", (*ci));
        ctrans->Append((*ci).c_str());
    }
    //TC_LOG_ERROR("scripts", "import: worldDb execLines:");
    for (std::list<std::string>::const_iterator wi = wtransStrings.begin(); wi != wtransStrings.end(); ++wi)
    {
        //TC_LOG_ERROR("scripts", "{}", (*wi));
        wtrans->Append((*wi).c_str());
    }

    CharacterDatabase.CommitTransaction(ctrans);
    WorldDatabase.CommitTransaction(wtrans);

    return BOT_DUMP_SUCCESS;
}

BotDataDumpResult NPCBotsDump::Write(std::string const& file)
{
    if (FILE* f = fopen(file.c_str(), "r"))
    {
        fclose(f);
        return BOT_DUMP_FAIL_FILE_ALREADY_EXISTS;
    }

    BotDataDumpResult ret = BOT_DUMP_SUCCESS;
    std::string dumpstr;
    if (!GetDump(dumpstr))
        ret = BOT_DUMP_FAIL_INCOMPLETE;
    else
    {
        FILE* fout = fopen(file.c_str(), "w");
        if (!fout)
            return BOT_DUMP_FAIL_CANT_WRITE_TO_FILE;

        fprintf(fout, "%s", dumpstr.c_str());
        fclose(fout);
    }

    return ret;
}

bool NPCBotsDump::GetDump(std::string& dump)
{
    //bots are disabled but we need that data
    if (!BotDataMgr::AllBotsLoaded())
        BotDataMgr::LoadNpcBots(false);

    dump = "";

    dump += "IMPORTANT NOTE: THIS DUMPFILE IS MADE FOR USE WITH THE 'NPCBOT DUMP' COMMAND ONLY - EITHER THROUGH INGAME CHAT OR ON CONSOLE!\n";
    dump += "IMPORTANT NOTE: DO NOT apply it directly - it will irreversibly DAMAGE and CORRUPT your database! You have been warned!\n\n";

    BotStringTransaction trans;

    std::set<uint32> valid_ids;
    bool integrityChecked = true;
    for (uint32 i : BotDataMgr::GetExistingNPCBotIds())
    {
        //skip generated bots
        if (i >= BOT_ENTRY_CREATE_BEGIN && BotDataMgr::GetBotExtraCreatureTemplate(i))
            continue;

        BotDataVerificationResult res = VerifyWriteData(i);
        if (res == BOT_DATA_INCOMPLETE)
        {
            if (integrityChecked)
                integrityChecked = false;
        }
        else if (res == BOT_DATA_VALID)
            valid_ids.insert(i);
    }

    if (!integrityChecked || valid_ids.empty())
        return false;

    for (std::set<uint32>::const_iterator ci = valid_ids.begin(); ci != valid_ids.end(); ++ci)
    {
        AppendBotNPCBotData(&trans, *ci);
        AppendBotNPCBotTransmogData(&trans, *ci);
        AppendBotEquipsData(&trans, *ci);
        AppendBotCreatureData(&trans, *ci);
    }

    dump += trans.GetBuffer();

    return true;
}

BotDataVerificationResult NPCBotsDump::VerifyWriteData(uint32 entry) const
{
    NpcBotData const* botData = BotDataMgr::SelectNpcBotData(entry);

    //bot of this entry is not spawned
    if (!botData)
        return BOT_DATA_NOT_EXIST;

    EquipmentInfo const* deinfo = BotDataMgr::GetBotEquipmentInfo(entry);
    if (!deinfo)
    {
        TC_LOG_ERROR("scripts", "NPCBotsDump::AppendBotCreatureData creature {} is not found in `creature_equip_template` table!", entry);
        return BOT_DATA_INCOMPLETE;
    }

    QueryResult result = WorldDatabase.PQuery("SELECT `guid` FROM `creature` WHERE `id` = {}", entry);

    //creature is not spawned, corrupted
    if (!result)
    {
        TC_LOG_ERROR("scripts", "NPCBotsDump::AppendBotCreatureData creature {} is not found in `creature` table!", entry);
        return BOT_DATA_INCOMPLETE;
    }
    if (result->GetRowCount() > 1)
    {
        TC_LOG_ERROR("scripts", "NPCBotsDump::AppendBotCreatureData creature {} is spawned more that once!", entry);
        return BOT_DATA_INCOMPLETE;
    }

    return BOT_DATA_VALID;
}

template<typename T>
inline void AppendEscapedValue(std::ostringstream& ss, T const& val, bool end = false)
{
    ss << '\'' << val << '\'';
    if (!end)
        ss << ',';
}
inline void AppendNULL(std::ostringstream& ss, bool end = false)
{
    AppendEscapedValue(ss, "NULL", end);
    //ss << "NULL";
    //if (!end)
    //    ss << ',';
}
std::string const EscapedString(char const* cstr)
{
    std::string s = cstr;
    CharacterDatabase.EscapeString(s);
    return s;
}

void NPCBotsDump::AppendBotNPCBotData(BotStringTransaction* trans, uint32 entry) const
{
    NpcBotData const* botData = BotDataMgr::SelectNpcBotData(entry);
    ASSERT(botData);

    std::ostringstream ss;
    ss << "INSERT INTO " << TableImportDatas[TABLE_TYPE_CHARACTERS_NPCBOT].name << '\n'
        << TableImportDatas[TABLE_TYPE_CHARACTERS_NPCBOT].fieldsStr << '\n';

    ss << '(';

    AppendEscapedValue(ss, entry);
    AppendEscapedValue(ss, botData->owner);
    AppendEscapedValue(ss, botData->roles);
    AppendEscapedValue(ss, uint32(botData->spec));
    AppendEscapedValue(ss, botData->faction);

    if (botData->disabled_spells.empty())
        AppendNULL(ss);
    else
    {
        std::ostringstream ssds;
        for (NpcBotData::DisabledSpellsContainer::const_iterator ci = botData->disabled_spells.begin(); ci != botData->disabled_spells.end(); ++ci)
            ssds << *ci << ' ';
        AppendEscapedValue(ss, ssds.str());
    }

    for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
        AppendEscapedValue(ss, botData->equips[i], i == BOT_INVENTORY_SIZE-1);

    ss << ");\n";

    trans->Append(ss.str());
}

void NPCBotsDump::AppendBotNPCBotTransmogData(BotStringTransaction* trans, uint32 entry) const
{
    NpcBotData const* botData = BotDataMgr::SelectNpcBotData(entry);
    ASSERT(botData);

    QueryResult tresult = CharacterDatabase.PQuery("SELECT `entry`,`slot`,`item_id`,`fake_id` FROM `characters_npcbot_transmog` WHERE entry = {}", entry);

    if (!tresult)
        return;

    std::ostringstream ss;
    ss << "INSERT INTO " << TableImportDatas[TABLE_TYPE_NPCBOT_TRANSMOG].name << '\n'
        << TableImportDatas[TABLE_TYPE_NPCBOT_TRANSMOG].fieldsStr << '\n';

    static const uint32 transmog_fields_count = TableImportDatas[TABLE_TYPE_NPCBOT_TRANSMOG].paramsCount;

    while (true)
    {
        Field* fields = tresult->Fetch();

        ss << '(';

        for (uint8 i = 0; i != transmog_fields_count; ++i)
        {
            bool end = i == transmog_fields_count - 1;
            switch (i)
            {
                case 1:  //slot
                    AppendEscapedValue(ss, uint32(fields[i].GetUInt8()), end);
                    break;
                default:
                    AppendEscapedValue(ss,        fields[i].GetUInt32(), end);
                    break;
            }
        }

        if (tresult->NextRow())
            ss << "),\n";
        else
        {
            ss << ");\n";
            break;
        }
    }

    trans->Append(ss.str());
}

void NPCBotsDump::AppendBotEquipsData(BotStringTransaction* trans, uint32 entry) const
{
    NpcBotData const* botData = BotDataMgr::SelectNpcBotData(entry);
    ASSERT(botData);

    EquipmentInfo const* deinfo = BotDataMgr::GetBotEquipmentInfo(entry);
    ASSERT(deinfo);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP_BY_ITEM_INSTANCE);
    //        0            1                2      3         4        5      6             7                 8           9           10    11    12         13
    //"SELECT creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, guid, itemEntry, owner_guid "
    //  "FROM item_instance WHERE guid IN (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_SYNCH

    for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        stmt->setUInt32(i, botData->equips[i]);

    PreparedQueryResult iiresult = CharacterDatabase.Query(stmt);

    //all zeros? or maybe broken entry
    if (!iiresult)
        return;

    std::ostringstream ss;
    ss << "INSERT INTO " << TableImportDatas[TABLE_TYPE_ITEM_INSTANCE].name << '\n'
        << TableImportDatas[TABLE_TYPE_ITEM_INSTANCE].fieldsStr << '\n';

    static const uint32 item_instance_fields_count = TableImportDatas[TABLE_TYPE_ITEM_INSTANCE].paramsCount;

    while (true)
    {
        Field* fields = iiresult->Fetch();

        ss << '(';

        for (uint8 i = 0; i != item_instance_fields_count; ++i)
        {
            bool end = i == item_instance_fields_count-1;
            switch (i)
            {
                case 4:  //charges
                case 6:  //enchantments
                case 10: //text
                {
                    char const* cstr = fields[i].GetCString();
                    if (!cstr)
                        AppendNULL(ss, end);
                    else
                        AppendEscapedValue(ss, EscapedString(cstr), end);
                    break;
                }
                case 7:  //randomPropertyId
                    AppendEscapedValue(ss,      int32(fields[i].GetInt16()),   end);
                    break;
                case 8:  //durability
                    AppendEscapedValue(ss,     uint32(fields[i].GetUInt16()),  end);
                    break;
                default:
                    AppendEscapedValue(ss,            fields[i].GetUInt32(),   end);
                    break;
            }
        }

        if (iiresult->NextRow())
            ss << "),\n";
        else
        {
            ss << ");\n";
            break;
        }
    }

    trans->Append(ss.str());
}

void NPCBotsDump::AppendBotCreatureData(BotStringTransaction* trans, uint32 entry) const
{
    QueryResult cresult = WorldDatabase.PQuery("SELECT `guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`curhealth`,`curmana` FROM `creature` WHERE id = {}", entry);

    ASSERT(cresult);

    std::ostringstream ss;
    ss << "INSERT INTO " << TableImportDatas[TABLE_TYPE_CREATURE].name << '\n'
        << TableImportDatas[TABLE_TYPE_CREATURE].fieldsStr << '\n';

    ss << '(';

    static const uint32 creature_fields_count = TableImportDatas[TABLE_TYPE_CREATURE].paramsCount;

    Field* fields = cresult->Fetch();

    for (uint8 i = 0; i != creature_fields_count; ++i)
    {
        bool end = i == creature_fields_count-1;
        switch (i)
        {
            case 5:  //position_x
            case 6:  //position_y
            case 7:  //position_z
            case 8:  //orientation
                ss.setf(std::ios_base::fixed);
                ss.precision(6);
                AppendEscapedValue(ss,            fields[i].GetFloat(),    end);
                break;
            case 3:  //spawnMask
                AppendEscapedValue(ss,     uint32(fields[i].GetUInt8()),   end);
                break;
            case 2:  //map
                AppendEscapedValue(ss,     uint32(fields[i].GetUInt16()),  end);
                break;
            default:
                AppendEscapedValue(ss,            fields[i].GetUInt32(),   end);
                break;
        }
    }

    ss << ");\n";

    trans->Append(ss.str());
}
