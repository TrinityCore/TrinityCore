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

#include "ServiceDispatcher.h"

Battlenet::ServiceDispatcher::ServiceDispatcher()
{
    AddService<Services::Account>();
    AddService<Services::Authentication>();
    AddService<Service<club::v1::membership::ClubMembershipService>>();
    AddService<Services::Connection>();
    AddService<Service<friends::v1::FriendsService>>();
    AddService<Services::GameUtilities>();
    AddService<Service<presence::v1::PresenceService>>();
    AddService<Service<report::v1::ReportService>>();
    AddService<Service<report::v2::ReportService>>();
    AddService<Service<resources::v1::ResourcesService>>();
    AddService<Service<user_manager::v1::UserManagerService>>();
}

void Battlenet::ServiceDispatcher::Dispatch(Session* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer)
{
    auto itr = _dispatchers.find(serviceHash);
    if (itr != _dispatchers.end())
        itr->second(session, token, methodId, std::move(buffer));
    else
        TC_LOG_DEBUG("session.rpc", "%s tried to call invalid service 0x%X", session->GetClientInfo().c_str(), serviceHash);
}

Battlenet::ServiceDispatcher& Battlenet::ServiceDispatcher::Instance()
{
    static ServiceDispatcher instance;
    return instance;
}
