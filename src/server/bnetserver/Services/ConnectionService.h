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

#ifndef ConnectionService_h__
#define ConnectionService_h__

#include "Service.h"
#include "connection_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class Connection : public Service<connection::v1::ConnectionService>
        {
            typedef Service<connection::v1::ConnectionService> ConnectionService;

        public:
            Connection(Session* session);

            uint32 HandleConnect(connection::v1::ConnectRequest const* request, connection::v1::ConnectResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
            uint32 HandleKeepAlive(NoData const* request) override;
            uint32 HandleRequestDisconnect(connection::v1::DisconnectRequest const* request) override;
        };
    }
}

#endif // ConnectionService_h__
