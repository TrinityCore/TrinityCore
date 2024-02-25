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

#include "AuthenticationService.h"

Battlenet::Services::Authentication::Authentication(Session* session) : AuthenticationService(session)
{
}

uint32 Battlenet::Services::Authentication::HandleLogon(authentication::v1::LogonRequest const* request, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return _session->HandleLogon(request, continuation);
}

uint32 Battlenet::Services::Authentication::HandleVerifyWebCredentials(authentication::v1::VerifyWebCredentialsRequest const* request, NoData* /*response*/, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation)
{
    return _session->HandleVerifyWebCredentials(request, continuation);
}

uint32 Battlenet::Services::Authentication::HandleGenerateWebCredentials(authentication::v1::GenerateWebCredentialsRequest const* request, authentication::v1::GenerateWebCredentialsResponse* /*response*/, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    return _session->HandleGenerateWebCredentials(request, continuation);
}
