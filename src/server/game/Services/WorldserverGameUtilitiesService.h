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

#ifndef WORLDSERVER_GAME_UTILITIES_SERVICE_H
#define WORLDSERVER_GAME_UTILITIES_SERVICE_H

#include "WorldserverService.h"
#include "Client/game_utilities_service.pb.h"
#include "Client/api/client/v2/game_utilities_service.pb.h"

namespace Battlenet::Services
{
    using Variant = std::variant<bool, int64, double, std::string, std::vector<uint8>, uint64>;

    namespace Shared
    {
        class GameUtilities
        {
        public:
            static std::string_view ParseParamName(std::string_view command);
            static Variant* FindParamValue(std::vector<std::pair<std::string_view, Variant>>& params, std::string_view paramName);

            static uint32 HandleClientRequest(WorldSession const* session,
                std::vector<std::pair<std::string_view, Variant>>& params,
                std::vector<std::pair<std::string_view, Variant>>& responseValues);

            static uint32 HandleGetAllValuesForAttribute(WorldSession const* session, std::string_view command, std::vector<Variant>& responseValues);

        private:
            static uint32 GetRealmList(WorldSession const* session, std::vector<std::pair<std::string_view, Variant>>& params,
                std::vector<std::pair<std::string_view, Variant>>& responseValues);
            static uint32 JoinRealm(WorldSession const* session, std::vector<std::pair<std::string_view, Variant>>& params,
                std::vector<std::pair<std::string_view, Variant>>& responseValues);
        };
    }

    namespace V2
    {
        Battlenet::Services::Variant FromProto(bgs::protocol::v2::Variant const& from);
        void ToProto(Battlenet::Services::Variant const& from, bgs::protocol::v2::Variant* to);

        class GameUtilitiesService : public WorldserverService<game_utilities::v2::client::GameUtilitiesService>
        {
            typedef WorldserverService<game_utilities::v2::client::GameUtilitiesService> BaseService;

        public:
            GameUtilitiesService(WorldSession* session);

            uint32 HandleProcessTask(game_utilities::v2::client::ProcessTaskRequest const* request, game_utilities::v2::client::ProcessTaskResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetAllValuesForAttribute(game_utilities::v2::client::GetAllValuesForAttributeRequest const* request, game_utilities::v2::client::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
        };
    }

    using GameUtilitiesService = V2::GameUtilitiesService;
}

#endif // WORLDSERVER_GAME_UTILITIES_SERVICE_H
