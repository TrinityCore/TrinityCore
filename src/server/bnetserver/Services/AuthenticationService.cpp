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

#include "AuthenticationService.h"
#include "BattlenetRpcErrorCodes.h"
#include "Client/api/client/v2/authentication_listener.pb.h"
#include "Client/challenge_service.pb.h"
#include "CryptoRandom.h"
#include "DatabaseEnv.h"
#include "IPLocation.h"
#include "LoginRESTService.h"
#include "Session.h"
#include "SslContext.h"
#include "Timezone.h"
#include <rapidjson/document.h>

namespace Battlenet::Services
{
namespace Shared
{
uint32 Authentication::HandleLogon(Session* session, ClientBuild::Program::Id program, std::string_view platform,
    std::string_view locale, uint32 applicationVersion, std::string_view deviceId)
{
    if (program != ClientBuild::Program::WoW)
    {
        TC_LOG_DEBUG("session", "[Battlenet::Authentication::LogonRequest] {} attempted to log in with game other than WoW (using {})!", session->GetClientInfo(), program);
        return ERROR_BAD_PROGRAM;
    }

    if (!ClientBuild::Platform::IsValid(platform))
    {
        TC_LOG_DEBUG("session", "[Battlenet::Authentication::LogonRequest] {} attempted to log in from an unsupported platform (using {})!", session->GetClientInfo(), platform);
        return ERROR_BAD_PLATFORM;
    }

    if (!IsValidLocale(GetLocaleByName(locale)))
    {
        TC_LOG_DEBUG("session", "[Battlenet::Authentication::LogonRequest] {} attempted to log in with unsupported locale (using {})!", session->GetClientInfo(), locale);
        return ERROR_BAD_LOCALE;
    }

    Minutes timezoneOffset = [&]
    {
        if (deviceId.empty())
            return 0min;

        rapidjson::Document doc;
        doc.Parse(deviceId.data(), deviceId.length());
        if (doc.HasParseError())
            return 0min;

        auto itr = doc.FindMember("UTCO");
        if (itr == doc.MemberEnd())
            return 0min;

        if (!itr->value.IsUint())
            return 0min;

        return Trinity::Timezone::GetOffsetByHash(itr->value.GetUint());
    }();

    session->OnLogon(platform, locale, applicationVersion, timezoneOffset);
    return ERROR_OK;
}

uint32 Authentication::HandleVerifyAuthToken(Session* session, std::string_view authToken,
    std::function<void(uint32)> sendResponse, std::function<void(AccountInfo const*, std::string_view)> sendLogonComplete)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_INFO);
    stmt->setString(0, authToken);

    std::shared_ptr<AccountInfo> accountInfo = std::make_shared<AccountInfo>();
    session->QueueQuery(LoginDatabase.AsyncQuery(stmt).WithChainingPreparedCallback([accountInfo, sendResponse](QueryCallback& callback, PreparedQueryResult result)
    {
        if (!result)
        {
            sendResponse(ERROR_DENIED);
            return;
        }

        accountInfo->LoadResult(result);

        if (accountInfo->LoginTicketExpiry < time(nullptr))
        {
            sendResponse(ERROR_TIMED_OUT);
            return;
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_BNET_ID);
        stmt->setUInt32(0, accountInfo->Id);
        callback.SetNextQuery(LoginDatabase.AsyncQuery(stmt));
    })
    .WithChainingPreparedCallback([accountInfo](QueryCallback& callback, PreparedQueryResult characterCountsResult)
    {
        if (characterCountsResult)
        {
            do
            {
                Field* fields = characterCountsResult->Fetch();
                accountInfo->GameAccounts[fields[0].GetUInt32()]
                    .CharacterCounts[Battlenet::RealmHandle{ fields[3].GetUInt8(), fields[4].GetUInt8(), fields[2].GetUInt32() }.GetAddress()] = fields[1].GetUInt8();

            } while (characterCountsResult->NextRow());
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_LAST_PLAYER_CHARACTERS);
        stmt->setUInt32(0, accountInfo->Id);
        callback.SetNextQuery(LoginDatabase.AsyncQuery(stmt));
    })
    .WithPreparedCallback([session, accountInfo, sendResponse, sendLogonComplete](PreparedQueryResult lastPlayerCharactersResult)
    {
        if (lastPlayerCharactersResult)
        {
            do
            {
                Field* fields = lastPlayerCharactersResult->Fetch();
                Battlenet::RealmHandle realmId{ fields[1].GetUInt8(), fields[2].GetUInt8(), fields[3].GetUInt32() };
                Battlenet::LastPlayedCharacterInfo& lastPlayedCharacter = accountInfo->GameAccounts[fields[0].GetUInt32()]
                    .LastPlayedCharacters[realmId.GetSubRegionAddress()];

                lastPlayedCharacter.RealmId = realmId;
                lastPlayedCharacter.CharacterName = fields[4].GetString();
                lastPlayedCharacter.CharacterGUID = fields[5].GetUInt64();
                lastPlayedCharacter.LastPlayedTime = fields[6].GetUInt32();

            } while (lastPlayerCharactersResult->NextRow());
        }

        std::string ip_address = session->GetRemoteIpAddress().to_string();

        std::string ipCountry;
        if (IpLocationRecord const* location = sIPLocation->GetLocationRecord(ip_address))
            ipCountry = location->CountryCode;

        // If the IP is 'locked', check that the player comes indeed from the correct IP address
        if (accountInfo->IsLockedToIP)
        {
            TC_LOG_DEBUG("session", "[Session::HandleVerifyWebCredentials] Account '{}' is locked to IP - '{}' is logging in from '{}'",
                accountInfo->Login, accountInfo->LastIP, ip_address);

            if (accountInfo->LastIP != ip_address)
            {
                sendResponse(ERROR_RISK_ACCOUNT_LOCKED);
                return;
            }
        }
        else
        {
            TC_LOG_DEBUG("session", "[Session::HandleVerifyWebCredentials] Account '{}' is not locked to ip", accountInfo->Login);
            if (accountInfo->LockCountry.empty() || accountInfo->LockCountry == "00")
                TC_LOG_DEBUG("session", "[Session::HandleVerifyWebCredentials] Account '{}' is not locked to country", accountInfo->Login);
            else if (!accountInfo->LockCountry.empty() && !ipCountry.empty())
            {
                TC_LOG_DEBUG("session", "[Session::HandleVerifyWebCredentials] Account '{}' is locked to country: '{}' Player country is '{}'",
                    accountInfo->Login, accountInfo->LockCountry, ipCountry);

                if (ipCountry != accountInfo->LockCountry)
                {
                    sendResponse(ERROR_RISK_ACCOUNT_LOCKED);
                    return;
                }
            }
        }

        // If the account is banned, reject the logon attempt
        if (accountInfo->IsBanned)
        {
            if (accountInfo->IsPermanenetlyBanned)
            {
                TC_LOG_DEBUG("session", "{} [Session::HandleVerifyWebCredentials] Banned account {} tried to login!", session->GetClientInfo(), accountInfo->Login);
                sendResponse(ERROR_GAME_ACCOUNT_BANNED);
                return;
            }
            else
            {
                TC_LOG_DEBUG("session", "{} [Session::HandleVerifyWebCredentials] Temporarily banned account {} tried to login!", session->GetClientInfo(), accountInfo->Login);
                sendResponse(ERROR_GAME_ACCOUNT_SUSPENDED);
                return;
            }
        }

        sendResponse(ERROR_OK);
        sendLogonComplete(accountInfo.get(), ipCountry);

        session->OnLogonSuccess(std::move(accountInfo), ipCountry);
    }));

    return ERROR_OK;
}

uint32 Authentication::HandleGenerateAuthToken(Session* session, std::function<void(std::string_view)> sendResponse)
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_EXISTING_AUTHENTICATION_BY_ID);
    stmt->setUInt32(0, session->GetAccountId());

    session->QueueQuery(LoginDatabase.AsyncQuery(stmt).WithPreparedCallback([sendResponse = std::move(sendResponse)](PreparedQueryResult result)
    {
        // just send existing credentials back (not the best but it works for now with them being stored in db)
        sendResponse((*result)[0].GetStringView());
    }));

    return ERROR_OK;
}
}

namespace V1
{
Authentication::Authentication(Session* session) : AuthenticationService(session)
{
}

uint32 Authentication::HandleLogon(authentication::v1::LogonRequest const* request, NoData* /*response*/, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    ClientBuild::Program::Id titleId = ClientBuild::Program::Id::FromString(request->program());
    std::string_view deviceId;

    if (request->has_device_id())
        deviceId = request->device_id();

    uint32 result = Shared::Authentication::HandleLogon(_session, titleId, request->platform(), request->locale(), request->application_version(), deviceId);
    if (result == ERROR_OK)
    {
        if (request->has_cached_web_credentials())
            return HandleVerifyWebCredentials(request->cached_web_credentials(), continuation);

        challenge::v1::ChallengeExternalRequest externalChallenge;
        externalChallenge.set_payload_type("web_auth_url");
        externalChallenge.set_payload(Trinity::StringFormat("http{}://{}:{}/bnetserver/login/", !SslContext::UsesDevWildcardCertificate() ? "s" : "",
            sLoginService.GetHostnameForClient(_session->GetRemoteIpAddress()), sLoginService.GetPort()));
        Service<challenge::v1::ChallengeListener>(_session).OnExternalChallenge(&externalChallenge);
    }

    return result;
}

uint32 Authentication::HandleVerifyWebCredentials(authentication::v1::VerifyWebCredentialsRequest const* request, NoData* /*response*/, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    if (!request->has_web_credentials())
        return ERROR_DENIED;

    return HandleVerifyWebCredentials(request->web_credentials(), continuation);
}

uint32 Authentication::HandleVerifyWebCredentials(std::string_view webCredentials,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    return Shared::Authentication::HandleVerifyAuthToken(_session, webCredentials, [session = _session, continuation = std::move(continuation)](uint32 result) mutable
    {
        Authentication asyncContinuationService(session);
        NoData response;
        continuation(&asyncContinuationService, result, &response);
    },
    [session = _session](AccountInfo const* accountInfo, std::string_view country)
    {
        authentication::v1::LogonResult logonResult;
        logonResult.set_error_code(0);
        logonResult.mutable_account_id()->set_low(accountInfo->Id);
        logonResult.mutable_account_id()->set_high(UI64LIT(0x100000000000000));
        for (auto const& [id, gameAccountInfo] : accountInfo->GameAccounts)
        {
            EntityId* gameAccountId = logonResult.add_game_account_id();
            gameAccountId->set_low(gameAccountInfo.Id);
            gameAccountId->set_high(UI64LIT(0x200000200576F57));
        }

        if (!country.empty())
            logonResult.set_geoip_country(country.data(), country.size());

        std::array<uint8, 64> k = Trinity::Crypto::GetRandomBytes<64>();
        logonResult.set_session_key(k.data(), 64);

        Service<authentication::v1::AuthenticationListener>(session).OnLogonComplete(&logonResult);
    });
}

uint32 Authentication::HandleGenerateWebCredentials(authentication::v1::GenerateWebCredentialsRequest const* /*request*/, authentication::v1::GenerateWebCredentialsResponse* /*response*/, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    if (!_session->IsAuthed())
        return ERROR_DENIED;

    return Shared::Authentication::HandleGenerateAuthToken(_session, [session = _session, continuation = std::move(continuation)](std::string_view webCredentials)
    {
        Authentication asyncContinuationService(session);
        authentication::v1::GenerateWebCredentialsResponse response;
        response.set_web_credentials(webCredentials.data(), webCredentials.size());
        continuation(&asyncContinuationService, ERROR_OK, &response);
    });
}
}

namespace V2
{
Authentication::Authentication(Session* session) : AuthenticationService(session)
{
}

uint32 Authentication::HandleLogon(authentication::v2::client::LogonRequest const* request, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    ClientBuild::Program::Id titleId{ request->title_id() };
    std::string_view deviceId;
    std::string_view cachedAuthToken;

    if (request->has_logon_options())
    {
        authentication::v2::client::LogonOptions const& logonOptions = request->logon_options();
        if (logonOptions.has_device_id())
            deviceId = logonOptions.device_id();

        if (logonOptions.has_auth_token())
            cachedAuthToken = logonOptions.auth_token();
    }

    uint32 result = Shared::Authentication::HandleLogon(_session, titleId, request->platform(), request->locale(), request->application_version(), deviceId);
    if (result == ERROR_OK)
    {
        if (!cachedAuthToken.empty())
            return HandleVerifyAuthToken(cachedAuthToken, continuation);

        authentication::v2::client::ExternalChallengeNotification externalChallenge;
        externalChallenge.set_payload_type("web_auth_url");
        externalChallenge.set_payload(Trinity::StringFormat("http{}://{}:{}/bnetserver/login/", !SslContext::UsesDevWildcardCertificate() ? "s" : "",
            sLoginService.GetHostnameForClient(_session->GetRemoteIpAddress()), sLoginService.GetPort()));
        Service<authentication::v2::client::AuthenticationListener>(_session).OnExternalChallenge(&externalChallenge);
    }

    return result;
}

uint32 Authentication::HandleVerifyAuthToken(authentication::v2::client::VerifyAuthTokenRequest const* request, NoData* /*response*/,
    std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    if (!request->has_auth_token())
        return ERROR_DENIED;

    return HandleVerifyAuthToken(request->auth_token(), continuation);
}

uint32 Authentication::HandleGenerateAuthToken(authentication::v2::client::GenerateAuthTokenRequest const* /*request*/,
    authentication::v2::client::GenerateAuthTokenResponse* /*response*/, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    if (!_session->IsAuthed())
        return ERROR_DENIED;

    return Shared::Authentication::HandleGenerateAuthToken(_session, [session = _session, continuation = std::move(continuation)](std::string_view webCredentials)
    {
        Authentication asyncContinuationService(session);
        authentication::v2::client::GenerateAuthTokenResponse response;
        response.set_auth_token(webCredentials.data(), webCredentials.size());
        continuation(&asyncContinuationService, ERROR_OK, &response);
    });
}

uint32 Authentication::HandleVerifyAuthToken(std::string_view authToken, std::function<void(ServiceBase*, uint32, google::protobuf::Message const*)>& continuation)
{
    return Shared::Authentication::HandleVerifyAuthToken(_session, authToken, [session = _session, continuation = std::move(continuation)](uint32 result) mutable
    {
        Authentication asyncContinuationService(session);
        NoData response;
        continuation(&asyncContinuationService, result, &response);
    },
    [session = _session](AccountInfo const* accountInfo, std::string_view country)
    {
        authentication::v2::client::LogonCompleteNotification logonResult;
        logonResult.set_error_code(0);
        authentication::v2::client::LogonRecord* logonRecord = logonResult.mutable_record();
        logonRecord->set_account_id(accountInfo->Id);
        for (auto const& [id, gameAccountInfo] : accountInfo->GameAccounts)
        {
            account::v2::GameAccountHandle* gameAccount = logonRecord->add_game_account();
            gameAccount->set_id(gameAccountInfo.Id);
            gameAccount->set_title_id(ClientBuild::Program::WoW);
            gameAccount->set_region(2);
        }

        if (!country.empty())
            logonRecord->set_geoip_country(country.data(), country.size());

        std::array<uint8, 64> k = Trinity::Crypto::GetRandomBytes<64>();
        logonRecord->set_session_key(k.data(), 64);

        Service<authentication::v2::client::AuthenticationListener>(session).OnLogonComplete(&logonResult);
    });
}
}
}
