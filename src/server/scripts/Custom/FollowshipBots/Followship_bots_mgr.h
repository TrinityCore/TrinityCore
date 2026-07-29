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

#pragma once

#include "Followship_bots_db.h"
#include "Followship_bots_defines.h"
#include "Followship_bots_utils.h"

struct FSBEntryRaceClassMap
{
    uint32 entry;
    FSB_Class botClass;
    FSB_Race botRace;
    uint32 companionSpell;
    FSB_ChatterType chatterType;
    Gender gender;
    uint32 petSource;
};

class FSBMgr
{
public:
    static FSBMgr* Get();

    void LoadBotTemplates();

    // Persistent Layer - with DB relation
    void LoadAllPersistentBots();
    bool StorePersistentBot(Creature* bot, Player* player, uint64 hireExpiry);

    void RemovePersistentExpiredPlayerBots(Player* player);
    bool RemovePersistentBot(uint64 playerGuid, uint32 botEntry);

    void UpdateHiredBotCount(Player* player);

    void SpawnPlayerBots(Player* player);

    // Getters
    std::vector<PlayerBotData>* GetPersistentBotsForPlayer(Player* player);
    PlayerBotData* GetPersistentBotBySpawnId(uint64 spawnId);
    Player* GetBotOwner(Unit* unit);

    // Checks the persistent container directly
    bool IsPersistentBotExpired(uint64 ownerGuid, uint64 botEntry);
    // Checks provided bot data
    bool IsBotExpired(PlayerBotData const& bot);


    // Bot Management
    void HirePersistentBot(Player* player, Creature* bot, uint32 hireDurationHours);
    void DismissPersistentBot(Creature* bot);

    void RegisterBotSpawn(Creature* bot, Player* owner);

    bool CheckPlayerHasBotWithEntry(Player* player, uint32 entry);
    bool IsBotOwnedByPlayer(Player* player, Creature* bot);
    bool IsBotOwned(Creature* bot);

    uint64 GetBotExpireTime(uint32 durationHours);
    
    void RestoreBotOwnership(Player* player, Creature* bot, uint32 hireTimeLeft);

    void SetInitialBotState(Creature* bot);

    void SetBotClassAndRace(Creature* creature, FSB_Class& outClass, FSB_Race& outRace);
    bool GetBotClassAndRaceForEntry(uint32 entry, FSB_Class& outClass, FSB_Race& outRace);

    FSB_Class GetBotClassForEntry(uint32 entry);
    void SetBotClass(Creature* creature, FSB_Class& outClass);

    FSB_Race GetBotRaceForEntry(uint32 entry);
    void SetBotRace(Creature* creature, FSB_Race& outRace);

    uint32 GetAvailableRolesForClass(FSB_Class botClass);
    FSB_Roles GetRandomRoleForClass(FSB_Class botClass);

    FSB_ChatterType GetBotChatterTypeForEntry(uint32 entry);

    Gender GetBotGenderForEntry(uint32 entry);

    uint32 GetBotPetSourceForEntry(uint32 entry);
    uint32 GetBotCompanionSpellForEntry(uint32 entry);

    // Get the role of a bot (returns FSB_ROLE_NONE if not a bot or AI not present)
    FSB_Roles GetRole(Creature* bot);

    // Set the role of a bot (does nothing if not a bot or AI not present)
    void SetRole(Creature* bot, FSB_Roles role);

    // Apply class+role specific auras/forms/stances (no-op for classes without them)
    void ApplyRoleAuras(Creature* bot, FSB_Roles role);

    // Check if bot is a melee role
    static bool BotIsMeleeRole(Creature* bot);

    // Sync bot phasing with owner
    void SyncBotPhasingWithOwner(Player* player);

    // Bot template management
    bool HasBotTemplate(uint32 entry);
    void AddBotTemplate(FSBEntryRaceClassMap const& data);
    void RemoveBotTemplate(uint32 entry);

    std::unordered_map<uint32, FSBEntryRaceClassMap> const& GetBotTemplates() const { return _botTemplates; }
    bool IsBotTemplateHired(uint32 entry) const;

private:
    std::unordered_map<uint64 /*playerGuid*/, std::vector<PlayerBotData>> _playerBotsPersistent;
    std::unordered_map<uint32 /*entry*/, FSBEntryRaceClassMap> _botTemplates;
};
