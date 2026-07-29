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

#ifndef SC_SCRIPTHELPERS_H
#define SC_SCRIPTHELPERS_H

#include "Define.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include <vector>
#include <string>

class Creature;
class Player;
class BattlegroundMap;

namespace WorldPackets::Battleground
{
    struct PVPMatchStatistics;
}

namespace ScriptHelpers
{
    // Simplified gossip option structure for scripts to avoid needing NPCPackets.h
    struct GossipOptionData
    {
        int32 GossipOptionID;
        uint32 OrderIndex;
        std::string Text;
        uint32 SpellID;
        uint8 Status; // GossipOptionStatus enum value
    };

    // Simplified treasure item structure for scripts
    struct TreasureItemData
    {
        uint32 ItemID;
        uint32 Quantity;
        uint32 ItemContext;
    };

    // Wrapper function to send a clear fake party update packet to a player
    // This constructs the packet internally in the core to avoid linking issues with dynamic loading
    TC_GAME_API void SendClearFakeParty(Player* player);

    // Wrapper function to send a party member full state packet for a bot to a player
    // This constructs the packet internally in the core to avoid linking issues with dynamic loading
    // Takes raw bot data instead of PartyMemberStats to avoid needing PartyPackets.h in scripts
    TC_GAME_API void SendBotMemberState(Player* player, Creature* bot, uint32 level, uint32 currentHealth, uint32 maxHealth, 
                                          uint8 powerType, uint32 currentPower, uint32 maxPower, uint32 zoneID, 
                                          float positionX, float positionY, float positionZ, 
                                          std::vector<uint32> const& auraSpellIds);

    // Wrapper function to send a fake party update packet to a player with bots
    // This constructs the packet internally in the core to avoid linking issues with dynamic loading
    // Takes a list of bot creatures and their class/race/role information to include in the party
    TC_GAME_API void SendFakePartyUpdate(Player* player, std::vector<Creature*> const& bots, std::vector<uint8> const& botClasses, std::vector<uint8> const& botRaces, std::vector<uint8> const& botRoles);

    // Wrapper function to send a fake battleground raid update packet to a player with bots
    // This constructs the packet internally in the core to avoid linking issues with dynamic loading
    // Distributes members across subgroups with a max of 5 per subgroup (core BG raid layout)
    TC_GAME_API void SendFakeBGRaidUpdate(Player* player, std::vector<Creature*> const& bots, std::vector<uint8> const& botClasses, std::vector<uint8> const& botRaces, std::vector<uint8> const& botRoles);

    // Wrapper function to send a GossipMessage packet to a player
    // This constructs the packet internally in the core to avoid linking issues with dynamic loading
    // Takes simplified data structures instead of the full GossipMessage to avoid needing NPCPackets.h in scripts
    TC_GAME_API void SendGossipMessage(Player* player, ObjectGuid gossipGUID, uint32 gossipID, uint32 lfgDungeonsID, 
                                        uint32 broadcastTextID, std::vector<GossipOptionData> const& options,
                                        std::vector<std::vector<TreasureItemData>> const& treasureItems);

    // Wrapper function to send a ShowDelvesCompanionConfigurationUI packet to a player
    // This constructs the packet internally in the core to avoid linking issues with dynamic loading
    TC_GAME_API void SendShowDelvesCompanionConfigurationUI(Player* player, uint32 companionConfigValue);

    // Wrapper function to add a creature entry to a PvP match statistics packet
    // This constructs the player statistics entry internally in the core to avoid needing BattlegroundPackets.h in scripts
    TC_GAME_API void AddCreatureToPvPLogData(WorldPackets::Battleground::PVPMatchStatistics& pvpLogData, ObjectGuid guid, uint8 race, uint8 classId, Gender gender, uint32 creatureId, Team team, uint32 killingBlows = 0, uint32 honorableKills = 0, uint32 deaths = 0, uint32 damageDone = 0, uint32 healingDone = 0);

    TC_GAME_API Team GetTeamForRace(uint8 race);
    TC_GAME_API void SetBotRace(ObjectGuid botGuid, uint8 race);
    TC_GAME_API uint8 GetBotRace(ObjectGuid botGuid);
    TC_GAME_API void EraseBotRace(ObjectGuid botGuid);
    TC_GAME_API Team GetBotTeam(Creature* bot);

    struct BotScoreData
    {
        uint32 KillingBlows = 0;
        uint32 HonorableKills = 0;
        uint32 Deaths = 0;
        uint32 DamageDone = 0;
        uint32 HealingDone = 0;
        uint32 FlagReturns = 0;
        uint32 FlagCaptures = 0;
        uint32 BasesAssaulted = 0;
        uint32 BasesDefended = 0;
    };

    TC_GAME_API void RecordBotKillingBlow(ObjectGuid botGuid);
    TC_GAME_API void RecordBotHonorableKill(ObjectGuid botGuid);
    TC_GAME_API void RecordBotDeath(ObjectGuid botGuid);
    TC_GAME_API void RecordBotDamageDone(ObjectGuid botGuid, uint32 damage);
    TC_GAME_API void RecordBotHealingDone(ObjectGuid botGuid, uint32 heal);
    TC_GAME_API void RecordBotFlagReturn(ObjectGuid botGuid);
    TC_GAME_API void RecordBotFlagCapture(ObjectGuid botGuid);
    TC_GAME_API void RecordBotBaseAssaulted(ObjectGuid botGuid);
    TC_GAME_API void RecordBotBaseDefended(ObjectGuid botGuid);
    TC_GAME_API BotScoreData const* GetBotScore(ObjectGuid botGuid);
    TC_GAME_API void EraseBotScore(ObjectGuid botGuid);

    TC_GAME_API void AddBotsToPvPLogData(BattlegroundMap* battlegroundMap, WorldPackets::Battleground::PVPMatchStatistics& pvpLogData);
    TC_GAME_API uint32 GetAliveBotCountByTeam(BattlegroundMap* battlegroundMap, Team team);
    TC_GAME_API uint32 GetBotTeamRating(BattlegroundMap* battlegroundMap, Team team);

    TC_GAME_API void SetHiredBotCount(uint64 playerGuid, uint8 count);
    TC_GAME_API uint8 GetHiredBotCount(uint64 playerGuid);
    TC_GAME_API void EraseHiredBotCount(uint64 playerGuid);

    constexpr uint32 DATA_BOT_CAPTURED_FLAG = 100;
}

#endif // SC_SCRIPTHELPERS_H
