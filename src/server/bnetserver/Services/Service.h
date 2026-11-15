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

#ifndef TRINITYCORE_BNET_SERVICE_H
#define TRINITYCORE_BNET_SERVICE_H

#include "MessageBuffer.h"
#include <functional>
#include <string>

namespace google::protobuf
{
class Message;
}

namespace bgs::protocol { }
using namespace bgs::protocol;

namespace Battlenet
{
    class Session;

    class ServiceBaseCaller
    {
    protected:
        explicit ServiceBaseCaller(Session* session) : _session(session) { }

        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)>&& callback);
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request);
        void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status);
        void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, google::protobuf::Message const* response);
        std::string GetCallerInfo() const;

        Session* _session;
    };

    template<class T>
    class Service : public T, public ServiceBaseCaller
    {
    public:
        explicit Service(Session* session) : T(true), ServiceBaseCaller(session) { }

    protected:
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)> callback) override
        {
            ServiceBaseCaller::SendRequest(serviceHash, methodId, request, std::move(callback));
        }

        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request) override
        {
            ServiceBaseCaller::SendRequest(serviceHash, methodId, request);
        }

        void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status) override
        {
            ServiceBaseCaller::SendResponse(serviceHash, methodId, token, status);
        }

        void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, google::protobuf::Message const* response) override
        {
            ServiceBaseCaller::SendResponse(serviceHash, methodId, token, response);
        }

        std::string GetCallerInfo() const override
        {
            return ServiceBaseCaller::GetCallerInfo();
        }
    };
}

#endif // TRINITYCORE_BNET_SERVICE_H
