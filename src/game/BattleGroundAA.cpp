/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "Player.h"
#include "BattleGround.h"
#include "BattleGroundAA.h"

BattleGroundAA::BattleGroundAA()
{

}

BattleGroundAA::~BattleGroundAA()
{

}

void BattleGroundAA::Update(time_t diff)
{
    BattleGround::Update(diff);
}

void BattleGroundAA::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattleGroundAAScore* sc = new BattleGroundAAScore;

    m_PlayerScores[plr->GetGUID()] = sc;
}

void BattleGroundAA::RemovePlayer(Player * /*plr*/, uint64 /*guid*/)
{
}

void BattleGroundAA::HandleKillPlayer(Player* player, Player* killer)
{
    BattleGround::HandleKillPlayer(player, killer);
}

void BattleGroundAA::HandleAreaTrigger(Player * /*Source*/, uint32 /*Trigger*/)
{
}

bool BattleGroundAA::SetupBattleGround()
{
    return true;
}

