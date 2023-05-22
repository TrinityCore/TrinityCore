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

#ifndef ServiceBase_h__
#define ServiceBase_h__

#include "MessageBuffer.h"
#include "Define.h"
#include <functional>
#include <string>

namespace google
{
    namespace protobuf
    {
        class Descriptor;
        class Message;
    }
}

class TC_PROTO_API ServiceBase
{
public:
    explicit ServiceBase(uint32 serviceHash) : service_hash_(serviceHash) { }

    virtual ~ServiceBase() { }

    virtual void CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) = 0;

    virtual std::string GetCallerInfo() const = 0;

    void LogDisallowedMethod(uint32 methodId);
    void LogCallClientMethod(char const* methodName, char const* inputTypeName, google::protobuf::Message const* request);
    void LogCallServerMethod(char const* methodName, char const* inputTypeName, google::protobuf::Message const* request);
    void LogUnimplementedServerMethod(char const* methodName, google::protobuf::Message const* request);
    void LogInvalidMethod(uint32 methodId);
    void LogFailedParsingRequest(char const* methodName);

    uint32 GetServiceHash() const { return service_hash_; }

protected:
    std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)> CreateServerContinuation(uint32 token, uint32 methodId, char const* methodName, google::protobuf::Descriptor const* outputDescriptor);

    virtual void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request, std::function<void(MessageBuffer)> callback) = 0;
    virtual void SendRequest(uint32 serviceHash, uint32 methodId, google::protobuf::Message const* request) = 0;
    virtual void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, uint32 status) = 0;
    virtual void SendResponse(uint32 serviceHash, uint32 methodId, uint32 token, google::protobuf::Message const* response) = 0;

    uint32 service_hash_;
};

#endif // ServiceBase_h__
