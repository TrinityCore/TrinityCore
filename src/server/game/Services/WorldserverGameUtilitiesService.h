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

#ifndef WorldserverGameUtilitiesService_h__
#define WorldserverGameUtilitiesService_h__

#include "WorldserverService.h"
#include "game_utilities_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class GameUtilitiesService : public WorldserverService<game_utilities::v1::GameUtilitiesService>
        {
            typedef WorldserverService<game_utilities::v1::GameUtilitiesService> BaseService;

        public:
            GameUtilitiesService(WorldSession* session);

            uint32 HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;

        private:
            using ClientRequestHandler = uint32(GameUtilitiesService::*)(std::unordered_map<std::string, Variant const*> const&, game_utilities::v1::ClientResponse*);
            static std::unordered_map<std::string, ClientRequestHandler> const ClientRequestHandlers;

            uint32 HandleRealmListRequest(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response);
            uint32 HandleRealmJoinRequest(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response);
        };
    }
}

#endif // WorldserverGameUtilitiesService_h__
