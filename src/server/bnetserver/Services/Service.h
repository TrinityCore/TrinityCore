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

#ifndef Service_h__
#define Service_h__

#include "Session.h"

namespace bgs { namespace protocol { } }
using namespace bgs::protocol;

namespace Battlenet
{
    template<class T>
    class Service : public T
    {
    public:
        Service(Session* session) : T(true), _session(session) { }

    protected:
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)> callback) override { _session->SendRequest(serviceHash, methodId, request, std::move(callback)); }
        void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request) override { _session->SendRequest(serviceHash, methodId, request); }
        void SendResponse(uint32 /*serviceHash*/, uint32 /*methodId*/, uint32 token, uint32 status) override { _session->SendResponse(token, status); }
        void SendResponse(uint32 /*serviceHash*/, uint32 /*methodId*/, uint32 token, google::protobuf::Message const* response) override { _session->SendResponse(token, response); }
        std::string GetCallerInfo() const override { return _session->GetClientInfo(); }

        Session* _session;
    };
}

#endif // Service_h__
