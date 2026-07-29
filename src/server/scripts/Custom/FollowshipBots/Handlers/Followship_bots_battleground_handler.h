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

#include "Define.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include <string>
#include <vector>

#include "Followship_bots_arathi_basin.h"
#include "Followship_bots_warsong_gulch.h"
#include "Followship_bots_arena.h"
#include "Chat/Followship_bots_chat_battleground.h"

class Battleground;
class BattlegroundMap;
class Creature;
class Player;
class Unit;

struct FSB_BattlegroundData
{
    bool initialized = false;
    uint32 bgTypeId = 0;
    FSBBattleground::WarsongGulch::WSGState wsgState = FSBBattleground::WarsongGulch::WSGState::None;
    FSBBattleground::WarsongGulch::WSGMovePhase wsgMovePhase = FSBBattleground::WarsongGulch::WSGMovePhase::None;
    uint8 wsgPathIndex = 0;
    uint8 wsgPathStep = 0;
    FSBBattleground::WarsongGulch::WSGPathChoice wsgExitPathChoice = FSBBattleground::WarsongGulch::WSGPathChoice::BaseExit;
    uint8 wsgCenterIndex = 0;
    bool wsgCapturePending = false;
    FSBBattleground::ArathiBasin::ABState abState = FSBBattleground::ArathiBasin::ABState::None;
    uint32 abCaptureTimer = 0;
    GuidUnorderedSet damageTappers;
    GuidUnorderedSet recentPlayerTargets;

    void Reset()
    {
        initialized = false;
        bgTypeId = 0;
        wsgState = FSBBattleground::WarsongGulch::WSGState::None;
        wsgMovePhase = FSBBattleground::WarsongGulch::WSGMovePhase::None;
        wsgPathIndex = 0;
        wsgPathStep = 0;
        wsgExitPathChoice = FSBBattleground::WarsongGulch::WSGPathChoice::BaseExit;
        wsgCenterIndex = 0;
        wsgCapturePending = false;
        abState = FSBBattleground::ArathiBasin::ABState::None;
        abCaptureTimer = 0;
        damageTappers.clear();
        recentPlayerTargets.clear();
    }
};

namespace FSBBattleground
{
    // Data index used with BattlegroundScript::GetData / SetData
    constexpr uint32 BotsSpawnedDataId = 0;
    constexpr uint32 DataCurrentBaseDefendersAlliance = 1;
    constexpr uint32 DataCurrentMiddleDefendersAlliance = 2;
    constexpr uint32 DataCurrentFlagAttackersAlliance = 3;
    constexpr uint32 DataCurrentBaseDefendersHorde = 4;
    constexpr uint32 DataCurrentMiddleDefendersHorde = 5;
    constexpr uint32 DataCurrentFlagAttackersHorde = 6;

    Team GetBotTeam(Creature* bot);
    ObjectGuid ResolveAttackerGuid(Unit* attacker);

    void SpawnBots(Battleground* battleground, BattlegroundMap* battlegroundMap, Player* triggeringPlayer = nullptr);
    void SpawnBotsForTeams(Battleground* battleground, uint32 maxTeamSize, Player* triggeringPlayer = nullptr);
    // Re-summons a bot at its team's start position when it despawns during an in-progress BG match.
    void RespawnBotOnDespawn(Creature* bot);

    bool IsInBG(Creature const* bot);
    bool IsInProgress(Creature const* bot);
    bool IsFinished(Creature const* bot);

    void InitializeBot(Creature* bot);
    void InitializeBotGeneric(Creature* bot, FSB_BattlegroundData* bgData, Battleground* bg);

    void HandlePlayerKilledBot(ObjectGuid killerGuid, Unit* botVictim);
    void HandleBotKilledPlayer(Unit* botKiller, ObjectGuid victimGuid);
    void HandlePlayerDamagedBot(Unit* attacker, Unit* botVictim, uint32 damage);
    void HandleBotDeathScores(Creature* bot, Unit* killer);
    void HandleBotDamageTaken(Creature* bot, Unit* attacker, uint32 damage);

    std::vector<ObjectGuid> const& GetSpawnedBotGuids(BattlegroundMap* battlegroundMap);
    void ClearSpawnedBotGuids(BattlegroundMap* battlegroundMap);

    void AddBotSpawnGuid(BattlegroundMap* battlegroundMap, ObjectGuid guid);
    uint32 CountExistingBots(Battleground* battleground, Team team);
    std::vector<uint32> SelectRandomEntries(std::vector<uint32>& entries, uint32 count);

    std::vector<Creature*> CollectBotsOnTeam(BattlegroundMap* battlegroundMap, Team team);

    Unit* FindHostileTargetInBattleground(Creature* bot);
    Unit* FindFriendlyAssistTarget(Creature* bot, float range);
    Unit* FindBattlegroundAllyToHeal(Creature* bot, float range, float lowHpPct);
}
