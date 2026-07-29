/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "FollowshipDatabase.h"
#include "DatabaseEnv.h"
#include "Log.h"

#include "Followship_bots_db.h"

namespace FSBUtilsDB
{
    bool LoadAllPersistentBotsFromDB(std::vector<PlayerBotData>& outBots)
    {
        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_OWNERS_ALL);
        PreparedQueryResult result = FollowshipDatabase.Query(stmt);

        if (!result)
            return false;

        do
        {
            Field* fields = result->Fetch();

            PlayerBotData data;
            data.botId = fields[0].GetUInt32();
            data.spawnId = fields[1].GetUInt64();
            data.entry = fields[2].GetUInt32();
            data.owner = fields[3].GetUInt32();
            data.hireExpiry = fields[4].GetUInt64();
            data.runtimeGuid = ObjectGuid::Empty;

            outBots.push_back(data);
        } while (result->NextRow());

        return true;
    }

    bool LoadBotsForPlayer(uint64 playerGuidLow, std::vector<PlayerBotData>& outBots)
    {
        outBots.clear();

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_OWNERS_BY_PLAYER);
        stmt->setUInt64(0, playerGuidLow);
        PreparedQueryResult result = FollowshipDatabase.Query(stmt);

        if (!result)
            return true; // no bots is valid

        do
        {
            Field* fields = result->Fetch();

            PlayerBotData data;
            data.botId = fields[0].GetUInt32();
            data.spawnId = fields[1].GetUInt64();
            data.entry = fields[2].GetUInt32();
            data.hireExpiry = fields[3].GetUInt64();
            data.runtimeGuid = ObjectGuid::Empty;

            outBots.push_back(data);
        } while (result->NextRow());

        return true;
    }

    bool LoadBotOwners(std::unordered_map<ObjectGuid::LowType, ObjectGuid::LowType>& botOwners)
    {
        botOwners.clear();

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_OWNERS_ALL);
        PreparedQueryResult result = FollowshipDatabase.Query(stmt);

        if (!result)
            return true; // no bots is valid

        do
        {
            Field* fields = result->Fetch();

            ObjectGuid::LowType spawnId = fields[1].GetUInt64(); // bot_guid
            ObjectGuid::LowType ownerGuid = fields[3].GetUInt32(); // player_guid
            uint64 hireExpiry = fields[4].GetUInt64();

            // Skip expired bots
            if (hireExpiry > 0 && hireExpiry <= static_cast<uint64>(time(nullptr)))
            {
                // Clean up DB entry
                FollowshipDatabasePreparedStatement* delStmt = FollowshipDatabase.GetPreparedStatement(FSB_DEL_BOT_OWNER_BY_GUID);
                delStmt->setUInt64(0, spawnId);
                FollowshipDatabase.Execute(delStmt);

                TC_LOG_DEBUG("scripts.fsb.manager",
                    "FSB: LoadBotOwners from DB Removing expired bot {} (owner {})", spawnId, ownerGuid);

                continue;
            }

            botOwners[spawnId] = ownerGuid;

        } while (result->NextRow());

        return true;
    }

    bool SaveBotToDB(Creature* bot, Player* player, uint64 hireExpiry)
    {
        ASSERT(bot && player);

        ObjectGuid::LowType spawnId = bot->GetSpawnId();
        uint32 playerGuidLow = player->GetGUID().GetCounter();

        if (!spawnId)
        {
            TC_LOG_ERROR("scripts.fsb.manager",
                "FSB: SaveBotToDB Attempted to save non-DB bot (entry {})", bot->GetEntry());
            return false;
        }

        uint32 entry = bot->GetEntry();

        FollowshipDatabasePreparedStatement* insStmt = FollowshipDatabase.GetPreparedStatement(FSB_INS_BOT_OWNER);
        insStmt->setUInt64(0, spawnId);
        insStmt->setUInt32(1, entry);
        insStmt->setUInt32(2, playerGuidLow);
        insStmt->setUInt64(3, hireExpiry);
        FollowshipDatabase.Execute(insStmt);

        TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SaveBotToDB Bot: {} was saved to DB for player: {} with expiry time: {}", bot->GetName(), player->GetName(), hireExpiry);

        // Retry select until we get the bot_id
        uint32 botId = 0;
        for (int attempts = 0; attempts < 5; ++attempts)
        {
            FollowshipDatabasePreparedStatement* selStmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_OWNER_ID);
            selStmt->setUInt64(0, spawnId);
            selStmt->setUInt32(1, playerGuidLow);
            PreparedQueryResult result = FollowshipDatabase.Query(selStmt);

            if (result)
            {
                botId = result->Fetch()[0].GetUInt32();
                if (botId != 0)
                    break;
            }

            TC_LOG_WARN("scripts.fsb.manager",
                "FSB: SaveBotToDB bot_id not yet available for bot spawn {} player {}, retrying...",
                spawnId, player->GetName());

            std::this_thread::sleep_for(std::chrono::milliseconds(50)); // small delay
        }

        if (!botId)
        {
            TC_LOG_ERROR("scripts.fsb.manager",
                "FSB: SaveBotToDB Failed to retrieve bot_id for bot_guid {} player {}", spawnId, player->GetName());
        }
        else
        {
            TC_LOG_DEBUG("scripts.fsb.manager",
                "FSB: SaveBotToDB Saved bot {} for player {} with bot_id {}", bot->GetName(), player->GetName(), botId);
        }

        return botId;
    }

    bool DeleteBotByEntry(uint32 bot_entry, uint32 player_guid)
    {
        if (!bot_entry || !player_guid)
            return false;

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_DEL_BOT_OWNER_BY_ENTRY_PLAYER);
        stmt->setUInt32(0, bot_entry);
        stmt->setUInt32(1, player_guid);
        FollowshipDatabase.Execute(stmt);

        TC_LOG_DEBUG("scripts.fsb.manager", "FSB: DeleteBotByEntry Deleted Bot with bot_entry: {}", bot_entry);

        return true;
    }

    bool LoadBotChatterLines(std::unordered_map<uint32, std::vector<FSBChatterDBLine>>& outMap)
    {
        outMap.clear();

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_CHATTER_ALL);
        PreparedQueryResult result = FollowshipDatabase.Query(stmt);

        if (!result)
            return true; // no lines is valid (will fall back to static table later)

        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();
            FSBChatterDBLine line;
            line.id          = fields[0].GetUInt32();
            line.zoneId      = fields[1].GetInt32();
            line.fsbRaceId   = fields[2].GetUInt8();
            line.fsbClassId  = fields[3].GetUInt8();
            uint16 category  = fields[4].GetUInt16();
            uint8 chatterType = fields[5].GetUInt8();
            line.lineText    = fields[6].GetString();

            uint32 key = (static_cast<uint32>(category) << 8) | static_cast<uint32>(chatterType);

            // targetKilled (category 1): populate targetKilledHired (category 2) with all lines,
            // and targetKilled with only lines that do not reference {player}
            if (category == 1)
            {
                uint32 hiredKey = (static_cast<uint32>(2) << 8) | static_cast<uint32>(chatterType);
                outMap[hiredKey].push_back(line); // copy: hired bots get every line
                if (line.lineText.find("{player}") == std::string::npos)
                    outMap[key].push_back(std::move(line)); // unhired bots skip player-tagged lines
            }
            else
            {
                outMap[key].push_back(std::move(line));
            }
            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("scripts.fsb.chatter", "FSB: Loaded {} bot chatter lines into {} category/type entries", count, outMap.size());
        return true;
    }

    bool LoadBotSpellsFromDB(std::vector<FSBSpellDefinition>& outSpells)
    {
        outSpells.clear();

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_SPELLS_ALL);
        PreparedQueryResult result = FollowshipDatabase.Query(stmt);

        if (!result)
            return true; // empty table is valid

        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();

            FSBSpellDefinition def;
            def.dbId            = fields[0].GetUInt32();
            def.spellId         = fields[1].GetUInt32();
            def.allowedRace     = static_cast<FSB_Race>(fields[2].GetUInt8());
            def.allowedClass    = static_cast<FSB_Class>(fields[3].GetUInt8());
            def.type            = static_cast<FSBSpellType>(fields[4].GetUInt8());
            def.manaCostOverride= fields[5].GetFloat();
            def.hpThreshold     = fields[6].GetFloat();
            def.dist            = fields[7].GetFloat();
            def.isSelfCast      = fields[8].GetBool();
            def.isLocationSpell = fields[9].GetBool();
            def.cooldownMs      = fields[10].GetUInt32();
            def.allowedRoles    = fields[11].GetUInt32();
            // comment is informational only; ignore in runtime

            outSpells.push_back(def);
            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("scripts.fsb.spells", "FSB: Loaded {} bot spells from DB", count);
        return true;
    }
}
