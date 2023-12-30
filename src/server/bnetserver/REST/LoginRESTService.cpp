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

#include "LoginRESTService.h"
#include "Base64.h"
#include "Configuration/Config.h"
#include "CryptoHash.h"
#include "CryptoRandom.h"
#include "DatabaseEnv.h"
#include "IpNetwork.h"
#include "IteratorPair.h"
#include "ProtobufJSON.h"
#include "Resolver.h"
#include "Timer.h"
#include "Util.h"

namespace Battlenet
{
LoginRESTService& LoginRESTService::Instance()
{
    static LoginRESTService instance;
    return instance;
}

bool LoginRESTService::StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int32 threadCount)
{
    if (!HttpService::StartNetwork(ioContext, bindIp, port, threadCount))
        return false;

    using Trinity::Net::Http::RequestHandlerFlag;

    RegisterHandler(boost::beast::http::verb::get, "/bnetserver/login/", [this](std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context)
    {
        return HandleGetForm(std::move(session), context);
    });

    RegisterHandler(boost::beast::http::verb::get, "/bnetserver/gameAccounts/", [](std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context)
    {
        return HandleGetGameAccounts(std::move(session), context);
    });

    RegisterHandler(boost::beast::http::verb::get, "/bnetserver/portal/", [this](std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context)
    {
        return HandleGetPortal(std::move(session), context);
    });

    RegisterHandler(boost::beast::http::verb::post, "/bnetserver/login/", [this](std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context)
    {
        return HandlePostLogin(std::move(session), context);
    }, RequestHandlerFlag::DoNotLogRequestContent);

    RegisterHandler(boost::beast::http::verb::post, "/bnetserver/refreshLoginTicket/", [this](std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context)
    {
        return HandlePostRefreshLoginTicket(std::move(session), context);
    });

    _bindIP = bindIp;
    _port = port;

    Trinity::Asio::Resolver resolver(ioContext);

    _hostnames[0] = sConfigMgr->GetStringDefault("LoginREST.ExternalAddress", "127.0.0.1");
    Optional<boost::asio::ip::tcp::endpoint> externalAddress = resolver.Resolve(boost::asio::ip::tcp::v4(), _hostnames[0], std::to_string(_port));
    if (!externalAddress)
    {
        TC_LOG_ERROR("server.http.login", "Could not resolve LoginREST.ExternalAddress {}", _hostnames[0]);
        return false;
    }

    _addresses[0] = externalAddress->address();

    _hostnames[1] = sConfigMgr->GetStringDefault("LoginREST.LocalAddress", "127.0.0.1");
    Optional<boost::asio::ip::tcp::endpoint> localAddress = resolver.Resolve(boost::asio::ip::tcp::v4(), _hostnames[1], std::to_string(_port));
    if (!localAddress)
    {
        TC_LOG_ERROR("server.http.login", "Could not resolve LoginREST.LocalAddress {}", _hostnames[1]);
        return false;
    }

    _addresses[1] = localAddress->address();

    // set up form inputs
    JSON::Login::FormInput* input;
    _formInputs.set_type(JSON::Login::LOGIN_FORM);
    input = _formInputs.add_inputs();
    input->set_input_id("account_name");
    input->set_type("text");
    input->set_label("E-mail");
    input->set_max_length(320);

    input = _formInputs.add_inputs();
    input->set_input_id("password");
    input->set_type("password");
    input->set_label("Password");
    input->set_max_length(128);

    input = _formInputs.add_inputs();
    input->set_input_id("log_in_submit");
    input->set_type("submit");
    input->set_label("Log In");

    _loginTicketDuration = sConfigMgr->GetIntDefault("LoginREST.TicketDuration", 3600);

    MigrateLegacyPasswordHashes();

    _acceptor->AsyncAcceptWithCallback<&LoginRESTService::OnSocketAccept>();
    return true;
}

std::string const& LoginRESTService::GetHostnameForClient(boost::asio::ip::address const& address) const
{
    if (auto addressIndex = Trinity::Net::SelectAddressForClient(address, _addresses))
        return _hostnames[*addressIndex];

    if (address.is_loopback())
        return _hostnames[1];

    return _hostnames[0];
}

std::string LoginRESTService::ExtractAuthorization(HttpRequest const& request)
{
    using namespace std::string_view_literals;

    std::string ticket;
    auto itr = request.find(boost::beast::http::field::authorization);
    if (itr == request.end())
        return ticket;

    std::string_view authorization = Trinity::Net::Http::ToStdStringView(itr->value());
    constexpr std::string_view BASIC_PREFIX = "Basic "sv;

    if (authorization.starts_with(BASIC_PREFIX))
        authorization.remove_prefix(BASIC_PREFIX.length());

    Optional<std::vector<uint8>> decoded = Trinity::Encoding::Base64::Decode(authorization);
    if (!decoded)
        return ticket;

    std::string_view decodedHeader(reinterpret_cast<char const*>(decoded->data()), decoded->size());

    if (std::size_t ticketEnd = decodedHeader.find(':'); ticketEnd != std::string_view::npos)
        decodedHeader.remove_suffix(decodedHeader.length() - ticketEnd);

    ticket = decodedHeader;
    return ticket;
}

LoginRESTService::RequestHandlerResult LoginRESTService::HandleGetForm(std::shared_ptr<LoginHttpSession> /*session*/, HttpRequestContext& context) const
{
    context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
    context.response.body() = ::JSON::Serialize(_formInputs);
    return RequestHandlerResult::Handled;
}

LoginRESTService::RequestHandlerResult LoginRESTService::HandleGetGameAccounts(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context)
{
    std::string ticket = ExtractAuthorization(context.request);
    if (ticket.empty())
        return HandleUnauthorized(std::move(session), context);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNT_LIST);
    stmt->setString(0, ticket);
    session->QueueQuery(LoginDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([session, context = std::move(context)](PreparedQueryResult result) mutable
    {
        JSON::Login::GameAccountList gameAccounts;
        if (result)
        {
            auto formatDisplayName = [](char const* name) -> std::string
            {
                if (char const* hashPos = strchr(name, '#'))
                    return std::string("WoW") + ++hashPos;
                else
                    return name;
            };

            time_t now = time(nullptr);
            do
            {
                Field* fields = result->Fetch();
                JSON::Login::GameAccountInfo* gameAccount = gameAccounts.add_game_accounts();
                gameAccount->set_display_name(formatDisplayName(fields[0].GetCString()));
                gameAccount->set_expansion(fields[1].GetUInt8());
                if (!fields[2].IsNull())
                {
                    uint32 banDate = fields[2].GetUInt32();
                    uint32 unbanDate = fields[3].GetUInt32();
                    gameAccount->set_is_suspended(unbanDate > now);
                    gameAccount->set_is_banned(banDate == unbanDate);
                    gameAccount->set_suspension_reason(fields[4].GetString());
                    gameAccount->set_suspension_expires(unbanDate);
                }
            } while (result->NextRow());
        }

        context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
        context.response.body() = ::JSON::Serialize(gameAccounts);
        session->SendResponse(context);
    }));

    return RequestHandlerResult::Async;
}

LoginRESTService::RequestHandlerResult LoginRESTService::HandleGetPortal(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const
{
    context.response.set(boost::beast::http::field::content_type, "text/plain");
    context.response.body() = Trinity::StringFormat("{}:{}", GetHostnameForClient(session->GetRemoteIpAddress()), sConfigMgr->GetIntDefault("BattlenetPort", 1119));
    return RequestHandlerResult::Handled;
}

LoginRESTService::RequestHandlerResult LoginRESTService::HandlePostLogin(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const
{
    std::shared_ptr<JSON::Login::LoginForm> loginForm = std::make_shared<JSON::Login::LoginForm>();
    if (!::JSON::Deserialize(context.request.body(), loginForm.get()))
    {
        JSON::Login::LoginResult loginResult;
        loginResult.set_authentication_state(JSON::Login::LOGIN);
        loginResult.set_error_code("UNABLE_TO_DECODE");
        loginResult.set_error_message("There was an internal error while connecting to Battle.net. Please try again later.");

        context.response.result(boost::beast::http::status::bad_request);
        context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
        context.response.body() = ::JSON::Serialize(loginResult);
        session->SendResponse(context);

        return RequestHandlerResult::Handled;
    }

    auto getInputValue = [](JSON::Login::LoginForm const* loginForm, std::string_view inputId) -> std::string
    {
        for (int32 i = 0; i < loginForm->inputs_size(); ++i)
            if (loginForm->inputs(i).input_id() == inputId)
                return loginForm->inputs(i).value();
        return "";
    };

    std::string login(getInputValue(loginForm.get(), "account_name"));
    Utf8ToUpperOnlyLatin(login);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_AUTHENTICATION);
    stmt->setString(0, login);

    session->QueueQuery(LoginDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([this, session, context = std::move(context), loginForm = std::move(loginForm), getInputValue](QueryCallback& callback, PreparedQueryResult result) mutable
    {
        if (!result)
        {
            JSON::Login::LoginResult loginResult;
            loginResult.set_authentication_state(JSON::Login::DONE);
            context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
            context.response.body() = ::JSON::Serialize(loginResult);
            session->SendResponse(context);
            return;
        }

        std::string login(getInputValue(loginForm.get(), "account_name"));
        Utf8ToUpperOnlyLatin(login);
        bool passwordCorrect = false;

        Field* fields = result->Fetch();
        uint32 accountId = fields[0].GetUInt32();
        if (!session->GetSessionState()->Srp)
        {
            SrpVersion version = SrpVersion(fields[1].GetInt8());
            std::string srpUsername = ByteArrayToHexStr(Trinity::Crypto::SHA256::GetDigestOf(login));
            Trinity::Crypto::SRP::Salt s = fields[2].GetBinary<Trinity::Crypto::SRP::SALT_LENGTH>();
            Trinity::Crypto::SRP::Verifier v = fields[3].GetBinary();
            session->GetSessionState()->Srp = CreateSrpImplementation(version, SrpHashFunction::Sha256, srpUsername, s, v);

            std::string password(getInputValue(loginForm.get(), "password"));
            if (version == SrpVersion::v1)
                Utf8ToUpperOnlyLatin(password);

            passwordCorrect = session->GetSessionState()->Srp->CheckCredentials(srpUsername, password);
        }

        uint32 failedLogins = fields[4].GetUInt32();
        std::string loginTicket = fields[5].GetString();
        uint32 loginTicketExpiry = fields[6].GetUInt32();
        bool isBanned = fields[7].GetUInt64() != 0;

        if (!passwordCorrect)
        {
            if (!isBanned)
            {
                std::string ip_address = session->GetRemoteIpAddress().to_string();
                uint32 maxWrongPassword = uint32(sConfigMgr->GetIntDefault("WrongPass.MaxCount", 0));

                if (sConfigMgr->GetBoolDefault("WrongPass.Logging", false))
                    TC_LOG_DEBUG("server.http.login", "[{}, Account {}, Id {}] Attempted to connect with wrong password!", ip_address, login, accountId);

                if (maxWrongPassword)
                {
                    LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();
                    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_FAILED_LOGINS);
                    stmt->setUInt32(0, accountId);
                    trans->Append(stmt);

                    ++failedLogins;

                    TC_LOG_DEBUG("server.http.login", "MaxWrongPass : {}, failed_login : {}", maxWrongPassword, accountId);

                    if (failedLogins >= maxWrongPassword)
                    {
                        BanMode banType = BanMode(sConfigMgr->GetIntDefault("WrongPass.BanType", uint16(BanMode::BAN_IP)));
                        int32 banTime = sConfigMgr->GetIntDefault("WrongPass.BanTime", 600);

                        if (banType == BanMode::BAN_ACCOUNT)
                        {
                            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ACCOUNT_AUTO_BANNED);
                            stmt->setUInt32(0, accountId);
                        }
                        else
                        {
                            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_IP_AUTO_BANNED);
                            stmt->setString(0, ip_address);
                        }

                        stmt->setUInt32(1, banTime);
                        trans->Append(stmt);

                        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_RESET_FAILED_LOGINS);
                        stmt->setUInt32(0, accountId);
                        trans->Append(stmt);
                    }

                    LoginDatabase.CommitTransaction(trans);
                }
            }

            JSON::Login::LoginResult loginResult;
            loginResult.set_authentication_state(JSON::Login::DONE);

            context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
            context.response.body() = ::JSON::Serialize(loginResult);
            session->SendResponse(context);
            return;
        }

        if (loginTicket.empty() || loginTicketExpiry < time(nullptr))
            loginTicket = "TC-" + ByteArrayToHexStr(Trinity::Crypto::GetRandomBytes<20>());

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_AUTHENTICATION);
        stmt->setString(0, loginTicket);
        stmt->setUInt32(1, time(nullptr) + _loginTicketDuration);
        stmt->setUInt32(2, accountId);
        callback.WithPreparedCallback([session, context = std::move(context), loginTicket = std::move(loginTicket)](PreparedQueryResult) mutable
        {
            JSON::Login::LoginResult loginResult;
            loginResult.set_authentication_state(JSON::Login::DONE);
            loginResult.set_login_ticket(loginTicket);

            context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
            context.response.body() = ::JSON::Serialize(loginResult);
            session->SendResponse(context);
        }).SetNextQuery(LoginDatabase.AsyncQuery(stmt));
    }));

    return RequestHandlerResult::Async;
}

LoginRESTService::RequestHandlerResult LoginRESTService::HandlePostRefreshLoginTicket(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const
{
    std::string ticket = ExtractAuthorization(context.request);
    if (ticket.empty())
        return HandleUnauthorized(std::move(session), context);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_EXISTING_AUTHENTICATION);
    stmt->setString(0, ticket);
    session->QueueQuery(LoginDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([this, session, context = std::move(context), ticket = std::move(ticket)](PreparedQueryResult result) mutable
    {
        JSON::Login::LoginRefreshResult loginRefreshResult;
        if (result)
        {
            uint32 loginTicketExpiry = (*result)[0].GetUInt32();
            time_t now = time(nullptr);
            if (loginTicketExpiry > now)
            {
                loginRefreshResult.set_login_ticket_expiry(now + _loginTicketDuration);

                LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_EXISTING_AUTHENTICATION);
                stmt->setUInt32(0, uint32(now + _loginTicketDuration));
                stmt->setString(1, ticket);
                LoginDatabase.Execute(stmt);
            }
            else
                loginRefreshResult.set_is_expired(true);
        }
        else
            loginRefreshResult.set_is_expired(true);

        context.response.set(boost::beast::http::field::content_type, "application/json;charset=utf-8");
        context.response.body() = ::JSON::Serialize(loginRefreshResult);
        session->SendResponse(context);
    }));

    return RequestHandlerResult::Async;
}

std::unique_ptr<Trinity::Crypto::SRP::BnetSRP6Base> LoginRESTService::CreateSrpImplementation(SrpVersion version, SrpHashFunction hashFunction,
    std::string const& username, Trinity::Crypto::SRP::Salt const& salt, Trinity::Crypto::SRP::Verifier const& verifier)
{
    if (version == SrpVersion::v2)
    {
        if (hashFunction == SrpHashFunction::Sha256)
            return std::make_unique<Trinity::Crypto::SRP::BnetSRP6v2<Trinity::Crypto::SHA256>>(username, salt, verifier);
        if (hashFunction == SrpHashFunction::Sha512)
            return std::make_unique<Trinity::Crypto::SRP::BnetSRP6v2<Trinity::Crypto::SHA512>>(username, salt, verifier);
    }

    if (version == SrpVersion::v1)
    {
        if (hashFunction == SrpHashFunction::Sha256)
            return std::make_unique<Trinity::Crypto::SRP::BnetSRP6v1<Trinity::Crypto::SHA256>>(username, salt, verifier);
        if (hashFunction == SrpHashFunction::Sha512)
            return std::make_unique<Trinity::Crypto::SRP::BnetSRP6v1<Trinity::Crypto::SHA512>>(username, salt, verifier);
    }

    return nullptr;
}

std::shared_ptr<Trinity::Net::Http::SessionState> LoginRESTService::CreateNewSessionState(boost::asio::ip::address const& address)
{
    std::shared_ptr<LoginSessionState> state = std::make_shared<LoginSessionState>();
    InitAndStoreSessionState(state, address);
    return state;
}

void LoginRESTService::OnSocketAccept(boost::asio::ip::tcp::socket&& sock, uint32 threadIndex)
{
    sLoginService.OnSocketOpen(std::move(sock), threadIndex);
}

void LoginRESTService::MigrateLegacyPasswordHashes() const
{
    if (!LoginDatabase.Query("SELECT 1 FROM information_schema.COLUMNS WHERE TABLE_SCHEMA = SCHEMA() AND TABLE_NAME = 'battlenet_accounts' AND COLUMN_NAME = 'sha_pass_hash'"))
        return;

    TC_LOG_INFO(_logger, "Updating password hashes...");
    uint32 const start = getMSTime();
    // the auth update query nulls salt/verifier if they cannot be converted
    // if they are non-null but s/v have been cleared, that means a legacy tool touched our auth DB (otherwise, the core might've done it itself, it used to use those hacks too)
    QueryResult result = LoginDatabase.Query("SELECT id, sha_pass_hash, IF((salt IS null) OR (verifier IS null), 0, 1) AS shouldWarn FROM battlenet_accounts WHERE sha_pass_hash != DEFAULT(sha_pass_hash) OR salt IS NULL OR verifier IS NULL");
    if (!result)
    {
        TC_LOG_INFO(_logger, ">> No password hashes to update - this took us {} ms to realize", GetMSTimeDiffToNow(start));
        return;
    }

    bool hadWarning = false;
    uint32 c = 0;
    LoginDatabaseTransaction tx = LoginDatabase.BeginTransaction();
    do
    {
        uint32 const id = (*result)[0].GetUInt32();

        Trinity::Crypto::SRP::Salt salt = Trinity::Crypto::GetRandomBytes<Trinity::Crypto::SRP::SALT_LENGTH>();
        BigNumber x = Trinity::Crypto::SHA256::GetDigestOf(salt, HexStrToByteArray<Trinity::Crypto::SHA256::DIGEST_LENGTH>((*result)[1].GetString(), true));
        Trinity::Crypto::SRP::Verifier verifier = Trinity::Crypto::SRP::BnetSRP6v1Base::g.ModExp(x, Trinity::Crypto::SRP::BnetSRP6v1Base::N).ToByteVector();

        if ((*result)[2].GetInt64())
        {
            if (!hadWarning)
            {
                hadWarning = true;
                TC_LOG_WARN(_logger,
                    "       ========\n"
                    "(!) You appear to be using an outdated external account management tool.\n"
                    "(!) Update your external tool.\n"
                    "(!!) If no update is available, refer your tool's developer to https://github.com/TrinityCore/TrinityCore/issues/25157.\n"
                    "       ========");
            }
        }

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_LOGON);
        stmt->setInt8(0, AsUnderlyingType(SrpVersion::v1));
        stmt->setBinary(1, salt);
        stmt->setBinary(2, verifier);
        stmt->setUInt32(3, id);
        tx->Append(stmt);

        tx->Append(Trinity::StringFormat("UPDATE battlenet_accounts SET sha_pass_hash = DEFAULT(sha_pass_hash) WHERE id = {}", id).c_str());

        if (tx->GetSize() >= 10000)
        {
            LoginDatabase.CommitTransaction(tx);
            tx = LoginDatabase.BeginTransaction();
        }

        ++c;
    } while (result->NextRow());
    LoginDatabase.CommitTransaction(tx);

    TC_LOG_INFO(_logger, ">> {} password hashes updated in {} ms", c, GetMSTimeDiffToNow(start));
}
}
