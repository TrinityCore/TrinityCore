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

#include "ClubMembershipService.h"
#include "BattlenetRpcErrorCodes.h"
#include "Guild.h"

Battlenet::Services::ClubMembershipService::ClubMembershipService(WorldSession* session) : BaseService(session) {}

uint32 Battlenet::Services::ClubMembershipService::HandleSubscribe(club::v1::membership::SubscribeRequest const* /*request*/, club::v1::membership::SubscribeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Player* player = _session->GetPlayer();

    if (!player)
        return ERROR_INTERNAL;

    Guild* guild = player->GetGuild();

    if (!guild)
        return ERROR_OK;

    return guild->HandleClubMemberSubscribe(response, _session);
}

uint32 Battlenet::Services::ClubMembershipService::HandleUnsubscribe(club::v1::membership::UnsubscribeRequest const* /*request*/, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    // We just have to signal the client that the unsubscribe request came through.
    return ERROR_OK;
}
