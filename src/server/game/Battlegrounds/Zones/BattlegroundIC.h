/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __BATTLEGROUNDIC_H
#define __BATTLEGROUNDIC_H

class Battleground;

enum Buffs
{
    OIL_REFINERY        = 68719,
    QUARRY            = 68720
};

enum BG_IC_Objectives
{
    IC_OBJECTIVE_ASSAULT_BASE   = 245,
    IC_OBJECTIVE_DEFEND_BASE    = 246
};

class BattlegroundICScore : public BattlegroundScore
{
    public:
        BattlegroundICScore() {};
        virtual ~BattlegroundICScore() {};
};

class BattlegroundIC : public Battleground
{
    friend class BattlegroundMgr;

    public:
        BattlegroundIC();
        ~BattlegroundIC();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleground();
        void SpawnLeader(uint32 teamid);
        void HandleKillUnit(Creature *unit, Player *killer);
        void EndBattleground(uint32 winner);
        void EventPlayerClickedOnFlag(Player *source, GameObject* /*target_obj*/);

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value, bool doAddHonor = true);

    private:
};
#endif
