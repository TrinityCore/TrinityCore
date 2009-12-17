/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef __BATTLEGROUNDRV_H
#define __BATTLEGROUNDRV_H

class BattleGround;

enum BattleGroundRVObjectTypes
{
    BG_RV_OBJECT_BUFF_1,
    BG_RV_OBJECT_BUFF_2,
    BG_RV_OBJECT_FIRE_1,
    BG_RV_OBJECT_FIRE_2,
    BG_RV_OBJECT_FIREDOOR_1,
    BG_RV_OBJECT_FIREDOOR_2,

    BG_RV_OBJECT_PILAR_1,
    BG_RV_OBJECT_PILAR_3,
    BG_RV_OBJECT_GEAR_1,
    BG_RV_OBJECT_GEAR_2,

    BG_RV_OBJECT_PILAR_2,
    BG_RV_OBJECT_PILAR_4,
    BG_RV_OBJECT_PULLEY_1,
    BG_RV_OBJECT_PULLEY_2,
/*
    BG_RV_OBJECT_PILAR_COLLISION_1,
    BG_RV_OBJECT_PILAR_COLLISION_2,
    BG_RV_OBJECT_PILAR_COLLISION_3,
    BG_RV_OBJECT_PILAR_COLLISION_4,
*/
    BG_RV_OBJECT_ELEVATOR_1,
    BG_RV_OBJECT_ELEVATOR_2,
    BG_RV_OBJECT_FENCE_1,
    BG_RV_OBJECT_FENCE_2,
    BG_RV_OBJECT_MAX,
};

enum BattleGroundRVObjects
{
    BG_RV_OBJECT_TYPE_BUFF_1                     = 184663,
    BG_RV_OBJECT_TYPE_BUFF_2                     = 184664,
    BG_RV_OBJECT_TYPE_FIRE_1                     = 192704,
    BG_RV_OBJECT_TYPE_FIRE_2                     = 192705,

    BG_RV_OBJECT_TYPE_FIREDOOR_2                 = 192387,
    BG_RV_OBJECT_TYPE_FIREDOOR_1                 = 192388,
    BG_RV_OBJECT_TYPE_PULLEY_1                   = 192389,
    BG_RV_OBJECT_TYPE_PULLEY_2                   = 192390,
    BG_RV_OBJECT_TYPE_FENCE_1                    = 192391,
    BG_RV_OBJECT_TYPE_FENCE_2                    = 192392,
    BG_RV_OBJECT_TYPE_GEAR_1                     = 192393,
    BG_RV_OBJECT_TYPE_GEAR_2                     = 192394,
    BG_RV_OBJECT_TYPE_ELEVATOR_1                 = 194582,
    BG_RV_OBJECT_TYPE_ELEVATOR_2                 = 194586,
/*
    BG_RV_OBJECT_TYPE_PILAR_COLLISION_1          = 194580, // axe
    BG_RV_OBJECT_TYPE_PILAR_COLLISION_2          = 194579, // arena
    BG_RV_OBJECT_TYPE_PILAR_COLLISION_3          = 194581, // lightning
    BG_RV_OBJECT_TYPE_PILAR_COLLISION_4          = 194578, // ivory
*/
    BG_RV_OBJECT_TYPE_PILAR_1                    = 194583, // axe
    BG_RV_OBJECT_TYPE_PILAR_2                    = 194584, // arena
    BG_RV_OBJECT_TYPE_PILAR_3                    = 194585, // lightning
    BG_RV_OBJECT_TYPE_PILAR_4                    = 194587, // ivory
};

enum BattleGroundRVData
{
    BG_RV_STATE_OPEN_FENCES,
    BG_RV_STATE_OPEN_PILARS,
    BG_RV_STATE_CLOSE_PILARS,
    BG_RV_STATE_OPEN_FIRE,
    BG_RV_STATE_CLOSE_FIRE,
    BG_RV_FIRE_TO_PILAR_TIMER                    = 20000,
    BG_RV_PILAR_TO_FIRE_TIMER                    =  5000,
    BG_RV_FIRST_TIMER                            = 20133,
    BG_RV_WORLD_STATE_A                          = 0xe10,
    BG_RV_WORLD_STATE_H                          = 0xe11,
    BG_RV_WORLD_STATE                            = 0xe1a,
};

class BattleGroundRVScore : public BattleGroundScore
{
    public:
        BattleGroundRVScore() {};
        virtual ~BattleGroundRVScore() {};
};

class BattleGroundRV : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundRV();
        ~BattleGroundRV();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();
        virtual void Reset();
        virtual void FillInitialWorldStates(WorldPacket &d);

        void RemovePlayer(Player *plr, uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleGround();
        void HandleKillPlayer(Player* player, Player *killer);
        bool HandlePlayerUnderMap(Player * plr);

    private:
        uint32 Timer;
        uint32 State;

    protected:
        uint32 getTimer() { return Timer; };
        void setTimer(uint32 timer) { Timer = timer; };

        uint32 getState() { return State; };
        void setState(uint32 state) { State = state; };
};
#endif
