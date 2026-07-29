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

#include "Followship_bots_arena.h"

#include "Battleground.h"
#include "Creature.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Random.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_combat_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_utils.h"

namespace FSBBattleground::Arena
{
    void InitializeArenaBot(Creature* bot, FSB_BattlegroundData* bgData, Battleground* bg)
    {
        if (!bot || !bgData || !bg)
            return;

        Milliseconds delay = FSBBattleground::IsInProgress(bot) ? 100ms : 1min;
        FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_ARENA_START, delay);
    }

    void HandleArenaStart(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        if (Unit* target = FindArenaTarget(bot, ARENA_TARGET_SCAN_RADIUS))
        {
            FSBCombat::BotDoAttack(bot, target);
            TC_LOG_DEBUG("scripts.fsb.arena", "FSB Arena: Bot {} acquired target {} at start", bot->GetName(), target->GetName());
        }
        else
            TC_LOG_DEBUG("scripts.fsb.arena", "FSB Arena: Bot {} found no targets within {}f at start", bot->GetName(), ARENA_TARGET_SCAN_RADIUS);
    }

    void HandleArenaTick(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        if (!bot->IsInCombat())
            return;

        IssueRandomMovement(bot);
    }

    Unit* FindArenaTarget(Creature* bot, float range)
    {
        if (!bot || !bot->IsAlive())
            return nullptr;

        return bot->SelectNearestTarget(range);
    }

    void IssueRandomMovement(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        float angle = frand(0.0f, 2.0f * float(M_PI));
        float dist = frand(ARENA_RANDOM_MOVE_MIN, ARENA_RANDOM_MOVE_MAX);
        Position dest = bot->GetFirstCollisionPosition(dist, angle);

        float actualDist = bot->GetExactDist2d(dest.GetPositionX(), dest.GetPositionY());
        int32 retries = 0;
        while (actualDist < ARENA_MOVE_MIN_VALID_DIST && retries < ARENA_MOVE_MAX_RETRIES)
        {
            angle = frand(0.0f, 2.0f * float(M_PI));
            dist = frand(ARENA_RANDOM_MOVE_MIN, ARENA_RANDOM_MOVE_MAX);
            dest = bot->GetFirstCollisionPosition(dist, angle);
            actualDist = bot->GetExactDist2d(dest.GetPositionX(), dest.GetPositionY());
            ++retries;
        }

        if (actualDist < ARENA_MOVE_MIN_VALID_DIST)
            return;

        baseAI->botGenericData.pauseCombatChase = true;
        bot->GetMotionMaster()->Clear();

        bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_ARENA_ROAM, dest, true);
        TC_LOG_DEBUG("scripts.fsb.arena", "FSB Arena: Bot {} issued random movement to ({}, {}, {}), dist={}",
            bot->GetName(), dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), actualDist);

        bot->m_Events.AddEventAtOffset([bot, baseAI]()
        {
            if (bot && bot->IsInWorld() && bot->IsAlive())
                baseAI->botGenericData.pauseCombatChase = false;
        }, 5s);
    }
}
