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

#ifndef GameUtilitiesServiceService_h__
#define GameUtilitiesServiceService_h__

#include "Common.h"
#include "Service.h"
#include "game_utilities_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class GameUtilities : public Service<game_utilities::v1::GameUtilitiesService>
        {
            typedef Service<game_utilities::v1::GameUtilitiesService> GameUtilitiesService;

        public:
            GameUtilities(Session* session);

            uint32 HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
        };
    }
}

#endif // GameUtilitiesServiceService_h__
