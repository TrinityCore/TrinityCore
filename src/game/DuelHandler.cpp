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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Log.h"
#include "Opcodes.h"
#include "UpdateData.h"
#include "Player.h"
#include "TimeMgr.h"

void WorldSession::HandleDuelAcceptedOpcode(WorldPacket& recvPacket)
{
    uint64 guid;
    Player *pl;
    Player *plTarget;

    if(!GetPlayer()->duel)                                  // ignore accept from duel-sender
        return;

    recvPacket >> guid;

    pl       = GetPlayer();
    plTarget = pl->duel->opponent;

    if(pl == pl->duel->initiator || !plTarget || pl == plTarget || pl->duel->startTime != 0 || plTarget->duel->startTime != 0)
        return;

    //sLog.outDebug( "WORLD: received CMSG_DUEL_ACCEPTED" );
    DEBUG_LOG("Player 1 is: %u (%s)", pl->GetGUIDLow(),pl->GetName());
    DEBUG_LOG("Player 2 is: %u (%s)", plTarget->GetGUIDLow(),plTarget->GetName());

    time_t now = sGameTime.GetGameTime();
    pl->duel->startTimer = now;
    plTarget->duel->startTimer = now;

    pl->SendDuelCountdown(3000);
    plTarget->SendDuelCountdown(3000);
}

void WorldSession::HandleDuelCancelledOpcode(WorldPacket& recvPacket)
{
    //sLog.outDebug( "WORLD: received CMSG_DUEL_CANCELLED" );

    // no duel requested
    if(!GetPlayer()->duel)
        return;

    // player surrendered in a duel using /forfeit
    if(GetPlayer()->duel->startTime != 0)
    {
        GetPlayer()->CombatStopWithPets(true);
        if(GetPlayer()->duel->opponent)
            GetPlayer()->duel->opponent->CombatStopWithPets(true);

        GetPlayer()->CastSpell(GetPlayer(), SPELL_ID_DUEL_BEG, true);    // beg
        GetPlayer()->DuelComplete(DUEL_WON);
        return;
    }

    // player either discarded the duel using the "discard button"
    // or used "/forfeit" before countdown reached 0
    uint64 guid;
    recvPacket >> guid;

    GetPlayer()->DuelComplete(DUEL_INTERUPTED);
}
