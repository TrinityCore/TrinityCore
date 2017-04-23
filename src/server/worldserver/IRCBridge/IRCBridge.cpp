#include "Config.h"
#include "Log.h"
#include "World.h"
#include "IRCBridge.h"

#include <boost/asio/connect.hpp>
#include <thread>

IRCBridge::IRCBridge() : _ioService(nullptr), _strand(nullptr), _thread(nullptr), _active(false), _connected(false)
{
}

IRCBridge::~IRCBridge()
{
    Stop();
    delete _strand;
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

    StartNetwork(*_ioService, GetConfiguration(CONFIGURATION_IRCBRIDGE_HOST), std::to_string(GetConfiguration(CONFIGURATION_IRCBRIDGE_PORT)));

    uint32 connectionAttempts = 0;
    while (_active && !World::IsStopped())
    {
        if (_connected)
        {
            // Testing
            if (connectionAttempts == 0)
            {
                Login();
                ++connectionAttempts;
            }
        }
    }
}

void IRCBridge::Stop()
{
    _active = false;

    _socket->CloseSocket();
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
    SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Authentication.Method", 0));
    if (uint32 temp = GetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD) > 4)
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: incorrect IRCBridge.Authentication.Method value (%u) on configuration file, using default value instead.", temp);
        SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, 0);
    }
    SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_NICKNAME, LoadConfiguration<CONFIGURATIONTYPE_STRING, std::string>("IRCBridge.Authentication.Nickname", "NickServ"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_CODE, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Connection.Code", 001));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_WAIT, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Connection.Wait", 10000));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_ATTEMPTS, LoadConfiguration<CONFIGURATIONTYPE_UINT, uint32>("IRCBridge.Connection.Attempts", 20));

    return true;
}

void IRCBridge::Send(std::string const message)
{
    if (_connected)
    {
        MessageBuffer buffer;
        buffer.Write(message.data(), message.size());
        _socket->Send(buffer);
    }
}

void IRCBridge::Login()
{
    Send("HELLO");
    Send("PASS " + GetConfiguration(CONFIGURATION_IRCBRIDGE_PASSWORD));
    Send("NICK " + GetConfiguration(CONFIGURATION_IRCBRIDGE_NICKNAME));
    Send("USER " + GetConfiguration(CONFIGURATION_IRCBRIDGE_USERNAME) + " " + GetConfiguration(CONFIGURATION_IRCBRIDGE_HOST));
}

void IRCBridge::StartNetwork(boost::asio::io_service& service, std::string const& bindIp, std::string const& port)
{
    std::shared_ptr<tcp::socket> socket = std::make_shared<tcp::socket>(service);
    std::shared_ptr<tcp::resolver> resolver = std::make_shared<tcp::resolver>(service);
    boost::asio::ip::tcp::resolver::query query(ip::tcp::v4(), bindIp, port);

    auto connectHandler = [socket, this] (const boost::system::error_code& errorCode, const tcp::resolver::iterator& it)
    {
        if (errorCode)
        {
            TC_LOG_ERROR("IRCBridge", "IRCBridge::StartNetwork: could not connect (%s).", errorCode.message().c_str());
        }
        else if (it == tcp::resolver::iterator())
        {
            TC_LOG_ERROR("IRCBridge", "IRCBridge::StartNetwork: could not connect.");
        }
        else
        {
            this->OnConnect(std::move(*socket));
        }
    };

    auto resolveHandler = [socket, resolver, connectHandler] (const boost::system::error_code& errorCode, const tcp::resolver::iterator& it)
    {
        if (errorCode)
        {
            TC_LOG_ERROR("IRCBridge", "IRCBridge::StartNetwork: could not resolve address: %s.", errorCode.message().c_str());
        }
        else
        {
            boost::asio::async_connect(*socket, it, tcp::resolver::iterator(), connectHandler);
        }
    };

    resolver->async_resolve(query, resolveHandler);
}

void IRCBridge::OnConnect(tcp::socket&& socket)
{
    _socket = new IRCBridgeSocket(std::move(socket));
    _socket->Start();

    _connected = true;
}

template<ConfigurationType T, typename N>
N IRCBridge::LoadConfiguration(char const* fieldname, N defvalue) const
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
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: %s value is empty, using default value %u instead.", fieldname, defvalue);
        temp = defvalue;
    }

    return temp;
}

IRCBridgeSocket::IRCBridgeSocket(tcp::socket&& socket) : Socket<IRCBridgeSocket>(std::move(socket))
{

}

IRCBridgeSocket::~IRCBridgeSocket()
{

}

void IRCBridgeSocket::Start()
{

}

void IRCBridgeSocket::OnClose()
{
}

void IRCBridgeSocket::ReadHandler()
{
}

void IRCBridgeSocket::Send(MessageBuffer message)
{
    if (!IsOpen())
        return;

    QueuePacket(std::move(message));
}
