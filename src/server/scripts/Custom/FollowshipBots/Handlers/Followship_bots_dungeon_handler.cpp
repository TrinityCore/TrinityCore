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

#include "Log.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Unit.h"
#include "Vehicle.h"

#include "Followship_bots_defines.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_dungeon_deadmines.h"
#include "Followship_bots_combat_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_ai_base.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_death_handler.h"
#include "Followship_bots_movement_handler.h"

#include "Custom_Instance_Deadmines.h"

using namespace FSBUtils;
using namespace FSBGroup;

namespace DM = Scripts::EasternKingdoms::Deadmines;

FSB_DungeonData* FSB_BaseAI::GetDungeonData()
{
    if (!botDungeonData)
        botDungeonData = new FSB_DungeonData();
    return botDungeonData;
}

namespace FSBDungeon
{
    // This is the entry point from Periodic Maintence in UpdateAI
    void CheckDungeonHandlingNeeded(Creature* bot)
    {
        if (!bot)
            return;

        if (!FSBDungeon::IsBotInDungeon(bot))
            return;

        // Dungeon-specific OOC handling
        switch (bot->GetMapId())
        {
        case Maps::Deadmines:
            FSBDeadmines::HandleOutOfCombat(bot);
            break;
        default:
            break;
        }

        // If no dungeon encounter is active, ensure bot resumes follow
        if (FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        {
            if (baseAI->botDungeonData && baseAI->botDungeonData->activeEncounterId == 0)
                FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
        }
    }

    // This is the entry point from ICActions (Main actions during combat state)
    bool CheckDungeonInCombatHandlingNeeded(Creature* bot)
    {
        if (!bot)
            return false;

        if (!FSBDungeon::IsBotInDungeon(bot))
            return false;

        // Check and maintain distance from boss/units in dungeons (for casters)
        Unit* target = bot->GetVictim();
        if (target && target->IsAlive())
        {
            if (FSBUtils::BotIsCasterRole(bot))
            {
                uint32 targetEntry = target->GetEntry();
                if (targetEntry)
                {
                    float targetMinDistance = FSBDungeon::GetDungeonBossMinDistance(targetEntry);

                    bool needsDistance = FSBDungeon::ShouldMaintainBossDistance(bot, target, targetMinDistance);

                    if (needsDistance)
                    {
                        bot->GetMotionMaster()->Clear();
                        bot->GetMotionMaster()->MoveChase(target, ChaseRange(targetMinDistance, FSBCombatUtils::GetBotChaseDistance(bot)));
                        return false;
                    }
                }
            }

            // Dungeon-specific encounter dispatch
            switch (bot->GetMapId())
            {
            case Maps::Deadmines:
                if (FSBDeadmines::Handle(bot, target))
                    return true;
                break;
            default:
                break;
            }

            return false;
        }

        return false;
    }

    uint32 GetBotDungeonId(Creature* bot)
    {
        if (!bot)
            return 0;

        if (bot->GetMap()->IsDungeon())
            return bot->GetMapId();

        return 0;
    }

    void UpdateBotDungeonId(Creature* bot)
    {
        if (!bot)
            return;

        uint32 dungeonId = GetBotDungeonId(bot);

        if (FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        {
            uint32 oldDungeonId = baseAI->DungeonID;
            baseAI->DungeonID = dungeonId;

            if (oldDungeonId != dungeonId)
                TC_LOG_DEBUG("scripts.fsb.dungeon", "FSB: Bot {} dungeon ID updated from {} to {}", 
                    bot->GetName(), oldDungeonId, dungeonId);
        }
    }

    bool IsBotInDungeon(Creature* bot)
    {
        return GetBotDungeonId(bot) != 0;
    }

    bool ShouldPreserveMana(Creature* bot)
    {
        if (!bot)
            return false;

        if (!FSBUtils::BotIsHealerClass(bot))
            return false;

        if (!IsBotInDungeon(bot))
            return false;

        if (bot->GetPowerType() != POWER_MANA)
            return false;

        float manaPct = (float)bot->GetPower(POWER_MANA) / (float)bot->GetMaxPower(POWER_MANA) * 100.0f;
        return manaPct < 70.0f;
    }

    bool IsTargetBoss(Creature* bot, Unit* target)
    {
        if (!bot || !target)
            return false;

        if (!target->ToCreature())
            return false;

        uint32 dungeonId = GetBotDungeonId(bot);
        if (dungeonId == 0)
            return false;

        uint32 targetEntry = target->GetEntry();

        if (dungeonId == Maps::Deadmines)
        {
            for (uint32 bossId : FSBDeadmines::BossIds)
                if (targetEntry == bossId)
                    return true;
        }

        return false;
    }

    bool ShouldDPSInExecutePhase(Creature* bot, Unit* target)
    {
        if (!bot || !target)
            return false;

        if (!FSBUtils::BotIsHealerClass(bot))
            return false;

        if (!IsBotInDungeon(bot))
            return false;

        if (!IsTargetBoss(bot, target))
            return false;

        if (!FSBGroup::BotGroupIsHealthy_Average(bot, 50))
            return false;

        float bossHpPct = target->GetHealthPct();
        return bossHpPct < 15.0f;
    }

    bool ShouldMaintainBossDistance(Creature* bot, Unit* target, float minDistance)
    {
        if (!bot || !target)
            return false;

        if (!IsTargetBoss(bot, target))
            return false;

        // GetDistance() subtracts both units' combat reach which makes large bosses trigger this from way too far
        float distance = bot->GetExactDist(target);
        return distance < minDistance;
    }

    float GetDungeonBossMinDistance(uint32 bossEntry)
    {
        if (!bossEntry)
            return DungeonBossMinDistance;

        switch (bossEntry)
        {
        case DM::Creatures::FoeReaper5000:
            return FSBDeadmines::Encounters::FoeReaper5000MinDistance;
        default:
            break;
        }

        return DungeonBossMinDistance;
    }

    Unit* GetDungeonTargetOverride(Creature* bot, Unit* target)
    {
        if (!bot || !target)
            return nullptr;

        if (!IsBotInDungeon(bot))
            return nullptr;

        uint32 mapId = GetBotDungeonId(bot);
        switch (mapId)
        {
            case Maps::Deadmines:
            {
                // Override for Glubtok blossom adds
                if (target->GetEntry() == DM::Creatures::Glubtok)
                {
                    Unit* blossom = nullptr;
                    if (Creature* frostBlossom = target->FindNearestCreature(DM::Creatures::FrostBlossom, 30.0f))
                    {
                        if (frostBlossom->IsAlive() && bot->IsValidAttackTarget(frostBlossom))
                            blossom = frostBlossom;
                    }
                    else if (Creature* fireBlossom = target->FindNearestCreature(DM::Creatures::FireBlossom, 30.0f))
                        if (fireBlossom->IsAlive() && bot->IsValidAttackTarget(fireBlossom))
                            blossom = fireBlossom;

                    return blossom;
                }
                // Override for Admiral Ripsnarl adds
                if (target->GetEntry() == DM::Creatures::AdmiralRipsnarl)
                {

                    InstanceScript* instance = bot->GetInstanceScript();
                    if (!instance)
                        return nullptr;

                    // Fog phase active -> redirect to vapors
                    if (instance->GetData(DM::Misc::RipsnarlFogActive) != 0)
                    {
                        if (Creature* vapor = target->FindNearestCreature(
                            DM::Creatures::Vapor, 100.0f))
                        {
                            if (vapor->IsAlive() && bot->IsValidAttackTarget(vapor))
                                return vapor;
                        }
                    }
                }
                break;
            }
            default:
                break;
        }

        return nullptr;
    }

    void CheckAndQueueDeadUnits(Creature* bot, float searchRange)
    {
        if (!bot || !bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        // Check if bot is a resurrect-capable class (healer class)
        if (!BotIsHealerClass(bot))
            return;

        auto& resurrectQueue = baseAI->botResurrectQueue;

        // Build logical bot group (owner, bot, and other bots owned by same player)
        auto group = ResolveGroup(bot, baseAI->botLogicalGroup, false);
        if (group.empty())
            return;

        for (Unit* unit : group)
        {
            if (!unit || unit->IsAlive())
                continue;

            if (bot->GetDistance(unit) > searchRange)
                continue;

            // Check if already in queue
            bool alreadyInQueue = false;
            std::queue<ObjectGuid> tempQueue = resurrectQueue;
            while (!tempQueue.empty())
            {
                if (tempQueue.front() == unit->GetGUID())
                {
                    alreadyInQueue = true;
                    break;
                }
                tempQueue.pop();
            }

            if (alreadyInQueue)
                continue;

            // Add to resurrect queue
            FSBDeath::AddToHealerResurrectQueue(unit, bot);
            TC_LOG_DEBUG("scripts.fsb.dungeon", "FSB: CheckAndQueueDeadUnits Bot {} added dead unit {} to resurrect queue", bot->GetName(), unit->GetName());
        }
    }
}

