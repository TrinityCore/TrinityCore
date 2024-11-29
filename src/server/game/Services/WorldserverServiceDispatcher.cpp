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

#include "WorldserverServiceDispatcher.h"

Battlenet::WorldserverServiceDispatcher::WorldserverServiceDispatcher()
{
    AddService<WorldserverService<account::v1::AccountService>>();
    AddService<WorldserverService<authentication::v1::AuthenticationService>>();
    AddService<WorldserverService<block_list::v1::client::BlockListService>>();
    AddService<Services::ClubMembershipService>();
    AddService<Services::ClubService>();
    AddService<WorldserverService<connection::v1::ConnectionService>>();
    AddService<WorldserverService<friends::v1::FriendsService>>();
    AddService<Services::GameUtilitiesService>();
    AddService<WorldserverService<notification::v2::client::NotificationService>>();
    AddService<WorldserverService<presence::v1::PresenceService>>();
    AddService<WorldserverService<report::v2::ReportService>>();
    AddService<WorldserverService<resources::v1::ResourcesService>>();
    AddService<WorldserverService<whisper::v2::client::WhisperService>>();
}

void Battlenet::WorldserverServiceDispatcher::Dispatch(WorldSession* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer)
{
    auto itr = _dispatchers.find(serviceHash);
    if (itr != _dispatchers.end())
        itr->second(session, token, methodId, std::move(buffer));
    else
        TC_LOG_DEBUG("session.rpc", "{} tried to call invalid service 0x{:X}", session->GetPlayerInfo(), serviceHash);
}

Battlenet::WorldserverServiceDispatcher& Battlenet::WorldserverServiceDispatcher::Instance()
{
    static WorldserverServiceDispatcher instance;
    return instance;
}
