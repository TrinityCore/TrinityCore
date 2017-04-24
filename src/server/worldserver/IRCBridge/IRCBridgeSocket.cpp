#include "Log.h"
#include "ByteBuffer.h"
#include "MessageBuffer.h"
#include "IRCBridge.h"
#include "IRCBridgeSocket.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

IRCCommand const commands[IRCCOMMAND_MAX] =
{
    { IRCCOMMAND_PING,  "PING",  4 },
    { IRCCOMMAND_PONG,  "PONG",  4 },
    { IRCCOMMAND_ERROR, "ERROR", 5 }
};

IRCBridgeSocket::IRCBridgeSocket(boost::asio::ip::tcp::socket&& socket) : Socket<IRCBridgeSocket>(std::move(socket))
{

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
    TC_LOG_INFO("IRCBridge", "IRCBridgeSocket::ReadHandler: message received: %s", message.c_str());

    uint8 type = 0;
    while (type < IRCCOMMAND_MAX)
    {
        size_t size = commands[type].size;
        std::string temp = message.substr(0, size);
        if (temp.compare(commands[type].data) == 0)
            break;
        ++type;
    }

    switch (type)
    {
        case IRCCOMMAND_PING:
            Send(commands[IRCCOMMAND_PONG].data + message.substr(commands[IRCCOMMAND_PONG].size, message.size() - commands[IRCCOMMAND_PONG].size) + "\r\n");
            break;
        case IRCCOMMAND_ERROR:
            break;
        default:
            break;
    }
}
