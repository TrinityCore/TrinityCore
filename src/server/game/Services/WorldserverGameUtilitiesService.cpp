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

#include "WorldserverGameUtilitiesService.h"
#include "BattlenetRpcErrorCodes.h"
#include "IpAddress.h"
#include "Log.h"
#include "MapUtils.h"
#include "ProtobufJSON.h"
#include "RealmList.h"
#include "RealmList.pb.h"
#include <zlib.h>

std::unordered_map<std::string, Battlenet::Services::GameUtilitiesService::ClientRequestHandler> const Battlenet::Services::GameUtilitiesService::ClientRequestHandlers =
{
    { "Command_RealmListRequest_v1", &GameUtilitiesService::HandleRealmListRequest },
    { "Command_RealmJoinRequest_v1", &GameUtilitiesService::HandleRealmJoinRequest }
};

Battlenet::Services::GameUtilitiesService::GameUtilitiesService(WorldSession* session) : BaseService(session)
{
}

uint32 Battlenet::Services::GameUtilitiesService::HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Attribute const* command = nullptr;
    std::unordered_map<std::string, Variant const*> params;
    auto removeSuffix = [](std::string const& string) -> std::string
    {
        size_t pos = string.rfind('_');
        if (pos != std::string::npos)
            return string.substr(0, pos);

        return string;
    };

    for (int32 i = 0; i < request->attribute_size(); ++i)
    {
        Attribute const& attr = request->attribute(i);
        if (strstr(attr.name().c_str(), "Command_") == attr.name().c_str())
        {
            command = &attr;
            params[removeSuffix(attr.name())] = &attr.value();
        }
        else
            params[attr.name()] = &attr.value();
    }

    if (!command)
    {
        TC_LOG_ERROR("session.rpc", "{} sent ClientRequest with no command.", GetCallerInfo());
        return ERROR_RPC_MALFORMED_REQUEST;
    }

    auto itr = ClientRequestHandlers.find(removeSuffix(command->name()));
    if (itr == ClientRequestHandlers.end())
    {
        TC_LOG_ERROR("session.rpc", "{} sent ClientRequest with unknown command {}.", GetCallerInfo(), removeSuffix(command->name()));
        return ERROR_RPC_NOT_IMPLEMENTED;
    }

    return (this->*itr->second)(params, response);
}

uint32 Battlenet::Services::GameUtilitiesService::HandleRealmListRequest(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response)
{
    std::string subRegionId;
    if (Variant const* subRegion = Trinity::Containers::MapGetValuePtr(params, "Command_RealmListRequest_v1"))
        subRegionId = subRegion->string_value();

    std::vector<uint8> compressed = sRealmList->GetRealmList(_session->GetClientBuild(), _session->GetSecurity(), subRegionId);

    if (compressed.empty())
        return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

    Attribute* attribute = response->add_attribute();
    attribute->set_name("Param_RealmList");
    attribute->mutable_value()->set_blob_value(compressed.data(), compressed.size());

    JSON::RealmList::RealmCharacterCountList realmCharacterCounts;
    for (auto const& characterCount : _session->GetRealmCharacterCounts())
    {
        ::JSON::RealmList::RealmCharacterCountEntry* countEntry = realmCharacterCounts.add_counts();
        countEntry->set_wowrealmaddress(characterCount.first);
        countEntry->set_count(characterCount.second);
    }

    std::string json = "JSONRealmCharacterCountList:" + JSON::Serialize(realmCharacterCounts);

    uLongf compressedLength = compressBound(json.length());
    compressed.resize(4 + compressedLength);
    *reinterpret_cast<uint32*>(compressed.data()) = json.length() + 1;

    if (compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), json.length() + 1) != Z_OK)
        return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

    attribute = response->add_attribute();
    attribute->set_name("Param_CharacterCountList");
    attribute->mutable_value()->set_blob_value(compressed.data(), compressedLength + 4);

    return ERROR_OK;
}

uint32 Battlenet::Services::GameUtilitiesService::HandleRealmJoinRequest(std::unordered_map<std::string, Variant const*> const& params, game_utilities::v1::ClientResponse* response)
{
    if (Variant const* realmAddress = Trinity::Containers::MapGetValuePtr(params, "Param_RealmAddress"))
        return sRealmList->JoinRealm(uint32(realmAddress->uint_value()), _session->GetClientBuild(), _session->GetClientBuildVariant(),
            Trinity::Net::make_address(_session->GetRemoteAddress()), _session->GetRealmListSecret(), _session->GetSessionDbcLocale(),
            _session->GetOS(), _session->GetTimezoneOffset(), _session->GetAccountName(), _session->GetSecurity(), response);

    return ERROR_WOW_SERVICES_INVALID_JOIN_TICKET;
}

uint32 Battlenet::Services::GameUtilitiesService::HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    if (request->attribute_key().find("Command_RealmListRequest_v1") == 0)
    {
        sRealmList->WriteSubRegions(response);
        return ERROR_OK;
    }

    return ERROR_RPC_NOT_IMPLEMENTED;
}
