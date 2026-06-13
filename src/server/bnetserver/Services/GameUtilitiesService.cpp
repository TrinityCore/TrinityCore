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

#include "GameUtilitiesService.h"
#include "BattlenetRpcErrorCodes.h"
#include "DatabaseEnv.h"
#include "Hash.h"
#include "Log.h"
#include "MapUtils.h"
#include "ProtobufJSON.h"
#include "RealmList.h"
#include "RealmList.pb.h"
#include "Session.h"
#include "Types.h"
#include <zlib.h>

namespace Battlenet::Services
{
namespace Shared
{
std::string_view GameUtilities::ParseParamName(std::string_view command)
{
    if (command.starts_with("Command_"sv))
    {
        size_t pos = command.rfind('_');
        if (pos != std::string_view::npos)
            command.remove_suffix(command.length() - pos);
    }

    return command;
}

Variant* GameUtilities::FindParamValue(std::vector<std::pair<std::string_view, Variant>>& params, std::string_view paramName)
{
    auto itr = std::ranges::find(params, paramName, Trinity::Containers::MapKey);
    return itr != params.end() ? &itr->second : nullptr;
}

uint32 GameUtilities::HandleClientRequest(Session* session,
    std::vector<std::pair<std::string_view, Variant>>& params,
    std::vector<std::pair<std::string_view, Variant>>& responseValues)
{
    auto command = std::ranges::find_if(params,
        [](std::string_view paramName) { return paramName.starts_with("Command_"sv); },
        Trinity::Containers::MapKey);

    if (command == params.end())
    {
        TC_LOG_ERROR("session.rpc", "{} sent ClientRequest with no command.", session->GetClientInfo());
        return ERROR_RPC_MALFORMED_REQUEST;
    }

    switch (Trinity::HashFnv1a<>::GetHash(command->first))
    {
        case Trinity::HashFnv1a<>::GetHash("Command_LastCharPlayedRequest_v1"sv):
            return GetLastCharPlayed(session, params, responseValues);
        case Trinity::HashFnv1a<>::GetHash("Command_RealmListTicketRequest_v1"sv):
            return GetRealmListTicket(session, params, responseValues);
        case Trinity::HashFnv1a<>::GetHash("Command_RealmListRequest_v1"sv):
            return GetRealmList(session, params, responseValues);
        case Trinity::HashFnv1a<>::GetHash("Command_RealmJoinRequest_v1"sv):
            return JoinRealm(session, params, responseValues);
        default:
            break;
    }

    TC_LOG_ERROR("session.rpc", "{} sent ClientRequest with unknown command {}.", session->GetClientInfo(), command->first);
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilities::HandleGetAllValuesForAttribute(Session const* session, std::string_view command, std::vector<Variant>& responseValues)
{
    if (!session->IsAuthed())
        return ERROR_DENIED;

    switch (Trinity::HashFnv1a<>::GetHash(command))
    {
        case Trinity::HashFnv1a<>::GetHash("Command_RealmListRequest_v1"sv):
            for (std::string& subRegion : sRealmList->GetSubRegions())
                responseValues.emplace_back(std::move(subRegion));
            return ERROR_OK;
        default:
            break;
    }

    TC_LOG_ERROR("session.rpc", "{} sent GetAllValuesForAttributeRequest with unknown command {}.", session->GetClientInfo(), command);
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 GameUtilities::GetLastCharPlayed(Session const* session,
    std::vector<std::pair<std::string_view, Variant>>& params,
    std::vector<std::pair<std::string_view, Variant>>& responseValues)
{
    Variant const* subRegion = FindParamValue(params, "Command_LastCharPlayedRequest_v1");
    if (!subRegion || !std::holds_alternative<std::string>(*subRegion))
        return ERROR_UTIL_SERVER_UNKNOWN_REALM;

    if (LastPlayedCharacterInfo const* lastPlayerChar = session->GetLastPlayedCharacter(std::get<std::string>(*subRegion)))
    {
        std::vector<uint8> realmEntryJson = sRealmList->GetRealmEntryJSON(lastPlayerChar->RealmId, session->GetBuild(), session->GetGameAccountInfo()->SecurityLevel);
        if (realmEntryJson.empty())
            return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

        std::vector<uint8> guidData(sizeof(lastPlayerChar->CharacterGUID));
        std::memcpy(guidData.data(), &lastPlayerChar->CharacterGUID, sizeof(lastPlayerChar->CharacterGUID));

        responseValues.emplace_back("Param_RealmEntry"sv, std::move(realmEntryJson));
        responseValues.emplace_back("Param_CharacterName"sv, lastPlayerChar->CharacterName);
        responseValues.emplace_back("Param_CharacterGUID"sv, std::move(guidData));
        responseValues.emplace_back("Param_LastPlayedTime"sv, int64(lastPlayerChar->LastPlayedTime));
    }

    return ERROR_OK;
}

uint32 GameUtilities::GetRealmListTicket(Session* session,
    std::vector<std::pair<std::string_view, Variant>>& params,
    std::vector<std::pair<std::string_view, Variant>>& responseValues)
{
    GameAccountInfo const* gameAccountInfo = nullptr;

    if (Variant const* identity = FindParamValue(params, "Param_Identity"); identity && std::holds_alternative<std::vector<uint8>>(*identity))
    {
        std::string_view json = { reinterpret_cast<char const*>(std::get<std::vector<uint8>>(*identity).data()), std::get<std::vector<uint8>>(*identity).size() };
        ::JSON::RealmList::RealmListTicketIdentity data;
        std::size_t jsonStart = json.find(':');
        if (jsonStart != std::string_view::npos && ::JSON::Deserialize(json.substr(jsonStart + 1), &data))
            gameAccountInfo = session->GetGameAccountInfo(data.gameaccountid());
    }

    if (!gameAccountInfo)
        return ERROR_UTIL_SERVER_INVALID_IDENTITY_ARGS;

    if (gameAccountInfo->IsPermanenetlyBanned)
        return ERROR_GAME_ACCOUNT_BANNED;
    if (gameAccountInfo->IsBanned)
        return ERROR_GAME_ACCOUNT_SUSPENDED;

    ClientBuild::VariantId clientBuildVariant = { };
    Optional<std::array<uint8, 32>> clientSecret;
    if (Variant const* clientInfo = FindParamValue(params, "Param_ClientInfo"))
    {
        std::string_view json = { reinterpret_cast<char const*>(std::get<std::vector<uint8>>(*clientInfo).data()), std::get<std::vector<uint8>>(*clientInfo).size() };
        ::JSON::RealmList::RealmListTicketClientInformation data;
        std::size_t jsonStart = json.find(':');
        if (jsonStart != std::string_view::npos && ::JSON::Deserialize(json.substr(jsonStart + 1), &data))
        {
            if (data.info().secret().size() == 32)
                memcpy(clientSecret.emplace().data(), data.info().secret().data(), data.info().secret().size());

            clientBuildVariant = { .Platform = data.info().platformtype(), .Arch = data.info().clientarch(), .Type = data.info().type() };
        }
    }

    if (!clientSecret)
        return ERROR_WOW_SERVICES_DENIED_REALM_LIST_TICKET;

    session->SetClientInfo(gameAccountInfo->Id, clientBuildVariant, *clientSecret);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_LAST_LOGIN_INFO);
    stmt->setString(0, session->GetRemoteIpAddress().to_string());
    stmt->setUInt8(1, GetLocaleByName(session->GetLocale()));
    stmt->setString(2, session->GetOS());
    stmt->setUInt32(3, session->GetAccountId());

    LoginDatabase.Execute(stmt);

    std::vector<uint8> realmListTicket;
    std::ranges::copy("AuthRealmListTicket\0"sv, std::back_inserter(realmListTicket));
    responseValues.emplace_back("Param_RealmListTicket"sv, std::move(realmListTicket));

    return ERROR_OK;
}

uint32 GameUtilities::GetRealmList(Session const* session,
    std::vector<std::pair<std::string_view, Variant>>& params,
    std::vector<std::pair<std::string_view, Variant>>& responseValues)
{
    std::string subRegionId;
    if (Variant const* subRegion = FindParamValue(params, "Command_RealmListRequest_v1"); subRegion && std::holds_alternative<std::string>(*subRegion))
        subRegionId = std::get<std::string>(*subRegion);

    std::vector<uint8> realmListJson = sRealmList->GetRealmList(session->GetBuild(), session->GetGameAccountInfo()->SecurityLevel, subRegionId);

    if (realmListJson.empty())
        return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

    ::JSON::RealmList::RealmCharacterCountList realmCharacterCounts;
    for (auto const& [realmAddress, count] : session->GetGameAccountInfo()->CharacterCounts)
    {
        ::JSON::RealmList::RealmCharacterCountEntry* countEntry = realmCharacterCounts.add_counts();
        countEntry->set_wowrealmaddress(realmAddress);
        countEntry->set_count(count);
    }

    std::string json = "JSONRealmCharacterCountList:" + ::JSON::Serialize(realmCharacterCounts);

    uLongf compressedLength = compressBound(json.length());
    std::vector<uint8> characterCountsJson(4 + compressedLength);
    *reinterpret_cast<uint32*>(characterCountsJson.data()) = json.length() + 1;

    if (compress(characterCountsJson.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), json.length() + 1) != Z_OK)
        return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

    responseValues.emplace_back("Param_RealmList"sv, std::move(realmListJson));
    responseValues.emplace_back("Param_CharacterCountList"sv, std::move(characterCountsJson));

    return ERROR_OK;
}

uint32 GameUtilities::JoinRealm(Session const* session,
    std::vector<std::pair<std::string_view, Variant>>& params,
    std::vector<std::pair<std::string_view, Variant>>& responseValues)
{
    Variant const* realmAddress = FindParamValue(params, "Param_RealmAddress");
    if (!realmAddress || !std::holds_alternative<uint64>(*realmAddress))
        return ERROR_UTIL_SERVER_UNKNOWN_REALM;

    RealmJoinResult result = sRealmList->JoinRealm(std::get<uint64>(*realmAddress), session->GetBuild(), session->GetBuildVariant(),
        session->GetRemoteIpAddress(), session->GetClientSecret(), GetLocaleByName(session->GetLocale()), session->GetOS(),
        session->GetTimezoneOffset(), session->GetGameAccountInfo()->Name, session->GetGameAccountInfo()->SecurityLevel);

    if (result.Result == ERROR_OK)
    {
        responseValues.emplace_back("Param_RealmJoinTicket"sv, std::move(result.JoinTicket));
        responseValues.emplace_back("Param_ServerAddresses"sv, std::move(result.ServerAddresses));
        responseValues.emplace_back("Param_JoinSecret"sv, std::move(result.JoinSecret));
    }

    return result.Result;
}
}

namespace V1
{
Battlenet::Services::Variant FromProto(bgs::protocol::Variant const& from)
{
    if (from.has_bool_value())
        return from.bool_value();
    if (from.has_int_value())
        return from.int_value();
    if (from.has_float_value())
        return from.float_value();
    if (from.has_string_value())
        return from.string_value();
    if (from.has_blob_value())
        return Variant{ std::in_place_type<std::vector<uint8>>,
            reinterpret_cast<uint8 const*>(from.blob_value().data()),
            reinterpret_cast<uint8 const*>(from.blob_value().data()) + from.blob_value().size() };
    if (from.has_uint_value())
        return from.uint_value();

    return { };
}

void ToProto(Battlenet::Services::Variant const& from, bgs::protocol::Variant* to)
{
    std::visit([to]<typename T>(T const& value)
    {
        if constexpr (std::is_same_v<T, bool>)
            to->set_bool_value(value);
        else if constexpr (std::is_same_v<T, int64>)
            to->set_int_value(value);
        else if constexpr (std::is_same_v<T, double>)
            to->set_float_value(value);
        else if constexpr (std::is_same_v<T, std::string>)
            to->set_string_value(value);
        else if constexpr (std::is_same_v<T, std::vector<uint8>>)
            to->set_blob_value(value.data(), value.size());
        else if constexpr (std::is_same_v<T, uint64>)
            to->set_uint_value(value);
        else
            static_assert(Trinity::dependant_false_v<T>);
    }, from);
}

GameUtilities::GameUtilities(Session* session) : GameUtilitiesService(session)
{
}

uint32 GameUtilities::HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    if (!_session->IsAuthed())
        return ERROR_DENIED;

    std::vector<std::pair<std::string_view, Variant>> params;
    std::vector<std::pair<std::string_view, Variant>> responseValues;

    for (Attribute const& attribute : request->attribute())
    {
        if (!attribute.has_name() || !attribute.has_value())
            continue;

        params.emplace_back(Shared::GameUtilities::ParseParamName(attribute.name()), FromProto(attribute.value()));
    }

    uint32 result = Shared::GameUtilities::HandleClientRequest(_session, params, responseValues);

    for (auto&& [name, value] : responseValues)
    {
        Attribute* attr = response->add_attribute();
        attr->set_name(name.data(), name.length());
        ToProto(value, attr->mutable_value());
    }

    return result;
}

uint32 GameUtilities::HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& /*continuation*/)
{
    if (!_session->IsAuthed())
        return ERROR_DENIED;

    std::vector<Variant> responseValues;

    uint32 result = Shared::GameUtilities::HandleGetAllValuesForAttribute(_session, Shared::GameUtilities::ParseParamName(request->attribute_key()), responseValues);

    for (Variant& value : responseValues)
        ToProto(value, response->add_attribute_value());

    return result;
}
}
}
