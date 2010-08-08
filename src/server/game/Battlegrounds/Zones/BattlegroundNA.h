/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#ifndef __BATTLEGROUNDNA_H
#define __BATTLEGROUNDNA_H

class Battleground;

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

enum BattlegroundNAObjects
{
    BG_NA_OBJECT_TYPE_DOOR_1    = 183978,
    BG_NA_OBJECT_TYPE_DOOR_2    = 183980,
    BG_NA_OBJECT_TYPE_DOOR_3    = 183977,
    BG_NA_OBJECT_TYPE_DOOR_4    = 183979,
    BG_NA_OBJECT_TYPE_BUFF_1    = 184663,
    BG_NA_OBJECT_TYPE_BUFF_2    = 184664
};

class BattlegroundNAScore : public BattlegroundScore
{
    public:
        BattlegroundNAScore() {};
        virtual ~BattlegroundNAScore() {};
        //TODO fix me
};

class BattlegroundNA : public Battleground
{
    friend class BattlegroundMgr;

    public:
        BattlegroundNA();
        ~BattlegroundNA();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player *plr, uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleground();
        virtual void Reset();
        virtual void FillInitialWorldStates(WorldPacket &d);
        void HandleKillPlayer(Player* player, Player *killer);
        bool HandlePlayerUnderMap(Player * plr);
};
#endif
