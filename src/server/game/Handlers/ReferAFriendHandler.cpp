/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ReferAFriendPackets.h"
#include "World.h"

inline uint32 GetMaxLevelForExpansion(uint32 expansion)
{
    switch (expansion)
    {
        case EXPANSION_CLASSIC:
            return 60;
        case EXPANSION_THE_BURNING_CRUSADE:
            return 70;
        case EXPANSION_WRATH_OF_THE_LICH_KING:
            return 80;
        case EXPANSION_CATACLYSM:
            return 85;
        case EXPANSION_MISTS_OF_PANDARIA:
            return 90;
        case EXPANSION_WARLORDS_OF_DRAENOR:
            return 100;
        case EXPANSION_LEGION:
            return 110;
        default:
            break;
    }
    return 0;
}

void WorldSession::HandleGrantLevel(WorldPackets::RaF::GrantLevel& grantLevel)
{
    Player* target = ObjectAccessor::GetPlayer(*_player, grantLevel.Target);

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
    else if (target->getLevel() >= _player->getLevel())
        error = ERR_REFER_A_FRIEND_TARGET_TOO_HIGH;
    else if (target->getLevel() >= sWorld->getIntConfig(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL))
        error = ERR_REFER_A_FRIEND_GRANT_LEVEL_MAX_I;
    else if (target->GetGroup() != _player->GetGroup())
        error = ERR_REFER_A_FRIEND_NOT_IN_GROUP;
    else if (target->getLevel() >= GetMaxLevelForExpansion(target->GetSession()->GetExpansion()))
        error = ERR_REFER_A_FRIEND_INSUF_EXPAN_LVL;

    if (error)
    {
        WorldPackets::RaF::ReferAFriendFailure failure;
        failure.Reason = error;
        if (error == ERR_REFER_A_FRIEND_NOT_IN_GROUP)
            failure.Str = target->GetName();

        SendPacket(failure.Write());
        return;
    }

    WorldPackets::RaF::ProposeLevelGrant proposeLevelGrant;
    proposeLevelGrant.Sender = _player->GetGUID();
    target->SendDirectMessage(proposeLevelGrant.Write());
}

void WorldSession::HandleAcceptGrantLevel(WorldPackets::RaF::AcceptLevelGrant& acceptLevelGrant)
{
    Player* other = ObjectAccessor::GetPlayer(*_player, acceptLevelGrant.Granter);
    if (!(other && other->GetSession()))
        return;

    if (GetAccountId() != other->GetSession()->GetRecruiterId())
        return;

    if (other->GetGrantableLevels())
        other->SetGrantableLevels(other->GetGrantableLevels() - 1);
    else
        return;

    _player->GiveLevel(_player->getLevel() + 1);
}
