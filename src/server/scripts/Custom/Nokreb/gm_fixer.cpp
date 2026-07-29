/*
 * gm_fixer — a set of GM .fix commands for quick NPC fixes.
 *
 * Each application:
 *   1) Synchronously executes SQL in the world database
 *   2) Appends the executed SQL to a cumulative daily file
 *      <DD_MM_YYYY>.sql next to the worldserver (e.g. 08_07_2026.sql)
 *
 * Commands:
 *   .fix faction <factionId>  — set factionId for the selected NPC
 *   .fix friendly             — quick set friendly faction (35)
 *   .fix hostile              — quick set hostile faction (16)
 *   .fix walk                 — disable flight (StaticFlags1 = 0x10000000)
 *   .fix fly                  — enable flight (StaticFlags1 = 0x20000000)
 *   .fix delete               — delete the selected NPC's spawn (entry + guid)
 *   .fix queststart <questId> — add quest questId to the selected NPC
 *
 * Installation:
 *   1. File at: src/server/scripts/Custom/gm_fixer/gm_fixer.cpp
 *   2. In custom_script_loader.cpp:
 *        void AddSC_gm_fixer();        // forward
 *        AddSC_gm_fixer();             // inside AddCustomScripts()
 *   3. Regenerate CMake, rebuild.
 */

#include "ScriptMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Player.h"
#include "WorldSession.h"
#include "RBAC.h"
#include "QuestDef.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "MotionMaster.h"
#include "WaypointManager.h"

#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <filesystem>
#include <cstdlib>

using namespace Trinity::ChatCommands;

namespace
{
    // Quick faction presets.
    // Names with FIX_ prefix — to avoid conflicts with FactionTemplates enum
    // from SharedDefines.h (which already has FACTION_FRIENDLY / FACTION_HOSTILE).
    constexpr uint32 FIX_FACTION_FRIENDLY = 35;
    constexpr uint32 FIX_FACTION_HOSTILE  = 16;

    // StaticFlags1 for movement control
    // (in StefalWoW / TrinityCore master these bits correspond to
    //  movement flags in creature_template_difficulty.StaticFlags1)
    constexpr uint32 STATIC_FLAG_WALK = 268435456u;  // 0x10000000
    constexpr uint32 STATIC_FLAG_FLY  = 536870912u;  // 0x20000000

    // Log channel name for TC_LOG_INFO, etc.
    static constexpr char const* LOG_CHAN = "scripts.gm_fixer";

    // VerifiedBuild for hotfix entries (current StefalWoW client build).
    constexpr uint32 HOTFIX_VERIFIED_BUILD = 67186;

    // Filename for separate spell fix log (GCD and CD).
    static constexpr char const* SPELL_CD_FILE = "spell_CD.sql";

    // Filename for separate creature size fix log.
    static constexpr char const* SCALE_SIZE_FILE = "creature_sizes.sql";

    /*
     * Appends a SQL query to a separate file creature_sizes.sql (next to worldserver).
     * This file only contains creature scale fixes.
     * The file is NOT date-dependent — it accumulates into a single common list.
     */
    static void AppendToScaleSizeFile(std::string const& sql, std::string const& fixType, std::string const& what = "")
    {
        namespace fs = std::filesystem;
        try
        {
            fs::path out = fs::current_path() / SCALE_SIZE_FILE;
            std::ofstream os(out, std::ios::app);
            if (!os.is_open())
            {
                TC_LOG_ERROR(LOG_CHAN, "gm_fixer: cannot open '{}' for append", out.string());
                return;
            }

            std::time_t now = std::time(nullptr);
            std::tm tm{};
#if defined(_WIN32) || defined(_WIN64)
            localtime_s(&tm, &now);
#else
            localtime_r(&now, &tm);
#endif
            std::ostringstream stamp;
            stamp << std::setfill('0')
                  << std::setw(2) << tm.tm_hour << ":"
                  << std::setw(2) << tm.tm_min  << ":"
                  << std::setw(2) << tm.tm_sec;
            std::ostringstream date;
            date << std::setfill('0')
                 << std::setw(2) << tm.tm_mday  << "."
                 << std::setw(2) << (tm.tm_mon + 1) << "."
                 << (tm.tm_year + 1900);

            if (!what.empty())
                os << "-- [" << date.str() << " " << stamp.str() << "] " << fixType << ": " << what << "\n"
                   << sql << "\n\n";
            else
                os << "-- [" << date.str() << " " << stamp.str() << "] " << fixType << "\n"
                   << sql << "\n\n";
        }
        catch (std::exception const& e)
        {
            TC_LOG_ERROR(LOG_CHAN, "gm_fixer: exception writing creature_sizes.sql: {}", e.what());
        }
    }

    /*
     * Appends a SQL query to a separate file spell_CD.sql (next to worldserver).
     * This file only contains spell fixes — GCD and RecoveryTime.
     * The file is NOT date-dependent — it accumulates into a single common list of spell fixes.
     */
    static void AppendToSpellCdFile(std::string const& sql, std::string const& fixType)
    {
        namespace fs = std::filesystem;
        try
        {
            fs::path out = fs::current_path() / SPELL_CD_FILE;
            std::ofstream os(out, std::ios::app);
            if (!os.is_open())
            {
                TC_LOG_ERROR(LOG_CHAN, "gm_fixer: cannot open '{}' for append", out.string());
                return;
            }

            std::time_t now = std::time(nullptr);
            std::tm tm{};
#if defined(_WIN32) || defined(_WIN64)
            localtime_s(&tm, &now);
#else
            localtime_r(&now, &tm);
#endif
            std::ostringstream stamp;
            stamp << std::setfill('0')
                  << std::setw(2) << tm.tm_hour << ":"
                  << std::setw(2) << tm.tm_min  << ":"
                  << std::setw(2) << tm.tm_sec;
            // Date for spell_CD.sql — in the file header, not on every line.
            std::ostringstream date;
            date << std::setfill('0')
                 << std::setw(2) << tm.tm_mday  << "."
                 << std::setw(2) << (tm.tm_mon + 1) << "."
                 << (tm.tm_year + 1900);

            os << "-- [" << date.str() << " " << stamp.str() << "] " << fixType << "\n"
               << sql << "\n\n";
        }
        catch (std::exception const& e)
        {
            TC_LOG_ERROR(LOG_CHAN, "gm_fixer: exception writing spell_CD.sql: {}", e.what());
        }
    }

    /*
     * Parses seconds (with support for fractional part and comma instead of dot).
     * Accepts: "1.5", "1,5", "0.5", "10".
     * Returns milliseconds: 1500, 1500, 500, 10000.
     *
     * If args is empty — returns defMs (default value).
     */
    static bool ParseSecondsToMs(char const* args, uint32 defMs, uint32& outMs)
    {
        if (!args || !*args)
        {
            outMs = defMs;
            return true;
        }
        // Copy to a local buffer and replace comma with dot.
        std::string s(args);
        for (char& c : s)
            if (c == ',') c = '.';
        // trim
        size_t start = s.find_first_not_of(" \t");
        if (start == std::string::npos)
        {
            outMs = defMs;
            return true;
        }
        s = s.substr(start);
        char* end = nullptr;
        double seconds = std::strtod(s.c_str(), &end);
        if (end == s.c_str())
            return false; // nothing was parsed
        if (seconds < 0.0)
            return false;
        double ms = seconds * 1000.0;
        if (ms > 4294967295.0) // UINT32_MAX
            return false;
        outMs = static_cast<uint32>(ms);
        return true;
    }


    /*
     * Generates the daily cumulative file name: DD_MM_YYYY.sql
     * Uses the server's local time.
     */
    static std::string MakeDailyFileName()
    {
        std::time_t now = std::time(nullptr);
        std::tm tm{};
#if defined(_WIN32) || defined(_WIN64)
        localtime_s(&tm, &now);
#else
        localtime_r(&now, &tm);
#endif
        std::ostringstream ss;
        ss << std::setfill('0')
           << std::setw(2) << tm.tm_mday  << "_"
           << std::setw(2) << (tm.tm_mon + 1) << "_"
           << (tm.tm_year + 1900)
           << ".sql";
        return ss.str();
    }

    /*
     * Appends a SQL query to the cumulative daily file next to the worldserver.
     * File: <cwd>/DD_MM_YYYY.sql  (cwd defaults to the worldserver.exe folder)
     * If the file doesn't exist — it's created. If it exists — the query is appended.
     * The fix type (fixType) is written as a block header, e.g.:
     *   -- [18:07:47] faction
     *   UPDATE creature_template SET faction = 16 WHERE entry = 1986;
     */
    static void AppendToDailySql(std::string const& sql, std::string const& fixType, std::string const& what = "")
    {
        namespace fs = std::filesystem;
        try
        {
            fs::path out = fs::current_path() / MakeDailyFileName();
            std::ofstream os(out, std::ios::app);
            if (!os.is_open())
            {
                TC_LOG_ERROR(LOG_CHAN, "gm_fixer: cannot open '{}' for append", out.string());
                return;
            }

            std::time_t now = std::time(nullptr);
            std::tm tm{};
#if defined(_WIN32) || defined(_WIN64)
            localtime_s(&tm, &now);
#else
            localtime_r(&now, &tm);
#endif
            std::ostringstream stamp;
            stamp << std::setfill('0')
                  << std::setw(2) << tm.tm_hour << ":"
                  << std::setw(2) << tm.tm_min  << ":"
                  << std::setw(2) << tm.tm_sec;

            if (!what.empty())
                os << "-- [" << stamp.str() << "] " << fixType << ": " << what << "\n"
                   << sql << "\n\n";
            else
                os << "-- [" << stamp.str() << "] " << fixType << "\n"
                   << sql << "\n\n";
        }
        catch (std::exception const& e)
        {
            TC_LOG_ERROR(LOG_CHAN, "gm_fixer: exception writing daily sql: {}", e.what());
        }
    }

    /*
     * Applies SQL to the world database (synchronously) and appends it to the daily file.
     * fixType — a short tag for the SQL block header ("faction", "delete", ...).
     * what    — a human-readable description for the player and log.
     * Always returns true — to avoid kicking the player out of the command on error,
     * as is customary in NpcLLM-style.
     */
    static bool ApplyFix(ChatHandler* h, std::string const& sql,
                         std::string const& fixType, char const* what)
    {
        // Apply to the world database. DirectExecute is synchronous, so the data
        // is guaranteed to be written before returning control to the GM.
        WorldDatabase.DirectExecute(sql.c_str());
        AppendToDailySql(sql, fixType, what);
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL: {}", sql));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sql);
        return true;
    }

    /*
     * Get the selected NPC and its entry.
     * On error, sends a message to the player and returns false.
     */
    static bool GetSelectedCreature(ChatHandler* h, Creature*& outC, uint32& outEntry)
    {
        Player* p = h->GetSession()->GetPlayer();
        if (!p) return false;
        Creature* c = p->GetSelectedUnit() ? p->GetSelectedUnit()->ToCreature() : nullptr;
        if (!c)
        {
            h->SendSysMessage("Select a creature first.");
            return false;
        }
        outC = c;
        outEntry = c->GetEntry();
        return true;
    }
}

/*
 * =========================================================================
 * CommandScript
 * =========================================================================
 */
class gm_fixer_cmd : public CommandScript
{
public:
    gm_fixer_cmd() : CommandScript("gm_fixer_cmd") {}

    std::span<ChatCommandBuilder const> GetCommands() const override
    {
        static ChatCommandTable fixTable = {
            {"faction",    HandleFixFaction,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"friendly",   HandleFixFriendly,          rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"hostile",    HandleFixHostile,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"walk",       HandleFixWalk,              rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"fly",        HandleFixFly,               rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"delete",     HandleFixDelete,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"queststart", HandleFixQuestStart,        rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"ct",         HandleFixContentTuning,     rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"hp",         HandleFixHealth,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"diff",       HandleFixDifficulty,        rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"diff1",      HandleFixDifficulty1,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"diff2",      HandleFixDifficulty2,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"diff3",      HandleFixDifficulty3,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"diff4",      HandleFixDifficulty4,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"diff5",      HandleFixDifficulty5,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"eflag",      HandleFixFlagsExtra,        rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"npcinfo",    HandleFixNpcInfo,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"questinfo",  HandleFixQuestInfo,         rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"spellgcd",   HandleFixSpellGCD,          rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"spellcd",    HandleFixSpellCD,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gstate",     HandleFixGState,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cstate",     HandleFixCState,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gdead",      HandleFixGDead,             rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cdead",      HandleFixCDead,             rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gnpcflag",   HandleFixGNpcFlag,          rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cnpcflag",   HandleFixCNpcFlag,          rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"guflags",    HandleFixGUnitFlags,        rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cuflags",    HandleFixCUnitFlags,        rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"guflags2",   HandleFixGUnitFlags2,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cuflags2",   HandleFixCUnitFlags2,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"guflags3",   HandleFixGUnitFlags3,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cuflags3",   HandleFixCUnitFlags3,       rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"combat",     HandleFixCombat,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"questprev",  HandleFixQuestPrev,         rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"addnpc",     HandleFixAddNpc,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gmove",      HandleFixGMove,             rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"cmove",      HandleFixCMove,             rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gmoverange", HandleFixGMoveRange,        rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"scalesize",  HandleFixScaleSize,         rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gmoveall",   HandleFixGMoveAll,          rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gpos",       HandleFixGPos,              rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gemote",     HandleFixGEmote,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"emote",      HandleFixEmote,             rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"gauras",     HandleFixGAuras,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"smart",      HandleFixSmart,             rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"unsmart",    HandleFixUnsmart,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"wayinfo",    HandleFixWayInfo,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"wayadd",     HandleFixWayAdd,            rbac::RBAC_PERM_COMMAND_GM, Console::No},
            {"waynode",    HandleFixWayNode,           rbac::RBAC_PERM_COMMAND_GM, Console::No},
        };
        static ChatCommandTable commandTable = {
            {"fix", fixTable},
        };
        return commandTable;
    }

private:
    // ----- .fix faction <factionId> -----
    static bool HandleFixFaction(ChatHandler* h, uint32 factionId)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT faction FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET faction = {} WHERE entry = {};", factionId, entry);
        return ApplyFix(h, sql, "faction",
            Trinity::StringFormat("faction: {} -> {} (entry {})", oldVal, factionId, entry).c_str());
    }

    // ----- .fix friendly -----
    static bool HandleFixFriendly(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT faction FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET faction = {} WHERE entry = {};", FIX_FACTION_FRIENDLY, entry);
        return ApplyFix(h, sql, "friendly",
            Trinity::StringFormat("faction: {} -> {} (entry {}, friendly)", oldVal, FIX_FACTION_FRIENDLY, entry).c_str());
    }

    // ----- .fix hostile -----
    static bool HandleFixHostile(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT faction FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET faction = {} WHERE entry = {};", FIX_FACTION_HOSTILE, entry);
        return ApplyFix(h, sql, "hostile",
            Trinity::StringFormat("faction: {} -> {} (entry {}, hostile)", oldVal, FIX_FACTION_HOSTILE, entry).c_str());
    }

    // ----- .fix walk -----
    static bool HandleFixWalk(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template_difficulty SET StaticFlags1 = {} "
            "WHERE Entry = {};", STATIC_FLAG_WALK, entry);
        return ApplyFix(h, sql, "walk",
            Trinity::StringFormat("Walk (StaticFlags1={}) entry {}", STATIC_FLAG_WALK, entry).c_str());
    }

    // ----- .fix fly -----
    static bool HandleFixFly(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template_difficulty SET StaticFlags1 = {} "
            "WHERE Entry = {};", STATIC_FLAG_FLY, entry);
        return ApplyFix(h, sql, "fly",
            Trinity::StringFormat("Fly (StaticFlags1={}) entry {}", STATIC_FLAG_FLY, entry).c_str());
    }

    // ----- .fix delete -----
    // Deletes the specific spawn of the selected NPC (entry + spawnId).
    // Despawn first, then SQL — otherwise GetSpawnId() may become invalid.
    static bool HandleFixDelete(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        c->DespawnOrUnsummon(0ms);

        std::string sql = Trinity::StringFormat(
            "DELETE FROM creature WHERE id = {} AND guid = {};", entry, spawnId);
        return ApplyFix(h, sql, "delete",
            Trinity::StringFormat("Delete spawn (entry {}, guid {})", entry, spawnId).c_str());
    }

    // ----- .fix queststart <questId> -----
    static bool HandleFixQuestStart(ChatHandler* h, uint32 questId)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Check that the quest exists — otherwise we'd get garbage in the DB.
        if (!sObjectMgr->GetQuestTemplate(questId))
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] Quest {} not found in quest_template.", questId));
            return true;
        }

        // INSERT IGNORE — in case of a duplicate (id, quest) PK.
        std::string sql = Trinity::StringFormat(
            "INSERT IGNORE INTO creature_queststarter (id, quest, VerifiedBuild) "
            "VALUES ({}, {}, 0);", entry, questId);
        return ApplyFix(h, sql, "queststart",
            Trinity::StringFormat("QuestStart: quest {} -> entry {}", questId, entry).c_str());
    }

    // ----- .fix ct <ContentTuningId> [rowIndex] -----
    // Updates ContentTuningID for a row in creature_template_difficulty.
    //
    // Command forms:
    //   .fix ct <ID>       — updates the FIRST row in order
    //   .fix ct <ID> <N>   — updates the Nth row in order (1-indexed)
    //                        If the Nth row doesn't exist — INSERT with that DifficultyID.
    //
    // If no rows exist at all — INSERT with standard StefalWoW defaults.
    static bool HandleFixContentTuning(ChatHandler* h, uint32 ctId, Optional<uint32> rowIndexOpt)
    {
        if (ctId == 0)
        {
            h->SendSysMessage("Usage: .fix ct <ContentTuningId> [rowIndex]");
            return true;
        }

        uint32 rowIndex = 0;  // 0 = first row (default)
        if (rowIndexOpt)
        {
            if (*rowIndexOpt == 0)
            {
                h->SendSysMessage("[gm_fixer] rowIndex must be >= 1");
                return true;
            }
            rowIndex = *rowIndexOpt - 1;  // convert to 0-indexed
        }

        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read all rows ordered by ascending DifficultyID.
        QueryResult fullRes = WorldDatabase.PQuery(
            "SELECT DifficultyID FROM creature_template_difficulty "
            "WHERE Entry = {} ORDER BY DifficultyID", entry);

        std::vector<uint32> existingDiffs;
        if (fullRes)
        {
            do
            {
                existingDiffs.push_back(fullRes->Fetch()[0].GetUInt32());
            } while (fullRes->NextRow());
        }

        std::string sql;
        std::string what;

        if (existingDiffs.empty())
        {
            // No rows at all — INSERT a new row with DifficultyID = 0
            // (or with DifficultyID = rowIndex if the Nth is needed)
            uint32 newDiffId = (rowIndex == 0) ? 0 : rowIndex;
            sql = Trinity::StringFormat(
                "INSERT INTO creature_template_difficulty "
                "(Entry, DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, "
                " ContentTuningID, HealthScalingExpansion, HealthModifier, ManaModifier, "
                " ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
                " TypeFlags3, LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax, "
                " StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, "
                " StaticFlags6, StaticFlags7, StaticFlags8, VerifiedBuild) "
                "VALUES ({}, {}, 0, 0, {}, 0, 1, 1, 1, 1, 0, 0, 0, 0, {}, {}, 0, 167, 167, "
                " 268435456, 0, 0, 0, 0, 0, 0, 0, 61609);",
                entry, newDiffId, ctId, entry, entry);
            what = Trinity::StringFormat(
                "ContentTuning -> {} (entry {}, INSERT new row DifficultyID={})",
                ctId, entry, newDiffId);
        }
        else if (rowIndex < existingDiffs.size())
        {
            // Nth row exists — UPDATE by exact PK (Entry, oldDifficultyID).
            uint32 oldDiffId = existingDiffs[rowIndex];
            sql = Trinity::StringFormat(
                "UPDATE creature_template_difficulty SET ContentTuningID = {} "
                "WHERE Entry = {} AND DifficultyID = {};",
                ctId, entry, oldDiffId);
            what = Trinity::StringFormat(
                "ContentTuning -> {} (entry {}, UPDATE row {}/DifficultyID={})",
                ctId, entry, rowIndex + 1, oldDiffId);
        }
        else
        {
            // Nth row doesn't exist — INSERT with a new DifficultyID.
            // Use max existing +1 as the new DifficultyID
            // (guarantees PK uniqueness).
            uint32 maxDiff = 0;
            for (uint32 d : existingDiffs)
                if (d > maxDiff) maxDiff = d;
            uint32 newDiffId = maxDiff + 1;
            sql = Trinity::StringFormat(
                "INSERT INTO creature_template_difficulty "
                "(Entry, DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, "
                " ContentTuningID, HealthScalingExpansion, HealthModifier, ManaModifier, "
                " ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
                " TypeFlags3, LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax, "
                " StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, "
                " StaticFlags6, StaticFlags7, StaticFlags8, VerifiedBuild) "
                "VALUES ({}, {}, 0, 0, {}, 0, 1, 1, 1, 1, 0, 0, 0, 0, {}, {}, 0, 167, 167, "
                " 268435456, 0, 0, 0, 0, 0, 0, 0, 61609);",
                entry, newDiffId, ctId, entry, entry);
            what = Trinity::StringFormat(
                "ContentTuning -> {} (entry {}, INSERT new row DifficultyID={})",
                ctId, entry, newDiffId);
        }
        return ApplyFix(h, sql, "ct", what.c_str());
    }

    // ----- .fix hp <HealthModifier> -----
    // Changes the creature's HealthModifier (hit point multiplier).
    // Not all entries have a row in creature_template_difficulty — if missing,
    // create one using the same template as in .fix ct.
    static bool HandleFixHealth(ChatHandler* h, double hpMod)
    {
        if (hpMod <= 0.0)
        {
            h->SendSysMessage("[gm_fixer] HealthModifier must be > 0.");
            return true;
        }

        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        QueryResult res = WorldDatabase.PQuery(
            "SELECT 1 FROM creature_template_difficulty WHERE Entry = {} LIMIT 1", entry);

        std::string sql;
        std::string what;
        if (res)
        {
            sql = Trinity::StringFormat(
                "UPDATE creature_template_difficulty SET HealthModifier = {} "
                "WHERE Entry = {};", hpMod, entry);
            what = Trinity::StringFormat(
                "HealthModifier -> {} (entry {}, UPDATE)", hpMod, entry);
        }
        else
        {
            // INSERT with defaults like in .fix ct, but with our HealthModifier.
            sql = Trinity::StringFormat(
                "INSERT INTO creature_template_difficulty "
                "(Entry, DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, "
                " ContentTuningID, HealthScalingExpansion, HealthModifier, ManaModifier, "
                " ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
                " TypeFlags3, LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax, "
                " StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, "
                " StaticFlags6, StaticFlags7, StaticFlags8, VerifiedBuild) "
                "VALUES ({}, 0, 0, 0, 0, 0, {}, 1, 1, 1, 0, 0, 0, 0, {}, {}, 0, 167, 167, "
                " 268435456, 0, 0, 0, 0, 0, 0, 0, 61609);",
                entry, hpMod, entry, entry);
            what = Trinity::StringFormat(
                "HealthModifier -> {} (entry {}, INSERT)", hpMod, entry);
        }
        return ApplyFix(h, sql, "hp", what.c_str());
    }

    // ----- .fix eflag <flags_extra> -----
    // Changes the creature's flags_extra in creature_template.
    // This is a bitmask of extra flags (corpse despawning, ignore aggro, etc.).
    static bool HandleFixFlagsExtra(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read old value
        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT flags_extra FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET flags_extra = {} WHERE entry = {};",
            flags, entry);
        return ApplyFix(h, sql, "eflag",
            Trinity::StringFormat("flags_extra: {} -> {} (entry {})", oldVal, flags, entry).c_str());
    }

    // ----- .fix diff <DifficultyID> [<DifficultyID>...] -----
    // Changes the creature's DifficultyID in creature_template_difficulty.
    //
    // (Entry, DifficultyID) is a composite PK, so a simple UPDATE of all rows
    // won't work — it would cause a PK conflict.
    //
    // Two modes:
    //   .fix diff X           — updates only the FIRST row in order
    //                            (by ascending current DifficultyID).
    //                            Simple UPDATE by exact PK.
    //   .fix diff X Y Z       — updates the first N rows in order:
    //                            1st to X, 2nd to Y, 3rd to Z.
    //                            Safe via DELETE + INSERT in a transaction.
    //
    // If the number of arguments > number of rows — error.
    // If the number of arguments < number of rows — remaining rows
    // keep their current DifficultyID (they are rewritten as-is).
    static bool HandleFixDifficulty(ChatHandler* h, std::vector<uint32> newIds)
    {
        if (newIds.empty())
        {
            h->SendSysMessage("Usage: .fix diff <DifficultyID> [<DifficultyID>...]");
            return true;
        }

        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read all current rows ordered by ascending DifficultyID — all columns,
        // so we can correctly restore the data later (for multi-mode).
        QueryResult fullRes = WorldDatabase.PQuery(
            "SELECT DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, "
            "       ContentTuningID, HealthScalingExpansion, HealthModifier, ManaModifier, "
            "       ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
            "       TypeFlags3, LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax, "
            "       StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, "
            "       StaticFlags6, StaticFlags7, StaticFlags8, VerifiedBuild "
            "FROM creature_template_difficulty WHERE Entry = {} ORDER BY DifficultyID",
            entry);

        if (!fullRes)
        {
            h->SendSysMessage("[gm_fixer] No row in creature_template_difficulty. Use .fix ct <id> to create.");
            return true;
        }

        // Collect all rows into a vector.
        struct DiffRow
        {
            uint32 diffId;
            int32  lvlMin, lvlMax;
            uint32 ctId;
            int32  hpScaleExp;
            float  hpMod, manaMod, armorMod, dmgMod;
            uint32 cdid, tflg1, tflg2, tflg3;
            uint32 lootId, ppLootId, skinLootId;
            uint32 goldMin, goldMax;
            uint32 sf1, sf2, sf3, sf4, sf5, sf6, sf7, sf8;
            int32  verified;
        };
        std::vector<DiffRow> rows;
        do
        {
            Field* f = fullRes->Fetch();
            DiffRow r;
            r.diffId     = f[0].GetUInt32();
            r.lvlMin     = f[1].GetInt32();
            r.lvlMax     = f[2].GetInt32();
            r.ctId       = f[3].GetUInt32();
            r.hpScaleExp = f[4].GetInt32();
            r.hpMod      = f[5].GetFloat();
            r.manaMod    = f[6].GetFloat();
            r.armorMod   = f[7].GetFloat();
            r.dmgMod     = f[8].GetFloat();
            r.cdid       = f[9].GetUInt32();
            r.tflg1      = f[10].GetUInt32();
            r.tflg2      = f[11].GetUInt32();
            r.tflg3      = f[12].GetUInt32();
            r.lootId     = f[13].GetUInt32();
            r.ppLootId   = f[14].GetUInt32();
            r.skinLootId = f[15].GetUInt32();
            r.goldMin    = f[16].GetUInt32();
            r.goldMax    = f[17].GetUInt32();
            r.sf1        = f[18].GetUInt32();
            r.sf2        = f[19].GetUInt32();
            r.sf3        = f[20].GetUInt32();
            r.sf4        = f[21].GetUInt32();
            r.sf5        = f[22].GetUInt32();
            r.sf6        = f[23].GetUInt32();
            r.sf7        = f[24].GetUInt32();
            r.sf8        = f[25].GetUInt32();
            r.verified   = f[26].GetInt32();
            rows.push_back(r);
        } while (fullRes->NextRow());

        // Validation: arguments must not exceed the number of rows.
        if (newIds.size() > rows.size())
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] {} rows exist, but {} IDs given. Use .fix npcinfo to inspect.",
                rows.size(), newIds.size()));
            return true;
        }

        // ---- Single mode: one argument, UPDATE first row ----
        if (newIds.size() == 1 && rows.size() == 1)
        {
            std::string sql = Trinity::StringFormat(
                "UPDATE creature_template_difficulty SET DifficultyID = {} "
                "WHERE Entry = {};", newIds[0], entry);
            return ApplyFix(h, sql, "diff",
                Trinity::StringFormat(
                    "DifficultyID -> {} (entry {}, single UPDATE)", newIds[0], entry).c_str());
        }
        if (newIds.size() == 1)
        {
            // Multiple rows, but only updating the first one.
            std::string sql = Trinity::StringFormat(
                "UPDATE creature_template_difficulty SET DifficultyID = {} "
                "WHERE Entry = {} AND DifficultyID = {};",
                newIds[0], entry, rows[0].diffId);
            return ApplyFix(h, sql, "diff",
                Trinity::StringFormat(
                    "DifficultyID -> {} (entry {}, first row {} updated)",
                    newIds[0], entry, rows[0].diffId).c_str());
        }

        // ---- Multi-mode: multiple arguments. Safe DELETE + INSERT ----
        // Apply new DifficultyIDs to the first newIds.size() rows,
        // the remaining rows are rewritten as-is.
        //
        // Use a transaction so data isn't lost if INSERT fails.
        std::string sqlDelete = Trinity::StringFormat(
            "DELETE FROM creature_template_difficulty WHERE Entry = {};", entry);

        std::string sqlInsert =
            "INSERT INTO creature_template_difficulty "
            "(Entry, DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, "
            " ContentTuningID, HealthScalingExpansion, HealthModifier, ManaModifier, "
            " ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
            " TypeFlags3, LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax, "
            " StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, "
            " StaticFlags6, StaticFlags7, StaticFlags8, VerifiedBuild) VALUES ";

        for (size_t i = 0; i < rows.size(); ++i)
        {
            // For the first newIds.size() rows take the new DifficultyID,
            // for the rest — keep the old one.
            uint32 newDiff = (i < newIds.size()) ? newIds[i] : rows[i].diffId;
            DiffRow const& r = rows[i];
            sqlInsert += Trinity::StringFormat(
                "({}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {})",
                entry, newDiff,
                r.lvlMin, r.lvlMax, r.ctId, r.hpScaleExp,
                r.hpMod, r.manaMod, r.armorMod, r.dmgMod,
                r.cdid, r.tflg1, r.tflg2, r.tflg3,
                r.lootId, r.ppLootId, r.skinLootId,
                r.goldMin, r.goldMax,
                r.sf1, r.sf2, r.sf3, r.sf4, r.sf5, r.sf6, r.sf7, r.sf8,
                r.verified);
            if (i + 1 < rows.size())
                sqlInsert += ", ";
        }
        sqlInsert += ";";

        // Full SQL block for writing to the daily file and log.
        std::string fullSql = sqlDelete + "\n" + sqlInsert;

        // Execute atomically via transaction.
        auto trans = WorldDatabase.BeginTransaction();
        trans->Append(sqlDelete.c_str());
        trans->Append(sqlInsert.c_str());
        WorldDatabase.CommitTransaction(trans);

        // Append to the daily file (as a single block).
        AppendToDailySql(fullSql, "diff",
            Trinity::StringFormat("entry {}, {} rows", entry, rows.size()));

        std::string what = Trinity::StringFormat(
            "DifficultyID multi-update (entry {}, {} rows)", entry, rows.size());
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", fullSql));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, fullSql);
        return true;
    }

    // ----- .fix diff<N> <DifficultyID>  (N = 1..5) -----
    // Updates the Nth row in order in creature_template_difficulty.
    // If the Nth row doesn't exist — INSERT with the new DifficultyID.
    //
    // Example: the table has rows with DifficultyID=2 and DifficultyID=4.
    //   .fix diff2 10  =>  the second row (DifficultyID=4) changes to 10.
    //   .fix diff3 10  =>  no third row, INSERT a new one with DifficultyID=10.
    //
    // Implementation: a common ApplyFixDifficultyAt function + 5 thin wrappers,
    // because the old ChatCommand API requires separate functions for different
    // command names (can't pass a parameter).
    static bool ApplyFixDifficultyAt(ChatHandler* h, uint32 newDiffId, uint32 rowIndex)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read all rows ordered by ascending DifficultyID.
        QueryResult fullRes = WorldDatabase.PQuery(
            "SELECT DifficultyID FROM creature_template_difficulty "
            "WHERE Entry = {} ORDER BY DifficultyID", entry);

        std::vector<uint32> existingDiffs;
        if (fullRes)
        {
            do
            {
                existingDiffs.push_back(fullRes->Fetch()[0].GetUInt32());
            } while (fullRes->NextRow());
        }

        std::string sql;
        std::string what;

        if (rowIndex < existingDiffs.size())
        {
            // Nth row exists — UPDATE by exact PK.
            // Change DifficultyID to newDiffId.
            uint32 oldDiffId = existingDiffs[rowIndex];
            sql = Trinity::StringFormat(
                "UPDATE creature_template_difficulty SET DifficultyID = {} "
                "WHERE Entry = {} AND DifficultyID = {};",
                newDiffId, entry, oldDiffId);
            what = Trinity::StringFormat(
                "DifficultyID row {} -> {} (entry {}, UPDATE old={})",
                rowIndex + 1, newDiffId, entry, oldDiffId);
        }
        else
        {
            // Nth row doesn't exist — INSERT with newDiffId as DifficultyID.
            sql = Trinity::StringFormat(
                "INSERT INTO creature_template_difficulty "
                "(Entry, DifficultyID, LevelScalingDeltaMin, LevelScalingDeltaMax, "
                " ContentTuningID, HealthScalingExpansion, HealthModifier, ManaModifier, "
                " ArmorModifier, DamageModifier, CreatureDifficultyID, TypeFlags, TypeFlags2, "
                " TypeFlags3, LootID, PickPocketLootID, SkinLootID, GoldMin, GoldMax, "
                " StaticFlags1, StaticFlags2, StaticFlags3, StaticFlags4, StaticFlags5, "
                " StaticFlags6, StaticFlags7, StaticFlags8, VerifiedBuild) "
                "VALUES ({}, {}, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, {}, {}, 0, 167, 167, "
                " 268435456, 0, 0, 0, 0, 0, 0, 0, 61609);",
                entry, newDiffId, entry, entry);
            what = Trinity::StringFormat(
                "DifficultyID row {} -> {} (entry {}, INSERT)",
                rowIndex + 1, newDiffId, entry);
        }
        return ApplyFix(h, sql, "diff", what.c_str());
    }

    static bool HandleFixDifficulty1(ChatHandler* h, uint32 newDiffId) { return ApplyFixDifficultyAt(h, newDiffId, 0); }
    static bool HandleFixDifficulty2(ChatHandler* h, uint32 newDiffId) { return ApplyFixDifficultyAt(h, newDiffId, 1); }
    static bool HandleFixDifficulty3(ChatHandler* h, uint32 newDiffId) { return ApplyFixDifficultyAt(h, newDiffId, 2); }
    static bool HandleFixDifficulty4(ChatHandler* h, uint32 newDiffId) { return ApplyFixDifficultyAt(h, newDiffId, 3); }
    static bool HandleFixDifficulty5(ChatHandler* h, uint32 newDiffId) { return ApplyFixDifficultyAt(h, newDiffId, 4); }

    // ----- .fix gstate <StandState> -----
    // Changes StandState in creature_addon for a specific spawn (by SpawnId).
    // creature_addon stores per-spawn data, guid = spawn GUID.
    //
    // If no row exists — INSERT a new one with guid + StandState (remaining columns
    // take DEFAULT from the table schema).
    //
    // SQL:
    //   UPDATE: UPDATE creature_addon SET StandState = X WHERE guid = <spawnId>;
    //   INSERT: INSERT INTO creature_addon (guid, StandState) VALUES (<spawnId>, X);
    //
    // Common StandState values:
    //   0 = STAND (standing)
    //   1 = SIT (sitting on the ground)
    //   2 = SIT_CHAIR (in a chair)
    //   3 = SLEEP (sleeping)
    //   4 = SIT_LOW_CHAIR (low chair)
    //   5 = DEAD (dead)
    //   6 = KNEEL (kneeling)
    //   7 = SUBMERGED (underwater)
    static bool HandleFixGState(ChatHandler* h, uint32 state)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Check if a row exists in creature_addon.
        QueryResult res = WorldDatabase.PQuery(
            "SELECT 1 FROM creature_addon WHERE guid = {} LIMIT 1", spawnId);

        std::string sql;
        std::string what;
        if (res)
        {
            // Row exists — UPDATE.
            sql = Trinity::StringFormat(
                "UPDATE creature_addon SET StandState = {} WHERE guid = {};",
                state, spawnId);
            what = Trinity::StringFormat(
                "StandState (creature_addon) -> {} (spawn guid {}, UPDATE)",
                state, spawnId);
        }
        else
        {
            // No row — INSERT with guid + StandState.
            // Remaining columns take DEFAULT from the schema (mount=0, emote=0, etc.).
            sql = Trinity::StringFormat(
                "INSERT INTO creature_addon (guid, StandState) VALUES ({}, {});",
                spawnId, state);
            what = Trinity::StringFormat(
                "StandState (creature_addon) -> {} (spawn guid {}, INSERT)",
                state, spawnId);
        }
        return ApplyFix(h, sql, "gstate", what.c_str());
    }

    // ----- .fix cstate <StandState> -----
    // Changes StandState in creature_template_addon for the template (by entry).
    // creature_template_addon stores per-template data, Entry = creature_template.entry.
    //
    // If no row exists — INSERT a new one with Entry + StandState (remaining columns
    // take DEFAULT from the table schema).
    //
    // SQL:
    //   UPDATE: UPDATE creature_template_addon SET StandState = X WHERE Entry = <entry>;
    //   INSERT: INSERT INTO creature_template_addon (Entry, StandState) VALUES (<entry>, X);
    //
    // Affects ALL spawns of this entry (not just one specific spawn).
    static bool HandleFixCState(ChatHandler* h, uint32 state)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Check if a row exists in creature_template_addon.
        QueryResult res = WorldDatabase.PQuery(
            "SELECT 1 FROM creature_template_addon WHERE Entry = {} LIMIT 1", entry);

        std::string sql;
        std::string what;
        if (res)
        {
            // Row exists — UPDATE.
            sql = Trinity::StringFormat(
                "UPDATE creature_template_addon SET StandState = {} WHERE Entry = {};",
                state, entry);
            what = Trinity::StringFormat(
                "StandState (creature_template_addon) -> {} (entry {}, UPDATE)",
                state, entry);
        }
        else
        {
            // No row — INSERT with Entry + StandState.
            sql = Trinity::StringFormat(
                "INSERT INTO creature_template_addon (Entry, StandState) VALUES ({}, {});",
                entry, state);
            what = Trinity::StringFormat(
                "StandState (creature_template_addon) -> {} (entry {}, INSERT)",
                state, entry);
        }
        return ApplyFix(h, sql, "cstate", what.c_str());
    }

    // ----- .fix gdead -----
    // Sets DEAD status (unit_flags3 = 8193) for a specific spawn.
    // In modern TrinityCore per-spawn unit_flags3 is stored in the creature table.
    //
    // SQL (per-spawn, via creature):
    //   UPDATE creature SET unit_flags3 = 8193 WHERE guid = <spawnId>;
    static bool HandleFixGDead(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        constexpr uint32 DEAD_FLAG = 8193;  // flag combination for DEAD status

        // Read old value
        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags3 FROM creature WHERE guid = {}", spawnId))
            oldVal = r->Fetch()[0].GetUInt32();

        // unit_flags3 = DEAD + curHealthPct = 0 (otherwise NPC lies down but with full HP)
        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET unit_flags3 = {}, curHealthPct = 0 WHERE guid = {};",
            DEAD_FLAG, spawnId);
        return ApplyFix(h, sql, "gdead",
            Trinity::StringFormat("unit_flags3: {} -> {} DEAD, curHealthPct -> 0 (spawn guid {})", oldVal, DEAD_FLAG, spawnId).c_str());
    }

    // ----- .fix cdead -----
    // Sets DEAD status (unit_flags3 = 8193) for all spawns of an entry.
    //
    // SQL (per-template):
    //   UPDATE creature_template SET unit_flags3 = 8193 WHERE entry = <entry>;
    static bool HandleFixCDead(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        constexpr uint32 DEAD_FLAG = 8193;

        // Read old value
        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags3 FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET unit_flags3 = {} WHERE entry = {};",
            DEAD_FLAG, entry);
        return ApplyFix(h, sql, "cdead",
            Trinity::StringFormat("unit_flags3: {} -> {} DEAD (entry {})", oldVal, DEAD_FLAG, entry).c_str());
    }

    // ----- .fix gnpcflag <npcflag> -----
    // Changes npcflag for a specific spawn (per-spawn, via creature).
    // In modern TrinityCore per-spawn npcflag is stored in the creature table.
    //
    // SQL: UPDATE creature SET npcflag = X WHERE guid = <spawnId>;
    //
    // Common npcflag values:
    //   0         = none
    //   1         = GOSSIP (can talk to)
    //   128       = VENDOR (vendor)
    //   4096      = TRAINER (trainer)
    //   65536     = BANKER (banker)
    //   131072    = PETITIONER (guild registrar)
    //   524288    = TABARDDESIGNER
    //   1048576   = BATTLEMASTER (battlemaster)
    //   2097152   = AUCTIONEER (auctioneer)
    //   0x1000000 = SPIRITHEALER (spirit healer)
    //   0x2000000 = SPIRITGUIDE (spirit guide)
    // Can be combined by addition.
    static bool HandleFixGNpcFlag(ChatHandler* h, uint64 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Read old value
        uint64 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT npcflag FROM creature WHERE guid = {}", spawnId))
            oldVal = r->Fetch()[0].GetUInt64();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET npcflag = {} WHERE guid = {};",
            flags, spawnId);
        return ApplyFix(h, sql, "gnpcflag",
            Trinity::StringFormat("npcflag: {} -> {} (spawn guid {})", oldVal, flags, spawnId).c_str());
    }

    // ----- .fix cnpcflag <npcflag> -----
    // Changes npcflag for the template (per-template, via creature_template).
    // Affects ALL spawns of this entry.
    //
    // SQL: UPDATE creature_template SET npcflag = X WHERE entry = <entry>;
    static bool HandleFixCNpcFlag(ChatHandler* h, uint64 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read old value
        uint64 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT npcflag FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt64();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET npcflag = {} WHERE entry = {};",
            flags, entry);
        return ApplyFix(h, sql, "cnpcflag",
            Trinity::StringFormat("npcflag: {} -> {} (entry {})", oldVal, flags, entry).c_str());
    }

    // ----- .fix guflags <unit_flags> -----
    // Changes unit_flags for a specific spawn (per-spawn, via creature).
    //
    // SQL: UPDATE creature SET unit_flags = X WHERE guid = <spawnId>;
    //
    // Common unit_flags values:
    //   0           = none
    //   64          = UNIT_FLAG_NOT_ATTACKABLE_1 (cannot be attacked)
    //   256         = UNIT_FLAG_IMMUNE_TO_NPC (immune to NPC spells)
    //   512         = UNIT_FLAG_IMMUNE_TO_PC (immune to players)
    //   768         = 256 + 512 (fully immune NPC)
    //   32768       = UNIT_FLAG_PACIFIED (doesn't attack on its own)
    //   33554432    = UNIT_FLAG_NOT_SELECTABLE (cannot be selected)
    //   67108864    = UNIT_FLAG_SKINNABLE (can be skinned)
    // Can be combined by addition.
    static bool HandleFixGUnitFlags(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Read old value
        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags FROM creature WHERE guid = {}", spawnId))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET unit_flags = {} WHERE guid = {};",
            flags, spawnId);
        return ApplyFix(h, sql, "guflags",
            Trinity::StringFormat("unit_flags: {} -> {} (spawn guid {})", oldVal, flags, spawnId).c_str());
    }

    // ----- .fix cuflags <unit_flags> -----
    // Changes unit_flags for the template (per-template, via creature_template).
    // Affects ALL spawns of this entry.
    //
    // SQL: UPDATE creature_template SET unit_flags = X WHERE entry = <entry>;
    static bool HandleFixCUnitFlags(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read old value
        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET unit_flags = {} WHERE entry = {};",
            flags, entry);
        return ApplyFix(h, sql, "cuflags",
            Trinity::StringFormat("unit_flags: {} -> {} (entry {})", oldVal, flags, entry).c_str());
    }

    // ----- .fix guflags2 <unit_flags2> -----
    static bool HandleFixGUnitFlags2(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags2 FROM creature WHERE guid = {}", spawnId))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET unit_flags2 = {} WHERE guid = {};",
            flags, spawnId);
        return ApplyFix(h, sql, "guflags2",
            Trinity::StringFormat("unit_flags2: {} -> {} (spawn guid {})", oldVal, flags, spawnId).c_str());
    }

    // ----- .fix cuflags2 <unit_flags2> -----
    static bool HandleFixCUnitFlags2(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags2 FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET unit_flags2 = {} WHERE entry = {};",
            flags, entry);
        return ApplyFix(h, sql, "cuflags2",
            Trinity::StringFormat("unit_flags2: {} -> {} (entry {})", oldVal, flags, entry).c_str());
    }

    // ----- .fix guflags3 <unit_flags3> -----
    static bool HandleFixGUnitFlags3(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags3 FROM creature WHERE guid = {}", spawnId))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET unit_flags3 = {} WHERE guid = {};",
            flags, spawnId);
        return ApplyFix(h, sql, "guflags3",
            Trinity::StringFormat("unit_flags3: {} -> {} (spawn guid {})", oldVal, flags, spawnId).c_str());
    }

    // ----- .fix cuflags3 <unit_flags3> -----
    static bool HandleFixCUnitFlags3(ChatHandler* h, uint32 flags)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT unit_flags3 FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET unit_flags3 = {} WHERE entry = {};",
            flags, entry);
        return ApplyFix(h, sql, "cuflags3",
            Trinity::StringFormat("unit_flags3: {} -> {} (entry {})", oldVal, flags, entry).c_str());
    }

    // ----- .fix combat -----
    // Enables SmartAI and adds a smart_script to attack nearby creatures
    // within a 10 yard radius.
    //
    // Logic:
    //   1. Checks AIName in creature_template.
    //      If AIName != 'SmartAI' — UPDATE it to 'SmartAI'.
    //   2. Checks for a smart_scripts entry with attack parameters for this entry
    //      (action_type=49, target_type=25, target_param1=10).
    //      If no such script exists — INSERT with id = MAX(id)+1 (to avoid conflicts
    //      with existing scripts for this entry).
    //
    // SQL:
    //   UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = <entry>;
    //   INSERT INTO smart_scripts (entryorguid, source_type, id, event_type,
    //     event_chance, action_type, target_type, target_param1, target_param2,
    //     target_param3, target_param4)
    //   VALUES (entry, 0, <nextId>, 60, 100, 49, 25, 10, 0, 0, 0);
    //
    // smart_script parameters:
    //   source_type  = 0   (SMART_SCRIPT_SOURCE_CREATURE)
    //   id           = auto (MAX+1 for this entry)
    //   event_type   = 60  (SMART_EVENT_UPDATE — periodic)
    //   event_chance = 100 (100% trigger chance)
    //   action_type  = 49  (SMART_ACTION_ATTACK — attack)
    //   target_type  = 25  (SMART_TARGET_CREATURE_RANGE — creatures in range)
    //   target_param1= 10  (radius 10 yards)
    static bool HandleFixCombat(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // 1. Check AIName in creature_template.
        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        bool needUpdateAI = true;
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (aiName == "SmartAI")
                needUpdateAI = false;
        }

        // 2. Check for smart_scripts with attack parameters for this entry.
        // Look for action_type=49 (ATTACK) + target_type=25 (CREATURE_RANGE) +
        // target_param1=10 (10yd radius) — these are the unique parameters of our fix.
        QueryResult ssRes = WorldDatabase.PQuery(
            "SELECT 1 FROM smart_scripts WHERE entryorguid = {} AND source_type = 0 "
            "AND action_type = 49 AND target_type = 25 AND target_param1 = 10 LIMIT 1",
            entry);
        bool needInsertScript = !ssRes;

        // If already SmartAI and script exists — nothing to do.
        if (!needUpdateAI && !needInsertScript)
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] combat: entry {} already has SmartAI + combat script, nothing to do.",
                entry));
            return true;
        }

        // Calculate the next free id for this entry (MAX+1, minimum 0).
        uint32 nextId = 0;
        if (needInsertScript)
        {
            QueryResult maxRes = WorldDatabase.PQuery(
                "SELECT IFNULL(MAX(id), -1) + 1 FROM smart_scripts "
                "WHERE entryorguid = {} AND source_type = 0", entry);
            if (maxRes)
                nextId = maxRes->Fetch()[0].GetUInt32();
        }

        // Build the SQL block (one or two statements).
        std::string sqlLog;  // for the daily file and log
        std::vector<std::string> stmts;  // for separate execution
        if (needUpdateAI)
        {
            std::string s = Trinity::StringFormat(
                "UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = {};",
                entry);
            stmts.push_back(s);
            sqlLog += s + "\n";
        }
        if (needInsertScript)
        {
            // event_param1=0, event_param2=0  — no delay on first trigger
            // event_param3=1000, event_param4=1000 — repeat every 1 second (1 sec = 1000 ms)
            // Without event_param3/4 SMART_EVENT_UPDATE triggers once and never repeats!
            std::string s = Trinity::StringFormat(
                "INSERT INTO smart_scripts "
                "(entryorguid, source_type, id, link, event_type, event_phase_mask, "
                " event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, "
                " action_type, action_param1, action_param2, action_param3, "
                " action_param4, action_param5, action_param6, "
                " target_type, target_param1, target_param2, target_param3, target_param4, "
                " target_x, target_y, target_z, target_o, comment) "
                "VALUES ({}, 0, {}, 0, 60, 0, 100, 0, "
                " 0, 0, 1000, 1000, "
                " 49, 0, 0, 0, 0, 0, 0, "
                " 25, 10, 0, 0, 0, "
                " 0, 0, 0, 0, 'gm_fixer: combat attack 10yd');",
                entry, nextId);
            stmts.push_back(s);
            sqlLog += s;
        }

        // Execute each statement separately — DirectExecute does NOT support
        // multiple statements in a single call (MySQL C API limitation).
        for (auto const& s : stmts)
            WorldDatabase.DirectExecute(s.c_str());

        std::string what;
        if (needUpdateAI && needInsertScript)
            what = Trinity::StringFormat(
                "combat: entry {} (SmartAI + script id={})", entry, nextId);
        else if (needUpdateAI)
            what = Trinity::StringFormat(
                "combat: entry {} (SmartAI only, combat script already exists)", entry);
        else
            what = Trinity::StringFormat(
                "combat: entry {} (script id={}, SmartAI already set)", entry, nextId);

        AppendToDailySql(sqlLog, "combat", what);

        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }

    // ----- .fix questprev <questId> <prevQuestId> -----
    // Sets PrevQuestID in quest_template_addon for quest questId.
    // prevQuestId is the ID of the quest that must be completed BEFORE questId.
    //
    // If no row exists in quest_template_addon — INSERT a new one.
    //
    // SQL:
    //   UPDATE: UPDATE quest_template_addon SET PrevQuestID = X WHERE ID = Y;
    //   INSERT: INSERT INTO quest_template_addon (ID, PrevQuestID) VALUES (Y, X);
    //
    // Notes:
    //   - If prevQuestId > 0 — the quest must be completed (normal prerequisite)
    //   - If prevQuestId < 0 — the quest must NOT be completed (exclusive)
    static bool HandleFixQuestPrev(ChatHandler* h, uint32 questId, int32 prevQuestId)
    {
        // Check that the quest exists.
        if (!sObjectMgr->GetQuestTemplate(questId))
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] Quest {} not found in quest_template.", questId));
            return true;
        }
        // If prevQuestId != 0 — check that the prerequisite quest also exists.
        if (prevQuestId != 0 && !sObjectMgr->GetQuestTemplate(uint32(std::abs(prevQuestId))))
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] PrevQuest {} not found in quest_template.",
                std::abs(prevQuestId)));
            return true;
        }

        // Check if a row exists in quest_template_addon.
        QueryResult res = WorldDatabase.PQuery(
            "SELECT 1 FROM quest_template_addon WHERE ID = {} LIMIT 1", questId);

        std::string sql;
        std::string what;
        if (res)
        {
            // Row exists — UPDATE.
            sql = Trinity::StringFormat(
                "UPDATE quest_template_addon SET PrevQuestID = {} WHERE ID = {};",
                prevQuestId, questId);
            what = Trinity::StringFormat(
                "PrevQuestID -> {} (quest {}, UPDATE)", prevQuestId, questId);
        }
        else
        {
            // No row — INSERT with ID + PrevQuestID.
            sql = Trinity::StringFormat(
                "INSERT INTO quest_template_addon (ID, PrevQuestID) VALUES ({}, {});",
                questId, prevQuestId);
            what = Trinity::StringFormat(
                "PrevQuestID -> {} (quest {}, INSERT)", prevQuestId, questId);
        }
        return ApplyFix(h, sql, "questprev", what.c_str());
    }

    // ----- .fix gmove <MovementType> [wander_distance] -----
    // Changes MovementType AND wander_distance for a specific spawn (per-spawn).
    // If wander_distance is not specified — default = 8.
    //
    // SQL: UPDATE creature SET MovementType = X, wander_distance = Y WHERE guid = <spawnId>;
    //
    // Common MovementType values:
    //   0 = IDLE (stays in place)
    //   1 = RANDOM (wanders randomly within wander_distance radius)
    //   2 = WAYPOINT (follows a waypoint route)
    static bool HandleFixGMove(ChatHandler* h, uint32 moveType, Optional<double> wanderDistOpt)
    {
        if (moveType > 2)
        {
            h->SendSysMessage("[gm_fixer] MovementType must be 0 (IDLE), 1 (RANDOM) or 2 (WAYPOINT).");
            return true;
        }

        double wanderDist = 8.0;
        if (wanderDistOpt)
        {
            if (*wanderDistOpt < 0.0)
            {
                h->SendSysMessage("[gm_fixer] wander_distance must be >= 0.");
                return true;
            }
            wanderDist = *wanderDistOpt;
        }

        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Check AIName — if empty, add UPDATE to SmartAI.
        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        bool needSmartAI = true;
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (!aiName.empty())
                needSmartAI = false;
        }

        // Build SQL (one or two operations).
        std::string sqlLog;
        std::vector<std::string> stmts;
        if (needSmartAI)
        {
            std::string s = Trinity::StringFormat(
                "UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = {};", entry);
            stmts.push_back(s);
            sqlLog += s + "\n";
        }

        std::string moveSql = Trinity::StringFormat(
            "UPDATE creature SET MovementType = {}, wander_distance = {} WHERE guid = {};",
            moveType, wanderDist, spawnId);
        stmts.push_back(moveSql);
        sqlLog += moveSql;

        for (auto const& s : stmts)
            WorldDatabase.DirectExecute(s.c_str());

        std::string what = Trinity::StringFormat(
            "MovementType -> {}, wander_distance -> {} (spawn guid {}, entry {}){}",
            moveType, wanderDist, spawnId, entry,
            needSmartAI ? " + SmartAI" : "");
        AppendToDailySql(sqlLog, "gmove", what);

        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }

    // ----- .fix cmove <MovementType> -----
    // Changes MovementType for the template (per-template, via creature_template).
    // Affects ALL spawns of this entry.
    //
    // SQL: UPDATE creature_template SET MovementType = X WHERE entry = <entry>;
    static bool HandleFixCMove(ChatHandler* h, uint32 moveType)
    {
        if (moveType > 2)
        {
            h->SendSysMessage("[gm_fixer] MovementType must be 0 (IDLE), 1 (RANDOM) or 2 (WAYPOINT).");
            return true;
        }
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read old value
        uint32 oldVal = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT MovementType FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetUInt32();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET MovementType = {} WHERE entry = {};",
            moveType, entry);
        return ApplyFix(h, sql, "cmove",
            Trinity::StringFormat("MovementType: {} -> {} (entry {})", oldVal, moveType, entry).c_str());
    }

    // ----- .fix gmoverange <wander_distance> -----
    // Changes wander_distance for a specific spawn (per-spawn, via creature).
    // wander_distance is the random wandering radius (in yards).
    // Only meaningful with MovementType = 1 (RANDOM).
    //
    // SQL: UPDATE creature SET wander_distance = X WHERE guid = <spawnId>;
    static bool HandleFixGMoveRange(ChatHandler* h, double dist)
    {
        if (dist < 0.0)
        {
            h->SendSysMessage("[gm_fixer] wander_distance must be >= 0.");
            return true;
        }
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Read old value
        float oldVal = 0.0f;
        if (QueryResult r = WorldDatabase.PQuery("SELECT wander_distance FROM creature WHERE guid = {}", spawnId))
            oldVal = r->Fetch()[0].GetFloat();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET wander_distance = {} WHERE guid = {};",
            dist, spawnId);
        return ApplyFix(h, sql, "gmoverange",
            Trinity::StringFormat("wander_distance: {} -> {} (spawn guid {})", oldVal, dist, spawnId).c_str());
    }

    // ----- .fix smart -----
    // Checks AIName in creature_template. If empty — sets it to 'SmartAI'.
    // If already set — does nothing.
    //
    // SQL: UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = <entry>;
    static bool HandleFixSmart(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Check AIName in creature_template.
        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (!aiName.empty())
            {
                h->SendSysMessage(Trinity::StringFormat(
                    "[gm_fixer] AIName already set to '{}' (entry {}), nothing to do.",
                    aiName, entry));
                return true;
            }
        }

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = {};", entry);
        return ApplyFix(h, sql, "smart",
            Trinity::StringFormat("AIName: '<empty>' -> 'SmartAI' (entry {})", entry).c_str());
    }

    // ----- .fix unsmart -----
    // Removes AIName (sets empty string) in creature_template.
    // If AIName is already empty — does nothing.
    static bool HandleFixUnsmart(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (aiName.empty())
            {
                h->SendSysMessage(Trinity::StringFormat(
                    "[gm_fixer] AIName already empty (entry {}), nothing to do.", entry));
                return true;
            }

            std::string sql = Trinity::StringFormat(
                "UPDATE creature_template SET AIName = '' WHERE entry = {};", entry);
            return ApplyFix(h, sql, "unsmart",
                Trinity::StringFormat("AIName: '{}' -> '' (entry {})", aiName, entry).c_str());
        }

        h->SendSysMessage(Trinity::StringFormat(
            "[gm_fixer] creature_template entry {} not found.", entry));
        return true;
    }

    // ----- .fix wayinfo -----
    // Finds waypoint path IDs for all waypoint nodes within 30 yards of the player.
    static bool HandleFixWayInfo(ChatHandler* h)
    {
        Player* p = h->GetSession()->GetPlayer();
        if (!p) return true;

        float x = p->GetPositionX();
        float y = p->GetPositionY();
        float z = p->GetPositionZ();
        uint32 mapId = p->GetMapId();

        // Convert float to string via snprintf (StringFormat may produce a comma)
        auto fmtFloatW = [](float v) -> std::string {
            char buf[32];
            std::snprintf(buf, sizeof(buf), "%.4f", v);
            return std::string(buf);
        };

        std::string xmin = fmtFloatW(x - 30.0f);
        std::string xmax = fmtFloatW(x + 30.0f);
        std::string ymin = fmtFloatW(y - 30.0f);
        std::string ymax = fmtFloatW(y + 30.0f);

        std::string query =
            "SELECT PathId, NodeId, PositionX, PositionY, PositionZ "
            "FROM waypoint_path_node "
            "WHERE PositionX BETWEEN " + xmin + " AND " + xmax +
            " AND PositionY BETWEEN " + ymin + " AND " + ymax +
            " LIMIT 50";
        QueryResult result = WorldDatabase.Query(query.c_str());

        if (!result)
        {
            h->SendSysMessage("[gm_fixer] No waypoint nodes found within 30 yards.");
            return true;
        }

        h->SendSysMessage(Trinity::StringFormat(
            "[gm_fixer] Waypoint nodes near ({:.1f}, {:.1f}, {:.1f}) map {}:", x, y, z, mapId));

        std::set<uint32> seenPaths;
        do
        {
            Field* f = result->Fetch();
            uint32 pathId = f[0].GetUInt32();
            uint32 nodeId = f[1].GetUInt32();
            float nx = f[2].GetFloat();
            float ny = f[3].GetFloat();
            float nz = f[4].GetFloat();

            float dx = nx - x;
            float dy = ny - y;
            float dist = std::sqrt(dx * dx + dy * dy);

            // Skip nodes farther than 30 yards (BETWEEN filters by a square, not a circle)
            if (dist > 30.0f)
                continue;

            h->SendSysMessage(Trinity::StringFormat(
                "  Path {} Node {} at ({:.1f}, {:.1f}, {:.1f}) dist {:.1f}yd",
                pathId, nodeId, nx, ny, nz, dist));
            seenPaths.insert(pathId);
        } while (result->NextRow());

        h->SendSysMessage(Trinity::StringFormat(
            "  Found {} unique path(s).",
            uint32(seenPaths.size())));
        return true;
    }

    // ----- .fix wayadd -----
    // Creates a new waypoint_path and assigns it to the selected NPC.
    // PathId = MAX(PathId)+1.
    // Sets MovementType=2 (WAYPOINT) and movementId=PathId in creature.
    // Also checks AIName — if empty, sets it to SmartAI.
    static bool HandleFixWayAdd(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId.");
            return true;
        }

        // Calculate PathId = MAX+1 (via raw query, PQuery with aggregates is unstable)
        uint32 newPathId = 1;
        QueryResult maxRes = WorldDatabase.Query("SELECT IFNULL(MAX(PathId), 0) + 1 FROM waypoint_path");
        if (maxRes)
            newPathId = maxRes->Fetch()[0].GetUInt32();

        // Check AIName
        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        bool needSmartAI = true;
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (!aiName.empty())
                needSmartAI = false;
        }

        // Build SQL
        std::string sqlLog;
        std::vector<std::string> stmts;

        if (needSmartAI)
        {
            std::string s = Trinity::StringFormat(
                "UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = {};", entry);
            stmts.push_back(s);
            sqlLog += s + "\n";
        }

        // INSERT waypoint_path
        std::string sPath = Trinity::StringFormat(
            "INSERT INTO waypoint_path (PathId, MoveType, Flags, Comment) VALUES ({}, 0, 0, 'gm_fixer: entry {}');",
            newPathId, entry);
        stmts.push_back(sPath);
        sqlLog += sPath + "\n";

        // Link the path to the spawn via creature_addon.PathId (like .wp load)
        // If row exists — UPDATE, if not — INSERT
        QueryResult addonRes = WorldDatabase.PQuery(
            "SELECT 1 FROM creature_addon WHERE guid = {} LIMIT 1", spawnId);
        std::string sAddon;
        if (addonRes)
        {
            sAddon = Trinity::StringFormat(
                "UPDATE creature_addon SET PathId = {} WHERE guid = {};",
                newPathId, spawnId);
        }
        else
        {
            sAddon = Trinity::StringFormat(
                "INSERT INTO creature_addon (guid, PathId) VALUES ({}, {});",
                spawnId, newPathId);
        }
        stmts.push_back(sAddon);
        sqlLog += sAddon + "\n";

        // MovementType = WAYPOINT (2)
        std::string sCreature = Trinity::StringFormat(
            "UPDATE creature SET MovementType = 2 WHERE guid = {};",
            spawnId);
        stmts.push_back(sCreature);
        sqlLog += sCreature;

        for (auto const& s : stmts)
            WorldDatabase.DirectExecute(s.c_str());
        AppendToDailySql(sqlLog, "wayadd",
            Trinity::StringFormat("PathId={} -> entry {} (spawn {}){}",
                newPathId, entry, spawnId,
                needSmartAI ? " + SmartAI" : ""));

        // Apply at runtime — reload path + load + init
        sWaypointMgr->ReloadPath(newPathId);
        c->LoadPath(newPathId);
        c->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
        c->GetMotionMaster()->Initialize();
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] .wp reload {} applied automatically", newPathId));

        std::string what = Trinity::StringFormat(
            "waypoint_path {} created -> entry {} (spawn {}){}",
            newPathId, entry, spawnId,
            needSmartAI ? " + SmartAI" : "");
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }

    // ----- .fix waynode [nodeId] [delay] -----
    // No arguments: adds a new node (NodeId = MAX+1) at the player's current position.
    // .fix waynode <nodeId>        — update coordinates of an existing node (player position)
    // .fix waynode <nodeId> <delay>— update coordinates + delay of an existing node
    static bool HandleFixWayNode(ChatHandler* h, Optional<uint32> nodeIdOpt, Optional<uint32> delayOpt)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId.");
            return true;
        }

        // Read PathId from creature_addon.PathId (NOT creature.currentwaypoint!)
        uint32 pathId = 0;
        QueryResult crRes = WorldDatabase.PQuery(
            "SELECT PathId FROM creature_addon WHERE guid = {}", spawnId);
        if (crRes)
            pathId = crRes->Fetch()[0].GetUInt32();

        if (pathId == 0)
        {
            h->SendSysMessage("[gm_fixer] This NPC has no waypoint path. Use .fix wayadd first.");
            return true;
        }

        // Parse arguments: [nodeId] [delay]
        uint32 nodeId = 0;   // 0 = new node
        uint32 delay = 0;
        bool updateMode = false;

        if (nodeIdOpt)
        {
            nodeId = *nodeIdOpt;
            updateMode = true;
        }
        if (delayOpt)
            delay = *delayOpt;

        // Player position
        Player* p = h->GetSession()->GetPlayer();
        if (!p) return true;

        // Convert float to string with dot via snprintf
        // (StringFormat/ostringstream may use comma in Russian locale)
        auto fmtFloat = [](float v) -> std::string {
            char buf[32];
            std::snprintf(buf, sizeof(buf), "%.4f", v);
            return std::string(buf);
        };

        std::string sx = fmtFloat(p->GetPositionX());
        std::string sy = fmtFloat(p->GetPositionY());
        std::string sz = fmtFloat(p->GetPositionZ());
        std::string so = fmtFloat(p->GetOrientation());

        std::string sql;
        std::string what;

        if (updateMode)
        {
            // UPDATE existing node
            sql = "UPDATE waypoint_path_node SET PositionX = " + sx +
                  ", PositionY = " + sy +
                  ", PositionZ = " + sz +
                  ", Orientation = " + so +
                  ", Delay = " + std::to_string(delay) +
                  " WHERE PathId = " + std::to_string(pathId) +
                  " AND NodeId = " + std::to_string(nodeId) + ";";
            what = Trinity::StringFormat("Path {} Node {} -> ({},{},{}) delay {} (UPDATE)",
                pathId, nodeId, sx, sy, sz, delay);
        }
        else
        {
            // INSERT new node — calculate NodeId = MAX+1 via raw query
            uint32 newNodeId = 1;
            std::string maxQuery = "SELECT IFNULL(MAX(NodeId), 0) + 1 FROM waypoint_path_node WHERE PathId = " + std::to_string(pathId);
            QueryResult maxRes = WorldDatabase.Query(maxQuery.c_str());
            if (maxRes)
                newNodeId = maxRes->Fetch()[0].GetUInt32();
            nodeId = newNodeId;

            sql = "INSERT INTO waypoint_path_node (PathId, NodeId, PositionX, PositionY, PositionZ, Orientation, Delay) VALUES (" +
                  std::to_string(pathId) + ", " + std::to_string(nodeId) + ", " +
                  sx + ", " + sy + ", " + sz + ", " + so + ", " + std::to_string(delay) + ");";
            what = Trinity::StringFormat("Path {} Node {} -> ({},{},{}) delay {} (INSERT)",
                pathId, nodeId, sx, sy, sz, delay);
        }

        WorldDatabase.DirectExecute(sql.c_str());
        AppendToDailySql(sql, "waynode", what);

        // Automatic .wp reload for this NPC's pathId
        sWaypointMgr->ReloadPath(pathId);
        c->LoadPath(pathId);
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] .wp reload {} applied automatically", pathId));

        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL: {}", sql));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sql);
        return true;
    }

    // ----- .fix gauras <spellId> [<spellId>...] -----
    // Sets auras in creature_addon for a specific spawn.
    // Multiple spellIds separated by spaces — all written to the auras column.
    // Also checks AIName and applies auras at runtime.
    //
    // SQL: UPDATE creature_addon SET auras = 'ID1 ID2 ID3' WHERE guid = <spawnId>;
    static bool HandleFixGAuras(ChatHandler* h, std::vector<uint32> spellIds)
    {
        if (spellIds.empty())
        {
            h->SendSysMessage("Usage: .fix gauras <spellId> [<spellId>...]");
            return true;
        }

        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Build auras string: "ID1 ID2 ID3"
        std::string aurasStr;
        for (size_t i = 0; i < spellIds.size(); ++i)
        {
            if (i > 0)
                aurasStr += " ";
            aurasStr += std::to_string(spellIds[i]);
        }

        // Check AIName
        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        bool needSmartAI = true;
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (!aiName.empty())
                needSmartAI = false;
        }

        // Read old auras
        std::string oldAuras = "<none>";
        QueryResult oldRes = WorldDatabase.PQuery(
            "SELECT auras FROM creature_addon WHERE guid = {}", spawnId);
        if (oldRes)
        {
            std::string s = oldRes->Fetch()[0].GetString();
            oldAuras = s.empty() ? "<empty>" : s;
        }

        // Check if a row exists in creature_addon
        QueryResult res = WorldDatabase.PQuery(
            "SELECT 1 FROM creature_addon WHERE guid = {} LIMIT 1", spawnId);

        std::string auraSql;
        std::string what;
        if (res)
        {
            auraSql = Trinity::StringFormat(
                "UPDATE creature_addon SET auras = '{}' WHERE guid = {};",
                aurasStr, spawnId);
            what = Trinity::StringFormat("auras: '{}' -> '{}' (spawn guid {}, UPDATE)",
                oldAuras, aurasStr, spawnId);
        }
        else
        {
            auraSql = Trinity::StringFormat(
                "INSERT INTO creature_addon (guid, auras) VALUES ({}, '{}');",
                spawnId, aurasStr);
            what = Trinity::StringFormat("auras: '<none>' -> '{}' (spawn guid {}, INSERT)",
                aurasStr, spawnId);
        }

        // Build SQL (one or two operations)
        std::string sqlLog;
        std::vector<std::string> stmts;
        if (needSmartAI)
        {
            std::string s = Trinity::StringFormat(
                "UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = {};", entry);
            stmts.push_back(s);
            sqlLog += s + "\n";
        }
        stmts.push_back(auraSql);
        sqlLog += auraSql;

        for (auto const& s : stmts)
            WorldDatabase.DirectExecute(s.c_str());

        if (needSmartAI)
            what += Trinity::StringFormat(" + SmartAI (entry {})", entry);
        AppendToDailySql(sqlLog, "gauras", what);

        // Apply auras at runtime
        for (uint32 sid : spellIds)
        {
            if (sSpellMgr->GetSpellInfo(sid, DIFFICULTY_NONE))
                c->AddAura(sid, c);
        }

        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }

    // ----- .fix emote <emoteId> -----
    // Applies emoteState to the selected NPC at runtime (without DB changes).
    // Equivalent to .npc playemote, but within gm_fixer.
    static bool HandleFixEmote(ChatHandler* h, uint32 emote)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        c->SetEmoteState(Emote(emote));
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] emote {} applied to '{}' (runtime only)", emote, c->GetName()));
        return true;
    }

    // ----- .fix gemote <emoteId> -----
    // Changes Emote (animation) in creature_addon for a specific spawn (by SpawnId).
    // If no row exists — INSERT a new one.
    //
    // SQL:
    //   UPDATE: UPDATE creature_addon SET emote = X WHERE guid = <spawnId>;
    //   INSERT: INSERT INTO creature_addon (guid, emote) VALUES (<spawnId>, X);
    //
    // Common emote values:
    //   0  = none (reset)
    //   1  = TALK
    //   4  = ONE_SHOT_BOW
    //   10 = STATE_DANCE
    //   16 = ONE_SHOT_KNEEL
    //   23 = STATE_WORK
    //   26 = STATE_SLEEP
    //   27 = STATE_SIT
    //   43 = STATE_SLEEP
    static bool HandleFixGEmote(ChatHandler* h, uint32 emote)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Check AIName — if empty, add UPDATE to SmartAI.
        QueryResult aiRes = WorldDatabase.PQuery(
            "SELECT AIName FROM creature_template WHERE entry = {} LIMIT 1", entry);
        bool needSmartAI = true;
        if (aiRes)
        {
            std::string aiName = aiRes->Fetch()[0].GetString();
            if (!aiName.empty())
                needSmartAI = false;
        }

        // Check if a row exists in creature_addon.
        QueryResult res = WorldDatabase.PQuery(
            "SELECT 1 FROM creature_addon WHERE guid = {} LIMIT 1", spawnId);

        std::string emoteSql;
        std::string what;
        if (res)
        {
            emoteSql = Trinity::StringFormat(
                "UPDATE creature_addon SET emote = {} WHERE guid = {};",
                emote, spawnId);
            what = Trinity::StringFormat(
                "emote -> {} (spawn guid {}, UPDATE)", emote, spawnId);
        }
        else
        {
            emoteSql = Trinity::StringFormat(
                "INSERT INTO creature_addon (guid, emote) VALUES ({}, {});",
                spawnId, emote);
            what = Trinity::StringFormat(
                "emote -> {} (spawn guid {}, INSERT)", emote, spawnId);
        }

        // Build SQL (one or two operations).
        std::string sqlLog;
        std::vector<std::string> stmts;
        if (needSmartAI)
        {
            std::string s = Trinity::StringFormat(
                "UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = {};", entry);
            stmts.push_back(s);
            sqlLog += s + "\n";
        }
        stmts.push_back(emoteSql);
        sqlLog += emoteSql;

        for (auto const& s : stmts)
            WorldDatabase.DirectExecute(s.c_str());

        if (needSmartAI)
            what += Trinity::StringFormat(" + SmartAI (entry {})", entry);
        AppendToDailySql(sqlLog, "gemote", what);

        // Apply emote at runtime
        c->SetEmoteState(Emote(emote));

        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }

    // ----- .fix gpos -----
    // Updates position_x, position_y, position_z, orientation for a specific
    // spawn (by SpawnID/guid) with the current coordinates of the selected NPC in the world.
    //
    // SQL: UPDATE creature SET position_x = X, position_y = Y, position_z = Z, orientation = O WHERE guid = <spawnId>;
    //
    // Useful when the GM has moved the NPC to a new location via .npc move or
    // manually, and wants to save the new coordinates to the DB.
    static bool HandleFixGPos(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        float x = c->GetPositionX();
        float y = c->GetPositionY();
        float z = c->GetPositionZ();
        float o = c->GetOrientation();

        // Read old values
        float oldX = 0, oldY = 0, oldZ = 0, oldO = 0;
        if (QueryResult r = WorldDatabase.PQuery("SELECT position_x, position_y, position_z, orientation FROM creature WHERE guid = {}", spawnId))
        {
            Field* f = r->Fetch();
            oldX = f[0].GetFloat(); oldY = f[1].GetFloat(); oldZ = f[2].GetFloat(); oldO = f[3].GetFloat();
        }

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET position_x = {}, position_y = {}, position_z = {}, orientation = {} WHERE guid = {};",
            x, y, z, o, spawnId);
        return ApplyFix(h, sql, "gpos",
            Trinity::StringFormat("position: ({:.2f},{:.2f},{:.2f},{:.2f}) -> ({:.2f},{:.2f},{:.2f},{:.2f}) (spawn guid {})",
                oldX, oldY, oldZ, oldO, x, y, z, o, spawnId).c_str());
    }

    // ----- .fix gmoveall [movementType] [wander_distance] -----
    // Updates MovementType AND wander_distance for ALL spawns of the selected NPC
    // (by entry, not by a specific guid).
    //
    // No arguments: MovementType = 1 (RANDOM), wander_distance = 8
    // With arguments: .fix gmoveall <movementType> <wander_distance>
    //
    // SQL: UPDATE creature SET MovementType = X, wander_distance = Y WHERE id = <entry>;
    static bool HandleFixGMoveAll(ChatHandler* h, Optional<uint32> moveTypeOpt, Optional<double> wanderDistOpt)
    {
        // Defaults: RANDOM movement, 8 yards wander
        uint32 moveType = 1;
        double wanderDist = 8.0;

        if (moveTypeOpt)
        {
            if (*moveTypeOpt > 2)
            {
                h->SendSysMessage("[gm_fixer] MovementType must be 0 (IDLE), 1 (RANDOM) or 2 (WAYPOINT).");
                return true;
            }
            moveType = *moveTypeOpt;
        }

        if (wanderDistOpt)
        {
            if (*wanderDistOpt < 0.0)
            {
                h->SendSysMessage("[gm_fixer] wander_distance must be >= 0.");
                return true;
            }
            wanderDist = *wanderDistOpt;
        }

        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read old values
        uint32 oldMt = 0; float oldWd = 0.0f;
        if (QueryResult r = WorldDatabase.PQuery("SELECT MovementType, wander_distance FROM creature WHERE id = {} LIMIT 1", entry))
        {
            oldMt = r->Fetch()[0].GetUInt32();
            oldWd = r->Fetch()[1].GetFloat();
        }

        std::string sql = Trinity::StringFormat(
            "UPDATE creature SET MovementType = {}, wander_distance = {} WHERE id = {};",
            moveType, wanderDist, entry);
        return ApplyFix(h, sql, "gmoveall",
            Trinity::StringFormat("MovementType: {} -> {}, wander_distance: {} -> {} (ALL spawns entry {})",
                oldMt, moveType, oldWd, wanderDist, entry).c_str());
    }

    // ----- .fix scalesize <scale> -----
    // Changes the creature's scale (size) in creature_template.
    // Value can be fractional: 0.85, 1.0, 1.5, 2.0
    //
    // SQL: UPDATE creature_template SET scale = X WHERE entry = <entry>;
    //
    // Saved to a separate file creature_sizes.sql next to the worldserver.
    static bool HandleFixScaleSize(ChatHandler* h, double scale)
    {
        if (scale <= 0.0 || scale > 100.0)
        {
            h->SendSysMessage("[gm_fixer] scale must be between 0.01 and 100.0");
            return true;
        }
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // Read old value
        float oldVal = 0.0f;
        if (QueryResult r = WorldDatabase.PQuery("SELECT scale FROM creature_template WHERE entry = {}", entry))
            oldVal = r->Fetch()[0].GetFloat();

        std::string sql = Trinity::StringFormat(
            "UPDATE creature_template SET scale = {} WHERE entry = {};",
            scale, entry);

        // Execute SQL and write to a separate file (not the daily file).
        WorldDatabase.DirectExecute(sql.c_str());
        AppendToScaleSizeFile(sql, "scalesize",
            Trinity::StringFormat("scale: {} -> {} (entry {})", oldVal, scale, entry));

        std::string what = Trinity::StringFormat(
            "scale: {} -> {} (entry {})", oldVal, scale, entry);
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL: {}", sql));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sql);
        return true;
    }

    // ----- .fix addnpc -----
    // Reads the selected NPC's spawn data from the creature table (by SpawnID/guid)
    // and generates a full INSERT with a new guid = MAX(guid)+1 (to avoid
    // PK conflicts if the table doesn't use AUTO_INCREMENT).
    //
    // SQL is saved to the daily file, NOT executed.
    // The file can be run later to recreate the spawn on this or another server.
    //
    // Example output in the file:
    //   INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, ...) VALUES (12346, 1976, 0, 12, ...);
    static bool HandleFixAddNpc(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        uint64 spawnId = c->GetSpawnId();
        if (spawnId == 0)
        {
            h->SendSysMessage("[gm_fixer] Selected creature has no SpawnId (probably a temporary summon).");
            return true;
        }

        // Read all spawn columns from creature.
        // guid will be replaced with MAX(guid)+1 when generating SQL.
        QueryResult result = WorldDatabase.PQuery(
            "SELECT `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, "
            "`phaseUseFlags`, `phaseId`, `phaseGroup`, `equipment_id`, "
            "`position_x`, `position_y`, `position_z`, `orientation`, "
            "`spawntimesecs`, `wander_distance`, `MovementType`, `ScriptName`, `StringId` "
            "FROM `creature` WHERE `guid` = {}",
            spawnId);

        if (!result)
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] addnpc: no creature row found for guid {}", spawnId));
            return true;
        }

        Field* fields = result->Fetch();

        // Column names in the same order as in the SELECT above.
        static constexpr char const* colNames[] = {
            "id", "map", "zoneId", "areaId", "spawnDifficulties",
            "phaseUseFlags", "phaseId", "phaseGroup", "equipment_id",
            "position_x", "position_y", "position_z", "orientation",
            "spawntimesecs", "wander_distance", "MovementType", "ScriptName", "StringId"
        };
        static constexpr uint32 numCols = 18;

        // Which columns are strings (need quotes in SQL).
        static constexpr bool colIsString[] = {
            false, false, false, false, true,   // id, map, zoneId, areaId, spawnDifficulties
            false, false, false, false,          // phaseUseFlags, phaseId, phaseGroup, equipment_id
            false, false, false, false,          // position_x, y, z, orientation
            false, false, false, true,  false    // spawntimesecs, wander_distance, MovementType, ScriptName, StringId
        };

        // Build columns and VALUES.
        // guid is calculated dynamically at SQL execution time via a subquery,
        // so the file works on any server with its own guids.
        //
        // MySQL Error 1093 (can't specify target table 'creature' for update
        // in FROM clause) is worked around via a derived table:
        //   FROM (SELECT `guid` FROM `creature`) AS tmp
        // MySQL materializes the subquery before INSERT and doesn't count it
        // as a reference to the target table.
        std::string colList = "(`guid`";
        std::string valList = "((SELECT IFNULL(MAX(`guid`), 0) + 1 FROM (SELECT `guid` FROM `creature`) AS tmp)";
        for (uint32 i = 0; i < numCols; ++i)
        {
            colList += ", `";
            colList += colNames[i];
            colList += "`";

            std::string val = fields[i].GetString();
            if (colIsString[i])
            {
                // Escape single quotes (SQL escaping).
                for (size_t pos = 0; (pos = val.find('\'', pos)) != std::string::npos; pos += 2)
                    val.insert(pos, 1, '\'');
                valList += ", '";
                valList += val;
                valList += "'";
            }
            else
            {
                // Numeric fields — as-is. If NULL/empty, use 0.
                if (val.empty())
                    val = "0";
                valList += ", ";
                valList += val;
            }
        }
        colList += ")";
        valList += ")";

        std::string sql = "INSERT INTO `creature` " + colList + " VALUES " + valList + ";";

        // Save to the daily file. NOT executed — the user will run the file themselves.
        AppendToDailySql(sql, "addnpc",
            Trinity::StringFormat("entry {} (source guid {})", entry, spawnId));

        h->SendSysMessage(Trinity::StringFormat(
            "[gm_fixer] addnpc: saved INSERT for entry {} (source guid {}) to daily SQL file",
            entry, spawnId));
        h->SendSysMessage(Trinity::StringFormat("  SQL: {}", sql));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] addnpc: entry {} spawn {} | SQL: {}", entry, spawnId, sql);
        return true;
    }

    // ----- .fix npcinfo -----
    // Shows information about the selected NPC:
    //   entry, name, faction (from creature_template)
    //   whether a row exists in creature_template_difficulty
    //   current ContentTuningID, StaticFlags1, HealthModifier
    // Does not write anything to the DB or daily file — read and display only.
    static bool HandleFixNpcInfo(ChatHandler* h)
    {
        Creature* c = nullptr; uint32 entry = 0;
        if (!GetSelectedCreature(h, c, entry)) return true;

        // 1) creature_template — faction, npcflag, name
        QueryResult tplRes = WorldDatabase.PQuery(
            "SELECT name, faction, npcflag, unit_flags FROM creature_template WHERE entry = {}",
            entry);
        if (!tplRes)
        {
            h->SendSysMessage(Trinity::StringFormat(
            "[gm_fixer] creature_template entry {} not found.", entry));
            return true;
        }
        Field* tf = tplRes->Fetch();
        std::string name    = tf[0].GetString();
        uint32     faction  = tf[1].GetUInt32();
        uint32     npcflag  = tf[2].GetUInt32();
        uint32     uflags   = tf[3].GetUInt32();

        h->SendSysMessage(Trinity::StringFormat(
            "[gm_fixer] NPC entry={} name='{}'", entry, name));
        h->SendSysMessage(Trinity::StringFormat(
            "  creature_template: faction={} npcflag={} unit_flags={}",
            faction, npcflag, uflags));

        // 2) creature_template_difficulty — all rows (normal/heroic/mythic).
        QueryResult diffRes = WorldDatabase.PQuery(
            "SELECT DifficultyID, ContentTuningID, StaticFlags1, HealthModifier, "
            "       HealthScalingExpansion "
            "FROM creature_template_difficulty WHERE Entry = {} ORDER BY DifficultyID",
            entry);
        if (!diffRes)
        {
            h->SendSysMessage("  creature_template_difficulty: NO ROW (use .fix ct to create)");
        }
        else
        {
            h->SendSysMessage(Trinity::StringFormat(
                "  creature_template_difficulty ({} rows):",
                uint32(diffRes->GetRowCount())));
            do
            {
                Field* df = diffRes->Fetch();
                uint32 diffId    = df[0].GetUInt32();
                uint32 ctId      = df[1].GetUInt32();
                uint32 staticF1  = df[2].GetUInt32();
                float  hpMod     = df[3].GetFloat();
                uint32 hpScale   = df[4].GetUInt32();
                h->SendSysMessage(Trinity::StringFormat(
                    "    diff={}: ContentTuningID={} StaticFlags1={} HPx={} HpScalingExp={}",
                    diffId, ctId, staticF1, hpMod, hpScale));
            } while (diffRes->NextRow());
        }
        return true;
    }

    // ----- .fix questinfo <questId> -----
    // Shows PrevQuestID from quest_template_addon — this is the quest that
    // must be completed before this quest becomes available.
    // Does not write to the DB — read only.
    static bool HandleFixQuestInfo(ChatHandler* h, uint32 questId)
    {

        // First check that the quest exists at all.
        Quest const* q = sObjectMgr->GetQuestTemplate(questId);
        if (!q)
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] Quest {} not found in quest_template.", questId));
            return true;
        }
        h->SendSysMessage(Trinity::StringFormat(
            "[gm_fixer] Quest {}: '{}'", questId, q->GetLogTitle()));

        // Read quest_template_addon — PrevQuestID (and also NextQuestID,
        // BreadcrumbForQuestId, AllowableClasses — for context).
        QueryResult res = WorldDatabase.PQuery(
            "SELECT PrevQuestID, NextQuestID, ExclusiveGroup, BreadcrumbForQuestId, "
            "       AllowableClasses, RequiredSkillID, RequiredSkillPoints "
            "FROM quest_template_addon WHERE ID = {}",
            questId);
        if (!res)
        {
            h->SendSysMessage("  quest_template_addon: NO ROW (no prerequisite chain)");
            return true;
        }

        Field* f = res->Fetch();
        int32  prevQ     = f[0].GetInt32();
        uint32 nextQ     = f[1].GetUInt32();
        int32  exclGroup = f[2].GetInt32();
        uint32 bcFor     = f[3].GetUInt32();
        uint32 allowCls  = f[4].GetUInt32();
        uint32 reqSkill  = f[5].GetUInt32();
        uint32 reqSkillP = f[6].GetUInt32();

        if (prevQ == 0)
        {
            h->SendSysMessage("  PrevQuestID: 0 (no prerequisite)");
        }
        else
        {
            // If prevQ > 0 — this quest must be completed.
            // If prevQ < 0 — this quest must NOT be completed (exclusive).
            if (prevQ > 0)
            {
                Quest const* prev = sObjectMgr->GetQuestTemplate(uint32(prevQ));
                h->SendSysMessage(Trinity::StringFormat(
                    "  PrevQuestID: {} (must be completed) - '{}'",
                    prevQ, prev ? prev->GetLogTitle() : "<unknown>"));
            }
            else
            {
                Quest const* prev = sObjectMgr->GetQuestTemplate(uint32(-prevQ));
                h->SendSysMessage(Trinity::StringFormat(
                    "  PrevQuestID: {} (must NOT be completed) - '{}'",
                    prevQ, prev ? prev->GetLogTitle() : "<unknown>"));
            }
        }

        if (nextQ)     h->SendSysMessage(Trinity::StringFormat("  NextQuestID: {}", nextQ));
        if (exclGroup) h->SendSysMessage(Trinity::StringFormat("  ExclusiveGroup: {}", exclGroup));
        if (bcFor)     h->SendSysMessage(Trinity::StringFormat("  BreadcrumbForQuestId: {}", bcFor));
        if (allowCls)  h->SendSysMessage(Trinity::StringFormat("  AllowableClasses: {}", allowCls));
        if (reqSkill)  h->SendSysMessage(Trinity::StringFormat("  RequiredSkill: {} ({} points)", reqSkill, reqSkillP));

        return true;
    }

    // ----- .fix spellgcd <SpellID> [seconds] -----
    // Sets StartRecoveryTime (GCD) for a spell in hotfixes.spell_cooldowns.
    // Seconds are specified as a fraction: "1.5" or "1,5" = 1500 ms.
    // If seconds are not specified — default 1500 ms (1.5s, standard GCD) is used.
    //
    // SQL: INSERT INTO hotfixes.spell_cooldowns
    //        (StartRecoveryTime, SpellID, VerifiedBuild)
    //      VALUES (<ms>, <spellId>, 67186);
    static bool HandleFixSpellGCD(ChatHandler* h, uint32 spellId, Optional<std::string_view> secondsOpt)
    {
        std::string secondsStr = secondsOpt ? std::string(*secondsOpt) : "";

        uint32 ms = 0;
        // Default GCD = 1500 ms (1.5 seconds).
        if (!ParseSecondsToMs(secondsStr.c_str(), 1500, ms))
        {
            h->SendSysMessage("Usage: .fix spellgcd <SpellID> [seconds]");
            h->SendSysMessage("  seconds can be '1.5', '1,5', '0.5', etc.");
            return true;
        }

        // Check that the spell exists.
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo)
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] Spell {} not found in SpellMgr.", spellId));
            return true;
        }

        // INSERT with ON DUPLICATE KEY UPDATE — atomic, without deleting the row.
        // IMPORTANT: PK of the spell_cooldowns table = (ID, VerifiedBuild), not SpellID!
        // ID is calculated as MAX(ID)+1 to avoid conflicts with other hotfix entries.
        // To prevent repeated runs of the same file from creating new rows,
        // wrap the entire INSERT in a condition: execute only if no record exists
        // for this SpellID with this VerifiedBuild yet.
        //
        // But MySQL can't do IF NOT EXISTS in a single atomic statement,
        // so we use INSERT ... SELECT with WHERE NOT EXISTS — this is
        // atomic and won't fail on a duplicate (SELECT simply returns 0 rows).
        std::string sql = Trinity::StringFormat(
            "INSERT INTO `spell_cooldowns` "
            "(`ID`, `DifficultyID`, `CategoryRecoveryTime`, `RecoveryTime`, "
            " `StartRecoveryTime`, `AuraSpellID`, `SpellID`, `VerifiedBuild`) "
            "SELECT (SELECT IFNULL(MAX(`ID`), 0) + 1 FROM `spell_cooldowns`), "
            "       0, 0, 0, {}, 0, {}, {} "
            "FROM DUAL "
            "WHERE NOT EXISTS ("
            "  SELECT 1 FROM `spell_cooldowns` "
            "  WHERE `SpellID` = {} AND `VerifiedBuild` = {}"
            ");",
            ms, spellId, HOTFIX_VERIFIED_BUILD,
            spellId, HOTFIX_VERIFIED_BUILD);

        // If the record already exists — UPDATE it via a separate query.
        // (INSERT ... ON DUPLICATE KEY UPDATE doesn't work since ID isn't known yet.)
        std::string sqlUpd = Trinity::StringFormat(
            "UPDATE `spell_cooldowns` SET `StartRecoveryTime` = {} "
            "WHERE `SpellID` = {} AND `VerifiedBuild` = {};",
            ms, spellId, HOTFIX_VERIFIED_BUILD);

        // Execute both queries sequentially.
        HotfixDatabase.DirectExecute(sql.c_str());
        HotfixDatabase.DirectExecute(sqlUpd.c_str());

        // Write both statements to the log file (for audit).
        std::string sqlLog = sql + "\n" + sqlUpd;

        // Write to file and log (SQL already executed above).
        AppendToSpellCdFile(sqlLog, "spellgcd");
        std::string what = Trinity::StringFormat(
            "SpellGCD spell={} -> {} ms ({} sec)",
            spellId, ms, (ms / 1000.0));
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }

    // ----- .fix spellcd <SpellID> <seconds> -----
    // Sets RecoveryTime (cooldown) for a spell in hotfixes.spell_cooldowns.
    // Seconds are specified as a fraction: "1.5" or "1,5" = 1500 ms.
    // Unlike spellgcd — seconds are required (no default).
    //
    // SQL: INSERT INTO hotfixes.spell_cooldowns
    //        (RecoveryTime, SpellID, VerifiedBuild)
    //      VALUES (<ms>, <spellId>, 67186);
    static bool HandleFixSpellCD(ChatHandler* h, uint32 spellId, std::string_view secondsStr)
    {
        std::string seconds(secondsStr);
        uint32 ms = 0;
        // For spellcd there is no default — if not specified, error.
        if (!ParseSecondsToMs(seconds.c_str(), 0, ms) || ms == 0)
        {
            h->SendSysMessage("Usage: .fix spellcd <SpellID> <seconds>");
            h->SendSysMessage("  seconds can be '1.5', '1,5', '10', etc. (must be > 0)");
            return true;
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo)
        {
            h->SendSysMessage(Trinity::StringFormat(
                "[gm_fixer] Spell {} not found in SpellMgr.", spellId));
            return true;
        }

        // PK = (ID, VerifiedBuild), ID = MAX(ID)+1 via subquery.
        std::string sql = Trinity::StringFormat(
            "INSERT INTO `spell_cooldowns` "
            "(`ID`, `DifficultyID`, `CategoryRecoveryTime`, `RecoveryTime`, "
            " `StartRecoveryTime`, `AuraSpellID`, `SpellID`, `VerifiedBuild`) "
            "SELECT (SELECT IFNULL(MAX(`ID`), 0) + 1 FROM `spell_cooldowns`), "
            "       0, 0, {}, 0, 0, {}, {} "
            "FROM DUAL "
            "WHERE NOT EXISTS ("
            "  SELECT 1 FROM `spell_cooldowns` "
            "  WHERE `SpellID` = {} AND `VerifiedBuild` = {}"
            ");",
            ms, spellId, HOTFIX_VERIFIED_BUILD,
            spellId, HOTFIX_VERIFIED_BUILD);

        std::string sqlUpd = Trinity::StringFormat(
            "UPDATE `spell_cooldowns` SET `RecoveryTime` = {} "
            "WHERE `SpellID` = {} AND `VerifiedBuild` = {};",
            ms, spellId, HOTFIX_VERIFIED_BUILD);

        HotfixDatabase.DirectExecute(sql.c_str());
        HotfixDatabase.DirectExecute(sqlUpd.c_str());

        std::string sqlLog = sql + "\n" + sqlUpd;

        AppendToSpellCdFile(sqlLog, "spellcd");
        std::string what = Trinity::StringFormat(
            "SpellCD spell={} -> {} ms ({} sec)",
            spellId, ms, (ms / 1000.0));
        h->SendSysMessage(Trinity::StringFormat("[gm_fixer] {} -> OK", what));
        h->SendSysMessage(Trinity::StringFormat("  SQL:\n{}", sqlLog));
        TC_LOG_INFO(LOG_CHAN, "[gm_fixer] {} | SQL: {}", what, sqlLog);
        return true;
    }
};

void AddSC_gm_fixer()
{
    new gm_fixer_cmd();
}
