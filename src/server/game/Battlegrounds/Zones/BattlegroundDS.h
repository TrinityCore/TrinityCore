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

#ifndef __BATTLEGROUNDDS_H
#define __BATTLEGROUNDDS_H

#include "Arena.h"
#include "EventMap.h"

enum BattlegroundDSObjectTypes
{
    BG_DS_OBJECT_DOOR_1         = 0,
    BG_DS_OBJECT_DOOR_2         = 1,
    BG_DS_OBJECT_WATER_1        = 2, // Collision
    BG_DS_OBJECT_WATER_2        = 3,
    BG_DS_OBJECT_BUFF_1         = 4,
    BG_DS_OBJECT_BUFF_2         = 5,
    BG_DS_OBJECT_MAX            = 6
};

enum BattlegroundDSGameObjects
{
    BG_DS_OBJECT_TYPE_DOOR_1    = 192642,
    BG_DS_OBJECT_TYPE_DOOR_2    = 192643,
    BG_DS_OBJECT_TYPE_WATER_1   = 194395, // Collision
    BG_DS_OBJECT_TYPE_WATER_2   = 191877,
    BG_DS_OBJECT_TYPE_BUFF_1    = 184663,
    BG_DS_OBJECT_TYPE_BUFF_2    = 184664
};

enum BattlegroundDSCreatureTypes
{
    BG_DS_NPC_WATERFALL_KNOCKBACK = 0,
    BG_DS_NPC_PIPE_KNOCKBACK_1    = 1,
    BG_DS_NPC_PIPE_KNOCKBACK_2    = 2,
    BG_DS_NPC_MAX                 = 3
};

enum BattlegroundDSCreatures
{
    BG_DS_NPC_TYPE_WATER_SPOUT    = 28567
};

enum BattlegroundDSSpells
{
    BG_DS_SPELL_FLUSH             = 57405, // Visual and target selector for the starting knockback from the pipe
    BG_DS_SPELL_FLUSH_KNOCKBACK   = 61698, // Knockback effect for previous spell (triggered, not needed to be cast)
    BG_DS_SPELL_WATER_SPOUT       = 58873, // Knockback effect of the central waterfall

    SPELL_WARL_DEMONIC_CIRCLE     = 48018  // Demonic Circle Summon
};

enum BattlegroundDSData
{
    // These values are NOT blizzlike... need the correct data!
    BG_DS_WATERFALL_TIMER_MIN           = 30000,
    BG_DS_WATERFALL_TIMER_MAX           = 60000,
    BG_DS_WATERFALL_WARNING_DURATION    = 5000,
    BG_DS_WATERFALL_DURATION            = 30000,
    BG_DS_WATERFALL_KNOCKBACK_TIMER     = 1500,

    BG_DS_PIPE_KNOCKBACK_FIRST_DELAY    = 5000,
    BG_DS_PIPE_KNOCKBACK_DELAY          = 3000,
    BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT    = 2,
};

enum BattlegroundDSEvents
{
    BG_DS_EVENT_WATERFALL_WARNING       = 1, // Water starting to fall, but no LoS Blocking nor movement blocking
    BG_DS_EVENT_WATERFALL_ON            = 2, // LoS and Movement blocking active
    BG_DS_EVENT_WATERFALL_OFF           = 3,
    BG_DS_EVENT_WATERFALL_KNOCKBACK     = 4,

    BG_DS_EVENT_PIPE_KNOCKBACK          = 5
};

class BattlegroundDS : public Arena
{
    public:
        BattlegroundDS(BattlegroundTemplate const* battlegroundTemplate);

        /* inherited from BattlegroundClass */
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;

        void HandleAreaTrigger(Player* source, uint32 trigger, bool entered) override;
        bool SetupBattleground() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;

    private:
        void PostUpdateImpl(uint32 diff) override;

        EventMap _events;

        uint32 _pipeKnockBackTimer;
        uint8 _pipeKnockBackCount;
};

#endif
