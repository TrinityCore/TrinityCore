/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __BATTLEGROUNDRB_H
#define __BATTLEGROUNDRB_H

class Battleground;

class BattlegroundRBScore : public BattlegroundScore
{
    public:
        BattlegroundRBScore() {};
        virtual ~BattlegroundRBScore() {};
};

class BattlegroundRB : public Battleground
{
    friend class BattlegroundMgr;

    public:
        BattlegroundRB();
        ~BattlegroundRB();
        void Update(uint32 diff);

        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value, bool doAddHonor = true);

    private:
};
#endif
