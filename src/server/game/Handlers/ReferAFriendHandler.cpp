/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "World.h"

void WorldSession::HandleGrantLevel(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_GRANT_LEVEL");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    Player* target = ObjectAccessor::GetPlayer(*_player, guid);

    // check cheating
    uint8 levels = _player->GetGrantableLevels();
    uint8 error = 0;
    if (!target)
        error = ERR_REFER_A_FRIEND_NO_TARGET;
    else if (levels == 0)
        error = ERR_REFER_A_FRIEND_INSUFFICIENT_GRANTABLE_LEVELS;
    else if (GetRecruiterId() != target->GetSession()->GetAccountId())
        error = ERR_REFER_A_FRIEND_NOT_REFERRED_BY;
    else if (target->GetTeamId() != _player->GetTeamId())
        error = ERR_REFER_A_FRIEND_DIFFERENT_FACTION;
    else if (target->GetLevel() >= _player->GetLevel())
        error = ERR_REFER_A_FRIEND_TARGET_TOO_HIGH;
    else if (target->GetLevel() >= sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL))
        error = ERR_REFER_A_FRIEND_GRANT_LEVEL_MAX_I;
    else if (target->GetGroup() != _player->GetGroup())
        error = ERR_REFER_A_FRIEND_NOT_IN_GROUP;

    if (error)
    {
        WorldPacket data(SMSG_REFER_A_FRIEND_FAILURE, 24);
        data << uint32(error);
        if (error == ERR_REFER_A_FRIEND_NOT_IN_GROUP)
            data << target->GetName();

        SendPacket(&data);
        return;
    }

    WorldPacket data2(SMSG_PROPOSE_LEVEL_GRANT, 8);
    data2 << _player->GetPackGUID();
    target->SendDirectMessage(&data2);
}

void WorldSession::HandleAcceptGrantLevel(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_ACCEPT_LEVEL_GRANT");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    Player* other = ObjectAccessor::GetPlayer(*_player, guid);

    if (!(other && other->GetSession()))
        return;

    if (GetAccountId() != other->GetSession()->GetRecruiterId())
        return;

    if (other->GetGrantableLevels())
        other->SetGrantableLevels(other->GetGrantableLevels() - 1);
    else
        return;

    _player->GiveLevel(_player->GetLevel() + 1);
}
