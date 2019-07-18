/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Configuration/Config.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "IpNetwork.h"
#include "ProtobufJSON.h"
#include "Realm.h"
#include "Resolver.h"
#include "SessionManager.h"
#include "SHA1.h"
#include "SHA256.h"
#include "SslContext.h"
#include "Util.h"
#include "httpget.h"
#include "httppost.h"
#include "soapH.h"

int ns1__executeCommand(soap*, char*, char**) { return SOAP_OK; }

class AsyncRequest
{
public:
    AsyncRequest(soap const& server) : _client(server), _responseStatus(0) { }

    AsyncRequest(AsyncRequest const&) = delete;
    AsyncRequest& operator=(AsyncRequest const&) = delete;
    AsyncRequest(AsyncRequest&&) = default;
    AsyncRequest& operator=(AsyncRequest&&) = default;

    bool InvokeIfReady()
    {
        ASSERT(_callback);
        return _callback->InvokeIfReady() == QueryCallback::Completed;
    }

    soap* GetClient() { return &_client; }
    void SetCallback(std::unique_ptr<QueryCallback> callback) { _callback = std::move(callback); }
    int32 GetResponseStatus() const { return _responseStatus; }
    void SetResponseStatus(int32 responseStatus) { _responseStatus = responseStatus; }

private:
    soap _client;
    std::unique_ptr<QueryCallback> _callback;
    int32 _responseStatus;
};

int32 handle_get_plugin(soap* soapClient)
{
    return sLoginService.HandleHttpRequest(soapClient, "GET", sLoginService._getHandlers);
}

int32 handle_post_plugin(soap* soapClient)
{
    return sLoginService.HandleHttpRequest(soapClient, "POST", sLoginService._postHandlers);
}

bool LoginRESTService::Start(Trinity::Asio::IoContext* ioContext)
{
    _ioContext = ioContext;
    _bindIP = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");
    _port = sConfigMgr->GetIntDefault("LoginREST.Port", 8081);
    if (_port < 0 || _port > 0xFFFF)
    {
        TC_LOG_ERROR("server.rest", "Specified login service port (%d) out of allowed range (1-65535), defaulting to 8081", _port);
        _port = 8081;
    }

    boost::system::error_code ec;
    boost::asio::ip::tcp::resolver resolver(*ioContext);

    std::string configuredAddress = sConfigMgr->GetStringDefault("LoginREST.ExternalAddress", "127.0.0.1");
    Optional<boost::asio::ip::tcp::endpoint> externalAddress = Trinity::Net::Resolve(resolver, boost::asio::ip::tcp::v4(), configuredAddress, std::to_string(_port));
    if (!externalAddress)
    {
        TC_LOG_ERROR("server.rest", "Could not resolve LoginREST.ExternalAddress %s", configuredAddress.c_str());
        return false;
    }

    _externalAddress = *externalAddress;

    configuredAddress = sConfigMgr->GetStringDefault("LoginREST.LocalAddress", "127.0.0.1");
    Optional<boost::asio::ip::tcp::endpoint> localAddress = Trinity::Net::Resolve(resolver, boost::asio::ip::tcp::v4(), configuredAddress, std::to_string(_port));
    if (!localAddress)
    {
        TC_LOG_ERROR("server.rest", "Could not resolve LoginREST.LocalAddress %s", configuredAddress.c_str());
        return false;
    }

    _localAddress = *localAddress;
    _localNetmask = Trinity::Net::GetDefaultNetmaskV4(_localAddress.address().to_v4());

    // set up form inputs
    Battlenet::JSON::Login::FormInput* input;
    _formInputs.set_type(Battlenet::JSON::Login::LOGIN_FORM);
    input = _formInputs.add_inputs();
    input->set_input_id("account_name");
    input->set_type("text");
    input->set_label("E-mail");
    input->set_max_length(320);

    input = _formInputs.add_inputs();
    input->set_input_id("password");
    input->set_type("password");
    input->set_label("Password");
    input->set_max_length(16);

    input = _formInputs.add_inputs();
    input->set_input_id("log_in_submit");
    input->set_type("submit");
    input->set_label("Log In");

    _loginTicketDuration = sConfigMgr->GetIntDefault("LoginREST.TicketDuration", 3600);

    _thread = std::thread(std::bind(&LoginRESTService::Run, this));
    return true;
}

void LoginRESTService::Stop()
{
    _stopped = true;
    _thread.join();
}

boost::asio::ip::tcp::endpoint const& LoginRESTService::GetAddressForClient(boost::asio::ip::address const& address) const
{
    if (address.is_loopback())
        return _localAddress;
    else if (_localAddress.address().is_loopback())
        return _externalAddress;

    if (Trinity::Net::IsInNetwork(_localAddress.address().to_v4(), _localNetmask, address.to_v4()))
        return _localAddress;

    return _externalAddress;
}

void LoginRESTService::Run()
{
    soap soapServer(SOAP_C_UTFSTRING, SOAP_C_UTFSTRING);

    // check every 3 seconds if world ended
    soapServer.accept_timeout = 3;
    soapServer.recv_timeout = 5;
    soapServer.send_timeout = 5;
    if (!soap_valid_socket(soap_bind(&soapServer, _bindIP.c_str(), _port, 100)))
    {
        TC_LOG_ERROR("server.rest", "Couldn't bind to %s:%d", _bindIP.c_str(), _port);
        return;
    }

    TC_LOG_INFO("server.rest", "Login service bound to http://%s:%d", _bindIP.c_str(), _port);

    http_post_handlers handlers[] =
    {
        { "application/json;charset=utf-8", handle_post_plugin },
        { "application/json", handle_post_plugin },
        { nullptr, nullptr }
    };

    _getHandlers["/bnetserver/login/"] = &LoginRESTService::HandleGetForm;
    _getHandlers["/bnetserver/gameAccounts/"] = &LoginRESTService::HandleGetGameAccounts;
    _getHandlers["/bnetserver/portal/"] = &LoginRESTService::HandleGetPortal;

    _postHandlers["/bnetserver/login/"] = &LoginRESTService::HandlePostLogin;
    _postHandlers["/bnetserver/refreshLoginTicket/"] = &LoginRESTService::HandlePostRefreshLoginTicket;

    soap_register_plugin_arg(&soapServer, &http_get, (void*)&handle_get_plugin);
    soap_register_plugin_arg(&soapServer, &http_post, handlers);
    soap_register_plugin_arg(&soapServer, &ContentTypePlugin::Init, (void*)"application/json;charset=utf-8");
    soap_register_plugin_arg(&soapServer, &ResponseCodePlugin::Init, nullptr);

    // Use our already ready ssl context
    soapServer.ctx = Battlenet::SslContext::instance().native_handle();
    soapServer.ssl_flags = SOAP_SSL_RSA;

    while (!_stopped)
    {
        if (!soap_valid_socket(soap_accept(&soapServer)))
            continue;   // ran into an accept timeout

        std::shared_ptr<AsyncRequest> soapClient = std::make_shared<AsyncRequest>(soapServer);
        if (soap_ssl_accept(soapClient->GetClient()) != SOAP_OK)
        {
            TC_LOG_DEBUG("server.rest", "Failed SSL handshake from IP=%s", boost::asio::ip::address_v4(soapClient->GetClient()->ip).to_string().c_str());
            continue;
        }

        TC_LOG_DEBUG("server.rest", "Accepted connection from IP=%s", boost::asio::ip::address_v4(soapClient->GetClient()->ip).to_string().c_str());

        Trinity::Asio::post(*_ioContext, [soapClient]()
        {
            soapClient->GetClient()->user = (void*)&soapClient; // this allows us to make a copy of pointer inside GET/POST handlers to increment reference count
            soap_begin(soapClient->GetClient());
            soap_begin_recv(soapClient->GetClient());
        });
    }

    // and release the context handle here - soap does not own it so it should not free it on exit
    soapServer.ctx = nullptr;

    TC_LOG_INFO("server.rest", "Login service exiting...");
}

int32 LoginRESTService::HandleHttpRequest(soap* soapClient, char const* method, HttpMethodHandlerMap const& handlers)
{
    TC_LOG_DEBUG("server.rest", "[%s:%d] Handling %s request path=\"%s\"",
        boost::asio::ip::address_v4(soapClient->ip).to_string().c_str(), soapClient->port, method, soapClient->path);

    size_t pathLength = strlen(soapClient->path);
    if (char const* queryPart = strchr(soapClient->path, '?'))
        pathLength = queryPart - soapClient->path;

    auto handler = handlers.find(std::string{ soapClient->path, pathLength });
    if (handler != handlers.end())
    {
        int32 status = (this->*handler->second)(*reinterpret_cast<std::shared_ptr<AsyncRequest>*>(soapClient->user));
        if (status != SOAP_OK)
        {
            ResponseCodePlugin::GetForClient(soapClient)->ErrorCode = status;
            return SendResponse(soapClient, Battlenet::JSON::Login::ErrorResponse());
        }

        return SOAP_OK;
    }

    ResponseCodePlugin::GetForClient(soapClient)->ErrorCode = 404;
    return SendResponse(soapClient, Battlenet::JSON::Login::ErrorResponse());
}

int32 LoginRESTService::HandleGetForm(std::shared_ptr<AsyncRequest> request)
{
    return SendResponse(request->GetClient(), _formInputs);
}

int32 LoginRESTService::HandleGetGameAccounts(std::shared_ptr<AsyncRequest> request)
{
    if (!request->GetClient()->userid)
        return 401;

    request->SetCallback(Trinity::make_unique<QueryCallback>(LoginDatabase.AsyncQuery([&] {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_GAME_ACCOUNT_LIST);
        stmt->setString(0, request->GetClient()->userid);
        return stmt;
    }())
        .WithPreparedCallback([this, request](PreparedQueryResult result)
    {
        Battlenet::JSON::Login::GameAccountList response;
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
                Battlenet::JSON::Login::GameAccountInfo* gameAccount = response.add_game_accounts();
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

        SendResponse(request->GetClient(), response);
    })));

    Trinity::Asio::post(*_ioContext, [this, request]() { HandleAsyncRequest(request); });

    return SOAP_OK;
}

int32 LoginRESTService::HandleGetPortal(std::shared_ptr<AsyncRequest> request)
{
    boost::asio::ip::tcp::endpoint const& endpoint = GetAddressForClient(boost::asio::ip::address_v4(request->GetClient()->ip));
    std::string response = Trinity::StringFormat("%s:%d", endpoint.address().to_string().c_str(), sConfigMgr->GetIntDefault("BattlenetPort", 1119));

    soap_response(request->GetClient(), SOAP_FILE);
    soap_send_raw(request->GetClient(), response.c_str(), response.length());
    return soap_end_send(request->GetClient());
}

int32 LoginRESTService::HandlePostLogin(std::shared_ptr<AsyncRequest> request)
{
    char* buf = nullptr;
    size_t len = 0;
    soap_http_body(request->GetClient(), &buf, &len);

    Battlenet::JSON::Login::LoginForm loginForm;
    if (!buf || !JSON::Deserialize(buf, &loginForm))
    {
        ResponseCodePlugin::GetForClient(request->GetClient())->ErrorCode = 400;

        Battlenet::JSON::Login::LoginResult loginResult;
        loginResult.set_authentication_state(Battlenet::JSON::Login::LOGIN);
        loginResult.set_error_code("UNABLE_TO_DECODE");
        loginResult.set_error_message("There was an internal error while connecting to Battle.net. Please try again later.");
        return SendResponse(request->GetClient(), loginResult);
    }

    std::string login;
    std::string password;

    for (int32 i = 0; i < loginForm.inputs_size(); ++i)
    {
        if (loginForm.inputs(i).input_id() == "account_name")
            login = loginForm.inputs(i).value();
        else if (loginForm.inputs(i).input_id() == "password")
            password = loginForm.inputs(i).value();
    }

    Utf8ToUpperOnlyLatin(login);
    Utf8ToUpperOnlyLatin(password);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_AUTHENTICATION);
    stmt->setString(0, login);

    std::string sentPasswordHash = CalculateShaPassHash(login, password);

    request->SetCallback(Trinity::make_unique<QueryCallback>(LoginDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([request, login, sentPasswordHash, this](QueryCallback& callback, PreparedQueryResult result)
    {
        if (result)
        {
            Field* fields = result->Fetch();
            uint32 accountId = fields[0].GetUInt32();
            std::string pass_hash = fields[1].GetString();
            uint32 failedLogins = fields[2].GetUInt32();
            std::string loginTicket = fields[3].GetString();
            uint32 loginTicketExpiry = fields[4].GetUInt32();
            bool isBanned = fields[5].GetUInt64() != 0;

            if (sentPasswordHash == pass_hash)
            {
                if (loginTicket.empty() || loginTicketExpiry < time(nullptr))
                {
                    BigNumber ticket;
                    ticket.SetRand(20 * 8);

                    loginTicket = "TC-" + ByteArrayToHexStr(ticket.AsByteArray(20).get(), 20);
                }

                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_AUTHENTICATION);
                stmt->setString(0, loginTicket);
                stmt->setUInt32(1, time(nullptr) + _loginTicketDuration);
                stmt->setUInt32(2, accountId);
                callback.WithPreparedCallback([request, loginTicket](PreparedQueryResult)
                {
                    Battlenet::JSON::Login::LoginResult loginResult;
                    loginResult.set_authentication_state(Battlenet::JSON::Login::DONE);
                    loginResult.set_login_ticket(loginTicket);
                    sLoginService.SendResponse(request->GetClient(), loginResult);
                }).SetNextQuery(LoginDatabase.AsyncQuery(stmt));
                return;
            }
            else if (!isBanned)
            {
                std::string ip_address = boost::asio::ip::address_v4(request->GetClient()->ip).to_string();
                uint32 maxWrongPassword = uint32(sConfigMgr->GetIntDefault("WrongPass.MaxCount", 0));

                if (sConfigMgr->GetBoolDefault("WrongPass.Logging", false))
                    TC_LOG_DEBUG("server.rest", "[%s, Account %s, Id %u] Attempted to connect with wrong password!", ip_address.c_str(), login.c_str(), accountId);

                if (maxWrongPassword)
                {
                    SQLTransaction trans = LoginDatabase.BeginTransaction();
                    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_FAILED_LOGINS);
                    stmt->setUInt32(0, accountId);
                    trans->Append(stmt);

                    ++failedLogins;

                    TC_LOG_DEBUG("server.rest", "MaxWrongPass : %u, failed_login : %u", maxWrongPassword, accountId);

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
        }

        Battlenet::JSON::Login::LoginResult loginResult;
        loginResult.set_authentication_state(Battlenet::JSON::Login::DONE);
        sLoginService.SendResponse(request->GetClient(), loginResult);
    })));

    Trinity::Asio::post(*_ioContext, [this, request]() { HandleAsyncRequest(request); });

    return SOAP_OK;
}

int32 LoginRESTService::HandlePostRefreshLoginTicket(std::shared_ptr<AsyncRequest> request)
{
    if (!request->GetClient()->userid)
        return 401;

    request->SetCallback(Trinity::make_unique<QueryCallback>(LoginDatabase.AsyncQuery([&] {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_EXISTING_AUTHENTICATION);
        stmt->setString(0, request->GetClient()->userid);
        return stmt;
    }())
        .WithPreparedCallback([this, request](PreparedQueryResult result)
    {
        Battlenet::JSON::Login::LoginRefreshResult loginRefreshResult;
        if (result)
        {
            uint32 loginTicketExpiry = (*result)[0].GetUInt32();
            time_t now = time(nullptr);
            if (loginTicketExpiry > now)
            {
                loginRefreshResult.set_login_ticket_expiry(now + _loginTicketDuration);

                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_EXISTING_AUTHENTICATION);
                stmt->setUInt32(0, uint32(now + _loginTicketDuration));
                stmt->setString(1, request->GetClient()->userid);
                LoginDatabase.Execute(stmt);
            }
            else
                loginRefreshResult.set_is_expired(true);
        }
        else
            loginRefreshResult.set_is_expired(true);

        SendResponse(request->GetClient(), loginRefreshResult);
    })));

    Trinity::Asio::post(*_ioContext, [this, request]() { HandleAsyncRequest(request); });

    return SOAP_OK;
}

int32 LoginRESTService::SendResponse(soap* soapClient, google::protobuf::Message const& response)
{
    std::string jsonResponse = JSON::Serialize(response);

    soap_response(soapClient, SOAP_FILE);
    soap_send_raw(soapClient, jsonResponse.c_str(), jsonResponse.length());
    return soap_end_send(soapClient);
}

void LoginRESTService::HandleAsyncRequest(std::shared_ptr<AsyncRequest> request)
{
    if (!request->InvokeIfReady())
    {
        Trinity::Asio::post(*_ioContext, [this, request]() { HandleAsyncRequest(request); });
    }
    else if (request->GetResponseStatus())
    {
        ResponseCodePlugin::GetForClient(request->GetClient())->ErrorCode = request->GetResponseStatus();
        SendResponse(request->GetClient(), Battlenet::JSON::Login::ErrorResponse());
    }
}

std::string LoginRESTService::CalculateShaPassHash(std::string const& name, std::string const& password)
{
    SHA256Hash email;
    email.UpdateData(name);
    email.Finalize();

    SHA256Hash sha;
    sha.UpdateData(ByteArrayToHexStr(email.GetDigest(), email.GetLength()));
    sha.UpdateData(":");
    sha.UpdateData(password);
    sha.Finalize();

    return ByteArrayToHexStr(sha.GetDigest(), sha.GetLength(), true);
}

Namespace namespaces[] =
{
    { nullptr, nullptr, nullptr, nullptr }
};

LoginRESTService& LoginRESTService::Instance()
{
    static LoginRESTService instance;
    return instance;
}

char const* const LoginRESTService::ResponseCodePlugin::PluginId = "bnet-error-code";

int32 LoginRESTService::ResponseCodePlugin::Init(soap* s, soap_plugin* p, void* /*arg*/)
{
    ResponseCodePlugin* data = new ResponseCodePlugin();
    data->fresponse = s->fresponse;

    p->id = PluginId;
    p->fcopy = &Copy;
    p->fdelete = &Destroy;
    p->data = data;

    s->fresponse = &ChangeResponse;
    return SOAP_OK;
}

int32 LoginRESTService::ResponseCodePlugin::Copy(soap* /*s*/, soap_plugin* dst, soap_plugin* src)
{
    dst->data = new ResponseCodePlugin(*reinterpret_cast<ResponseCodePlugin*>(src->data));
    return SOAP_OK;
}

void LoginRESTService::ResponseCodePlugin::Destroy(soap* s, soap_plugin* p)
{
    ResponseCodePlugin* data = reinterpret_cast<ResponseCodePlugin*>(p->data);
    s->fresponse = data->fresponse;
    delete data;
}

int32 LoginRESTService::ResponseCodePlugin::ChangeResponse(soap* s, int32 originalResponse, size_t contentLength)
{
    ResponseCodePlugin* self = reinterpret_cast<ResponseCodePlugin*>(soap_lookup_plugin(s, PluginId));
    return self->fresponse(s, self->ErrorCode && originalResponse == SOAP_FILE ? self->ErrorCode : originalResponse, contentLength);
}

LoginRESTService::ResponseCodePlugin* LoginRESTService::ResponseCodePlugin::GetForClient(soap* s)
{
    return ASSERT_NOTNULL(reinterpret_cast<ResponseCodePlugin*>(soap_lookup_plugin(s, PluginId)));
}

char const* const LoginRESTService::ContentTypePlugin::PluginId = "bnet-content-type";

int32 LoginRESTService::ContentTypePlugin::Init(soap* s, soap_plugin* p, void* arg)
{
    ContentTypePlugin* data = new ContentTypePlugin();
    data->fposthdr = s->fposthdr;
    data->ContentType = reinterpret_cast<char const*>(arg);

    p->id = PluginId;
    p->fdelete = &Destroy;
    p->data = data;

    s->fposthdr = &OnSetHeader;
    return SOAP_OK;
}

void LoginRESTService::ContentTypePlugin::Destroy(soap* s, soap_plugin* p)
{
    ContentTypePlugin* data = reinterpret_cast<ContentTypePlugin*>(p->data);
    s->fposthdr = data->fposthdr;
    delete data;
}

int32 LoginRESTService::ContentTypePlugin::OnSetHeader(soap* s, char const* key, char const* value)
{
    ContentTypePlugin* self = reinterpret_cast<ContentTypePlugin*>(soap_lookup_plugin(s, PluginId));
    if (key && !strcmp("Content-Type", key))
        value = self->ContentType;

    return self->fposthdr(s, key, value);
}
