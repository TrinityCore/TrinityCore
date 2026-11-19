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

#ifndef TRINITYCORE_ACCOUNT_SERVICE_H
#define TRINITYCORE_ACCOUNT_SERVICE_H

#include "Service.h"
#include "Client/account_service.pb.h"
#include "Client/api/client/v2/account_service.pb.h"

namespace Battlenet::Services
{
    namespace V1
    {
        class Account : public Service<account::v1::AccountService>
        {
            typedef Service<account::v1::AccountService> AccountService;

        public:
            Account(Session* session);

            uint32 HandleGetAccountState(account::v1::GetAccountStateRequest const* request, account::v1::GetAccountStateResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetGameAccountState(account::v1::GetGameAccountStateRequest const* request, account::v1::GetGameAccountStateResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
        };
    }

    namespace V2
    {
        class Account : public Service<account::v2::client::AccountService>
        {
            typedef Service<account::v2::client::AccountService> AccountService;

        public:
            Account(Session* session);

            uint32 HandleGetAccountInfo(account::v2::client::GetAccountInfoRequest const* request, account::v2::client::GetAccountInfoResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetRestriction(account::v2::client::GetRestrictionRequest const* request, account::v2::client::GetRestrictionResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetGameAccountInfo(account::v2::client::GetGameAccountInfoRequest const* request, account::v2::client::GetGameAccountInfoResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetGameAccountRestriction(account::v2::client::GetGameAccountRestrictionRequest const* request, account::v2::client::GetGameAccountRestrictionResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
        };
    }
}

#endif // TRINITYCORE_ACCOUNT_SERVICE_H
