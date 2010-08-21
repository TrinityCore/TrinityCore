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

#include "Common.h"
#include "Log.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "ObjectDefines.h"

void WorldSession::HandleAttackSwingOpcode(WorldPacket & recv_data)
{
    uint64 guid;
    recv_data >> guid;

    sLog.outStaticDebug("WORLD: Recvd CMSG_ATTACKSWING Message guidlow:%u guidhigh:%u", GUID_LOPART(guid), GUID_HIPART(guid));

    Unit *pEnemy = ObjectAccessor::GetUnit(*_player, guid);

    if (!pEnemy)
    {
        if (!IS_UNIT_GUID(guid))
            sLog.outError("WORLD: Object %u (TypeID: %u) isn't player, pet or creature",GUID_LOPART(guid),GuidHigh2TypeId(GUID_HIPART(guid)));
        else
            sLog.outError("WORLD: Enemy %s %u not found",GetLogNameForGuid(guid),GUID_LOPART(guid));

        // stop attack state at client
        SendAttackStop(NULL);
        return;
    }

    if (!_player->canAttack(pEnemy))
    {
        sLog.outError("WORLD: Enemy %s %u is friendly",(IS_PLAYER_GUID(guid) ? "player" : "creature"),GUID_LOPART(guid));

        // stop attack state at client
        SendAttackStop(pEnemy);
        return;
    }

    _player->Attack(pEnemy,true);
}

void WorldSession::HandleAttackStopOpcode(WorldPacket & /*recv_data*/)
{
    GetPlayer()->AttackStop();
}

void WorldSession::HandleSetSheathedOpcode(WorldPacket & recv_data)
{
    uint32 sheathed;
    recv_data >> sheathed;

    //sLog.outDebug("WORLD: Recvd CMSG_SETSHEATHED Message guidlow:%u value1:%u", GetPlayer()->GetGUIDLow(), sheathed);

    if (sheathed >= MAX_SHEATH_STATE)
    {
        sLog.outError("Unknown sheath state %u ??",sheathed);
        return;
    }

    GetPlayer()->SetSheath(SheathState(sheathed));
}

void WorldSession::SendAttackStop(Unit const* enemy)
{
    WorldPacket data(SMSG_ATTACKSTOP, (4+20));            // we guess size
    data.append(GetPlayer()->GetPackGUID());
    data.append(enemy ? enemy->GetPackGUID() : 0);          // must be packed guid
    data << uint32(0);                                      // unk, can be 1 also
    SendPacket(&data);
}

