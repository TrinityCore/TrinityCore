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

#include "CharmInfo.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "PhasingHandler.h"
#include "ScriptHelpers.h"
#include "TemporarySummon.h"
#include "DB2Stores.h"
#include <random>

#include "GenAI_chatter_prompts.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_db.h"
#include "Followship_bots.h"
#include "FollowshipDatabase.h"
#include "Followship_bots_config.h"

#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_gossip_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_powers_handler.h"
#include "Followship_bots_stats_handler.h"
#include "Followship_bots_utils.h"

FSBMgr* FSBMgr::Get()
{
    static FSBMgr instance;
    return &instance;
}

// ==================== PERSISTENT LAYER ================================================= //
void FSBMgr::LoadAllPersistentBots()
{
    std::vector<PlayerBotData> allBots;
    if (!FSBUtilsDB::LoadAllPersistentBotsFromDB(allBots))
        return;

    _playerBotsPersistent.clear();

    for (auto const& bot : allBots)
    {
        _playerBotsPersistent[bot.owner].push_back(bot);
    }

    TC_LOG_INFO("scripts.fsb.manager", "FSB: LoadAllPersistentBots {} persistent bots loaded for {} players", allBots.size(), _playerBotsPersistent.size());
}

void FSBMgr::LoadBotTemplates()
{
    _botTemplates.clear();

    FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_SEL_BOT_TEMPLATES_ALL);
    PreparedQueryResult result = FollowshipDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_ERROR("scripts.fsb.manager", "FSB: LoadBotTemplates failed - no data found in bot_templates table");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        FSBEntryRaceClassMap data;
        data.entry = fields[0].GetUInt32();
        data.botClass = static_cast<FSB_Class>(fields[1].GetUInt8());
        data.botRace = static_cast<FSB_Race>(fields[2].GetUInt8());
        data.companionSpell = fields[3].GetUInt32();
        data.chatterType = static_cast<FSB_ChatterType>(fields[4].GetUInt8());
        data.gender = static_cast<Gender>(fields[5].GetUInt8());
        data.petSource = fields[6].GetUInt32();

        _botTemplates[data.entry] = data;
    } while (result->NextRow());

    TC_LOG_INFO("scripts.fsb.manager", "FSB: LoadBotTemplates {} bot templates loaded from database", _botTemplates.size());
}

bool FSBMgr::StorePersistentBot(Creature* bot, Player* player, uint64 hireExpiry)
{
    if (!bot || !player)
        return false;

    uint64 ownerGuid = player->GetGUID().GetCounter();
    uint64 spawnId = bot->GetSpawnId();
    uint32 entry = bot->GetEntry();

    // Build persistent record
    PlayerBotData data;
    data.botId = 0; // if you auto-increment in DB, this will be filled on reload
    data.spawnId = spawnId;
    data.entry = entry;
    data.owner = ownerGuid;
    data.hireExpiry = hireExpiry;
    data.runtimeGuid = bot->GetGUID();

    // Save to DB first
    if (!FSBUtilsDB::SaveBotToDB(bot, player, hireExpiry))
    {
        TC_LOG_ERROR("scripts.fsb.manager",
            "FSB: StorePersistentBot Failed to save bot {} for player {} to DB",
            entry, player->GetName());
        return false;
    }

    // Insert into persistent container
    _playerBotsPersistent[ownerGuid].push_back(data);

    TC_LOG_DEBUG("scripts.fsb.manager",
        "FSB: StorePersistentBot Stored persistent bot {} for player {} (spawnId {}). Player has now {} bots.",
        entry, player->GetName(), spawnId, _playerBotsPersistent[ownerGuid].size());

    return true;
}

void FSBMgr::RemovePersistentExpiredPlayerBots(Player* player)
{
    if (!player)
        return;

    uint64 guid = player->GetGUID().GetCounter();

    // Look up persistent bots for this player
    auto it = _playerBotsPersistent.find(guid);
    if (it == _playerBotsPersistent.end())
        return;

    auto& bots = it->second;

    for (auto botIt = bots.begin(); botIt != bots.end(); )
    {
        if (IsBotExpired(*botIt))
        {
            uint32 botEntry = botIt->entry;

            // Remove from DB
            FSBUtilsDB::DeleteBotByEntry(botEntry, guid);

            // Remove from persistent container
            botIt = bots.erase(botIt);

            TC_LOG_DEBUG("scripts.fsb.manager",
                "FSB: RemovePersistentExpiredPlayerBots Removed expired bot entry {} for player {}", botEntry, player->GetName());
        }
        else
        {
            ++botIt;
        }
    }

    // If the player now has zero bots, you may optionally erase the key entirely:
    if (bots.empty())
        _playerBotsPersistent.erase(guid);

    UpdateHiredBotCount(player);
}

void FSBMgr::UpdateHiredBotCount(Player* player)
{
    if (!player)
        return;

    auto* bots = GetPersistentBotsForPlayer(player);
    if (!bots || bots->empty())
    {
        ScriptHelpers::EraseHiredBotCount(player->GetGUID().GetCounter());
        return;
    }

    uint8 count = 0;
    for (auto const& botData : *bots)
        if (!IsBotExpired(botData))
            ++count;

    if (count > 0)
        ScriptHelpers::SetHiredBotCount(player->GetGUID().GetCounter(), count);
    else
        ScriptHelpers::EraseHiredBotCount(player->GetGUID().GetCounter());
}

bool FSBMgr::RemovePersistentBot(uint64 playerGuid, uint32 botEntry)
{
    auto it = _playerBotsPersistent.find(playerGuid);
    if (it == _playerBotsPersistent.end())
        return false;

    auto& bots = it->second;

    // Remove from persistent container
    std::erase_if(bots, [&](auto const& b) { return b.entry == botEntry; });

    // Remove from DB
    FSBUtilsDB::DeleteBotByEntry(botEntry, playerGuid);

    TC_LOG_INFO("scripts.fsb.manager",
        "FSB: RemovePersistentBot Removed 1 persistent bot with entry {} for player guid {}", botEntry, playerGuid);

    // Optional: remove empty entry
    if (bots.empty())
        _playerBotsPersistent.erase(playerGuid);

    return true;
}

void FSBMgr::SpawnPlayerBots(Player* player)
{
    if (!player)
        return;

    // Get persistent bots for this player
    auto* bots = FSBMgr::Get()->GetPersistentBotsForPlayer(player);
    if (!bots || bots->empty())
    {
        TC_LOG_INFO("scripts.fsb.manager",
            "FSB: SpawnPlayerBots Player {} has no persistent bots", player->GetName());
        return;
    }

    uint64 now = time(nullptr);

    for (auto& botData : *bots)
    {
        Creature* bot = nullptr;

        // 1. Try to find the bot by spawnId on this map
        if (botData.spawnId != 0)
            bot = player->GetMap()->GetCreatureBySpawnId(botData.spawnId);

        // 2. If in dungeon and not found, try nearest fallback
        if (!bot && player->GetMap()->IsDungeon())
        {
            bot = player->FindNearestCreature(botData.entry, 500.f, true);
            if (!bot)
                bot = player->FindNearestCreature(botData.entry, 500.f, false);
        }

        // 3. If still not found ? spawn a temporary runtime bot
        if (!bot)
        {
            Position pos = player->GetPosition();
            TempSummon* temp = player->SummonCreature(botData.entry, pos, TEMPSUMMON_MANUAL_DESPAWN, 0s);
            if (temp)
            {
                bot = static_cast<Creature*>(temp);
                PhasingHandler::InheritPhaseShift(bot, player);
            }

            if (!bot)
            {
                TC_LOG_ERROR("scripts.fsb.manager",
                    "FSB: SpawnPlayerBots Failed to summon bot entry {} for player {}",
                    botData.entry, player->GetName());
                continue;
            }

            botData.runtimeGuid = bot->GetGUID();

            TC_LOG_DEBUG("scripts.fsb.manager",
                "FSB: SpawnPlayerBots Spawned TEMP bot {} for player {} on new map",
                bot->GetName(), player->GetName());
        }
        else
        {
            TC_LOG_DEBUG("scripts.fsb.manager",
                "FSB: SpawnPlayerBots Found existing DB bot {} on new map for player {}",
                bot->GetName(), player->GetName());
        }

        // 4. Restore ownership (AI, follow, hire time left)
        uint32 hireTimeLeft = botData.hireExpiry > 0
            ? uint32(botData.hireExpiry - now)
            : 0;

        FSBMgr::Get()->RestoreBotOwnership(player, bot, hireTimeLeft);

        // 5. Update dungeon ID
        FSBDungeon::UpdateBotDungeonId(bot);

        // 6. Schedule stats recalculation if in dungeon (to override difficulty-based stats)
        if (bot->GetMap()->IsDungeon())
        {
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_DUNGEON_STATS_RECALCULATE, 500ms);
            TC_LOG_DEBUG("scripts.fsb.manager", "FSB: Scheduled stats recalculation for bot {} in dungeon", bot->GetName());
        }
    }
}

// -------------------- Bot Ownership --------------------
void FSBMgr::RegisterBotSpawn(Creature* bot, Player* owner)
{
    if (!bot || !owner)
        return;

    auto botsPtr = GetPersistentBotsForPlayer(owner);
    if (!botsPtr)
        return;

    for (auto& botData : *botsPtr)
        if (botData.entry == bot->GetEntry())
            botData.runtimeGuid = bot->GetGUID();
}

void FSBMgr::RestoreBotOwnership(Player* player, Creature* bot, uint32 hireTimeLeft)
{
    if (!player || !bot)
        return;

    auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
    if (!baseAI)
        return;

    // Set owner
    bot->SetOwnerGUID(player->GetGUID());

    bot->AI()->SetData(FSB_DATA_HIRED, 1);
    bot->AI()->SetData(FSB_DATA_HIRE_TIME_LEFT, hireTimeLeft);

    FSBMgr::Get()->RegisterBotSpawn(bot, player);
    PhasingHandler::InheritPhaseShift(bot, player);

    bot->SetFaction(player->GetFaction());

    // Do not remove the below since they are needed for the Hire flow
    bot->SetStandState(UNIT_STAND_STATE_STAND);
    FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_HIRED_RESUME_FOLLOW, 1s, 3s);

    // Hired bots keep their gossip flag in battlegrounds.
    if (FSBBattleground::IsInBG(bot))
        bot->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
}

// ==================== GETTER METHODS ==================================================== //
std::vector<PlayerBotData>* FSBMgr::GetPersistentBotsForPlayer(Player* player)
{
    if (!player)
        return nullptr;

    uint64 guid = player->GetGUID().GetCounter();
    auto it = _playerBotsPersistent.find(guid);

    if (it == _playerBotsPersistent.end())
        return nullptr;

    return &it->second;
}

PlayerBotData* FSBMgr::GetPersistentBotBySpawnId(uint64 spawnId)
{
    for (auto& [playerGuid, bots] : _playerBotsPersistent)
    {
        for (auto& bot : bots)
        {
            if (bot.spawnId == spawnId)
                return &bot;
        }
    }
    return nullptr;
}

Player* FSBMgr::GetBotOwner(Unit* unit)
{
    if (!unit)
        return nullptr;

    if (Unit* owner = unit->GetOwner())
        return owner->ToPlayer();

    return nullptr;
}

// ==================== CHECK METHODS ==================================================== //
bool FSBMgr::IsBotExpired(PlayerBotData const& bot)
{
    return bot.hireExpiry > 0 && bot.hireExpiry < static_cast<uint64>(time(nullptr));
}

bool FSBMgr::IsPersistentBotExpired(uint64 ownerGuid, uint64 botEntry)
{
    auto it = _playerBotsPersistent.find(ownerGuid);
    if (it == _playerBotsPersistent.end())
        return false;

    for (auto const& bot : it->second)
    {
        if (bot.entry == botEntry)
            return bot.hireExpiry > 0 && bot.hireExpiry < uint64(time(nullptr));
    }

    return false;
}

uint64 FSBMgr::GetBotExpireTime(uint32 durationHours)
{
    return uint64(time(nullptr)) + uint64(durationHours) * 60 * 60;
}

// -------------------- Player Queries --------------------
bool FSBMgr::CheckPlayerHasBotWithEntry(Player* player, uint32 entry)
{
    auto* bots = GetPersistentBotsForPlayer(player);
    if (!bots)
        return false;

    return std::any_of(bots->begin(), bots->end(), [entry](PlayerBotData const& b) { return b.entry == entry; });
}

bool FSBMgr::IsBotOwnedByPlayer(Player* player, Creature* bot)
{
    if (!player || !bot)
        return false;

    uint64 ownerGuid = player->GetGUID().GetCounter();
    uint64 spawnId = bot->GetSpawnId();

    auto it = _playerBotsPersistent.find(ownerGuid);
    if (it == _playerBotsPersistent.end())
        return false;

    for (auto const& data : it->second)
    {
        if (data.spawnId == spawnId)
            return true;
    }

    return false;
}

bool FSBMgr::IsBotOwned(Creature* bot)
{
    if (!bot)
        return false;

    uint64 spawnId = bot->GetSpawnId();

    for (auto const& [ownerGuid, bots] : _playerBotsPersistent)
    {
        for (auto const& data : bots)
        {
            if (data.spawnId == spawnId)
                return true;
        }
    }

    return false;
}

bool FSBMgr::IsBotTemplateHired(uint32 entry) const
{
    for (auto const& [ownerGuid, bots] : _playerBotsPersistent)
    {
        for (auto const& data : bots)
        {
            if (data.entry == entry)
                return true;
        }
    }

    return false;
}


// ==================== MANAGEMENT METHODS ==================================================== //
void FSBMgr::HirePersistentBot(Player* player, Creature* bot, uint32 hireDurationHours)
{
    if (!bot || !player)
        return;

    // Calculate expiry
    // Permanent hire comes with duration 0
    uint64 hireExpiry = 0;
    if (hireDurationHours != 0)
        hireExpiry = GetBotExpireTime(hireDurationHours);

    StorePersistentBot(bot, player, hireExpiry);

    // 3?? Restore ownership + AI state
    uint32 hireTimeLeft = hireDurationHours * 3600;
    RestoreBotOwnership(player, bot, hireTimeLeft);

    // Update dungeon ID
    FSBDungeon::UpdateBotDungeonId(bot);

    // Schedule stats recalculation if in dungeon (to override difficulty-based stats)
    if (bot->GetMap()->IsDungeon())
    {
        FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_DUNGEON_STATS_RECALCULATE, 500ms);
        TC_LOG_DEBUG("scripts.fsb.manager", "FSB: Scheduled stats recalculation for hired bot {} in dungeon", bot->GetName());
    }

    TC_LOG_DEBUG("scripts.fsb.manager", "FSB: HirePersistentBot Player {} hired bot {} (entry {}) until {}",
        player->GetName(), bot->GetName(), bot->GetEntry(), hireExpiry);

    UpdateHiredBotCount(player);
}

void FSBMgr::DismissPersistentBot(Creature* bot)
{
    if (!bot)
        return;

    Player* player = GetBotOwner(bot);

    if (!player)
        return;

    uint32 playerGuidLow = player->GetGUID().GetCounter();
    uint32 botEntry = bot->GetEntry();

    bot->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
    bot->StopMoving();
    bot->GetMotionMaster()->Clear();
    if (player)
        FSBGenAIPrompts::DispatchBotDismissed(bot);

    RemovePersistentBot(playerGuidLow, botEntry);

    TC_LOG_DEBUG("scripts.fsb.manager", "FSB: DismissPersistentBot Dismissed bot {} for player {}", bot->GetName(), player->GetName());

    UpdateHiredBotCount(player);
}

void FSBMgr::SetInitialBotState(Creature* bot)
{
    if (!bot)
        return;

    bot->SetBot(true);
    bot->setActive(true);

    bot->SetStandState(UNIT_STAND_STATE_STAND);
    bot->SetEmoteState(EMOTE_STATE_NONE);
    bot->RemoveAllAuras();
    bot->SetDisableGravity(false);

    bot->SetLevel(90, true);

    auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
    if (!baseAI)
        return;

    if (FSBMgr::Get()->GetBotOwner(bot))
    {
        baseAI->botHired = true;
        FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
    }
    else
    {
        baseAI->botHired = false;
        baseAI->botMoveState = FSB_MOVE_STATE_IDLE;
        baseAI->botFollowDistance = frand(2.f, 8.f);
        baseAI->botFollowAngle = frand(0.0f, float(M_PI * 2.0f));
    }

    auto& botClass = baseAI->botClass;
    auto& botRace = baseAI->botRace;
    auto& botStats = baseAI->botStats;
    auto& botRole = baseAI->botRole;
    SetBotClassAndRace(bot, botClass, botRace);
    baseAI->botClassStats = FSBStats::GetBotClassStats(botClass);
    baseAI->botTCRace = FSBUtils::BotRaceToTC(botRace);
    ScriptHelpers::SetBotRace(bot->GetGUID(), uint8(baseAI->botTCRace));
    bot->SetClass(uint8(FSBUtils::FSBToTCClass(botClass)));
    baseAI->botHasDemon = false;

    // For shaman we set self resurrect flag for reincarnation
    if (botClass == FSB_Class::Shaman)
    {
        baseAI->botHasSoulstone = true;

        if (roll_chance(30))
            bot->CastSpell(bot, SPELL_SHAMAN_GHOST_WOLF, false);
    }

    // Initial Flags and States
    bot->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
    bot->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

    if (!bot->GetGossipMenuId())
        bot->SetGossipMenuId(FSB_GOSSIP_DEFAULT_MENU);

    if (FSBBattleground::IsInBG(bot) && !baseAI->botHired)
        bot->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
    else bot->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);

    if (FSBBattleground::IsInBG(bot) && !baseAI->botHired)
        FSBBattleground::InitializeBot(bot);
    else if (baseAI->botBattlegroundData)
    {
        baseAI->botBattlegroundData->Reset();
        delete baseAI->botBattlegroundData;
        baseAI->botBattlegroundData = nullptr;
    }

    bot->SetReactState(REACT_DEFENSIVE);
    
    bot->ApplyLevelScaling(3325, 0); // Sets Content Tuning override
    bot->RemoveCivilianFlag();
    bot->SetFaction(FSBUtils::GetFactionForFSBRace(botRace));
    baseAI->botLanguage = FSBUtils::GetLanguageForFSBRace(botRace);
    FSBStats::ApplyBotBaseClassStats(bot, botClass);
    botStats = FSBBotStats();
    botRole = GetRandomRoleForClass(botClass);
    TC_LOG_INFO("scripts.fsb.manager", "FSB: SetInitialBotState Assigned random role {} to bot {}", botRole, bot->GetName());

    ApplyRoleAuras(bot, botRole);

    if (botClass == FSB_Class::Monk)
    {
        if(botRole == FSB_Roles::FSB_ROLE_HEALER)
            FSBPowers::SetBotToMana(bot);

        if (botRole == FSB_Roles::FSB_ROLE_TANK)
            FSBPowers::SetBotToEnergy(bot);

        if (botRole == FSB_Roles::FSB_ROLE_MELEE_DAMAGE)
            FSBPowers::SetBotToChi(bot);
    }

    FSBStats::RecalculateStats(bot, true, true);
}

void FSBMgr::SetBotClassAndRace(Creature* creature, FSB_Class& outClass, FSB_Race& outRace)
{
    if (!creature)
        return;

    bool found = GetBotClassAndRaceForEntry(
        creature->GetEntry(),
        outClass,
        outRace
    );

    if (!found)
    {
        TC_LOG_WARN(
            "scripts.fsb.manager",
            "FSB: SetBotClassAndRace No class/race mapping found for creature entry {}",
            creature->GetEntry()
        );
        return;
    }

    TC_LOG_DEBUG(
        "scripts.fsb.manager",
        "FSB: SetBotClassAndRace Class set to {} and Race set to {} for bot with entry {}",
        outClass,
        outRace,
        creature->GetEntry()
    );
}

bool FSBMgr::GetBotClassAndRaceForEntry(uint32 entry, FSB_Class& outClass, FSB_Race& outRace)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
    {
        outClass = it->second.botClass;
        outRace = it->second.botRace;
        return true;
    }

    outClass = FSB_Class::None;
    outRace = FSB_Race::None;
    return false;
}

FSB_Class FSBMgr::GetBotClassForEntry(uint32 entry)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
        return it->second.botClass;

    return FSB_Class::None;
}

void FSBMgr::SetBotClass(Creature* creature, FSB_Class& outClass)
{
    if (!creature)
        return;

    FSB_Class cls = GetBotClassForEntry(creature->GetEntry());

    TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SetBotClass Class set: {} for bot with entry {}", cls, creature->GetEntry());

    if (cls == FSB_Class::None)
    {
        TC_LOG_WARN("scripts.fsb.manager", "FSB: SetBotClass No class mapping found for creature entry {}", creature->GetEntry());
    }

    outClass = cls;
}

FSB_Race FSBMgr::GetBotRaceForEntry(uint32 entry)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
        return it->second.botRace;

    return FSB_Race::None;
}

void FSBMgr::SetBotRace(Creature* creature, FSB_Race& outRace)
{
    if (!creature)
        return;

    FSB_Race race = GetBotRaceForEntry(creature->GetEntry());

    TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SetBotRace Race set: {} for bot with entry {}", race, creature->GetEntry());

    if (race == FSB_Race::None)
    {
        TC_LOG_WARN("scripts.fsb.manager", "FSB: SetBotRace No race mapping found for creature entry {}", creature->GetEntry());
    }

    outRace = race;
}

uint32 FSBMgr::GetAvailableRolesForClass(FSB_Class botClass)
{
    switch (botClass)
    {
    case FSB_Class::Warrior:
        return FSB_ROLEMASK_TANK | FSB_ROLEMASK_MELEE_DAMAGE;

    case FSB_Class::Paladin:
        return FSB_ROLEMASK_TANK | FSB_ROLEMASK_HEALER | FSB_ROLEMASK_MELEE_DAMAGE;

    case FSB_Class::Shaman:
        return FSB_ROLEMASK_RANGED_DAMAGE | FSB_ROLEMASK_HEALER | FSB_ROLEMASK_MELEE_DAMAGE;

    case FSB_Class::Hunter:
        return FSB_ROLEMASK_RANGED_DAMAGE | FSB_ROLEMASK_ASSIST;

    case FSB_Class::Rogue:
        return FSB_ROLEMASK_MELEE_DAMAGE | FSB_ROLEMASK_MELEE_DAMAGE_2 | FSB_ROLEMASK_MELEE_DAMAGE_3;

    case FSB_Class::Priest:
        return FSB_ROLEMASK_HEALER | FSB_ROLEMASK_RANGED_DAMAGE | FSB_ROLEMASK_ASSIST;

    case FSB_Class::Mage:
        return FSB_ROLEMASK_RANGED_ARCANE | FSB_ROLEMASK_RANGED_FIRE | FSB_ROLEMASK_RANGED_FROST;

    case FSB_Class::Warlock:
        return FSB_ROLEMASK_RANGED_DEMONOLOGY | FSB_ROLEMASK_RANGED_AFFLICTION | FSB_ROLEMASK_RANGED_DESTRUCTION;

    case FSB_Class::Druid:
        return FSB_ROLEMASK_TANK | FSB_ROLEMASK_HEALER | FSB_ROLEMASK_MELEE_DAMAGE | FSB_ROLEMASK_RANGED_DAMAGE;

    //case FSB_Class::DeathKnight:
    //    return FSB_ROLEMASK_TANK | FSB_ROLEMASK_MELEE_DAMAGE;

    case FSB_Class::Monk:
        return FSB_ROLEMASK_TANK | FSB_ROLEMASK_HEALER | FSB_ROLEMASK_MELEE_DAMAGE;

    default:
        return 0;
    }
}

FSB_Roles FSBMgr::GetRandomRoleForClass(FSB_Class botClass)
{
    uint32 mask = GetAvailableRolesForClass(botClass);
    if (mask == 0)
        return FSB_ROLE_NONE;

    std::vector<FSB_Roles> roles;

    // Loop through ALL roles and check if their mask is in the class mask
    for (int r = FSB_ROLE_NONE + 1; r <= FSB_ROLE_RANGED_DESTRUCTION; ++r)
    {
        FSB_Roles role = static_cast<FSB_Roles>(r);
        uint32 roleMask = RoleToMask(role);

        if (roleMask != 0 && (mask & roleMask))
            roles.push_back(role);
    }

    if (roles.empty())
        return FSB_ROLE_NONE;

    uint32 idx = urand(0, roles.size() - 1);
    return roles[idx];
}

FSB_ChatterType FSBMgr::GetBotChatterTypeForEntry(uint32 entry)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
        return it->second.chatterType;

    return FSB_ChatterType::None;
}

Gender FSBMgr::GetBotGenderForEntry(uint32 entry)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
        return it->second.gender;

    return GENDER_NONE;
}

uint32 FSBMgr::GetBotPetSourceForEntry(uint32 entry)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
        return it->second.petSource;

    return 0;
}

uint32 FSBMgr::GetBotCompanionSpellForEntry(uint32 entry)
{
    auto it = _botTemplates.find(entry);
    if (it != _botTemplates.end())
        return it->second.companionSpell;

    return 0;
}

bool FSBMgr::HasBotTemplate(uint32 entry)
{
    return _botTemplates.find(entry) != _botTemplates.end();
}

void FSBMgr::AddBotTemplate(FSBEntryRaceClassMap const& data)
{
    _botTemplates[data.entry] = data;
}

void FSBMgr::RemoveBotTemplate(uint32 entry)
{
    _botTemplates.erase(entry);
}

FSB_Roles FSBMgr::GetRole(Creature* bot)
{
    if (!bot || !bot->IsBot())
        return FSB_Roles::FSB_ROLE_NONE;

    if (FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        return ai->botRole;

    return FSB_Roles::FSB_ROLE_NONE;
}

bool FSBMgr::BotIsMeleeRole(Creature* bot)
{
    if (!bot)
        return false;

    FSB_Roles role = Get()->GetRole(bot);
    return role == FSB_ROLE_MELEE_DAMAGE || role == FSB_ROLE_MELEE_DAMAGE_2 || role == FSB_ROLE_MELEE_DAMAGE_3;
}

void FSBMgr::SetRole(Creature* bot, FSB_Roles role)
{
    if (!bot || !bot->IsBot())
        return;

    if (FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        ai->botRole = role;
}

void FSBMgr::ApplyRoleAuras(Creature* bot, FSB_Roles role)
{
    if (!bot)
        return;

    FSB_Class botClass = GetBotClassForEntry(bot->GetEntry());

    switch (botClass)
    {
    case FSB_Class::Druid:   FSBDruid::BotSetRoleAuras(bot, role);   break;
    case FSB_Class::Paladin: FSBPaladin::BotSetRoleAuras(bot, role); break;
    case FSB_Class::Warrior: FSBWarrior::BotSetRoleAuras(bot, role); break;
    case FSB_Class::Priest:  FSBPriest::BotSetRoleAuras(bot, role);  break;
    case FSB_Class::Warlock: FSBWarlock::BotSetRoleAuras(bot, role); break;
    default: break;
    }
}

void FSBMgr::SyncBotPhasingWithOwner(Player* player)
{
    if (!player)
        return;

    auto* bots = GetPersistentBotsForPlayer(player);
    if (!bots || bots->empty())
    {
        TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SyncBotPhasingWithOwner Player {} has no persistent bots", player->GetName());
        return;
    }

    TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SyncBotPhasingWithOwner Player {} has {} bots to sync", player->GetName(), bots->size());

    for (auto const& botData : *bots)
    {
        Creature* bot = nullptr;

        // Try to find bot on current map by spawnId
        if (botData.spawnId != 0)
            bot = player->GetMap()->GetCreatureBySpawnId(botData.spawnId);

        // If not found by spawnId, try by entry (for temp spawns)
        if (!bot)
            bot = player->FindNearestCreatureWithOptions(500.f, { .CreatureId = botData.entry, .IgnorePhases = true });

        if (!bot)
        {
            TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SyncBotPhasingWithOwner Bot entry {} spawnId {} not found for player {}", botData.entry, botData.spawnId, player->GetName());
            continue;
        }

        if (bot->GetOwnerGUID() != player->GetGUID())
        {
            TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SyncBotPhasingWithOwner Bot {} has wrong owner (expected {}, got {})", bot->GetName(), player->GetGUID().ToString(), bot->GetOwnerGUID().ToString());
            continue;
        }

        PhasingHandler::InheritPhaseShift(bot, player);
        bot->UpdateObjectVisibility(true);
        TC_LOG_DEBUG("scripts.fsb.manager", "FSB: SyncBotPhasingWithOwner Synced phasing for bot {} with player {}", bot->GetName(), player->GetName());
    }
}

