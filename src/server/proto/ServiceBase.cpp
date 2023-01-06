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

#include "ServiceBase.h"
#include "Errors.h"
#include "Log.h"
#include <google/protobuf/message.h>

void ServiceBase::LogDisallowedMethod(uint32 methodId)
{
    TC_LOG_ERROR("service.protobuf", "%s Server tried to call server method %u",
        GetCallerInfo().c_str(), methodId);
}

void ServiceBase::LogCallClientMethod(char const* methodName, char const* inputTypeName, google::protobuf::Message const* request)
{
    TC_LOG_DEBUG("service.protobuf", "%s Server called client method %s(%s{ %s })",
        GetCallerInfo().c_str(), methodName, inputTypeName, request->ShortDebugString().c_str());
}

void ServiceBase::LogCallServerMethod(char const* methodName, char const* inputTypeName, google::protobuf::Message const* request)
{
    TC_LOG_DEBUG("service.protobuf", "%s Client called server method %s(%s{ %s }).",
        GetCallerInfo().c_str(), methodName, inputTypeName, request->ShortDebugString().c_str());
}

void ServiceBase::LogUnimplementedServerMethod(char const* methodName, google::protobuf::Message const* request)
{
    TC_LOG_ERROR("service.protobuf", "%s Client tried to call not implemented method %s({ %s })",
            GetCallerInfo().c_str(), methodName, request->ShortDebugString().c_str());
}

void ServiceBase::LogInvalidMethod(uint32 methodId)
{
    TC_LOG_ERROR("service.protobuf", "Bad method id %u.", methodId);
}

void ServiceBase::LogFailedParsingRequest(char const* methodName)
{
    TC_LOG_DEBUG("service.protobuf", "%s Failed to parse request for %s server method call.", GetCallerInfo().c_str(), methodName);
}

std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)> ServiceBase::CreateServerContinuation(uint32 token, uint32 methodId, char const* methodName, google::protobuf::Descriptor const* outputDescriptor)
{
    return [token, methodId, methodName, outputDescriptor](ServiceBase* service, uint32 status, ::google::protobuf::Message const* response)
    {
        ASSERT(response->GetDescriptor() == outputDescriptor);
        TC_LOG_DEBUG("service.protobuf", "%s Client called server method %s() %s{ %s } status %u.",
            service->GetCallerInfo().c_str(), methodName, outputDescriptor->full_name().c_str(), response->ShortDebugString().c_str(), status);
        if (!status)
            service->SendResponse(service->GetServiceHash(), methodId, token, response);
        else
            service->SendResponse(service->GetServiceHash(), methodId, token, status);
    };
}
