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

#include "WorldserverService.h"
#include "BattlenetRpcErrorCodes.h"
#include "IpAddress.h"
#include "Log.h"
#include "ProtobufJSON.h"
#include "Realm.h"
#include "RealmList.h"
#include "RealmList.pb.h"
#include "World.h"
#include <zlib.h>

Battlenet::GameUtilitiesService::GameUtilitiesService(WorldSession* session) : BaseService(session)
{
}

uint32 Battlenet::GameUtilitiesService::HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    Attribute const* command = nullptr;
    std::unordered_map<std::string, Variant const*> params;

    for (int32 i = 0; i < request->attribute_size(); ++i)
    {
        Attribute const& attr = request->attribute(i);
        params[attr.name()] = &attr.value();
        if (strstr(attr.name().c_str(), "Command_") == attr.name().c_str())
            command = &attr;
    }

    if (!command)
    {
        TC_LOG_ERROR("session.rpc", "%s sent ClientRequest with no command.", GetCallerInfo().c_str());
        return ERROR_RPC_MALFORMED_REQUEST;
    }

    if (command->name() == "Command_RealmListRequest_v1_b9")
        return HandleRealmListRequest(params, response);
    else if (command->name() == "Command_RealmJoinRequest_v1_b9")
        return HandleRealmJoinRequest(params, response);

    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::GameUtilitiesService::HandleRealmListRequest(std::unordered_map<std::string, Variant const*> params, game_utilities::v1::ClientResponse* response)
{
    std::string subRegionId;
    auto subRegion = params.find("Command_RealmListRequest_v1_b9");
    if (subRegion != params.end())
        subRegionId = subRegion->second->string_value();

    std::vector<uint8> compressed = sRealmList->GetRealmList(realm.Build, subRegionId);

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

uint32 Battlenet::GameUtilitiesService::HandleRealmJoinRequest(std::unordered_map<std::string, Variant const*> params, game_utilities::v1::ClientResponse* response)
{
    auto realmAddress = params.find("Param_RealmAddress");
    if (realmAddress != params.end())
        return sRealmList->JoinRealm(uint32(realmAddress->second->uint_value()), realm.Build, Trinity::Net::make_address(_session->GetRemoteAddress()), _session->GetRealmListSecret(),
            _session->GetSessionDbcLocale(), _session->GetOS(), _session->GetAccountName(), response);

    return ERROR_WOW_SERVICES_INVALID_JOIN_TICKET;
}

uint32 Battlenet::GameUtilitiesService::HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    if (request->attribute_key() == "Command_RealmListRequest_v1_b9")
    {
        sRealmList->WriteSubRegions(response);
        return ERROR_OK;
    }

    return ERROR_RPC_NOT_IMPLEMENTED;
}
