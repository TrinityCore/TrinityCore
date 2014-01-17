/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Battleground.h"

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

enum BattlegroundDSObjects
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
    BG_DS_SPELL_WATER_SPOUT       = 58873  // Knockback effect of the central waterfall
};

enum BattlegroundDSData
{ // These values are NOT blizzlike... need the correct data!
    BG_DS_WATERFALL_TIMER_MIN                    = 30000,
    BG_DS_WATERFALL_TIMER_MAX                    = 60000,
    BG_DS_WATERFALL_WARNING_DURATION             = 5000,
    BG_DS_WATERFALL_DURATION                     = 30000,
    BG_DS_WATERFALL_KNOCKBACK_TIMER              = 1500,

    BG_DS_PIPE_KNOCKBACK_FIRST_DELAY             = 5000,
    BG_DS_PIPE_KNOCKBACK_DELAY                   = 3000,
    BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT             = 2,

    BG_DS_WATERFALL_STATUS_WARNING               = 1, // Water starting to fall, but no LoS Blocking nor movement blocking
    BG_DS_WATERFALL_STATUS_ON                    = 2, // LoS and Movement blocking active
    BG_DS_WATERFALL_STATUS_OFF                   = 3
};

class BattlegroundDS : public Battleground
{
    public:
        BattlegroundDS();
        ~BattlegroundDS();

        /* inherited from BattlegroundClass */
        void AddPlayer(Player* player);
        void StartingEventCloseDoors();
        void StartingEventOpenDoors();

        void RemovePlayer(Player* player, uint64 guid, uint32 team);
        void HandleAreaTrigger(Player* Source, uint32 Trigger);
        bool SetupBattleground();
        void Reset();
        void FillInitialWorldStates(WorldPacket &d);
        void HandleKillPlayer(Player* player, Player* killer);
    private:
        uint32 _waterfallTimer;
        uint8 _waterfallStatus;
        uint32 _waterfallKnockbackTimer;
        uint32 _pipeKnockBackTimer;
        uint8 _pipeKnockBackCount;

        void PostUpdateImpl(uint32 diff);
    protected:
        uint32 getWaterFallStatus() { return _waterfallStatus; }
        void setWaterFallStatus(uint8 status) { _waterfallStatus = status; }
        uint32 getWaterFallTimer() { return _waterfallTimer; }
        void setWaterFallTimer(uint32 timer) { _waterfallTimer = timer; }
        uint32 getWaterFallKnockbackTimer() { return _waterfallKnockbackTimer; }
        void setWaterFallKnockbackTimer(uint32 timer) { _waterfallKnockbackTimer = timer; }
        uint8 getPipeKnockBackCount() { return _pipeKnockBackCount; }
        void setPipeKnockBackCount(uint8 count) { _pipeKnockBackCount = count; }
        uint32 getPipeKnockBackTimer() { return _pipeKnockBackTimer; }
        void setPipeKnockBackTimer(uint32 timer) { _pipeKnockBackTimer = timer; }
};
#endif
