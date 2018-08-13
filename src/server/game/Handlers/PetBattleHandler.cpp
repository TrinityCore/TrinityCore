/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "WorldSession.h"
#include "BattlePet.h"
#include "BattlePetMgr.h"
#include "PetBattleMgr.h"
#include "PetBattlePackets.h"
#include "Player.h"

void WorldSession::HandlePetBattleRequestWild(WorldPackets::PetBattle::RequestWild& requestWild)
{
    PetBattleRequest request;
    request.Location = requestWild.Location;
    request.opponentGUID = requestWild.TargetGUID;

    sPetBattleMgr->HandleWildRequest(GetPlayer(), request);
}
