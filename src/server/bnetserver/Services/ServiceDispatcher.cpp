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

#include "ServiceDispatcher.h"

Battlenet::ServiceDispatcher::ServiceDispatcher()
{
    AddService<Services::Account>();
    AddService<Services::Authentication>();
    AddService<Service<challenge::v1::ChallengeService>>();
    AddService<Service<channel::v1::ChannelService>>();
    AddService<Services::Connection>();
    AddService<Service<friends::v1::FriendsService>>();
    AddService<Services::GameUtilities>();
    AddService<Service<presence::v1::PresenceService>>();
    AddService<Service<report::v1::ReportService>>();
    AddService<Service<resources::v1::ResourcesService>>();
    AddService<Service<user_manager::v1::UserManagerService>>();
}

void Battlenet::ServiceDispatcher::Dispatch(Session* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer)
{
    auto itr = _dispatchers.find(serviceHash);
    if (itr != _dispatchers.end())
        itr->second(session, token, methodId, std::forward<MessageBuffer>(buffer));
    else
        TC_LOG_DEBUG("session.rpc", "%s tried to call invalid service 0x%X", session->GetClientInfo().c_str(), serviceHash);
}

Battlenet::ServiceDispatcher& Battlenet::ServiceDispatcher::Instance()
{
    static ServiceDispatcher instance;
    return instance;
}
