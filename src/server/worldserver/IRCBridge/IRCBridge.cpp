#include "Config.h"
#include "Log.h"
#include "IRCBridgeHandler.h"
#include "World.h"
#include "IRCBridge.h"
#include "IRCBridgeSocket.h"

#include <boost/algorithm/string.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <functional>
#include <thread>

#define UPDATE_CONST 50

IRCBridge::IRCBridge() : _ioService(nullptr), _strand(nullptr), _socket(nullptr), _status(IRCBRIDGESTATUS_IDLE), _reconnectTimer(0), _active(false)
{
}

IRCBridge::~IRCBridge()
{
    Stop();

    if (_thread.joinable())
        _thread.join();

    delete _strand;
}

IRCBridge* IRCBridge::instance()
{
    static IRCBridge instance;
    return &instance;
}

void IRCBridge::Initialize(boost::asio::io_service * service)
{
    if (_active)
        return;

    _ioService = service;
    _strand = new boost::asio::strand(*_ioService);
    _thread = std::thread(std::bind(&IRCBridge::Run, this));
}

void IRCBridge::Run()
{
    if (!LoadConfigurations())
        return;

    _active = true;
    while (_active)
        ThreadLoop();
}

void IRCBridge::Stop()
{
    _status = IRCBRIDGESTATUS_SHUTDOWN;

    if (_socket)
        _socket->CloseSocket();

    _active = false;
}

void IRCBridge::Send(std::string message)
{
    if (IsConnected())
    {
        message.append("\r\n");
        _socket->Send(message);
    }
}

void IRCBridge::Report(IRCBridgeReportType report)
{
    switch (report)
    {
        case REPORTTYPE_ERROR:
            _socket->CloseSocket();
            _reconnectTimer = GetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_WAIT);
            _status = IRCBRIDGESTATUS_IDLE;
            break;
        default:
            break;
    }
}

void IRCBridge::HandleMessage(std::string const& message)
{
    std::string temp = message.substr(0, 1);
    if (!temp.empty() && temp.compare(":") == 0)
    {
        size_t firstWordPosition = message.find(' ');
        size_t secondWordPosition = message.find(' ', firstWordPosition + 1);

        // Get command
        std::string temp = message.substr(firstWordPosition + 1, secondWordPosition - firstWordPosition - 1);
        std::string command = MakeStringUpper(temp);

        if (command.compare(GetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_CODE)) == 0 && _status == IRCBRIDGESTATUS_WAITING_CONFIRMATION)
        {
            _status = IRCBRIDGESTATUS_LOGGED;
        }
        else
        {
            // Get user
            temp = message.substr(1, firstWordPosition - 1);
            size_t userPosition = temp.find("!");
            std::string user = MakeStringUpper(temp.substr(0, userPosition));

            temp = message.substr(secondWordPosition + 2, message.size() - secondWordPosition - 3);

            TC_LOG_INFO("IRCBridge", "IRCBridge::HandleMessage: user: %s, command %s, rest: '%s'", user.c_str(), command.c_str(), temp.c_str());
        }
    }
}

void IRCBridge::ThreadLoop()
{
    switch (_status)
    {
        case IRCBRIDGESTATUS_IDLE:
            if (_reconnectTimer <= UPDATE_CONST)
            {
                StartNetwork(GetConfiguration(CONFIGURATION_IRCBRIDGE_HOST), std::to_string(GetConfiguration(CONFIGURATION_IRCBRIDGE_PORT)));
                _status = IRCBRIDGESTATUS_WAITING_CONNECTION;
            }
            else
                _reconnectTimer -= UPDATE_CONST;
            break;
        case IRCBRIDGESTATUS_CONNECTED:
            Login();
            _status = IRCBRIDGESTATUS_WAITING_CONFIRMATION;
            break;
        case IRCBRIDGESTATUS_LOGGED:
        {
            std::string temp = sIRCBridgeHandler->GetNext();
            if (!temp.empty())
                Send(temp);
            break;
        }
        case IRCBRIDGESTATUS_SHUTDOWN:
        case IRCBRIDGESTATUS_WAITING_CONNECTION:
        case IRCBRIDGESTATUS_WAITING_CONFIRMATION:
        default:
            break;
    }
}

void IRCBridge::StartNetwork(std::string const& bindIp, std::string const& port)
{
    std::shared_ptr<boost::asio::ip::tcp::socket> socket = std::make_shared<boost::asio::ip::tcp::socket>(*_ioService);
    std::shared_ptr<boost::asio::ip::tcp::resolver> resolver = std::make_shared<boost::asio::ip::tcp::resolver>(*_ioService);
    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), bindIp, port);

    auto connectHandler = [socket, this] (const boost::system::error_code& errorCode, const boost::asio::ip::tcp::resolver::iterator& it)
    {
        if (errorCode)
        {
            TC_LOG_ERROR("IRCBridge", "IRCBridge::StartNetwork: could not connect: %s.", errorCode.message().c_str());
        }
        else if (it == boost::asio::ip::tcp::resolver::iterator())
        {
            TC_LOG_ERROR("IRCBridge", "IRCBridge::StartNetwork: could not connect.");
        }
        else
        {
            this->OnConnect(std::move(*socket));
        }
    };

    auto resolveHandler = [socket, resolver, connectHandler] (const boost::system::error_code& errorCode, const boost::asio::ip::tcp::resolver::iterator& it)
    {
        if (errorCode)
        {
            TC_LOG_ERROR("IRCBridge", "IRCBridge::StartNetwork: could not resolve address: %s.", errorCode.message().c_str());
        }
        else
        {
            boost::asio::async_connect(*socket, it, boost::asio::ip::tcp::resolver::iterator(), connectHandler);
        }
    };

    resolver->async_resolve(query, resolveHandler);
}

void IRCBridge::OnConnect(boost::asio::ip::tcp::socket&& socket)
{
    TC_LOG_INFO("IRCBridge", "IRCBridge::OnConnect: connected to %s port %u", socket.remote_endpoint().address().to_string().c_str(), socket.remote_endpoint().port());

    _socket = std::make_shared<IRCBridgeSocket>(this, std::move(socket));
    _socket->Start();

    _status = IRCBRIDGESTATUS_CONNECTED;
}

void IRCBridge::Login()
{
    Send("HELLO");
    if (!GetConfiguration(CONFIGURATION_IRCBRIDGE_PASSWORD).empty())
        Send("PASS " + GetConfiguration(CONFIGURATION_IRCBRIDGE_PASSWORD));
    Send("NICK " + GetConfiguration(CONFIGURATION_IRCBRIDGE_NICKNAME));
    Send("USER " + GetConfiguration(CONFIGURATION_IRCBRIDGE_USERNAME) + " 0 * :TrinityCore - IRCBridge");
}

void IRCBridge::Reconnect()
{
}

template<ConfigurationType T, typename N>
N IRCBridge::LoadConfiguration(char const* /*fieldname*/, N /*defvalue*/) const
{
    return N();
}

template<>
uint32 IRCBridge::LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>(char const* fieldname, uint32 defvalue) const
{
    int32 temp = sConfigMgr->GetIntDefault(fieldname, defvalue);
    if (temp < 0)
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: %s value (%i) can't be negative, using default value %u instead.", fieldname, temp, defvalue);
        temp = defvalue;
    }

    return uint32(temp);
}

template<>
std::string IRCBridge::LoadConfiguration<CONFIGURATIONTYPE_STRING, std::string>(char const* fieldname, std::string defvalue) const
{
    std::string temp = sConfigMgr->GetStringDefault(fieldname, defvalue);
    if (temp.empty())
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: %s value is empty, using default value %s instead.", fieldname, defvalue.c_str());
        temp = defvalue;
    }

    return temp;
}

bool IRCBridge::LoadConfigurations()
{
    SetConfiguration(CONFIGURATION_IRCBRIDGE_HOST, sConfigMgr->GetStringDefault("IRCBridge.Host", ""));
    if (GetConfiguration(CONFIGURATION_IRCBRIDGE_HOST).empty())
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: missing IRCBridge.Host value on configuration file.");
        return false;
    }
    SetConfiguration(CONFIGURATION_IRCBRIDGE_PORT, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Port", 6667));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_USERNAME, LoadConfiguration<CONFIGURATIONTYPE_STRING, std::string>("IRCBridge.Username", "IRCBridge"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_NICKNAME, LoadConfiguration<CONFIGURATIONTYPE_STRING, std::string>("IRCBridge.Nickname", "IRCBridge"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_PASSWORD, sConfigMgr->GetStringDefault("IRCBridge.Password", ""));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_CODE, LoadConfiguration<CONFIGURATIONTYPE_STRING, std::string>("IRCBridge.Connection.Code", "001"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_WAIT, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Connection.Wait", 10000));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_ATTEMPTS, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Connection.Attempts", 20));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Authentication.Method", 0));
    if (uint32 temp = GetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD) > 4)
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: incorrect IRCBridge.Authentication.Method value (%u) on configuration file, using default value instead.", temp);
        SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, 0);
    }
    SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_NICKNAME, LoadConfiguration<CONFIGURATIONTYPE_STRING, std::string>("IRCBridge.Authentication.Nickname", "NickServ"));

    return true;
}

std::string IRCBridge::MakeStringUpper(std::string string)
{
    boost::to_upper(string);
    return string;
}
