/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __ASYNCACCEPT_H_
#define __ASYNCACCEPT_H_

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

template <class T>
class AsyncAcceptor
{
public:
    AsyncAcceptor(boost::asio::io_service& ioService, std::string bindIp, int port) :
        _acceptor(ioService, tcp::endpoint(boost::asio::ip::address::from_string(bindIp), port)),
        _socket(ioService)
    {
        AsyncAccept();
    };

    AsyncAcceptor(boost::asio::io_service& ioService, std::string bindIp, int port, bool tcpNoDelay) :
        _socket(ioService),
        _acceptor(ioService, tcp::endpoint(boost::asio::ip::address::from_string(bindIp), port))
    {
        _acceptor.set_option(boost::asio::ip::tcp::no_delay(tcpNoDelay));

        AsyncAccept();
    };

private:
    void AsyncAccept()
    {
        _acceptor.async_accept(_socket, [this](boost::system::error_code error)
        {
            if (!error)
            {
                // this-> is required here to fix an segmentation fault in gcc 4.7.2 - reason is lambdas in a templated class
                std::make_shared<T>(std::move(this->_socket))->Start();
            }

            // lets slap some more this-> on this so we can fix this bug with gcc 4.7.2 throwing internals in yo face
            this->AsyncAccept();
        });
    }

    tcp::acceptor _acceptor;
    tcp::socket _socket;
};

#endif /* __ASYNCACCEPT_H_ */
