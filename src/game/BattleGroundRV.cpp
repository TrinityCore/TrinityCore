/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Player.h"
#include "BattleGround.h"
#include "BattleGroundRV.h"

BattleGroundRV::BattleGroundRV()
{

}

BattleGroundRV::~BattleGroundRV()
{

}

void BattleGroundRV::Update(time_t diff)
{
    BattleGround::Update(diff);
}

void BattleGroundRV::AddPlayer(Player *plr)
{
    BattleGround::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattleGroundRVScore* sc = new BattleGroundRVScore;

    m_PlayerScores[plr->GetGUID()] = sc;
}

void BattleGroundRV::RemovePlayer(Player * /*plr*/, uint64 /*guid*/)
{
}

void BattleGroundRV::HandleKillPlayer(Player* player, Player* killer)
{
    BattleGround::HandleKillPlayer(player, killer);
}

void BattleGroundRV::HandleAreaTrigger(Player * /*Source*/, uint32 /*Trigger*/)
{
}

bool BattleGroundRV::SetupBattleGround()
{
    return true;
}
