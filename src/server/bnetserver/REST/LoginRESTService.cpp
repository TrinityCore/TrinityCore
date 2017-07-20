/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ProtobufJSON.h"
#include "Realm.h"
#include "SessionManager.h"
#include "SHA1.h"
#include "SHA256.h"
#include "SslContext.h"
#include "Util.h"
#include "httpget.h"
#include "httppost.h"
#include "soapH.h"

int ns1__executeCommand(soap*, char*, char**) { return SOAP_OK; }

class AsyncLoginRequest
{
public:
    AsyncLoginRequest(std::shared_ptr<soap> client)
        : _client(std::move(client)) { }

    AsyncLoginRequest(AsyncLoginRequest const&) = delete;
    AsyncLoginRequest& operator=(AsyncLoginRequest const&) = delete;
    AsyncLoginRequest(AsyncLoginRequest&&) = default;
    AsyncLoginRequest& operator=(AsyncLoginRequest&&) = default;

    bool InvokeIfReady()
    {
        ASSERT(_callback);
        return _callback->InvokeIfReady() == QueryCallback::Completed;
    }

    soap* GetClient() const { return _client.get(); }
    void SetCallback(std::unique_ptr<QueryCallback> callback) { _callback = std::move(callback); }
    std::unique_ptr<Battlenet::Session::AccountInfo>& GetResult() { return _result; }
    void SetResult(std::unique_ptr<Battlenet::Session::AccountInfo> result) { _result = std::move(result); }

private:
    std::shared_ptr<soap> _client;
    std::unique_ptr<QueryCallback> _callback;
    std::unique_ptr<Battlenet::Session::AccountInfo> _result;
};

int32 handle_get_plugin(soap* soapClient)
{
    return sLoginService.HandleGet(soapClient);
}

int32 handle_post_plugin(soap* soapClient)
{
    return sLoginService.HandlePost(soapClient);
}

bool LoginRESTService::Start(boost::asio::io_service* ioService)
{
    _ioService = ioService;
    _bindIP = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");
    _port = sConfigMgr->GetIntDefault("LoginREST.Port", 8081);
    if (_port < 0 || _port > 0xFFFF)
    {
        TC_LOG_ERROR("server.rest", "Specified login service port (%d) out of allowed range (1-65535), defaulting to 8081", _port);
        _port = 8081;
    }

    boost::system::error_code ec;
    boost::asio::ip::tcp::resolver resolver(*ioService);
    boost::asio::ip::tcp::resolver::iterator end;

    std::string configuredAddress = sConfigMgr->GetStringDefault("LoginREST.ExternalAddress", "127.0.0.1");
    boost::asio::ip::tcp::resolver::query externalAddressQuery(boost::asio::ip::tcp::v4(), configuredAddress, std::to_string(_port));
    boost::asio::ip::tcp::resolver::iterator endPoint = resolver.resolve(externalAddressQuery, ec);
    if (endPoint == end || ec)
    {
        TC_LOG_ERROR("server.rest", "Could not resolve LoginREST.ExternalAddress %s", configuredAddress.c_str());
        return false;
    }

    _externalAddress = endPoint->endpoint();

    configuredAddress = sConfigMgr->GetStringDefault("LoginREST.LocalAddress", "127.0.0.1");
    boost::asio::ip::tcp::resolver::query localAddressQuery(boost::asio::ip::tcp::v4(), configuredAddress, std::to_string(_port));
    endPoint = resolver.resolve(localAddressQuery, ec);
    if (endPoint == end || ec)
    {
        TC_LOG_ERROR("server.rest", "Could not resolve LoginREST.ExternalAddress %s", configuredAddress.c_str());
        return false;
    }

    _localAddress = endPoint->endpoint();

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

    _loginTicketCleanupTimer = new boost::asio::deadline_timer(*ioService);
    _loginTicketCleanupTimer->expires_from_now(boost::posix_time::seconds(10));
    _loginTicketCleanupTimer->async_wait(std::bind(&LoginRESTService::CleanupLoginTickets, this, std::placeholders::_1));

    _thread = std::thread(std::bind(&LoginRESTService::Run, this));
    return true;
}

void LoginRESTService::Stop()
{
    _stopped = true;
    _loginTicketCleanupTimer->cancel();
    _thread.join();
}

boost::asio::ip::tcp::endpoint const& LoginRESTService::GetAddressForClient(boost::asio::ip::address const& address) const
{
    if (address.is_loopback())
        return _localAddress;
    else if (_localAddress.address().is_loopback())
        return _externalAddress;

    boost::asio::ip::address_v4 netmask = boost::asio::ip::address_v4::netmask(_localAddress.address().to_v4());
    if ((netmask.to_ulong() & address.to_v4().to_ulong()) == (netmask.to_ulong() & _localAddress.address().to_v4().to_ulong()))
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

    soap_register_plugin_arg(&soapServer, &http_get, (void*)&handle_get_plugin);
    soap_register_plugin_arg(&soapServer, &http_post, handlers);
    soap_register_plugin_arg(&soapServer, &ContentTypePlugin::Init, (void*)"application/json;charset=utf-8");

    // Use our already ready ssl context
    soapServer.ctx = Battlenet::SslContext::instance().native_handle();
    soapServer.ssl_flags = SOAP_SSL_RSA;

    while (!_stopped)
    {
        if (!soap_valid_socket(soap_accept(&soapServer)))
            continue;   // ran into an accept timeout

        std::shared_ptr<soap> soapClient = std::make_shared<soap>(soapServer);
        boost::asio::ip::address_v4 address(soapClient->ip);
        if (soap_ssl_accept(soapClient.get()) != SOAP_OK)
        {
            TC_LOG_DEBUG("server.rest", "Failed SSL handshake from IP=%s", address.to_string().c_str());
            continue;
        }

        TC_LOG_DEBUG("server.rest", "Accepted connection from IP=%s", address.to_string().c_str());

        _ioService->post([soapClient]()
        {
            soapClient->user = (void*)&soapClient; // this allows us to make a copy of pointer inside GET/POST handlers to increment reference count
            soap_begin(soapClient.get());
            soap_begin_recv(soapClient.get());
        });
    }

    // and release the context handle here - soap does not own it so it should not free it on exit
    soapServer.ctx = nullptr;

    TC_LOG_INFO("server.rest", "Login service exiting...");
}

int32 LoginRESTService::HandleGet(soap* soapClient)
{
    boost::asio::ip::address_v4 address(soapClient->ip);
    std::string ip_address = address.to_string();

    TC_LOG_DEBUG("server.rest", "[%s:%d] Handling GET request path=\"%s\"", ip_address.c_str(), soapClient->port, soapClient->path);

    static std::string const expectedPath = "/bnetserver/login/";
    if (strstr(soapClient->path, expectedPath.c_str()) != &soapClient->path[0])
        return 404;

    return SendResponse(soapClient, _formInputs);
}

int32 LoginRESTService::HandlePost(soap* soapClient)
{
    boost::asio::ip::address_v4 address(soapClient->ip);
    std::string ip_address = address.to_string();

    TC_LOG_DEBUG("server.rest", "[%s:%d] Handling POST request path=\"%s\"", ip_address.c_str(), soapClient->port, soapClient->path);

    static std::string const expectedPath = "/bnetserver/login/";
    if (strstr(soapClient->path, expectedPath.c_str()) != &soapClient->path[0])
        return 404;

    char *buf;
    size_t len;
    soap_http_body(soapClient, &buf, &len);

    Battlenet::JSON::Login::LoginForm loginForm;
    if (!JSON::Deserialize(buf, &loginForm))
    {
        if (soap_register_plugin_arg(soapClient, &ResponseCodePlugin::Init, nullptr) != SOAP_OK)
            return 500;

        ResponseCodePlugin* responseCode = reinterpret_cast<ResponseCodePlugin*>(soap_lookup_plugin(soapClient, ResponseCodePlugin::PluginId));
        ASSERT(responseCode);

        responseCode->ErrorCode = 400;

        Battlenet::JSON::Login::LoginResult loginResult;
        loginResult.set_authentication_state(Battlenet::JSON::Login::LOGIN);
        loginResult.set_error_code("UNABLE_TO_DECODE");
        loginResult.set_error_message("There was an internal error while connecting to Battle.net. Please try again later.");
        return SendResponse(soapClient, loginResult);
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

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_ACCOUNT_INFO);
    stmt->setString(0, login);

    std::string sentPasswordHash = CalculateShaPassHash(login, password);

    std::shared_ptr<AsyncLoginRequest> request = std::make_shared<AsyncLoginRequest>(*reinterpret_cast<std::shared_ptr<soap>*>(soapClient->user));
    request->SetCallback(Trinity::make_unique<QueryCallback>(LoginDatabase.AsyncQuery(stmt)
        .WithChainingPreparedCallback([request, login, sentPasswordHash](QueryCallback& callback, PreparedQueryResult result)
    {
        if (result)
        {
            std::string pass_hash = result->Fetch()[13].GetString();

            request->SetResult(Trinity::make_unique<Battlenet::Session::AccountInfo>());
            request->GetResult()->LoadResult(result);

            if (sentPasswordHash == pass_hash)
            {
                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_BNET_ID);
                stmt->setUInt32(0, request->GetResult()->Id);
                callback.SetNextQuery(LoginDatabase.AsyncQuery(stmt));
                return;
            }
            else if (!request->GetResult()->IsBanned)
            {
                std::string ip_address = boost::asio::ip::address_v4(request->GetClient()->ip).to_string();
                uint32 maxWrongPassword = uint32(sConfigMgr->GetIntDefault("WrongPass.MaxCount", 0));

                if (sConfigMgr->GetBoolDefault("WrongPass.Logging", false))
                    TC_LOG_DEBUG("server.rest", "[%s, Account %s, Id %u] Attempted to connect with wrong password!", ip_address.c_str(), login.c_str(), request->GetResult()->Id);

                if (maxWrongPassword)
                {
                    SQLTransaction trans = LoginDatabase.BeginTransaction();
                    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_FAILED_LOGINS);
                    stmt->setUInt32(0, request->GetResult()->Id);
                    trans->Append(stmt);

                    ++request->GetResult()->FailedLogins;

                    TC_LOG_DEBUG("server.rest", "MaxWrongPass : %u, failed_login : %u", maxWrongPassword, request->GetResult()->Id);

                    if (request->GetResult()->FailedLogins >= maxWrongPassword)
                    {
                        BanMode banType = BanMode(sConfigMgr->GetIntDefault("WrongPass.BanType", uint16(BanMode::BAN_IP)));
                        int32 banTime = sConfigMgr->GetIntDefault("WrongPass.BanTime", 600);

                        if (banType == BanMode::BAN_ACCOUNT)
                        {
                            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ACCOUNT_AUTO_BANNED);
                            stmt->setUInt32(0, request->GetResult()->Id);
                        }
                        else
                        {
                            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_IP_AUTO_BANNED);
                            stmt->setString(0, ip_address);
                        }

                        stmt->setUInt32(1, banTime);
                        trans->Append(stmt);

                        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_RESET_FAILED_LOGINS);
                        stmt->setUInt32(0, request->GetResult()->Id);
                        trans->Append(stmt);
                    }

                    LoginDatabase.CommitTransaction(trans);
                }
            }
        }
        Battlenet::JSON::Login::LoginResult loginResult;
        loginResult.set_authentication_state(Battlenet::JSON::Login::DONE);
        sLoginService.SendResponse(request->GetClient(), loginResult);
    })
        .WithChainingPreparedCallback([request](QueryCallback& callback, PreparedQueryResult characterCountsResult)
    {
        if (characterCountsResult)
        {
            do
            {
                Field* fields = characterCountsResult->Fetch();
                request->GetResult()->GameAccounts[fields[0].GetUInt32()]
                    .CharacterCounts[Battlenet::RealmHandle{ fields[3].GetUInt8(), fields[4].GetUInt8(), fields[2].GetUInt32() }.GetAddress()] = fields[1].GetUInt8();

            } while (characterCountsResult->NextRow());
        }

        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BNET_LAST_PLAYER_CHARACTERS);
        stmt->setUInt32(0, request->GetResult()->Id);
        callback.SetNextQuery(LoginDatabase.AsyncQuery(stmt));
    })
        .WithPreparedCallback([request](PreparedQueryResult lastPlayerCharactersResult)
    {
        if (lastPlayerCharactersResult)
        {
            do
            {
                Field* fields = lastPlayerCharactersResult->Fetch();
                Battlenet::RealmHandle realmId{ fields[1].GetUInt8(), fields[2].GetUInt8(), fields[3].GetUInt32() };
                Battlenet::Session::LastPlayedCharacterInfo& lastPlayedCharacter = request->GetResult()->GameAccounts[fields[0].GetUInt32()]
                    .LastPlayedCharacters[realmId.GetSubRegionAddress()];

                lastPlayedCharacter.RealmId = realmId;
                lastPlayedCharacter.CharacterName = fields[4].GetString();
                lastPlayedCharacter.CharacterGUID = fields[5].GetUInt64();
                lastPlayedCharacter.LastPlayedTime = fields[6].GetUInt32();

            } while (lastPlayerCharactersResult->NextRow());
        }

        BigNumber ticket;
        ticket.SetRand(20 * 8);

        Battlenet::JSON::Login::LoginResult loginResult;
        loginResult.set_authentication_state(Battlenet::JSON::Login::DONE);
        loginResult.set_login_ticket("TC-" + ByteArrayToHexStr(ticket.AsByteArray(20).get(), 20));
        sLoginService.SendResponse(request->GetClient(), loginResult);

        sLoginService.AddLoginTicket(loginResult.login_ticket(), std::move(request->GetResult()));
    })));

    _ioService->post(std::bind(&LoginRESTService::HandleAsyncRequest, this, std::move(request)));

    return SOAP_OK;
}

int32 LoginRESTService::SendResponse(soap* soapClient, google::protobuf::Message const& response)
{
    std::string jsonResponse = JSON::Serialize(response);

    soap_response(soapClient, SOAP_FILE);
    soap_send_raw(soapClient, jsonResponse.c_str(), jsonResponse.length());
    return soap_end_send(soapClient);
}

void LoginRESTService::HandleAsyncRequest(std::shared_ptr<AsyncLoginRequest> request)
{
    if (!request->InvokeIfReady())
        _ioService->post(std::bind(&LoginRESTService::HandleAsyncRequest, this, std::move(request)));
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

std::unique_ptr<Battlenet::Session::AccountInfo> LoginRESTService::VerifyLoginTicket(std::string const& id)
{
    std::unique_lock<std::mutex> lock(_loginTicketMutex);

    auto itr = _validLoginTickets.find(id);
    if (itr != _validLoginTickets.end())
    {
        if (itr->second.ExpiryTime > time(nullptr))
        {
            std::unique_ptr<Battlenet::Session::AccountInfo> accountInfo = std::move(itr->second.Account);
            _validLoginTickets.erase(itr);
            return accountInfo;
        }
    }

    return std::unique_ptr<Battlenet::Session::AccountInfo>();
}

void LoginRESTService::AddLoginTicket(std::string const& id, std::unique_ptr<Battlenet::Session::AccountInfo> accountInfo)
{
    std::unique_lock<std::mutex> lock(_loginTicketMutex);

    _validLoginTickets[id] = { id, std::move(accountInfo), time(nullptr) + 10 };
}

void LoginRESTService::CleanupLoginTickets(boost::system::error_code const& error)
{
    if (error)
        return;

    time_t now = time(nullptr);

    {
        std::unique_lock<std::mutex> lock(_loginTicketMutex);
        for (auto itr = _validLoginTickets.begin(); itr != _validLoginTickets.end();)
        {
            if (itr->second.ExpiryTime < now)
                itr = _validLoginTickets.erase(itr);
            else
                ++itr;
        }
    }

    _loginTicketCleanupTimer->expires_from_now(boost::posix_time::seconds(10));
    _loginTicketCleanupTimer->async_wait(std::bind(&LoginRESTService::CleanupLoginTickets, this, std::placeholders::_1));
}

LoginRESTService::LoginTicket& LoginRESTService::LoginTicket::operator=(LoginTicket&& right)
{
    if (this != &right)
    {
        Id = std::move(right.Id);
        Account = std::move(right.Account);
        ExpiryTime = right.ExpiryTime;
    }

    return *this;
}

Namespace namespaces[] =
{
    { NULL, NULL, NULL, NULL }
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
    p->fdelete = &Destroy;
    p->data = data;

    s->fresponse = &ChangeResponse;
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
