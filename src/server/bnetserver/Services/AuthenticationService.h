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

#ifndef TRINITYCORE_AUTHENTICATION_SERVICE_H
#define TRINITYCORE_AUTHENTICATION_SERVICE_H

#include "Service.h"
#include "Client/authentication_service.pb.h"
#include "Client/api/client/v2/authentication_service.pb.h"

namespace Battlenet
{
struct AccountInfo;
}

namespace Battlenet::Services
{
    namespace Shared
    {
        class Authentication
        {
        public:
            static uint32 HandleLogon(Session* session, std::string_view program, std::string_view platform,
                std::string_view locale, uint32 applicationVersion, std::string_view deviceId);
            static uint32 HandleVerifyAuthToken(Session* session, std::string_view authToken,
                std::function<void(uint32)> sendResponse, std::function<void(AccountInfo const*, std::string_view)> sendLogonComplete);
            static uint32 HandleGenerateAuthToken(Session* session, std::function<void(std::string_view)> sendResponse);
        };
    }

    namespace V1
    {
        class Authentication : public Service<authentication::v1::AuthenticationService>
        {
            typedef Service<authentication::v1::AuthenticationService> AuthenticationService;

        public:
            Authentication(Session* session);

            uint32 HandleLogon(authentication::v1::LogonRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleVerifyWebCredentials(authentication::v1::VerifyWebCredentialsRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGenerateWebCredentials(authentication::v1::GenerateWebCredentialsRequest const* request, authentication::v1::GenerateWebCredentialsResponse* response, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation) override;

        private:
            uint32 HandleVerifyWebCredentials(std::string_view webCredentials, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation);
        };
    }

    namespace V2
    {
        class Authentication : public Service<authentication::v2::client::AuthenticationService>
        {
            typedef Service<authentication::v2::client::AuthenticationService> AuthenticationService;

        public:
            Authentication(Session* session);

            uint32 HandleLogon(authentication::v2::client::LogonRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleVerifyAuthToken(authentication::v2::client::VerifyAuthTokenRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGenerateAuthToken(authentication::v2::client::GenerateAuthTokenRequest const* request, authentication::v2::client::GenerateAuthTokenResponse* response, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation) override;

        private:
            uint32 HandleVerifyAuthToken(std::string_view authToken, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation);
        };
    }
}

#endif // TRINITYCORE_AUTHENTICATION_SERVICE_H
