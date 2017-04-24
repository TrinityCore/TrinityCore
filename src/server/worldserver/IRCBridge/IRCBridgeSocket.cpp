#include "Log.h"
#include "ByteBuffer.h"
#include "MessageBuffer.h"
#include "IRCBridge.h"
#include "IRCBridgeSocket.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

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
        TC_LOG_ERROR("IRCBRidge", "IRCBridgeSocket::ReadHandler: message received '%s", result.c_str());
    }

    message.ReadCompleted(readSize);

    AsyncRead();
}

void IRCBridgeSocket::Send(ByteBuffer const& message)
{
    if (!IsOpen())
        return;

    if (!message.empty())
    {
        MessageBuffer buffer;
        buffer.Write(message.contents(), message.size());
        QueuePacket(std::move(buffer));
    }
}
