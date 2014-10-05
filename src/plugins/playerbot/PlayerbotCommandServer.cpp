#include "../pchdef.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotFactory.h"
#include "PlayerbotCommandServer.h"
#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>


using namespace std;
using boost::asio::ip::tcp;
typedef boost::shared_ptr<tcp::socket> socket_ptr;

bool ReadLine(socket_ptr sock, string* buffer, string* line)
{
    // Do the real reading from fd until buffer has '\n'.
    string::iterator pos;
    while ((pos = find(buffer->begin(), buffer->end(), '\n')) == buffer->end())
    {
        char buf[1025];
        boost::system::error_code error;
        size_t n = sock->read_some(boost::asio::buffer(buf), error);
        if (n == -1 || error == boost::asio::error::eof)
            return false;
        else if (error)
            throw boost::system::system_error(error); // Some other error.

        buf[n] = 0;
        *buffer += buf;
    }

    *line = string(buffer->begin(), pos);
    *buffer = string(pos + 1, buffer->end());
    return true;
}

void session(socket_ptr sock)
{
    try
    {
        string buffer, request;
        while (ReadLine(sock, &buffer, &request)) {
            string response = sRandomPlayerbotMgr.HandleRemoteCommand(request) + "\n";
            boost::asio::write(*sock, boost::asio::buffer(response.c_str(), response.size()));
            request = "";
        }
    }
    catch (std::exception& e)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, e.what());
    }
}

void server(boost::asio::io_service& io_service, short port)
{
    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
    for (;;)
    {
        socket_ptr sock(new tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock));
    }
}

void Run()
{
    if (!sPlayerbotAIConfig.commandServerPort) {
        return;
    }

    ostringstream s; s << "Starting Playerbot Command Server on port " << sPlayerbotAIConfig.commandServerPort;
    sLog->outMessage("playerbot", LOG_LEVEL_INFO, s.str().c_str());

    try
    {
        boost::asio::io_service io_service;
        server(io_service, sPlayerbotAIConfig.commandServerPort);
    }
    catch (std::exception& e)
    {
        sLog->outMessage("playerbot", LOG_LEVEL_ERROR, e.what());
    }
}


void PlayerbotCommandServer::Start()
{
    thread serverThread(Run);
    serverThread.detach();
}
