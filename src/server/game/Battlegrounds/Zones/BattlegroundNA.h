/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#ifndef __BATTLEGROUNDNA_H
#define __BATTLEGROUNDNA_H

#include "Arena.h"
#include "EventMap.h"

enum BattlegroundNAObjectTypes
{
    BG_NA_OBJECT_DOOR_1         = 0,
    BG_NA_OBJECT_DOOR_2         = 1,
    BG_NA_OBJECT_DOOR_3         = 2,
    BG_NA_OBJECT_DOOR_4         = 3,
    BG_NA_OBJECT_BUFF_1         = 4,
    BG_NA_OBJECT_BUFF_2         = 5,
    BG_NA_OBJECT_MAX            = 6
};

enum BattlegroundNAGameObjects
{
    BG_NA_OBJECT_TYPE_DOOR_1    = 183978,
    BG_NA_OBJECT_TYPE_DOOR_2    = 183980,
    BG_NA_OBJECT_TYPE_DOOR_3    = 183977,
    BG_NA_OBJECT_TYPE_DOOR_4    = 183979,
    BG_NA_OBJECT_TYPE_BUFF_1    = 184663,
    BG_NA_OBJECT_TYPE_BUFF_2    = 184664
};

enum BattlegroundNAData
{
    BG_NA_REMOVE_DOORS_TIMER    = 5000
};

enum BattlegroundNAEvents
{
    BG_NA_EVENT_REMOVE_DOORS    = 1
};

class BattlegroundNA : public Arena
{
    public:
        BattlegroundNA();

        /* inherited from BattlegroundClass */
        void StartingEventCloseDoors() override;
        void StartingEventOpenDoors() override;

        void HandleAreaTrigger(Player* Source, uint32 Trigger) override;
        bool SetupBattleground() override;
        void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;

    private:
        void PostUpdateImpl(uint32 diff) override;

        EventMap _events;
};
#endif
