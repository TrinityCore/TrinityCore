/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef WorldserverService_h__
#define WorldserverService_h__

#include "WorldSession.h"
#include "account_service.pb.h"
#include "authentication_service.pb.h"
#include "challenge_service.pb.h"
#include "channel_service.pb.h"
#include "connection_service.pb.h"
#include "friends_service.pb.h"
#include "game_utilities_service.pb.h"
#include "presence_service.pb.h"
#include "report_service.pb.h"
#include "resource_service.pb.h"
#include "user_manager_service.pb.h"

namespace bgs { namespace protocol { } }
using namespace bgs::protocol;

namespace Battlenet
{
    template<class T>
    class WorldserverService : public T
    {
    public:
        WorldserverService(WorldSession* session) : T(false), _session(session) { }

    protected:
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)> callback) override { _session->SendBattlenetRequest(serviceHash, methodId, request, std::move(callback)); }
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request) override { _session->SendBattlenetRequest(serviceHash, methodId, request); }
        void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status) override { _session->SendBattlenetResponse(serviceHash, methodId, token, status); }
        void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, google::protobuf::Message const* response) override { _session->SendBattlenetResponse(serviceHash, methodId, token, response); }
        std::string GetCallerInfo() const override { return _session->GetPlayerInfo(); }

        WorldSession* _session;
    };

    class GameUtilitiesService : public WorldserverService<game_utilities::v1::GameUtilitiesService>
    {
        typedef WorldserverService<game_utilities::v1::GameUtilitiesService> BaseService;

    public:
        GameUtilitiesService(WorldSession* session);

        uint32 HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
        uint32 HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;

    private:
        uint32 HandleRealmListRequest(std::unordered_map<std::string, Variant const*> params, game_utilities::v1::ClientResponse* response);
        uint32 HandleRealmJoinRequest(std::unordered_map<std::string, Variant const*> params, game_utilities::v1::ClientResponse* response);
    };
}

#endif // WorldserverService_h__
