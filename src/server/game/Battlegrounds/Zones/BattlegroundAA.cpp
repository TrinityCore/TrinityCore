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

#include "BattlegroundMap.h"
#include "BattlegroundAA.h"
#include "Language.h"
#include "Player.h"

BattlegroundAA::BattlegroundAA()
{
}

BattlegroundAA::~BattlegroundAA()
{
}

void BattlegroundAA::Update(uint32 diff)
{
    Battleground::Update(diff);
}

void BattlegroundAA::StartingEventCloseDoors()
{
}

void BattlegroundAA::StartingEventOpenDoors()
{
}

void BattlegroundAA::AddPlayer(Player *plr)
{
    Battleground::OnPlayerJoin(plr);
    //create score and add it to map, default values are set in constructor
    BattlegroundAAScore* sc = new BattlegroundAAScore;

    m_PlayerScores[plr->GetGUID()] = sc;
}

void BattlegroundAA::RemovePlayer(Player* /*plr*/, uint64 /*guid*/, uint32 /*team*/)
{
}

void BattlegroundAA::HandleKillPlayer(Player* player, Player* killer)
{
    Battleground::HandleKillPlayer(player, killer);
}

void BattlegroundAA::HandleAreaTrigger(Player* /*Source*/, uint32 /*Trigger*/)
{
}

bool BattlegroundAA::SetupBattleground()
{
    return true;
}
