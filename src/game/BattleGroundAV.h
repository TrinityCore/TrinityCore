/*
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
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

#ifndef __BATTLEGROUNDAV_H
#define __BATTLEGROUNDAV_H

class BattleGround;

class BattleGroundAVScore : public BattleGroundScore
{
    public:
        BattleGroundAVScore() : GraveyardsAssaulted(0), GraveyardsDefended(0), TowersAssaulted(0), TowersDefended(0), MinesCaptured(0), LeadersKilled(0), SecondaryObjectives(0) {};
        virtual ~BattleGroundAVScore() {};
        uint32 GraveyardsAssaulted;
        uint32 GraveyardsDefended;
        uint32 TowersAssaulted;
        uint32 TowersDefended;
        uint32 MinesCaptured;
        uint32 LeadersKilled;
        uint32 SecondaryObjectives;
};

class BattleGroundAV : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundAV();
        ~BattleGroundAV();
        void Update(time_t diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);

        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        //bool SetupBattleGround();

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);

    private:
};
#endif
