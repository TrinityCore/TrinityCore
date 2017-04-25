#include "Log.h"
#include "MessageBuffer.h"
#include "IRCBridge.h"
#include "IRCBridgeSocket.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

IRCCommand const commands[IRCSOCKETCOMMAND_MAX] =
{
    { IRCSOCKETCOMMAND_PING,  "PING",  4 },
    { IRCSOCKETCOMMAND_PONG,  "PONG",  4 },
    { IRCSOCKETCOMMAND_ERROR, "ERROR", 5 }
};

IRCBridgeSocket::IRCBridgeSocket(IRCBridge* master, boost::asio::ip::tcp::socket&& socket) : Socket<IRCBridgeSocket>(std::move(socket))
{
    _master = master;
}

IRCBridgeSocket::~IRCBridgeSocket()
{
}

void IRCBridgeSocket::Start()
{
    AsyncRead();
}

void IRCBridgeSocket::OnClose()
{
}

void IRCBridgeSocket::ReadHandler()
{
    if (!IsOpen())
        return;

    MessageBuffer& message = GetReadBuffer();
    std::size_t readSize = message.GetActiveSize();

    if (readSize > 0)
    {
        std::string result(reinterpret_cast<char const*>(message.GetReadPointer()), readSize);
        HandleMessage(result);
    }

    message.ReadCompleted(readSize);

    AsyncRead();
}

void IRCBridgeSocket::Send(std::string const& message)
{
    if (!IsOpen())
        return;

    if (!message.empty())
    {
        MessageBuffer buffer;
        buffer.Write(message.data(), message.size());
        QueuePacket(std::move(buffer));
    }
}

void IRCBridgeSocket::HandleMessage(std::string const& message)
{
    uint8 type = 0;
    while (type < IRCSOCKETCOMMAND_MAX)
    {
        size_t size = commands[type].size;
        std::string temp = message.substr(0, size);
        if (temp.compare(commands[type].data) == 0)
            break;
        ++type;
    }

    switch (type)
    {
        case IRCSOCKETCOMMAND_PING:
            Send(commands[IRCSOCKETCOMMAND_PONG].data + message.substr(commands[IRCSOCKETCOMMAND_PONG].size, message.size() - commands[IRCSOCKETCOMMAND_PONG].size) + "\r\n");
            break;
        case IRCSOCKETCOMMAND_ERROR:
            _master->Report(REPORTTYPE_ERROR);
            break;
        default:
            _master->HandleMessage(message);
            break;
    }
}
