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

#include "ScriptHelpers.h"
#include "BattlegroundPackets.h"
#include "Battleground.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "DB2Structure.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PartyPackets.h"
#include "NPCPackets.h"
#include "DelvePackets.h"
#include "Group.h"
#include "WorldSession.h"
#include "GossipDef.h"

#include <algorithm>
#include <unordered_map>
#include <unordered_set>

namespace ScriptHelpers
{
    void SendClearFakeParty(Player* player)
    {
        if (!player || !player->GetSession() || player->IsBeingTeleportedNear() || player->IsBeingTeleported() || player->IsBeingTeleportedFar() || !player->IsInWorld())
            return;

        // Only clear if the player is NOT in a real group
        if (player->GetGroup() && player->GetGroup()->GetMembersCount() > 1)
            return;

        WorldPackets::Party::PartyUpdate partyUpdate;
        partyUpdate.PartyFlags = GROUP_FLAG_NONE;
        partyUpdate.PartyIndex = GROUP_CATEGORY_HOME;
        partyUpdate.PartyType = GROUP_TYPE_NONE;
        partyUpdate.PartyGUID = ObjectGuid::Empty;
        partyUpdate.LeaderGUID = ObjectGuid::Empty;
        partyUpdate.LeaderFactionGroup = Player::GetFactionGroupForRace(player->GetRace());
        partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(GROUP_CATEGORY_HOME);
        partyUpdate.MyIndex = -1;

        player->SendDirectMessage(partyUpdate.Write());
    }

    void SendBotMemberState(Player* player, Creature* bot, uint32 level, uint32 currentHealth, uint32 maxHealth, 
                           uint8 powerType, uint32 currentPower, uint32 maxPower, uint32 zoneID, 
                           float positionX, float positionY, float positionZ, 
                           std::vector<uint32> const& auraSpellIds)
    {
        if (!player || !player->GetSession() || !player->IsInWorld() || player->IsBeingTeleportedNear() || player->IsBeingTeleported() || player->IsBeingTeleportedFar())
            return;

        if (player->GetSession()->PlayerLoading())
            return;

        if (!bot || !bot->IsInWorld())
            return;

        if (player->GetMapId() != bot->GetMapId())
            return;

        WorldPackets::Party::PartyMemberFullState packet;
        packet.ForEnemy = false;
        packet.MemberGuid = bot->GetGUID();

        auto& stats = packet.MemberStats;
        stats.Level = level;
        stats.CurrentHealth = currentHealth;
        stats.MaxHealth = maxHealth;
        stats.PowerType = powerType;
        stats.CurrentPower = currentPower;
        stats.MaxPower = maxPower;
        stats.ZoneID = zoneID;
        stats.PositionX = positionX;
        stats.PositionY = positionY;
        stats.PositionZ = positionZ;

        // Keep the bot member state consistent with the roster PartyUpdate:
        // PartyType[0] mirrors the group type, PartyType[1] the group category
        // (e.g. GROUP_CATEGORY_INSTANCE for a BG raid group). For players in a BG
        // without a real group (solo) we still report the instance category so the
        // client matches the fake BG raid roster.
        Group* group = player->GetGroup();
        stats.PartyType[0] = GROUP_TYPE_NORMAL;
        if (group)
            stats.PartyType[1] = group->GetGroupCategory();
        else if (player->InBattleground())
            stats.PartyType[1] = GROUP_CATEGORY_INSTANCE;
        else
            stats.PartyType[1] = GROUP_CATEGORY_HOME;

        // Populate auras
        for (uint32 spellId : auraSpellIds)
        {
            WorldPackets::Party::PartyMemberAuraStates& aura = stats.Auras.emplace_back();
            aura.SpellID = spellId;
            aura.ActiveFlags = 0;
            aura.Flags = 0;
        }

        player->SendDirectMessage(packet.Write());
    }

    void SendFakePartyUpdate(Player* player, std::vector<Creature*> const& bots, std::vector<uint8> const& botClasses, std::vector<uint8> const& botRaces, std::vector<uint8> const& botRoles)
    {
        if (!player || !player->IsInWorld() || player->IsBeingTeleportedNear() || player->IsBeingTeleported() || player->IsBeingTeleportedFar())
            return;

        Group* realGroup = player->GetGroup();

        if (bots.empty())
        {
            if (!realGroup || realGroup->GetMembersCount() == 1)
            {
                // Player is solo ? send a clean "clear fake party"
                SendClearFakeParty(player);
            }
            else
            {
                // Player is in a real group ? send a normal group-only PartyUpdate
                WorldPackets::Party::PartyUpdate partyUpdate;
                partyUpdate.PartyFlags = realGroup->GetGroupFlags();
                partyUpdate.PartyIndex = realGroup->GetGroupCategory();
                partyUpdate.PartyType = GROUP_TYPE_NORMAL;
                partyUpdate.PartyGUID = realGroup->GetGUID();
                partyUpdate.LeaderGUID = realGroup->GetLeaderGUID();
                partyUpdate.LeaderFactionGroup = Player::GetFactionGroupForRace(player->GetRace());
                partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(realGroup->GetGroupCategory());

                int32 myIndex = -1;
                uint8 index = 0;

                for (auto const& memberSlot : realGroup->GetMemberSlots())
                {
                    if (memberSlot.guid == player->GetGUID())
                        myIndex = index;

                    Player* member = ObjectAccessor::FindConnectedPlayer(memberSlot.guid);

                    WorldPackets::Party::PartyPlayerInfo& info = partyUpdate.PlayerList.emplace_back();
                    info.GUID = memberSlot.guid;
                    info.Name = memberSlot.name;
                    info.Class = memberSlot._class;
                    info.FactionGroup = Player::GetFactionGroupForRace(memberSlot.race);
                    info.Connected = member && member->GetSession() && !member->GetSession()->PlayerLogout();
                    info.Subgroup = memberSlot.group;
                    info.Flags = memberSlot.flags;
                    info.RolesAssigned = memberSlot.roles;
                    ++index;
                }

                partyUpdate.MyIndex = myIndex;

                if (realGroup->GetMembersCount() > 1)
                {
                    partyUpdate.LootSettings.emplace();
                    partyUpdate.LootSettings->Method = realGroup->GetLootMethod();
                    partyUpdate.LootSettings->Threshold = realGroup->GetLootThreshold();
                    partyUpdate.LootSettings->LootMaster = ObjectGuid::Empty;

                    partyUpdate.DifficultySettings.emplace();
                    partyUpdate.DifficultySettings->DungeonDifficultyID = realGroup->GetDungeonDifficultyID();
                    partyUpdate.DifficultySettings->RaidDifficultyID = realGroup->GetRaidDifficultyID();
                    partyUpdate.DifficultySettings->LegacyRaidDifficultyID = realGroup->GetLegacyRaidDifficultyID();
                }

                player->SendDirectMessage(partyUpdate.Write());
            }

            return;
        }

        WorldPackets::Party::PartyUpdate partyUpdate;

        // Filter bots and match with class/race/role info
        std::vector<Creature*> safeBots;
        std::vector<uint8> safeBotClasses;
        std::vector<uint8> safeBotRaces;
        std::vector<uint8> safeBotRoles;
        for (size_t i = 0; i < bots.size() && i < botClasses.size() && i < botRaces.size() && i < botRoles.size(); ++i)
        {
            if (bots[i] && bots[i]->IsInWorld())
            {
                safeBots.push_back(bots[i]);
                safeBotClasses.push_back(botClasses[i]);
                safeBotRaces.push_back(botRaces[i]);
                safeBotRoles.push_back(botRoles[i]);
            }
        }

        // ------------------------------------------------------------

        if (realGroup)
        {
            // Player is in a real group - augment it with bots
            partyUpdate.PartyFlags = realGroup->GetGroupFlags();
            partyUpdate.PartyIndex = realGroup->GetGroupCategory();
            partyUpdate.PartyType = GROUP_TYPE_NORMAL;
            partyUpdate.PartyGUID = realGroup->GetGUID();
            partyUpdate.LeaderGUID = realGroup->GetLeaderGUID();
            partyUpdate.LeaderFactionGroup = Player::GetFactionGroupForRace(player->GetRace());
            partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(realGroup->GetGroupCategory());

            int32 myIndex = -1;
            uint8 index = 0;

            for (auto const& memberSlot : realGroup->GetMemberSlots())
            {
                if (memberSlot.guid == player->GetGUID())
                    myIndex = index;

                Player* member = ObjectAccessor::FindConnectedPlayer(memberSlot.guid);

                WorldPackets::Party::PartyPlayerInfo& info = partyUpdate.PlayerList.emplace_back();
                info.GUID = memberSlot.guid;
                info.Name = memberSlot.name;
                info.Class = memberSlot._class;
                info.FactionGroup = Player::GetFactionGroupForRace(memberSlot.race);
                info.Connected = member && member->GetSession() && !member->GetSession()->PlayerLogout();
                info.Subgroup = memberSlot.group;
                info.Flags = memberSlot.flags;
                info.RolesAssigned = memberSlot.roles;
                ++index;
            }

            partyUpdate.MyIndex = myIndex;

            // Append bots
            for (size_t i = 0; i < safeBots.size(); ++i)
            {
                WorldPackets::Party::PartyPlayerInfo& info = partyUpdate.PlayerList.emplace_back();
                info.GUID = safeBots[i]->GetGUID();
                info.Name = safeBots[i]->GetName();
                info.Class = safeBotClasses[i];
                info.FactionGroup = Player::GetFactionGroupForRace(safeBotRaces[i]);
                info.Connected = true;
                info.Subgroup = 0;
                info.RolesAssigned = safeBotRoles[i];
            }

            if (realGroup->GetMembersCount() > 1)
            {
                partyUpdate.LootSettings.emplace();
                partyUpdate.LootSettings->Method = realGroup->GetLootMethod();
                partyUpdate.LootSettings->Threshold = realGroup->GetLootThreshold();
                partyUpdate.LootSettings->LootMaster = ObjectGuid::Empty;

                partyUpdate.DifficultySettings.emplace();
                partyUpdate.DifficultySettings->DungeonDifficultyID = realGroup->GetDungeonDifficultyID();
                partyUpdate.DifficultySettings->RaidDifficultyID = realGroup->GetRaidDifficultyID();
                partyUpdate.DifficultySettings->LegacyRaidDifficultyID = realGroup->GetLegacyRaidDifficultyID();
            }

            player->SendDirectMessage(partyUpdate.Write());
        }
        else
        {
            // Player is solo - create a fake party with bots
            partyUpdate.PartyFlags = GROUP_FLAG_NONE;
            partyUpdate.PartyIndex = GROUP_CATEGORY_HOME;
            partyUpdate.PartyType = GROUP_TYPE_NORMAL;
            partyUpdate.PartyGUID = player->GetGUID();
            partyUpdate.LeaderGUID = player->GetGUID();
            partyUpdate.LeaderFactionGroup = Player::GetFactionGroupForRace(player->GetRace());
            partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(GROUP_CATEGORY_HOME);
            partyUpdate.MyIndex = 0;

            // Add player
            WorldPackets::Party::PartyPlayerInfo& playerInfo = partyUpdate.PlayerList.emplace_back();
            playerInfo.GUID = player->GetGUID();
            playerInfo.Name = player->GetName();
            playerInfo.Class = player->GetClass();
            playerInfo.FactionGroup = Player::GetFactionGroupForRace(player->GetRace());
            playerInfo.Connected = true;
            playerInfo.Subgroup = 0;
            playerInfo.Flags = 0;
            playerInfo.RolesAssigned = 0;

            // Add bots
            for (size_t i = 0; i < safeBots.size(); ++i)
            {
                WorldPackets::Party::PartyPlayerInfo& info = partyUpdate.PlayerList.emplace_back();
                info.GUID = safeBots[i]->GetGUID();
                info.Name = safeBots[i]->GetName();
                info.Class = safeBotClasses[i];
                info.FactionGroup = Player::GetFactionGroupForRace(safeBotRaces[i]);
                info.Connected = true;
                info.Subgroup = 0;
                info.RolesAssigned = safeBotRoles[i];
            }

            player->SendDirectMessage(partyUpdate.Write());
        }
    }

    void SendFakeBGRaidUpdate(Player* player, std::vector<Creature*> const& bots, std::vector<uint8> const& botClasses, std::vector<uint8> const& botRaces, std::vector<uint8> const& botRoles)
    {
        if (!player || !player->IsInWorld() || player->IsBeingTeleportedNear() || player->IsBeingTeleported() || player->IsBeingTeleportedFar())
            return;

        Group* realGroup = player->GetGroup();

        // Filter bots and match with class/race/role info
        std::vector<Creature*> safeBots;
        std::vector<uint8> safeBotClasses;
        std::vector<uint8> safeBotRaces;
        std::vector<uint8> safeBotRoles;
        for (size_t i = 0; i < bots.size() && i < botClasses.size() && i < botRaces.size() && i < botRoles.size(); ++i)
        {
            if (bots[i] && bots[i]->IsInWorld())
            {
                safeBots.push_back(bots[i]);
                safeBotClasses.push_back(botClasses[i]);
                safeBotRaces.push_back(botRaces[i]);
                safeBotRoles.push_back(botRoles[i]);
            }
        }

        WorldPackets::Party::PartyUpdate partyUpdate;

        // Mimic a BG raid group: raid flag + instance category so the client
        // renders the multi-subgroup raid frame.
        partyUpdate.PartyFlags = GROUP_MASK_BGRAID;
        partyUpdate.PartyIndex = GROUP_CATEGORY_INSTANCE;
        partyUpdate.PartyType = GROUP_TYPE_NORMAL;
        partyUpdate.LeaderFactionGroup = Player::GetFactionGroupForRace(player->GetRace());
        partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(GROUP_CATEGORY_INSTANCE);

        // Track per-subgroup occupancy so bots fill sequentially into the
        // lowest subgroup that still has room (< MAX_GROUP_SIZE members).
        uint8 subGroupCounts[MAX_RAID_SUBGROUPS] = {};

        if (realGroup)
        {
            partyUpdate.PartyGUID = realGroup->GetGUID();
            partyUpdate.LeaderGUID = realGroup->GetLeaderGUID();

            int32 myIndex = -1;
            uint8 index = 0;

            for (auto const& memberSlot : realGroup->GetMemberSlots())
            {
                if (memberSlot.guid == player->GetGUID())
                    myIndex = index;

                if (memberSlot.group < MAX_RAID_SUBGROUPS)
                    ++subGroupCounts[memberSlot.group];

                Player* member = ObjectAccessor::FindConnectedPlayer(memberSlot.guid);

                WorldPackets::Party::PartyPlayerInfo& info = partyUpdate.PlayerList.emplace_back();
                info.GUID = memberSlot.guid;
                info.Name = memberSlot.name;
                info.Class = memberSlot._class;
                info.FactionGroup = Player::GetFactionGroupForRace(memberSlot.race);
                info.Connected = member && member->GetSession() && !member->GetSession()->PlayerLogout();
                info.Subgroup = memberSlot.group;
                info.Flags = memberSlot.flags;
                info.RolesAssigned = memberSlot.roles;
                ++index;
            }

            partyUpdate.MyIndex = myIndex;
        }
        else
        {
            // No real group: create a fake BG raid with the player as leader.
            partyUpdate.PartyGUID = player->GetGUID();
            partyUpdate.LeaderGUID = player->GetGUID();
            partyUpdate.MyIndex = 0;

            WorldPackets::Party::PartyPlayerInfo& playerInfo = partyUpdate.PlayerList.emplace_back();
            playerInfo.GUID = player->GetGUID();
            playerInfo.Name = player->GetName();
            playerInfo.Class = player->GetClass();
            playerInfo.FactionGroup = Player::GetFactionGroupForRace(player->GetRace());
            playerInfo.Connected = true;
            playerInfo.Subgroup = 0;
            playerInfo.Flags = 0;
            playerInfo.RolesAssigned = 0;

            // Player occupies slot 0 in subgroup 0.
            subGroupCounts[0] = 1;
        }

        // Add bots into the lowest subgroup that still has room (< 5 members).
        for (size_t i = 0; i < safeBots.size(); ++i)
        {
            uint8 targetSub = 0;
            for (uint8 s = 0; s < MAX_RAID_SUBGROUPS; ++s)
            {
                if (subGroupCounts[s] < MAX_GROUP_SIZE)
                {
                    targetSub = s;
                    break;
                }
                targetSub = MAX_RAID_SUBGROUPS - 1;
            }

            ++subGroupCounts[targetSub];

            WorldPackets::Party::PartyPlayerInfo& info = partyUpdate.PlayerList.emplace_back();
            info.GUID = safeBots[i]->GetGUID();
            info.Name = safeBots[i]->GetName();
            info.Class = safeBotClasses[i];
            info.FactionGroup = Player::GetFactionGroupForRace(safeBotRaces[i]);
            info.Connected = true;
            info.Subgroup = targetSub;
            info.Flags = 0;
            info.RolesAssigned = safeBotRoles[i];
        }

        if (realGroup && realGroup->GetMembersCount() > 1)
        {
            partyUpdate.LootSettings.emplace();
            partyUpdate.LootSettings->Method = realGroup->GetLootMethod();
            partyUpdate.LootSettings->Threshold = realGroup->GetLootThreshold();
            partyUpdate.LootSettings->LootMaster = ObjectGuid::Empty;

            partyUpdate.DifficultySettings.emplace();
            partyUpdate.DifficultySettings->DungeonDifficultyID = realGroup->GetDungeonDifficultyID();
            partyUpdate.DifficultySettings->RaidDifficultyID = realGroup->GetRaidDifficultyID();
            partyUpdate.DifficultySettings->LegacyRaidDifficultyID = realGroup->GetLegacyRaidDifficultyID();
        }

        player->SendDirectMessage(partyUpdate.Write());
    }

    void SendGossipMessage(Player* player, ObjectGuid gossipGUID, uint32 gossipID, uint32 lfgDungeonsID, 
                           uint32 broadcastTextID, std::vector<GossipOptionData> const& options,
                           std::vector<std::vector<TreasureItemData>> const& treasureItems)
    {
        if (!player || !player->GetSession())
            return;

        WorldPackets::NPC::GossipMessage gossipMessage;
        gossipMessage.GossipGUID = gossipGUID;
        gossipMessage.GossipID = gossipID;
        gossipMessage.LfgDungeonsID = lfgDungeonsID;
        gossipMessage.BroadcastTextID = broadcastTextID;

        for (size_t i = 0; i < options.size() && i < treasureItems.size(); ++i)
        {
            auto& opt = gossipMessage.GossipOptions.emplace_back();
            opt.GossipOptionID = options[i].GossipOptionID;
            opt.OrderIndex = options[i].OrderIndex;
            opt.OptionNPC = GossipOptionNpc::None;
            opt.Text = options[i].Text;
            opt.SpellID = options[i].SpellID;
            opt.Status = static_cast<GossipOptionStatus>(options[i].Status);

            for (auto const& itemData : treasureItems[i])
            {
                WorldPackets::NPC::TreasureItem ti;
                ti.Type = GossipOptionRewardType::Item;
                ti.ID = itemData.ItemID;
                ti.Quantity = itemData.Quantity;
                ti.ItemContext = itemData.ItemContext;
                opt.Treasure.Items.push_back(ti);
            }
        }

        player->GetSession()->SendPacket(gossipMessage.Write());
    }

    void SendShowDelvesCompanionConfigurationUI(Player* player, uint32 companionConfigValue)
    {
        if (!player || !player->GetSession())
            return;

        WorldPackets::Delve::ShowDelvesCompanionConfigurationUI configUI;
        configUI.CompanionConfigValue = companionConfigValue;
        player->GetSession()->SendPacket(configUI.Write());
    }

    void AddCreatureToPvPLogData(WorldPackets::Battleground::PVPMatchStatistics& pvpLogData, ObjectGuid guid, uint8 race, uint8 classId, Gender gender, uint32 creatureId, Team team, uint32 killingBlows, uint32 honorableKills, uint32 deaths, uint32 damageDone, uint32 healingDone)
    {
        WorldPackets::Battleground::PVPMatchStatistics::PVPMatchPlayerStatistics playerData;
        playerData.PlayerGUID = guid;
        playerData.Faction = (team == ALLIANCE) ? PVP_TEAM_ALLIANCE : PVP_TEAM_HORDE;
        playerData.IsInWorld = true;
        playerData.CreatureID = creatureId;
        playerData.Sex = int8(gender);
        playerData.Race = int8(race);
        playerData.Class = int8(classId);
        playerData.Kills = killingBlows;
        playerData.DamageDone = damageDone;
        playerData.HealingDone = healingDone;
        if (honorableKills || deaths)
        {
            playerData.Honor.emplace();
            playerData.Honor->HonorKills = honorableKills;
            playerData.Honor->Deaths = deaths;
        }

        pvpLogData.Statistics.push_back(playerData);
    }

    Team GetTeamForRace(uint8 race)
    {
        ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
        if (!rEntry)
            return ALLIANCE;

        switch (rEntry->Alliance)
        {
            case 0: return ALLIANCE;
            case 1: return HORDE;
            case 2: return PANDARIA_NEUTRAL;
            default: return ALLIANCE;
        }
    }

    std::unordered_map<ObjectGuid, uint8> BotRaces;

    void SetBotRace(ObjectGuid botGuid, uint8 race)
    {
        BotRaces[botGuid] = race;
    }

    uint8 GetBotRace(ObjectGuid botGuid)
    {
        auto it = BotRaces.find(botGuid);
        if (it != BotRaces.end())
            return it->second;

        return RACE_HUMAN;
    }

    void EraseBotRace(ObjectGuid botGuid)
    {
        BotRaces.erase(botGuid);
    }

    Team GetBotTeam(Creature* bot)
    {
        if (!bot || !bot->IsBot())
            return TEAM_OTHER;

        FactionTemplateEntry const* ftEntry = bot->GetFactionTemplateEntry();
        if (!ftEntry)
            return TEAM_OTHER;

        if (ftEntry->FactionGroup & FACTION_MASK_ALLIANCE)
            return ALLIANCE;
        if (ftEntry->FactionGroup & FACTION_MASK_HORDE)
            return HORDE;

        return TEAM_OTHER;
    }

    std::unordered_map<ObjectGuid, BotScoreData> BotScores;

    void RecordBotKillingBlow(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.KillingBlows;
        ++score.HonorableKills;
    }

    void RecordBotHonorableKill(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.HonorableKills;
    }

    void RecordBotDeath(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.Deaths;
    }

    void RecordBotDamageDone(ObjectGuid botGuid, uint32 damage)
    {
        if (!damage)
            return;
        BotScoreData& score = BotScores[botGuid];
        score.DamageDone += damage;
    }

    void RecordBotHealingDone(ObjectGuid botGuid, uint32 heal)
    {
        if (!heal)
            return;
        BotScoreData& score = BotScores[botGuid];
        score.HealingDone += heal;
    }

    void RecordBotFlagReturn(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.FlagReturns;
    }

    void RecordBotFlagCapture(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.FlagCaptures;
    }

    void RecordBotBaseAssaulted(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.BasesAssaulted;
    }

    void RecordBotBaseDefended(ObjectGuid botGuid)
    {
        BotScoreData& score = BotScores[botGuid];
        ++score.BasesDefended;
    }

    BotScoreData const* GetBotScore(ObjectGuid botGuid)
    {
        auto it = BotScores.find(botGuid);
        return it != BotScores.end() ? &it->second : nullptr;
    }

    void EraseBotScore(ObjectGuid botGuid)
    {
        BotScores.erase(botGuid);
    }

    void AddBotsToPvPLogData(BattlegroundMap* battlegroundMap, WorldPackets::Battleground::PVPMatchStatistics& pvpLogData)
    {
        if (!battlegroundMap)
            return;

        Battleground* bg = battlegroundMap->GetBG();
        std::unordered_set<uint32> const* pvpStatIds = bg ? bg->GetPvpStatIds() : nullptr;

        int8 botCountAlliance = 0;
        int8 botCountHorde = 0;

        for (auto const& [guid, creature] : battlegroundMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot())
                continue;

            Team team = GetBotTeam(creature);
            if (team == ALLIANCE)
                ++botCountAlliance;
            else if (team == HORDE)
                ++botCountHorde;
            else
                continue;

            uint32 killingBlows = 0;
            uint32 honorableKills = 0;
            uint32 deaths = 0;
            uint32 damageDone = 0;
            uint32 healingDone = 0;
            uint32 flagReturns = 0;
            uint32 flagCaptures = 0;
            uint32 basesAssaulted = 0;
            uint32 basesDefended = 0;
            if (BotScoreData const* score = GetBotScore(guid))
            {
                killingBlows = score->KillingBlows;
                honorableKills = score->HonorableKills;
                deaths = score->Deaths;
                damageDone = score->DamageDone;
                healingDone = score->HealingDone;
                flagReturns = score->FlagReturns;
                flagCaptures = score->FlagCaptures;
                basesAssaulted = score->BasesAssaulted;
                basesDefended = score->BasesDefended;
            }

            AddCreatureToPvPLogData(pvpLogData, guid, GetBotRace(guid), creature->GetClass(), creature->GetGender(), creature->GetEntry(), team, killingBlows, honorableKills, deaths, damageDone, healingDone);

            if (pvpStatIds && !pvpStatIds->empty())
            {
                constexpr uint32 PVP_STAT_FLAG_CAPTURES = 928;
                constexpr uint32 PVP_STAT_FLAG_RETURNS = 929;
                constexpr uint32 PVP_STAT_BASES_ASSAULTED = 926;
                constexpr uint32 PVP_STAT_BASES_DEFENDED = 927;
                auto& botEntry = pvpLogData.Statistics.back();
                for (uint32 statId : *pvpStatIds)
                {
                    int32 value = 0;
                    if (statId == PVP_STAT_FLAG_CAPTURES)
                        value = int32(flagCaptures);
                    else if (statId == PVP_STAT_FLAG_RETURNS)
                        value = int32(flagReturns);
                    else if (statId == PVP_STAT_BASES_ASSAULTED)
                        value = int32(basesAssaulted);
                    else if (statId == PVP_STAT_BASES_DEFENDED)
                        value = int32(basesDefended);
                    botEntry.Stats.emplace_back(int32(statId), value);
                }
            }
        }

        pvpLogData.PlayerCount[PVP_TEAM_ALLIANCE] += botCountAlliance;
        pvpLogData.PlayerCount[PVP_TEAM_HORDE] += botCountHorde;
    }

    uint32 GetAliveBotCountByTeam(BattlegroundMap* battlegroundMap, Team team)
    {
        if (!battlegroundMap)
            return 0;

        uint32 count = 0;
        for (auto const& [guid, creature] : battlegroundMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot() || !creature->IsAlive())
                continue;

            if (GetBotTeam(creature) == team)
                ++count;
        }

        return count;
    }

    uint32 GetBotTeamRating(BattlegroundMap* battlegroundMap, Team team)
    {
        if (!battlegroundMap)
            return 0;

        uint32 totalHealth = 0;
        for (auto const& [guid, creature] : battlegroundMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot())
                continue;

            if (GetBotTeam(creature) == team)
                totalHealth += creature->GetMaxHealth();
        }

        uint32 rating = totalHealth / 10;
        if (rating > 2000)
            rating = 2000;

        return rating;
    }

    std::unordered_map<uint64, uint8> HiredBotCounts;

    void SetHiredBotCount(uint64 playerGuid, uint8 count)
    {
        HiredBotCounts[playerGuid] = count;
    }

    uint8 GetHiredBotCount(uint64 playerGuid)
    {
        auto it = HiredBotCounts.find(playerGuid);
        if (it != HiredBotCounts.end())
            return it->second;

        return 0;
    }

    void EraseHiredBotCount(uint64 playerGuid)
    {
        HiredBotCounts.erase(playerGuid);
    }
}
