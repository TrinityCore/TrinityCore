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

#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptHelpers.h"
#include "ScriptMgr.h"

class followship_bots_battleground_player : public PlayerScript
{
public:
    followship_bots_battleground_player() : PlayerScript("followship_bots_battleground_player") { }

    void OnMapChanged(Player* player) override
    {
        TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: OnMapChanged for player {} map {}", player->GetName(), player->GetMapId());

        if (!sBattlegroundMgr->IsFSBOverrideEnabled())
        {
            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: FSB override not enabled, aborting spawn");
            return;
        }

        BattlegroundMap* battlegroundMap = player->GetMap()->ToBattlegroundMap();
        if (!battlegroundMap)
        {
            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: Not a battleground map, aborting spawn");
            return;
        }

        Battleground* battleground = battlegroundMap->GetBG();
        if (!battleground)
        {
            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: No battleground instance, aborting spawn");
            return;
        }

        BattlegroundScript* script = battlegroundMap->GetBattlegroundScript();
        if (!script)
        {
            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: No battleground script, aborting spawn");
            return;
        }

        if (script->GetData(FSBBattleground::BotsSpawnedDataId) != 0)
        {
            TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: Bots already spawned for this BG, aborting");
            return;
        }

        TC_LOG_INFO("scripts.fsb.battleground", "FSB BG Player: Spawning bots for BG type {}", battleground->GetTypeID());
        script->SetData(FSBBattleground::BotsSpawnedDataId, 1);
        FSBBattleground::SpawnBots(battleground, battlegroundMap, player);
    }

    void OnPlayerKilledByCreature(Creature* killer, Player* killed) override
    {
        if (!killer || !killed)
            return;

        BattlegroundMap* bgMap = killed->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        ObjectGuid killingBotGuid = FSBBattleground::ResolveAttackerGuid(killer);

        if (!killer->IsBot() && !killingBotGuid.IsEmpty())
        {
            if (Creature* killingBot = ObjectAccessor::GetCreature(*killed, killingBotGuid))
            {
                if (killingBot->IsBot())
                {
                    FSBBattleground::HandleBotKilledPlayer(killingBot, killed->GetGUID());
                    ScriptHelpers::RecordBotKillingBlow(killingBot->GetGUID());
                }
            }
        }

        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot() || creature->GetGUID() == killingBotGuid)
                continue;

            FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(creature->AI());
            if (!baseAI)
                continue;

            FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData();
            if (!bgData)
                continue;

            if (bgData->recentPlayerTargets.find(killed->GetGUID()) == bgData->recentPlayerTargets.end())
                continue;

            if (!creature->IsInCombat())
                continue;

            if (creature->GetDistance(killed) > 50.0f)
                continue;

            ScriptHelpers::RecordBotHonorableKill(creature->GetGUID());
        }

        // Remove the killed player from all bots' recent targets so the same death isn't credited again
        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot())
                continue;

            if (FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(creature->AI()))
                if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
                    bgData->recentPlayerTargets.erase(killed->GetGUID());
        }
    }
};

void AddSC_followship_bots_battleground_player()
{
    new followship_bots_battleground_player();
}
