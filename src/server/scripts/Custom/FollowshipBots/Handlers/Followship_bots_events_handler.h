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

#include "Followship_bots_defines.h"

enum FSB_BOT_EVENTS
{
    FSB_EVENT_HIRED_MOUNT_AURA = 1,
    FSB_EVENT_HIRED_RESURRECT_TARGET,
    FSB_EVENT_HIRED_RESUME_FOLLOW,
    FSB_EVENT_DESPAWN_TEMP_BOT,
    FSB_EVENT_HIRED_DESPAWN_TEMP_BOT,
    FSB_EVENT_HIRED_SPELL_RESURRECT_STATE,
    FSB_EVENT_HIRED_TIMED_CHATTER_REPLY,
    FSB_EVENT_HIRED_TIMED_DUMMY_EMOTE,
    FSB_EVENT_HIRED_EXPIRED,
    FSB_EVENT_HIRED_LEAVE,

    // Generic periodic checks for non / hired bots
    FSB_EVENT_GENERIC_MAINTENANCE,
    FSB_EVENT_GENERIC_PET_TELEPORT,
    FSB_EVENT_GENERIC_TELEPORT_GRAVEYARD,
    FSB_EVENT_GENERIC_GRAVEYARD_RESSURECT,
    FSB_EVENT_GENERIC_CHECK_HIRED_TIME,

    FSB_EVENT_BATTLEGROUND_TELEPORT_GRAVEYARD,
    FSB_EVENT_BATTLEGROUND_GRAVEYARD_RESSURECT,
    FSB_EVENT_BATTLEGROUND_START,
    FSB_EVENT_BATTLEGROUND_TICK,
    FSB_EVENT_BATTLEGROUND_SPAWN_CHAT,
    FSB_EVENT_WSG_USE_FLAG,
    FSB_EVENT_WSG_USE_DROPPED_FLAG,
    FSB_EVENT_WSG_BOT_CAPTURE,
    FSB_EVENT_BATTLEGROUND_STATE_CHAT,
    FSB_EVENT_WSG_REROLL_STATE,
    FSB_EVENT_AB_CHECK_CAPTURE,
    FSB_EVENT_AB_REROLL_STATE,

    FSB_EVENT_ARENA_START,
    FSB_EVENT_ARENA_TICK,

    FSB_EVENT_RANDOM_ACTION_SIT_BY_FIRE,
    FSB_EVENT_RANDOM_ACTION_MOVE_FIRE,
    FSB_EVENT_RANDOM_ACTION_FINISH,
    FSB_EVENT_DUNGEON_STATS_RECALCULATE,
    FSB_EVENT_DUNGEON_CHECK_DEAD_UNITS,
    FSB_EVENT_DEADMINES_CHECK_PROTOTYPE_REAPER,
    FSB_EVENT_RECOVERY_END,
};

namespace FSBEvents
{
    // Dungeon Events
    static constexpr int8 EVENT_DM_ENTER_PROTOTYPE_REAPER = 100;
    static constexpr int8 EVENT_DM_REAPER_STRIKE = 101;
    static constexpr int8 EVENT_DM_PRESSURIZED_STRIKE = 102;
    static constexpr int8 EVENT_DM_VEHICLE_COMBAT_CHECK = 103;
    static constexpr int8 EVENT_DM_COOKIE_FOOD_CYCLE = 104;

    // Wrapper for scheduling a bot event directly from Creature*
    void ScheduleBotEvent(Creature* bot, uint32 eventId, std::chrono::milliseconds minTime, std::chrono::milliseconds maxTime = std::chrono::milliseconds(0));
    void ScheduleBotEventWithChatter(Creature* bot, uint32 eventId, std::chrono::milliseconds minTime, std::chrono::milliseconds maxTime, FSB_ReplyType replyType, std::string chatterReply, Unit* target);
}
