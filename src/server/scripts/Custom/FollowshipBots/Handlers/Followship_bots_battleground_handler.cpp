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

#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_arathi_basin.h"
#include "Followship_bots_warsong_gulch.h"
#include "Followship_bots_arena.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_party_handler.h"
#include "Followship_bots_combat_handler.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_stats_handler.h"

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "Creature.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "Timer.h"
#include "Unit.h"
#include "WorldSession.h"
#include "ScriptHelpers.h"

#include <algorithm>
#include <random>
#include <string>
#include <unordered_map>

namespace FSBBattleground
{
    Team GetBotTeam(Creature* bot)
    {
        FSB_BaseAI* botAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        return FSBUtils::GetTeamFromFSBRace(botAI->botRace);
    }

    ObjectGuid ResolveAttackerGuid(Unit* attacker)
    {
        if (!attacker)
            return ObjectGuid::Empty;

        if (Player* player = attacker->GetCharmerOrOwnerPlayerOrPlayerItself())
            return player->GetGUID();

        if (Unit* owner = attacker->GetCharmerOrOwner())
            if (Creature* creature = owner->ToCreature())
                if (creature->IsBot())
                    return creature->GetGUID();

        if (Creature* creature = attacker->ToCreature())
            if (creature->IsBot())
                return creature->GetGUID();

        return ObjectGuid::Empty;
    }

    void SpawnBots(Battleground* battleground, BattlegroundMap* /*battlegroundMap*/, Player* triggeringPlayer)
    {
        if (!battleground)
            return;

        switch (battleground->GetTypeID())
        {
            case BATTLEGROUND_WS:
            case BATTLEGROUND_WG_CTF:
                SpawnBotsForTeams(battleground, WarsongGulch::FSB_WSG_MAX_TEAM_SIZE, triggeringPlayer);
                break;
            case BATTLEGROUND_AB:
            case BATTLEGROUND_DOM_AB:
                SpawnBotsForTeams(battleground, ArathiBasin::FSB_AB_MAX_TEAM_SIZE, triggeringPlayer);
                break;
            case BATTLEGROUND_TTP:
            case BATTLEGROUND_DS:
            case BATTLEGROUND_AF:
            case BATTLEGROUND_TVA:
            case BATTLEGROUND_RL:
            case BATTLEGROUND_BRH:
            case BATTLEGROUND_CC3:
            case BATTLEGROUND_RL3:
            case BATTLEGROUND_BRHA3:
            case BATTLEGROUND_MC3:
            case BATTLEGROUND_HP:
            case BATTLEGROUND_NNA:
            case BATTLEGROUND_MB:
            case BATTLEGROUND_TR:
            case BATTLEGROUND_AA:
                SpawnBotsForTeams(battleground, battleground->GetArenaType(), triggeringPlayer);
                break;
            default:
                TC_LOG_DEBUG("scripts.fsb.battleground", "FSBBattleground::SpawnBots not implemented for bg type {}", battleground->GetTypeID());
                break;
        }
    }

    void SpawnBotsForTeams(Battleground* battleground, uint32 maxTeamSize, Player* triggeringPlayer)
    {
        FSBBattleground::ClearSpawnedBotGuids(battleground->GetBgMap());

        // Count real players from GetPlayers() instead of GetPlayersCountByTeam(),
        // because the triggering player may not yet be registered in the BG's team count.
        uint32 alliancePlayers = 0;
        uint32 hordePlayers = 0;
        bool triggeringInRoster = false;
        for (auto const& [guid, bgPlayer] : battleground->GetPlayers())
        {
            if (triggeringPlayer && guid == triggeringPlayer->GetGUID())
                triggeringInRoster = true;

            if (bgPlayer.Team == ALLIANCE)
                ++alliancePlayers;
            else if (bgPlayer.Team == HORDE)
                ++hordePlayers;
        }

        // If the triggering player is not yet in the BG roster, account for them.
        if (triggeringPlayer && !triggeringInRoster)
        {
            if (triggeringPlayer->GetTeam() == ALLIANCE)
                ++alliancePlayers;
            else if (triggeringPlayer->GetTeam() == HORDE)
                ++hordePlayers;
        }

        uint32 const allianceExistingBots = FSBBattleground::CountExistingBots(battleground, ALLIANCE);
        uint32 const hordeExistingBots = FSBBattleground::CountExistingBots(battleground, HORDE);

        int32 const allianceNeeded = std::max(0, int32(maxTeamSize) - int32(alliancePlayers) - int32(allianceExistingBots));
        int32 const hordeNeeded = std::max(0, int32(maxTeamSize) - int32(hordePlayers) - int32(hordeExistingBots));

        TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: players A={} H={}; existing bots A={} H={}; needed A={} H={}",
            alliancePlayers, hordePlayers, allianceExistingBots, hordeExistingBots, allianceNeeded, hordeNeeded);

        if (allianceNeeded <= 0 && hordeNeeded <= 0)
        {
            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: No bots needed, aborting");
            return;
        }

        std::vector<uint32> allianceEntries;
        std::vector<uint32> hordeEntries;

        uint32 totalTemplates = 0;
        uint32 hiredTemplates = 0;
        for (auto const& [entry, templateData] : FSBMgr::Get()->GetBotTemplates())
        {
            ++totalTemplates;
            if (FSBMgr::Get()->IsBotTemplateHired(entry))
            {
                ++hiredTemplates;
                continue;
            }

            Team team = FSBUtils::GetTeamFromFSBRace(templateData.botRace);
            if (team == ALLIANCE)
                allianceEntries.push_back(entry);
            else if (team == HORDE)
                hordeEntries.push_back(entry);
        }

        TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: bot templates total={} hired={} available A={} H={}",
            totalTemplates, hiredTemplates, allianceEntries.size(), hordeEntries.size());

        auto const spawnTeam = [&](Team team, int32 needed, std::vector<uint32>& availableEntries)
        {
            if (needed <= 0)
                return;

            std::vector<uint32> selected = FSBBattleground::SelectRandomEntries(availableEntries, static_cast<uint32>(needed));
            if (selected.empty())
            {
                TC_LOG_WARN("scripts.fsb.battleground", "FSB BG Handler: No available bot templates for team {}", team);
                return;
            }

            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: selected {} bot entries for team {}", selected.size(), team);

            TeamId teamId = Battleground::GetTeamIndexByTeamId(team);
            WorldSafeLocsEntry const* startPos = battleground->GetTeamStartPosition(teamId);
            if (!startPos)
            {
                TC_LOG_ERROR("scripts.fsb.battleground", "FSB BG Handler: No start position for team {}", team);
                return;
            }

            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: start position for team {} found", team);

            for (uint32 entry : selected)
            {
                Position pos(startPos->Loc);
                pos.m_positionX += frand(-3.0f, 3.0f);
                pos.m_positionY += frand(-3.0f, 3.0f);

                Creature* bot = battleground->GetBgMap()->SummonCreature(entry, pos);
                if (!bot)
                {
                    TC_LOG_ERROR("scripts.fsb.battleground", "FSB BG Handler: Failed to summon bot entry {}", entry);
                    continue;
                }

                bot->SetPvP(true);
                bot->SetLevel(triggeringPlayer->GetLevel());
                FSBStats::RecalculateStats(bot, true, true);
                FSBBattleground::AddBotSpawnGuid(battleground->GetBgMap(), bot->GetGUID());

                std::string spawnMsg = FSBBattlegroundChat::FormatChatLine(FSBBattlegroundChat::SpawnChatLines[urand(0, FSBBattlegroundChat::SpawnChatLines.size() - 1)], team);
                FSBEvents::ScheduleBotEventWithChatter(bot, FSB_EVENT_BATTLEGROUND_SPAWN_CHAT, 3s, 15s, FSB_ReplyType::Raid, spawnMsg, nullptr);

                TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: Spawned bot {} for team {}", bot->GetEntry(), team);
            }

            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Handler: Spawned bots for team {}", team);
        };

        spawnTeam(ALLIANCE, allianceNeeded, allianceEntries);
        spawnTeam(HORDE, hordeNeeded, hordeEntries);
    }

    void RespawnBotOnDespawn(Creature* bot)
    {
        if (!bot)
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI || baseAI->botHired)
            return;

        FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData();
        if (!bgData)
            return;

        if (!FSBBattleground::IsInProgress(bot))
            return;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return;

        uint32 entry = bot->GetEntry();

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        if (bg->GetPlayers().empty())
            return;

        TeamId teamId = Battleground::GetTeamIndexByTeamId(botTeam);
        WorldSafeLocsEntry const* startPos = bg->GetTeamStartPosition(teamId);
        if (!startPos)
            return;

        Position pos(startPos->Loc);
        pos.m_positionX += frand(-3.0f, 3.0f);
        pos.m_positionY += frand(-3.0f, 3.0f);

        Creature* newBot = bgMap->SummonCreature(entry, pos);
        if (!newBot)
            return;

        newBot->SetPvP(true);
        FSBBattleground::AddBotSpawnGuid(bgMap, newBot->GetGUID());

        TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: Respawned bot {} for team {} after despawn", newBot->GetEntry(), botTeam);
    }

    bool IsInBG(Creature const* bot)
    {
        if (!bot)
            return false;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return false;

        return true;
    }

    bool IsInProgress(Creature const* bot)
    {
        if (!bot)
            return false;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return false;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return false;

        return bg->GetStatus() == STATUS_IN_PROGRESS;
    }

    bool IsFinished(Creature const* bot)
    {
        if (!bot)
            return false;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return false;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return false;

        return bg->GetStatus() == STATUS_WAIT_LEAVE;
    }

    void InitializeBot(Creature* bot)
    {
        if (!bot)
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (baseAI->botHired)
            return;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        if (!baseAI->botBattlegroundData)
            baseAI->botBattlegroundData = new FSB_BattlegroundData();
        FSB_BattlegroundData* bgData = baseAI->botBattlegroundData;

        if (!bgData->initialized)
        {
            bgData->bgTypeId = bg->GetTypeID();
            bgData->initialized = true;
        }

        if (bg->isArena())
        {
            FSBBattleground::Arena::InitializeArenaBot(bot, bgData, bg);
            return;
        }

        switch (bg->GetTypeID())
        {
        case BATTLEGROUND_WS:
        case BATTLEGROUND_WG_CTF:
        case BATTLEGROUND_AB:
        case BATTLEGROUND_DOM_AB:
            InitializeBotGeneric(bot, bgData, bg);
            break;
        default:
            break;
        }
    }

    void InitializeBotGeneric(Creature* bot, FSB_BattlegroundData* bgData, Battleground* bg)
    {
        if (!bot || !bgData || !bg)
            return;

        Milliseconds delay = FSBBattleground::IsInProgress(bot) ? 100ms : 2min;
        FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_BATTLEGROUND_START, delay);
    }

    void HandlePlayerKilledBot(ObjectGuid killerGuid, Unit* botVictim)
    {
        if (!killerGuid || !botVictim)
            return;

        BattlegroundMap* bgMap = botVictim->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        Player* killer = ObjectAccessor::GetPlayer(bgMap, killerGuid);
        if (!killer)
            return;

        bg->UpdatePlayerScore(killer, SCORE_KILLING_BLOWS, 1);
        bg->UpdatePlayerScore(killer, SCORE_HONORABLE_KILLS, 1);
    }

    void HandleBotKilledPlayer(Unit* botKiller, ObjectGuid victimGuid)
    {
        if (!botKiller || !victimGuid)
            return;

        BattlegroundMap* bgMap = botKiller->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        Player* victim = ObjectAccessor::GetPlayer(bgMap, victimGuid);
        if (!victim)
            return;

        bg->UpdatePlayerScore(victim, SCORE_DEATHS, 1);
    }

    void HandlePlayerDamagedBot(Unit* attacker, Unit* botVictim, uint32 damage)
    {
        if (!attacker || !botVictim || !damage)
            return;

        Player* player = attacker->ToPlayer();
        if (!player)
            return;

        BattlegroundMap* bgMap = botVictim->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg || bg->GetStatus() != STATUS_IN_PROGRESS)
            return;

        bg->UpdatePlayerScore(player, SCORE_DAMAGE_DONE, damage);
    }

    void HandleBotDeathScores(Creature* bot, Unit* killer)
    {
        if (!bot || !bot->GetMap()->IsBattlegroundOrArena())
            return;

        FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
        {
            BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
            Battleground* bg = bgMap ? bgMap->GetBG() : nullptr;

            ObjectGuid killerGuid = ResolveAttackerGuid(killer);

            for (ObjectGuid const& tapperGuid : bgData->damageTappers)
            {
                if (tapperGuid == killerGuid)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*bot, killerGuid))
                    {
                        if (bg)
                        {
                            bg->UpdatePlayerScore(player, SCORE_KILLING_BLOWS, 1);
                            bg->UpdatePlayerScore(player, SCORE_HONORABLE_KILLS, 1);
                        }
                    }
                    else if (Creature* botKiller = ObjectAccessor::GetCreature(*bot, killerGuid))
                    {
                        if (botKiller->IsBot())
                        {
                            bool alreadyAwarded = (killer && killer->ToCreature() && killer->ToCreature()->IsBot() && killer->GetGUID() == killerGuid);
                            if (!alreadyAwarded)
                                ScriptHelpers::RecordBotKillingBlow(botKiller->GetGUID());
                        }
                    }
                }
                else
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*bot, tapperGuid))
                    {
                        if (bg)
                            bg->UpdatePlayerScore(player, SCORE_HONORABLE_KILLS, 1);
                    }
                    else if (Creature* botAlly = ObjectAccessor::GetCreature(*bot, tapperGuid))
                    {
                        if (botAlly->IsBot())
                            ScriptHelpers::RecordBotHonorableKill(botAlly->GetGUID());
                    }
                }
            }

            bgData->damageTappers.clear();
            bgData->recentPlayerTargets.clear();
        }

        ScriptHelpers::RecordBotDeath(bot->GetGUID());
    }

    void HandleBotDamageTaken(Creature* bot, Unit* attacker, uint32 damage)
    {
        if (!bot || !bot->GetMap()->IsBattlegroundOrArena() || !attacker)
            return;

        if (attacker->GetTypeId() == TYPEID_PLAYER)
            HandlePlayerDamagedBot(attacker, bot, damage);

        FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
        {
            ObjectGuid attackerGuid = ResolveAttackerGuid(attacker);
            if (!attackerGuid.IsEmpty())
                bgData->damageTappers.insert(attackerGuid);
        }
    }

    std::unordered_map<BattlegroundMap*, std::vector<ObjectGuid>> SpawnedBotGuids;

    void AddBotSpawnGuid(BattlegroundMap* battlegroundMap, ObjectGuid guid)
    {
        SpawnedBotGuids[battlegroundMap].push_back(guid);
    }

    void ClearSpawnedBotGuids(BattlegroundMap* battlegroundMap)
    {
        SpawnedBotGuids.erase(battlegroundMap);
    }

    uint32 CountExistingBots(Battleground* battleground, Team team)
    {
        BattlegroundMap* bgMap = battleground->GetBgMap();
        if (!bgMap)
            return 0;

        uint32 count = 0;
        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot())
                continue;

            FSB_Race race = FSBMgr::Get()->GetBotRaceForEntry(creature->GetEntry());
            if (FSBUtils::GetTeamFromFSBRace(race) == team)
                ++count;
        }

        return count;
    }

    std::vector<Creature*> CollectBotsOnTeam(BattlegroundMap* battlegroundMap, Team team)
    {
        std::vector<Creature*> bots;
        if (!battlegroundMap)
            return bots;

        for (auto const& [guid, creature] : battlegroundMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot())
                continue;

            FSB_Race race = FSBMgr::Get()->GetBotRaceForEntry(creature->GetEntry());
            if (FSBUtils::GetTeamFromFSBRace(race) != team)
                continue;

            // Skip bots that would produce malformed roster/member-state packets.
            if (creature->GetGUID().IsEmpty() || creature->GetName().empty())
            {
                TC_LOG_WARN("scripts.fsb.battleground", "FSBBattleground::CollectBotsOnTeam: skipping bot entry {} with empty GUID or name", creature->GetEntry());
                continue;
            }

            FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(creature->GetEntry());
            if (FSBUtils::BotRaceToTC(race) == RACE_NONE || FSBUtils::FSBToTCClass(botClass) == CLASS_NONE)
            {
                TC_LOG_WARN("scripts.fsb.battleground", "FSBBattleground::CollectBotsOnTeam: skipping bot entry {} with invalid race/class mapping", creature->GetEntry());
                continue;
            }

            bots.push_back(creature);

            // Defensive cap: a client raid roster cannot exceed MAX_RAID_SIZE members.
            if (bots.size() >= MAX_RAID_SIZE)
                break;
        }

        return bots;
    }

    std::vector<uint32> SelectRandomEntries(std::vector<uint32>& entries, uint32 count)
    {
        std::shuffle(entries.begin(), entries.end(), std::mt19937(std::random_device{}()));
        if (count > entries.size())
            count = static_cast<uint32>(entries.size());

        return std::vector<uint32>(entries.begin(), entries.begin() + count);
    }

    std::vector<ObjectGuid> const& GetSpawnedBotGuids(BattlegroundMap* battlegroundMap)
    {
        static std::vector<ObjectGuid> const empty;
        auto it = SpawnedBotGuids.find(battlegroundMap);
        return it != SpawnedBotGuids.end() ? it->second : empty;
    }

    Unit* FindFriendlyAssistTarget(Creature* bot, float range)
    {
        if (!bot)
            return nullptr;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return nullptr;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return nullptr;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return nullptr;

        Unit* bestVictim = nullptr;
        float bestDistance = range;

        // Friendly players
        for (auto const& [guid, bgPlayer] : bg->GetPlayers())
        {
            if (bgPlayer.Team != botTeam)
                continue;

            Player* player = ObjectAccessor::GetPlayer(bgMap, guid);
            if (!player)
                continue;

            float distance = bot->GetDistance(player);
            if (distance >= bestDistance)
                continue;

            Unit* victim = player->GetVictim();
            if (!victim || !FSBCombat::BotCanAttack(bot, victim))
                continue;

            bestVictim = victim;
            bestDistance = distance;
        }

        // Friendly bots
        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot() || creature == bot)
                continue;

            auto baseAI = dynamic_cast<FSB_BaseAI*>(creature->AI());
            if (!baseAI || baseAI->botHired)
                continue;

            Team creatureTeam = FSBUtils::GetTeamFromFSBRace(baseAI->botRace);
            if (creatureTeam != botTeam)
                continue;

            float distance = bot->GetDistance(creature);
            if (distance >= bestDistance)
                continue;

            Unit* victim = creature->GetVictim();
            if (!victim || !FSBCombat::BotCanAttack(bot, victim))
                continue;

            bestVictim = victim;
            bestDistance = distance;
        }

        return bestVictim;
    }

    Unit* FindBattlegroundAllyToHeal(Creature* bot, float range, float lowHpPct)
    {
        if (!bot || !bot->IsAlive() || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return nullptr;

        if (!IsInBG(bot) || !IsInProgress(bot))
            return nullptr;

        Team botTeam = GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return nullptr;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return nullptr;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return nullptr;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return nullptr;

        auto const& groupGuids = baseAI->botLogicalGroup;
        auto isInGroup = [&](ObjectGuid const& guid) -> bool
        {
            return std::find(groupGuids.begin(), groupGuids.end(), guid) != groupGuids.end();
        };

        std::vector<Unit*> candidates;

        // Friendly players
        for (auto const& [guid, bgPlayer] : bg->GetPlayers())
        {
            if (bgPlayer.Team != botTeam)
                continue;

            if (isInGroup(guid))
                continue;

            Player* player = ObjectAccessor::GetPlayer(bgMap, guid);
            if (!player || !player->IsAlive() || !player->IsInWorld() || player->IsDuringRemoveFromWorld())
                continue;

            if (bot->GetDistance(player) > range)
                continue;

            if (player->GetHealthPct() > lowHpPct)
                continue;

            candidates.push_back(player);
        }

        // Friendly bots
        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot() || creature == bot)
                continue;

            if (creature->GetGUID().IsEmpty() || creature->GetName().empty())
                continue;

            Team creatureTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(creature->GetEntry()));
            if (creatureTeam != botTeam)
                continue;

            if (isInGroup(creature->GetGUID()))
                continue;

            if (!creature->IsAlive() || !creature->IsInWorld() || creature->IsDuringRemoveFromWorld())
                continue;

            if (bot->GetDistance(creature) > range)
                continue;

            if (creature->GetHealthPct() > lowHpPct)
                continue;

            candidates.push_back(creature);
        }

        if (candidates.empty())
            return nullptr;

        FSBGroup::SortEmergencyTargets(candidates);
        return candidates.front();
    }

    Unit* FindHostileTargetInBattleground(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return nullptr;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return nullptr;

        Battleground* bg = bgMap->GetBG();
        if (!bg || bg->GetStatus() != STATUS_IN_PROGRESS)
            return nullptr;

        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
        Team botTeam = FSBUtils::GetTeamFromFSBRace(botRace);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return nullptr;

        uint32 bgTypeId = bg->GetTypeID();
        bool isCtf = (bgTypeId == BATTLEGROUND_WS || bgTypeId == BATTLEGROUND_WG_CTF);

        bool isCarrier = false;
        if (isCtf)
        {
            isCarrier = bot->HasAura(WarsongGulch::Spells::WarsongFlag) ||
                        bot->HasAura(WarsongGulch::Spells::SilverwingFlag) ||
                        bot->HasAura(WarsongGulch::Spells::AllianceFlag) ||
                        bot->HasAura(WarsongGulch::Spells::HordeFlag);
        }

        float scanRange = 50.0f;
        if (isCarrier)
            scanRange = 20.0f;
        else if (isCtf)
        {
            if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
                if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
                    if (bgData->wsgState == WarsongGulch::WSGState::ProtectCarrier)
                        scanRange = 20.0f;
        }

        struct Candidate
        {
            Unit* target;
            bool isFlagCarrier;
            float healthPct;
            float distance;
        };

        std::vector<Candidate> candidates;

        auto isValidTarget = [&](Unit* target) -> bool
        {
            if (!target || !target->IsAlive() || !target->IsInWorld() || target->IsDuringRemoveFromWorld())
                return false;

            if (!bot->IsWithinDistInMap(target, scanRange))
                return false;

            if (!bot->IsValidAttackTarget(target))
                return false;

            if (target->HasBreakableByDamageCrowdControlAura())
                return false;

            if (target->HasUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC) ||
                target->HasUnitFlag(UNIT_FLAG_UNINTERACTIBLE) ||
                target->HasUnitFlag(UNIT_FLAG_PACIFIED) ||
                target->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
                return false;

            return true;
        };

        // Hostile players
        for (auto const& [guid, bgPlayer] : bg->GetPlayers())
        {
            if (bgPlayer.Team == botTeam)
                continue;

            Player* player = ObjectAccessor::GetPlayer(bgMap, guid);
            if (!player)
                continue;

            if (!isValidTarget(player))
                continue;

            bool isFlagCarrier = false;
            if (isCtf)
                isFlagCarrier = player->HasAura(WarsongGulch::Spells::WarsongFlag) ||
                                player->HasAura(WarsongGulch::Spells::SilverwingFlag) ||
                                player->HasAura(WarsongGulch::Spells::AllianceFlag) ||
                                    player->HasAura(WarsongGulch::Spells::HordeFlag);

            candidates.push_back({ player, isFlagCarrier, player->GetHealthPct(), bot->GetDistance(player) });
        }

        // Hostile bots
        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot())
                continue;

            Team creatureTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(creature->GetEntry()));
            if (creatureTeam == botTeam)
                continue;

            if (!isValidTarget(creature))
                continue;

            bool isFlagCarrier = false;
            if (isCtf)
                isFlagCarrier = creature->HasAura(WarsongGulch::Spells::WarsongFlag) ||
                                creature->HasAura(WarsongGulch::Spells::SilverwingFlag) ||
                                creature->HasAura(WarsongGulch::Spells::AllianceFlag) ||
                                creature->HasAura(WarsongGulch::Spells::HordeFlag);

            candidates.push_back({ creature, isFlagCarrier, creature->GetHealthPct(), bot->GetDistance(creature) });
        }

        if (candidates.empty())
            return nullptr;

        auto best = std::min_element(candidates.begin(), candidates.end(),
            [](Candidate const& a, Candidate const& b)
        {
            if (a.isFlagCarrier != b.isFlagCarrier)
                return a.isFlagCarrier;
            if (a.healthPct != b.healthPct)
                return a.healthPct < b.healthPct;
            return a.distance < b.distance;
        });

        TC_LOG_DEBUG("scripts.fsb.combat", "FSBBattleground::FindHostileTargetInBattleground: Bot {} selected target {} (flagCarrier={}, healthPct={}, distance={})",
            bot->GetName(), best->target->GetName(), best->isFlagCarrier, best->healthPct, best->distance);

        return best->target;
    }
}
