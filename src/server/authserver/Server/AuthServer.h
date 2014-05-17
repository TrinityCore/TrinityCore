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

#ifndef __AUTHSERVER_H__
#define __AUTHSERVER_H__

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class AuthServer
{
public:
	AuthServer(boost::asio::io_service& ioService, std::string bindIp, int port) : _socket(ioService), _acceptor(ioService, tcp::endpoint(tcp::v4(), port))
	{
		tcp::endpoint endpoint(boost::asio::ip::address::from_string(bindIp), port);

		_acceptor = tcp::acceptor(ioService, endpoint);

		AsyncAccept();
	};

private:
	void AsyncAccept();

	tcp::acceptor _acceptor;
	tcp::socket _socket;
};

#endif /* __AUTHSERVER_H__ */
